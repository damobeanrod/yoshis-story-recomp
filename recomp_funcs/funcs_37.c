#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804BF3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BF3E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804BF3E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BF3E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804BF3EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804BF3F0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x804BF3F4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BF3F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x804BF3FC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x804BF400: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804BF404: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x804BF408: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804BF40C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x804BF410: lwc1        $f8, 0x74($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X74);
    // 0x804BF414: addiu       $a0, $zero, 0x412B
    ctx->r4 = ADD32(0, 0X412B);
    // 0x804BF418: jal         0x80047090
    // 0x804BF41C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804BF41C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x804BF420: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804BF424: beq         $v0, $at, L_804BF54C
    if (ctx->r2 == ctx->r1) {
        // 0x804BF428: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804BF54C;
    }
    // 0x804BF428: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804BF42C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x804BF430: lui         $at, 0x412B
    ctx->r1 = S32(0X412B << 16);
    // 0x804BF434: ori         $at, $at, 0x2400
    ctx->r1 = ctx->r1 | 0X2400;
    // 0x804BF438: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804BF43C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X3C80) << 16);
    // 0x804BF440: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x804BF444: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804BF448: lwc1        $f10, -0xA50($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X3C80));
    // 0x804BF44C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804BF450: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X3C8C) << 16);
    // 0x804BF454: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804BF458: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804BF45C: lwc1        $f4, -0xA44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X3C8C));
    // 0x804BF460: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804BF464: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4220) << 16);
    // 0x804BF468: lwc1        $f10, -0x4B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4220));
    // 0x804BF46C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804BF470: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804BF474: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x804BF478: sh          $v1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r3;
    // 0x804BF47C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804BF480: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x804BF484: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x804BF488: jal         0x8004613C
    // 0x804BF48C: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804BF48C: nop

    after_1:
    // 0x804BF490: lhu         $v1, 0x3A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X3A);
    // 0x804BF494: beq         $v0, $zero, L_804BF544
    if (ctx->r2 == 0) {
        // 0x804BF498: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_804BF544;
    }
    // 0x804BF498: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x804BF49C: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x804BF4A0: andi        $t8, $v1, 0x3FF
    ctx->r24 = ctx->r3 & 0X3FF;
    // 0x804BF4A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804BF4A8: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x804BF4AC: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x804BF4B0: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x804BF4B4: lw          $t2, 0x138($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X138);
    // 0x804BF4B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804BF4BC: jal         0x80047F9C
    // 0x804BF4C0: sw          $t2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r10;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804BF4C0: sw          $t2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r10;
    after_2:
    // 0x804BF4C4: jal         0x804BBA18
    // 0x804BF4C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BBA18(rdram, ctx);
        goto after_3;
    // 0x804BF4C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804BF4CC: bne         $v0, $zero, L_804BF4DC
    if (ctx->r2 != 0) {
        // 0x804BF4D0: nop
    
            goto L_804BF4DC;
    }
    // 0x804BF4D0: nop

    // 0x804BF4D4: b           L_804BF554
    // 0x804BF4D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BF554;
    // 0x804BF4D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BF4DC:
    // 0x804BF4DC: jal         0x8005FDC4
    // 0x804BF4E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x804BF4E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804BF4E4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4224) << 16);
    // 0x804BF4E8: lwc1        $f0, -0x4AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4224));
    // 0x804BF4EC: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804BF4F0: lui         $t5, 0x804C
    ctx->r13 = S32(RELOC_HI16(191, 0X3CA4) << 16);
    // 0x804BF4F4: addiu       $t5, $t5, -0xA2C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(191, 0X3CA4));
    // 0x804BF4F8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804BF4FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804BF500: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x804BF504: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804BF508: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x804BF50C: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x804BF510: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804BF514: swc1        $f16, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f16.u32l;
    // 0x804BF518: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x804BF51C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x804BF520: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x804BF524: jal         0x804BF004
    // 0x804BF528: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    func_804BF004(rdram, ctx);
        goto after_5;
    // 0x804BF528: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    after_5:
    // 0x804BF52C: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X3D04) << 16);
    // 0x804BF530: lh          $t6, -0x9CC($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(191, 0X3D04));
    // 0x804BF534: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x804BF538: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804BF53C: b           L_804BF554
    // 0x804BF540: sh          $t6, 0x32($t7)
    MEM_H(0X32, ctx->r15) = ctx->r14;
        goto L_804BF554;
    // 0x804BF540: sh          $t6, 0x32($t7)
    MEM_H(0X32, ctx->r15) = ctx->r14;
L_804BF544:
    // 0x804BF544: b           L_804BF554
    // 0x804BF548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BF554;
    // 0x804BF548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BF54C:
    // 0x804BF54C: b           L_804BF554
    // 0x804BF550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BF554;
    // 0x804BF550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BF554:
    // 0x804BF554: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804BF558: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804BF55C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804BF560: jr          $ra
    // 0x804BF564: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x804BF564: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80034CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034CC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80034CCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80034CD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80034CD4: jal         0x80021958
    // 0x80034CD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80034CD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80034CDC: beql        $v0, $zero, L_80034D38
    if (ctx->r2 == 0) {
        // 0x80034CE0: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_80034D38;
    }
    goto skip_0;
    // 0x80034CE0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    skip_0:
    // 0x80034CE4: jal         0x80041698
    // 0x80034CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041698(rdram, ctx);
        goto after_1;
    // 0x80034CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80034CEC: bnel        $v0, $zero, L_80034D38
    if (ctx->r2 != 0) {
        // 0x80034CF0: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_80034D38;
    }
    goto skip_1;
    // 0x80034CF0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    skip_1:
    // 0x80034CF4: jal         0x8003444C
    // 0x80034CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003444C(rdram, ctx);
        goto after_2;
    // 0x80034CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80034CFC: beql        $v0, $zero, L_80034D38
    if (ctx->r2 == 0) {
        // 0x80034D00: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_80034D38;
    }
    goto skip_2;
    // 0x80034D00: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    skip_2:
    // 0x80034D04: jal         0x8001D770
    // 0x80034D08: nop

    func_8001D770(rdram, ctx);
        goto after_3;
    // 0x80034D08: nop

    after_3:
    // 0x80034D0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80034D10: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80034D14: jal         0x80067BF8
    // 0x80034D18: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_4;
    // 0x80034D18: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x80034D1C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80034D20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80034D24: jal         0x800678F0
    // 0x80034D28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_5;
    // 0x80034D28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80034D2C: b           L_80034D44
    // 0x80034D30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80034D44;
    // 0x80034D30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80034D34: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_80034D38:
    // 0x80034D38: jal         0x80067878
    // 0x80034D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_6;
    // 0x80034D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80034D40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034D44:
    // 0x80034D44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80034D48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80034D4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80034D50: jr          $ra
    // 0x80034D54: nop

    return;
    // 0x80034D54: nop

;}
RECOMP_FUNC void func_8000CFF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CFF0: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000CFF4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000CFF8: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8000CFFC: sltiu       $at, $v0, 0x9
    ctx->r1 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x8000D000: beq         $at, $zero, L_8000D28C
    if (ctx->r1 == 0) {
        // 0x8000D004: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000D28C;
    }
    // 0x8000D004: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000D008: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8000D00C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000D010: addu        $at, $at, $t6
    gpr jr_addend_8000D018 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000D014: lw          $t6, -0x42C0($at)
    ctx->r14 = ADD32(ctx->r1, -0X42C0);
    // 0x8000D018: jr          $t6
    // 0x8000D01C: nop

    switch (jr_addend_8000D018 >> 2) {
        case 0: goto L_8000D020; break;
        case 1: goto L_8000D02C; break;
        case 2: goto L_8000D04C; break;
        case 3: goto L_8000D05C; break;
        case 4: goto L_8000D19C; break;
        case 5: goto L_8000D28C; break;
        case 6: goto L_8000D1D4; break;
        case 7: goto L_8000D1D4; break;
        case 8: goto L_8000D264; break;
        default: switch_error(__func__, 0x8000D018, 0x800ABD40);
    }
    // 0x8000D01C: nop

L_8000D020:
    // 0x8000D020: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000D024: jr          $ra
    // 0x8000D028: nop

    return;
    // 0x8000D028: nop

L_8000D02C:
    // 0x8000D02C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000D030: andi        $t0, $v1, 0xFFF0
    ctx->r8 = ctx->r3 & 0XFFF0;
    // 0x8000D034: ori         $t1, $t0, 0x5
    ctx->r9 = ctx->r8 | 0X5;
    // 0x8000D038: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8000D03C: bgezl       $t9, L_8000D050
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000D040: andi        $t2, $v1, 0xFFF0
        ctx->r10 = ctx->r3 & 0XFFF0;
            goto L_8000D050;
    }
    goto skip_0;
    // 0x8000D040: andi        $t2, $v1, 0xFFF0
    ctx->r10 = ctx->r3 & 0XFFF0;
    skip_0:
    // 0x8000D044: b           L_8000D28C
    // 0x8000D048: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
        goto L_8000D28C;
    // 0x8000D048: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
L_8000D04C:
    // 0x8000D04C: andi        $t2, $v1, 0xFFF0
    ctx->r10 = ctx->r3 & 0XFFF0;
L_8000D050:
    // 0x8000D050: ori         $t3, $t2, 0x3
    ctx->r11 = ctx->r10 | 0X3;
    // 0x8000D054: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x8000D058: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
L_8000D05C:
    // 0x8000D05C: lbu         $t5, 0x1($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X1);
    // 0x8000D060: lw          $t4, 0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1C);
    // 0x8000D064: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8000D068: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8000D06C: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x8000D070: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8000D074: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x8000D078: lh          $a1, 0x2($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X2);
    // 0x8000D07C: beq         $a1, $at, L_8000D0CC
    if (ctx->r5 == ctx->r1) {
        // 0x8000D080: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8000D0CC;
    }
    // 0x8000D080: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000D084: beq         $a1, $at, L_8000D0C0
    if (ctx->r5 == ctx->r1) {
        // 0x8000D088: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8000D0C0;
    }
    // 0x8000D088: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D08C: beql        $a1, $at, L_8000D0B0
    if (ctx->r5 == ctx->r1) {
        // 0x8000D090: lbu         $t0, 0x0($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X0);
            goto L_8000D0B0;
    }
    goto skip_1;
    // 0x8000D090: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8000D094: bnel        $a1, $zero, L_8000D0E4
    if (ctx->r5 != 0) {
        // 0x8000D098: mtc1        $a1, $f4
        ctx->f4.u32l = ctx->r5;
            goto L_8000D0E4;
    }
    goto skip_2;
    // 0x8000D098: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    skip_2:
    // 0x8000D09C: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D0A0: andi        $t9, $t8, 0xFFF0
    ctx->r25 = ctx->r24 & 0XFFF0;
    // 0x8000D0A4: b           L_8000D188
    // 0x8000D0A8: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
        goto L_8000D188;
    // 0x8000D0A8: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x8000D0AC: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
L_8000D0B0:
    // 0x8000D0B0: andi        $t1, $t0, 0xFFF0
    ctx->r9 = ctx->r8 & 0XFFF0;
    // 0x8000D0B4: ori         $t2, $t1, 0x5
    ctx->r10 = ctx->r9 | 0X5;
    // 0x8000D0B8: b           L_8000D188
    // 0x8000D0BC: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
        goto L_8000D188;
    // 0x8000D0BC: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
L_8000D0C0:
    // 0x8000D0C0: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x8000D0C4: b           L_8000D05C
    // 0x8000D0C8: sb          $t3, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r11;
        goto L_8000D05C;
    // 0x8000D0C8: sb          $t3, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r11;
L_8000D0CC:
    // 0x8000D0CC: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D0D0: andi        $t4, $t5, 0xFFF0
    ctx->r12 = ctx->r13 & 0XFFF0;
    // 0x8000D0D4: ori         $t6, $t4, 0x1
    ctx->r14 = ctx->r12 | 0X1;
    // 0x8000D0D8: b           L_8000D188
    // 0x8000D0DC: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
        goto L_8000D188;
    // 0x8000D0DC: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8000D0E0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
L_8000D0E4:
    // 0x8000D0E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000D0E8: lwc1        $f8, 0x6AB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6AB0);
    // 0x8000D0EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000D0F0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000D0F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000D0F8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8000D0FC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8000D100: nop

    // 0x8000D104: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    // 0x8000D108: lh          $a1, 0x2($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X2);
    // 0x8000D10C: bnel        $a1, $zero, L_8000D120
    if (ctx->r5 != 0) {
        // 0x8000D110: lbu         $v0, 0x1($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X1);
            goto L_8000D120;
    }
    goto skip_3;
    // 0x8000D110: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    skip_3:
    // 0x8000D114: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    // 0x8000D118: lh          $a1, 0x2($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X2);
    // 0x8000D11C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
L_8000D120:
    // 0x8000D120: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x8000D124: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000D128: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8000D12C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8000D130: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x8000D134: lwc1        $f6, -0x429C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X429C);
    // 0x8000D138: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D13C: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8000D140: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8000D144: andi        $t4, $t5, 0xFFF0
    ctx->r12 = ctx->r13 & 0XFFF0;
    // 0x8000D148: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D14C: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000D150: ori         $t6, $t4, 0x4
    ctx->r14 = ctx->r12 | 0X4;
    // 0x8000D154: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8000D158: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x8000D15C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000D160: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8000D164: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x8000D168: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8000D16C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000D170: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000D174: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x8000D178: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8000D17C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8000D180: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000D184: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
L_8000D188:
    // 0x8000D188: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D18C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D190: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8000D194: bnel        $t9, $at, L_8000D290
    if (ctx->r25 != ctx->r1) {
        // 0x8000D198: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8000D290;
    }
    goto skip_4;
    // 0x8000D198: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_4:
L_8000D19C:
    // 0x8000D19C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x8000D1A0: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000D1A4: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000D1A8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8000D1AC: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    // 0x8000D1B0: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000D1B4: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x8000D1B8: bgtz        $t2, L_8000D28C
    if (SIGNED(ctx->r10) > 0) {
        // 0x8000D1BC: swc1        $f6, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
            goto L_8000D28C;
    }
    // 0x8000D1BC: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x8000D1C0: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D1C4: andi        $t5, $t3, 0xFFF0
    ctx->r13 = ctx->r11 & 0XFFF0;
    // 0x8000D1C8: ori         $t4, $t5, 0x3
    ctx->r12 = ctx->r13 | 0X3;
    // 0x8000D1CC: b           L_8000D28C
    // 0x8000D1D0: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
        goto L_8000D28C;
    // 0x8000D1D0: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
L_8000D1D4:
    // 0x8000D1D4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000D1D8: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8000D1DC: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000D1E0: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000D1E4: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x8000D1E8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8000D1EC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8000D1F0: bc1t        L_8000D234
    if (c1cs) {
        // 0x8000D1F4: swc1        $f10, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
            goto L_8000D234;
    }
    // 0x8000D1F4: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x8000D1F8: bne         $a1, $at, L_8000D234
    if (ctx->r5 != ctx->r1) {
        // 0x8000D1FC: nop
    
            goto L_8000D234;
    }
    // 0x8000D1FC: nop

    // 0x8000D200: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000D204: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8000D208: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8000D20C: nop

    // 0x8000D210: bc1fl       L_8000D290
    if (!c1cs) {
        // 0x8000D214: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8000D290;
    }
    goto skip_5;
    // 0x8000D214: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_5:
    // 0x8000D218: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D21C: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8000D220: sh          $t6, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r14;
    // 0x8000D224: andi        $t8, $t7, 0xFFF0
    ctx->r24 = ctx->r15 & 0XFFF0;
    // 0x8000D228: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8000D22C: b           L_8000D28C
    // 0x8000D230: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
        goto L_8000D28C;
    // 0x8000D230: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
L_8000D234:
    // 0x8000D234: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000D238: lwc1        $f6, -0x4298($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4298);
    // 0x8000D23C: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000D240: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8000D244: nop

    // 0x8000D248: bc1fl       L_8000D290
    if (!c1cs) {
        // 0x8000D24C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8000D290;
    }
    goto skip_6;
    // 0x8000D24C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_6:
    // 0x8000D250: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D254: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
    // 0x8000D258: andi        $t1, $t0, 0xFFF0
    ctx->r9 = ctx->r8 & 0XFFF0;
    // 0x8000D25C: b           L_8000D28C
    // 0x8000D260: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
        goto L_8000D28C;
    // 0x8000D260: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
L_8000D264:
    // 0x8000D264: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x8000D268: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8000D26C: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    // 0x8000D270: lh          $t5, 0x2($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2);
    // 0x8000D274: bnel        $t5, $zero, L_8000D290
    if (ctx->r13 != 0) {
        // 0x8000D278: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8000D290;
    }
    goto skip_7;
    // 0x8000D278: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_7:
    // 0x8000D27C: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D280: andi        $t6, $t4, 0xFFF0
    ctx->r14 = ctx->r12 & 0XFFF0;
    // 0x8000D284: ori         $t7, $t6, 0x7
    ctx->r15 = ctx->r14 | 0X7;
    // 0x8000D288: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_8000D28C:
    // 0x8000D28C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_8000D290:
    // 0x8000D290: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000D294: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000D298: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8000D29C: bgezl       $t9, L_8000D2C4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000D2A0: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_8000D2C4;
    }
    goto skip_8;
    // 0x8000D2A0: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    skip_8:
    // 0x8000D2A4: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D2A8: andi        $t1, $t0, 0xFFF0
    ctx->r9 = ctx->r8 & 0XFFF0;
    // 0x8000D2AC: ori         $t3, $t1, 0x6
    ctx->r11 = ctx->r9 | 0X6;
    // 0x8000D2B0: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x8000D2B4: andi        $t5, $t3, 0xDF
    ctx->r13 = ctx->r11 & 0XDF;
    // 0x8000D2B8: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
    // 0x8000D2BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D2C0: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
L_8000D2C4:
    // 0x8000D2C4: bgezl       $t6, L_8000D2E8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000D2C8: lwc1        $f2, 0x10($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
            goto L_8000D2E8;
    }
    goto skip_9;
    // 0x8000D2C8: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    skip_9:
    // 0x8000D2CC: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D2D0: andi        $t8, $t7, 0xFFF0
    ctx->r24 = ctx->r15 & 0XFFF0;
    // 0x8000D2D4: ori         $t0, $t8, 0x7
    ctx->r8 = ctx->r24 | 0X7;
    // 0x8000D2D8: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x8000D2DC: andi        $t1, $t0, 0xEF
    ctx->r9 = ctx->r8 & 0XEF;
    // 0x8000D2E0: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
    // 0x8000D2E4: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
L_8000D2E8:
    // 0x8000D2E8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8000D2EC: nop

    // 0x8000D2F0: bc1fl       L_8000D304
    if (!c1cs) {
        // 0x8000D2F4: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_8000D304;
    }
    goto skip_10;
    // 0x8000D2F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_10:
    // 0x8000D2F8: jr          $ra
    // 0x8000D2FC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x8000D2FC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8000D300: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_8000D304:
    // 0x8000D304: nop

    // 0x8000D308: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8000D30C: nop

    // 0x8000D310: bc1fl       L_8000D324
    if (!c1cs) {
        // 0x8000D314: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8000D324;
    }
    goto skip_11;
    // 0x8000D314: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_11:
    // 0x8000D318: jr          $ra
    // 0x8000D31C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x8000D31C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8000D320: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8000D324:
    // 0x8000D324: jr          $ra
    // 0x8000D328: nop

    return;
    // 0x8000D328: nop

    // 0x8000D32C: nop

;}
RECOMP_FUNC void func_806CEB64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CEB64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CEB68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CEB6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CEB70: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806CEB74: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(604, 0X3B34) << 16);
    // 0x806CEB78: addiu       $t6, $t6, -0xDAC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(604, 0X3B34));
    // 0x806CEB7C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806CEB80: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806CEB84: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806CEB88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806CEB8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806CEB90: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x806CEB94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CEB98: jal         0x806CED40
    // 0x806CEB9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_806CED40(rdram, ctx);
        goto after_0;
    // 0x806CEB9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x806CEBA0: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x806CEBA4: lui         $t9, 0x806D
    ctx->r25 = S32(RELOC_HI16(604, 0X1564) << 16);
    // 0x806CEBA8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806CEBAC: sw          $zero, 0x134($s0)
    MEM_W(0X134, ctx->r16) = 0;
    // 0x806CEBB0: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806CEBB4: addiu       $t9, $t9, -0x337C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(604, 0X1564));
    // 0x806CEBB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x806CEBBC: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x806CEBC0: sb          $t1, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r9;
    // 0x806CEBC4: jal         0x806CEAE4
    // 0x806CEBC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CEAE4(rdram, ctx);
        goto after_1;
    // 0x806CEBC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CEBCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CEBD0: jal         0x80045A34
    // 0x806CEBD4: addiu       $a1, $zero, 0x88C
    ctx->r5 = ADD32(0, 0X88C);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x806CEBD4: addiu       $a1, $zero, 0x88C
    ctx->r5 = ADD32(0, 0X88C);
    after_2:
    // 0x806CEBD8: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806CEBDC: jal         0x806CC2F8
    // 0x806CEBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CC2F8(rdram, ctx);
        goto after_3;
    // 0x806CEBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806CEBE4: jal         0x806CC6F8
    // 0x806CEBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CC6F8(rdram, ctx);
        goto after_4;
    // 0x806CEBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806CEBEC: bne         $v0, $zero, L_806CEC0C
    if (ctx->r2 != 0) {
        // 0x806CEBF0: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_806CEC0C;
    }
    // 0x806CEBF0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x806CEBF4: lw          $t3, 0x180($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X180);
    // 0x806CEBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CEBFC: jal         0x80048060
    // 0x806CEC00: sw          $t2, 0x1E0($t3)
    MEM_W(0X1E0, ctx->r11) = ctx->r10;
    func_80048060(rdram, ctx);
        goto after_5;
    // 0x806CEC00: sw          $t2, 0x1E0($t3)
    MEM_W(0X1E0, ctx->r11) = ctx->r10;
    after_5:
    // 0x806CEC04: jal         0x800447C8
    // 0x806CEC08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_6;
    // 0x806CEC08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_806CEC0C:
    // 0x806CEC0C: jal         0x806CCCE4
    // 0x806CEC10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCCE4(rdram, ctx);
        goto after_7;
    // 0x806CEC10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806CEC14: jal         0x806CC008
    // 0x806CEC18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CC008(rdram, ctx);
        goto after_8;
    // 0x806CEC18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x806CEC1C: lui         $t5, 0x806D
    ctx->r13 = S32(RELOC_HI16(604, 0X340C) << 16);
    // 0x806CEC20: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x806CEC24: addiu       $t5, $t5, -0x14D4
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(604, 0X340C));
    // 0x806CEC28: sh          $t4, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r12;
    // 0x806CEC2C: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x806CEC30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806CEC34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CEC38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CEC3C: jr          $ra
    // 0x806CEC40: nop

    return;
    // 0x806CEC40: nop

;}
RECOMP_FUNC void func_806D9874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D9878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D987C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806D9880: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x806D9884: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(631, 0X3EC) << 16);
    // 0x806D9888: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D988C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806D9890: lw          $t8, -0x6504($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(631, 0X3EC));
    // 0x806D9894: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806D9898: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806D989C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x806D98A0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x806D98A4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806D98A8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806D98AC: beql        $v1, $zero, L_806D98E0
    if (ctx->r3 == 0) {
        // 0x806D98B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D98E0;
    }
    goto skip_0;
    // 0x806D98B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806D98B4: jalr        $v1
    // 0x806D98B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806D98B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D98BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D98C0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x806D98C4: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x806D98C8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x806D98CC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x806D98D0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x806D98D4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x806D98D8: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x806D98DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D98E0:
    // 0x806D98E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D98E4: jr          $ra
    // 0x806D98E8: nop

    return;
    // 0x806D98E8: nop

;}
RECOMP_FUNC void func_807607BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807607BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807607C0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x807607C4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x807607C8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x807607CC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x807607D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807607D4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x807607D8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x807607DC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807607E0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x807607E4: jr          $ra
    // 0x807607E8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x807607E8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80521FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521FC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80521FC8: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80521FCC: beql        $t6, $zero, L_80522008
    if (ctx->r14 == 0) {
        // 0x80521FD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80522008;
    }
    goto skip_0;
    // 0x80521FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80521FD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80521FD8: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80521FDC: jalr        $t9
    // 0x80521FE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80521FE0: nop

    after_0:
    // 0x80521FE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80521FE8: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80521FEC: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80521FF0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80521FF4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80521FF8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80521FFC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80522000: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x80522004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80522008:
    // 0x80522008: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052200C: jr          $ra
    // 0x80522010: nop

    return;
    // 0x80522010: nop

;}
RECOMP_FUNC void func_807AD0FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD0FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807AD100: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AD104: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807AD108: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AD10C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x807AD110: jal         0x80047090
    // 0x807AD114: addiu       $a0, $zero, 0x46EF
    ctx->r4 = ADD32(0, 0X46EF);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807AD114: addiu       $a0, $zero, 0x46EF
    ctx->r4 = ADD32(0, 0X46EF);
    after_0:
    // 0x807AD118: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807AD11C: bne         $v0, $at, L_807AD12C
    if (ctx->r2 != ctx->r1) {
        // 0x807AD120: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807AD12C;
    }
    // 0x807AD120: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807AD124: b           L_807AD1B8
    // 0x807AD128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807AD1B8;
    // 0x807AD128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AD12C:
    // 0x807AD12C: lui         $at, 0x46EF
    ctx->r1 = S32(0X46EF << 16);
    // 0x807AD130: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x807AD134: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807AD138: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x807AD13C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26B8) << 16);
    // 0x807AD140: lwc1        $f6, -0x12E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26B8));
    // 0x807AD144: lwc1        $f4, 0x8C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x807AD148: lw          $a1, 0x84($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X84);
    // 0x807AD14C: lw          $a2, 0x88($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X88);
    // 0x807AD150: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AD154: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    // 0x807AD158: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x807AD15C: jal         0x8004613C
    // 0x807AD160: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807AD160: nop

    after_1:
    // 0x807AD164: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x807AD168: bne         $v0, $zero, L_807AD178
    if (ctx->r2 != 0) {
        // 0x807AD16C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_807AD178;
    }
    // 0x807AD16C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x807AD170: b           L_807AD1B8
    // 0x807AD174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807AD1B8;
    // 0x807AD174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AD178:
    // 0x807AD178: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x807AD17C: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x807AD180: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807AD184: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x807AD188: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x807AD18C: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x807AD190: jal         0x80047F9C
    // 0x807AD194: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807AD194: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x807AD198: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807AD19C: sb          $t1, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r9;
    // 0x807AD1A0: jal         0x807ACCFC
    // 0x807AD1A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807ACCFC(rdram, ctx);
        goto after_3;
    // 0x807AD1A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807AD1A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AD1AC: jal         0x807ACDAC
    // 0x807AD1B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_807ACDAC(rdram, ctx);
        goto after_4;
    // 0x807AD1B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x807AD1B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_807AD1B8:
    // 0x807AD1B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807AD1BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AD1C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807AD1C4: jr          $ra
    // 0x807AD1C8: nop

    return;
    // 0x807AD1C8: nop

;}
RECOMP_FUNC void func_805C72B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C72B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x805C72B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805C72B8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x805C72BC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x805C72C0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x805C72C4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C72C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805C72CC: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x805C72D0: beql        $t6, $zero, L_805C74B4
    if (ctx->r14 == 0) {
        // 0x805C72D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_805C74B4;
    }
    goto skip_0;
    // 0x805C72D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x805C72D8: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x805C72DC: beq         $v0, $zero, L_805C72EC
    if (ctx->r2 == 0) {
        // 0x805C72E0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_805C72EC;
    }
    // 0x805C72E0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x805C72E4: b           L_805C74B0
    // 0x805C72E8: sw          $t7, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r15;
        goto L_805C74B0;
    // 0x805C72E8: sw          $t7, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r15;
L_805C72EC:
    // 0x805C72EC: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x805C72F0: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x805C72F4: addiu       $a0, $zero, 0x4632
    ctx->r4 = ADD32(0, 0X4632);
    // 0x805C72F8: beq         $v0, $zero, L_805C7308
    if (ctx->r2 == 0) {
        // 0x805C72FC: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_805C7308;
    }
    // 0x805C72FC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x805C7300: b           L_805C74B0
    // 0x805C7304: sw          $t8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r24;
        goto L_805C74B0;
    // 0x805C7304: sw          $t8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r24;
L_805C7308:
    // 0x805C7308: jal         0x80047090
    // 0x805C730C: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805C730C: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    after_0:
    // 0x805C7310: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x805C7314: beq         $a0, $v0, L_805C74B0
    if (ctx->r4 == ctx->r2) {
        // 0x805C7318: sh          $v0, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r2;
            goto L_805C74B0;
    }
    // 0x805C7318: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x805C731C: beql        $a0, $v0, L_805C73F8
    if (ctx->r4 == ctx->r2) {
        // 0x805C7320: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_805C73F8;
    }
    goto skip_1;
    // 0x805C7320: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x805C7324: lw          $t0, 0x138($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X138);
    // 0x805C7328: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805C732C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805C7330: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805C7334: bne         $t0, $zero, L_805C7344
    if (ctx->r8 != 0) {
        // 0x805C7338: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_805C7344;
    }
    // 0x805C7338: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805C733C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805C7340: nop

L_805C7344:
    // 0x805C7344: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805C7348: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805C734C: lwc1        $f4, 0x50($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
    // 0x805C7350: sub.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x805C7354: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x805C7358: nop

    // 0x805C735C: bc1fl       L_805C736C
    if (!c1cs) {
        // 0x805C7360: c.lt.s      $f20, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
            goto L_805C736C;
    }
    goto skip_2;
    // 0x805C7360: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    skip_2:
    // 0x805C7364: sub.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x805C7368: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
L_805C736C:
    // 0x805C736C: nop

    // 0x805C7370: bc1fl       L_805C7380
    if (!c1cs) {
        // 0x805C7374: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_805C7380;
    }
    goto skip_3;
    // 0x805C7374: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_3:
    // 0x805C7378: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x805C737C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_805C7380:
    // 0x805C7380: jal         0x80066E88
    // 0x805C7384: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x805C7384: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x805C7388: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805C738C: lwc1        $f16, 0x170($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X170);
    // 0x805C7390: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x805C7394: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x805C7398: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x805C739C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x805C73A0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x805C73A4: jal         0x80066DE4
    // 0x805C73A8: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x805C73A8: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x805C73AC: lwc1        $f8, 0x178($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X178);
    // 0x805C73B0: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    // 0x805C73B4: lui         $at, 0x4632
    ctx->r1 = S32(0X4632 << 16);
    // 0x805C73B8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x805C73BC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    // 0x805C73C0: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(447, 0X3BE8) << 16);
    // 0x805C73C4: lwc1        $f16, 0x40($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X40);
    // 0x805C73C8: lwc1        $f4, -0x5F28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X3BE8));
    // 0x805C73CC: lwc1        $f18, 0x44($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X44);
    // 0x805C73D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x805C73D4: add.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805C73D8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x805C73DC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x805C73E0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x805C73E4: jal         0x8004613C
    // 0x805C73E8: nop

    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x805C73E8: nop

    after_3:
    // 0x805C73EC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x805C73F0: swc1        $f20, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f20.u32l;
    // 0x805C73F4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_805C73F8:
    // 0x805C73F8: lwc1        $f20, 0x30($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X30);
    // 0x805C73FC: beql        $t1, $zero, L_805C74B4
    if (ctx->r9 == 0) {
        // 0x805C7400: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_805C74B4;
    }
    goto skip_4;
    // 0x805C7400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x805C7404: jal         0x80044194
    // 0x805C7408: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_80044194(rdram, ctx);
        goto after_4;
    // 0x805C7408: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_4:
    // 0x805C740C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x805C7410: jal         0x80067BBC
    // 0x805C7414: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x805C7414: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_5:
    // 0x805C7418: addiu       $a0, $zero, 0xC9
    ctx->r4 = ADD32(0, 0XC9);
    // 0x805C741C: jal         0x80067818
    // 0x805C7420: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x805C7420: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x805C7424: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x805C7428: lw          $t2, 0x138($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X138);
    // 0x805C742C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805C7430: swc1        $f20, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f20.u32l;
    // 0x805C7434: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x805C7438: sw          $t3, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r11;
    // 0x805C743C: lwc1        $f10, 0x17C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x805C7440: lwc1        $f8, 0x50($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X50);
    // 0x805C7444: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805C7448: add.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805C744C: swc1        $f16, 0xE0($v0)
    MEM_W(0XE0, ctx->r2) = ctx->f16.u32l;
    // 0x805C7450: jal         0x80066E88
    // 0x805C7454: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x805C7454: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x805C7458: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x805C745C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805C7460: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805C7464: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x805C7468: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x805C746C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x805C7470: addiu       $s1, $s1, 0xC4
    ctx->r17 = ADD32(ctx->r17, 0XC4);
    // 0x805C7474: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x805C7478: jal         0x80066DE4
    // 0x805C747C: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x805C747C: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    after_8:
    // 0x805C7480: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x805C7484: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805C7488: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x805C748C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x805C7490: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x805C7494: lw          $t4, 0x58($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X58);
    // 0x805C7498: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x805C749C: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x805C74A0: bne         $at, $zero, L_805C74B0
    if (ctx->r1 != 0) {
        // 0x805C74A4: sw          $t5, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->r13;
            goto L_805C74B0;
    }
    // 0x805C74A4: sw          $t5, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r13;
    // 0x805C74A8: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x805C74AC: sw          $t7, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r15;
L_805C74B0:
    // 0x805C74B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805C74B4:
    // 0x805C74B4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x805C74B8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x805C74BC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x805C74C0: jr          $ra
    // 0x805C74C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x805C74C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80058D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058D94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058D98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058D9C: jal         0x80081C64
    // 0x80058DA0: nop

    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80058DA0: nop

    after_0:
    // 0x80058DA4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80058DA8: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x80058DAC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80058DB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80058DB4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80058DB8: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80058DBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80058DC0: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80058DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058DC8: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80058DCC: lwc1        $f4, 0xB90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB90);
    // 0x80058DD0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80058DD4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80058DD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80058DDC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80058DE0: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80058DE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80058DE8: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80058DEC: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80058DF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058DF4: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80058DF8: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80058DFC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80058E00: jr          $ra
    // 0x80058E04: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    return;
    // 0x80058E04: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
;}
RECOMP_FUNC void func_8064B218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B218: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8064B21C: lwc1        $f16, 0xDC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x8064B220: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8064B224: lwc1        $f6, 0xE8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE8);
    // 0x8064B228: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8064B22C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8064B230: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8064B234: bc1f        L_8064B260
    if (!c1cs) {
        // 0x8064B238: swc1        $f8, 0xC4($a0)
        MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
            goto L_8064B260;
    }
    // 0x8064B238: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x8064B23C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8064B240: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8064B244: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064B248: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8064B24C: nop

    // 0x8064B250: bc1fl       L_8064B280
    if (!c1cs) {
        // 0x8064B254: lwc1        $f6, 0x3C($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_8064B280;
    }
    goto skip_0;
    // 0x8064B254: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    skip_0:
    // 0x8064B258: b           L_8064B27C
    // 0x8064B25C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_8064B27C;
    // 0x8064B25C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8064B260:
    // 0x8064B260: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8064B264: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064B268: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8064B26C: nop

    // 0x8064B270: bc1fl       L_8064B280
    if (!c1cs) {
        // 0x8064B274: lwc1        $f6, 0x3C($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_8064B280;
    }
    goto skip_1;
    // 0x8064B274: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    skip_1:
    // 0x8064B278: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8064B27C:
    // 0x8064B27C: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
L_8064B280:
    // 0x8064B280: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8064B284: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8064B288: jr          $ra
    // 0x8064B28C: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x8064B28C: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80469BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469BA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80469BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80469BAC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80469BB0: jal         0x80469900
    // 0x80469BB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80469900(rdram, ctx);
        goto after_0;
    // 0x80469BB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80469BB8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80469BBC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80469BC0: bne         $v0, $at, L_80469BCC
    if (ctx->r2 != ctx->r1) {
        // 0x80469BC4: addiu       $v1, $v0, 0x1
        ctx->r3 = ADD32(ctx->r2, 0X1);
            goto L_80469BCC;
    }
    // 0x80469BC4: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80469BC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80469BCC:
    // 0x80469BCC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80469BD0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80469BD4: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x80469BD8: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80469BDC: lwc1        $f4, 0x4C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x80469BE0: lwc1        $f6, 0x4C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x80469BE4: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2924) << 16);
    // 0x80469BE8: lwc1        $f8, -0x3F9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2924));
    // 0x80469BEC: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80469BF0: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2928) << 16);
    // 0x80469BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80469BF8: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80469BFC: nop

    // 0x80469C00: bc1tl       L_80469C2C
    if (c1cs) {
        // 0x80469C04: lui         $at, 0xC270
        ctx->r1 = S32(0XC270 << 16);
            goto L_80469C2C;
    }
    goto skip_0;
    // 0x80469C04: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    skip_0:
    // 0x80469C08: lwc1        $f10, -0x3F98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2928));
    // 0x80469C0C: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80469C10: nop

    // 0x80469C14: bc1tl       L_80469C2C
    if (c1cs) {
        // 0x80469C18: lui         $at, 0xC270
        ctx->r1 = S32(0XC270 << 16);
            goto L_80469C2C;
    }
    goto skip_1;
    // 0x80469C18: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    skip_1:
    // 0x80469C1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80469C20: b           L_80469C3C
    // 0x80469C24: nop

        goto L_80469C3C;
    // 0x80469C24: nop

    // 0x80469C28: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
L_80469C2C:
    // 0x80469C2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80469C30: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80469C34: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80469C38: div.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
L_80469C3C:
    // 0x80469C3C: jr          $ra
    // 0x80469C40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80469C40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80018EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018EE8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80018EEC: jr          $ra
    // 0x80018EF0: sw          $a0, -0x6D18($at)
    MEM_W(-0X6D18, ctx->r1) = ctx->r4;
    return;
    // 0x80018EF0: sw          $a0, -0x6D18($at)
    MEM_W(-0X6D18, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80535350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80535354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80535358: jal         0x80534620
    // 0x8053535C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80534620(rdram, ctx);
        goto after_0;
    // 0x8053535C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80535360: jal         0x80045BD8
    // 0x80535364: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80535364: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80535368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8053536C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80535370: jr          $ra
    // 0x80535374: nop

    return;
    // 0x80535374: nop

;}
RECOMP_FUNC void func_805745DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805745DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805745E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805745E4: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x805745E8: bnel        $t6, $zero, L_80574618
    if (ctx->r14 != 0) {
        // 0x805745EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80574618;
    }
    goto skip_0;
    // 0x805745EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805745F0: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x805745F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805745F8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805745FC: sh          $t7, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r15;
    // 0x80574600: jal         0x8005FCA8
    // 0x80574604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x80574604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80574608: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8057460C: jal         0x80574A64
    // 0x80574610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80574A64(rdram, ctx);
        goto after_1;
    // 0x80574610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80574614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80574618:
    // 0x80574618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057461C: jr          $ra
    // 0x80574620: nop

    return;
    // 0x80574620: nop

;}
RECOMP_FUNC void func_80562E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80562E84: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80562E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80562E8C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80562E90: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80562E94: jal         0x8004700C
    // 0x80562E98: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80562E98: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80562E9C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80562EA0: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80562EA4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80562EA8: beq         $v0, $zero, L_805630EC
    if (ctx->r2 == 0) {
        // 0x80562EAC: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_805630EC;
    }
    // 0x80562EAC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80562EB0: lw          $a0, 0x174($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X174);
    // 0x80562EB4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80562EB8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80562EBC: lh          $t8, 0xC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XC);
    // 0x80562EC0: lw          $t7, 0x70($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X70);
    // 0x80562EC4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80562EC8: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80562ECC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80562ED0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80562ED4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80562ED8: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80562EDC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80562EE0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80562EE4: nop

    // 0x80562EE8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80562EEC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80562EF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80562EF4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80562EF8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80562EFC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80562F00: lw          $t2, 0x180($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X180);
    // 0x80562F04: bnel        $t2, $zero, L_805630F0
    if (ctx->r10 != 0) {
        // 0x80562F08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805630F0;
    }
    goto skip_0;
    // 0x80562F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80562F0C: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x80562F10: andi        $t4, $t3, 0xF00
    ctx->r12 = ctx->r11 & 0XF00;
    // 0x80562F14: bnel        $t4, $zero, L_805630F0
    if (ctx->r12 != 0) {
        // 0x80562F18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805630F0;
    }
    goto skip_1;
    // 0x80562F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80562F1C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80562F20: lwc1        $f10, 0xC8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80562F24: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80562F28: nop

    // 0x80562F2C: bc1fl       L_805630F0
    if (!c1cs) {
        // 0x80562F30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805630F0;
    }
    goto skip_2;
    // 0x80562F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80562F34: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80562F38: addiu       $a1, $a2, 0x6C0
    ctx->r5 = ADD32(ctx->r6, 0X6C0);
    // 0x80562F3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80562F40: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x80562F44: lw          $t5, 0x174($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X174);
    // 0x80562F48: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x80562F4C: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x80562F50: lw          $t6, 0x70($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X70);
    // 0x80562F54: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x80562F58: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80562F5C: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80562F60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80562F64: lwc1        $f8, 0x88($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80562F68: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80562F6C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80562F70: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80562F74: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x80562F78: lwc1        $f10, 0x84($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X84);
    // 0x80562F7C: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80562F80: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80562F84: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80562F88: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80562F8C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80562F90: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80562F94: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80562F98: nop

    // 0x80562F9C: bc1fl       L_805630F0
    if (!c1cs) {
        // 0x80562FA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805630F0;
    }
    goto skip_3;
    // 0x80562FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_80562FA4:
    // 0x80562FA4: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80562FA8: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80562FAC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80562FB0: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80562FB4: nop

    // 0x80562FB8: bc1f        L_805630E4
    if (!c1cs) {
        // 0x80562FBC: nop
    
            goto L_805630E4;
    }
    // 0x80562FBC: nop

    // 0x80562FC0: lwc1        $f2, -0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X8);
    // 0x80562FC4: lwc1        $f12, -0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80562FC8: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80562FCC: sub.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80562FD0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80562FD4: sub.s       $f16, $f12, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80562FD8: sub.s       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80562FDC: div.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80562FE0: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80562FE4: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80562FE8: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80562FEC: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80562FF0: sub.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80562FF4: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80562FF8: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80562FFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80563000: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80563004: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80563008: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x8056300C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80563010: bc1fl       L_805630F0
    if (!c1cs) {
        // 0x80563014: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805630F0;
    }
    goto skip_4;
    // 0x80563014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80563018: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8056301C: nop

    // 0x80563020: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80563024: c.le.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x80563028: nop

    // 0x8056302C: bc1fl       L_805630F0
    if (!c1cs) {
        // 0x80563030: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805630F0;
    }
    goto skip_5;
    // 0x80563030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80563034: lw          $t8, 0x714($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X714);
    // 0x80563038: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8056303C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80563040: bne         $t8, $zero, L_8056304C
    if (ctx->r24 != 0) {
        // 0x80563044: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8056304C;
    }
    // 0x80563044: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80563048: swc1        $f4, 0x728($a2)
    MEM_W(0X728, ctx->r6) = ctx->f4.u32l;
L_8056304C:
    // 0x8056304C: lwc1        $f10, 0xC4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x80563050: addiu       $a1, $t1, 0xC4
    ctx->r5 = ADD32(ctx->r9, 0XC4);
    // 0x80563054: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x80563058: nop

    // 0x8056305C: bc1fl       L_805630B8
    if (!c1cs) {
        // 0x80563060: lwc1        $f10, 0x44($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
            goto L_805630B8;
    }
    goto skip_6;
    // 0x80563060: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    skip_6:
    // 0x80563064: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80563068: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8056306C: jal         0x80562B74
    // 0x80563070: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_80562B74(rdram, ctx);
        goto after_1;
    // 0x80563070: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x80563074: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80563078: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8056307C: bne         $v0, $zero, L_805630B4
    if (ctx->r2 != 0) {
        // 0x80563080: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_805630B4;
    }
    // 0x80563080: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80563084: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80563088: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8056308C: jal         0x80562BC4
    // 0x80563090: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_80562BC4(rdram, ctx);
        goto after_2;
    // 0x80563090: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_2:
    // 0x80563094: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80563098: bne         $v0, $zero, L_805630B4
    if (ctx->r2 != 0) {
        // 0x8056309C: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_805630B4;
    }
    // 0x8056309C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x805630A0: lwc1        $f8, 0x728($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X728);
    // 0x805630A4: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x805630A8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x805630AC: b           L_805630BC
    // 0x805630B0: swc1        $f6, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f6.u32l;
        goto L_805630BC;
    // 0x805630B0: swc1        $f6, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f6.u32l;
L_805630B4:
    // 0x805630B4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
L_805630B8:
    // 0x805630B8: swc1        $f10, 0x728($a2)
    MEM_W(0X728, ctx->r6) = ctx->f10.u32l;
L_805630BC:
    // 0x805630BC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x805630C0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805630C4: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x805630C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805630CC: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x805630D0: swc1        $f6, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f6.u32l;
    // 0x805630D4: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x805630D8: ori         $t2, $t9, 0x700
    ctx->r10 = ctx->r25 | 0X700;
    // 0x805630DC: b           L_805630EC
    // 0x805630E0: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
        goto L_805630EC;
    // 0x805630E0: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
L_805630E4:
    // 0x805630E4: bne         $a0, $a1, L_80562FA4
    if (ctx->r4 != ctx->r5) {
        // 0x805630E8: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80562FA4;
    }
    // 0x805630E8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_805630EC:
    // 0x805630EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805630F0:
    // 0x805630F0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x805630F4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x805630F8: jr          $ra
    // 0x805630FC: nop

    return;
    // 0x805630FC: nop

;}
RECOMP_FUNC void func_804A00E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A00E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A00E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A00E8: jal         0x80056904
    // 0x804A00EC: nop

    func_80056904(rdram, ctx);
        goto after_0;
    // 0x804A00EC: nop

    after_0:
    // 0x804A00F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A00F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A00F8: jr          $ra
    // 0x804A00FC: nop

    return;
    // 0x804A00FC: nop

;}
RECOMP_FUNC void func_804BA2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BA2E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BA2EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BA2F0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804BA2F4: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804BA2F8: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(185, 0X2AD4) << 16);
    // 0x804BA2FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BA300: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804BA304: lw          $t8, -0x570C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(185, 0X2AD4));
    // 0x804BA308: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804BA30C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804BA310: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804BA314: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804BA318: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804BA31C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804BA320: beql        $v1, $zero, L_804BA354
    if (ctx->r3 == 0) {
        // 0x804BA324: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BA354;
    }
    goto skip_0;
    // 0x804BA324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BA328: jalr        $v1
    // 0x804BA32C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804BA32C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BA330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BA334: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804BA338: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804BA33C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804BA340: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804BA344: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804BA348: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804BA34C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804BA350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BA354:
    // 0x804BA354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BA358: jr          $ra
    // 0x804BA35C: nop

    return;
    // 0x804BA35C: nop

;}
RECOMP_FUNC void func_8064C9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C9AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C9B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C9B4: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064C9B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8064C9BC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C9C0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064C9C4: nop

    // 0x8064C9C8: bc1fl       L_8064CA20
    if (!c1cs) {
        // 0x8064C9CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064CA20;
    }
    goto skip_0;
    // 0x8064C9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C9D0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064C9D4: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064C9D8: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x8064C9DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064C9E0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8064C9E4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8064C9E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C9EC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8064C9F0: nop

    // 0x8064C9F4: bc1fl       L_8064CA20
    if (!c1cs) {
        // 0x8064C9F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064CA20;
    }
    goto skip_1;
    // 0x8064C9F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8064C9FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064CA00: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(495, 0X365C) << 16);
    // 0x8064CA04: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8064CA08: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8064CA0C: lwc1        $f6, -0x28D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(495, 0X365C));
    // 0x8064CA10: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064CA14: jal         0x8064CD50
    // 0x8064CA18: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    func_8064CD50(rdram, ctx);
        goto after_0;
    // 0x8064CA18: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x8064CA1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064CA20:
    // 0x8064CA20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064CA24: jr          $ra
    // 0x8064CA28: nop

    return;
    // 0x8064CA28: nop

;}
RECOMP_FUNC void func_80427AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80427AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80427AC8: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80427ACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80427AD0: beq         $t6, $zero, L_80427B0C
    if (ctx->r14 == 0) {
        // 0x80427AD4: nop
    
            goto L_80427B0C;
    }
    // 0x80427AD4: nop

    // 0x80427AD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80427ADC: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80427AE0: jalr        $t9
    // 0x80427AE4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80427AE4: nop

    after_0:
    // 0x80427AE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80427AEC: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80427AF0: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80427AF4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80427AF8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80427AFC: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80427B00: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80427B04: b           L_80427B0C
    // 0x80427B08: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80427B0C;
    // 0x80427B08: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80427B0C:
    // 0x80427B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80427B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80427B14: jr          $ra
    // 0x80427B18: nop

    return;
    // 0x80427B18: nop

;}
RECOMP_FUNC void func_80054AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054AF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80054AFC: jal         0x80064E84
    // 0x80054B00: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x80054B00: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80054B04: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80054B08: jal         0x80064E84
    // 0x80054B0C: lw          $a0, 0x18($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X18);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x80054B0C: lw          $a0, 0x18($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X18);
    after_1:
    // 0x80054B10: jal         0x80064E84
    // 0x80054B14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x80054B14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80054B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80054B20: jr          $ra
    // 0x80054B24: nop

    return;
    // 0x80054B24: nop

;}
RECOMP_FUNC void func_80010640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010640: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80010644: addiu       $v0, $v0, -0x6DA0
    ctx->r2 = ADD32(ctx->r2, -0X6DA0);
    // 0x80010648: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8001064C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010654: bne         $t6, $zero, L_80010678
    if (ctx->r14 != 0) {
        // 0x80010658: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80010678;
    }
    // 0x80010658: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001065C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80010660: jal         0x8001B960
    // 0x80010664: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001B960(rdram, ctx);
        goto after_0;
    // 0x80010664: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80010668: jal         0x80011A74
    // 0x8001066C: nop

    func_80011A74(rdram, ctx);
        goto after_1;
    // 0x8001066C: nop

    after_1:
    // 0x80010670: jal         0x80011540
    // 0x80010674: nop

    func_80011540(rdram, ctx);
        goto after_2;
    // 0x80010674: nop

    after_2:
L_80010678:
    // 0x80010678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001067C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80010680: jr          $ra
    // 0x80010684: nop

    return;
    // 0x80010684: nop

;}
RECOMP_FUNC void func_804CFAFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CFAFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CFB00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CFB04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CFB08: jal         0x804CFAA0
    // 0x804CFB0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804CFAA0(rdram, ctx);
        goto after_0;
    // 0x804CFB0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804CFB10: bne         $v0, $zero, L_804CFB28
    if (ctx->r2 != 0) {
        // 0x804CFB14: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_804CFB28;
    }
    // 0x804CFB14: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804CFB18: jal         0x800445A4
    // 0x804CFB1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804CFB1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804CFB20: b           L_804CFBA8
    // 0x804CFB24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804CFBA8;
    // 0x804CFB24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CFB28:
    // 0x804CFB28: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x804CFB2C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804CFB30: lui         $t7, 0x804D
    ctx->r15 = S32(RELOC_HI16(240, 0X1AD4) << 16);
    // 0x804CFB34: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x804CFB38: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804CFB3C: addiu       $t7, $t7, -0x27C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(240, 0X1AD4));
    // 0x804CFB40: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804CFB44: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804CFB48: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804CFB4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CFB50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CFB54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804CFB58: jal         0x804CFBB8
    // 0x804CFB5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804CFBB8(rdram, ctx);
        goto after_2;
    // 0x804CFB5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804CFB60: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x804CFB64: jal         0x804CFAE4
    // 0x804CFB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CFAE4(rdram, ctx);
        goto after_3;
    // 0x804CFB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804CFB6C: jal         0x804CF930
    // 0x804CFB70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF930(rdram, ctx);
        goto after_4;
    // 0x804CFB70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804CFB74: bne         $v0, $zero, L_804CFB8C
    if (ctx->r2 != 0) {
        // 0x804CFB78: nop
    
            goto L_804CFB8C;
    }
    // 0x804CFB78: nop

    // 0x804CFB7C: jal         0x800445A4
    // 0x804CFB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x804CFB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804CFB84: b           L_804CFBA8
    // 0x804CFB88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804CFBA8;
    // 0x804CFB88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CFB8C:
    // 0x804CFB8C: jal         0x804CF9D8
    // 0x804CFB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF9D8(rdram, ctx);
        goto after_6;
    // 0x804CFB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804CFB94: bnel        $v0, $zero, L_804CFBA8
    if (ctx->r2 != 0) {
        // 0x804CFB98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CFBA8;
    }
    goto skip_0;
    // 0x804CFB98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804CFB9C: jal         0x800445A4
    // 0x804CFBA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x804CFBA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x804CFBA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CFBA8:
    // 0x804CFBA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CFBAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CFBB0: jr          $ra
    // 0x804CFBB4: nop

    return;
    // 0x804CFBB4: nop

;}
RECOMP_FUNC void pad_off_trigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FB6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8007FB70: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    // 0x8007FB74: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8007FB78: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x8007FB7C: xor         $v0, $t7, $a1
    ctx->r2 = ctx->r15 ^ ctx->r5;
    // 0x8007FB80: jr          $ra
    // 0x8007FB84: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8007FB84: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80558EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558EA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80558EA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80558EA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80558EAC: jal         0x805582E0
    // 0x80558EB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_805582E0(rdram, ctx);
        goto after_0;
    // 0x80558EB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80558EB4: lw          $t6, 0x1E4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E4);
    // 0x80558EB8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80558EBC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80558EC0: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80558EC4: bne         $v0, $at, L_80558F00
    if (ctx->r2 != ctx->r1) {
        // 0x80558EC8: sw          $v0, 0x1E4($s0)
        MEM_W(0X1E4, ctx->r16) = ctx->r2;
            goto L_80558F00;
    }
    // 0x80558EC8: sw          $v0, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r2;
    // 0x80558ECC: sb          $t8, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r24;
    // 0x80558ED0: jal         0x800677F8
    // 0x80558ED4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800677F8(rdram, ctx);
        goto after_1;
    // 0x80558ED4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_1:
    // 0x80558ED8: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80558EDC: lw          $t9, -0x7288($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7288);
    // 0x80558EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558EE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558EE8: jalr        $t9
    // 0x80558EEC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80558EEC: nop

    after_2:
    // 0x80558EF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80558EF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80558EF8: sb          $t0, 0x7EA5($at)
    MEM_B(0X7EA5, ctx->r1) = ctx->r8;
    // 0x80558EFC: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
L_80558F00:
    // 0x80558F00: slti        $at, $v0, 0xD2
    ctx->r1 = SIGNED(ctx->r2) < 0XD2 ? 1 : 0;
    // 0x80558F04: bne         $at, $zero, L_80558F18
    if (ctx->r1 != 0) {
        // 0x80558F08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80558F18;
    }
    // 0x80558F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558F0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80558F10: jal         0x80559928
    // 0x80558F14: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    func_80559928(rdram, ctx);
        goto after_3;
    // 0x80558F14: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_3:
L_80558F18:
    // 0x80558F18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80558F1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80558F20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80558F24: jr          $ra
    // 0x80558F28: nop

    return;
    // 0x80558F28: nop

;}
RECOMP_FUNC void func_806ED5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED5F0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CE4) << 16);
    // 0x806ED5F4: lwc1        $f2, 0xC34($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CE4));
    // 0x806ED5F8: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806ED5FC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806ED600: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806ED604: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x806ED608: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806ED60C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x806ED610: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x806ED614: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806ED618: bne         $t6, $at, L_806ED654
    if (ctx->r14 != ctx->r1) {
        // 0x806ED61C: nop
    
            goto L_806ED654;
    }
    // 0x806ED61C: nop

    // 0x806ED620: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806ED624: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806ED628: nop

    // 0x806ED62C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x806ED630: nop

    // 0x806ED634: bc1fl       L_806ED64C
    if (!c1cs) {
        // 0x806ED638: sub.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_806ED64C;
    }
    goto skip_0;
    // 0x806ED638: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x806ED63C: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x806ED640: b           L_806ED668
    // 0x806ED644: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
        goto L_806ED668;
    // 0x806ED644: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x806ED648: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
L_806ED64C:
    // 0x806ED64C: b           L_806ED668
    // 0x806ED650: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
        goto L_806ED668;
    // 0x806ED650: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
L_806ED654:
    // 0x806ED654: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CE8) << 16);
    // 0x806ED658: lwc1        $f8, 0xC38($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CE8));
    // 0x806ED65C: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806ED660: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x806ED664: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
L_806ED668:
    // 0x806ED668: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806ED66C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806ED670: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806ED674: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x806ED678: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806ED67C: nop

    // 0x806ED680: bc1fl       L_806ED698
    if (!c1cs) {
        // 0x806ED684: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_806ED698;
    }
    goto skip_1;
    // 0x806ED684: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x806ED688: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x806ED68C: b           L_806ED6B4
    // 0x806ED690: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
        goto L_806ED6B4;
    // 0x806ED690: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806ED694: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_806ED698:
    // 0x806ED698: nop

    // 0x806ED69C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806ED6A0: nop

    // 0x806ED6A4: bc1fl       L_806ED6B8
    if (!c1cs) {
        // 0x806ED6A8: lwc1        $f16, 0x50($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
            goto L_806ED6B8;
    }
    goto skip_2;
    // 0x806ED6A8: lwc1        $f16, 0x50($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
    skip_2:
    // 0x806ED6AC: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x806ED6B0: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
L_806ED6B4:
    // 0x806ED6B4: lwc1        $f16, 0x50($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
L_806ED6B8:
    // 0x806ED6B8: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x806ED6BC: jr          $ra
    // 0x806ED6C0: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x806ED6C0: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_80045AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80045AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045AF0: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x80045AF4: addiu       $a1, $zero, 0x279
    ctx->r5 = ADD32(0, 0X279);
    // 0x80045AF8: beq         $t6, $zero, L_80045B14
    if (ctx->r14 == 0) {
        // 0x80045AFC: nop
    
            goto L_80045B14;
    }
    // 0x80045AFC: nop

    // 0x80045B00: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045B04: jal         0x80071380
    // 0x80045B08: addiu       $a0, $a0, 0x6C0
    ctx->r4 = ADD32(ctx->r4, 0X6C0);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80045B08: addiu       $a0, $a0, 0x6C0
    ctx->r4 = ADD32(ctx->r4, 0X6C0);
    after_0:
    // 0x80045B0C: b           L_80045B20
    // 0x80045B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80045B20;
    // 0x80045B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80045B14:
    // 0x80045B14: jal         0x800439F4
    // 0x80045B18: nop

    func_800439F4(rdram, ctx);
        goto after_1;
    // 0x80045B18: nop

    after_1:
    // 0x80045B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80045B20:
    // 0x80045B20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80045B24: jr          $ra
    // 0x80045B28: nop

    return;
    // 0x80045B28: nop

;}
RECOMP_FUNC void func_807991D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807991D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807991DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807991E0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807991E4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x807991E8: blezl       $t7, L_80799210
    if (SIGNED(ctx->r15) <= 0) {
        // 0x807991EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80799210;
    }
    goto skip_0;
    // 0x807991EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807991F0: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x807991F4: addiu       $at, $zero, 0x46B3
    ctx->r1 = ADD32(0, 0X46B3);
    // 0x807991F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807991FC: bnel        $t8, $at, L_80799210
    if (ctx->r24 != ctx->r1) {
        // 0x80799200: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80799210;
    }
    goto skip_1;
    // 0x80799200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80799204: jal         0x80799654
    // 0x80799208: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80799654(rdram, ctx);
        goto after_0;
    // 0x80799208: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8079920C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80799210:
    // 0x80799210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80799214: jr          $ra
    // 0x80799218: nop

    return;
    // 0x80799218: nop

;}
RECOMP_FUNC void func_805351C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805351C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805351CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805351D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805351D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805351D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805351DC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805351E0: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x805351E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805351E8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x805351EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805351F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805351F4: jal         0x80062AEC
    // 0x805351F8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x805351F8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    after_0:
    // 0x805351FC: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x80535200: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80535204: bnel        $t7, $at, L_80535314
    if (ctx->r15 != ctx->r1) {
        // 0x80535208: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80535314;
    }
    goto skip_0;
    // 0x80535208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8053520C: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
    // 0x80535210: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80535214: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80535218: bne         $v1, $at, L_80535244
    if (ctx->r3 != ctx->r1) {
        // 0x8053521C: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80535244;
    }
    // 0x8053521C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80535220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80535224: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80535228: jal         0x805351A8
    // 0x8053522C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_805351A8(rdram, ctx);
        goto after_1;
    // 0x8053522C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80535230: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80535234: lhu         $t8, 0xC($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XC);
    // 0x80535238: andi        $t9, $t8, 0xFFFB
    ctx->r25 = ctx->r24 & 0XFFFB;
    // 0x8053523C: b           L_80535310
    // 0x80535240: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
        goto L_80535310;
    // 0x80535240: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
L_80535244:
    // 0x80535244: bne         $v0, $a0, L_805352F8
    if (ctx->r2 != ctx->r4) {
        // 0x80535248: nop
    
            goto L_805352F8;
    }
    // 0x80535248: nop

    // 0x8053524C: lbu         $t0, 0x30($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X30);
    // 0x80535250: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80535254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80535258: bne         $t0, $at, L_805352AC
    if (ctx->r8 != ctx->r1) {
        // 0x8053525C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_805352AC;
    }
    // 0x8053525C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80535260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80535264: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80535268: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8053526C: jal         0x805350A0
    // 0x80535270: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_805350A0(rdram, ctx);
        goto after_2;
    // 0x80535270: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
    // 0x80535274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80535278: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8053527C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80535280: jal         0x805351A8
    // 0x80535284: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_805351A8(rdram, ctx);
        goto after_3;
    // 0x80535284: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80535288: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8053528C: lhu         $t1, 0xC($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XC);
    // 0x80535290: andi        $t2, $t1, 0xFFFD
    ctx->r10 = ctx->r9 & 0XFFFD;
    // 0x80535294: sh          $t2, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r10;
    // 0x80535298: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8053529C: lhu         $t3, 0xC($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XC);
    // 0x805352A0: andi        $t4, $t3, 0xFFFB
    ctx->r12 = ctx->r11 & 0XFFFB;
    // 0x805352A4: b           L_80535310
    // 0x805352A8: sh          $t4, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r12;
        goto L_80535310;
    // 0x805352A8: sh          $t4, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r12;
L_805352AC:
    // 0x805352AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805352B0: jal         0x805350A0
    // 0x805352B4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_805350A0(rdram, ctx);
        goto after_4;
    // 0x805352B4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x805352B8: jal         0x8002F92C
    // 0x805352BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002F92C(rdram, ctx);
        goto after_5;
    // 0x805352BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x805352C0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x805352C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805352C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805352CC: lhu         $t5, 0xC($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XC);
    // 0x805352D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805352D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805352D8: andi        $t6, $t5, 0xFFFD
    ctx->r14 = ctx->r13 & 0XFFFD;
    // 0x805352DC: sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // 0x805352E0: addiu       $a1, $zero, 0x21E
    ctx->r5 = ADD32(0, 0X21E);
    // 0x805352E4: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x805352E8: jal         0x805346E4
    // 0x805352EC: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    func_805346E4(rdram, ctx);
        goto after_6;
    // 0x805352EC: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x805352F0: b           L_80535314
    // 0x805352F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80535314;
    // 0x805352F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805352F8:
    // 0x805352F8: beq         $a0, $v1, L_80535310
    if (ctx->r4 == ctx->r3) {
        // 0x805352FC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80535310;
    }
    // 0x805352FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80535300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80535304: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80535308: jal         0x8002F6E4
    // 0x8053530C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_7;
    // 0x8053530C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_80535310:
    // 0x80535310: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80535314:
    // 0x80535314: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80535318: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8053531C: jr          $ra
    // 0x80535320: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80535320: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800716C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800716C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800716C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800716C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800716CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800716D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800716D4: sw          $t6, -0x7AE4($at)
    MEM_W(-0X7AE4, ctx->r1) = ctx->r14;
    // 0x800716D8: addiu       $a0, $a0, -0x6360
    ctx->r4 = ADD32(ctx->r4, -0X6360);
    // 0x800716DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800716E0: jal         0x80082210
    // 0x800716E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800716E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800716E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800716EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800716F0: jr          $ra
    // 0x800716F4: nop

    return;
    // 0x800716F4: nop

;}
RECOMP_FUNC void func_80020DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020DBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80020DC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020DC4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80020DC8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80020DCC: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x80020DD0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80020DD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020DD8: bne         $t6, $at, L_80020E04
    if (ctx->r14 != ctx->r1) {
        // 0x80020DDC: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80020E04;
    }
    // 0x80020DDC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80020DE0: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x80020DE4: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80020DE8: bnel        $t7, $at, L_80020E08
    if (ctx->r15 != ctx->r1) {
        // 0x80020DEC: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80020E08;
    }
    goto skip_0;
    // 0x80020DEC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    skip_0:
    // 0x80020DF0: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80020DF4: lwc1        $f6, 0xAC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x80020DF8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80020DFC: nop

    // 0x80020E00: bc1t        L_80020E3C
    if (c1cs) {
        // 0x80020E04: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80020E3C;
    }
L_80020E04:
    // 0x80020E04: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
L_80020E08:
    // 0x80020E08: jal         0x80047AB8
    // 0x80020E0C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80020E0C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80020E10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80020E14: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80020E18: jal         0x80020B78
    // 0x80020E1C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_80020B78(rdram, ctx);
        goto after_1;
    // 0x80020E1C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80020E20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80020E24: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80020E28: jal         0x80020BD0
    // 0x80020E2C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_80020BD0(rdram, ctx);
        goto after_2;
    // 0x80020E2C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80020E30: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80020E34: jal         0x80020CE4
    // 0x80020E38: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80020CE4(rdram, ctx);
        goto after_3;
    // 0x80020E38: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
L_80020E3C:
    // 0x80020E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020E40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80020E44: jr          $ra
    // 0x80020E48: nop

    return;
    // 0x80020E48: nop

;}
RECOMP_FUNC void func_804559B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804559B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804559B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804559BC: jal         0x804449C0
    // 0x804559C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804449C0(rdram, ctx);
        goto after_0;
    // 0x804559C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804559C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804559C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804559CC: jal         0x80450490
    // 0x804559D0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_1;
    // 0x804559D0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_1:
    // 0x804559D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804559D8: jal         0x8044FEF4
    // 0x804559DC: lui         $a1, 0x4313
    ctx->r5 = S32(0X4313 << 16);
    func_8044FEF4(rdram, ctx);
        goto after_2;
    // 0x804559DC: lui         $a1, 0x4313
    ctx->r5 = S32(0X4313 << 16);
    after_2:
    // 0x804559E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804559E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804559E8: jr          $ra
    // 0x804559EC: nop

    return;
    // 0x804559EC: nop

;}
RECOMP_FUNC void func_80065388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006538C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065390: jal         0x80065368
    // 0x80065394: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    func_80065368(rdram, ctx);
        goto after_0;
    // 0x80065394: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80065398: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8006539C: jal         0x80065368
    // 0x800653A0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_80065368(rdram, ctx);
        goto after_1;
    // 0x800653A0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800653A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800653A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800653AC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800653B0: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800653B4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800653B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800653BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800653C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800653C4: jr          $ra
    // 0x800653C8: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    return;
    // 0x800653C8: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
;}
RECOMP_FUNC void func_804B98E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B98E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B98EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B98F0: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804B98F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804B98F8: beq         $t6, $zero, L_804B9934
    if (ctx->r14 == 0) {
        // 0x804B98FC: nop
    
            goto L_804B9934;
    }
    // 0x804B98FC: nop

    // 0x804B9900: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B9904: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804B9908: jalr        $t9
    // 0x804B990C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804B990C: nop

    after_0:
    // 0x804B9910: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B9914: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804B9918: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804B991C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804B9920: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804B9924: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804B9928: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804B992C: b           L_804B9934
    // 0x804B9930: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804B9934;
    // 0x804B9930: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804B9934:
    // 0x804B9934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B9938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B993C: jr          $ra
    // 0x804B9940: nop

    return;
    // 0x804B9940: nop

;}
RECOMP_FUNC void func_804215E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804215E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804215EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804215F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804215F4: jal         0x80045A34
    // 0x804215F8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804215F8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_0:
    // 0x804215FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80421600: bne         $v0, $zero, L_80421610
    if (ctx->r2 != 0) {
        // 0x80421604: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80421610;
    }
    // 0x80421604: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80421608: b           L_80421680
    // 0x8042160C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80421680;
    // 0x8042160C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80421610:
    // 0x80421610: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80421614: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80421618: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8042161C: sw          $zero, 0x10($t6)
    MEM_W(0X10, ctx->r14) = 0;
    // 0x80421620: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80421624: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80421628: lui         $t1, 0x8042
    ctx->r9 = S32(RELOC_HI16(32, 0X16CC) << 16);
    // 0x8042162C: addiu       $t1, $t1, 0x278C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(32, 0X16CC));
    // 0x80421630: swc1        $f4, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f4.u32l;
    // 0x80421634: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x80421638: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8042163C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80421640: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80421644: swc1        $f6, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f6.u32l;
    // 0x80421648: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042164C: lwc1        $f8, 0x74($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X74);
    // 0x80421650: swc1        $f8, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f8.u32l;
    // 0x80421654: lw          $t2, 0x16C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X16C);
    // 0x80421658: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x8042165C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80421660: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80421664: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80421668: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8042166C: jal         0x80421690
    // 0x80421670: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80421690(rdram, ctx);
        goto after_1;
    // 0x80421670: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80421674: jal         0x804215D0
    // 0x80421678: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804215D0(rdram, ctx);
        goto after_2;
    // 0x80421678: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8042167C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80421680:
    // 0x80421680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80421684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80421688: jr          $ra
    // 0x8042168C: nop

    return;
    // 0x8042168C: nop

;}
RECOMP_FUNC void func_80051200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051200: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80051204: lw          $v1, -0x7B2C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7B2C);
    // 0x80051208: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005120C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80051210: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80051214: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x80051218: beql        $a1, $zero, L_80051250
    if (ctx->r5 == 0) {
        // 0x8005121C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80051250;
    }
    goto skip_0;
    // 0x8005121C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80051220:
    // 0x80051220: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80051224: beq         $v1, $zero, L_80051244
    if (ctx->r3 == 0) {
        // 0x80051228: nop
    
            goto L_80051244;
    }
    // 0x80051228: nop

    // 0x8005122C: lhu         $t6, 0x3C($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X3C);
    // 0x80051230: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80051234: bne         $a0, $t6, L_80051244
    if (ctx->r4 != ctx->r14) {
        // 0x80051238: nop
    
            goto L_80051244;
    }
    // 0x80051238: nop

    // 0x8005123C: jr          $ra
    // 0x80051240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80051240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80051244:
    // 0x80051244: bne         $a1, $zero, L_80051220
    if (ctx->r5 != 0) {
        // 0x80051248: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80051220;
    }
    // 0x80051248: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8005124C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80051250:
    // 0x80051250: jr          $ra
    // 0x80051254: nop

    return;
    // 0x80051254: nop

;}
RECOMP_FUNC void func_807AF9F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF9F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AF9F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AF9F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807AF9FC: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(868, 0X2AC) << 16);
    // 0x807AFA00: addiu       $t6, $t6, -0x764
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(868, 0X2AC));
    // 0x807AFA04: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x807AFA08: sb          $v0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r2;
    // 0x807AFA0C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807AFA10: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x807AFA14: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x807AFA18: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x807AFA1C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807AFA20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807AFA24: jal         0x807AF8EC
    // 0x807AFA28: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    func_807AF8EC(rdram, ctx);
        goto after_0;
    // 0x807AFA28: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    after_0:
    // 0x807AFA2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AFA30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AFA34: jr          $ra
    // 0x807AFA38: nop

    return;
    // 0x807AFA38: nop

;}
RECOMP_FUNC void func_805D1E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1E54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805D1E58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805D1E5C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x805D1E60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805D1E64: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805D1E68: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x805D1E6C: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(471, 0X2A10) << 16);
    // 0x805D1E70: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x805D1E74: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x805D1E78: addiu       $a0, $a0, 0x4440
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(471, 0X2A10));
    // 0x805D1E7C: lui         $a1, 0x4526
    ctx->r5 = S32(0X4526 << 16);
    // 0x805D1E80: jal         0x80046804
    // 0x805D1E84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x805D1E84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x805D1E88: bne         $v0, $zero, L_805D1E98
    if (ctx->r2 != 0) {
        // 0x805D1E8C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805D1E98;
    }
    // 0x805D1E8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805D1E90: b           L_805D1EC8
    // 0x805D1E94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805D1EC8;
    // 0x805D1E94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D1E98:
    // 0x805D1E98: jal         0x80047090
    // 0x805D1E9C: addiu       $a0, $zero, 0x4526
    ctx->r4 = ADD32(0, 0X4526);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x805D1E9C: addiu       $a0, $zero, 0x4526
    ctx->r4 = ADD32(0, 0X4526);
    after_1:
    // 0x805D1EA0: lhu         $t9, 0xE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XE);
    // 0x805D1EA4: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x805D1EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D1EAC: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x805D1EB0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x805D1EB4: jal         0x80044194
    // 0x805D1EB8: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805D1EB8: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    after_2:
    // 0x805D1EBC: jal         0x80052BA4
    // 0x805D1EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_3;
    // 0x805D1EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805D1EC4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_805D1EC8:
    // 0x805D1EC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805D1ECC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805D1ED0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805D1ED4: jr          $ra
    // 0x805D1ED8: nop

    return;
    // 0x805D1ED8: nop

;}
RECOMP_FUNC void func_80433C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433C0C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80433C10: lw          $t6, 0xF2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF2C);
    // 0x80433C14: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80433C18: slti        $at, $t7, 0x32
    ctx->r1 = SIGNED(ctx->r15) < 0X32 ? 1 : 0;
    // 0x80433C1C: bne         $at, $zero, L_80433C28
    if (ctx->r1 != 0) {
        // 0x80433C20: sw          $t7, 0xF2C($v0)
        MEM_W(0XF2C, ctx->r2) = ctx->r15;
            goto L_80433C28;
    }
    // 0x80433C20: sw          $t7, 0xF2C($v0)
    MEM_W(0XF2C, ctx->r2) = ctx->r15;
    // 0x80433C24: sw          $zero, 0xF2C($v0)
    MEM_W(0XF2C, ctx->r2) = 0;
L_80433C28:
    // 0x80433C28: jr          $ra
    // 0x80433C2C: nop

    return;
    // 0x80433C2C: nop

;}
RECOMP_FUNC void func_8066A46C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A46C: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8066A470: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8066A474: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8066A478: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8066A47C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8066A480: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8066A484: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8066A488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8066A48C: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8066A490: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8066A494: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x8066A498: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8066A49C: nop

    // 0x8066A4A0: bc1f        L_8066A4AC
    if (!c1cs) {
        // 0x8066A4A4: nop
    
            goto L_8066A4AC;
    }
    // 0x8066A4A4: nop

    // 0x8066A4A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8066A4AC:
    // 0x8066A4AC: jr          $ra
    // 0x8066A4B0: nop

    return;
    // 0x8066A4B0: nop

;}
RECOMP_FUNC void func_807B0E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B0E8C: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x807B0E90: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x807B0E94: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x807B0E98: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x807B0E9C: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x807B0EA0: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x807B0EA4: bne         $at, $zero, L_807B0ECC
    if (ctx->r1 != 0) {
        // 0x807B0EA8: nop
    
            goto L_807B0ECC;
    }
    // 0x807B0EA8: nop

    // 0x807B0EAC: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x807B0EB0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x807B0EB4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x807B0EB8: bne         $v0, $at, L_807B0EC8
    if (ctx->r2 != ctx->r1) {
        // 0x807B0EBC: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_807B0EC8;
    }
    // 0x807B0EBC: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x807B0EC0: jr          $ra
    // 0x807B0EC4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    return;
    // 0x807B0EC4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_807B0EC8:
    // 0x807B0EC8: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
L_807B0ECC:
    // 0x807B0ECC: jr          $ra
    // 0x807B0ED0: nop

    return;
    // 0x807B0ED0: nop

;}
RECOMP_FUNC void func_805C6AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C6AF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805C6AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805C6AF8: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C6AFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805C6B00: jal         0x805C6A70
    // 0x805C6B04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_805C6A70(rdram, ctx);
        goto after_0;
    // 0x805C6B04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x805C6B08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805C6B0C: bne         $v0, $zero, L_805C6B58
    if (ctx->r2 != 0) {
        // 0x805C6B10: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_805C6B58;
    }
    // 0x805C6B10: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805C6B14: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x805C6B18: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x805C6B1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C6B20: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x805C6B24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805C6B28: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x805C6B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805C6B30: bc1fl       L_805C6B5C
    if (!c1cs) {
        // 0x805C6B34: lui         $at, 0x43E7
        ctx->r1 = S32(0X43E7 << 16);
            goto L_805C6B5C;
    }
    goto skip_0;
    // 0x805C6B34: lui         $at, 0x43E7
    ctx->r1 = S32(0X43E7 << 16);
    skip_0:
    // 0x805C6B38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805C6B3C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x805C6B40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C6B44: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x805C6B48: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x805C6B4C: swc1        $f8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f8.u32l;
    // 0x805C6B50: b           L_805C6BB4
    // 0x805C6B54: sw          $t6, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->r14;
        goto L_805C6BB4;
    // 0x805C6B54: sw          $t6, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->r14;
L_805C6B58:
    // 0x805C6B58: lui         $at, 0x43E7
    ctx->r1 = S32(0X43E7 << 16);
L_805C6B5C:
    // 0x805C6B5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805C6B60: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805C6B64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C6B68: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x805C6B6C: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x805C6B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805C6B74: bc1fl       L_805C6BB4
    if (!c1cs) {
        // 0x805C6B78: sw          $zero, 0x5C($a1)
        MEM_W(0X5C, ctx->r5) = 0;
            goto L_805C6BB4;
    }
    goto skip_1;
    // 0x805C6B78: sw          $zero, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = 0;
    skip_1:
    // 0x805C6B7C: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x805C6B80: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x805C6B84: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x805C6B88: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x805C6B8C: nop

    // 0x805C6B90: bc1fl       L_805C6BB4
    if (!c1cs) {
        // 0x805C6B94: sw          $zero, 0x5C($a1)
        MEM_W(0X5C, ctx->r5) = 0;
            goto L_805C6BB4;
    }
    goto skip_2;
    // 0x805C6B94: sw          $zero, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = 0;
    skip_2:
    // 0x805C6B98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805C6B9C: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
    // 0x805C6BA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x805C6BA4: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x805C6BA8: b           L_805C6BB4
    // 0x805C6BAC: sw          $t7, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->r15;
        goto L_805C6BB4;
    // 0x805C6BAC: sw          $t7, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->r15;
    // 0x805C6BB0: sw          $zero, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = 0;
L_805C6BB4:
    // 0x805C6BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805C6BB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805C6BBC: jr          $ra
    // 0x805C6BC0: nop

    return;
    // 0x805C6BC0: nop

;}
RECOMP_FUNC void func_80581A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581A70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80581A74: jal         0x80045A34
    // 0x80581A78: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80581A78: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80581A7C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80581A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80581A84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80581A88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80581A8C: jal         0x800657CC
    // 0x80581A90: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x80581A90: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    after_1:
    // 0x80581A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80581A98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581A9C: jr          $ra
    // 0x80581AA0: nop

    return;
    // 0x80581AA0: nop

;}
RECOMP_FUNC void func_8058402C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058402C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80584030: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80584034: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A380) << 16);
    // 0x80584038: lwc1        $f4, -0x1FC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A380));
    // 0x8058403C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80584040: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80584044: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80584048: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8058404C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80584050: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80584054: addiu       $t6, $zero, 0x1D10
    ctx->r14 = ADD32(0, 0X1D10);
    // 0x80584058: addiu       $t7, $zero, 0x1DC4
    ctx->r15 = ADD32(0, 0X1DC4);
    // 0x8058405C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80584060: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80584064: addiu       $a2, $zero, 0x1A4
    ctx->r6 = ADD32(0, 0X1A4);
    // 0x80584068: addiu       $a3, $zero, 0x1C98
    ctx->r7 = ADD32(0, 0X1C98);
    // 0x8058406C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80584070: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80584074: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x80584078: jal         0x80583D88
    // 0x8058407C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_80583D88(rdram, ctx);
        goto after_0;
    // 0x8058407C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80584080: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80584084: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80584088: addiu       $t9, $zero, 0x1DC4
    ctx->r25 = ADD32(0, 0X1DC4);
    // 0x8058408C: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x80584090: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80584094: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80584098: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8058409C: addiu       $a2, $zero, 0x1A4
    ctx->r6 = ADD32(0, 0X1A4);
    // 0x805840A0: addiu       $a3, $zero, 0x1D10
    ctx->r7 = ADD32(0, 0X1D10);
    // 0x805840A4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x805840A8: jal         0x80583CCC
    // 0x805840AC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_80583CCC(rdram, ctx);
        goto after_1;
    // 0x805840AC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x805840B0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x805840B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805840B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805840BC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805840C0: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x805840C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x805840C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805840CC: jr          $ra
    // 0x805840D0: nop

    return;
    // 0x805840D0: nop

;}
RECOMP_FUNC void func_807A5D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A5D00: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(847, 0X1480) << 16);
    // 0x807A5D04: lbu         $t6, 0x7180($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(847, 0X1480));
    // 0x807A5D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A5D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A5D10: bne         $t6, $zero, L_807A5D3C
    if (ctx->r14 != 0) {
        // 0x807A5D14: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_807A5D3C;
    }
    // 0x807A5D14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807A5D18: lui         $a0, 0x807A
    ctx->r4 = S32(RELOC_HI16(847, 0X18B0) << 16);
    // 0x807A5D1C: lui         $a1, 0x807A
    ctx->r5 = S32(RELOC_HI16(847, 0X18C0) << 16);
    // 0x807A5D20: addiu       $a1, $a1, 0x75C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(847, 0X18C0));
    // 0x807A5D24: addiu       $a0, $a0, 0x75B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(847, 0X18B0));
    // 0x807A5D28: jal         0x8004667C
    // 0x807A5D2C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x807A5D2C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_0:
    // 0x807A5D30: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807A5D34: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1480) << 16);
    // 0x807A5D38: sb          $t7, 0x7180($at)
    MEM_B((int16_t)RELOC_LO16(847, 0X1480), ctx->r1) = ctx->r15;
L_807A5D3C:
    // 0x807A5D3C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x807A5D40: addiu       $at, $zero, 0x46E5
    ctx->r1 = ADD32(0, 0X46E5);
    // 0x807A5D44: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
    // 0x807A5D48: beq         $v0, $at, L_807A5D7C
    if (ctx->r2 == ctx->r1) {
        // 0x807A5D4C: addiu       $at, $zero, 0x46E6
        ctx->r1 = ADD32(0, 0X46E6);
            goto L_807A5D7C;
    }
    // 0x807A5D4C: addiu       $at, $zero, 0x46E6
    ctx->r1 = ADD32(0, 0X46E6);
    // 0x807A5D50: beq         $v0, $at, L_807A5DA0
    if (ctx->r2 == ctx->r1) {
        // 0x807A5D54: lui         $t9, 0x807A
        ctx->r25 = S32(RELOC_HI16(847, 0XB80) << 16);
            goto L_807A5DA0;
    }
    // 0x807A5D54: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(847, 0XB80) << 16);
    // 0x807A5D58: addiu       $at, $zero, 0x46E7
    ctx->r1 = ADD32(0, 0X46E7);
    // 0x807A5D5C: beq         $v0, $at, L_807A5D94
    if (ctx->r2 == ctx->r1) {
        // 0x807A5D60: addiu       $at, $zero, 0x46E8
        ctx->r1 = ADD32(0, 0X46E8);
            goto L_807A5D94;
    }
    // 0x807A5D60: addiu       $at, $zero, 0x46E8
    ctx->r1 = ADD32(0, 0X46E8);
    // 0x807A5D64: beq         $v0, $at, L_807A5D88
    if (ctx->r2 == ctx->r1) {
        // 0x807A5D68: addiu       $at, $zero, 0x471A
        ctx->r1 = ADD32(0, 0X471A);
            goto L_807A5D88;
    }
    // 0x807A5D68: addiu       $at, $zero, 0x471A
    ctx->r1 = ADD32(0, 0X471A);
    // 0x807A5D6C: beq         $v0, $at, L_807A5DA0
    if (ctx->r2 == ctx->r1) {
        // 0x807A5D70: nop
    
            goto L_807A5DA0;
    }
    // 0x807A5D70: nop

    // 0x807A5D74: b           L_807A5DB8
    // 0x807A5D78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A5DB8;
    // 0x807A5D78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A5D7C:
    // 0x807A5D7C: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(847, 0X13DC) << 16);
    // 0x807A5D80: b           L_807A5DB8
    // 0x807A5D84: addiu       $v0, $v0, 0x70DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(847, 0X13DC));
        goto L_807A5DB8;
    // 0x807A5D84: addiu       $v0, $v0, 0x70DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(847, 0X13DC));
L_807A5D88:
    // 0x807A5D88: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(847, 0X320) << 16);
    // 0x807A5D8C: b           L_807A5DB8
    // 0x807A5D90: addiu       $v0, $v0, 0x6020
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(847, 0X320));
        goto L_807A5DB8;
    // 0x807A5D90: addiu       $v0, $v0, 0x6020
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(847, 0X320));
L_807A5D94:
    // 0x807A5D94: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(847, 0XD64) << 16);
    // 0x807A5D98: b           L_807A5DB8
    // 0x807A5D9C: addiu       $v0, $v0, 0x6A64
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(847, 0XD64));
        goto L_807A5DB8;
    // 0x807A5D9C: addiu       $v0, $v0, 0x6A64
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(847, 0XD64));
L_807A5DA0:
    // 0x807A5DA0: addiu       $t9, $t9, 0x6880
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(847, 0XB80));
    // 0x807A5DA4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807A5DA8: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(847, 0XA10) << 16);
    // 0x807A5DAC: sw          $t9, -0x7284($at)
    MEM_W(-0X7284, ctx->r1) = ctx->r25;
    // 0x807A5DB0: b           L_807A5DB8
    // 0x807A5DB4: addiu       $v0, $v0, 0x6710
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(847, 0XA10));
        goto L_807A5DB8;
    // 0x807A5DB4: addiu       $v0, $v0, 0x6710
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(847, 0XA10));
L_807A5DB8:
    // 0x807A5DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A5DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A5DC0: jr          $ra
    // 0x807A5DC4: nop

    return;
    // 0x807A5DC4: nop

;}
RECOMP_FUNC void func_805743C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805743C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805743CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805743D0: lh          $t6, 0x144($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X144);
    // 0x805743D4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x805743D8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805743DC: bnel        $t6, $at, L_80574400
    if (ctx->r14 != ctx->r1) {
        // 0x805743E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80574400;
    }
    goto skip_0;
    // 0x805743E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805743E4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805743E8: jal         0x80067BBC
    // 0x805743EC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805743EC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_0:
    // 0x805743F0: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    // 0x805743F4: jal         0x80067818
    // 0x805743F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805743F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805743FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80574400:
    // 0x80574400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80574404: jr          $ra
    // 0x80574408: nop

    return;
    // 0x80574408: nop

;}
RECOMP_FUNC void func_804CC1B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC1B8: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x804CC1BC: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x804CC1C0: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x804CC1C4: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x804CC1C8: andi        $t8, $t7, 0xC00
    ctx->r24 = ctx->r15 & 0XC00;
    // 0x804CC1CC: beq         $t8, $zero, L_804CC2A4
    if (ctx->r24 == 0) {
        // 0x804CC1D0: nop
    
            goto L_804CC2A4;
    }
    // 0x804CC1D0: nop

    // 0x804CC1D4: lw          $t9, 0x1E0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1E0);
    // 0x804CC1D8: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x804CC1DC: addiu       $t0, $zero, 0x800
    ctx->r8 = ADD32(0, 0X800);
    // 0x804CC1E0: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x804CC1E4: sw          $t1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r9;
    // 0x804CC1E8: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x804CC1EC: addiu       $t3, $zero, 0x21
    ctx->r11 = ADD32(0, 0X21);
    // 0x804CC1F0: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x804CC1F4: lhu         $a2, 0xC($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0XC);
    // 0x804CC1F8: andi        $t2, $a2, 0x800
    ctx->r10 = ctx->r6 & 0X800;
    // 0x804CC1FC: bne         $t0, $t2, L_804CC214
    if (ctx->r8 != ctx->r10) {
        // 0x804CC200: andi        $t4, $a2, 0x400
        ctx->r12 = ctx->r6 & 0X400;
            goto L_804CC214;
    }
    // 0x804CC200: andi        $t4, $a2, 0x400
    ctx->r12 = ctx->r6 & 0X400;
    // 0x804CC204: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x804CC208: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x804CC20C: b           L_804CC26C
    // 0x804CC210: sw          $t3, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r11;
        goto L_804CC26C;
    // 0x804CC210: sw          $t3, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r11;
L_804CC214:
    // 0x804CC214: bne         $t4, $at, L_804CC22C
    if (ctx->r12 != ctx->r1) {
        // 0x804CC218: addiu       $t5, $zero, 0x21
        ctx->r13 = ADD32(0, 0X21);
            goto L_804CC22C;
    }
    // 0x804CC218: addiu       $t5, $zero, 0x21
    ctx->r13 = ADD32(0, 0X21);
    // 0x804CC21C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x804CC220: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x804CC224: b           L_804CC26C
    // 0x804CC228: sw          $t5, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r13;
        goto L_804CC26C;
    // 0x804CC228: sw          $t5, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r13;
L_804CC22C:
    // 0x804CC22C: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x804CC230: bnel        $t6, $zero, L_804CC270
    if (ctx->r14 != 0) {
        // 0x804CC234: slti        $at, $v1, 0x51
        ctx->r1 = SIGNED(ctx->r3) < 0X51 ? 1 : 0;
            goto L_804CC270;
    }
    goto skip_0;
    // 0x804CC234: slti        $at, $v1, 0x51
    ctx->r1 = SIGNED(ctx->r3) < 0X51 ? 1 : 0;
    skip_0:
    // 0x804CC238: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x804CC23C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x804CC240: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x804CC244: andi        $t8, $t7, 0x800
    ctx->r24 = ctx->r15 & 0X800;
    // 0x804CC248: bnel        $t0, $t8, L_804CC264
    if (ctx->r8 != ctx->r24) {
        // 0x804CC24C: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_804CC264;
    }
    goto skip_1;
    // 0x804CC24C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_1:
    // 0x804CC250: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x804CC254: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x804CC258: b           L_804CC26C
    // 0x804CC25C: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
        goto L_804CC26C;
    // 0x804CC25C: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
    // 0x804CC260: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_804CC264:
    // 0x804CC264: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x804CC268: sw          $t1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r9;
L_804CC26C:
    // 0x804CC26C: slti        $at, $v1, 0x51
    ctx->r1 = SIGNED(ctx->r3) < 0X51 ? 1 : 0;
L_804CC270:
    // 0x804CC270: bne         $at, $zero, L_804CC280
    if (ctx->r1 != 0) {
        // 0x804CC274: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_804CC280;
    }
    // 0x804CC274: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x804CC278: b           L_804CC2A0
    // 0x804CC27C: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
        goto L_804CC2A0;
    // 0x804CC27C: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
L_804CC280:
    // 0x804CC280: slti        $at, $v0, 0x51
    ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
    // 0x804CC284: beq         $at, $zero, L_804CC294
    if (ctx->r1 == 0) {
        // 0x804CC288: slti        $at, $v0, 0xB
        ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
            goto L_804CC294;
    }
    // 0x804CC288: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x804CC28C: beq         $at, $zero, L_804CC29C
    if (ctx->r1 == 0) {
        // 0x804CC290: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804CC29C;
    }
    // 0x804CC290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_804CC294:
    // 0x804CC294: b           L_804CC29C
    // 0x804CC298: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
        goto L_804CC29C;
    // 0x804CC298: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
L_804CC29C:
    // 0x804CC29C: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
L_804CC2A0:
    // 0x804CC2A0: sb          $v1, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r3;
L_804CC2A4:
    // 0x804CC2A4: jr          $ra
    // 0x804CC2A8: nop

    return;
    // 0x804CC2A8: nop

;}
RECOMP_FUNC void func_804B65FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B65FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B6604: jal         0x8004700C
    // 0x804B6608: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804B6608: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B660C: beq         $v0, $zero, L_804B6650
    if (ctx->r2 == 0) {
        // 0x804B6610: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804B6650;
    }
    // 0x804B6610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6614: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x804B6618: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804B661C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x804B6620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6624: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804B6628: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804B662C: bc1f        L_804B6648
    if (!c1cs) {
        // 0x804B6630: nop
    
            goto L_804B6648;
    }
    // 0x804B6630: nop

    // 0x804B6634: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6638: jal         0x804B6FF0
    // 0x804B663C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804B6FF0(rdram, ctx);
        goto after_1;
    // 0x804B663C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x804B6640: b           L_804B6654
    // 0x804B6644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804B6654;
    // 0x804B6644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804B6648:
    // 0x804B6648: jal         0x804B6FF0
    // 0x804B664C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_2;
    // 0x804B664C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
L_804B6650:
    // 0x804B6650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804B6654:
    // 0x804B6654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B6658: jr          $ra
    // 0x804B665C: nop

    return;
    // 0x804B665C: nop

;}
RECOMP_FUNC void func_80049180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80049188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004918C: addiu       $a0, $a1, 0x2
    ctx->r4 = ADD32(ctx->r5, 0X2);
    // 0x80049190: jal         0x800490A8
    // 0x80049194: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800490A8(rdram, ctx);
        goto after_0;
    // 0x80049194: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_0:
    // 0x80049198: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8004919C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800491A0: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800491A4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x800491A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800491AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800491B0: jr          $ra
    // 0x800491B4: nop

    return;
    // 0x800491B4: nop

;}
RECOMP_FUNC void func_8003E968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E968: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003E96C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003E970: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003E974: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003E978: lw          $t6, 0x1EC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1EC);
    // 0x8003E97C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003E980: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8003E984: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8003E988: lw          $t7, 0x16C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X16C);
    // 0x8003E98C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8003E990: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8003E994: jal         0x8005FE48
    // 0x8003E998: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x8003E998: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_0:
    // 0x8003E99C: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x8003E9A0: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8003E9A4: addiu       $a1, $s1, 0x3C
    ctx->r5 = ADD32(ctx->r17, 0X3C);
    // 0x8003E9A8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8003E9AC: jal         0x80065490
    // 0x8003E9B0: sw          $zero, 0x44($t0)
    MEM_W(0X44, ctx->r8) = 0;
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8003E9B0: sw          $zero, 0x44($t0)
    MEM_W(0X44, ctx->r8) = 0;
    after_1:
    // 0x8003E9B4: lw          $t1, 0x1EC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1EC);
    // 0x8003E9B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003E9BC: sw          $t1, 0x1EC($s1)
    MEM_W(0X1EC, ctx->r17) = ctx->r9;
    // 0x8003E9C0: lw          $t2, 0x16C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X16C);
    // 0x8003E9C4: jal         0x8004590C
    // 0x8003E9C8: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    func_8004590C(rdram, ctx);
        goto after_2;
    // 0x8003E9C8: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    after_2:
    // 0x8003E9CC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8003E9D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E9D4: sw          $t3, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r11;
    // 0x8003E9D8: jal         0x8004590C
    // 0x8003E9DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8004590C(rdram, ctx);
        goto after_3;
    // 0x8003E9DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8003E9E0: addiu       $a1, $s1, 0x6C
    ctx->r5 = ADD32(ctx->r17, 0X6C);
    // 0x8003E9E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003E9E8: jal         0x80065490
    // 0x8003E9EC: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    func_80065490(rdram, ctx);
        goto after_4;
    // 0x8003E9EC: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    after_4:
    // 0x8003E9F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003E9F4: jal         0x80065490
    // 0x8003E9F8: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    func_80065490(rdram, ctx);
        goto after_5;
    // 0x8003E9F8: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    after_5:
    // 0x8003E9FC: jal         0x8003AE00
    // 0x8003EA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003AE00(rdram, ctx);
        goto after_6;
    // 0x8003EA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8003EA04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003EA08: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003EA0C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003EA10: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003EA14: jr          $ra
    // 0x8003EA18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8003EA18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_807AE930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE930: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AE934: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AE938: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x807AE93C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807AE940: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x807AE944: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x807AE948: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x807AE94C: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x807AE950: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x807AE954: jr          $ra
    // 0x807AE958: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x807AE958: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_806B1428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B142C: beq         $a1, $zero, L_806B1448
    if (ctx->r5 == 0) {
        // 0x806B1430: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_806B1448;
    }
    // 0x806B1430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B1434: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806B1438: beq         $a1, $at, L_806B1458
    if (ctx->r5 == ctx->r1) {
        // 0x806B143C: nop
    
            goto L_806B1458;
    }
    // 0x806B143C: nop

    // 0x806B1440: b           L_806B1464
    // 0x806B1444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806B1464;
    // 0x806B1444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B1448:
    // 0x806B1448: jal         0x806B12FC
    // 0x806B144C: nop

    func_806B12FC(rdram, ctx);
        goto after_0;
    // 0x806B144C: nop

    after_0:
    // 0x806B1450: b           L_806B1464
    // 0x806B1454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806B1464;
    // 0x806B1454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B1458:
    // 0x806B1458: jal         0x806B10F4
    // 0x806B145C: nop

    func_806B10F4(rdram, ctx);
        goto after_1;
    // 0x806B145C: nop

    after_1:
    // 0x806B1460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B1464:
    // 0x806B1464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B1468: jr          $ra
    // 0x806B146C: nop

    return;
    // 0x806B146C: nop

;}
RECOMP_FUNC void func_806B285C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B285C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2860: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2864: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2868: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B286C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2870: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2874: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2878: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B287C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2880: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2884: jr          $ra
    // 0x806B2888: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2888: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80563100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80563100: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80563104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80563108: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8056310C: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80563110: jal         0x8004700C
    // 0x80563114: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80563114: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80563118: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8056311C: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80563120: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80563124: beq         $v0, $zero, L_80563368
    if (ctx->r2 == 0) {
        // 0x80563128: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80563368;
    }
    // 0x80563128: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8056312C: lw          $a0, 0x174($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X174);
    // 0x80563130: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80563134: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80563138: lh          $t8, 0xC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XC);
    // 0x8056313C: lw          $t7, 0x70($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X70);
    // 0x80563140: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80563144: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80563148: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8056314C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80563150: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80563154: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80563158: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8056315C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80563160: nop

    // 0x80563164: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80563168: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8056316C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80563170: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80563174: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80563178: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8056317C: lw          $t2, 0x180($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X180);
    // 0x80563180: bnel        $t2, $zero, L_8056336C
    if (ctx->r10 != 0) {
        // 0x80563184: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8056336C;
    }
    goto skip_0;
    // 0x80563184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80563188: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x8056318C: andi        $t4, $t3, 0xF00
    ctx->r12 = ctx->r11 & 0XF00;
    // 0x80563190: bnel        $t4, $zero, L_8056336C
    if (ctx->r12 != 0) {
        // 0x80563194: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8056336C;
    }
    goto skip_1;
    // 0x80563194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80563198: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8056319C: lwc1        $f10, 0xC8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x805631A0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x805631A4: nop

    // 0x805631A8: bc1fl       L_8056336C
    if (!c1cs) {
        // 0x805631AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8056336C;
    }
    goto skip_2;
    // 0x805631AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x805631B0: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x805631B4: addiu       $a1, $a2, 0x6C0
    ctx->r5 = ADD32(ctx->r6, 0X6C0);
    // 0x805631B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x805631BC: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x805631C0: lw          $t5, 0x174($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X174);
    // 0x805631C4: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x805631C8: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x805631CC: lw          $t6, 0x70($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X70);
    // 0x805631D0: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x805631D4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x805631D8: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x805631DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805631E0: lwc1        $f8, 0x88($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
    // 0x805631E4: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x805631E8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x805631EC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x805631F0: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x805631F4: lwc1        $f10, 0x84($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X84);
    // 0x805631F8: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x805631FC: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80563200: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80563204: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80563208: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8056320C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80563210: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80563214: nop

    // 0x80563218: bc1fl       L_8056336C
    if (!c1cs) {
        // 0x8056321C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8056336C;
    }
    goto skip_3;
    // 0x8056321C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_80563220:
    // 0x80563220: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80563224: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80563228: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8056322C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80563230: nop

    // 0x80563234: bc1f        L_80563360
    if (!c1cs) {
        // 0x80563238: nop
    
            goto L_80563360;
    }
    // 0x80563238: nop

    // 0x8056323C: lwc1        $f2, -0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X8);
    // 0x80563240: lwc1        $f12, -0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80563244: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80563248: sub.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8056324C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80563250: sub.s       $f16, $f12, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80563254: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80563258: div.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8056325C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80563260: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80563264: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80563268: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8056326C: sub.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80563270: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80563274: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80563278: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8056327C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80563280: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80563284: c.le.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl <= ctx->f18.fl;
    // 0x80563288: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8056328C: bc1fl       L_8056336C
    if (!c1cs) {
        // 0x80563290: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8056336C;
    }
    goto skip_4;
    // 0x80563290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80563294: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80563298: nop

    // 0x8056329C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x805632A0: c.le.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x805632A4: nop

    // 0x805632A8: bc1fl       L_8056336C
    if (!c1cs) {
        // 0x805632AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8056336C;
    }
    goto skip_5;
    // 0x805632AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x805632B0: lw          $t8, 0x714($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X714);
    // 0x805632B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805632B8: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x805632BC: bne         $t8, $zero, L_805632C8
    if (ctx->r24 != 0) {
        // 0x805632C0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_805632C8;
    }
    // 0x805632C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805632C4: swc1        $f10, 0x728($a2)
    MEM_W(0X728, ctx->r6) = ctx->f10.u32l;
L_805632C8:
    // 0x805632C8: lwc1        $f4, 0xC4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x805632CC: addiu       $a1, $t1, 0xC4
    ctx->r5 = ADD32(ctx->r9, 0XC4);
    // 0x805632D0: c.eq.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl == ctx->f4.fl;
    // 0x805632D4: nop

    // 0x805632D8: bc1fl       L_80563334
    if (!c1cs) {
        // 0x805632DC: lwc1        $f4, 0x44($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80563334;
    }
    goto skip_6;
    // 0x805632DC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    skip_6:
    // 0x805632E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805632E4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x805632E8: jal         0x80562B74
    // 0x805632EC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_80562B74(rdram, ctx);
        goto after_1;
    // 0x805632EC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x805632F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x805632F4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x805632F8: bne         $v0, $zero, L_80563330
    if (ctx->r2 != 0) {
        // 0x805632FC: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_80563330;
    }
    // 0x805632FC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80563300: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80563304: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80563308: jal         0x80562BC4
    // 0x8056330C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_80562BC4(rdram, ctx);
        goto after_2;
    // 0x8056330C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_2:
    // 0x80563310: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80563314: bne         $v0, $zero, L_80563330
    if (ctx->r2 != 0) {
        // 0x80563318: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_80563330;
    }
    // 0x80563318: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8056331C: lwc1        $f8, 0x728($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X728);
    // 0x80563320: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80563324: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80563328: b           L_80563338
    // 0x8056332C: swc1        $f6, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f6.u32l;
        goto L_80563338;
    // 0x8056332C: swc1        $f6, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f6.u32l;
L_80563330:
    // 0x80563330: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
L_80563334:
    // 0x80563334: swc1        $f4, 0x728($a2)
    MEM_W(0X728, ctx->r6) = ctx->f4.u32l;
L_80563338:
    // 0x80563338: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8056333C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80563340: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80563344: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80563348: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8056334C: swc1        $f6, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f6.u32l;
    // 0x80563350: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x80563354: ori         $t2, $t9, 0x700
    ctx->r10 = ctx->r25 | 0X700;
    // 0x80563358: b           L_80563368
    // 0x8056335C: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
        goto L_80563368;
    // 0x8056335C: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
L_80563360:
    // 0x80563360: bne         $a0, $a1, L_80563220
    if (ctx->r4 != ctx->r5) {
        // 0x80563364: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80563220;
    }
    // 0x80563364: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80563368:
    // 0x80563368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056336C:
    // 0x8056336C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80563370: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80563374: jr          $ra
    // 0x80563378: nop

    return;
    // 0x80563378: nop

;}
RECOMP_FUNC void func_8073FAC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073FAC4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073FAC8: lw          $v0, 0xC($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XC);
    // 0x8073FACC: jr          $ra
    // 0x8073FAD0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x8073FAD0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
RECOMP_FUNC void func_80521EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521EA0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80521EA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80521EA8: lwc1        $f4, 0xDC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x80521EAC: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x80521EB0: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x80521EB4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80521EB8: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80521EBC: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x80521EC0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80521EC4: sw          $t7, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r15;
    // 0x80521EC8: sw          $t9, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r25;
    // 0x80521ECC: jr          $ra
    // 0x80521ED0: swc1        $f8, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80521ED0: swc1        $f8, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80421E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421E90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80421E94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80421E98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80421E9C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80421EA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80421EA4: jal         0x80421C00
    // 0x80421EA8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80421C00(rdram, ctx);
        goto after_0;
    // 0x80421EA8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80421EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80421EB0: jal         0x80421C70
    // 0x80421EB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80421C70(rdram, ctx);
        goto after_1;
    // 0x80421EB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80421EB8: bnel        $v0, $zero, L_80421F44
    if (ctx->r2 != 0) {
        // 0x80421EBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80421F44;
    }
    goto skip_0;
    // 0x80421EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80421EC0: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x80421EC4: jal         0x80421A34
    // 0x80421EC8: addiu       $a0, $a0, 0x884
    ctx->r4 = ADD32(ctx->r4, 0X884);
    func_80421A34(rdram, ctx);
        goto after_2;
    // 0x80421EC8: addiu       $a0, $a0, 0x884
    ctx->r4 = ADD32(ctx->r4, 0X884);
    after_2:
    // 0x80421ECC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80421ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80421ED4: addiu       $a1, $v0, 0x888
    ctx->r5 = ADD32(ctx->r2, 0X888);
    // 0x80421ED8: jal         0x80421AB4
    // 0x80421EDC: lw          $a2, 0x890($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X890);
    func_80421AB4(rdram, ctx);
        goto after_3;
    // 0x80421EDC: lw          $a2, 0x890($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X890);
    after_3:
    // 0x80421EE0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80421EE4: jal         0x80048F84
    // 0x80421EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x80421EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80421EEC: jal         0x804216FC
    // 0x80421EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804216FC(rdram, ctx);
        goto after_5;
    // 0x80421EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80421EF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80421EF8: bne         $v0, $at, L_80421F38
    if (ctx->r2 != ctx->r1) {
        // 0x80421EFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80421F38;
    }
    // 0x80421EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80421F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80421F04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80421F08: jal         0x80422558
    // 0x80421F0C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80422558(rdram, ctx);
        goto after_6;
    // 0x80421F0C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_6:
    // 0x80421F10: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x80421F14: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80421F18: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(32, 0X1500) << 16);
    // 0x80421F1C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80421F20: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80421F24: lwc1        $f6, 0x25C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(32, 0X1500));
    // 0x80421F28: lwc1        $f4, 0x88C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X88C);
    // 0x80421F2C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80421F30: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x80421F34: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
L_80421F38:
    // 0x80421F38: jal         0x80421A4C
    // 0x80421F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80421A4C(rdram, ctx);
        goto after_7;
    // 0x80421F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80421F40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80421F44:
    // 0x80421F44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80421F48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80421F4C: jr          $ra
    // 0x80421F50: nop

    return;
    // 0x80421F50: nop

;}
RECOMP_FUNC void func_80715210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80715214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80715218: jal         0x80714DD4
    // 0x8071521C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80714DD4(rdram, ctx);
        goto after_0;
    // 0x8071521C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80715220: jal         0x80714E64
    // 0x80715224: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80714E64(rdram, ctx);
        goto after_1;
    // 0x80715224: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80715228: jal         0x80714D40
    // 0x8071522C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80714D40(rdram, ctx);
        goto after_2;
    // 0x8071522C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80715230: beq         $v0, $zero, L_80715248
    if (ctx->r2 == 0) {
        // 0x80715234: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80715248;
    }
    // 0x80715234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80715238: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8071523C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80715240: jal         0x80715C24
    // 0x80715244: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80715C24(rdram, ctx);
        goto after_3;
    // 0x80715244: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
L_80715248:
    // 0x80715248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8071524C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715250: jr          $ra
    // 0x80715254: nop

    return;
    // 0x80715254: nop

;}
RECOMP_FUNC void func_80446690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446690: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446694: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446698: ori         $at, $at, 0x6E2C
    ctx->r1 = ctx->r1 | 0X6E2C;
    // 0x8044669C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x804466A0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x804466A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_804466A8:
    // 0x804466A8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804466AC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x804466B0: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x804466B4: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x804466B8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x804466BC: bne         $a1, $v0, L_804466A8
    if (ctx->r5 != ctx->r2) {
        // 0x804466C0: sw          $zero, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = 0;
            goto L_804466A8;
    }
    // 0x804466C0: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x804466C4: jr          $ra
    // 0x804466C8: nop

    return;
    // 0x804466C8: nop

;}
RECOMP_FUNC void func_8046D0B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046D0B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046D0B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046D0B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046D0BC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8046D0C0: jal         0x80048F84
    // 0x8046D0C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8046D0C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8046D0C8: jal         0x8046C850
    // 0x8046D0CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8046C850(rdram, ctx);
        goto after_1;
    // 0x8046D0CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8046D0D0: beq         $v0, $zero, L_8046D0F0
    if (ctx->r2 == 0) {
        // 0x8046D0D4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8046D0F0;
    }
    // 0x8046D0D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046D0D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046D0DC: jal         0x8046D3E8
    // 0x8046D0E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8046D3E8(rdram, ctx);
        goto after_2;
    // 0x8046D0E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8046D0E4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8046D0E8: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x8046D0EC: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_8046D0F0:
    // 0x8046D0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046D0F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046D0F8: jr          $ra
    // 0x8046D0FC: nop

    return;
    // 0x8046D0FC: nop

;}
RECOMP_FUNC void func_80409918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409918: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8040991C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80409920: jr          $ra
    // 0x80409924: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80409924: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void func_805AAF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AAF8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805AAF90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805AAF94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805AAF98: lh          $a2, 0x184($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X184);
    // 0x805AAF9C: addiu       $a3, $a0, 0x188
    ctx->r7 = ADD32(ctx->r4, 0X188);
    // 0x805AAFA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805AAFA4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x805AAFA8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x805AAFAC: jal         0x80062684
    // 0x805AAFB0: sh          $a2, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r6;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x805AAFB0: sh          $a2, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r6;
    after_0:
    // 0x805AAFB4: lh          $a2, 0x2A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2A);
    // 0x805AAFB8: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x805AAFBC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x805AAFC0: beq         $a2, $zero, L_805AB08C
    if (ctx->r6 == 0) {
        // 0x805AAFC4: addiu       $t1, $t1, 0x7EA0
        ctx->r9 = ADD32(ctx->r9, 0X7EA0);
            goto L_805AB08C;
    }
    // 0x805AAFC4: addiu       $t1, $t1, 0x7EA0
    ctx->r9 = ADD32(ctx->r9, 0X7EA0);
    // 0x805AAFC8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805AAFCC: addiu       $a1, $zero, 0x4001
    ctx->r5 = ADD32(0, 0X4001);
L_805AAFD0:
    // 0x805AAFD0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x805AAFD4: beq         $v0, $zero, L_805AB084
    if (ctx->r2 == 0) {
        // 0x805AAFD8: nop
    
            goto L_805AB084;
    }
    // 0x805AAFD8: nop

    // 0x805AAFDC: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x805AAFE0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x805AAFE4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x805AAFE8: bne         $a1, $t6, L_805AB084
    if (ctx->r5 != ctx->r14) {
        // 0x805AAFEC: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_805AB084;
    }
    // 0x805AAFEC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x805AAFF0: lbu         $t7, 0x18($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18);
    // 0x805AAFF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805AAFF8: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x805AAFFC: bne         $t0, $t7, L_805AB084
    if (ctx->r8 != ctx->r15) {
        // 0x805AB000: nop
    
            goto L_805AB084;
    }
    // 0x805AB000: nop

    // 0x805AB004: lh          $t8, 0xAE0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0XAE0);
    // 0x805AB008: slti        $at, $t8, -0x27
    ctx->r1 = SIGNED(ctx->r24) < -0X27 ? 1 : 0;
    // 0x805AB00C: beq         $at, $zero, L_805AB084
    if (ctx->r1 == 0) {
        // 0x805AB010: nop
    
            goto L_805AB084;
    }
    // 0x805AB010: nop

    // 0x805AB014: lw          $t9, 0x12EC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X12EC);
    // 0x805AB018: bne         $t9, $zero, L_805AB084
    if (ctx->r25 != 0) {
        // 0x805AB01C: nop
    
            goto L_805AB084;
    }
    // 0x805AB01C: nop

    // 0x805AB020: lbu         $t2, 0xF4($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF4);
    // 0x805AB024: bne         $t2, $zero, L_805AB084
    if (ctx->r10 != 0) {
        // 0x805AB028: nop
    
            goto L_805AB084;
    }
    // 0x805AB028: nop

    // 0x805AB02C: lbu         $t3, 0x154($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X154);
    // 0x805AB030: bne         $t3, $zero, L_805AB084
    if (ctx->r11 != 0) {
        // 0x805AB034: nop
    
            goto L_805AB084;
    }
    // 0x805AB034: nop

    // 0x805AB038: lbu         $t4, 0x155($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X155);
    // 0x805AB03C: bne         $t4, $zero, L_805AB084
    if (ctx->r12 != 0) {
        // 0x805AB040: nop
    
            goto L_805AB084;
    }
    // 0x805AB040: nop

    // 0x805AB044: lbu         $t5, 0x1F8($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1F8);
    // 0x805AB048: bne         $t5, $zero, L_805AB084
    if (ctx->r13 != 0) {
        // 0x805AB04C: nop
    
            goto L_805AB084;
    }
    // 0x805AB04C: nop

    // 0x805AB050: jal         0x80061170
    // 0x805AB054: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80061170(rdram, ctx);
        goto after_1;
    // 0x805AB054: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x805AB058: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805AB05C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805AB060: lw          $a2, 0x88($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X88);
    // 0x805AB064: jal         0x8002F7AC
    // 0x805AB068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F7AC(rdram, ctx);
        goto after_2;
    // 0x805AB068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x805AB06C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AB070: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AB074: jal         0x805AB914
    // 0x805AB078: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805AB914(rdram, ctx);
        goto after_3;
    // 0x805AB078: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x805AB07C: b           L_805AB090
    // 0x805AB080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805AB090;
    // 0x805AB080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AB084:
    // 0x805AB084: bne         $a2, $zero, L_805AAFD0
    if (ctx->r6 != 0) {
        // 0x805AB088: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_805AAFD0;
    }
    // 0x805AB088: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_805AB08C:
    // 0x805AB08C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AB090:
    // 0x805AB090: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805AB094: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805AB098: jr          $ra
    // 0x805AB09C: nop

    return;
    // 0x805AB09C: nop

;}
RECOMP_FUNC void func_804BBB38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BBB38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BBB3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BBB40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804BBB44: jal         0x80045A34
    // 0x804BBB48: addiu       $a1, $zero, 0x378
    ctx->r5 = ADD32(0, 0X378);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804BBB48: addiu       $a1, $zero, 0x378
    ctx->r5 = ADD32(0, 0X378);
    after_0:
    // 0x804BBB4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BBB50: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X1E4) << 16);
    // 0x804BBB54: bne         $v0, $zero, L_804BBB64
    if (ctx->r2 != 0) {
        // 0x804BBB58: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804BBB64;
    }
    // 0x804BBB58: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804BBB5C: b           L_804BBB70
    // 0x804BBB60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BBB70;
    // 0x804BBB60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BBB64:
    // 0x804BBB64: addiu       $t6, $t6, -0x44EC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(191, 0X1E4));
    // 0x804BBB68: sw          $t6, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = ctx->r14;
    // 0x804BBB6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804BBB70:
    // 0x804BBB70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BBB74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BBB78: jr          $ra
    // 0x804BBB7C: nop

    return;
    // 0x804BBB7C: nop

;}
RECOMP_FUNC void func_80008588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008588: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000858C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80008590: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80008594: jr          $ra
    // 0x80008598: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x80008598: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void func_80460EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460EF8: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80460EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80460F00: beq         $t6, $zero, L_80460F3C
    if (ctx->r14 == 0) {
        // 0x80460F04: nop
    
            goto L_80460F3C;
    }
    // 0x80460F04: nop

    // 0x80460F08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80460F0C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80460F10: jalr        $t9
    // 0x80460F14: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80460F14: nop

    after_0:
    // 0x80460F18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80460F1C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80460F20: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80460F24: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80460F28: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80460F2C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80460F30: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80460F34: b           L_80460F3C
    // 0x80460F38: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80460F3C;
    // 0x80460F38: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80460F3C:
    // 0x80460F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80460F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460F44: jr          $ra
    // 0x80460F48: nop

    return;
    // 0x80460F48: nop

;}
RECOMP_FUNC void func_800381EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800381EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800381F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800381F4: jal         0x80021958
    // 0x800381F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x800381F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800381FC: bne         $v0, $zero, L_8003820C
    if (ctx->r2 != 0) {
        // 0x80038200: nop
    
            goto L_8003820C;
    }
    // 0x80038200: nop

    // 0x80038204: b           L_80038240
    // 0x80038208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038240;
    // 0x80038208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003820C:
    // 0x8003820C: jal         0x800415FC
    // 0x80038210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80038210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80038214: beq         $v0, $zero, L_80038224
    if (ctx->r2 == 0) {
        // 0x80038218: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80038224;
    }
    // 0x80038218: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003821C: b           L_80038240
    // 0x80038220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038240;
    // 0x80038220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038224:
    // 0x80038224: jal         0x800376A4
    // 0x80038228: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800376A4(rdram, ctx);
        goto after_2;
    // 0x80038228: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x8003822C: bnel        $v0, $zero, L_80038240
    if (ctx->r2 != 0) {
        // 0x80038230: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80038240;
    }
    goto skip_0;
    // 0x80038230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80038234: b           L_80038240
    // 0x80038238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038240;
    // 0x80038238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003823C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80038240:
    // 0x80038240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038248: jr          $ra
    // 0x8003824C: nop

    return;
    // 0x8003824C: nop

;}
RECOMP_FUNC void func_8005E30C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E30C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8005E310: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005E314: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005E318: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005E31C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005E320: lw          $s2, 0x16C($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X16C);
    // 0x8005E324: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005E328: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005E32C: lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X2C);
    // 0x8005E330: bnel        $v0, $at, L_8005E344
    if (ctx->r2 != ctx->r1) {
        // 0x8005E334: lbu         $t6, 0x165($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X165);
            goto L_8005E344;
    }
    goto skip_0;
    // 0x8005E334: lbu         $t6, 0x165($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X165);
    skip_0:
    // 0x8005E338: b           L_8005E580
    // 0x8005E33C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005E580;
    // 0x8005E33C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005E340: lbu         $t6, 0x165($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X165);
L_8005E344:
    // 0x8005E344: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E348: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8005E34C: beq         $t6, $at, L_8005E57C
    if (ctx->r14 == ctx->r1) {
        // 0x8005E350: sll         $t8, $v0, 3
        ctx->r24 = S32(ctx->r2 << 3);
            goto L_8005E57C;
    }
    // 0x8005E350: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x8005E354: lwc1        $f4, 0x9C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x8005E358: lw          $t7, -0x76D8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76D8);
    // 0x8005E35C: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8005E360: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x8005E364: lwc1        $f6, 0xA0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x8005E368: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8005E36C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8005E370: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x8005E374: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8005E378: jal         0x80058CC0
    // 0x8005E37C: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    func_80058CC0(rdram, ctx);
        goto after_0;
    // 0x8005E37C: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8005E380: lh          $t9, 0x144($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X144);
    // 0x8005E384: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E388: sb          $t9, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r25;
    // 0x8005E38C: lw          $t0, 0x30($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X30);
    // 0x8005E390: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x8005E394: jal         0x8005E2E8
    // 0x8005E398: lbu         $a1, 0xC($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XC);
    func_8005E2E8(rdram, ctx);
        goto after_1;
    // 0x8005E398: lbu         $a1, 0xC($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XC);
    after_1:
    // 0x8005E39C: addiu       $v0, $s2, 0xD
    ctx->r2 = ADD32(ctx->r18, 0XD);
    // 0x8005E3A0: beql        $v0, $zero, L_8005E40C
    if (ctx->r2 == 0) {
        // 0x8005E3A4: lwc1        $f8, 0x9C($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
            goto L_8005E40C;
    }
    goto skip_1;
    // 0x8005E3A4: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    skip_1:
    // 0x8005E3A8: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8005E3AC: sb          $t1, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r9;
    // 0x8005E3B0: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x8005E3B4: sb          $t2, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r10;
    // 0x8005E3B8: lbu         $t3, 0x2($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2);
    // 0x8005E3BC: sb          $t3, 0x1E($s1)
    MEM_B(0X1E, ctx->r17) = ctx->r11;
    // 0x8005E3C0: lbu         $t4, 0x3($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X3);
    // 0x8005E3C4: sb          $t4, 0x1F($s1)
    MEM_B(0X1F, ctx->r17) = ctx->r12;
    // 0x8005E3C8: lbu         $t5, 0xC($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XC);
    // 0x8005E3CC: beql        $t5, $zero, L_8005E3FC
    if (ctx->r13 == 0) {
        // 0x8005E3D0: sb          $zero, 0x20($s1)
        MEM_B(0X20, ctx->r17) = 0;
            goto L_8005E3FC;
    }
    goto skip_2;
    // 0x8005E3D0: sb          $zero, 0x20($s1)
    MEM_B(0X20, ctx->r17) = 0;
    skip_2:
    // 0x8005E3D4: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    // 0x8005E3D8: sb          $t6, 0x20($s1)
    MEM_B(0X20, ctx->r17) = ctx->r14;
    // 0x8005E3DC: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    // 0x8005E3E0: sb          $t7, 0x21($s1)
    MEM_B(0X21, ctx->r17) = ctx->r15;
    // 0x8005E3E4: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x8005E3E8: sb          $t8, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r24;
    // 0x8005E3EC: lbu         $t9, 0x7($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X7);
    // 0x8005E3F0: b           L_8005E408
    // 0x8005E3F4: sb          $t9, 0x23($s1)
    MEM_B(0X23, ctx->r17) = ctx->r25;
        goto L_8005E408;
    // 0x8005E3F4: sb          $t9, 0x23($s1)
    MEM_B(0X23, ctx->r17) = ctx->r25;
    // 0x8005E3F8: sb          $zero, 0x20($s1)
    MEM_B(0X20, ctx->r17) = 0;
L_8005E3FC:
    // 0x8005E3FC: sb          $zero, 0x21($s1)
    MEM_B(0X21, ctx->r17) = 0;
    // 0x8005E400: sb          $zero, 0x22($s1)
    MEM_B(0X22, ctx->r17) = 0;
    // 0x8005E404: sb          $zero, 0x23($s1)
    MEM_B(0X23, ctx->r17) = 0;
L_8005E408:
    // 0x8005E408: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
L_8005E40C:
    // 0x8005E40C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8005E410: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x8005E414: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8005E418: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x8005E41C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8005E420: jal         0x80066468
    // 0x8005E424: nop

    func_80066468(rdram, ctx);
        goto after_2;
    // 0x8005E424: nop

    after_2:
    // 0x8005E428: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x8005E42C: lw          $t2, 0x138($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X138);
    // 0x8005E430: addiu       $t5, $s0, 0x48
    ctx->r13 = ADD32(ctx->r16, 0X48);
    // 0x8005E434: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8005E438: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005E43C: addiu       $t6, $s0, 0x54
    ctx->r14 = ADD32(ctx->r16, 0X54);
    // 0x8005E440: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8005E444: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8005E448: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005E44C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005E450: andi        $a2, $v0, 0x2
    ctx->r6 = ctx->r2 & 0X2;
    // 0x8005E454: srl         $a2, $a2, 1
    ctx->r6 = S32(U32(ctx->r6) >> 1);
    // 0x8005E458: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8005E45C: addiu       $a3, $s0, 0x90
    ctx->r7 = ADD32(ctx->r16, 0X90);
    // 0x8005E460: jal         0x8005DF6C
    // 0x8005E464: andi        $a1, $v0, 0x1
    ctx->r5 = ctx->r2 & 0X1;
    func_8005DF6C(rdram, ctx);
        goto after_3;
    // 0x8005E464: andi        $a1, $v0, 0x1
    ctx->r5 = ctx->r2 & 0X1;
    after_3:
    // 0x8005E468: lw          $t7, 0x20($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X20);
    // 0x8005E46C: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8005E470: addiu       $t8, $t8, 0x6430
    ctx->r24 = ADD32(ctx->r24, 0X6430);
    // 0x8005E474: beql        $t7, $zero, L_8005E4EC
    if (ctx->r15 == 0) {
        // 0x8005E478: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005E4EC;
    }
    goto skip_3;
    // 0x8005E478: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_3:
    // 0x8005E47C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005E480: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8005E484: addiu       $a1, $s0, 0x13C
    ctx->r5 = ADD32(ctx->r16, 0X13C);
    // 0x8005E488: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8005E48C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8005E490: addiu       $a2, $s2, 0x18
    ctx->r6 = ADD32(ctx->r18, 0X18);
    // 0x8005E494: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8005E498: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8005E49C: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005E4A0: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8005E4A4: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8005E4A8: lw          $t9, 0x20($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X20);
    // 0x8005E4AC: jalr        $t9
    // 0x8005E4B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8005E4B0: nop

    after_4:
    // 0x8005E4B4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8005E4B8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8005E4BC: jal         0x80080798
    // 0x8005E4C0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_80080798(rdram, ctx);
        goto after_5;
    // 0x8005E4C0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_5:
    // 0x8005E4C4: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8005E4C8: lwc1        $f4, 0x18($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8005E4CC: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005E4D0: lwc1        $f6, 0x1C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8005E4D4: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005E4D8: sw          $zero, 0x20($s2)
    MEM_W(0X20, ctx->r18) = 0;
    // 0x8005E4DC: mul.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8005E4E0: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x8005E4E4: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    // 0x8005E4E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8005E4EC:
    // 0x8005E4EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E4F0: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8005E4F4: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005E4F8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8005E4FC: nop

    // 0x8005E500: bc1fl       L_8005E51C
    if (!c1cs) {
        // 0x8005E504: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_8005E51C;
    }
    goto skip_4;
    // 0x8005E504: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_4:
    // 0x8005E508: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x8005E50C: nop

    // 0x8005E510: bc1tl       L_8005E52C
    if (c1cs) {
        // 0x8005E514: lw          $a0, 0x10($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X10);
            goto L_8005E52C;
    }
    goto skip_5;
    // 0x8005E514: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    skip_5:
    // 0x8005E518: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_8005E51C:
    // 0x8005E51C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8005E520: jal         0x80080440
    // 0x8005E524: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_80080440(rdram, ctx);
        goto after_6;
    // 0x8005E524: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_6:
    // 0x8005E528: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
L_8005E52C:
    // 0x8005E52C: jal         0x800817A0
    // 0x8005E530: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    MtxConv_F2L(rdram, ctx);
        goto after_7;
    // 0x8005E530: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_7:
    // 0x8005E534: lw          $v0, 0x44($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X44);
    // 0x8005E538: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8005E53C: addiu       $t2, $t2, 0x6400
    ctx->r10 = ADD32(ctx->r10, 0X6400);
    // 0x8005E540: beq         $v0, $zero, L_8005E550
    if (ctx->r2 == 0) {
        // 0x8005E544: lui         $t1, 0x800F
        ctx->r9 = S32(0X800F << 16);
            goto L_8005E550;
    }
    // 0x8005E544: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x8005E548: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8005E54C: lw          $v0, 0x44($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X44);
L_8005E550:
    // 0x8005E550: bne         $t2, $v0, L_8005E574
    if (ctx->r10 != ctx->r2) {
        // 0x8005E554: nop
    
            goto L_8005E574;
    }
    // 0x8005E554: nop

    // 0x8005E558: lw          $t1, 0x7FF8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7FF8);
    // 0x8005E55C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005E560: addiu       $a0, $a0, 0xD20
    ctx->r4 = ADD32(ctx->r4, 0XD20);
    // 0x8005E564: bne         $t1, $zero, L_8005E574
    if (ctx->r9 != 0) {
        // 0x8005E568: nop
    
            goto L_8005E574;
    }
    // 0x8005E568: nop

    // 0x8005E56C: jal         0x80071380
    // 0x8005E570: addiu       $a1, $zero, 0x29E
    ctx->r5 = ADD32(0, 0X29E);
    Fault_HungUp(rdram, ctx);
        goto after_8;
    // 0x8005E570: addiu       $a1, $zero, 0x29E
    ctx->r5 = ADD32(0, 0X29E);
    after_8:
L_8005E574:
    // 0x8005E574: b           L_8005E580
    // 0x8005E578: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8005E580;
    // 0x8005E578: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8005E57C:
    // 0x8005E57C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005E580:
    // 0x8005E580: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E584: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005E588: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005E58C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005E590: jr          $ra
    // 0x8005E594: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8005E594: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8006E0FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E0FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E104: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006E108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006E10C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8006E110: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006E114: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x8006E118: jal         0x8006E06C
    // 0x8006E11C: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    func_8006E06C(rdram, ctx);
        goto after_0;
    // 0x8006E11C: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    after_0:
    // 0x8006E120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E128: jr          $ra
    // 0x8006E12C: nop

    return;
    // 0x8006E12C: nop

;}
RECOMP_FUNC void func_807BAE44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BAE44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BAE48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BAE4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807BAE50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807BAE54: jal         0x807BA848
    // 0x807BAE58: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_807BA848(rdram, ctx);
        goto after_0;
    // 0x807BAE58: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x807BAE5C: jal         0x807BABD4
    // 0x807BAE60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BABD4(rdram, ctx);
        goto after_1;
    // 0x807BAE60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807BAE64: jal         0x807BAB94
    // 0x807BAE68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAB94(rdram, ctx);
        goto after_2;
    // 0x807BAE68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807BAE6C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1224) << 16);
    // 0x807BAE70: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x807BAE74: lwc1        $f0, -0x45CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1224));
    // 0x807BAE78: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x807BAE7C: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x807BAE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BAE84: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x807BAE88: nop

    // 0x807BAE8C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807BAE90: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x807BAE94: jal         0x807BAA7C
    // 0x807BAE98: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    func_807BAA7C(rdram, ctx);
        goto after_3;
    // 0x807BAE98: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    after_3:
    // 0x807BAE9C: beq         $v0, $zero, L_807BAF10
    if (ctx->r2 == 0) {
        // 0x807BAEA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807BAF10;
    }
    // 0x807BAEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BAEA4: jal         0x807BAAFC
    // 0x807BAEA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAAFC(rdram, ctx);
        goto after_4;
    // 0x807BAEA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807BAEAC: bnel        $v0, $zero, L_807BAF24
    if (ctx->r2 != 0) {
        // 0x807BAEB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807BAF24;
    }
    goto skip_0;
    // 0x807BAEB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807BAEB4: jal         0x807BAD68
    // 0x807BAEB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAD68(rdram, ctx);
        goto after_5;
    // 0x807BAEB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807BAEBC: bne         $v0, $zero, L_807BAF20
    if (ctx->r2 != 0) {
        // 0x807BAEC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807BAF20;
    }
    // 0x807BAEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BAEC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BAEC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807BAECC: jal         0x807BB7A4
    // 0x807BAED0: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_807BB7A4(rdram, ctx);
        goto after_6;
    // 0x807BAED0: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_6:
    // 0x807BAED4: jal         0x800653D8
    // 0x807BAED8: nop

    func_800653D8(rdram, ctx);
        goto after_7;
    // 0x807BAED8: nop

    after_7:
    // 0x807BAEDC: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x807BAEE0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x807BAEE4: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1228) << 16);
    // 0x807BAEE8: lwc1        $f4, -0x45C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1228));
    // 0x807BAEEC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807BAEF0: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X122C) << 16);
    // 0x807BAEF4: lwc1        $f8, -0x45C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X122C));
    // 0x807BAEF8: lwc1        $f16, 0x18($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X18);
    // 0x807BAEFC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x807BAF00: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x807BAF04: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x807BAF08: b           L_807BAF20
    // 0x807BAF0C: swc1        $f18, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f18.u32l;
        goto L_807BAF20;
    // 0x807BAF0C: swc1        $f18, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f18.u32l;
L_807BAF10:
    // 0x807BAF10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BAF14: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807BAF18: jal         0x807BB7A4
    // 0x807BAF1C: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_807BB7A4(rdram, ctx);
        goto after_8;
    // 0x807BAF1C: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_8:
L_807BAF20:
    // 0x807BAF20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807BAF24:
    // 0x807BAF24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807BAF28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807BAF2C: jr          $ra
    // 0x807BAF30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807BAF30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8051A568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A568: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051A56C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051A570: lh          $a3, 0x1F0($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X1F0);
    // 0x8051A574: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8051A578: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8051A57C: bne         $a3, $at, L_8051A5E8
    if (ctx->r7 != ctx->r1) {
        // 0x8051A580: sll         $a1, $a3, 16
        ctx->r5 = S32(ctx->r7 << 16);
            goto L_8051A5E8;
    }
    // 0x8051A580: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8051A584: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8051A588: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8051A58C: jal         0x80067BBC
    // 0x8051A590: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8051A590: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8051A594: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8051A598: jal         0x80067F78
    // 0x8051A59C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8051A59C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8051A5A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8051A5A4: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8051A5A8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8051A5AC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8051A5B0: beq         $v0, $at, L_8051A630
    if (ctx->r2 == ctx->r1) {
        // 0x8051A5B4: sh          $v0, 0x1F0($a2)
        MEM_H(0X1F0, ctx->r6) = ctx->r2;
            goto L_8051A630;
    }
    // 0x8051A5B4: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
    // 0x8051A5B8: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8051A5BC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8051A5C0: jal         0x80067BBC
    // 0x8051A5C4: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8051A5C4: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_2:
    // 0x8051A5C8: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8051A5CC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8051A5D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8051A5D4: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8051A5D8: jal         0x80067838
    // 0x8051A5DC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x8051A5DC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x8051A5E0: b           L_8051A634
    // 0x8051A5E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8051A634;
    // 0x8051A5E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8051A5E8:
    // 0x8051A5E8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8051A5EC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8051A5F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8051A5F4: jal         0x80067930
    // 0x8051A5F8: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_4;
    // 0x8051A5F8: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_4:
    // 0x8051A5FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8051A600: beq         $v0, $zero, L_8051A630
    if (ctx->r2 == 0) {
        // 0x8051A604: lh          $a3, 0x1E($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X1E);
            goto L_8051A630;
    }
    // 0x8051A604: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8051A608: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8051A60C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8051A610: jal         0x80067BBC
    // 0x8051A614: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8051A614: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_5:
    // 0x8051A618: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8051A61C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8051A620: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8051A624: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8051A628: jal         0x800678F0
    // 0x8051A62C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x8051A62C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_6:
L_8051A630:
    // 0x8051A630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8051A634:
    // 0x8051A634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051A638: jr          $ra
    // 0x8051A63C: nop

    return;
    // 0x8051A63C: nop

;}
RECOMP_FUNC void func_80436860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436860: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(74, 0X10) << 16);
    // 0x80436864: addiu       $v0, $v0, 0x6870
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(74, 0X10));
    // 0x80436868: jr          $ra
    // 0x8043686C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8043686C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8000ADA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ADA0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000ADA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000ADA8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8000ADAC: lbu         $t6, 0x2($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X2);
    // 0x8000ADB0: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8000ADB4: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x8000ADB8: sb          $t6, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r14;
    // 0x8000ADBC: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x8000ADC0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8000ADC4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000ADC8: sb          $t7, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r15;
    // 0x8000ADCC: lbu         $t0, 0x3($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X3);
    // 0x8000ADD0: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
    // 0x8000ADD4: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8000ADD8: lbu         $t2, 0xB0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XB0);
    // 0x8000ADDC: addiu       $v0, $v0, 0xB0
    ctx->r2 = ADD32(ctx->r2, 0XB0);
    // 0x8000ADE0: sb          $t2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r10;
    // 0x8000ADE4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8000ADE8: lbu         $t5, 0xB1($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0XB1);
    // 0x8000ADEC: sb          $t5, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r13;
    // 0x8000ADF0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8000ADF4: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x8000ADF8: sw          $t7, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r15;
    // 0x8000ADFC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8000AE00: lbu         $t9, 0xB6($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XB6);
    // 0x8000AE04: sb          $t9, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r25;
    // 0x8000AE08: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    // 0x8000AE0C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8000AE10: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8000AE14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000AE18: jal         0x8000B164
    // 0x8000AE1C: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    func_8000B164(rdram, ctx);
        goto after_0;
    // 0x8000AE1C: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8000AE20: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x8000AE24: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AE28: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000AE2C: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x8000AE30: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    // 0x8000AE34: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000AE38: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8000AE3C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8000AE40: sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3 << 6);
    // 0x8000AE44: srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // 0x8000AE48: beq         $v1, $zero, L_8000AEE8
    if (ctx->r3 == 0) {
        // 0x8000AE4C: lwc1        $f2, 0x28($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8000AEE8;
    }
    // 0x8000AE4C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8000AE50: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x8000AE54: lb          $t2, 0x6AC2($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X6AC2);
    // 0x8000AE58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000AE5C: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8000AE60: bne         $t2, $at, L_8000AEE8
    if (ctx->r10 != ctx->r1) {
        // 0x8000AE64: lui         $t5, 0x8009
        ctx->r13 = S32(0X8009 << 16);
            goto L_8000AEE8;
    }
    // 0x8000AE64: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8000AE68: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
    // 0x8000AE6C: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8000AE70: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
    // 0x8000AE74: bnel        $at, $zero, L_8000AE84
    if (ctx->r1 != 0) {
        // 0x8000AE78: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_8000AE84;
    }
    goto skip_0;
    // 0x8000AE78: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    skip_0:
    // 0x8000AE7C: addiu       $v1, $zero, 0x3F
    ctx->r3 = ADD32(0, 0X3F);
    // 0x8000AE80: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_8000AE84:
    // 0x8000AE84: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x8000AE88: lhu         $t3, 0x6C44($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X6C44);
    // 0x8000AE8C: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x8000AE90: negu        $t4, $v0
    ctx->r12 = SUB32(0, ctx->r2);
    // 0x8000AE94: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8000AE98: sb          $t3, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r11;
    // 0x8000AE9C: lhu         $t5, 0x6CC2($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X6CC2);
    // 0x8000AEA0: andi        $t8, $t6, 0xFFF7
    ctx->r24 = ctx->r14 & 0XFFF7;
    // 0x8000AEA4: andi        $t2, $t8, 0xFB
    ctx->r10 = ctx->r24 & 0XFB;
    // 0x8000AEA8: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
    // 0x8000AEAC: sb          $t2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r10;
    // 0x8000AEB0: ori         $t1, $t2, 0x1
    ctx->r9 = ctx->r10 | 0X1;
    // 0x8000AEB4: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
    // 0x8000AEB8: sb          $t5, 0x3($a3)
    MEM_B(0X3, ctx->r7) = ctx->r13;
    // 0x8000AEBC: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    // 0x8000AEC0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000AEC4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8000AEC8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8000AECC: lwc1        $f12, 0x6D48($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6D48);
    // 0x8000AED0: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8000AED4: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x8000AED8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000AEDC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000AEE0: b           L_8000B0D0
    // 0x8000AEE4: lwc1        $f14, 0x6F44($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6F44);
        goto L_8000B0D0;
    // 0x8000AEE4: lwc1        $f14, 0x6F44($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6F44);
L_8000AEE8:
    // 0x8000AEE8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000AEEC: beq         $v1, $zero, L_8000B090
    if (ctx->r3 == 0) {
        // 0x8000AEF0: lb          $v0, 0x6AC2($v0)
        ctx->r2 = MEM_B(ctx->r2, 0X6AC2);
            goto L_8000B090;
    }
    // 0x8000AEF0: lb          $v0, 0x6AC2($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AC2);
    // 0x8000AEF4: bnel        $v0, $zero, L_8000B094
    if (ctx->r2 != 0) {
        // 0x8000AEF8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8000B094;
    }
    goto skip_1;
    // 0x8000AEF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x8000AEFC: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x8000AF00: sb          $zero, 0x3($a3)
    MEM_B(0X3, ctx->r7) = 0;
    // 0x8000AF04: sb          $zero, 0x4($a3)
    MEM_B(0X4, ctx->r7) = 0;
    // 0x8000AF08: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x8000AF0C: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
    // 0x8000AF10: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x8000AF14: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000AF18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000AF1C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8000AF20: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8000AF24: lwc1        $f12, 0x6F48($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6F48);
    // 0x8000AF28: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8000AF2C: negu        $t1, $t2
    ctx->r9 = SUB32(0, ctx->r10);
    // 0x8000AF30: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000AF34: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8000AF38: lwc1        $f14, 0x7144($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7144);
    // 0x8000AF3C: slti        $at, $t9, 0x20
    ctx->r1 = SIGNED(ctx->r25) < 0X20 ? 1 : 0;
    // 0x8000AF40: beq         $at, $zero, L_8000AF50
    if (ctx->r1 == 0) {
        // 0x8000AF44: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000AF50;
    }
    // 0x8000AF44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000AF48: b           L_8000AF64
    // 0x8000AF4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8000AF64;
    // 0x8000AF4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8000AF50:
    // 0x8000AF50: lbu         $t4, 0x27($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X27);
    // 0x8000AF54: slti        $at, $t4, 0x61
    ctx->r1 = SIGNED(ctx->r12) < 0X61 ? 1 : 0;
    // 0x8000AF58: bnel        $at, $zero, L_8000AF68
    if (ctx->r1 != 0) {
        // 0x8000AF5C: lbu         $t7, 0x0($a3)
        ctx->r15 = MEM_BU(ctx->r7, 0X0);
            goto L_8000AF68;
    }
    goto skip_2;
    // 0x8000AF5C: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    skip_2:
    // 0x8000AF60: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000AF64:
    // 0x8000AF64: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
L_8000AF68:
    // 0x8000AF68: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x8000AF6C: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x8000AF70: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x8000AF74: or          $t4, $t6, $t8
    ctx->r12 = ctx->r14 | ctx->r24;
    // 0x8000AF78: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8000AF7C: andi        $t9, $t1, 0x4
    ctx->r25 = ctx->r9 & 0X4;
    // 0x8000AF80: andi        $t3, $t4, 0xFB
    ctx->r11 = ctx->r12 & 0XFB;
    // 0x8000AF84: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
    // 0x8000AF88: or          $t5, $t9, $t3
    ctx->r13 = ctx->r25 | ctx->r11;
    // 0x8000AF8C: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
    // 0x8000AF90: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8000AF94: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000AF98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000AF9C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8000AFA0: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x8000AFA4: beq         $v0, $zero, L_8000AFD0
    if (ctx->r2 == 0) {
        // 0x8000AFA8: sll         $t6, $t7, 6
        ctx->r14 = S32(ctx->r15 << 6);
            goto L_8000AFD0;
    }
    // 0x8000AFA8: sll         $t6, $t7, 6
    ctx->r14 = S32(ctx->r15 << 6);
    // 0x8000AFAC: beq         $v0, $at, L_8000B0D0
    if (ctx->r2 == ctx->r1) {
        // 0x8000AFB0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000B0D0;
    }
    // 0x8000AFB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000AFB4: beq         $v0, $at, L_8000B008
    if (ctx->r2 == ctx->r1) {
        // 0x8000AFB8: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_8000B008;
    }
    // 0x8000AFB8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8000AFBC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000AFC0: beq         $v0, $at, L_8000B04C
    if (ctx->r2 == ctx->r1) {
        // 0x8000AFC4: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_8000B04C;
    }
    // 0x8000AFC4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000AFC8: b           L_8000B0D4
    // 0x8000AFCC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
        goto L_8000B0D4;
    // 0x8000AFCC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8000AFD0:
    // 0x8000AFD0: lbu         $t1, 0x0($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X0);
    // 0x8000AFD4: srl         $t8, $t6, 31
    ctx->r24 = S32(U32(ctx->r14) >> 31);
    // 0x8000AFD8: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x8000AFDC: andi        $t2, $t0, 0x8
    ctx->r10 = ctx->r8 & 0X8;
    // 0x8000AFE0: andi        $t4, $t1, 0xFFF7
    ctx->r12 = ctx->r9 & 0XFFF7;
    // 0x8000AFE4: or          $t8, $t2, $t4
    ctx->r24 = ctx->r10 | ctx->r12;
    // 0x8000AFE8: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
    // 0x8000AFEC: lbu         $t5, 0x24($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X24);
    // 0x8000AFF0: andi        $t0, $t8, 0xFB
    ctx->r8 = ctx->r24 & 0XFB;
    // 0x8000AFF4: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8000AFF8: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x8000AFFC: or          $t1, $t6, $t0
    ctx->r9 = ctx->r14 | ctx->r8;
    // 0x8000B000: b           L_8000B0D0
    // 0x8000B004: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
        goto L_8000B0D0;
    // 0x8000B004: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
L_8000B008:
    // 0x8000B008: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x8000B00C: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x8000B010: srl         $t9, $t4, 31
    ctx->r25 = S32(U32(ctx->r12) >> 31);
    // 0x8000B014: or          $t5, $t9, $v1
    ctx->r13 = ctx->r25 | ctx->r3;
    // 0x8000B018: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x8000B01C: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8000B020: andi        $t0, $t6, 0xFFF7
    ctx->r8 = ctx->r14 & 0XFFF7;
    // 0x8000B024: or          $t6, $t8, $t0
    ctx->r14 = ctx->r24 | ctx->r8;
    // 0x8000B028: sb          $t6, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r14;
    // 0x8000B02C: lbu         $t4, 0x24($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X24);
    // 0x8000B030: andi        $t8, $t6, 0xFB
    ctx->r24 = ctx->r14 & 0XFB;
    // 0x8000B034: or          $t3, $t4, $a0
    ctx->r11 = ctx->r12 | ctx->r4;
    // 0x8000B038: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8000B03C: andi        $t7, $t5, 0x4
    ctx->r15 = ctx->r13 & 0X4;
    // 0x8000B040: or          $t0, $t7, $t8
    ctx->r8 = ctx->r15 | ctx->r24;
    // 0x8000B044: b           L_8000B0D0
    // 0x8000B048: sb          $t0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r8;
        goto L_8000B0D0;
    // 0x8000B048: sb          $t0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r8;
L_8000B04C:
    // 0x8000B04C: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x8000B050: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x8000B054: srl         $t4, $t2, 31
    ctx->r12 = S32(U32(ctx->r10) >> 31);
    // 0x8000B058: xor         $t3, $t4, $v1
    ctx->r11 = ctx->r12 ^ ctx->r3;
    // 0x8000B05C: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8000B060: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x8000B064: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x8000B068: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8000B06C: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
    // 0x8000B070: lbu         $t2, 0x24($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X24);
    // 0x8000B074: andi        $t6, $t7, 0xFB
    ctx->r14 = ctx->r15 & 0XFB;
    // 0x8000B078: xor         $t9, $t2, $a0
    ctx->r25 = ctx->r10 ^ ctx->r4;
    // 0x8000B07C: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8000B080: andi        $t5, $t3, 0x4
    ctx->r13 = ctx->r11 & 0X4;
    // 0x8000B084: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x8000B088: b           L_8000B0D0
    // 0x8000B08C: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
        goto L_8000B0D0;
    // 0x8000B08C: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
L_8000B090:
    // 0x8000B090: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8000B094:
    // 0x8000B094: bne         $v0, $at, L_8000B0AC
    if (ctx->r2 != ctx->r1) {
        // 0x8000B098: lbu         $t0, 0x27($sp)
        ctx->r8 = MEM_BU(ctx->r29, 0X27);
            goto L_8000B0AC;
    }
    // 0x8000B098: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x8000B09C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000B0A0: lwc1        $f14, -0x42F0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X42F0);
    // 0x8000B0A4: b           L_8000B0D0
    // 0x8000B0A8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_8000B0D0;
    // 0x8000B0A8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_8000B0AC:
    // 0x8000B0AC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000B0B0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000B0B4: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8000B0B8: lwc1        $f12, 0x7148($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7148);
    // 0x8000B0BC: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8000B0C0: negu        $t4, $t2
    ctx->r12 = SUB32(0, ctx->r10);
    // 0x8000B0C4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000B0C8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8000B0CC: lwc1        $f14, 0x7344($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7344);
L_8000B0D0:
    // 0x8000B0D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8000B0D4:
    // 0x8000B0D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000B0D8: bc1fl       L_8000B0E8
    if (!c1cs) {
        // 0x8000B0DC: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8000B0E8;
    }
    goto skip_3;
    // 0x8000B0DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_3:
    // 0x8000B0E0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8000B0E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8000B0E8:
    // 0x8000B0E8: nop

    // 0x8000B0EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8000B0F0: nop

    // 0x8000B0F4: bc1f        L_8000B100
    if (!c1cs) {
        // 0x8000B0F8: nop
    
            goto L_8000B100;
    }
    // 0x8000B0F8: nop

    // 0x8000B0FC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8000B100:
    // 0x8000B100: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8000B104: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000B108: lwc1        $f0, -0x42EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X42EC);
    // 0x8000B10C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000B110: nop

    // 0x8000B114: mul.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8000B118: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8000B11C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000B120: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8000B124: nop

    // 0x8000B128: sh          $t3, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r11;
    // 0x8000B12C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8000B130: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8000B134: nop

    // 0x8000B138: sh          $t5, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r13;
    // 0x8000B13C: lbu         $t6, 0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1);
    // 0x8000B140: sb          $t6, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r14;
    // 0x8000B144: lw          $t8, 0x10($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X10);
    // 0x8000B148: sw          $t8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r24;
    // 0x8000B14C: lbu         $t1, 0x26($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X26);
    // 0x8000B150: sb          $t1, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r9;
    // 0x8000B154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B158: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8000B15C: jr          $ra
    // 0x8000B160: nop

    return;
    // 0x8000B160: nop

;}
RECOMP_FUNC void func_80407C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80407C2C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80407C30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80407C34: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80407C38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80407C3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80407C40: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x80407C44: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(11, 0X2CA0) << 16);
    // 0x80407C48: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x80407C4C: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80407C50: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(11, 0X24D4) << 16);
    // 0x80407C54: addiu       $t6, $t6, -0x5990
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(11, 0X2CA0));
    // 0x80407C58: addiu       $t7, $t7, -0x615C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(11, 0X24D4));
    // 0x80407C5C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80407C60: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x80407C64: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80407C68: jr          $ra
    // 0x80407C6C: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x80407C6C: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80436950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80436954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436958: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8043695C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80436960: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(77, 0X1EE0) << 16);
    // 0x80436964: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80436968: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8043696C: lw          $t8, -0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(77, 0X1EE0));
    // 0x80436970: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80436974: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80436978: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8043697C: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80436980: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80436984: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80436988: beql        $v1, $zero, L_804369BC
    if (ctx->r3 == 0) {
        // 0x8043698C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804369BC;
    }
    goto skip_0;
    // 0x8043698C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80436990: jalr        $v1
    // 0x80436994: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80436994: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80436998: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043699C: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804369A0: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804369A4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804369A8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804369AC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804369B0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804369B4: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804369B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804369BC:
    // 0x804369BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804369C0: jr          $ra
    // 0x804369C4: nop

    return;
    // 0x804369C4: nop

;}
RECOMP_FUNC void func_806D996C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D996C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D9970: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806D9974: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806D9978: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806D997C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D9980: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806D9984: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806D9988: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x806D998C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806D9990: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806D9994: lui         $t2, 0x806E
    ctx->r10 = S32(RELOC_HI16(631, 0X3F4) << 16);
    // 0x806D9998: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806D999C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806D99A0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806D99A4: lw          $t2, -0x64FC($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(631, 0X3F4));
    // 0x806D99A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806D99AC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806D99B0: jal         0x806D9818
    // 0x806D99B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806D9818(rdram, ctx);
        goto after_0;
    // 0x806D99B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D99B8: jal         0x806D9874
    // 0x806D99BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806D9874(rdram, ctx);
        goto after_1;
    // 0x806D99BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806D99C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D99C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D99C8: jr          $ra
    // 0x806D99CC: nop

    return;
    // 0x806D99CC: nop

;}
RECOMP_FUNC void func_805694F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805694F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x805694F4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x805694F8: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x805694FC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80569500: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80569504: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80569508: lui         $t7, 0x8057
    ctx->r15 = S32(RELOC_HI16(378, 0X2880) << 16);
    // 0x8056950C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80569510: addiu       $t7, $t7, -0x61D0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(378, 0X2880));
    // 0x80569514: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80569518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8056951C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80569520: addiu       $a1, $a0, 0xC
    ctx->r5 = ADD32(ctx->r4, 0XC);
    // 0x80569524: jal         0x8004667C
    // 0x80569528: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80569528: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x8056952C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80569530: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x80569534: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80569538: lui         $a2, 0x8057
    ctx->r6 = S32(RELOC_HI16(378, 0X1D9C) << 16);
    // 0x8056953C: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x80569540: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80569544: bnel        $t9, $zero, L_80569558
    if (ctx->r25 != 0) {
        // 0x80569548: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80569558;
    }
    goto skip_0;
    // 0x80569548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8056954C: jal         0x80057B28
    // 0x80569550: addiu       $a2, $a2, -0x6CB4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(378, 0X1D9C));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x80569550: addiu       $a2, $a2, -0x6CB4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(378, 0X1D9C));
    after_1:
    // 0x80569554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80569558:
    // 0x80569558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8056955C: jr          $ra
    // 0x80569560: nop

    return;
    // 0x80569560: nop

    // 0x80569564: nop

    // 0x80569568: nop

    // 0x8056956C: nop

;}
RECOMP_FUNC void func_805A6E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6E10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A6E14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A6E18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A6E1C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805A6E20: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805A6E24: jal         0x800485B8
    // 0x805A6E28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800485B8(rdram, ctx);
        goto after_0;
    // 0x805A6E28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A6E2C: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(423, 0X4F0) << 16);
    // 0x805A6E30: lwc1        $f4, 0x72F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(423, 0X4F0));
    // 0x805A6E34: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805A6E38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A6E3C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805A6E40: swc1        $f4, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f4.u32l;
    // 0x805A6E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A6E48: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    // 0x805A6E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A6E50: jr          $ra
    // 0x805A6E54: nop

    return;
    // 0x805A6E54: nop

;}
RECOMP_FUNC void func_8076D38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D38C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8076D390: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8076D394: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8076D398: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8076D39C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8076D3A0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8076D3A4: nop

    // 0x8076D3A8: bc1fl       L_8076D42C
    if (!c1cs) {
        // 0x8076D3AC: swc1        $f12, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
            goto L_8076D42C;
    }
    goto skip_0;
    // 0x8076D3AC: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    skip_0:
    // 0x8076D3B0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8076D3B4: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x8076D3B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8076D3BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8076D3C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8076D3C4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8076D3C8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8076D3CC: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8076D3D0: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8076D3D4: nop

    // 0x8076D3D8: bc1fl       L_8076D3EC
    if (!c1cs) {
        // 0x8076D3DC: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_8076D3EC;
    }
    goto skip_1;
    // 0x8076D3DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_1:
    // 0x8076D3E0: b           L_8076D404
    // 0x8076D3E4: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_8076D404;
    // 0x8076D3E4: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8076D3E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_8076D3EC:
    // 0x8076D3EC: nop

    // 0x8076D3F0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8076D3F4: nop

    // 0x8076D3F8: bc1fl       L_8076D408
    if (!c1cs) {
        // 0x8076D3FC: sub.s       $f10, $f0, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8076D408;
    }
    goto skip_2;
    // 0x8076D3FC: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x8076D400: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_8076D404:
    // 0x8076D404: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
L_8076D408:
    // 0x8076D408: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x8076D40C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8076D410: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x8076D414: nop

    // 0x8076D418: bc1f        L_8076D430
    if (!c1cs) {
        // 0x8076D41C: nop
    
            goto L_8076D430;
    }
    // 0x8076D41C: nop

    // 0x8076D420: jr          $ra
    // 0x8076D424: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    return;
    // 0x8076D424: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    // 0x8076D428: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
L_8076D42C:
    // 0x8076D42C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_8076D430:
    // 0x8076D430: jr          $ra
    // 0x8076D434: nop

    return;
    // 0x8076D434: nop

;}
RECOMP_FUNC void func_8064CB1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064CB1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064CB20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064CB24: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8064CB28: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8064CB2C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064CB30: lui         $t8, 0x8065
    ctx->r24 = S32(RELOC_HI16(495, 0X3590) << 16);
    // 0x8064CB34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8064CB38: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8064CB3C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8064CB40: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064CB44: lw          $t8, -0x29A0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(495, 0X3590));
    // 0x8064CB48: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064CB4C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064CB50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064CB54: jal         0x80048490
    // 0x8064CB58: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8064CB58: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8064CB5C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8064CB60: jal         0x80048378
    // 0x8064CB64: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8064CB64: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8064CB68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064CB6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064CB70: jr          $ra
    // 0x8064CB74: nop

    return;
    // 0x8064CB74: nop

;}
RECOMP_FUNC void func_80683134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80683134: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80683138: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8068313C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80683140: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80683144: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80683148: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8068314C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80683150: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80683154: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80683158: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8068315C: jr          $ra
    // 0x80683160: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80683160: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80683164: nop

    // 0x80683168: nop

    // 0x8068316C: nop

;}
RECOMP_FUNC void func_80434B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434B9C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80434BA0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80434BA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80434BA8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80434BAC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80434BB0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80434BB4: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    // 0x80434BB8: addiu       $v1, $v0, 0x5CC
    ctx->r3 = ADD32(ctx->r2, 0X5CC);
L_80434BBC:
    // 0x80434BBC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80434BC0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80434BC4: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80434BC8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80434BCC: addiu       $v1, $v1, 0x0
    ctx->r3 = ADD32(ctx->r3, 0X0);
    // 0x80434BD0: bc1fl       L_80434BE4
    if (!c1cs) {
        // 0x80434BD4: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_80434BE4;
    }
    goto skip_0;
    // 0x80434BD4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_0:
    // 0x80434BD8: b           L_80434BF4
    // 0x80434BDC: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
        goto L_80434BF4;
    // 0x80434BDC: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80434BE0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_80434BE4:
    // 0x80434BE4: nop

    // 0x80434BE8: bc1fl       L_80434BF8
    if (!c1cs) {
        // 0x80434BEC: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80434BF8;
    }
    goto skip_1;
    // 0x80434BEC: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_1:
    // 0x80434BF0: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_80434BF4:
    // 0x80434BF4: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80434BF8:
    // 0x80434BF8: nop

    // 0x80434BFC: bc1fl       L_80434C10
    if (!c1cs) {
        // 0x80434C00: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_80434C10;
    }
    goto skip_2;
    // 0x80434C00: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_2:
    // 0x80434C04: b           L_80434C20
    // 0x80434C08: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
        goto L_80434C20;
    // 0x80434C08: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80434C0C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_80434C10:
    // 0x80434C10: nop

    // 0x80434C14: bc1fl       L_80434C24
    if (!c1cs) {
        // 0x80434C18: swc1        $f0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
            goto L_80434C24;
    }
    goto skip_3;
    // 0x80434C18: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    skip_3:
    // 0x80434C1C: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
L_80434C20:
    // 0x80434C20: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_80434C24:
    // 0x80434C24: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x80434C28: bgez        $a1, L_80434BBC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80434C2C: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80434BBC;
    }
    // 0x80434C2C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80434C30: jr          $ra
    // 0x80434C34: nop

    return;
    // 0x80434C34: nop

;}
RECOMP_FUNC void func_804BB3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB3A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BB3A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB3A8: jal         0x804BB604
    // 0x804BB3AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804BB604(rdram, ctx);
        goto after_0;
    // 0x804BB3AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BB3B0: beql        $v0, $zero, L_804BB3D4
    if (ctx->r2 == 0) {
        // 0x804BB3B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BB3D4;
    }
    goto skip_0;
    // 0x804BB3B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BB3B8: jal         0x804BAD44
    // 0x804BB3BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804BAD44(rdram, ctx);
        goto after_1;
    // 0x804BB3BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804BB3C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BB3C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB3C8: jal         0x804BB4C4
    // 0x804BB3CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_804BB4C4(rdram, ctx);
        goto after_2;
    // 0x804BB3CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x804BB3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB3D4:
    // 0x804BB3D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BB3D8: jr          $ra
    // 0x804BB3DC: nop

    return;
    // 0x804BB3DC: nop

;}
RECOMP_FUNC void func_80026D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026D10: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80026D14: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x80026D18: lw          $t6, 0xF10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XF10);
    // 0x80026D1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80026D20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026D24: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80026D28: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80026D2C: lw          $t9, 0xF14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XF14);
    // 0x80026D30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80026D34: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026D38: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80026D3C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80026D40: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80026D44: lw          $t1, 0xE8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE8);
    // 0x80026D48: lw          $v1, 0x144($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X144);
    // 0x80026D4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80026D50: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80026D54: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80026D58: beql        $at, $zero, L_80026D74
    if (ctx->r1 == 0) {
        // 0x80026D5C: lw          $t5, 0x15C($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X15C);
            goto L_80026D74;
    }
    goto skip_0;
    // 0x80026D5C: lw          $t5, 0x15C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X15C);
    skip_0:
    // 0x80026D60: lw          $t3, 0x15C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X15C);
    // 0x80026D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80026D68: b           L_80026D80
    // 0x80026D6C: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
        goto L_80026D80;
    // 0x80026D6C: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x80026D70: lw          $t5, 0x15C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X15C);
L_80026D74:
    // 0x80026D74: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80026D78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80026D7C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
L_80026D80:
    // 0x80026D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80026D84: jal         0x80024840
    // 0x80026D88: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80024840(rdram, ctx);
        goto after_0;
    // 0x80026D88: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80026D8C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80026D90: beq         $v0, $zero, L_80026DC8
    if (ctx->r2 == 0) {
        // 0x80026D94: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80026DC8;
    }
    // 0x80026D94: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80026D98: jal         0x8001D770
    // 0x80026D9C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x80026D9C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x80026DA0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80026DA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80026DA8: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80026DAC: jal         0x80067CE4
    // 0x80026DB0: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067CE4(rdram, ctx);
        goto after_2;
    // 0x80026DB0: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80026DB4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80026DB8: jal         0x80067818
    // 0x80026DBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80026DBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80026DC0: b           L_80026E10
    // 0x80026DC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80026E10;
    // 0x80026DC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80026DC8:
    // 0x80026DC8: lw          $t6, 0x154($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X154);
    // 0x80026DCC: bnel        $t6, $zero, L_80026E10
    if (ctx->r14 != 0) {
        // 0x80026DD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80026E10;
    }
    goto skip_1;
    // 0x80026DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80026DD4: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x80026DD8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80026DDC: bnel        $t7, $at, L_80026E10
    if (ctx->r15 != ctx->r1) {
        // 0x80026DE0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80026E10;
    }
    goto skip_2;
    // 0x80026DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80026DE4: jal         0x8001D770
    // 0x80026DE8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x80026DE8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_4:
    // 0x80026DEC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80026DF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80026DF4: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80026DF8: jal         0x80067CE4
    // 0x80026DFC: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067CE4(rdram, ctx);
        goto after_5;
    // 0x80026DFC: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x80026E00: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80026E04: jal         0x80067818
    // 0x80026E08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x80026E08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80026E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80026E10:
    // 0x80026E10: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80026E14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80026E18: jr          $ra
    // 0x80026E1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80026E1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80037028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003702C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037030: jal         0x80036DE4
    // 0x80037034: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    func_80036DE4(rdram, ctx);
        goto after_0;
    // 0x80037034: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80037038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003703C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037040: jr          $ra
    // 0x80037044: nop

    return;
    // 0x80037044: nop

;}
RECOMP_FUNC void func_80466610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80466610: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80466614: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80466618: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8046661C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80466620: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80466624: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80466628: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8046662C: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80466630: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x80466634: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80466638: beql        $at, $zero, L_804666E0
    if (ctx->r1 == 0) {
        // 0x8046663C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804666E0;
    }
    goto skip_0;
    // 0x8046663C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80466640: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x80466644: lw          $t1, 0x1C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1C);
    // 0x80466648: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x8046664C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80466650: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80466654: beql        $at, $zero, L_804666E0
    if (ctx->r1 == 0) {
        // 0x80466658: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804666E0;
    }
    goto skip_1;
    // 0x80466658: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8046665C: jal         0x8007B4F0
    // 0x80466660: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8007B4F0(rdram, ctx);
        goto after_0;
    // 0x80466660: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80466664: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80466668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046666C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80466670: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80466674: jal         0x8007B55C
    // 0x80466678: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    func_8007B55C(rdram, ctx);
        goto after_1;
    // 0x80466678: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    after_1:
    // 0x8046667C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80466680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80466684: lw          $t2, 0x1C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1C);
    // 0x80466688: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x8046668C: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x80466690: lw          $a3, 0x18($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X18);
    // 0x80466694: jal         0x8007B580
    // 0x80466698: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_8007B580(rdram, ctx);
        goto after_2;
    // 0x80466698: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_2:
    // 0x8046669C: jal         0x8007B59C
    // 0x804666A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007B59C(rdram, ctx);
        goto after_3;
    // 0x804666A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804666A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804666A8: jal         0x8007BA6C
    // 0x804666AC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_8007BA6C(rdram, ctx);
        goto after_4;
    // 0x804666AC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_4:
    // 0x804666B0: jal         0x8007B550
    // 0x804666B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007B550(rdram, ctx);
        goto after_5;
    // 0x804666B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804666B8: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x804666BC: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x804666C0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x804666C4: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x804666C8: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x804666CC: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x804666D0: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x804666D4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x804666D8: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x804666DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804666E0:
    // 0x804666E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804666E4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x804666E8: jr          $ra
    // 0x804666EC: nop

    return;
    // 0x804666EC: nop

;}
RECOMP_FUNC void func_8040EAB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EAB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EABC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8040EAC0: bne         $a1, $at, L_8040EAD8
    if (ctx->r5 != ctx->r1) {
        // 0x8040EAC4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8040EAD8;
    }
    // 0x8040EAC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EAC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040EACC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8040EAD0: jal         0x8040F0B8
    // 0x8040EAD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8040F0B8(rdram, ctx);
        goto after_0;
    // 0x8040EAD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
L_8040EAD8:
    // 0x8040EAD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040EADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EAE0: jr          $ra
    // 0x8040EAE4: nop

    return;
    // 0x8040EAE4: nop

;}
RECOMP_FUNC void func_806D92F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D92F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x806D92F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D92F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D92FC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x806D9300: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806D9304: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806D9308: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806D930C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x806D9310: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806D9314: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806D9318: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806D931C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x806D9320: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x806D9324: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806D9328: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D932C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x806D9330: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806D9334: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x806D9338: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x806D933C: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x806D9340: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x806D9344: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x806D9348: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x806D934C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x806D9350: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x806D9354: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x806D9358: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x806D935C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806D9360: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x806D9364: jalr        $t9
    // 0x806D9368: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806D9368: nop

    after_0:
    // 0x806D936C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806D9370: jal         0x80067BBC
    // 0x806D9374: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x806D9374: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x806D9378: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x806D937C: jal         0x80067818
    // 0x806D9380: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x806D9380: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x806D9384: jal         0x806D8FD0
    // 0x806D9388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D8FD0(rdram, ctx);
        goto after_3;
    // 0x806D9388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806D938C: jal         0x800447C8
    // 0x806D9390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x806D9390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806D9394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D9398: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806D939C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806D93A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D93A4: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x806D93A8: jr          $ra
    // 0x806D93AC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x806D93AC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8006E49C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E49C: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8006E4A0: addiu       $v0, $v0, -0x1B54
    ctx->r2 = ADD32(ctx->r2, -0X1B54);
    // 0x8006E4A4: jr          $ra
    // 0x8006E4A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006E4A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80679028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80679028: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067902C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80679030: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80679034: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80679038: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067903C: addiu       $a0, $zero, 0x4562
    ctx->r4 = ADD32(0, 0X4562);
    // 0x80679040: jal         0x80047090
    // 0x80679044: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80679044: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80679048: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8067904C: bne         $v0, $at, L_8067905C
    if (ctx->r2 != ctx->r1) {
        // 0x80679050: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8067905C;
    }
    // 0x80679050: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80679054: b           L_80679084
    // 0x80679058: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80679084;
    // 0x80679058: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8067905C:
    // 0x8067905C: lui         $a0, 0x4562
    ctx->r4 = S32(0X4562 << 16);
    // 0x80679060: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x80679064: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80679068: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x8067906C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80679070: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80679074: jal         0x8004613C
    // 0x80679078: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80679078: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    after_1:
    // 0x8067907C: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x80679080: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80679084:
    // 0x80679084: beq         $s0, $zero, L_806790EC
    if (ctx->r16 == 0) {
        // 0x80679088: nop
    
            goto L_806790EC;
    }
    // 0x80679088: nop

    // 0x8067908C: lhu         $t0, 0xE($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XE);
    // 0x80679090: andi        $t9, $v1, 0x3FF
    ctx->r25 = ctx->r3 & 0X3FF;
    // 0x80679094: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80679098: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x8067909C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x806790A0: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    // 0x806790A4: jal         0x80047F9C
    // 0x806790A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806790A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x806790AC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x806790B0: sb          $t3, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r11;
    // 0x806790B4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x806790B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806790BC: jal         0x80678FD8
    // 0x806790C0: sw          $s0, 0x41C($t4)
    MEM_W(0X41C, ctx->r12) = ctx->r16;
    func_80678FD8(rdram, ctx);
        goto after_3;
    // 0x806790C0: sw          $s0, 0x41C($t4)
    MEM_W(0X41C, ctx->r12) = ctx->r16;
    after_3:
    // 0x806790C4: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(538, 0XF50) << 16);
    // 0x806790C8: addiu       $v0, $v0, -0x7140
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(538, 0XF50));
    // 0x806790CC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x806790D0: sw          $zero, 0x134($s0)
    MEM_W(0X134, ctx->r16) = 0;
    // 0x806790D4: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x806790D8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x806790DC: jal         0x8005FDC4
    // 0x806790E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x806790E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806790E4: b           L_806790FC
    // 0x806790E8: nop

        goto L_806790FC;
    // 0x806790E8: nop

L_806790EC:
    // 0x806790EC: jal         0x800445A4
    // 0x806790F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x806790F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x806790F4: b           L_806791B8
    // 0x806790F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806791B8;
    // 0x806790F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806790FC:
    // 0x806790FC: jal         0x80047090
    // 0x80679100: addiu       $a0, $zero, 0x4563
    ctx->r4 = ADD32(0, 0X4563);
    func_80047090(rdram, ctx);
        goto after_6;
    // 0x80679100: addiu       $a0, $zero, 0x4563
    ctx->r4 = ADD32(0, 0X4563);
    after_6:
    // 0x80679104: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80679108: bne         $v0, $at, L_80679118
    if (ctx->r2 != ctx->r1) {
        // 0x8067910C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80679118;
    }
    // 0x8067910C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80679110: b           L_80679144
    // 0x80679114: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80679144;
    // 0x80679114: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80679118:
    // 0x80679118: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8067911C: lui         $a0, 0x4563
    ctx->r4 = S32(0X4563 << 16);
    // 0x80679120: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x80679124: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80679128: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8067912C: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80679130: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x80679134: jal         0x8004613C
    // 0x80679138: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_7;
    // 0x80679138: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    after_7:
    // 0x8067913C: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x80679140: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80679144:
    // 0x80679144: beq         $s0, $zero, L_806791A8
    if (ctx->r16 == 0) {
        // 0x80679148: nop
    
            goto L_806791A8;
    }
    // 0x80679148: nop

    // 0x8067914C: lhu         $t7, 0xE($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XE);
    // 0x80679150: andi        $t6, $v1, 0x3FF
    ctx->r14 = ctx->r3 & 0X3FF;
    // 0x80679154: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80679158: andi        $t8, $t7, 0xFC00
    ctx->r24 = ctx->r15 & 0XFC00;
    // 0x8067915C: or          $t0, $t6, $t8
    ctx->r8 = ctx->r14 | ctx->r24;
    // 0x80679160: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x80679164: jal         0x80047F9C
    // 0x80679168: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80047F9C(rdram, ctx);
        goto after_8;
    // 0x80679168: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x8067916C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80679170: sb          $t9, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r25;
    // 0x80679174: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80679178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067917C: jal         0x80678FD8
    // 0x80679180: sw          $s0, 0x420($t1)
    MEM_W(0X420, ctx->r9) = ctx->r16;
    func_80678FD8(rdram, ctx);
        goto after_9;
    // 0x80679180: sw          $s0, 0x420($t1)
    MEM_W(0X420, ctx->r9) = ctx->r16;
    after_9:
    // 0x80679184: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80679188: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8067918C: sw          $zero, 0x134($s0)
    MEM_W(0X134, ctx->r16) = 0;
    // 0x80679190: sh          $t3, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r11;
    // 0x80679194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80679198: jal         0x8005FDC4
    // 0x8067919C: sw          $t2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r10;
    func_8005FDC4(rdram, ctx);
        goto after_10;
    // 0x8067919C: sw          $t2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r10;
    after_10:
    // 0x806791A0: b           L_806791B8
    // 0x806791A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806791B8;
    // 0x806791A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806791A8:
    // 0x806791A8: jal         0x800445A4
    // 0x806791AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800445A4(rdram, ctx);
        goto after_11;
    // 0x806791AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x806791B0: b           L_806791B8
    // 0x806791B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806791B8;
    // 0x806791B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806791B8:
    // 0x806791B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806791BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806791C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806791C4: jr          $ra
    // 0x806791C8: nop

    return;
    // 0x806791C8: nop

;}
RECOMP_FUNC void func_805846CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805846CC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805846D0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805846D4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805846D8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805846DC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805846E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805846E4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805846E8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805846EC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805846F0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805846F4: jr          $ra
    // 0x805846F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805846F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8044ADEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044ADEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044ADF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044ADF4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044ADF8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044ADFC: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044AE00: lw          $a1, 0x6A60($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A60);
    // 0x8044AE04: beq         $a1, $zero, L_8044AE1C
    if (ctx->r5 == 0) {
        // 0x8044AE08: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044AE1C;
    }
    // 0x8044AE08: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044AE0C: jal         0x80050A2C
    // 0x8044AE10: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044AE10: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044AE14: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044AE18: sw          $zero, 0x6A60($v1)
    MEM_W(0X6A60, ctx->r3) = 0;
L_8044AE1C:
    // 0x8044AE1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044AE20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044AE24: jr          $ra
    // 0x8044AE28: nop

    return;
    // 0x8044AE28: nop

;}
RECOMP_FUNC void func_807ADD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ADD60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807ADD64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807ADD68: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807ADD6C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x807ADD70: lw          $a0, -0x7CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE8);
    // 0x807ADD74: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x807ADD78: jal         0x807ADCC8
    // 0x807ADD7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807ADCC8(rdram, ctx);
        goto after_0;
    // 0x807ADD7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807ADD80: beq         $v0, $zero, L_807ADD90
    if (ctx->r2 == 0) {
        // 0x807ADD84: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807ADD90;
    }
    // 0x807ADD84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807ADD88: b           L_807ADE28
    // 0x807ADD8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807ADE28;
    // 0x807ADD8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807ADD90:
    // 0x807ADD90: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x807ADD94: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x807ADD98: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807ADD9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807ADDA0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807ADDA4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x807ADDA8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x807ADDAC: lwc1        $f18, 0x10($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X10);
    // 0x807ADDB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807ADDB4: jal         0x80065954
    // 0x807ADDB8: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x807ADDB8: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    after_1:
    // 0x807ADDBC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x807ADDC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807ADDC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807ADDC8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x807ADDCC: nop

    // 0x807ADDD0: bc1fl       L_807ADE28
    if (!c1cs) {
        // 0x807ADDD4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807ADE28;
    }
    goto skip_0;
    // 0x807ADDD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x807ADDD8: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x807ADDDC: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x807ADDE0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807ADDE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807ADDE8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807ADDEC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x807ADDF0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807ADDF4: lwc1        $f4, 0x14($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X14);
    // 0x807ADDF8: jal         0x80065954
    // 0x807ADDFC: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x807ADDFC: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_2:
    // 0x807ADE00: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x807ADE04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807ADE08: nop

    // 0x807ADE0C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x807ADE10: nop

    // 0x807ADE14: bc1fl       L_807ADE28
    if (!c1cs) {
        // 0x807ADE18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807ADE28;
    }
    goto skip_1;
    // 0x807ADE18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x807ADE1C: b           L_807ADE28
    // 0x807ADE20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807ADE28;
    // 0x807ADE20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807ADE24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807ADE28:
    // 0x807ADE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807ADE2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807ADE30: jr          $ra
    // 0x807ADE34: nop

    return;
    // 0x807ADE34: nop

;}
RECOMP_FUNC void func_804290A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804290A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804290A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804290AC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804290B0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804290B4: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(41, 0X1E08) << 16);
    // 0x804290B8: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804290BC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804290C0: addiu       $t7, $t7, -0x68B8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(41, 0X1E08));
    // 0x804290C4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804290C8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804290CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804290D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804290D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804290D8: jal         0x80429040
    // 0x804290DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80429040(rdram, ctx);
        goto after_0;
    // 0x804290DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804290E0: jal         0x80428D54
    // 0x804290E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80428D54(rdram, ctx);
        goto after_1;
    // 0x804290E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804290E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804290EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804290F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804290F4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x804290F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804290FC: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80429100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80429104: jr          $ra
    // 0x80429108: nop

    return;
    // 0x80429108: nop

;}
RECOMP_FUNC void func_805AAC18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AAC18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AAC1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AAC20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805AAC24: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805AAC28: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x805AAC2C: jal         0x80047090
    // 0x805AAC30: addiu       $a0, $zero, 0x40B4
    ctx->r4 = ADD32(0, 0X40B4);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805AAC30: addiu       $a0, $zero, 0x40B4
    ctx->r4 = ADD32(0, 0X40B4);
    after_0:
    // 0x805AAC34: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x805AAC38: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x805AAC3C: beq         $v0, $at, L_805AACC8
    if (ctx->r2 == ctx->r1) {
        // 0x805AAC40: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_805AACC8;
    }
    // 0x805AAC40: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805AAC44: lui         $at, 0x40B4
    ctx->r1 = S32(0X40B4 << 16);
    // 0x805AAC48: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x805AAC4C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x805AAC50: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x805AAC54: jal         0x8004613C
    // 0x805AAC58: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x805AAC58: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    after_1:
    // 0x805AAC5C: beq         $v0, $zero, L_805AACC8
    if (ctx->r2 == 0) {
        // 0x805AAC60: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805AACC8;
    }
    // 0x805AAC60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805AAC64: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805AAC68: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x805AAC6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805AAC70: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x805AAC74: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    // 0x805AAC78: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x805AAC7C: beq         $a1, $zero, L_805AAC94
    if (ctx->r5 == 0) {
        // 0x805AAC80: swc1        $f6, 0x70($v0)
        MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
            goto L_805AAC94;
    }
    // 0x805AAC80: swc1        $f6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
    // 0x805AAC84: beq         $a1, $at, L_805AACA8
    if (ctx->r5 == ctx->r1) {
        // 0x805AAC88: lui         $t6, 0x805B
        ctx->r14 = S32(RELOC_HI16(432, 0XF4) << 16);
            goto L_805AACA8;
    }
    // 0x805AAC88: lui         $t6, 0x805B
    ctx->r14 = S32(RELOC_HI16(432, 0XF4) << 16);
    // 0x805AAC8C: b           L_805AACCC
    // 0x805AAC90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805AACCC;
    // 0x805AAC90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805AAC94:
    // 0x805AAC94: jal         0x805AA478
    // 0x805AAC98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AA478(rdram, ctx);
        goto after_2;
    // 0x805AAC98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x805AAC9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AACA0: b           L_805AACCC
    // 0x805AACA4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_805AACCC;
    // 0x805AACA4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_805AACA8:
    // 0x805AACA8: addiu       $t6, $t6, -0x5C1C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(432, 0XF4));
    // 0x805AACAC: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x805AACB0: jal         0x80044194
    // 0x805AACB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_3;
    // 0x805AACB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x805AACB8: b           L_805AACCC
    // 0x805AACBC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_805AACCC;
    // 0x805AACBC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x805AACC0: b           L_805AACCC
    // 0x805AACC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805AACCC;
    // 0x805AACC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805AACC8:
    // 0x805AACC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805AACCC:
    // 0x805AACCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AACD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805AACD4: jr          $ra
    // 0x805AACD8: nop

    return;
    // 0x805AACD8: nop

    // 0x805AACDC: nop

;}
RECOMP_FUNC void func_8044BBB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BBB0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8044BBB4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8044BBB8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8044BBBC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8044BBC0: addiu       $s3, $sp, 0x38
    ctx->r19 = ADD32(ctx->r29, 0X38);
    // 0x8044BBC4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8044BBC8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8044BBCC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8044BBD0: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8044BBD4: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8044BBD8: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8044BBDC: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8044BBE0: jal         0x800667D4
    // 0x8044BBE4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800667D4(rdram, ctx);
        goto after_0;
    // 0x8044BBE4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x8044BBE8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8044BBEC: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8044BBF0: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x8044BBF4: lh          $t8, 0x4($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X4);
    // 0x8044BBF8: lh          $t7, 0x4($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X4);
    // 0x8044BBFC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8044BC00: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8044BC04: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8044BC08: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044BC0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8044BC10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8044BC14: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8044BC18: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8044BC1C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8044BC20: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8044BC24: lh          $t9, 0x4($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X4);
    // 0x8044BC28: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8044BC2C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8044BC30: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8044BC34: jal         0x8044BB6C
    // 0x8044BC38: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_8044BB6C(rdram, ctx);
        goto after_1;
    // 0x8044BC38: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8044BC3C: lh          $t2, 0x6($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X6);
    // 0x8044BC40: lh          $t0, 0x6($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X6);
    // 0x8044BC44: lh          $t1, 0x6($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X6);
    // 0x8044BC48: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8044BC4C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8044BC50: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8044BC54: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8044BC58: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8044BC5C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8044BC60: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044BC64: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8044BC68: lh          $t3, 0x6($s5)
    ctx->r11 = MEM_H(ctx->r21, 0X6);
    // 0x8044BC6C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8044BC70: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8044BC74: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8044BC78: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8044BC7C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8044BC80: jal         0x8044BB6C
    // 0x8044BC84: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_8044BB6C(rdram, ctx);
        goto after_2;
    // 0x8044BC84: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8044BC88: lh          $t6, 0x8($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X8);
    // 0x8044BC8C: lh          $t4, 0x8($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X8);
    // 0x8044BC90: lh          $t5, 0x8($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X8);
    // 0x8044BC94: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8044BC98: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8044BC9C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8044BCA0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8044BCA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8044BCA8: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x8044BCAC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044BCB0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8044BCB4: lh          $t7, 0x8($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X8);
    // 0x8044BCB8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8044BCBC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8044BCC0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8044BCC4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8044BCC8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8044BCCC: jal         0x8044BB6C
    // 0x8044BCD0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_8044BB6C(rdram, ctx);
        goto after_3;
    // 0x8044BCD0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8044BCD4: lh          $t0, 0xA($s4)
    ctx->r8 = MEM_H(ctx->r20, 0XA);
    // 0x8044BCD8: lh          $t8, 0xA($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XA);
    // 0x8044BCDC: lh          $t9, 0xA($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XA);
    // 0x8044BCE0: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8044BCE4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8044BCE8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8044BCEC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8044BCF0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8044BCF4: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8044BCF8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044BCFC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8044BD00: lh          $t1, 0xA($s5)
    ctx->r9 = MEM_H(ctx->r21, 0XA);
    // 0x8044BD04: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8044BD08: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8044BD0C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8044BD10: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8044BD14: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8044BD18: jal         0x8044BB6C
    // 0x8044BD1C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_8044BB6C(rdram, ctx);
        goto after_4;
    // 0x8044BD1C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x8044BD20: lh          $t4, 0xC($s4)
    ctx->r12 = MEM_H(ctx->r20, 0XC);
    // 0x8044BD24: lh          $t2, 0xC($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XC);
    // 0x8044BD28: lh          $t3, 0xC($s2)
    ctx->r11 = MEM_H(ctx->r18, 0XC);
    // 0x8044BD2C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8044BD30: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8044BD34: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8044BD38: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8044BD3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8044BD40: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8044BD44: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044BD48: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8044BD4C: lh          $t5, 0xC($s5)
    ctx->r13 = MEM_H(ctx->r21, 0XC);
    // 0x8044BD50: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8044BD54: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8044BD58: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8044BD5C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8044BD60: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8044BD64: jal         0x8044BB6C
    // 0x8044BD68: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_8044BB6C(rdram, ctx);
        goto after_5;
    // 0x8044BD68: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8044BD6C: lh          $t8, 0xE($s4)
    ctx->r24 = MEM_H(ctx->r20, 0XE);
    // 0x8044BD70: lh          $t6, 0xE($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XE);
    // 0x8044BD74: lh          $t7, 0xE($s2)
    ctx->r15 = MEM_H(ctx->r18, 0XE);
    // 0x8044BD78: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8044BD7C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8044BD80: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8044BD84: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8044BD88: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8044BD8C: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // 0x8044BD90: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044BD94: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8044BD98: lh          $t9, 0xE($s5)
    ctx->r25 = MEM_H(ctx->r21, 0XE);
    // 0x8044BD9C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8044BDA0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8044BDA4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8044BDA8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8044BDAC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8044BDB0: jal         0x8044BB6C
    // 0x8044BDB4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_8044BB6C(rdram, ctx);
        goto after_6;
    // 0x8044BDB4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x8044BDB8: lh          $t2, 0x2($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X2);
    // 0x8044BDBC: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x8044BDC0: lh          $t1, 0x2($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X2);
    // 0x8044BDC4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8044BDC8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8044BDCC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8044BDD0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8044BDD4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8044BDD8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x8044BDDC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044BDE0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8044BDE4: lh          $t3, 0x2($s5)
    ctx->r11 = MEM_H(ctx->r21, 0X2);
    // 0x8044BDE8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8044BDEC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8044BDF0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8044BDF4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8044BDF8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8044BDFC: jal         0x8006692C
    // 0x8044BE00: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_8006692C(rdram, ctx);
        goto after_7;
    // 0x8044BE00: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x8044BE04: lh          $t6, 0x10($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X10);
    // 0x8044BE08: lh          $t4, 0x10($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X10);
    // 0x8044BE0C: lh          $t5, 0x10($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X10);
    // 0x8044BE10: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8044BE14: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8044BE18: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8044BE1C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8044BE20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8044BE24: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x8044BE28: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044BE2C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8044BE30: lh          $t7, 0x10($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X10);
    // 0x8044BE34: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8044BE38: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8044BE3C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8044BE40: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8044BE44: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8044BE48: jal         0x8044BB6C
    // 0x8044BE4C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_8044BB6C(rdram, ctx);
        goto after_8;
    // 0x8044BE4C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x8044BE50: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8044BE54: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8044BE58: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8044BE5C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8044BE60: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8044BE64: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8044BE68: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8044BE6C: jr          $ra
    // 0x8044BE70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8044BE70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_806ECCD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ECCD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806ECCDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806ECCE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806ECCE4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806ECCE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806ECCEC: jal         0x800577D8
    // 0x806ECCF0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806ECCF0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x806ECCF4: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806ECCF8: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x806ECCFC: jal         0x80065ABC
    // 0x806ECD00: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x806ECD00: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_1:
    // 0x806ECD04: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806ECD08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECD0C: jal         0x80049D74
    // 0x806ECD10: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x806ECD10: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_2:
    // 0x806ECD14: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806ECD18: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x806ECD1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECD20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806ECD24: jal         0x8004D150
    // 0x806ECD28: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x806ECD28: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x806ECD2C: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x806ECD30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECD34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806ECD38: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806ECD3C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x806ECD40: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x806ECD44: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x806ECD48: beql        $t0, $zero, L_806ECDCC
    if (ctx->r8 == 0) {
        // 0x806ECD4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806ECDCC;
    }
    goto skip_0;
    // 0x806ECD4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806ECD50: jal         0x8004D618
    // 0x806ECD54: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x806ECD54: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_4:
    // 0x806ECD58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECD5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECD60: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806ECD64: jal         0x806ED360
    // 0x806ECD68: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_5;
    // 0x806ECD68: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x806ECD6C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x806ECD70: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x806ECD74: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x806ECD78: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x806ECD7C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806ECD80: lbu         $t1, 0xF0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XF0);
    // 0x806ECD84: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x806ECD88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806ECD8C: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x806ECD90: addiu       $t3, $t2, 0x20
    ctx->r11 = ADD32(ctx->r10, 0X20);
    // 0x806ECD94: sb          $t3, 0xF0($v0)
    MEM_B(0XF0, ctx->r2) = ctx->r11;
    // 0x806ECD98: lw          $t4, 0x478($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X478);
    // 0x806ECD9C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x806ECDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECDA4: sb          $zero, 0xF2($t4)
    MEM_B(0XF2, ctx->r12) = 0;
    // 0x806ECDA8: sb          $t5, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r13;
    // 0x806ECDAC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806ECDB0: sb          $t6, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r14;
    // 0x806ECDB4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806ECDB8: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
    // 0x806ECDBC: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806ECDC0: jal         0x806EC098
    // 0x806ECDC4: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    func_806EC098(rdram, ctx);
        goto after_6;
    // 0x806ECDC4: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    after_6:
    // 0x806ECDC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ECDCC:
    // 0x806ECDCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806ECDD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806ECDD4: jr          $ra
    // 0x806ECDD8: nop

    return;
    // 0x806ECDD8: nop

;}
RECOMP_FUNC void func_806AE53C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AE53C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806AE540: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AE544: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806AE548: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806AE54C: jal         0x8004700C
    // 0x806AE550: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806AE550: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x806AE554: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x806AE558: beq         $v0, $zero, L_806AE7AC
    if (ctx->r2 == 0) {
        // 0x806AE55C: lw          $v1, 0x1F4($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X1F4);
            goto L_806AE7AC;
    }
    // 0x806AE55C: lw          $v1, 0x1F4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1F4);
    // 0x806AE560: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
    // 0x806AE564: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806AE568: sltiu       $at, $t7, 0x3C
    ctx->r1 = ctx->r15 < 0X3C ? 1 : 0;
    // 0x806AE56C: bne         $at, $zero, L_806AE76C
    if (ctx->r1 != 0) {
        // 0x806AE570: sw          $t7, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r15;
            goto L_806AE76C;
    }
    // 0x806AE570: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
    // 0x806AE574: jal         0x800653D8
    // 0x806AE578: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x806AE578: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x806AE57C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x806AE580: beq         $t9, $zero, L_806AE5A4
    if (ctx->r25 == 0) {
        // 0x806AE584: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_806AE5A4;
    }
    // 0x806AE584: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806AE588: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806AE58C: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x806AE590: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x806AE594: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x806AE598: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x806AE59C: b           L_806AE768
    // 0x806AE5A0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
        goto L_806AE768;
    // 0x806AE5A0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_806AE5A4:
    // 0x806AE5A4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x806AE5A8: lwc1        $f4, 0x84($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X84);
    // 0x806AE5AC: lwc1        $f6, 0x84($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X84);
    // 0x806AE5B0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x806AE5B4: jal         0x80065954
    // 0x806AE5B8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x806AE5B8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x806AE5BC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x806AE5C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806AE5C4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806AE5C8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806AE5CC: nop

    // 0x806AE5D0: bc1f        L_806AE618
    if (!c1cs) {
        // 0x806AE5D4: nop
    
            goto L_806AE618;
    }
    // 0x806AE5D4: nop

    // 0x806AE5D8: jal         0x800653D8
    // 0x806AE5DC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x806AE5DC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x806AE5E0: andi        $t1, $v0, 0x1F
    ctx->r9 = ctx->r2 & 0X1F;
    // 0x806AE5E4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x806AE5E8: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F68) << 16);
    // 0x806AE5EC: lwc1        $f18, -0x358($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F68));
    // 0x806AE5F0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806AE5F4: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F6C) << 16);
    // 0x806AE5F8: lwc1        $f6, -0x354($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F6C));
    // 0x806AE5FC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806AE600: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x806AE604: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x806AE608: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806AE60C: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806AE610: b           L_806AE650
    // 0x806AE614: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_806AE650;
    // 0x806AE614: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_806AE618:
    // 0x806AE618: jal         0x800653D8
    // 0x806AE61C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x806AE61C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x806AE620: andi        $t2, $v0, 0x1F
    ctx->r10 = ctx->r2 & 0X1F;
    // 0x806AE624: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x806AE628: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F70) << 16);
    // 0x806AE62C: lwc1        $f4, -0x350($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F70));
    // 0x806AE630: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806AE634: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806AE638: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    // 0x806AE63C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806AE640: nop

    // 0x806AE644: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806AE648: nop

    // 0x806AE64C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_806AE650:
    // 0x806AE650: lwc1        $f16, 0x84($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X84);
    // 0x806AE654: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x806AE658: lwc1        $f10, 0x84($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806AE65C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F74) << 16);
    // 0x806AE660: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806AE664: nop

    // 0x806AE668: bc1fl       L_806AE678
    if (!c1cs) {
        // 0x806AE66C: swc1        $f0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
            goto L_806AE678;
    }
    goto skip_0;
    // 0x806AE66C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    skip_0:
    // 0x806AE670: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x806AE674: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_806AE678:
    // 0x806AE678: lwc1        $f18, -0x34C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F74));
    // 0x806AE67C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x806AE680: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x806AE684: lwc1        $f8, 0x88($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
    // 0x806AE688: lwc1        $f6, 0x88($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X88);
    // 0x806AE68C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x806AE690: jal         0x80065954
    // 0x806AE694: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x806AE694: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_5:
    // 0x806AE698: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x806AE69C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806AE6A0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806AE6A4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806AE6A8: nop

    // 0x806AE6AC: bc1f        L_806AE6F4
    if (!c1cs) {
        // 0x806AE6B0: nop
    
            goto L_806AE6F4;
    }
    // 0x806AE6B0: nop

    // 0x806AE6B4: jal         0x800653D8
    // 0x806AE6B8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_6;
    // 0x806AE6B8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_6:
    // 0x806AE6BC: andi        $t3, $v0, 0x1F
    ctx->r11 = ctx->r2 & 0X1F;
    // 0x806AE6C0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x806AE6C4: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F78) << 16);
    // 0x806AE6C8: lwc1        $f4, -0x348($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F78));
    // 0x806AE6CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806AE6D0: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F7C) << 16);
    // 0x806AE6D4: lwc1        $f8, -0x344($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F7C));
    // 0x806AE6D8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806AE6DC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806AE6E0: lwc1        $f16, 0x18($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X18);
    // 0x806AE6E4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806AE6E8: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806AE6EC: b           L_806AE72C
    // 0x806AE6F0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
        goto L_806AE72C;
    // 0x806AE6F0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
L_806AE6F4:
    // 0x806AE6F4: jal         0x800653D8
    // 0x806AE6F8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_7;
    // 0x806AE6F8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_7:
    // 0x806AE6FC: andi        $t4, $v0, 0x1F
    ctx->r12 = ctx->r2 & 0X1F;
    // 0x806AE700: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x806AE704: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F80) << 16);
    // 0x806AE708: lwc1        $f6, -0x340($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F80));
    // 0x806AE70C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806AE710: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806AE714: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x806AE718: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806AE71C: nop

    // 0x806AE720: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806AE724: nop

    // 0x806AE728: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
L_806AE72C:
    // 0x806AE72C: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x806AE730: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806AE734: lwc1        $f16, 0x88($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X88);
    // 0x806AE738: lwc1        $f6, 0x88($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X88);
    // 0x806AE73C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F84) << 16);
    // 0x806AE740: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806AE744: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806AE748: nop

    // 0x806AE74C: bc1fl       L_806AE75C
    if (!c1cs) {
        // 0x806AE750: swc1        $f0, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
            goto L_806AE75C;
    }
    goto skip_1;
    // 0x806AE750: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    skip_1:
    // 0x806AE754: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x806AE758: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_806AE75C:
    // 0x806AE75C: lwc1        $f8, -0x33C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F84));
    // 0x806AE760: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x806AE764: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
L_806AE768:
    // 0x806AE768: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
L_806AE76C:
    // 0x806AE76C: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x806AE770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AE774: jal         0x806AE4CC
    // 0x806AE778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806AE4CC(rdram, ctx);
        goto after_8;
    // 0x806AE778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x806AE77C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AE780: jal         0x806AE4CC
    // 0x806AE784: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806AE4CC(rdram, ctx);
        goto after_9;
    // 0x806AE784: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x806AE788: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F88) << 16);
    // 0x806AE78C: lwc1        $f0, -0x338($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F88));
    // 0x806AE790: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806AE794: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806AE798: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806AE79C: nop

    // 0x806AE7A0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806AE7A4: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x806AE7A8: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
L_806AE7AC:
    // 0x806AE7AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806AE7B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806AE7B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806AE7B8: jr          $ra
    // 0x806AE7BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x806AE7BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001E70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E70C: lbu         $t6, 0x12CA($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X12CA);
    // 0x8001E710: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001E714: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001E718: beq         $t6, $zero, L_8001E750
    if (ctx->r14 == 0) {
        // 0x8001E71C: addiu       $v0, $a0, 0x12CC
        ctx->r2 = ADD32(ctx->r4, 0X12CC);
            goto L_8001E750;
    }
    // 0x8001E71C: addiu       $v0, $a0, 0x12CC
    ctx->r2 = ADD32(ctx->r4, 0X12CC);
    // 0x8001E720: addiu       $v0, $a0, 0x12CC
    ctx->r2 = ADD32(ctx->r4, 0X12CC);
    // 0x8001E724: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001E728: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8001E72C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8001E730: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001E734: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x8001E738: nop

    // 0x8001E73C: bc1f        L_8001E780
    if (!c1cs) {
        // 0x8001E740: nop
    
            goto L_8001E780;
    }
    // 0x8001E740: nop

    // 0x8001E744: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
    // 0x8001E748: jr          $ra
    // 0x8001E74C: sb          $zero, 0x12CA($a0)
    MEM_B(0X12CA, ctx->r4) = 0;
    return;
    // 0x8001E74C: sb          $zero, 0x12CA($a0)
    MEM_B(0X12CA, ctx->r4) = 0;
L_8001E750:
    // 0x8001E750: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001E754: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001E758: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E75C: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8001E760: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8001E764: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001E768: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8001E76C: nop

    // 0x8001E770: bc1f        L_8001E780
    if (!c1cs) {
        // 0x8001E774: nop
    
            goto L_8001E780;
    }
    // 0x8001E774: nop

    // 0x8001E778: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8001E77C: sb          $t7, 0x12CA($a0)
    MEM_B(0X12CA, ctx->r4) = ctx->r15;
L_8001E780:
    // 0x8001E780: jr          $ra
    // 0x8001E784: nop

    return;
    // 0x8001E784: nop

;}
RECOMP_FUNC void func_8057A738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057A738: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8057A73C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8057A740: lw          $v0, -0x762C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X762C);
    // 0x8057A744: lw          $t6, -0x7628($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7628);
    // 0x8057A748: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8057A74C: addiu       $a0, $a0, 0x7EA8
    ctx->r4 = ADD32(ctx->r4, 0X7EA8);
    // 0x8057A750: beq         $v0, $t6, L_8057A760
    if (ctx->r2 == ctx->r14) {
        // 0x8057A754: lui         $v1, 0x800F
        ctx->r3 = S32(0X800F << 16);
            goto L_8057A760;
    }
    // 0x8057A754: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8057A758: jr          $ra
    // 0x8057A75C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8057A75C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057A760:
    // 0x8057A760: addiu       $v1, $v1, 0x7F18
    ctx->r3 = ADD32(ctx->r3, 0X7F18);
    // 0x8057A764: lw          $t7, 0xB34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB34);
L_8057A768:
    // 0x8057A768: beql        $v0, $t7, L_8057A77C
    if (ctx->r2 == ctx->r15) {
        // 0x8057A76C: lw          $t8, 0xB38($a0)
        ctx->r24 = MEM_W(ctx->r4, 0XB38);
            goto L_8057A77C;
    }
    goto skip_0;
    // 0x8057A76C: lw          $t8, 0xB38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XB38);
    skip_0:
    // 0x8057A770: jr          $ra
    // 0x8057A774: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8057A774: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8057A778: lw          $t8, 0xB38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XB38);
L_8057A77C:
    // 0x8057A77C: beql        $v0, $t8, L_8057A790
    if (ctx->r2 == ctx->r24) {
        // 0x8057A780: lw          $t9, 0xB3C($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XB3C);
            goto L_8057A790;
    }
    goto skip_1;
    // 0x8057A780: lw          $t9, 0xB3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XB3C);
    skip_1:
    // 0x8057A784: jr          $ra
    // 0x8057A788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8057A788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8057A78C: lw          $t9, 0xB3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XB3C);
L_8057A790:
    // 0x8057A790: beql        $v0, $t9, L_8057A7A4
    if (ctx->r2 == ctx->r25) {
        // 0x8057A794: lw          $t0, 0xB40($a0)
        ctx->r8 = MEM_W(ctx->r4, 0XB40);
            goto L_8057A7A4;
    }
    goto skip_2;
    // 0x8057A794: lw          $t0, 0xB40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XB40);
    skip_2:
    // 0x8057A798: jr          $ra
    // 0x8057A79C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8057A79C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8057A7A0: lw          $t0, 0xB40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XB40);
L_8057A7A4:
    // 0x8057A7A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8057A7A8: beq         $v0, $t0, L_8057A7B8
    if (ctx->r2 == ctx->r8) {
        // 0x8057A7AC: nop
    
            goto L_8057A7B8;
    }
    // 0x8057A7AC: nop

    // 0x8057A7B0: jr          $ra
    // 0x8057A7B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8057A7B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057A7B8:
    // 0x8057A7B8: bnel        $a0, $v1, L_8057A768
    if (ctx->r4 != ctx->r3) {
        // 0x8057A7BC: lw          $t7, 0xB34($a0)
        ctx->r15 = MEM_W(ctx->r4, 0XB34);
            goto L_8057A768;
    }
    goto skip_3;
    // 0x8057A7BC: lw          $t7, 0xB34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB34);
    skip_3:
    // 0x8057A7C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8057A7C4: bnel        $v0, $at, L_8057A7D8
    if (ctx->r2 != ctx->r1) {
        // 0x8057A7C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8057A7D8;
    }
    goto skip_4;
    // 0x8057A7C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8057A7CC: jr          $ra
    // 0x8057A7D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x8057A7D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8057A7D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8057A7D8:
    // 0x8057A7D8: jr          $ra
    // 0x8057A7DC: nop

    return;
    // 0x8057A7DC: nop

;}
RECOMP_FUNC void func_8051F708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F708: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051F70C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051F710: jal         0x80045A34
    // 0x8051F714: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8051F714: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8051F718: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8051F71C: jal         0x80064D1C
    // 0x8051F720: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x8051F720: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8051F724: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8051F728: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8051F72C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051F730: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051F734: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8051F738: jr          $ra
    // 0x8051F73C: nop

    return;
    // 0x8051F73C: nop

;}
