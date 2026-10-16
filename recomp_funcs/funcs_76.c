#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80009EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009EAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009EB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009EB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009EB8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80009EBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80009EC0: slti        $at, $v0, 0x91
    ctx->r1 = SIGNED(ctx->r2) < 0X91 ? 1 : 0;
    // 0x80009EC4: bne         $at, $zero, L_80009EF0
    if (ctx->r1 != 0) {
        // 0x80009EC8: addiu       $t7, $v0, -0x81
        ctx->r15 = ADD32(ctx->r2, -0X81);
            goto L_80009EF0;
    }
    // 0x80009EC8: addiu       $t7, $v0, -0x81
    ctx->r15 = ADD32(ctx->r2, -0X81);
    // 0x80009ECC: addiu       $t6, $v0, -0xF0
    ctx->r14 = ADD32(ctx->r2, -0XF0);
    // 0x80009ED0: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x80009ED4: beq         $at, $zero, L_8000A1AC
    if (ctx->r1 == 0) {
        // 0x80009ED8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8000A1AC;
    }
    // 0x80009ED8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80009EDC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80009EE0: addu        $at, $at, $t6
    gpr jr_addend_80009EE8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80009EE4: lw          $t6, -0x43C0($at)
    ctx->r14 = ADD32(ctx->r1, -0X43C0);
    // 0x80009EE8: jr          $t6
    // 0x80009EEC: nop

    switch (jr_addend_80009EE8 >> 2) {
        case 0: goto L_80009FC0; break;
        case 1: goto L_80009FD4; break;
        case 2: goto L_8000A024; break;
        case 3: goto L_8000A0FC; break;
        case 4: goto L_8000A114; break;
        case 5: goto L_8000A134; break;
        case 6: goto L_8000A154; break;
        case 7: goto L_8000A1AC; break;
        case 8: goto L_8000A1AC; break;
        case 9: goto L_8000A184; break;
        case 10: goto L_8000A1AC; break;
        case 11: goto L_8000A1A0; break;
        default: switch_error(__func__, 0x80009EE8, 0x800ABC40);
    }
    // 0x80009EEC: nop

L_80009EF0:
    // 0x80009EF0: sltiu       $at, $t7, 0x10
    ctx->r1 = ctx->r15 < 0X10 ? 1 : 0;
    // 0x80009EF4: beq         $at, $zero, L_8000A1AC
    if (ctx->r1 == 0) {
        // 0x80009EF8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8000A1AC;
    }
    // 0x80009EF8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80009EFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80009F00: addu        $at, $at, $t7
    gpr jr_addend_80009F08 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80009F04: lw          $t7, -0x4390($at)
    ctx->r15 = ADD32(ctx->r1, -0X4390);
    // 0x80009F08: jr          $t7
    // 0x80009F0C: nop

    switch (jr_addend_80009F08 >> 2) {
        case 0: goto L_80009F10; break;
        case 1: goto L_80009F24; break;
        case 2: goto L_80009F60; break;
        case 3: goto L_8000A1AC; break;
        case 4: goto L_80009F48; break;
        case 5: goto L_8000A1AC; break;
        case 6: goto L_8000A1AC; break;
        case 7: goto L_80009F24; break;
        case 8: goto L_8000A1AC; break;
        case 9: goto L_8000A1AC; break;
        case 10: goto L_8000A1AC; break;
        case 11: goto L_8000A1AC; break;
        case 12: goto L_8000A1AC; break;
        case 13: goto L_8000A1AC; break;
        case 14: goto L_8000A1AC; break;
        case 15: goto L_8000A164; break;
        default: switch_error(__func__, 0x80009F08, 0x800ABC70);
    }
    // 0x80009F0C: nop

L_80009F10:
    // 0x80009F10: lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2);
    // 0x80009F14: jal         0x800068F8
    // 0x80009F18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800068F8(rdram, ctx);
        goto after_0;
    // 0x80009F18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80009F1C: b           L_8000A1B0
    // 0x80009F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A1B0;
    // 0x80009F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80009F24:
    // 0x80009F24: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80009F28: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x80009F2C: jal         0x80006E0C
    // 0x80009F30: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    func_80006E0C(rdram, ctx);
        goto after_1;
    // 0x80009F30: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    after_1:
    // 0x80009F34: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80009F38: jal         0x8000A214
    // 0x80009F3C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    func_8000A214(rdram, ctx);
        goto after_2;
    // 0x80009F3C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x80009F40: b           L_8000A1B0
    // 0x80009F44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A1B0;
    // 0x80009F44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80009F48:
    // 0x80009F48: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80009F4C: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x80009F50: jal         0x80006E5C
    // 0x80009F54: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_80006E5C(rdram, ctx);
        goto after_3;
    // 0x80009F54: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x80009F58: b           L_8000A1B0
    // 0x80009F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A1B0;
    // 0x80009F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80009F60:
    // 0x80009F60: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x80009F64: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80009F68: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x80009F6C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80009F70: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80009F74: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80009F78: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80009F7C: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80009F80: addu        $v1, $a3, $t8
    ctx->r3 = ADD32(ctx->r7, ctx->r24);
    // 0x80009F84: lw          $t9, 0x2A30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2A30);
    // 0x80009F88: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80009F8C: beql        $t0, $zero, L_8000A1B0
    if (ctx->r8 == 0) {
        // 0x80009F90: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000A1B0;
    }
    goto skip_0;
    // 0x80009F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80009F94: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80009F98: bne         $a1, $zero, L_80009FB0
    if (ctx->r5 != 0) {
        // 0x80009F9C: nop
    
            goto L_80009FB0;
    }
    // 0x80009F9C: nop

    // 0x80009FA0: jal         0x8000DAE8
    // 0x80009FA4: addiu       $a0, $v1, 0x2A30
    ctx->r4 = ADD32(ctx->r3, 0X2A30);
    func_8000DAE8(rdram, ctx);
        goto after_4;
    // 0x80009FA4: addiu       $a0, $v1, 0x2A30
    ctx->r4 = ADD32(ctx->r3, 0X2A30);
    after_4:
    // 0x80009FA8: b           L_8000A1B0
    // 0x80009FAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A1B0;
    // 0x80009FAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80009FB0:
    // 0x80009FB0: jal         0x8000A1C0
    // 0x80009FB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8000A1C0(rdram, ctx);
        goto after_5;
    // 0x80009FB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80009FB8: b           L_8000A1B0
    // 0x80009FBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A1B0;
    // 0x80009FBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80009FC0:
    // 0x80009FC0: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80009FC4: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80009FC8: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x80009FCC: b           L_8000A1AC
    // 0x80009FD0: sb          $t1, 0x1DB2($a3)
    MEM_B(0X1DB2, ctx->r7) = ctx->r9;
        goto L_8000A1AC;
    // 0x80009FD0: sb          $t1, 0x1DB2($a3)
    MEM_B(0X1DB2, ctx->r7) = ctx->r9;
L_80009FD4:
    // 0x80009FD4: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80009FD8: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x80009FDC: lh          $t2, 0x1D90($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X1D90);
    // 0x80009FE0: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80009FE4: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x80009FE8: blez        $t2, L_8000A1AC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80009FEC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000A1AC;
    }
    // 0x80009FEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009FF0: lbu         $t4, 0x2A30($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X2A30);
L_80009FF4:
    // 0x80009FF4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80009FF8: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, 0X160);
    // 0x80009FFC: ori         $t7, $t4, 0x20
    ctx->r15 = ctx->r12 | 0X20;
    // 0x8000A000: sb          $t7, 0x28D0($v0)
    MEM_B(0X28D0, ctx->r2) = ctx->r15;
    // 0x8000A004: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x8000A008: sb          $t8, 0x28D0($v0)
    MEM_B(0X28D0, ctx->r2) = ctx->r24;
    // 0x8000A00C: lh          $t9, 0x1D90($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X1D90);
    // 0x8000A010: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000A014: bnel        $at, $zero, L_80009FF4
    if (ctx->r1 != 0) {
        // 0x8000A018: lbu         $t4, 0x2A30($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X2A30);
            goto L_80009FF4;
    }
    goto skip_1;
    // 0x8000A018: lbu         $t4, 0x2A30($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X2A30);
    skip_1:
    // 0x8000A01C: b           L_8000A1B0
    // 0x8000A020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A1B0;
    // 0x8000A020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000A024:
    // 0x8000A024: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8000A028: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A02C: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8000A030: bne         $t0, $at, L_8000A0AC
    if (ctx->r8 != ctx->r1) {
        // 0x8000A034: addiu       $a3, $a3, 0x4D10
        ctx->r7 = ADD32(ctx->r7, 0X4D10);
            goto L_8000A0AC;
    }
    // 0x8000A034: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x8000A038: lw          $a2, 0x1DAC($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X1DAC);
    // 0x8000A03C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000A044: blez        $a2, L_8000A0AC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000A048: nop
    
            goto L_8000A0AC;
    }
    // 0x8000A048: nop

L_8000A04C:
    // 0x8000A04C: lw          $t1, 0x2A2C($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X2A2C);
    // 0x8000A050: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000A054: addu        $v1, $a1, $t1
    ctx->r3 = ADD32(ctx->r5, ctx->r9);
    // 0x8000A058: lw          $t2, 0xB0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XB0);
    // 0x8000A05C: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x8000A060: beql        $t3, $zero, L_8000A0A4
    if (ctx->r11 == 0) {
        // 0x8000A064: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8000A0A4;
    }
    goto skip_2;
    // 0x8000A064: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_2:
    // 0x8000A068: lbu         $t4, 0x34($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X34);
    // 0x8000A06C: bnel        $t4, $zero, L_8000A0A4
    if (ctx->r12 != 0) {
        // 0x8000A070: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8000A0A4;
    }
    goto skip_3;
    // 0x8000A070: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_3:
    // 0x8000A074: lw          $t5, 0x44($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X44);
    // 0x8000A078: addiu       $v0, $v1, 0xB0
    ctx->r2 = ADD32(ctx->r3, 0XB0);
    // 0x8000A07C: lw          $t6, 0x50($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X50);
    // 0x8000A080: lbu         $t7, 0x3($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3);
    // 0x8000A084: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8000A088: beql        $t8, $zero, L_8000A0A4
    if (ctx->r24 == 0) {
        // 0x8000A08C: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8000A0A4;
    }
    goto skip_4;
    // 0x8000A08C: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_4:
    // 0x8000A090: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8000A094: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x8000A098: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8000A09C: lw          $a2, 0x1DAC($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X1DAC);
    // 0x8000A0A0: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_8000A0A4:
    // 0x8000A0A4: bne         $at, $zero, L_8000A04C
    if (ctx->r1 != 0) {
        // 0x8000A0A8: addiu       $a1, $a1, 0xD0
        ctx->r5 = ADD32(ctx->r5, 0XD0);
            goto L_8000A04C;
    }
    // 0x8000A0A8: addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
L_8000A0AC:
    // 0x8000A0AC: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8000A0B0: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x8000A0B4: lh          $t2, 0x1D90($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X1D90);
    // 0x8000A0B8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000A0BC: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x8000A0C0: blez        $t2, L_8000A1AC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8000A0C4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000A1AC;
    }
    // 0x8000A0C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A0C8: lbu         $t3, 0x2A30($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2A30);
L_8000A0CC:
    // 0x8000A0CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000A0D0: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, 0X160);
    // 0x8000A0D4: andi        $t6, $t3, 0xFFDF
    ctx->r14 = ctx->r11 & 0XFFDF;
    // 0x8000A0D8: sb          $t6, 0x28D0($v0)
    MEM_B(0X28D0, ctx->r2) = ctx->r14;
    // 0x8000A0DC: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x8000A0E0: sb          $t7, 0x28D0($v0)
    MEM_B(0X28D0, ctx->r2) = ctx->r15;
    // 0x8000A0E4: lh          $t8, 0x1D90($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X1D90);
    // 0x8000A0E8: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000A0EC: bnel        $at, $zero, L_8000A0CC
    if (ctx->r1 != 0) {
        // 0x8000A0F0: lbu         $t3, 0x2A30($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X2A30);
            goto L_8000A0CC;
    }
    goto skip_5;
    // 0x8000A0F0: lbu         $t3, 0x2A30($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2A30);
    skip_5:
    // 0x8000A0F4: b           L_8000A1B0
    // 0x8000A0F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A1B0;
    // 0x8000A0F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000A0FC:
    // 0x8000A0FC: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8000A100: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x8000A104: jal         0x80006A44
    // 0x8000A108: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    func_80006A44(rdram, ctx);
        goto after_6;
    // 0x8000A108: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    after_6:
    // 0x8000A10C: b           L_8000A1B0
    // 0x8000A110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A1B0;
    // 0x8000A110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000A114:
    // 0x8000A114: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8000A118: addiu       $a3, $a3, 0x60A4
    ctx->r7 = ADD32(ctx->r7, 0X60A4);
    // 0x8000A11C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8000A120: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x8000A124: jal         0x80006B14
    // 0x8000A128: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    func_80006B14(rdram, ctx);
        goto after_7;
    // 0x8000A128: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    after_7:
    // 0x8000A12C: b           L_8000A1B0
    // 0x8000A130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A1B0;
    // 0x8000A130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000A134:
    // 0x8000A134: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8000A138: addiu       $a3, $a3, 0x60A4
    ctx->r7 = ADD32(ctx->r7, 0X60A4);
    // 0x8000A13C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8000A140: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x8000A144: jal         0x80006B78
    // 0x8000A148: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    func_80006B78(rdram, ctx);
        goto after_8;
    // 0x8000A148: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    after_8:
    // 0x8000A14C: b           L_8000A1B0
    // 0x8000A150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A1B0;
    // 0x8000A150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000A154:
    // 0x8000A154: jal         0x80006CA8
    // 0x8000A158: lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2);
    func_80006CA8(rdram, ctx);
        goto after_9;
    // 0x8000A158: lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2);
    after_9:
    // 0x8000A15C: b           L_8000A1B0
    // 0x8000A160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A1B0;
    // 0x8000A160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000A164:
    // 0x8000A164: lbu         $t0, 0x1($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1);
    // 0x8000A168: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8000A16C: lhu         $t9, 0x4($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X4);
    // 0x8000A170: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x8000A174: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8000A178: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x8000A17C: b           L_8000A1AC
    // 0x8000A180: sh          $t9, 0x4F80($t2)
    MEM_H(0X4F80, ctx->r10) = ctx->r25;
        goto L_8000A1AC;
    // 0x8000A180: sh          $t9, 0x4F80($t2)
    MEM_H(0X4F80, ctx->r10) = ctx->r25;
L_8000A184:
    // 0x8000A184: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8000A188: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x8000A18C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8000A190: sb          $t3, 0x2A22($a3)
    MEM_B(0X2A22, ctx->r7) = ctx->r11;
    // 0x8000A194: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x8000A198: b           L_8000A1AC
    // 0x8000A19C: sb          $t4, 0x2A23($a3)
    MEM_B(0X2A23, ctx->r7) = ctx->r12;
        goto L_8000A1AC;
    // 0x8000A19C: sb          $t4, 0x2A23($a3)
    MEM_B(0X2A23, ctx->r7) = ctx->r12;
L_8000A1A0:
    // 0x8000A1A0: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x8000A1A4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000A1A8: sw          $t5, -0x5AF8($at)
    MEM_W(-0X5AF8, ctx->r1) = ctx->r13;
L_8000A1AC:
    // 0x8000A1AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000A1B0:
    // 0x8000A1B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000A1B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A1B8: jr          $ra
    // 0x8000A1BC: nop

    return;
    // 0x8000A1BC: nop

;}
RECOMP_FUNC void func_80680D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680D04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80680D08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80680D0C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80680D10: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80680D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680D18: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80680D1C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80680D20: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80680D24: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80680D28: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80680D2C: lui         $t2, 0x8068
    ctx->r10 = S32(RELOC_HI16(550, 0X21B4) << 16);
    // 0x80680D30: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80680D34: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80680D38: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80680D3C: lw          $t2, 0x25C4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(550, 0X21B4));
    // 0x80680D40: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80680D44: jal         0x80680930
    // 0x80680D48: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_80680930(rdram, ctx);
        goto after_0;
    // 0x80680D48: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x80680D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80680D50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80680D54: jr          $ra
    // 0x80680D58: nop

    return;
    // 0x80680D58: nop

;}
RECOMP_FUNC void func_80411844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80411844: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80411848: addu        $a3, $a0, $at
    ctx->r7 = ADD32(ctx->r4, ctx->r1);
    // 0x8041184C: lw          $t6, 0x39E4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39E4);
    // 0x80411850: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80411854: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80411858: beq         $t6, $zero, L_80411960
    if (ctx->r14 == 0) {
        // 0x8041185C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80411960;
    }
    // 0x8041185C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80411860: addu        $t0, $a0, $at
    ctx->r8 = ADD32(ctx->r4, ctx->r1);
    // 0x80411864: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80411868: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8041186C: lw          $t7, 0x39E8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X39E8);
L_80411870:
    // 0x80411870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80411874: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x80411878: beq         $t7, $zero, L_8041194C
    if (ctx->r15 == 0) {
        // 0x8041187C: sll         $t9, $a1, 4
        ctx->r25 = S32(ctx->r5 << 4);
            goto L_8041194C;
    }
    // 0x8041187C: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x80411880: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80411884: sll         $t9, $t9, 9
    ctx->r25 = S32(ctx->r25 << 9);
    // 0x80411888: addu        $t4, $a0, $t9
    ctx->r12 = ADD32(ctx->r4, ctx->r25);
    // 0x8041188C: addu        $t1, $t8, $t4
    ctx->r9 = ADD32(ctx->r24, ctx->r12);
    // 0x80411890: addiu       $t1, $t1, 0x5FC0
    ctx->r9 = ADD32(ctx->r9, 0X5FC0);
L_80411894:
    // 0x80411894: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x80411898: sh          $zero, 0x2($t1)
    MEM_H(0X2, ctx->r9) = 0;
    // 0x8041189C: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
    // 0x804118A0: sh          $zero, 0x6($t1)
    MEM_H(0X6, ctx->r9) = 0;
    // 0x804118A4: sh          $zero, 0x8($t1)
    MEM_H(0X8, ctx->r9) = 0;
    // 0x804118A8: sh          $zero, 0xA($t1)
    MEM_H(0XA, ctx->r9) = 0;
    // 0x804118AC: sb          $t2, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r10;
    // 0x804118B0: sb          $t2, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r10;
    // 0x804118B4: sb          $t2, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r10;
    // 0x804118B8: sb          $t2, 0xF($t1)
    MEM_B(0XF, ctx->r9) = ctx->r10;
    // 0x804118BC: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
    // 0x804118C0: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x804118C4: sh          $zero, 0x14($t1)
    MEM_H(0X14, ctx->r9) = 0;
    // 0x804118C8: sh          $zero, 0x16($t1)
    MEM_H(0X16, ctx->r9) = 0;
    // 0x804118CC: sh          $t3, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r11;
    // 0x804118D0: sh          $zero, 0x1A($t1)
    MEM_H(0X1A, ctx->r9) = 0;
    // 0x804118D4: sb          $t2, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r10;
    // 0x804118D8: sb          $t2, 0x1D($t1)
    MEM_B(0X1D, ctx->r9) = ctx->r10;
    // 0x804118DC: sb          $t2, 0x1E($t1)
    MEM_B(0X1E, ctx->r9) = ctx->r10;
    // 0x804118E0: sb          $t2, 0x1F($t1)
    MEM_B(0X1F, ctx->r9) = ctx->r10;
    // 0x804118E4: sh          $zero, 0x20($t1)
    MEM_H(0X20, ctx->r9) = 0;
    // 0x804118E8: sh          $zero, 0x22($t1)
    MEM_H(0X22, ctx->r9) = 0;
    // 0x804118EC: sh          $zero, 0x24($t1)
    MEM_H(0X24, ctx->r9) = 0;
    // 0x804118F0: sh          $zero, 0x26($t1)
    MEM_H(0X26, ctx->r9) = 0;
    // 0x804118F4: sh          $zero, 0x28($t1)
    MEM_H(0X28, ctx->r9) = 0;
    // 0x804118F8: sh          $t3, 0x2A($t1)
    MEM_H(0X2A, ctx->r9) = ctx->r11;
    // 0x804118FC: sb          $t2, 0x2C($t1)
    MEM_B(0X2C, ctx->r9) = ctx->r10;
    // 0x80411900: sb          $t2, 0x2D($t1)
    MEM_B(0X2D, ctx->r9) = ctx->r10;
    // 0x80411904: sb          $t2, 0x2E($t1)
    MEM_B(0X2E, ctx->r9) = ctx->r10;
    // 0x80411908: sb          $t2, 0x2F($t1)
    MEM_B(0X2F, ctx->r9) = ctx->r10;
    // 0x8041190C: sh          $zero, 0x30($t1)
    MEM_H(0X30, ctx->r9) = 0;
    // 0x80411910: sh          $zero, 0x32($t1)
    MEM_H(0X32, ctx->r9) = 0;
    // 0x80411914: sh          $zero, 0x34($t1)
    MEM_H(0X34, ctx->r9) = 0;
    // 0x80411918: sh          $zero, 0x36($t1)
    MEM_H(0X36, ctx->r9) = 0;
    // 0x8041191C: sh          $t3, 0x38($t1)
    MEM_H(0X38, ctx->r9) = ctx->r11;
    // 0x80411920: sh          $t3, 0x3A($t1)
    MEM_H(0X3A, ctx->r9) = ctx->r11;
    // 0x80411924: sb          $t2, 0x3C($t1)
    MEM_B(0X3C, ctx->r9) = ctx->r10;
    // 0x80411928: sb          $t2, 0x3D($t1)
    MEM_B(0X3D, ctx->r9) = ctx->r10;
    // 0x8041192C: sb          $t2, 0x3E($t1)
    MEM_B(0X3E, ctx->r9) = ctx->r10;
    // 0x80411930: sb          $t2, 0x3F($t1)
    MEM_B(0X3F, ctx->r9) = ctx->r10;
    // 0x80411934: lw          $t5, 0x39E8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X39E8);
    // 0x80411938: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8041193C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80411940: sltu        $at, $v0, $t5
    ctx->r1 = ctx->r2 < ctx->r13 ? 1 : 0;
    // 0x80411944: bne         $at, $zero, L_80411894
    if (ctx->r1 != 0) {
        // 0x80411948: addiu       $t1, $t1, 0x40
        ctx->r9 = ADD32(ctx->r9, 0X40);
            goto L_80411894;
    }
    // 0x80411948: addiu       $t1, $t1, 0x40
    ctx->r9 = ADD32(ctx->r9, 0X40);
L_8041194C:
    // 0x8041194C: lw          $t6, 0x39E4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X39E4);
    // 0x80411950: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80411954: sltu        $at, $a2, $t6
    ctx->r1 = ctx->r6 < ctx->r14 ? 1 : 0;
    // 0x80411958: bnel        $at, $zero, L_80411870
    if (ctx->r1 != 0) {
        // 0x8041195C: lw          $t7, 0x39E8($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X39E8);
            goto L_80411870;
    }
    goto skip_0;
    // 0x8041195C: lw          $t7, 0x39E8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X39E8);
    skip_0:
L_80411960:
    // 0x80411960: jr          $ra
    // 0x80411964: nop

    return;
    // 0x80411964: nop

;}
RECOMP_FUNC void func_8078A998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A998: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078A99C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078A9A0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078A9A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8078A9A8: jal         0x8078AD80
    // 0x8078A9AC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8078AD80(rdram, ctx);
        goto after_0;
    // 0x8078A9AC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8078A9B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8078A9B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8078A9B8: lw          $t7, 0x264($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X264);
    // 0x8078A9BC: beql        $t7, $zero, L_8078A9D4
    if (ctx->r15 == 0) {
        // 0x8078A9C0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8078A9D4;
    }
    goto skip_0;
    // 0x8078A9C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x8078A9C4: jal         0x8078A8B0
    // 0x8078A9C8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8078A8B0(rdram, ctx);
        goto after_1;
    // 0x8078A9C8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x8078A9CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8078A9D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8078A9D4:
    // 0x8078A9D4: jal         0x8005D87C
    // 0x8078A9D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8005D87C(rdram, ctx);
        goto after_2;
    // 0x8078A9D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8078A9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078A9E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078A9E4: jr          $ra
    // 0x8078A9E8: nop

    return;
    // 0x8078A9E8: nop

;}
RECOMP_FUNC void func_800245A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800245A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800245A4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800245A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800245AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800245B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800245B4: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x800245B8: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x800245BC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800245C0: bnel        $t6, $t7, L_800245E8
    if (ctx->r14 != ctx->r15) {
        // 0x800245C4: lbu         $v0, 0x18($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X18);
            goto L_800245E8;
    }
    goto skip_0;
    // 0x800245C4: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    skip_0:
    // 0x800245C8: lw          $t8, 0xC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XC);
    // 0x800245CC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800245D0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800245D4: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x800245D8: lw          $t1, 0x3DC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X3DC);
    // 0x800245DC: beql        $a3, $t1, L_80024658
    if (ctx->r7 == ctx->r9) {
        // 0x800245E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80024658;
    }
    goto skip_1;
    // 0x800245E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800245E4: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
L_800245E8:
    // 0x800245E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800245EC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800245F0: bne         $v0, $at, L_8002460C
    if (ctx->r2 != ctx->r1) {
        // 0x800245F4: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_8002460C;
    }
    // 0x800245F4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800245F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800245FC: jal         0x800520E0
    // 0x80024600: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    func_800520E0(rdram, ctx);
        goto after_0;
    // 0x80024600: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    after_0:
    // 0x80024604: b           L_80024658
    // 0x80024608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80024658;
    // 0x80024608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002460C:
    // 0x8002460C: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x80024610: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80024614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80024618: lbu         $t3, 0x155($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X155);
    // 0x8002461C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80024620: beq         $t3, $zero, L_8002464C
    if (ctx->r11 == 0) {
        // 0x80024624: nop
    
            goto L_8002464C;
    }
    // 0x80024624: nop

    // 0x80024628: beq         $v0, $at, L_8002464C
    if (ctx->r2 == ctx->r1) {
        // 0x8002462C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8002464C;
    }
    // 0x8002462C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80024630: beq         $v0, $at, L_8002464C
    if (ctx->r2 == ctx->r1) {
        // 0x80024634: lh          $a2, 0x2E($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X2E);
            goto L_8002464C;
    }
    // 0x80024634: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    // 0x80024638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002463C: jal         0x80024550
    // 0x80024640: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80024550(rdram, ctx);
        goto after_1;
    // 0x80024640: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80024644: b           L_80024658
    // 0x80024648: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80024658;
    // 0x80024648: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002464C:
    // 0x8002464C: jal         0x800520E0
    // 0x80024650: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    func_800520E0(rdram, ctx);
        goto after_2;
    // 0x80024650: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    after_2:
    // 0x80024654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80024658:
    // 0x80024658: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002465C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80024660: jr          $ra
    // 0x80024664: nop

    return;
    // 0x80024664: nop

;}
RECOMP_FUNC void func_8042701C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042701C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80427020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80427024: jal         0x80426FCC
    // 0x80427028: nop

    func_80426FCC(rdram, ctx);
        goto after_0;
    // 0x80427028: nop

    after_0:
    // 0x8042702C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80427030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80427034: jr          $ra
    // 0x80427038: nop

    return;
    // 0x80427038: nop

;}
RECOMP_FUNC void func_8002C57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C57C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C580: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C584: addiu       $a1, $a1, -0x3558
    ctx->r5 = ADD32(ctx->r5, -0X3558);
    // 0x8002C588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C58C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C590: jal         0x80028118
    // 0x8002C594: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C594: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002C598: jal         0x8002C4F0
    // 0x8002C59C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002C4F0(rdram, ctx);
        goto after_1;
    // 0x8002C59C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8002C5A0: jal         0x8002C51C
    // 0x8002C5A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002C51C(rdram, ctx);
        goto after_2;
    // 0x8002C5A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8002C5A8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8002C5AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002C5B0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002C5B4: sw          $v0, 0x138($t6)
    MEM_W(0X138, ctx->r14) = ctx->r2;
    // 0x8002C5B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C5BC: sb          $v0, -0x7684($at)
    MEM_B(-0X7684, ctx->r1) = ctx->r2;
    // 0x8002C5C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C5C4: jr          $ra
    // 0x8002C5C8: nop

    return;
    // 0x8002C5C8: nop

;}
RECOMP_FUNC void func_806E7328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E732C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E7330: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x806E7334: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806E7338: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806E733C: beq         $a1, $at, L_806E7360
    if (ctx->r5 == ctx->r1) {
        // 0x806E7340: addiu       $a0, $zero, 0x4E
        ctx->r4 = ADD32(0, 0X4E);
            goto L_806E7360;
    }
    // 0x806E7340: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x806E7344: jal         0x80067930
    // 0x806E7348: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x806E7348: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x806E734C: beq         $v0, $zero, L_806E7360
    if (ctx->r2 == 0) {
        // 0x806E7350: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_806E7360;
    }
    // 0x806E7350: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806E7354: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x806E7358: jal         0x80067878
    // 0x806E735C: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x806E735C: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    after_1:
L_806E7360:
    // 0x806E7360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E7364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E7368: jr          $ra
    // 0x806E736C: nop

    return;
    // 0x806E736C: nop

;}
RECOMP_FUNC void func_80072500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072508: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007250C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80072510: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072514: sw          $t6, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r14;
    // 0x80072518: addiu       $a0, $a0, -0x26D0
    ctx->r4 = ADD32(ctx->r4, -0X26D0);
    // 0x8007251C: jal         0x8008AFE0
    // 0x80072520: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osJamMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80072520: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80072524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007252C: jr          $ra
    // 0x80072530: nop

    return;
    // 0x80072530: nop

;}
RECOMP_FUNC void func_80446518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446518: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044651C: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x80446520: jr          $ra
    // 0x80446524: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    return;
    // 0x80446524: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8064E0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E0F8: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x8064E0FC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8064E100: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8064E104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8064E108: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8064E10C: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
    // 0x8064E110: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8064E114: jr          $ra
    // 0x8064E118: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x8064E118: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8003B764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B764: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8003B768: lw          $v0, -0x77F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F0);
    // 0x8003B76C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003B770: addiu       $a3, $zero, 0x4002
    ctx->r7 = ADD32(0, 0X4002);
    // 0x8003B774: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    // 0x8003B778: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B77C: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x8003B780: beq         $a1, $zero, L_8003B7CC
    if (ctx->r5 == 0) {
        // 0x8003B784: nop
    
            goto L_8003B7CC;
    }
    // 0x8003B784: nop

L_8003B788:
    // 0x8003B788: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003B78C: beq         $v0, $zero, L_8003B7C4
    if (ctx->r2 == 0) {
        // 0x8003B790: nop
    
            goto L_8003B7C4;
    }
    // 0x8003B790: nop

    // 0x8003B794: beq         $a2, $v0, L_8003B7BC
    if (ctx->r6 == ctx->r2) {
        // 0x8003B798: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_8003B7BC;
    }
    // 0x8003B798: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8003B79C: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x8003B7A0: bnel        $a3, $t6, L_8003B7C0
    if (ctx->r7 != ctx->r14) {
        // 0x8003B7A4: sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5 << 16);
            goto L_8003B7C0;
    }
    goto skip_0;
    // 0x8003B7A4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    skip_0:
    // 0x8003B7A8: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    // 0x8003B7AC: beql        $t7, $zero, L_8003B7C0
    if (ctx->r15 == 0) {
        // 0x8003B7B0: sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5 << 16);
            goto L_8003B7C0;
    }
    goto skip_1;
    // 0x8003B7B0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    skip_1:
    // 0x8003B7B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003B7B8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8003B7BC:
    // 0x8003B7BC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
L_8003B7C0:
    // 0x8003B7C0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_8003B7C4:
    // 0x8003B7C4: bne         $a1, $zero, L_8003B788
    if (ctx->r5 != 0) {
        // 0x8003B7C8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8003B788;
    }
    // 0x8003B7C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8003B7CC:
    // 0x8003B7CC: jr          $ra
    // 0x8003B7D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8003B7D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8057C460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057C464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C468: jal         0x8057BB68
    // 0x8057C46C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8057BB68(rdram, ctx);
        goto after_0;
    // 0x8057C46C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057C470: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8057C474: lw          $t6, -0x7280($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7280);
    // 0x8057C478: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8057C47C: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x8057C480: bne         $at, $zero, L_8057C490
    if (ctx->r1 != 0) {
        // 0x8057C484: nop
    
            goto L_8057C490;
    }
    // 0x8057C484: nop

    // 0x8057C488: jal         0x8057C6B0
    // 0x8057C48C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8057C6B0(rdram, ctx);
        goto after_1;
    // 0x8057C48C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
L_8057C490:
    // 0x8057C490: jal         0x8057BD84
    // 0x8057C494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8057BD84(rdram, ctx);
        goto after_2;
    // 0x8057C494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8057C498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057C49C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057C4A0: jr          $ra
    // 0x8057C4A4: nop

    return;
    // 0x8057C4A4: nop

;}
RECOMP_FUNC void func_80019B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019B5C: beq         $a0, $zero, L_80019B8C
    if (ctx->r4 == 0) {
        // 0x80019B60: nop
    
            goto L_80019B8C;
    }
    // 0x80019B60: nop

    // 0x80019B64: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80019B68: beq         $v0, $zero, L_80019B8C
    if (ctx->r2 == 0) {
        // 0x80019B6C: nop
    
            goto L_80019B8C;
    }
    // 0x80019B6C: nop

    // 0x80019B70: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80019B74: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80019B78: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80019B7C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80019B80: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80019B84: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80019B88: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
L_80019B8C:
    // 0x80019B8C: jr          $ra
    // 0x80019B90: nop

    return;
    // 0x80019B90: nop

;}
RECOMP_FUNC void func_80027820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027828: jal         0x80024748
    // 0x8002782C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024748(rdram, ctx);
        goto after_0;
    // 0x8002782C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027830: beq         $v0, $zero, L_8002788C
    if (ctx->r2 == 0) {
        // 0x80027834: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8002788C;
    }
    // 0x80027834: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80027838: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002783C: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80027840: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x80027844: beql        $t7, $zero, L_80027890
    if (ctx->r15 == 0) {
        // 0x80027848: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80027890;
    }
    goto skip_0;
    // 0x80027848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002784C: lwc1        $f4, 0x120($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X120);
    // 0x80027850: lwc1        $f6, 0x68($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80027854: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80027858: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x8002785C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80027860: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80027864: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80027868: addiu       $t0, $t0, 0x4748
    ctx->r8 = ADD32(ctx->r8, 0X4748);
    // 0x8002786C: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80027870: nop

    // 0x80027874: bc1fl       L_80027890
    if (!c1cs) {
        // 0x80027878: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80027890;
    }
    goto skip_1;
    // 0x80027878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8002787C: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
    // 0x80027880: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80027884: sb          $t9, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r25;
    // 0x80027888: sw          $t0, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r8;
L_8002788C:
    // 0x8002788C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80027890:
    // 0x80027890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80027898: jr          $ra
    // 0x8002789C: nop

    return;
    // 0x8002789C: nop

;}
RECOMP_FUNC void func_80027744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027744: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80027748: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002774C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80027750: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80027754: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80027758: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002775C: lw          $t7, 0x78($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X78);
    // 0x80027760: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80027764: bne         $t7, $zero, L_800277F8
    if (ctx->r15 != 0) {
        // 0x80027768: nop
    
            goto L_800277F8;
    }
    // 0x80027768: nop

    // 0x8002776C: lwc1        $f4, -0x7678($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7678);
    // 0x80027770: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x80027774: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80027778: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8002777C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80027780: jal         0x8006593C
    // 0x80027784: nop

    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80027784: nop

    after_0:
    // 0x80027788: sltiu       $at, $v0, 0x14
    ctx->r1 = ctx->r2 < 0X14 ? 1 : 0;
    // 0x8002778C: beq         $at, $zero, L_80027798
    if (ctx->r1 == 0) {
        // 0x80027790: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80027798;
    }
    // 0x80027790: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80027794: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_80027798:
    // 0x80027798: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8002779C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800277A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800277A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800277A8: jal         0x80024D30
    // 0x800277AC: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    func_80024D30(rdram, ctx);
        goto after_1;
    // 0x800277AC: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_1:
    // 0x800277B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800277B4: bne         $v0, $at, L_800277C4
    if (ctx->r2 != ctx->r1) {
        // 0x800277B8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800277C4;
    }
    // 0x800277B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800277BC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800277C0: sw          $t1, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r9;
L_800277C4:
    // 0x800277C4: lw          $t2, 0x14C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14C);
    // 0x800277C8: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800277CC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800277D0: bne         $t2, $at, L_800277F0
    if (ctx->r10 != ctx->r1) {
        // 0x800277D4: addiu       $t3, $zero, 0x9
        ctx->r11 = ADD32(0, 0X9);
            goto L_800277F0;
    }
    // 0x800277D4: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x800277D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800277DC: sb          $v0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r2;
    // 0x800277E0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800277E4: sb          $v0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r2;
    // 0x800277E8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800277EC: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
L_800277F0:
    // 0x800277F0: b           L_800277F8
    // 0x800277F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800277F8;
    // 0x800277F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800277F8:
    // 0x800277F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800277FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80027800: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80027804: jr          $ra
    // 0x80027808: nop

    return;
    // 0x80027808: nop

;}
RECOMP_FUNC void func_804B6A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6A4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804B6A50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B6A54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B6A58: jal         0x804B66F8
    // 0x804B6A5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804B66F8(rdram, ctx);
        goto after_0;
    // 0x804B6A5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B6A60: bne         $v0, $zero, L_804B6AAC
    if (ctx->r2 != 0) {
        // 0x804B6A64: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_804B6AAC;
    }
    // 0x804B6A64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804B6A68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804B6A6C: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x804B6A70: jal         0x804B6524
    // 0x804B6A74: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    func_804B6524(rdram, ctx);
        goto after_1;
    // 0x804B6A74: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x804B6A78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804B6A7C: bne         $v0, $at, L_804B6A94
    if (ctx->r2 != ctx->r1) {
        // 0x804B6A80: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_804B6A94;
    }
    // 0x804B6A80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804B6A84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6A88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804B6A8C: jal         0x804B6FF0
    // 0x804B6A90: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_804B6FF0(rdram, ctx);
        goto after_2;
    // 0x804B6A90: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_2:
L_804B6A94:
    // 0x804B6A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B6A98: jal         0x804B6580
    // 0x804B6A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_804B6580(rdram, ctx);
        goto after_3;
    // 0x804B6A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x804B6AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B6AA4: jal         0x804B6580
    // 0x804B6AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804B6580(rdram, ctx);
        goto after_4;
    // 0x804B6AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_804B6AAC:
    // 0x804B6AAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804B6AB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B6AB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804B6AB8: jr          $ra
    // 0x804B6ABC: nop

    return;
    // 0x804B6ABC: nop

;}
RECOMP_FUNC void func_807AE118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE118: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AE11C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AE120: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807AE124: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AE128: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x807AE12C: jal         0x80044658
    // 0x807AE130: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80044658(rdram, ctx);
        goto after_0;
    // 0x807AE130: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x807AE134: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807AE138: jal         0x80044658
    // 0x807AE13C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    func_80044658(rdram, ctx);
        goto after_1;
    // 0x807AE13C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_1:
    // 0x807AE140: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807AE144: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807AE148: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x807AE14C: jal         0x807ADF40
    // 0x807AE150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_807ADF40(rdram, ctx);
        goto after_2;
    // 0x807AE150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x807AE154: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807AE158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE15C: jal         0x807AEA24
    // 0x807AE160: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_807AEA24(rdram, ctx);
        goto after_3;
    // 0x807AE160: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_3:
    // 0x807AE164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AE168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AE16C: jr          $ra
    // 0x807AE170: nop

    return;
    // 0x807AE170: nop

;}
RECOMP_FUNC void func_806E82B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E82B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E82B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E82B8: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806E82BC: addiu       $at, $zero, 0x44E1
    ctx->r1 = ADD32(0, 0X44E1);
    // 0x806E82C0: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(667, 0X1640) << 16);
    // 0x806E82C4: beq         $v0, $at, L_806E82DC
    if (ctx->r2 == ctx->r1) {
        // 0x806E82C8: addiu       $at, $zero, 0x45D0
        ctx->r1 = ADD32(0, 0X45D0);
            goto L_806E82DC;
    }
    // 0x806E82C8: addiu       $at, $zero, 0x45D0
    ctx->r1 = ADD32(0, 0X45D0);
    // 0x806E82CC: beq         $v0, $at, L_806E832C
    if (ctx->r2 == ctx->r1) {
        // 0x806E82D0: nop
    
            goto L_806E832C;
    }
    // 0x806E82D0: nop

    // 0x806E82D4: b           L_806E8338
    // 0x806E82D8: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(667, 0X1550) << 16);
        goto L_806E8338;
    // 0x806E82D8: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(667, 0X1550) << 16);
L_806E82DC:
    // 0x806E82DC: lw          $t6, -0x6710($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(667, 0X1640));
    // 0x806E82E0: lui         $a0, 0x806F
    ctx->r4 = S32(RELOC_HI16(667, 0X1890) << 16);
    // 0x806E82E4: addiu       $a0, $a0, -0x64C0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(667, 0X1890));
    // 0x806E82E8: bne         $t6, $zero, L_806E8320
    if (ctx->r14 != 0) {
        // 0x806E82EC: lui         $a1, 0x806F
        ctx->r5 = S32(RELOC_HI16(667, 0X18A0) << 16);
            goto L_806E8320;
    }
    // 0x806E82EC: lui         $a1, 0x806F
    ctx->r5 = S32(RELOC_HI16(667, 0X18A0) << 16);
    // 0x806E82F0: addiu       $a1, $a1, -0x64B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(667, 0X18A0));
    // 0x806E82F4: jal         0x8004667C
    // 0x806E82F8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x806E82F8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x806E82FC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x806E8300: lui         $a2, 0x806F
    ctx->r6 = S32(RELOC_HI16(667, 0X9C) << 16);
    // 0x806E8304: addiu       $a2, $a2, -0x7CB4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(667, 0X9C));
    // 0x806E8308: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x806E830C: jal         0x80057B28
    // 0x806E8310: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x806E8310: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_1:
    // 0x806E8314: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806E8318: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X1640) << 16);
    // 0x806E831C: sw          $t7, -0x6710($at)
    MEM_W((int16_t)RELOC_LO16(667, 0X1640), ctx->r1) = ctx->r15;
L_806E8320:
    // 0x806E8320: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(667, 0X1550) << 16);
    // 0x806E8324: b           L_806E833C
    // 0x806E8328: addiu       $v0, $v0, -0x6800
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(667, 0X1550));
        goto L_806E833C;
    // 0x806E8328: addiu       $v0, $v0, -0x6800
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(667, 0X1550));
L_806E832C:
    // 0x806E832C: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(667, 0X15A8) << 16);
    // 0x806E8330: b           L_806E833C
    // 0x806E8334: addiu       $v0, $v0, -0x67A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(667, 0X15A8));
        goto L_806E833C;
    // 0x806E8334: addiu       $v0, $v0, -0x67A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(667, 0X15A8));
L_806E8338:
    // 0x806E8338: addiu       $v0, $v0, -0x6800
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(667, 0X1550));
L_806E833C:
    // 0x806E833C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E8340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E8344: jr          $ra
    // 0x806E8348: nop

    return;
    // 0x806E8348: nop

;}
RECOMP_FUNC void func_804B66F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B66F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804B66FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B6700: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x804B6704: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804B6708: jal         0x800692D4
    // 0x804B670C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x804B670C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x804B6710: bne         $v0, $zero, L_804B6720
    if (ctx->r2 != 0) {
        // 0x804B6714: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_804B6720;
    }
    // 0x804B6714: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804B6718: b           L_804B6780
    // 0x804B671C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804B6780;
    // 0x804B671C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804B6720:
    // 0x804B6720: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x804B6724: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804B6728: sw          $zero, 0x44($t8)
    MEM_W(0X44, ctx->r24) = 0;
    // 0x804B672C: jal         0x8005FE48
    // 0x804B6730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x804B6730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x804B6734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804B6738: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x804B673C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x804B6740: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x804B6744: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804B6748: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804B674C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804B6750: lui         $at, 0x804B
    ctx->r1 = S32(RELOC_HI16(182, 0X11B8) << 16);
    // 0x804B6754: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x804B6758: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x804B675C: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    // 0x804B6760: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x804B6764: lwc1        $f16, 0x7458($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(182, 0X11B8));
    // 0x804B6768: lui         $t9, 0x804B
    ctx->r25 = S32(RELOC_HI16(182, 0X3C0) << 16);
    // 0x804B676C: addiu       $t9, $t9, 0x6660
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(182, 0X3C0));
    // 0x804B6770: swc1        $f16, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f16.u32l;
    // 0x804B6774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804B6778: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804B677C: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
L_804B6780:
    // 0x804B6780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B6784: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804B6788: jr          $ra
    // 0x804B678C: nop

    return;
    // 0x804B678C: nop

;}
RECOMP_FUNC void func_8004D23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D23C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004D240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D244: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004D248: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004D24C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8004D250: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8004D254: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8004D258: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8004D25C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8004D260: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8004D264: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004D268: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8004D26C: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004D270: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004D274: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8004D278: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8004D27C: beql        $v1, $zero, L_8004D2D0
    if (ctx->r3 == 0) {
        // 0x8004D280: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004D2D0;
    }
    goto skip_0;
    // 0x8004D280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004D284: beql        $v1, $at, L_8004D2D0
    if (ctx->r3 == ctx->r1) {
        // 0x8004D288: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004D2D0;
    }
    goto skip_1;
    // 0x8004D288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004D28C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8004D290: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004D294: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x8004D298: beq         $v1, $at, L_8004D2CC
    if (ctx->r3 == ctx->r1) {
        // 0x8004D29C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004D2CC;
    }
    // 0x8004D29C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004D2A0: beq         $v1, $at, L_8004D2CC
    if (ctx->r3 == ctx->r1) {
        // 0x8004D2A4: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_8004D2CC;
    }
    // 0x8004D2A4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8004D2A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8004D2AC: jal         0x80047AB8
    // 0x8004D2B0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8004D2B0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x8004D2B4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8004D2B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8004D2BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8004D2C0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8004D2C4: jalr        $t9
    // 0x8004D2C8: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8004D2C8: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_1:
L_8004D2CC:
    // 0x8004D2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004D2D0:
    // 0x8004D2D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004D2D4: jr          $ra
    // 0x8004D2D8: nop

    return;
    // 0x8004D2D8: nop

;}
RECOMP_FUNC void func_8045F2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F2A0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8045F2A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8045F2A8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8045F2AC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8045F2B0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8045F2B4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8045F2B8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8045F2BC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8045F2C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8045F2C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8045F2C8: lw          $s5, 0x174($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X174);
    // 0x8045F2CC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045F2D0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8045F2D4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8045F2D8: jal         0x80049D74
    // 0x8045F2DC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x8045F2DC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    after_0:
    // 0x8045F2E0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8045F2E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8045F2E8: lui         $s6, 0x8005
    ctx->r22 = S32(0X8005 << 16);
    // 0x8045F2EC: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8045F2F0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8045F2F4: addiu       $s6, $s6, -0x3078
    ctx->r22 = ADD32(ctx->r22, -0X3078);
    // 0x8045F2F8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8045F2FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8045F300: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8045F304: lui         $s4, 0x8005
    ctx->r20 = S32(0X8005 << 16);
    // 0x8045F308: bc1fl       L_8045F38C
    if (!c1cs) {
        // 0x8045F30C: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8045F38C;
    }
    goto skip_0;
    // 0x8045F30C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x8045F310: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8045F314: addiu       $s4, $s4, -0x2B40
    ctx->r20 = ADD32(ctx->r20, -0X2B40);
    // 0x8045F318: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
L_8045F31C:
    // 0x8045F31C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8045F320: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8045F324: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x8045F328: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8045F32C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8045F330: jal         0x8004D150
    // 0x8045F334: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x8045F334: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_1:
    // 0x8045F338: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8045F33C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8045F340: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8045F344: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8045F348: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x8045F34C: lbu         $t1, 0x14($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X14);
    // 0x8045F350: beql        $t1, $zero, L_8045F374
    if (ctx->r9 == 0) {
        // 0x8045F354: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8045F374;
    }
    goto skip_1;
    // 0x8045F354: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8045F358: jal         0x8004D618
    // 0x8045F35C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_8004D618(rdram, ctx);
        goto after_2;
    // 0x8045F35C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_2:
    // 0x8045F360: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8045F364: sllv        $t3, $t2, $s0
    ctx->r11 = S32(ctx->r10 << (ctx->r16 & 31));
    // 0x8045F368: or          $s3, $t3, $s3
    ctx->r19 = ctx->r11 | ctx->r19;
    // 0x8045F36C: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x8045F370: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8045F374:
    // 0x8045F374: sltiu       $at, $s0, 0x6
    ctx->r1 = ctx->r16 < 0X6 ? 1 : 0;
    // 0x8045F378: bnel        $at, $zero, L_8045F31C
    if (ctx->r1 != 0) {
        // 0x8045F37C: sll         $s1, $s0, 2
        ctx->r17 = S32(ctx->r16 << 2);
            goto L_8045F31C;
    }
    goto skip_2;
    // 0x8045F37C: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    skip_2:
    // 0x8045F380: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8045F384: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8045F388: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8045F38C:
    // 0x8045F38C: lui         $s6, 0x8005
    ctx->r22 = S32(0X8005 << 16);
    // 0x8045F390: addiu       $s6, $s6, -0x2F94
    ctx->r22 = ADD32(ctx->r22, -0X2F94);
    // 0x8045F394: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8045F398: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x8045F39C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8045F3A0: lui         $s4, 0x8005
    ctx->r20 = S32(0X8005 << 16);
    // 0x8045F3A4: bc1fl       L_8045F424
    if (!c1cs) {
        // 0x8045F3A8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8045F424;
    }
    goto skip_3;
    // 0x8045F3A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x8045F3AC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8045F3B0: addiu       $s4, $s4, -0x2A94
    ctx->r20 = ADD32(ctx->r20, -0X2A94);
    // 0x8045F3B4: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
L_8045F3B8:
    // 0x8045F3B8: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8045F3BC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8045F3C0: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x8045F3C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8045F3C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8045F3CC: jal         0x8004D150
    // 0x8045F3D0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x8045F3D0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_3:
    // 0x8045F3D4: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8045F3D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8045F3DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8045F3E0: lw          $t6, 0x40($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X40);
    // 0x8045F3E4: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8045F3E8: lbu         $t8, 0x14($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X14);
    // 0x8045F3EC: beql        $t8, $zero, L_8045F414
    if (ctx->r24 == 0) {
        // 0x8045F3F0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8045F414;
    }
    goto skip_4;
    // 0x8045F3F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x8045F3F4: jal         0x8004D618
    // 0x8045F3F8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x8045F3F8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_4:
    // 0x8045F3FC: addiu       $t9, $s0, 0x1A
    ctx->r25 = ADD32(ctx->r16, 0X1A);
    // 0x8045F400: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x8045F404: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x8045F408: or          $s3, $t1, $s3
    ctx->r19 = ctx->r9 | ctx->r19;
    // 0x8045F40C: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x8045F410: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8045F414:
    // 0x8045F414: sltiu       $at, $s0, 0xC
    ctx->r1 = ctx->r16 < 0XC ? 1 : 0;
    // 0x8045F418: bnel        $at, $zero, L_8045F3B8
    if (ctx->r1 != 0) {
        // 0x8045F41C: sll         $s1, $s0, 2
        ctx->r17 = S32(ctx->r16 << 2);
            goto L_8045F3B8;
    }
    goto skip_5;
    // 0x8045F41C: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    skip_5:
    // 0x8045F420: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8045F424:
    // 0x8045F424: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8045F428: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8045F42C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8045F430: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8045F434: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8045F438: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8045F43C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8045F440: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8045F444: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8045F448: jr          $ra
    // 0x8045F44C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8045F44C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_807ACD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ACD74: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807ACD78: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807ACD7C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807ACD80: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807ACD84: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807ACD88: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807ACD8C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807ACD90: lui         $t1, 0x807B
    ctx->r9 = S32(RELOC_HI16(859, 0X25E4) << 16);
    // 0x807ACD94: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807ACD98: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807ACD9C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807ACDA0: lw          $t1, -0x13BC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(859, 0X25E4));
    // 0x807ACDA4: jr          $ra
    // 0x807ACDA8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807ACDA8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80034EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034EA8: jal         0x80021958
    // 0x80034EAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80034EAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80034EB0: bne         $v0, $zero, L_80034EC0
    if (ctx->r2 != 0) {
        // 0x80034EB4: nop
    
            goto L_80034EC0;
    }
    // 0x80034EB4: nop

    // 0x80034EB8: b           L_80034EF4
    // 0x80034EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034EF4;
    // 0x80034EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034EC0:
    // 0x80034EC0: jal         0x80041698
    // 0x80034EC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80041698(rdram, ctx);
        goto after_1;
    // 0x80034EC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80034EC8: beq         $v0, $zero, L_80034ED8
    if (ctx->r2 == 0) {
        // 0x80034ECC: nop
    
            goto L_80034ED8;
    }
    // 0x80034ECC: nop

    // 0x80034ED0: b           L_80034EF4
    // 0x80034ED4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034EF4;
    // 0x80034ED4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034ED8:
    // 0x80034ED8: jal         0x8003449C
    // 0x80034EDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003449C(rdram, ctx);
        goto after_2;
    // 0x80034EDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80034EE0: bnel        $v0, $zero, L_80034EF4
    if (ctx->r2 != 0) {
        // 0x80034EE4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80034EF4;
    }
    goto skip_0;
    // 0x80034EE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80034EE8: b           L_80034EF4
    // 0x80034EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034EF4;
    // 0x80034EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034EF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80034EF4:
    // 0x80034EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034EF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034EFC: jr          $ra
    // 0x80034F00: nop

    return;
    // 0x80034F00: nop

;}
RECOMP_FUNC void func_804E9F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9F10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804E9F14: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_804E9F18:
    // 0x804E9F18: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x804E9F1C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804E9F20: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x804E9F24: sb          $t6, -0x4($a2)
    MEM_B(-0X4, ctx->r6) = ctx->r14;
    // 0x804E9F28: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x804E9F2C: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x804E9F30: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x804E9F34: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804E9F38: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x804E9F3C: sw          $t9, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->r25;
    // 0x804E9F40: lbu         $t0, -0x3($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X3);
    // 0x804E9F44: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804E9F48: sb          $t0, -0x3($a2)
    MEM_B(-0X3, ctx->r6) = ctx->r8;
    // 0x804E9F4C: lbu         $t2, -0x3($a0)
    ctx->r10 = MEM_BU(ctx->r4, -0X3);
    // 0x804E9F50: lbu         $t1, -0x3($a1)
    ctx->r9 = MEM_BU(ctx->r5, -0X3);
    // 0x804E9F54: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x804E9F58: sw          $t3, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->r11;
    // 0x804E9F5C: lbu         $t4, -0x2($a0)
    ctx->r12 = MEM_BU(ctx->r4, -0X2);
    // 0x804E9F60: sb          $t4, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r12;
    // 0x804E9F64: lbu         $t6, -0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, -0X2);
    // 0x804E9F68: lbu         $t5, -0x2($a1)
    ctx->r13 = MEM_BU(ctx->r5, -0X2);
    // 0x804E9F6C: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x804E9F70: sw          $t7, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->r15;
    // 0x804E9F74: lbu         $t8, -0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, -0X1);
    // 0x804E9F78: sb          $t8, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r24;
    // 0x804E9F7C: lbu         $t0, -0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X1);
    // 0x804E9F80: lbu         $t9, -0x1($a1)
    ctx->r25 = MEM_BU(ctx->r5, -0X1);
    // 0x804E9F84: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x804E9F88: bne         $v0, $v1, L_804E9F18
    if (ctx->r2 != ctx->r3) {
        // 0x804E9F8C: sw          $t1, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = ctx->r9;
            goto L_804E9F18;
    }
    // 0x804E9F8C: sw          $t1, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r9;
    // 0x804E9F90: jr          $ra
    // 0x804E9F94: nop

    return;
    // 0x804E9F94: nop

;}
RECOMP_FUNC void func_8066DB44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066DB44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066DB48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066DB4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8066DB50: jal         0x8004700C
    // 0x8066DB54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8066DB54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8066DB58: beq         $v0, $zero, L_8066DB74
    if (ctx->r2 == 0) {
        // 0x8066DB5C: lbu         $t6, 0x1F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1F);
            goto L_8066DB74;
    }
    // 0x8066DB5C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8066DB60: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8066DB64: bnel        $t6, $at, L_8066DB78
    if (ctx->r14 != ctx->r1) {
        // 0x8066DB68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066DB78;
    }
    goto skip_0;
    // 0x8066DB68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066DB6C: jal         0x8066DA28
    // 0x8066DB70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8066DA28(rdram, ctx);
        goto after_1;
    // 0x8066DB70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_8066DB74:
    // 0x8066DB74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066DB78:
    // 0x8066DB78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066DB7C: jr          $ra
    // 0x8066DB80: nop

    return;
    // 0x8066DB80: nop

;}
RECOMP_FUNC void func_8067A5FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067A5FC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067A600: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8067A604: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8067A608: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8067A60C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067A610: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8067A614: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067A618: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8067A61C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8067A620: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067A624: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8067A628: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067A62C: nop

    // 0x8067A630: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8067A634: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067A638: nop

    // 0x8067A63C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067A640: beql        $t7, $zero, L_8067A690
    if (ctx->r15 == 0) {
        // 0x8067A644: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_8067A690;
    }
    goto skip_0;
    // 0x8067A644: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x8067A648: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8067A64C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067A650: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8067A654: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067A658: nop

    // 0x8067A65C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8067A660: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067A664: nop

    // 0x8067A668: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067A66C: bne         $t7, $zero, L_8067A684
    if (ctx->r15 != 0) {
        // 0x8067A670: nop
    
            goto L_8067A684;
    }
    // 0x8067A670: nop

    // 0x8067A674: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8067A678: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067A67C: b           L_8067A69C
    // 0x8067A680: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8067A69C;
    // 0x8067A680: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8067A684:
    // 0x8067A684: b           L_8067A69C
    // 0x8067A688: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8067A69C;
    // 0x8067A688: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8067A68C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_8067A690:
    // 0x8067A690: nop

    // 0x8067A694: bltz        $t7, L_8067A684
    if (SIGNED(ctx->r15) < 0) {
        // 0x8067A698: nop
    
            goto L_8067A684;
    }
    // 0x8067A698: nop

L_8067A69C:
    // 0x8067A69C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8067A6A0: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8067A6A4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8067A6A8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8067A6AC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8067A6B0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8067A6B4: bgez        $t9, L_8067A6CC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8067A6B8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8067A6CC;
    }
    // 0x8067A6B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8067A6BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8067A6C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067A6C4: nop

    // 0x8067A6C8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8067A6CC:
    // 0x8067A6CC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8067A6D0: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x8067A6D4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067A6D8: bc1fl       L_8067A6F0
    if (!c1cs) {
        // 0x8067A6DC: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_8067A6F0;
    }
    goto skip_1;
    // 0x8067A6DC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_1:
    // 0x8067A6E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067A6E4: nop

    // 0x8067A6E8: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8067A6EC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_8067A6F0:
    // 0x8067A6F0: nop

    // 0x8067A6F4: bc1fl       L_8067A708
    if (!c1cs) {
        // 0x8067A6F8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8067A708;
    }
    goto skip_2;
    // 0x8067A6F8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
    // 0x8067A6FC: b           L_8067A708
    // 0x8067A700: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_8067A708;
    // 0x8067A700: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8067A704: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8067A708:
    // 0x8067A708: jr          $ra
    // 0x8067A70C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x8067A70C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80582EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80582EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80582EA8: jal         0x80580C70
    // 0x80582EAC: nop

    func_80580C70(rdram, ctx);
        goto after_0;
    // 0x80582EAC: nop

    after_0:
    // 0x80582EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80582EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80582EB8: jr          $ra
    // 0x80582EBC: nop

    return;
    // 0x80582EBC: nop

;}
RECOMP_FUNC void func_805691F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805691F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805691F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805691FC: jal         0x80568710
    // 0x80569200: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80569200: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80569204: jal         0x80567AAC
    // 0x80569208: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80567AAC(rdram, ctx);
        goto after_1;
    // 0x80569208: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8056920C: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X221C) << 16);
    // 0x80569210: lwc1        $f4, -0x6834($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X221C));
    // 0x80569214: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80569218: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8056921C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80569220: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2220) << 16);
    // 0x80569224: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x80569228: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x8056922C: lwc1        $f8, -0x6830($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2220));
    // 0x80569230: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80569234: jal         0x80569310
    // 0x80569238: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    func_80569310(rdram, ctx);
        goto after_2;
    // 0x80569238: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    after_2:
    // 0x8056923C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80569240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80569244: jr          $ra
    // 0x80569248: nop

    return;
    // 0x80569248: nop

;}
RECOMP_FUNC void func_804444C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804444C4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x804444C8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804444CC: jr          $ra
    // 0x804444D0: sb          $t6, -0x71F4($at)
    MEM_B(-0X71F4, ctx->r1) = ctx->r14;
    return;
    // 0x804444D0: sb          $t6, -0x71F4($at)
    MEM_B(-0X71F4, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80044FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044FE4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80044FE8: div         $zero, $a1, $at
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r1)));
    // 0x80044FEC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80044FF0: mflo        $v1
    ctx->r3 = lo;
    // 0x80044FF4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80044FF8: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80044FFC: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80045000: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80045004: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80045008: bne         $at, $zero, L_8004502C
    if (ctx->r1 != 0) {
        // 0x8004500C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004502C;
    }
    // 0x8004500C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045010: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_80045014:
    // 0x80045014: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80045018: mflo        $v0
    ctx->r2 = lo;
    // 0x8004501C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80045020: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80045024: bne         $at, $zero, L_80045014
    if (ctx->r1 != 0) {
        // 0x80045028: nop
    
            goto L_80045014;
    }
    // 0x80045028: nop

L_8004502C:
    // 0x8004502C: blez        $v0, L_80045130
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80045030: addiu       $s1, $zero, 0x3
        ctx->r17 = ADD32(0, 0X3);
            goto L_80045130;
    }
    // 0x80045030: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80045034: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80045038: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
L_8004503C:
    // 0x8004503C: beq         $at, $zero, L_800450FC
    if (ctx->r1 == 0) {
        // 0x80045040: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800450FC;
    }
    // 0x80045040: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80045044: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_80045048:
    // 0x80045048: bne         $at, $zero, L_800450F0
    if (ctx->r1 != 0) {
        // 0x8004504C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800450F0;
    }
    // 0x8004504C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80045050: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
L_80045054:
    // 0x80045054: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80045058: addu        $t0, $t6, $a3
    ctx->r8 = ADD32(ctx->r14, ctx->r7);
    // 0x8004505C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80045060: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x80045064: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80045068: lbu         $t5, 0x31($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X31);
    // 0x8004506C: or          $t1, $t3, $zero
    ctx->r9 = ctx->r11 | 0;
    // 0x80045070: bnel        $s2, $t5, L_8004508C
    if (ctx->r18 != ctx->r13) {
        // 0x80045074: lw          $t0, 0x0($t3)
        ctx->r8 = MEM_W(ctx->r11, 0X0);
            goto L_8004508C;
    }
    goto skip_0;
    // 0x80045074: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    skip_0:
    // 0x80045078: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8004507C: lbu         $t8, 0x31($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X31);
    // 0x80045080: bnel        $s2, $t8, L_800450F4
    if (ctx->r18 != ctx->r24) {
        // 0x80045084: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800450F4;
    }
    goto skip_1;
    // 0x80045084: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80045088: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
L_8004508C:
    // 0x8004508C: bne         $s2, $t5, L_8004509C
    if (ctx->r18 != ctx->r13) {
        // 0x80045090: lbu         $s0, 0x31($t0)
        ctx->r16 = MEM_BU(ctx->r8, 0X31);
            goto L_8004509C;
    }
    // 0x80045090: lbu         $s0, 0x31($t0)
    ctx->r16 = MEM_BU(ctx->r8, 0X31);
    // 0x80045094: beql        $s2, $s0, L_800450A8
    if (ctx->r18 == ctx->r16) {
        // 0x80045098: lwc1        $f0, 0x8C($t4)
        ctx->f0.u32l = MEM_W(ctx->r12, 0X8C);
            goto L_800450A8;
    }
    goto skip_2;
    // 0x80045098: lwc1        $f0, 0x8C($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X8C);
    skip_2:
L_8004509C:
    // 0x8004509C: beql        $s2, $s0, L_800450D8
    if (ctx->r18 == ctx->r16) {
        // 0x800450A0: lw          $t9, 0x0($t1)
        ctx->r25 = MEM_W(ctx->r9, 0X0);
            goto L_800450D8;
    }
    goto skip_3;
    // 0x800450A0: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    skip_3:
    // 0x800450A4: lwc1        $f0, 0x8C($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X8C);
L_800450A8:
    // 0x800450A8: lwc1        $f2, 0x8C($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X8C);
    // 0x800450AC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800450B0: nop

    // 0x800450B4: bc1tl       L_800450F4
    if (c1cs) {
        // 0x800450B8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800450F4;
    }
    goto skip_4;
    // 0x800450B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_4:
    // 0x800450BC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800450C0: sltu        $at, $t0, $t4
    ctx->r1 = ctx->r8 < ctx->r12 ? 1 : 0;
    // 0x800450C4: bc1fl       L_800450D8
    if (!c1cs) {
        // 0x800450C8: lw          $t9, 0x0($t1)
        ctx->r25 = MEM_W(ctx->r9, 0X0);
            goto L_800450D8;
    }
    goto skip_5;
    // 0x800450C8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    skip_5:
    // 0x800450CC: bnel        $at, $zero, L_800450F4
    if (ctx->r1 != 0) {
        // 0x800450D0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800450F4;
    }
    goto skip_6;
    // 0x800450D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_6:
    // 0x800450D4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
L_800450D8:
    // 0x800450D8: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800450DC: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800450E0: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800450E4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800450E8: beq         $at, $zero, L_80045054
    if (ctx->r1 == 0) {
        // 0x800450EC: sw          $t0, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r8;
            goto L_80045054;
    }
    // 0x800450EC: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_800450F0:
    // 0x800450F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800450F4:
    // 0x800450F4: bnel        $v1, $a1, L_80045048
    if (ctx->r3 != ctx->r5) {
        // 0x800450F8: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80045048;
    }
    goto skip_7;
    // 0x800450F8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_7:
L_800450FC:
    // 0x800450FC: div         $zero, $v0, $s1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r17)));
    // 0x80045100: bne         $s1, $zero, L_8004510C
    if (ctx->r17 != 0) {
        // 0x80045104: nop
    
            goto L_8004510C;
    }
    // 0x80045104: nop

    // 0x80045108: break       7
    do_break(2147766536);
L_8004510C:
    // 0x8004510C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80045110: bne         $s1, $at, L_80045124
    if (ctx->r17 != ctx->r1) {
        // 0x80045114: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80045124;
    }
    // 0x80045114: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80045118: bne         $v0, $at, L_80045124
    if (ctx->r2 != ctx->r1) {
        // 0x8004511C: nop
    
            goto L_80045124;
    }
    // 0x8004511C: nop

    // 0x80045120: break       6
    do_break(2147766560);
L_80045124:
    // 0x80045124: mflo        $v0
    ctx->r2 = lo;
    // 0x80045128: bgtzl       $v0, L_8004503C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8004512C: slt         $at, $v0, $a1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8004503C;
    }
    goto skip_8;
    // 0x8004512C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    skip_8:
L_80045130:
    // 0x80045130: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80045134: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80045138: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x8004513C: jr          $ra
    // 0x80045140: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80045140: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80067D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067D60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067D68: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80067D6C: jal         0x80067BBC
    // 0x80067D70: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80067D70: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80067D74: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80067D78: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067D7C: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067D80: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x80067D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067D8C: jr          $ra
    // 0x80067D90: nop

    return;
    // 0x80067D90: nop

;}
RECOMP_FUNC void func_804EF1E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF1E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804EF1E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804EF1EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804EF1F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804EF1F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804EF1F8: jal         0x804EEEDC
    // 0x804EF1FC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_804EEEDC(rdram, ctx);
        goto after_0;
    // 0x804EF1FC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x804EF200: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x804EF204: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804EF208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804EF20C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804EF210: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x804EF214: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804EF218: bc1f        L_804EF298
    if (!c1cs) {
        // 0x804EF21C: nop
    
            goto L_804EF298;
    }
    // 0x804EF21C: nop

    // 0x804EF220: jal         0x804EF078
    // 0x804EF224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804EF078(rdram, ctx);
        goto after_1;
    // 0x804EF224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804EF228: jal         0x804EEF38
    // 0x804EF22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804EEF38(rdram, ctx);
        goto after_2;
    // 0x804EF22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804EF230: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x804EF234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804EF238: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x804EF23C: beq         $at, $zero, L_804EF26C
    if (ctx->r1 == 0) {
        // 0x804EF240: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_804EF26C;
    }
    // 0x804EF240: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x804EF244: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804EF248: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804EF24C: lui         $a3, 0xBBA3
    ctx->r7 = S32(0XBBA3 << 16);
    // 0x804EF250: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x804EF254: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x804EF258: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x804EF25C: jal         0x804EF0EC
    // 0x804EF260: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    func_804EF0EC(rdram, ctx);
        goto after_3;
    // 0x804EF260: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    after_3:
    // 0x804EF264: b           L_804EF2AC
    // 0x804EF268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804EF2AC;
    // 0x804EF268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804EF26C:
    // 0x804EF26C: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(267, 0X118C) << 16);
    // 0x804EF270: lwc1        $f10, -0xE4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(267, 0X118C));
    // 0x804EF274: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x804EF278: lwc1        $f12, 0x3C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804EF27C: lwc1        $f14, 0x40($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804EF280: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804EF284: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x804EF288: jal         0x804EFBB4
    // 0x804EF28C: nop

    func_804EFBB4(rdram, ctx);
        goto after_4;
    // 0x804EF28C: nop

    after_4:
    // 0x804EF290: b           L_804EF2A8
    // 0x804EF294: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_804EF2A8;
    // 0x804EF294: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_804EF298:
    // 0x804EF298: jal         0x804EF5A0
    // 0x804EF29C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804EF5A0(rdram, ctx);
        goto after_5;
    // 0x804EF29C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x804EF2A0: jal         0x804EF050
    // 0x804EF2A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804EF050(rdram, ctx);
        goto after_6;
    // 0x804EF2A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_804EF2A8:
    // 0x804EF2A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804EF2AC:
    // 0x804EF2AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804EF2B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804EF2B4: jr          $ra
    // 0x804EF2B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x804EF2B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806D6C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D6C6C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806D6C70: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D6C74: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x806D6C78: beq         $v1, $zero, L_806D6D58
    if (ctx->r3 == 0) {
        // 0x806D6C7C: nop
    
            goto L_806D6D58;
    }
    // 0x806D6C7C: nop

    // 0x806D6C80: lw          $a3, 0x180($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X180);
    // 0x806D6C84: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x806D6C88: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x806D6C8C: beq         $a0, $a3, L_806D6C9C
    if (ctx->r4 == ctx->r7) {
        // 0x806D6C90: subu        $t6, $t6, $a1
        ctx->r14 = SUB32(ctx->r14, ctx->r5);
            goto L_806D6C9C;
    }
    // 0x806D6C90: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x806D6C94: jr          $ra
    // 0x806D6C98: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    return;
    // 0x806D6C98: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_806D6C9C:
    // 0x806D6C9C: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(622, 0X1480) << 16);
    // 0x806D6CA0: addiu       $t7, $t7, -0x7FD0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(622, 0X1480));
    // 0x806D6CA4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x806D6CA8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x806D6CAC: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x806D6CB0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x806D6CB4: nop

    // 0x806D6CB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806D6CBC: bne         $a0, $a3, L_806D6D58
    if (ctx->r4 != ctx->r7) {
        // 0x806D6CC0: swc1        $f6, 0x40($a2)
        MEM_W(0X40, ctx->r6) = ctx->f6.u32l;
            goto L_806D6D58;
    }
    // 0x806D6CC0: swc1        $f6, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f6.u32l;
    // 0x806D6CC4: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x806D6CC8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x806D6CCC: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x806D6CD0: beq         $t9, $at, L_806D6D00
    if (ctx->r25 == ctx->r1) {
        // 0x806D6CD4: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_806D6D00;
    }
    // 0x806D6CD4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806D6CD8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x806D6CDC: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x806D6CE0: nop

    // 0x806D6CE4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806D6CE8: swc1        $f10, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f10.u32l;
    // 0x806D6CEC: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806D6CF0: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x806D6CF4: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x806D6CF8: b           L_806D6D50
    // 0x806D6CFC: swc1        $f18, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f18.u32l;
        goto L_806D6D50;
    // 0x806D6CFC: swc1        $f18, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f18.u32l;
L_806D6D00:
    // 0x806D6D00: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x806D6D04: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x806D6D08: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x806D6D0C: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1B60) << 16);
    // 0x806D6D10: lwc1        $f0, -0x78F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1B60));
    // 0x806D6D14: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x806D6D18: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1B14) << 16);
    // 0x806D6D1C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x806D6D20: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806D6D24: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x806D6D28: lwc1        $f4, -0x793C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1B14));
    // 0x806D6D2C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x806D6D30: swc1        $f10, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f10.u32l;
    // 0x806D6D34: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x806D6D38: swc1        $f0, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f0.u32l;
    // 0x806D6D3C: swc1        $f0, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f0.u32l;
    // 0x806D6D40: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x806D6D44: nop

    // 0x806D6D48: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806D6D4C: swc1        $f18, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f18.u32l;
L_806D6D50:
    // 0x806D6D50: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x806D6D54: swc1        $f6, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f6.u32l;
L_806D6D58:
    // 0x806D6D58: jr          $ra
    // 0x806D6D5C: nop

    return;
    // 0x806D6D5C: nop

;}
RECOMP_FUNC void func_8005AB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AB90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005AB94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005AB98: jal         0x80064E84
    // 0x8005AB9C: nop

    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8005AB9C: nop

    after_0:
    // 0x8005ABA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005ABA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005ABA8: jr          $ra
    // 0x8005ABAC: nop

    return;
    // 0x8005ABAC: nop

;}
RECOMP_FUNC void func_806F5BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F5BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F5BE8: jal         0x806F5BC0
    // 0x806F5BEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F5BC0(rdram, ctx);
        goto after_0;
    // 0x806F5BEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F5BF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F5BF4: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(685, 0X5F4) << 16);
    // 0x806F5BF8: addiu       $t7, $t7, 0x5954
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(685, 0X5F4));
    // 0x806F5BFC: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x806F5C00: beql        $t6, $zero, L_806F5C14
    if (ctx->r14 == 0) {
        // 0x806F5C04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F5C14;
    }
    goto skip_0;
    // 0x806F5C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F5C08: jal         0x8005FE48
    // 0x806F5C0C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x806F5C0C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    after_1:
    // 0x806F5C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F5C14:
    // 0x806F5C14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F5C18: jr          $ra
    // 0x806F5C1C: nop

    return;
    // 0x806F5C1C: nop

;}
RECOMP_FUNC void func_8045DDAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045DDAC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8045DDB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045DDB4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8045DDB8: lhu         $t6, 0x28($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X28);
    // 0x8045DDBC: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045DDC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8045DDC4: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x8045DDC8: sh          $t7, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r15;
    // 0x8045DDCC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8045DDD0: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8045DDD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8045DDD8: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8045DDDC: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8045DDE0: nop

    // 0x8045DDE4: bc1tl       L_8045DE3C
    if (c1cs) {
        // 0x8045DDE8: lhu         $t8, 0x28($a2)
        ctx->r24 = MEM_HU(ctx->r6, 0X28);
            goto L_8045DE3C;
    }
    goto skip_0;
    // 0x8045DDE8: lhu         $t8, 0x28($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X28);
    skip_0:
    // 0x8045DDEC: neg.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = -ctx->f12.fl;
    // 0x8045DDF0: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8045DDF4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8045DDF8: nop

    // 0x8045DDFC: bc1tl       L_8045DE3C
    if (c1cs) {
        // 0x8045DE00: lhu         $t8, 0x28($a2)
        ctx->r24 = MEM_HU(ctx->r6, 0X28);
            goto L_8045DE3C;
    }
    goto skip_1;
    // 0x8045DE00: lhu         $t8, 0x28($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X28);
    skip_1:
    // 0x8045DE04: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045DE08: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8045DE0C: add.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x8045DE10: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8045DE14: nop

    // 0x8045DE18: bc1tl       L_8045DE3C
    if (c1cs) {
        // 0x8045DE1C: lhu         $t8, 0x28($a2)
        ctx->r24 = MEM_HU(ctx->r6, 0X28);
            goto L_8045DE3C;
    }
    goto skip_2;
    // 0x8045DE1C: lhu         $t8, 0x28($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X28);
    skip_2:
    // 0x8045DE20: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
    // 0x8045DE24: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8045DE28: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8045DE2C: nop

    // 0x8045DE30: bc1fl       L_8045DE54
    if (!c1cs) {
        // 0x8045DE34: c.lt.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
            goto L_8045DE54;
    }
    goto skip_3;
    // 0x8045DE34: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    skip_3:
    // 0x8045DE38: lhu         $t8, 0x28($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X28);
L_8045DE3C:
    // 0x8045DE3C: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x8045DE40: sh          $t0, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r8;
    // 0x8045DE44: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x8045DE48: b           L_8045E3A8
    // 0x8045DE4C: sh          $t1, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r9;
        goto L_8045E3A8;
    // 0x8045DE4C: sh          $t1, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r9;
    // 0x8045DE50: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
L_8045DE54:
    // 0x8045DE54: nop

    // 0x8045DE58: bc1fl       L_8045DF04
    if (!c1cs) {
        // 0x8045DE5C: c.lt.s      $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
            goto L_8045DF04;
    }
    goto skip_4;
    // 0x8045DE5C: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    skip_4:
    // 0x8045DE60: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8045DE64: nop

    // 0x8045DE68: bc1fl       L_8045DF04
    if (!c1cs) {
        // 0x8045DE6C: c.lt.s      $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
            goto L_8045DF04;
    }
    goto skip_5;
    // 0x8045DE6C: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    skip_5:
    // 0x8045DE70: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8045DE74: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8045DE78: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8045DE7C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8045DE80: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8045DE84: nop

    // 0x8045DE88: bc1fl       L_8045DEBC
    if (!c1cs) {
        // 0x8045DE8C: lwc1        $f6, 0x4($a2)
        ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
            goto L_8045DEBC;
    }
    goto skip_6;
    // 0x8045DE8C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    skip_6:
    // 0x8045DE90: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045DE94: addiu       $a1, $zero, 0x168
    ctx->r5 = ADD32(0, 0X168);
    // 0x8045DE98: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8045DE9C: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045DEA0: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8045DEA4: swc1        $f6, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f6.u32l;
    // 0x8045DEA8: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8045DEAC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8045DEB0: b           L_8045DEE8
    // 0x8045DEB4: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
        goto L_8045DEE8;
    // 0x8045DEB4: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x8045DEB8: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
L_8045DEBC:
    // 0x8045DEBC: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8045DEC0: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x8045DEC4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8045DEC8: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8045DECC: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045DED0: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8045DED4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8045DED8: swc1        $f6, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f6.u32l;
    // 0x8045DEDC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8045DEE0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8045DEE4: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_8045DEE8:
    // 0x8045DEE8: lhu         $t2, 0x28($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X28);
    // 0x8045DEEC: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045DEF0: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x8045DEF4: sh          $t3, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r11;
    // 0x8045DEF8: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8045DEFC: neg.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = -ctx->f12.fl;
    // 0x8045DF00: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
L_8045DF04:
    // 0x8045DF04: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8045DF08: bc1fl       L_8045DFA8
    if (!c1cs) {
        // 0x8045DF0C: lhu         $v0, 0x28($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X28);
            goto L_8045DFA8;
    }
    goto skip_7;
    // 0x8045DF0C: lhu         $v0, 0x28($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X28);
    skip_7:
    // 0x8045DF10: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8045DF14: nop

    // 0x8045DF18: bc1fl       L_8045DFA8
    if (!c1cs) {
        // 0x8045DF1C: lhu         $v0, 0x28($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X28);
            goto L_8045DFA8;
    }
    goto skip_8;
    // 0x8045DF1C: lhu         $v0, 0x28($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X28);
    skip_8:
    // 0x8045DF20: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8045DF24: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8045DF28: addiu       $v1, $a2, 0x1C
    ctx->r3 = ADD32(ctx->r6, 0X1C);
    // 0x8045DF2C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8045DF30: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8045DF34: nop

    // 0x8045DF38: bc1fl       L_8045DF6C
    if (!c1cs) {
        // 0x8045DF3C: lwc1        $f6, 0x0($a2)
        ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
            goto L_8045DF6C;
    }
    goto skip_9;
    // 0x8045DF3C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    skip_9:
    // 0x8045DF40: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045DF44: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    // 0x8045DF48: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8045DF4C: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8045DF50: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8045DF54: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8045DF58: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045DF5C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8045DF60: b           L_8045DF98
    // 0x8045DF64: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
        goto L_8045DF98;
    // 0x8045DF64: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x8045DF68: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
L_8045DF6C:
    // 0x8045DF6C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8045DF70: addiu       $a3, $zero, 0x10E
    ctx->r7 = ADD32(0, 0X10E);
    // 0x8045DF74: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8045DF78: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8045DF7C: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8045DF80: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8045DF84: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045DF88: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8045DF8C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8045DF90: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8045DF94: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
L_8045DF98:
    // 0x8045DF98: lhu         $t4, 0x28($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X28);
    // 0x8045DF9C: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x8045DFA0: sh          $t5, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r13;
    // 0x8045DFA4: lhu         $v0, 0x28($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X28);
L_8045DFA8:
    // 0x8045DFA8: andi        $t6, $v0, 0x10
    ctx->r14 = ctx->r2 & 0X10;
    // 0x8045DFAC: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x8045DFB0: beq         $t7, $zero, L_8045E0EC
    if (ctx->r15 == 0) {
        // 0x8045DFB4: andi        $t8, $v0, 0x20
        ctx->r24 = ctx->r2 & 0X20;
            goto L_8045E0EC;
    }
    // 0x8045DFB4: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    // 0x8045DFB8: sra         $t9, $t8, 5
    ctx->r25 = S32(SIGNED(ctx->r24) >> 5);
    // 0x8045DFBC: beq         $t9, $zero, L_8045DFD8
    if (ctx->r25 == 0) {
        // 0x8045DFC0: andi        $t0, $v0, 0x8
        ctx->r8 = ctx->r2 & 0X8;
            goto L_8045DFD8;
    }
    // 0x8045DFC0: andi        $t0, $v0, 0x8
    ctx->r8 = ctx->r2 & 0X8;
    // 0x8045DFC4: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8045DFC8: beq         $t1, $zero, L_8045DFD8
    if (ctx->r9 == 0) {
        // 0x8045DFCC: andi        $t2, $v0, 0xFFF7
        ctx->r10 = ctx->r2 & 0XFFF7;
            goto L_8045DFD8;
    }
    // 0x8045DFCC: andi        $t2, $v0, 0xFFF7
    ctx->r10 = ctx->r2 & 0XFFF7;
    // 0x8045DFD0: sh          $t2, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r10;
    // 0x8045DFD4: andi        $v0, $t2, 0xFFFF
    ctx->r2 = ctx->r10 & 0XFFFF;
L_8045DFD8:
    // 0x8045DFD8: andi        $t3, $v0, 0xFFDF
    ctx->r11 = ctx->r2 & 0XFFDF;
    // 0x8045DFDC: bne         $a3, $zero, L_8045E010
    if (ctx->r7 != 0) {
        // 0x8045DFE0: sh          $t3, 0x28($a2)
        MEM_H(0X28, ctx->r6) = ctx->r11;
            goto L_8045E010;
    }
    // 0x8045DFE0: sh          $t3, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r11;
    // 0x8045DFE4: addiu       $t4, $a1, -0x5A
    ctx->r12 = ADD32(ctx->r5, -0X5A);
    // 0x8045DFE8: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8045DFEC: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8045DFF0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8045DFF4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8045DFF8: swc1        $f6, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f6.u32l;
    // 0x8045DFFC: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8045E000: swc1        $f8, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f8.u32l;
    // 0x8045E004: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8045E008: b           L_8045E250
    // 0x8045E00C: swc1        $f10, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f10.u32l;
        goto L_8045E250;
    // 0x8045E00C: swc1        $f10, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f10.u32l;
L_8045E010:
    // 0x8045E010: bne         $a1, $zero, L_8045E044
    if (ctx->r5 != 0) {
        // 0x8045E014: addiu       $v1, $a2, 0x1C
        ctx->r3 = ADD32(ctx->r6, 0X1C);
            goto L_8045E044;
    }
    // 0x8045E014: addiu       $v1, $a2, 0x1C
    ctx->r3 = ADD32(ctx->r6, 0X1C);
    // 0x8045E018: addiu       $t5, $a3, -0x5A
    ctx->r13 = ADD32(ctx->r7, -0X5A);
    // 0x8045E01C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8045E020: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8045E024: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8045E028: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8045E02C: swc1        $f10, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f10.u32l;
    // 0x8045E030: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8045E034: swc1        $f4, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f4.u32l;
    // 0x8045E038: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8045E03C: b           L_8045E250
    // 0x8045E040: swc1        $f6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f6.u32l;
        goto L_8045E250;
    // 0x8045E040: swc1        $f6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f6.u32l;
L_8045E044:
    // 0x8045E044: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8045E048: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x8045E04C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8045E050: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8045E054: jal         0x80065954
    // 0x8045E058: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8045E058: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8045E05C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8045E060: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8045E064: jal         0x80065954
    // 0x8045E068: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8045E068: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    after_1:
    // 0x8045E06C: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8045E070: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8045E074: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8045E078: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8045E07C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8045E080: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8045E084: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8045E088: bc1f        L_8045E0C0
    if (!c1cs) {
        // 0x8045E08C: addiu       $t7, $a3, -0x5A
        ctx->r15 = ADD32(ctx->r7, -0X5A);
            goto L_8045E0C0;
    }
    // 0x8045E08C: addiu       $t7, $a3, -0x5A
    ctx->r15 = ADD32(ctx->r7, -0X5A);
    // 0x8045E090: addiu       $t6, $a1, -0x5A
    ctx->r14 = ADD32(ctx->r5, -0X5A);
    // 0x8045E094: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8045E098: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8045E09C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8045E0A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8045E0A4: swc1        $f8, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f8.u32l;
    // 0x8045E0A8: swc1        $f14, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f14.u32l;
    // 0x8045E0AC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8045E0B0: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    // 0x8045E0B4: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8045E0B8: b           L_8045E250
    // 0x8045E0BC: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
        goto L_8045E250;
    // 0x8045E0BC: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
L_8045E0C0:
    // 0x8045E0C0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8045E0C4: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8045E0C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8045E0CC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8045E0D0: swc1        $f4, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f4.u32l;
    // 0x8045E0D4: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
    // 0x8045E0D8: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8045E0DC: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x8045E0E0: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8045E0E4: b           L_8045E250
    // 0x8045E0E8: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
        goto L_8045E250;
    // 0x8045E0E8: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_8045E0EC:
    // 0x8045E0EC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8045E0F0: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045E0F4: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8045E0F8: nop

    // 0x8045E0FC: bc1fl       L_8045E110
    if (!c1cs) {
        // 0x8045E100: neg.s       $f4, $f12
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = -ctx->f12.fl;
            goto L_8045E110;
    }
    goto skip_10;
    // 0x8045E100: neg.s       $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = -ctx->f12.fl;
    skip_10:
    // 0x8045E104: b           L_8045E114
    // 0x8045E108: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
        goto L_8045E114;
    // 0x8045E108: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x8045E10C: neg.s       $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = -ctx->f12.fl;
L_8045E110:
    // 0x8045E110: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
L_8045E114:
    // 0x8045E114: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8045E118: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x8045E11C: nop

    // 0x8045E120: bc1fl       L_8045E138
    if (!c1cs) {
        // 0x8045E124: lwc1        $f10, 0x0($a2)
        ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
            goto L_8045E138;
    }
    goto skip_11;
    // 0x8045E124: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    skip_11:
    // 0x8045E128: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045E12C: b           L_8045E140
    // 0x8045E130: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
        goto L_8045E140;
    // 0x8045E130: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8045E134: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
L_8045E138:
    // 0x8045E138: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8045E13C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
L_8045E140:
    // 0x8045E140: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8045E144: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8045E148: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8045E14C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8045E150: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8045E154: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8045E158: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8045E15C: jal         0x80067114
    // 0x8045E160: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    func_80067114(rdram, ctx);
        goto after_2;
    // 0x8045E160: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    after_2:
    // 0x8045E164: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8045E168: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8045E16C: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8045E170: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8045E174: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12C0) << 16);
    // 0x8045E178: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8045E17C: swc1        $f8, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f8.u32l;
    // 0x8045E180: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8045E184: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8045E188: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8045E18C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8045E190: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8045E194: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8045E198: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8045E19C: nop

    // 0x8045E1A0: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8045E1A4: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8045E1A8: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8045E1AC: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x8045E1B0: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8045E1B4: nop

    // 0x8045E1B8: bc1f        L_8045E244
    if (!c1cs) {
        // 0x8045E1BC: nop
    
            goto L_8045E244;
    }
    // 0x8045E1BC: nop

    // 0x8045E1C0: lwc1        $f0, -0x1030($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12C0));
    // 0x8045E1C4: addiu       $v1, $a2, 0x1C
    ctx->r3 = ADD32(ctx->r6, 0X1C);
    // 0x8045E1C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8045E1CC: nop

    // 0x8045E1D0: bc1fl       L_8045E1E0
    if (!c1cs) {
        // 0x8045E1D4: sqrt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
            goto L_8045E1E0;
    }
    goto skip_12;
    // 0x8045E1D4: sqrt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
    skip_12:
    // 0x8045E1D8: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x8045E1DC: sqrt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
L_8045E1E0:
    // 0x8045E1E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8045E1E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8045E1E8: div.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8045E1EC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8045E1F0: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8045E1F4: nop

    // 0x8045E1F8: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8045E1FC: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8045E200: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x8045E204: lhu         $t8, 0x28($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X28);
    // 0x8045E208: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8045E20C: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
    // 0x8045E210: andi        $t0, $v0, 0x20
    ctx->r8 = ctx->r2 & 0X20;
    // 0x8045E214: sra         $t1, $t0, 5
    ctx->r9 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8045E218: bne         $t1, $zero, L_8045E230
    if (ctx->r9 != 0) {
        // 0x8045E21C: sh          $t9, 0x28($a2)
        MEM_H(0X28, ctx->r6) = ctx->r25;
            goto L_8045E230;
    }
    // 0x8045E21C: sh          $t9, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r25;
    // 0x8045E220: andi        $t3, $v0, 0xFFF7
    ctx->r11 = ctx->r2 & 0XFFF7;
    // 0x8045E224: sh          $t3, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r11;
    // 0x8045E228: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x8045E22C: sh          $t4, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r12;
L_8045E230:
    // 0x8045E230: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8045E234: swc1        $f8, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f8.u32l;
    // 0x8045E238: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8045E23C: b           L_8045E250
    // 0x8045E240: swc1        $f10, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f10.u32l;
        goto L_8045E250;
    // 0x8045E240: swc1        $f10, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f10.u32l;
L_8045E244:
    // 0x8045E244: lhu         $t5, 0x28($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X28);
    // 0x8045E248: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x8045E24C: sh          $t6, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r14;
L_8045E250:
    // 0x8045E250: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8045E254: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8045E258: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
    // 0x8045E25C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8045E260: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8045E264: nop

    // 0x8045E268: bc1fl       L_8045E298
    if (!c1cs) {
        // 0x8045E26C: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8045E298;
    }
    goto skip_13;
    // 0x8045E26C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_13:
    // 0x8045E270: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8045E274: nop

    // 0x8045E278: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
L_8045E27C:
    // 0x8045E27C: swc1        $f4, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f4.u32l;
    // 0x8045E280: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
    // 0x8045E284: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8045E288: nop

    // 0x8045E28C: bc1tl       L_8045E27C
    if (c1cs) {
        // 0x8045E290: sub.s       $f4, $f12, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_8045E27C;
    }
    goto skip_14;
    // 0x8045E290: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
    skip_14:
    // 0x8045E294: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_8045E298:
    // 0x8045E298: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8045E29C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8045E2A0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8045E2A4: nop

    // 0x8045E2A8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8045E2AC: nop

    // 0x8045E2B0: bc1fl       L_8045E2D8
    if (!c1cs) {
        // 0x8045E2B4: lhu         $t7, 0x28($a2)
        ctx->r15 = MEM_HU(ctx->r6, 0X28);
            goto L_8045E2D8;
    }
    goto skip_15;
    // 0x8045E2B4: lhu         $t7, 0x28($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X28);
    skip_15:
    // 0x8045E2B8: add.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
L_8045E2BC:
    // 0x8045E2BC: swc1        $f6, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f6.u32l;
    // 0x8045E2C0: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
    // 0x8045E2C4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8045E2C8: nop

    // 0x8045E2CC: bc1tl       L_8045E2BC
    if (c1cs) {
        // 0x8045E2D0: add.s       $f6, $f12, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_8045E2BC;
    }
    goto skip_16;
    // 0x8045E2D0: add.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
    skip_16:
    // 0x8045E2D4: lhu         $t7, 0x28($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X28);
L_8045E2D8:
    // 0x8045E2D8: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8045E2DC: sra         $t9, $t8, 4
    ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
    // 0x8045E2E0: beql        $t9, $zero, L_8045E3A8
    if (ctx->r25 == 0) {
        // 0x8045E2E4: sh          $zero, 0x28($a2)
        MEM_H(0X28, ctx->r6) = 0;
            goto L_8045E3A8;
    }
    goto skip_17;
    // 0x8045E2E4: sh          $zero, 0x28($a2)
    MEM_H(0X28, ctx->r6) = 0;
    skip_17:
    // 0x8045E2E8: jal         0x80066DE4
    // 0x8045E2EC: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8045E2EC: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    after_3:
    // 0x8045E2F0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12C4) << 16);
    // 0x8045E2F4: lwc1        $f8, -0x102C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12C4));
    // 0x8045E2F8: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8045E2FC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8045E300: nop

    // 0x8045E304: bc1fl       L_8045E330
    if (!c1cs) {
        // 0x8045E308: lhu         $t6, 0x28($a2)
        ctx->r14 = MEM_HU(ctx->r6, 0X28);
            goto L_8045E330;
    }
    goto skip_18;
    // 0x8045E308: lhu         $t6, 0x28($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X28);
    skip_18:
    // 0x8045E30C: lhu         $t0, 0x28($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X28);
    // 0x8045E310: ori         $t2, $t0, 0x1
    ctx->r10 = ctx->r8 | 0X1;
    // 0x8045E314: andi        $t4, $t2, 0xFFFD
    ctx->r12 = ctx->r10 & 0XFFFD;
    // 0x8045E318: sh          $t2, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r10;
    // 0x8045E31C: sh          $t4, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r12;
    // 0x8045E320: andi        $t5, $t4, 0xFFFB
    ctx->r13 = ctx->r12 & 0XFFFB;
    // 0x8045E324: b           L_8045E3A8
    // 0x8045E328: sh          $t5, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r13;
        goto L_8045E3A8;
    // 0x8045E328: sh          $t5, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r13;
    // 0x8045E32C: lhu         $t6, 0x28($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X28);
L_8045E330:
    // 0x8045E330: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12C8) << 16);
    // 0x8045E334: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x8045E338: sh          $t7, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r15;
    // 0x8045E33C: lwc1        $f10, -0x1028($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12C8));
    // 0x8045E340: andi        $t0, $t7, 0xFFFD
    ctx->r8 = ctx->r15 & 0XFFFD;
    // 0x8045E344: andi        $t1, $t0, 0xFFFB
    ctx->r9 = ctx->r8 & 0XFFFB;
    // 0x8045E348: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8045E34C: nop

    // 0x8045E350: bc1fl       L_8045E368
    if (!c1cs) {
        // 0x8045E354: lhu         $t2, 0x28($a2)
        ctx->r10 = MEM_HU(ctx->r6, 0X28);
            goto L_8045E368;
    }
    goto skip_19;
    // 0x8045E354: lhu         $t2, 0x28($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X28);
    skip_19:
    // 0x8045E358: sh          $t0, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r8;
    // 0x8045E35C: b           L_8045E3A8
    // 0x8045E360: sh          $t1, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r9;
        goto L_8045E3A8;
    // 0x8045E360: sh          $t1, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r9;
    // 0x8045E364: lhu         $t2, 0x28($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X28);
L_8045E368:
    // 0x8045E368: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12CC) << 16);
    // 0x8045E36C: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8045E370: sh          $t3, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r11;
    // 0x8045E374: lwc1        $f4, -0x1024($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12CC));
    // 0x8045E378: ori         $t5, $t3, 0x4
    ctx->r13 = ctx->r11 | 0X4;
    // 0x8045E37C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8045E380: nop

    // 0x8045E384: bc1fl       L_8045E398
    if (!c1cs) {
        // 0x8045E388: lhu         $t6, 0x28($a2)
        ctx->r14 = MEM_HU(ctx->r6, 0X28);
            goto L_8045E398;
    }
    goto skip_20;
    // 0x8045E388: lhu         $t6, 0x28($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X28);
    skip_20:
    // 0x8045E38C: b           L_8045E3A8
    // 0x8045E390: sh          $t5, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r13;
        goto L_8045E3A8;
    // 0x8045E390: sh          $t5, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r13;
    // 0x8045E394: lhu         $t6, 0x28($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X28);
L_8045E398:
    // 0x8045E398: andi        $t7, $t6, 0xFFFB
    ctx->r15 = ctx->r14 & 0XFFFB;
    // 0x8045E39C: b           L_8045E3A8
    // 0x8045E3A0: sh          $t7, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r15;
        goto L_8045E3A8;
    // 0x8045E3A0: sh          $t7, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r15;
    // 0x8045E3A4: sh          $zero, 0x28($a2)
    MEM_H(0X28, ctx->r6) = 0;
L_8045E3A8:
    // 0x8045E3A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045E3AC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8045E3B0: jr          $ra
    // 0x8045E3B4: nop

    return;
    // 0x8045E3B4: nop

;}
RECOMP_FUNC void func_80789E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80789E20: lh          $v1, 0x184($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X184);
    // 0x80789E24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80789E28: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80789E2C: blez        $v1, L_80789E64
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80789E30: addiu       $a2, $zero, 0x4002
        ctx->r6 = ADD32(0, 0X4002);
            goto L_80789E64;
    }
    // 0x80789E30: addiu       $a2, $zero, 0x4002
    ctx->r6 = ADD32(0, 0X4002);
L_80789E34:
    // 0x80789E34: lw          $a0, 0x188($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X188);
    // 0x80789E38: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80789E3C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80789E40: beq         $a0, $zero, L_80789E5C
    if (ctx->r4 == 0) {
        // 0x80789E44: nop
    
            goto L_80789E5C;
    }
    // 0x80789E44: nop

    // 0x80789E48: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x80789E4C: bne         $a2, $t6, L_80789E5C
    if (ctx->r6 != ctx->r14) {
        // 0x80789E50: nop
    
            goto L_80789E5C;
    }
    // 0x80789E50: nop

    // 0x80789E54: jr          $ra
    // 0x80789E58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80789E58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80789E5C:
    // 0x80789E5C: bne         $at, $zero, L_80789E34
    if (ctx->r1 != 0) {
        // 0x80789E60: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80789E34;
    }
    // 0x80789E60: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80789E64:
    // 0x80789E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80789E68: jr          $ra
    // 0x80789E6C: nop

    return;
    // 0x80789E6C: nop

;}
RECOMP_FUNC void func_804F5CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F5CE8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804F5CEC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x804F5CF0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804F5CF4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804F5CF8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804F5CFC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804F5D00: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804F5D04: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804F5D08: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804F5D0C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804F5D10: lui         $t1, 0x8051
    ctx->r9 = S32(RELOC_HI16(273, 0X20878) << 16);
    // 0x804F5D14: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804F5D18: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804F5D1C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804F5D20: lw          $t1, 0x4B08($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(273, 0X20878));
    // 0x804F5D24: jr          $ra
    // 0x804F5D28: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804F5D28: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x804F5D2C: nop

;}
RECOMP_FUNC void func_80434C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434C38: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80434C3C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80434C40: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80434C44: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80434C48: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80434C4C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80434C50: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    // 0x80434C54: addiu       $v1, $v0, 0x5CC
    ctx->r3 = ADD32(ctx->r2, 0X5CC);
L_80434C58:
    // 0x80434C58: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80434C5C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80434C60: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80434C64: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80434C68: addiu       $v1, $v1, 0x0
    ctx->r3 = ADD32(ctx->r3, 0X0);
    // 0x80434C6C: bc1fl       L_80434C80
    if (!c1cs) {
        // 0x80434C70: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_80434C80;
    }
    goto skip_0;
    // 0x80434C70: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_0:
    // 0x80434C74: b           L_80434C90
    // 0x80434C78: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
        goto L_80434C90;
    // 0x80434C78: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80434C7C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_80434C80:
    // 0x80434C80: nop

    // 0x80434C84: bc1fl       L_80434C94
    if (!c1cs) {
        // 0x80434C88: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80434C94;
    }
    goto skip_1;
    // 0x80434C88: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_1:
    // 0x80434C8C: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_80434C90:
    // 0x80434C90: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80434C94:
    // 0x80434C94: nop

    // 0x80434C98: bc1fl       L_80434CA8
    if (!c1cs) {
        // 0x80434C9C: swc1        $f0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
            goto L_80434CA8;
    }
    goto skip_2;
    // 0x80434C9C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    skip_2:
    // 0x80434CA0: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80434CA4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_80434CA8:
    // 0x80434CA8: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x80434CAC: bgez        $a1, L_80434C58
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80434CB0: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80434C58;
    }
    // 0x80434CB0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80434CB4: jr          $ra
    // 0x80434CB8: nop

    return;
    // 0x80434CB8: nop

;}
RECOMP_FUNC void pad_physical_stick_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FBA0: jr          $ra
    // 0x8007FBA4: lb          $v0, 0x3($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3);
    return;
    // 0x8007FBA4: lb          $v0, 0x3($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3);
;}
RECOMP_FUNC void func_80075468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075468: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8007546C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80075470: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80075474: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80075478: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8007547C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80075480: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80075484: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80075488: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8007548C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80075490: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80075494: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80075498: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x8007549C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800754A0: addiu       $s1, $s1, -0x53C0
    ctx->r17 = ADD32(ctx->r17, -0X53C0);
    // 0x800754A4: addiu       $s7, $s0, 0x60
    ctx->r23 = ADD32(ctx->r16, 0X60);
    // 0x800754A8: addiu       $s6, $zero, 0x29E
    ctx->r22 = ADD32(0, 0X29E);
    // 0x800754AC: addiu       $s5, $zero, 0x29D
    ctx->r21 = ADD32(0, 0X29D);
    // 0x800754B0: addiu       $s4, $zero, 0x29A
    ctx->r20 = ADD32(0, 0X29A);
    // 0x800754B4: addiu       $s3, $sp, 0x64
    ctx->r19 = ADD32(ctx->r29, 0X64);
L_800754B8:
    // 0x800754B8: jal         0x8008B920
    // 0x800754BC: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x800754BC: nop

    after_0:
    // 0x800754C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800754C4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800754C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800754CC: jal         0x80082D88
    // 0x800754D0: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800754D0: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_1:
    // 0x800754D4: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800754D8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x800754DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800754E0: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x800754E4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800754E8: jal         0x80082C88
    // 0x800754EC: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_2;
    // 0x800754EC: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_2:
    // 0x800754F0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800754F4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800754F8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800754FC: jal         0x80082C88
    // 0x80075500: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_3;
    // 0x80075500: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_3:
    // 0x80075504: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80075508: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8007550C: jal         0x800824B0
    // 0x80075510: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80075510: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80075514: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80075518: beq         $t6, $s4, L_80075538
    if (ctx->r14 == ctx->r20) {
        // 0x8007551C: nop
    
            goto L_80075538;
    }
    // 0x8007551C: nop

    // 0x80075520: beq         $t6, $s5, L_80075594
    if (ctx->r14 == ctx->r21) {
        // 0x80075524: nop
    
            goto L_80075594;
    }
    // 0x80075524: nop

    // 0x80075528: beq         $t6, $s6, L_800755A4
    if (ctx->r14 == ctx->r22) {
        // 0x8007552C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800755A4;
    }
    // 0x8007552C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80075530: b           L_800755AC
    // 0x80075534: nop

        goto L_800755AC;
    // 0x80075534: nop

L_80075538:
    // 0x80075538: jal         0x8008B920
    // 0x8007553C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_5;
    // 0x8007553C: nop

    after_5:
    // 0x80075540: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80075544: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80075548: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007554C: jal         0x80082D88
    // 0x80075550: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_6;
    // 0x80075550: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_6:
    // 0x80075554: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80075558: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8007555C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80075560: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80075564: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80075568: jal         0x80082C88
    // 0x8007556C: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_7;
    // 0x8007556C: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_7:
    // 0x80075570: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80075574: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80075578: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8007557C: jal         0x80082C88
    // 0x80075580: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_8;
    // 0x80075580: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_8:
    // 0x80075584: jal         0x80075388
    // 0x80075588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80075388(rdram, ctx);
        goto after_9;
    // 0x80075588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8007558C: b           L_800755AC
    // 0x80075590: nop

        goto L_800755AC;
    // 0x80075590: nop

L_80075594:
    // 0x80075594: jal         0x8007524C
    // 0x80075598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007524C(rdram, ctx);
        goto after_10;
    // 0x80075598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8007559C: b           L_800755AC
    // 0x800755A0: nop

        goto L_800755AC;
    // 0x800755A0: nop

L_800755A4:
    // 0x800755A4: jal         0x80075348
    // 0x800755A8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    func_80075348(rdram, ctx);
        goto after_11;
    // 0x800755A8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    after_11:
L_800755AC:
    // 0x800755AC: beq         $s2, $zero, L_800754B8
    if (ctx->r18 == 0) {
        // 0x800755B0: nop
    
            goto L_800754B8;
    }
    // 0x800755B0: nop

    // 0x800755B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800755B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800755BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800755C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800755C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800755C8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800755CC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800755D0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800755D4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800755D8: jr          $ra
    // 0x800755DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800755DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_806DF37C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF37C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806DF380: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806DF384: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806DF388: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(640, 0X3B0) << 16);
    // 0x806DF38C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806DF390: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806DF394: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806DF398: lw          $t8, -0xC50($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(640, 0X3B0));
    // 0x806DF39C: jr          $ra
    // 0x806DF3A0: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x806DF3A0: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x806DF3A4: nop

    // 0x806DF3A8: nop

    // 0x806DF3AC: nop

;}
RECOMP_FUNC void func_8056704C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056704C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80567050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80567054: jal         0x80566E48
    // 0x80567058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80566E48(rdram, ctx);
        goto after_0;
    // 0x80567058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8056705C: jal         0x80566F88
    // 0x80567060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80566F88(rdram, ctx);
        goto after_1;
    // 0x80567060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80567064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80567068: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8056706C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80567070: jal         0x805670F4
    // 0x80567074: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    func_805670F4(rdram, ctx);
        goto after_2;
    // 0x80567074: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    after_2:
    // 0x80567078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8056707C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80567080: jr          $ra
    // 0x80567084: nop

    return;
    // 0x80567084: nop

;}
RECOMP_FUNC void func_8004816C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004816C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048174: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80048178: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x8004817C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80048180: addiu       $a0, $a0, 0x7F0
    ctx->r4 = ADD32(ctx->r4, 0X7F0);
    // 0x80048184: bne         $t7, $zero, L_80048194
    if (ctx->r15 != 0) {
        // 0x80048188: nop
    
            goto L_80048194;
    }
    // 0x80048188: nop

    // 0x8004818C: jal         0x80071380
    // 0x80048190: addiu       $a1, $zero, 0x9F2
    ctx->r5 = ADD32(0, 0X9F2);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80048190: addiu       $a1, $zero, 0x9F2
    ctx->r5 = ADD32(0, 0X9F2);
    after_0:
L_80048194:
    // 0x80048194: jal         0x80048060
    // 0x80048198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80048060(rdram, ctx);
        goto after_1;
    // 0x80048198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8004819C: jal         0x800443EC
    // 0x800481A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800443EC(rdram, ctx);
        goto after_2;
    // 0x800481A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800481A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800481A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800481AC: jr          $ra
    // 0x800481B0: nop

    return;
    // 0x800481B0: nop

;}
RECOMP_FUNC void func_805AE4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE4D4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE4D8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE4DC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE4E0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE4E4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE4E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE4EC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE4F0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE4F4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE4F8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE4FC: jr          $ra
    // 0x805AE500: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE500: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805D1CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D1CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D1CC8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805D1CCC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805D1CD0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805D1CD4: lui         $t8, 0x805D
    ctx->r24 = S32(RELOC_HI16(471, 0X2328) << 16);
    // 0x805D1CD8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805D1CDC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805D1CE0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805D1CE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805D1CE8: lw          $t8, 0x3D58($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(471, 0X2328));
    // 0x805D1CEC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805D1CF0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805D1CF4: jal         0x80048490
    // 0x805D1CF8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805D1CF8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x805D1CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D1D00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D1D04: jr          $ra
    // 0x805D1D08: nop

    return;
    // 0x805D1D08: nop

;}
RECOMP_FUNC void func_806AE458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AE458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AE45C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AE460: jal         0x806AE32C
    // 0x806AE464: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806AE32C(rdram, ctx);
        goto after_0;
    // 0x806AE464: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806AE468: jal         0x806AE270
    // 0x806AE46C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806AE270(rdram, ctx);
        goto after_1;
    // 0x806AE46C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806AE470: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806AE474: beq         $v0, $at, L_806AE490
    if (ctx->r2 == ctx->r1) {
        // 0x806AE478: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806AE490;
    }
    // 0x806AE478: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AE47C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806AE480: beq         $v0, $at, L_806AE4A0
    if (ctx->r2 == ctx->r1) {
        // 0x806AE484: nop
    
            goto L_806AE4A0;
    }
    // 0x806AE484: nop

    // 0x806AE488: b           L_806AE4B0
    // 0x806AE48C: nop

        goto L_806AE4B0;
    // 0x806AE48C: nop

L_806AE490:
    // 0x806AE490: jal         0x806ADEE0
    // 0x806AE494: nop

    func_806ADEE0(rdram, ctx);
        goto after_2;
    // 0x806AE494: nop

    after_2:
    // 0x806AE498: b           L_806AE4BC
    // 0x806AE49C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806AE4BC;
    // 0x806AE49C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806AE4A0:
    // 0x806AE4A0: jal         0x806ADEE0
    // 0x806AE4A4: nop

    func_806ADEE0(rdram, ctx);
        goto after_3;
    // 0x806AE4A4: nop

    after_3:
    // 0x806AE4A8: b           L_806AE4BC
    // 0x806AE4AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806AE4BC;
    // 0x806AE4AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806AE4B0:
    // 0x806AE4B0: jal         0x806ADEE0
    // 0x806AE4B4: nop

    func_806ADEE0(rdram, ctx);
        goto after_4;
    // 0x806AE4B4: nop

    after_4:
    // 0x806AE4B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806AE4BC:
    // 0x806AE4BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AE4C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AE4C4: jr          $ra
    // 0x806AE4C8: nop

    return;
    // 0x806AE4C8: nop

;}
RECOMP_FUNC void func_80553E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553E4C: lw          $t6, 0xDD8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XDD8);
    // 0x80553E50: beq         $t6, $zero, L_80553E9C
    if (ctx->r14 == 0) {
        // 0x80553E54: nop
    
            goto L_80553E9C;
    }
    // 0x80553E54: nop

    // 0x80553E58: lw          $v0, 0xDDC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDDC);
    // 0x80553E5C: beq         $v0, $zero, L_80553E6C
    if (ctx->r2 == 0) {
        // 0x80553E60: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80553E6C;
    }
    // 0x80553E60: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80553E64: b           L_80553EA4
    // 0x80553E68: sw          $t7, 0xDDC($a0)
    MEM_W(0XDDC, ctx->r4) = ctx->r15;
        goto L_80553EA4;
    // 0x80553E68: sw          $t7, 0xDDC($a0)
    MEM_W(0XDDC, ctx->r4) = ctx->r15;
L_80553E6C:
    // 0x80553E6C: lw          $t8, 0xDE0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XDE0);
    // 0x80553E70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80553E74: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80553E78: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80553E7C: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x80553E80: bne         $at, $zero, L_80553E94
    if (ctx->r1 != 0) {
        // 0x80553E84: sw          $t9, 0xDE0($a0)
        MEM_W(0XDE0, ctx->r4) = ctx->r25;
            goto L_80553E94;
    }
    // 0x80553E84: sw          $t9, 0xDE0($a0)
    MEM_W(0XDE0, ctx->r4) = ctx->r25;
    // 0x80553E88: sw          $zero, 0xDE0($a0)
    MEM_W(0XDE0, ctx->r4) = 0;
    // 0x80553E8C: jr          $ra
    // 0x80553E90: sw          $zero, 0xDD8($a0)
    MEM_W(0XDD8, ctx->r4) = 0;
    return;
    // 0x80553E90: sw          $zero, 0xDD8($a0)
    MEM_W(0XDD8, ctx->r4) = 0;
L_80553E94:
    // 0x80553E94: b           L_80553EA4
    // 0x80553E98: sw          $t1, 0xDDC($a0)
    MEM_W(0XDDC, ctx->r4) = ctx->r9;
        goto L_80553EA4;
    // 0x80553E98: sw          $t1, 0xDDC($a0)
    MEM_W(0XDDC, ctx->r4) = ctx->r9;
L_80553E9C:
    // 0x80553E9C: jr          $ra
    // 0x80553EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80553EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80553EA4:
    // 0x80553EA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80553EA8: jr          $ra
    // 0x80553EAC: nop

    return;
    // 0x80553EAC: nop

;}
RECOMP_FUNC void func_8051ACE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051ACE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051ACEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8051ACF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8051ACF4: jal         0x8051A530
    // 0x8051ACF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8051A530(rdram, ctx);
        goto after_0;
    // 0x8051ACF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8051ACFC: jal         0x8051A640
    // 0x8051AD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051A640(rdram, ctx);
        goto after_1;
    // 0x8051AD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8051AD04: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8051AD08: sb          $t6, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r14;
    // 0x8051AD0C: jal         0x800447C8
    // 0x8051AD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8051AD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8051AD14: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8051AD18: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8051AD1C: lui         $a1, 0x8052
    ctx->r5 = S32(RELOC_HI16(294, 0XC54) << 16);
    // 0x8051AD20: addiu       $a1, $a1, -0x4E8C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(294, 0XC54));
    // 0x8051AD24: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8051AD28: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8051AD2C: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8051AD30: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8051AD34: jalr        $t9
    // 0x8051AD38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8051AD38: nop

    after_3:
    // 0x8051AD3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8051AD40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8051AD44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051AD48: jr          $ra
    // 0x8051AD4C: nop

    return;
    // 0x8051AD4C: nop

;}
RECOMP_FUNC void func_8043B688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B688: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043B68C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043B690: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043B694: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8043B698: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8043B69C: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(83, 0X1160) << 16);
    // 0x8043B6A0: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8043B6A4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8043B6A8: addiu       $t7, $t7, -0x4840
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(83, 0X1160));
    // 0x8043B6AC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8043B6B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043B6B4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8043B6B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043B6BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8043B6C0: jal         0x8043B728
    // 0x8043B6C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8043B728(rdram, ctx);
        goto after_0;
    // 0x8043B6C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8043B6C8: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8043B6CC: jal         0x8043B624
    // 0x8043B6D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043B624(rdram, ctx);
        goto after_1;
    // 0x8043B6D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8043B6D4: bne         $v0, $zero, L_8043B6EC
    if (ctx->r2 != 0) {
        // 0x8043B6D8: nop
    
            goto L_8043B6EC;
    }
    // 0x8043B6D8: nop

    // 0x8043B6DC: jal         0x800445A4
    // 0x8043B6E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x8043B6E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8043B6E4: b           L_8043B718
    // 0x8043B6E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8043B718;
    // 0x8043B6E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043B6EC:
    // 0x8043B6EC: jal         0x8043B670
    // 0x8043B6F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043B670(rdram, ctx);
        goto after_3;
    // 0x8043B6F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043B6F4: lui         $t9, 0x8044
    ctx->r25 = S32(RELOC_HI16(83, 0X79C) << 16);
    // 0x8043B6F8: addiu       $t9, $t9, -0x5204
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(83, 0X79C));
    // 0x8043B6FC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8043B700: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x8043B704: sh          $t0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r8;
    // 0x8043B708: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8043B70C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8043B710: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x8043B714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043B718:
    // 0x8043B718: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043B71C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043B720: jr          $ra
    // 0x8043B724: nop

    return;
    // 0x8043B724: nop

;}
RECOMP_FUNC void func_80018C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018C98: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80018C9C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80018CA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80018CA4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80018CA8: jr          $ra
    // 0x80018CAC: sb          $a0, -0x6D14($at)
    MEM_B(-0X6D14, ctx->r1) = ctx->r4;
    return;
    // 0x80018CAC: sb          $a0, -0x6D14($at)
    MEM_B(-0X6D14, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_806752FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806752FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80675300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80675304: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80675308: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8067530C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80675310: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80675314: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(532, 0X318) << 16);
    // 0x80675318: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8067531C: addiu       $t6, $t6, 0x5268
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(532, 0X318));
    // 0x80675320: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80675324: nop

    // 0x80675328: bc1f        L_8067533C
    if (!c1cs) {
        // 0x8067532C: nop
    
            goto L_8067533C;
    }
    // 0x8067532C: nop

    // 0x80675330: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x80675334: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x80675338: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8067533C:
    // 0x8067533C: jal         0x806751EC
    // 0x80675340: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    func_806751EC(rdram, ctx);
        goto after_0;
    // 0x80675340: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x80675344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80675348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067534C: jr          $ra
    // 0x80675350: nop

    return;
    // 0x80675350: nop

;}
RECOMP_FUNC void func_804C8E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C8E5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C8E60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C8E64: jal         0x804C8DC0
    // 0x804C8E68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C8DC0(rdram, ctx);
        goto after_0;
    // 0x804C8E68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C8E6C: jal         0x804C8D14
    // 0x804C8E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804C8D14(rdram, ctx);
        goto after_1;
    // 0x804C8E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804C8E74: beq         $v0, $zero, L_804C8E88
    if (ctx->r2 == 0) {
        // 0x804C8E78: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804C8E88;
    }
    // 0x804C8E78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C8E7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C8E80: jal         0x804C91F8
    // 0x804C8E84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804C91F8(rdram, ctx);
        goto after_2;
    // 0x804C8E84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_804C8E88:
    // 0x804C8E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C8E8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C8E90: jr          $ra
    // 0x804C8E94: nop

    return;
    // 0x804C8E94: nop

;}
RECOMP_FUNC void func_80453B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453B68: jal         0x80453B04
    // 0x80453B6C: nop

    func_80453B04(rdram, ctx);
        goto after_0;
    // 0x80453B6C: nop

    after_0:
    // 0x80453B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453B78: jr          $ra
    // 0x80453B7C: nop

    return;
    // 0x80453B7C: nop

;}
RECOMP_FUNC void func_807B20D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B20D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807B20DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B20E0: jal         0x8004700C
    // 0x807B20E4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807B20E4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x807B20E8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x807B20EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x807B20F0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x807B20F4: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x807B20F8: lw          $t6, 0x170($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X170);
    // 0x807B20FC: beq         $v0, $zero, L_807B21C4
    if (ctx->r2 == 0) {
        // 0x807B2100: sw          $t6, 0x174($v1)
        MEM_W(0X174, ctx->r3) = ctx->r14;
            goto L_807B21C4;
    }
    // 0x807B2100: sw          $t6, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->r14;
    // 0x807B2104: jal         0x80047AB8
    // 0x807B2108: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x807B2108: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x807B210C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x807B2110: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x807B2114: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x807B2118: lw          $t8, 0x140($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X140);
    // 0x807B211C: lwc1        $f4, 0x70($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X70);
    // 0x807B2120: addiu       $a0, $v1, 0x160
    ctx->r4 = ADD32(ctx->r3, 0X160);
    // 0x807B2124: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x807B2128: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807B212C: jal         0x80047AB8
    // 0x807B2130: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x807B2130: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x807B2134: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x807B2138: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x807B213C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x807B2140: lw          $t0, 0x174($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X174);
    // 0x807B2144: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x807B2148: lh          $t2, 0xC($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XC);
    // 0x807B214C: lw          $t1, 0x70($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X70);
    // 0x807B2150: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x807B2154: lwc1        $f10, 0x4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X4);
    // 0x807B2158: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807B215C: lwc1        $f16, 0x160($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X160);
    // 0x807B2160: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x807B2164: lwc1        $f18, 0x164($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X164);
    // 0x807B2168: swc1        $f4, 0x16C($v1)
    MEM_W(0X16C, ctx->r3) = ctx->f4.u32l;
    // 0x807B216C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807B2170: lwc1        $f6, 0x16C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X16C);
    // 0x807B2174: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807B2178: swc1        $f14, 0x144($v1)
    MEM_W(0X144, ctx->r3) = ctx->f14.u32l;
    // 0x807B217C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807B2180: sub.s       $f2, $f16, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x807B2184: swc1        $f2, 0x14C($v1)
    MEM_W(0X14C, ctx->r3) = ctx->f2.u32l;
    // 0x807B2188: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x807B218C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B2190: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x807B2194: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x807B2198: swc1        $f12, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f12.u32l;
    // 0x807B219C: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807B21A0: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x807B21A4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x807B21A8: swc1        $f0, 0x148($v1)
    MEM_W(0X148, ctx->r3) = ctx->f0.u32l;
    // 0x807B21AC: bc1f        L_807B21BC
    if (!c1cs) {
        // 0x807B21B0: nop
    
            goto L_807B21BC;
    }
    // 0x807B21B0: nop

    // 0x807B21B4: b           L_807B21C8
    // 0x807B21B8: sw          $zero, 0x170($v1)
    MEM_W(0X170, ctx->r3) = 0;
        goto L_807B21C8;
    // 0x807B21B8: sw          $zero, 0x170($v1)
    MEM_W(0X170, ctx->r3) = 0;
L_807B21BC:
    // 0x807B21BC: b           L_807B21C8
    // 0x807B21C0: sw          $t3, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->r11;
        goto L_807B21C8;
    // 0x807B21C0: sw          $t3, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->r11;
L_807B21C4:
    // 0x807B21C4: sw          $zero, 0x170($v1)
    MEM_W(0X170, ctx->r3) = 0;
L_807B21C8:
    // 0x807B21C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B21CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x807B21D0: jr          $ra
    // 0x807B21D4: nop

    return;
    // 0x807B21D4: nop

;}
RECOMP_FUNC void func_804EF6D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF6D8: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804EF6DC: beq         $v0, $zero, L_804EF6F4
    if (ctx->r2 == 0) {
        // 0x804EF6E0: nop
    
            goto L_804EF6F4;
    }
    // 0x804EF6E0: nop

    // 0x804EF6E4: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804EF6E8: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x804EF6EC: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804EF6F0: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
L_804EF6F4:
    // 0x804EF6F4: jr          $ra
    // 0x804EF6F8: nop

    return;
    // 0x804EF6F8: nop

;}
RECOMP_FUNC void func_8006E7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E7F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E7F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E7F8: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8006E7FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006E800: beq         $t6, $zero, L_8006E83C
    if (ctx->r14 == 0) {
        // 0x8006E804: nop
    
            goto L_8006E83C;
    }
    // 0x8006E804: nop

    // 0x8006E808: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006E80C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8006E810: jalr        $t9
    // 0x8006E814: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8006E814: nop

    after_0:
    // 0x8006E818: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006E81C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8006E820: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8006E824: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8006E828: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8006E82C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8006E830: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8006E834: b           L_8006E83C
    // 0x8006E838: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8006E83C;
    // 0x8006E838: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8006E83C:
    // 0x8006E83C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E844: jr          $ra
    // 0x8006E848: nop

    return;
    // 0x8006E848: nop

;}
RECOMP_FUNC void func_8073F98C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F98C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8073F990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073F994: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073F998: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8073F99C: jal         0x8004700C
    // 0x8073F9A0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8073F9A0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8073F9A4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8073F9A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8073F9AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8073F9B0: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8073F9B4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8073F9B8: lw          $a3, 0x174($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X174);
    // 0x8073F9BC: beql        $v1, $zero, L_8073FAB8
    if (ctx->r3 == 0) {
        // 0x8073F9C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073FAB8;
    }
    goto skip_0;
    // 0x8073F9C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8073F9C4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8073F9C8: lwc1        $f10, 0x40($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8073F9CC: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8073F9D0: lh          $t9, 0x52($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X52);
    // 0x8073F9D4: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x8073F9D8: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8073F9DC: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8073F9E0: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8073F9E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8073F9E8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8073F9EC: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8073F9F0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8073F9F4: nop

    // 0x8073F9F8: bc1fl       L_8073FA20
    if (!c1cs) {
        // 0x8073F9FC: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8073FA20;
    }
    goto skip_1;
    // 0x8073F9FC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x8073FA00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8073FA04: nop

    // 0x8073FA08: add.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8073FA0C: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8073FA10: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8073FA14: b           L_8073FA48
    // 0x8073FA18: sh          $t1, 0x52($v0)
    MEM_H(0X52, ctx->r2) = ctx->r9;
        goto L_8073FA48;
    // 0x8073FA18: sh          $t1, 0x52($v0)
    MEM_H(0X52, ctx->r2) = ctx->r9;
    // 0x8073FA1C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8073FA20:
    // 0x8073FA20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8073FA24: bc1fl       L_8073FA4C
    if (!c1cs) {
        // 0x8073FA28: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8073FA4C;
    }
    goto skip_2;
    // 0x8073FA28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    skip_2:
    // 0x8073FA2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8073FA30: nop

    // 0x8073FA34: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8073FA38: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8073FA3C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8073FA40: nop

    // 0x8073FA44: sh          $t3, 0x52($v0)
    MEM_H(0X52, ctx->r2) = ctx->r11;
L_8073FA48:
    // 0x8073FA48: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
L_8073FA4C:
    // 0x8073FA4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8073FA50: jal         0x80062684
    // 0x8073FA54: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80062684(rdram, ctx);
        goto after_1;
    // 0x8073FA54: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8073FA58: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8073FA5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8073FA60: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8073FA64: beql        $a2, $zero, L_8073FAB8
    if (ctx->r6 == 0) {
        // 0x8073FA68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073FAB8;
    }
    goto skip_3;
    // 0x8073FA68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8073FA6C: lw          $t4, 0x180($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X180);
    // 0x8073FA70: bnel        $a0, $t4, L_8073FA9C
    if (ctx->r4 != ctx->r12) {
        // 0x8073FA74: lw          $v0, 0x0($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X0);
            goto L_8073FA9C;
    }
    goto skip_4;
    // 0x8073FA74: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    skip_4:
    // 0x8073FA78: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8073FA7C: lbu         $t5, 0x77($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X77);
    // 0x8073FA80: beql        $t5, $zero, L_8073FAB8
    if (ctx->r13 == 0) {
        // 0x8073FA84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073FAB8;
    }
    goto skip_5;
    // 0x8073FA84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8073FA88: jal         0x8005FB2C
    // 0x8073FA8C: sb          $zero, 0x74($v0)
    MEM_B(0X74, ctx->r2) = 0;
    func_8005FB2C(rdram, ctx);
        goto after_2;
    // 0x8073FA8C: sb          $zero, 0x74($v0)
    MEM_B(0X74, ctx->r2) = 0;
    after_2:
    // 0x8073FA90: b           L_8073FAB8
    // 0x8073FA94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8073FAB8;
    // 0x8073FA94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073FA98: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_8073FA9C:
    // 0x8073FA9C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8073FAA0: lbu         $t6, 0x77($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X77);
    // 0x8073FAA4: bnel        $t6, $zero, L_8073FAB8
    if (ctx->r14 != 0) {
        // 0x8073FAA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073FAB8;
    }
    goto skip_6;
    // 0x8073FAA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8073FAAC: jal         0x8005FAE0
    // 0x8073FAB0: sb          $t7, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r15;
    func_8005FAE0(rdram, ctx);
        goto after_3;
    // 0x8073FAB0: sb          $t7, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r15;
    after_3:
    // 0x8073FAB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8073FAB8:
    // 0x8073FAB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8073FABC: jr          $ra
    // 0x8073FAC0: nop

    return;
    // 0x8073FAC0: nop

;}
RECOMP_FUNC void func_80434774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434774: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80434778: lwc1        $f6, 0xE0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x8043477C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80434780: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80434784: nop

    // 0x80434788: bc1t        L_804347A0
    if (c1cs) {
        // 0x8043478C: nop
    
            goto L_804347A0;
    }
    // 0x8043478C: nop

    // 0x80434790: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80434794: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80434798: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8043479C: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
L_804347A0:
    // 0x804347A0: jr          $ra
    // 0x804347A4: nop

    return;
    // 0x804347A4: nop

;}
RECOMP_FUNC void func_8004CE68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CE68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004CE6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004CE70: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004CE74: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004CE78: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004CE7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004CE80: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004CE84: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004CE88: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004CE8C: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004CE90: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8004CE94: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8004CE98: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8004CE9C: jal         0x8004AF8C
    // 0x8004CEA0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8004AF8C(rdram, ctx);
        goto after_0;
    // 0x8004CEA0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004CEA4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004CEA8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8004CEAC: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8004CEB0: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x8004CEB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004CEB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004CEBC: jr          $ra
    // 0x8004CEC0: nop

    return;
    // 0x8004CEC0: nop

;}
RECOMP_FUNC void func_807ADE38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ADE38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807ADE3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807ADE40: lw          $v1, 0xE8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XE8);
    // 0x807ADE44: lw          $t6, 0x1F4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1F4);
    // 0x807ADE48: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807ADE4C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x807ADE50: jal         0x8004700C
    // 0x807ADE54: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807ADE54: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x807ADE58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807ADE5C: jal         0x807ADB40
    // 0x807ADE60: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_807ADB40(rdram, ctx);
        goto after_1;
    // 0x807ADE60: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x807ADE64: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807ADE68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807ADE6C: beq         $v0, $zero, L_807ADEFC
    if (ctx->r2 == 0) {
        // 0x807ADE70: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_807ADEFC;
    }
    // 0x807ADE70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x807ADE74: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x807ADE78: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x807ADE7C: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x807ADE80: beql        $v0, $zero, L_807ADEB4
    if (ctx->r2 == 0) {
        // 0x807ADE84: lui         $at, 0x4320
        ctx->r1 = S32(0X4320 << 16);
            goto L_807ADEB4;
    }
    goto skip_0;
    // 0x807ADE84: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    skip_0:
    // 0x807ADE88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807ADE8C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807ADE90: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x807ADE94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807ADE98: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x807ADE9C: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x807ADEA0: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807ADEA4: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x807ADEA8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x807ADEAC: swc1        $f10, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f10.u32l;
    // 0x807ADEB0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
L_807ADEB4:
    // 0x807ADEB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807ADEB8: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807ADEBC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x807ADEC0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807ADEC4: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x807ADEC8: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x807ADECC: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807ADED0: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x807ADED4: beq         $a1, $zero, L_807ADEF4
    if (ctx->r5 == 0) {
        // 0x807ADED8: swc1        $f6, 0x40($v1)
        MEM_W(0X40, ctx->r3) = ctx->f6.u32l;
            goto L_807ADEF4;
    }
    // 0x807ADED8: swc1        $f6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f6.u32l;
    // 0x807ADEDC: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807ADEE0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x807ADEE4: swc1        $f10, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f10.u32l;
    // 0x807ADEE8: lwc1        $f16, 0x88($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807ADEEC: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x807ADEF0: swc1        $f18, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f18.u32l;
L_807ADEF4:
    // 0x807ADEF4: b           L_807ADF00
    // 0x807ADEF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807ADF00;
    // 0x807ADEF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807ADEFC:
    // 0x807ADEFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807ADF00:
    // 0x807ADF00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807ADF04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807ADF08: jr          $ra
    // 0x807ADF0C: nop

    return;
    // 0x807ADF0C: nop

;}
RECOMP_FUNC void func_807BB7A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB7A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BB7A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807BB7AC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x807BB7B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BB7B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x807BB7B8: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x807BB7BC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807BB7C0: lui         $t9, 0x807C
    ctx->r25 = S32(RELOC_HI16(895, 0X11FC) << 16);
    // 0x807BB7C4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807BB7C8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x807BB7CC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x807BB7D0: lw          $t9, -0x45F4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(895, 0X11FC));
    // 0x807BB7D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x807BB7D8: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x807BB7DC: jal         0x807BA86C
    // 0x807BB7E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807BA86C(rdram, ctx);
        goto after_0;
    // 0x807BB7E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807BB7E4: jal         0x807BA970
    // 0x807BB7E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_807BA970(rdram, ctx);
        goto after_1;
    // 0x807BB7E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807BB7EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BB7F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BB7F4: jr          $ra
    // 0x807BB7F8: nop

    return;
    // 0x807BB7F8: nop

    // 0x807BB7FC: nop

;}
RECOMP_FUNC void func_800440E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800440E4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800440E8: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x800440EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800440F0: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x800440F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800440F8: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800440FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80044100: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80044104: beq         $t8, $zero, L_80044124
    if (ctx->r24 == 0) {
        // 0x80044108: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80044124;
    }
    // 0x80044108: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8004410C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044110: addiu       $a0, $a0, 0x3F0
    ctx->r4 = ADD32(ctx->r4, 0X3F0);
    // 0x80044114: jal         0x80071380
    // 0x80044118: addiu       $a1, $zero, 0x390
    ctx->r5 = ADD32(0, 0X390);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80044118: addiu       $a1, $zero, 0x390
    ctx->r5 = ADD32(0, 0X390);
    after_0:
    // 0x8004411C: b           L_80044184
    // 0x80044120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80044184;
    // 0x80044120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80044124:
    // 0x80044124: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80044128: lui         $at, 0x1997
    ctx->r1 = S32(0X1997 << 16);
    // 0x8004412C: ori         $at, $at, 0x1110
    ctx->r1 = ctx->r1 | 0X1110;
    // 0x80044130: beq         $t9, $at, L_8004414C
    if (ctx->r25 == ctx->r1) {
        // 0x80044134: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8004414C;
    }
    // 0x80044134: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044138: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // 0x8004413C: jal         0x80071380
    // 0x80044140: addiu       $a1, $zero, 0x39A
    ctx->r5 = ADD32(0, 0X39A);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80044140: addiu       $a1, $zero, 0x39A
    ctx->r5 = ADD32(0, 0X39A);
    after_1:
    // 0x80044144: b           L_80044184
    // 0x80044148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80044184;
    // 0x80044148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004414C:
    // 0x8004414C: jal         0x8005FDC4
    // 0x80044150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_2;
    // 0x80044150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80044154: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80044158: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8004415C: jal         0x80043A88
    // 0x80044160: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    func_80043A88(rdram, ctx);
        goto after_3;
    // 0x80044160: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    after_3:
    // 0x80044164: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80044168: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004416C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80044170: jal         0x80043C0C
    // 0x80044174: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80043C0C(rdram, ctx);
        goto after_4;
    // 0x80044174: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x80044178: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8004417C: sb          $t2, 0x17D($s0)
    MEM_B(0X17D, ctx->r16) = ctx->r10;
    // 0x80044180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80044184:
    // 0x80044184: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80044188: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004418C: jr          $ra
    // 0x80044190: nop

    return;
    // 0x80044190: nop

;}
RECOMP_FUNC void func_804B6580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6580: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x804B6584: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x804B6588: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804B658C: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x804B6590: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804B6594: nop

    // 0x804B6598: bc1fl       L_804B65C8
    if (!c1cs) {
        // 0x804B659C: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_804B65C8;
    }
    goto skip_0;
    // 0x804B659C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x804B65A0: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804B65A4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804B65A8: nop

    // 0x804B65AC: bc1f        L_804B65F4
    if (!c1cs) {
        // 0x804B65B0: nop
    
            goto L_804B65F4;
    }
    // 0x804B65B0: nop

    // 0x804B65B4: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x804B65B8: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x804B65BC: jr          $ra
    // 0x804B65C0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x804B65C0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x804B65C4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_804B65C8:
    // 0x804B65C8: nop

    // 0x804B65CC: bc1f        L_804B65F4
    if (!c1cs) {
        // 0x804B65D0: nop
    
            goto L_804B65F4;
    }
    // 0x804B65D0: nop

    // 0x804B65D4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804B65D8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804B65DC: nop

    // 0x804B65E0: bc1f        L_804B65F4
    if (!c1cs) {
        // 0x804B65E4: nop
    
            goto L_804B65F4;
    }
    // 0x804B65E4: nop

    // 0x804B65E8: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x804B65EC: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x804B65F0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_804B65F4:
    // 0x804B65F4: jr          $ra
    // 0x804B65F8: nop

    return;
    // 0x804B65F8: nop

;}
RECOMP_FUNC void func_80454EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454EA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80454EA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80454EAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80454EB0: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X1390C) << 16);
    // 0x80454EB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80454EB8: jal         0x804548E4
    // 0x80454EBC: lw          $a1, 0x7CEC($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X1390C));
    func_804548E4(rdram, ctx);
        goto after_0;
    // 0x80454EBC: lw          $a1, 0x7CEC($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X1390C));
    after_0:
    // 0x80454EC0: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80454EC4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454EC8: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80454ECC: addu        $a0, $v1, $at
    ctx->r4 = ADD32(ctx->r3, ctx->r1);
    // 0x80454ED0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454ED4: ori         $at, $at, 0x6D8C
    ctx->r1 = ctx->r1 | 0X6D8C;
    // 0x80454ED8: addu        $a1, $v1, $at
    ctx->r5 = ADD32(ctx->r3, ctx->r1);
    // 0x80454EDC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454EE0: ori         $at, $at, 0x6D90
    ctx->r1 = ctx->r1 | 0X6D90;
    // 0x80454EE4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80454EE8: addu        $a2, $v1, $at
    ctx->r6 = ADD32(ctx->r3, ctx->r1);
    // 0x80454EEC: jal         0x804549D4
    // 0x80454EF0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_804549D4(rdram, ctx);
        goto after_1;
    // 0x80454EF0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80454EF4: beq         $v0, $zero, L_80454F1C
    if (ctx->r2 == 0) {
        // 0x80454EF8: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80454F1C;
    }
    // 0x80454EF8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80454EFC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454F00: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80454F04: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80454F08: sw          $t6, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r14;
    // 0x80454F0C: jal         0x804457C0
    // 0x80454F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804457C0(rdram, ctx);
        goto after_2;
    // 0x80454F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80454F14: jal         0x8045359C
    // 0x80454F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8045359C(rdram, ctx);
        goto after_3;
    // 0x80454F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80454F1C:
    // 0x80454F1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80454F20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80454F24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80454F28: jr          $ra
    // 0x80454F2C: nop

    return;
    // 0x80454F2C: nop

;}
RECOMP_FUNC void func_80019B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019B94: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80019B98: jr          $ra
    // 0x80019B9C: lw          $v0, -0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X20);
    return;
    // 0x80019B9C: lw          $v0, -0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X20);
;}
RECOMP_FUNC void func_8044BE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BE74: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8044BE78: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x8044BE7C: jr          $ra
    // 0x8044BE80: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x8044BE80: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void func_8044BA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BA24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044BA28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044BA2C: jal         0x8044B740
    // 0x8044BA30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8044B740(rdram, ctx);
        goto after_0;
    // 0x8044BA30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8044BA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044BA38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044BA3C: jr          $ra
    // 0x8044BA40: nop

    return;
    // 0x8044BA40: nop

;}
RECOMP_FUNC void func_8067B66C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067B66C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8067B670: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8067B674: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067B678: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067B67C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8067B680: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x8067B684: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8067B688: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8067B68C: jal         0x80080050
    // 0x8067B690: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80080050(rdram, ctx);
        goto after_0;
    // 0x8067B690: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x8067B694: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8067B698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8067B69C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8067B6A0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8067B6A4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8067B6A8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8067B6AC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8067B6B0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8067B6B4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8067B6B8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8067B6BC: jal         0x80080798
    // 0x8067B6C0: nop

    func_80080798(rdram, ctx);
        goto after_1;
    // 0x8067B6C0: nop

    after_1:
    // 0x8067B6C4: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8067B6C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8067B6CC: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x8067B6D0: jal         0x80080440
    // 0x8067B6D4: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    func_80080440(rdram, ctx);
        goto after_2;
    // 0x8067B6D4: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    after_2:
    // 0x8067B6D8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8067B6DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8067B6E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8067B6E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8067B6E8: jal         0x800662B8
    // 0x8067B6EC: lw          $a1, 0x10($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X10);
    func_800662B8(rdram, ctx);
        goto after_3;
    // 0x8067B6EC: lw          $a1, 0x10($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X10);
    after_3:
    // 0x8067B6F0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8067B6F4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8067B6F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8067B6FC: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x8067B700: sll         $a2, $a2, 6
    ctx->r6 = S32(ctx->r6 << 6);
    // 0x8067B704: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8067B708: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8067B70C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8067B710: sll         $t0, $t0, 6
    ctx->r8 = S32(ctx->r8 << 6);
    // 0x8067B714: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8067B718: addu        $a0, $t1, $a2
    ctx->r4 = ADD32(ctx->r9, ctx->r6);
    // 0x8067B71C: jal         0x800817A0
    // 0x8067B720: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    MtxConv_F2L(rdram, ctx);
        goto after_4;
    // 0x8067B720: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    after_4:
    // 0x8067B724: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8067B728: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8067B72C: lui         $t3, 0x104
    ctx->r11 = S32(0X104 << 16);
    // 0x8067B730: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8067B734: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8067B738: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x8067B73C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8067B740: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8067B744: lui         $t2, 0x8068
    ctx->r10 = S32(RELOC_HI16(541, 0X3140) << 16);
    // 0x8067B748: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x8067B74C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8067B750: ori         $t1, $t1, 0x207F
    ctx->r9 = ctx->r9 | 0X207F;
    // 0x8067B754: addiu       $t2, $t2, -0x3210
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(541, 0X3140));
    // 0x8067B758: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8067B75C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8067B760: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x8067B764: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8067B768: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x8067B76C: addiu       $t9, $t8, 0x38
    ctx->r25 = ADD32(ctx->r24, 0X38);
    // 0x8067B770: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8067B774: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8067B778: lui         $t4, 0x6
    ctx->r12 = S32(0X6 << 16);
    // 0x8067B77C: lui         $t5, 0xB100
    ctx->r13 = S32(0XB100 << 16);
    // 0x8067B780: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8067B784: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8067B788: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8067B78C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8067B790: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8067B794: ori         $t5, $t5, 0x204
    ctx->r13 = ctx->r13 | 0X204;
    // 0x8067B798: ori         $t4, $t4, 0x4
    ctx->r12 = ctx->r12 | 0X4;
    // 0x8067B79C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8067B7A0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8067B7A4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8067B7A8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8067B7AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8067B7B0: lui         $t7, 0xBD00
    ctx->r15 = S32(0XBD00 << 16);
    // 0x8067B7B4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8067B7B8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8067B7BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8067B7C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8067B7C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067B7C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8067B7CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8067B7D0: jr          $ra
    // 0x8067B7D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8067B7D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_806810CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806810CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806810D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x806810D4: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x806810D8: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x806810DC: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x806810E0: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x806810E4: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x806810E8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x806810EC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x806810F0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x806810F4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x806810F8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x806810FC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80681100: lui         $t7, 0x104
    ctx->r15 = S32(0X104 << 16);
    // 0x80681104: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80681108: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8068110C: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x80681110: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80681114: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80681118: lui         $s5, 0xE700
    ctx->r21 = S32(0XE700 << 16);
    // 0x8068111C: lui         $s6, 0x400
    ctx->r22 = S32(0X400 << 16);
    // 0x80681120: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x80681124: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x80681128: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8068112C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80681130: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681134: lui         $s7, 0x8068
    ctx->r23 = S32(RELOC_HI16(550, 0X1D30) << 16);
    // 0x80681138: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8068113C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80681140: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80681144: addiu       $s7, $s7, 0x2140
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(550, 0X1D30));
    // 0x80681148: ori         $s6, $s6, 0x81FF
    ctx->r22 = ctx->r22 | 0X81FF;
    // 0x8068114C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80681150: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80681154: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80681158: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8068115C: addiu       $fp, $zero, 0x7E0
    ctx->r30 = ADD32(0, 0X7E0);
    // 0x80681160: lui         $ra, 0xFD50
    ctx->r31 = S32(0XFD50 << 16);
    // 0x80681164: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80681168: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8068116C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
L_80681170:
    // 0x80681170: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x80681174: bne         $at, $zero, L_806811A4
    if (ctx->r1 != 0) {
        // 0x80681178: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_806811A4;
    }
    // 0x80681178: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8068117C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681180: sll         $t6, $s3, 4
    ctx->r14 = S32(ctx->r19 << 4);
    // 0x80681184: addu        $t7, $s7, $t6
    ctx->r15 = ADD32(ctx->r23, ctx->r14);
    // 0x80681188: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8068118C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80681190: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80681194: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x80681198: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8068119C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x806811A0: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
L_806811A4:
    // 0x806811A4: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x806811A8: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x806811AC: addiu       $t1, $v1, 0x2
    ctx->r9 = ADD32(ctx->r3, 0X2);
    // 0x806811B0: addiu       $t2, $v1, 0x4
    ctx->r10 = ADD32(ctx->r3, 0X4);
    // 0x806811B4: bne         $at, $zero, L_806811C0
    if (ctx->r1 != 0) {
        // 0x806811B8: addiu       $t3, $v1, 0x6
        ctx->r11 = ADD32(ctx->r3, 0X6);
            goto L_806811C0;
    }
    // 0x806811B8: addiu       $t3, $v1, 0x6
    ctx->r11 = ADD32(ctx->r3, 0X6);
    // 0x806811BC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_806811C0:
    // 0x806811C0: multu       $t4, $fp
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806811C4: lw          $t8, 0x168($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X168);
    // 0x806811C8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x806811CC: andi        $a0, $t2, 0xFF
    ctx->r4 = ctx->r10 & 0XFF;
    // 0x806811D0: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x806811D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x806811D8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x806811DC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x806811E0: lui         $at, 0xB100
    ctx->r1 = S32(0XB100 << 16);
    // 0x806811E4: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x806811E8: mflo        $t6
    ctx->r14 = lo;
    // 0x806811EC: addu        $t0, $t9, $t6
    ctx->r8 = ADD32(ctx->r25, ctx->r14);
    // 0x806811F0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x806811F4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x806811F8: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x806811FC: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x80681200: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80681204: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80681208: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8068120C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80681210: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681214: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80681218: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8068121C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80681220: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80681224: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80681228: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8068122C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681230: lui         $t7, 0x73E
    ctx->r15 = S32(0X73E << 16);
    // 0x80681234: ori         $t7, $t7, 0xF0AB
    ctx->r15 = ctx->r15 | 0XF0AB;
    // 0x80681238: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8068123C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80681240: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80681244: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80681248: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8068124C: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80681250: ori         $t6, $t6, 0x1800
    ctx->r14 = ctx->r14 | 0X1800;
    // 0x80681254: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80681258: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8068125C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80681260: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80681264: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681268: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8068126C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80681270: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80681274: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80681278: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8068127C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80681280: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681284: lui         $t9, 0x17
    ctx->r25 = S32(0X17 << 16);
    // 0x80681288: ori         $t9, $t9, 0xC050
    ctx->r25 = ctx->r25 | 0XC050;
    // 0x8068128C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80681290: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80681294: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80681298: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8068129C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x806812A0: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x806812A4: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x806812A8: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x806812AC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x806812B0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x806812B4: sll         $t9, $v0, 8
    ctx->r25 = S32(ctx->r2 << 8);
    // 0x806812B8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x806812BC: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x806812C0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x806812C4: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x806812C8: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x806812CC: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x806812D0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x806812D4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x806812D8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x806812DC: or          $t6, $t8, $a0
    ctx->r14 = ctx->r24 | ctx->r4;
    // 0x806812E0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806812E4: bne         $s2, $at, L_80681170
    if (ctx->r18 != ctx->r1) {
        // 0x806812E8: sw          $t6, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->r14;
            goto L_80681170;
    }
    // 0x806812E8: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x806812EC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x806812F0: lui         $t7, 0xBD00
    ctx->r15 = S32(0XBD00 << 16);
    // 0x806812F4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x806812F8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x806812FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80681300: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80681304: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80681308: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8068130C: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80681310: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80681314: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80681318: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8068131C: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80681320: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80681324: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80681328: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8068132C: jr          $ra
    // 0x80681330: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80681330: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_805ADC50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADC50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805ADC54: lui         $at, 0x805C
    ctx->r1 = S32(RELOC_HI16(444, 0X183F4) << 16);
    // 0x805ADC58: lwc1        $f0, 0x5AF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(444, 0X183F4));
    // 0x805ADC5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805ADC60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805ADC64: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805ADC68: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805ADC6C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805ADC70: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805ADC74: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x805ADC78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805ADC7C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805ADC80: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805ADC84: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x805ADC88: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x805ADC8C: jal         0x805AD70C
    // 0x805ADC90: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_805AD70C(rdram, ctx);
        goto after_0;
    // 0x805ADC90: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805ADC94: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805ADC98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ADC9C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805ADCA0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x805ADCA4: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x805ADCA8: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x805ADCAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805ADCB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ADCB4: jr          $ra
    // 0x805ADCB8: nop

    return;
    // 0x805ADCB8: nop

;}
RECOMP_FUNC void func_8002AF54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AF54: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8002AF58: lbu         $t6, 0x7EA5($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7EA5);
    // 0x8002AF5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AF60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AF64: bnel        $t6, $zero, L_8002AF80
    if (ctx->r14 != 0) {
        // 0x8002AF68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002AF80;
    }
    goto skip_0;
    // 0x8002AF68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002AF6C: jal         0x8002AF3C
    // 0x8002AF70: nop

    func_8002AF3C(rdram, ctx);
        goto after_0;
    // 0x8002AF70: nop

    after_0:
    // 0x8002AF74: jal         0x8002AEE4
    // 0x8002AF78: nop

    func_8002AEE4(rdram, ctx);
        goto after_1;
    // 0x8002AF78: nop

    after_1:
    // 0x8002AF7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002AF80:
    // 0x8002AF80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002AF84: jr          $ra
    // 0x8002AF88: nop

    return;
    // 0x8002AF88: nop

;}
RECOMP_FUNC void func_80437148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437148: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043714C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80437150: lwc1        $f6, 0x4C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80437154: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80437158: jr          $ra
    // 0x8043715C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8043715C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80019AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019AC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80019AC8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80019ACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019AD0: addiu       $a0, $a0, -0x4820
    ctx->r4 = ADD32(ctx->r4, -0X4820);
    // 0x80019AD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80019AD8: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
L_80019ADC:
    // 0x80019ADC: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019AE0: mflo        $t6
    ctx->r14 = lo;
    // 0x80019AE4: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80019AE8: lw          $t7, 0x3C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3C);
    // 0x80019AEC: bne         $t7, $zero, L_80019B34
    if (ctx->r15 != 0) {
        // 0x80019AF0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80019B34;
    }
    // 0x80019AF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80019AF4: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
    // 0x80019AF8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80019AFC: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
    // 0x80019B00: jal         0x80019BA0
    // 0x80019B04: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80019BA0(rdram, ctx);
        goto after_0;
    // 0x80019B04: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80019B08: bne         $v0, $zero, L_80019B20
    if (ctx->r2 != 0) {
        // 0x80019B0C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80019B20;
    }
    // 0x80019B0C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80019B10: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80019B14: sw          $v1, -0x20($at)
    MEM_W(-0X20, ctx->r1) = ctx->r3;
    // 0x80019B18: b           L_80019B28
    // 0x80019B1C: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
        goto L_80019B28;
    // 0x80019B1C: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
L_80019B20:
    // 0x80019B20: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    // 0x80019B24: sw          $v0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r2;
L_80019B28:
    // 0x80019B28: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x80019B2C: b           L_80019B4C
    // 0x80019B30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80019B4C;
    // 0x80019B30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80019B34:
    // 0x80019B34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80019B38: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80019B3C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80019B40: bne         $at, $zero, L_80019ADC
    if (ctx->r1 != 0) {
        // 0x80019B44: nop
    
            goto L_80019ADC;
    }
    // 0x80019B44: nop

    // 0x80019B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80019B4C:
    // 0x80019B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019B50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80019B54: jr          $ra
    // 0x80019B58: nop

    return;
    // 0x80019B58: nop

;}
RECOMP_FUNC void func_80078D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078D84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80078D88: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80078D8C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80078D90: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x80078D94: jal         0x80084820
    // 0x80078D98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x80078D98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80078D9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80078DA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80078DA4: jal         0x80084820
    // 0x80078DA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_1;
    // 0x80078DA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80078DAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80078DB0: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80078DB4: addiu       $t7, $t7, -0x73E0
    ctx->r15 = ADD32(ctx->r15, -0X73E0);
    // 0x80078DB8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80078DBC: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80078DC0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80078DC4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80078DC8: beql        $t8, $zero, L_80078DE4
    if (ctx->r24 == 0) {
        // 0x80078DCC: lbu         $t1, 0x8($a0)
        ctx->r9 = MEM_BU(ctx->r4, 0X8);
            goto L_80078DE4;
    }
    goto skip_0;
    // 0x80078DCC: lbu         $t1, 0x8($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X8);
    skip_0:
    // 0x80078DD0: lbu         $t9, 0x8($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X8);
    // 0x80078DD4: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x80078DD8: b           L_80078DEC
    // 0x80078DDC: sb          $t0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r8;
        goto L_80078DEC;
    // 0x80078DDC: sb          $t0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r8;
    // 0x80078DE0: lbu         $t1, 0x8($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X8);
L_80078DE4:
    // 0x80078DE4: andi        $t2, $t1, 0xFFFB
    ctx->r10 = ctx->r9 & 0XFFFB;
    // 0x80078DE8: sb          $t2, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r10;
L_80078DEC:
    // 0x80078DEC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80078DF0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80078DF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80078DF8: sb          $t3, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r11;
    // 0x80078DFC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80078E00: sw          $t4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r12;
    // 0x80078E04: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80078E08: sb          $zero, 0x18($a0)
    MEM_B(0X18, ctx->r4) = 0;
    // 0x80078E0C: sb          $v0, 0x1F($a0)
    MEM_B(0X1F, ctx->r4) = ctx->r2;
    // 0x80078E10: sb          $v0, 0x1E($a0)
    MEM_B(0X1E, ctx->r4) = ctx->r2;
    // 0x80078E14: sb          $v0, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r2;
    // 0x80078E18: sb          $v0, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r2;
    // 0x80078E1C: sb          $v1, 0x23($a0)
    MEM_B(0X23, ctx->r4) = ctx->r3;
    // 0x80078E20: sb          $v1, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r3;
    // 0x80078E24: sb          $v1, 0x21($a0)
    MEM_B(0X21, ctx->r4) = ctx->r3;
    // 0x80078E28: sb          $v1, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r3;
    // 0x80078E2C: sw          $t5, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r13;
    // 0x80078E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078E34: jr          $ra
    // 0x80078E38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80078E38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078E3C: nop

;}
RECOMP_FUNC void func_804554E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804554E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804554E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804554EC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804554F0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804554F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804554F8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804554FC: lwc1        $f0, 0x6CE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6CE0);
    // 0x80455500: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80455504: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80455508: nop

    // 0x8045550C: bc1f        L_8045552C
    if (!c1cs) {
        // 0x80455510: nop
    
            goto L_8045552C;
    }
    // 0x80455510: nop

    // 0x80455514: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80455518: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045551C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455520: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80455524: b           L_80455534
    // 0x80455528: swc1        $f8, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f8.u32l;
        goto L_80455534;
    // 0x80455528: swc1        $f8, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f8.u32l;
L_8045552C:
    // 0x8045552C: jal         0x80453B60
    // 0x80455530: nop

    func_80453B60(rdram, ctx);
        goto after_0;
    // 0x80455530: nop

    after_0:
L_80455534:
    // 0x80455534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045553C: jr          $ra
    // 0x80455540: nop

    return;
    // 0x80455540: nop

;}
RECOMP_FUNC void func_8005C420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C420: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8005C424: bne         $at, $zero, L_8005C4C4
    if (ctx->r1 != 0) {
        // 0x8005C428: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005C4C4;
    }
    // 0x8005C428: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005C42C:
    // 0x8005C42C: blez        $a1, L_8005C4B8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005C430: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005C4B8;
    }
    // 0x8005C430: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005C434: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8005C438: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C43C: andi        $t4, $a1, 0x3
    ctx->r12 = ctx->r5 & 0X3;
    // 0x8005C440: or          $t3, $t4, $zero
    ctx->r11 = ctx->r12 | 0;
    // 0x8005C444: mflo        $t7
    ctx->r15 = lo;
    // 0x8005C448: addu        $a3, $a0, $t7
    ctx->r7 = ADD32(ctx->r4, ctx->r15);
    // 0x8005C44C: addu        $t0, $a3, $zero
    ctx->r8 = ADD32(ctx->r7, 0);
    // 0x8005C450: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C454: mflo        $t8
    ctx->r24 = lo;
    // 0x8005C458: addu        $t1, $t8, $a0
    ctx->r9 = ADD32(ctx->r24, ctx->r4);
    // 0x8005C45C: beq         $t4, $zero, L_8005C480
    if (ctx->r12 == 0) {
        // 0x8005C460: addu        $t2, $t1, $zero
        ctx->r10 = ADD32(ctx->r9, 0);
            goto L_8005C480;
    }
    // 0x8005C460: addu        $t2, $t1, $zero
    ctx->r10 = ADD32(ctx->r9, 0);
L_8005C464:
    // 0x8005C464: lbu         $t9, 0x0($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X0);
    // 0x8005C468: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005C46C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005C470: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8005C474: bne         $t3, $v1, L_8005C464
    if (ctx->r11 != ctx->r3) {
        // 0x8005C478: sb          $t9, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r25;
            goto L_8005C464;
    }
    // 0x8005C478: sb          $t9, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r25;
    // 0x8005C47C: beq         $v1, $a1, L_8005C4B8
    if (ctx->r3 == ctx->r5) {
        // 0x8005C480: addu        $t0, $a3, $v1
        ctx->r8 = ADD32(ctx->r7, ctx->r3);
            goto L_8005C4B8;
    }
L_8005C480:
    // 0x8005C480: addu        $t0, $a3, $v1
    ctx->r8 = ADD32(ctx->r7, ctx->r3);
    // 0x8005C484: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
L_8005C488:
    // 0x8005C488: lbu         $t5, 0x0($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X0);
    // 0x8005C48C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005C490: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8005C494: sb          $t5, -0x4($t0)
    MEM_B(-0X4, ctx->r8) = ctx->r13;
    // 0x8005C498: lbu         $t6, 0x1($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X1);
    // 0x8005C49C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8005C4A0: sb          $t6, -0x3($t0)
    MEM_B(-0X3, ctx->r8) = ctx->r14;
    // 0x8005C4A4: lbu         $t7, -0x2($t2)
    ctx->r15 = MEM_BU(ctx->r10, -0X2);
    // 0x8005C4A8: sb          $t7, -0x2($t0)
    MEM_B(-0X2, ctx->r8) = ctx->r15;
    // 0x8005C4AC: lbu         $t8, -0x1($t2)
    ctx->r24 = MEM_BU(ctx->r10, -0X1);
    // 0x8005C4B0: bne         $v1, $a1, L_8005C488
    if (ctx->r3 != ctx->r5) {
        // 0x8005C4B4: sb          $t8, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r24;
            goto L_8005C488;
    }
    // 0x8005C4B4: sb          $t8, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r24;
L_8005C4B8:
    // 0x8005C4B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005C4BC: bne         $v0, $a2, L_8005C42C
    if (ctx->r2 != ctx->r6) {
        // 0x8005C4C0: nop
    
            goto L_8005C42C;
    }
    // 0x8005C4C0: nop

L_8005C4C4:
    // 0x8005C4C4: jr          $ra
    // 0x8005C4C8: nop

    return;
    // 0x8005C4C8: nop

;}
RECOMP_FUNC void func_805364D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805364D4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805364D8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805364DC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805364E0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805364E4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805364E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805364EC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805364F0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805364F4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805364F8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805364FC: jr          $ra
    // 0x80536500: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536500: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void Fault_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007127C: lui         $t7, 0xFFFA
    ctx->r15 = S32(0XFFFA << 16);
    // 0x80071280: or          $t8, $sp, $zero
    ctx->r24 = ctx->r29 | 0;
    // 0x80071284: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80071288: ori         $t7, $t7, 0x5A5A
    ctx->r15 = ctx->r15 | 0X5A5A;
L_8007128C:
    // 0x8007128C: addiu       $t8, $t8, -0x8
    ctx->r24 = ADD32(ctx->r24, -0X8);
    // 0x80071290: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80071294: bne         $t8, $sp, L_8007128C
    if (ctx->r24 != ctx->r29) {
        // 0x80071298: sw          $t7, 0x4($t8)
        MEM_W(0X4, ctx->r24) = ctx->r15;
            goto L_8007128C;
    }
    // 0x80071298: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8007129C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800712A0: addiu       $v0, $v0, -0x7968
    ctx->r2 = ADD32(ctx->r2, -0X7968);
    // 0x800712A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800712A8: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x800712AC: addiu       $t7, $t7, -0x7FF8
    ctx->r15 = ADD32(ctx->r15, -0X7FF8);
    // 0x800712B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800712B4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800712B8: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800712BC: lw          $t8, 0x318($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X318);
    // 0x800712C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800712C4: addiu       $t1, $zero, 0x140
    ctx->r9 = ADD32(0, 0X140);
    // 0x800712C8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800712CC: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x800712D0: ori         $at, $at, 0xA800
    ctx->r1 = ctx->r1 | 0XA800;
    // 0x800712D4: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x800712D8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800712DC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800712E0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800712E4: sw          $t0, 0x5CC($v0)
    MEM_W(0X5CC, ctx->r2) = ctx->r8;
    // 0x800712E8: sh          $t1, 0x5D0($v0)
    MEM_H(0X5D0, ctx->r2) = ctx->r9;
    // 0x800712EC: sh          $t2, 0x5D2($v0)
    MEM_H(0X5D2, ctx->r2) = ctx->r10;
    // 0x800712F0: addiu       $a1, $a1, -0x73A0
    ctx->r5 = ADD32(ctx->r5, -0X73A0);
    // 0x800712F4: addiu       $a0, $a0, -0x73B8
    ctx->r4 = ADD32(ctx->r4, -0X73B8);
    // 0x800712F8: jal         0x8008AE20
    // 0x800712FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800712FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80071300: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x80071304: addiu       $t4, $t4, 0x1A38
    ctx->r12 = ADD32(ctx->r12, 0X1A38);
    // 0x80071308: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007130C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80071310: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80071314: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x80071318: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8007131C: addiu       $a2, $a2, -0x6F90
    ctx->r6 = ADD32(ctx->r6, -0X6F90);
    // 0x80071320: addiu       $a1, $a1, -0x7390
    ctx->r5 = ADD32(ctx->r5, -0X7390);
    // 0x80071324: addiu       $a0, $a0, -0x6F90
    ctx->r4 = ADD32(ctx->r4, -0X6F90);
    // 0x80071328: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8007132C: jal         0x80081910
    // 0x80071330: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_1;
    // 0x80071330: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80071334: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80071338: addiu       $t5, $t5, -0x6F90
    ctx->r13 = ADD32(ctx->r13, -0X6F90);
    // 0x8007133C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071340: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80071344: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x80071348: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8007134C: addiu       $a2, $a2, 0xFB0
    ctx->r6 = ADD32(ctx->r6, 0XFB0);
    // 0x80071350: addiu       $a0, $a0, -0x7968
    ctx->r4 = ADD32(ctx->r4, -0X7968);
    // 0x80071354: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80071358: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007135C: jal         0x80085B10
    // 0x80071360: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80071360: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80071364: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071368: jal         0x80090CC0
    // 0x8007136C: addiu       $a0, $a0, -0x7968
    ctx->r4 = ADD32(ctx->r4, -0X7968);
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x8007136C: addiu       $a0, $a0, -0x7968
    ctx->r4 = ADD32(ctx->r4, -0X7968);
    after_3:
    // 0x80071370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80071374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80071378: jr          $ra
    // 0x8007137C: nop

    return;
    // 0x8007137C: nop

;}
RECOMP_FUNC void func_80470EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80470EE0: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(152, 0X10) << 16);
    // 0x80470EE4: jr          $ra
    // 0x80470EE8: addiu       $v0, $v0, 0xEF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(152, 0X10));
    return;
    // 0x80470EE8: addiu       $v0, $v0, 0xEF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(152, 0X10));
    // 0x80470EEC: nop

;}
RECOMP_FUNC void func_80445FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445FD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445FD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445FDC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80445FE0: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x80445FE4: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x80445FE8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80445FEC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80445FF0: sw          $a1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r5;
    // 0x80445FF4: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80445FF8: sw          $t6, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r14;
    // 0x80445FFC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446000: sw          $t7, 0x6CA0($at)
    MEM_W(0X6CA0, ctx->r1) = ctx->r15;
    // 0x80446004: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X131D8) << 16);
    // 0x80446008: lw          $v1, 0x75B8($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X131D8));
    // 0x8044600C: beql        $v1, $zero, L_80446020
    if (ctx->r3 == 0) {
        // 0x80446010: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80446020;
    }
    goto skip_0;
    // 0x80446010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80446014: jalr        $v1
    // 0x80446018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80446018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8044601C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80446020:
    // 0x80446020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80446024: jr          $ra
    // 0x80446028: nop

    return;
    // 0x80446028: nop

;}
RECOMP_FUNC void func_8076CAD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076CAD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8076CAD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076CAD8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076CADC: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x8076CAE0: bnel        $t6, $zero, L_8076CB08
    if (ctx->r14 != 0) {
        // 0x8076CAE4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8076CB08;
    }
    goto skip_0;
    // 0x8076CAE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8076CAE8: jal         0x80045A34
    // 0x8076CAEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8076CAEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8076CAF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8076CAF4: bne         $v0, $zero, L_8076CB04
    if (ctx->r2 != 0) {
        // 0x8076CAF8: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8076CB04;
    }
    // 0x8076CAF8: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8076CAFC: b           L_8076CB08
    // 0x8076CB00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8076CB08;
    // 0x8076CB00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8076CB04:
    // 0x8076CB04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8076CB08:
    // 0x8076CB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8076CB0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8076CB10: jr          $ra
    // 0x8076CB14: nop

    return;
    // 0x8076CB14: nop

;}
RECOMP_FUNC void func_8064ECB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064ECB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8064ECBC: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(501, 0X15D40) << 16);
    // 0x8064ECC0: lwc1        $f0, 0x4740($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(501, 0X15D40));
    // 0x8064ECC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8064ECC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8064ECCC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8064ECD0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8064ECD4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8064ECD8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064ECDC: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x8064ECE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8064ECE4: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8064ECE8: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8064ECEC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8064ECF0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8064ECF4: jal         0x8064EA0C
    // 0x8064ECF8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8064EA0C(rdram, ctx);
        goto after_0;
    // 0x8064ECF8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8064ECFC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8064ED00: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(501, 0X15D44) << 16);
    // 0x8064ED04: lwc1        $f2, 0x4744($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(501, 0X15D44));
    // 0x8064ED08: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x8064ED0C: addiu       $t8, $zero, 0x1EF0
    ctx->r24 = ADD32(0, 0X1EF0);
    // 0x8064ED10: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8064ED14: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8064ED18: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8064ED1C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8064ED20: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8064ED24: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8064ED28: jal         0x8064EA0C
    // 0x8064ED2C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8064EA0C(rdram, ctx);
        goto after_1;
    // 0x8064ED2C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8064ED30: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8064ED34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064ED38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064ED3C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8064ED40: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8064ED44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8064ED48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8064ED4C: jr          $ra
    // 0x8064ED50: nop

    return;
    // 0x8064ED50: nop

;}
RECOMP_FUNC void func_800574F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800574F4: lw          $v1, 0x1CC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1CC);
    // 0x800574F8: lw          $t6, 0x1B4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1B4);
    // 0x800574FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80057500: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80057504: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057508: mflo        $t7
    ctx->r15 = lo;
    // 0x8005750C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80057510: blez        $v1, L_80057558
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80057514: addu        $v0, $a0, $t8
        ctx->r2 = ADD32(ctx->r4, ctx->r24);
            goto L_80057558;
    }
    // 0x80057514: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x80057518: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005751C: lbu         $t9, 0x1D0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1D0);
L_80057520:
    // 0x80057520: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80057524: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80057528: sb          $t9, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r25;
    // 0x8005752C: lbu         $t0, 0x1D1($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X1D1);
    // 0x80057530: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80057534: sb          $t0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r8;
    // 0x80057538: lbu         $t1, 0x1CE($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X1CE);
    // 0x8005753C: sb          $t1, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r9;
    // 0x80057540: lbu         $t2, 0x1CF($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1CF);
    // 0x80057544: sb          $t2, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r10;
    // 0x80057548: lw          $t3, 0x1CC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1CC);
    // 0x8005754C: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80057550: bnel        $at, $zero, L_80057520
    if (ctx->r1 != 0) {
        // 0x80057554: lbu         $t9, 0x1D0($a1)
        ctx->r25 = MEM_BU(ctx->r5, 0X1D0);
            goto L_80057520;
    }
    goto skip_0;
    // 0x80057554: lbu         $t9, 0x1D0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1D0);
    skip_0:
L_80057558:
    // 0x80057558: jr          $ra
    // 0x8005755C: nop

    return;
    // 0x8005755C: nop

;}
RECOMP_FUNC void func_80515D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80515D04: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE70) << 16);
    // 0x80515D08: lwc1        $f2, 0x6310($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE70));
    // 0x80515D0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80515D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80515D14: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE74) << 16);
    // 0x80515D18: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80515D1C: lwc1        $f4, 0x6314($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE74));
    // 0x80515D20: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80515D24: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80515D28: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80515D2C: nop

    // 0x80515D30: bc1fl       L_80515D58
    if (!c1cs) {
        // 0x80515D34: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_80515D58;
    }
    goto skip_0;
    // 0x80515D34: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x80515D38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80515D3C: jal         0x80515DD4
    // 0x80515D40: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80515DD4(rdram, ctx);
        goto after_0;
    // 0x80515D40: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80515D44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80515D48: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80515D4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80515D50: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80515D54: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80515D58:
    // 0x80515D58: jal         0x805158B4
    // 0x80515D5C: nop

    func_805158B4(rdram, ctx);
        goto after_1;
    // 0x80515D5C: nop

    after_1:
    // 0x80515D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80515D64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80515D68: jr          $ra
    // 0x80515D6C: nop

    return;
    // 0x80515D6C: nop

;}
RECOMP_FUNC void func_806FDE70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FDE70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806FDE74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FDE78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806FDE7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806FDE80: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FDE84: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806FDE88: jal         0x80057754
    // 0x806FDE8C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80057754(rdram, ctx);
        goto after_0;
    // 0x806FDE8C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x806FDE90: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x806FDE94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDE98: jal         0x806FD60C
    // 0x806FDE9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806FD60C(rdram, ctx);
        goto after_1;
    // 0x806FDE9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x806FDEA0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806FDEA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806FDEA8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806FDEAC: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(706, 0X12C4) << 16);
    // 0x806FDEB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806FDEB4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806FDEB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDEBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806FDEC0: bc1fl       L_806FDED8
    if (!c1cs) {
        // 0x806FDEC4: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_806FDED8;
    }
    goto skip_0;
    // 0x806FDEC4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x806FDEC8: lwc1        $f6, -0x18DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(706, 0X12C4));
    // 0x806FDECC: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x806FDED0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x806FDED4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_806FDED8:
    // 0x806FDED8: lwc1        $f10, 0x88($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X88);
    // 0x806FDEDC: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(706, 0X12C8) << 16);
    // 0x806FDEE0: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x806FDEE4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806FDEE8: nop

    // 0x806FDEEC: bc1f        L_806FDF04
    if (!c1cs) {
        // 0x806FDEF0: nop
    
            goto L_806FDF04;
    }
    // 0x806FDEF0: nop

    // 0x806FDEF4: lwc1        $f18, -0x18D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(706, 0X12C8));
    // 0x806FDEF8: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    // 0x806FDEFC: jal         0x806FE468
    // 0x806FDF00: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    func_806FE468(rdram, ctx);
        goto after_2;
    // 0x806FDF00: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_2:
L_806FDF04:
    // 0x806FDF04: jal         0x806FDA5C
    // 0x806FDF08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806FDA5C(rdram, ctx);
        goto after_3;
    // 0x806FDF08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x806FDF0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806FDF10: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806FDF14: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806FDF18: jr          $ra
    // 0x806FDF1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806FDF1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80025ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025ABC: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80025AC0: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80025AC4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80025AC8: addiu       $t8, $t8, 0x4748
    ctx->r24 = ADD32(ctx->r24, 0X4748);
    // 0x80025ACC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80025AD0: sb          $t7, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r15;
    // 0x80025AD4: jr          $ra
    // 0x80025AD8: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
    return;
    // 0x80025AD8: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80050048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050050: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050054: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80050058: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8005005C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80050060: lw          $a3, 0x1B8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1B8);
    // 0x80050064: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80050068: beq         $a3, $zero, L_8005009C
    if (ctx->r7 == 0) {
        // 0x8005006C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8005009C;
    }
    // 0x8005006C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80050070: jal         0x8004FEB4
    // 0x80050074: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8004FEB4(rdram, ctx);
        goto after_0;
    // 0x80050074: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x80050078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005007C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80050080: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80050084: jal         0x8004FEC8
    // 0x80050088: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_8004FEC8(rdram, ctx);
        goto after_1;
    // 0x80050088: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8005008C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80050090: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80050094: jal         0x8004FE44
    // 0x80050098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004FE44(rdram, ctx);
        goto after_2;
    // 0x80050098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_8005009C:
    // 0x8005009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800500A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800500A4: jr          $ra
    // 0x800500A8: nop

    return;
    // 0x800500A8: nop

;}
RECOMP_FUNC void func_80441EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441EB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80441EBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80441EC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80441EC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80441EC8: jal         0x80045A34
    // 0x80441ECC: addiu       $a1, $zero, 0x2638
    ctx->r5 = ADD32(0, 0X2638);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80441ECC: addiu       $a1, $zero, 0x2638
    ctx->r5 = ADD32(0, 0X2638);
    after_0:
    // 0x80441ED0: bne         $v0, $zero, L_80441EE0
    if (ctx->r2 != 0) {
        // 0x80441ED4: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_80441EE0;
    }
    // 0x80441ED4: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80441ED8: b           L_80441EF4
    // 0x80441EDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80441EF4;
    // 0x80441EDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80441EE0:
    // 0x80441EE0: jal         0x80441D98
    // 0x80441EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80441D98(rdram, ctx);
        goto after_1;
    // 0x80441EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80441EE8: jal         0x80441D38
    // 0x80441EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80441D38(rdram, ctx);
        goto after_2;
    // 0x80441EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80441EF0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80441EF4:
    // 0x80441EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80441EF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80441EFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80441F00: jr          $ra
    // 0x80441F04: nop

    return;
    // 0x80441F04: nop

;}
RECOMP_FUNC void func_8043D41C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D41C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043D420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043D424: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8043D428: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    // 0x8043D42C: lui         $a1, 0x8044
    ctx->r5 = S32(RELOC_HI16(92, 0X1A08) << 16);
    // 0x8043D430: lw          $v1, 0x138($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X138);
    // 0x8043D434: lhu         $t0, 0xC($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XC);
    // 0x8043D438: addiu       $a1, $a1, -0x15B8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(92, 0X1A08));
    // 0x8043D43C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8043D440: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8043D444: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8043D448: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x8043D44C: addiu       $at, $zero, 0x406B
    ctx->r1 = ADD32(0, 0X406B);
    // 0x8043D450: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8043D454: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8043D458: bne         $t0, $at, L_8043D480
    if (ctx->r8 != ctx->r1) {
        // 0x8043D45C: lwc1        $f14, 0x0($t9)
        ctx->f14.u32l = MEM_W(ctx->r25, 0X0);
            goto L_8043D480;
    }
    // 0x8043D45C: lwc1        $f14, 0x0($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8043D460: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8043D464: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043D468: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8043D46C: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8043D470: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8043D474: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8043D478: b           L_8043D49C
    // 0x8043D47C: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
        goto L_8043D49C;
    // 0x8043D47C: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
L_8043D480:
    // 0x8043D480: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8043D484: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043D488: lwc1        $f18, 0x84($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8043D48C: lwc1        $f10, 0x84($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X84);
    // 0x8043D490: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8043D494: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8043D498: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
L_8043D49C:
    // 0x8043D49C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B6C) << 16);
    // 0x8043D4A0: lwc1        $f16, -0x1454($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B6C));
    // 0x8043D4A4: lwc1        $f0, 0xC4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x8043D4A8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B70) << 16);
    // 0x8043D4AC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8043D4B0: nop

    // 0x8043D4B4: bc1t        L_8043D540
    if (c1cs) {
        // 0x8043D4B8: nop
    
            goto L_8043D540;
    }
    // 0x8043D4B8: nop

    // 0x8043D4BC: lwc1        $f6, -0x1450($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B70));
    // 0x8043D4C0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8043D4C4: nop

    // 0x8043D4C8: bc1t        L_8043D540
    if (c1cs) {
        // 0x8043D4CC: nop
    
            goto L_8043D540;
    }
    // 0x8043D4CC: nop

    // 0x8043D4D0: mul.s       $f18, $f12, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8043D4D4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8043D4D8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B74) << 16);
    // 0x8043D4DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8043D4E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043D4E4: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x8043D4E8: nop

    // 0x8043D4EC: bc1f        L_8043D520
    if (!c1cs) {
        // 0x8043D4F0: nop
    
            goto L_8043D520;
    }
    // 0x8043D4F0: nop

    // 0x8043D4F4: lwc1        $f4, -0x144C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B74));
    // 0x8043D4F8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B78) << 16);
    // 0x8043D4FC: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    // 0x8043D500: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8043D504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8043D508: swc1        $f8, 0xDC($a3)
    MEM_W(0XDC, ctx->r7) = ctx->f8.u32l;
    // 0x8043D50C: lwc1        $f10, -0x1448($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B78));
    // 0x8043D510: jal         0x80048F84
    // 0x8043D514: swc1        $f10, 0xE8($a3)
    MEM_W(0XE8, ctx->r7) = ctx->f10.u32l;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8043D514: swc1        $f10, 0xE8($a3)
    MEM_W(0XE8, ctx->r7) = ctx->f10.u32l;
    after_0:
    // 0x8043D518: b           L_8043D60C
    // 0x8043D51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043D60C;
    // 0x8043D51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043D520:
    // 0x8043D520: jal         0x8043E490
    // 0x8043D524: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8043E490(rdram, ctx);
        goto after_1;
    // 0x8043D524: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x8043D528: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8043D52C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8043D530: nop

    // 0x8043D534: swc1        $f2, 0xE8($a3)
    MEM_W(0XE8, ctx->r7) = ctx->f2.u32l;
    // 0x8043D538: b           L_8043D608
    // 0x8043D53C: swc1        $f2, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f2.u32l;
        goto L_8043D608;
    // 0x8043D53C: swc1        $f2, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f2.u32l;
L_8043D540:
    // 0x8043D540: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8043D544: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8043D548: nop

    // 0x8043D54C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8043D550: nop

    // 0x8043D554: bc1f        L_8043D5BC
    if (!c1cs) {
        // 0x8043D558: nop
    
            goto L_8043D5BC;
    }
    // 0x8043D558: nop

    // 0x8043D55C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8043D560: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8043D564: jal         0x80065954
    // 0x8043D568: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8043D568: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x8043D56C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B7C) << 16);
    // 0x8043D570: lwc1        $f6, -0x1444($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B7C));
    // 0x8043D574: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8043D578: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8043D57C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8043D580: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8043D584: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B84) << 16);
    // 0x8043D588: bc1fl       L_8043D5AC
    if (!c1cs) {
        // 0x8043D58C: swc1        $f12, 0xC4($a3)
        MEM_W(0XC4, ctx->r7) = ctx->f12.u32l;
            goto L_8043D5AC;
    }
    goto skip_0;
    // 0x8043D58C: swc1        $f12, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f12.u32l;
    skip_0:
    // 0x8043D590: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B80) << 16);
    // 0x8043D594: lwc1        $f18, -0x1440($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B80));
    // 0x8043D598: mul.s       $f0, $f18, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8043D59C: swc1        $f0, 0xDC($a3)
    MEM_W(0XDC, ctx->r7) = ctx->f0.u32l;
    // 0x8043D5A0: b           L_8043D608
    // 0x8043D5A4: swc1        $f0, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f0.u32l;
        goto L_8043D608;
    // 0x8043D5A4: swc1        $f0, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f0.u32l;
    // 0x8043D5A8: swc1        $f12, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f12.u32l;
L_8043D5AC:
    // 0x8043D5AC: lwc1        $f4, -0x143C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B84));
    // 0x8043D5B0: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8043D5B4: b           L_8043D608
    // 0x8043D5B8: swc1        $f8, 0xDC($a3)
    MEM_W(0XDC, ctx->r7) = ctx->f8.u32l;
        goto L_8043D608;
    // 0x8043D5B8: swc1        $f8, 0xDC($a3)
    MEM_W(0XDC, ctx->r7) = ctx->f8.u32l;
L_8043D5BC:
    // 0x8043D5BC: bne         $v1, $a2, L_8043D5E8
    if (ctx->r3 != ctx->r6) {
        // 0x8043D5C0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8043D5E8;
    }
    // 0x8043D5C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8043D5C4: swc1        $f2, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f2.u32l;
    // 0x8043D5C8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B88) << 16);
    // 0x8043D5CC: lwc1        $f10, -0x1438($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B88));
    // 0x8043D5D0: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    // 0x8043D5D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8043D5D8: jal         0x80048F84
    // 0x8043D5DC: swc1        $f10, 0xE8($a3)
    MEM_W(0XE8, ctx->r7) = ctx->f10.u32l;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x8043D5DC: swc1        $f10, 0xE8($a3)
    MEM_W(0XE8, ctx->r7) = ctx->f10.u32l;
    after_3:
    // 0x8043D5E0: b           L_8043D60C
    // 0x8043D5E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043D60C;
    // 0x8043D5E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043D5E8:
    // 0x8043D5E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043D5EC: jal         0x8043E490
    // 0x8043D5F0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8043E490(rdram, ctx);
        goto after_4;
    // 0x8043D5F0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_4:
    // 0x8043D5F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8043D5F8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8043D5FC: nop

    // 0x8043D600: swc1        $f2, 0xE8($a3)
    MEM_W(0XE8, ctx->r7) = ctx->f2.u32l;
    // 0x8043D604: swc1        $f2, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f2.u32l;
L_8043D608:
    // 0x8043D608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043D60C:
    // 0x8043D60C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043D610: jr          $ra
    // 0x8043D614: nop

    return;
    // 0x8043D614: nop

;}
RECOMP_FUNC void func_8001DDA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DDA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DDA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DDA8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001DDAC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001DDB0: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001DDB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001DDB8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001DDBC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8001DDC0: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001DDC4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001DDC8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8001DDCC: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8001DDD0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8001DDD4: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8001DDD8: jal         0x8002F6E4
    // 0x8001DDDC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x8001DDDC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8001DDE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DDE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001DDE8: jr          $ra
    // 0x8001DDEC: nop

    return;
    // 0x8001DDEC: nop

;}
RECOMP_FUNC void func_804B94F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B94F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B94F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B94FC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804B9500: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804B9504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B9508: jal         0x8004921C
    // 0x804B950C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804B950C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x804B9510: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x804B9514: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804B9518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B951C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804B9520: jal         0x8004921C
    // 0x804B9524: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804B9524: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x804B9528: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x804B952C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804B9530: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804B9534: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804B9538: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x804B953C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804B9540: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x804B9544: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x804B9548: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x804B954C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x804B9550: addiu       $a3, $zero, 0x5C0
    ctx->r7 = ADD32(0, 0X5C0);
    // 0x804B9554: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x804B9558: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804B955C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x804B9560: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804B9564: mul.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x804B9568: sb          $a2, 0x337($t3)
    MEM_B(0X337, ctx->r11) = ctx->r6;
    // 0x804B956C: sb          $a1, 0x336($t3)
    MEM_B(0X336, ctx->r11) = ctx->r5;
    // 0x804B9570: sb          $zero, 0x335($t3)
    MEM_B(0X335, ctx->r11) = 0;
    // 0x804B9574: sb          $zero, 0x334($t3)
    MEM_B(0X334, ctx->r11) = 0;
    // 0x804B9578: mul.s       $f14, $f4, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x804B957C: sh          $zero, 0x332($t3)
    MEM_H(0X332, ctx->r11) = 0;
    // 0x804B9580: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x804B9584: sh          $zero, 0x330($t3)
    MEM_H(0X330, ctx->r11) = 0;
    // 0x804B9588: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x804B958C: sh          $zero, 0x32E($t3)
    MEM_H(0X32E, ctx->r11) = 0;
    // 0x804B9590: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x804B9594: sh          $zero, 0x32C($t3)
    MEM_H(0X32C, ctx->r11) = 0;
    // 0x804B9598: addiu       $t3, $t3, 0x328
    ctx->r11 = ADD32(ctx->r11, 0X328);
    // 0x804B959C: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x804B95A0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x804B95A4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804B95A8: sh          $a3, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r7;
    // 0x804B95AC: sb          $a2, 0x1F($t3)
    MEM_B(0X1F, ctx->r11) = ctx->r6;
    // 0x804B95B0: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x804B95B4: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x804B95B8: sb          $a1, 0x1E($t3)
    MEM_B(0X1E, ctx->r11) = ctx->r5;
    // 0x804B95BC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804B95C0: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x804B95C4: sb          $zero, 0x1D($t3)
    MEM_B(0X1D, ctx->r11) = 0;
    // 0x804B95C8: sb          $zero, 0x1C($t3)
    MEM_B(0X1C, ctx->r11) = 0;
    // 0x804B95CC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x804B95D0: sh          $zero, 0x18($t3)
    MEM_H(0X18, ctx->r11) = 0;
    // 0x804B95D4: sh          $zero, 0x16($t3)
    MEM_H(0X16, ctx->r11) = 0;
    // 0x804B95D8: sh          $zero, 0x14($t3)
    MEM_H(0X14, ctx->r11) = 0;
    // 0x804B95DC: sh          $a3, 0x368($t3)
    MEM_H(0X368, ctx->r11) = ctx->r7;
    // 0x804B95E0: sb          $a2, 0x36F($t3)
    MEM_B(0X36F, ctx->r11) = ctx->r6;
    // 0x804B95E4: sb          $a1, 0x36E($t3)
    MEM_B(0X36E, ctx->r11) = ctx->r5;
    // 0x804B95E8: sb          $zero, 0x36D($t3)
    MEM_B(0X36D, ctx->r11) = 0;
    // 0x804B95EC: sb          $zero, 0x36C($t3)
    MEM_B(0X36C, ctx->r11) = 0;
    // 0x804B95F0: sh          $zero, 0x36A($t3)
    MEM_H(0X36A, ctx->r11) = 0;
    // 0x804B95F4: sh          $zero, 0x366($t3)
    MEM_H(0X366, ctx->r11) = 0;
    // 0x804B95F8: sh          $zero, 0x364($t3)
    MEM_H(0X364, ctx->r11) = 0;
    // 0x804B95FC: sh          $a3, 0x378($t3)
    MEM_H(0X378, ctx->r11) = ctx->r7;
    // 0x804B9600: sh          $a3, 0x37A($t3)
    MEM_H(0X37A, ctx->r11) = ctx->r7;
    // 0x804B9604: sb          $a2, 0x37F($t3)
    MEM_B(0X37F, ctx->r11) = ctx->r6;
    // 0x804B9608: sb          $a1, 0x37E($t3)
    MEM_B(0X37E, ctx->r11) = ctx->r5;
    // 0x804B960C: sb          $zero, 0x37D($t3)
    MEM_B(0X37D, ctx->r11) = 0;
    // 0x804B9610: sb          $zero, 0x37C($t3)
    MEM_B(0X37C, ctx->r11) = 0;
    // 0x804B9614: sh          $zero, 0x376($t3)
    MEM_H(0X376, ctx->r11) = 0;
    // 0x804B9618: sh          $zero, 0x374($t3)
    MEM_H(0X374, ctx->r11) = 0;
    // 0x804B961C: sh          $v1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r3;
    // 0x804B9620: sh          $v1, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r3;
    // 0x804B9624: sh          $t1, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r9;
    // 0x804B9628: sh          $t1, 0x362($t3)
    MEM_H(0X362, ctx->r11) = ctx->r9;
    // 0x804B962C: sh          $t2, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r10;
    // 0x804B9630: sh          $t2, 0x372($t3)
    MEM_H(0X372, ctx->r11) = ctx->r10;
    // 0x804B9634: sh          $a0, 0x360($t3)
    MEM_H(0X360, ctx->r11) = ctx->r4;
    // 0x804B9638: sh          $a0, 0x370($t3)
    MEM_H(0X370, ctx->r11) = ctx->r4;
L_804B963C:
    // 0x804B963C: bne         $t4, $zero, L_804B964C
    if (ctx->r12 != 0) {
        // 0x804B9640: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_804B964C;
    }
    // 0x804B9640: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804B9644: b           L_804B964C
    // 0x804B9648: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_804B964C;
    // 0x804B9648: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_804B964C:
    // 0x804B964C: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x804B9650: beq         $at, $zero, L_804B972C
    if (ctx->r1 == 0) {
        // 0x804B9654: sll         $t7, $t4, 3
        ctx->r15 = S32(ctx->r12 << 3);
            goto L_804B972C;
    }
    // 0x804B9654: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x804B9658: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x804B965C: sll         $t6, $t9, 6
    ctx->r14 = S32(ctx->r25 << 6);
    // 0x804B9660: addu        $v0, $t6, $t3
    ctx->r2 = ADD32(ctx->r14, ctx->r11);
L_804B9664:
    // 0x804B9664: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x804B9668: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x804B966C: slti        $at, $t0, 0x34
    ctx->r1 = SIGNED(ctx->r8) < 0X34 ? 1 : 0;
    // 0x804B9670: sh          $t1, -0x1E($v0)
    MEM_H(-0X1E, ctx->r2) = ctx->r9;
    // 0x804B9674: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x804B9678: sh          $zero, -0x1C($v0)
    MEM_H(-0X1C, ctx->r2) = 0;
    // 0x804B967C: sh          $zero, -0x1A($v0)
    MEM_H(-0X1A, ctx->r2) = 0;
    // 0x804B9680: sh          $a3, -0x18($v0)
    MEM_H(-0X18, ctx->r2) = ctx->r7;
    // 0x804B9684: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x804B9688: sh          $zero, -0x16($v0)
    MEM_H(-0X16, ctx->r2) = 0;
    // 0x804B968C: sb          $zero, -0x14($v0)
    MEM_B(-0X14, ctx->r2) = 0;
    // 0x804B9690: sb          $zero, -0x13($v0)
    MEM_B(-0X13, ctx->r2) = 0;
    // 0x804B9694: sb          $a1, -0x12($v0)
    MEM_B(-0X12, ctx->r2) = ctx->r5;
    // 0x804B9698: sb          $a2, -0x11($v0)
    MEM_B(-0X11, ctx->r2) = ctx->r6;
    // 0x804B969C: sh          $t2, -0xE($v0)
    MEM_H(-0XE, ctx->r2) = ctx->r10;
    // 0x804B96A0: sh          $zero, -0xC($v0)
    MEM_H(-0XC, ctx->r2) = 0;
    // 0x804B96A4: sh          $zero, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = 0;
    // 0x804B96A8: sh          $a3, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r7;
    // 0x804B96AC: sh          $a3, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r7;
    // 0x804B96B0: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x804B96B4: sb          $zero, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = 0;
    // 0x804B96B8: sb          $a1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r5;
    // 0x804B96BC: sb          $a2, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r6;
    // 0x804B96C0: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
    // 0x804B96C4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x804B96C8: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x804B96CC: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x804B96D0: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x804B96D4: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x804B96D8: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x804B96DC: sb          $a1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r5;
    // 0x804B96E0: sb          $a2, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r6;
    // 0x804B96E4: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x804B96E8: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    // 0x804B96EC: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x804B96F0: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x804B96F4: sh          $a3, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r7;
    // 0x804B96F8: sb          $zero, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = 0;
    // 0x804B96FC: sb          $zero, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = 0;
    // 0x804B9700: sb          $a1, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r5;
    // 0x804B9704: sb          $a2, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r6;
    // 0x804B9708: sh          $v1, -0x20($v0)
    MEM_H(-0X20, ctx->r2) = ctx->r3;
    // 0x804B970C: sh          $v1, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r3;
    // 0x804B9710: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x804B9714: beq         $at, $zero, L_804B972C
    if (ctx->r1 == 0) {
        // 0x804B9718: sh          $v1, 0x10($v0)
        MEM_H(0X10, ctx->r2) = ctx->r3;
            goto L_804B972C;
    }
    // 0x804B9718: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x804B971C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x804B9720: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x804B9724: bne         $at, $zero, L_804B9664
    if (ctx->r1 != 0) {
        // 0x804B9728: addiu       $v0, $v0, 0x40
        ctx->r2 = ADD32(ctx->r2, 0X40);
            goto L_804B9664;
    }
    // 0x804B9728: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
L_804B972C:
    // 0x804B972C: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x804B9730: bne         $at, $zero, L_804B9740
    if (ctx->r1 != 0) {
        // 0x804B9734: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_804B9740;
    }
    // 0x804B9734: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x804B9738: bne         $t4, $t5, L_804B963C
    if (ctx->r12 != ctx->r13) {
        // 0x804B973C: nop
    
            goto L_804B963C;
    }
    // 0x804B973C: nop

L_804B9740:
    // 0x804B9740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B9744: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804B9748: jr          $ra
    // 0x804B974C: nop

    return;
    // 0x804B974C: nop

;}
RECOMP_FUNC void func_80474E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474E20: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474E24: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474E28: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474E2C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474E30: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474E34: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474E38: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474E3C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474E40: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474E44: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474E48: jr          $ra
    // 0x80474E4C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474E4C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806F95A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F95A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F95A4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x806F95A8: beq         $v1, $zero, L_806F95B4
    if (ctx->r3 == 0) {
        // 0x806F95AC: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_806F95B4;
    }
    // 0x806F95AC: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x806F95B0: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_806F95B4:
    // 0x806F95B4: jr          $ra
    // 0x806F95B8: nop

    return;
    // 0x806F95B8: nop

;}
RECOMP_FUNC void func_8069CAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069CAA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069CAA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069CAA8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8069CAAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8069CAB0: jal         0x80048F84
    // 0x8069CAB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8069CAB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8069CAB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069CABC: jal         0x80048F84
    // 0x8069CAC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8069CAC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8069CAC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069CAC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069CACC: jr          $ra
    // 0x8069CAD0: nop

    return;
    // 0x8069CAD0: nop

;}
RECOMP_FUNC void func_804506FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804506FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80450700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450704: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80450708: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045070C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450710: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80450714: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80450718: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8045071C: sw          $t6, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r14;
    // 0x80450720: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450724: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80450728: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    // 0x8045072C: jal         0x804449C0
    // 0x80450730: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804449C0(rdram, ctx);
        goto after_0;
    // 0x80450730: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80450734: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80450738: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8045073C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450740: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80450744: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80450748: jal         0x80450490
    // 0x8045074C: swc1        $f14, 0x6C88($at)
    MEM_W(0X6C88, ctx->r1) = ctx->f14.u32l;
    func_80450490(rdram, ctx);
        goto after_1;
    // 0x8045074C: swc1        $f14, 0x6C88($at)
    MEM_W(0X6C88, ctx->r1) = ctx->f14.u32l;
    after_1:
    // 0x80450750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80450754: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80450758: jr          $ra
    // 0x8045075C: nop

    return;
    // 0x8045075C: nop

;}
RECOMP_FUNC void func_80521BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521BB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80521BB8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80521BBC: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(312, 0X1E0) << 16);
    // 0x80521BC0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80521BC4: addiu       $t6, $t6, 0x1D80
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(312, 0X1E0));
    // 0x80521BC8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80521BCC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80521BD0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80521BD4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80521BD8: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x80521BDC: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x80521BE0: jal         0x80521D2C
    // 0x80521BE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80521D2C(rdram, ctx);
        goto after_0;
    // 0x80521BE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80521BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80521BEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80521BF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80521BF4: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x80521BF8: jr          $ra
    // 0x80521BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80521BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805A2658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A2658: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805A265C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A2660: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A2664: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A2668: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A266C: jal         0x8004700C
    // 0x805A2670: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805A2670: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x805A2674: beq         $v0, $zero, L_805A276C
    if (ctx->r2 == 0) {
        // 0x805A2678: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_805A276C;
    }
    // 0x805A2678: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805A267C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805A2680: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805A2684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A2688: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x805A268C: jal         0x80048F84
    // 0x805A2690: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x805A2690: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x805A2694: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805A2698: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A269C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805A26A0: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x805A26A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x805A26A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805A26AC: nop

    // 0x805A26B0: bc1fl       L_805A2730
    if (!c1cs) {
        // 0x805A26B4: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_805A2730;
    }
    goto skip_0;
    // 0x805A26B4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_0:
    // 0x805A26B8: lwc1        $f4, 0x2C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x805A26BC: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805A26C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A26C4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805A26C8: nop

    // 0x805A26CC: bc1fl       L_805A2730
    if (!c1cs) {
        // 0x805A26D0: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_805A2730;
    }
    goto skip_1;
    // 0x805A26D0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_1:
    // 0x805A26D4: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x805A26D8: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x805A26DC: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x805A26E0: lwc1        $f8, 0x2C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x805A26E4: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x805A26E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805A26EC: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x805A26F0: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
    // 0x805A26F4: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805A26F8: lwc1        $f10, 0x84($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X84);
    // 0x805A26FC: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805A2700: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805A2704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A2708: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x805A270C: nop

    // 0x805A2710: bc1f        L_805A271C
    if (!c1cs) {
        // 0x805A2714: nop
    
            goto L_805A271C;
    }
    // 0x805A2714: nop

    // 0x805A2718: sw          $t7, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r15;
L_805A271C:
    // 0x805A271C: jal         0x805A2B28
    // 0x805A2720: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_2;
    // 0x805A2720: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x805A2724: b           L_805A2770
    // 0x805A2728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A2770;
    // 0x805A2728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A272C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
L_805A2730:
    // 0x805A2730: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(411, 0X1DEC) << 16);
    // 0x805A2734: bc1f        L_805A2764
    if (!c1cs) {
        // 0x805A2738: nop
    
            goto L_805A2764;
    }
    // 0x805A2738: nop

    // 0x805A273C: lwc1        $f0, 0x315C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(411, 0X1DEC));
    // 0x805A2740: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x805A2744: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A2748: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A274C: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x805A2750: nop

    // 0x805A2754: bc1t        L_805A2764
    if (c1cs) {
        // 0x805A2758: nop
    
            goto L_805A2764;
    }
    // 0x805A2758: nop

    // 0x805A275C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x805A2760: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
L_805A2764:
    // 0x805A2764: jal         0x805A1BA8
    // 0x805A2768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1BA8(rdram, ctx);
        goto after_3;
    // 0x805A2768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_805A276C:
    // 0x805A276C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A2770:
    // 0x805A2770: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A2774: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805A2778: jr          $ra
    // 0x805A277C: nop

    return;
    // 0x805A277C: nop

;}
RECOMP_FUNC void func_8002C724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C72C: jal         0x8002C684
    // 0x8002C730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002C684(rdram, ctx);
        goto after_0;
    // 0x8002C730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002C734: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8002C738: sw          $zero, 0x138($t6)
    MEM_W(0X138, ctx->r14) = 0;
    // 0x8002C73C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C744: jr          $ra
    // 0x8002C748: nop

    return;
    // 0x8002C748: nop

;}
