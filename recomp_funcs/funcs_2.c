#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80703F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80703F90: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80703F94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80703F98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80703F9C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80703FA0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80703FA4: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x80703FA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80703FAC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80703FB0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80703FB4: jal         0x80062AEC
    // 0x80703FB8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x80703FB8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80703FBC: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(709, 0X3770) << 16);
    // 0x80703FC0: addiu       $t6, $t6, 0x6BE0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(709, 0X3770));
    // 0x80703FC4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80703FC8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80703FCC: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80703FD0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80703FD4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80703FD8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80703FDC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80703FE0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80703FE4: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80703FE8: lhu         $t9, 0xC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XC);
    // 0x80703FEC: addiu       $t1, $t9, -0x4605
    ctx->r9 = ADD32(ctx->r25, -0X4605);
    // 0x80703FF0: sltiu       $at, $t1, 0x1B
    ctx->r1 = ctx->r9 < 0X1B ? 1 : 0;
    // 0x80703FF4: beq         $at, $zero, L_807041CC
    if (ctx->r1 == 0) {
        // 0x80703FF8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_807041CC;
    }
    // 0x80703FF8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80703FFC: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X3820) << 16);
    // 0x80704000: addu        $at, $at, $t1
    gpr jr_addend_80704008 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80704004: lw          $t1, 0x6C90($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(709, 0X3820));
    // 0x80704008: jr          $t1
    // 0x8070400C: nop

    switch (jr_addend_80704008 >> 2) {
        case 0: goto L_80704010; break;
        case 1: goto L_80704010; break;
        case 2: goto L_80704010; break;
        case 3: goto L_807041CC; break;
        case 4: goto L_807041CC; break;
        case 5: goto L_807041CC; break;
        case 6: goto L_807041CC; break;
        case 7: goto L_807041CC; break;
        case 8: goto L_807041CC; break;
        case 9: goto L_807041CC; break;
        case 10: goto L_807041CC; break;
        case 11: goto L_807041CC; break;
        case 12: goto L_807041CC; break;
        case 13: goto L_807041CC; break;
        case 14: goto L_807041CC; break;
        case 15: goto L_807041CC; break;
        case 16: goto L_807041CC; break;
        case 17: goto L_807041CC; break;
        case 18: goto L_807041CC; break;
        case 19: goto L_807041CC; break;
        case 20: goto L_807041CC; break;
        case 21: goto L_807041CC; break;
        case 22: goto L_807041CC; break;
        case 23: goto L_807041CC; break;
        case 24: goto L_807041CC; break;
        case 25: goto L_807040F4; break;
        case 26: goto L_80704010; break;
        default: switch_error(__func__, 0x80704008, 0x80706C90);
    }
    // 0x8070400C: nop

L_80704010:
    // 0x80704010: lbu         $t2, 0x30($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X30);
    // 0x80704014: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80704018: beql        $t2, $at, L_807041D0
    if (ctx->r10 == ctx->r1) {
        // 0x8070401C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807041D0;
    }
    goto skip_0;
    // 0x8070401C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80704020: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80704024: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80704028: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8070402C: lhu         $t4, 0xC($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XC);
    // 0x80704030: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80704034: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80704038: bne         $t4, $at, L_807040E4
    if (ctx->r12 != ctx->r1) {
        // 0x8070403C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_807040E4;
    }
    // 0x8070403C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80704040: bne         $v0, $at, L_807041CC
    if (ctx->r2 != ctx->r1) {
        // 0x80704044: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807041CC;
    }
    // 0x80704044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80704048: jal         0x8005FD1C
    // 0x8070404C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    func_8005FD1C(rdram, ctx);
        goto after_1;
    // 0x8070404C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80704050: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x80704054: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80704058: lui         $a1, 0xC020
    ctx->r5 = S32(0XC020 << 16);
    // 0x8070405C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80704060: jal         0x8002FABC
    // 0x80704064: sh          $zero, 0x12($t6)
    MEM_H(0X12, ctx->r14) = 0;
    func_8002FABC(rdram, ctx);
        goto after_2;
    // 0x80704064: sh          $zero, 0x12($t6)
    MEM_H(0X12, ctx->r14) = 0;
    after_2:
    // 0x80704068: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8070406C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80704070: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80704074: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x80704078: sw          $t7, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r15;
    // 0x8070407C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80704080: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80704084: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x80704088: sw          $zero, 0x20($t0)
    MEM_W(0X20, ctx->r8) = 0;
    // 0x8070408C: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
    // 0x80704090: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80704094: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80704098: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8070409C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807040A0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x807040A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807040A8: bc1t        L_807040BC
    if (c1cs) {
        // 0x807040AC: nop
    
            goto L_807040BC;
    }
    // 0x807040AC: nop

    // 0x807040B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807040B4: nop

    // 0x807040B8: swc1        $f8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f8.u32l;
L_807040BC:
    // 0x807040BC: jal         0x80705A5C
    // 0x807040C0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_80705A5C(rdram, ctx);
        goto after_3;
    // 0x807040C0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_3:
    // 0x807040C4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x807040C8: jal         0x80067BBC
    // 0x807040CC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x807040CC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x807040D0: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    // 0x807040D4: jal         0x80067818
    // 0x807040D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x807040D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x807040DC: b           L_807041D0
    // 0x807040E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807041D0;
    // 0x807040E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807040E4:
    // 0x807040E4: jal         0x8002F6E4
    // 0x807040E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_6;
    // 0x807040E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x807040EC: b           L_807041D0
    // 0x807040F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807041D0;
    // 0x807040F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807040F4:
    // 0x807040F4: lbu         $t8, 0x18($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X18);
    // 0x807040F8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x807040FC: bnel        $t8, $at, L_807041D0
    if (ctx->r24 != ctx->r1) {
        // 0x80704100: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807041D0;
    }
    goto skip_1;
    // 0x80704100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80704104: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
    // 0x80704108: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8070410C: beql        $t9, $at, L_807041D0
    if (ctx->r25 == ctx->r1) {
        // 0x80704110: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807041D0;
    }
    goto skip_2;
    // 0x80704110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80704114: lwc1        $f10, 0x3C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80704118: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8070411C: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x80704120: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80704124: lwc1        $f16, 0x40($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X40);
    // 0x80704128: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8070412C: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x80704130: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80704134: lwc1        $f18, 0x44($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X44);
    // 0x80704138: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8070413C: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80704140: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x80704144: lw          $t9, 0x18($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X18);
    // 0x80704148: jalr        $t9
    // 0x8070414C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8070414C: nop

    after_7:
    // 0x80704150: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80704154: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80704158: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8070415C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80704160: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80704164: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x80704168: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8070416C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80704170: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x80704174: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    // 0x80704178: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X3738) << 16);
    // 0x8070417C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80704180: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80704184: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80704188: lwc1        $f8, 0x6BA8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X3738));
    // 0x8070418C: jal         0x8005FD1C
    // 0x80704190: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    func_8005FD1C(rdram, ctx);
        goto after_8;
    // 0x80704190: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    after_8:
    // 0x80704194: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x80704198: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8070419C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x807041A0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x807041A4: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x807041A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807041AC: sh          $zero, 0x12($t6)
    MEM_H(0X12, ctx->r14) = 0;
    // 0x807041B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807041B4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x807041B8: sw          $t7, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r15;
    // 0x807041BC: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
    // 0x807041C0: sw          $t8, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r24;
    // 0x807041C4: jal         0x80705A5C
    // 0x807041C8: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
    func_80705A5C(rdram, ctx);
        goto after_9;
    // 0x807041C8: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
    after_9:
L_807041CC:
    // 0x807041CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807041D0:
    // 0x807041D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807041D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x807041D8: jr          $ra
    // 0x807041DC: nop

    return;
    // 0x807041DC: nop

;}
RECOMP_FUNC void func_8079918C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079918C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80799190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799194: jal         0x80799038
    // 0x80799198: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80799038(rdram, ctx);
        goto after_0;
    // 0x80799198: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079919C: bne         $v0, $zero, L_807991AC
    if (ctx->r2 != 0) {
        // 0x807991A0: nop
    
            goto L_807991AC;
    }
    // 0x807991A0: nop

    // 0x807991A4: b           L_807991C8
    // 0x807991A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807991C8;
    // 0x807991A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807991AC:
    // 0x807991AC: jal         0x807990EC
    // 0x807991B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_807990EC(rdram, ctx);
        goto after_1;
    // 0x807991B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807991B4: bnel        $v0, $zero, L_807991C8
    if (ctx->r2 != 0) {
        // 0x807991B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_807991C8;
    }
    goto skip_0;
    // 0x807991B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x807991BC: b           L_807991C8
    // 0x807991C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807991C8;
    // 0x807991C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807991C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807991C8:
    // 0x807991C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807991CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807991D0: jr          $ra
    // 0x807991D4: nop

    return;
    // 0x807991D4: nop

;}
RECOMP_FUNC void func_8044B6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B6B4: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8044B6B8: lbu         $v1, -0x71F4($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X71F4);
    // 0x8044B6BC: bltz        $v1, L_8044B6CC
    if (SIGNED(ctx->r3) < 0) {
        // 0x8044B6C0: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_8044B6CC;
    }
    // 0x8044B6C0: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8044B6C4: bne         $at, $zero, L_8044B6D0
    if (ctx->r1 != 0) {
        // 0x8044B6C8: nop
    
            goto L_8044B6D0;
    }
    // 0x8044B6C8: nop

L_8044B6CC:
    // 0x8044B6CC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8044B6D0:
    // 0x8044B6D0: jr          $ra
    // 0x8044B6D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8044B6D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80451A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80451A00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80451A04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80451A08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80451A0C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80451A10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80451A14: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80451A18: jal         0x8045111C
    // 0x80451A1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8045111C(rdram, ctx);
        goto after_0;
    // 0x80451A1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80451A20: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80451A24: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451A28: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80451A2C: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x80451A30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80451A34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80451A38: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80451A3C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80451A40: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451A44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80451A48: ori         $at, $at, 0x6E70
    ctx->r1 = ctx->r1 | 0X6E70;
    // 0x80451A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80451A50: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80451A54: lw          $t6, -0x71A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71A8);
    // 0x80451A58: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80451A5C: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80451A60: bne         $t8, $zero, L_80451A84
    if (ctx->r24 != 0) {
        // 0x80451A64: nop
    
            goto L_80451A84;
    }
    // 0x80451A64: nop

    // 0x80451A68: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451A6C: ori         $at, $at, 0x6E70
    ctx->r1 = ctx->r1 | 0X6E70;
    // 0x80451A70: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    // 0x80451A74: jal         0x804518A0
    // 0x80451A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804518A0(rdram, ctx);
        goto after_1;
    // 0x80451A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80451A7C: b           L_80451A8C
    // 0x80451A80: nop

        goto L_80451A8C;
    // 0x80451A80: nop

L_80451A84:
    // 0x80451A84: jal         0x80451704
    // 0x80451A88: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    func_80451704(rdram, ctx);
        goto after_2;
    // 0x80451A88: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    after_2:
L_80451A8C:
    // 0x80451A8C: jal         0x804507C4
    // 0x80451A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804507C4(rdram, ctx);
        goto after_3;
    // 0x80451A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80451A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80451A98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80451A9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80451AA0: jr          $ra
    // 0x80451AA4: nop

    return;
    // 0x80451AA4: nop

;}
RECOMP_FUNC void func_80038558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003855C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038560: jal         0x80021958
    // 0x80038564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80038564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038568: bne         $v0, $zero, L_80038578
    if (ctx->r2 != 0) {
        // 0x8003856C: nop
    
            goto L_80038578;
    }
    // 0x8003856C: nop

    // 0x80038570: b           L_800385AC
    // 0x80038574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800385AC;
    // 0x80038574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038578:
    // 0x80038578: jal         0x800415FC
    // 0x8003857C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x8003857C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80038580: beq         $v0, $zero, L_80038590
    if (ctx->r2 == 0) {
        // 0x80038584: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80038590;
    }
    // 0x80038584: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038588: b           L_800385AC
    // 0x8003858C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800385AC;
    // 0x8003858C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038590:
    // 0x80038590: jal         0x8003790C
    // 0x80038594: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_8003790C(rdram, ctx);
        goto after_2;
    // 0x80038594: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_2:
    // 0x80038598: bnel        $v0, $zero, L_800385AC
    if (ctx->r2 != 0) {
        // 0x8003859C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800385AC;
    }
    goto skip_0;
    // 0x8003859C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800385A0: b           L_800385AC
    // 0x800385A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800385AC;
    // 0x800385A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800385A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800385AC:
    // 0x800385AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800385B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800385B4: jr          $ra
    // 0x800385B8: nop

    return;
    // 0x800385B8: nop

;}
RECOMP_FUNC void func_804D1374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D1374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D1378: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x804D137C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804D1380: addiu       $v1, $sp, 0x8
    ctx->r3 = ADD32(ctx->r29, 0X8);
    // 0x804D1384: addiu       $v0, $sp, 0x14
    ctx->r2 = ADD32(ctx->r29, 0X14);
    // 0x804D1388: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804D138C: lwc1        $f16, 0x6C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x804D1390: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804D1394: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x804D1398: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x804D139C: beql        $at, $zero, L_804D13C4
    if (ctx->r1 == 0) {
        // 0x804D13A0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_804D13C4;
    }
    goto skip_0;
    // 0x804D13A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    skip_0:
L_804D13A4:
    // 0x804D13A4: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x804D13A8: lwc1        $f16, 0x70($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X70);
    // 0x804D13AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804D13B0: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x804D13B4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x804D13B8: bne         $at, $zero, L_804D13A4
    if (ctx->r1 != 0) {
        // 0x804D13BC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_804D13A4;
    }
    // 0x804D13BC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804D13C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_804D13C4:
    // 0x804D13C4: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x804D13C8: addiu       $v1, $sp, 0x8
    ctx->r3 = ADD32(ctx->r29, 0X8);
    // 0x804D13CC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804D13D0: addiu       $v0, $sp, 0x14
    ctx->r2 = ADD32(ctx->r29, 0X14);
    // 0x804D13D4: lwc1        $f12, 0xC4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x804D13D8: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804D13DC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804D13E0: lwc1        $f16, 0x3C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x804D13E4: mul.s       $f18, $f12, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x804D13E8: beql        $v1, $v0, L_804D141C
    if (ctx->r3 == ctx->r2) {
        // 0x804D13EC: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_804D141C;
    }
    goto skip_1;
    // 0x804D13EC: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x804D13F0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_804D13F4:
    // 0x804D13F4: lwc1        $f12, 0xC8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC8);
    // 0x804D13F8: lwc1        $f16, 0x40($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X40);
    // 0x804D13FC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804D1400: swc1        $f14, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f14.u32l;
    // 0x804D1404: lwc1        $f14, -0x4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, -0X4);
    // 0x804D1408: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804D140C: mul.s       $f18, $f12, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x804D1410: bnel        $v1, $v0, L_804D13F4
    if (ctx->r3 != ctx->r2) {
        // 0x804D1414: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_804D13F4;
    }
    goto skip_2;
    // 0x804D1414: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_2:
    // 0x804D1418: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_804D141C:
    // 0x804D141C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804D1420: swc1        $f14, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f14.u32l;
    // 0x804D1424: jr          $ra
    // 0x804D1428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804D1428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80066E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066E88: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80066E8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066E90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066E94: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80066E98: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80066E9C: bc1fl       L_80066EC4
    if (!c1cs) {
        // 0x80066EA0: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80066EC4;
    }
    goto skip_0;
    // 0x80066EA0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x80066EA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066EA8: nop

    // 0x80066EAC: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_80066EB0:
    // 0x80066EB0: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80066EB4: nop

    // 0x80066EB8: bc1tl       L_80066EB0
    if (c1cs) {
        // 0x80066EBC: add.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_80066EB0;
    }
    goto skip_1;
    // 0x80066EBC: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    skip_1:
    // 0x80066EC0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80066EC4:
    // 0x80066EC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066EC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80066ECC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80066ED0: nop

    // 0x80066ED4: bc1f        L_80066EF0
    if (!c1cs) {
        // 0x80066ED8: nop
    
            goto L_80066EF0;
    }
    // 0x80066ED8: nop

    // 0x80066EDC: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
L_80066EE0:
    // 0x80066EE0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80066EE4: nop

    // 0x80066EE8: bc1tl       L_80066EE0
    if (c1cs) {
        // 0x80066EEC: sub.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_80066EE0;
    }
    goto skip_2;
    // 0x80066EEC: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    skip_2:
L_80066EF0:
    // 0x80066EF0: lwc1        $f4, 0xF0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XF0C);
    // 0x80066EF4: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80066EF8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80066EFC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80066F00: jal         0x8008D3C0
    // 0x80066F04: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    coss(rdram, ctx);
        goto after_0;
    // 0x80066F04: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80066F08: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80066F0C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80066F10: lwc1        $f18, 0xF10($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XF10);
    // 0x80066F14: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80066F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066F20: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80066F24: jr          $ra
    // 0x80066F28: nop

    return;
    // 0x80066F28: nop

;}
RECOMP_FUNC void func_8069D320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D328: jal         0x8069D170
    // 0x8069D32C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8069D170(rdram, ctx);
        goto after_0;
    // 0x8069D32C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069D330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069D334: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8069D338: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(571, 0X748) << 16);
    // 0x8069D33C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069D340: addiu       $t6, $t6, -0x2BC8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(571, 0X748));
    // 0x8069D344: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(571, 0X778) << 16);
    // 0x8069D348: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8069D34C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8069D350: lwc1        $f6, -0x2B98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(571, 0X778));
    // 0x8069D354: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(571, 0X36C) << 16);
    // 0x8069D358: addiu       $t7, $t7, -0x2FA4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(571, 0X36C));
    // 0x8069D35C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8069D360: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8069D364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D36C: jr          $ra
    // 0x8069D370: nop

    return;
    // 0x8069D370: nop

;}
RECOMP_FUNC void func_805A82D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A82D8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x805A82DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805A82E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805A82E4: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805A82E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A82EC: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x805A82F0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x805A82F4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x805A82F8: nop

    // 0x805A82FC: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x805A8300: lw          $t8, 0x168($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X168);
    // 0x805A8304: lw          $t9, 0x88($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X88);
    // 0x805A8308: jal         0x80045A34
    // 0x805A830C: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805A830C: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    after_0:
    // 0x805A8310: bne         $v0, $zero, L_805A8328
    if (ctx->r2 != 0) {
        // 0x805A8314: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_805A8328;
    }
    // 0x805A8314: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x805A8318: jal         0x800445A4
    // 0x805A831C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805A831C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A8320: b           L_805A8728
    // 0x805A8324: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_805A8728;
    // 0x805A8324: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805A8328:
    // 0x805A8328: lw          $t2, 0x16C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X16C);
    // 0x805A832C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805A8330: lui         $t1, 0x805B
    ctx->r9 = S32(RELOC_HI16(426, 0X16E8) << 16);
    // 0x805A8334: sb          $t0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r8;
    // 0x805A8338: addiu       $t1, $t1, -0x75C8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(426, 0X16E8));
    // 0x805A833C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x805A8340: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x805A8344: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x805A8348: addiu       $t4, $t4, -0x7C48
    ctx->r12 = ADD32(ctx->r12, -0X7C48);
    // 0x805A834C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805A8350: sw          $t3, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r11;
    // 0x805A8354: sw          $t4, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r12;
    // 0x805A8358: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x805A835C: jal         0x80067BBC
    // 0x805A8360: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x805A8360: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x805A8364: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x805A8368: jal         0x80067F78
    // 0x805A836C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_3;
    // 0x805A836C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x805A8370: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x805A8374: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805A8378: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x805A837C: lui         $t5, 0x805A
    ctx->r13 = S32(RELOC_HI16(426, 0X290) << 16);
    // 0x805A8380: addiu       $t5, $t5, 0x75E0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(426, 0X290));
    // 0x805A8384: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x805A8388: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x805A838C: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x805A8390: swc1        $f8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
    // 0x805A8394: sw          $t5, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r13;
    // 0x805A8398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A839C: jal         0x805A757C
    // 0x805A83A0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    func_805A757C(rdram, ctx);
        goto after_4;
    // 0x805A83A0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_4:
    // 0x805A83A4: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(426, 0XC4) << 16);
    // 0x805A83A8: addiu       $t6, $t6, 0x7414
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(426, 0XC4));
    // 0x805A83AC: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x805A83B0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x805A83B4: jal         0x80058958
    // 0x805A83B8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    func_80058958(rdram, ctx);
        goto after_5;
    // 0x805A83B8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    after_5:
    // 0x805A83BC: beq         $v0, $zero, L_805A8434
    if (ctx->r2 == 0) {
        // 0x805A83C0: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_805A8434;
    }
    // 0x805A83C0: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x805A83C4: lw          $t8, -0x7BC4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7BC4);
    // 0x805A83C8: lw          $t9, 0x10C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10C);
    // 0x805A83CC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x805A83D0: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x805A83D4: beql        $t1, $zero, L_805A8438
    if (ctx->r9 == 0) {
        // 0x805A83D8: lw          $v0, 0x58($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X58);
            goto L_805A8438;
    }
    goto skip_0;
    // 0x805A83D8: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    skip_0:
    // 0x805A83DC: jal         0x80056564
    // 0x805A83E0: nop

    func_80056564(rdram, ctx);
        goto after_6;
    // 0x805A83E0: nop

    after_6:
    // 0x805A83E4: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x805A83E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A83EC: beq         $v0, $zero, L_805A8434
    if (ctx->r2 == 0) {
        // 0x805A83F0: sw          $v0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r2;
            goto L_805A8434;
    }
    // 0x805A83F0: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x805A83F4: jal         0x800457A0
    // 0x805A83F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_7;
    // 0x805A83F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x805A83FC: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x805A8400: addiu       $t4, $zero, 0x29
    ctx->r12 = ADD32(0, 0X29);
    // 0x805A8404: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805A8408: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x805A840C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x805A8410: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x805A8414: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805A8418: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805A841C: jal         0x80056584
    // 0x805A8420: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80056584(rdram, ctx);
        goto after_8;
    // 0x805A8420: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_8:
    // 0x805A8424: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x805A8428: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x805A842C: addiu       $t6, $t6, 0x784C
    ctx->r14 = ADD32(ctx->r14, 0X784C);
    // 0x805A8430: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
L_805A8434:
    // 0x805A8434: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
L_805A8438:
    // 0x805A8438: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805A843C: sra         $v0, $v0, 4
    ctx->r2 = S32(SIGNED(ctx->r2) >> 4);
    // 0x805A8440: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x805A8444: beql        $v0, $zero, L_805A8508
    if (ctx->r2 == 0) {
        // 0x805A8448: lw          $t9, 0x174($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X174);
            goto L_805A8508;
    }
    goto skip_1;
    // 0x805A8448: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    skip_1:
    // 0x805A844C: beq         $v0, $at, L_805A8474
    if (ctx->r2 == ctx->r1) {
        // 0x805A8450: lw          $a1, 0x54($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X54);
            goto L_805A8474;
    }
    // 0x805A8450: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x805A8454: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805A8458: beq         $v0, $at, L_805A84A4
    if (ctx->r2 == ctx->r1) {
        // 0x805A845C: lw          $a1, 0x54($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X54);
            goto L_805A84A4;
    }
    // 0x805A845C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x805A8460: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805A8464: beq         $v0, $at, L_805A84D4
    if (ctx->r2 == ctx->r1) {
        // 0x805A8468: lw          $a1, 0x54($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X54);
            goto L_805A84D4;
    }
    // 0x805A8468: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x805A846C: b           L_805A8528
    // 0x805A8470: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
        goto L_805A8528;
    // 0x805A8470: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_805A8474:
    // 0x805A8474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A8478: jal         0x8004590C
    // 0x805A847C: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    func_8004590C(rdram, ctx);
        goto after_9;
    // 0x805A847C: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    after_9:
    // 0x805A8480: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x805A8484: addiu       $t8, $zero, 0x2242
    ctx->r24 = ADD32(0, 0X2242);
    // 0x805A8488: addiu       $t1, $zero, 0x2244
    ctx->r9 = ADD32(0, 0X2244);
    // 0x805A848C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805A8490: sh          $t8, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r24;
    // 0x805A8494: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x805A8498: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x805A849C: b           L_805A8524
    // 0x805A84A0: sh          $t1, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r9;
        goto L_805A8524;
    // 0x805A84A0: sh          $t1, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r9;
L_805A84A4:
    // 0x805A84A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A84A8: jal         0x8004590C
    // 0x805A84AC: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    func_8004590C(rdram, ctx);
        goto after_10;
    // 0x805A84AC: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    after_10:
    // 0x805A84B0: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x805A84B4: addiu       $t4, $zero, 0x4222
    ctx->r12 = ADD32(0, 0X4222);
    // 0x805A84B8: addiu       $t7, $zero, 0x2244
    ctx->r15 = ADD32(0, 0X2244);
    // 0x805A84BC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x805A84C0: sh          $t4, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r12;
    // 0x805A84C4: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x805A84C8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x805A84CC: b           L_805A8524
    // 0x805A84D0: sh          $t7, 0x1A($t8)
    MEM_H(0X1A, ctx->r24) = ctx->r15;
        goto L_805A8524;
    // 0x805A84D0: sh          $t7, 0x1A($t8)
    MEM_H(0X1A, ctx->r24) = ctx->r15;
L_805A84D4:
    // 0x805A84D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A84D8: jal         0x8004590C
    // 0x805A84DC: addiu       $a1, $a1, 0x600
    ctx->r5 = ADD32(ctx->r5, 0X600);
    func_8004590C(rdram, ctx);
        goto after_11;
    // 0x805A84DC: addiu       $a1, $a1, 0x600
    ctx->r5 = ADD32(ctx->r5, 0X600);
    after_11:
    // 0x805A84E0: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x805A84E4: addiu       $t0, $zero, 0x2224
    ctx->r8 = ADD32(0, 0X2224);
    // 0x805A84E8: addiu       $t3, $zero, 0x4244
    ctx->r11 = ADD32(0, 0X4244);
    // 0x805A84EC: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x805A84F0: sh          $t0, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r8;
    // 0x805A84F4: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x805A84F8: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x805A84FC: b           L_805A8524
    // 0x805A8500: sh          $t3, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r11;
        goto L_805A8524;
    // 0x805A8500: sh          $t3, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r11;
    // 0x805A8504: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
L_805A8508:
    // 0x805A8508: addiu       $t6, $zero, 0x2422
    ctx->r14 = ADD32(0, 0X2422);
    // 0x805A850C: addiu       $t8, $zero, 0x2444
    ctx->r24 = ADD32(0, 0X2444);
    // 0x805A8510: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x805A8514: sh          $t6, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r14;
    // 0x805A8518: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x805A851C: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x805A8520: sh          $t8, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r24;
L_805A8524:
    // 0x805A8524: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_805A8528:
    // 0x805A8528: slti        $at, $v0, 0x45B5
    ctx->r1 = SIGNED(ctx->r2) < 0X45B5 ? 1 : 0;
    // 0x805A852C: bne         $at, $zero, L_805A8544
    if (ctx->r1 != 0) {
        // 0x805A8530: addiu       $at, $zero, 0x4697
        ctx->r1 = ADD32(0, 0X4697);
            goto L_805A8544;
    }
    // 0x805A8530: addiu       $at, $zero, 0x4697
    ctx->r1 = ADD32(0, 0X4697);
    // 0x805A8534: beq         $v0, $at, L_805A85D4
    if (ctx->r2 == ctx->r1) {
        // 0x805A8538: lui         $t0, 0x805B
        ctx->r8 = S32(RELOC_HI16(426, 0X16F8) << 16);
            goto L_805A85D4;
    }
    // 0x805A8538: lui         $t0, 0x805B
    ctx->r8 = S32(RELOC_HI16(426, 0X16F8) << 16);
    // 0x805A853C: b           L_805A8604
    // 0x805A8540: lhu         $t1, 0x38($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X38);
        goto L_805A8604;
    // 0x805A8540: lhu         $t1, 0x38($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X38);
L_805A8544:
    // 0x805A8544: slti        $at, $v0, 0x418E
    ctx->r1 = SIGNED(ctx->r2) < 0X418E ? 1 : 0;
    // 0x805A8548: bne         $at, $zero, L_805A8564
    if (ctx->r1 != 0) {
        // 0x805A854C: addiu       $t1, $v0, -0x4188
        ctx->r9 = ADD32(ctx->r2, -0X4188);
            goto L_805A8564;
    }
    // 0x805A854C: addiu       $t1, $v0, -0x4188
    ctx->r9 = ADD32(ctx->r2, -0X4188);
    // 0x805A8550: addiu       $at, $zero, 0x45B4
    ctx->r1 = ADD32(0, 0X45B4);
    // 0x805A8554: beq         $v0, $at, L_805A85CC
    if (ctx->r2 == ctx->r1) {
        // 0x805A8558: addiu       $t2, $zero, 0x45B6
        ctx->r10 = ADD32(0, 0X45B6);
            goto L_805A85CC;
    }
    // 0x805A8558: addiu       $t2, $zero, 0x45B6
    ctx->r10 = ADD32(0, 0X45B6);
    // 0x805A855C: b           L_805A8604
    // 0x805A8560: lhu         $t1, 0x38($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X38);
        goto L_805A8604;
    // 0x805A8560: lhu         $t1, 0x38($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X38);
L_805A8564:
    // 0x805A8564: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x805A8568: beq         $at, $zero, L_805A8600
    if (ctx->r1 == 0) {
        // 0x805A856C: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_805A8600;
    }
    // 0x805A856C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x805A8570: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(426, 0X1790) << 16);
    // 0x805A8574: addu        $at, $at, $t1
    gpr jr_addend_805A857C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x805A8578: lw          $t1, -0x7520($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(426, 0X1790));
    // 0x805A857C: jr          $t1
    // 0x805A8580: nop

    switch (jr_addend_805A857C >> 2) {
        case 0: goto L_805A8584; break;
        case 1: goto L_805A8590; break;
        case 2: goto L_805A859C; break;
        case 3: goto L_805A85A8; break;
        case 4: goto L_805A85B4; break;
        case 5: goto L_805A85C0; break;
        default: switch_error(__func__, 0x805A857C, 0x805A8AE0);
    }
    // 0x805A8580: nop

L_805A8584:
    // 0x805A8584: addiu       $t5, $zero, 0x4030
    ctx->r13 = ADD32(0, 0X4030);
    // 0x805A8588: b           L_805A8600
    // 0x805A858C: sh          $t5, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r13;
        goto L_805A8600;
    // 0x805A858C: sh          $t5, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r13;
L_805A8590:
    // 0x805A8590: addiu       $t3, $zero, 0x4031
    ctx->r11 = ADD32(0, 0X4031);
    // 0x805A8594: b           L_805A8600
    // 0x805A8598: sh          $t3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r11;
        goto L_805A8600;
    // 0x805A8598: sh          $t3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r11;
L_805A859C:
    // 0x805A859C: addiu       $t4, $zero, 0x4032
    ctx->r12 = ADD32(0, 0X4032);
    // 0x805A85A0: b           L_805A8600
    // 0x805A85A4: sh          $t4, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r12;
        goto L_805A8600;
    // 0x805A85A4: sh          $t4, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r12;
L_805A85A8:
    // 0x805A85A8: addiu       $t9, $zero, 0x4033
    ctx->r25 = ADD32(0, 0X4033);
    // 0x805A85AC: b           L_805A8600
    // 0x805A85B0: sh          $t9, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r25;
        goto L_805A8600;
    // 0x805A85B0: sh          $t9, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r25;
L_805A85B4:
    // 0x805A85B4: addiu       $t6, $zero, 0x4034
    ctx->r14 = ADD32(0, 0X4034);
    // 0x805A85B8: b           L_805A8600
    // 0x805A85BC: sh          $t6, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r14;
        goto L_805A8600;
    // 0x805A85BC: sh          $t6, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r14;
L_805A85C0:
    // 0x805A85C0: addiu       $t7, $zero, 0x4035
    ctx->r15 = ADD32(0, 0X4035);
    // 0x805A85C4: b           L_805A8600
    // 0x805A85C8: sh          $t7, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r15;
        goto L_805A8600;
    // 0x805A85C8: sh          $t7, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r15;
L_805A85CC:
    // 0x805A85CC: b           L_805A8600
    // 0x805A85D0: sh          $t2, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r10;
        goto L_805A8600;
    // 0x805A85D0: sh          $t2, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r10;
L_805A85D4:
    // 0x805A85D4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x805A85D8: lw          $v0, -0x76C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X76C0);
    // 0x805A85DC: bltz        $v0, L_805A85EC
    if (SIGNED(ctx->r2) < 0) {
        // 0x805A85E0: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_805A85EC;
    }
    // 0x805A85E0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x805A85E4: bnel        $at, $zero, L_805A85F4
    if (ctx->r1 != 0) {
        // 0x805A85E8: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_805A85F4;
    }
    goto skip_2;
    // 0x805A85E8: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    skip_2:
L_805A85EC:
    // 0x805A85EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x805A85F0: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
L_805A85F4:
    // 0x805A85F4: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x805A85F8: lhu         $t0, -0x75B8($t0)
    ctx->r8 = MEM_HU(ctx->r8, (int16_t)RELOC_LO16(426, 0X16F8));
    // 0x805A85FC: sh          $t0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r8;
L_805A8600:
    // 0x805A8600: lhu         $t1, 0x38($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X38);
L_805A8604:
    // 0x805A8604: addiu       $at, $zero, 0x45B6
    ctx->r1 = ADD32(0, 0X45B6);
    // 0x805A8608: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x805A860C: beq         $t1, $at, L_805A8680
    if (ctx->r9 == ctx->r1) {
        // 0x805A8610: lui         $t3, 0x8010
        ctx->r11 = S32(0X8010 << 16);
            goto L_805A8680;
    }
    // 0x805A8610: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x805A8614: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x805A8618: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A861C: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x805A8620: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805A8624: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A8628: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(426, 0X17A8) << 16);
    // 0x805A862C: lwc1        $f18, -0x7508($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(426, 0X17A8));
    // 0x805A8630: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x805A8634: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x805A8638: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x805A863C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x805A8640: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x805A8644: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x805A8648: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x805A864C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x805A8650: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x805A8654: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x805A8658: lw          $t9, 0x54($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X54);
    // 0x805A865C: jalr        $t9
    // 0x805A8660: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_12;
    // 0x805A8660: nop

    after_12:
    // 0x805A8664: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x805A8668: bne         $v0, $zero, L_805A86F0
    if (ctx->r2 != 0) {
        // 0x805A866C: sw          $v0, 0x4($t6)
        MEM_W(0X4, ctx->r14) = ctx->r2;
            goto L_805A86F0;
    }
    // 0x805A866C: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x805A8670: jal         0x800445A4
    // 0x805A8674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_13;
    // 0x805A8674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x805A8678: b           L_805A8728
    // 0x805A867C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_805A8728;
    // 0x805A867C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805A8680:
    // 0x805A8680: jal         0x80047090
    // 0x805A8684: addiu       $a0, $zero, 0x45B6
    ctx->r4 = ADD32(0, 0X45B6);
    func_80047090(rdram, ctx);
        goto after_14;
    // 0x805A8684: addiu       $a0, $zero, 0x45B6
    ctx->r4 = ADD32(0, 0X45B6);
    after_14:
    // 0x805A8688: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A868C: lui         $at, 0x45B6
    ctx->r1 = S32(0X45B6 << 16);
    // 0x805A8690: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x805A8694: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805A8698: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805A869C: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x805A86A0: jal         0x8004613C
    // 0x805A86A4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_15;
    // 0x805A86A4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_15:
    // 0x805A86A8: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x805A86AC: bne         $v0, $zero, L_805A86C4
    if (ctx->r2 != 0) {
        // 0x805A86B0: sw          $v0, 0x4($t7)
        MEM_W(0X4, ctx->r15) = ctx->r2;
            goto L_805A86C4;
    }
    // 0x805A86B0: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x805A86B4: jal         0x800445A4
    // 0x805A86B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_16;
    // 0x805A86B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x805A86BC: b           L_805A8728
    // 0x805A86C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_805A8728;
    // 0x805A86C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805A86C4:
    // 0x805A86C4: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x805A86C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A86CC: jal         0x80047F9C
    // 0x805A86D0: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_17;
    // 0x805A86D0: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    after_17:
    // 0x805A86D4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x805A86D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A86DC: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x805A86E0: sb          $t8, 0x165($t1)
    MEM_B(0X165, ctx->r9) = ctx->r24;
    // 0x805A86E4: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x805A86E8: jal         0x8005FDC4
    // 0x805A86EC: lw          $a0, 0x4($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X4);
    func_8005FDC4(rdram, ctx);
        goto after_18;
    // 0x805A86EC: lw          $a0, 0x4($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X4);
    after_18:
L_805A86F0:
    // 0x805A86F0: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x805A86F4: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(426, 0X17AC) << 16);
    // 0x805A86F8: lwc1        $f0, -0x7504($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(426, 0X17AC));
    // 0x805A86FC: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x805A8700: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x805A8704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A8708: sb          $t3, 0x17C($t9)
    MEM_B(0X17C, ctx->r25) = ctx->r11;
    // 0x805A870C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x805A8710: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A8714: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805A8718: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x805A871C: jal         0x805A8794
    // 0x805A8720: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    func_805A8794(rdram, ctx);
        goto after_19;
    // 0x805A8720: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    after_19:
    // 0x805A8724: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805A8728:
    // 0x805A8728: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805A872C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x805A8730: jr          $ra
    // 0x805A8734: nop

    return;
    // 0x805A8734: nop

;}
RECOMP_FUNC void func_8079D7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079D7C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8079D7CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8079D7D0: sll         $s1, $a1, 16
    ctx->r17 = S32(ctx->r5 << 16);
    // 0x8079D7D4: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8079D7D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8079D7DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8079D7E0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8079D7E4: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8079D7E8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8079D7EC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8079D7F0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8079D7F4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8079D7F8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8079D7FC: beq         $s1, $zero, L_8079D8BC
    if (ctx->r17 == 0) {
        // 0x8079D800: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_8079D8BC;
    }
    // 0x8079D800: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8079D804: addiu       $s7, $zero, 0x4001
    ctx->r23 = ADD32(0, 0X4001);
    // 0x8079D808: addiu       $s6, $zero, 0x9
    ctx->r22 = ADD32(0, 0X9);
    // 0x8079D80C: addiu       $s5, $zero, 0xB
    ctx->r21 = ADD32(0, 0XB);
    // 0x8079D810: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x8079D814: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8079D818: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8079D81C:
    // 0x8079D81C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8079D820: beq         $v1, $zero, L_8079D8B4
    if (ctx->r3 == 0) {
        // 0x8079D824: nop
    
            goto L_8079D8B4;
    }
    // 0x8079D824: nop

    // 0x8079D828: beql        $s2, $v1, L_8079D8AC
    if (ctx->r18 == ctx->r3) {
        // 0x8079D82C: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8079D8AC;
    }
    goto skip_0;
    // 0x8079D82C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x8079D830: lh          $a1, 0x184($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X184);
    // 0x8079D834: beql        $a1, $zero, L_8079D858
    if (ctx->r5 == 0) {
        // 0x8079D838: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8079D858;
    }
    goto skip_1;
    // 0x8079D838: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8079D83C: jal         0x8079D7C8
    // 0x8079D840: addiu       $a0, $v1, 0x188
    ctx->r4 = ADD32(ctx->r3, 0X188);
    func_8079D7C8(rdram, ctx);
        goto after_0;
    // 0x8079D840: addiu       $a0, $v1, 0x188
    ctx->r4 = ADD32(ctx->r3, 0X188);
    after_0:
    // 0x8079D844: beql        $v0, $zero, L_8079D858
    if (ctx->r2 == 0) {
        // 0x8079D848: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8079D858;
    }
    goto skip_2;
    // 0x8079D848: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8079D84C: b           L_8079D8C4
    // 0x8079D850: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8079D8C4;
    // 0x8079D850: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8079D854: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8079D858:
    // 0x8079D858: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x8079D85C: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x8079D860: bnel        $s3, $t7, L_8079D8AC
    if (ctx->r19 != ctx->r15) {
        // 0x8079D864: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8079D8AC;
    }
    goto skip_3;
    // 0x8079D864: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_3:
    // 0x8079D868: lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XE);
    // 0x8079D86C: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x8079D870: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8079D874: beql        $s4, $v0, L_8079D898
    if (ctx->r20 == ctx->r2) {
        // 0x8079D878: lhu         $t8, 0xC($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0XC);
            goto L_8079D898;
    }
    goto skip_4;
    // 0x8079D878: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    skip_4:
    // 0x8079D87C: beql        $s5, $v0, L_8079D898
    if (ctx->r21 == ctx->r2) {
        // 0x8079D880: lhu         $t8, 0xC($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0XC);
            goto L_8079D898;
    }
    goto skip_5;
    // 0x8079D880: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    skip_5:
    // 0x8079D884: beql        $v0, $zero, L_8079D898
    if (ctx->r2 == 0) {
        // 0x8079D888: lhu         $t8, 0xC($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0XC);
            goto L_8079D898;
    }
    goto skip_6;
    // 0x8079D888: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    skip_6:
    // 0x8079D88C: bnel        $s6, $v0, L_8079D8AC
    if (ctx->r22 != ctx->r2) {
        // 0x8079D890: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8079D8AC;
    }
    goto skip_7;
    // 0x8079D890: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_7:
    // 0x8079D894: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
L_8079D898:
    // 0x8079D898: beql        $s7, $t8, L_8079D8AC
    if (ctx->r23 == ctx->r24) {
        // 0x8079D89C: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8079D8AC;
    }
    goto skip_8;
    // 0x8079D89C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_8:
    // 0x8079D8A0: b           L_8079D8C0
    // 0x8079D8A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8079D8C0;
    // 0x8079D8A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8079D8A8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8079D8AC:
    // 0x8079D8AC: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x8079D8B0: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
L_8079D8B4:
    // 0x8079D8B4: bne         $s1, $zero, L_8079D81C
    if (ctx->r17 != 0) {
        // 0x8079D8B8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8079D81C;
    }
    // 0x8079D8B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8079D8BC:
    // 0x8079D8BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8079D8C0:
    // 0x8079D8C0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8079D8C4:
    // 0x8079D8C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8079D8C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8079D8CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8079D8D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8079D8D4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8079D8D8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8079D8DC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8079D8E0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8079D8E4: jr          $ra
    // 0x8079D8E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8079D8E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_804BA0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BA0C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804BA0CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BA0D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BA0D4: jal         0x8004700C
    // 0x804BA0D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804BA0D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804BA0DC: beq         $v0, $zero, L_804BA16C
    if (ctx->r2 == 0) {
        // 0x804BA0E0: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_804BA16C;
    }
    // 0x804BA0E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804BA0E4: jal         0x804B7E74
    // 0x804BA0E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B7E74(rdram, ctx);
        goto after_1;
    // 0x804BA0E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804BA0EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BA0F0: jal         0x80062748
    // 0x804BA0F4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062748(rdram, ctx);
        goto after_2;
    // 0x804BA0F4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_2:
    // 0x804BA0F8: jal         0x804B98E8
    // 0x804BA0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B98E8(rdram, ctx);
        goto after_3;
    // 0x804BA0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804BA100: jal         0x804B9FA4
    // 0x804BA104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B9FA4(rdram, ctx);
        goto after_4;
    // 0x804BA104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804BA108: jal         0x804B9944
    // 0x804BA10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B9944(rdram, ctx);
        goto after_5;
    // 0x804BA10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804BA110: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x804BA114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BA118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BA11C: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x804BA120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804BA124: beql        $s0, $t7, L_804BA138
    if (ctx->r16 == ctx->r15) {
        // 0x804BA128: lui         $at, 0x41C0
        ctx->r1 = S32(0X41C0 << 16);
            goto L_804BA138;
    }
    goto skip_0;
    // 0x804BA128: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    skip_0:
    // 0x804BA12C: jal         0x804BA728
    // 0x804BA130: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804BA728(rdram, ctx);
        goto after_6;
    // 0x804BA130: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_6:
    // 0x804BA134: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
L_804BA138:
    // 0x804BA138: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x804BA13C: lw          $t8, -0x7BC4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7BC4);
    // 0x804BA140: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BA144: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x804BA148: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x804BA14C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804BA150: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804BA154: lwc1        $f10, 0x3C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X3C);
    // 0x804BA158: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x804BA15C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804BA160: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x804BA164: div.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x804BA168: swc1        $f4, 0xE4($t0)
    MEM_W(0XE4, ctx->r8) = ctx->f4.u32l;
L_804BA16C:
    // 0x804BA16C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804BA170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BA174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804BA178: jr          $ra
    // 0x804BA17C: nop

    return;
    // 0x804BA17C: nop

;}
RECOMP_FUNC void func_80682D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682D74: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682D78: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682D7C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682D80: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682D84: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682D88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682D8C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682D90: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682D94: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682D98: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682D9C: jr          $ra
    // 0x80682DA0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682DA0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80067CAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067CAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067CB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067CB8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80067CBC: jal         0x80067BBC
    // 0x80067CC0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80067CC0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80067CC4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80067CC8: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067CCC: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067CD0: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x80067CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067CD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067CDC: jr          $ra
    // 0x80067CE0: nop

    return;
    // 0x80067CE0: nop

;}
RECOMP_FUNC void func_80445F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445F60: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80445F64: addiu       $v1, $zero, 0x1EF0
    ctx->r3 = ADD32(0, 0X1EF0);
    // 0x80445F68: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80445F6C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80445F70: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80445F74: sw          $zero, 0x6CA0($at)
    MEM_W(0X6CA0, ctx->r1) = 0;
    // 0x80445F78: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x80445F7C: addiu       $a2, $zero, 0x1B6C
    ctx->r6 = ADD32(0, 0X1B6C);
    // 0x80445F80: sw          $a1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r5;
    // 0x80445F84: sw          $a2, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r6;
    // 0x80445F88: sw          $a1, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r5;
    // 0x80445F8C: sw          $a2, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->r6;
    // 0x80445F90: jr          $ra
    // 0x80445F94: sw          $v1, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->r3;
    return;
    // 0x80445F94: sw          $v1, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_8042F5E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F5E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042F5E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F5E8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042F5EC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8042F5F0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042F5F4: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X3784) << 16);
    // 0x8042F5F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042F5FC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8042F600: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042F604: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042F608: lw          $t8, 0x1864($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X3784));
    // 0x8042F60C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042F610: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042F614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042F618: jal         0x80048490
    // 0x8042F61C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8042F61C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8042F620: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8042F624: jal         0x80048378
    // 0x8042F628: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8042F628: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8042F62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042F630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F634: jr          $ra
    // 0x8042F638: nop

    return;
    // 0x8042F638: nop

;}
RECOMP_FUNC void func_807AD420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD420: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x807AD424: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x807AD428: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x807AD42C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x807AD430: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x807AD434: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x807AD438: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x807AD43C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x807AD440: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x807AD444: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x807AD448: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x807AD44C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x807AD450: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807AD454: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x807AD458: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x807AD45C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x807AD460: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x807AD464: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807AD468: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807AD46C: addiu       $s2, $sp, 0x80
    ctx->r18 = ADD32(ctx->r29, 0X80);
    // 0x807AD470: addiu       $s3, $sp, 0x78
    ctx->r19 = ADD32(ctx->r29, 0X78);
    // 0x807AD474: addiu       $s4, $zero, 0x18
    ctx->r20 = ADD32(0, 0X18);
    // 0x807AD478: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_807AD47C:
    // 0x807AD47C: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    // 0x807AD480: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807AD484: mul.s       $f12, $f6, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x807AD488: jal         0x807AC6D8
    // 0x807AD48C: nop

    func_807AC6D8(rdram, ctx);
        goto after_0;
    // 0x807AD48C: nop

    after_0:
    // 0x807AD490: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x807AD494: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807AD498: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x807AD49C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807AD4A0: jal         0x807AC6D8
    // 0x807AD4A4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_807AC6D8(rdram, ctx);
        goto after_1;
    // 0x807AD4A4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x807AD4A8: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26C0) << 16);
    // 0x807AD4AC: lwc1        $f8, -0x12E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26C0));
    // 0x807AD4B0: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26C4) << 16);
    // 0x807AD4B4: lwc1        $f16, -0x12DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26C4));
    // 0x807AD4B8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x807AD4BC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x807AD4C0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x807AD4C4: mul.s       $f24, $f10, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807AD4C8: jal         0x80066DE4
    // 0x807AD4CC: nop

    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x807AD4CC: nop

    after_2:
    // 0x807AD4D0: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x807AD4D4: jal         0x80066E88
    // 0x807AD4D8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x807AD4D8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x807AD4DC: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x807AD4E0: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x807AD4E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807AD4E8: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x807AD4EC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x807AD4F0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x807AD4F4: neg.s       $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = -ctx->f26.fl;
    // 0x807AD4F8: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x807AD4FC: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x807AD500: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x807AD504: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x807AD508: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x807AD50C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x807AD510: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x807AD514: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x807AD518: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x807AD51C: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x807AD520: jal         0x807AD364
    // 0x807AD524: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    func_807AD364(rdram, ctx);
        goto after_4;
    // 0x807AD524: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x807AD528: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x807AD52C: bnel        $s0, $s4, L_807AD47C
    if (ctx->r16 != ctx->r20) {
        // 0x807AD530: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_807AD47C;
    }
    goto skip_0;
    // 0x807AD530: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_0:
    // 0x807AD534: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x807AD538: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x807AD53C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x807AD540: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x807AD544: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x807AD548: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x807AD54C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x807AD550: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x807AD554: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x807AD558: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x807AD55C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x807AD560: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x807AD564: jr          $ra
    // 0x807AD568: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x807AD568: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80043A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043A24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043A2C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80043A30: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80043A34: addiu       $a1, $a1, 0x3A14
    ctx->r5 = ADD32(ctx->r5, 0X3A14);
    // 0x80043A38: addiu       $a0, $a0, -0x7804
    ctx->r4 = ADD32(ctx->r4, -0X7804);
    // 0x80043A3C: jal         0x80057A28
    // 0x80043A40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80057A28(rdram, ctx);
        goto after_0;
    // 0x80043A40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80043A44: bne         $v0, $zero, L_80043A54
    if (ctx->r2 != 0) {
        // 0x80043A48: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80043A54;
    }
    // 0x80043A48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80043A4C: b           L_80043A78
    // 0x80043A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80043A78;
    // 0x80043A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80043A54:
    // 0x80043A54: jal         0x80045C44
    // 0x80043A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045C44(rdram, ctx);
        goto after_1;
    // 0x80043A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80043A5C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80043A60: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80043A64: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x80043A68: lw          $t6, -0x77F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F8);
    // 0x80043A6C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80043A70: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80043A74: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
L_80043A78:
    // 0x80043A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043A7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80043A80: jr          $ra
    // 0x80043A84: nop

    return;
    // 0x80043A84: nop

;}
RECOMP_FUNC void func_804355DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804355DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804355E0: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x804355E4: lw          $a2, -0x7CE8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CE8);
    // 0x804355E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804355EC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x804355F0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x804355F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804355F8: lwc1        $f6, 0x38($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X38);
    // 0x804355FC: lwc1        $f2, 0xC4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80435600: lwc1        $f14, 0xC8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80435604: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80435608: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8043560C: addiu       $v0, $a1, 0xE8C
    ctx->r2 = ADD32(ctx->r5, 0XE8C);
    // 0x80435610: addiu       $v1, $a1, 0x106C
    ctx->r3 = ADD32(ctx->r5, 0X106C);
    // 0x80435614: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80435618: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8043561C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80435620: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80435624: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80435628: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8043562C: jal         0x80081C64
    // 0x80435630: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80435630: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80435634: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80435638: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x8043563C: lw          $a1, 0x3F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X3F4);
    // 0x80435640: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80435644: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80435648: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8043564C: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80435650: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80435654: div.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80435658: lw          $t6, 0x478($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X478);
    // 0x8043565C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80435660: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80435664: lwc1        $f8, 0xAC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XAC);
    // 0x80435668: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8043566C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80435670: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80435674: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80435678: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8043567C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80435680: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80435684: nop

    // 0x80435688: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8043568C: jal         0x80081C64
    // 0x80435690: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x80435690: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80435694: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80435698: lw          $a1, -0x7D6C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D6C);
    // 0x8043569C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x804356A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804356A4: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x804356A8: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x804356AC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x804356B0: div.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x804356B4: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x804356B8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x804356BC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x804356C0: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x804356C4: lwc1        $f6, 0xB0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XB0);
    // 0x804356C8: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804356CC: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804356D0: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804356D4: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x804356D8: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x804356DC: lwc1        $f8, 0x30($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X30);
    // 0x804356E0: div.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    // 0x804356E4: swc1        $f8, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f8.u32l;
    // 0x804356E8: lwc1        $f10, 0x34($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X34);
    // 0x804356EC: swc1        $f10, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f10.u32l;
    // 0x804356F0: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804356F4: nop

L_804356F8:
    // 0x804356F8: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804356FC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80435700: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80435704: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80435708: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8043570C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80435710: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80435714: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80435718: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8043571C: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80435720: lwc1        $f4, -0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80435724: add.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80435728: sub.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8043572C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80435730: bgez        $a0, L_804356F8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80435734: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_804356F8;
    }
    // 0x80435734: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80435738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043573C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80435740: jr          $ra
    // 0x80435744: nop

    return;
    // 0x80435744: nop

;}
RECOMP_FUNC void func_80029CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029CC0: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80029CC4: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80029CC8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80029CCC: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80029CD0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80029CD4: lwc1        $f4, 0x10($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80029CD8: sll         $v0, $t7, 2
    ctx->r2 = S32(ctx->r15 << 2);
    // 0x80029CDC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80029CE0: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80029CE4: lwc1        $f6, -0x2174($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2174);
    // 0x80029CE8: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x80029CEC: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x80029CF0: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80029CF4: jr          $ra
    // 0x80029CF8: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80029CF8: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80519CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519CE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80519CE4: jal         0x80519C5C
    // 0x80519CE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80519C5C(rdram, ctx);
        goto after_0;
    // 0x80519CE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80519CEC: jal         0x8003B41C
    // 0x80519CF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003B41C(rdram, ctx);
        goto after_1;
    // 0x80519CF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80519CF4: jal         0x8005FE48
    // 0x80519CF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x80519CF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80519CFC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80519D00: addiu       $t6, $zero, 0x707
    ctx->r14 = ADD32(0, 0X707);
    // 0x80519D04: lw          $t8, 0x174($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X174);
    // 0x80519D08: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80519D0C: sh          $t6, 0x16($t9)
    MEM_H(0X16, ctx->r25) = ctx->r14;
    // 0x80519D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80519D14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519D18: jr          $ra
    // 0x80519D1C: nop

    return;
    // 0x80519D1C: nop

;}
RECOMP_FUNC void func_8051B420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051B420: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8051B424: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x8051B428: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8051B42C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8051B430: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8051B434: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8051B438: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8051B43C: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8051B440: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8051B444: bnel        $v1, $zero, L_8051B5DC
    if (ctx->r3 != 0) {
        // 0x8051B448: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_8051B5DC;
    }
    goto skip_0;
    // 0x8051B448: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x8051B44C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8051B450: jal         0x800653D8
    // 0x8051B454: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8051B454: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x8051B458: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8051B45C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8051B460: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(297, 0X408) << 16);
    // 0x8051B464: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8051B468: lwc1        $f6, -0x48C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(297, 0X408));
    // 0x8051B46C: jal         0x800653D8
    // 0x8051B470: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x8051B470: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8051B474: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8051B478: andi        $a1, $v0, 0x1F
    ctx->r5 = ctx->r2 & 0X1F;
    // 0x8051B47C: lwc1        $f12, 0xAC($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XAC);
    // 0x8051B480: jal         0x80065954
    // 0x8051B484: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8051B484: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_2:
    // 0x8051B488: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8051B48C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8051B490: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8051B494: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8051B498: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8051B49C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8051B4A0: bc1fl       L_8051B4B4
    if (!c1cs) {
        // 0x8051B4A4: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8051B4B4;
    }
    goto skip_1;
    // 0x8051B4A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x8051B4A8: b           L_8051B4D4
    // 0x8051B4AC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
        goto L_8051B4D4;
    // 0x8051B4AC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8051B4B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8051B4B4:
    // 0x8051B4B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8051B4B8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8051B4BC: nop

    // 0x8051B4C0: bc1fl       L_8051B4D4
    if (!c1cs) {
        // 0x8051B4C4: sw          $zero, 0x24($sp)
        MEM_W(0X24, ctx->r29) = 0;
            goto L_8051B4D4;
    }
    goto skip_2;
    // 0x8051B4C4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    skip_2:
    // 0x8051B4C8: b           L_8051B4D4
    // 0x8051B4CC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
        goto L_8051B4D4;
    // 0x8051B4CC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8051B4D0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8051B4D4:
    // 0x8051B4D4: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8051B4D8: bnel        $a1, $t1, L_8051B4FC
    if (ctx->r5 != ctx->r9) {
        // 0x8051B4DC: lw          $t3, 0x44($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X44);
            goto L_8051B4FC;
    }
    goto skip_3;
    // 0x8051B4DC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    skip_3:
L_8051B4E0:
    // 0x8051B4E0: jal         0x800653D8
    // 0x8051B4E4: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x8051B4E4: nop

    after_3:
    // 0x8051B4E8: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8051B4EC: andi        $a1, $v0, 0x1F
    ctx->r5 = ctx->r2 & 0X1F;
    // 0x8051B4F0: beq         $a1, $t2, L_8051B4E0
    if (ctx->r5 == ctx->r10) {
        // 0x8051B4F4: nop
    
            goto L_8051B4E0;
    }
    // 0x8051B4F4: nop

    // 0x8051B4F8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
L_8051B4FC:
    // 0x8051B4FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8051B500: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8051B504: lwc1        $f16, 0xAC($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XAC);
    // 0x8051B508: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8051B50C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8051B510: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8051B514: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(297, 0X410) << 16);
    // 0x8051B518: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8051B51C: bc1fl       L_8051B52C
    if (!c1cs) {
        // 0x8051B520: sll         $t5, $t4, 2
        ctx->r13 = S32(ctx->r12 << 2);
            goto L_8051B52C;
    }
    goto skip_4;
    // 0x8051B520: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    skip_4:
    // 0x8051B524: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8051B528: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
L_8051B52C:
    // 0x8051B52C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8051B530: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8051B534: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8051B538: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8051B53C: lw          $t9, -0x48C0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(297, 0X410));
    // 0x8051B540: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8051B544: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8051B548: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x8051B54C: addiu       $t1, $t0, -0x10
    ctx->r9 = ADD32(ctx->r8, -0X10);
    // 0x8051B550: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8051B554: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8051B558: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8051B55C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8051B560: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8051B564: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8051B568: lw          $a2, 0x44($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X44);
    // 0x8051B56C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8051B570: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8051B574: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8051B578: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8051B57C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8051B580: jal         0x8051B368
    // 0x8051B584: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    func_8051B368(rdram, ctx);
        goto after_4;
    // 0x8051B584: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    after_4:
    // 0x8051B588: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8051B58C: beq         $v0, $zero, L_8051B5E0
    if (ctx->r2 == 0) {
        // 0x8051B590: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8051B5E0;
    }
    // 0x8051B590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8051B594: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8051B598: lw          $t3, 0x16C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X16C);
    // 0x8051B59C: lui         $t2, 0x8052
    ctx->r10 = S32(RELOC_HI16(297, 0X400) << 16);
    // 0x8051B5A0: addiu       $t2, $t2, -0x48D0
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(297, 0X400));
    // 0x8051B5A4: lui         $t4, 0x8052
    ctx->r12 = S32(RELOC_HI16(297, 0X398) << 16);
    // 0x8051B5A8: swc1        $f0, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f0.u32l;
    // 0x8051B5AC: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x8051B5B0: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x8051B5B4: addiu       $t4, $t4, -0x4938
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(297, 0X398));
    // 0x8051B5B8: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8051B5BC: sw          $t4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r12;
    // 0x8051B5C0: jal         0x80044194
    // 0x8051B5C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80044194(rdram, ctx);
        goto after_5;
    // 0x8051B5C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_5:
    // 0x8051B5C8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8051B5CC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8051B5D0: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x8051B5D4: sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // 0x8051B5D8: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
L_8051B5DC:
    // 0x8051B5DC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_8051B5E0:
    // 0x8051B5E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8051B5E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8051B5E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8051B5EC: jr          $ra
    // 0x8051B5F0: nop

    return;
    // 0x8051B5F0: nop

;}
RECOMP_FUNC void func_80002770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002770: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002774: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80002778: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8000277C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80002780: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80002784: bne         $a3, $zero, L_800027A0
    if (ctx->r7 != 0) {
        // 0x80002788: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800027A0;
    }
    // 0x80002788: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000278C: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x80002790: jal         0x80000FA0
    // 0x80002794: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    func_80000FA0(rdram, ctx);
        goto after_0;
    // 0x80002794: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x80002798: b           L_80002808
    // 0x8000279C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80002808;
    // 0x8000279C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800027A0:
    // 0x800027A0: lhu         $t7, 0x32($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X32);
    // 0x800027A4: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800027A8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800027AC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800027B0: lui         $at, 0x3C0
    ctx->r1 = S32(0X3C0 << 16);
    // 0x800027B4: andi        $t9, $a2, 0xFFFF
    ctx->r25 = ctx->r6 & 0XFFFF;
    // 0x800027B8: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x800027BC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800027C0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800027C4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800027C8: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800027CC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800027D0: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800027D4: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800027D8: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800027DC: andi        $t5, $a3, 0xFFFF
    ctx->r13 = ctx->r7 & 0XFFFF;
    // 0x800027E0: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x800027E4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800027E8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800027EC: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x800027F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800027F4: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800027F8: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800027FC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80002800: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80002804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80002808:
    // 0x80002808: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8000280C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002810: jr          $ra
    // 0x80002814: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80002814: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_805AE174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE174: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE178: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE17C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE180: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE184: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE188: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE18C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE190: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE194: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE198: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE19C: jr          $ra
    // 0x805AE1A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE1A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8073751C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073751C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80737520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80737524: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80737528: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B54) << 16);
    // 0x8073752C: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x80737530: blez        $v1, L_80737540
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80737534: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80737540;
    }
    // 0x80737534: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80737538: b           L_80737560
    // 0x8073753C: sw          $t6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r14;
        goto L_80737560;
    // 0x8073753C: sw          $t6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r14;
L_80737540:
    // 0x80737540: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80737544: lwc1        $f14, -0x6A4C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B54));
    // 0x80737548: jal         0x80735AE8
    // 0x8073754C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80735AE8(rdram, ctx);
        goto after_0;
    // 0x8073754C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80737550: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80737554: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x80737558: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x8073755C: sw          $t7, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r15;
L_80737560:
    // 0x80737560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80737564: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80737568: jr          $ra
    // 0x8073756C: nop

    return;
    // 0x8073756C: nop

;}
RECOMP_FUNC void func_8002181C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002181C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80021820: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80021824: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80021828: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002182C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80021830: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80021834: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80021838: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8002183C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80021840: jal         0x80047AB8
    // 0x80021844: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80021844: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    after_0:
    // 0x80021848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002184C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80021850: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80021854: jal         0x800213B0
    // 0x80021858: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_800213B0(rdram, ctx);
        goto after_1;
    // 0x80021858: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8002185C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021860: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80021864: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80021868: jal         0x800217E0
    // 0x8002186C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_800217E0(rdram, ctx);
        goto after_2;
    // 0x8002186C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80021870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80021874: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021878: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8002187C: jr          $ra
    // 0x80021880: nop

    return;
    // 0x80021880: nop

;}
RECOMP_FUNC void func_80561460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80561460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80561464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80561468: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8056146C: addiu       $at, $zero, 0x41CA
    ctx->r1 = ADD32(0, 0X41CA);
    // 0x80561470: beq         $v0, $at, L_80561498
    if (ctx->r2 == ctx->r1) {
        // 0x80561474: addiu       $at, $zero, 0x41CB
        ctx->r1 = ADD32(0, 0X41CB);
            goto L_80561498;
    }
    // 0x80561474: addiu       $at, $zero, 0x41CB
    ctx->r1 = ADD32(0, 0X41CB);
    // 0x80561478: beq         $v0, $at, L_80561498
    if (ctx->r2 == ctx->r1) {
        // 0x8056147C: addiu       $at, $zero, 0x41CC
        ctx->r1 = ADD32(0, 0X41CC);
            goto L_80561498;
    }
    // 0x8056147C: addiu       $at, $zero, 0x41CC
    ctx->r1 = ADD32(0, 0X41CC);
    // 0x80561480: beq         $v0, $at, L_805614A8
    if (ctx->r2 == ctx->r1) {
        // 0x80561484: addiu       $at, $zero, 0x41CD
        ctx->r1 = ADD32(0, 0X41CD);
            goto L_805614A8;
    }
    // 0x80561484: addiu       $at, $zero, 0x41CD
    ctx->r1 = ADD32(0, 0X41CD);
    // 0x80561488: beq         $v0, $at, L_805614A8
    if (ctx->r2 == ctx->r1) {
        // 0x8056148C: nop
    
            goto L_805614A8;
    }
    // 0x8056148C: nop

    // 0x80561490: b           L_805614B4
    // 0x80561494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805614B4;
    // 0x80561494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80561498:
    // 0x80561498: jal         0x805616BC
    // 0x8056149C: nop

    func_805616BC(rdram, ctx);
        goto after_0;
    // 0x8056149C: nop

    after_0:
    // 0x805614A0: b           L_805614B4
    // 0x805614A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805614B4;
    // 0x805614A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805614A8:
    // 0x805614A8: jal         0x80561760
    // 0x805614AC: nop

    func_80561760(rdram, ctx);
        goto after_1;
    // 0x805614AC: nop

    after_1:
    // 0x805614B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805614B4:
    // 0x805614B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805614B8: jr          $ra
    // 0x805614BC: nop

    return;
    // 0x805614BC: nop

;}
RECOMP_FUNC void func_80558720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558720: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80558724: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80558728: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8055872C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80558730: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80558734: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80558738: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8055873C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558740: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80558744: jal         0x80048F84
    // 0x80558748: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80558748: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x8055874C: jal         0x805580E8
    // 0x80558750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805580E8(rdram, ctx);
        goto after_1;
    // 0x80558750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80558754: jal         0x805582E0
    // 0x80558758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805582E0(rdram, ctx);
        goto after_2;
    // 0x80558758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8055875C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80558760: jal         0x80558430
    // 0x80558764: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_80558430(rdram, ctx);
        goto after_3;
    // 0x80558764: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_3:
    // 0x80558768: jal         0x805586D8
    // 0x8055876C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_805586D8(rdram, ctx);
        goto after_4;
    // 0x8055876C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80558770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558778: jal         0x80559928
    // 0x8055877C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    func_80559928(rdram, ctx);
        goto after_5;
    // 0x8055877C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_5:
    // 0x80558780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80558784: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80558788: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8055878C: jr          $ra
    // 0x80558790: nop

    return;
    // 0x80558790: nop

;}
RECOMP_FUNC void func_80682CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682CB4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682CB8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682CBC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682CC0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682CC4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682CC8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682CCC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682CD0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682CD4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682CD8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682CDC: jr          $ra
    // 0x80682CE0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682CE0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805A7BD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7BD8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805A7BDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A7BE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A7BE4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A7BE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A7BEC: jal         0x805A7440
    // 0x805A7BF0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_805A7440(rdram, ctx);
        goto after_0;
    // 0x805A7BF0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x805A7BF4: jal         0x800692D4
    // 0x805A7BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800692D4(rdram, ctx);
        goto after_1;
    // 0x805A7BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A7BFC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805A7C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A7C04: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
    // 0x805A7C08: bnel        $t6, $zero, L_805A7C48
    if (ctx->r14 != 0) {
        // 0x805A7C0C: lw          $v0, 0x14($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X14);
            goto L_805A7C48;
    }
    goto skip_0;
    // 0x805A7C0C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    skip_0:
    // 0x805A7C10: jal         0x805A7620
    // 0x805A7C14: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_805A7620(rdram, ctx);
        goto after_2;
    // 0x805A7C14: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_2:
    // 0x805A7C18: beq         $v0, $zero, L_805A7C44
    if (ctx->r2 == 0) {
        // 0x805A7C1C: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_805A7C44;
    }
    // 0x805A7C1C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805A7C20: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x805A7C24: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x805A7C28: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x805A7C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A7C30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A7C34: jal         0x805A8794
    // 0x805A7C38: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_805A8794(rdram, ctx);
        goto after_3;
    // 0x805A7C38: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_3:
    // 0x805A7C3C: b           L_805A7D90
    // 0x805A7C40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A7D90;
    // 0x805A7C40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A7C44:
    // 0x805A7C44: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
L_805A7C48:
    // 0x805A7C48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805A7C4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805A7C50: beql        $v0, $zero, L_805A7C6C
    if (ctx->r2 == 0) {
        // 0x805A7C54: lw          $v0, 0x8($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X8);
            goto L_805A7C6C;
    }
    goto skip_1;
    // 0x805A7C54: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x805A7C58: beql        $v0, $at, L_805A7CA0
    if (ctx->r2 == ctx->r1) {
        // 0x805A7C5C: lw          $t9, 0x138($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X138);
            goto L_805A7CA0;
    }
    goto skip_2;
    // 0x805A7C5C: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    skip_2:
    // 0x805A7C60: b           L_805A7D54
    // 0x805A7C64: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
        goto L_805A7D54;
    // 0x805A7C64: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805A7C68: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
L_805A7C6C:
    // 0x805A7C6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A7C70: beq         $v0, $zero, L_805A7C80
    if (ctx->r2 == 0) {
        // 0x805A7C74: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_805A7C80;
    }
    // 0x805A7C74: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x805A7C78: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x805A7C7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_805A7C80:
    // 0x805A7C80: bne         $v0, $zero, L_805A7C94
    if (ctx->r2 != 0) {
        // 0x805A7C84: nop
    
            goto L_805A7C94;
    }
    // 0x805A7C84: nop

    // 0x805A7C88: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x805A7C8C: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x805A7C90: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
L_805A7C94:
    // 0x805A7C94: b           L_805A7D54
    // 0x805A7C98: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
        goto L_805A7D54;
    // 0x805A7C98: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805A7C9C: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
L_805A7CA0:
    // 0x805A7CA0: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(426, 0X16F0) << 16);
    // 0x805A7CA4: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x805A7CA8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805A7CAC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x805A7CB0: lwc1        $f4, -0x75C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(426, 0X16F0));
    // 0x805A7CB4: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x805A7CB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A7CBC: swc1        $f4, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f4.u32l;
    // 0x805A7CC0: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x805A7CC4: swc1        $f6, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f6.u32l;
    // 0x805A7CC8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x805A7CCC: beq         $v0, $zero, L_805A7CDC
    if (ctx->r2 == 0) {
        // 0x805A7CD0: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_805A7CDC;
    }
    // 0x805A7CD0: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x805A7CD4: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x805A7CD8: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_805A7CDC:
    // 0x805A7CDC: bnel        $v0, $zero, L_805A7D54
    if (ctx->r2 != 0) {
        // 0x805A7CE0: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_805A7D54;
    }
    goto skip_3;
    // 0x805A7CE0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_3:
    // 0x805A7CE4: lw          $t4, 0x10($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X10);
    // 0x805A7CE8: lui         $t6, 0x805B
    ctx->r14 = S32(RELOC_HI16(426, 0X16E0) << 16);
    // 0x805A7CEC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x805A7CF0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x805A7CF4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x805A7CF8: lh          $t6, -0x75D0($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(426, 0X16E0));
    // 0x805A7CFC: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
    // 0x805A7D00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x805A7D04: sh          $t6, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r14;
    // 0x805A7D08: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x805A7D0C: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x805A7D10: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805A7D14: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x805A7D18: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x805A7D1C: bne         $at, $zero, L_805A7D50
    if (ctx->r1 != 0) {
        // 0x805A7D20: sw          $t8, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r24;
            goto L_805A7D50;
    }
    // 0x805A7D20: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x805A7D24: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x805A7D28: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x805A7D2C: lw          $t2, 0x138($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X138);
    // 0x805A7D30: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805A7D34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A7D38: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x805A7D3C: sw          $t4, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r12;
    // 0x805A7D40: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x805A7D44: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805A7D48: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
    // 0x805A7D4C: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
L_805A7D50:
    // 0x805A7D50: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_805A7D54:
    // 0x805A7D54: jal         0x80048F84
    // 0x805A7D58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x805A7D58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_4:
    // 0x805A7D5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A7D60: jal         0x80048F84
    // 0x805A7D64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_5;
    // 0x805A7D64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x805A7D68: beq         $v0, $zero, L_805A7D84
    if (ctx->r2 == 0) {
        // 0x805A7D6C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_805A7D84;
    }
    // 0x805A7D6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A7D70: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805A7D74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A7D78: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x805A7D7C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x805A7D80: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
L_805A7D84:
    // 0x805A7D84: jal         0x805A7460
    // 0x805A7D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A7460(rdram, ctx);
        goto after_6;
    // 0x805A7D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805A7D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A7D90:
    // 0x805A7D90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A7D94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805A7D98: jr          $ra
    // 0x805A7D9C: nop

    return;
    // 0x805A7D9C: nop

;}
RECOMP_FUNC void func_805AE5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE5F4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE5F8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE5FC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE600: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE604: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE608: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE60C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE610: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE614: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE618: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE61C: jr          $ra
    // 0x805AE620: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE620: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8006A284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A284: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006A288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A28C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006A290: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8006A294: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8006A298: lw          $a3, 0x38($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X38);
    // 0x8006A29C: bnel        $a3, $zero, L_8006A2B0
    if (ctx->r7 != 0) {
        // 0x8006A2A0: lw          $t9, 0x1C($t8)
        ctx->r25 = MEM_W(ctx->r24, 0X1C);
            goto L_8006A2B0;
    }
    goto skip_0;
    // 0x8006A2A0: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    skip_0:
    // 0x8006A2A4: b           L_8006A318
    // 0x8006A2A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006A318;
    // 0x8006A2A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006A2AC: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
L_8006A2B0:
    // 0x8006A2B0: addiu       $a1, $zero, 0x19C
    ctx->r5 = ADD32(0, 0X19C);
    // 0x8006A2B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8006A2B8: beq         $t9, $zero, L_8006A2D4
    if (ctx->r25 == 0) {
        // 0x8006A2BC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8006A2D4;
    }
    // 0x8006A2BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006A2C0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A2C4: jal         0x80071380
    // 0x8006A2C8: addiu       $a0, $a0, 0xF60
    ctx->r4 = ADD32(ctx->r4, 0XF60);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8006A2C8: addiu       $a0, $a0, 0xF60
    ctx->r4 = ADD32(ctx->r4, 0XF60);
    after_0:
    // 0x8006A2CC: b           L_8006A318
    // 0x8006A2D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A318;
    // 0x8006A2D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A2D4:
    // 0x8006A2D4: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8006A2D8: jal         0x80069FE4
    // 0x8006A2DC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80069FE4(rdram, ctx);
        goto after_1;
    // 0x8006A2DC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8006A2E0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8006A2E4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A2E8: bne         $v0, $zero, L_8006A308
    if (ctx->r2 != 0) {
        // 0x8006A2EC: sw          $v0, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->r2;
            goto L_8006A308;
    }
    // 0x8006A2EC: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x8006A2F0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A2F4: addiu       $a0, $a0, 0xF70
    ctx->r4 = ADD32(ctx->r4, 0XF70);
    // 0x8006A2F8: jal         0x80071380
    // 0x8006A2FC: addiu       $a1, $zero, 0x1A7
    ctx->r5 = ADD32(0, 0X1A7);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8006A2FC: addiu       $a1, $zero, 0x1A7
    ctx->r5 = ADD32(0, 0X1A7);
    after_2:
    // 0x8006A300: b           L_8006A318
    // 0x8006A304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A318;
    // 0x8006A304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A308:
    // 0x8006A308: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8006A30C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006A310: srl         $t1, $t0, 1
    ctx->r9 = S32(U32(ctx->r8) >> 1);
    // 0x8006A314: sh          $t1, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r9;
L_8006A318:
    // 0x8006A318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A31C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006A320: jr          $ra
    // 0x8006A324: nop

    return;
    // 0x8006A324: nop

;}
RECOMP_FUNC void func_8059FA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059FA00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8059FA04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8059FA08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8059FA0C: jal         0x8059F608
    // 0x8059FA10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8059F608(rdram, ctx);
        goto after_0;
    // 0x8059FA10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8059FA14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8059FA18: beq         $v0, $at, L_8059FA30
    if (ctx->r2 == ctx->r1) {
        // 0x8059FA1C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8059FA30;
    }
    // 0x8059FA1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8059FA20: beq         $v0, $at, L_8059FA40
    if (ctx->r2 == ctx->r1) {
        // 0x8059FA24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8059FA40;
    }
    // 0x8059FA24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059FA28: b           L_8059FA80
    // 0x8059FA2C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_8059FA80;
    // 0x8059FA2C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059FA30:
    // 0x8059FA30: jal         0x8059F3CC
    // 0x8059FA34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8059F3CC(rdram, ctx);
        goto after_1;
    // 0x8059FA34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8059FA38: b           L_8059FA80
    // 0x8059FA3C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_8059FA80;
    // 0x8059FA3C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059FA40:
    // 0x8059FA40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059FA44: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8059FA48: jal         0x805A0790
    // 0x8059FA4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A0790(rdram, ctx);
        goto after_2;
    // 0x8059FA4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8059FA50: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8059FA54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8059FA58: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8059FA5C: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8059FA60: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8059FA64: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8059FA68: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8059FA6C: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x8059FA70: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FA74: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x8059FA78: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x8059FA7C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059FA80:
    // 0x8059FA80: lhu         $t8, 0x8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FA84: andi        $t9, $t8, 0xFFF7
    ctx->r25 = ctx->r24 & 0XFFF7;
    // 0x8059FA88: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x8059FA8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8059FA90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8059FA94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8059FA98: jr          $ra
    // 0x8059FA9C: nop

    return;
    // 0x8059FA9C: nop

;}
RECOMP_FUNC void func_80554A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80554A94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80554A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80554A9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80554AA0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80554AA4: jal         0x80047090
    // 0x80554AA8: addiu       $a0, $zero, 0x46F9
    ctx->r4 = ADD32(0, 0X46F9);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80554AA8: addiu       $a0, $zero, 0x46F9
    ctx->r4 = ADD32(0, 0X46F9);
    after_0:
    // 0x80554AAC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80554AB0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80554AB4: beq         $v0, $at, L_80554AF4
    if (ctx->r2 == ctx->r1) {
        // 0x80554AB8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80554AF4;
    }
    // 0x80554AB8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80554ABC: lui         $at, 0x46F9
    ctx->r1 = S32(0X46F9 << 16);
    // 0x80554AC0: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80554AC4: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80554AC8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80554ACC: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x80554AD0: jal         0x8004613C
    // 0x80554AD4: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80554AD4: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    after_1:
    // 0x80554AD8: beq         $v0, $zero, L_80554AF4
    if (ctx->r2 == 0) {
        // 0x80554ADC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80554AF4;
    }
    // 0x80554ADC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80554AE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80554AE4: jal         0x80047F9C
    // 0x80554AE8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80554AE8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x80554AEC: b           L_80554AF8
    // 0x80554AF0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_80554AF8;
    // 0x80554AF0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_80554AF4:
    // 0x80554AF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80554AF8:
    // 0x80554AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80554AFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80554B00: jr          $ra
    // 0x80554B04: nop

    return;
    // 0x80554B04: nop

    // 0x80554B08: nop

    // 0x80554B0C: nop

;}
RECOMP_FUNC void func_80043610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043610: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043618: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8004361C: jal         0x80045A34
    // 0x80043620: addiu       $a1, $zero, 0x1550
    ctx->r5 = ADD32(0, 0X1550);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80043620: addiu       $a1, $zero, 0x1550
    ctx->r5 = ADD32(0, 0X1550);
    after_0:
    // 0x80043624: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80043628: addiu       $a1, $zero, 0x1550
    ctx->r5 = ADD32(0, 0X1550);
    // 0x8004362C: bne         $v0, $zero, L_80043644
    if (ctx->r2 != 0) {
        // 0x80043630: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_80043644;
    }
    // 0x80043630: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x80043634: jal         0x800445A4
    // 0x80043638: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80043638: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8004363C: b           L_80043690
    // 0x80043640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80043690;
    // 0x80043640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80043644:
    // 0x80043644: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x80043648: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004364C: jal         0x80065728
    // 0x80043650: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x80043650: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x80043654: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80043658: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004365C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80043660: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80043664: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80043668: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004366C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80043670: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80043674: sb          $t6, 0xF6($a0)
    MEM_B(0XF6, ctx->r4) = ctx->r14;
    // 0x80043678: sw          $t7, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r15;
    // 0x8004367C: sb          $v1, 0xDE($a0)
    MEM_B(0XDE, ctx->r4) = ctx->r3;
    // 0x80043680: sb          $v1, 0xDF($a0)
    MEM_B(0XDF, ctx->r4) = ctx->r3;
    // 0x80043684: sb          $t8, 0x1AC($a0)
    MEM_B(0X1AC, ctx->r4) = ctx->r24;
    // 0x80043688: swc1        $f0, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->f0.u32l;
    // 0x8004368C: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
L_80043690:
    // 0x80043690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80043698: jr          $ra
    // 0x8004369C: nop

    return;
    // 0x8004369C: nop

;}
RECOMP_FUNC void func_804233F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804233F4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804233F8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804233FC: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x80423400: lh          $a1, 0x1C($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X1C);
    // 0x80423404: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80423408: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8042340C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80423410: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80423414: lw          $v1, 0x10($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X10);
    // 0x80423418: beq         $t8, $zero, L_80423498
    if (ctx->r24 == 0) {
        // 0x8042341C: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_80423498;
    }
    // 0x8042341C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80423420: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80423424: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
L_80423428:
    // 0x80423428: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8042342C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80423430: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80423434: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80423438: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8042343C: mflo        $t3
    ctx->r11 = lo;
    // 0x80423440: addu        $a0, $t9, $t3
    ctx->r4 = ADD32(ctx->r25, ctx->r11);
    // 0x80423444: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    // 0x80423448: sh          $t4, -0x10($a2)
    MEM_H(-0X10, ctx->r6) = ctx->r12;
    // 0x8042344C: lh          $t5, 0x2($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2);
    // 0x80423450: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80423454: sh          $t6, -0xE($a2)
    MEM_H(-0XE, ctx->r6) = ctx->r14;
    // 0x80423458: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x8042345C: sh          $zero, -0xA($a2)
    MEM_H(-0XA, ctx->r6) = 0;
    // 0x80423460: sh          $t7, -0xC($a2)
    MEM_H(-0XC, ctx->r6) = ctx->r15;
    // 0x80423464: lh          $t8, -0x4($a3)
    ctx->r24 = MEM_H(ctx->r7, -0X4);
    // 0x80423468: sh          $t8, -0x8($a2)
    MEM_H(-0X8, ctx->r6) = ctx->r24;
    // 0x8042346C: lh          $t2, -0x2($a3)
    ctx->r10 = MEM_H(ctx->r7, -0X2);
    // 0x80423470: sb          $zero, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = 0;
    // 0x80423474: sb          $t1, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r9;
    // 0x80423478: sb          $zero, -0x3($a2)
    MEM_B(-0X3, ctx->r6) = 0;
    // 0x8042347C: sb          $zero, -0x4($a2)
    MEM_B(-0X4, ctx->r6) = 0;
    // 0x80423480: sh          $t2, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r10;
    // 0x80423484: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80423488: sltu        $at, $t0, $t9
    ctx->r1 = ctx->r8 < ctx->r25 ? 1 : 0;
    // 0x8042348C: bnel        $at, $zero, L_80423428
    if (ctx->r1 != 0) {
        // 0x80423490: lw          $t2, 0x0($a3)
        ctx->r10 = MEM_W(ctx->r7, 0X0);
            goto L_80423428;
    }
    goto skip_0;
    // 0x80423490: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x80423494: lh          $a1, 0x1C($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X1C);
L_80423498:
    // 0x80423498: addiu       $t3, $a1, 0x1
    ctx->r11 = ADD32(ctx->r5, 0X1);
    // 0x8042349C: sh          $t3, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r11;
    // 0x804234A0: lh          $t4, 0x1C($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X1C);
    // 0x804234A4: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x804234A8: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x804234AC: bne         $at, $zero, L_804234B8
    if (ctx->r1 != 0) {
        // 0x804234B0: nop
    
            goto L_804234B8;
    }
    // 0x804234B0: nop

    // 0x804234B4: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
L_804234B8:
    // 0x804234B8: jr          $ra
    // 0x804234BC: nop

    return;
    // 0x804234BC: nop

;}
RECOMP_FUNC void func_80450760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450760: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80450764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450768: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8045076C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450770: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450774: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80450778: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8045077C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80450780: sw          $t6, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r14;
    // 0x80450784: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450788: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8045078C: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    // 0x80450790: jal         0x804449C0
    // 0x80450794: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804449C0(rdram, ctx);
        goto after_0;
    // 0x80450794: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80450798: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8045079C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804507A0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804507A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x804507A8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804507AC: jal         0x80450490
    // 0x804507B0: swc1        $f14, 0x6C88($at)
    MEM_W(0X6C88, ctx->r1) = ctx->f14.u32l;
    func_80450490(rdram, ctx);
        goto after_1;
    // 0x804507B0: swc1        $f14, 0x6C88($at)
    MEM_W(0X6C88, ctx->r1) = ctx->f14.u32l;
    after_1:
    // 0x804507B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804507B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804507BC: jr          $ra
    // 0x804507C0: nop

    return;
    // 0x804507C0: nop

;}
RECOMP_FUNC void func_806ECC78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ECC78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806ECC7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806ECC80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806ECC84: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806ECC88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806ECC8C: jal         0x800577D8
    // 0x806ECC90: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806ECC90: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x806ECC94: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806ECC98: blez        $v0, L_806ECCA8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806ECC9C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_806ECCA8;
    }
    // 0x806ECC9C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x806ECCA0: b           L_806ECCC4
    // 0x806ECCA4: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
        goto L_806ECCC4;
    // 0x806ECCA4: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_806ECCA8:
    // 0x806ECCA8: jal         0x806EC324
    // 0x806ECCAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC324(rdram, ctx);
        goto after_1;
    // 0x806ECCAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806ECCB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECCB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECCB8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806ECCBC: jal         0x806ED360
    // 0x806ECCC0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_2;
    // 0x806ECCC0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
L_806ECCC4:
    // 0x806ECCC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806ECCC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806ECCCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806ECCD0: jr          $ra
    // 0x806ECCD4: nop

    return;
    // 0x806ECCD4: nop

;}
RECOMP_FUNC void func_8078B4F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B4F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078B4F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078B4F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8078B4FC: jal         0x80045A34
    // 0x8078B500: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8078B500: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x8078B504: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8078B508: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8078B50C: bne         $v0, $zero, L_8078B51C
    if (ctx->r2 != 0) {
        // 0x8078B510: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078B51C;
    }
    // 0x8078B510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078B514: b           L_8078B520
    // 0x8078B518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8078B520;
    // 0x8078B518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8078B51C:
    // 0x8078B51C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8078B520:
    // 0x8078B520: jr          $ra
    // 0x8078B524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8078B524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805AD700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AD700: lui         $v0, 0x805B
    ctx->r2 = S32(RELOC_HI16(444, 0X10F0) << 16);
    // 0x805AD704: jr          $ra
    // 0x805AD708: addiu       $v0, $v0, -0x1810
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(444, 0X10F0));
    return;
    // 0x805AD708: addiu       $v0, $v0, -0x1810
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(444, 0X10F0));
;}
RECOMP_FUNC void func_807B9A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9A6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B9A70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B9A74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B9A78: jal         0x807B8D30
    // 0x807B9A7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807B8D30(rdram, ctx);
        goto after_0;
    // 0x807B9A7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807B9A80: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x807B9A84: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x807B9A88: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x807B9A8C: lhu         $v0, 0xC($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0XC);
    // 0x807B9A90: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x807B9A94: bne         $t7, $at, L_807B9B24
    if (ctx->r15 != ctx->r1) {
        // 0x807B9A98: andi        $t4, $v0, 0x4000
        ctx->r12 = ctx->r2 & 0X4000;
            goto L_807B9B24;
    }
    // 0x807B9A98: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    // 0x807B9A9C: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x807B9AA0: addiu       $a0, $zero, 0x205
    ctx->r4 = ADD32(0, 0X205);
    // 0x807B9AA4: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x807B9AA8: bne         $t9, $zero, L_807B9ADC
    if (ctx->r25 != 0) {
        // 0x807B9AAC: nop
    
            goto L_807B9ADC;
    }
    // 0x807B9AAC: nop

    // 0x807B9AB0: jal         0x807B92A8
    // 0x807B9AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B92A8(rdram, ctx);
        goto after_1;
    // 0x807B9AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807B9AB8: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x807B9ABC: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    // 0x807B9AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B9AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B9AC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807B9ACC: jal         0x807B9E2C
    // 0x807B9AD0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_807B9E2C(rdram, ctx);
        goto after_2;
    // 0x807B9AD0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_2:
    // 0x807B9AD4: b           L_807B9B74
    // 0x807B9AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807B9B74;
    // 0x807B9AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807B9ADC:
    // 0x807B9ADC: jal         0x80067818
    // 0x807B9AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x807B9AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x807B9AE4: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x807B9AE8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9AEC: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x807B9AF0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9AF4: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x807B9AF8: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x807B9AFC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9B00: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x807B9B04: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
    // 0x807B9B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B9B0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B9B10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807B9B14: jal         0x807B9E2C
    // 0x807B9B18: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_807B9E2C(rdram, ctx);
        goto after_4;
    // 0x807B9B18: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_4:
    // 0x807B9B1C: b           L_807B9B74
    // 0x807B9B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807B9B74;
    // 0x807B9B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807B9B24:
    // 0x807B9B24: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x807B9B28: bne         $t4, $at, L_807B9B70
    if (ctx->r12 != ctx->r1) {
        // 0x807B9B2C: addiu       $a0, $zero, 0x205
        ctx->r4 = ADD32(0, 0X205);
            goto L_807B9B70;
    }
    // 0x807B9B2C: addiu       $a0, $zero, 0x205
    ctx->r4 = ADD32(0, 0X205);
    // 0x807B9B30: jal         0x80067818
    // 0x807B9B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x807B9B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x807B9B38: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x807B9B3C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9B40: sb          $t5, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r13;
    // 0x807B9B44: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9B48: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x807B9B4C: sb          $t6, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r14;
    // 0x807B9B50: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9B54: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x807B9B58: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
    // 0x807B9B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B9B60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B9B64: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807B9B68: jal         0x807B9E2C
    // 0x807B9B6C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_807B9E2C(rdram, ctx);
        goto after_6;
    // 0x807B9B6C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_6:
L_807B9B70:
    // 0x807B9B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807B9B74:
    // 0x807B9B74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B9B78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B9B7C: jr          $ra
    // 0x807B9B80: nop

    return;
    // 0x807B9B80: nop

;}
RECOMP_FUNC void func_80034DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034DCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034DD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034DD4: jal         0x80021958
    // 0x80034DD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80034DD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80034DDC: bne         $v0, $zero, L_80034DEC
    if (ctx->r2 != 0) {
        // 0x80034DE0: nop
    
            goto L_80034DEC;
    }
    // 0x80034DE0: nop

    // 0x80034DE4: b           L_80034E08
    // 0x80034DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034E08;
    // 0x80034DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034DEC:
    // 0x80034DEC: jal         0x80034570
    // 0x80034DF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80034570(rdram, ctx);
        goto after_1;
    // 0x80034DF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80034DF4: bnel        $v0, $zero, L_80034E08
    if (ctx->r2 != 0) {
        // 0x80034DF8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80034E08;
    }
    goto skip_0;
    // 0x80034DF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80034DFC: b           L_80034E08
    // 0x80034E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034E08;
    // 0x80034E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034E04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80034E08:
    // 0x80034E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034E0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034E10: jr          $ra
    // 0x80034E14: nop

    return;
    // 0x80034E14: nop

;}
RECOMP_FUNC void func_806D1F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D1F1C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x806D1F20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D1F24: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x806D1F28: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D1F2C: jal         0x8004700C
    // 0x806D1F30: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D1F30: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_0:
    // 0x806D1F34: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x806D1F38: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x806D1F3C: lui         $t9, 0x806D
    ctx->r25 = S32(RELOC_HI16(610, 0X1688) << 16);
    // 0x806D1F40: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x806D1F44: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x806D1F48: addiu       $t9, $t9, 0x2C48
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(610, 0X1688));
    // 0x806D1F4C: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x806D1F50: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x806D1F54: lw          $a1, 0x16C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X16C);
    // 0x806D1F58: lw          $a2, 0x16C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X16C);
    // 0x806D1F5C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x806D1F60: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x806D1F64: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x806D1F68: sw          $t2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r10;
    // 0x806D1F6C: beq         $v0, $zero, L_806D226C
    if (ctx->r2 == 0) {
        // 0x806D1F70: sw          $t1, 0x4($t8)
        MEM_W(0X4, ctx->r24) = ctx->r9;
            goto L_806D226C;
    }
    // 0x806D1F70: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x806D1F74: lbu         $a3, 0x18($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X18);
    // 0x806D1F78: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x806D1F7C: bne         $t0, $a3, L_806D1FCC
    if (ctx->r8 != ctx->r7) {
        // 0x806D1F80: nop
    
            goto L_806D1FCC;
    }
    // 0x806D1F80: nop

    // 0x806D1F84: lw          $t3, 0x30($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X30);
    // 0x806D1F88: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x806D1F8C: bne         $t3, $zero, L_806D1FC4
    if (ctx->r11 != 0) {
        // 0x806D1F90: nop
    
            goto L_806D1FC4;
    }
    // 0x806D1F90: nop

    // 0x806D1F94: lbu         $a0, 0x30($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X30);
    // 0x806D1F98: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x806D1F9C: beq         $a0, $at, L_806D1FC4
    if (ctx->r4 == ctx->r1) {
        // 0x806D1FA0: nop
    
            goto L_806D1FC4;
    }
    // 0x806D1FA0: nop

    // 0x806D1FA4: beq         $t0, $a0, L_806D1FC4
    if (ctx->r8 == ctx->r4) {
        // 0x806D1FA8: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_806D1FC4;
    }
    // 0x806D1FA8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x806D1FAC: beq         $a0, $at, L_806D1FC4
    if (ctx->r4 == ctx->r1) {
        // 0x806D1FB0: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_806D1FC4;
    }
    // 0x806D1FB0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x806D1FB4: beq         $a0, $at, L_806D1FC4
    if (ctx->r4 == ctx->r1) {
        // 0x806D1FB8: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_806D1FC4;
    }
    // 0x806D1FB8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x806D1FBC: bne         $a0, $at, L_806D1FCC
    if (ctx->r4 != ctx->r1) {
        // 0x806D1FC0: nop
    
            goto L_806D1FCC;
    }
    // 0x806D1FC0: nop

L_806D1FC4:
    // 0x806D1FC4: b           L_806D226C
    // 0x806D1FC8: sw          $t4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r12;
        goto L_806D226C;
    // 0x806D1FC8: sw          $t4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r12;
L_806D1FCC:
    // 0x806D1FCC: bnel        $t0, $a3, L_806D2048
    if (ctx->r8 != ctx->r7) {
        // 0x806D1FD0: lw          $v0, 0x28($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X28);
            goto L_806D2048;
    }
    goto skip_0;
    // 0x806D1FD0: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    skip_0:
    // 0x806D1FD4: lw          $t5, 0x30($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X30);
    // 0x806D1FD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806D1FDC: bne         $t5, $zero, L_806D203C
    if (ctx->r13 != 0) {
        // 0x806D1FE0: nop
    
            goto L_806D203C;
    }
    // 0x806D1FE0: nop

    // 0x806D1FE4: lbu         $a0, 0x30($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X30);
    // 0x806D1FE8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x806D1FEC: beq         $a0, $zero, L_806D203C
    if (ctx->r4 == 0) {
        // 0x806D1FF0: nop
    
            goto L_806D203C;
    }
    // 0x806D1FF0: nop

    // 0x806D1FF4: beq         $a0, $at, L_806D203C
    if (ctx->r4 == ctx->r1) {
        // 0x806D1FF8: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_806D203C;
    }
    // 0x806D1FF8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x806D1FFC: beq         $a0, $at, L_806D203C
    if (ctx->r4 == ctx->r1) {
        // 0x806D2000: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_806D203C;
    }
    // 0x806D2000: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x806D2004: beq         $a0, $at, L_806D203C
    if (ctx->r4 == ctx->r1) {
        // 0x806D2008: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_806D203C;
    }
    // 0x806D2008: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x806D200C: beq         $a0, $at, L_806D203C
    if (ctx->r4 == ctx->r1) {
        // 0x806D2010: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_806D203C;
    }
    // 0x806D2010: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x806D2014: beq         $a0, $at, L_806D203C
    if (ctx->r4 == ctx->r1) {
        // 0x806D2018: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_806D203C;
    }
    // 0x806D2018: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x806D201C: beq         $a0, $at, L_806D203C
    if (ctx->r4 == ctx->r1) {
        // 0x806D2020: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_806D203C;
    }
    // 0x806D2020: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x806D2024: beq         $a0, $at, L_806D203C
    if (ctx->r4 == ctx->r1) {
        // 0x806D2028: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_806D203C;
    }
    // 0x806D2028: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x806D202C: beq         $a0, $at, L_806D203C
    if (ctx->r4 == ctx->r1) {
        // 0x806D2030: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_806D203C;
    }
    // 0x806D2030: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x806D2034: bnel        $a0, $at, L_806D2048
    if (ctx->r4 != ctx->r1) {
        // 0x806D2038: lw          $v0, 0x28($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X28);
            goto L_806D2048;
    }
    goto skip_1;
    // 0x806D2038: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    skip_1:
L_806D203C:
    // 0x806D203C: b           L_806D226C
    // 0x806D2040: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
        goto L_806D226C;
    // 0x806D2040: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x806D2044: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
L_806D2048:
    // 0x806D2048: beq         $v0, $zero, L_806D2054
    if (ctx->r2 == 0) {
        // 0x806D204C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_806D2054;
    }
    // 0x806D204C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x806D2050: sw          $t7, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r15;
L_806D2054:
    // 0x806D2054: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x806D2058: beq         $v0, $zero, L_806D2068
    if (ctx->r2 == 0) {
        // 0x806D205C: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_806D2068;
    }
    // 0x806D205C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x806D2060: sw          $t8, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r24;
    // 0x806D2064: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_806D2068:
    // 0x806D2068: bnel        $v0, $zero, L_806D208C
    if (ctx->r2 != 0) {
        // 0x806D206C: lw          $v0, 0x18($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X18);
            goto L_806D208C;
    }
    goto skip_2;
    // 0x806D206C: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    skip_2:
    // 0x806D2070: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x806D2074: lw          $t2, 0x1C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X1C);
    // 0x806D2078: addiu       $t1, $t9, 0x4
    ctx->r9 = ADD32(ctx->r25, 0X4);
    // 0x806D207C: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x806D2080: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    // 0x806D2084: sw          $t3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r11;
    // 0x806D2088: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
L_806D208C:
    // 0x806D208C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x806D2090: bnel        $at, $zero, L_806D20A8
    if (ctx->r1 != 0) {
        // 0x806D2094: sb          $v0, 0xD($a1)
        MEM_B(0XD, ctx->r5) = ctx->r2;
            goto L_806D20A8;
    }
    goto skip_3;
    // 0x806D2094: sb          $v0, 0xD($a1)
    MEM_B(0XD, ctx->r5) = ctx->r2;
    skip_3:
    // 0x806D2098: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x806D209C: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x806D20A0: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x806D20A4: sb          $v0, 0xD($a1)
    MEM_B(0XD, ctx->r5) = ctx->r2;
L_806D20A8:
    // 0x806D20A8: lw          $t4, 0x18($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X18);
    // 0x806D20AC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x806D20B0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x806D20B4: sb          $t4, 0xE($a1)
    MEM_B(0XE, ctx->r5) = ctx->r12;
    // 0x806D20B8: lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X18);
    // 0x806D20BC: sb          $t5, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r13;
    // 0x806D20C0: lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C);
    // 0x806D20C4: sb          $t6, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r14;
    // 0x806D20C8: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x806D20CC: sb          $t7, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r15;
    // 0x806D20D0: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x806D20D4: sb          $t8, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r24;
    // 0x806D20D8: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x806D20DC: sb          $t9, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r25;
    // 0x806D20E0: lw          $t1, 0x1C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X1C);
    // 0x806D20E4: sb          $t1, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r9;
    // 0x806D20E8: lw          $t2, 0x28($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X28);
    // 0x806D20EC: bne         $t2, $zero, L_806D2174
    if (ctx->r10 != 0) {
        // 0x806D20F0: nop
    
            goto L_806D2174;
    }
    // 0x806D20F0: nop

    // 0x806D20F4: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x806D20F8: bne         $t3, $zero, L_806D2120
    if (ctx->r11 != 0) {
        // 0x806D20FC: nop
    
            goto L_806D2120;
    }
    // 0x806D20FC: nop

    // 0x806D2100: jal         0x800677F8
    // 0x806D2104: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_800677F8(rdram, ctx);
        goto after_1;
    // 0x806D2104: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_1:
    // 0x806D2108: jal         0x8002FF38
    // 0x806D210C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8002FF38(rdram, ctx);
        goto after_2;
    // 0x806D210C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x806D2110: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x806D2114: lw          $t5, -0x72D8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X72D8);
    // 0x806D2118: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x806D211C: sw          $t4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r12;
L_806D2120:
    // 0x806D2120: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806D2124: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806D2128: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x806D212C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x806D2130: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806D2134: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806D2138: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x806D213C: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x806D2140: jalr        $t9
    // 0x806D2144: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x806D2144: nop

    after_3:
    // 0x806D2148: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x806D214C: lw          $a0, 0x34($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X34);
    // 0x806D2150: jal         0x80067BBC
    // 0x806D2154: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x806D2154: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    after_4:
    // 0x806D2158: addiu       $a0, $zero, 0x26F
    ctx->r4 = ADD32(0, 0X26F);
    // 0x806D215C: jal         0x80067818
    // 0x806D2160: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806D2160: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x806D2164: jal         0x800447C8
    // 0x806D2168: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800447C8(rdram, ctx);
        goto after_6;
    // 0x806D2168: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_6:
    // 0x806D216C: b           L_806D21F8
    // 0x806D2170: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
        goto L_806D21F8;
    // 0x806D2170: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
L_806D2174:
    // 0x806D2174: lw          $v0, -0x72D8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72D8);
    // 0x806D2178: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806D217C: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x806D2180: bnel        $t1, $at, L_806D21F8
    if (ctx->r9 != ctx->r1) {
        // 0x806D2184: lw          $t4, 0x50($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X50);
            goto L_806D21F8;
    }
    goto skip_4;
    // 0x806D2184: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    skip_4:
    // 0x806D2188: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x806D218C: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x806D2190: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x806D2194: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x806D2198: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x806D219C: sw          $t4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r12;
    // 0x806D21A0: sw          $a0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r4;
    // 0x806D21A4: sw          $a0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r4;
    // 0x806D21A8: sb          $t5, 0xD($a1)
    MEM_B(0XD, ctx->r5) = ctx->r13;
    // 0x806D21AC: lw          $t6, 0x18($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18);
    // 0x806D21B0: sb          $t6, 0xE($a1)
    MEM_B(0XE, ctx->r5) = ctx->r14;
    // 0x806D21B4: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x806D21B8: sb          $t7, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r15;
    // 0x806D21BC: lw          $t9, 0x1C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1C);
    // 0x806D21C0: sb          $t9, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r25;
    // 0x806D21C4: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x806D21C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D21CC: sb          $t8, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r24;
    // 0x806D21D0: lw          $t1, 0x18($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X18);
    // 0x806D21D4: sb          $t1, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r9;
    // 0x806D21D8: lw          $t2, 0x18($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X18);
    // 0x806D21DC: sb          $t2, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r10;
    // 0x806D21E0: lw          $t3, 0x1C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1C);
    // 0x806D21E4: sb          $t3, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r11;
    // 0x806D21E8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x806D21EC: jal         0x806D2BCC
    // 0x806D21F0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_806D2BCC(rdram, ctx);
        goto after_7;
    // 0x806D21F0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_7:
    // 0x806D21F4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
L_806D21F8:
    // 0x806D21F8: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x806D21FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806D2200: lhu         $t5, 0xC($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XC);
    // 0x806D2204: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x806D2208: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x806D220C: addiu       $t6, $t5, -0x465E
    ctx->r14 = ADD32(ctx->r13, -0X465E);
    // 0x806D2210: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x806D2214: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x806D2218: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X1724) << 16);
    // 0x806D221C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806D2220: lwc1        $f4, 0x2CE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X1724));
    // 0x806D2224: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x806D2228: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806D222C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x806D2230: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806D2234: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806D2238: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x806D223C: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x806D2240: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x806D2244: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x806D2248: swc1        $f6, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f6.u32l;
    // 0x806D224C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x806D2250: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806D2254: swc1        $f18, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f18.u32l;
    // 0x806D2258: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x806D225C: lbu         $t8, 0x165($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X165);
    // 0x806D2260: beql        $t8, $zero, L_806D2270
    if (ctx->r24 == 0) {
        // 0x806D2264: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D2270;
    }
    goto skip_5;
    // 0x806D2264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x806D2268: sb          $zero, 0x165($t9)
    MEM_B(0X165, ctx->r25) = 0;
L_806D226C:
    // 0x806D226C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D2270:
    // 0x806D2270: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x806D2274: jr          $ra
    // 0x806D2278: nop

    return;
    // 0x806D2278: nop

;}
RECOMP_FUNC void func_80421C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421C70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80421C74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80421C78: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80421C7C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80421C80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80421C84: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80421C88: lw          $t6, 0x898($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X898);
    // 0x80421C8C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80421C90: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80421C94: bne         $t6, $zero, L_80421CA4
    if (ctx->r14 != 0) {
        // 0x80421C98: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80421CA4;
    }
    // 0x80421C98: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80421C9C: b           L_80421D84
    // 0x80421CA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80421D84;
    // 0x80421CA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80421CA4:
    // 0x80421CA4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80421CA8:
    // 0x80421CA8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80421CAC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80421CB0: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x80421CB4: beq         $s0, $zero, L_80421CE0
    if (ctx->r16 == 0) {
        // 0x80421CB8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80421CE0;
    }
    // 0x80421CB8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80421CBC: lw          $t7, 0x180($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X180);
    // 0x80421CC0: bne         $v0, $t7, L_80421CE0
    if (ctx->r2 != ctx->r15) {
        // 0x80421CC4: nop
    
            goto L_80421CE0;
    }
    // 0x80421CC4: nop

    // 0x80421CC8: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x80421CCC: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x80421CD0: bne         $t9, $zero, L_80421CE0
    if (ctx->r25 != 0) {
        // 0x80421CD4: nop
    
            goto L_80421CE0;
    }
    // 0x80421CD4: nop

    // 0x80421CD8: b           L_80421D84
    // 0x80421CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80421D84;
    // 0x80421CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80421CE0:
    // 0x80421CE0: bne         $at, $zero, L_80421CA8
    if (ctx->r1 != 0) {
        // 0x80421CE4: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80421CA8;
    }
    // 0x80421CE4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80421CE8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80421CEC: jal         0x8005FD1C
    // 0x80421CF0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x80421CF0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80421CF4: lw          $t0, 0x174($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X174);
    // 0x80421CF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80421CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80421D00: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80421D04: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80421D08: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x80421D0C: jal         0x80422558
    // 0x80421D10: lw          $a3, 0x138($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X138);
    func_80422558(rdram, ctx);
        goto after_1;
    // 0x80421D10: lw          $a3, 0x138($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X138);
    after_1:
    // 0x80421D14: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80421D18: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80421D1C: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80421D20: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80421D24:
    // 0x80421D24: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80421D28: beql        $s0, $zero, L_80421D74
    if (ctx->r16 == 0) {
        // 0x80421D2C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80421D74;
    }
    goto skip_0;
    // 0x80421D2C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80421D30: lw          $t2, 0x180($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X180);
    // 0x80421D34: bnel        $v0, $t2, L_80421D74
    if (ctx->r2 != ctx->r10) {
        // 0x80421D38: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80421D74;
    }
    goto skip_1;
    // 0x80421D38: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80421D3C: jal         0x8005FD1C
    // 0x80421D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_2;
    // 0x80421D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80421D44: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80421D48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80421D4C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80421D50: lw          $t4, 0x174($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X174);
    // 0x80421D54: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80421D58: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    // 0x80421D5C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80421D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80421D64: jal         0x80421690
    // 0x80421D68: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80421690(rdram, ctx);
        goto after_3;
    // 0x80421D68: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x80421D6C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80421D70: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80421D74:
    // 0x80421D74: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80421D78: bne         $s2, $s3, L_80421D24
    if (ctx->r18 != ctx->r19) {
        // 0x80421D7C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80421D24;
    }
    // 0x80421D7C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80421D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80421D84:
    // 0x80421D84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80421D88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80421D8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80421D90: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80421D94: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80421D98: jr          $ra
    // 0x80421D9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80421D9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804EF46C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF46C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804EF470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF474: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804EF478: jal         0x80045A34
    // 0x804EF47C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804EF47C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x804EF480: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x804EF484: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x804EF488: bne         $v0, $zero, L_804EF498
    if (ctx->r2 != 0) {
        // 0x804EF48C: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_804EF498;
    }
    // 0x804EF48C: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x804EF490: b           L_804EF4D4
    // 0x804EF494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804EF4D4;
    // 0x804EF494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804EF498:
    // 0x804EF498: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x804EF49C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x804EF4A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804EF4A4: jal         0x800657CC
    // 0x804EF4A8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x804EF4A8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x804EF4AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x804EF4B0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x804EF4B4: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x804EF4B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804EF4BC: lwc1        $f4, 0x3C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x804EF4C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804EF4C4: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x804EF4C8: lwc1        $f6, 0x40($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X40);
    // 0x804EF4CC: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x804EF4D0: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
L_804EF4D4:
    // 0x804EF4D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EF4D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804EF4DC: jr          $ra
    // 0x804EF4E0: nop

    return;
    // 0x804EF4E0: nop

;}
RECOMP_FUNC void __osGetCurrFaultedThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090740: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80090744: jr          $ra
    // 0x80090748: lw          $v0, -0x53EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X53EC);
    return;
    // 0x80090748: lw          $v0, -0x53EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X53EC);
;}
RECOMP_FUNC void func_8041D660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041D660: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8041D664: addiu       $at, $zero, 0x45CB
    ctx->r1 = ADD32(0, 0X45CB);
    // 0x8041D668: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8041D66C: bne         $v0, $at, L_8041D690
    if (ctx->r2 != ctx->r1) {
        // 0x8041D670: addiu       $v1, $v1, 0x7EA0
        ctx->r3 = ADD32(ctx->r3, 0X7EA0);
            goto L_8041D690;
    }
    // 0x8041D670: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8041D674: lui         $t6, 0x8042
    ctx->r14 = S32(RELOC_HI16(29, 0X3A40) << 16);
    // 0x8041D678: addiu       $t6, $t6, 0x10A0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(29, 0X3A40));
    // 0x8041D67C: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(29, 0X2874) << 16);
    // 0x8041D680: sw          $t6, 0xE70($v1)
    MEM_W(0XE70, ctx->r3) = ctx->r14;
    // 0x8041D684: addiu       $t7, $t7, -0x12C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(29, 0X2874));
    // 0x8041D688: sw          $t7, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r15;
    // 0x8041D68C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
L_8041D690:
    // 0x8041D690: addiu       $at, $zero, 0x45F0
    ctx->r1 = ADD32(0, 0X45F0);
    // 0x8041D694: beq         $v0, $at, L_8041D6A8
    if (ctx->r2 == ctx->r1) {
        // 0x8041D698: lui         $t9, 0x8042
        ctx->r25 = S32(RELOC_HI16(29, 0X2FE4) << 16);
            goto L_8041D6A8;
    }
    // 0x8041D698: lui         $t9, 0x8042
    ctx->r25 = S32(RELOC_HI16(29, 0X2FE4) << 16);
    // 0x8041D69C: addiu       $at, $zero, 0x4638
    ctx->r1 = ADD32(0, 0X4638);
    // 0x8041D6A0: bne         $v0, $at, L_8041D6C8
    if (ctx->r2 != ctx->r1) {
        // 0x8041D6A4: nop
    
            goto L_8041D6C8;
    }
    // 0x8041D6A4: nop

L_8041D6A8:
    // 0x8041D6A8: lw          $t9, 0x644($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(29, 0X2FE4));
    // 0x8041D6AC: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8041D6B0: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X2FE0) << 16);
    // 0x8041D6B4: bne         $t9, $zero, L_8041D6C8
    if (ctx->r25 != 0) {
        // 0x8041D6B8: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8041D6C8;
    }
    // 0x8041D6B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8041D6BC: sw          $t0, 0x640($at)
    MEM_W((int16_t)RELOC_LO16(29, 0X2FE0), ctx->r1) = ctx->r8;
    // 0x8041D6C0: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X2FE4) << 16);
    // 0x8041D6C4: sw          $t1, 0x644($at)
    MEM_W((int16_t)RELOC_LO16(29, 0X2FE4), ctx->r1) = ctx->r9;
L_8041D6C8:
    // 0x8041D6C8: lui         $v0, 0x8042
    ctx->r2 = S32(RELOC_HI16(29, 0XA8) << 16);
    // 0x8041D6CC: jr          $ra
    // 0x8041D6D0: addiu       $v0, $v0, -0x28F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(29, 0XA8));
    return;
    // 0x8041D6D0: addiu       $v0, $v0, -0x28F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(29, 0XA8));
;}
RECOMP_FUNC void func_80741C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80741C34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80741C38: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80741C3C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80741C40: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80741C44: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80741C48: sh          $zero, -0x6DB8($at)
    MEM_H(-0X6DB8, ctx->r1) = 0;
    // 0x80741C4C: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x80741C50: sh          $zero, 0x13AA($v0)
    MEM_H(0X13AA, ctx->r2) = 0;
    // 0x80741C54: sh          $zero, 0x13AC($v0)
    MEM_H(0X13AC, ctx->r2) = 0;
    // 0x80741C58: sh          $zero, 0x13AE($v0)
    MEM_H(0X13AE, ctx->r2) = 0;
    // 0x80741C5C: sh          $zero, 0x13A8($v0)
    MEM_H(0X13A8, ctx->r2) = 0;
    // 0x80741C60: ori         $t1, $zero, 0x4
    ctx->r9 = 0 | 0X4;
    // 0x80741C64: sb          $zero, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = 0;
    // 0x80741C68: ori         $t4, $t1, 0x10
    ctx->r12 = ctx->r9 | 0X10;
    // 0x80741C6C: sb          $t1, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r9;
    // 0x80741C70: ori         $t7, $t4, 0x20
    ctx->r15 = ctx->r12 | 0X20;
    // 0x80741C74: sb          $t4, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r12;
    // 0x80741C78: ori         $t0, $t7, 0x2
    ctx->r8 = ctx->r15 | 0X2;
    // 0x80741C7C: lbu         $t5, 0x13B4($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X13B4);
    // 0x80741C80: sb          $t7, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r15;
    // 0x80741C84: ori         $t3, $t0, 0x1
    ctx->r11 = ctx->r8 | 0X1;
    // 0x80741C88: sb          $t0, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r8;
    // 0x80741C8C: sb          $t3, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r11;
    // 0x80741C90: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x80741C94: lbu         $t1, 0x13B5($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X13B5);
    // 0x80741C98: andi        $t3, $t5, 0xFF1F
    ctx->r11 = ctx->r13 & 0XFF1F;
    // 0x80741C9C: lbu         $t7, 0x13B3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X13B3);
    // 0x80741CA0: andi        $t5, $t3, 0xE7
    ctx->r13 = ctx->r11 & 0XE7;
    // 0x80741CA4: sb          $t3, 0x13B4($v1)
    MEM_B(0X13B4, ctx->r3) = ctx->r11;
    // 0x80741CA8: sb          $t5, 0x13B4($v1)
    MEM_B(0X13B4, ctx->r3) = ctx->r13;
    // 0x80741CAC: andi        $t6, $t5, 0xF9
    ctx->r14 = ctx->r13 & 0XF9;
    // 0x80741CB0: andi        $t2, $t1, 0xFFF8
    ctx->r10 = ctx->r9 & 0XFFF8;
    // 0x80741CB4: sb          $t2, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r10;
    // 0x80741CB8: sb          $t6, 0x13B4($v1)
    MEM_B(0X13B4, ctx->r3) = ctx->r14;
    // 0x80741CBC: andi        $t9, $t7, 0xFFCF
    ctx->r25 = ctx->r15 & 0XFFCF;
    // 0x80741CC0: lhu         $t7, 0x13B4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X13B4);
    // 0x80741CC4: sb          $t9, 0x13B3($v1)
    MEM_B(0X13B3, ctx->r3) = ctx->r25;
    // 0x80741CC8: andi        $t0, $t9, 0x3F
    ctx->r8 = ctx->r25 & 0X3F;
    // 0x80741CCC: andi        $t8, $t7, 0xFE7F
    ctx->r24 = ctx->r15 & 0XFE7F;
    // 0x80741CD0: sh          $t8, 0x13B4($v1)
    MEM_H(0X13B4, ctx->r3) = ctx->r24;
    // 0x80741CD4: lbu         $t9, 0x13B5($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X13B5);
    // 0x80741CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80741CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80741CE0: andi        $t1, $t9, 0xFF9F
    ctx->r9 = ctx->r25 & 0XFF9F;
    // 0x80741CE4: sb          $t1, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r9;
    // 0x80741CE8: andi        $t2, $t1, 0xE7
    ctx->r10 = ctx->r9 & 0XE7;
    // 0x80741CEC: sb          $t4, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r12;
    // 0x80741CF0: sb          $t0, 0x13B3($v1)
    MEM_B(0X13B3, ctx->r3) = ctx->r8;
    // 0x80741CF4: jal         0x8006988C
    // 0x80741CF8: sb          $t2, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r10;
    func_8006988C(rdram, ctx);
        goto after_0;
    // 0x80741CF8: sb          $t2, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r10;
    after_0:
    // 0x80741CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80741D00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80741D04: jr          $ra
    // 0x80741D08: nop

    return;
    // 0x80741D08: nop

;}
RECOMP_FUNC void func_805E41AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E41AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805E41B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E41B4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E41B8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805E41BC: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x805E41C0: lh          $a1, 0xA($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XA);
    // 0x805E41C4: beql        $a1, $at, L_805E4200
    if (ctx->r5 == ctx->r1) {
        // 0x805E41C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805E4200;
    }
    goto skip_0;
    // 0x805E41C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805E41CC: jal         0x80067930
    // 0x805E41D0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x805E41D0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805E41D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805E41D8: bne         $v0, $at, L_805E41F4
    if (ctx->r2 != ctx->r1) {
        // 0x805E41DC: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_805E41F4;
    }
    // 0x805E41DC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805E41E0: lh          $a1, 0xA($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XA);
    // 0x805E41E4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x805E41E8: jal         0x80067878
    // 0x805E41EC: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x805E41EC: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_1:
    // 0x805E41F0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_805E41F4:
    // 0x805E41F4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x805E41F8: sh          $t6, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r14;
    // 0x805E41FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805E4200:
    // 0x805E4200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805E4204: jr          $ra
    // 0x805E4208: nop

    return;
    // 0x805E4208: nop

;}
RECOMP_FUNC void func_8069CBE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069CBE4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8069CBE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8069CBEC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8069CBF0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8069CBF4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8069CBF8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8069CBFC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8069CC00: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8069CC04: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8069CC08: lui         $t1, 0x806A
    ctx->r9 = S32(RELOC_HI16(568, 0X4B0) << 16);
    // 0x8069CC0C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8069CC10: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8069CC14: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8069CC18: lw          $t1, -0x33B0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(568, 0X4B0));
    // 0x8069CC1C: jr          $ra
    // 0x8069CC20: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8069CC20: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8069CC24: nop

    // 0x8069CC28: nop

    // 0x8069CC2C: nop

;}
RECOMP_FUNC void func_80042F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042F50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042F58: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80042F5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80042F60: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80042F64: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80042F68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80042F6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80042F70: jal         0x80053924
    // 0x80042F74: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    func_80053924(rdram, ctx);
        goto after_0;
    // 0x80042F74: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x80042F78: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80042F7C: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x80042F80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042F84: lbu         $v1, 0x22($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X22);
    // 0x80042F88: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80042F8C: beq         $v1, $at, L_80042FA4
    if (ctx->r3 == ctx->r1) {
        // 0x80042F90: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80042FA4;
    }
    // 0x80042F90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80042F94: beq         $v1, $at, L_8004301C
    if (ctx->r3 == ctx->r1) {
        // 0x80042F98: lhu         $v0, 0x1E($sp)
        ctx->r2 = MEM_HU(ctx->r29, 0X1E);
            goto L_8004301C;
    }
    // 0x80042F98: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
    // 0x80042F9C: b           L_80043094
    // 0x80042FA0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_80043094;
    // 0x80042FA0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80042FA4:
    // 0x80042FA4: beq         $v0, $zero, L_80043008
    if (ctx->r2 == 0) {
        // 0x80042FA8: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80043008;
    }
    // 0x80042FA8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80042FAC: beq         $v0, $at, L_80043008
    if (ctx->r2 == ctx->r1) {
        // 0x80042FB0: lbu         $a0, 0x1E($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X1E);
            goto L_80043008;
    }
    // 0x80042FB0: lbu         $a0, 0x1E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1E);
    // 0x80042FB4: andi        $v1, $a0, 0xF8
    ctx->r3 = ctx->r4 & 0XF8;
    // 0x80042FB8: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80042FBC: beq         $v1, $at, L_80043008
    if (ctx->r3 == ctx->r1) {
        // 0x80042FC0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80043008;
    }
    // 0x80042FC0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80042FC4: beql        $v1, $at, L_8004300C
    if (ctx->r3 == ctx->r1) {
        // 0x80042FC8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8004300C;
    }
    goto skip_0;
    // 0x80042FC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x80042FCC: lw          $t6, 0x174($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X174);
    // 0x80042FD0: xori        $t7, $v1, 0x28
    ctx->r15 = ctx->r3 ^ 0X28;
    // 0x80042FD4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80042FD8: lbu         $v0, 0x10($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X10);
    // 0x80042FDC: andi        $t0, $a0, 0x1
    ctx->r8 = ctx->r4 & 0X1;
    // 0x80042FE0: beq         $v0, $zero, L_80042FF0
    if (ctx->r2 == 0) {
        // 0x80042FE4: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80042FF0;
    }
    // 0x80042FE4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80042FE8: bnel        $t7, $t8, L_8004300C
    if (ctx->r15 != ctx->r24) {
        // 0x80042FEC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8004300C;
    }
    goto skip_1;
    // 0x80042FEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_1:
L_80042FF0:
    // 0x80042FF0: beq         $t0, $zero, L_80043008
    if (ctx->r8 == 0) {
        // 0x80042FF4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80043008;
    }
    // 0x80042FF4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80042FF8: jal         0x80042E2C
    // 0x80042FFC: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    func_80042E2C(rdram, ctx);
        goto after_1;
    // 0x80042FFC: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_1:
    // 0x80043000: b           L_800430A0
    // 0x80043004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800430A0;
    // 0x80043004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80043008:
    // 0x80043008: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8004300C:
    // 0x8004300C: jal         0x80042F10
    // 0x80043010: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80042F10(rdram, ctx);
        goto after_2;
    // 0x80043010: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x80043014: b           L_800430A0
    // 0x80043018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800430A0;
    // 0x80043018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004301C:
    // 0x8004301C: beq         $v0, $zero, L_80043080
    if (ctx->r2 == 0) {
        // 0x80043020: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80043080;
    }
    // 0x80043020: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80043024: beq         $v0, $at, L_80043080
    if (ctx->r2 == ctx->r1) {
        // 0x80043028: lbu         $a0, 0x1E($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X1E);
            goto L_80043080;
    }
    // 0x80043028: lbu         $a0, 0x1E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1E);
    // 0x8004302C: andi        $v1, $a0, 0xF8
    ctx->r3 = ctx->r4 & 0XF8;
    // 0x80043030: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80043034: beq         $v1, $at, L_80043080
    if (ctx->r3 == ctx->r1) {
        // 0x80043038: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80043080;
    }
    // 0x80043038: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004303C: beql        $v1, $at, L_80043084
    if (ctx->r3 == ctx->r1) {
        // 0x80043040: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80043084;
    }
    goto skip_2;
    // 0x80043040: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_2:
    // 0x80043044: lw          $t1, 0x174($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X174);
    // 0x80043048: xori        $t2, $v1, 0x28
    ctx->r10 = ctx->r3 ^ 0X28;
    // 0x8004304C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80043050: lbu         $v0, 0x10($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X10);
    // 0x80043054: andi        $t5, $a0, 0x1
    ctx->r13 = ctx->r4 & 0X1;
    // 0x80043058: beq         $v0, $zero, L_80043068
    if (ctx->r2 == 0) {
        // 0x8004305C: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_80043068;
    }
    // 0x8004305C: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80043060: bnel        $t2, $t3, L_80043084
    if (ctx->r10 != ctx->r11) {
        // 0x80043064: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80043084;
    }
    goto skip_3;
    // 0x80043064: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_3:
L_80043068:
    // 0x80043068: beq         $t5, $zero, L_80043080
    if (ctx->r13 == 0) {
        // 0x8004306C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80043080;
    }
    // 0x8004306C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80043070: jal         0x80042E2C
    // 0x80043074: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80042E2C(rdram, ctx);
        goto after_3;
    // 0x80043074: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x80043078: b           L_800430A0
    // 0x8004307C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800430A0;
    // 0x8004307C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80043080:
    // 0x80043080: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80043084:
    // 0x80043084: jal         0x80042F10
    // 0x80043088: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80042F10(rdram, ctx);
        goto after_4;
    // 0x80043088: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_4:
    // 0x8004308C: b           L_800430A0
    // 0x80043090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800430A0;
    // 0x80043090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80043094:
    // 0x80043094: jal         0x80042F10
    // 0x80043098: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80042F10(rdram, ctx);
        goto after_5;
    // 0x80043098: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_5:
    // 0x8004309C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800430A0:
    // 0x800430A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800430A4: jr          $ra
    // 0x800430A8: nop

    return;
    // 0x800430A8: nop

;}
RECOMP_FUNC void func_804F3680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F3684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F3688: jal         0x80062748
    // 0x804F368C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062748(rdram, ctx);
        goto after_0;
    // 0x804F368C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x804F3690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F3694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F3698: jr          $ra
    // 0x804F369C: nop

    return;
    // 0x804F369C: nop

;}
RECOMP_FUNC void func_8064C5D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C5D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C5DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064C5E0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8064C5E4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8064C5E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C5EC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8064C5F0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8064C5F4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8064C5F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064C5FC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8064C600: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8064C604: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8064C608: lui         $t2, 0x8065
    ctx->r10 = S32(RELOC_HI16(495, 0X33E8) << 16);
    // 0x8064C60C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8064C610: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8064C614: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8064C618: lw          $t2, -0x2B48($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(495, 0X33E8));
    // 0x8064C61C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064C620: jal         0x8064C3A0
    // 0x8064C624: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8064C3A0(rdram, ctx);
        goto after_0;
    // 0x8064C624: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8064C628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064C62C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C630: jr          $ra
    // 0x8064C634: nop

    return;
    // 0x8064C634: nop

;}
RECOMP_FUNC void func_804A51D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A51D4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804A51D8: lw          $t6, -0x720C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X720C);
    // 0x804A51DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A51E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A51E4: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x804A51E8: beq         $t7, $zero, L_804A5244
    if (ctx->r15 == 0) {
        // 0x804A51EC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_804A5244;
    }
    // 0x804A51EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804A51F0: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804A51F4: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804A51F8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x804A51FC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804A5200: lw          $v1, 0x6ED0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6ED0);
    // 0x804A5204: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x804A5208: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A520C: bne         $v1, $zero, L_804A523C
    if (ctx->r3 != 0) {
        // 0x804A5210: nop
    
            goto L_804A523C;
    }
    // 0x804A5210: nop

    // 0x804A5214: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x804A5218: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x804A521C: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x804A5220: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x804A5224: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x804A5228: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x804A522C: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x804A5230: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x804A5234: b           L_804A5244
    // 0x804A5238: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
        goto L_804A5244;
    // 0x804A5238: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_804A523C:
    // 0x804A523C: jal         0x804A4D74
    // 0x804A5240: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_804A4D74(rdram, ctx);
        goto after_0;
    // 0x804A5240: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_0:
L_804A5244:
    // 0x804A5244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A5248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A524C: jr          $ra
    // 0x804A5250: nop

    return;
    // 0x804A5250: nop

;}
RECOMP_FUNC void func_8005BA30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BA30: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005BA34: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005BA38: jr          $ra
    // 0x8005BA3C: addiu       $v0, $a0, -0x4001
    ctx->r2 = ADD32(ctx->r4, -0X4001);
    return;
    // 0x8005BA3C: addiu       $v0, $a0, -0x4001
    ctx->r2 = ADD32(ctx->r4, -0X4001);
;}
RECOMP_FUNC void func_80409810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409810: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80409814: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80409818: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8040981C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80409820: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80409824: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80409828: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x8040982C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80409830: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80409834: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80409838: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8040983C: nop

    // 0x80409840: bc1f        L_80409850
    if (!c1cs) {
        // 0x80409844: nop
    
            goto L_80409850;
    }
    // 0x80409844: nop

    // 0x80409848: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x8040984C: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
L_80409850:
    // 0x80409850: jr          $ra
    // 0x80409854: nop

    return;
    // 0x80409854: nop

;}
RECOMP_FUNC void func_80064850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064850: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80064854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064858: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006485C: jal         0x80050C8C
    // 0x80064860: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_80050C8C(rdram, ctx);
        goto after_0;
    // 0x80064860: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80064864: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80064868: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8006486C: jal         0x80064DD0
    // 0x80064870: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80064DD0(rdram, ctx);
        goto after_1;
    // 0x80064870: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_1:
    // 0x80064874: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80064878: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8006487C: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x80064880: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80064884: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80064888: jal         0x800675D0
    // 0x8006488C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x8006488C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_2:
    // 0x80064890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064894: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80064898: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006489C: jr          $ra
    // 0x800648A0: nop

    return;
    // 0x800648A0: nop

;}
RECOMP_FUNC void func_807417A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807417A4: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x807417A8: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x807417AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807417B0: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x807417B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807417B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807417BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807417C0: lb          $v0, 0x2($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X2);
    // 0x807417C4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807417C8: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(751, 0X1150) << 16);
    // 0x807417CC: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x807417D0: bne         $at, $zero, L_807417E0
    if (ctx->r1 != 0) {
        // 0x807417D4: slti        $at, $v0, 0x1F
        ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
            goto L_807417E0;
    }
    // 0x807417D4: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x807417D8: bne         $at, $zero, L_8074192C
    if (ctx->r1 != 0) {
        // 0x807417DC: nop
    
            goto L_8074192C;
    }
    // 0x807417DC: nop

L_807417E0:
    // 0x807417E0: lw          $t7, 0x1FB0($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(751, 0X1150));
    // 0x807417E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807417E8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X1150) << 16);
    // 0x807417EC: bnel        $t7, $zero, L_80741938
    if (ctx->r15 != 0) {
        // 0x807417F0: lhu         $v0, 0xC($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0XC);
            goto L_80741938;
    }
    goto skip_0;
    // 0x807417F0: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    skip_0:
    // 0x807417F4: bgez        $v0, L_80741894
    if (SIGNED(ctx->r2) >= 0) {
        // 0x807417F8: sw          $t8, 0x1FB0($at)
        MEM_W((int16_t)RELOC_LO16(751, 0X1150), ctx->r1) = ctx->r24;
            goto L_80741894;
    }
    // 0x807417F8: sw          $t8, 0x1FB0($at)
    MEM_W((int16_t)RELOC_LO16(751, 0X1150), ctx->r1) = ctx->r24;
    // 0x807417FC: lui         $t9, 0x8074
    ctx->r25 = S32(RELOC_HI16(751, 0X1154) << 16);
    // 0x80741800: lw          $t9, 0x1FB4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(751, 0X1154));
    // 0x80741804: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80741808: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8074180C: beq         $t9, $at, L_80741934
    if (ctx->r25 == ctx->r1) {
        // 0x80741810: lui         $at, 0x8074
        ctx->r1 = S32(RELOC_HI16(751, 0X1154) << 16);
            goto L_80741934;
    }
    // 0x80741810: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X1154) << 16);
    // 0x80741814: sw          $t0, 0x1FB4($at)
    MEM_W((int16_t)RELOC_LO16(751, 0X1154), ctx->r1) = ctx->r8;
    // 0x80741818: lw          $t1, 0xFB8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XFB8);
    // 0x8074181C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80741820: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80741824: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80741828: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x8074182C: bne         $t3, $zero, L_80741864
    if (ctx->r11 != 0) {
        // 0x80741830: addiu       $a3, $zero, 0x20
        ctx->r7 = ADD32(0, 0X20);
            goto L_80741864;
    }
    // 0x80741830: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80741834: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80741838: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8074183C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80741840: jal         0x8005C27C
    // 0x80741844: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x80741844: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_0:
    // 0x80741848: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8074184C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80741850: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x80741854: jal         0x8005C27C
    // 0x80741858: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x80741858: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_1:
    // 0x8074185C: b           L_80741884
    // 0x80741860: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
        goto L_80741884;
    // 0x80741860: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
L_80741864:
    // 0x80741864: jal         0x8005C27C
    // 0x80741868: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x80741868: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x8074186C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80741870: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80741874: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80741878: jal         0x8005C27C
    // 0x8074187C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x8074187C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_3:
    // 0x80741880: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
L_80741884:
    // 0x80741884: jal         0x80067818
    // 0x80741888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80741888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8074188C: b           L_807419C0
    // 0x80741890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807419C0;
    // 0x80741890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80741894:
    // 0x80741894: lui         $t4, 0x8074
    ctx->r12 = S32(RELOC_HI16(751, 0X1154) << 16);
    // 0x80741898: lw          $t4, 0x1FB4($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(751, 0X1154));
    // 0x8074189C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807418A0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x807418A4: beq         $t4, $at, L_80741934
    if (ctx->r12 == ctx->r1) {
        // 0x807418A8: lui         $at, 0x8074
        ctx->r1 = S32(RELOC_HI16(751, 0X1154) << 16);
            goto L_80741934;
    }
    // 0x807418A8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X1154) << 16);
    // 0x807418AC: sw          $t5, 0x1FB4($at)
    MEM_W((int16_t)RELOC_LO16(751, 0X1154), ctx->r1) = ctx->r13;
    // 0x807418B0: lw          $t6, 0xFB8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XFB8);
    // 0x807418B4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x807418B8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x807418BC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x807418C0: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x807418C4: bne         $t8, $zero, L_807418FC
    if (ctx->r24 != 0) {
        // 0x807418C8: addiu       $a3, $zero, 0x20
        ctx->r7 = ADD32(0, 0X20);
            goto L_807418FC;
    }
    // 0x807418C8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x807418CC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x807418D0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x807418D4: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x807418D8: jal         0x8005C27C
    // 0x807418DC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x807418DC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_5:
    // 0x807418E0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x807418E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807418E8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x807418EC: jal         0x8005C27C
    // 0x807418F0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_6;
    // 0x807418F0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_6:
    // 0x807418F4: b           L_8074191C
    // 0x807418F8: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
        goto L_8074191C;
    // 0x807418F8: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
L_807418FC:
    // 0x807418FC: jal         0x8005C27C
    // 0x80741900: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8005C27C(rdram, ctx);
        goto after_7;
    // 0x80741900: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_7:
    // 0x80741904: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80741908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8074190C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80741910: jal         0x8005C27C
    // 0x80741914: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_8;
    // 0x80741914: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_8:
    // 0x80741918: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
L_8074191C:
    // 0x8074191C: jal         0x80067818
    // 0x80741920: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x80741920: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80741924: b           L_807419C0
    // 0x80741928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807419C0;
    // 0x80741928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8074192C:
    // 0x8074192C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X1150) << 16);
    // 0x80741930: sw          $zero, 0x1FB0($at)
    MEM_W((int16_t)RELOC_LO16(751, 0X1150), ctx->r1) = 0;
L_80741934:
    // 0x80741934: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
L_80741938:
    // 0x80741938: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8074193C: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(751, 0X1154) << 16);
    // 0x80741940: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x80741944: beq         $t9, $at, L_80741958
    if (ctx->r25 == ctx->r1) {
        // 0x80741948: andi        $t0, $v0, 0x1000
        ctx->r8 = ctx->r2 & 0X1000;
            goto L_80741958;
    }
    // 0x80741948: andi        $t0, $v0, 0x1000
    ctx->r8 = ctx->r2 & 0X1000;
    // 0x8074194C: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80741950: bnel        $t0, $at, L_807419C0
    if (ctx->r8 != ctx->r1) {
        // 0x80741954: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807419C0;
    }
    goto skip_1;
    // 0x80741954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_80741958:
    // 0x80741958: lw          $t1, 0x1FB4($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(751, 0X1154));
    // 0x8074195C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80741960: addiu       $a0, $zero, 0x203
    ctx->r4 = ADD32(0, 0X203);
    // 0x80741964: bne         $t1, $at, L_80741988
    if (ctx->r9 != ctx->r1) {
        // 0x80741968: nop
    
            goto L_80741988;
    }
    // 0x80741968: nop

    // 0x8074196C: jal         0x8006D1C0
    // 0x80741970: nop

    func_8006D1C0(rdram, ctx);
        goto after_10;
    // 0x80741970: nop

    after_10:
    // 0x80741974: addiu       $a0, $zero, 0x205
    ctx->r4 = ADD32(0, 0X205);
    // 0x80741978: jal         0x80067818
    // 0x8074197C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_11;
    // 0x8074197C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80741980: b           L_80741990
    // 0x80741984: nop

        goto L_80741990;
    // 0x80741984: nop

L_80741988:
    // 0x80741988: jal         0x80067818
    // 0x8074198C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_12;
    // 0x8074198C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
L_80741990:
    // 0x80741990: lui         $t2, 0x8074
    ctx->r10 = S32(RELOC_HI16(751, 0X1154) << 16);
    // 0x80741994: lw          $t2, 0x1FB4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(751, 0X1154));
    // 0x80741998: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x8074199C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x807419A0: sw          $t2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r10;
    // 0x807419A4: lw          $v0, 0x1F4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X1F4);
    // 0x807419A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807419AC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x807419B0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x807419B4: jal         0x80741E44
    // 0x807419B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80741E44(rdram, ctx);
        goto after_13;
    // 0x807419B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_13:
    // 0x807419BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807419C0:
    // 0x807419C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807419C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807419C8: jr          $ra
    // 0x807419CC: nop

    return;
    // 0x807419CC: nop

;}
RECOMP_FUNC void func_805A6098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A609C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A60A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805A60A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A60A8: jal         0x80066DE4
    // 0x805A60AC: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x805A60AC: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x805A60B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805A60B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805A60B8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805A60BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A60C0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x805A60C4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x805A60C8: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(417, 0X152C) << 16);
    // 0x805A60CC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x805A60D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805A60D4: bc1fl       L_805A60E4
    if (!c1cs) {
        // 0x805A60D8: sll         $v0, $v0, 2
        ctx->r2 = S32(ctx->r2 << 2);
            goto L_805A60E4;
    }
    goto skip_0;
    // 0x805A60D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    skip_0:
    // 0x805A60DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805A60E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_805A60E4:
    // 0x805A60E4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x805A60E8: lwc1        $f8, 0x67EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(417, 0X152C));
    // 0x805A60EC: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(417, 0X1534) << 16);
    // 0x805A60F0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x805A60F4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x805A60F8: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x805A60FC: swc1        $f16, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f16.u32l;
    // 0x805A6100: lwc1        $f18, 0x67F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(417, 0X1534));
    // 0x805A6104: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x805A6108: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x805A610C: swc1        $f6, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f6.u32l;
    // 0x805A6110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A6114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A6118: jr          $ra
    // 0x805A611C: nop

    return;
    // 0x805A611C: nop

;}
RECOMP_FUNC void func_805C6E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C6E30: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C6E34: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805C6E38: lui         $at, 0x4420
    ctx->r1 = S32(0X4420 << 16);
    // 0x805C6E3C: lwc1        $f6, 0x180($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X180);
    // 0x805C6E40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C6E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805C6E48: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805C6E4C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C6E50: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x805C6E54: nop

    // 0x805C6E58: bc1f        L_805C6E70
    if (!c1cs) {
        // 0x805C6E5C: nop
    
            goto L_805C6E70;
    }
    // 0x805C6E5C: nop

    // 0x805C6E60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x805C6E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805C6E68: jr          $ra
    // 0x805C6E6C: swc1        $f10, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x805C6E6C: swc1        $f10, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f10.u32l;
L_805C6E70:
    // 0x805C6E70: jr          $ra
    // 0x805C6E74: nop

    return;
    // 0x805C6E74: nop

;}
RECOMP_FUNC void func_8042E824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042E828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E82C: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8042E830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8042E834: beq         $t6, $zero, L_8042E870
    if (ctx->r14 == 0) {
        // 0x8042E838: nop
    
            goto L_8042E870;
    }
    // 0x8042E838: nop

    // 0x8042E83C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042E840: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8042E844: jalr        $t9
    // 0x8042E848: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042E848: nop

    after_0:
    // 0x8042E84C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042E850: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8042E854: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8042E858: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8042E85C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8042E860: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8042E864: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8042E868: b           L_8042E870
    // 0x8042E86C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8042E870;
    // 0x8042E86C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8042E870:
    // 0x8042E870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042E874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042E878: jr          $ra
    // 0x8042E87C: nop

    return;
    // 0x8042E87C: nop

;}
RECOMP_FUNC void func_80438538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043853C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80438540: jal         0x804381F4
    // 0x80438544: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804381F4(rdram, ctx);
        goto after_0;
    // 0x80438544: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80438548: jal         0x80045BD8
    // 0x8043854C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8043854C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80438550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80438554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80438558: jr          $ra
    // 0x8043855C: nop

    return;
    // 0x8043855C: nop

;}
RECOMP_FUNC void func_8000F984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F984: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8000F988: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000F98C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000F990: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000F994: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000F998: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000F99C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000F9A0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000F9A4: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8000F9A8: beql        $t7, $zero, L_80010114
    if (ctx->r15 == 0) {
        // 0x8000F9AC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80010114;
    }
    goto skip_0;
    // 0x8000F9AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8000F9B0: jal         0x800066E4
    // 0x8000F9B4: lbu         $a0, 0x4($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4);
    func_800066E4(rdram, ctx);
        goto after_0;
    // 0x8000F9B4: lbu         $a0, 0x4($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4);
    after_0:
    // 0x8000F9B8: beq         $v0, $zero, L_8000F9D0
    if (ctx->r2 == 0) {
        // 0x8000F9BC: nop
    
            goto L_8000F9D0;
    }
    // 0x8000F9BC: nop

    // 0x8000F9C0: jal         0x800066A8
    // 0x8000F9C4: lbu         $a0, 0x5($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X5);
    func_800066A8(rdram, ctx);
        goto after_1;
    // 0x8000F9C4: lbu         $a0, 0x5($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X5);
    after_1:
    // 0x8000F9C8: bne         $v0, $zero, L_8000F9E0
    if (ctx->r2 != 0) {
        // 0x8000F9CC: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8000F9E0;
    }
    // 0x8000F9CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8000F9D0:
    // 0x8000F9D0: jal         0x8000DAE8
    // 0x8000F9D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DAE8(rdram, ctx);
        goto after_2;
    // 0x8000F9D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8000F9D8: b           L_80010114
    // 0x8000F9DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80010114;
    // 0x8000F9DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000F9E0:
    // 0x8000F9E0: jal         0x8000678C
    // 0x8000F9E4: lbu         $a0, 0x4($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X4);
    func_8000678C(rdram, ctx);
        goto after_3;
    // 0x8000F9E4: lbu         $a0, 0x4($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X4);
    after_3:
    // 0x8000F9E8: lbu         $a0, 0x5($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X5);
    // 0x8000F9EC: jal         0x8000675C
    // 0x8000F9F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8000675C(rdram, ctx);
        goto after_4;
    // 0x8000F9F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8000F9F4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8000F9F8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000F9FC: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8000FA00: bgezl       $t0, L_8000FA1C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8000FA04: lhu         $t5, 0xA($s2)
        ctx->r13 = MEM_HU(ctx->r18, 0XA);
            goto L_8000FA1C;
    }
    goto skip_1;
    // 0x8000FA04: lhu         $t5, 0xA($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0XA);
    skip_1:
    // 0x8000FA08: lbu         $t1, 0x3($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X3);
    // 0x8000FA0C: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x8000FA10: bnel        $t2, $zero, L_80010114
    if (ctx->r10 != 0) {
        // 0x8000FA14: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80010114;
    }
    goto skip_2;
    // 0x8000FA14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x8000FA18: lhu         $t5, 0xA($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0XA);
L_8000FA1C:
    // 0x8000FA1C: lhu         $t6, 0x8($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X8);
    // 0x8000FA20: lw          $t3, 0xDC($s2)
    ctx->r11 = MEM_W(ctx->r18, 0XDC);
    // 0x8000FA24: lh          $t9, 0xC($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XC);
    // 0x8000FA28: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x8000FA2C: sh          $t8, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r24;
    // 0x8000FA30: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8000FA34: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8000FA38: sw          $t4, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r12;
    // 0x8000FA3C: sh          $t0, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r8;
    // 0x8000FA40: lh          $a0, 0x6AC0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6AC0);
    // 0x8000FA44: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x8000FA48: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000FA4C: bnel        $at, $zero, L_80010114
    if (ctx->r1 != 0) {
        // 0x8000FA50: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80010114;
    }
    goto skip_3;
    // 0x8000FA50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x8000FA54: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8000FA58: subu        $t2, $v0, $a0
    ctx->r10 = SUB32(ctx->r2, ctx->r4);
    // 0x8000FA5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000FA60: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8000FA64: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x8000FA68: beq         $t5, $at, L_80010110
    if (ctx->r13 == ctx->r1) {
        // 0x8000FA6C: sh          $t2, 0xA($s2)
        MEM_H(0XA, ctx->r18) = ctx->r10;
            goto L_80010110;
    }
    // 0x8000FA6C: sh          $t2, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r10;
    // 0x8000FA70: lhu         $v0, 0x10($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X10);
    // 0x8000FA74: addiu       $s1, $s2, 0x74
    ctx->r17 = ADD32(ctx->r18, 0X74);
    // 0x8000FA78: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000FA7C: bne         $at, $zero, L_8000FA8C
    if (ctx->r1 != 0) {
        // 0x8000FA80: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8000FA8C;
    }
    // 0x8000FA80: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8000FA84: b           L_800100D8
    // 0x8000FA88: sh          $t6, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r14;
        goto L_800100D8;
    // 0x8000FA88: sh          $t6, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r14;
L_8000FA8C:
    // 0x8000FA8C: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x8000FA90: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8000FA94: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8000FA98: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x8000FA9C: sb          $t9, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r25;
L_8000FAA0:
    // 0x8000FAA0: jal         0x8000DCB4
    // 0x8000FAA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_5;
    // 0x8000FAA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8000FAA8: slti        $at, $v0, 0xF2
    ctx->r1 = SIGNED(ctx->r2) < 0XF2 ? 1 : 0;
    // 0x8000FAAC: bne         $at, $zero, L_8000FB00
    if (ctx->r1 != 0) {
        // 0x8000FAB0: andi        $s0, $v0, 0xFF
        ctx->r16 = ctx->r2 & 0XFF;
            goto L_8000FB00;
    }
    // 0x8000FAB0: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x8000FAB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000FAB8: jal         0x8000D330
    // 0x8000FABC: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    func_8000D330(rdram, ctx);
        goto after_6;
    // 0x8000FABC: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_6:
    // 0x8000FAC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000FAC4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000FAC8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8000FACC: jal         0x8000D398
    // 0x8000FAD0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_8000D398(rdram, ctx);
        goto after_7;
    // 0x8000FAD0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_7:
    // 0x8000FAD4: beq         $v0, $zero, L_8000FAA0
    if (ctx->r2 == 0) {
        // 0x8000FAD8: nop
    
            goto L_8000FAA0;
    }
    // 0x8000FAD8: nop

    // 0x8000FADC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000FAE0: bne         $v0, $at, L_8000FAF8
    if (ctx->r2 != ctx->r1) {
        // 0x8000FAE4: nop
    
            goto L_8000FAF8;
    }
    // 0x8000FAE4: nop

    // 0x8000FAE8: jal         0x8000DAE8
    // 0x8000FAEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DAE8(rdram, ctx);
        goto after_8;
    // 0x8000FAEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x8000FAF0: b           L_800100DC
    // 0x8000FAF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800100DC;
    // 0x8000FAF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000FAF8:
    // 0x8000FAF8: b           L_800100D8
    // 0x8000FAFC: sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
        goto L_800100D8;
    // 0x8000FAFC: sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
L_8000FB00:
    // 0x8000FB00: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8000FB04: slti        $at, $v1, 0xC0
    ctx->r1 = SIGNED(ctx->r3) < 0XC0 ? 1 : 0;
    // 0x8000FB08: bne         $at, $zero, L_8000FF4C
    if (ctx->r1 != 0) {
        // 0x8000FB0C: andi        $v0, $v1, 0xF0
        ctx->r2 = ctx->r3 & 0XF0;
            goto L_8000FF4C;
    }
    // 0x8000FB0C: andi        $v0, $v1, 0xF0
    ctx->r2 = ctx->r3 & 0XF0;
    // 0x8000FB10: addiu       $t0, $v1, -0xC5
    ctx->r8 = ADD32(ctx->r3, -0XC5);
    // 0x8000FB14: sltiu       $at, $t0, 0x2D
    ctx->r1 = ctx->r8 < 0X2D ? 1 : 0;
    // 0x8000FB18: beq         $at, $zero, L_8000FAA0
    if (ctx->r1 == 0) {
        // 0x8000FB1C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8000FAA0;
    }
    // 0x8000FB1C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8000FB20: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000FB24: addu        $at, $at, $t0
    gpr jr_addend_8000FB2C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8000FB28: lw          $t0, -0x3ED0($at)
    ctx->r8 = ADD32(ctx->r1, -0X3ED0);
    // 0x8000FB2C: jr          $t0
    // 0x8000FB30: nop

    switch (jr_addend_8000FB2C >> 2) {
        case 0: goto L_8000FF38; break;
        case 1: goto L_8000FF28; break;
        case 2: goto L_8000FEF8; break;
        case 3: goto L_8000FEE0; break;
        case 4: goto L_8000FEC8; break;
        case 5: goto L_8000FAA0; break;
        case 6: goto L_8000FAA0; break;
        case 7: goto L_8000FEB8; break;
        case 8: goto L_8000FE40; break;
        case 9: goto L_8000FDF0; break;
        case 10: goto L_8000FAA0; break;
        case 11: goto L_8000FDE0; break;
        case 12: goto L_8000FDB4; break;
        case 13: goto L_8000FDB4; break;
        case 14: goto L_8000FDA4; break;
        case 15: goto L_8000FD94; break;
        case 16: goto L_8000FD6C; break;
        case 17: goto L_8000FD5C; break;
        case 18: goto L_8000FD40; break;
        case 19: goto L_8000FAA0; break;
        case 20: goto L_8000FD18; break;
        case 21: goto L_8000FC10; break;
        case 22: goto L_8000FC8C; break;
        case 23: goto L_8000FBEC; break;
        case 24: goto L_8000FB98; break;
        case 25: goto L_8000FB78; break;
        case 26: goto L_8000FB74; break;
        case 27: goto L_8000FAA0; break;
        case 28: goto L_8000FAA0; break;
        case 29: goto L_8000FAA0; break;
        case 30: goto L_8000FAA0; break;
        case 31: goto L_8000FAA0; break;
        case 32: goto L_8000FAA0; break;
        case 33: goto L_8000FAA0; break;
        case 34: goto L_8000FAA0; break;
        case 35: goto L_8000FAA0; break;
        case 36: goto L_8000FAA0; break;
        case 37: goto L_8000FAA0; break;
        case 38: goto L_8000FAA0; break;
        case 39: goto L_8000FAA0; break;
        case 40: goto L_8000FAA0; break;
        case 41: goto L_8000FAA0; break;
        case 42: goto L_8000FAA0; break;
        case 43: goto L_8000FB64; break;
        case 44: goto L_8000FB34; break;
        default: switch_error(__func__, 0x8000FB2C, 0x800AC130);
    }
    // 0x8000FB30: nop

L_8000FB34:
    // 0x8000FB34: addiu       $s0, $s2, 0x98
    ctx->r16 = ADD32(ctx->r18, 0X98);
    // 0x8000FB38: jal         0x8000BE94
    // 0x8000FB3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000BE94(rdram, ctx);
        goto after_9;
    // 0x8000FB3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8000FB40: jal         0x8000DCB4
    // 0x8000FB44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_10;
    // 0x8000FB44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8000FB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000FB4C: jal         0x8000BFF4
    // 0x8000FB50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8000BFF4(rdram, ctx);
        goto after_11;
    // 0x8000FB50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x8000FB54: b           L_8000FAA0
    // 0x8000FB58: nop

        goto L_8000FAA0;
    // 0x8000FB58: nop

    // 0x8000FB5C: b           L_8000FAA0
    // 0x8000FB60: nop

        goto L_8000FAA0;
    // 0x8000FB60: nop

L_8000FB64:
    // 0x8000FB64: jal         0x8000BE94
    // 0x8000FB68: addiu       $a0, $s2, 0x98
    ctx->r4 = ADD32(ctx->r18, 0X98);
    func_8000BE94(rdram, ctx);
        goto after_12;
    // 0x8000FB68: addiu       $a0, $s2, 0x98
    ctx->r4 = ADD32(ctx->r18, 0X98);
    after_12:
    // 0x8000FB6C: b           L_8000FAA0
    // 0x8000FB70: nop

        goto L_8000FAA0;
    // 0x8000FB70: nop

L_8000FB74:
    // 0x8000FB74: sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
L_8000FB78:
    // 0x8000FB78: jal         0x8000DCB4
    // 0x8000FB7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_13;
    // 0x8000FB7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8000FB80: lh          $t1, 0xE($s2)
    ctx->r9 = MEM_H(ctx->r18, 0XE);
    // 0x8000FB84: sll         $t2, $v0, 24
    ctx->r10 = S32(ctx->r2 << 24);
    // 0x8000FB88: sra         $t3, $t2, 24
    ctx->r11 = S32(SIGNED(ctx->r10) >> 24);
    // 0x8000FB8C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000FB90: b           L_8000FAA0
    // 0x8000FB94: sh          $t4, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r12;
        goto L_8000FAA0;
    // 0x8000FB94: sh          $t4, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r12;
L_8000FB98:
    // 0x8000FB98: jal         0x8000DCB4
    // 0x8000FB9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_14;
    // 0x8000FB9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8000FBA0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8000FBA4: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8000FBA8: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8000FBAC: sh          $t5, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r13;
    // 0x8000FBB0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000FBB4: lh          $a0, 0x6AC0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6AC0);
    // 0x8000FBB8: andi        $v1, $t5, 0xFFFF
    ctx->r3 = ctx->r13 & 0XFFFF;
    // 0x8000FBBC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000FBC0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000FBC4: beql        $at, $zero, L_8000FBD8
    if (ctx->r1 == 0) {
        // 0x8000FBC8: sll         $t6, $v1, 16
        ctx->r14 = S32(ctx->r3 << 16);
            goto L_8000FBD8;
    }
    goto skip_4;
    // 0x8000FBC8: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    skip_4:
    // 0x8000FBCC: sh          $a0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r4;
    // 0x8000FBD0: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8000FBD4: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
L_8000FBD8:
    // 0x8000FBD8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8000FBDC: bgtz        $t7, L_8000FAA0
    if (SIGNED(ctx->r15) > 0) {
        // 0x8000FBE0: nop
    
            goto L_8000FAA0;
    }
    // 0x8000FBE0: nop

    // 0x8000FBE4: b           L_8000FAA0
    // 0x8000FBE8: sh          $t8, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r24;
        goto L_8000FAA0;
    // 0x8000FBE8: sh          $t8, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r24;
L_8000FBEC:
    // 0x8000FBEC: jal         0x8000DCB4
    // 0x8000FBF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_15;
    // 0x8000FBF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x8000FBF4: sll         $t9, $v0, 24
    ctx->r25 = S32(ctx->r2 << 24);
    // 0x8000FBF8: sra         $t0, $t9, 24
    ctx->r8 = S32(SIGNED(ctx->r25) >> 24);
    // 0x8000FBFC: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8000FC00: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8000FC04: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8000FC08: b           L_8000FAA0
    // 0x8000FC0C: sh          $t2, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r10;
        goto L_8000FAA0;
    // 0x8000FC0C: sh          $t2, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r10;
L_8000FC10:
    // 0x8000FC10: jal         0x8000DCB4
    // 0x8000FC14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_16;
    // 0x8000FC14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x8000FC18: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x8000FC1C: jal         0x8000DCC8
    // 0x8000FC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_17;
    // 0x8000FC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x8000FC24: beq         $s0, $zero, L_8000FC48
    if (ctx->r16 == 0) {
        // 0x8000FC28: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8000FC48;
    }
    // 0x8000FC28: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8000FC2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000FC30: beq         $v1, $at, L_8000FC48
    if (ctx->r3 == ctx->r1) {
        // 0x8000FC34: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000FC48;
    }
    // 0x8000FC34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000FC38: beq         $v1, $at, L_8000FC64
    if (ctx->r3 == ctx->r1) {
        // 0x8000FC3C: andi        $t3, $v0, 0xFFFF
        ctx->r11 = ctx->r2 & 0XFFFF;
            goto L_8000FC64;
    }
    // 0x8000FC3C: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x8000FC40: b           L_8000FAA0
    // 0x8000FC44: nop

        goto L_8000FAA0;
    // 0x8000FC44: nop

L_8000FC48:
    // 0x8000FC48: lbu         $t1, 0x1($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X1);
    // 0x8000FC4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000FC50: beq         $t1, $at, L_8000FAA0
    if (ctx->r9 == ctx->r1) {
        // 0x8000FC54: nop
    
            goto L_8000FAA0;
    }
    // 0x8000FC54: nop

    // 0x8000FC58: sh          $v0, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r2;
    // 0x8000FC5C: b           L_8000FAA0
    // 0x8000FC60: sb          $s0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r16;
        goto L_8000FAA0;
    // 0x8000FC60: sb          $s0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r16;
L_8000FC64:
    // 0x8000FC64: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8000FC68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000FC6C: lwc1        $f6, 0x1C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8000FC70: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000FC74: sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // 0x8000FC78: sb          $s0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r16;
    // 0x8000FC7C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000FC80: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000FC84: b           L_8000FAA0
    // 0x8000FC88: swc1        $f18, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f18.u32l;
        goto L_8000FAA0;
    // 0x8000FC88: swc1        $f18, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f18.u32l;
L_8000FC8C:
    // 0x8000FC8C: jal         0x8000DCB4
    // 0x8000FC90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_18;
    // 0x8000FC90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x8000FC94: lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1);
    // 0x8000FC98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000FC9C: beql        $v1, $zero, L_8000FCCC
    if (ctx->r3 == 0) {
        // 0x8000FCA0: lhu         $v1, 0x14($s2)
        ctx->r3 = MEM_HU(ctx->r18, 0X14);
            goto L_8000FCCC;
    }
    goto skip_5;
    // 0x8000FCA0: lhu         $v1, 0x14($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X14);
    skip_5:
    // 0x8000FCA4: beq         $v1, $at, L_8000FCBC
    if (ctx->r3 == ctx->r1) {
        // 0x8000FCA8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000FCBC;
    }
    // 0x8000FCA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000FCAC: beq         $v1, $at, L_8000FAA0
    if (ctx->r3 == ctx->r1) {
        // 0x8000FCB0: nop
    
            goto L_8000FAA0;
    }
    // 0x8000FCB0: nop

    // 0x8000FCB4: b           L_8000FAA0
    // 0x8000FCB8: nop

        goto L_8000FAA0;
    // 0x8000FCB8: nop

L_8000FCBC:
    // 0x8000FCBC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000FCC0: sb          $zero, 0x1($s2)
    MEM_B(0X1, ctx->r18) = 0;
    // 0x8000FCC4: swc1        $f4, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f4.u32l;
    // 0x8000FCC8: lhu         $v1, 0x14($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X14);
L_8000FCCC:
    // 0x8000FCCC: beq         $v1, $zero, L_8000FD00
    if (ctx->r3 == 0) {
        // 0x8000FCD0: sh          $v1, 0x12($s2)
        MEM_H(0X12, ctx->r18) = ctx->r3;
            goto L_8000FD00;
    }
    // 0x8000FCD0: sh          $v1, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r3;
    // 0x8000FCD4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8000FCD8: andi        $t4, $v1, 0xFFFF
    ctx->r12 = ctx->r3 & 0XFFFF;
    // 0x8000FCDC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8000FCE0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000FCE4: lwc1        $f16, 0x1C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8000FCE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000FCEC: div.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8000FCF0: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8000FCF4: div.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8000FCF8: b           L_8000FAA0
    // 0x8000FCFC: swc1        $f10, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f10.u32l;
        goto L_8000FAA0;
    // 0x8000FCFC: swc1        $f10, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f10.u32l;
L_8000FD00:
    // 0x8000FD00: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8000FD04: nop

    // 0x8000FD08: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000FD0C: div.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8000FD10: b           L_8000FAA0
    // 0x8000FD14: swc1        $f4, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f4.u32l;
        goto L_8000FAA0;
    // 0x8000FD14: swc1        $f4, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f4.u32l;
L_8000FD18:
    // 0x8000FD18: jal         0x8000DCB4
    // 0x8000FD1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_19;
    // 0x8000FD1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x8000FD20: sll         $t5, $v0, 24
    ctx->r13 = S32(ctx->r2 << 24);
    // 0x8000FD24: sra         $t6, $t5, 24
    ctx->r14 = S32(SIGNED(ctx->r13) >> 24);
    // 0x8000FD28: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8000FD2C: nop

    // 0x8000FD30: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000FD34: div.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8000FD38: b           L_8000FAA0
    // 0x8000FD3C: swc1        $f10, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f10.u32l;
        goto L_8000FAA0;
    // 0x8000FD3C: swc1        $f10, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f10.u32l;
L_8000FD40:
    // 0x8000FD40: jal         0x8000DCC8
    // 0x8000FD44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_20;
    // 0x8000FD44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x8000FD48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000FD4C: jal         0x8000D8D8
    // 0x8000FD50: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    func_8000D8D8(rdram, ctx);
        goto after_21;
    // 0x8000FD50: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_21:
    // 0x8000FD54: b           L_8000FAA0
    // 0x8000FD58: nop

        goto L_8000FAA0;
    // 0x8000FD58: nop

L_8000FD5C:
    // 0x8000FD5C: jal         0x8000DCC8
    // 0x8000FD60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_22;
    // 0x8000FD60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x8000FD64: b           L_8000FAA0
    // 0x8000FD68: nop

        goto L_8000FAA0;
    // 0x8000FD68: nop

L_8000FD6C:
    // 0x8000FD6C: jal         0x8000DCB4
    // 0x8000FD70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_23;
    // 0x8000FD70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x8000FD74: sll         $t7, $v0, 24
    ctx->r15 = S32(ctx->r2 << 24);
    // 0x8000FD78: sra         $t8, $t7, 24
    ctx->r24 = S32(SIGNED(ctx->r15) >> 24);
    // 0x8000FD7C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8000FD80: nop

    // 0x8000FD84: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000FD88: div.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8000FD8C: b           L_8000FAA0
    // 0x8000FD90: swc1        $f4, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f4.u32l;
        goto L_8000FAA0;
    // 0x8000FD90: swc1        $f4, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f4.u32l;
L_8000FD94:
    // 0x8000FD94: lbu         $t0, 0x0($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X0);
    // 0x8000FD98: ori         $t2, $t0, 0x20
    ctx->r10 = ctx->r8 | 0X20;
    // 0x8000FD9C: b           L_8000FAA0
    // 0x8000FDA0: sb          $t2, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r10;
        goto L_8000FAA0;
    // 0x8000FDA0: sb          $t2, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r10;
L_8000FDA4:
    // 0x8000FDA4: jal         0x8000DCB4
    // 0x8000FDA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_24;
    // 0x8000FDA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_24:
    // 0x8000FDAC: b           L_8000FAA0
    // 0x8000FDB0: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
        goto L_8000FAA0;
    // 0x8000FDB0: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
L_8000FDB4:
    // 0x8000FDB4: jal         0x8000DCC8
    // 0x8000FDB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_25;
    // 0x8000FDB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x8000FDBC: lw          $t1, 0x18($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X18);
    // 0x8000FDC0: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x8000FDC4: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x8000FDC8: bne         $s0, $at, L_8000FDD8
    if (ctx->r16 != ctx->r1) {
        // 0x8000FDCC: addu        $v1, $t1, $t3
        ctx->r3 = ADD32(ctx->r9, ctx->r11);
            goto L_8000FDD8;
    }
    // 0x8000FDCC: addu        $v1, $t1, $t3
    ctx->r3 = ADD32(ctx->r9, ctx->r11);
    // 0x8000FDD0: b           L_8000FAA0
    // 0x8000FDD4: sw          $v1, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->r3;
        goto L_8000FAA0;
    // 0x8000FDD4: sw          $v1, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->r3;
L_8000FDD8:
    // 0x8000FDD8: b           L_8000FAA0
    // 0x8000FDDC: sw          $v1, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r3;
        goto L_8000FAA0;
    // 0x8000FDDC: sw          $v1, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->r3;
L_8000FDE0:
    // 0x8000FDE0: jal         0x8000DCB4
    // 0x8000FDE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_26;
    // 0x8000FDE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x8000FDE8: b           L_8000FAA0
    // 0x8000FDEC: sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
        goto L_8000FAA0;
    // 0x8000FDEC: sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
L_8000FDF0:
    // 0x8000FDF0: jal         0x8000DCB4
    // 0x8000FDF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_27;
    // 0x8000FDF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x8000FDF8: bne         $v0, $zero, L_8000FE14
    if (ctx->r2 != 0) {
        // 0x8000FDFC: lui         $t7, 0x800B
        ctx->r15 = S32(0X800B << 16);
            goto L_8000FE14;
    }
    // 0x8000FDFC: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8000FE00: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x8000FE04: lw          $t4, 0x6BA4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6BA4);
    // 0x8000FE08: srl         $t6, $t4, 2
    ctx->r14 = S32(U32(ctx->r12) >> 2);
    // 0x8000FE0C: b           L_8000FAA0
    // 0x8000FE10: sb          $t6, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r14;
        goto L_8000FAA0;
    // 0x8000FE10: sb          $t6, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r14;
L_8000FE14:
    // 0x8000FE14: lw          $t7, 0x6BA4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BA4);
    // 0x8000FE18: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8000FE1C: srl         $t8, $t7, 2
    ctx->r24 = S32(U32(ctx->r15) >> 2);
    // 0x8000FE20: divu        $zero, $t8, $t9
    lo = S32(U32(ctx->r24) / U32(ctx->r25)); hi = S32(U32(ctx->r24) % U32(ctx->r25));
    // 0x8000FE24: mfhi        $t0
    ctx->r8 = hi;
    // 0x8000FE28: sb          $t0, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r8;
    // 0x8000FE2C: bne         $t9, $zero, L_8000FE38
    if (ctx->r25 != 0) {
        // 0x8000FE30: nop
    
            goto L_8000FE38;
    }
    // 0x8000FE30: nop

    // 0x8000FE34: break       7
    do_break(2147548724);
L_8000FE38:
    // 0x8000FE38: b           L_8000FAA0
    // 0x8000FE3C: nop

        goto L_8000FAA0;
    // 0x8000FE3C: nop

L_8000FE40:
    // 0x8000FE40: jal         0x8000DCC8
    // 0x8000FE44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_28;
    // 0x8000FE44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_28:
    // 0x8000FE48: lb          $a1, 0x19($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X19);
    // 0x8000FE4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000FE50: beq         $a1, $at, L_8000FAA0
    if (ctx->r5 == ctx->r1) {
        // 0x8000FE54: nop
    
            goto L_8000FAA0;
    }
    // 0x8000FE54: nop

    // 0x8000FE58: lbu         $a2, 0x18($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X18);
    // 0x8000FE5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000FE60: andi        $t2, $v0, 0xFFFF
    ctx->r10 = ctx->r2 & 0XFFFF;
    // 0x8000FE64: beq         $a2, $at, L_8000FAA0
    if (ctx->r6 == ctx->r1) {
        // 0x8000FE68: sll         $t1, $a1, 1
        ctx->r9 = S32(ctx->r5 << 1);
            goto L_8000FAA0;
    }
    // 0x8000FE68: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x8000FE6C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8000FE70: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8000FE74: lw          $t4, 0x18($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X18);
    // 0x8000FE78: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8000FE7C: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8000FE80: lbu         $t8, 0x18($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X18);
    // 0x8000FE84: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x8000FE88: addu        $v0, $t4, $t3
    ctx->r2 = ADD32(ctx->r12, ctx->r11);
    // 0x8000FE8C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8000FE90: sb          $t9, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r25;
    // 0x8000FE94: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8000FE98: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x8000FE9C: lw          $t4, 0x18($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X18);
    // 0x8000FEA0: sll         $t1, $t2, 8
    ctx->r9 = S32(ctx->r10 << 8);
    // 0x8000FEA4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8000FEA8: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8000FEAC: addu        $t3, $t4, $v1
    ctx->r11 = ADD32(ctx->r12, ctx->r3);
    // 0x8000FEB0: b           L_8000FAA0
    // 0x8000FEB4: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
        goto L_8000FAA0;
    // 0x8000FEB4: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
L_8000FEB8:
    // 0x8000FEB8: jal         0x8000DCB4
    // 0x8000FEBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_29;
    // 0x8000FEBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
    // 0x8000FEC0: b           L_8000FAA0
    // 0x8000FEC4: sb          $v0, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r2;
        goto L_8000FAA0;
    // 0x8000FEC4: sb          $v0, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r2;
L_8000FEC8:
    // 0x8000FEC8: jal         0x8000DCB4
    // 0x8000FECC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_30;
    // 0x8000FECC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_30:
    // 0x8000FED0: lb          $t6, 0x19($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X19);
    // 0x8000FED4: and         $t5, $t6, $v0
    ctx->r13 = ctx->r14 & ctx->r2;
    // 0x8000FED8: b           L_8000FAA0
    // 0x8000FEDC: sb          $t5, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r13;
        goto L_8000FAA0;
    // 0x8000FEDC: sb          $t5, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r13;
L_8000FEE0:
    // 0x8000FEE0: jal         0x8000DCB4
    // 0x8000FEE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_31;
    // 0x8000FEE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_31:
    // 0x8000FEE8: lb          $t7, 0x19($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X19);
    // 0x8000FEEC: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x8000FEF0: b           L_8000FAA0
    // 0x8000FEF4: sb          $t8, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r24;
        goto L_8000FAA0;
    // 0x8000FEF4: sb          $t8, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r24;
L_8000FEF8:
    // 0x8000FEF8: jal         0x8000DCB4
    // 0x8000FEFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_32;
    // 0x8000FEFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_32:
    // 0x8000FF00: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x8000FF04: jal         0x8000DCC8
    // 0x8000FF08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_33;
    // 0x8000FF08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_33:
    // 0x8000FF0C: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x8000FF10: lbu         $t0, 0x19($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X19);
    // 0x8000FF14: andi        $t2, $v0, 0xFFFF
    ctx->r10 = ctx->r2 & 0XFFFF;
    // 0x8000FF18: addu        $a1, $t9, $t2
    ctx->r5 = ADD32(ctx->r25, ctx->r10);
    // 0x8000FF1C: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x8000FF20: b           L_8000FAA0
    // 0x8000FF24: sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
        goto L_8000FAA0;
    // 0x8000FF24: sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
L_8000FF28:
    // 0x8000FF28: lbu         $t3, 0x0($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X0);
    // 0x8000FF2C: ori         $t6, $t3, 0x2
    ctx->r14 = ctx->r11 | 0X2;
    // 0x8000FF30: b           L_80010110
    // 0x8000FF34: sb          $t6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r14;
        goto L_80010110;
    // 0x8000FF34: sb          $t6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r14;
L_8000FF38:
    // 0x8000FF38: jal         0x8000DCC8
    // 0x8000FF3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_34;
    // 0x8000FF3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_34:
    // 0x8000FF40: andi        $t5, $v0, 0xFFFF
    ctx->r13 = ctx->r2 & 0XFFFF;
    // 0x8000FF44: b           L_8000FAA0
    // 0x8000FF48: sw          $t5, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r13;
        goto L_8000FAA0;
    // 0x8000FF48: sw          $t5, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r13;
L_8000FF4C:
    // 0x8000FF4C: andi        $a0, $v1, 0xF
    ctx->r4 = ctx->r3 & 0XF;
    // 0x8000FF50: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x8000FF54: bne         $at, $zero, L_8000FF9C
    if (ctx->r1 != 0) {
        // 0x8000FF58: sb          $a0, 0x6E($sp)
        MEM_B(0X6E, ctx->r29) = ctx->r4;
            goto L_8000FF9C;
    }
    // 0x8000FF58: sb          $a0, 0x6E($sp)
    MEM_B(0X6E, ctx->r29) = ctx->r4;
    // 0x8000FF5C: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x8000FF60: bne         $at, $zero, L_8000FF88
    if (ctx->r1 != 0) {
        // 0x8000FF64: addiu       $t7, $v0, -0x40
        ctx->r15 = ADD32(ctx->r2, -0X40);
            goto L_8000FF88;
    }
    // 0x8000FF64: addiu       $t7, $v0, -0x40
    ctx->r15 = ADD32(ctx->r2, -0X40);
    // 0x8000FF68: sltiu       $at, $t7, 0x71
    ctx->r1 = ctx->r15 < 0X71 ? 1 : 0;
    // 0x8000FF6C: beq         $at, $zero, L_8000FAA0
    if (ctx->r1 == 0) {
        // 0x8000FF70: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8000FAA0;
    }
    // 0x8000FF70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000FF74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000FF78: addu        $at, $at, $t7
    gpr jr_addend_8000FF80 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8000FF7C: lw          $t7, -0x3E1C($at)
    ctx->r15 = ADD32(ctx->r1, -0X3E1C);
    // 0x8000FF80: jr          $t7
    // 0x8000FF84: nop

    switch (jr_addend_8000FF80 >> 2) {
        case 0: goto L_8001002C; break;
        case 1: goto L_8000FAA0; break;
        case 2: goto L_8000FAA0; break;
        case 3: goto L_8000FAA0; break;
        case 4: goto L_8000FAA0; break;
        case 5: goto L_8000FAA0; break;
        case 6: goto L_8000FAA0; break;
        case 7: goto L_8000FAA0; break;
        case 8: goto L_8000FAA0; break;
        case 9: goto L_8000FAA0; break;
        case 10: goto L_8000FAA0; break;
        case 11: goto L_8000FAA0; break;
        case 12: goto L_8000FAA0; break;
        case 13: goto L_8000FAA0; break;
        case 14: goto L_8000FAA0; break;
        case 15: goto L_8000FAA0; break;
        case 16: goto L_8000FFD8; break;
        case 17: goto L_8000FAA0; break;
        case 18: goto L_8000FAA0; break;
        case 19: goto L_8000FAA0; break;
        case 20: goto L_8000FAA0; break;
        case 21: goto L_8000FAA0; break;
        case 22: goto L_8000FAA0; break;
        case 23: goto L_8000FAA0; break;
        case 24: goto L_8000FAA0; break;
        case 25: goto L_8000FAA0; break;
        case 26: goto L_8000FAA0; break;
        case 27: goto L_8000FAA0; break;
        case 28: goto L_8000FAA0; break;
        case 29: goto L_8000FAA0; break;
        case 30: goto L_8000FAA0; break;
        case 31: goto L_8000FAA0; break;
        case 32: goto L_8000FAA0; break;
        case 33: goto L_8000FAA0; break;
        case 34: goto L_8000FAA0; break;
        case 35: goto L_8000FAA0; break;
        case 36: goto L_8000FAA0; break;
        case 37: goto L_8000FAA0; break;
        case 38: goto L_8000FAA0; break;
        case 39: goto L_8000FAA0; break;
        case 40: goto L_8000FAA0; break;
        case 41: goto L_8000FAA0; break;
        case 42: goto L_8000FAA0; break;
        case 43: goto L_8000FAA0; break;
        case 44: goto L_8000FAA0; break;
        case 45: goto L_8000FAA0; break;
        case 46: goto L_8000FAA0; break;
        case 47: goto L_8000FAA0; break;
        case 48: goto L_8000FFF4; break;
        case 49: goto L_8000FAA0; break;
        case 50: goto L_8000FAA0; break;
        case 51: goto L_8000FAA0; break;
        case 52: goto L_8000FAA0; break;
        case 53: goto L_8000FAA0; break;
        case 54: goto L_8000FAA0; break;
        case 55: goto L_8000FAA0; break;
        case 56: goto L_8000FAA0; break;
        case 57: goto L_8000FAA0; break;
        case 58: goto L_8000FAA0; break;
        case 59: goto L_8000FAA0; break;
        case 60: goto L_8000FAA0; break;
        case 61: goto L_8000FAA0; break;
        case 62: goto L_8000FAA0; break;
        case 63: goto L_8000FAA0; break;
        case 64: goto L_80010008; break;
        case 65: goto L_8000FAA0; break;
        case 66: goto L_8000FAA0; break;
        case 67: goto L_8000FAA0; break;
        case 68: goto L_8000FAA0; break;
        case 69: goto L_8000FAA0; break;
        case 70: goto L_8000FAA0; break;
        case 71: goto L_8000FAA0; break;
        case 72: goto L_8000FAA0; break;
        case 73: goto L_8000FAA0; break;
        case 74: goto L_8000FAA0; break;
        case 75: goto L_8000FAA0; break;
        case 76: goto L_8000FAA0; break;
        case 77: goto L_8000FAA0; break;
        case 78: goto L_8000FAA0; break;
        case 79: goto L_8000FAA0; break;
        case 80: goto L_80010048; break;
        case 81: goto L_8000FAA0; break;
        case 82: goto L_8000FAA0; break;
        case 83: goto L_8000FAA0; break;
        case 84: goto L_8000FAA0; break;
        case 85: goto L_8000FAA0; break;
        case 86: goto L_8000FAA0; break;
        case 87: goto L_8000FAA0; break;
        case 88: goto L_8000FAA0; break;
        case 89: goto L_8000FAA0; break;
        case 90: goto L_8000FAA0; break;
        case 91: goto L_8000FAA0; break;
        case 92: goto L_8000FAA0; break;
        case 93: goto L_8000FAA0; break;
        case 94: goto L_8000FAA0; break;
        case 95: goto L_8000FAA0; break;
        case 96: goto L_80010074; break;
        case 97: goto L_8000FAA0; break;
        case 98: goto L_8000FAA0; break;
        case 99: goto L_8000FAA0; break;
        case 100: goto L_8000FAA0; break;
        case 101: goto L_8000FAA0; break;
        case 102: goto L_8000FAA0; break;
        case 103: goto L_8000FAA0; break;
        case 104: goto L_8000FAA0; break;
        case 105: goto L_8000FAA0; break;
        case 106: goto L_8000FAA0; break;
        case 107: goto L_8000FAA0; break;
        case 108: goto L_8000FAA0; break;
        case 109: goto L_8000FAA0; break;
        case 110: goto L_8000FAA0; break;
        case 111: goto L_8000FAA0; break;
        case 112: goto L_8001009C; break;
        default: switch_error(__func__, 0x8000FF80, 0x800AC1E4);
    }
    // 0x8000FF84: nop

L_8000FF88:
    // 0x8000FF88: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8000FF8C: beq         $v0, $at, L_8000FAA0
    if (ctx->r2 == ctx->r1) {
        // 0x8000FF90: nop
    
            goto L_8000FAA0;
    }
    // 0x8000FF90: nop

    // 0x8000FF94: b           L_8000FAA0
    // 0x8000FF98: nop

        goto L_8000FAA0;
    // 0x8000FF98: nop

L_8000FF9C:
    // 0x8000FF9C: beq         $v0, $zero, L_8000FFB8
    if (ctx->r2 == 0) {
        // 0x8000FFA0: andi        $t8, $a0, 0xFF
        ctx->r24 = ctx->r4 & 0XFF;
            goto L_8000FFB8;
    }
    // 0x8000FFA0: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x8000FFA4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8000FFA8: beq         $v0, $at, L_8000FAA0
    if (ctx->r2 == ctx->r1) {
        // 0x8000FFAC: nop
    
            goto L_8000FAA0;
    }
    // 0x8000FFAC: nop

    // 0x8000FFB0: b           L_8000FAA0
    // 0x8000FFB4: nop

        goto L_8000FAA0;
    // 0x8000FFB4: nop

L_8000FFB8:
    // 0x8000FFB8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000FFBC: addu        $t2, $s2, $t9
    ctx->r10 = ADD32(ctx->r18, ctx->r25);
    // 0x8000FFC0: lw          $t0, 0x34($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X34);
    // 0x8000FFC4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000FFC8: srl         $t4, $t1, 31
    ctx->r12 = S32(U32(ctx->r9) >> 31);
    // 0x8000FFCC: xori        $t3, $t4, 0x1
    ctx->r11 = ctx->r12 ^ 0X1;
    // 0x8000FFD0: b           L_8000FAA0
    // 0x8000FFD4: sb          $t3, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r11;
        goto L_8000FAA0;
    // 0x8000FFD4: sb          $t3, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r11;
L_8000FFD8:
    // 0x8000FFD8: andi        $t5, $a0, 0xFF
    ctx->r13 = ctx->r4 & 0XFF;
    // 0x8000FFDC: addu        $t7, $s2, $t5
    ctx->r15 = ADD32(ctx->r18, ctx->r13);
    // 0x8000FFE0: lb          $t8, 0x154($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X154);
    // 0x8000FFE4: lb          $t6, 0x19($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X19);
    // 0x8000FFE8: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x8000FFEC: b           L_8000FAA0
    // 0x8000FFF0: sb          $t9, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r25;
        goto L_8000FAA0;
    // 0x8000FFF0: sb          $t9, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r25;
L_8000FFF4:
    // 0x8000FFF4: lb          $t2, 0x19($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X19);
    // 0x8000FFF8: andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
    // 0x8000FFFC: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x80010000: b           L_8000FAA0
    // 0x80010004: sb          $t2, 0x154($t1)
    MEM_B(0X154, ctx->r9) = ctx->r10;
        goto L_8000FAA0;
    // 0x80010004: sb          $t2, 0x154($t1)
    MEM_B(0X154, ctx->r9) = ctx->r10;
L_80010008:
    // 0x80010008: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8001000C: addu        $v1, $s2, $v0
    ctx->r3 = ADD32(ctx->r18, ctx->r2);
    // 0x80010010: lb          $t4, 0x154($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X154);
    // 0x80010014: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80010018: beq         $at, $zero, L_8000FAA0
    if (ctx->r1 == 0) {
        // 0x8001001C: sb          $t4, 0x19($s1)
        MEM_B(0X19, ctx->r17) = ctx->r12;
            goto L_8000FAA0;
    }
    // 0x8001001C: sb          $t4, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r12;
    // 0x80010020: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80010024: b           L_8000FAA0
    // 0x80010028: sb          $t3, 0x154($v1)
    MEM_B(0X154, ctx->r3) = ctx->r11;
        goto L_8000FAA0;
    // 0x80010028: sb          $t3, 0x154($v1)
    MEM_B(0X154, ctx->r3) = ctx->r11;
L_8001002C:
    // 0x8001002C: andi        $t7, $s0, 0xF
    ctx->r15 = ctx->r16 & 0XF;
    // 0x80010030: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80010034: addu        $t8, $s2, $t6
    ctx->r24 = ADD32(ctx->r18, ctx->r14);
    // 0x80010038: jal         0x8000D86C
    // 0x8001003C: lw          $a0, 0x34($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X34);
    func_8000D86C(rdram, ctx);
        goto after_35;
    // 0x8001003C: lw          $a0, 0x34($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X34);
    after_35:
    // 0x80010040: b           L_8000FAA0
    // 0x80010044: nop

        goto L_8000FAA0;
    // 0x80010044: nop

L_80010048:
    // 0x80010048: jal         0x8000DCC8
    // 0x8001004C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_36;
    // 0x8001004C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_36:
    // 0x80010050: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x80010054: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80010058: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x8001005C: andi        $a1, $a1, 0xF
    ctx->r5 = ctx->r5 & 0XF;
    // 0x80010060: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80010064: jal         0x8000DA50
    // 0x80010068: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    func_8000DA50(rdram, ctx);
        goto after_37;
    // 0x80010068: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    after_37:
    // 0x8001006C: b           L_8000FAA0
    // 0x80010070: nop

        goto L_8000FAA0;
    // 0x80010070: nop

L_80010074:
    // 0x80010074: jal         0x8000DCC8
    // 0x80010078: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_38;
    // 0x80010078: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_38:
    // 0x8001007C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80010080: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80010084: andi        $a1, $a1, 0xF
    ctx->r5 = ctx->r5 & 0XF;
    // 0x80010088: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8001008C: jal         0x8000DA50
    // 0x80010090: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
    func_8000DA50(rdram, ctx);
        goto after_39;
    // 0x80010090: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
    after_39:
    // 0x80010094: b           L_8000FAA0
    // 0x80010098: nop

        goto L_8000FAA0;
    // 0x80010098: nop

L_8001009C:
    // 0x8001009C: jal         0x8000DCB4
    // 0x800100A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_40;
    // 0x800100A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_40:
    // 0x800100A4: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800100A8: jal         0x8000DCC8
    // 0x800100AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_41;
    // 0x800100AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_41:
    // 0x800100B0: lbu         $t3, 0x6E($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X6E);
    // 0x800100B4: lw          $t1, 0x18($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X18);
    // 0x800100B8: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x800100BC: addu        $a2, $s2, $t3
    ctx->r6 = ADD32(ctx->r18, ctx->r11);
    // 0x800100C0: addiu       $a2, $a2, 0x154
    ctx->r6 = ADD32(ctx->r6, 0X154);
    // 0x800100C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800100C8: jal         0x8000859C
    // 0x800100CC: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    func_8000859C(rdram, ctx);
        goto after_42;
    // 0x800100CC: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    after_42:
    // 0x800100D0: b           L_8000FAA0
    // 0x800100D4: nop

        goto L_8000FAA0;
    // 0x800100D4: nop

L_800100D8:
    // 0x800100D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800100DC:
    // 0x800100DC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800100E0: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
L_800100E4:
    // 0x800100E4: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    // 0x800100E8: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800100EC: srl         $t7, $t5, 31
    ctx->r15 = S32(U32(ctx->r13) >> 31);
    // 0x800100F0: beql        $t7, $zero, L_80010108
    if (ctx->r15 == 0) {
        // 0x800100F4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80010108;
    }
    goto skip_6;
    // 0x800100F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_6:
    // 0x800100F8: jal         0x8000ED6C
    // 0x800100FC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8000ED6C(rdram, ctx);
        goto after_43;
    // 0x800100FC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_43:
    // 0x80010100: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80010104: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80010108:
    // 0x80010108: bne         $s0, $s1, L_800100E4
    if (ctx->r16 != ctx->r17) {
        // 0x8001010C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800100E4;
    }
    // 0x8001010C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80010110:
    // 0x80010110: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80010114:
    // 0x80010114: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80010118: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001011C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80010120: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80010124: jr          $ra
    // 0x80010128: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80010128: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8059F750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059F750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8059F754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059F758: jal         0x8004700C
    // 0x8059F75C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8059F75C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8059F760: beq         $v0, $zero, L_8059F7A0
    if (ctx->r2 == 0) {
        // 0x8059F764: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8059F7A0;
    }
    // 0x8059F764: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8059F768: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8059F76C: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8059F770: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8059F774: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8059F778: nop

    // 0x8059F77C: bc1fl       L_8059F798
    if (!c1cs) {
        // 0x8059F780: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8059F798;
    }
    goto skip_0;
    // 0x8059F780: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x8059F784: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8059F788: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8059F78C: b           L_8059F7B0
    // 0x8059F790: swc1        $f8, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f8.u32l;
        goto L_8059F7B0;
    // 0x8059F790: swc1        $f8, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f8.u32l;
    // 0x8059F794: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8059F798:
    // 0x8059F798: b           L_8059F7B0
    // 0x8059F79C: swc1        $f10, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f10.u32l;
        goto L_8059F7B0;
    // 0x8059F79C: swc1        $f10, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f10.u32l;
L_8059F7A0:
    // 0x8059F7A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8059F7A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8059F7A8: nop

    // 0x8059F7AC: swc1        $f16, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f16.u32l;
L_8059F7B0:
    // 0x8059F7B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8059F7B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8059F7B8: jr          $ra
    // 0x8059F7BC: nop

    return;
    // 0x8059F7BC: nop

;}
RECOMP_FUNC void func_8007FDBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FDBC: jr          $ra
    // 0x8007FDC0: nop

    return;
    // 0x8007FDC0: nop

;}
RECOMP_FUNC void func_8057C148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057C14C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057C150: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057C154: jal         0x8057BB68
    // 0x8057C158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8057BB68(rdram, ctx);
        goto after_0;
    // 0x8057C158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8057C15C: jal         0x8057BFE8
    // 0x8057C160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057BFE8(rdram, ctx);
        goto after_1;
    // 0x8057C160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8057C164: jal         0x8057BD84
    // 0x8057C168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057BD84(rdram, ctx);
        goto after_2;
    // 0x8057C168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8057C16C: jal         0x8057BE58
    // 0x8057C170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057BE58(rdram, ctx);
        goto after_3;
    // 0x8057C170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8057C174: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8057C178: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8057C17C: nop

    // 0x8057C180: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8057C184: nop

    // 0x8057C188: bc1fl       L_8057C19C
    if (!c1cs) {
        // 0x8057C18C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8057C19C;
    }
    goto skip_0;
    // 0x8057C18C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8057C190: jal         0x8057BE88
    // 0x8057C194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057BE88(rdram, ctx);
        goto after_4;
    // 0x8057C194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8057C198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8057C19C:
    // 0x8057C19C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057C1A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057C1A4: jr          $ra
    // 0x8057C1A8: nop

    return;
    // 0x8057C1A8: nop

;}
RECOMP_FUNC void func_80522AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80522AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80522ADC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80522AE0: lui         $t1, 0x8052
    ctx->r9 = S32(RELOC_HI16(321, 0X15EC) << 16);
    // 0x80522AE4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80522AE8: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80522AEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80522AF0: addiu       $t1, $t1, 0x389C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(321, 0X15EC));
    // 0x80522AF4: beq         $v0, $zero, L_80522B14
    if (ctx->r2 == 0) {
        // 0x80522AF8: lw          $a2, 0x0($v1)
        ctx->r6 = MEM_W(ctx->r3, 0X0);
            goto L_80522B14;
    }
    // 0x80522AF8: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80522AFC: beq         $v0, $at, L_80522C6C
    if (ctx->r2 == ctx->r1) {
        // 0x80522B00: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80522C6C;
    }
    // 0x80522B00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80522B04: beq         $v0, $at, L_80522D40
    if (ctx->r2 == ctx->r1) {
        // 0x80522B08: lui         $t2, 0x8052
        ctx->r10 = S32(RELOC_HI16(321, 0X15EC) << 16);
            goto L_80522D40;
    }
    // 0x80522B08: lui         $t2, 0x8052
    ctx->r10 = S32(RELOC_HI16(321, 0X15EC) << 16);
    // 0x80522B0C: b           L_80522E7C
    // 0x80522B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80522E7C;
    // 0x80522B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80522B14:
    // 0x80522B14: bnel        $a1, $zero, L_80522B38
    if (ctx->r5 != 0) {
        // 0x80522B18: lw          $t8, 0x18($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X18);
            goto L_80522B38;
    }
    goto skip_0;
    // 0x80522B18: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    skip_0:
    // 0x80522B1C: lw          $t6, 0x18($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18);
    // 0x80522B20: lui         $a0, 0x8052
    ctx->r4 = S32(RELOC_HI16(321, 0X1D0C) << 16);
    // 0x80522B24: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80522B28: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80522B2C: b           L_80522B48
    // 0x80522B30: lw          $a0, 0x3FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(321, 0X1D0C));
        goto L_80522B48;
    // 0x80522B30: lw          $a0, 0x3FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(321, 0X1D0C));
    // 0x80522B34: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
L_80522B38:
    // 0x80522B38: lui         $a0, 0x8052
    ctx->r4 = S32(RELOC_HI16(321, 0X1D5C) << 16);
    // 0x80522B3C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80522B40: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80522B44: lw          $a0, 0x400C($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(321, 0X1D5C));
L_80522B48:
    // 0x80522B48: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80522B4C: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80522B50: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80522B54: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80522B58: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80522B5C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80522B60: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80522B64: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80522B68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80522B6C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80522B70: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80522B74: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80522B78: swc1        $f16, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f16.u32l;
    // 0x80522B7C: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x80522B80: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80522B84: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80522B88: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80522B8C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80522B90: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80522B94: swc1        $f8, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f8.u32l;
    // 0x80522B98: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80522B9C: swc1        $f10, 0x6C($a3)
    MEM_W(0X6C, ctx->r7) = ctx->f10.u32l;
    // 0x80522BA0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80522BA4: swc1        $f16, 0x70($a3)
    MEM_W(0X70, ctx->r7) = ctx->f16.u32l;
    // 0x80522BA8: lw          $t4, 0x18($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X18);
    // 0x80522BAC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80522BB0: nop

    // 0x80522BB4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80522BB8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80522BBC: swc1        $f6, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f6.u32l;
    // 0x80522BC0: lw          $t5, 0x1C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C);
    // 0x80522BC4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80522BC8: nop

    // 0x80522BCC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80522BD0: swc1        $f10, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f10.u32l;
    // 0x80522BD4: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80522BD8: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x80522BDC: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80522BE0: bne         $a1, $zero, L_80522C04
    if (ctx->r5 != 0) {
        // 0x80522BE4: swc1        $f18, 0x70($a2)
        MEM_W(0X70, ctx->r6) = ctx->f18.u32l;
            goto L_80522C04;
    }
    // 0x80522BE4: swc1        $f18, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f18.u32l;
    // 0x80522BE8: lw          $t6, 0x18($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18);
    // 0x80522BEC: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(321, 0X1DA4) << 16);
    // 0x80522BF0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80522BF4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80522BF8: lw          $t8, 0x4054($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(321, 0X1DA4));
    // 0x80522BFC: b           L_80522C1C
    // 0x80522C00: sh          $t8, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r24;
        goto L_80522C1C;
    // 0x80522C00: sh          $t8, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r24;
L_80522C04:
    // 0x80522C04: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x80522C08: lui         $t1, 0x8052
    ctx->r9 = S32(RELOC_HI16(321, 0X1DF4) << 16);
    // 0x80522C0C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80522C10: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80522C14: lw          $t1, 0x40A4($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(321, 0X1DF4));
    // 0x80522C18: sh          $t1, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r9;
L_80522C1C:
    // 0x80522C1C: lw          $t2, 0x2C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C);
    // 0x80522C20: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80522C24: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80522C28: bnel        $t2, $zero, L_80522C3C
    if (ctx->r10 != 0) {
        // 0x80522C2C: sb          $t3, 0x165($a2)
        MEM_B(0X165, ctx->r6) = ctx->r11;
            goto L_80522C3C;
    }
    goto skip_1;
    // 0x80522C2C: sb          $t3, 0x165($a2)
    MEM_B(0X165, ctx->r6) = ctx->r11;
    skip_1:
    // 0x80522C30: b           L_80522C3C
    // 0x80522C34: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
        goto L_80522C3C;
    // 0x80522C34: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
    // 0x80522C38: sb          $t3, 0x165($a2)
    MEM_B(0X165, ctx->r6) = ctx->r11;
L_80522C3C:
    // 0x80522C3C: lw          $t4, 0x18($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X18);
    // 0x80522C40: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(321, 0X1E64) << 16);
    // 0x80522C44: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80522C48: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80522C4C: sw          $t5, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r13;
    // 0x80522C50: lw          $t7, 0x4114($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(321, 0X1E64));
    // 0x80522C54: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80522C58: beql        $at, $zero, L_80522E7C
    if (ctx->r1 == 0) {
        // 0x80522C5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80522E7C;
    }
    goto skip_2;
    // 0x80522C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80522C60: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x80522C64: b           L_80522E78
    // 0x80522C68: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
        goto L_80522E78;
    // 0x80522C68: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
L_80522C6C:
    // 0x80522C6C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80522C70: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80522C74: beq         $v0, $zero, L_80522C84
    if (ctx->r2 == 0) {
        // 0x80522C78: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80522C84;
    }
    // 0x80522C78: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80522C7C: sw          $t0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r8;
    // 0x80522C80: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80522C84:
    // 0x80522C84: bnel        $v0, $zero, L_80522CE0
    if (ctx->r2 != 0) {
        // 0x80522C88: lh          $t2, 0x144($a2)
        ctx->r10 = MEM_H(ctx->r6, 0X144);
            goto L_80522CE0;
    }
    goto skip_3;
    // 0x80522C88: lh          $t2, 0x144($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X144);
    skip_3:
    // 0x80522C8C: bne         $a1, $zero, L_80522CB0
    if (ctx->r5 != 0) {
        // 0x80522C90: sw          $t1, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r9;
            goto L_80522CB0;
    }
    // 0x80522C90: sw          $t1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r9;
    // 0x80522C94: lw          $t2, 0x18($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X18);
    // 0x80522C98: lui         $t4, 0x8052
    ctx->r12 = S32(RELOC_HI16(321, 0X1E44) << 16);
    // 0x80522C9C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80522CA0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80522CA4: lw          $t4, 0x40F4($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(321, 0X1E44));
    // 0x80522CA8: b           L_80522CC8
    // 0x80522CAC: sh          $t4, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r12;
        goto L_80522CC8;
    // 0x80522CAC: sh          $t4, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r12;
L_80522CB0:
    // 0x80522CB0: lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X18);
    // 0x80522CB4: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(321, 0X1E54) << 16);
    // 0x80522CB8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80522CBC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80522CC0: lw          $t7, 0x4104($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(321, 0X1E54));
    // 0x80522CC4: sh          $t7, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r15;
L_80522CC8:
    // 0x80522CC8: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x80522CCC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80522CD0: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x80522CD4: andi        $t1, $t9, 0x3
    ctx->r9 = ctx->r25 & 0X3;
    // 0x80522CD8: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    // 0x80522CDC: lh          $t2, 0x144($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X144);
L_80522CE0:
    // 0x80522CE0: lui         $t4, 0x8052
    ctx->r12 = S32(RELOC_HI16(321, 0X15EC) << 16);
    // 0x80522CE4: addiu       $t4, $t4, 0x389C
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(321, 0X15EC));
    // 0x80522CE8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80522CEC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80522CF0: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80522CF4: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80522CF8: lw          $t5, 0x18($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X18);
    // 0x80522CFC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80522D00: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80522D04: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80522D08: nop

    // 0x80522D0C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80522D10: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80522D14: swc1        $f8, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f8.u32l;
    // 0x80522D18: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x80522D1C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80522D20: nop

    // 0x80522D24: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80522D28: swc1        $f16, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f16.u32l;
    // 0x80522D2C: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80522D30: swc1        $f18, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f18.u32l;
    // 0x80522D34: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80522D38: b           L_80522E78
    // 0x80522D3C: swc1        $f4, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f4.u32l;
        goto L_80522E78;
    // 0x80522D3C: swc1        $f4, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f4.u32l;
L_80522D40:
    // 0x80522D40: bne         $a1, $zero, L_80522D60
    if (ctx->r5 != 0) {
        // 0x80522D44: addiu       $t2, $t2, 0x389C
        ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(321, 0X15EC));
            goto L_80522D60;
    }
    // 0x80522D44: addiu       $t2, $t2, 0x389C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(321, 0X15EC));
    // 0x80522D48: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x80522D4C: lui         $a0, 0x8052
    ctx->r4 = S32(RELOC_HI16(321, 0X1D0C) << 16);
    // 0x80522D50: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80522D54: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80522D58: b           L_80522D74
    // 0x80522D5C: lw          $a0, 0x3FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(321, 0X1D0C));
        goto L_80522D74;
    // 0x80522D5C: lw          $a0, 0x3FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(321, 0X1D0C));
L_80522D60:
    // 0x80522D60: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x80522D64: lui         $a0, 0x8052
    ctx->r4 = S32(RELOC_HI16(321, 0X1D5C) << 16);
    // 0x80522D68: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80522D6C: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80522D70: lw          $a0, 0x400C($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(321, 0X1D5C));
L_80522D74:
    // 0x80522D74: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80522D78: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80522D7C: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80522D80: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80522D84: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80522D88: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80522D8C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80522D90: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80522D94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80522D98: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80522D9C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80522DA0: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80522DA4: swc1        $f18, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f18.u32l;
    // 0x80522DA8: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80522DAC: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80522DB0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80522DB4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80522DB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80522DBC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80522DC0: swc1        $f10, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f10.u32l;
    // 0x80522DC4: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80522DC8: swc1        $f16, 0x6C($a3)
    MEM_W(0X6C, ctx->r7) = ctx->f16.u32l;
    // 0x80522DCC: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80522DD0: swc1        $f18, 0x70($a3)
    MEM_W(0X70, ctx->r7) = ctx->f18.u32l;
    // 0x80522DD4: lw          $t5, 0x18($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X18);
    // 0x80522DD8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80522DDC: nop

    // 0x80522DE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80522DE4: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80522DE8: swc1        $f8, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f8.u32l;
    // 0x80522DEC: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x80522DF0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80522DF4: nop

    // 0x80522DF8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80522DFC: swc1        $f16, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f16.u32l;
    // 0x80522E00: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80522E04: swc1        $f18, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f18.u32l;
    // 0x80522E08: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80522E0C: bne         $a1, $zero, L_80522E30
    if (ctx->r5 != 0) {
        // 0x80522E10: swc1        $f4, 0x70($a2)
        MEM_W(0X70, ctx->r6) = ctx->f4.u32l;
            goto L_80522E30;
    }
    // 0x80522E10: swc1        $f4, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f4.u32l;
    // 0x80522E14: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x80522E18: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(321, 0X1DA4) << 16);
    // 0x80522E1C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80522E20: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80522E24: lw          $t9, 0x4054($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(321, 0X1DA4));
    // 0x80522E28: b           L_80522E48
    // 0x80522E2C: sh          $t9, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r25;
        goto L_80522E48;
    // 0x80522E2C: sh          $t9, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r25;
L_80522E30:
    // 0x80522E30: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x80522E34: lui         $t2, 0x8052
    ctx->r10 = S32(RELOC_HI16(321, 0X1DF4) << 16);
    // 0x80522E38: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80522E3C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80522E40: lw          $t2, 0x40A4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(321, 0X1DF4));
    // 0x80522E44: sh          $t2, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r10;
L_80522E48:
    // 0x80522E48: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x80522E4C: bnel        $t3, $zero, L_80522E60
    if (ctx->r11 != 0) {
        // 0x80522E50: sb          $t4, 0x165($a2)
        MEM_B(0X165, ctx->r6) = ctx->r12;
            goto L_80522E60;
    }
    goto skip_4;
    // 0x80522E50: sb          $t4, 0x165($a2)
    MEM_B(0X165, ctx->r6) = ctx->r12;
    skip_4:
    // 0x80522E54: b           L_80522E60
    // 0x80522E58: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
        goto L_80522E60;
    // 0x80522E58: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
    // 0x80522E5C: sb          $t4, 0x165($a2)
    MEM_B(0X165, ctx->r6) = ctx->r12;
L_80522E60:
    // 0x80522E60: lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X18);
    // 0x80522E64: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80522E68: bgez        $t6, L_80522E78
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80522E6C: sw          $t6, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->r14;
            goto L_80522E78;
    }
    // 0x80522E6C: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
    // 0x80522E70: jal         0x800447C8
    // 0x80522E74: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80522E74: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
L_80522E78:
    // 0x80522E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80522E7C:
    // 0x80522E7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80522E80: jr          $ra
    // 0x80522E84: nop

    return;
    // 0x80522E84: nop

;}
RECOMP_FUNC void func_806D409C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D409C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D40A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D40A4: jal         0x806D3F68
    // 0x806D40A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_806D3F68(rdram, ctx);
        goto after_0;
    // 0x806D40A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D40AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D40B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806D40B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806D40B8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D40BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D40C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D40C4: sh          $t6, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r14;
    // 0x806D40C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x806D40CC: jal         0x806D414C
    // 0x806D40D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806D414C(rdram, ctx);
        goto after_1;
    // 0x806D40D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x806D40D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D40D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806D40DC: jal         0x806D30C4
    // 0x806D40E0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_806D30C4(rdram, ctx);
        goto after_2;
    // 0x806D40E0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_2:
    // 0x806D40E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D40E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D40EC: jr          $ra
    // 0x806D40F0: nop

    return;
    // 0x806D40F0: nop

;}
RECOMP_FUNC void func_8005BE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BE80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005BE84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BE88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005BE8C: beq         $a2, $zero, L_8005BEB4
    if (ctx->r6 == 0) {
        // 0x8005BE90: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8005BEB4;
    }
    // 0x8005BE90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005BE94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005BE98: beq         $a2, $at, L_8005BEE8
    if (ctx->r6 == ctx->r1) {
        // 0x8005BE9C: lw          $t1, 0x18($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X18);
            goto L_8005BEE8;
    }
    // 0x8005BE9C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8005BEA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005BEA4: beq         $a2, $at, L_8005BF18
    if (ctx->r6 == ctx->r1) {
        // 0x8005BEA8: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_8005BF18;
    }
    // 0x8005BEA8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005BEAC: b           L_8005BF44
    // 0x8005BEB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005BF44;
    // 0x8005BEB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005BEB4:
    // 0x8005BEB4: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    // 0x8005BEB8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005BEBC: lui         $t0, 0x319
    ctx->r8 = S32(0X319 << 16);
    // 0x8005BEC0: addiu       $t0, $t0, 0x555C
    ctx->r8 = ADD32(ctx->r8, 0X555C);
    // 0x8005BEC4: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8005BEC8: sll         $t9, $t8, 7
    ctx->r25 = S32(ctx->r24 << 7);
    // 0x8005BECC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x8005BED0: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x8005BED4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x8005BED8: jal         0x800675D0
    // 0x8005BEDC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800675D0(rdram, ctx);
        goto after_0;
    // 0x8005BEDC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8005BEE0: b           L_8005BF44
    // 0x8005BEE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005BF44;
    // 0x8005BEE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005BEE8:
    // 0x8005BEE8: lhu         $t3, 0x1E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X1E);
    // 0x8005BEEC: lui         $t5, 0x31A
    ctx->r13 = S32(0X31A << 16);
    // 0x8005BEF0: addiu       $t5, $t5, -0x2AA0
    ctx->r13 = ADD32(ctx->r13, -0X2AA0);
    // 0x8005BEF4: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8005BEF8: sll         $t4, $t3, 7
    ctx->r12 = S32(ctx->r11 << 7);
    // 0x8005BEFC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x8005BF00: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x8005BF04: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8005BF08: jal         0x800675D0
    // 0x8005BF0C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x8005BF0C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_1:
    // 0x8005BF10: b           L_8005BF44
    // 0x8005BF14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005BF44;
    // 0x8005BF14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005BF18:
    // 0x8005BF18: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    // 0x8005BF1C: lui         $t0, 0x31A
    ctx->r8 = S32(0X31A << 16);
    // 0x8005BF20: addiu       $t0, $t0, 0x5564
    ctx->r8 = ADD32(ctx->r8, 0X5564);
    // 0x8005BF24: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8005BF28: sll         $t9, $t8, 7
    ctx->r25 = S32(ctx->r24 << 7);
    // 0x8005BF2C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x8005BF30: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x8005BF34: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8005BF38: jal         0x800675D0
    // 0x8005BF3C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x8005BF3C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_2:
    // 0x8005BF40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005BF44:
    // 0x8005BF44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005BF48: jr          $ra
    // 0x8005BF4C: nop

    return;
    // 0x8005BF4C: nop

;}
RECOMP_FUNC void func_8044C260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044C260: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8044C264: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8044C268: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8044C26C: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x8044C270: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044C274: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8044C278: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8044C27C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8044C280: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_8044C284:
    // 0x8044C284: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8044C288: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8044C28C: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8044C290: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8044C294: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8044C298: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8044C29C: beq         $a0, $t3, L_8044C304
    if (ctx->r4 == ctx->r11) {
        // 0x8044C2A0: nop
    
            goto L_8044C304;
    }
    // 0x8044C2A0: nop

L_8044C2A4:
    // 0x8044C2A4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8044C2A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8044C2AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8044C2B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8044C2B4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8044C2B8: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8044C2BC: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8044C2C0: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x8044C2C4: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8044C2C8: srl         $t9, $t1, 16
    ctx->r25 = S32(U32(ctx->r9) >> 16);
    // 0x8044C2CC: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x8044C2D0: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x8044C2D4: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8044C2D8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8044C2DC: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x8044C2E0: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8044C2E4: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x8044C2E8: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8044C2EC: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x8044C2F0: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8044C2F4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8044C2F8: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8044C2FC: bne         $a0, $t3, L_8044C2A4
    if (ctx->r4 != ctx->r11) {
        // 0x8044C300: nop
    
            goto L_8044C2A4;
    }
    // 0x8044C300: nop

L_8044C304:
    // 0x8044C304: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8044C308: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8044C30C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8044C310: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8044C314: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8044C318: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8044C31C: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x8044C320: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8044C324: srl         $t9, $t1, 16
    ctx->r25 = S32(U32(ctx->r9) >> 16);
    // 0x8044C328: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x8044C32C: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x8044C330: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8044C334: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8044C338: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x8044C33C: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x8044C340: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8044C344: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8044C348: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x8044C34C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8044C350: bne         $a2, $t4, L_8044C284
    if (ctx->r6 != ctx->r12) {
        // 0x8044C354: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8044C284;
    }
    // 0x8044C354: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8044C358: jr          $ra
    // 0x8044C35C: nop

    return;
    // 0x8044C35C: nop

;}
RECOMP_FUNC void func_804547C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804547C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804547C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804547C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804547CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804547D0: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x804547D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804547D8: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x804547DC: lw          $v0, 0xA5C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA5C);
    // 0x804547E0: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x804547E4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x804547E8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x804547EC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x804547F0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x804547F4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x804547F8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x804547FC: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454800: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80454804: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454808: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8045480C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454810: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80454814: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80454818: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x8045481C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80454820: jal         0x8044EEF8
    // 0x80454824: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_8044EEF8(rdram, ctx);
        goto after_0;
    // 0x80454824: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x80454828: jal         0x80446D70
    // 0x8045482C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80446D70(rdram, ctx);
        goto after_1;
    // 0x8045482C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80454830: jal         0x8044DED8
    // 0x80454834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044DED8(rdram, ctx);
        goto after_2;
    // 0x80454834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80454838: jal         0x8044E2E4
    // 0x8045483C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044E2E4(rdram, ctx);
        goto after_3;
    // 0x8045483C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80454840: jal         0x8044FD5C
    // 0x80454844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044FD5C(rdram, ctx);
        goto after_4;
    // 0x80454844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80454848: jal         0x8044FFC0
    // 0x8045484C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044FFC0(rdram, ctx);
        goto after_5;
    // 0x8045484C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80454850: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80454854: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80454858: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8045485C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80454860: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80454864: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80454868: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8045486C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80454870: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80454874: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x80454878: addu        $a1, $s1, $t0
    ctx->r5 = ADD32(ctx->r17, ctx->r8);
    // 0x8045487C: jal         0x8044ED68
    // 0x80454880: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_6;
    // 0x80454880: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_6:
    // 0x80454884: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80454888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045488C: jal         0x8044F178
    // 0x80454890: sw          $t1, 0xA5C($s1)
    MEM_W(0XA5C, ctx->r17) = ctx->r9;
    func_8044F178(rdram, ctx);
        goto after_7;
    // 0x80454890: sw          $t1, 0xA5C($s1)
    MEM_W(0XA5C, ctx->r17) = ctx->r9;
    after_7:
    // 0x80454894: jal         0x8044F384
    // 0x80454898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044F384(rdram, ctx);
        goto after_8;
    // 0x80454898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8045489C: jal         0x8045012C
    // 0x804548A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8045012C(rdram, ctx);
        goto after_9;
    // 0x804548A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x804548A4: jal         0x8045043C
    // 0x804548A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8045043C(rdram, ctx);
        goto after_10;
    // 0x804548A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x804548AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804548B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804548B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804548B8: jr          $ra
    // 0x804548BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804548BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804C6D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C6D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C6D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C6D88: jal         0x80059278
    // 0x804C6D8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80059278(rdram, ctx);
        goto after_0;
    // 0x804C6D8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C6D90: bne         $v0, $zero, L_804C6DA8
    if (ctx->r2 != 0) {
        // 0x804C6D94: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804C6DA8;
    }
    // 0x804C6D94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C6D98: jal         0x800447C8
    // 0x804C6D9C: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x804C6D9C: nop

    after_1:
    // 0x804C6DA0: b           L_804C6DF0
    // 0x804C6DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804C6DF0;
    // 0x804C6DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C6DA8:
    // 0x804C6DA8: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x804C6DAC: beql        $v0, $zero, L_804C6DF0
    if (ctx->r2 == 0) {
        // 0x804C6DB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C6DF0;
    }
    goto skip_0;
    // 0x804C6DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C6DB4: jalr        $v0
    // 0x804C6DB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x804C6DB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x804C6DBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C6DC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804C6DC4: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x804C6DC8: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x804C6DCC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x804C6DD0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x804C6DD4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804C6DD8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x804C6DDC: bne         $v0, $at, L_804C6DEC
    if (ctx->r2 != ctx->r1) {
        // 0x804C6DE0: sh          $t1, 0x144($a0)
        MEM_H(0X144, ctx->r4) = ctx->r9;
            goto L_804C6DEC;
    }
    // 0x804C6DE0: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x804C6DE4: jal         0x800447C8
    // 0x804C6DE8: nop

    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x804C6DE8: nop

    after_3:
L_804C6DEC:
    // 0x804C6DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C6DF0:
    // 0x804C6DF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C6DF4: jr          $ra
    // 0x804C6DF8: nop

    return;
    // 0x804C6DF8: nop

;}
RECOMP_FUNC void func_805A29EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A29EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A29F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A29F4: jal         0x805A27E8
    // 0x805A29F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A27E8(rdram, ctx);
        goto after_0;
    // 0x805A29F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A29FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A2A00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805A2A04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A2A08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805A2A0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x805A2A10: jal         0x805A2B28
    // 0x805A2A14: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    func_805A2B28(rdram, ctx);
        goto after_1;
    // 0x805A2A14: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    after_1:
    // 0x805A2A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A2A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A2A20: jr          $ra
    // 0x805A2A24: nop

    return;
    // 0x805A2A24: nop

;}
RECOMP_FUNC void func_80450490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80450494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450498: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8045049C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x804504A0: jal         0x80046E88
    // 0x804504A4: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x804504A4: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    after_0:
    // 0x804504A8: beq         $v0, $zero, L_80450558
    if (ctx->r2 == 0) {
        // 0x804504AC: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_80450558;
    }
    // 0x804504AC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x804504B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804504B4: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804504B8: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804504BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804504C0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804504C4: lw          $v1, 0x16C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X16C);
    // 0x804504C8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x804504CC: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x804504D0: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804504D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x804504D8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x804504DC: nop

    // 0x804504E0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x804504E4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x804504E8: nop

    // 0x804504EC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x804504F0: beql        $t7, $zero, L_80450540
    if (ctx->r15 == 0) {
        // 0x804504F4: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_80450540;
    }
    goto skip_0;
    // 0x804504F4: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x804504F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804504FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80450500: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80450504: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80450508: nop

    // 0x8045050C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80450510: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80450514: nop

    // 0x80450518: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8045051C: bne         $t7, $zero, L_80450534
    if (ctx->r15 != 0) {
        // 0x80450520: nop
    
            goto L_80450534;
    }
    // 0x80450520: nop

    // 0x80450524: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80450528: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8045052C: b           L_8045054C
    // 0x80450530: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8045054C;
    // 0x80450530: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80450534:
    // 0x80450534: b           L_8045054C
    // 0x80450538: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8045054C;
    // 0x80450538: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8045053C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_80450540:
    // 0x80450540: nop

    // 0x80450544: bltz        $t7, L_80450534
    if (SIGNED(ctx->r15) < 0) {
        // 0x80450548: nop
    
            goto L_80450534;
    }
    // 0x80450548: nop

L_8045054C:
    // 0x8045054C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80450550: sb          $t7, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r15;
    // 0x80450554: nop

L_80450558:
    // 0x80450558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045055C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80450560: jr          $ra
    // 0x80450564: nop

    return;
    // 0x80450564: nop

;}
RECOMP_FUNC void func_8064AB38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AB38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064AB3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064AB40: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064AB44: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064AB48: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8064AB4C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064AB50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064AB54: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8064AB58: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8064AB5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064AB60: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8064AB64: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8064AB68: nop

    // 0x8064AB6C: bc1fl       L_8064AB84
    if (!c1cs) {
        // 0x8064AB70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064AB84;
    }
    goto skip_0;
    // 0x8064AB70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064AB74: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064AB78: jal         0x8064AEA8
    // 0x8064AB7C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064AEA8(rdram, ctx);
        goto after_0;
    // 0x8064AB7C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064AB80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064AB84:
    // 0x8064AB84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064AB88: jr          $ra
    // 0x8064AB8C: nop

    return;
    // 0x8064AB8C: nop

;}
RECOMP_FUNC void func_807A0F78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A0F78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A0F7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A0F80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807A0F84: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x807A0F88: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x807A0F8C: jal         0x80067BBC
    // 0x807A0F90: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x807A0F90: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x807A0F94: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x807A0F98: jal         0x80067818
    // 0x807A0F9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807A0F9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x807A0FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A0FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A0FA8: jr          $ra
    // 0x807A0FAC: nop

    return;
    // 0x807A0FAC: nop

;}
RECOMP_FUNC void func_8064E0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E0A0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8064E0A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8064E0A8: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8064E0AC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8064E0B0: nop

    // 0x8064E0B4: bc1f        L_8064E0F0
    if (!c1cs) {
        // 0x8064E0B8: nop
    
            goto L_8064E0F0;
    }
    // 0x8064E0B8: nop

    // 0x8064E0BC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8064E0C0: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8064E0C4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8064E0C8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8064E0CC: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x8064E0D0: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8064E0D4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8064E0D8: nop

    // 0x8064E0DC: bc1f        L_8064E0F0
    if (!c1cs) {
        // 0x8064E0E0: nop
    
            goto L_8064E0F0;
    }
    // 0x8064E0E0: nop

    // 0x8064E0E4: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x8064E0E8: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x8064E0EC: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
L_8064E0F0:
    // 0x8064E0F0: jr          $ra
    // 0x8064E0F4: nop

    return;
    // 0x8064E0F4: nop

;}
RECOMP_FUNC void func_804CC3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC3DC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CC3E0: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x804CC3E4: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x804CC3E8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x804CC3EC: lbu         $v1, 0x584($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X584);
    // 0x804CC3F0: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x804CC3F4: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x804CC3F8: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x804CC3FC: beql        $at, $zero, L_804CC410
    if (ctx->r1 == 0) {
        // 0x804CC400: sb          $v1, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r3;
            goto L_804CC410;
    }
    goto skip_0;
    // 0x804CC400: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    skip_0:
    // 0x804CC404: sb          $t6, 0x584($a2)
    MEM_B(0X584, ctx->r6) = ctx->r14;
    // 0x804CC408: andi        $v1, $t6, 0xFF
    ctx->r3 = ctx->r14 & 0XFF;
    // 0x804CC40C: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
L_804CC410:
    // 0x804CC410: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x804CC414: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x804CC418: jr          $ra
    // 0x804CC41C: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    return;
    // 0x804CC41C: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80475780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475780: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475784: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475788: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047578C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475790: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475794: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475798: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047579C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804757A0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804757A4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804757A8: jr          $ra
    // 0x804757AC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804757AC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805C8240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C8240: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805C8244: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C8248: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C824C: lui         $a1, 0x439D
    ctx->r5 = S32(0X439D << 16);
    // 0x805C8250: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C8254: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x805C8258: jal         0x805C70B0
    // 0x805C825C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    func_805C70B0(rdram, ctx);
        goto after_0;
    // 0x805C825C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_0:
    // 0x805C8260: beq         $v0, $zero, L_805C82A4
    if (ctx->r2 == 0) {
        // 0x805C8264: lui         $at, 0xC0A0
        ctx->r1 = S32(0XC0A0 << 16);
            goto L_805C82A4;
    }
    // 0x805C8264: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x805C8268: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x805C826C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805C8270: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(447, 0X3908) << 16);
    // 0x805C8274: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805C8278: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x805C827C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x805C8280: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    // 0x805C8284: lw          $a2, -0x6208($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(447, 0X3908));
    // 0x805C8288: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x805C828C: jal         0x805C74C8
    // 0x805C8290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C74C8(rdram, ctx);
        goto after_1;
    // 0x805C8290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805C8294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C829C: jal         0x805C9D10
    // 0x805C82A0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_805C9D10(rdram, ctx);
        goto after_2;
    // 0x805C82A0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
L_805C82A4:
    // 0x805C82A4: jal         0x805C7844
    // 0x805C82A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7844(rdram, ctx);
        goto after_3;
    // 0x805C82A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805C82AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805C82B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C82B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805C82B8: jr          $ra
    // 0x805C82BC: nop

    return;
    // 0x805C82BC: nop

;}
RECOMP_FUNC void func_80055A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055A38: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80055A3C: sw          $a0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r4;
    // 0x80055A40: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80055A44: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x80055A48: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80055A4C: sw          $a2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r6;
    // 0x80055A50: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80055A54: sw          $a3, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r7;
    // 0x80055A58: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80055A5C: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x80055A60: jr          $ra
    // 0x80055A64: sw          $t0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r8;
    return;
    // 0x80055A64: sw          $t0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r8;
;}
RECOMP_FUNC void func_805EC200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805EC200: lui         $v0, 0x8065
    ctx->r2 = S32(RELOC_HI16(492, 0X5DE38) << 16);
    // 0x805EC204: jr          $ra
    // 0x805EC208: addiu       $v0, $v0, -0x5FC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(492, 0X5DE38));
    return;
    // 0x805EC208: addiu       $v0, $v0, -0x5FC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(492, 0X5DE38));
;}
RECOMP_FUNC void func_800231C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800231C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800231CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800231D0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x800231D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800231D8: lwc1        $f6, -0x308($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X308);
    // 0x800231DC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800231E0: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x800231E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800231E8: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800231EC: jal         0x8001D78C
    // 0x800231F0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8001D78C(rdram, ctx);
        goto after_0;
    // 0x800231F0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800231F4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800231F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800231FC: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80023200: lbu         $t8, 0x1A8($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1A8);
    // 0x80023204: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80023208: beql        $t8, $zero, L_80023244
    if (ctx->r24 == 0) {
        // 0x8002320C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80023244;
    }
    goto skip_0;
    // 0x8002320C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x80023210: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80023214: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80023218: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8002321C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023220: nop

    // 0x80023224: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80023228: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002322C: nop

    // 0x80023230: bc1fl       L_8002326C
    if (!c1cs) {
        // 0x80023234: swc1        $f0, 0xC4($a0)
        MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
            goto L_8002326C;
    }
    goto skip_1;
    // 0x80023234: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x80023238: b           L_80023268
    // 0x8002323C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80023268;
    // 0x8002323C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80023240: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80023244:
    // 0x80023244: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80023248: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002324C: nop

    // 0x80023250: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80023254: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80023258: nop

    // 0x8002325C: bc1fl       L_8002326C
    if (!c1cs) {
        // 0x80023260: swc1        $f0, 0xC4($a0)
        MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
            goto L_8002326C;
    }
    goto skip_2;
    // 0x80023260: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    skip_2:
    // 0x80023264: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80023268:
    // 0x80023268: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
L_8002326C:
    // 0x8002326C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023270: lwc1        $f16, -0x304($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X304);
    // 0x80023274: swc1        $f16, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f16.u32l;
    // 0x80023278: jal         0x800231AC
    // 0x8002327C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800231AC(rdram, ctx);
        goto after_1;
    // 0x8002327C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80023280: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80023284: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80023288: nop

    // 0x8002328C: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x80023290: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x80023294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023298: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002329C: jr          $ra
    // 0x800232A0: nop

    return;
    // 0x800232A0: nop

;}
RECOMP_FUNC void func_8045F950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F950: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8045F954: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8045F958: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8045F95C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8045F960: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8045F964: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8045F968: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8045F96C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8045F970: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8045F974: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8045F978: sb          $s0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r16;
    // 0x8045F97C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8045F980: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8045F984: jal         0x8045FAB0
    // 0x8045F988: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8045FAB0(rdram, ctx);
        goto after_0;
    // 0x8045F988: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8045F98C: lw          $t9, 0x16C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X16C);
    // 0x8045F990: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8045F994: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8045F998: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(113, 0XA78) << 16);
    // 0x8045F99C: sw          $t7, 0x130($s2)
    MEM_W(0X130, ctx->r18) = ctx->r15;
    // 0x8045F9A0: addiu       $t8, $t8, -0x468
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(113, 0XA78));
    // 0x8045F9A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8045F9A8: lui         $t0, 0x8046
    ctx->r8 = S32(RELOC_HI16(113, 0X808) << 16);
    // 0x8045F9AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8045F9B0: sb          $s0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r16;
    // 0x8045F9B4: addiu       $t0, $t0, -0x6D8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(113, 0X808));
    // 0x8045F9B8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8045F9BC: sw          $t0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r8;
    // 0x8045F9C0: sh          $t1, 0x1F0($s2)
    MEM_H(0X1F0, ctx->r18) = ctx->r9;
    // 0x8045F9C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8045F9C8: jal         0x80045A34
    // 0x8045F9CC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8045F9CC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x8045F9D0: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(113, 0X800) << 16);
    // 0x8045F9D4: addiu       $t2, $t2, -0x6E0
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(113, 0X800));
    // 0x8045F9D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8045F9DC: sw          $v0, 0x1F4($s2)
    MEM_W(0X1F4, ctx->r18) = ctx->r2;
    // 0x8045F9E0: sw          $t2, 0x1F8($s2)
    MEM_W(0X1F8, ctx->r18) = ctx->r10;
    // 0x8045F9E4: lui         $t4, 0x8046
    ctx->r12 = S32(RELOC_HI16(113, 0XA00) << 16);
    // 0x8045F9E8: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8045F9EC: addiu       $t4, $t4, -0x4E0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(113, 0XA00));
    // 0x8045F9F0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8045F9F4: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x8045F9F8: sw          $t4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r12;
    // 0x8045F9FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8045FA00: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8045FA04: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8045FA08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8045FA0C:
    // 0x8045FA0C: jal         0x8045F8A4
    // 0x8045FA10: addiu       $a1, $zero, 0x409A
    ctx->r5 = ADD32(0, 0X409A);
    func_8045F8A4(rdram, ctx);
        goto after_2;
    // 0x8045FA10: addiu       $a1, $zero, 0x409A
    ctx->r5 = ADD32(0, 0X409A);
    after_2:
    // 0x8045FA14: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x8045FA18: lw          $t5, 0x8($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X8);
    // 0x8045FA1C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8045FA20: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8045FA24: sltu        $at, $s0, $t5
    ctx->r1 = ctx->r16 < ctx->r13 ? 1 : 0;
    // 0x8045FA28: bnel        $at, $zero, L_8045FA0C
    if (ctx->r1 != 0) {
        // 0x8045FA2C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8045FA0C;
    }
    goto skip_0;
    // 0x8045FA2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x8045FA30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8045FA34: jal         0x8045F8A4
    // 0x8045FA38: addiu       $a1, $zero, 0x44D4
    ctx->r5 = ADD32(0, 0X44D4);
    func_8045F8A4(rdram, ctx);
        goto after_3;
    // 0x8045FA38: addiu       $a1, $zero, 0x44D4
    ctx->r5 = ADD32(0, 0X44D4);
    after_3:
    // 0x8045FA3C: lw          $t7, 0x16C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X16C);
    // 0x8045FA40: lui         $t6, 0x8046
    ctx->r14 = S32(RELOC_HI16(113, 0X170) << 16);
    // 0x8045FA44: addiu       $t6, $t6, -0xD70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(113, 0X170));
    // 0x8045FA48: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x8045FA4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8045FA50: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8045FA54: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8045FA58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8045FA5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8045FA60: jr          $ra
    // 0x8045FA64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8045FA64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8052D7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D7C8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8052D7CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8052D7D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8052D7D4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8052D7D8: lw          $v1, 0xF00($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XF00);
    // 0x8052D7DC: lw          $v0, 0xF04($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XF04);
    // 0x8052D7E0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8052D7E4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8052D7E8: slti        $at, $v1, 0x1E0
    ctx->r1 = SIGNED(ctx->r3) < 0X1E0 ? 1 : 0;
    // 0x8052D7EC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8052D7F0: lw          $t1, 0xF08($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XF08);
    // 0x8052D7F4: bne         $at, $zero, L_8052D800
    if (ctx->r1 != 0) {
        // 0x8052D7F8: lw          $a0, 0x1F4($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X1F4);
            goto L_8052D800;
    }
    // 0x8052D7F8: lw          $a0, 0x1F4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1F4);
    // 0x8052D7FC: addiu       $v1, $v1, -0x1E0
    ctx->r3 = ADD32(ctx->r3, -0X1E0);
L_8052D800:
    // 0x8052D800: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8052D804: addu        $v0, $t6, $s0
    ctx->r2 = ADD32(ctx->r14, ctx->r16);
    // 0x8052D808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8052D80C: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
L_8052D810:
    // 0x8052D810: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8052D814: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8052D818: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8052D81C: slti        $at, $v1, 0x1E0
    ctx->r1 = SIGNED(ctx->r3) < 0X1E0 ? 1 : 0;
    // 0x8052D820: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8052D824: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8052D828: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x8052D82C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8052D830: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8052D834: lwc1        $f10, -0x7C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X7C);
    // 0x8052D838: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8052D83C: bne         $at, $zero, L_8052D84C
    if (ctx->r1 != 0) {
        // 0x8052D840: swc1        $f18, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
            goto L_8052D84C;
    }
    // 0x8052D840: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x8052D844: addiu       $v1, $v1, -0x1E0
    ctx->r3 = ADD32(ctx->r3, -0X1E0);
    // 0x8052D848: addiu       $v0, $v0, -0xF00
    ctx->r2 = ADD32(ctx->r2, -0XF00);
L_8052D84C:
    // 0x8052D84C: bne         $a1, $a2, L_8052D810
    if (ctx->r5 != ctx->r6) {
        // 0x8052D850: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_8052D810;
    }
    // 0x8052D850: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8052D854: addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    // 0x8052D858: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8052D85C: swc1        $f4, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f4.u32l;
    // 0x8052D860: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8052D864: swc1        $f6, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f6.u32l;
    // 0x8052D868: lwc1        $f18, -0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, -0X4);
    // 0x8052D86C: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8052D870: lwc1        $f10, -0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8052D874: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8052D878: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8052D87C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8052D880: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8052D884: jal         0x80067114
    // 0x8052D888: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x8052D888: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
    after_0:
    // 0x8052D88C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8052D890: swc1        $f0, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f0.u32l;
    // 0x8052D894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8052D898: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8052D89C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8052D8A0: jr          $ra
    // 0x8052D8A4: nop

    return;
    // 0x8052D8A4: nop

;}
RECOMP_FUNC void func_807ACDAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ACDAC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807ACDB0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x807ACDB4: bne         $a1, $zero, L_807ACDCC
    if (ctx->r5 != 0) {
        // 0x807ACDB8: sw          $a1, 0x468($v0)
        MEM_W(0X468, ctx->r2) = ctx->r5;
            goto L_807ACDCC;
    }
    // 0x807ACDB8: sw          $a1, 0x468($v0)
    MEM_W(0X468, ctx->r2) = ctx->r5;
    // 0x807ACDBC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26B0) << 16);
    // 0x807ACDC0: lwc1        $f4, -0x12F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26B0));
    // 0x807ACDC4: b           L_807ACDD8
    // 0x807ACDC8: swc1        $f4, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f4.u32l;
        goto L_807ACDD8;
    // 0x807ACDC8: swc1        $f4, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f4.u32l;
L_807ACDCC:
    // 0x807ACDCC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26B4) << 16);
    // 0x807ACDD0: lwc1        $f6, -0x12EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26B4));
    // 0x807ACDD4: swc1        $f6, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f6.u32l;
L_807ACDD8:
    // 0x807ACDD8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x807ACDDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x807ACDE0: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x807ACDE4: lwc1        $f8, 0x470($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X470);
    // 0x807ACDE8: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x807ACDEC: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x807ACDF0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x807ACDF4: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x807ACDF8: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x807ACDFC: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x807ACE00: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x807ACE04: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x807ACE08: sb          $t0, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r8;
    // 0x807ACE0C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x807ACE10: sb          $t0, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r8;
    // 0x807ACE14: beq         $v1, $zero, L_807ACE64
    if (ctx->r3 == 0) {
        // 0x807ACE18: sb          $t0, 0x16($v0)
        MEM_B(0X16, ctx->r2) = ctx->r8;
            goto L_807ACE64;
    }
    // 0x807ACE18: sb          $t0, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r8;
    // 0x807ACE1C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x807ACE20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807ACE24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x807ACE28: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x807ACE2C: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x807ACE30: nop

    // 0x807ACE34: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x807ACE38: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x807ACE3C: nop

    // 0x807ACE40: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x807ACE44: bne         $v1, $zero, L_807ACE5C
    if (ctx->r3 != 0) {
        // 0x807ACE48: nop
    
            goto L_807ACE5C;
    }
    // 0x807ACE48: nop

    // 0x807ACE4C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x807ACE50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x807ACE54: b           L_807ACE74
    // 0x807ACE58: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_807ACE74;
    // 0x807ACE58: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_807ACE5C:
    // 0x807ACE5C: b           L_807ACE74
    // 0x807ACE60: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_807ACE74;
    // 0x807ACE60: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_807ACE64:
    // 0x807ACE64: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x807ACE68: nop

    // 0x807ACE6C: bltz        $v1, L_807ACE5C
    if (SIGNED(ctx->r3) < 0) {
        // 0x807ACE70: nop
    
            goto L_807ACE5C;
    }
    // 0x807ACE70: nop

L_807ACE74:
    // 0x807ACE74: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x807ACE78: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x807ACE7C: lui         $t8, 0x807B
    ctx->r24 = S32(RELOC_HI16(859, 0X24F0) << 16);
    // 0x807ACE80: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x807ACE84: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x807ACE88: addiu       $t8, $t8, -0x14B0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(859, 0X24F0));
    // 0x807ACE8C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x807ACE90: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807ACE94: sb          $v1, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r3;
    // 0x807ACE98: sh          $zero, 0x1F8($v0)
    MEM_H(0X1F8, ctx->r2) = 0;
    // 0x807ACE9C: sh          $zero, 0x1FA($v0)
    MEM_H(0X1FA, ctx->r2) = 0;
    // 0x807ACEA0: sh          $zero, 0x1FC($v0)
    MEM_H(0X1FC, ctx->r2) = 0;
    // 0x807ACEA4: sh          $zero, 0x1FE($v0)
    MEM_H(0X1FE, ctx->r2) = 0;
    // 0x807ACEA8: sh          $zero, 0x200($v0)
    MEM_H(0X200, ctx->r2) = 0;
    // 0x807ACEAC: sh          $zero, 0x202($v0)
    MEM_H(0X202, ctx->r2) = 0;
    // 0x807ACEB0: sb          $t0, 0x204($v0)
    MEM_B(0X204, ctx->r2) = ctx->r8;
    // 0x807ACEB4: sb          $t0, 0x205($v0)
    MEM_B(0X205, ctx->r2) = ctx->r8;
    // 0x807ACEB8: sb          $t0, 0x206($v0)
    MEM_B(0X206, ctx->r2) = ctx->r8;
    // 0x807ACEBC: sb          $v1, 0x207($v0)
    MEM_B(0X207, ctx->r2) = ctx->r3;
    // 0x807ACEC0: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x807ACEC4: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x807ACEC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807ACECC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x807ACED0: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x807ACED4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x807ACED8: beq         $a0, $t1, L_807ACFF0
    if (ctx->r4 == ctx->r9) {
        // 0x807ACEDC: lh          $t9, 0x0($a2)
        ctx->r25 = MEM_H(ctx->r6, 0X0);
            goto L_807ACFF0;
    }
    // 0x807ACEDC: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
L_807ACEE0:
    // 0x807ACEE0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x807ACEE4: lh          $t2, 0x2($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X2);
    // 0x807ACEE8: sh          $zero, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = 0;
    // 0x807ACEEC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807ACEF0: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x807ACEF4: sh          $zero, 0x1E($a3)
    MEM_H(0X1E, ctx->r7) = 0;
    // 0x807ACEF8: sh          $zero, 0x20($a3)
    MEM_H(0X20, ctx->r7) = 0;
    // 0x807ACEFC: sh          $zero, 0x22($a3)
    MEM_H(0X22, ctx->r7) = 0;
    // 0x807ACF00: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807ACF04: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x807ACF08: sb          $t0, 0x24($a3)
    MEM_B(0X24, ctx->r7) = ctx->r8;
    // 0x807ACF0C: sb          $t0, 0x25($a3)
    MEM_B(0X25, ctx->r7) = ctx->r8;
    // 0x807ACF10: sb          $a1, 0x26($a3)
    MEM_B(0X26, ctx->r7) = ctx->r5;
    // 0x807ACF14: sb          $zero, 0x27($a3)
    MEM_B(0X27, ctx->r7) = 0;
    // 0x807ACF18: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x807ACF1C: sh          $zero, 0x20C($a3)
    MEM_H(0X20C, ctx->r7) = 0;
    // 0x807ACF20: sh          $zero, 0x20E($a3)
    MEM_H(0X20E, ctx->r7) = 0;
    // 0x807ACF24: sh          $zero, 0x210($a3)
    MEM_H(0X210, ctx->r7) = 0;
    // 0x807ACF28: sh          $zero, 0x212($a3)
    MEM_H(0X212, ctx->r7) = 0;
    // 0x807ACF2C: sb          $t0, 0x214($a3)
    MEM_B(0X214, ctx->r7) = ctx->r8;
    // 0x807ACF30: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x807ACF34: sb          $t0, 0x215($a3)
    MEM_B(0X215, ctx->r7) = ctx->r8;
    // 0x807ACF38: sb          $a1, 0x216($a3)
    MEM_B(0X216, ctx->r7) = ctx->r5;
    // 0x807ACF3C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x807ACF40: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x807ACF44: sb          $zero, 0x217($a3)
    MEM_B(0X217, ctx->r7) = 0;
    // 0x807ACF48: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x807ACF4C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x807ACF50: sh          $v0, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r2;
    // 0x807ACF54: sh          $v0, 0x208($a3)
    MEM_H(0X208, ctx->r7) = ctx->r2;
    // 0x807ACF58: sh          $v1, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r3;
    // 0x807ACF5C: sh          $v1, 0x20A($a3)
    MEM_H(0X20A, ctx->r7) = ctx->r3;
    // 0x807ACF60: lh          $t5, 0x4($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X4);
    // 0x807ACF64: lh          $t6, 0x6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X6);
    // 0x807ACF68: sh          $zero, 0x2C($a3)
    MEM_H(0X2C, ctx->r7) = 0;
    // 0x807ACF6C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x807ACF70: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x807ACF74: sh          $zero, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = 0;
    // 0x807ACF78: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807ACF7C: sh          $zero, 0x30($a3)
    MEM_H(0X30, ctx->r7) = 0;
    // 0x807ACF80: sh          $zero, 0x32($a3)
    MEM_H(0X32, ctx->r7) = 0;
    // 0x807ACF84: sb          $t0, 0x34($a3)
    MEM_B(0X34, ctx->r7) = ctx->r8;
    // 0x807ACF88: sb          $t0, 0x35($a3)
    MEM_B(0X35, ctx->r7) = ctx->r8;
    // 0x807ACF8C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807ACF90: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x807ACF94: sb          $a1, 0x36($a3)
    MEM_B(0X36, ctx->r7) = ctx->r5;
    // 0x807ACF98: sb          $zero, 0x37($a3)
    MEM_B(0X37, ctx->r7) = 0;
    // 0x807ACF9C: sh          $zero, 0x21C($a3)
    MEM_H(0X21C, ctx->r7) = 0;
    // 0x807ACFA0: sh          $zero, 0x21E($a3)
    MEM_H(0X21E, ctx->r7) = 0;
    // 0x807ACFA4: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x807ACFA8: sh          $zero, 0x220($a3)
    MEM_H(0X220, ctx->r7) = 0;
    // 0x807ACFAC: sh          $zero, 0x222($a3)
    MEM_H(0X222, ctx->r7) = 0;
    // 0x807ACFB0: sb          $t0, 0x224($a3)
    MEM_B(0X224, ctx->r7) = ctx->r8;
    // 0x807ACFB4: sb          $t0, 0x225($a3)
    MEM_B(0X225, ctx->r7) = ctx->r8;
    // 0x807ACFB8: sb          $a1, 0x226($a3)
    MEM_B(0X226, ctx->r7) = ctx->r5;
    // 0x807ACFBC: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x807ACFC0: sb          $zero, 0x227($a3)
    MEM_B(0X227, ctx->r7) = 0;
    // 0x807ACFC4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x807ACFC8: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x807ACFCC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x807ACFD0: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x807ACFD4: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x807ACFD8: sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    // 0x807ACFDC: sh          $v0, 0x1F8($a3)
    MEM_H(0X1F8, ctx->r7) = ctx->r2;
    // 0x807ACFE0: sh          $v1, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r3;
    // 0x807ACFE4: sh          $v1, 0x1FA($a3)
    MEM_H(0X1FA, ctx->r7) = ctx->r3;
    // 0x807ACFE8: bne         $a0, $t1, L_807ACEE0
    if (ctx->r4 != ctx->r9) {
        // 0x807ACFEC: lh          $t9, 0x0($a2)
        ctx->r25 = MEM_H(ctx->r6, 0X0);
            goto L_807ACEE0;
    }
    // 0x807ACFEC: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
L_807ACFF0:
    // 0x807ACFF0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x807ACFF4: lh          $t2, 0x2($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X2);
    // 0x807ACFF8: sb          $zero, 0x27($a3)
    MEM_B(0X27, ctx->r7) = 0;
    // 0x807ACFFC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AD000: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x807AD004: sb          $a1, 0x26($a3)
    MEM_B(0X26, ctx->r7) = ctx->r5;
    // 0x807AD008: sb          $t0, 0x25($a3)
    MEM_B(0X25, ctx->r7) = ctx->r8;
    // 0x807AD00C: sb          $t0, 0x24($a3)
    MEM_B(0X24, ctx->r7) = ctx->r8;
    // 0x807AD010: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807AD014: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x807AD018: sh          $zero, 0x22($a3)
    MEM_H(0X22, ctx->r7) = 0;
    // 0x807AD01C: sh          $zero, 0x20($a3)
    MEM_H(0X20, ctx->r7) = 0;
    // 0x807AD020: sh          $zero, 0x1E($a3)
    MEM_H(0X1E, ctx->r7) = 0;
    // 0x807AD024: sh          $zero, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = 0;
    // 0x807AD028: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x807AD02C: sb          $zero, 0x217($a3)
    MEM_B(0X217, ctx->r7) = 0;
    // 0x807AD030: sb          $a1, 0x216($a3)
    MEM_B(0X216, ctx->r7) = ctx->r5;
    // 0x807AD034: sb          $t0, 0x215($a3)
    MEM_B(0X215, ctx->r7) = ctx->r8;
    // 0x807AD038: sb          $t0, 0x214($a3)
    MEM_B(0X214, ctx->r7) = ctx->r8;
    // 0x807AD03C: sh          $zero, 0x212($a3)
    MEM_H(0X212, ctx->r7) = 0;
    // 0x807AD040: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x807AD044: sh          $zero, 0x210($a3)
    MEM_H(0X210, ctx->r7) = 0;
    // 0x807AD048: sh          $zero, 0x20E($a3)
    MEM_H(0X20E, ctx->r7) = 0;
    // 0x807AD04C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x807AD050: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x807AD054: sh          $zero, 0x20C($a3)
    MEM_H(0X20C, ctx->r7) = 0;
    // 0x807AD058: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x807AD05C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x807AD060: sh          $v0, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r2;
    // 0x807AD064: sh          $v0, 0x208($a3)
    MEM_H(0X208, ctx->r7) = ctx->r2;
    // 0x807AD068: sh          $v1, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r3;
    // 0x807AD06C: sh          $v1, 0x20A($a3)
    MEM_H(0X20A, ctx->r7) = ctx->r3;
    // 0x807AD070: lh          $t5, -0x4($a2)
    ctx->r13 = MEM_H(ctx->r6, -0X4);
    // 0x807AD074: lh          $t6, -0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X2);
    // 0x807AD078: sb          $zero, 0x227($a3)
    MEM_B(0X227, ctx->r7) = 0;
    // 0x807AD07C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x807AD080: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x807AD084: sb          $a1, 0x226($a3)
    MEM_B(0X226, ctx->r7) = ctx->r5;
    // 0x807AD088: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807AD08C: sb          $t0, 0x225($a3)
    MEM_B(0X225, ctx->r7) = ctx->r8;
    // 0x807AD090: sb          $t0, 0x224($a3)
    MEM_B(0X224, ctx->r7) = ctx->r8;
    // 0x807AD094: sh          $zero, 0x222($a3)
    MEM_H(0X222, ctx->r7) = 0;
    // 0x807AD098: sh          $zero, 0x220($a3)
    MEM_H(0X220, ctx->r7) = 0;
    // 0x807AD09C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AD0A0: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x807AD0A4: sh          $zero, 0x21E($a3)
    MEM_H(0X21E, ctx->r7) = 0;
    // 0x807AD0A8: sh          $zero, 0x21C($a3)
    MEM_H(0X21C, ctx->r7) = 0;
    // 0x807AD0AC: sb          $zero, 0x37($a3)
    MEM_B(0X37, ctx->r7) = 0;
    // 0x807AD0B0: sb          $a1, 0x36($a3)
    MEM_B(0X36, ctx->r7) = ctx->r5;
    // 0x807AD0B4: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x807AD0B8: sb          $t0, 0x35($a3)
    MEM_B(0X35, ctx->r7) = ctx->r8;
    // 0x807AD0BC: sb          $t0, 0x34($a3)
    MEM_B(0X34, ctx->r7) = ctx->r8;
    // 0x807AD0C0: sh          $zero, 0x32($a3)
    MEM_H(0X32, ctx->r7) = 0;
    // 0x807AD0C4: sh          $zero, 0x30($a3)
    MEM_H(0X30, ctx->r7) = 0;
    // 0x807AD0C8: sh          $zero, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = 0;
    // 0x807AD0CC: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x807AD0D0: sh          $zero, 0x2C($a3)
    MEM_H(0X2C, ctx->r7) = 0;
    // 0x807AD0D4: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x807AD0D8: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x807AD0DC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x807AD0E0: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x807AD0E4: sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    // 0x807AD0E8: sh          $v0, 0x1F8($a3)
    MEM_H(0X1F8, ctx->r7) = ctx->r2;
    // 0x807AD0EC: sh          $v1, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r3;
    // 0x807AD0F0: sh          $v1, 0x1FA($a3)
    MEM_H(0X1FA, ctx->r7) = ctx->r3;
    // 0x807AD0F4: jr          $ra
    // 0x807AD0F8: nop

    return;
    // 0x807AD0F8: nop

;}
RECOMP_FUNC void func_80791CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791CFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80791D00: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80791D04: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80791D08: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80791D0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80791D10: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x80791D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791D18: jal         0x807903C4
    // 0x80791D1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x80791D1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80791D20: lw          $t6, 0x1E0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1E0);
    // 0x80791D24: lw          $t8, 0x1E4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1E4);
    // 0x80791D28: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80791D2C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80791D30: bne         $t8, $zero, L_80791D58
    if (ctx->r24 != 0) {
        // 0x80791D34: sw          $t7, 0x1E0($s1)
        MEM_W(0X1E0, ctx->r17) = ctx->r15;
            goto L_80791D58;
    }
    // 0x80791D34: sw          $t7, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r15;
    // 0x80791D38: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80791D3C: sb          $t9, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r25;
    // 0x80791D40: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80791D44: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x80791D48: sb          $t0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r8;
    // 0x80791D4C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80791D50: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80791D54: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
L_80791D58:
    // 0x80791D58: jal         0x80790714
    // 0x80791D5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x80791D5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80791D60: beq         $v0, $zero, L_80791DB0
    if (ctx->r2 == 0) {
        // 0x80791D64: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80791DB0;
    }
    // 0x80791D64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80791D68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791D6C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80791D70: jal         0x8079393C
    // 0x80791D74: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80791D74: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_2:
    // 0x80791D78: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80791D7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80791D80: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7ACC) << 16);
    // 0x80791D84: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80791D88: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80791D8C: lwc1        $f6, 0x7E1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7ACC));
    // 0x80791D90: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80791D94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80791D98: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80791D9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80791DA0: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80791DA4: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x80791DA8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80791DAC: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_80791DB0:
    // 0x80791DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80791DB4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80791DB8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80791DBC: jr          $ra
    // 0x80791DC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80791DC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80070988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070988: lui         $t6, 0xFFFA
    ctx->r14 = S32(0XFFFA << 16);
    // 0x8007098C: or          $t7, $sp, $zero
    ctx->r15 = ctx->r29 | 0;
    // 0x80070990: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80070994: ori         $t6, $t6, 0x5A5A
    ctx->r14 = ctx->r14 | 0X5A5A;
L_80070998:
    // 0x80070998: addiu       $t7, $t7, -0x8
    ctx->r15 = ADD32(ctx->r15, -0X8);
    // 0x8007099C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800709A0: bne         $t7, $sp, L_80070998
    if (ctx->r15 != ctx->r29) {
        // 0x800709A4: sw          $t6, 0x4($t7)
        MEM_W(0X4, ctx->r15) = ctx->r14;
            goto L_80070998;
    }
    // 0x800709A4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800709A8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800709AC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800709B0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800709B4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800709B8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800709BC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800709C0: addiu       $a2, $zero, 0x114
    ctx->r6 = ADD32(0, 0X114);
    // 0x800709C4: jal         0x8006F600
    // 0x800709C8: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    Fault_DrawRec(rdram, ctx);
        goto after_0;
    // 0x800709C8: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    after_0:
    // 0x800709CC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800709D0: lw          $a3, -0x57C4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X57C4);
    // 0x800709D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800709D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800709DC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800709E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800709E4: addiu       $a0, $a0, -0x57C0
    ctx->r4 = ADD32(ctx->r4, -0X57C0);
    // 0x800709E8: blez        $a3, L_80070A48
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800709EC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80070A48;
    }
    // 0x800709EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800709F0:
    // 0x800709F0: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800709F4: beql        $v0, $zero, L_80070A38
    if (ctx->r2 == 0) {
        // 0x800709F8: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80070A38;
    }
    goto skip_0;
    // 0x800709F8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x800709FC: lw          $a1, 0x11C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X11C);
    // 0x80070A00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80070A04: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80070A08: bnel        $at, $zero, L_80070A3C
    if (ctx->r1 != 0) {
        // 0x80070A0C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80070A3C;
    }
    goto skip_1;
    // 0x80070A0C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_1:
    // 0x80070A10: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80070A14: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80070A18: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80070A1C: sltu        $at, $a1, $t8
    ctx->r1 = ctx->r5 < ctx->r24 ? 1 : 0;
    // 0x80070A20: beql        $at, $zero, L_80070A3C
    if (ctx->r1 == 0) {
        // 0x80070A24: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80070A3C;
    }
    goto skip_2;
    // 0x80070A24: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_2:
    // 0x80070A28: subu        $s0, $v0, $v1
    ctx->r16 = SUB32(ctx->r2, ctx->r3);
    // 0x80070A2C: b           L_80070A38
    // 0x80070A30: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
        goto L_80070A38;
    // 0x80070A30: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x80070A34: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80070A38:
    // 0x80070A38: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80070A3C:
    // 0x80070A3C: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80070A40: bne         $at, $zero, L_800709F0
    if (ctx->r1 != 0) {
        // 0x80070A44: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800709F0;
    }
    // 0x80070A44: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_80070A48:
    // 0x80070A48: addiu       $t9, $zero, 0x7FC1
    ctx->r25 = ADD32(0, 0X7FC1);
    // 0x80070A4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80070A50: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070A54: addiu       $t2, $s1, 0x20
    ctx->r10 = ADD32(ctx->r17, 0X20);
    // 0x80070A58: sh          $t9, -0x7B94($at)
    MEM_H(-0X7B94, ctx->r1) = ctx->r25;
    // 0x80070A5C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80070A60: addiu       $a2, $a2, 0x17DC
    ctx->r6 = ADD32(ctx->r6, 0X17DC);
    // 0x80070A64: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80070A68: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80070A6C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80070A70: jal         0x8006F884
    // 0x80070A74: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    Fault_Printf(rdram, ctx);
        goto after_1;
    // 0x80070A74: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_1:
    // 0x80070A78: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80070A7C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070A80: addiu       $a2, $a2, 0x17E8
    ctx->r6 = ADD32(ctx->r6, 0X17E8);
    // 0x80070A84: lw          $t3, 0xFC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XFC);
    // 0x80070A88: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    // 0x80070A8C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80070A90: jal         0x8006F884
    // 0x80070A94: addu        $a3, $t3, $s0
    ctx->r7 = ADD32(ctx->r11, ctx->r16);
    Fault_Printf(rdram, ctx);
        goto after_2;
    // 0x80070A94: addu        $a3, $t3, $s0
    ctx->r7 = ADD32(ctx->r11, ctx->r16);
    after_2:
    // 0x80070A98: lw          $t5, 0xE4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XE4);
    // 0x80070A9C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070AA0: addiu       $a2, $a2, 0x17F0
    ctx->r6 = ADD32(ctx->r6, 0X17F0);
    // 0x80070AA4: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    // 0x80070AA8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80070AAC: jal         0x8006F884
    // 0x80070AB0: addu        $a3, $t5, $s0
    ctx->r7 = ADD32(ctx->r13, ctx->r16);
    Fault_Printf(rdram, ctx);
        goto after_3;
    // 0x80070AB0: addu        $a3, $t5, $s0
    ctx->r7 = ADD32(ctx->r13, ctx->r16);
    after_3:
    // 0x80070AB4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070AB8: addiu       $a2, $a2, 0x17F8
    ctx->r6 = ADD32(ctx->r6, 0X17F8);
    // 0x80070ABC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80070AC0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80070AC4: jal         0x8006F884
    // 0x80070AC8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    Fault_Printf(rdram, ctx);
        goto after_4;
    // 0x80070AC8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x80070ACC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80070AD0: ori         $t7, $zero, 0xFFC1
    ctx->r15 = 0 | 0XFFC1;
    // 0x80070AD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80070AD8: bltz        $t1, L_80070B2C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80070ADC: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_80070B2C;
    }
    // 0x80070ADC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80070AE0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80070AE4: addiu       $t9, $t9, -0x57C0
    ctx->r25 = ADD32(ctx->r25, -0X57C0);
    // 0x80070AE8: sll         $t8, $t1, 4
    ctx->r24 = S32(ctx->r9 << 4);
    // 0x80070AEC: sh          $t7, -0x7B94($at)
    MEM_H(-0X7B94, ctx->r1) = ctx->r15;
    // 0x80070AF0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80070AF4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80070AF8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80070AFC: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x80070B00: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x80070B04: subu        $t2, $a3, $v1
    ctx->r10 = SUB32(ctx->r7, ctx->r3);
    // 0x80070B08: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070B0C: addu        $t3, $t2, $t0
    ctx->r11 = ADD32(ctx->r10, ctx->r8);
    // 0x80070B10: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80070B14: addiu       $a2, $a2, 0x1804
    ctx->r6 = ADD32(ctx->r6, 0X1804);
    // 0x80070B18: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80070B1C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x80070B20: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80070B24: jal         0x8006F884
    // 0x80070B28: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    Fault_Printf(rdram, ctx);
        goto after_5;
    // 0x80070B28: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    after_5:
L_80070B2C:
    // 0x80070B2C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80070B30: addiu       $s0, $s0, -0x7970
    ctx->r16 = ADD32(ctx->r16, -0X7970);
    // 0x80070B34: jal         0x800708D4
    // 0x80070B38: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800708D4(rdram, ctx);
        goto after_6;
    // 0x80070B38: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x80070B3C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80070B40: ori         $t5, $zero, 0xFFFF
    ctx->r13 = 0 | 0XFFFF;
    // 0x80070B44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80070B48: sh          $t5, -0x7B94($at)
    MEM_H(-0X7B94, ctx->r1) = ctx->r13;
    // 0x80070B4C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80070B50: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80070B54: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80070B58: jr          $ra
    // 0x80070B5C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80070B5C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_804C40B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C40B8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804C40BC: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x804C40C0: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x804C40C4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x804C40C8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x804C40CC: beq         $v1, $zero, L_804C4178
    if (ctx->r3 == 0) {
        // 0x804C40D0: lw          $v0, 0x4($t7)
        ctx->r2 = MEM_W(ctx->r15, 0X4);
            goto L_804C4178;
    }
    // 0x804C40D0: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x804C40D4: beq         $v0, $zero, L_804C4178
    if (ctx->r2 == 0) {
        // 0x804C40D8: nop
    
            goto L_804C4178;
    }
    // 0x804C40D8: nop

    // 0x804C40DC: lw          $a0, 0x16C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X16C);
    // 0x804C40E0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x804C40E4: lbu         $t8, 0xD($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XD);
    // 0x804C40E8: addiu       $a0, $a0, 0xD
    ctx->r4 = ADD32(ctx->r4, 0XD);
    // 0x804C40EC: addiu       $t9, $t8, 0x40
    ctx->r25 = ADD32(ctx->r24, 0X40);
    // 0x804C40F0: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x804C40F4: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x804C40F8: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x804C40FC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x804C4100: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x804C4104: addiu       $t2, $t1, 0x20
    ctx->r10 = ADD32(ctx->r9, 0X20);
    // 0x804C4108: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x804C410C: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
    // 0x804C4110: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x804C4114: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x804C4118: addiu       $t5, $t4, 0x20
    ctx->r13 = ADD32(ctx->r12, 0X20);
    // 0x804C411C: bne         $at, $zero, L_804C4128
    if (ctx->r1 != 0) {
        // 0x804C4120: sw          $t5, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r13;
            goto L_804C4128;
    }
    // 0x804C4120: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x804C4124: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
L_804C4128:
    // 0x804C4128: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x804C412C: slti        $at, $t8, 0x100
    ctx->r1 = SIGNED(ctx->r24) < 0X100 ? 1 : 0;
    // 0x804C4130: bnel        $at, $zero, L_804C4140
    if (ctx->r1 != 0) {
        // 0x804C4134: lw          $t0, 0x8($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X8);
            goto L_804C4140;
    }
    goto skip_0;
    // 0x804C4134: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    skip_0:
    // 0x804C4138: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x804C413C: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
L_804C4140:
    // 0x804C4140: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x804C4144: bnel        $at, $zero, L_804C4154
    if (ctx->r1 != 0) {
        // 0x804C4148: lw          $v1, 0x16C($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X16C);
            goto L_804C4154;
    }
    goto skip_1;
    // 0x804C4148: lw          $v1, 0x16C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X16C);
    skip_1:
    // 0x804C414C: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x804C4150: lw          $v1, 0x16C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X16C);
L_804C4154:
    // 0x804C4154: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x804C4158: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    // 0x804C415C: bne         $t2, $zero, L_804C4178
    if (ctx->r10 != 0) {
        // 0x804C4160: nop
    
            goto L_804C4178;
    }
    // 0x804C4160: nop

    // 0x804C4164: sb          $t3, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r11;
    // 0x804C4168: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x804C416C: sb          $t4, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r12;
    // 0x804C4170: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x804C4174: sb          $t5, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r13;
L_804C4178:
    // 0x804C4178: jr          $ra
    // 0x804C417C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x804C417C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_807B4A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4A10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B4A14: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B4A18: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B4A1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B4A20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B4A24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807B4A28: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x807B4A2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B4A30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B4A34: addiu       $s3, $zero, 0x80
    ctx->r19 = ADD32(0, 0X80);
    // 0x807B4A38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_807B4A3C:
    // 0x807B4A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B4A40: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B4A44: jal         0x8005C27C
    // 0x807B4A48: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x807B4A48: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_0:
    // 0x807B4A4C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B4A50: bnel        $s0, $s3, L_807B4A3C
    if (ctx->r16 != ctx->r19) {
        // 0x807B4A54: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_807B4A3C;
    }
    goto skip_0;
    // 0x807B4A54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x807B4A58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B4A5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B4A60: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B4A64: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B4A68: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B4A6C: jr          $ra
    // 0x807B4A70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B4A70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804C3CE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3CE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C3CE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C3CEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804C3CF0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C3CF4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x804C3CF8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x804C3CFC: addiu       $t7, $v0, 0x180
    ctx->r15 = ADD32(ctx->r2, 0X180);
    // 0x804C3D00: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x804C3D04: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x804C3D08: jal         0x804C3B5C
    // 0x804C3D0C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_804C3B5C(rdram, ctx);
        goto after_0;
    // 0x804C3D0C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x804C3D10: jal         0x804C3B7C
    // 0x804C3D14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_804C3B7C(rdram, ctx);
        goto after_1;
    // 0x804C3D14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x804C3D18: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804C3D1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804C3D20: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804C3D24: sw          $t8, 0x300($v0)
    MEM_W(0X300, ctx->r2) = ctx->r24;
    // 0x804C3D28: swc1        $f4, 0x908($v0)
    MEM_W(0X908, ctx->r2) = ctx->f4.u32l;
    // 0x804C3D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C3D30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C3D34: jr          $ra
    // 0x804C3D38: nop

    return;
    // 0x804C3D38: nop

;}
RECOMP_FUNC void func_8064BD98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BD98: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8064BD9C: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x8064BDA0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8064BDA4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8064BDA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064BDAC:
    // 0x8064BDAC: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8064BDB0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064BDB4: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8064BDB8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8064BDBC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8064BDC0: bc1f        L_8064BDE4
    if (!c1cs) {
        // 0x8064BDC4: swc1        $f8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
            goto L_8064BDE4;
    }
    // 0x8064BDC4: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x8064BDC8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064BDCC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8064BDD0: nop

    // 0x8064BDD4: bc1fl       L_8064BE00
    if (!c1cs) {
        // 0x8064BDD8: lwc1        $f18, 0x3C($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
            goto L_8064BE00;
    }
    goto skip_0;
    // 0x8064BDD8: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
    skip_0:
    // 0x8064BDDC: b           L_8064BDFC
    // 0x8064BDE0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_8064BDFC;
    // 0x8064BDE0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8064BDE4:
    // 0x8064BDE4: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064BDE8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8064BDEC: nop

    // 0x8064BDF0: bc1fl       L_8064BE00
    if (!c1cs) {
        // 0x8064BDF4: lwc1        $f18, 0x3C($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
            goto L_8064BE00;
    }
    goto skip_1;
    // 0x8064BDF4: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
    skip_1:
    // 0x8064BDF8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8064BDFC:
    // 0x8064BDFC: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
L_8064BE00:
    // 0x8064BE00: lwc1        $f4, 0xC4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x8064BE04: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8064BE08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8064BE0C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8064BE10: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8064BE14: bne         $v0, $a0, L_8064BDAC
    if (ctx->r2 != ctx->r4) {
        // 0x8064BE18: swc1        $f6, 0x38($v1)
        MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
            goto L_8064BDAC;
    }
    // 0x8064BE18: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
    // 0x8064BE1C: jr          $ra
    // 0x8064BE20: nop

    return;
    // 0x8064BE20: nop

;}
RECOMP_FUNC void func_807AE174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE174: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807AE178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AE17C: jal         0x8004700C
    // 0x807AE180: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807AE180: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x807AE184: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x807AE188: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AE18C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x807AE190: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x807AE194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807AE19C: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x807AE1A0: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x807AE1A4: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x807AE1A8: beql        $a0, $zero, L_807AE1C8
    if (ctx->r4 == 0) {
        // 0x807AE1AC: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_807AE1C8;
    }
    goto skip_0;
    // 0x807AE1AC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x807AE1B0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x807AE1B4: jal         0x807ADA60
    // 0x807AE1B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_807ADA60(rdram, ctx);
        goto after_1;
    // 0x807AE1B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x807AE1BC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x807AE1C0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x807AE1C4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_807AE1C8:
    // 0x807AE1C8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x807AE1CC: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(859, 0X24C0) << 16);
    // 0x807AE1D0: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807AE1D4: addiu       $v0, $v0, -0x14E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(859, 0X24C0));
    // 0x807AE1D8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x807AE1DC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26E8) << 16);
    // 0x807AE1E0: lwc1        $f10, -0x12B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26E8));
    // 0x807AE1E4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x807AE1E8: mflo        $t8
    ctx->r24 = lo;
    // 0x807AE1EC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807AE1F0: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x807AE1F4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x807AE1F8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x807AE1FC: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807AE200: mflo        $t1
    ctx->r9 = lo;
    // 0x807AE204: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x807AE208: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x807AE20C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x807AE210: lwc1        $f8, 0x8C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8C);
    // 0x807AE214: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x807AE218: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x807AE21C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807AE220: jal         0x807AD420
    // 0x807AE224: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_807AD420(rdram, ctx);
        goto after_2;
    // 0x807AE224: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x807AE228: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x807AE22C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x807AE230: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x807AE234: beq         $a3, $zero, L_807AE298
    if (ctx->r7 == 0) {
        // 0x807AE238: addiu       $t6, $zero, 0x3C
        ctx->r14 = ADD32(0, 0X3C);
            goto L_807AE298;
    }
    // 0x807AE238: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x807AE23C: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x807AE240: lw          $v0, 0x478($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X478);
    // 0x807AE244: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807AE248: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807AE24C: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x807AE250: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807AE254: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X24C8) << 16);
    // 0x807AE258: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x807AE25C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x807AE260: swc1        $f8, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f8.u32l;
    // 0x807AE264: lw          $v0, 0x478($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X478);
    // 0x807AE268: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x807AE26C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807AE270: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x807AE274: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x807AE278: swc1        $f4, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f4.u32l;
    // 0x807AE27C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x807AE280: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x807AE284: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x807AE288: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x807AE28C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x807AE290: lwc1        $f6, -0x14D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X24C8));
    // 0x807AE294: swc1        $f6, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->f6.u32l;
L_807AE298:
    // 0x807AE298: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x807AE29C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE2A0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x807AE2A4: sw          $t6, 0x1E0($t7)
    MEM_W(0X1E0, ctx->r15) = ctx->r14;
    // 0x807AE2A8: jal         0x807AEA24
    // 0x807AE2AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_807AEA24(rdram, ctx);
        goto after_3;
    // 0x807AE2AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x807AE2B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AE2B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807AE2B8: jr          $ra
    // 0x807AE2BC: nop

    return;
    // 0x807AE2BC: nop

;}
RECOMP_FUNC void func_80033DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033DAC: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x80033DB0: jal         0x80067930
    // 0x80033DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80033DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80033DB8: beq         $v0, $zero, L_80033DC8
    if (ctx->r2 == 0) {
        // 0x80033DBC: addiu       $a0, $zero, 0x5A
        ctx->r4 = ADD32(0, 0X5A);
            goto L_80033DC8;
    }
    // 0x80033DBC: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x80033DC0: jal         0x80067878
    // 0x80033DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x80033DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80033DC8:
    // 0x80033DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033DD0: jr          $ra
    // 0x80033DD4: nop

    return;
    // 0x80033DD4: nop

;}
RECOMP_FUNC void func_8044E8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044E8B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8044E8B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044E8B8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044E8BC: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x8044E8C0: slti        $at, $a1, 0xB4
    ctx->r1 = SIGNED(ctx->r5) < 0XB4 ? 1 : 0;
    // 0x8044E8C4: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8044E8C8: lw          $a3, 0x6A94($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6A94);
    // 0x8044E8CC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8044E8D0: bne         $at, $zero, L_8044E8DC
    if (ctx->r1 != 0) {
        // 0x8044E8D4: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8044E8DC;
    }
    // 0x8044E8D4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8044E8D8: addiu       $a2, $zero, 0xB3
    ctx->r6 = ADD32(0, 0XB3);
L_8044E8DC:
    // 0x8044E8DC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8044E8E0: jal         0x8044BFA8
    // 0x8044E8E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_8044BFA8(rdram, ctx);
        goto after_0;
    // 0x8044E8E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x8044E8E8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8044E8EC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8044E8F0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8044E8F4: jal         0x8006C56C
    // 0x8044E8F8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_8006C56C(rdram, ctx);
        goto after_1;
    // 0x8044E8F8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8044E8FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044E900: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8044E904: jr          $ra
    // 0x8044E908: nop

    return;
    // 0x8044E908: nop

;}
RECOMP_FUNC void gfxprint_cleanup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FA40: jr          $ra
    // 0x8007FA44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8007FA44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80554FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80554FFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80555000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80555004: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80555008: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8055500C: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x80555010: lw          $a0, 0x554($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X554);
    // 0x80555014: jal         0x80067878
    // 0x80555018: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80555018: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8055501C: jal         0x80045BD8
    // 0x80555020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80555020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80555024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80555028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8055502C: jr          $ra
    // 0x80555030: nop

    return;
    // 0x80555030: nop

;}
RECOMP_FUNC void roundf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800820C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800820C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800820C8: nop

    // 0x800820CC: add.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x800820D0: floor.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = S32(floorf(ctx->f0.fl));
    // 0x800820D4: jr          $ra
    // 0x800820D8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    return;
    // 0x800820D8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
;}
RECOMP_FUNC void func_8064A70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A70C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A714: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064A718: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064A71C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064A720: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8064A724: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8064A728: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064A72C: bne         $v0, $at, L_8064A754
    if (ctx->r2 != ctx->r1) {
        // 0x8064A730: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8064A754;
    }
    // 0x8064A730: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064A734: jal         0x8064A1C8
    // 0x8064A738: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8064A1C8(rdram, ctx);
        goto after_0;
    // 0x8064A738: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8064A73C: beq         $v0, $zero, L_8064A754
    if (ctx->r2 == 0) {
        // 0x8064A740: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8064A754;
    }
    // 0x8064A740: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8064A744: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8064A748: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8064A74C: jal         0x8002F6E4
    // 0x8064A750: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8064A750: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8064A754:
    // 0x8064A754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064A758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A75C: jr          $ra
    // 0x8064A760: nop

    return;
    // 0x8064A760: nop

;}
RECOMP_FUNC void fsin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082730: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80082734: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80082738: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8008273C: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80082740: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x80082744: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x80082748: beq         $at, $zero, L_800827B0
    if (ctx->r1 == 0) {
        // 0x8008274C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800827B0;
    }
    // 0x8008274C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80082750: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x80082754: bne         $at, $zero, L_800827A8
    if (ctx->r1 != 0) {
        // 0x80082758: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800827A8;
    }
    // 0x80082758: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x8008275C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80082760: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80082764: addiu       $v1, $v1, 0x3220
    ctx->r3 = ADD32(ctx->r3, 0X3220);
    // 0x80082768: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x8008276C: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x80082770: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x80082774: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x80082778: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8008277C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x80082780: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x80082784: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80082788: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x8008278C: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x80082790: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80082794: nop

    // 0x80082798: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x8008279C: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800827A0: jr          $ra
    // 0x800827A4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800827A4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800827A8:
    // 0x800827A8: jr          $ra
    // 0x800827AC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x800827AC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_800827B0:
    // 0x800827B0: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x800827B4: beq         $at, $zero, L_800828C8
    if (ctx->r1 == 0) {
        // 0x800827B8: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_800828C8;
    }
    // 0x800827B8: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800827BC: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800827C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800827C4: ldc1        $f10, 0x3248($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X3248);
    // 0x800827C8: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x800827CC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800827D0: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x800827D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800827D8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800827DC: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800827E0: nop

    // 0x800827E4: bc1fl       L_80082814
    if (!c1cs) {
        // 0x800827E8: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_80082814;
    }
    goto skip_0;
    // 0x800827E8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800827EC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800827F0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800827F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800827F8: nop

    // 0x800827FC: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x80082800: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x80082804: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80082808: b           L_80082830
    // 0x8008280C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_80082830;
    // 0x8008280C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80082810: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_80082814:
    // 0x80082814: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80082818: nop

    // 0x8008281C: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x80082820: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80082824: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80082828: nop

    // 0x8008282C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_80082830:
    // 0x80082830: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80082834: ldc1        $f18, 0x3250($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X3250);
    // 0x80082838: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x8008283C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80082840: ldc1        $f6, 0x3258($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X3258);
    // 0x80082844: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80082848: addiu       $v1, $v1, 0x3220
    ctx->r3 = ADD32(ctx->r3, 0X3220);
    // 0x8008284C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x80082850: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x80082854: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x80082858: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8008285C: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x80082860: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x80082864: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x80082868: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x8008286C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80082870: nop

    // 0x80082874: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x80082878: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8008287C: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x80082880: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x80082884: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80082888: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x8008288C: bne         $t9, $zero, L_800828AC
    if (ctx->r25 != 0) {
        // 0x80082890: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_800828AC;
    }
    // 0x80082890: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x80082894: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80082898: nop

    // 0x8008289C: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x800828A0: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800828A4: jr          $ra
    // 0x800828A8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800828A8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800828AC:
    // 0x800828AC: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800828B0: nop

    // 0x800828B4: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800828B8: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x800828BC: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x800828C0: jr          $ra
    // 0x800828C4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800828C4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800828C8:
    // 0x800828C8: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x800828CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800828D0: bc1t        L_800828E4
    if (c1cs) {
        // 0x800828D4: nop
    
            goto L_800828E4;
    }
    // 0x800828D4: nop

    // 0x800828D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800828DC: jr          $ra
    // 0x800828E0: lwc1        $f0, 0x3440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3440);
    return;
    // 0x800828E0: lwc1        $f0, 0x3440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3440);
L_800828E4:
    // 0x800828E4: lwc1        $f0, 0x3260($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3260);
    // 0x800828E8: jr          $ra
    // 0x800828EC: nop

    return;
    // 0x800828EC: nop

;}
RECOMP_FUNC void func_80521CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80521CA8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80521CAC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80521CB0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80521CB4: jal         0x80048F84
    // 0x80521CB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80521CB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80521CBC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80521CC0: lh          $t6, 0x184($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X184);
    // 0x80521CC4: bnel        $t6, $zero, L_80521D20
    if (ctx->r14 != 0) {
        // 0x80521CC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80521D20;
    }
    goto skip_0;
    // 0x80521CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80521CCC: lw          $t7, 0x1E0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1E0);
    // 0x80521CD0: bnel        $t7, $zero, L_80521D20
    if (ctx->r15 != 0) {
        // 0x80521CD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80521D20;
    }
    goto skip_1;
    // 0x80521CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80521CD8: lhu         $t8, 0xC($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0XC);
    // 0x80521CDC: addiu       $at, $zero, 0x41DC
    ctx->r1 = ADD32(0, 0X41DC);
    // 0x80521CE0: bne         $t8, $at, L_80521CFC
    if (ctx->r24 != ctx->r1) {
        // 0x80521CE4: nop
    
            goto L_80521CFC;
    }
    // 0x80521CE4: nop

    // 0x80521CE8: jal         0x80521C00
    // 0x80521CEC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80521C00(rdram, ctx);
        goto after_1;
    // 0x80521CEC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80521CF0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80521CF4: b           L_80521D0C
    // 0x80521CF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80521D0C;
    // 0x80521CF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80521CFC:
    // 0x80521CFC: jal         0x80521C50
    // 0x80521D00: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80521C50(rdram, ctx);
        goto after_2;
    // 0x80521D00: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80521D04: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80521D08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80521D0C:
    // 0x80521D0C: beql        $v0, $zero, L_80521D20
    if (ctx->r2 == 0) {
        // 0x80521D10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80521D20;
    }
    goto skip_2;
    // 0x80521D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80521D14: jal         0x80047F9C
    // 0x80521D18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x80521D18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80521D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80521D20:
    // 0x80521D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80521D24: jr          $ra
    // 0x80521D28: nop

    return;
    // 0x80521D28: nop

;}
