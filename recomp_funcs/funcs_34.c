#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8046A180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8046A184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046A188: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046A18C: jal         0x8004700C
    // 0x8046A190: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8046A190: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8046A194: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8046A198: jal         0x8046B08C
    // 0x8046A19C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046B08C(rdram, ctx);
        goto after_1;
    // 0x8046A19C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8046A1A0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8046A1A4: beql        $t6, $zero, L_8046A1E8
    if (ctx->r14 == 0) {
        // 0x8046A1A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8046A1E8;
    }
    goto skip_0;
    // 0x8046A1A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8046A1AC: jal         0x80048378
    // 0x8046A1B0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    func_80048378(rdram, ctx);
        goto after_2;
    // 0x8046A1B0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    after_2:
    // 0x8046A1B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046A1B8: jal         0x80062684
    // 0x8046A1BC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062684(rdram, ctx);
        goto after_3;
    // 0x8046A1BC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_3:
    // 0x8046A1C0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8046A1C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046A1C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046A1CC: lw          $t8, 0x180($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X180);
    // 0x8046A1D0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8046A1D4: bnel        $s0, $t8, L_8046A1E8
    if (ctx->r16 != ctx->r24) {
        // 0x8046A1D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8046A1E8;
    }
    goto skip_1;
    // 0x8046A1D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8046A1DC: jal         0x8046B2D8
    // 0x8046A1E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8046B2D8(rdram, ctx);
        goto after_4;
    // 0x8046A1E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8046A1E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046A1E8:
    // 0x8046A1E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046A1EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8046A1F0: jr          $ra
    // 0x8046A1F4: nop

    return;
    // 0x8046A1F4: nop

;}
RECOMP_FUNC void func_8079DEA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079DEA0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8079DEA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8079DEA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8079DEAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8079DEB0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8079DEB4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8079DEB8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8079DEBC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8079DEC0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8079DEC4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8079DEC8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8079DECC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8079DED0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8079DED4: lw          $s6, 0x1F4($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079DED8: lui         $a0, 0x4014
    ctx->r4 = S32(0X4014 << 16);
    // 0x8079DEDC: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x8079DEE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8079DEE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8079DEE8: addiu       $s7, $zero, 0x1F
    ctx->r23 = ADD32(0, 0X1F);
    // 0x8079DEEC: sw          $s0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r16;
    // 0x8079DEF0: jal         0x8004613C
    // 0x8079DEF4: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x8079DEF4: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    after_0:
    // 0x8079DEF8: sw          $v0, 0x88($s6)
    MEM_W(0X88, ctx->r22) = ctx->r2;
    // 0x8079DEFC: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8079DF00: jal         0x80047F9C
    // 0x8079DF04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x8079DF04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8079DF08: lw          $t7, 0x88($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X88);
    // 0x8079DF0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8079DF10: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x8079DF14: sb          $t6, 0x17C($t7)
    MEM_B(0X17C, ctx->r15) = ctx->r14;
    // 0x8079DF18: lw          $t8, 0x88($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X88);
    // 0x8079DF1C: lui         $s2, 0x807A
    ctx->r18 = S32(RELOC_HI16(835, 0X18E0) << 16);
    // 0x8079DF20: lui         $s3, 0x807A
    ctx->r19 = S32(RELOC_HI16(835, 0X1728) << 16);
    // 0x8079DF24: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x8079DF28: lui         $s1, 0x807A
    ctx->r17 = S32(RELOC_HI16(835, 0X1788) << 16);
    // 0x8079DF2C: lui         $s5, 0x807A
    ctx->r21 = S32(RELOC_HI16(835, 0X17E8) << 16);
    // 0x8079DF30: addiu       $s5, $s5, -0xD28
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(835, 0X17E8));
    // 0x8079DF34: addiu       $s1, $s1, -0xD88
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(835, 0X1788));
    // 0x8079DF38: addiu       $s3, $s3, -0xDE8
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(835, 0X1728));
    // 0x8079DF3C: addiu       $s2, $s2, -0xC30
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(835, 0X18E0));
    // 0x8079DF40: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x8079DF44: addiu       $s4, $sp, 0x78
    ctx->r20 = ADD32(ctx->r29, 0X78);
    // 0x8079DF48: sb          $fp, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r30;
L_8079DF4C:
    // 0x8079DF4C: lhu         $t0, 0x0($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X0);
    // 0x8079DF50: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8079DF54: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8079DF58: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8079DF5C: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x8079DF60: sh          $t0, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r8;
    // 0x8079DF64: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x8079DF68: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x8079DF6C: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x8079DF70: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8079DF74: lw          $t9, 0xA4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0XA4);
    // 0x8079DF78: jalr        $t9
    // 0x8079DF7C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8079DF7C: nop

    after_2:
    // 0x8079DF80: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8079DF84: sltu        $at, $s1, $s5
    ctx->r1 = ctx->r17 < ctx->r21 ? 1 : 0;
    // 0x8079DF88: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8079DF8C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8079DF90: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8079DF94: bne         $at, $zero, L_8079DF4C
    if (ctx->r1 != 0) {
        // 0x8079DF98: sw          $v0, 0x88($s0)
        MEM_W(0X88, ctx->r16) = ctx->r2;
            goto L_8079DF4C;
    }
    // 0x8079DF98: sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    // 0x8079DF9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8079DFA0: lui         $a0, 0x46E9
    ctx->r4 = S32(0X46E9 << 16);
    // 0x8079DFA4: lui         $a3, 0x7F7F
    ctx->r7 = S32(0X7F7F << 16);
    // 0x8079DFA8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8079DFAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8079DFB0: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x8079DFB4: jal         0x8004613C
    // 0x8079DFB8: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x8079DFB8: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    after_3:
    // 0x8079DFBC: sw          $v0, 0x84($s6)
    MEM_W(0X84, ctx->r22) = ctx->r2;
    // 0x8079DFC0: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8079DFC4: jal         0x80047F9C
    // 0x8079DFC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x8079DFC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8079DFCC: lw          $t4, 0x84($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X84);
    // 0x8079DFD0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8079DFD4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1964) << 16);
    // 0x8079DFD8: sb          $t3, 0x17C($t4)
    MEM_B(0X17C, ctx->r12) = ctx->r11;
    // 0x8079DFDC: lwc1        $f8, -0xBAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1964));
    // 0x8079DFE0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079DFE4: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x8079DFE8: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x8079DFEC: lui         $a2, 0xC1A8
    ctx->r6 = S32(0XC1A8 << 16);
    // 0x8079DFF0: lui         $a3, 0xC290
    ctx->r7 = S32(0XC290 << 16);
    // 0x8079DFF4: jal         0x8005CEBC
    // 0x8079DFF8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_5;
    // 0x8079DFF8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x8079DFFC: sw          $v0, 0x7C($s6)
    MEM_W(0X7C, ctx->r22) = ctx->r2;
    // 0x8079E000: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8079E004: jal         0x80047F9C
    // 0x8079E008: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x8079E008: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8079E00C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1968) << 16);
    // 0x8079E010: lwc1        $f0, -0xBA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1968));
    // 0x8079E014: lw          $t5, 0x7C($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X7C);
    // 0x8079E018: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8079E01C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8079E020: swc1        $f0, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f0.u32l;
    // 0x8079E024: lw          $t6, 0x7C($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X7C);
    // 0x8079E028: addiu       $a0, $zero, 0x4730
    ctx->r4 = ADD32(0, 0X4730);
    // 0x8079E02C: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x8079E030: swc1        $f0, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f0.u32l;
    // 0x8079E034: lw          $t7, 0x7C($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X7C);
    // 0x8079E038: lui         $a2, 0xC1A8
    ctx->r6 = S32(0XC1A8 << 16);
    // 0x8079E03C: lui         $a3, 0xC290
    ctx->r7 = S32(0XC290 << 16);
    // 0x8079E040: lw          $t8, 0x16C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X16C);
    // 0x8079E044: sb          $zero, 0xD($t8)
    MEM_B(0XD, ctx->r24) = 0;
    // 0x8079E048: lw          $t0, 0x7C($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X7C);
    // 0x8079E04C: lw          $t1, 0x16C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X16C);
    // 0x8079E050: sb          $zero, 0xE($t1)
    MEM_B(0XE, ctx->r9) = 0;
    // 0x8079E054: lw          $t2, 0x7C($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X7C);
    // 0x8079E058: lw          $t9, 0x16C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X16C);
    // 0x8079E05C: sb          $fp, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r30;
    // 0x8079E060: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8079E064: jal         0x8005CEBC
    // 0x8079E068: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_7;
    // 0x8079E068: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x8079E06C: sw          $v0, 0x80($s6)
    MEM_W(0X80, ctx->r22) = ctx->r2;
    // 0x8079E070: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8079E074: jal         0x80047F9C
    // 0x8079E078: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_8;
    // 0x8079E078: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x8079E07C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X196C) << 16);
    // 0x8079E080: lwc1        $f0, -0xBA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X196C));
    // 0x8079E084: lw          $t3, 0x80($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X80);
    // 0x8079E088: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x8079E08C: or          $s1, $sp, $zero
    ctx->r17 = ctx->r29 | 0;
    // 0x8079E090: swc1        $f0, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f0.u32l;
    // 0x8079E094: lw          $t4, 0x80($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X80);
    // 0x8079E098: addiu       $s1, $s1, 0x67
    ctx->r17 = ADD32(ctx->r17, 0X67);
    // 0x8079E09C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8079E0A0: swc1        $f0, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f0.u32l;
    // 0x8079E0A4: lw          $t5, 0x80($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X80);
    // 0x8079E0A8: srl         $s1, $s1, 3
    ctx->r17 = S32(U32(ctx->r17) >> 3);
    // 0x8079E0AC: lui         $s3, 0x8006
    ctx->r19 = S32(0X8006 << 16);
    // 0x8079E0B0: lw          $t6, 0x16C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X16C);
    // 0x8079E0B4: lui         $t5, 0x361
    ctx->r13 = S32(0X361 << 16);
    // 0x8079E0B8: addiu       $t5, $t5, -0x2570
    ctx->r13 = ADD32(ctx->r13, -0X2570);
    // 0x8079E0BC: sb          $zero, 0xD($t6)
    MEM_B(0XD, ctx->r14) = 0;
    // 0x8079E0C0: lw          $t7, 0x80($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X80);
    // 0x8079E0C4: addiu       $s3, $s3, 0x758C
    ctx->r19 = ADD32(ctx->r19, 0X758C);
    // 0x8079E0C8: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x8079E0CC: lw          $t8, 0x16C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X16C);
    // 0x8079E0D0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8079E0D4: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x8079E0D8: sb          $zero, 0xE($t8)
    MEM_B(0XE, ctx->r24) = 0;
    // 0x8079E0DC: lw          $t0, 0x80($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X80);
    // 0x8079E0E0: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
    // 0x8079E0E4: lw          $t1, 0x16C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X16C);
    // 0x8079E0E8: sb          $fp, 0xF($t1)
    MEM_B(0XF, ctx->r9) = ctx->r30;
    // 0x8079E0EC: lw          $t2, -0x71A8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X71A8);
    // 0x8079E0F0: ori         $fp, $zero, 0xFFFF
    ctx->r30 = 0 | 0XFFFF;
    // 0x8079E0F4: sll         $t9, $t2, 4
    ctx->r25 = S32(ctx->r10 << 4);
    // 0x8079E0F8: srl         $t3, $t9, 30
    ctx->r11 = S32(U32(ctx->r25) >> 30);
    // 0x8079E0FC: bnel        $t3, $at, L_8079E10C
    if (ctx->r11 != ctx->r1) {
        // 0x8079E100: sll         $t4, $s7, 2
        ctx->r12 = S32(ctx->r23 << 2);
            goto L_8079E10C;
    }
    goto skip_0;
    // 0x8079E100: sll         $t4, $s7, 2
    ctx->r12 = S32(ctx->r23 << 2);
    skip_0:
    // 0x8079E104: addiu       $s7, $zero, 0xD0
    ctx->r23 = ADD32(0, 0XD0);
    // 0x8079E108: sll         $t4, $s7, 2
    ctx->r12 = S32(ctx->r23 << 2);
L_8079E10C:
    // 0x8079E10C: subu        $t4, $t4, $s7
    ctx->r12 = SUB32(ctx->r12, ctx->r23);
    // 0x8079E110: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8079E114: addu        $s2, $t4, $t5
    ctx->r18 = ADD32(ctx->r12, ctx->r13);
    // 0x8079E118: addiu       $s7, $zero, 0x1000
    ctx->r23 = ADD32(0, 0X1000);
L_8079E11C:
    // 0x8079E11C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8079E120: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8079E124: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8079E128: jal         0x800675D0
    // 0x8079E12C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_800675D0(rdram, ctx);
        goto after_9;
    // 0x8079E12C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_9:
    // 0x8079E130: jal         0x80064D1C
    // 0x8079E134: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    func_80064D1C(rdram, ctx);
        goto after_10;
    // 0x8079E134: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    after_10:
    // 0x8079E138: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8079E13C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8079E140: lw          $t8, -0x71A4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X71A4);
    // 0x8079E144: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8079E148: sllv        $t7, $t6, $s4
    ctx->r15 = S32(ctx->r14 << (ctx->r20 & 31));
    // 0x8079E14C: and         $t0, $t7, $t8
    ctx->r8 = ctx->r15 & ctx->r24;
    // 0x8079E150: beq         $t0, $zero, L_8079E170
    if (ctx->r8 == 0) {
        // 0x8079E154: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8079E170;
    }
    // 0x8079E154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8079E158: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8079E15C: lhu         $a2, 0x4($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X4);
    // 0x8079E160: jal         0x800675D0
    // 0x8079E164: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_800675D0(rdram, ctx);
        goto after_11;
    // 0x8079E164: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_11:
    // 0x8079E168: b           L_8079E184
    // 0x8079E16C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_8079E184;
    // 0x8079E16C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8079E170:
    // 0x8079E170: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    // 0x8079E174: sh          $s7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r23;
    // 0x8079E178: lw          $t2, 0x18($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X18);
    // 0x8079E17C: sh          $fp, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r30;
    // 0x8079E180: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8079E184:
    // 0x8079E184: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8079E188: bne         $s4, $s5, L_8079E11C
    if (ctx->r20 != ctx->r21) {
        // 0x8079E18C: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_8079E11C;
    }
    // 0x8079E18C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x8079E190: lui         $a0, 0x46F8
    ctx->r4 = S32(0X46F8 << 16);
    // 0x8079E194: lui         $a3, 0x7F7F
    ctx->r7 = S32(0X7F7F << 16);
    // 0x8079E198: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x8079E19C: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x8079E1A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8079E1A4: jal         0x8004613C
    // 0x8079E1A8: lui         $a2, 0x4370
    ctx->r6 = S32(0X4370 << 16);
    func_8004613C(rdram, ctx);
        goto after_12;
    // 0x8079E1A8: lui         $a2, 0x4370
    ctx->r6 = S32(0X4370 << 16);
    after_12:
    // 0x8079E1AC: sw          $v0, 0x78($s6)
    MEM_W(0X78, ctx->r22) = ctx->r2;
    // 0x8079E1B0: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8079E1B4: jal         0x80047F9C
    // 0x8079E1B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_13;
    // 0x8079E1B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x8079E1BC: lw          $t3, 0x78($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X78);
    // 0x8079E1C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8079E1C4: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x8079E1C8: sb          $t9, 0x17C($t3)
    MEM_B(0X17C, ctx->r11) = ctx->r25;
    // 0x8079E1CC: lbu         $t6, -0x7203($t4)
    ctx->r14 = MEM_BU(ctx->r12, -0X7203);
    // 0x8079E1D0: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x8079E1D4: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x8079E1D8: lbu         $t7, -0x7204($t5)
    ctx->r15 = MEM_BU(ctx->r13, -0X7204);
    // 0x8079E1DC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8079E1E0: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x8079E1E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8079E1E8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8079E1EC: sw          $zero, 0x14($s6)
    MEM_W(0X14, ctx->r22) = 0;
    // 0x8079E1F0: sw          $t7, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r15;
    // 0x8079E1F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8079E1F8: swc1        $f18, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f18.u32l;
    // 0x8079E1FC: swc1        $f6, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->f6.u32l;
    // 0x8079E200: jal         0x8079DB4C
    // 0x8079E204: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    func_8079DB4C(rdram, ctx);
        goto after_14;
    // 0x8079E204: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_14:
    // 0x8079E208: lw          $t8, 0x4($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X4);
    // 0x8079E20C: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x8079E210: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8079E214: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8079E218: jal         0x8079E800
    // 0x8079E21C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    func_8079E800(rdram, ctx);
        goto after_15;
    // 0x8079E21C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_15:
    // 0x8079E220: lw          $t2, 0x4($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X4);
    // 0x8079E224: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x8079E228: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8079E22C: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x8079E230: jal         0x8079EC04
    // 0x8079E234: addu        $a1, $t9, $t3
    ctx->r5 = ADD32(ctx->r25, ctx->r11);
    func_8079EC04(rdram, ctx);
        goto after_16;
    // 0x8079E234: addu        $a1, $t9, $t3
    ctx->r5 = ADD32(ctx->r25, ctx->r11);
    after_16:
    // 0x8079E238: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8079E23C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8079E240: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8079E244: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8079E248: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8079E24C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8079E250: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8079E254: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8079E258: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8079E25C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8079E260: jr          $ra
    // 0x8079E264: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8079E264: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8043B17C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B17C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043B180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043B184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8043B188: jal         0x80045A34
    // 0x8043B18C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8043B18C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x8043B190: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043B194: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8043B198: bne         $v0, $zero, L_8043B1A8
    if (ctx->r2 != 0) {
        // 0x8043B19C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8043B1A8;
    }
    // 0x8043B19C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8043B1A0: b           L_8043B21C
    // 0x8043B1A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043B21C;
    // 0x8043B1A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043B1A8:
    // 0x8043B1A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8043B1AC: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11E0) << 16);
    // 0x8043B1B0: lwc1        $f4, -0x47C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11E0));
    // 0x8043B1B4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043B1B8: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    // 0x8043B1BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043B1C0: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8043B1C4: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8043B1C8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043B1CC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8043B1D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8043B1D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8043B1D8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8043B1DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043B1E0: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8043B1E4: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8043B1E8: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x8043B1EC: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x8043B1F0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8043B1F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8043B1F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8043B1FC: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x8043B200: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8043B204: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8043B208: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x8043B20C: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8043B210: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x8043B214: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8043B218: swc1        $f4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f4.u32l;
L_8043B21C:
    // 0x8043B21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043B220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043B224: jr          $ra
    // 0x8043B228: nop

    return;
    // 0x8043B228: nop

;}
RECOMP_FUNC void func_8002B470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B470: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002B474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002B478: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002B47C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8002B480: lw          $a0, 0x164($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X164);
    // 0x8002B484: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x8002B488: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x8002B48C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8002B490: lw          $v1, 0xF10($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XF10);
    // 0x8002B494: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8002B498: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8002B49C: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x8002B4A0: lhu         $t7, 0x18($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X18);
    // 0x8002B4A4: lhu         $t9, 0x1A($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1A);
    // 0x8002B4A8: lw          $s0, 0xF14($t2)
    ctx->r16 = MEM_W(ctx->r10, 0XF14);
    // 0x8002B4AC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8002B4B0: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x8002B4B4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8002B4B8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8002B4BC: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x8002B4C0: jal         0x8002B088
    // 0x8002B4C4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_8002B088(rdram, ctx);
        goto after_0;
    // 0x8002B4C4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002B4C8: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8002B4CC: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8002B4D0: lw          $t3, 0xAA0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0XAA0);
    // 0x8002B4D4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002B4D8: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8002B4DC: bne         $v0, $t3, L_8002B4EC
    if (ctx->r2 != ctx->r11) {
        // 0x8002B4E0: lw          $t5, 0x38($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X38);
            goto L_8002B4EC;
    }
    // 0x8002B4E0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8002B4E4: b           L_8002B518
    // 0x8002B4E8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
        goto L_8002B518;
    // 0x8002B4E8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8002B4EC:
    // 0x8002B4EC: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8002B4F0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8002B4F4: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8002B4F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002B4FC: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8002B500: lw          $t6, -0x20BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X20BC);
    // 0x8002B504: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8002B508: lw          $t8, -0x209C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X209C);
    // 0x8002B50C: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8002B510: srlv        $t9, $t7, $t8
    ctx->r25 = S32(U32(ctx->r15) >> (ctx->r24 & 31));
    // 0x8002B514: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8002B518:
    // 0x8002B518: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B51C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8002B520: addiu       $t2, $zero, 0xB4
    ctx->r10 = ADD32(0, 0XB4);
    // 0x8002B524: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002B528: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8002B52C: lw          $v0, -0x207C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X207C);
    // 0x8002B530: sw          $t2, 0x1400($a1)
    MEM_W(0X1400, ctx->r5) = ctx->r10;
    // 0x8002B534: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8002B538: sw          $v0, 0x178($a1)
    MEM_W(0X178, ctx->r5) = ctx->r2;
    // 0x8002B53C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B540: beql        $t3, $zero, L_8002B5A4
    if (ctx->r11 == 0) {
        // 0x8002B544: lw          $t5, 0xAA4($a3)
        ctx->r13 = MEM_W(ctx->r7, 0XAA4);
            goto L_8002B5A4;
    }
    goto skip_0;
    // 0x8002B544: lw          $t5, 0xAA4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0XAA4);
    skip_0:
    // 0x8002B548: bnel        $t3, $at, L_8002B5E0
    if (ctx->r11 != ctx->r1) {
        // 0x8002B54C: slti        $at, $s0, 0x8
        ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
            goto L_8002B5E0;
    }
    goto skip_1;
    // 0x8002B54C: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    skip_1:
    // 0x8002B550: jal         0x8001D770
    // 0x8002B554: nop

    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x8002B554: nop

    after_1:
    // 0x8002B558: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8002B55C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002B560: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    // 0x8002B564: jal         0x80067BF8
    // 0x8002B568: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x8002B568: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    after_2:
    // 0x8002B56C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x8002B570: jal         0x80067818
    // 0x8002B574: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8002B574: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8002B578: addiu       $a0, $zero, 0x262
    ctx->r4 = ADD32(0, 0X262);
    // 0x8002B57C: jal         0x80067818
    // 0x8002B580: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8002B580: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8002B584: addiu       $t4, $zero, 0x4B0
    ctx->r12 = ADD32(0, 0X4B0);
    // 0x8002B588: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002B58C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8002B590: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
    // 0x8002B594: sw          $t4, -0x76BC($at)
    MEM_W(-0X76BC, ctx->r1) = ctx->r12;
    // 0x8002B598: b           L_8002B65C
    // 0x8002B59C: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
        goto L_8002B65C;
    // 0x8002B59C: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8002B5A0: lw          $t5, 0xAA4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0XAA4);
L_8002B5A4:
    // 0x8002B5A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002B5A8: beq         $t5, $zero, L_8002B5B4
    if (ctx->r13 == 0) {
        // 0x8002B5AC: nop
    
            goto L_8002B5B4;
    }
    // 0x8002B5AC: nop

    // 0x8002B5B0: sw          $zero, 0xAA4($a3)
    MEM_W(0XAA4, ctx->r7) = 0;
L_8002B5B4:
    // 0x8002B5B4: blezl       $s0, L_8002B660
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8002B5B8: lw          $t7, 0xF10($a3)
        ctx->r15 = MEM_W(ctx->r7, 0XF10);
            goto L_8002B660;
    }
    goto skip_2;
    // 0x8002B5B8: lw          $t7, 0xF10($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XF10);
    skip_2:
    // 0x8002B5BC: jal         0x80067D28
    // 0x8002B5C0: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    func_80067D28(rdram, ctx);
        goto after_5;
    // 0x8002B5C0: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    after_5:
    // 0x8002B5C4: addiu       $a0, $zero, 0x25F
    ctx->r4 = ADD32(0, 0X25F);
    // 0x8002B5C8: jal         0x80067818
    // 0x8002B5CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8002B5CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8002B5D0: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8002B5D4: b           L_8002B65C
    // 0x8002B5D8: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
        goto L_8002B65C;
    // 0x8002B5D8: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8002B5DC: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
L_8002B5E0:
    // 0x8002B5E0: beq         $at, $zero, L_8002B65C
    if (ctx->r1 == 0) {
        // 0x8002B5E4: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8002B65C;
    }
    // 0x8002B5E4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8002B5E8: beq         $v0, $zero, L_8002B640
    if (ctx->r2 == 0) {
        // 0x8002B5EC: addu        $s0, $s0, $v0
        ctx->r16 = ADD32(ctx->r16, ctx->r2);
            goto L_8002B640;
    }
    // 0x8002B5EC: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8002B5F0: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8002B5F4: bne         $at, $zero, L_8002B640
    if (ctx->r1 != 0) {
        // 0x8002B5F8: addiu       $a0, $zero, 0x242
        ctx->r4 = ADD32(0, 0X242);
            goto L_8002B640;
    }
    // 0x8002B5F8: addiu       $a0, $zero, 0x242
    ctx->r4 = ADD32(0, 0X242);
    // 0x8002B5FC: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x8002B600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002B604: jal         0x80067818
    // 0x8002B608: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8002B608: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_7:
    // 0x8002B60C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8002B610: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8002B614: subu        $a0, $t6, $v1
    ctx->r4 = SUB32(ctx->r14, ctx->r3);
    // 0x8002B618: beq         $a0, $zero, L_8002B634
    if (ctx->r4 == 0) {
        // 0x8002B61C: nop
    
            goto L_8002B634;
    }
    // 0x8002B61C: nop

    // 0x8002B620: jal         0x80067D28
    // 0x8002B624: nop

    func_80067D28(rdram, ctx);
        goto after_8;
    // 0x8002B624: nop

    after_8:
    // 0x8002B628: addiu       $a0, $zero, 0x260
    ctx->r4 = ADD32(0, 0X260);
    // 0x8002B62C: jal         0x80067818
    // 0x8002B630: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x8002B630: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
L_8002B634:
    // 0x8002B634: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8002B638: b           L_8002B65C
    // 0x8002B63C: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
        goto L_8002B65C;
    // 0x8002B63C: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
L_8002B640:
    // 0x8002B640: jal         0x80067D28
    // 0x8002B644: subu        $a0, $s0, $v1
    ctx->r4 = SUB32(ctx->r16, ctx->r3);
    func_80067D28(rdram, ctx);
        goto after_10;
    // 0x8002B644: subu        $a0, $s0, $v1
    ctx->r4 = SUB32(ctx->r16, ctx->r3);
    after_10:
    // 0x8002B648: addiu       $a0, $zero, 0x260
    ctx->r4 = ADD32(0, 0X260);
    // 0x8002B64C: jal         0x80067818
    // 0x8002B650: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_11;
    // 0x8002B650: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x8002B654: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8002B658: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
L_8002B65C:
    // 0x8002B65C: lw          $t7, 0xF10($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XF10);
L_8002B660:
    // 0x8002B660: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002B664: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8002B668: sw          $s0, 0xF14($t9)
    MEM_W(0XF14, ctx->r25) = ctx->r16;
    // 0x8002B66C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B670: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8002B674: jal         0x8002B200
    // 0x8002B678: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8002B200(rdram, ctx);
        goto after_12;
    // 0x8002B678: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_12:
    // 0x8002B67C: jal         0x8002B3A0
    // 0x8002B680: nop

    func_8002B3A0(rdram, ctx);
        goto after_13;
    // 0x8002B680: nop

    after_13:
    // 0x8002B684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B688: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002B68C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8002B690: jr          $ra
    // 0x8002B694: nop

    return;
    // 0x8002B694: nop

;}
RECOMP_FUNC void func_80475960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475960: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475964: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475968: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047596C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475970: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475974: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475978: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047597C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475980: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475984: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475988: jr          $ra
    // 0x8047598C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047598C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806E5CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E5CC0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x806E5CC4: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(655, 0X11D0) << 16);
    // 0x806E5CC8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x806E5CCC: addiu       $t6, $t6, 0x6E90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(655, 0X11D0));
    // 0x806E5CD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x806E5CD4: sw          $t6, 0xECC($v1)
    MEM_W(0XECC, ctx->r3) = ctx->r14;
    // 0x806E5CD8: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(655, 0XCE8) << 16);
    // 0x806E5CDC: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x806E5CE0: jr          $ra
    // 0x806E5CE4: addiu       $v0, $v0, 0x69A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(655, 0XCE8));
    return;
    // 0x806E5CE4: addiu       $v0, $v0, 0x69A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(655, 0XCE8));
;}
RECOMP_FUNC void func_8000375C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000375C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80003760: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80003764: jr          $ra
    // 0x80003768: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    return;
    // 0x80003768: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_806DB994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB994: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806DB998: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806DB99C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806DB9A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806DB9A4: jal         0x80047090
    // 0x806DB9A8: addiu       $a0, $zero, 0x40B3
    ctx->r4 = ADD32(0, 0X40B3);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806DB9A8: addiu       $a0, $zero, 0x40B3
    ctx->r4 = ADD32(0, 0X40B3);
    after_0:
    // 0x806DB9AC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806DB9B0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x806DB9B4: beq         $v0, $at, L_806DBA1C
    if (ctx->r2 == ctx->r1) {
        // 0x806DB9B8: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_806DBA1C;
    }
    // 0x806DB9B8: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x806DB9BC: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x806DB9C0: lui         $a0, 0x806E
    ctx->r4 = S32(RELOC_HI16(634, 0X760) << 16);
    // 0x806DB9C4: lui         $at, 0x40B3
    ctx->r1 = S32(0X40B3 << 16);
    // 0x806DB9C8: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x806DB9CC: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x806DB9D0: or          $a1, $t0, $at
    ctx->r5 = ctx->r8 | ctx->r1;
    // 0x806DB9D4: addiu       $a0, $a0, -0x43E0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(634, 0X760));
    // 0x806DB9D8: jal         0x80046804
    // 0x806DB9DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x806DB9DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x806DB9E0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x806DB9E4: beq         $v0, $zero, L_806DBA1C
    if (ctx->r2 == 0) {
        // 0x806DB9E8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_806DBA1C;
    }
    // 0x806DB9E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806DB9EC: beq         $v1, $zero, L_806DBA0C
    if (ctx->r3 == 0) {
        // 0x806DB9F0: nop
    
            goto L_806DBA0C;
    }
    // 0x806DB9F0: nop

    // 0x806DB9F4: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806DB9F8: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x806DB9FC: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806DBA00: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x806DBA04: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x806DBA08: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_806DBA0C:
    // 0x806DBA0C: jal         0x80044194
    // 0x806DBA10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x806DBA10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x806DBA14: b           L_806DBA20
    // 0x806DBA18: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_806DBA20;
    // 0x806DBA18: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_806DBA1C:
    // 0x806DBA1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806DBA20:
    // 0x806DBA20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806DBA24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806DBA28: jr          $ra
    // 0x806DBA2C: nop

    return;
    // 0x806DBA2C: nop

;}
RECOMP_FUNC void func_80516CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80516CCC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80516CD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80516CD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80516CD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80516CDC: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80516CE0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80516CE4: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x80516CE8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80516CEC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80516CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80516CF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80516CF8: jal         0x80048F84
    // 0x80516CFC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80516CFC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80516D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80516D04: jal         0x80048F84
    // 0x80516D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80516D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80516D0C: beq         $v0, $zero, L_80516D4C
    if (ctx->r2 == 0) {
        // 0x80516D10: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80516D4C;
    }
    // 0x80516D10: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80516D14: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80516D18: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80516D1C: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80516D20: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80516D24: nop

    // 0x80516D28: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80516D2C: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x80516D30: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x80516D34: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x80516D38: jal         0x80067BBC
    // 0x80516D3C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80516D3C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    after_2:
    // 0x80516D40: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    // 0x80516D44: jal         0x80067818
    // 0x80516D48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80516D48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_80516D4C:
    // 0x80516D4C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80516D50: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80516D54: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80516D58: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80516D5C: lwc1        $f6, 0x1C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80516D60: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80516D64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80516D68: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x80516D6C: swc1        $f8, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f8.u32l;
    // 0x80516D70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80516D74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80516D78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80516D7C: jr          $ra
    // 0x80516D80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80516D80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_807362F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807362F4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x807362F8: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x807362FC: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x80736300: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x80736304: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80736308: lwc1        $f2, 0xC8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8073630C: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80736310: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B1C) << 16);
    // 0x80736314: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80736318: lwc1        $f26, -0x6A84($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B1C));
    // 0x8073631C: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80736320: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80736324: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80736328: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8073632C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80736330: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B20) << 16);
    // 0x80736334: lwc1        $f20, -0x6A80($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B20));
    // 0x80736338: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B24) << 16);
    // 0x8073633C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80736340: lwc1        $f18, -0x6A7C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B24));
    // 0x80736344: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B28) << 16);
    // 0x80736348: lwc1        $f14, -0x6A78($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B28));
    // 0x8073634C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B2C) << 16);
    // 0x80736350: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80736354: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80736358: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8073635C: lwc1        $f12, -0x6A74($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B2C));
    // 0x80736360: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80736364: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x80736368: addiu       $a3, $a0, 0xC4
    ctx->r7 = ADD32(ctx->r4, 0XC4);
L_8073636C:
    // 0x8073636C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80736370: nop

    // 0x80736374: bc1tl       L_807363A4
    if (c1cs) {
        // 0x80736378: lwc1        $f2, 0x0($a3)
        ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
            goto L_807363A4;
    }
    goto skip_0;
    // 0x80736378: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x8073637C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80736380: nop

    // 0x80736384: bc1tl       L_807363A4
    if (c1cs) {
        // 0x80736388: lwc1        $f2, 0x0($a3)
        ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
            goto L_807363A4;
    }
    goto skip_1;
    // 0x80736388: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x8073638C: lwc1        $f8, 0x1C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80736390: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80736394: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80736398: b           L_807363BC
    // 0x8073639C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_807363BC;
    // 0x8073639C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x807363A0: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
L_807363A4:
    // 0x807363A4: lwc1        $f6, 0x1C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x807363A8: mul.s       $f8, $f26, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x807363AC: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807363B0: add.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x807363B4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x807363B8: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_807363BC:
    // 0x807363BC: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x807363C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x807363C4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x807363C8: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x807363CC: nop

    // 0x807363D0: bc1f        L_807363F8
    if (!c1cs) {
        // 0x807363D4: nop
    
            goto L_807363F8;
    }
    // 0x807363D4: nop

    // 0x807363D8: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x807363DC: nop

    // 0x807363E0: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807363E4: sub.s       $f6, $f2, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x807363E8: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x807363EC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x807363F0: b           L_80736418
    // 0x807363F4: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
        goto L_80736418;
    // 0x807363F4: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
L_807363F8:
    // 0x807363F8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807363FC: nop

    // 0x80736400: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80736404: nop

    // 0x80736408: mul.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8073640C: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80736410: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80736414: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
L_80736418:
    // 0x80736418: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8073641C: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
    // 0x80736420: nop

    // 0x80736424: bc1fl       L_80736438
    if (!c1cs) {
        // 0x80736428: c.lt.s      $f2, $f24
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
            goto L_80736438;
    }
    goto skip_2;
    // 0x80736428: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    skip_2:
    // 0x8073642C: b           L_80736448
    // 0x80736430: swc1        $f22, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f22.u32l;
        goto L_80736448;
    // 0x80736430: swc1        $f22, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f22.u32l;
    // 0x80736434: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
L_80736438:
    // 0x80736438: nop

    // 0x8073643C: bc1f        L_80736448
    if (!c1cs) {
        // 0x80736440: nop
    
            goto L_80736448;
    }
    // 0x80736440: nop

    // 0x80736444: swc1        $f24, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f24.u32l;
L_80736448:
    // 0x80736448: bne         $a1, $v0, L_8073636C
    if (ctx->r5 != ctx->r2) {
        // 0x8073644C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8073636C;
    }
    // 0x8073644C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80736450: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80736454: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x80736458: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x8073645C: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x80736460: jr          $ra
    // 0x80736464: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80736464: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8003BB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BB94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003BB98: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
    // 0x8003BB9C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8003BBA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003BBA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003BBA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003BBAC: jal         0x8003BA90
    // 0x8003BBB0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_8003BA90(rdram, ctx);
        goto after_0;
    // 0x8003BBB0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8003BBB4: beq         $v0, $zero, L_8003BBE0
    if (ctx->r2 == 0) {
        // 0x8003BBB8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8003BBE0;
    }
    // 0x8003BBB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8003BBBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003BBC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003BBC4: nop

    // 0x8003BBC8: swc1        $f0, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->f0.u32l;
    // 0x8003BBCC: swc1        $f0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f0.u32l;
    // 0x8003BBD0: swc1        $f0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f0.u32l;
    // 0x8003BBD4: swc1        $f0, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f0.u32l;
    // 0x8003BBD8: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x8003BBDC: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
L_8003BBE0:
    // 0x8003BBE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BBE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003BBE8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8003BBEC: jr          $ra
    // 0x8003BBF0: nop

    return;
    // 0x8003BBF0: nop

;}
RECOMP_FUNC void func_80068340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068348: jal         0x80064AA8
    // 0x8006834C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80064AA8(rdram, ctx);
        goto after_0;
    // 0x8006834C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80068350: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80068354: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80068358: lbu         $t6, 0x5($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X5);
    // 0x8006835C: beql        $t6, $zero, L_80068388
    if (ctx->r14 == 0) {
        // 0x80068360: lw          $t1, 0x18($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X18);
            goto L_80068388;
    }
    goto skip_0;
    // 0x80068360: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80068364: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80068368: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x8006836C: andi        $t8, $t7, 0x30C0
    ctx->r24 = ctx->r15 & 0X30C0;
    // 0x80068370: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80068374: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80068378: sb          $zero, 0x2($t9)
    MEM_B(0X2, ctx->r25) = 0;
    // 0x8006837C: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80068380: sb          $zero, 0x3($t0)
    MEM_B(0X3, ctx->r8) = 0;
    // 0x80068384: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
L_80068388:
    // 0x80068388: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x8006838C: jalr        $t9
    // 0x80068390: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80068390: nop

    after_1:
    // 0x80068394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006839C: jr          $ra
    // 0x800683A0: nop

    return;
    // 0x800683A0: nop

;}
RECOMP_FUNC void func_8044C9D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044C9D0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8044C9D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044C9D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8044C9DC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8044C9E0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C9E4: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x8044C9E8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8044C9EC: swc1        $f0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8044C9F0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8044C9F4: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8044C9F8: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x8044C9FC: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8044CA00: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8044CA04: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x8044CA08: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x8044CA0C: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x8044CA10: jr          $ra
    // 0x8044CA14: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x8044CA14: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80737798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073779C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807377A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807377A4: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x807377A8: lwc1        $f18, 0xC8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x807377AC: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x807377B0: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x807377B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807377B8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807377BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807377C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x807377C4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x807377C8: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x807377CC: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B6C) << 16);
    // 0x807377D0: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x807377D4: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x807377D8: lwc1        $f8, -0x6A34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B6C));
    // 0x807377DC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x807377E0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x807377E4: mul.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x807377E8: bc1fl       L_80737828
    if (!c1cs) {
        // 0x807377EC: lwc1        $f2, 0x48($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
            goto L_80737828;
    }
    goto skip_0;
    // 0x807377EC: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
    skip_0:
    // 0x807377F0: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
    // 0x807377F4: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x807377F8: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x807377FC: add.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80737800: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80737804: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80737808: sub.s       $f14, $f10, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8073780C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80737810: nop

    // 0x80737814: bc1fl       L_80737854
    if (!c1cs) {
        // 0x80737818: c.lt.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
            goto L_80737854;
    }
    goto skip_1;
    // 0x80737818: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    skip_1:
    // 0x8073781C: b           L_80737850
    // 0x80737820: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_80737850;
    // 0x80737820: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x80737824: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
L_80737828:
    // 0x80737828: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8073782C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80737830: add.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80737834: add.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80737838: add.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8073783C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80737840: nop

    // 0x80737844: bc1fl       L_80737854
    if (!c1cs) {
        // 0x80737848: c.lt.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
            goto L_80737854;
    }
    goto skip_2;
    // 0x80737848: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    skip_2:
    // 0x8073784C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_80737850:
    // 0x80737850: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
L_80737854:
    // 0x80737854: nop

    // 0x80737858: bc1f        L_80737890
    if (!c1cs) {
        // 0x8073785C: nop
    
            goto L_80737890;
    }
    // 0x8073785C: nop

    // 0x80737860: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80737864: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B70) << 16);
    // 0x80737868: lwc1        $f10, -0x6A30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B70));
    // 0x8073786C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B74) << 16);
    // 0x80737870: lwc1        $f8, -0x6A2C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B74));
    // 0x80737874: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80737878: nop

    // 0x8073787C: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80737880: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80737884: sub.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80737888: b           L_807378BC
    // 0x8073788C: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
        goto L_807378BC;
    // 0x8073788C: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
L_80737890:
    // 0x80737890: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80737894: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B78) << 16);
    // 0x80737898: lwc1        $f4, -0x6A28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B78));
    // 0x8073789C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B7C) << 16);
    // 0x807378A0: lwc1        $f18, -0x6A24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B7C));
    // 0x807378A4: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x807378A8: nop

    // 0x807378AC: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x807378B0: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x807378B4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x807378B8: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
L_807378BC:
    // 0x807378BC: lwc1        $f18, 0x50($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X50);
    // 0x807378C0: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x807378C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807378C8: jal         0x800659EC
    // 0x807378CC: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    func_800659EC(rdram, ctx);
        goto after_0;
    // 0x807378CC: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_0:
    // 0x807378D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807378D4: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x807378D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807378DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807378E0: jr          $ra
    // 0x807378E4: nop

    return;
    // 0x807378E4: nop

;}
RECOMP_FUNC void func_806D6D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D6D60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806D6D64: nop

    // 0x806D6D68: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x806D6D6C: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x806D6D70: jr          $ra
    // 0x806D6D74: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x806D6D74: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8079A3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A3DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8079A3E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8079A3E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8079A3E8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8079A3EC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8079A3F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8079A3F4: jal         0x80799B68
    // 0x8079A3F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80799B68(rdram, ctx);
        goto after_0;
    // 0x8079A3F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8079A3FC: jal         0x80799BE0
    // 0x8079A400: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80799BE0(rdram, ctx);
        goto after_1;
    // 0x8079A400: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x8079A404: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8079A408: jal         0x80062684
    // 0x8079A40C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062684(rdram, ctx);
        goto after_2;
    // 0x8079A40C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x8079A410: jal         0x8079A15C
    // 0x8079A414: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8079A15C(rdram, ctx);
        goto after_3;
    // 0x8079A414: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x8079A418: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X26AC) << 16);
    // 0x8079A41C: lwc1        $f6, -0x4E34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X26AC));
    // 0x8079A420: lwc1        $f4, 0x70($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X70);
    // 0x8079A424: lw          $v0, 0x1E0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1E0);
    // 0x8079A428: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8079A42C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8079A430: addiu       $s1, $s3, 0x84
    ctx->r17 = ADD32(ctx->r19, 0X84);
    // 0x8079A434: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x8079A438: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8079A43C: blez        $v0, L_8079A44C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8079A440: swc1        $f8, 0x70($s3)
        MEM_W(0X70, ctx->r19) = ctx->f8.u32l;
            goto L_8079A44C;
    }
    // 0x8079A440: swc1        $f8, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->f8.u32l;
    // 0x8079A444: b           L_8079A498
    // 0x8079A448: sw          $t6, 0x1E0($s3)
    MEM_W(0X1E0, ctx->r19) = ctx->r14;
        goto L_8079A498;
    // 0x8079A448: sw          $t6, 0x1E0($s3)
    MEM_W(0X1E0, ctx->r19) = ctx->r14;
L_8079A44C:
    // 0x8079A44C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8079A450:
    // 0x8079A450: jal         0x80798FCC
    // 0x8079A454: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80798FCC(rdram, ctx);
        goto after_4;
    // 0x8079A454: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8079A458: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8079A45C: bnel        $s0, $s2, L_8079A450
    if (ctx->r16 != ctx->r18) {
        // 0x8079A460: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8079A450;
    }
    goto skip_0;
    // 0x8079A460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8079A464: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8079A468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079A46C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8079A470: jal         0x8079AEDC
    // 0x8079A474: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8079AEDC(rdram, ctx);
        goto after_5;
    // 0x8079A474: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8079A478: jal         0x8079A038
    // 0x8079A47C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8079A038(rdram, ctx);
        goto after_6;
    // 0x8079A47C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x8079A480: lw          $a0, 0x34($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X34);
    // 0x8079A484: jal         0x80067BBC
    // 0x8079A488: lw          $a1, 0x38($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_7;
    // 0x8079A488: lw          $a1, 0x38($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X38);
    after_7:
    // 0x8079A48C: addiu       $a0, $zero, 0x27F
    ctx->r4 = ADD32(0, 0X27F);
    // 0x8079A490: jal         0x80067818
    // 0x8079A494: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x8079A494: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
L_8079A498:
    // 0x8079A498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8079A49C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8079A4A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8079A4A4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8079A4A8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8079A4AC: jr          $ra
    // 0x8079A4B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8079A4B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006D6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D6E4: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x8006D6E8: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x8006D6EC: xor         $v0, $t6, $t7
    ctx->r2 = ctx->r14 ^ ctx->r15;
    // 0x8006D6F0: jr          $ra
    // 0x8006D6F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8006D6F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_8052DDC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052DDC0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8052DDC4: addiu       $t7, $t6, -0x419F
    ctx->r15 = ADD32(ctx->r14, -0X419F);
    // 0x8052DDC8: sltiu       $at, $t7, 0xD
    ctx->r1 = ctx->r15 < 0XD ? 1 : 0;
    // 0x8052DDCC: beq         $at, $zero, L_8052DDFC
    if (ctx->r1 == 0) {
        // 0x8052DDD0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8052DDFC;
    }
    // 0x8052DDD0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8052DDD4: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X23A0) << 16);
    // 0x8052DDD8: addu        $at, $at, $t7
    gpr jr_addend_8052DDE0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8052DDDC: lw          $t7, 0x160($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(333, 0X23A0));
    // 0x8052DDE0: jr          $t7
    // 0x8052DDE4: nop

    switch (jr_addend_8052DDE0 >> 2) {
        case 0: goto L_8052DDF4; break;
        case 1: goto L_8052DDFC; break;
        case 2: goto L_8052DDF4; break;
        case 3: goto L_8052DDFC; break;
        case 4: goto L_8052DDFC; break;
        case 5: goto L_8052DDFC; break;
        case 6: goto L_8052DDFC; break;
        case 7: goto L_8052DDFC; break;
        case 8: goto L_8052DDFC; break;
        case 9: goto L_8052DDE8; break;
        case 10: goto L_8052DDE8; break;
        case 11: goto L_8052DDE8; break;
        case 12: goto L_8052DDE8; break;
        default: switch_error(__func__, 0x8052DDE0, 0x80530160);
    }
    // 0x8052DDE4: nop

L_8052DDE8:
    // 0x8052DDE8: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(333, 0X1D74) << 16);
    // 0x8052DDEC: jr          $ra
    // 0x8052DDF0: addiu       $v0, $v0, -0x4CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(333, 0X1D74));
    return;
    // 0x8052DDF0: addiu       $v0, $v0, -0x4CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(333, 0X1D74));
L_8052DDF4:
    // 0x8052DDF4: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(333, 0X20CC) << 16);
    // 0x8052DDF8: addiu       $v0, $v0, -0x174
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(333, 0X20CC));
L_8052DDFC:
    // 0x8052DDFC: jr          $ra
    // 0x8052DE00: nop

    return;
    // 0x8052DE00: nop

;}
RECOMP_FUNC void func_8064CC78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064CC78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064CC7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064CC80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064CC84: lh          $t6, 0xC2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC2);
    // 0x8064CC88: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x8064CC8C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8064CC90: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8064CC94: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8064CC98: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8064CC9C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8064CCA0: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064CCA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064CCA8: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8064CCAC: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8064CCB0: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8064CCB4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8064CCB8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8064CCBC: swc1        $f10, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f10.u32l;
    // 0x8064CCC0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8064CCC4: jal         0x8064CC1C
    // 0x8064CCC8: sh          $t8, 0xC2($a0)
    MEM_H(0XC2, ctx->r4) = ctx->r24;
    func_8064CC1C(rdram, ctx);
        goto after_0;
    // 0x8064CCC8: sh          $t8, 0xC2($a0)
    MEM_H(0XC2, ctx->r4) = ctx->r24;
    after_0:
    // 0x8064CCCC: bne         $v0, $zero, L_8064CCE4
    if (ctx->r2 != 0) {
        // 0x8064CCD0: lui         $t9, 0x8065
        ctx->r25 = S32(RELOC_HI16(495, 0X2AA8) << 16);
            goto L_8064CCE4;
    }
    // 0x8064CCD0: lui         $t9, 0x8065
    ctx->r25 = S32(RELOC_HI16(495, 0X2AA8) << 16);
    // 0x8064CCD4: jal         0x800445A4
    // 0x8064CCD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8064CCD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8064CCDC: b           L_8064CD40
    // 0x8064CCE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8064CD40;
    // 0x8064CCE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064CCE4:
    // 0x8064CCE4: addiu       $t9, $t9, -0x3488
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(495, 0X2AA8));
    // 0x8064CCE8: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8064CCEC: jal         0x8064A468
    // 0x8064CCF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A468(rdram, ctx);
        goto after_2;
    // 0x8064CCF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8064CCF4: jal         0x8064CC60
    // 0x8064CCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064CC60(rdram, ctx);
        goto after_3;
    // 0x8064CCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8064CCFC: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x8064CD00: lui         $t0, 0x8065
    ctx->r8 = S32(RELOC_HI16(495, 0X35C0) << 16);
    // 0x8064CD04: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8064CD08: addiu       $t0, $t0, -0x2970
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(495, 0X35C0));
    // 0x8064CD0C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8064CD10: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8064CD14: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8064CD18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064CD1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064CD20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064CD24: jal         0x8064CD50
    // 0x8064CD28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8064CD50(rdram, ctx);
        goto after_4;
    // 0x8064CD28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8064CD2C: jal         0x8064A158
    // 0x8064CD30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A158(rdram, ctx);
        goto after_5;
    // 0x8064CD30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8064CD34: jal         0x8064A40C
    // 0x8064CD38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A40C(rdram, ctx);
        goto after_6;
    // 0x8064CD38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8064CD3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064CD40:
    // 0x8064CD40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064CD44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064CD48: jr          $ra
    // 0x8064CD4C: nop

    return;
    // 0x8064CD4C: nop

;}
RECOMP_FUNC void func_806D3134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3134: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x806D3138: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x806D313C: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x806D3140: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x806D3144: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x806D3148: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x806D314C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x806D3150: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x806D3154: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x806D3158: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x806D315C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x806D3160: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x806D3164: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806D3168: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806D316C: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D3170: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x806D3174: lui         $t3, 0x806D
    ctx->r11 = S32(RELOC_HI16(616, 0X34B8) << 16);
    // 0x806D3178: lh          $t9, 0x26($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X26);
    // 0x806D317C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806D3180: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806D3184: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806D3188: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806D318C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x806D3190: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x806D3194: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x806D3198: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806D319C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x806D31A0: addiu       $t3, $t3, 0x6468
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(616, 0X34B8));
    // 0x806D31A4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x806D31A8: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x806D31AC: addiu       $t6, $sp, 0x9C
    ctx->r14 = ADD32(ctx->r29, 0X9C);
    // 0x806D31B0: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x806D31B4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x806D31B8: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x806D31BC: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x806D31C0: sw          $t7, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r15;
    // 0x806D31C4: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x806D31C8: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
    // 0x806D31CC: lw          $t7, 0x10($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X10);
    // 0x806D31D0: sw          $t7, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r15;
    // 0x806D31D4: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x806D31D8: sw          $t5, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r13;
    // 0x806D31DC: lwc1        $f22, 0x6C($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806D31E0: lwc1        $f24, 0x70($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X70);
    // 0x806D31E4: lw          $s3, 0x20($s5)
    ctx->r19 = MEM_W(ctx->r21, 0X20);
    // 0x806D31E8: jal         0x80049018
    // 0x806D31EC: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x806D31EC: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D31F0: beq         $v0, $zero, L_806D3210
    if (ctx->r2 == 0) {
        // 0x806D31F4: or          $s1, $s5, $zero
        ctx->r17 = ctx->r21 | 0;
            goto L_806D3210;
    }
    // 0x806D31F4: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x806D31F8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806D31FC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806D3200: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806D3204: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x806D3208: b           L_806D3224
    // 0x806D320C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
        goto L_806D3224;
    // 0x806D320C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
L_806D3210:
    // 0x806D3210: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806D3214: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806D3218: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806D321C: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x806D3220: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
L_806D3224:
    // 0x806D3224: lui         $s7, 0x806D
    ctx->r23 = S32(RELOC_HI16(616, 0X1418) << 16);
    // 0x806D3228: addiu       $s7, $s7, 0x43C8
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(616, 0X1418));
    // 0x806D322C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806D3230: addiu       $fp, $sp, 0x88
    ctx->r30 = ADD32(ctx->r29, 0X88);
    // 0x806D3234: addiu       $s6, $sp, 0x6C
    ctx->r22 = ADD32(ctx->r29, 0X6C);
    // 0x806D3238: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_806D323C:
    // 0x806D323C: lw          $t1, 0x4($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X4);
    // 0x806D3240: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x806D3244: lw          $s0, 0xC($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC);
    // 0x806D3248: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x806D324C: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x806D3250: lh          $t6, 0x0($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X0);
    // 0x806D3254: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x806D3258: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x806D325C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x806D3260: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x806D3264: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x806D3268: addu        $t7, $s7, $t5
    ctx->r15 = ADD32(ctx->r23, ctx->r13);
    // 0x806D326C: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x806D3270: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x806D3274: sw          $t1, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r9;
    // 0x806D3278: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x806D327C: sw          $t0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r8;
    // 0x806D3280: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x806D3284: sw          $t1, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r9;
    // 0x806D3288: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x806D328C: sw          $t0, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r8;
    // 0x806D3290: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x806D3294: beq         $s0, $zero, L_806D33A0
    if (ctx->r16 == 0) {
        // 0x806D3298: sw          $t1, 0x10($s6)
        MEM_W(0X10, ctx->r22) = ctx->r9;
            goto L_806D33A0;
    }
    // 0x806D3298: sw          $t1, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->r9;
    // 0x806D329C: lh          $t8, 0x6C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6C);
    // 0x806D32A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D32A4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x806D32A8: nop

    // 0x806D32AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806D32B0: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x806D32B4: nop

    // 0x806D32B8: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x806D32BC: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x806D32C0: lh          $t2, 0x6E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X6E);
    // 0x806D32C4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x806D32C8: nop

    // 0x806D32CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806D32D0: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x806D32D4: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x806D32D8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x806D32DC: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x806D32E0: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x806D32E4: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x806D32E8: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x806D32EC: swc1        $f16, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f16.u32l;
    // 0x806D32F0: lh          $t3, 0x78($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X78);
    // 0x806D32F4: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x806D32F8: nop

    // 0x806D32FC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806D3300: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x806D3304: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x806D3308: lh          $t6, 0x7C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X7C);
    // 0x806D330C: sh          $t6, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r14;
    // 0x806D3310: lbu         $t4, 0x7A($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X7A);
    // 0x806D3314: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x806D3318: addu        $t7, $fp, $t5
    ctx->r15 = ADD32(ctx->r30, ctx->r13);
    // 0x806D331C: jal         0x806D301C
    // 0x806D3320: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    func_806D301C(rdram, ctx);
        goto after_1;
    // 0x806D3320: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x806D3324: lh          $v0, 0x144($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X144);
    // 0x806D3328: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x806D332C: bnel        $at, $zero, L_806D338C
    if (ctx->r1 != 0) {
        // 0x806D3330: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_806D338C;
    }
    goto skip_0;
    // 0x806D3330: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x806D3334: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806D3338: sb          $s4, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r20;
    // 0x806D333C: swc1        $f8, 0x3C($s3)
    MEM_W(0X3C, ctx->r19) = ctx->f8.u32l;
    // 0x806D3340: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806D3344: swc1        $f10, 0x40($s3)
    MEM_W(0X40, ctx->r19) = ctx->f10.u32l;
    // 0x806D3348: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x806D334C: swc1        $f16, 0x44($s3)
    MEM_W(0X44, ctx->r19) = ctx->f16.u32l;
    // 0x806D3350: lwc1        $f18, 0x6C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806D3354: swc1        $f18, 0x6C($s3)
    MEM_W(0X6C, ctx->r19) = ctx->f18.u32l;
    // 0x806D3358: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x806D335C: swc1        $f4, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->f4.u32l;
    // 0x806D3360: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x806D3364: swc1        $f6, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f6.u32l;
    // 0x806D3368: lh          $t9, 0x144($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X144);
    // 0x806D336C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x806D3370: sh          $t0, 0x144($s3)
    MEM_H(0X144, ctx->r19) = ctx->r8;
    // 0x806D3374: lw          $t1, 0x12C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X12C);
    // 0x806D3378: sw          $t1, 0x12C($s3)
    MEM_W(0X12C, ctx->r19) = ctx->r9;
    // 0x806D337C: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x806D3380: b           L_806D33A0
    // 0x806D3384: sw          $t8, 0x138($s3)
    MEM_W(0X138, ctx->r19) = ctx->r24;
        goto L_806D33A0;
    // 0x806D3384: sw          $t8, 0x138($s3)
    MEM_W(0X138, ctx->r19) = ctx->r24;
    // 0x806D3388: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_806D338C:
    // 0x806D338C: bnel        $v0, $at, L_806D33A0
    if (ctx->r2 != ctx->r1) {
        // 0x806D3390: sb          $zero, 0x165($s0)
        MEM_B(0X165, ctx->r16) = 0;
            goto L_806D33A0;
    }
    goto skip_1;
    // 0x806D3390: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    skip_1:
    // 0x806D3394: b           L_806D33A0
    // 0x806D3398: sb          $s4, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r20;
        goto L_806D33A0;
    // 0x806D3398: sb          $s4, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r20;
    // 0x806D339C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
L_806D33A0:
    // 0x806D33A0: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x806D33A4: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x806D33A8: bne         $at, $zero, L_806D323C
    if (ctx->r1 != 0) {
        // 0x806D33AC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_806D323C;
    }
    // 0x806D33AC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806D33B0: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x806D33B4: andi        $t2, $zero, 0xFF
    ctx->r10 = 0 & 0XFF;
    // 0x806D33B8: bne         $t2, $zero, L_806D3424
    if (ctx->r10 != 0) {
        // 0x806D33BC: sb          $zero, 0x10($v0)
        MEM_B(0X10, ctx->r2) = 0;
            goto L_806D3424;
    }
    // 0x806D33BC: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x806D33C0: lw          $s0, 0xC($s5)
    ctx->r16 = MEM_W(ctx->r21, 0XC);
    // 0x806D33C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806D33C8: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x806D33CC: beq         $s0, $zero, L_806D33D8
    if (ctx->r16 == 0) {
        // 0x806D33D0: addu        $s1, $s5, $t3
        ctx->r17 = ADD32(ctx->r21, ctx->r11);
            goto L_806D33D8;
    }
    // 0x806D33D0: addu        $s1, $s5, $t3
    ctx->r17 = ADD32(ctx->r21, ctx->r11);
    // 0x806D33D4: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
L_806D33D8:
    // 0x806D33D8: lw          $s0, 0xC($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC);
    // 0x806D33DC: beql        $s0, $zero, L_806D33EC
    if (ctx->r16 == 0) {
        // 0x806D33E0: lw          $s0, 0x10($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X10);
            goto L_806D33EC;
    }
    goto skip_2;
    // 0x806D33E0: lw          $s0, 0x10($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X10);
    skip_2:
    // 0x806D33E4: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x806D33E8: lw          $s0, 0x10($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X10);
L_806D33EC:
    // 0x806D33EC: beql        $s0, $zero, L_806D33FC
    if (ctx->r16 == 0) {
        // 0x806D33F0: lw          $s0, 0x14($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X14);
            goto L_806D33FC;
    }
    goto skip_3;
    // 0x806D33F0: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    skip_3:
    // 0x806D33F4: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x806D33F8: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
L_806D33FC:
    // 0x806D33FC: beql        $s0, $zero, L_806D340C
    if (ctx->r16 == 0) {
        // 0x806D3400: lw          $s0, 0x18($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X18);
            goto L_806D340C;
    }
    goto skip_4;
    // 0x806D3400: lw          $s0, 0x18($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X18);
    skip_4:
    // 0x806D3404: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x806D3408: lw          $s0, 0x18($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X18);
L_806D340C:
    // 0x806D340C: beq         $s0, $zero, L_806D3418
    if (ctx->r16 == 0) {
        // 0x806D3410: nop
    
            goto L_806D3418;
    }
    // 0x806D3410: nop

    // 0x806D3414: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
L_806D3418:
    // 0x806D3418: beql        $s3, $zero, L_806D3428
    if (ctx->r19 == 0) {
        // 0x806D341C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_806D3428;
    }
    goto skip_5;
    // 0x806D341C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_5:
    // 0x806D3420: sb          $zero, 0x10($s3)
    MEM_B(0X10, ctx->r19) = 0;
L_806D3424:
    // 0x806D3424: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_806D3428:
    // 0x806D3428: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806D342C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806D3430: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x806D3434: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x806D3438: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x806D343C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x806D3440: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x806D3444: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x806D3448: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x806D344C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x806D3450: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x806D3454: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x806D3458: jr          $ra
    // 0x806D345C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x806D345C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_8042AA04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042AA04: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x8042AA08: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8042AA0C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8042AA10: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8042AA14: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8042AA18: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8042AA1C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8042AA20: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8042AA24: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8042AA28: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8042AA2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042AA30: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8042AA34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8042AA38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8042AA3C: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x8042AA40: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8042AA44: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8042AA48: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
    // 0x8042AA4C: lw          $t8, 0x38($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X38);
    // 0x8042AA50: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8042AA54: lw          $s2, 0x4($a1)
    ctx->r18 = MEM_W(ctx->r5, 0X4);
    // 0x8042AA58: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8042AA5C: bgez        $t8, L_8042AA6C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8042AA60: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_8042AA6C;
    }
    // 0x8042AA60: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8042AA64: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x8042AA68: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8042AA6C:
    // 0x8042AA6C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8042AA70: swc1        $f14, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f14.u32l;
    // 0x8042AA74: swc1        $f0, 0x70($s7)
    MEM_W(0X70, ctx->r23) = ctx->f0.u32l;
    // 0x8042AA78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8042AA7C: swc1        $f0, 0x6C($s7)
    MEM_W(0X6C, ctx->r23) = ctx->f0.u32l;
    // 0x8042AA80: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8042AA84: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    // 0x8042AA88: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
    // 0x8042AA8C: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8042AA90: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8042AA94: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8042AA98: addiu       $s0, $sp, 0xEC
    ctx->r16 = ADD32(ctx->r29, 0XEC);
    // 0x8042AA9C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8042AAA0: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8042AAA4: blez        $v0, L_8042AAE0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8042AAA8: nop
    
            goto L_8042AAE0;
    }
    // 0x8042AAA8: nop

    // 0x8042AAAC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
L_8042AAB0:
    // 0x8042AAB0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8042AAB4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8042AAB8: sw          $t7, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r15;
    // 0x8042AABC: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    // 0x8042AAC0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8042AAC4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8042AAC8: sw          $t8, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r24;
    // 0x8042AACC: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8042AAD0: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8042AAD4: bnel        $at, $zero, L_8042AAB0
    if (ctx->r1 != 0) {
        // 0x8042AAD8: lw          $t7, 0x8($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X8);
            goto L_8042AAB0;
    }
    goto skip_0;
    // 0x8042AAD8: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x8042AADC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8042AAE0:
    // 0x8042AAE0: blez        $v0, L_8042AB24
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8042AAE4: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_8042AB24;
    }
    // 0x8042AAE4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8042AAE8:
    // 0x8042AAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042AAEC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8042AAF0: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x8042AAF4: sw          $t5, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r13;
    // 0x8042AAF8: jal         0x8042A8B0
    // 0x8042AAFC: swc1        $f14, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f14.u32l;
    func_8042A8B0(rdram, ctx);
        goto after_0;
    // 0x8042AAFC: swc1        $f14, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8042AB00: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8042AB04: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8042AB08: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8042AB0C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8042AB10: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8042AB14: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x8042AB18: bne         $at, $zero, L_8042AAE8
    if (ctx->r1 != 0) {
        // 0x8042AB1C: lwc1        $f14, 0xB0($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_8042AAE8;
    }
    // 0x8042AB1C: lwc1        $f14, 0xB0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8042AB20: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8042AB24:
    // 0x8042AB24: lh          $s6, 0x13E($s7)
    ctx->r22 = MEM_H(ctx->r23, 0X13E);
    // 0x8042AB28: lw          $a3, 0x3C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X3C);
    // 0x8042AB2C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8042AB30: bgez        $s6, L_8042AB3C
    if (SIGNED(ctx->r22) >= 0) {
        // 0x8042AB34: addu        $at, $s6, $zero
        ctx->r1 = ADD32(ctx->r22, 0);
            goto L_8042AB3C;
    }
    // 0x8042AB34: addu        $at, $s6, $zero
    ctx->r1 = ADD32(ctx->r22, 0);
    // 0x8042AB38: addiu       $at, $s6, 0x1
    ctx->r1 = ADD32(ctx->r22, 0X1);
L_8042AB3C:
    // 0x8042AB3C: sra         $s6, $at, 1
    ctx->r22 = S32(SIGNED(ctx->r1) >> 1);
    // 0x8042AB40: negu        $s6, $s6
    ctx->r22 = SUB32(0, ctx->r22);
    // 0x8042AB44: sw          $s5, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r21;
    // 0x8042AB48: blez        $a3, L_8042AD44
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8042AB4C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8042AD44;
    }
    // 0x8042AB4C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8042AB50: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8042AB54: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8042AB58:
    // 0x8042AB58: lw          $t9, 0x44($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X44);
    // 0x8042AB5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8042AB60: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x8042AB64: addu        $t6, $t9, $s5
    ctx->r14 = ADD32(ctx->r25, ctx->r21);
    // 0x8042AB68: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8042AB6C: sll         $t3, $s4, 2
    ctx->r11 = S32(ctx->r20 << 2);
    // 0x8042AB70: negu        $t0, $t5
    ctx->r8 = SUB32(0, ctx->r13);
    // 0x8042AB74: blez        $a1, L_8042ABA4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8042AB78: nop
    
            goto L_8042ABA4;
    }
    // 0x8042AB78: nop

    // 0x8042AB7C: lw          $t7, 0x48($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X48);
    // 0x8042AB80: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8042AB84: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
L_8042AB88:
    // 0x8042AB88: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8042AB8C: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x8042AB90: slt         $at, $ra, $a1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8042AB94: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8042AB98: bne         $at, $zero, L_8042AB88
    if (ctx->r1 != 0) {
        // 0x8042AB9C: addu        $a2, $a2, $t9
        ctx->r6 = ADD32(ctx->r6, ctx->r25);
            goto L_8042AB88;
    }
    // 0x8042AB9C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8042ABA0: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
L_8042ABA4:
    // 0x8042ABA4: bltz        $a2, L_8042AD10
    if (SIGNED(ctx->r6) < 0) {
        // 0x8042ABA8: addu        $t2, $t2, $a1
        ctx->r10 = ADD32(ctx->r10, ctx->r5);
            goto L_8042AD10;
    }
    // 0x8042ABA8: addu        $t2, $t2, $a1
    ctx->r10 = ADD32(ctx->r10, ctx->r5);
    // 0x8042ABAC: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x8042ABB0: mtc1        $s6, $f18
    ctx->f18.u32l = ctx->r22;
    // 0x8042ABB4: addiu       $s0, $a2, 0x1
    ctx->r16 = ADD32(ctx->r6, 0X1);
    // 0x8042ABB8: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8042ABBC: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
L_8042ABC0:
    // 0x8042ABC0: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8042ABC4: mtc1        $ra, $f8
    ctx->f8.u32l = ctx->r31;
    // 0x8042ABC8: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8042ABCC: addu        $t7, $t6, $s5
    ctx->r15 = ADD32(ctx->r14, ctx->r21);
    // 0x8042ABD0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8042ABD4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8042ABD8: addu        $t6, $t9, $t3
    ctx->r14 = ADD32(ctx->r25, ctx->r11);
    // 0x8042ABDC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8042ABE0: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8042ABE4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8042ABE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8042ABEC: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x8042ABF0: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x8042ABF4: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x8042ABF8: lw          $t6, 0x4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X4);
    // 0x8042ABFC: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8042AC00: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8042AC04: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x8042AC08: div.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8042AC0C: add.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8042AC10: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8042AC14: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8042AC18: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8042AC1C: nop

    // 0x8042AC20: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x8042AC24: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    // 0x8042AC28: addu        $t9, $t8, $t3
    ctx->r25 = ADD32(ctx->r24, ctx->r11);
    // 0x8042AC2C: sw          $a1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r5;
    // 0x8042AC30: lw          $t6, 0x8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X8);
    // 0x8042AC34: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x8042AC38: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8042AC3C: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x8042AC40: addu        $v0, $t8, $t3
    ctx->r2 = ADD32(ctx->r24, ctx->r11);
    // 0x8042AC44: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8042AC48: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x8042AC4C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8042AC50: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8042AC54: blez        $v0, L_8042AD04
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8042AC58: nop
    
            goto L_8042AD04;
    }
    // 0x8042AC58: nop

    // 0x8042AC5C: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8042AC60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8042AC64: addiu       $a3, $sp, 0xE0
    ctx->r7 = ADD32(ctx->r29, 0XE0);
    // 0x8042AC68: sll         $t1, $s4, 4
    ctx->r9 = S32(ctx->r20 << 4);
    // 0x8042AC6C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8042AC70: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8042AC74: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8042AC78: nop

    // 0x8042AC7C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
L_8042AC80:
    // 0x8042AC80: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8042AC84: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8042AC88: addu        $v0, $t7, $t1
    ctx->r2 = ADD32(ctx->r15, ctx->r9);
    // 0x8042AC8C: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8042AC90: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    // 0x8042AC94: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8042AC98: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8042AC9C: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8042ACA0: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
    // 0x8042ACA4: sb          $a0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r4;
    // 0x8042ACA8: sb          $a0, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r4;
    // 0x8042ACAC: sb          $a0, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r4;
    // 0x8042ACB0: sb          $a0, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r4;
    // 0x8042ACB4: lw          $t8, -0x4($a3)
    ctx->r24 = MEM_W(ctx->r7, -0X4);
    // 0x8042ACB8: addu        $v1, $t8, $t1
    ctx->r3 = ADD32(ctx->r24, ctx->r9);
    // 0x8042ACBC: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x8042ACC0: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x8042ACC4: sh          $a1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r5;
    // 0x8042ACC8: sh          $t5, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r13;
    // 0x8042ACCC: lw          $t9, 0x38($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X38);
    // 0x8042ACD0: sb          $a0, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = ctx->r4;
    // 0x8042ACD4: sb          $a0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r4;
    // 0x8042ACD8: sll         $t6, $t9, 6
    ctx->r14 = S32(ctx->r25 << 6);
    // 0x8042ACDC: sh          $t6, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r14;
    // 0x8042ACE0: sb          $a0, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r4;
    // 0x8042ACE4: sb          $a0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r4;
    // 0x8042ACE8: sh          $a2, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r6;
    // 0x8042ACEC: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8042ACF0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8042ACF4: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8042ACF8: bnel        $at, $zero, L_8042AC80
    if (ctx->r1 != 0) {
        // 0x8042ACFC: lw          $t7, 0x0($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X0);
            goto L_8042AC80;
    }
    goto skip_1;
    // 0x8042ACFC: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x8042AD00: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8042AD04:
    // 0x8042AD04: bne         $s0, $ra, L_8042ABC0
    if (ctx->r16 != ctx->r31) {
        // 0x8042AD08: addiu       $s4, $s4, 0x2
        ctx->r20 = ADD32(ctx->r20, 0X2);
            goto L_8042ABC0;
    }
    // 0x8042AD08: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8042AD0C: lw          $a3, 0x3C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X3C);
L_8042AD10:
    // 0x8042AD10: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x8042AD14: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x8042AD18: addu        $t8, $t7, $s5
    ctx->r24 = ADD32(ctx->r15, ctx->r21);
    // 0x8042AD1C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8042AD20: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8042AD24: slt         $at, $t7, $a3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8042AD28: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x8042AD2C: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8042AD30: bne         $at, $zero, L_8042AB58
    if (ctx->r1 != 0) {
        // 0x8042AD34: addu        $s6, $s6, $t9
        ctx->r22 = ADD32(ctx->r22, ctx->r25);
            goto L_8042AB58;
    }
    // 0x8042AD34: addu        $s6, $s6, $t9
    ctx->r22 = ADD32(ctx->r22, ctx->r25);
    // 0x8042AD38: sw          $zero, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = 0;
    // 0x8042AD3C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8042AD40: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8042AD44:
    // 0x8042AD44: blez        $a3, L_8042B124
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8042AD48: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8042B124;
    }
    // 0x8042AD48: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8042AD4C: lui         $fp, 0xE600
    ctx->r30 = S32(0XE600 << 16);
    // 0x8042AD50: lui         $s7, 0xF590
    ctx->r23 = S32(0XF590 << 16);
    // 0x8042AD54: lui         $s6, 0xFD90
    ctx->r22 = S32(0XFD90 << 16);
    // 0x8042AD58: lui         $s2, 0x700
    ctx->r18 = S32(0X700 << 16);
    // 0x8042AD5C: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x8042AD60: lui         $t0, 0xBF00
    ctx->r8 = S32(0XBF00 << 16);
    // 0x8042AD64: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
L_8042AD68:
    // 0x8042AD68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042AD6C: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x8042AD70: bne         $t8, $at, L_8042ADAC
    if (ctx->r24 != ctx->r1) {
        // 0x8042AD74: nop
    
            goto L_8042ADAC;
    }
    // 0x8042AD74: nop

    // 0x8042AD78: blez        $v0, L_8042ADAC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8042AD7C: addiu       $s0, $sp, 0xEC
        ctx->r16 = ADD32(ctx->r29, 0XEC);
            goto L_8042ADAC;
    }
    // 0x8042AD7C: addiu       $s0, $sp, 0xEC
    ctx->r16 = ADD32(ctx->r29, 0XEC);
    // 0x8042AD80: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8042AD84: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_8042AD88:
    // 0x8042AD88: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8042AD8C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8042AD90: sw          $t9, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r25;
    // 0x8042AD94: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8042AD98: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8042AD9C: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8042ADA0: bnel        $at, $zero, L_8042AD88
    if (ctx->r1 != 0) {
        // 0x8042ADA4: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_8042AD88;
    }
    goto skip_2;
    // 0x8042ADA4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8042ADA8: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8042ADAC:
    // 0x8042ADAC: blez        $v0, L_8042AF78
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8042ADB0: addiu       $s0, $sp, 0xEC
        ctx->r16 = ADD32(ctx->r29, 0XEC);
            goto L_8042AF78;
    }
    // 0x8042ADB0: addiu       $s0, $sp, 0xEC
    ctx->r16 = ADD32(ctx->r29, 0XEC);
    // 0x8042ADB4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8042ADB8:
    // 0x8042ADB8: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x8042ADBC: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8042ADC0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8042ADC4: sw          $s6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r22;
    // 0x8042ADC8: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x8042ADCC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8042ADD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8042ADD4: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8042ADD8: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x8042ADDC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8042ADE0: sw          $s7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r23;
    // 0x8042ADE4: sw          $s2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r18;
    // 0x8042ADE8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8042ADEC: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x8042ADF0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8042ADF4: sw          $fp, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r30;
    // 0x8042ADF8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8042ADFC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8042AE00: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8042AE04: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8042AE08: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8042AE0C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8042AE10: lw          $t8, 0x40($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X40);
    // 0x8042AE14: lw          $v1, 0x38($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X38);
    // 0x8042AE18: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x8042AE1C: addu        $t9, $t8, $s5
    ctx->r25 = ADD32(ctx->r24, ctx->r21);
    // 0x8042AE20: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8042AE24: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8042AE28: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042AE2C: mflo        $v0
    ctx->r2 = lo;
    // 0x8042AE30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8042AE34: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8042AE38: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8042AE3C: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8042AE40: beq         $at, $zero, L_8042AE50
    if (ctx->r1 == 0) {
        // 0x8042AE44: nop
    
            goto L_8042AE50;
    }
    // 0x8042AE44: nop

    // 0x8042AE48: b           L_8042AE50
    // 0x8042AE4C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_8042AE50;
    // 0x8042AE4C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8042AE50:
    // 0x8042AE50: bgez        $v1, L_8042AE60
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8042AE54: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8042AE60;
    }
    // 0x8042AE54: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8042AE58: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8042AE5C: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8042AE60:
    // 0x8042AE60: bgtz        $v0, L_8042AE70
    if (SIGNED(ctx->r2) > 0) {
        // 0x8042AE64: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8042AE70;
    }
    // 0x8042AE64: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8042AE68: b           L_8042AE70
    // 0x8042AE6C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8042AE70;
    // 0x8042AE6C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8042AE70:
    // 0x8042AE70: bgtz        $v0, L_8042AE80
    if (SIGNED(ctx->r2) > 0) {
        // 0x8042AE74: addiu       $t8, $t1, 0x7FF
        ctx->r24 = ADD32(ctx->r9, 0X7FF);
            goto L_8042AE80;
    }
    // 0x8042AE74: addiu       $t8, $t1, 0x7FF
    ctx->r24 = ADD32(ctx->r9, 0X7FF);
    // 0x8042AE78: b           L_8042AE84
    // 0x8042AE7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8042AE84;
    // 0x8042AE7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8042AE80:
    // 0x8042AE80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8042AE84:
    // 0x8042AE84: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x8042AE88: mflo        $t9
    ctx->r25 = lo;
    // 0x8042AE8C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8042AE90: bne         $a2, $zero, L_8042AE9C
    if (ctx->r6 != 0) {
        // 0x8042AE94: nop
    
            goto L_8042AE9C;
    }
    // 0x8042AE94: nop

    // 0x8042AE98: break       7
    do_break(2151853720);
L_8042AE9C:
    // 0x8042AE9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8042AEA0: bne         $a2, $at, L_8042AEB4
    if (ctx->r6 != ctx->r1) {
        // 0x8042AEA4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8042AEB4;
    }
    // 0x8042AEA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8042AEA8: bne         $t8, $at, L_8042AEB4
    if (ctx->r24 != ctx->r1) {
        // 0x8042AEAC: nop
    
            goto L_8042AEB4;
    }
    // 0x8042AEAC: nop

    // 0x8042AEB0: break       6
    do_break(2151853744);
L_8042AEB4:
    // 0x8042AEB4: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x8042AEB8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8042AEBC: or          $t7, $t6, $s2
    ctx->r15 = ctx->r14 | ctx->r18;
    // 0x8042AEC0: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8042AEC4: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8042AEC8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8042AECC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8042AED0: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8042AED4: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x8042AED8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8042AEDC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8042AEE0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8042AEE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8042AEE8: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8042AEEC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8042AEF0: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x8042AEF4: sw          $t9, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r25;
    // 0x8042AEF8: lw          $t6, 0x38($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X38);
    // 0x8042AEFC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8042AF00: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8042AF04: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x8042AF08: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8042AF0C: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x8042AF10: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x8042AF14: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8042AF18: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8042AF1C: lw          $a0, -0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X4);
    // 0x8042AF20: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8042AF24: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x8042AF28: sw          $t7, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r15;
    // 0x8042AF2C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8042AF30: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8042AF34: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8042AF38: addu        $t8, $t6, $s5
    ctx->r24 = ADD32(ctx->r14, ctx->r21);
    // 0x8042AF3C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8042AF40: lw          $t8, 0x38($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X38);
    // 0x8042AF44: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8042AF48: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8042AF4C: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8042AF50: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8042AF54: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8042AF58: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8042AF5C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8042AF60: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8042AF64: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8042AF68: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8042AF6C: bnel        $at, $zero, L_8042ADB8
    if (ctx->r1 != 0) {
        // 0x8042AF70: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8042ADB8;
    }
    goto skip_3;
    // 0x8042AF70: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x8042AF74: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8042AF78:
    // 0x8042AF78: lw          $t8, 0x40($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X40);
    // 0x8042AF7C: lw          $t9, 0x38($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X38);
    // 0x8042AF80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8042AF84: addu        $t6, $t8, $s5
    ctx->r14 = ADD32(ctx->r24, ctx->r21);
    // 0x8042AF88: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8042AF8C: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x8042AF90: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042AF94: mflo        $t8
    ctx->r24 = lo;
    // 0x8042AF98: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x8042AF9C: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
    // 0x8042AFA0: lw          $t9, 0x44($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X44);
    // 0x8042AFA4: addu        $t6, $t9, $s5
    ctx->r14 = ADD32(ctx->r25, ctx->r21);
    // 0x8042AFA8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8042AFAC: blezl       $a1, L_8042B100
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8042AFB0: lw          $v1, 0xDC($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XDC);
            goto L_8042B100;
    }
    goto skip_4;
    // 0x8042AFB0: lw          $v1, 0xDC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XDC);
    skip_4:
L_8042AFB4:
    // 0x8042AFB4: blez        $v0, L_8042B0D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8042AFB8: addiu       $s0, $sp, 0xEC
        ctx->r16 = ADD32(ctx->r29, 0XEC);
            goto L_8042B0D0;
    }
    // 0x8042AFB8: addiu       $s0, $sp, 0xEC
    ctx->r16 = ADD32(ctx->r29, 0XEC);
    // 0x8042AFBC: addu        $t3, $t2, $ra
    ctx->r11 = ADD32(ctx->r10, ctx->r31);
    // 0x8042AFC0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8042AFC4: addiu       $a3, $sp, 0xE0
    ctx->r7 = ADD32(ctx->r29, 0XE0);
    // 0x8042AFC8: sll         $t1, $s4, 4
    ctx->r9 = S32(ctx->r20 << 4);
L_8042AFCC:
    // 0x8042AFCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8042AFD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8042AFD4: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x8042AFD8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8042AFDC: lw          $t7, 0x48($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X48);
    // 0x8042AFE0: addu        $t9, $t7, $t3
    ctx->r25 = ADD32(ctx->r15, ctx->r11);
    // 0x8042AFE4: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x8042AFE8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8042AFEC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8042AFF0: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x8042AFF4: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x8042AFF8: sll         $t7, $v1, 10
    ctx->r15 = S32(ctx->r3 << 10);
    // 0x8042AFFC: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8042B000: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8042B004: or          $t8, $t6, $t5
    ctx->r24 = ctx->r14 | ctx->r13;
    // 0x8042B008: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8042B00C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8042B010: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x8042B014: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x8042B018: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8042B01C: lw          $t6, 0x48($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X48);
    // 0x8042B020: addu        $t8, $t6, $t3
    ctx->r24 = ADD32(ctx->r14, ctx->r11);
    // 0x8042B024: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8042B028: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8042B02C: blezl       $t9, L_8042B0AC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8042B030: lw          $v0, 0x34($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X34);
            goto L_8042B0AC;
    }
    goto skip_5;
    // 0x8042B030: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    skip_5:
    // 0x8042B034: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8042B038:
    // 0x8042B038: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8042B03C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8042B040: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8042B044: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8042B048: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8042B04C: lw          $t8, -0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X4);
    // 0x8042B050: lw          $t6, -0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XC);
    // 0x8042B054: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8042B058: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8042B05C: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8042B060: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x8042B064: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8042B068: lw          $t7, -0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X8);
    // 0x8042B06C: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8042B070: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8042B074: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8042B078: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8042B07C: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8042B080: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8042B084: lw          $t6, 0x48($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X48);
    // 0x8042B088: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8042B08C: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x8042B090: addu        $t9, $t7, $a2
    ctx->r25 = ADD32(ctx->r15, ctx->r6);
    // 0x8042B094: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8042B098: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8042B09C: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8042B0A0: bnel        $at, $zero, L_8042B038
    if (ctx->r1 != 0) {
        // 0x8042B0A4: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8042B038;
    }
    goto skip_6;
    // 0x8042B0A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_6:
    // 0x8042B0A8: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
L_8042B0AC:
    // 0x8042B0AC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8042B0B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8042B0B4: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8042B0B8: bne         $at, $zero, L_8042AFCC
    if (ctx->r1 != 0) {
        // 0x8042B0BC: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8042AFCC;
    }
    // 0x8042B0BC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8042B0C0: lw          $t7, 0x44($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X44);
    // 0x8042B0C4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8042B0C8: addu        $t9, $t7, $s5
    ctx->r25 = ADD32(ctx->r15, ctx->r21);
    // 0x8042B0CC: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
L_8042B0D0:
    // 0x8042B0D0: lw          $t6, 0x48($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X48);
    // 0x8042B0D4: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8042B0D8: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x8042B0DC: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x8042B0E0: addu        $t9, $t7, $a2
    ctx->r25 = ADD32(ctx->r15, ctx->r6);
    // 0x8042B0E4: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8042B0E8: slt         $at, $ra, $a1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8042B0EC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8042B0F0: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8042B0F4: bne         $at, $zero, L_8042AFB4
    if (ctx->r1 != 0) {
        // 0x8042B0F8: addu        $s4, $s4, $t8
        ctx->r20 = ADD32(ctx->r20, ctx->r24);
            goto L_8042AFB4;
    }
    // 0x8042B0F8: addu        $s4, $s4, $t8
    ctx->r20 = ADD32(ctx->r20, ctx->r24);
    // 0x8042B0FC: lw          $v1, 0xDC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XDC);
L_8042B100:
    // 0x8042B100: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8042B104: addu        $t2, $t2, $a1
    ctx->r10 = ADD32(ctx->r10, ctx->r5);
    // 0x8042B108: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8042B10C: sw          $v1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r3;
    // 0x8042B110: lw          $t7, 0x3C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X3C);
    // 0x8042B114: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8042B118: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8042B11C: bnel        $at, $zero, L_8042AD68
    if (ctx->r1 != 0) {
        // 0x8042B120: lw          $t8, 0xDC($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XDC);
            goto L_8042AD68;
    }
    goto skip_7;
    // 0x8042B120: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    skip_7:
L_8042B124:
    // 0x8042B124: blez        $v0, L_8042B15C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8042B128: addiu       $s0, $sp, 0xEC
        ctx->r16 = ADD32(ctx->r29, 0XEC);
            goto L_8042B15C;
    }
    // 0x8042B128: addiu       $s0, $sp, 0xEC
    ctx->r16 = ADD32(ctx->r29, 0XEC);
    // 0x8042B12C: lui         $v1, 0xB800
    ctx->r3 = S32(0XB800 << 16);
    // 0x8042B130: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8042B134:
    // 0x8042B134: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8042B138: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8042B13C: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x8042B140: sw          $t9, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r25;
    // 0x8042B144: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8042B148: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8042B14C: lw          $t6, 0x34($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X34);
    // 0x8042B150: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8042B154: bnel        $at, $zero, L_8042B134
    if (ctx->r1 != 0) {
        // 0x8042B158: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8042B134;
    }
    goto skip_8;
    // 0x8042B158: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_8:
L_8042B15C:
    // 0x8042B15C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8042B160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042B164: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8042B168: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8042B16C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8042B170: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8042B174: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8042B178: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8042B17C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8042B180: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8042B184: jr          $ra
    // 0x8042B188: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x8042B188: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_80742B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742B84: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742B88: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742B8C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742B90: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742B94: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742B98: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742B9C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742BA0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742BA4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742BA8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742BAC: jr          $ra
    // 0x80742BB0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742BB0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804C0C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0C74: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x804C0C78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804C0C7C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x804C0C80: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x804C0C84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C0C88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C0C8C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x804C0C90: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(200, 0X470) << 16);
    // 0x804C0C94: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804C0C98: addiu       $t7, $t7, 0xED0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(200, 0X470));
    // 0x804C0C9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x804C0CA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C0CA4: jal         0x80048490
    // 0x804C0CA8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804C0CA8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x804C0CAC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x804C0CB0: jal         0x80048378
    // 0x804C0CB4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804C0CB4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x804C0CB8: jal         0x80066E88
    // 0x804C0CBC: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x804C0CBC: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    after_2:
    // 0x804C0CC0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(200, 0X4D0) << 16);
    // 0x804C0CC4: lwc1        $f4, 0xF30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(200, 0X4D0));
    // 0x804C0CC8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x804C0CCC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804C0CD0: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804C0CD4: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x804C0CD8: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x804C0CDC: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x804C0CE0: bnel        $t8, $zero, L_804C0D00
    if (ctx->r24 != 0) {
        // 0x804C0CE4: lwc1        $f12, 0x50($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
            goto L_804C0D00;
    }
    goto skip_0;
    // 0x804C0CE4: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x804C0CE8: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x804C0CEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804C0CF0: nop

    // 0x804C0CF4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804C0CF8: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x804C0CFC: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
L_804C0D00:
    // 0x804C0D00: jal         0x80066DE4
    // 0x804C0D04: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x804C0D04: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_3:
    // 0x804C0D08: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(200, 0X4D4) << 16);
    // 0x804C0D0C: lwc1        $f16, 0xF34($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(200, 0X4D4));
    // 0x804C0D10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804C0D14: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x804C0D18: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x804C0D1C: c.eq.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl == ctx->f2.fl;
    // 0x804C0D20: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x804C0D24: bc1tl       L_804C0D60
    if (c1cs) {
        // 0x804C0D28: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804C0D60;
    }
    goto skip_1;
    // 0x804C0D28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x804C0D2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804C0D30: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x804C0D34: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804C0D38: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x804C0D3C: nop

    // 0x804C0D40: bc1fl       L_804C0D5C
    if (!c1cs) {
        // 0x804C0D44: swc1        $f12, 0x28($a0)
        MEM_W(0X28, ctx->r4) = ctx->f12.u32l;
            goto L_804C0D5C;
    }
    goto skip_2;
    // 0x804C0D44: swc1        $f12, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f12.u32l;
    skip_2:
    // 0x804C0D48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C0D4C: nop

    // 0x804C0D50: mul.s       $f12, $f2, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x804C0D54: nop

    // 0x804C0D58: swc1        $f12, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f12.u32l;
L_804C0D5C:
    // 0x804C0D5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C0D60:
    // 0x804C0D60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C0D64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804C0D68: jr          $ra
    // 0x804C0D6C: nop

    return;
    // 0x804C0D6C: nop

;}
RECOMP_FUNC void func_800199F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800199F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800199F4: bne         $a0, $zero, L_80019A04
    if (ctx->r4 != 0) {
        // 0x800199F8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80019A04;
    }
    // 0x800199F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800199FC: b           L_80019A68
    // 0x80019A00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80019A68;
    // 0x80019A00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80019A04:
    // 0x80019A04: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80019A08: bnel        $v1, $zero, L_80019A24
    if (ctx->r3 != 0) {
        // 0x80019A0C: lw          $t6, 0x1C($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X1C);
            goto L_80019A24;
    }
    goto skip_0;
    // 0x80019A0C: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    skip_0:
    // 0x80019A10: jal         0x80019B5C
    // 0x80019A14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80019B5C(rdram, ctx);
        goto after_0;
    // 0x80019A14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80019A18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80019A1C: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80019A20: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
L_80019A24:
    // 0x80019A24: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80019A28: bnel        $at, $zero, L_80019A44
    if (ctx->r1 != 0) {
        // 0x80019A2C: mtc1        $v1, $f8
        ctx->f8.u32l = ctx->r3;
            goto L_80019A44;
    }
    goto skip_1;
    // 0x80019A2C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    skip_1:
    // 0x80019A30: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80019A34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80019A38: b           L_80019A68
    // 0x80019A3C: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
        goto L_80019A68;
    // 0x80019A3C: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x80019A40: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
L_80019A44:
    // 0x80019A44: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80019A48: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80019A4C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80019A50: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80019A54: sw          $t7, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r15;
    // 0x80019A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80019A5C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80019A60: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80019A64: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
L_80019A68:
    // 0x80019A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019A70: jr          $ra
    // 0x80019A74: nop

    return;
    // 0x80019A74: nop

;}
RECOMP_FUNC void func_8006E3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E3E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E3E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E3E8: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8006E3EC: lwc1        $f2, 0xC8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8006E3F0: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006E3F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006E3F8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8006E3FC: addiu       $a1, $a1, -0x1CBC
    ctx->r5 = ADD32(ctx->r5, -0X1CBC);
    // 0x8006E400: jal         0x8006E154
    // 0x8006E404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006E154(rdram, ctx);
        goto after_0;
    // 0x8006E404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006E408: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006E40C: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8006E410: lbu         $t6, 0x24($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X24);
    // 0x8006E414: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x8006E418: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8006E41C: sb          $t8, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r24;
    // 0x8006E420: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8006E424: lbu         $t9, 0x24($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X24);
    // 0x8006E428: andi        $t0, $t9, 0xFFF0
    ctx->r8 = ctx->r25 & 0XFFF0;
    // 0x8006E42C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8006E430: sb          $t1, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r9;
    // 0x8006E434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E43C: jr          $ra
    // 0x8006E440: nop

    return;
    // 0x8006E440: nop

;}
RECOMP_FUNC void func_8044BB54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BB54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BB58: jr          $ra
    // 0x8044BB5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BB5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_80446CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446CB0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446CB4: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446CB8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446CBC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80446CC0: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x80446CC4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446CC8: jr          $ra
    // 0x80446CCC: sw          $t7, 0x6CC8($at)
    MEM_W(0X6CC8, ctx->r1) = ctx->r15;
    return;
    // 0x80446CCC: sw          $t7, 0x6CC8($at)
    MEM_W(0X6CC8, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80422A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422A00: lui         $v0, 0x8042
    ctx->r2 = S32(RELOC_HI16(35, 0X10) << 16);
    // 0x80422A04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80422A08: jr          $ra
    // 0x80422A0C: addiu       $v0, $v0, 0x2A10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(35, 0X10));
    return;
    // 0x80422A0C: addiu       $v0, $v0, 0x2A10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(35, 0X10));
;}
RECOMP_FUNC void func_80798CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80798CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80798CE4: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x80798CE8: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x80798CEC: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80798CF0: jal         0x80065ABC
    // 0x80798CF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x80798CF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80798CF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80798CFC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80798D00: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x80798D04: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80798D08: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80798D0C: jal         0x800659EC
    // 0x80798D10: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x80798D10: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80798D14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80798D18: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x80798D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80798D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80798D24: jr          $ra
    // 0x80798D28: nop

    return;
    // 0x80798D28: nop

;}
RECOMP_FUNC void func_804550E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804550E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804550E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804550E8: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X13914) << 16);
    // 0x804550EC: jal         0x804547C0
    // 0x804550F0: lw          $a1, 0x7CF4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13914));
    func_804547C0(rdram, ctx);
        goto after_0;
    // 0x804550F0: lw          $a1, 0x7CF4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13914));
    after_0:
    // 0x804550F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804550F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804550FC: jr          $ra
    // 0x80455100: nop

    return;
    // 0x80455100: nop

;}
RECOMP_FUNC void func_8051F760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F760: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8051F764: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8051F768: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8051F76C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8051F770: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8051F774: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8051F778: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8051F77C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8051F780: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8051F784: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8051F788: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x8051F78C: mov.s       $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = ctx->f18.fl;
L_8051F790:
    // 0x8051F790: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8051F794: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x8051F798: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8051F79C: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
    // 0x8051F7A0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8051F7A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8051F7A8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8051F7AC: sll         $a2, $a2, 6
    ctx->r6 = S32(ctx->r6 << 6);
L_8051F7B0:
    // 0x8051F7B0: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8051F7B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8051F7B8: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    // 0x8051F7BC: trunc.w.s   $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8051F7C0: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8051F7C4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8051F7C8: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8051F7CC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8051F7D0: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x8051F7D4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x8051F7D8: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
    // 0x8051F7DC: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x8051F7E0: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x8051F7E4: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    // 0x8051F7E8: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x8051F7EC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8051F7F0: add.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x8051F7F4: sh          $t9, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r25;
    // 0x8051F7F8: bne         $a0, $a3, L_8051F7B0
    if (ctx->r4 != ctx->r7) {
        // 0x8051F7FC: add.s       $f14, $f14, $f20
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f20.fl;
            goto L_8051F7B0;
    }
    // 0x8051F7FC: add.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f20.fl;
    // 0x8051F800: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8051F804: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8051F808: bne         $v1, $a3, L_8051F790
    if (ctx->r3 != ctx->r7) {
        // 0x8051F80C: add.s       $f2, $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f20.fl;
            goto L_8051F790;
    }
    // 0x8051F80C: add.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x8051F810: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8051F814: jr          $ra
    // 0x8051F818: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8051F818: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_805363E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805363E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805363E8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805363EC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805363F0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805363F4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805363F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805363FC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536400: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536404: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536408: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053640C: jr          $ra
    // 0x80536410: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536410: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80673B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673B54: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80673B58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80673B5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80673B60: jal         0x80673808
    // 0x80673B64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80673808(rdram, ctx);
        goto after_0;
    // 0x80673B64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80673B68: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80673B6C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80673B70: lwc1        $f14, 0x24($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80673B74: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    // 0x80673B78: jal         0x80065ABC
    // 0x80673B7C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x80673B7C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80673B80: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80673B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673B88: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80673B8C: jal         0x80049D74
    // 0x80673B90: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x80673B90: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_2:
    // 0x80673B94: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80673B98: addiu       $a2, $a2, -0x2EE4
    ctx->r6 = ADD32(ctx->r6, -0X2EE4);
    // 0x80673B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673BA0: jal         0x8004D328
    // 0x80673BA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8004D328(rdram, ctx);
        goto after_3;
    // 0x80673BA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80673BA8: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x80673BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673BB0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80673BB4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80673BB8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80673BBC: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80673BC0: lbu         $t9, 0x5C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X5C);
    // 0x80673BC4: beql        $t9, $zero, L_80673C1C
    if (ctx->r25 == 0) {
        // 0x80673BC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80673C1C;
    }
    goto skip_0;
    // 0x80673BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80673BCC: jal         0x8004D618
    // 0x80673BD0: addiu       $a2, $a2, -0x2A94
    ctx->r6 = ADD32(ctx->r6, -0X2A94);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x80673BD0: addiu       $a2, $a2, -0x2A94
    ctx->r6 = ADD32(ctx->r6, -0X2A94);
    after_4:
    // 0x80673BD4: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x80673BD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80673BDC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80673BE0: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x80673BE4: jal         0x8004A97C
    // 0x80673BE8: lhu         $a0, 0x48($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X48);
    func_8004A97C(rdram, ctx);
        goto after_5;
    // 0x80673BE8: lhu         $a0, 0x48($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X48);
    after_5:
    // 0x80673BEC: jal         0x800659EC
    // 0x80673BF0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800659EC(rdram, ctx);
        goto after_6;
    // 0x80673BF0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x80673BF4: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80673BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673BFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80673C00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80673C04: jal         0x80673F0C
    // 0x80673C08: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_80673F0C(rdram, ctx);
        goto after_7;
    // 0x80673C08: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x80673C0C: jal         0x80673590
    // 0x80673C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80673590(rdram, ctx);
        goto after_8;
    // 0x80673C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80673C14: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80673C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80673C1C:
    // 0x80673C1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80673C20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80673C24: jr          $ra
    // 0x80673C28: nop

    return;
    // 0x80673C28: nop

;}
RECOMP_FUNC void func_8002FDB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FDB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FDBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FDC0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FDC4: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FDC8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8002FDCC: jal         0x8002F678
    // 0x8002FDD0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FDD0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FDD4: beq         $v0, $zero, L_8002FDE8
    if (ctx->r2 == 0) {
        // 0x8002FDD8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FDE8;
    }
    // 0x8002FDD8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FDDC: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FDE0: addiu       $t6, $t6, -0x330C
    ctx->r14 = ADD32(ctx->r14, -0X330C);
    // 0x8002FDE4: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FDE8:
    // 0x8002FDE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FDEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FDF0: jr          $ra
    // 0x8002FDF4: nop

    return;
    // 0x8002FDF4: nop

;}
RECOMP_FUNC void func_807AF89C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF89C: jr          $ra
    // 0x807AF8A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807AF8A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8073DF50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073DF50: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8073DF54: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8073DF58: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8073DF5C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8073DF60: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8073DF64: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8073DF68: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8073DF6C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8073DF70: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8073DF74: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8073DF78: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8073DF7C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8073DF80: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8073DF84: jal         0x8004700C
    // 0x8073DF88: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8073DF88: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x8073DF8C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1474) << 16);
    // 0x8073DF90: lwc1        $f26, -0x19BC($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1474));
    // 0x8073DF94: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1478) << 16);
    // 0x8073DF98: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8073DF9C: lwc1        $f24, -0x19B8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1478));
    // 0x8073DFA0: lw          $s3, 0x1F4($s6)
    ctx->r19 = MEM_W(ctx->r22, 0X1F4);
    // 0x8073DFA4: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X147C) << 16);
    // 0x8073DFA8: lwc1        $f22, -0x19B4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X147C));
    // 0x8073DFAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8073DFB0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8073DFB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8073DFB8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8073DFBC: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x8073DFC0: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x8073DFC4: addiu       $s2, $s3, 0x14
    ctx->r18 = ADD32(ctx->r19, 0X14);
L_8073DFC8:
    // 0x8073DFC8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8073DFCC: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8073DFD0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8073DFD4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8073DFD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8073DFDC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8073DFE0: jal         0x8073DCE8
    // 0x8073DFE4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    func_8073DCE8(rdram, ctx);
        goto after_1;
    // 0x8073DFE4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8073DFE8: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    // 0x8073DFEC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8073DFF0: bnel        $t6, $zero, L_8073E030
    if (ctx->r14 != 0) {
        // 0x8073DFF4: lwc1        $f16, 0x4($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
            goto L_8073E030;
    }
    goto skip_0;
    // 0x8073DFF4: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x8073DFF8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8073DFFC: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x8073E000: nop

    // 0x8073E004: bc1fl       L_8073E04C
    if (!c1cs) {
        // 0x8073E008: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8073E04C;
    }
    goto skip_1;
    // 0x8073E008: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8073E00C: sw          $s5, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r21;
    // 0x8073E010: bne         $s1, $zero, L_8073E048
    if (ctx->r17 != 0) {
        // 0x8073E014: swc1        $f24, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f24.u32l;
            goto L_8073E048;
    }
    // 0x8073E014: swc1        $f24, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f24.u32l;
    // 0x8073E018: lw          $v0, 0x38($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X38);
    // 0x8073E01C: beq         $v0, $zero, L_8073E048
    if (ctx->r2 == 0) {
        // 0x8073E020: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8073E048;
    }
    // 0x8073E020: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8073E024: b           L_8073E048
    // 0x8073E028: sw          $t7, 0x38($s3)
    MEM_W(0X38, ctx->r19) = ctx->r15;
        goto L_8073E048;
    // 0x8073E028: sw          $t7, 0x38($s3)
    MEM_W(0X38, ctx->r19) = ctx->r15;
    // 0x8073E02C: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
L_8073E030:
    // 0x8073E030: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x8073E034: nop

    // 0x8073E038: bc1fl       L_8073E04C
    if (!c1cs) {
        // 0x8073E03C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8073E04C;
    }
    goto skip_2;
    // 0x8073E03C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x8073E040: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8073E044: swc1        $f26, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f26.u32l;
L_8073E048:
    // 0x8073E048: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8073E04C:
    // 0x8073E04C: bne         $s1, $s4, L_8073DFC8
    if (ctx->r17 != ctx->r20) {
        // 0x8073E050: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8073DFC8;
    }
    // 0x8073E050: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8073E054: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8073E058: beql        $t8, $zero, L_8073E0A8
    if (ctx->r24 == 0) {
        // 0x8073E05C: lw          $t3, 0x38($s3)
        ctx->r11 = MEM_W(ctx->r19, 0X38);
            goto L_8073E0A8;
    }
    goto skip_3;
    // 0x8073E05C: lw          $t3, 0x38($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X38);
    skip_3:
    // 0x8073E060: lw          $t9, 0x28($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X28);
    // 0x8073E064: beql        $t9, $zero, L_8073E078
    if (ctx->r25 == 0) {
        // 0x8073E068: lwc1        $f18, 0x3C($s6)
        ctx->f18.u32l = MEM_W(ctx->r22, 0X3C);
            goto L_8073E078;
    }
    goto skip_4;
    // 0x8073E068: lwc1        $f18, 0x3C($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X3C);
    skip_4:
    // 0x8073E06C: jal         0x8073DC90
    // 0x8073E070: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8073DC90(rdram, ctx);
        goto after_2;
    // 0x8073E070: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x8073E074: lwc1        $f18, 0x3C($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X3C);
L_8073E078:
    // 0x8073E078: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8073E07C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1480) << 16);
    // 0x8073E080: swc1        $f18, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f18.u32l;
    // 0x8073E084: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8073E088: lwc1        $f4, 0x40($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X40);
    // 0x8073E08C: swc1        $f4, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f4.u32l;
    // 0x8073E090: lwc1        $f8, -0x19B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1480));
    // 0x8073E094: lwc1        $f6, 0x44($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X44);
    // 0x8073E098: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8073E09C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8073E0A0: swc1        $f10, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->f10.u32l;
    // 0x8073E0A4: lw          $t3, 0x38($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X38);
L_8073E0A8:
    // 0x8073E0A8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1484) << 16);
    // 0x8073E0AC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8073E0B0: bnel        $t3, $zero, L_8073E0F0
    if (ctx->r11 != 0) {
        // 0x8073E0B4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8073E0F0;
    }
    goto skip_5;
    // 0x8073E0B4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_5:
    // 0x8073E0B8: sw          $zero, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = 0;
    // 0x8073E0BC: swc1        $f26, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f26.u32l;
    // 0x8073E0C0: lwc1        $f16, -0x19AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1484));
    // 0x8073E0C4: sw          $s5, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r21;
    // 0x8073E0C8: swc1        $f24, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f24.u32l;
    // 0x8073E0CC: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1488) << 16);
    // 0x8073E0D0: swc1        $f16, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f16.u32l;
    // 0x8073E0D4: lwc1        $f18, -0x19A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1488));
    // 0x8073E0D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073E0DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8073E0E0: swc1        $f18, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f18.u32l;
    // 0x8073E0E4: jal         0x8073E498
    // 0x8073E0E8: lw          $a3, 0x138($s6)
    ctx->r7 = MEM_W(ctx->r22, 0X138);
    func_8073E498(rdram, ctx);
        goto after_3;
    // 0x8073E0E8: lw          $a3, 0x138($s6)
    ctx->r7 = MEM_W(ctx->r22, 0X138);
    after_3:
    // 0x8073E0EC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8073E0F0:
    // 0x8073E0F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8073E0F4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8073E0F8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8073E0FC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8073E100: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8073E104: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8073E108: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8073E10C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8073E110: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8073E114: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8073E118: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8073E11C: jr          $ra
    // 0x8073E120: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8073E120: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_807C3FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C3FB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C3FBC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x807C3FC0: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x807C3FC4: jal         0x80067878
    // 0x807C3FC8: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x807C3FC8: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_0:
    // 0x807C3FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C3FD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C3FD4: jr          $ra
    // 0x807C3FD8: nop

    return;
    // 0x807C3FD8: nop

;}
RECOMP_FUNC void func_804C5488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5488: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x804C548C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804C5490: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804C5494: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x804C5498: lwc1        $f2, 0x78($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X78);
    // 0x804C549C: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804C54A0: lwc1        $f20, 0x70($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804C54A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C54A8: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x804C54AC: jal         0x804C50B4
    // 0x804C54B0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    func_804C50B4(rdram, ctx);
        goto after_0;
    // 0x804C54B0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x804C54B4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(212, 0X994) << 16);
    // 0x804C54B8: lwc1        $f12, 0x58D4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(212, 0X994));
    // 0x804C54BC: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x804C54C0: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x804C54C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804C54C8: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x804C54CC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x804C54D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C54D4: add.s       $f20, $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f12.fl;
    // 0x804C54D8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804C54DC: nop

    // 0x804C54E0: bc1fl       L_804C54F8
    if (!c1cs) {
        // 0x804C54E4: swc1        $f0, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
            goto L_804C54F8;
    }
    goto skip_0;
    // 0x804C54E4: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    skip_0:
    // 0x804C54E8: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x804C54EC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804C54F0: sb          $t6, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r14;
    // 0x804C54F4: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_804C54F8:
    // 0x804C54F8: swc1        $f20, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f20.u32l;
    // 0x804C54FC: jal         0x80048F84
    // 0x804C5500: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x804C5500: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x804C5504: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804C5508: jal         0x80048F84
    // 0x804C550C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x804C550C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x804C5510: jal         0x804C53C4
    // 0x804C5514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C53C4(rdram, ctx);
        goto after_3;
    // 0x804C5514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804C5518: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804C551C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x804C5520: beql        $t7, $zero, L_804C5550
    if (ctx->r15 == 0) {
        // 0x804C5524: lw          $t9, 0x4($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X4);
            goto L_804C5550;
    }
    goto skip_1;
    // 0x804C5524: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x804C5528: jal         0x804C5430
    // 0x804C552C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C5430(rdram, ctx);
        goto after_4;
    // 0x804C552C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804C5530: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x804C5534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C5538: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x804C553C: jal         0x804C57AC
    // 0x804C5540: lbu         $a1, 0x18($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X18);
    func_804C57AC(rdram, ctx);
        goto after_5;
    // 0x804C5540: lbu         $a1, 0x18($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X18);
    after_5:
    // 0x804C5544: b           L_804C55F8
    // 0x804C5548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_804C55F8;
    // 0x804C5548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804C554C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
L_804C5550:
    // 0x804C5550: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(212, 0X998) << 16);
    // 0x804C5554: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x804C5558: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x804C555C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x804C5560: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804C5564: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x804C5568: bnel        $t1, $zero, L_804C55F8
    if (ctx->r9 != 0) {
        // 0x804C556C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804C55F8;
    }
    goto skip_2;
    // 0x804C556C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x804C5570: lwc1        $f2, 0x58D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(212, 0X998));
    // 0x804C5574: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x804C5578: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804C557C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x804C5580: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804C5584: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x804C5588: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C558C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x804C5590: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804C5594: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804C5598: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804C559C: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x804C55A0: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x804C55A4: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x804C55A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x804C55AC: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x804C55B0: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x804C55B4: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x804C55B8: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x804C55BC: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x804C55C0: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x804C55C4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x804C55C8: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x804C55CC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x804C55D0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x804C55D4: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x804C55D8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x804C55DC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x804C55E0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x804C55E4: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x804C55E8: lw          $t9, 0xC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XC);
    // 0x804C55EC: jalr        $t9
    // 0x804C55F0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x804C55F0: nop

    after_6:
    // 0x804C55F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804C55F8:
    // 0x804C55F8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804C55FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804C5600: jr          $ra
    // 0x804C5604: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x804C5604: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_805A6A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6A30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805A6A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A6A38: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x805A6A3C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x805A6A40: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805A6A44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805A6A48: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x805A6A4C: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805A6A50: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(420, 0X3A0) << 16);
    // 0x805A6A54: lwc1        $f10, 0x6D80($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(420, 0X3A0));
    // 0x805A6A58: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x805A6A5C: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x805A6A60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A6A64: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805A6A68: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805A6A6C: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x805A6A70: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x805A6A74: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x805A6A78: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x805A6A7C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x805A6A80: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x805A6A84: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x805A6A88: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x805A6A8C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x805A6A90: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x805A6A94: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x805A6A98: jalr        $t9
    // 0x805A6A9C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805A6A9C: nop

    after_0:
    // 0x805A6AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A6AA4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805A6AA8: jr          $ra
    // 0x805A6AAC: nop

    return;
    // 0x805A6AAC: nop

;}
RECOMP_FUNC void func_804610B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804610B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804610B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804610BC: jal         0x80062748
    // 0x804610C0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062748(rdram, ctx);
        goto after_0;
    // 0x804610C0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x804610C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804610C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804610CC: jr          $ra
    // 0x804610D0: nop

    return;
    // 0x804610D0: nop

;}
RECOMP_FUNC void func_80445CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445CC8: bltz        $a0, L_80445CF8
    if (SIGNED(ctx->r4) < 0) {
        // 0x80445CCC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80445CF8;
    }
    // 0x80445CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445CD0: slti        $at, $a0, 0xE
    ctx->r1 = SIGNED(ctx->r4) < 0XE ? 1 : 0;
    // 0x80445CD4: beq         $at, $zero, L_80445CF8
    if (ctx->r1 == 0) {
        // 0x80445CD8: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80445CF8;
    }
    // 0x80445CD8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80445CDC: lui         $v0, 0x8045
    ctx->r2 = S32(RELOC_HI16(98, 0X1313C) << 16);
    // 0x80445CE0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80445CE4: lw          $v0, 0x751C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(98, 0X1313C));
    // 0x80445CE8: beql        $v0, $zero, L_80445CFC
    if (ctx->r2 == 0) {
        // 0x80445CEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80445CFC;
    }
    goto skip_0;
    // 0x80445CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80445CF0: jalr        $v0
    // 0x80445CF4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80445CF4: nop

    after_0:
L_80445CF8:
    // 0x80445CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80445CFC:
    // 0x80445CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445D00: jr          $ra
    // 0x80445D04: nop

    return;
    // 0x80445D04: nop

;}
RECOMP_FUNC void func_805CC470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CC470: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x805CC474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805CC478: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805CC47C: lw          $v0, 0x1E4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E4);
    // 0x805CC480: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805CC484: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x805CC488: beq         $v0, $zero, L_805CC498
    if (ctx->r2 == 0) {
        // 0x805CC48C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805CC498;
    }
    // 0x805CC48C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805CC490: b           L_805CC540
    // 0x805CC494: sw          $t6, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r14;
        goto L_805CC540;
    // 0x805CC494: sw          $t6, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r14;
L_805CC498:
    // 0x805CC498: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x805CC49C: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805CC4A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805CC4A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805CC4A8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x805CC4AC: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805CC4B0: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(456, 0X400) << 16);
    // 0x805CC4B4: lwc1        $f10, -0x39A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(456, 0X400));
    // 0x805CC4B8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x805CC4BC: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x805CC4C0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805CC4C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805CC4C8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805CC4CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805CC4D0: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(456, 0X404) << 16);
    // 0x805CC4D4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x805CC4D8: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x805CC4DC: lwc1        $f18, 0x6C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x805CC4E0: lwc1        $f16, -0x399C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(456, 0X404));
    // 0x805CC4E4: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x805CC4E8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x805CC4EC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x805CC4F0: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x805CC4F4: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x805CC4F8: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x805CC4FC: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x805CC500: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x805CC504: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x805CC508: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x805CC50C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x805CC510: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x805CC514: lw          $t9, 0x28($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X28);
    // 0x805CC518: jalr        $t9
    // 0x805CC51C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805CC51C: nop

    after_0:
    // 0x805CC520: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805CC524: jal         0x80067BBC
    // 0x805CC528: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x805CC528: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x805CC52C: addiu       $a0, $zero, 0x278
    ctx->r4 = ADD32(0, 0X278);
    // 0x805CC530: jal         0x80067818
    // 0x805CC534: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x805CC534: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x805CC538: jal         0x800447C8
    // 0x805CC53C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x805CC53C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_805CC540:
    // 0x805CC540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805CC544: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805CC548: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x805CC54C: jr          $ra
    // 0x805CC550: nop

    return;
    // 0x805CC550: nop

;}
RECOMP_FUNC void func_8042B8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042B8A0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8042B8A4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8042B8A8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8042B8AC: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x8042B8B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8042B8B4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8042B8B8: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8042B8BC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8042B8C0: andi        $s0, $a1, 0xFF
    ctx->r16 = ctx->r5 & 0XFF;
    // 0x8042B8C4: andi        $s1, $a2, 0xFF
    ctx->r17 = ctx->r6 & 0XFF;
    // 0x8042B8C8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8042B8CC: lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2C);
    // 0x8042B8D0: blez        $t6, L_8042B928
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8042B8D4: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8042B928;
    }
    // 0x8042B8D4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8042B8D8: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8042B8DC: addu        $t4, $a0, $t7
    ctx->r12 = ADD32(ctx->r4, ctx->r15);
    // 0x8042B8E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8042B8E4: lbu         $t3, 0x2B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2B);
    // 0x8042B8E8: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x8042B8EC: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x8042B8F0: lw          $v1, 0x20($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X20);
L_8042B8F4:
    // 0x8042B8F4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8042B8F8: addu        $a2, $v1, $a1
    ctx->r6 = ADD32(ctx->r3, ctx->r5);
    // 0x8042B8FC: sb          $s0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r16;
    // 0x8042B900: sb          $s1, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r17;
    // 0x8042B904: sb          $a3, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r7;
    // 0x8042B908: sb          $t1, 0x1C($a2)
    MEM_B(0X1C, ctx->r6) = ctx->r9;
    // 0x8042B90C: sb          $t2, 0x1D($a2)
    MEM_B(0X1D, ctx->r6) = ctx->r10;
    // 0x8042B910: sb          $t3, 0x1E($a2)
    MEM_B(0X1E, ctx->r6) = ctx->r11;
    // 0x8042B914: lw          $t8, 0x4C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4C);
    // 0x8042B918: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8042B91C: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8042B920: bnel        $at, $zero, L_8042B8F4
    if (ctx->r1 != 0) {
        // 0x8042B924: lw          $v1, 0x20($t4)
        ctx->r3 = MEM_W(ctx->r12, 0X20);
            goto L_8042B8F4;
    }
    goto skip_0;
    // 0x8042B924: lw          $v1, 0x20($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X20);
    skip_0:
L_8042B928:
    // 0x8042B928: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8042B92C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8042B930: jr          $ra
    // 0x8042B934: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8042B934: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80065A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065A54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065A58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065A5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065A60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80065A64: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80065A68: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80065A6C: jal         0x80066E88
    // 0x80065A70: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80065A70: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x80065A74: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80065A78: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80065A7C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80065A80: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80065A84: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80065A88: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x80065A8C: jal         0x80066DE4
    // 0x80065A90: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80065A90: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80065A94: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80065A98: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80065A9C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80065AA0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80065AA4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80065AA8: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x80065AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065AB4: jr          $ra
    // 0x80065AB8: nop

    return;
    // 0x80065AB8: nop

;}
RECOMP_FUNC void func_80799654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799654: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80799658: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8079965C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80799660: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80799664: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80799668: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8079966C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80799670: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(826, 0X24A0) << 16);
    // 0x80799674: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80799678: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8079967C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80799680: lw          $t1, -0x5040($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(826, 0X24A0));
    // 0x80799684: jr          $ra
    // 0x80799688: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80799688: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8040818C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040818C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80408190: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80408194: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80408198: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8040819C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804081A0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804081A4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804081A8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804081AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804081B0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x804081B4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804081B8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804081BC: lui         $t2, 0x8041
    ctx->r10 = S32(RELOC_HI16(11, 0X2D68) << 16);
    // 0x804081C0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804081C4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804081C8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804081CC: lw          $t2, -0x58C8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(11, 0X2D68));
    // 0x804081D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804081D4: jal         0x80407CB4
    // 0x804081D8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_80407CB4(rdram, ctx);
        goto after_0;
    // 0x804081D8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804081DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804081E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804081E4: jr          $ra
    // 0x804081E8: nop

    return;
    // 0x804081E8: nop

;}
RECOMP_FUNC void func_806AB424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AB428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AB42C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806AB430: lui         $t6, 0x806B
    ctx->r14 = S32(RELOC_HI16(592, 0X2FB8) << 16);
    // 0x806AB434: addiu       $t6, $t6, -0x2468
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(592, 0X2FB8));
    // 0x806AB438: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806AB43C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806AB440: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806AB444: sw          $zero, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = 0;
    // 0x806AB448: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AB44C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806AB450: jal         0x806AB72C
    // 0x806AB454: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806AB72C(rdram, ctx);
        goto after_0;
    // 0x806AB454: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x806AB458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AB45C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806AB460: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806AB464: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x806AB468: jr          $ra
    // 0x806AB46C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806AB46C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8073FBEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073FBEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073FBF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073FBF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8073FBF8: jal         0x80045A34
    // 0x8073FBFC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8073FBFC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x8073FC00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8073FC04: bne         $v0, $zero, L_8073FC14
    if (ctx->r2 != 0) {
        // 0x8073FC08: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8073FC14;
    }
    // 0x8073FC08: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8073FC0C: b           L_8073FC20
    // 0x8073FC10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8073FC20;
    // 0x8073FC10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073FC14:
    // 0x8073FC14: jal         0x8073FBB8
    // 0x8073FC18: nop

    func_8073FBB8(rdram, ctx);
        goto after_1;
    // 0x8073FC18: nop

    after_1:
    // 0x8073FC1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8073FC20:
    // 0x8073FC20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073FC24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073FC28: jr          $ra
    // 0x8073FC2C: nop

    return;
    // 0x8073FC2C: nop

;}
RECOMP_FUNC void func_8045E950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045E950: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8045E954: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045E958: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045E95C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8045E960: lw          $v1, 0x174($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X174);
    // 0x8045E964: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8045E968: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045E96C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8045E970: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8045E974: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8045E978: lw          $v0, 0x70($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X70);
    // 0x8045E97C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045E980: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8045E984: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8045E988: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8045E98C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8045E990: nop

    // 0x8045E994: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8045E998: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x8045E99C: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
    // 0x8045E9A0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8045E9A4: lwc1        $f18, 0xC8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XC8);
    // 0x8045E9A8: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8045E9AC: nop

    // 0x8045E9B0: bc1f        L_8045E9C8
    if (!c1cs) {
        // 0x8045E9B4: nop
    
            goto L_8045E9C8;
    }
    // 0x8045E9B4: nop

    // 0x8045E9B8: lhu         $t8, 0x28($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X28);
    // 0x8045E9BC: andi        $t9, $t8, 0xFF11
    ctx->r25 = ctx->r24 & 0XFF11;
    // 0x8045E9C0: sh          $t9, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r25;
    // 0x8045E9C4: lw          $v1, 0x174($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X174);
L_8045E9C8:
    // 0x8045E9C8: lhu         $t0, 0x28($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X28);
    // 0x8045E9CC: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8045E9D0: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x8045E9D4: sra         $t2, $t1, 4
    ctx->r10 = S32(SIGNED(ctx->r9) >> 4);
    // 0x8045E9D8: beq         $t2, $zero, L_8045ED9C
    if (ctx->r10 == 0) {
        // 0x8045E9DC: andi        $t3, $t0, 0x2
        ctx->r11 = ctx->r8 & 0X2;
            goto L_8045ED9C;
    }
    // 0x8045E9DC: andi        $t3, $t0, 0x2
    ctx->r11 = ctx->r8 & 0X2;
    // 0x8045E9E0: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8045E9E4: beq         $t4, $zero, L_8045ECF8
    if (ctx->r12 == 0) {
        // 0x8045E9E8: addiu       $t5, $a3, 0xC4
        ctx->r13 = ADD32(ctx->r7, 0XC4);
            goto L_8045ECF8;
    }
    // 0x8045E9E8: addiu       $t5, $a3, 0xC4
    ctx->r13 = ADD32(ctx->r7, 0XC4);
    // 0x8045E9EC: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8045E9F0: lwc1        $f0, 0x4($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8045E9F4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8045E9F8: nop

    // 0x8045E9FC: bc1fl       L_8045ECFC
    if (!c1cs) {
        // 0x8045EA00: lw          $t5, 0x60($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X60);
            goto L_8045ECFC;
    }
    goto skip_0;
    // 0x8045EA00: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    skip_0:
    // 0x8045EA04: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8045EA08: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8045EA0C: beq         $v0, $zero, L_8045EA1C
    if (ctx->r2 == 0) {
        // 0x8045EA10: nop
    
            goto L_8045EA1C;
    }
    // 0x8045EA10: nop

    // 0x8045EA14: bnel        $t7, $v0, L_8045ECFC
    if (ctx->r15 != ctx->r2) {
        // 0x8045EA18: lw          $t5, 0x60($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X60);
            goto L_8045ECFC;
    }
    goto skip_1;
    // 0x8045EA18: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    skip_1:
L_8045EA1C:
    // 0x8045EA1C: bne         $v0, $zero, L_8045EA30
    if (ctx->r2 != 0) {
        // 0x8045EA20: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_8045EA30;
    }
    // 0x8045EA20: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8045EA24: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8045EA28: b           L_8045EA48
    // 0x8045EA2C: lhu         $t0, 0x28($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X28);
        goto L_8045EA48;
    // 0x8045EA2C: lhu         $t0, 0x28($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X28);
L_8045EA30:
    // 0x8045EA30: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8045EA34: nop

    // 0x8045EA38: bc1fl       L_8045EA4C
    if (!c1cs) {
        // 0x8045EA3C: andi        $t9, $t0, 0x4
        ctx->r25 = ctx->r8 & 0X4;
            goto L_8045EA4C;
    }
    goto skip_2;
    // 0x8045EA3C: andi        $t9, $t0, 0x4
    ctx->r25 = ctx->r8 & 0X4;
    skip_2:
    // 0x8045EA40: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8045EA44: lhu         $t0, 0x28($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X28);
L_8045EA48:
    // 0x8045EA48: andi        $t9, $t0, 0x4
    ctx->r25 = ctx->r8 & 0X4;
L_8045EA4C:
    // 0x8045EA4C: sra         $t1, $t9, 2
    ctx->r9 = S32(SIGNED(ctx->r25) >> 2);
    // 0x8045EA50: bne         $t1, $zero, L_8045EBD8
    if (ctx->r9 != 0) {
        // 0x8045EA54: andi        $t5, $t0, 0xFFF7
        ctx->r13 = ctx->r8 & 0XFFF7;
            goto L_8045EBD8;
    }
    // 0x8045EA54: andi        $t5, $t0, 0xFFF7
    ctx->r13 = ctx->r8 & 0XFFF7;
    // 0x8045EA58: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x8045EA5C: lw          $t2, 0x7EA8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7EA8);
    // 0x8045EA60: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8045EA64: lb          $v0, 0x2($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X2);
    // 0x8045EA68: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8045EA6C: beq         $at, $zero, L_8045EA78
    if (ctx->r1 == 0) {
        // 0x8045EA70: slti        $at, $v0, -0x9
        ctx->r1 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
            goto L_8045EA78;
    }
    // 0x8045EA70: slti        $at, $v0, -0x9
    ctx->r1 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
    // 0x8045EA74: beq         $at, $zero, L_8045EAAC
    if (ctx->r1 == 0) {
        // 0x8045EA78: lui         $at, 0x8046
        ctx->r1 = S32(RELOC_HI16(110, 0X12E8) << 16);
            goto L_8045EAAC;
    }
L_8045EA78:
    // 0x8045EA78: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12E8) << 16);
    // 0x8045EA7C: lwc1        $f4, -0x1008($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12E8));
    // 0x8045EA80: lwc1        $f0, 0x0($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8045EA84: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8045EA88: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12EC) << 16);
    // 0x8045EA8C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8045EA90: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8045EA94: bc1fl       L_8045EBB4
    if (!c1cs) {
        // 0x8045EA98: lw          $a1, 0x8($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X8);
            goto L_8045EBB4;
    }
    goto skip_3;
    // 0x8045EA98: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    skip_3:
    // 0x8045EA9C: lwc1        $f6, -0x1004($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12EC));
    // 0x8045EAA0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8045EAA4: nop

    // 0x8045EAA8: bc1f        L_8045EBB0
    if (!c1cs) {
        // 0x8045EAAC: andi        $t4, $t0, 0x8
        ctx->r12 = ctx->r8 & 0X8;
            goto L_8045EBB0;
    }
L_8045EAAC:
    // 0x8045EAAC: andi        $t4, $t0, 0x8
    ctx->r12 = ctx->r8 & 0X8;
    // 0x8045EAB0: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8045EAB4: bne         $t5, $zero, L_8045EAF0
    if (ctx->r13 != 0) {
        // 0x8045EAB8: addiu       $a0, $s0, 0x1C
        ctx->r4 = ADD32(ctx->r16, 0X1C);
            goto L_8045EAF0;
    }
    // 0x8045EAB8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8045EABC: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8045EAC0: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8045EAC4: ori         $t6, $t0, 0x8
    ctx->r14 = ctx->r8 | 0X8;
    // 0x8045EAC8: sh          $t6, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r14;
    // 0x8045EACC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8045EAD0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8045EAD4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8045EAD8: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8045EADC: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8045EAE0: jal         0x8045DD20
    // 0x8045EAE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8045DD20(rdram, ctx);
        goto after_0;
    // 0x8045EAE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x8045EAE8: b           L_8045EBF4
    // 0x8045EAEC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
        goto L_8045EBF4;
    // 0x8045EAEC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
L_8045EAF0:
    // 0x8045EAF0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8045EAF4: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8045EAF8: jal         0x8045DD20
    // 0x8045EAFC: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    func_8045DD20(rdram, ctx);
        goto after_1;
    // 0x8045EAFC: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    after_1:
    // 0x8045EB00: lhu         $t7, 0x28($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X28);
    // 0x8045EB04: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8045EB08: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8045EB0C: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x8045EB10: sra         $t9, $t8, 5
    ctx->r25 = S32(SIGNED(ctx->r24) >> 5);
    // 0x8045EB14: beql        $t9, $zero, L_8045EB6C
    if (ctx->r25 == 0) {
        // 0x8045EB18: addiu       $a0, $sp, 0x48
        ctx->r4 = ADD32(ctx->r29, 0X48);
            goto L_8045EB6C;
    }
    goto skip_4;
    // 0x8045EB18: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    skip_4:
    // 0x8045EB1C: lwc1        $f12, 0x5C($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X5C);
    // 0x8045EB20: jal         0x80066E88
    // 0x8045EB24: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8045EB24: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_2:
    // 0x8045EB28: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8045EB2C: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8045EB30: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8045EB34: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8045EB38: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8045EB3C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8045EB40: jal         0x80066DE4
    // 0x8045EB44: lwc1        $f12, 0x5C($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X5C);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8045EB44: lwc1        $f12, 0x5C($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X5C);
    after_3:
    // 0x8045EB48: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8045EB4C: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8045EB50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8045EB54: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8045EB58: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8045EB5C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8045EB60: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8045EB64: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x8045EB68: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
L_8045EB6C:
    // 0x8045EB6C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8045EB70: jal         0x80047AB8
    // 0x8045EB74: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_4;
    // 0x8045EB74: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_4:
    // 0x8045EB78: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8045EB7C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8045EB80: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8045EB84: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8045EB88: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8045EB8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8045EB90: swc1        $f8, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f8.u32l;
    // 0x8045EB94: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8045EB98: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8045EB9C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8045EBA0: swc1        $f4, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f4.u32l;
    // 0x8045EBA4: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x8045EBA8: b           L_8045EBF4
    // 0x8045EBAC: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
        goto L_8045EBF4;
    // 0x8045EBAC: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_8045EBB0:
    // 0x8045EBB0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
L_8045EBB4:
    // 0x8045EBB4: jal         0x8045DD20
    // 0x8045EBB8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    func_8045DD20(rdram, ctx);
        goto after_5;
    // 0x8045EBB8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_5:
    // 0x8045EBBC: lhu         $t3, 0x28($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X28);
    // 0x8045EBC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8045EBC4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8045EBC8: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x8045EBCC: sh          $t4, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r12;
    // 0x8045EBD0: b           L_8045EBF4
    // 0x8045EBD4: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
        goto L_8045EBF4;
    // 0x8045EBD4: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
L_8045EBD8:
    // 0x8045EBD8: sh          $t5, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r13;
    // 0x8045EBDC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8045EBE0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8045EBE4: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8045EBE8: jal         0x8045DD20
    // 0x8045EBEC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8045DD20(rdram, ctx);
        goto after_6;
    // 0x8045EBEC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_6:
    // 0x8045EBF0: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
L_8045EBF4:
    // 0x8045EBF4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8045EBF8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045EBFC: lwc1        $f0, 0x50($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X50);
    // 0x8045EC00: lw          $t6, 0x16C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X16C);
    // 0x8045EC04: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8045EC08: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8045EC0C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8045EC10: bc1fl       L_8045EC40
    if (!c1cs) {
        // 0x8045EC14: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8045EC40;
    }
    goto skip_5;
    // 0x8045EC14: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_5:
    // 0x8045EC18: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8045EC1C: nop

    // 0x8045EC20: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
L_8045EC24:
    // 0x8045EC24: swc1        $f18, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f18.u32l;
    // 0x8045EC28: lwc1        $f0, 0x50($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X50);
    // 0x8045EC2C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8045EC30: nop

    // 0x8045EC34: bc1tl       L_8045EC24
    if (c1cs) {
        // 0x8045EC38: sub.s       $f18, $f0, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8045EC24;
    }
    goto skip_6;
    // 0x8045EC38: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    skip_6:
    // 0x8045EC3C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_8045EC40:
    // 0x8045EC40: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8045EC44: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8045EC48: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045EC4C: nop

    // 0x8045EC50: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8045EC54: nop

    // 0x8045EC58: bc1fl       L_8045EC80
    if (!c1cs) {
        // 0x8045EC5C: lw          $t7, 0x138($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X138);
            goto L_8045EC80;
    }
    goto skip_7;
    // 0x8045EC5C: lw          $t7, 0x138($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X138);
    skip_7:
    // 0x8045EC60: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
L_8045EC64:
    // 0x8045EC64: swc1        $f16, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f16.u32l;
    // 0x8045EC68: lwc1        $f0, 0x50($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X50);
    // 0x8045EC6C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8045EC70: nop

    // 0x8045EC74: bc1tl       L_8045EC64
    if (c1cs) {
        // 0x8045EC78: add.s       $f16, $f0, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_8045EC64;
    }
    goto skip_8;
    // 0x8045EC78: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    skip_8:
    // 0x8045EC7C: lw          $t7, 0x138($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X138);
L_8045EC80:
    // 0x8045EC80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8045EC84: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8045EC88: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8045EC8C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8045EC90: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8045EC94: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8045EC98: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8045EC9C: beq         $t2, $at, L_8045ECCC
    if (ctx->r10 == ctx->r1) {
        // 0x8045ECA0: lui         $at, 0x8046
        ctx->r1 = S32(RELOC_HI16(110, 0X12F0) << 16);
            goto L_8045ECCC;
    }
    // 0x8045ECA0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12F0) << 16);
    // 0x8045ECA4: lwc1        $f6, -0x1000($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12F0));
    // 0x8045ECA8: lwc1        $f4, 0x5C($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X5C);
    // 0x8045ECAC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12F4) << 16);
    // 0x8045ECB0: lwc1        $f8, -0xFFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12F4));
    // 0x8045ECB4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8045ECB8: nop

    // 0x8045ECBC: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8045ECC0: sub.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8045ECC4: b           L_8045ED40
    // 0x8045ECC8: swc1        $f16, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f16.u32l;
        goto L_8045ED40;
    // 0x8045ECC8: swc1        $f16, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f16.u32l;
L_8045ECCC:
    // 0x8045ECCC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12F8) << 16);
    // 0x8045ECD0: lwc1        $f6, -0xFF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12F8));
    // 0x8045ECD4: lwc1        $f4, 0x5C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X5C);
    // 0x8045ECD8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12FC) << 16);
    // 0x8045ECDC: lwc1        $f18, -0xFF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12FC));
    // 0x8045ECE0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8045ECE4: nop

    // 0x8045ECE8: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8045ECEC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8045ECF0: b           L_8045ED40
    // 0x8045ECF4: swc1        $f16, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f16.u32l;
        goto L_8045ED40;
    // 0x8045ECF4: swc1        $f16, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f16.u32l;
L_8045ECF8:
    // 0x8045ECF8: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
L_8045ECFC:
    // 0x8045ECFC: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8045ED00: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8045ED04: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8045ED08: bnel        $t5, $t6, L_8045ED1C
    if (ctx->r13 != ctx->r14) {
        // 0x8045ED0C: andi        $t7, $t0, 0x1
        ctx->r15 = ctx->r8 & 0X1;
            goto L_8045ED1C;
    }
    goto skip_9;
    // 0x8045ED0C: andi        $t7, $t0, 0x1
    ctx->r15 = ctx->r8 & 0X1;
    skip_9:
    // 0x8045ED10: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8045ED14: lhu         $t0, 0x28($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X28);
    // 0x8045ED18: andi        $t7, $t0, 0x1
    ctx->r15 = ctx->r8 & 0X1;
L_8045ED1C:
    // 0x8045ED1C: beq         $t7, $zero, L_8045ED30
    if (ctx->r15 == 0) {
        // 0x8045ED20: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_8045ED30;
    }
    // 0x8045ED20: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8045ED24: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x8045ED28: ori         $t1, $t9, 0x3000
    ctx->r9 = ctx->r25 | 0X3000;
    // 0x8045ED2C: sw          $t1, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r9;
L_8045ED30:
    // 0x8045ED30: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8045ED34: jal         0x8045DD20
    // 0x8045ED38: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    func_8045DD20(rdram, ctx);
        goto after_7;
    // 0x8045ED38: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_7:
    // 0x8045ED3C: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
L_8045ED40:
    // 0x8045ED40: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8045ED44: lwc1        $f6, 0x3C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8045ED48: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8045ED4C: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8045ED50: swc1        $f18, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f18.u32l;
    // 0x8045ED54: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8045ED58: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8045ED5C: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8045ED60: nop

    // 0x8045ED64: bc1tl       L_8045ED90
    if (c1cs) {
        // 0x8045ED68: lwc1        $f10, 0x40($a3)
        ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
            goto L_8045ED90;
    }
    goto skip_10;
    // 0x8045ED68: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    skip_10:
    // 0x8045ED6C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8045ED70: andi        $t4, $t3, 0x700
    ctx->r12 = ctx->r11 & 0X700;
    // 0x8045ED74: bnel        $t4, $zero, L_8045EDB4
    if (ctx->r12 != 0) {
        // 0x8045ED78: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8045EDB4;
    }
    goto skip_11;
    // 0x8045ED78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x8045ED7C: lw          $t5, 0x28($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X28);
    // 0x8045ED80: andi        $t6, $t5, 0x700
    ctx->r14 = ctx->r13 & 0X700;
    // 0x8045ED84: bnel        $t6, $zero, L_8045EDB4
    if (ctx->r14 != 0) {
        // 0x8045ED88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8045EDB4;
    }
    goto skip_12;
    // 0x8045ED88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x8045ED8C: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
L_8045ED90:
    // 0x8045ED90: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8045ED94: b           L_8045EDB0
    // 0x8045ED98: swc1        $f16, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f16.u32l;
        goto L_8045EDB0;
    // 0x8045ED98: swc1        $f16, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f16.u32l;
L_8045ED9C:
    // 0x8045ED9C: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x8045EDA0: bnel        $t7, $t9, L_8045EDB0
    if (ctx->r15 != ctx->r25) {
        // 0x8045EDA4: sh          $zero, 0x28($s0)
        MEM_H(0X28, ctx->r16) = 0;
            goto L_8045EDB0;
    }
    goto skip_13;
    // 0x8045EDA4: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    skip_13:
    // 0x8045EDA8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8045EDAC: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
L_8045EDB0:
    // 0x8045EDB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045EDB4:
    // 0x8045EDB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045EDB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8045EDBC: jr          $ra
    // 0x8045EDC0: nop

    return;
    // 0x8045EDC0: nop

;}
RECOMP_FUNC void func_806772F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806772F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806772FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80677300: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80677304: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80677308: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8067730C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80677310: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80677314: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80677318: beq         $v0, $at, L_80677470
    if (ctx->r2 == ctx->r1) {
        // 0x8067731C: lw          $t0, 0x180($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X180);
            goto L_80677470;
    }
    // 0x8067731C: lw          $t0, 0x180($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X180);
    // 0x80677320: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80677324: bnel        $v0, $at, L_80677584
    if (ctx->r2 != ctx->r1) {
        // 0x80677328: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80677584;
    }
    goto skip_0;
    // 0x80677328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8067732C: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x80677330: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80677334: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80677338: bne         $t6, $at, L_80677580
    if (ctx->r14 != ctx->r1) {
        // 0x8067733C: addiu       $t8, $zero, 0xA
        ctx->r24 = ADD32(0, 0XA);
            goto L_80677580;
    }
    // 0x8067733C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80677340: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80677344: sb          $t7, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r15;
    // 0x80677348: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8067734C: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x80677350: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80677354: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80677358: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
    // 0x8067735C: lwc1        $f4, 0xC4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x80677360: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80677364: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80677368: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8067736C: nop

    // 0x80677370: bc1fl       L_806773AC
    if (!c1cs) {
        // 0x80677374: lwc1        $f8, 0x0($a3)
        ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
            goto L_806773AC;
    }
    goto skip_1;
    // 0x80677374: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x80677378: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8067737C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80677380: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80677384: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80677388: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8067738C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80677390: nop

    // 0x80677394: bc1tl       L_80677584
    if (c1cs) {
        // 0x80677398: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80677584;
    }
    goto skip_2;
    // 0x80677398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8067739C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806773A0: b           L_806773E0
    // 0x806773A4: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
        goto L_806773E0;
    // 0x806773A4: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x806773A8: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
L_806773AC:
    // 0x806773AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806773B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806773B4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x806773B8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x806773BC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806773C0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806773C4: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x806773C8: nop

    // 0x806773CC: bc1tl       L_80677584
    if (c1cs) {
        // 0x806773D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80677584;
    }
    goto skip_3;
    // 0x806773D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806773D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806773D8: nop

    // 0x806773DC: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
L_806773E0:
    // 0x806773E0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x806773E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806773E8: addiu       $a1, $zero, 0x233
    ctx->r5 = ADD32(0, 0X233);
    // 0x806773EC: lhu         $t1, 0x4($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X4);
    // 0x806773F0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x806773F4: jal         0x80675738
    // 0x806773F8: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    func_80675738(rdram, ctx);
        goto after_0;
    // 0x806773F8: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    after_0:
    // 0x806773FC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80677400: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80677404: lw          $t3, 0x3EC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X3EC);
    // 0x80677408: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x8067740C: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80677410: lbu         $t5, 0x598($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X598);
    // 0x80677414: bnel        $t5, $at, L_80677448
    if (ctx->r13 != ctx->r1) {
        // 0x80677418: lw          $t9, 0x1C($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X1C);
            goto L_80677448;
    }
    goto skip_4;
    // 0x80677418: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
    skip_4:
    // 0x8067741C: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x80677420: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80677424: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x80677428: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x8067742C: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80677430: mfhi        $a0
    ctx->r4 = hi;
    // 0x80677434: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80677438: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8067743C: jal         0x80018B78
    // 0x80677440: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_80018B78(rdram, ctx);
        goto after_1;
    // 0x80677440: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x80677444: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
L_80677448:
    // 0x80677448: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067744C: sb          $t7, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r15;
    // 0x80677450: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80677454: jalr        $t9
    // 0x80677458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80677458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8067745C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80677460: nop

    // 0x80677464: swc1        $f0, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f0.u32l;
    // 0x80677468: b           L_80677580
    // 0x8067746C: swc1        $f0, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f0.u32l;
        goto L_80677580;
    // 0x8067746C: swc1        $f0, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f0.u32l;
L_80677470:
    // 0x80677470: lw          $t8, 0x1F4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1F4);
    // 0x80677474: lw          $t1, 0x1A4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X1A4);
    // 0x80677478: bnel        $t1, $zero, L_80677584
    if (ctx->r9 != 0) {
        // 0x8067747C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80677584;
    }
    goto skip_5;
    // 0x8067747C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80677480: beql        $t0, $zero, L_80677500
    if (ctx->r8 == 0) {
        // 0x80677484: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80677500;
    }
    goto skip_6;
    // 0x80677484: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_6:
    // 0x80677488: lwc1        $f12, 0x0($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8067748C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80677490: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80677494: jal         0x80065954
    // 0x80677498: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x80677498: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_3:
    // 0x8067749C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x806774A0: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X2614) << 16);
    // 0x806774A4: lwc1        $f10, 0x7CD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X2614));
    // 0x806774A8: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x806774AC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x806774B0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x806774B4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806774B8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x806774BC: nop

    // 0x806774C0: bc1fl       L_80677500
    if (!c1cs) {
        // 0x806774C4: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80677500;
    }
    goto skip_7;
    // 0x806774C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_7:
    // 0x806774C8: lw          $t2, 0x1F4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1F4);
    // 0x806774CC: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806774D0: lhu         $t4, 0x408($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X408);
    // 0x806774D4: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x806774D8: beql        $t5, $zero, L_806774F4
    if (ctx->r13 == 0) {
        // 0x806774DC: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_806774F4;
    }
    goto skip_8;
    // 0x806774DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_8:
    // 0x806774E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806774E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806774E8: b           L_80677534
    // 0x806774EC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
        goto L_80677534;
    // 0x806774EC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x806774F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_806774F4:
    // 0x806774F4: b           L_80677534
    // 0x806774F8: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
        goto L_80677534;
    // 0x806774F8: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x806774FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80677500:
    // 0x80677500: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80677504: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80677508: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8067750C: nop

    // 0x80677510: bc1fl       L_8067752C
    if (!c1cs) {
        // 0x80677514: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_8067752C;
    }
    goto skip_9;
    // 0x80677514: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_9:
    // 0x80677518: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8067751C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80677520: b           L_80677534
    // 0x80677524: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
        goto L_80677534;
    // 0x80677524: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80677528: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_8067752C:
    // 0x8067752C: nop

    // 0x80677530: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
L_80677534:
    // 0x80677534: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80677538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067753C: addiu       $a1, $zero, 0x233
    ctx->r5 = ADD32(0, 0X233);
    // 0x80677540: lhu         $t6, 0x4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4);
    // 0x80677544: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80677548: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x8067754C: jal         0x80675738
    // 0x80677550: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_80675738(rdram, ctx);
        goto after_4;
    // 0x80677550: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_4:
    // 0x80677554: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80677558: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8067755C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80677560: neg.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = -ctx->f6.fl;
    // 0x80677564: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80677568: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8067756C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80677570: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80677574: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80677578: jal         0x8002F6E4
    // 0x8067757C: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    func_8002F6E4(rdram, ctx);
        goto after_5;
    // 0x8067757C: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    after_5:
L_80677580:
    // 0x80677580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80677584:
    // 0x80677584: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80677588: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8067758C: jr          $ra
    // 0x80677590: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80677590: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80454F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454F30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80454F34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80454F38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80454F3C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454F40: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80454F44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80454F48: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454F4C: lw          $t6, 0x6A28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A28);
    // 0x80454F50: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x80454F54: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80454F58: bne         $t6, $at, L_80454F84
    if (ctx->r14 != ctx->r1) {
        // 0x80454F5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80454F84;
    }
    // 0x80454F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80454F60: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80454F64: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80454F68: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80454F6C: jal         0x8044EDC4
    // 0x80454F70: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8044EDC4(rdram, ctx);
        goto after_0;
    // 0x80454F70: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80454F74: jal         0x80446D70
    // 0x80454F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80446D70(rdram, ctx);
        goto after_1;
    // 0x80454F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80454F7C: b           L_80454F94
    // 0x80454F80: nop

        goto L_80454F94;
    // 0x80454F80: nop

L_80454F84:
    // 0x80454F84: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454F88: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80454F8C: jal         0x80453724
    // 0x80454F90: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    func_80453724(rdram, ctx);
        goto after_2;
    // 0x80454F90: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    after_2:
L_80454F94:
    // 0x80454F94: jal         0x80454664
    // 0x80454F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80454664(rdram, ctx);
        goto after_3;
    // 0x80454F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80454F9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80454FA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80454FA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80454FA8: jr          $ra
    // 0x80454FAC: nop

    return;
    // 0x80454FAC: nop

;}
RECOMP_FUNC void func_8043D708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D708: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043D70C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043D710: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043D714: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x8043D718: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8043D71C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043D720: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8043D724: jal         0x80065954
    // 0x8043D728: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8043D728: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8043D72C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8043D730: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8043D734: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8043D738: addiu       $v1, $s0, 0x154
    ctx->r3 = ADD32(ctx->r16, 0X154);
    // 0x8043D73C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8043D740: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8043D744: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8043D748: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8043D74C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8043D750: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8043D754: nop

    // 0x8043D758: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8043D75C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8043D760: nop

    // 0x8043D764: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8043D768: beql        $t9, $zero, L_8043D7B8
    if (ctx->r25 == 0) {
        // 0x8043D76C: mfc1        $t9, $f8
        ctx->r25 = (int32_t)ctx->f8.u32l;
            goto L_8043D7B8;
    }
    goto skip_0;
    // 0x8043D76C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x8043D770: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043D774: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8043D778: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8043D77C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8043D780: nop

    // 0x8043D784: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8043D788: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8043D78C: nop

    // 0x8043D790: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8043D794: bne         $t9, $zero, L_8043D7AC
    if (ctx->r25 != 0) {
        // 0x8043D798: nop
    
            goto L_8043D7AC;
    }
    // 0x8043D798: nop

    // 0x8043D79C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8043D7A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8043D7A4: b           L_8043D7C4
    // 0x8043D7A8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8043D7C4;
    // 0x8043D7A8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8043D7AC:
    // 0x8043D7AC: b           L_8043D7C4
    // 0x8043D7B0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8043D7C4;
    // 0x8043D7B0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8043D7B4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
L_8043D7B8:
    // 0x8043D7B8: nop

    // 0x8043D7BC: bltz        $t9, L_8043D7AC
    if (SIGNED(ctx->r25) < 0) {
        // 0x8043D7C0: nop
    
            goto L_8043D7AC;
    }
    // 0x8043D7C0: nop

L_8043D7C4:
    // 0x8043D7C4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8043D7C8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8043D7CC: sltu        $at, $t0, $a1
    ctx->r1 = ctx->r8 < ctx->r5 ? 1 : 0;
    // 0x8043D7D0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8043D7D4: bne         $at, $zero, L_8043D880
    if (ctx->r1 != 0) {
        // 0x8043D7D8: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8043D880;
    }
    // 0x8043D7D8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8043D7DC: sltu        $at, $t0, $a1
    ctx->r1 = ctx->r8 < ctx->r5 ? 1 : 0;
    // 0x8043D7E0: bne         $at, $zero, L_8043D7F8
    if (ctx->r1 != 0) {
        // 0x8043D7E4: subu        $t1, $v0, $a1
        ctx->r9 = SUB32(ctx->r2, ctx->r5);
            goto L_8043D7F8;
    }
L_8043D7E4:
    // 0x8043D7E4: subu        $t1, $v0, $a1
    ctx->r9 = SUB32(ctx->r2, ctx->r5);
    // 0x8043D7E8: sltu        $at, $t1, $a1
    ctx->r1 = ctx->r9 < ctx->r5 ? 1 : 0;
    // 0x8043D7EC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8043D7F0: beq         $at, $zero, L_8043D7E4
    if (ctx->r1 == 0) {
        // 0x8043D7F4: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8043D7E4;
    }
    // 0x8043D7F4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8043D7F8:
    // 0x8043D7F8: lh          $v0, 0x144($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X144);
    // 0x8043D7FC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8043D800: beq         $v0, $at, L_8043D810
    if (ctx->r2 == ctx->r1) {
        // 0x8043D804: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8043D810;
    }
    // 0x8043D804: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8043D808: bnel        $v0, $at, L_8043D860
    if (ctx->r2 != ctx->r1) {
        // 0x8043D80C: addiu       $t3, $v0, 0x1
        ctx->r11 = ADD32(ctx->r2, 0X1);
            goto L_8043D860;
    }
    goto skip_1;
    // 0x8043D80C: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    skip_1:
L_8043D810:
    // 0x8043D810: lhu         $t2, 0xC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XC);
    // 0x8043D814: addiu       $at, $zero, 0x406B
    ctx->r1 = ADD32(0, 0X406B);
    // 0x8043D818: bnel        $t2, $at, L_8043D844
    if (ctx->r10 != ctx->r1) {
        // 0x8043D81C: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_8043D844;
    }
    goto skip_2;
    // 0x8043D81C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_2:
    // 0x8043D820: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8043D824: jal         0x80067BBC
    // 0x8043D828: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8043D828: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8043D82C: addiu       $a0, $zero, 0x224
    ctx->r4 = ADD32(0, 0X224);
    // 0x8043D830: jal         0x80067818
    // 0x8043D834: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8043D834: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8043D838: b           L_8043D85C
    // 0x8043D83C: lh          $v0, 0x144($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X144);
        goto L_8043D85C;
    // 0x8043D83C: lh          $v0, 0x144($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X144);
    // 0x8043D840: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_8043D844:
    // 0x8043D844: jal         0x80067BBC
    // 0x8043D848: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8043D848: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8043D84C: addiu       $a0, $zero, 0x225
    ctx->r4 = ADD32(0, 0X225);
    // 0x8043D850: jal         0x80067818
    // 0x8043D854: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8043D854: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8043D858: lh          $v0, 0x144($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X144);
L_8043D85C:
    // 0x8043D85C: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
L_8043D860:
    // 0x8043D860: sh          $t3, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r11;
    // 0x8043D864: lh          $t4, 0x144($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X144);
    // 0x8043D868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8043D86C: slti        $at, $t4, 0xC
    ctx->r1 = SIGNED(ctx->r12) < 0XC ? 1 : 0;
    // 0x8043D870: bnel        $at, $zero, L_8043D884
    if (ctx->r1 != 0) {
        // 0x8043D874: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8043D884;
    }
    goto skip_3;
    // 0x8043D874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8043D878: b           L_8043D884
    // 0x8043D87C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
        goto L_8043D884;
    // 0x8043D87C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
L_8043D880:
    // 0x8043D880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043D884:
    // 0x8043D884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043D888: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043D88C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043D890: jr          $ra
    // 0x8043D894: nop

    return;
    // 0x8043D894: nop

;}
RECOMP_FUNC void func_804CAE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CAE28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CAE2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CAE30: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x804CAE34: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x804CAE38: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804CAE3C: jal         0x80065ABC
    // 0x804CAE40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x804CAE40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CAE44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CAE48: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x804CAE4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CAE50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CAE54: jr          $ra
    // 0x804CAE58: nop

    return;
    // 0x804CAE58: nop

;}
RECOMP_FUNC void func_80026290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026290: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026294: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x80026298: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8002629C: addiu       $t7, $t7, 0x61E0
    ctx->r15 = ADD32(ctx->r15, 0X61E0);
    // 0x800262A0: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x800262A4: sw          $zero, 0x80($v0)
    MEM_W(0X80, ctx->r2) = 0;
    // 0x800262A8: sb          $t6, 0x8C($v0)
    MEM_B(0X8C, ctx->r2) = ctx->r14;
    // 0x800262AC: jr          $ra
    // 0x800262B0: sw          $t7, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r15;
    return;
    // 0x800262B0: sw          $t7, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_805AB654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB654: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AB658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AB65C: jal         0x805AAF60
    // 0x805AB660: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AAF60(rdram, ctx);
        goto after_0;
    // 0x805AB660: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AB664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AB668: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805AB66C: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x805AB670: jal         0x80065ABC
    // 0x805AB674: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x805AB674: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    after_1:
    // 0x805AB678: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AB67C: jal         0x805AB4D8
    // 0x805AB680: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    func_805AB4D8(rdram, ctx);
        goto after_2;
    // 0x805AB680: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x805AB684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AB688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AB68C: jr          $ra
    // 0x805AB690: nop

    return;
    // 0x805AB690: nop

;}
RECOMP_FUNC void func_8052C928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052C928: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8052C92C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8052C930: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8052C934: jal         0x8052C9BC
    // 0x8052C938: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8052C9BC(rdram, ctx);
        goto after_0;
    // 0x8052C938: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8052C93C: beql        $v0, $zero, L_8052C9A8
    if (ctx->r2 == 0) {
        // 0x8052C940: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8052C9A8;
    }
    goto skip_0;
    // 0x8052C940: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8052C944: jal         0x8052C9F4
    // 0x8052C948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8052C9F4(rdram, ctx);
        goto after_1;
    // 0x8052C948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8052C94C: jal         0x80051194
    // 0x8052C950: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    func_80051194(rdram, ctx);
        goto after_2;
    // 0x8052C950: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    after_2:
    // 0x8052C954: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x8052C958: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(330, 0X16B8) << 16);
    // 0x8052C95C: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x8052C960: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8052C964: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8052C968: addiu       $t6, $t6, -0x2378
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(330, 0X16B8));
    // 0x8052C96C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8052C970: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8052C974: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8052C978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052C97C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8052C980: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8052C984: jal         0x8052D61C
    // 0x8052C988: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8052D61C(rdram, ctx);
        goto after_3;
    // 0x8052C988: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8052C98C: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x8052C990: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(330, 0X628) << 16);
    // 0x8052C994: addiu       $t8, $t8, -0x3408
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(330, 0X628));
    // 0x8052C998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8052C99C: b           L_8052C9A8
    // 0x8052C9A0: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
        goto L_8052C9A8;
    // 0x8052C9A0: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x8052C9A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8052C9A8:
    // 0x8052C9A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8052C9AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8052C9B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8052C9B4: jr          $ra
    // 0x8052C9B8: nop

    return;
    // 0x8052C9B8: nop

;}
RECOMP_FUNC void func_804C4F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C4F68: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804C4F6C: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(212, 0X324) << 16);
    // 0x804C4F70: addiu       $t6, $t6, 0x5264
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(212, 0X324));
    // 0x804C4F74: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804C4F78: jr          $ra
    // 0x804C4F7C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804C4F7C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80046730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046730: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80046734: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80046738: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004673C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80046740: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80046744: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80046748: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8004674C: lw          $s0, 0x8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X8);
    // 0x80046750: blez        $t6, L_80046778
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80046754: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80046778;
    }
    // 0x80046754: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80046758:
    // 0x80046758: jal         0x8004627C
    // 0x8004675C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_8004627C(rdram, ctx);
        goto after_0;
    // 0x8004675C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80046760: lw          $t7, 0x4($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X4);
    // 0x80046764: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80046768: addiu       $s0, $s0, 0x280
    ctx->r16 = ADD32(ctx->r16, 0X280);
    // 0x8004676C: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80046770: bne         $at, $zero, L_80046758
    if (ctx->r1 != 0) {
        // 0x80046774: nop
    
            goto L_80046758;
    }
    // 0x80046774: nop

L_80046778:
    // 0x80046778: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004677C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80046780: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80046784: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80046788: jr          $ra
    // 0x8004678C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004678C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80430F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430F3C: jr          $ra
    // 0x80430F40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80430F40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80039F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039F48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80039F4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80039F50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80039F54: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80039F58: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80039F5C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80039F60: beq         $v0, $at, L_80039F8C
    if (ctx->r2 == ctx->r1) {
        // 0x80039F64: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_80039F8C;
    }
    // 0x80039F64: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80039F68: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x80039F6C: bnel        $v0, $at, L_8003A050
    if (ctx->r2 != ctx->r1) {
        // 0x80039F70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003A050;
    }
    goto skip_0;
    // 0x80039F70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80039F74: jal         0x80039F00
    // 0x80039F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80039F00(rdram, ctx);
        goto after_0;
    // 0x80039F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80039F7C: jal         0x8005FE48
    // 0x80039F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x80039F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80039F84: b           L_8003A050
    // 0x80039F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003A050;
    // 0x80039F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80039F8C:
    // 0x80039F8C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80039F90: bnel        $t6, $zero, L_8003A050
    if (ctx->r14 != 0) {
        // 0x80039F94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003A050;
    }
    goto skip_1;
    // 0x80039F94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80039F98: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    // 0x80039F9C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80039FA0: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80039FA4: beql        $at, $zero, L_8003A050
    if (ctx->r1 == 0) {
        // 0x80039FA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003A050;
    }
    goto skip_2;
    // 0x80039FA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80039FAC: lbu         $t8, -0x764C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X764C);
    // 0x80039FB0: bnel        $t8, $zero, L_8003A050
    if (ctx->r24 != 0) {
        // 0x80039FB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003A050;
    }
    goto skip_3;
    // 0x80039FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80039FB8: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x80039FBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80039FC0: beql        $t9, $zero, L_8003A038
    if (ctx->r25 == 0) {
        // 0x80039FC4: lbu         $t1, 0x18($a0)
        ctx->r9 = MEM_BU(ctx->r4, 0X18);
            goto L_8003A038;
    }
    goto skip_4;
    // 0x80039FC4: lbu         $t1, 0x18($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X18);
    skip_4:
    // 0x80039FC8: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80039FCC: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80039FD0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80039FD4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80039FD8: nop

    // 0x80039FDC: bc1fl       L_80039FF8
    if (!c1cs) {
        // 0x80039FE0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80039FF8;
    }
    goto skip_5;
    // 0x80039FE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_5:
    // 0x80039FE4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80039FE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80039FEC: b           L_8003A000
    // 0x80039FF0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
        goto L_8003A000;
    // 0x80039FF0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80039FF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80039FF8:
    // 0x80039FF8: nop

    // 0x80039FFC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_8003A000:
    // 0x8003A000: jal         0x80039F00
    // 0x8003A004: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80039F00(rdram, ctx);
        goto after_2;
    // 0x8003A004: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8003A008: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8003A00C: lui         $a2, 0xC07F
    ctx->r6 = S32(0XC07F << 16);
    // 0x8003A010: ori         $a2, $a2, 0x5C29
    ctx->r6 = ctx->r6 | 0X5C29;
    // 0x8003A014: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003A018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A01C: jal         0x8002F96C
    // 0x8003A020: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8002F96C(rdram, ctx);
        goto after_3;
    // 0x8003A020: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_3:
    // 0x8003A024: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003A028: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003A02C: b           L_8003A04C
    // 0x8003A030: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
        goto L_8003A04C;
    // 0x8003A030: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x8003A034: lbu         $t1, 0x18($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X18);
L_8003A038:
    // 0x8003A038: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8003A03C: beql        $t1, $at, L_8003A050
    if (ctx->r9 == ctx->r1) {
        // 0x8003A040: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003A050;
    }
    goto skip_6;
    // 0x8003A040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8003A044: jal         0x8004012C
    // 0x8003A048: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004012C(rdram, ctx);
        goto after_4;
    // 0x8003A048: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
L_8003A04C:
    // 0x8003A04C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003A050:
    // 0x8003A050: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003A054: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003A058: jr          $ra
    // 0x8003A05C: nop

    return;
    // 0x8003A05C: nop

;}
RECOMP_FUNC void func_8045B0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B0A8: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045B0AC: lwc1        $f12, 0x0($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045B0B0: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8045B0B4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8045B0B8: nop

    // 0x8045B0BC: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8045B0C0: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8045B0C4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8045B0C8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8045B0CC: nop

    // 0x8045B0D0: bc1f        L_8045B194
    if (!c1cs) {
        // 0x8045B0D4: nop
    
            goto L_8045B194;
    }
    // 0x8045B0D4: nop

    // 0x8045B0D8: div.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8045B0DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8045B0E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8045B0E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8045B0E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8045B0EC: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8045B0F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8045B0F4: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8045B0F8: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8045B0FC: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8045B100: mul.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8045B104: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8045B108: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8045B10C: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045B110: lwc1        $f10, 0xC4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8045B114: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8045B118: nop

    // 0x8045B11C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8045B120: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8045B124: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x8045B128: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x8045B12C: bc1f        L_8045B144
    if (!c1cs) {
        // 0x8045B130: nop
    
            goto L_8045B144;
    }
    // 0x8045B130: nop

    // 0x8045B134: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045B138: lhu         $t6, 0x40($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X40);
    // 0x8045B13C: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x8045B140: sh          $t7, 0x40($v0)
    MEM_H(0X40, ctx->r2) = ctx->r15;
L_8045B144:
    // 0x8045B144: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045B148: lwc1        $f18, 0x3C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x8045B14C: lwc1        $f4, 0x40($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X40);
    // 0x8045B150: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8045B154: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8045B158: swc1        $f10, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f10.u32l;
    // 0x8045B15C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045B160: lwc1        $f10, 0xC4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x8045B164: mul.s       $f18, $f2, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8045B168: nop

    // 0x8045B16C: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8045B170: sub.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8045B174: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x8045B178: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
    // 0x8045B17C: bc1f        L_8045B194
    if (!c1cs) {
        // 0x8045B180: nop
    
            goto L_8045B194;
    }
    // 0x8045B180: nop

    // 0x8045B184: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8045B188: lhu         $t8, 0x40($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X40);
    // 0x8045B18C: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8045B190: sh          $t9, 0x40($v0)
    MEM_H(0X40, ctx->r2) = ctx->r25;
L_8045B194:
    // 0x8045B194: jr          $ra
    // 0x8045B198: nop

    return;
    // 0x8045B198: nop

;}
RECOMP_FUNC void func_80027EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027EA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80027EAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80027EB0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80027EB4: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x80027EB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80027EBC: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    // 0x80027EC0: addiu       $a2, $zero, 0x79
    ctx->r6 = ADD32(0, 0X79);
    // 0x80027EC4: jal         0x80024680
    // 0x80027EC8: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x80027EC8: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    after_0:
    // 0x80027ECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80027ED0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80027ED4: jr          $ra
    // 0x80027ED8: nop

    return;
    // 0x80027ED8: nop

;}
RECOMP_FUNC void func_80059300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059300: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80059304: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80059308: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8005930C: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x80059310: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80059314: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80059318: lwc1        $f10, 0x38($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X38);
    // 0x8005931C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80059320: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80059324: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80059328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005932C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80059330: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80059334: nop

    // 0x80059338: bc1f        L_80059344
    if (!c1cs) {
        // 0x8005933C: nop
    
            goto L_80059344;
    }
    // 0x8005933C: nop

    // 0x80059340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059344:
    // 0x80059344: jr          $ra
    // 0x80059348: nop

    return;
    // 0x80059348: nop

;}
RECOMP_FUNC void func_80523040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80523040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80523044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80523048: jal         0x80522AD4
    // 0x8052304C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80522AD4(rdram, ctx);
        goto after_0;
    // 0x8052304C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80523050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80523054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80523058: jr          $ra
    // 0x8052305C: nop

    return;
    // 0x8052305C: nop

;}
RECOMP_FUNC void func_8000A480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A480: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000A484: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000A488: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x8000A48C: addiu       $s5, $s5, 0x4D10
    ctx->r21 = ADD32(ctx->r21, 0X4D10);
    // 0x8000A490: lbu         $t6, 0x4F7E($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X4F7E);
    // 0x8000A494: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000A498: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000A49C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000A4A0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000A4A4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000A4A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000A4AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000A4B0: bne         $t6, $zero, L_8000A4C4
    if (ctx->r14 != 0) {
        // 0x8000A4B4: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8000A4C4;
    }
    // 0x8000A4B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000A4B8: srl         $t8, $a0, 8
    ctx->r24 = S32(U32(ctx->r4) >> 8);
    // 0x8000A4BC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8000A4C0: sb          $t8, -0x77B4($at)
    MEM_B(-0X77B4, ctx->r1) = ctx->r24;
L_8000A4C4:
    // 0x8000A4C4: andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
    // 0x8000A4C8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8000A4CC: addiu       $s7, $zero, 0x30
    ctx->r23 = ADD32(0, 0X30);
    // 0x8000A4D0: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x8000A4D4: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
L_8000A4D8:
    // 0x8000A4D8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8000A4DC: lbu         $v1, -0x77B4($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X77B4);
    // 0x8000A4E0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8000A4E4: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8000A4E8: andi        $t2, $v1, 0xFF
    ctx->r10 = ctx->r3 & 0XFF;
    // 0x8000A4EC: bne         $t1, $v1, L_8000A4FC
    if (ctx->r9 != ctx->r3) {
        // 0x8000A4F0: sll         $t3, $t2, 3
        ctx->r11 = S32(ctx->r10 << 3);
            goto L_8000A4FC;
    }
    // 0x8000A4F0: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8000A4F4: b           L_8000A79C
    // 0x8000A4F8: sb          $zero, 0x4F7E($s5)
    MEM_B(0X4F7E, ctx->r21) = 0;
        goto L_8000A79C;
    // 0x8000A4F8: sb          $zero, 0x4F7E($s5)
    MEM_B(0X4F7E, ctx->r21) = 0;
L_8000A4FC:
    // 0x8000A4FC: lbu         $t4, -0x77B4($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X77B4);
    // 0x8000A500: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8000A504: addu        $s3, $s5, $t3
    ctx->r19 = ADD32(ctx->r21, ctx->r11);
    // 0x8000A508: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000A50C: sb          $t5, -0x77B4($at)
    MEM_B(-0X77B4, ctx->r1) = ctx->r13;
    // 0x8000A510: lbu         $v0, 0x4FF4($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X4FF4);
    // 0x8000A514: addiu       $at, $zero, 0xF8
    ctx->r1 = ADD32(0, 0XF8);
    // 0x8000A518: addiu       $s3, $s3, 0x4FF4
    ctx->r19 = ADD32(ctx->r19, 0X4FF4);
    // 0x8000A51C: bne         $v0, $at, L_8000A530
    if (ctx->r2 != ctx->r1) {
        // 0x8000A520: andi        $t7, $v0, 0xF0
        ctx->r15 = ctx->r2 & 0XF0;
            goto L_8000A530;
    }
    // 0x8000A520: andi        $t7, $v0, 0xF0
    ctx->r15 = ctx->r2 & 0XF0;
    // 0x8000A524: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000A528: b           L_8000A79C
    // 0x8000A52C: sb          $t6, 0x4F7E($s5)
    MEM_B(0X4F7E, ctx->r21) = ctx->r14;
        goto L_8000A79C;
    // 0x8000A52C: sb          $t6, 0x4F7E($s5)
    MEM_B(0X4F7E, ctx->r21) = ctx->r14;
L_8000A530:
    // 0x8000A530: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8000A534: bnel        $t7, $at, L_8000A550
    if (ctx->r15 != ctx->r1) {
        // 0x8000A538: lbu         $a0, 0x1($s3)
        ctx->r4 = MEM_BU(ctx->r19, 0X1);
            goto L_8000A550;
    }
    goto skip_0;
    // 0x8000A538: lbu         $a0, 0x1($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X1);
    skip_0:
    // 0x8000A53C: jal         0x80009EAC
    // 0x8000A540: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80009EAC(rdram, ctx);
        goto after_0;
    // 0x8000A540: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x8000A544: b           L_8000A794
    // 0x8000A548: nop

        goto L_8000A794;
    // 0x8000A548: nop

    // 0x8000A54C: lbu         $a0, 0x1($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X1);
L_8000A550:
    // 0x8000A550: lh          $t8, 0x1D90($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X1D90);
    // 0x8000A554: andi        $t0, $v0, 0x80
    ctx->r8 = ctx->r2 & 0X80;
    // 0x8000A558: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8000A55C: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000A560: beq         $at, $zero, L_8000A794
    if (ctx->r1 == 0) {
        // 0x8000A564: subu        $t9, $t9, $a0
        ctx->r25 = SUB32(ctx->r25, ctx->r4);
            goto L_8000A794;
    }
    // 0x8000A564: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8000A568: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000A56C: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8000A570: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8000A574: addu        $s2, $s5, $t9
    ctx->r18 = ADD32(ctx->r21, ctx->r25);
    // 0x8000A578: beq         $t0, $zero, L_8000A590
    if (ctx->r8 == 0) {
        // 0x8000A57C: addiu       $s2, $s2, 0x2A30
        ctx->r18 = ADD32(ctx->r18, 0X2A30);
            goto L_8000A590;
    }
    // 0x8000A57C: addiu       $s2, $s2, 0x2A30
    ctx->r18 = ADD32(ctx->r18, 0X2A30);
    // 0x8000A580: jal         0x80009EAC
    // 0x8000A584: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80009EAC(rdram, ctx);
        goto after_1;
    // 0x8000A584: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x8000A588: b           L_8000A794
    // 0x8000A58C: nop

        goto L_8000A794;
    // 0x8000A58C: nop

L_8000A590:
    // 0x8000A590: andi        $t1, $v0, 0x40
    ctx->r9 = ctx->r2 & 0X40;
    // 0x8000A594: beq         $t1, $zero, L_8000A710
    if (ctx->r9 == 0) {
        // 0x8000A598: addiu       $t2, $v0, -0x41
        ctx->r10 = ADD32(ctx->r2, -0X41);
            goto L_8000A710;
    }
    // 0x8000A598: addiu       $t2, $v0, -0x41
    ctx->r10 = ADD32(ctx->r2, -0X41);
    // 0x8000A59C: sltiu       $at, $t2, 0xC
    ctx->r1 = ctx->r10 < 0XC ? 1 : 0;
    // 0x8000A5A0: beq         $at, $zero, L_8000A794
    if (ctx->r1 == 0) {
        // 0x8000A5A4: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8000A794;
    }
    // 0x8000A5A4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8000A5A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000A5AC: addu        $at, $at, $t2
    gpr jr_addend_8000A5B4 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8000A5B0: lw          $t2, -0x4350($at)
    ctx->r10 = ADD32(ctx->r1, -0X4350);
    // 0x8000A5B4: jr          $t2
    // 0x8000A5B8: nop

    switch (jr_addend_8000A5B4 >> 2) {
        case 0: goto L_8000A5BC; break;
        case 1: goto L_8000A794; break;
        case 2: goto L_8000A794; break;
        case 3: goto L_8000A794; break;
        case 4: goto L_8000A794; break;
        case 5: goto L_8000A624; break;
        case 6: goto L_8000A5E8; break;
        case 7: goto L_8000A618; break;
        case 8: goto L_8000A600; break;
        case 9: goto L_8000A638; break;
        case 10: goto L_8000A658; break;
        case 11: goto L_8000A6C4; break;
        default: switch_error(__func__, 0x8000A5B4, 0x800ABCB0);
    }
    // 0x8000A5B8: nop

L_8000A5BC:
    // 0x8000A5BC: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8000A5C0: lwc1        $f4, 0x2C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8000A5C4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8000A5C8: nop

    // 0x8000A5CC: bc1t        L_8000A794
    if (c1cs) {
        // 0x8000A5D0: nop
    
            goto L_8000A794;
    }
    // 0x8000A5D0: nop

    // 0x8000A5D4: lbu         $t4, 0x0($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X0);
    // 0x8000A5D8: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
    // 0x8000A5DC: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x8000A5E0: b           L_8000A794
    // 0x8000A5E4: sb          $t5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r13;
        goto L_8000A794;
    // 0x8000A5E4: sb          $t5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r13;
L_8000A5E8:
    // 0x8000A5E8: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x8000A5EC: multu       $t6, $s7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A5F0: mflo        $t7
    ctx->r15 = lo;
    // 0x8000A5F4: sh          $t7, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r15;
    // 0x8000A5F8: b           L_8000A794
    // 0x8000A5FC: nop

        goto L_8000A794;
    // 0x8000A5FC: nop

L_8000A600:
    // 0x8000A600: lw          $t8, 0x4($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X4);
    // 0x8000A604: multu       $t8, $s7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A608: mflo        $t9
    ctx->r25 = lo;
    // 0x8000A60C: sh          $t9, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r25;
    // 0x8000A610: b           L_8000A794
    // 0x8000A614: nop

        goto L_8000A794;
    // 0x8000A614: nop

L_8000A618:
    // 0x8000A618: lb          $t0, 0x4($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X4);
    // 0x8000A61C: b           L_8000A794
    // 0x8000A620: sh          $t0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r8;
        goto L_8000A794;
    // 0x8000A620: sh          $t0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r8;
L_8000A624:
    // 0x8000A624: lbu         $t2, 0x3($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X3);
    // 0x8000A628: lb          $t1, 0x4($s3)
    ctx->r9 = MEM_B(ctx->r19, 0X4);
    // 0x8000A62C: addu        $t3, $s2, $t2
    ctx->r11 = ADD32(ctx->r18, ctx->r10);
    // 0x8000A630: b           L_8000A794
    // 0x8000A634: sb          $t1, 0x154($t3)
    MEM_B(0X154, ctx->r11) = ctx->r9;
        goto L_8000A794;
    // 0x8000A634: sb          $t1, 0x154($t3)
    MEM_B(0X154, ctx->r11) = ctx->r9;
L_8000A638:
    // 0x8000A638: lbu         $t4, 0x2($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X2);
    // 0x8000A63C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8000A640: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A644: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8000A648: nop

    // 0x8000A64C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000A650: b           L_8000A67C
    // 0x8000A654: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
        goto L_8000A67C;
    // 0x8000A654: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
L_8000A658:
    // 0x8000A658: lbu         $t5, 0x2($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X2);
    // 0x8000A65C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8000A660: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000A664: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8000A668: lwc1        $f8, 0x1C($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8000A66C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000A670: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000A674: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000A678: nop

L_8000A67C:
    // 0x8000A67C: lbu         $t6, 0x1($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X1);
    // 0x8000A680: beq         $s6, $t6, L_8000A794
    if (ctx->r22 == ctx->r14) {
        // 0x8000A684: nop
    
            goto L_8000A794;
    }
    // 0x8000A684: nop

    // 0x8000A688: lwc1        $f0, 0x1C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8000A68C: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
    // 0x8000A690: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8000A694: bnel        $v0, $zero, L_8000A6A8
    if (ctx->r2 != 0) {
        // 0x8000A698: mtc1        $v0, $f16
        ctx->f16.u32l = ctx->r2;
            goto L_8000A6A8;
    }
    goto skip_1;
    // 0x8000A698: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    skip_1:
    // 0x8000A69C: b           L_8000A794
    // 0x8000A6A0: swc1        $f2, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f2.u32l;
        goto L_8000A794;
    // 0x8000A6A0: swc1        $f2, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f2.u32l;
    // 0x8000A6A4: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_8000A6A8:
    // 0x8000A6A8: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8000A6AC: sb          $zero, 0x1($s2)
    MEM_B(0X1, ctx->r18) = 0;
    // 0x8000A6B0: sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // 0x8000A6B4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000A6B8: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8000A6BC: b           L_8000A794
    // 0x8000A6C0: swc1        $f4, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f4.u32l;
        goto L_8000A794;
    // 0x8000A6C0: swc1        $f4, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f4.u32l;
L_8000A6C4:
    // 0x8000A6C4: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x8000A6C8: beq         $s6, $t7, L_8000A794
    if (ctx->r22 == ctx->r15) {
        // 0x8000A6CC: nop
    
            goto L_8000A794;
    }
    // 0x8000A6CC: nop

    // 0x8000A6D0: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8000A6D4: bnel        $v0, $zero, L_8000A6EC
    if (ctx->r2 != 0) {
        // 0x8000A6D8: mtc1        $v0, $f18
        ctx->f18.u32l = ctx->r2;
            goto L_8000A6EC;
    }
    goto skip_2;
    // 0x8000A6D8: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    skip_2:
    // 0x8000A6DC: lwc1        $f6, 0x24($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X24);
    // 0x8000A6E0: b           L_8000A794
    // 0x8000A6E4: swc1        $f6, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f6.u32l;
        goto L_8000A794;
    // 0x8000A6E4: swc1        $f6, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f6.u32l;
    // 0x8000A6E8: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
L_8000A6EC:
    // 0x8000A6EC: lwc1        $f8, 0x24($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X24);
    // 0x8000A6F0: lwc1        $f16, 0x1C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8000A6F4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000A6F8: sb          $zero, 0x1($s2)
    MEM_B(0X1, ctx->r18) = 0;
    // 0x8000A6FC: sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // 0x8000A700: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8000A704: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000A708: b           L_8000A794
    // 0x8000A70C: swc1        $f6, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f6.u32l;
        goto L_8000A794;
    // 0x8000A70C: swc1        $f6, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f6.u32l;
L_8000A710:
    // 0x8000A710: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8000A714: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x8000A718: beq         $t9, $zero, L_8000A794
    if (ctx->r25 == 0) {
        // 0x8000A71C: nop
    
            goto L_8000A794;
    }
    // 0x8000A71C: nop

    // 0x8000A720: lbu         $v0, 0x2($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X2);
    // 0x8000A724: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000A728: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8000A72C: beq         $at, $zero, L_8000A74C
    if (ctx->r1 == 0) {
        // 0x8000A730: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8000A74C;
    }
    // 0x8000A730: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000A734: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8000A738: addu        $t2, $s2, $t0
    ctx->r10 = ADD32(ctx->r18, ctx->r8);
    // 0x8000A73C: jal         0x8000AA84
    // 0x8000A740: lw          $a0, 0x34($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X34);
    func_8000AA84(rdram, ctx);
        goto after_2;
    // 0x8000A740: lw          $a0, 0x34($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X34);
    after_2:
    // 0x8000A744: b           L_8000A794
    // 0x8000A748: nop

        goto L_8000A794;
    // 0x8000A748: nop

L_8000A74C:
    // 0x8000A74C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000A750: bne         $v1, $at, L_8000A794
    if (ctx->r3 != ctx->r1) {
        // 0x8000A754: sll         $t1, $a0, 1
        ctx->r9 = S32(ctx->r4 << 1);
            goto L_8000A794;
    }
    // 0x8000A754: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x8000A758: addu        $t3, $s5, $t1
    ctx->r11 = ADD32(ctx->r21, ctx->r9);
    // 0x8000A75C: lhu         $v0, 0x4F80($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X4F80);
    // 0x8000A760: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000A764:
    // 0x8000A764: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x8000A768: beq         $t4, $zero, L_8000A784
    if (ctx->r12 == 0) {
        // 0x8000A76C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000A784;
    }
    // 0x8000A76C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000A770: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8000A774: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x8000A778: lw          $a0, 0x34($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X34);
    // 0x8000A77C: jal         0x8000AA84
    // 0x8000A780: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_8000AA84(rdram, ctx);
        goto after_3;
    // 0x8000A780: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
L_8000A784:
    // 0x8000A784: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000A788: sra         $v0, $s1, 1
    ctx->r2 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8000A78C: bne         $s0, $s4, L_8000A764
    if (ctx->r16 != ctx->r20) {
        // 0x8000A790: andi        $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 & 0XFFFF;
            goto L_8000A764;
    }
    // 0x8000A790: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8000A794:
    // 0x8000A794: b           L_8000A4D8
    // 0x8000A798: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
        goto L_8000A4D8;
    // 0x8000A798: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
L_8000A79C:
    // 0x8000A79C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000A7A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000A7A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000A7A8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A7AC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000A7B0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000A7B4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000A7B8: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A7BC: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8000A7C0: jr          $ra
    // 0x8000A7C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8000A7C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8004D038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004D03C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D040: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8004D044: jal         0x8004C4D0
    // 0x8004D048: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_8004C4D0(rdram, ctx);
        goto after_0;
    // 0x8004D048: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x8004D04C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8004D050: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004D054: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8004D058: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8004D05C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004D060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004D064: jr          $ra
    // 0x8004D068: nop

    return;
    // 0x8004D068: nop

;}
RECOMP_FUNC void func_8077053C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077053C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80770540: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80770544: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80770548: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8077054C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80770550: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80770554: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80770558: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8077055C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80770560: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80770564: jr          $ra
    // 0x80770568: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80770568: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8056908C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056908C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80569090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80569094: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80569098: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8056909C: addiu       $at, $zero, 0x415A
    ctx->r1 = ADD32(0, 0X415A);
    // 0x805690A0: beq         $v0, $at, L_805690C0
    if (ctx->r2 == ctx->r1) {
        // 0x805690A4: addiu       $at, $zero, 0x4166
        ctx->r1 = ADD32(0, 0X4166);
            goto L_805690C0;
    }
    // 0x805690A4: addiu       $at, $zero, 0x4166
    ctx->r1 = ADD32(0, 0X4166);
    // 0x805690A8: beq         $v0, $at, L_805690D0
    if (ctx->r2 == ctx->r1) {
        // 0x805690AC: addiu       $at, $zero, 0x4172
        ctx->r1 = ADD32(0, 0X4172);
            goto L_805690D0;
    }
    // 0x805690AC: addiu       $at, $zero, 0x4172
    ctx->r1 = ADD32(0, 0X4172);
    // 0x805690B0: beql        $v0, $at, L_805690E0
    if (ctx->r2 == ctx->r1) {
        // 0x805690B4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_805690E0;
    }
    goto skip_0;
    // 0x805690B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x805690B8: b           L_805690EC
    // 0x805690BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
        goto L_805690EC;
    // 0x805690BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_805690C0:
    // 0x805690C0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x805690C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805690C8: b           L_805690EC
    // 0x805690CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
        goto L_805690EC;
    // 0x805690CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_805690D0:
    // 0x805690D0: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X220C) << 16);
    // 0x805690D4: b           L_805690E8
    // 0x805690D8: lwc1        $f0, -0x6844($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X220C));
        goto L_805690E8;
    // 0x805690D8: lwc1        $f0, -0x6844($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X220C));
    // 0x805690DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_805690E0:
    // 0x805690E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805690E4: nop

L_805690E8:
    // 0x805690E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_805690EC:
    // 0x805690EC: jal         0x80568710
    // 0x805690F0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x805690F0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805690F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x805690F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805690FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80569100: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80569104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80569108: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8056910C: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2210) << 16);
    // 0x80569110: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x80569114: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x80569118: lwc1        $f8, -0x6840($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2210));
    // 0x8056911C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80569120: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2214) << 16);
    // 0x80569124: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x80569128: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8056912C: lwc1        $f10, -0x683C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2214));
    // 0x80569130: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80569134: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80569138: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8056913C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80569140: jal         0x80569310
    // 0x80569144: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    func_80569310(rdram, ctx);
        goto after_1;
    // 0x80569144: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    after_1:
    // 0x80569148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8056914C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80569150: jr          $ra
    // 0x80569154: nop

    return;
    // 0x80569154: nop

;}
RECOMP_FUNC void func_805A585C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A585C: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x805A5860: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x805A5864: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x805A5868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805A586C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805A5870: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_805A5874:
    // 0x805A5874: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x805A5878: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x805A587C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x805A5880: lw          $t8, 0x5BC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X5BC);
    // 0x805A5884: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x805A5888: beq         $t8, $zero, L_805A5898
    if (ctx->r24 == 0) {
        // 0x805A588C: nop
    
            goto L_805A5898;
    }
    // 0x805A588C: nop

    // 0x805A5890: jr          $ra
    // 0x805A5894: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x805A5894: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_805A5898:
    // 0x805A5898: bnel        $v0, $a2, L_805A5874
    if (ctx->r2 != ctx->r6) {
        // 0x805A589C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_805A5874;
    }
    goto skip_0;
    // 0x805A589C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x805A58A0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x805A58A4: jr          $ra
    // 0x805A58A8: nop

    return;
    // 0x805A58A8: nop

;}
RECOMP_FUNC void func_80067990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067998: jal         0x80010688
    // 0x8006799C: nop

    func_80010688(rdram, ctx);
        goto after_0;
    // 0x8006799C: nop

    after_0:
    // 0x800679A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800679A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800679A8: jr          $ra
    // 0x800679AC: nop

    return;
    // 0x800679AC: nop

;}
RECOMP_FUNC void func_8073B504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073B504: lui         $a2, 0x8074
    ctx->r6 = S32(RELOC_HI16(739, 0X23B4) << 16);
    // 0x8073B508: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X2404) << 16);
    // 0x8073B50C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8073B510: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x8073B514: addiu       $v0, $v0, -0x41CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(739, 0X2404));
    // 0x8073B518: addiu       $a2, $a2, -0x421C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(739, 0X23B4));
    // 0x8073B51C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8073B520:
    // 0x8073B520: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x8073B524: bnel        $v1, $t6, L_8073B540
    if (ctx->r3 != ctx->r14) {
        // 0x8073B528: lhu         $t7, 0x2($a2)
        ctx->r15 = MEM_HU(ctx->r6, 0X2);
            goto L_8073B540;
    }
    goto skip_0;
    // 0x8073B528: lhu         $t7, 0x2($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X2);
    skip_0:
    // 0x8073B52C: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X2404) << 16);
    // 0x8073B530: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8073B534: jr          $ra
    // 0x8073B538: lhu         $v0, -0x41CC($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2404));
    return;
    // 0x8073B538: lhu         $v0, -0x41CC($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2404));
    // 0x8073B53C: lhu         $t7, 0x2($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X2);
L_8073B540:
    // 0x8073B540: bnel        $v1, $t7, L_8073B55C
    if (ctx->r3 != ctx->r15) {
        // 0x8073B544: lhu         $t8, 0x4($a2)
        ctx->r24 = MEM_HU(ctx->r6, 0X4);
            goto L_8073B55C;
    }
    goto skip_1;
    // 0x8073B544: lhu         $t8, 0x4($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X4);
    skip_1:
    // 0x8073B548: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X2406) << 16);
    // 0x8073B54C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8073B550: jr          $ra
    // 0x8073B554: lhu         $v0, -0x41CA($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2406));
    return;
    // 0x8073B554: lhu         $v0, -0x41CA($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2406));
    // 0x8073B558: lhu         $t8, 0x4($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X4);
L_8073B55C:
    // 0x8073B55C: bnel        $v1, $t8, L_8073B578
    if (ctx->r3 != ctx->r24) {
        // 0x8073B560: lhu         $t9, 0x6($a2)
        ctx->r25 = MEM_HU(ctx->r6, 0X6);
            goto L_8073B578;
    }
    goto skip_2;
    // 0x8073B560: lhu         $t9, 0x6($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X6);
    skip_2:
    // 0x8073B564: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X2408) << 16);
    // 0x8073B568: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8073B56C: jr          $ra
    // 0x8073B570: lhu         $v0, -0x41C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2408));
    return;
    // 0x8073B570: lhu         $v0, -0x41C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X2408));
    // 0x8073B574: lhu         $t9, 0x6($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X6);
L_8073B578:
    // 0x8073B578: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8073B57C: bne         $v1, $t9, L_8073B594
    if (ctx->r3 != ctx->r25) {
        // 0x8073B580: nop
    
            goto L_8073B594;
    }
    // 0x8073B580: nop

    // 0x8073B584: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0X240A) << 16);
    // 0x8073B588: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8073B58C: jr          $ra
    // 0x8073B590: lhu         $v0, -0x41C6($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X240A));
    return;
    // 0x8073B590: lhu         $v0, -0x41C6($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(739, 0X240A));
L_8073B594:
    // 0x8073B594: bne         $a2, $v0, L_8073B520
    if (ctx->r6 != ctx->r2) {
        // 0x8073B598: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_8073B520;
    }
    // 0x8073B598: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8073B59C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8073B5A0: jr          $ra
    // 0x8073B5A4: nop

    return;
    // 0x8073B5A4: nop

;}
RECOMP_FUNC void func_8004535C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004535C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80045360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80045364: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80045368: lw          $a3, 0x16C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X16C);
    // 0x8004536C: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x80045370: lw          $s0, 0x30($a3)
    ctx->r16 = MEM_W(ctx->r7, 0X30);
    // 0x80045374: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x80045378: beql        $s0, $t7, L_80045404
    if (ctx->r16 == ctx->r15) {
        // 0x8004537C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80045404;
    }
    goto skip_0;
    // 0x8004537C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80045380: lw          $v0, 0x38($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X38);
    // 0x80045384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80045388: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8004538C: beq         $v0, $zero, L_800453E8
    if (ctx->r2 == 0) {
        // 0x80045390: addiu       $a2, $sp, 0x30
        ctx->r6 = ADD32(ctx->r29, 0X30);
            goto L_800453E8;
    }
    // 0x80045390: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80045394: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80045398: jal         0x8007336C
    // 0x8004539C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_8007336C(rdram, ctx);
        goto after_0;
    // 0x8004539C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800453A0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800453A4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800453A8: jal         0x8005AB90
    // 0x800453AC: subu        $a0, $v0, $t8
    ctx->r4 = SUB32(ctx->r2, ctx->r24);
    func_8005AB90(rdram, ctx);
        goto after_1;
    // 0x800453AC: subu        $a0, $v0, $t8
    ctx->r4 = SUB32(ctx->r2, ctx->r24);
    after_1:
    // 0x800453B0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800453B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800453B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800453BC: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_800453C0:
    // 0x800453C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800453C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800453C8: bne         $v0, $a0, L_800453C0
    if (ctx->r2 != ctx->r4) {
        // 0x800453CC: sw          $zero, 0x34($v1)
        MEM_W(0X34, ctx->r3) = 0;
            goto L_800453C0;
    }
    // 0x800453CC: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x800453D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800453D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800453D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800453DC: jal         0x80073390
    // 0x800453E0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_80073390(rdram, ctx);
        goto after_2;
    // 0x800453E0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_2:
    // 0x800453E4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
L_800453E8:
    // 0x800453E8: beq         $s0, $zero, L_80045400
    if (ctx->r16 == 0) {
        // 0x800453EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80045400;
    }
    // 0x800453EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800453F0: jal         0x8005AB10
    // 0x800453F4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_8005AB10(rdram, ctx);
        goto after_3;
    // 0x800453F4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_3:
    // 0x800453F8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800453FC: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
L_80045400:
    // 0x80045400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80045404:
    // 0x80045404: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80045408: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8004540C: jr          $ra
    // 0x80045410: nop

    return;
    // 0x80045410: nop

;}
RECOMP_FUNC void func_806CF9B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CF9B8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x806CF9BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x806CF9C0: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x806CF9C4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_806CF9C8:
    // 0x806CF9C8: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x806CF9CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806CF9D0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806CF9D4: nop

    // 0x806CF9D8: bc1fl       L_806CFA08
    if (!c1cs) {
        // 0x806CF9DC: lwc1        $f0, 0x0($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
            goto L_806CFA08;
    }
    goto skip_0;
    // 0x806CF9DC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x806CF9E0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806CF9E4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806CF9E8: nop

    // 0x806CF9EC: bc1f        L_806CFA24
    if (!c1cs) {
        // 0x806CF9F0: nop
    
            goto L_806CFA24;
    }
    // 0x806CF9F0: nop

    // 0x806CF9F4: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x806CF9F8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806CF9FC: b           L_806CFA24
    // 0x806CFA00: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_806CFA24;
    // 0x806CFA00: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x806CFA04: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
L_806CFA08:
    // 0x806CFA08: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806CFA0C: nop

    // 0x806CFA10: bc1f        L_806CFA24
    if (!c1cs) {
        // 0x806CFA14: nop
    
            goto L_806CFA24;
    }
    // 0x806CFA14: nop

    // 0x806CFA18: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x806CFA1C: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x806CFA20: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_806CFA24:
    // 0x806CFA24: bne         $v1, $v0, L_806CF9C8
    if (ctx->r3 != ctx->r2) {
        // 0x806CFA28: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_806CF9C8;
    }
    // 0x806CFA28: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806CFA2C: jr          $ra
    // 0x806CFA30: nop

    return;
    // 0x806CFA30: nop

;}
RECOMP_FUNC void func_80027968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002796C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027970: jal         0x80024748
    // 0x80027974: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024748(rdram, ctx);
        goto after_0;
    // 0x80027974: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027978: beq         $v0, $zero, L_800279D4
    if (ctx->r2 == 0) {
        // 0x8002797C: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_800279D4;
    }
    // 0x8002797C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80027980: lw          $v1, 0x1F4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X1F4);
    // 0x80027984: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    // 0x80027988: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002798C: bne         $v0, $zero, L_8002799C
    if (ctx->r2 != 0) {
        // 0x80027990: sw          $v0, 0x44($v1)
        MEM_W(0X44, ctx->r3) = ctx->r2;
            goto L_8002799C;
    }
    // 0x80027990: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x80027994: b           L_800279D8
    // 0x80027998: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800279D8;
    // 0x80027998: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8002799C:
    // 0x8002799C: lw          $t6, 0x15C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X15C);
    // 0x800279A0: sw          $zero, 0x14C($a3)
    MEM_W(0X14C, ctx->r7) = 0;
    // 0x800279A4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800279A8: sb          $t7, 0x158($a3)
    MEM_B(0X158, ctx->r7) = ctx->r15;
    // 0x800279AC: jal         0x8001D770
    // 0x800279B0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x800279B0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x800279B4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800279B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800279BC: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x800279C0: jal         0x80067BF8
    // 0x800279C4: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x800279C4: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x800279C8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800279CC: jal         0x80067818
    // 0x800279D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x800279D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_800279D4:
    // 0x800279D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800279D8:
    // 0x800279D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800279DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800279E0: jr          $ra
    // 0x800279E4: nop

    return;
    // 0x800279E4: nop

;}
RECOMP_FUNC void func_8004246C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004246C: lbu         $t6, 0x159($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X159);
    // 0x80042470: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80042474: bne         $t6, $at, L_8004249C
    if (ctx->r14 != ctx->r1) {
        // 0x80042478: nop
    
            goto L_8004249C;
    }
    // 0x80042478: nop

    // 0x8004247C: lbu         $v0, 0x15A($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X15A);
    // 0x80042480: beq         $v0, $zero, L_8004249C
    if (ctx->r2 == 0) {
        // 0x80042484: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8004249C;
    }
    // 0x80042484: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80042488: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8004248C: bne         $v0, $zero, L_8004249C
    if (ctx->r2 != 0) {
        // 0x80042490: sb          $v0, 0x15A($a0)
        MEM_B(0X15A, ctx->r4) = ctx->r2;
            goto L_8004249C;
    }
    // 0x80042490: sb          $v0, 0x15A($a0)
    MEM_B(0X15A, ctx->r4) = ctx->r2;
    // 0x80042494: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80042498: sb          $t7, 0x159($a0)
    MEM_B(0X159, ctx->r4) = ctx->r15;
L_8004249C:
    // 0x8004249C: jr          $ra
    // 0x800424A0: nop

    return;
    // 0x800424A0: nop

;}
RECOMP_FUNC void func_807B7F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B7F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B7F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B7F98: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x807B7F9C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807B7FA0: lui         $t7, 0x807C
    ctx->r15 = S32(RELOC_HI16(883, 0X53C) << 16);
    // 0x807B7FA4: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x807B7FA8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807B7FAC: addiu       $t7, $t7, -0x7E84
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(883, 0X53C));
    // 0x807B7FB0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807B7FB4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807B7FB8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807B7FBC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807B7FC0: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x807B7FC4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x807B7FC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807B7FCC: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x807B7FD0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x807B7FD4: jal         0x80048378
    // 0x807B7FD8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x807B7FD8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x807B7FDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B7FE0: jal         0x80045A34
    // 0x807B7FE4: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x807B7FE4: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_1:
    // 0x807B7FE8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x807B7FEC: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x807B7FF0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x807B7FF4: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x807B7FF8: sh          $zero, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = 0;
    // 0x807B7FFC: lbu         $v1, -0x7203($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7203);
    // 0x807B8000: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807B8004: lw          $a2, 0x1F4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X1F4);
    // 0x807B8008: beq         $v1, $zero, L_807B8034
    if (ctx->r3 == 0) {
        // 0x807B800C: nop
    
            goto L_807B8034;
    }
    // 0x807B800C: nop

    // 0x807B8010: beq         $v1, $at, L_807B803C
    if (ctx->r3 == ctx->r1) {
        // 0x807B8014: addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
            goto L_807B803C;
    }
    // 0x807B8014: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x807B8018: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x807B801C: beq         $v1, $a3, L_807B8044
    if (ctx->r3 == ctx->r7) {
        // 0x807B8020: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_807B8044;
    }
    // 0x807B8020: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x807B8024: beql        $v1, $at, L_807B8050
    if (ctx->r3 == ctx->r1) {
        // 0x807B8028: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_807B8050;
    }
    goto skip_0;
    // 0x807B8028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_0:
    // 0x807B802C: b           L_807B8054
    // 0x807B8030: sll         $t0, $a3, 2
    ctx->r8 = S32(ctx->r7 << 2);
        goto L_807B8054;
    // 0x807B8030: sll         $t0, $a3, 2
    ctx->r8 = S32(ctx->r7 << 2);
L_807B8034:
    // 0x807B8034: b           L_807B8050
    // 0x807B8038: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_807B8050;
    // 0x807B8038: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_807B803C:
    // 0x807B803C: b           L_807B8050
    // 0x807B8040: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_807B8050;
    // 0x807B8040: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_807B8044:
    // 0x807B8044: b           L_807B8050
    // 0x807B8048: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_807B8050;
    // 0x807B8048: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x807B804C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_807B8050:
    // 0x807B8050: sll         $t0, $a3, 2
    ctx->r8 = S32(ctx->r7 << 2);
L_807B8054:
    // 0x807B8054: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x807B8058: sh          $a0, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = ctx->r4;
    // 0x807B805C: sh          $zero, 0x28($a2)
    MEM_H(0X28, ctx->r6) = 0;
    // 0x807B8060: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x807B8064: sh          $a0, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r4;
    // 0x807B8068: sh          $zero, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = 0;
    // 0x807B806C: addu        $v1, $a2, $t0
    ctx->r3 = ADD32(ctx->r6, ctx->r8);
    // 0x807B8070: sll         $t1, $a3, 1
    ctx->r9 = S32(ctx->r7 << 1);
    // 0x807B8074: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x807B8078: addu        $v0, $a2, $t1
    ctx->r2 = ADD32(ctx->r6, ctx->r9);
    // 0x807B807C: sh          $a0, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r4;
    // 0x807B8080: sh          $zero, 0x28($v0)
    MEM_H(0X28, ctx->r2) = 0;
    // 0x807B8084: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x807B8088: sh          $zero, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = 0;
    // 0x807B808C: sh          $a0, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r4;
    // 0x807B8090: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x807B8094: sh          $zero, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = 0;
    // 0x807B8098: sh          $a0, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r4;
    // 0x807B809C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x807B80A0: sh          $zero, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = 0;
    // 0x807B80A4: sh          $a0, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r4;
    // 0x807B80A8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x807B80AC: sh          $a3, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = ctx->r7;
    // 0x807B80B0: sh          $zero, 0x28($a2)
    MEM_H(0X28, ctx->r6) = 0;
    // 0x807B80B4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x807B80B8: sh          $a3, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r7;
    // 0x807B80BC: sh          $zero, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = 0;
    // 0x807B80C0: sw          $zero, 0x18($a2)
    MEM_W(0X18, ctx->r6) = 0;
    // 0x807B80C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B80C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B80CC: jr          $ra
    // 0x807B80D0: nop

    return;
    // 0x807B80D0: nop

;}
RECOMP_FUNC void func_805A2550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A2550: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A2554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A2558: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A255C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A2560: jal         0x8004700C
    // 0x805A2564: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805A2564: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x805A2568: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A256C: beq         $v0, $zero, L_805A2648
    if (ctx->r2 == 0) {
        // 0x805A2570: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_805A2648;
    }
    // 0x805A2570: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x805A2574: lw          $v1, 0x18($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X18);
    // 0x805A2578: beq         $v1, $zero, L_805A2588
    if (ctx->r3 == 0) {
        // 0x805A257C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_805A2588;
    }
    // 0x805A257C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x805A2580: sw          $t6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r14;
    // 0x805A2584: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_805A2588:
    // 0x805A2588: bnel        $v1, $zero, L_805A25D8
    if (ctx->r3 != 0) {
        // 0x805A258C: lwc1        $f4, 0x84($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
            goto L_805A25D8;
    }
    goto skip_0;
    // 0x805A258C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    skip_0:
    // 0x805A2590: lw          $v1, 0x14($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X14);
    // 0x805A2594: lui         $t8, 0x805A
    ctx->r24 = S32(RELOC_HI16(411, 0X1C1C) << 16);
    // 0x805A2598: lui         $t1, 0x805A
    ctx->r9 = S32(RELOC_HI16(411, 0X1C10) << 16);
    // 0x805A259C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x805A25A0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805A25A4: lw          $t8, 0x2F8C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(411, 0X1C1C));
    // 0x805A25A8: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x805A25AC: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x805A25B0: sw          $t8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r24;
    // 0x805A25B4: lhu         $t1, 0x2F80($t1)
    ctx->r9 = MEM_HU(ctx->r9, (int16_t)RELOC_LO16(411, 0X1C10));
    // 0x805A25B8: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x805A25BC: lw          $t2, 0x14($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X14);
    // 0x805A25C0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x805A25C4: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x805A25C8: bne         $at, $zero, L_805A25D4
    if (ctx->r1 != 0) {
        // 0x805A25CC: sw          $t3, 0x14($t0)
        MEM_W(0X14, ctx->r8) = ctx->r11;
            goto L_805A25D4;
    }
    // 0x805A25CC: sw          $t3, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r11;
    // 0x805A25D0: sw          $zero, 0x14($t0)
    MEM_W(0X14, ctx->r8) = 0;
L_805A25D4:
    // 0x805A25D4: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
L_805A25D8:
    // 0x805A25D8: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x805A25DC: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(411, 0X1D58) << 16);
    // 0x805A25E0: lwc1        $f8, 0x30C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(411, 0X1D58));
    // 0x805A25E4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805A25E8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805A25EC: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x805A25F0: nop

    // 0x805A25F4: bc1fl       L_805A264C
    if (!c1cs) {
        // 0x805A25F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A264C;
    }
    goto skip_1;
    // 0x805A25F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x805A25FC: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805A2600: lwc1        $f16, 0x88($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X88);
    // 0x805A2604: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x805A2608: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805A260C: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805A2610: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x805A2614: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805A2618: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x805A261C: nop

    // 0x805A2620: bc1fl       L_805A264C
    if (!c1cs) {
        // 0x805A2624: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A264C;
    }
    goto skip_2;
    // 0x805A2624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x805A2628: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A262C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A2630: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x805A2634: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x805A2638: lwc1        $f6, 0x2C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x805A263C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x805A2640: jal         0x805A2B28
    // 0x805A2644: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    func_805A2B28(rdram, ctx);
        goto after_1;
    // 0x805A2644: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    after_1:
L_805A2648:
    // 0x805A2648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A264C:
    // 0x805A264C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A2650: jr          $ra
    // 0x805A2654: nop

    return;
    // 0x805A2654: nop

;}
RECOMP_FUNC void func_800717BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800717BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800717C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800717C4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800717C8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800717CC: addiu       $a0, $a0, -0x5E30
    ctx->r4 = ADD32(ctx->r4, -0X5E30);
    // 0x800717D0: jal         0x8008AFE0
    // 0x800717D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osJamMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800717D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800717D8: jal         0x80086880
    // 0x800717DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadId_recomp(rdram, ctx);
        goto after_1;
    // 0x800717DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800717E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800717E4: bne         $v0, $at, L_800717FC
    if (ctx->r2 != ctx->r1) {
        // 0x800717E8: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800717FC;
    }
    // 0x800717E8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800717EC: addiu       $v0, $v0, -0x7B80
    ctx->r2 = ADD32(ctx->r2, -0X7B80);
    // 0x800717F0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800717F4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800717F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800717FC:
    // 0x800717FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071804: jr          $ra
    // 0x80071808: nop

    return;
    // 0x80071808: nop

;}
RECOMP_FUNC void func_807A6A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6A64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A6A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A6A6C: jal         0x807A6A0C
    // 0x807A6A70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807A6A0C(rdram, ctx);
        goto after_0;
    // 0x807A6A70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A6A74: bne         $v0, $zero, L_807A6A8C
    if (ctx->r2 != 0) {
        // 0x807A6A78: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807A6A8C;
    }
    // 0x807A6A78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A6A7C: jal         0x80044658
    // 0x807A6A80: nop

    func_80044658(rdram, ctx);
        goto after_1;
    // 0x807A6A80: nop

    after_1:
    // 0x807A6A84: b           L_807A6AC8
    // 0x807A6A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A6AC8;
    // 0x807A6A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A6A8C:
    // 0x807A6A8C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x807A6A90: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x807A6A94: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x807A6A98: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(847, 0X1504) << 16);
    // 0x807A6A9C: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x807A6AA0: addiu       $t7, $t7, 0x7204
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(847, 0X1504));
    // 0x807A6AA4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807A6AA8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807A6AAC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807A6AB0: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807A6AB4: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807A6AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A6ABC: jal         0x807A6AD4
    // 0x807A6AC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807A6AD4(rdram, ctx);
        goto after_2;
    // 0x807A6AC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x807A6AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A6AC8:
    // 0x807A6AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A6ACC: jr          $ra
    // 0x807A6AD0: nop

    return;
    // 0x807A6AD0: nop

;}
RECOMP_FUNC void func_80791380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791380: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80791384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80791388: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079138C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80791390: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x80791394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791398: jal         0x807903C4
    // 0x8079139C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x8079139C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x807913A0: jal         0x80790714
    // 0x807913A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x807913A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x807913A8: beq         $v0, $zero, L_807913F8
    if (ctx->r2 == 0) {
        // 0x807913AC: addiu       $t6, $zero, 0x46
        ctx->r14 = ADD32(0, 0X46);
            goto L_807913F8;
    }
    // 0x807913AC: addiu       $t6, $zero, 0x46
    ctx->r14 = ADD32(0, 0X46);
    // 0x807913B0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807913B4: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x807913B8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807913BC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x807913C0: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x807913C4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807913C8: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x807913CC: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
    // 0x807913D0: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    // 0x807913D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807913D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807913DC: jal         0x8079393C
    // 0x807913E0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x807913E0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_2:
    // 0x807913E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x807913E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807913EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x807913F0: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x807913F4: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_807913F8:
    // 0x807913F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807913FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80791400: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80791404: jr          $ra
    // 0x80791408: nop

    return;
    // 0x80791408: nop

;}
RECOMP_FUNC void func_8064F168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F168: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F16C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F170: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F174: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F178: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F17C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F180: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F184: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F188: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F18C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F190: jr          $ra
    // 0x8064F194: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F194: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8067A0B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067A0B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8067A0B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067A0B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8067A0BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8067A0C0: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8067A0C4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8067A0C8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8067A0CC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8067A0D0: bne         $t6, $at, L_8067A234
    if (ctx->r14 != ctx->r1) {
        // 0x8067A0D4: lw          $t0, 0x1F4($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X1F4);
            goto L_8067A234;
    }
    // 0x8067A0D4: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067A0D8: lbu         $v0, 0x18($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X18);
    // 0x8067A0DC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8067A0E0: lwc1        $f16, 0xC4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x8067A0E4: lwc1        $f2, 0xC8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0XC8);
    // 0x8067A0E8: beq         $v0, $at, L_8067A0F8
    if (ctx->r2 == ctx->r1) {
        // 0x8067A0EC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8067A0F8;
    }
    // 0x8067A0EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8067A0F0: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8067A0F4: bne         $v0, $at, L_8067A110
    if (ctx->r2 != ctx->r1) {
        // 0x8067A0F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8067A110;
    }
L_8067A0F8:
    // 0x8067A0F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067A0FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8067A100: jal         0x80040AC8
    // 0x8067A104: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_80040AC8(rdram, ctx);
        goto after_0;
    // 0x8067A104: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x8067A108: b           L_8067A1DC
    // 0x8067A10C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
        goto L_8067A1DC;
    // 0x8067A10C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_8067A110:
    // 0x8067A110: lwc1        $f0, 0xC4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8067A114: lwc1        $f12, 0x0($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8067A118: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8067A11C: sub.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8067A120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067A124: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8067A128: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
    // 0x8067A12C: nop

    // 0x8067A130: bc1fl       L_8067A168
    if (!c1cs) {
        // 0x8067A134: lwc1        $f0, 0xC8($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0XC8);
            goto L_8067A168;
    }
    goto skip_0;
    // 0x8067A134: lwc1        $f0, 0xC8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC8);
    skip_0:
    // 0x8067A138: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8067A13C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8067A140: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067A144: div.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8067A148: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8067A14C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067A150: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8067A154: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8067A158: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8067A15C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8067A160: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8067A164: lwc1        $f0, 0xC8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC8);
L_8067A168:
    // 0x8067A168: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8067A16C: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2670) << 16);
    // 0x8067A170: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8067A174: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8067A178: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x8067A17C: nop

    // 0x8067A180: bc1fl       L_8067A1BC
    if (!c1cs) {
        // 0x8067A184: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8067A1BC;
    }
    goto skip_1;
    // 0x8067A184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x8067A188: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8067A18C: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x8067A190: bc1fl       L_8067A1A0
    if (!c1cs) {
        // 0x8067A194: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_8067A1A0;
    }
    goto skip_2;
    // 0x8067A194: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_2:
    // 0x8067A198: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067A19C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_8067A1A0:
    // 0x8067A1A0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8067A1A4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8067A1A8: lwc1        $f2, -0x3CE0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2670));
    // 0x8067A1AC: bc1f        L_8067A1B8
    if (!c1cs) {
        // 0x8067A1B0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8067A1B8;
    }
    // 0x8067A1B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8067A1B4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_8067A1B8:
    // 0x8067A1B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8067A1BC:
    // 0x8067A1BC: bnel        $v1, $at, L_8067A1E0
    if (ctx->r3 != ctx->r1) {
        // 0x8067A1C0: lw          $t9, 0x30($t0)
        ctx->r25 = MEM_W(ctx->r8, 0X30);
            goto L_8067A1E0;
    }
    goto skip_3;
    // 0x8067A1C0: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    skip_3:
    // 0x8067A1C4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8067A1C8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8067A1CC: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8067A1D0: jal         0x8002F96C
    // 0x8067A1D4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_8002F96C(rdram, ctx);
        goto after_1;
    // 0x8067A1D4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_1:
    // 0x8067A1D8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_8067A1DC:
    // 0x8067A1DC: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
L_8067A1E0:
    // 0x8067A1E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8067A1E4: beql        $v0, $t9, L_8067A1F8
    if (ctx->r2 == ctx->r25) {
        // 0x8067A1E8: lw          $a0, 0x34($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X34);
            goto L_8067A1F8;
    }
    goto skip_4;
    // 0x8067A1E8: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    skip_4:
    // 0x8067A1EC: sw          $v0, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r2;
    // 0x8067A1F0: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x8067A1F4: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
L_8067A1F8:
    // 0x8067A1F8: jal         0x80067BBC
    // 0x8067A1FC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8067A1FC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_2:
    // 0x8067A200: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    // 0x8067A204: jal         0x80067818
    // 0x8067A208: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8067A208: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8067A20C: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x8067A210: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8067A214: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x8067A218: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8067A21C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8067A220: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x8067A224: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8067A228: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8067A22C: b           L_8067A2A0
    // 0x8067A230: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
        goto L_8067A2A0;
    // 0x8067A230: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
L_8067A234:
    // 0x8067A234: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    // 0x8067A238: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8067A23C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8067A240: beq         $v0, $at, L_8067A254
    if (ctx->r2 == ctx->r1) {
        // 0x8067A244: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8067A254;
    }
    // 0x8067A244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067A248: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8067A24C: bnel        $v0, $at, L_8067A2A4
    if (ctx->r2 != ctx->r1) {
        // 0x8067A250: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8067A2A4;
    }
    goto skip_5;
    // 0x8067A250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
L_8067A254:
    // 0x8067A254: sw          $t4, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r12;
    // 0x8067A258: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x8067A25C: jal         0x8003E3D4
    // 0x8067A260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003E3D4(rdram, ctx);
        goto after_4;
    // 0x8067A260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8067A264: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8067A268: jal         0x80067BBC
    // 0x8067A26C: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8067A26C: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_5:
    // 0x8067A270: addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    // 0x8067A274: jal         0x80067818
    // 0x8067A278: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8067A278: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8067A27C: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x8067A280: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8067A284: sb          $t5, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r13;
    // 0x8067A288: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8067A28C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8067A290: sb          $t6, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r14;
    // 0x8067A294: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8067A298: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8067A29C: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
L_8067A2A0:
    // 0x8067A2A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067A2A4:
    // 0x8067A2A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8067A2A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8067A2AC: jr          $ra
    // 0x8067A2B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8067A2B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80018E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018E68: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80018E6C: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80018E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018E78: bne         $v0, $zero, L_80018E88
    if (ctx->r2 != 0) {
        // 0x80018E7C: addiu       $a1, $zero, 0xF
        ctx->r5 = ADD32(0, 0XF);
            goto L_80018E88;
    }
    // 0x80018E7C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80018E80: b           L_80018EAC
    // 0x80018E84: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80018EAC;
    // 0x80018E84: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80018E88:
    // 0x80018E88: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80018E8C: jal         0x8000A9CC
    // 0x80018E90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000A9CC(rdram, ctx);
        goto after_0;
    // 0x80018E90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80018E94: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80018E98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80018E9C: bne         $v0, $at, L_80018EA8
    if (ctx->r2 != ctx->r1) {
        // 0x80018EA0: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_80018EA8;
    }
    // 0x80018EA0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80018EA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80018EA8:
    // 0x80018EA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80018EAC:
    // 0x80018EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018EB4: jr          $ra
    // 0x80018EB8: nop

    return;
    // 0x80018EB8: nop

;}
RECOMP_FUNC void func_805DCCFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DCCFC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805DCD00: lui         $t6, 0x805E
    ctx->r14 = S32(RELOC_HI16(480, 0X1F90) << 16);
    // 0x805DCD04: addiu       $t6, $t6, -0x3370
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(480, 0X1F90));
    // 0x805DCD08: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805DCD0C: jr          $ra
    // 0x805DCD10: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x805DCD10: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804548C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804548C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804548C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804548C8: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X13904) << 16);
    // 0x804548CC: jal         0x804547C0
    // 0x804548D0: lw          $a1, 0x7CE4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13904));
    func_804547C0(rdram, ctx);
        goto after_0;
    // 0x804548D0: lw          $a1, 0x7CE4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13904));
    after_0:
    // 0x804548D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804548D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804548DC: jr          $ra
    // 0x804548E0: nop

    return;
    // 0x804548E0: nop

;}
RECOMP_FUNC void func_8073B804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073B804: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8073B808: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073B80C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073B810: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073B814: lw          $t6, 0x44($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X44);
    // 0x8073B818: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8073B81C: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x8073B820: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8073B824: lbu         $s0, 0x10($t7)
    ctx->r16 = MEM_BU(ctx->r15, 0X10);
    // 0x8073B828: addiu       $s0, $s0, 0x5
    ctx->r16 = ADD32(ctx->r16, 0X5);
    // 0x8073B82C: sltiu       $at, $s0, 0xFF
    ctx->r1 = ctx->r16 < 0XFF ? 1 : 0;
    // 0x8073B830: bnel        $at, $zero, L_8073B8B4
    if (ctx->r1 != 0) {
        // 0x8073B834: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_8073B8B4;
    }
    goto skip_0;
    // 0x8073B834: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8073B838: jal         0x8073AEB4
    // 0x8073B83C: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    func_8073AEB4(rdram, ctx);
        goto after_0;
    // 0x8073B83C: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    after_0:
    // 0x8073B840: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8073B844: lw          $t9, -0x7478($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7478);
    // 0x8073B848: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8073B84C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8073B850: beq         $t9, $zero, L_8073B89C
    if (ctx->r25 == 0) {
        // 0x8073B854: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8073B89C;
    }
    // 0x8073B854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073B858: lw          $t0, -0x71A8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X71A8);
    // 0x8073B85C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8073B860: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8073B864: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8073B868: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x8073B86C: bne         $t2, $at, L_8073B88C
    if (ctx->r10 != ctx->r1) {
        // 0x8073B870: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8073B88C;
    }
    // 0x8073B870: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073B874: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8073B878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073B87C: jal         0x8006E0FC
    // 0x8073B880: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_8006E0FC(rdram, ctx);
        goto after_1;
    // 0x8073B880: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_1:
    // 0x8073B884: b           L_8073B8B4
    // 0x8073B888: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
        goto L_8073B8B4;
    // 0x8073B888: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_8073B88C:
    // 0x8073B88C: jal         0x8006E0FC
    // 0x8073B890: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    func_8006E0FC(rdram, ctx);
        goto after_2;
    // 0x8073B890: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    after_2:
    // 0x8073B894: b           L_8073B8B4
    // 0x8073B898: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
        goto L_8073B8B4;
    // 0x8073B898: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_8073B89C:
    // 0x8073B89C: jal         0x8006E0FC
    // 0x8073B8A0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8006E0FC(rdram, ctx);
        goto after_3;
    // 0x8073B8A0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x8073B8A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8073B8A8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8073B8AC: sw          $t3, -0x7200($at)
    MEM_W(-0X7200, ctx->r1) = ctx->r11;
    // 0x8073B8B0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_8073B8B4:
    // 0x8073B8B4: sb          $s0, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r16;
    // 0x8073B8B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073B8BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073B8C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8073B8C4: jr          $ra
    // 0x8073B8C8: nop

    return;
    // 0x8073B8C8: nop

;}
RECOMP_FUNC void func_80558D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558D24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80558D28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80558D2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80558D30: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80558D34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80558D38: jal         0x8004700C
    // 0x80558D3C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80558D3C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80558D40: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80558D44: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80558D48: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80558D4C: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80558D50: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80558D54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558D58: jal         0x80048F84
    // 0x80558D5C: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80558D5C: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    after_1:
    // 0x80558D60: jal         0x805580E8
    // 0x80558D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805580E8(rdram, ctx);
        goto after_2;
    // 0x80558D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80558D68: jal         0x805582E0
    // 0x80558D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805582E0(rdram, ctx);
        goto after_3;
    // 0x80558D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80558D70: beq         $v0, $zero, L_80558DA4
    if (ctx->r2 == 0) {
        // 0x80558D74: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_80558DA4;
    }
    // 0x80558D74: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80558D78: beq         $t8, $zero, L_80558D98
    if (ctx->r24 == 0) {
        // 0x80558D7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80558D98;
    }
    // 0x80558D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558D80: lw          $t9, 0x1E4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E4);
    // 0x80558D84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80558D88: bnel        $t9, $at, L_80558D9C
    if (ctx->r25 != ctx->r1) {
        // 0x80558D8C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80558D9C;
    }
    goto skip_0;
    // 0x80558D8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_0:
    // 0x80558D90: b           L_80558DA4
    // 0x80558D94: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
        goto L_80558DA4;
    // 0x80558D94: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
L_80558D98:
    // 0x80558D98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80558D9C:
    // 0x80558D9C: jal         0x80559928
    // 0x80558DA0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    func_80559928(rdram, ctx);
        goto after_4;
    // 0x80558DA0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_4:
L_80558DA4:
    // 0x80558DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80558DA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80558DAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80558DB0: jr          $ra
    // 0x80558DB4: nop

    return;
    // 0x80558DB4: nop

;}
RECOMP_FUNC void func_8046A80C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A80C: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8046A810: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x8046A814: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046A818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046A81C: lb          $t7, 0x3($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X3);
    // 0x8046A820: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8046A824: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8046A828: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8046A82C: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2970) << 16);
    // 0x8046A830: lwc1        $f6, -0x3F50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2970));
    // 0x8046A834: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8046A838: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2974) << 16);
    // 0x8046A83C: lwc1        $f10, -0x3F4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2974));
    // 0x8046A840: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046A844: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2978) << 16);
    // 0x8046A848: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8046A84C: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8046A850: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8046A854: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8046A858: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8046A85C: lwc1        $f8, -0x3F48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2978));
    // 0x8046A860: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8046A864: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8046A868: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8046A86C: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x8046A870: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8046A874: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8046A878: nop

    // 0x8046A87C: bc1fl       L_8046A894
    if (!c1cs) {
        // 0x8046A880: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8046A894;
    }
    goto skip_0;
    // 0x8046A880: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8046A884: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x8046A888: b           L_8046A8B0
    // 0x8046A88C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
        goto L_8046A8B0;
    // 0x8046A88C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8046A890: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8046A894:
    // 0x8046A894: nop

    // 0x8046A898: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8046A89C: nop

    // 0x8046A8A0: bc1fl       L_8046A8B4
    if (!c1cs) {
        // 0x8046A8A4: lwc1        $f16, 0x10($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
            goto L_8046A8B4;
    }
    goto skip_1;
    // 0x8046A8A4: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    skip_1:
    // 0x8046A8A8: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x8046A8AC: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
L_8046A8B0:
    // 0x8046A8B0: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
L_8046A8B4:
    // 0x8046A8B4: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046A8B8: add.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8046A8BC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8046A8C0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8046A8C4: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046A8C8: jal         0x804697D8
    // 0x8046A8CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804697D8(rdram, ctx);
        goto after_0;
    // 0x8046A8CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8046A8D0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8046A8D4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8046A8D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046A8DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046A8E0: jr          $ra
    // 0x8046A8E4: nop

    return;
    // 0x8046A8E4: nop

;}
RECOMP_FUNC void func_8003B078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B078: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003B07C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B080: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8003B084: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8003B088: addiu       $t6, $t6, 0x5284
    ctx->r14 = ADD32(ctx->r14, 0X5284);
    // 0x8003B08C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8003B090: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8003B094: jal         0x8005FE48
    // 0x8003B098: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x8003B098: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003B09C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B0A0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8003B0A4: sb          $zero, 0x74($t7)
    MEM_B(0X74, ctx->r15) = 0;
    // 0x8003B0A8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003B0AC: sb          $zero, 0x75($t8)
    MEM_B(0X75, ctx->r24) = 0;
    // 0x8003B0B0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8003B0B4: sw          $zero, 0x44($t9)
    MEM_W(0X44, ctx->r25) = 0;
    // 0x8003B0B8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003B0BC: sh          $zero, 0x4C($t0)
    MEM_H(0X4C, ctx->r8) = 0;
    // 0x8003B0C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B0C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003B0C8: jr          $ra
    // 0x8003B0CC: nop

    return;
    // 0x8003B0CC: nop

;}
RECOMP_FUNC void func_8069D90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D90C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069D910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D914: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8069D918: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8069D91C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8069D920: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x8069D924: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8069D928: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8069D92C: bnel        $t7, $at, L_8069D960
    if (ctx->r15 != ctx->r1) {
        // 0x8069D930: lhu         $t1, 0xC($t0)
        ctx->r9 = MEM_HU(ctx->r8, 0XC);
            goto L_8069D960;
    }
    goto skip_0;
    // 0x8069D930: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    skip_0:
    // 0x8069D934: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069D938: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8069D93C: jal         0x8069D8CC
    // 0x8069D940: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8069D8CC(rdram, ctx);
        goto after_0;
    // 0x8069D940: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069D944: jal         0x8004816C
    // 0x8069D948: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x8069D948: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8069D94C: jal         0x8069D820
    // 0x8069D950: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8069D820(rdram, ctx);
        goto after_2;
    // 0x8069D950: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8069D954: b           L_8069D97C
    // 0x8069D958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8069D97C;
    // 0x8069D958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D95C: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
L_8069D960:
    // 0x8069D960: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8069D964: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8069D968: bne         $t1, $at, L_8069D978
    if (ctx->r9 != ctx->r1) {
        // 0x8069D96C: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_8069D978;
    }
    // 0x8069D96C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8069D970: jal         0x8002F6E4
    // 0x8069D974: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_3;
    // 0x8069D974: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
L_8069D978:
    // 0x8069D978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8069D97C:
    // 0x8069D97C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069D980: jr          $ra
    // 0x8069D984: nop

    return;
    // 0x8069D984: nop

;}
RECOMP_FUNC void func_80027B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027B78: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80027B7C: addiu       $t6, $t6, 0x7B4C
    ctx->r14 = ADD32(ctx->r14, 0X7B4C);
    // 0x80027B80: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80027B84: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80027B88: jr          $ra
    // 0x80027B8C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80027B8C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8073AEB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073AEB4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8073AEB8: lw          $t6, -0x7470($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7470);
    // 0x8073AEBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8073AEC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073AEC4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8073AEC8: lhu         $t7, 0x1A($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1A);
    // 0x8073AECC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8073AED0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8073AED4: sh          $t7, -0x74BC($at)
    MEM_H(-0X74BC, ctx->r1) = ctx->r15;
    // 0x8073AED8: lhu         $t8, 0x1C($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X1C);
    // 0x8073AEDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8073AEE0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8073AEE4: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x8073AEE8: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
    // 0x8073AEEC: sh          $t8, -0x74BA($at)
    MEM_H(-0X74BA, ctx->r1) = ctx->r24;
    // 0x8073AEF0: lhu         $t0, 0x1A($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X1A);
    // 0x8073AEF4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8073AEF8: addiu       $t9, $t9, -0x76C0
    ctx->r25 = ADD32(ctx->r25, -0X76C0);
    // 0x8073AEFC: addu        $v1, $a0, $t9
    ctx->r3 = ADD32(ctx->r4, ctx->r25);
    // 0x8073AF00: sh          $t0, 0x204($v1)
    MEM_H(0X204, ctx->r3) = ctx->r8;
    // 0x8073AF04: lhu         $t1, 0x1C($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X1C);
    // 0x8073AF08: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x8073AF0C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8073AF10: sh          $t1, 0x206($v1)
    MEM_H(0X206, ctx->r3) = ctx->r9;
    // 0x8073AF14: lhu         $t2, 0x1E($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X1E);
    // 0x8073AF18: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8073AF1C: sh          $t2, 0x208($v1)
    MEM_H(0X208, ctx->r3) = ctx->r10;
    // 0x8073AF20: lhu         $t3, 0x20($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X20);
    // 0x8073AF24: sh          $t3, 0x20A($v1)
    MEM_H(0X20A, ctx->r3) = ctx->r11;
    // 0x8073AF28: lw          $t4, -0x7478($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7478);
    // 0x8073AF2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8073AF30: beq         $t4, $zero, L_8073AF54
    if (ctx->r12 == 0) {
        // 0x8073AF34: nop
    
            goto L_8073AF54;
    }
    // 0x8073AF34: nop

    // 0x8073AF38: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8073AF3C: lhu         $a2, -0x7492($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X7492);
    // 0x8073AF40: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8073AF44: jal         0x8073AC44
    // 0x8073AF48: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_8073AC44(rdram, ctx);
        goto after_0;
    // 0x8073AF48: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x8073AF4C: b           L_8073AF5C
    // 0x8073AF50: nop

        goto L_8073AF5C;
    // 0x8073AF50: nop

L_8073AF54:
    // 0x8073AF54: jal         0x8073AD70
    // 0x8073AF58: lhu         $a2, -0x7472($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X7472);
    func_8073AD70(rdram, ctx);
        goto after_1;
    // 0x8073AF58: lhu         $a2, -0x7472($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X7472);
    after_1:
L_8073AF5C:
    // 0x8073AF5C: jal         0x8006988C
    // 0x8073AF60: nop

    func_8006988C(rdram, ctx);
        goto after_2;
    // 0x8073AF60: nop

    after_2:
    // 0x8073AF64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073AF68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8073AF6C: jr          $ra
    // 0x8073AF70: nop

    return;
    // 0x8073AF70: nop

;}
RECOMP_FUNC void func_8049FC18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049FC18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8049FC1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8049FC20: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8049FC24: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8049FC28: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8049FC2C: lui         $t8, 0x804A
    ctx->r24 = S32(RELOC_HI16(167, 0X1250) << 16);
    // 0x8049FC30: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8049FC34: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8049FC38: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8049FC3C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8049FC40: lw          $t8, -0x230($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(167, 0X1250));
    // 0x8049FC44: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8049FC48: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8049FC4C: jal         0x80048490
    // 0x8049FC50: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8049FC50: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8049FC54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8049FC58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8049FC5C: jr          $ra
    // 0x8049FC60: nop

    return;
    // 0x8049FC60: nop

;}
RECOMP_FUNC void func_80069644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006964C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80069650: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x80069654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069658: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8006965C: addiu       $t8, $t7, 0xFC2
    ctx->r24 = ADD32(ctx->r15, 0XFC2);
    // 0x80069660: addiu       $t9, $t9, 0x7EA0
    ctx->r25 = ADD32(ctx->r25, 0X7EA0);
    // 0x80069664: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80069668: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8006966C: jal         0x8006958C
    // 0x80069670: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8006958C(rdram, ctx);
        goto after_0;
    // 0x80069670: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x80069674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006967C: jr          $ra
    // 0x80069680: nop

    return;
    // 0x80069680: nop

;}
RECOMP_FUNC void func_806FE044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FE044: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x806FE048: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x806FE04C: lw          $t6, 0x478($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X478);
    // 0x806FE050: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806FE054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FE058: lbu         $t7, 0xF8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XF8);
    // 0x806FE05C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x806FE060: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FE064: beql        $t7, $zero, L_806FE08C
    if (ctx->r15 == 0) {
        // 0x806FE068: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_806FE08C;
    }
    goto skip_0;
    // 0x806FE068: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x806FE06C: lw          $t8, 0xAA4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XAA4);
    // 0x806FE070: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(706, 0XB40) << 16);
    // 0x806FE074: addiu       $t9, $t9, -0x2060
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(706, 0XB40));
    // 0x806FE078: beql        $t8, $zero, L_806FE08C
    if (ctx->r24 == 0) {
        // 0x806FE07C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_806FE08C;
    }
    goto skip_1;
    // 0x806FE07C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_1:
    // 0x806FE080: b           L_806FE240
    // 0x806FE084: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
        goto L_806FE240;
    // 0x806FE084: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x806FE088: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_806FE08C:
    // 0x806FE08C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x806FE090: jal         0x80062D14
    // 0x806FE094: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80062D14(rdram, ctx);
        goto after_0;
    // 0x806FE094: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x806FE098: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x806FE09C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806FE0A0: lw          $t0, 0x1E0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1E0);
    // 0x806FE0A4: addiu       $a0, $a1, 0x84
    ctx->r4 = ADD32(ctx->r5, 0X84);
    // 0x806FE0A8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x806FE0AC: sw          $t1, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r9;
    // 0x806FE0B0: lw          $t3, 0xC($a2)
    ctx->r11 = MEM_W(ctx->r6, 0XC);
    // 0x806FE0B4: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x806FE0B8: bnel        $at, $zero, L_806FE1C4
    if (ctx->r1 != 0) {
        // 0x806FE0BC: lw          $v0, 0x1F4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X1F4);
            goto L_806FE1C4;
    }
    goto skip_2;
    // 0x806FE0BC: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    skip_2:
    // 0x806FE0C0: sw          $zero, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = 0;
    // 0x806FE0C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x806FE0C8: jal         0x806FD534
    // 0x806FE0CC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_806FD534(rdram, ctx);
        goto after_1;
    // 0x806FE0CC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_1:
    // 0x806FE0D0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x806FE0D4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806FE0D8: beq         $v0, $zero, L_806FE1B8
    if (ctx->r2 == 0) {
        // 0x806FE0DC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_806FE1B8;
    }
    // 0x806FE0DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806FE0E0: lhu         $v0, 0x10($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X10);
    // 0x806FE0E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806FE0E8: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x806FE0EC: beq         $t5, $zero, L_806FE104
    if (ctx->r13 == 0) {
        // 0x806FE0F0: ori         $t7, $v0, 0x4
        ctx->r15 = ctx->r2 | 0X4;
            goto L_806FE104;
    }
    // 0x806FE0F0: ori         $t7, $v0, 0x4
    ctx->r15 = ctx->r2 | 0X4;
    // 0x806FE0F4: andi        $t6, $v0, 0xFFFB
    ctx->r14 = ctx->r2 & 0XFFFB;
    // 0x806FE0F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x806FE0FC: b           L_806FE108
    // 0x806FE100: sh          $t6, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r14;
        goto L_806FE108;
    // 0x806FE100: sh          $t6, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r14;
L_806FE104:
    // 0x806FE104: sh          $t7, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r15;
L_806FE108:
    // 0x806FE108: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x806FE10C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x806FE110: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x806FE114: jal         0x800653D8
    // 0x806FE118: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x806FE118: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x806FE11C: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x806FE120: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x806FE124: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806FE128: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806FE12C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806FE130: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x806FE134: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806FE138: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806FE13C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x806FE140: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x806FE144: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806FE148: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x806FE14C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x806FE150: lwc1        $f6, 0x44($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X44);
    // 0x806FE154: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x806FE158: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x806FE15C: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x806FE160: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806FE164: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x806FE168: beq         $a0, $zero, L_806FE194
    if (ctx->r4 == 0) {
        // 0x806FE16C: swc1        $f0, 0x40($v1)
        MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
            goto L_806FE194;
    }
    // 0x806FE16C: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x806FE170: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x806FE174: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806FE178: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x806FE17C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x806FE180: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806FE184: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806FE188: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806FE18C: b           L_806FE1B0
    // 0x806FE190: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
        goto L_806FE1B0;
    // 0x806FE190: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
L_806FE194:
    // 0x806FE194: lwc1        $f6, 0x3C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x806FE198: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806FE19C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x806FE1A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806FE1A4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806FE1A8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806FE1AC: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
L_806FE1B0:
    // 0x806FE1B0: b           L_806FE1C0
    // 0x806FE1B4: sw          $t9, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r25;
        goto L_806FE1C0;
    // 0x806FE1B4: sw          $t9, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r25;
L_806FE1B8:
    // 0x806FE1B8: addiu       $t0, $zero, 0x168
    ctx->r8 = ADD32(0, 0X168);
    // 0x806FE1BC: sw          $t0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r8;
L_806FE1C0:
    // 0x806FE1C0: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
L_806FE1C4:
    // 0x806FE1C4: lhu         $a0, 0x10($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X10);
    // 0x806FE1C8: andi        $t2, $a0, 0x1
    ctx->r10 = ctx->r4 & 0X1;
    // 0x806FE1CC: beql        $t2, $zero, L_806FE21C
    if (ctx->r10 == 0) {
        // 0x806FE1D0: andi        $t9, $a0, 0x2
        ctx->r25 = ctx->r4 & 0X2;
            goto L_806FE21C;
    }
    goto skip_3;
    // 0x806FE1D0: andi        $t9, $a0, 0x2
    ctx->r25 = ctx->r4 & 0X2;
    skip_3:
    // 0x806FE1D4: lw          $v1, 0x1E4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1E4);
    // 0x806FE1D8: andi        $t4, $a0, 0xFFFE
    ctx->r12 = ctx->r4 & 0XFFFE;
    // 0x806FE1DC: blez        $v1, L_806FE1F4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x806FE1E0: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_806FE1F4;
    }
    // 0x806FE1E0: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x806FE1E4: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x806FE1E8: sw          $t3, 0x1E4($a1)
    MEM_W(0X1E4, ctx->r5) = ctx->r11;
    // 0x806FE1EC: b           L_806FE218
    // 0x806FE1F0: lhu         $a0, 0x10($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X10);
        goto L_806FE218;
    // 0x806FE1F0: lhu         $a0, 0x10($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X10);
L_806FE1F4:
    // 0x806FE1F4: sh          $t4, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r12;
    // 0x806FE1F8: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x806FE1FC: addiu       $t7, $zero, 0x168
    ctx->r15 = ADD32(0, 0X168);
    // 0x806FE200: lhu         $t5, 0x10($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X10);
    // 0x806FE204: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x806FE208: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
    // 0x806FE20C: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x806FE210: sw          $t7, 0x1E4($a1)
    MEM_W(0X1E4, ctx->r5) = ctx->r15;
    // 0x806FE214: lhu         $a0, 0x10($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X10);
L_806FE218:
    // 0x806FE218: andi        $t9, $a0, 0x2
    ctx->r25 = ctx->r4 & 0X2;
L_806FE21C:
    // 0x806FE21C: beql        $t9, $zero, L_806FE244
    if (ctx->r25 == 0) {
        // 0x806FE220: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806FE244;
    }
    goto skip_4;
    // 0x806FE220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x806FE224: lw          $v1, 0x1E4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1E4);
    // 0x806FE228: andi        $t1, $a0, 0xFFFD
    ctx->r9 = ctx->r4 & 0XFFFD;
    // 0x806FE22C: blez        $v1, L_806FE23C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x806FE230: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_806FE23C;
    }
    // 0x806FE230: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x806FE234: b           L_806FE240
    // 0x806FE238: sw          $t0, 0x1E4($a1)
    MEM_W(0X1E4, ctx->r5) = ctx->r8;
        goto L_806FE240;
    // 0x806FE238: sw          $t0, 0x1E4($a1)
    MEM_W(0X1E4, ctx->r5) = ctx->r8;
L_806FE23C:
    // 0x806FE23C: sh          $t1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r9;
L_806FE240:
    // 0x806FE240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806FE244:
    // 0x806FE244: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806FE248: jr          $ra
    // 0x806FE24C: nop

    return;
    // 0x806FE24C: nop

;}
RECOMP_FUNC void func_804CCCB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CCCB4: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x804CCCB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804CCCBC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x804CCCC0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x804CCCC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804CCCC8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804CCCCC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CCCD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CCCD4: lw          $s3, 0xC($s1)
    ctx->r19 = MEM_W(ctx->r17, 0XC);
    // 0x804CCCD8: jal         0x8004921C
    // 0x804CCCDC: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804CCCDC: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    after_0:
    // 0x804CCCE0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x804CCCE4: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x804CCCE8: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x804CCCEC: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x804CCCF0: or          $t4, $a2, $zero
    ctx->r12 = ctx->r6 | 0;
    // 0x804CCCF4: lwc1        $f4, 0x10($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X10);
    // 0x804CCCF8: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804CCCFC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x804CCD00: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x804CCD04: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804CCD08: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x804CCD0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804CCD10: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x804CCD14: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804CCD18: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x804CCD1C: sll         $s0, $v0, 6
    ctx->r16 = S32(ctx->r2 << 6);
    // 0x804CCD20: addiu       $t6, $zero, 0x7C0
    ctx->r14 = ADD32(0, 0X7C0);
    // 0x804CCD24: sb          $t0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r8;
    // 0x804CCD28: sb          $zero, 0xF($v1)
    MEM_B(0XF, ctx->r3) = 0;
    // 0x804CCD2C: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x804CCD30: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    // 0x804CCD34: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x804CCD38: sub.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x804CCD3C: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x804CCD40: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x804CCD44: sub.s       $f14, $f0, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x804CCD48: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x804CCD4C: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x804CCD50: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804CCD54: sh          $s0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r16;
    // 0x804CCD58: sb          $t0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r8;
    // 0x804CCD5C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804CCD60: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x804CCD64: sb          $zero, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = 0;
    // 0x804CCD68: add.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x804CCD6C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x804CCD70: sb          $zero, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = 0;
    // 0x804CCD74: add.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x804CCD78: sb          $zero, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = 0;
    // 0x804CCD7C: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x804CCD80: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x804CCD84: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x804CCD88: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x804CCD8C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804CCD90: sh          $t6, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r14;
    // 0x804CCD94: sh          $s0, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r16;
    // 0x804CCD98: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804CCD9C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x804CCDA0: sb          $t0, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r8;
    // 0x804CCDA4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804CCDA8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x804CCDAC: sb          $zero, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = 0;
    // 0x804CCDB0: sub.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x804CCDB4: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x804CCDB8: sb          $zero, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = 0;
    // 0x804CCDBC: sb          $zero, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = 0;
    // 0x804CCDC0: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x804CCDC4: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x804CCDC8: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x804CCDCC: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    // 0x804CCDD0: sh          $a1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r5;
    // 0x804CCDD4: sh          $t7, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r15;
    // 0x804CCDD8: sh          $a3, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r7;
    // 0x804CCDDC: sh          $t3, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r11;
    // 0x804CCDE0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x804CCDE4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804CCDE8: addiu       $t8, $zero, 0x7C0
    ctx->r24 = ADD32(0, 0X7C0);
    // 0x804CCDEC: sltiu       $at, $s3, 0x2
    ctx->r1 = ctx->r19 < 0X2 ? 1 : 0;
    // 0x804CCDF0: sh          $t8, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r24;
    // 0x804CCDF4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x804CCDF8: sb          $zero, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = 0;
    // 0x804CCDFC: sb          $t0, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = ctx->r8;
    // 0x804CCE00: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x804CCE04: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x804CCE08: sll         $s1, $a3, 16
    ctx->r17 = S32(ctx->r7 << 16);
    // 0x804CCE0C: sh          $a3, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r7;
    // 0x804CCE10: sb          $zero, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = 0;
    // 0x804CCE14: sb          $zero, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = 0;
    // 0x804CCE18: sh          $zero, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = 0;
    // 0x804CCE1C: sh          $zero, 0x36($v1)
    MEM_H(0X36, ctx->r3) = 0;
    // 0x804CCE20: sh          $zero, 0x34($v1)
    MEM_H(0X34, ctx->r3) = 0;
    // 0x804CCE24: sh          $t3, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r11;
    // 0x804CCE28: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x804CCE2C: addiu       $ra, $zero, 0x1F
    ctx->r31 = ADD32(0, 0X1F);
    // 0x804CCE30: addiu       $t4, $t4, 0x18
    ctx->r12 = ADD32(ctx->r12, 0X18);
    // 0x804CCE34: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804CCE38: lh          $s2, 0x2E($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X2E);
    // 0x804CCE3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x804CCE40: addiu       $t2, $a2, 0xC
    ctx->r10 = ADD32(ctx->r6, 0XC);
    // 0x804CCE44: bne         $at, $zero, L_804CCF94
    if (ctx->r1 != 0) {
        // 0x804CCE48: addiu       $v1, $v1, 0x40
        ctx->r3 = ADD32(ctx->r3, 0X40);
            goto L_804CCF94;
    }
    // 0x804CCE48: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
L_804CCE4C:
    // 0x804CCE4C: lwc1        $f2, 0x0($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X0);
    // 0x804CCE50: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x804CCE54: lwc1        $f0, 0x4($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X4);
    // 0x804CCE58: sub.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x804CCE5C: sll         $a2, $t5, 6
    ctx->r6 = S32(ctx->r13 << 6);
    // 0x804CCE60: sh          $a2, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r6;
    // 0x804CCE64: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x804CCE68: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804CCE6C: sh          $a2, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r6;
    // 0x804CCE70: sh          $s1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r17;
    // 0x804CCE74: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x804CCE78: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x804CCE7C: sh          $s2, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r18;
    // 0x804CCE80: add.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x804CCE84: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x804CCE88: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    // 0x804CCE8C: sh          $a1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r5;
    // 0x804CCE90: sll         $a1, $ra, 6
    ctx->r5 = S32(ctx->r31 << 6);
    // 0x804CCE94: addiu       $t5, $t5, 0x20
    ctx->r13 = ADD32(ctx->r13, 0X20);
    // 0x804CCE98: addiu       $ra, $ra, 0x20
    ctx->r31 = ADD32(ctx->r31, 0X20);
    // 0x804CCE9C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804CCEA0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x804CCEA4: sll         $t5, $t5, 16
    ctx->r13 = S32(ctx->r13 << 16);
    // 0x804CCEA8: sub.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x804CCEAC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x804CCEB0: sll         $ra, $ra, 16
    ctx->r31 = S32(ctx->r31 << 16);
    // 0x804CCEB4: sb          $zero, 0xF($v1)
    MEM_B(0XF, ctx->r3) = 0;
    // 0x804CCEB8: add.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x804CCEBC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x804CCEC0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x804CCEC4: sub.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x804CCEC8: sb          $t0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r8;
    // 0x804CCECC: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    // 0x804CCED0: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804CCED4: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x804CCED8: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x804CCEDC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804CCEE0: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x804CCEE4: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x804CCEE8: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x804CCEEC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x804CCEF0: sll         $t3, $t3, 16
    ctx->r11 = S32(ctx->r11 << 16);
    // 0x804CCEF4: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x804CCEF8: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x804CCEFC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x804CCF00: sll         $s1, $a3, 16
    ctx->r17 = S32(ctx->r7 << 16);
    // 0x804CCF04: sll         $s2, $t3, 16
    ctx->r18 = S32(ctx->r11 << 16);
    // 0x804CCF08: sb          $zero, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = 0;
    // 0x804CCF0C: sb          $t0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r8;
    // 0x804CCF10: sb          $zero, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = 0;
    // 0x804CCF14: sb          $zero, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = 0;
    // 0x804CCF18: sh          $s0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r16;
    // 0x804CCF1C: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x804CCF20: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x804CCF24: sh          $t3, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r11;
    // 0x804CCF28: sh          $a2, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r6;
    // 0x804CCF2C: sh          $a1, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r5;
    // 0x804CCF30: sb          $zero, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = 0;
    // 0x804CCF34: sb          $t0, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r8;
    // 0x804CCF38: sb          $zero, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = 0;
    // 0x804CCF3C: sb          $zero, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = 0;
    // 0x804CCF40: sh          $s0, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r16;
    // 0x804CCF44: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x804CCF48: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x804CCF4C: sh          $a3, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r7;
    // 0x804CCF50: sh          $a2, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r6;
    // 0x804CCF54: sh          $a1, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r5;
    // 0x804CCF58: sb          $zero, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = 0;
    // 0x804CCF5C: sb          $t0, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = ctx->r8;
    // 0x804CCF60: sb          $zero, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = 0;
    // 0x804CCF64: sb          $zero, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = 0;
    // 0x804CCF68: sh          $zero, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = 0;
    // 0x804CCF6C: sh          $zero, 0x36($v1)
    MEM_H(0X36, ctx->r3) = 0;
    // 0x804CCF70: sh          $zero, 0x34($v1)
    MEM_H(0X34, ctx->r3) = 0;
    // 0x804CCF74: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x804CCF78: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x804CCF7C: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x804CCF80: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804CCF84: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x804CCF88: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x804CCF8C: bne         $t1, $s3, L_804CCE4C
    if (ctx->r9 != ctx->r19) {
        // 0x804CCF90: sra         $ra, $ra, 16
        ctx->r31 = S32(SIGNED(ctx->r31) >> 16);
            goto L_804CCE4C;
    }
    // 0x804CCF90: sra         $ra, $ra, 16
    ctx->r31 = S32(SIGNED(ctx->r31) >> 16);
L_804CCF94:
    // 0x804CCF94: lwc1        $f2, 0x0($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X0);
    // 0x804CCF98: lwc1        $f0, 0x4($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X4);
    // 0x804CCF9C: sll         $a2, $t5, 6
    ctx->r6 = S32(ctx->r13 << 6);
    // 0x804CCFA0: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x804CCFA4: sh          $a2, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r6;
    // 0x804CCFA8: sh          $a2, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r6;
    // 0x804CCFAC: add.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x804CCFB0: sb          $zero, 0xF($v1)
    MEM_B(0XF, ctx->r3) = 0;
    // 0x804CCFB4: sb          $t0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r8;
    // 0x804CCFB8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804CCFBC: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    // 0x804CCFC0: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x804CCFC4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x804CCFC8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x804CCFCC: add.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x804CCFD0: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x804CCFD4: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    // 0x804CCFD8: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x804CCFDC: sh          $a1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r5;
    // 0x804CCFE0: sll         $a1, $ra, 6
    ctx->r5 = S32(ctx->r31 << 6);
    // 0x804CCFE4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804CCFE8: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x804CCFEC: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x804CCFF0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804CCFF4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x804CCFF8: sh          $s1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r17;
    // 0x804CCFFC: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804CD000: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x804CD004: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x804CD008: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x804CD00C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x804CD010: sb          $zero, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = 0;
    // 0x804CD014: sb          $t0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r8;
    // 0x804CD018: sb          $zero, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = 0;
    // 0x804CD01C: sb          $zero, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = 0;
    // 0x804CD020: sh          $s0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r16;
    // 0x804CD024: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x804CD028: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x804CD02C: sh          $s2, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r18;
    // 0x804CD030: sh          $a2, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r6;
    // 0x804CD034: sh          $a1, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r5;
    // 0x804CD038: sb          $zero, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = 0;
    // 0x804CD03C: sb          $t0, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r8;
    // 0x804CD040: sb          $zero, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = 0;
    // 0x804CD044: sb          $zero, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = 0;
    // 0x804CD048: sh          $s0, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r16;
    // 0x804CD04C: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x804CD050: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x804CD054: sh          $a2, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r6;
    // 0x804CD058: sh          $a1, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r5;
    // 0x804CD05C: sb          $zero, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = 0;
    // 0x804CD060: sb          $t0, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = ctx->r8;
    // 0x804CD064: sb          $zero, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = 0;
    // 0x804CD068: sb          $zero, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = 0;
    // 0x804CD06C: sh          $zero, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = 0;
    // 0x804CD070: sh          $zero, 0x36($v1)
    MEM_H(0X36, ctx->r3) = 0;
    // 0x804CD074: sh          $zero, 0x34($v1)
    MEM_H(0X34, ctx->r3) = 0;
    // 0x804CD078: sh          $t8, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r24;
    // 0x804CD07C: sh          $t6, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r14;
    // 0x804CD080: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804CD084: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x804CD088: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x804CD08C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804CD090: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804CD094: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x804CD098: jr          $ra
    // 0x804CD09C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x804CD09C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_8043F0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F0F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043F0F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F0FC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8043F100: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8043F104: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8043F108: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(95, 0X3D48) << 16);
    // 0x8043F10C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043F110: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8043F114: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8043F118: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8043F11C: lw          $t8, 0x2C48($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(95, 0X3D48));
    // 0x8043F120: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8043F124: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8043F128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8043F12C: jal         0x80048490
    // 0x8043F130: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8043F130: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8043F134: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8043F138: jal         0x80048378
    // 0x8043F13C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8043F13C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8043F140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043F144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043F148: jr          $ra
    // 0x8043F14C: nop

    return;
    // 0x8043F14C: nop

;}
RECOMP_FUNC void func_804C5C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5C54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5C58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C5C5C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804C5C60: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804C5C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C5C68: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804C5C6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804C5C70: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804C5C74: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804C5C78: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804C5C7C: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(215, 0X45C) << 16);
    // 0x804C5C80: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C5C84: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804C5C88: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804C5C8C: lw          $t2, 0x5E6C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(215, 0X45C));
    // 0x804C5C90: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804C5C94: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804C5C98: jal         0x804C5CB8
    // 0x804C5C9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C5CB8(rdram, ctx);
        goto after_0;
    // 0x804C5C9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C5CA0: jal         0x804C5D04
    // 0x804C5CA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804C5D04(rdram, ctx);
        goto after_1;
    // 0x804C5CA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804C5CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C5CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5CB0: jr          $ra
    // 0x804C5CB4: nop

    return;
    // 0x804C5CB4: nop

;}
RECOMP_FUNC void func_806D0B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0B0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D0B10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D0B14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806D0B18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806D0B1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806D0B20: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806D0B24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x806D0B28: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806D0B2C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806D0B30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D0B34: beq         $v0, $at, L_806D0B50
    if (ctx->r2 == ctx->r1) {
        // 0x806D0B38: lw          $s1, 0x180($a0)
        ctx->r17 = MEM_W(ctx->r4, 0X180);
            goto L_806D0B50;
    }
    // 0x806D0B38: lw          $s1, 0x180($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X180);
    // 0x806D0B3C: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806D0B40: beql        $v0, $at, L_806D0C28
    if (ctx->r2 == ctx->r1) {
        // 0x806D0B44: lbu         $t3, 0x30($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X30);
            goto L_806D0C28;
    }
    goto skip_0;
    // 0x806D0B44: lbu         $t3, 0x30($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X30);
    skip_0:
    // 0x806D0B48: b           L_806D0CF0
    // 0x806D0B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D0CF0;
    // 0x806D0B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D0B50:
    // 0x806D0B50: lbu         $t7, 0x30($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X30);
    // 0x806D0B54: bnel        $t7, $zero, L_806D0CF0
    if (ctx->r15 != 0) {
        // 0x806D0B58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D0CF0;
    }
    goto skip_1;
    // 0x806D0B58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806D0B5C: jal         0x8002F92C
    // 0x806D0B60: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8002F92C(rdram, ctx);
        goto after_0;
    // 0x806D0B60: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x806D0B64: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x806D0B68: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x806D0B6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806D0B70: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806D0B74: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x806D0B78: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806D0B7C: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806D0B80: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x806D0B84: sb          $t9, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r25;
    // 0x806D0B88: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x806D0B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0B90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0B94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806D0B98: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x806D0B9C: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806D0BA0: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x806D0BA4: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x806D0BA8: jal         0x806D0EC8
    // 0x806D0BAC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    func_806D0EC8(rdram, ctx);
        goto after_1;
    // 0x806D0BAC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x806D0BB0: beql        $s1, $zero, L_806D0BF4
    if (ctx->r17 == 0) {
        // 0x806D0BB4: lw          $t0, 0x174($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X174);
            goto L_806D0BF4;
    }
    goto skip_2;
    // 0x806D0BB4: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    skip_2:
    // 0x806D0BB8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806D0BBC: lwc1        $f18, 0xC4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x806D0BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806D0BC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D0BC8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x806D0BCC: nop

    // 0x806D0BD0: bc1f        L_806D0BE8
    if (!c1cs) {
        // 0x806D0BD4: nop
    
            goto L_806D0BE8;
    }
    // 0x806D0BD4: nop

    // 0x806D0BD8: jal         0x806CFDA8
    // 0x806D0BDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806CFDA8(rdram, ctx);
        goto after_2;
    // 0x806D0BDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x806D0BE0: b           L_806D0BF4
    // 0x806D0BE4: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
        goto L_806D0BF4;
    // 0x806D0BE4: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
L_806D0BE8:
    // 0x806D0BE8: jal         0x806CFDA8
    // 0x806D0BEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806CFDA8(rdram, ctx);
        goto after_3;
    // 0x806D0BEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x806D0BF0: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
L_806D0BF4:
    // 0x806D0BF4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x806D0BF8: lhu         $t1, 0x16($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X16);
    // 0x806D0BFC: andi        $t2, $t1, 0xF0FF
    ctx->r10 = ctx->r9 & 0XF0FF;
    // 0x806D0C00: sh          $t2, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r10;
    // 0x806D0C04: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806D0C08: jal         0x80067BBC
    // 0x806D0C0C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x806D0C0C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_4:
    // 0x806D0C10: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x806D0C14: jal         0x80067818
    // 0x806D0C18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806D0C18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x806D0C1C: b           L_806D0CF0
    // 0x806D0C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D0CF0;
    // 0x806D0C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D0C24: lbu         $t3, 0x30($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X30);
L_806D0C28:
    // 0x806D0C28: bnel        $t3, $zero, L_806D0CF0
    if (ctx->r11 != 0) {
        // 0x806D0C2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D0CF0;
    }
    goto skip_3;
    // 0x806D0C2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806D0C30: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x806D0C34: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
    // 0x806D0C38: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x806D0C3C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1B1C) << 16);
    // 0x806D0C40: swc1        $f4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f4.u32l;
    // 0x806D0C44: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806D0C48: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806D0C4C: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x806D0C50: sb          $t5, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r13;
    // 0x806D0C54: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x806D0C58: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x806D0C5C: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x806D0C60: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x806D0C64: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x806D0C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0C6C: lwc1        $f16, 0xC4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XC4);
    // 0x806D0C70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0C74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806D0C78: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
    // 0x806D0C7C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806D0C80: lwc1        $f4, 0x12BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1B1C));
    // 0x806D0C84: lwc1        $f18, 0xC8($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC8);
    // 0x806D0C88: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806D0C8C: jal         0x806D0EC8
    // 0x806D0C90: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    func_806D0EC8(rdram, ctx);
        goto after_6;
    // 0x806D0C90: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x806D0C94: beq         $s1, $zero, L_806D0CD4
    if (ctx->r17 == 0) {
        // 0x806D0C98: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_806D0CD4;
    }
    // 0x806D0C98: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806D0C9C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806D0CA0: lwc1        $f10, 0xC4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC4);
    // 0x806D0CA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806D0CA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D0CAC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806D0CB0: nop

    // 0x806D0CB4: bc1f        L_806D0CCC
    if (!c1cs) {
        // 0x806D0CB8: nop
    
            goto L_806D0CCC;
    }
    // 0x806D0CB8: nop

    // 0x806D0CBC: jal         0x806CFDF8
    // 0x806D0CC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806CFDF8(rdram, ctx);
        goto after_7;
    // 0x806D0CC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x806D0CC4: b           L_806D0CD8
    // 0x806D0CC8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
        goto L_806D0CD8;
    // 0x806D0CC8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_806D0CCC:
    // 0x806D0CCC: jal         0x806CFDF8
    // 0x806D0CD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806CFDF8(rdram, ctx);
        goto after_8;
    // 0x806D0CD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_806D0CD4:
    // 0x806D0CD4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_806D0CD8:
    // 0x806D0CD8: jal         0x80067BBC
    // 0x806D0CDC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_9;
    // 0x806D0CDC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_9:
    // 0x806D0CE0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x806D0CE4: jal         0x80067818
    // 0x806D0CE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x806D0CE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x806D0CEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D0CF0:
    // 0x806D0CF0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806D0CF4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806D0CF8: jr          $ra
    // 0x806D0CFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806D0CFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006A5C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A5C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A5C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A5C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006A5CC: bne         $a1, $zero, L_8006A5DC
    if (ctx->r5 != 0) {
        // 0x8006A5D0: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8006A5DC;
    }
    // 0x8006A5D0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8006A5D4: b           L_8006A63C
    // 0x8006A5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006A63C;
    // 0x8006A5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A5DC:
    // 0x8006A5DC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006A5E0: addiu       $a1, $zero, 0x250
    ctx->r5 = ADD32(0, 0X250);
    // 0x8006A5E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8006A5E8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8006A5EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006A5F0: beq         $t7, $zero, L_8006A60C
    if (ctx->r15 == 0) {
        // 0x8006A5F4: nop
    
            goto L_8006A60C;
    }
    // 0x8006A5F4: nop

    // 0x8006A5F8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A5FC: jal         0x80071380
    // 0x8006A600: addiu       $a0, $a0, 0xFF0
    ctx->r4 = ADD32(ctx->r4, 0XFF0);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8006A600: addiu       $a0, $a0, 0xFF0
    ctx->r4 = ADD32(ctx->r4, 0XFF0);
    after_0:
    // 0x8006A604: b           L_8006A63C
    // 0x8006A608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A63C;
    // 0x8006A608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A60C:
    // 0x8006A60C: jal         0x80069FE4
    // 0x8006A610: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    func_80069FE4(rdram, ctx);
        goto after_1;
    // 0x8006A610: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    after_1:
    // 0x8006A614: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006A618: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A61C: bne         $v0, $zero, L_8006A638
    if (ctx->r2 != 0) {
        // 0x8006A620: sw          $v0, 0x2C($t8)
        MEM_W(0X2C, ctx->r24) = ctx->r2;
            goto L_8006A638;
    }
    // 0x8006A620: sw          $v0, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r2;
    // 0x8006A624: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x8006A628: jal         0x80071380
    // 0x8006A62C: addiu       $a1, $zero, 0x25B
    ctx->r5 = ADD32(0, 0X25B);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8006A62C: addiu       $a1, $zero, 0x25B
    ctx->r5 = ADD32(0, 0X25B);
    after_2:
    // 0x8006A630: b           L_8006A63C
    // 0x8006A634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A63C;
    // 0x8006A634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A638:
    // 0x8006A638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A63C:
    // 0x8006A63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A644: jr          $ra
    // 0x8006A648: nop

    return;
    // 0x8006A648: nop

;}
