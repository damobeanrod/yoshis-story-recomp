#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_807985F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807985F0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x807985F4: addiu       $at, $zero, 0x4695
    ctx->r1 = ADD32(0, 0X4695);
    // 0x807985F8: beq         $v0, $at, L_80798614
    if (ctx->r2 == ctx->r1) {
        // 0x807985FC: addiu       $at, $zero, 0x471F
        ctx->r1 = ADD32(0, 0X471F);
            goto L_80798614;
    }
    // 0x807985FC: addiu       $at, $zero, 0x471F
    ctx->r1 = ADD32(0, 0X471F);
    // 0x80798600: beq         $v0, $at, L_80798614
    if (ctx->r2 == ctx->r1) {
        // 0x80798604: addiu       $at, $zero, 0x4720
        ctx->r1 = ADD32(0, 0X4720);
            goto L_80798614;
    }
    // 0x80798604: addiu       $at, $zero, 0x4720
    ctx->r1 = ADD32(0, 0X4720);
    // 0x80798608: beq         $v0, $at, L_80798614
    if (ctx->r2 == ctx->r1) {
        // 0x8079860C: addiu       $at, $zero, 0x4721
        ctx->r1 = ADD32(0, 0X4721);
            goto L_80798614;
    }
    // 0x8079860C: addiu       $at, $zero, 0x4721
    ctx->r1 = ADD32(0, 0X4721);
    // 0x80798610: bne         $v0, $at, L_80798620
    if (ctx->r2 != ctx->r1) {
        // 0x80798614: lui         $v0, 0x807A
        ctx->r2 = S32(RELOC_HI16(820, 0X274) << 16);
            goto L_80798620;
    }
L_80798614:
    // 0x80798614: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(820, 0X274) << 16);
    // 0x80798618: jr          $ra
    // 0x8079861C: addiu       $v0, $v0, -0x779C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(820, 0X274));
    return;
    // 0x8079861C: addiu       $v0, $v0, -0x779C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(820, 0X274));
L_80798620:
    // 0x80798620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80798624: jr          $ra
    // 0x80798628: nop

    return;
    // 0x80798628: nop

;}
RECOMP_FUNC void ltruncf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082068: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8008206C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80082070: jr          $ra
    // 0x80082074: nop

    return;
    // 0x80082074: nop

;}
RECOMP_FUNC void func_8040C1F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C1F8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8040C1FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040C200: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040C204: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8040C208: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8040C20C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8040C210: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8040C214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8040C218: jal         0x8004921C
    // 0x8040C21C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8040C21C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8040C220: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x8040C224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040C228: jal         0x8004921C
    // 0x8040C22C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8040C22C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8040C230: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x8040C234: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8040C238: lbu         $t1, 0x145($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X145);
    // 0x8040C23C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8040C240: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x8040C244: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8040C248: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8040C24C: lw          $t3, 0x80($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X80);
    // 0x8040C250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8040C254: mflo        $t0
    ctx->r8 = lo;
    // 0x8040C258: nop

    // 0x8040C25C: nop

    // 0x8040C260: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8040C264: mflo        $t2
    ctx->r10 = lo;
    // 0x8040C268: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8040C26C: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
    // 0x8040C270: lw          $t5, 0x88($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X88);
    // 0x8040C274: jal         0x800773A4
    // 0x8040C278: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    func_800773A4(rdram, ctx);
        goto after_2;
    // 0x8040C278: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    after_2:
    // 0x8040C27C: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8040C280: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8040C284: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040C288: jal         0x8007711C
    // 0x8040C28C: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x8040C28C: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    after_3:
    // 0x8040C290: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8040C294: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8040C298: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x8040C29C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8040C2A0: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x8040C2A4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8040C2A8: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8040C2AC: ori         $t3, $t3, 0x20
    ctx->r11 = ctx->r11 | 0X20;
    // 0x8040C2B0: lui         $t2, 0xF550
    ctx->r10 = S32(0XF550 << 16);
    // 0x8040C2B4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8040C2B8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8040C2BC: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8040C2C0: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8040C2C4: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8040C2C8: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x8040C2CC: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x8040C2D0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8040C2D4: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8040C2D8: lui         $t0, 0x73B
    ctx->r8 = S32(0X73B << 16);
    // 0x8040C2DC: ori         $t0, $t0, 0xF800
    ctx->r8 = ctx->r8 | 0XF800;
    // 0x8040C2E0: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8040C2E4: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x8040C2E8: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8040C2EC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8040C2F0: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8040C2F4: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8040C2F8: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x8040C2FC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8040C300: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x8040C304: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x8040C308: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8040C30C: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8040C310: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8040C314: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8040C318: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8040C31C: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x8040C320: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8040C324: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8040C328: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8040C32C: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8040C330: ori         $t1, $t1, 0xC3BC
    ctx->r9 = ctx->r9 | 0XC3BC;
    // 0x8040C334: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8040C338: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x8040C33C: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8040C340: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8040C344: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x8040C348: lui         $t0, 0xF200
    ctx->r8 = S32(0XF200 << 16);
    // 0x8040C34C: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x8040C350: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8040C354: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x8040C358: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8040C35C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8040C360: lw          $t2, -0x7CE8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7CE8);
    // 0x8040C364: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8040C368: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8040C36C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8040C370: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8040C374: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8040C378: nop

    // 0x8040C37C: bgez        $t4, L_8040C398
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8040C380: sw          $t4, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r12;
            goto L_8040C398;
    }
    // 0x8040C380: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x8040C384: lh          $t5, 0x13E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X13E);
    // 0x8040C388: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8040C38C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8040C390: b           L_8040C3A0
    // 0x8040C394: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
        goto L_8040C3A0;
    // 0x8040C394: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
L_8040C398:
    // 0x8040C398: lh          $t7, 0x13E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X13E);
    // 0x8040C39C: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
L_8040C3A0:
    // 0x8040C3A0: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8040C3A4: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8040C3A8: bltz        $t8, L_8040C41C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8040C3AC: slti        $at, $t9, 0xF0
        ctx->r1 = SIGNED(ctx->r25) < 0XF0 ? 1 : 0;
            goto L_8040C41C;
    }
    // 0x8040C3AC: slti        $at, $t9, 0xF0
    ctx->r1 = SIGNED(ctx->r25) < 0XF0 ? 1 : 0;
    // 0x8040C3B0: beq         $at, $zero, L_8040C41C
    if (ctx->r1 == 0) {
        // 0x8040C3B4: addu        $t0, $t8, $t9
        ctx->r8 = ADD32(ctx->r24, ctx->r25);
            goto L_8040C41C;
    }
    // 0x8040C3B4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8040C3B8: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x8040C3BC: lh          $t1, 0x13E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X13E);
    // 0x8040C3C0: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x8040C3C4: lui         $t5, 0xE44F
    ctx->r13 = S32(0XE44F << 16);
    // 0x8040C3C8: subu        $t2, $t1, $t8
    ctx->r10 = SUB32(ctx->r9, ctx->r24);
    // 0x8040C3CC: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8040C3D0: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x8040C3D4: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x8040C3D8: ori         $t5, $t5, 0xC3BC
    ctx->r13 = ctx->r13 | 0XC3BC;
    // 0x8040C3DC: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8040C3E0: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8040C3E4: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8040C3E8: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8040C3EC: lui         $t2, 0x400
    ctx->r10 = S32(0X400 << 16);
    // 0x8040C3F0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8040C3F4: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x8040C3F8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8040C3FC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8040C400: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8040C404: ori         $t2, $t2, 0x400
    ctx->r10 = ctx->r10 | 0X400;
    // 0x8040C408: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8040C40C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8040C410: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x8040C414: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8040C418: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
L_8040C41C:
    // 0x8040C41C: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x8040C420: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x8040C424: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
    // 0x8040C428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040C42C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040C430: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8040C434: jr          $ra
    // 0x8040C438: nop

    return;
    // 0x8040C438: nop

;}
RECOMP_FUNC void func_80020BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020BD0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80020BD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80020BD8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80020BDC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80020BE0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80020BE4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80020BE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80020BEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80020BF0: lw          $v0, 0x40($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X40);
    // 0x80020BF4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80020BF8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80020BFC: addiu       $t8, $v0, 0x48
    ctx->r24 = ADD32(ctx->r2, 0X48);
    // 0x80020C00: addiu       $t9, $v0, 0x60
    ctx->r25 = ADD32(ctx->r2, 0X60);
    // 0x80020C04: addiu       $t0, $v0, 0x78
    ctx->r8 = ADD32(ctx->r2, 0X78);
    // 0x80020C08: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80020C0C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80020C10: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80020C14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80020C18: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80020C1C: jal         0x8004D6C8
    // 0x80020C20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8004D6C8(rdram, ctx);
        goto after_0;
    // 0x80020C20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80020C24: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80020C28: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80020C2C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80020C30: lbu         $v0, 0x14($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X14);
    // 0x80020C34: bnel        $v0, $zero, L_80020C5C
    if (ctx->r2 != 0) {
        // 0x80020C38: lw          $t7, 0x4($t6)
        ctx->r15 = MEM_W(ctx->r14, 0X4);
            goto L_80020C5C;
    }
    goto skip_0;
    // 0x80020C38: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    skip_0:
    // 0x80020C3C: lbu         $t3, 0x14($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X14);
    // 0x80020C40: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80020C44: bnel        $t3, $zero, L_80020C5C
    if (ctx->r11 != 0) {
        // 0x80020C48: lw          $t7, 0x4($t6)
        ctx->r15 = MEM_W(ctx->r14, 0X4);
            goto L_80020C5C;
    }
    goto skip_1;
    // 0x80020C48: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    skip_1:
    // 0x80020C4C: lbu         $t5, 0x14($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X14);
    // 0x80020C50: beql        $t5, $zero, L_80020CD4
    if (ctx->r13 == 0) {
        // 0x80020C54: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80020CD4;
    }
    goto skip_2;
    // 0x80020C54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80020C58: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
L_80020C5C:
    // 0x80020C5C: beq         $t7, $zero, L_80020C84
    if (ctx->r15 == 0) {
        // 0x80020C60: nop
    
            goto L_80020C84;
    }
    // 0x80020C60: nop

    // 0x80020C64: jal         0x80061170
    // 0x80020C68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80061170(rdram, ctx);
        goto after_1;
    // 0x80020C68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80020C6C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80020C70: lw          $t9, 0x130($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X130);
    // 0x80020C74: jalr        $t9
    // 0x80020C78: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80020C78: nop

    after_2:
    // 0x80020C7C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80020C80: lbu         $v0, 0x14($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X14);
L_80020C84:
    // 0x80020C84: beql        $v0, $zero, L_80020C9C
    if (ctx->r2 == 0) {
        // 0x80020C88: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_80020C9C;
    }
    goto skip_3;
    // 0x80020C88: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    skip_3:
    // 0x80020C8C: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x80020C90: ori         $t2, $t1, 0x400
    ctx->r10 = ctx->r9 | 0X400;
    // 0x80020C94: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x80020C98: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_80020C9C:
    // 0x80020C9C: lbu         $t4, 0x14($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X14);
    // 0x80020CA0: beql        $t4, $zero, L_80020CB8
    if (ctx->r12 == 0) {
        // 0x80020CA4: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80020CB8;
    }
    goto skip_4;
    // 0x80020CA4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x80020CA8: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x80020CAC: ori         $t6, $t5, 0x200
    ctx->r14 = ctx->r13 | 0X200;
    // 0x80020CB0: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    // 0x80020CB4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80020CB8:
    // 0x80020CB8: lbu         $t8, 0x14($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X14);
    // 0x80020CBC: beql        $t8, $zero, L_80020CD4
    if (ctx->r24 == 0) {
        // 0x80020CC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80020CD4;
    }
    goto skip_5;
    // 0x80020CC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80020CC4: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80020CC8: ori         $t0, $t9, 0x100
    ctx->r8 = ctx->r25 | 0X100;
    // 0x80020CCC: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x80020CD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80020CD4:
    // 0x80020CD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80020CD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80020CDC: jr          $ra
    // 0x80020CE0: nop

    return;
    // 0x80020CE0: nop

;}
RECOMP_FUNC void func_804EF050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF050: lwc1        $f4, 0xE0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x804EF054: lwc1        $f6, 0xDC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x804EF058: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804EF05C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804EF060: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x804EF064: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x804EF068: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x804EF06C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x804EF070: jr          $ra
    // 0x804EF074: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    return;
    // 0x804EF074: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80025724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002572C: jal         0x80024748
    // 0x80025730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024748(rdram, ctx);
        goto after_0;
    // 0x80025730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80025734: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80025738: bne         $v0, $at, L_80025754
    if (ctx->r2 != ctx->r1) {
        // 0x8002573C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80025754;
    }
    // 0x8002573C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80025740: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80025744: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80025748: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    // 0x8002574C: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80025750: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
L_80025754:
    // 0x80025754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002575C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80025760: jr          $ra
    // 0x80025764: nop

    return;
    // 0x80025764: nop

;}
RECOMP_FUNC void func_804D1454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D1454: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804D1458: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x804D145C: addiu       $v1, $a0, -0x8
    ctx->r3 = ADD32(ctx->r4, -0X8);
    // 0x804D1460: sltiu       $at, $v1, 0xFF
    ctx->r1 = ctx->r3 < 0XFF ? 1 : 0;
    // 0x804D1464: bne         $at, $zero, L_804D1470
    if (ctx->r1 != 0) {
        // 0x804D1468: nop
    
            goto L_804D1470;
    }
    // 0x804D1468: nop

    // 0x804D146C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_804D1470:
    // 0x804D1470: jr          $ra
    // 0x804D1474: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x804D1474: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void func_8042A9DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042A9DC: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8042A9E0: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x8042A9E4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8042A9E8: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8042A9EC: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
    // 0x8042A9F0: bne         $at, $zero, L_8042A9FC
    if (ctx->r1 != 0) {
        // 0x8042A9F4: sw          $v0, 0x30($a0)
        MEM_W(0X30, ctx->r4) = ctx->r2;
            goto L_8042A9FC;
    }
    // 0x8042A9F4: sw          $v0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r2;
    // 0x8042A9F8: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
L_8042A9FC:
    // 0x8042A9FC: jr          $ra
    // 0x8042AA00: nop

    return;
    // 0x8042AA00: nop

;}
RECOMP_FUNC void func_806CCC84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CCC84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CCC88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CCC8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806CCC90: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806CCC94: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x806CCC98: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x806CCC9C: jal         0x806CC888
    // 0x806CCCA0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_806CC888(rdram, ctx);
        goto after_0;
    // 0x806CCCA0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x806CCCA4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x806CCCA8: jal         0x806CC984
    // 0x806CCCAC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_806CC984(rdram, ctx);
        goto after_1;
    // 0x806CCCAC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x806CCCB0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x806CCCB4: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x806CCCB8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806CCCBC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x806CCCC0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x806CCCC4: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x806CCCC8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x806CCCCC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x806CCCD0: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x806CCCD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CCCD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CCCDC: jr          $ra
    // 0x806CCCE0: nop

    return;
    // 0x806CCCE0: nop

;}
RECOMP_FUNC void func_80740E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80740E70: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80740E74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80740E78: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80740E7C: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(751, 0X1094) << 16);
    // 0x80740E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80740E84: addiu       $t7, $t7, 0x1EF4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(751, 0X1094));
    // 0x80740E88: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80740E8C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80740E90: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80740E94: sw          $a1, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r5;
    // 0x80740E98: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80740E9C: beql        $v1, $zero, L_80740ED4
    if (ctx->r3 == 0) {
        // 0x80740EA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80740ED4;
    }
    goto skip_0;
    // 0x80740EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80740EA4: jalr        $v1
    // 0x80740EA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80740EA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80740EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80740EB0: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
    // 0x80740EB4: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80740EB8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80740EBC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80740EC0: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80740EC4: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80740EC8: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80740ECC: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x80740ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80740ED4:
    // 0x80740ED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80740ED8: jr          $ra
    // 0x80740EDC: nop

    return;
    // 0x80740EDC: nop

;}
RECOMP_FUNC void func_800684E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800684E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800684EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800684F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800684F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800684F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800684FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80068500: lh          $s2, 0x28($a0)
    ctx->r18 = MEM_H(ctx->r4, 0X28);
    // 0x80068504: addiu       $s0, $a0, 0x2C
    ctx->r16 = ADD32(ctx->r4, 0X2C);
    // 0x80068508: beql        $s2, $zero, L_8006854C
    if (ctx->r18 == 0) {
        // 0x8006850C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006854C;
    }
    goto skip_0;
    // 0x8006850C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80068510: blez        $s2, L_80068540
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80068514: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80068540;
    }
    // 0x80068514: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80068518:
    // 0x80068518: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8006851C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80068520: jalr        $t9
    // 0x80068524: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80068524: nop

    after_0:
    // 0x80068528: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006852C: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80068530: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80068534: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80068538: bne         $at, $zero, L_80068518
    if (ctx->r1 != 0) {
        // 0x8006853C: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80068518;
    }
    // 0x8006853C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80068540:
    // 0x80068540: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80068544: sh          $zero, 0x28($t7)
    MEM_H(0X28, ctx->r15) = 0;
    // 0x80068548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006854C:
    // 0x8006854C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068550: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80068554: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80068558: jr          $ra
    // 0x8006855C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006855C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __osBlockSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CA88: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008CA8C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8008CA90: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8008CA94: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x8008CA98: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008CA9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CAA0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8008CAA4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8008CAA8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8008CAAC: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x8008CAB0: jal         0x800890BC
    // 0x8008CAB4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x8008CAB4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x8008CAB8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8008CABC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8008CAC0: beq         $t8, $zero, L_8008CAD0
    if (ctx->r24 == 0) {
        // 0x8008CAC4: nop
    
            goto L_8008CAD0;
    }
    // 0x8008CAC4: nop

    // 0x8008CAC8: b           L_8008CB68
    // 0x8008CACC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8008CB68;
    // 0x8008CACC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8008CAD0:
    // 0x8008CAD0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_8008CAD4:
    // 0x8008CAD4: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x8008CAD8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008CADC: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8008CAE0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8008CAE4: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8008CAE8: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8008CAEC: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x8008CAF0: jal         0x80090750
    // 0x8008CAF4: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamRead_recomp(rdram, ctx);
        goto after_1;
    // 0x8008CAF4: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x8008CAF8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8008CAFC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008CB00: beq         $t3, $zero, L_8008CB20
    if (ctx->r11 == 0) {
        // 0x8008CB04: nop
    
            goto L_8008CB20;
    }
    // 0x8008CB04: nop

    // 0x8008CB08: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008CB0C: sb          $zero, 0x65($t4)
    MEM_B(0X65, ctx->r12) = 0;
    // 0x8008CB10: jal         0x800890BC
    // 0x8008CB14: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x8008CB14: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x8008CB18: b           L_8008CB68
    // 0x8008CB1C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_8008CB68;
    // 0x8008CB1C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_8008CB20:
    // 0x8008CB20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8008CB24: jal         0x800883D0
    // 0x8008CB28: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    __osSumcalc(rdram, ctx);
        goto after_3;
    // 0x8008CB28: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_3:
    // 0x8008CB2C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8008CB30: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8008CB34: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8008CB38: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x8008CB3C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8008CB40: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008CB44: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x8008CB48: bne         $at, $zero, L_8008CAD4
    if (ctx->r1 != 0) {
        // 0x8008CB4C: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_8008CAD4;
    }
    // 0x8008CB4C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8008CB50: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008CB54: sb          $zero, 0x65($t0)
    MEM_B(0X65, ctx->r8) = 0;
    // 0x8008CB58: jal         0x800890BC
    // 0x8008CB5C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_4;
    // 0x8008CB5C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x8008CB60: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8008CB64: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_8008CB68:
    // 0x8008CB68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CB6C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8008CB70: jr          $ra
    // 0x8008CB74: nop

    return;
    // 0x8008CB74: nop

;}
RECOMP_FUNC void func_80760360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80760360: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80760364: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80760368: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8076036C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80760370: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80760374: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80760378: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8076037C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80760380: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80760384: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80760388: addiu       $t6, $zero, 0x438
    ctx->r14 = ADD32(0, 0X438);
    // 0x8076038C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80760390: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80760394: addiu       $a3, $zero, 0x3FC
    ctx->r7 = ADD32(0, 0X3FC);
    // 0x80760398: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8076039C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x807603A0: jal         0x8076009C
    // 0x807603A4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_8076009C(rdram, ctx);
        goto after_0;
    // 0x807603A4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x807603A8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x807603AC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x807603B0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x807603B4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x807603B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807603BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807603C0: jr          $ra
    // 0x807603C4: nop

    return;
    // 0x807603C4: nop

;}
RECOMP_FUNC void func_80475CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475CE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475CEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475CF0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475CF4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475CF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475CFC: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26DB8) << 16);
    // 0x80475D00: addiu       $a2, $a2, -0x4A88
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26DB8));
    // 0x80475D04: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80475D08: jal         0x80475B40
    // 0x80475D0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475B40(rdram, ctx);
        goto after_0;
    // 0x80475D0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475D14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475D18: jr          $ra
    // 0x80475D1C: nop

    return;
    // 0x80475D1C: nop

;}
RECOMP_FUNC void func_80531FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531FB8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80531FBC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80531FC0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80531FC4: lui         $t7, 0x8053
    ctx->r15 = S32(RELOC_HI16(342, 0X19BC) << 16);
    // 0x80531FC8: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x80531FCC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80531FD0: lw          $t7, 0x27AC($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(342, 0X19BC));
    // 0x80531FD4: jr          $ra
    // 0x80531FD8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x80531FD8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_804C1DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1DD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C1DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C1DDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804C1DE0: jal         0x80047090
    // 0x804C1DE4: addiu       $a0, $zero, 0x4121
    ctx->r4 = ADD32(0, 0X4121);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804C1DE4: addiu       $a0, $zero, 0x4121
    ctx->r4 = ADD32(0, 0X4121);
    after_0:
    // 0x804C1DE8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804C1DEC: bne         $v0, $at, L_804C1DFC
    if (ctx->r2 != ctx->r1) {
        // 0x804C1DF0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804C1DFC;
    }
    // 0x804C1DF0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804C1DF4: b           L_804C1E5C
    // 0x804C1DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C1E5C;
    // 0x804C1DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C1DFC:
    // 0x804C1DFC: lui         $at, 0x4121
    ctx->r1 = S32(0X4121 << 16);
    // 0x804C1E00: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x804C1E04: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x804C1E08: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804C1E0C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x804C1E10: lui         $a2, 0xC1C0
    ctx->r6 = S32(0XC1C0 << 16);
    // 0x804C1E14: jal         0x8004613C
    // 0x804C1E18: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804C1E18: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x804C1E1C: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x804C1E20: bne         $v0, $zero, L_804C1E30
    if (ctx->r2 != 0) {
        // 0x804C1E24: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804C1E30;
    }
    // 0x804C1E24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804C1E28: b           L_804C1E5C
    // 0x804C1E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C1E5C;
    // 0x804C1E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C1E30:
    // 0x804C1E30: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x804C1E34: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x804C1E38: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x804C1E3C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x804C1E40: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x804C1E44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C1E48: jal         0x80047F9C
    // 0x804C1E4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804C1E4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x804C1E50: jal         0x8005FDC4
    // 0x804C1E54: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x804C1E54: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x804C1E58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804C1E5C:
    // 0x804C1E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C1E60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C1E64: jr          $ra
    // 0x804C1E68: nop

    return;
    // 0x804C1E68: nop

;}
RECOMP_FUNC void func_8053510C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053510C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80535110: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80535114: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80535118: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8053511C: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80535120: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80535124: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80535128: slti        $at, $v0, 0x41A8
    ctx->r1 = SIGNED(ctx->r2) < 0X41A8 ? 1 : 0;
    // 0x8053512C: bne         $at, $zero, L_80535194
    if (ctx->r1 != 0) {
        // 0x80535130: slti        $at, $v0, 0x41AF
        ctx->r1 = SIGNED(ctx->r2) < 0X41AF ? 1 : 0;
            goto L_80535194;
    }
    // 0x80535130: slti        $at, $v0, 0x41AF
    ctx->r1 = SIGNED(ctx->r2) < 0X41AF ? 1 : 0;
    // 0x80535134: beql        $at, $zero, L_80535198
    if (ctx->r1 == 0) {
        // 0x80535138: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80535198;
    }
    goto skip_0;
    // 0x80535138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8053513C: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x80535140: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80535144: bnel        $t6, $zero, L_80535178
    if (ctx->r14 != 0) {
        // 0x80535148: lw          $t8, 0x174($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X174);
            goto L_80535178;
    }
    goto skip_1;
    // 0x80535148: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    skip_1:
    // 0x8053514C: jal         0x80048114
    // 0x80535150: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80048114(rdram, ctx);
        goto after_0;
    // 0x80535150: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80535154: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80535158: sb          $t7, 0x17C($s1)
    MEM_B(0X17C, ctx->r17) = ctx->r15;
    // 0x8053515C: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(348, 0X1098) << 16);
    // 0x80535160: lwc1        $f6, 0x56A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(348, 0X1098));
    // 0x80535164: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80535168: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8053516C: b           L_80535194
    // 0x80535170: swc1        $f8, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f8.u32l;
        goto L_80535194;
    // 0x80535170: swc1        $f8, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f8.u32l;
    // 0x80535174: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
L_80535178:
    // 0x80535178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8053517C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80535180: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x80535184: beql        $v0, $zero, L_80535198
    if (ctx->r2 == 0) {
        // 0x80535188: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80535198;
    }
    goto skip_2;
    // 0x80535188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8053518C: jalr        $v0
    // 0x80535190: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80535190: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
L_80535194:
    // 0x80535194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80535198:
    // 0x80535198: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8053519C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805351A0: jr          $ra
    // 0x805351A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805351A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void DmaMgr_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DD70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007DD74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007DD78: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8007DD7C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007DD80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007DD84: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007DD88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8007DD8C: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x8007DD90: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x8007DD94: addiu       $s2, $s2, -0x12F0
    ctx->r18 = ADD32(ctx->r18, -0X12F0);
    // 0x8007DD98: addiu       $s3, $s3, -0x12B0
    ctx->r19 = ADD32(ctx->r19, -0X12B0);
    // 0x8007DD9C: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x8007DDA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8007DDA4:
    // 0x8007DDA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8007DDA8: jal         0x800824B0
    // 0x8007DDAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8007DDAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007DDB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8007DDB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8007DDB8: jal         0x800824B0
    // 0x8007DDBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8007DDBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8007DDC0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007DDC4: jal         0x8007DC5C
    // 0x8007DDC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8007DC5C(rdram, ctx);
        goto after_2;
    // 0x8007DDC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_2:
    // 0x8007DDCC: bnel        $v0, $zero, L_8007DDA4
    if (ctx->r2 != 0) {
        // 0x8007DDD0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007DDA4;
    }
    goto skip_0;
    // 0x8007DDD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x8007DDD4: lbu         $t6, 0x11($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X11);
    // 0x8007DDD8: beql        $t6, $zero, L_8007DE04
    if (ctx->r14 == 0) {
        // 0x8007DDDC: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_8007DE04;
    }
    goto skip_1;
    // 0x8007DDDC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_1:
    // 0x8007DDE0: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x8007DDE4: jal         0x8006F560
    // 0x8007DDE8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    func_8006F560(rdram, ctx);
        goto after_3;
    // 0x8007DDE8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x8007DDEC: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8007DDF0: bnel        $t7, $zero, L_8007DE04
    if (ctx->r15 != 0) {
        // 0x8007DDF4: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_8007DE04;
    }
    goto skip_2;
    // 0x8007DDF4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_2:
    // 0x8007DDF8: jal         0x80064E84
    // 0x8007DDFC: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    func_80064E84(rdram, ctx);
        goto after_4;
    // 0x8007DDFC: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x8007DE00: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
L_8007DE04:
    // 0x8007DE04: beql        $a0, $zero, L_8007DDA4
    if (ctx->r4 == 0) {
        // 0x8007DE08: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007DDA4;
    }
    goto skip_3;
    // 0x8007DE08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_3:
    // 0x8007DE0C: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x8007DE10: jal         0x80082210
    // 0x8007DE14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8007DE14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8007DE18: b           L_8007DDA4
    // 0x8007DE1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_8007DDA4;
    // 0x8007DE1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007DE20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007DE24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007DE28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007DE2C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007DE30: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007DE34: jr          $ra
    // 0x8007DE38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007DE38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80525698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525698: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052569C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x805256A0: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x805256A4: beq         $at, $zero, L_805256D4
    if (ctx->r1 == 0) {
        // 0x805256A8: nop
    
            goto L_805256D4;
    }
    // 0x805256A8: nop

    // 0x805256AC: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x805256B0: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x805256B4: bne         $t7, $zero, L_805256D4
    if (ctx->r15 != 0) {
        // 0x805256B8: nop
    
            goto L_805256D4;
    }
    // 0x805256B8: nop

    // 0x805256BC: lh          $t8, -0x7680($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X7680);
    // 0x805256C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805256C4: slti        $at, $t8, -0x5
    ctx->r1 = SIGNED(ctx->r24) < -0X5 ? 1 : 0;
    // 0x805256C8: beq         $at, $zero, L_805256D4
    if (ctx->r1 == 0) {
        // 0x805256CC: nop
    
            goto L_805256D4;
    }
    // 0x805256CC: nop

    // 0x805256D0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_805256D4:
    // 0x805256D4: jr          $ra
    // 0x805256D8: nop

    return;
    // 0x805256D8: nop

;}
RECOMP_FUNC void func_8064F288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F288: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F28C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F290: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F294: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F298: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F29C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F2A0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F2A4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F2A8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F2AC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F2B0: jr          $ra
    // 0x8064F2B4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F2B4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80677A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80677A88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80677A8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80677A90: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80677A94: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80677A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80677A9C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80677AA0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80677AA4: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80677AA8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80677AAC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80677AB0: lui         $t2, 0x8067
    ctx->r10 = S32(RELOC_HI16(535, 0X254C) << 16);
    // 0x80677AB4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80677AB8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80677ABC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80677AC0: lw          $t2, 0x7C0C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(535, 0X254C));
    // 0x80677AC4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80677AC8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80677ACC: jal         0x80675704
    // 0x80677AD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80675704(rdram, ctx);
        goto after_0;
    // 0x80677AD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80677AD4: jal         0x80675724
    // 0x80677AD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80675724(rdram, ctx);
        goto after_1;
    // 0x80677AD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80677ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80677AE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80677AE4: jr          $ra
    // 0x80677AE8: nop

    return;
    // 0x80677AE8: nop

;}
RECOMP_FUNC void func_800742A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800742A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800742AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800742B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800742B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800742B8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800742BC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800742C0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800742C4: lbu         $t7, 0x9($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X9);
    // 0x800742C8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800742CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800742D0: bne         $t7, $at, L_800742E4
    if (ctx->r15 != ctx->r1) {
        // 0x800742D4: lw          $v0, 0x0($t6)
        ctx->r2 = MEM_W(ctx->r14, 0X0);
            goto L_800742E4;
    }
    // 0x800742D4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800742D8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800742DC: b           L_800742EC
    // 0x800742E0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800742EC;
    // 0x800742E0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800742E4:
    // 0x800742E4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800742E8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800742EC:
    // 0x800742EC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800742F0: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x800742F4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800742F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800742FC: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80074300: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80074304: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80074308: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8007430C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80074310: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80074314: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x80074318: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8007431C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80074320: jal         0x800734F0
    // 0x80074324: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800734F0(rdram, ctx);
        goto after_0;
    // 0x80074324: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x80074328: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8007432C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80074330: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80074334: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80074338: addu        $t8, $t1, $t5
    ctx->r24 = ADD32(ctx->r9, ctx->r13);
    // 0x8007433C: addu        $a0, $t8, $t3
    ctx->r4 = ADD32(ctx->r24, ctx->r11);
    // 0x80074340: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80074344: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80074348: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8007434C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80074350: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x80074354: andi        $t9, $a0, 0x3FF
    ctx->r25 = ctx->r4 & 0X3FF;
    // 0x80074358: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x8007435C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80074360: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80074364: addu        $t9, $t7, $ra
    ctx->r25 = ADD32(ctx->r15, ctx->r31);
    // 0x80074368: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x8007436C: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x80074370: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80074374: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80074378: andi        $t7, $t2, 0x3FF
    ctx->r15 = ctx->r10 & 0X3FF;
    // 0x8007437C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80074380: andi        $t4, $t1, 0x3FF
    ctx->r12 = ctx->r9 & 0X3FF;
    // 0x80074384: sll         $t4, $t4, 14
    ctx->r12 = S32(ctx->r12 << 14);
    // 0x80074388: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007438C: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x80074390: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80074394: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80074398: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007439C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800743A0: lhu         $a2, 0xC($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XC);
    // 0x800743A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800743A8: addu        $t7, $t6, $ra
    ctx->r15 = ADD32(ctx->r14, ctx->r31);
    // 0x800743AC: subu        $a3, $t7, $a2
    ctx->r7 = SUB32(ctx->r15, ctx->r6);
    // 0x800743B0: blez        $a3, L_800743F0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800743B4: addu        $a1, $a3, $t0
        ctx->r5 = ADD32(ctx->r7, ctx->r8);
            goto L_800743F0;
    }
    // 0x800743B4: addu        $a1, $a3, $t0
    ctx->r5 = ADD32(ctx->r7, ctx->r8);
    // 0x800743B8: andi        $t8, $v1, 0x3FF
    ctx->r24 = ctx->r3 & 0X3FF;
    // 0x800743BC: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x800743C0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800743C4: andi        $t7, $a1, 0x3FF
    ctx->r15 = ctx->r5 & 0X3FF;
    // 0x800743C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800743CC: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800743D0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800743D4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800743D8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800743DC: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x800743E0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800743E4: lhu         $a2, 0xC($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XC);
    // 0x800743E8: addu        $t6, $t7, $ra
    ctx->r14 = ADD32(ctx->r15, ctx->r31);
    // 0x800743EC: subu        $a3, $t6, $a2
    ctx->r7 = SUB32(ctx->r14, ctx->r6);
L_800743F0:
    // 0x800743F0: bltz        $a3, L_80074498
    if (SIGNED(ctx->r7) < 0) {
        // 0x800743F4: lw          $t8, 0x48($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X48);
            goto L_80074498;
    }
    // 0x800743F4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800743F8: lhu         $a3, 0xA($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0XA);
    // 0x800743FC: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x80074400: lui         $ra, 0xF600
    ctx->r31 = S32(0XF600 << 16);
    // 0x80074404: subu        $t7, $t9, $a3
    ctx->r15 = SUB32(ctx->r25, ctx->r7);
    // 0x80074408: blez        $t7, L_80074498
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8007440C: addiu       $t2, $a2, -0x1
        ctx->r10 = ADD32(ctx->r6, -0X1);
            goto L_80074498;
    }
    // 0x8007440C: addiu       $t2, $a2, -0x1
    ctx->r10 = ADD32(ctx->r6, -0X1);
    // 0x80074410: addu        $a1, $a2, $t0
    ctx->r5 = ADD32(ctx->r6, ctx->r8);
    // 0x80074414: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x80074418: addu        $v1, $a3, $t3
    ctx->r3 = ADD32(ctx->r7, ctx->r11);
    // 0x8007441C: andi        $t6, $v1, 0x3FF
    ctx->r14 = ctx->r3 & 0X3FF;
    // 0x80074420: sll         $t9, $t6, 14
    ctx->r25 = S32(ctx->r14 << 14);
    // 0x80074424: andi        $t8, $a1, 0x3FF
    ctx->r24 = ctx->r5 & 0X3FF;
    // 0x80074428: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8007442C: or          $t7, $t9, $ra
    ctx->r15 = ctx->r25 | ctx->r31;
    // 0x80074430: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80074434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074438: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007443C: andi        $t6, $t2, 0x3FF
    ctx->r14 = ctx->r10 & 0X3FF;
    // 0x80074440: andi        $t8, $t1, 0x3FF
    ctx->r24 = ctx->r9 & 0X3FF;
    // 0x80074444: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x80074448: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8007444C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80074450: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80074454: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80074458: lhu         $t7, 0xA($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XA);
    // 0x8007445C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80074460: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x80074464: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x80074468: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x8007446C: andi        $t6, $v1, 0x3FF
    ctx->r14 = ctx->r3 & 0X3FF;
    // 0x80074470: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80074474: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x80074478: andi        $t6, $t8, 0x3FF
    ctx->r14 = ctx->r24 & 0X3FF;
    // 0x8007447C: or          $t9, $t7, $ra
    ctx->r25 = ctx->r15 | ctx->r31;
    // 0x80074480: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x80074484: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80074488: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8007448C: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80074490: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80074494: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80074498:
    // 0x80074498: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8007449C: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x800744A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800744A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800744A8: jr          $ra
    // 0x800744AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800744AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_804E7CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7CF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E7CFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804E7D00: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804E7D04: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804E7D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E7D0C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804E7D10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804E7D14: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x804E7D18: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804E7D1C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804E7D20: lui         $t2, 0x804E
    ctx->r10 = S32(RELOC_HI16(261, 0X6C4) << 16);
    // 0x804E7D24: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804E7D28: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804E7D2C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804E7D30: lw          $t2, 0x7F24($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(261, 0X6C4));
    // 0x804E7D34: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804E7D38: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804E7D3C: jal         0x804E7AF0
    // 0x804E7D40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804E7AF0(rdram, ctx);
        goto after_0;
    // 0x804E7D40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804E7D44: jal         0x804E7B4C
    // 0x804E7D48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804E7B4C(rdram, ctx);
        goto after_1;
    // 0x804E7D48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804E7D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E7D50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E7D54: jr          $ra
    // 0x804E7D58: nop

    return;
    // 0x804E7D58: nop

;}
RECOMP_FUNC void func_8003EB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EB90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003EB94: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003EB98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003EB9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003EBA0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8003EBA4: lw          $t9, 0x1C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1C);
    // 0x8003EBA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8003EBAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003EBB0: jalr        $t9
    // 0x8003EBB4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8003EBB4: nop

    after_0:
    // 0x8003EBB8: jal         0x8003EB2C
    // 0x8003EBBC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8003EB2C(rdram, ctx);
        goto after_1;
    // 0x8003EBBC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8003EBC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003EBC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8003EBC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003EBCC: jr          $ra
    // 0x8003EBD0: nop

    return;
    // 0x8003EBD0: nop

;}
RECOMP_FUNC void func_8002515C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002515C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80025160: lh          $t6, -0x7682($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7682);
    // 0x80025164: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025168: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002516C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80025170: beq         $t6, $zero, L_8002523C
    if (ctx->r14 == 0) {
        // 0x80025174: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_8002523C;
    }
    // 0x80025174: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80025178: jal         0x80066E88
    // 0x8002517C: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8002517C: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    after_0:
    // 0x80025180: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80025184: lwc1        $f6, 0x100($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X100);
    // 0x80025188: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002518C: nop

    // 0x80025190: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80025194: jal         0x80065954
    // 0x80025198: nop

    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80025198: nop

    after_1:
    // 0x8002519C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800251A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800251A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800251A8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800251AC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800251B0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800251B4: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800251B8: nop

    // 0x800251BC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800251C0: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800251C4: nop

    // 0x800251C8: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800251CC: beql        $a1, $zero, L_80025224
    if (ctx->r5 == 0) {
        // 0x800251D0: mfc1        $a1, $f18
        ctx->r5 = (int32_t)ctx->f18.u32l;
            goto L_80025224;
    }
    goto skip_0;
    // 0x800251D0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x800251D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800251D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800251DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800251E0: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800251E4: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800251E8: nop

    // 0x800251EC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800251F0: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800251F4: nop

    // 0x800251F8: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800251FC: bnel        $a1, $zero, L_80025218
    if (ctx->r5 != 0) {
        // 0x80025200: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_80025218;
    }
    goto skip_1;
    // 0x80025200: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_1:
    // 0x80025204: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80025208: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002520C: b           L_800252FC
    // 0x80025210: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_800252FC;
    // 0x80025210: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    // 0x80025214: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
L_80025218:
    // 0x80025218: b           L_800252FC
    // 0x8002521C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_800252FC;
    // 0x8002521C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80025220: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
L_80025224:
    // 0x80025224: nop

    // 0x80025228: bltzl       $a1, L_80025218
    if (SIGNED(ctx->r5) < 0) {
        // 0x8002522C: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_80025218;
    }
    goto skip_2;
    // 0x8002522C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_2:
    // 0x80025230: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80025234: b           L_80025300
    // 0x80025238: sltiu       $at, $a1, 0x28
    ctx->r1 = ctx->r5 < 0X28 ? 1 : 0;
        goto L_80025300;
    // 0x80025238: sltiu       $at, $a1, 0x28
    ctx->r1 = ctx->r5 < 0X28 ? 1 : 0;
L_8002523C:
    // 0x8002523C: jal         0x80066E88
    // 0x80025240: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80025240: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    after_2:
    // 0x80025244: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80025248: lwc1        $f6, 0x100($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X100);
    // 0x8002524C: lwc1        $f16, 0x10C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80025250: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80025254: nop

    // 0x80025258: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8002525C: jal         0x80065954
    // 0x80025260: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x80025260: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_3:
    // 0x80025264: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80025268: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002526C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80025270: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80025274: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80025278: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002527C: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80025280: nop

    // 0x80025284: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80025288: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x8002528C: nop

    // 0x80025290: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80025294: beql        $a1, $zero, L_800252E4
    if (ctx->r5 == 0) {
        // 0x80025298: mfc1        $a1, $f6
        ctx->r5 = (int32_t)ctx->f6.u32l;
            goto L_800252E4;
    }
    goto skip_3;
    // 0x80025298: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x8002529C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800252A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800252A4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800252A8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800252AC: nop

    // 0x800252B0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800252B4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800252B8: nop

    // 0x800252BC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800252C0: bne         $a1, $zero, L_800252D8
    if (ctx->r5 != 0) {
        // 0x800252C4: nop
    
            goto L_800252D8;
    }
    // 0x800252C4: nop

    // 0x800252C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800252CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800252D0: b           L_800252F0
    // 0x800252D4: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_800252F0;
    // 0x800252D4: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_800252D8:
    // 0x800252D8: b           L_800252F0
    // 0x800252DC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_800252F0;
    // 0x800252DC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800252E0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
L_800252E4:
    // 0x800252E4: nop

    // 0x800252E8: bltz        $a1, L_800252D8
    if (SIGNED(ctx->r5) < 0) {
        // 0x800252EC: nop
    
            goto L_800252D8;
    }
    // 0x800252EC: nop

L_800252F0:
    // 0x800252F0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800252F4: nop

    // 0x800252F8: nop

L_800252FC:
    // 0x800252FC: sltiu       $at, $a1, 0x28
    ctx->r1 = ctx->r5 < 0X28 ? 1 : 0;
L_80025300:
    // 0x80025300: beq         $at, $zero, L_8002530C
    if (ctx->r1 == 0) {
        // 0x80025304: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002530C;
    }
    // 0x80025304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80025308: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
L_8002530C:
    // 0x8002530C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80025310: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80025314: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80025318: jal         0x80024D30
    // 0x8002531C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80024D30(rdram, ctx);
        goto after_4;
    // 0x8002531C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_4:
    // 0x80025320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80025324: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80025328: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002532C: jr          $ra
    // 0x80025330: nop

    return;
    // 0x80025330: nop

;}
RECOMP_FUNC void func_80050FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050FCC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80050FD0: addiu       $sp, $sp, -0x2C0
    ctx->r29 = ADD32(ctx->r29, -0X2C0);
    // 0x80050FD4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80050FD8: beq         $v0, $zero, L_80051024
    if (ctx->r2 == 0) {
        // 0x80050FDC: sll         $a2, $zero, 2
        ctx->r6 = S32(0 << 2);
            goto L_80051024;
    }
    // 0x80050FDC: sll         $a2, $zero, 2
    ctx->r6 = S32(0 << 2);
    // 0x80050FE0: addu        $t0, $a0, $a2
    ctx->r8 = ADD32(ctx->r4, ctx->r6);
    // 0x80050FE4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80050FE8: addiu       $t2, $sp, 0x24
    ctx->r10 = ADD32(ctx->r29, 0X24);
    // 0x80050FEC: addiu       $a3, $zero, 0x294
    ctx->r7 = ADD32(0, 0X294);
    // 0x80050FF0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
L_80050FF4:
    // 0x80050FF4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80050FF8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80050FFC: beq         $a1, $zero, L_80051014
    if (ctx->r5 == 0) {
        // 0x80051000: addu        $t7, $t2, $t6
        ctx->r15 = ADD32(ctx->r10, ctx->r14);
            goto L_80051014;
    }
    // 0x80051000: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x80051004: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x80051008: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8005100C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80051010: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80051014:
    // 0x80051014: beq         $v0, $zero, L_80051024
    if (ctx->r2 == 0) {
        // 0x80051018: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80051024;
    }
    // 0x80051018: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8005101C: bnel        $a2, $a3, L_80050FF4
    if (ctx->r6 != ctx->r7) {
        // 0x80051020: lw          $a1, 0x0($t0)
        ctx->r5 = MEM_W(ctx->r8, 0X0);
            goto L_80050FF4;
    }
    goto skip_0;
    // 0x80051020: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    skip_0:
L_80051024:
    // 0x80051024: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80051028: addiu       $t2, $sp, 0x24
    ctx->r10 = ADD32(ctx->r29, 0X24);
    // 0x8005102C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80051030: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80051034: bne         $at, $zero, L_800510C4
    if (ctx->r1 != 0) {
        // 0x80051038: addiu       $a3, $sp, 0x28
        ctx->r7 = ADD32(ctx->r29, 0X28);
            goto L_800510C4;
    }
    // 0x80051038: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x8005103C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80051040:
    // 0x80051040: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80051044: bltz        $t0, L_800510A0
    if (SIGNED(ctx->r8) < 0) {
        // 0x80051048: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_800510A0;
    }
    // 0x80051048: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8005104C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80051050: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x80051054: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80051058: lhu         $t8, 0x3C($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X3C);
    // 0x8005105C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80051060: lhu         $t5, 0x3C($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X3C);
    // 0x80051064: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x80051068: slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8005106C: beql        $at, $zero, L_800510A4
    if (ctx->r1 == 0) {
        // 0x80051070: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_800510A4;
    }
    goto skip_1;
    // 0x80051070: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    skip_1:
    // 0x80051074: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80051078: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_8005107C:
    // 0x8005107C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80051080: bltz        $v1, L_800510A0
    if (SIGNED(ctx->r3) < 0) {
        // 0x80051084: sw          $t1, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r9;
            goto L_800510A0;
    }
    // 0x80051084: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x80051088: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8005108C: lhu         $t7, 0x3C($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X3C);
    // 0x80051090: lhu         $t9, 0x3C($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X3C);
    // 0x80051094: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80051098: bnel        $at, $zero, L_8005107C
    if (ctx->r1 != 0) {
        // 0x8005109C: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_8005107C;
    }
    goto skip_2;
    // 0x8005109C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_2:
L_800510A0:
    // 0x800510A0: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
L_800510A4:
    // 0x800510A4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800510A8: sw          $a2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r6;
    // 0x800510AC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800510B0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800510B4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800510B8: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800510BC: bne         $at, $zero, L_80051040
    if (ctx->r1 != 0) {
        // 0x800510C0: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80051040;
    }
    // 0x800510C0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800510C4:
    // 0x800510C4: blez        $v0, L_800510F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800510C8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800510F8;
    }
    // 0x800510C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800510CC: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x800510D0: addiu       $t0, $a0, 0x4
    ctx->r8 = ADD32(ctx->r4, 0X4);
    // 0x800510D4: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
L_800510D8:
    // 0x800510D8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800510DC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800510E0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800510E4: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800510E8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800510EC: slt         $at, $a1, $t5
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800510F0: bnel        $at, $zero, L_800510D8
    if (ctx->r1 != 0) {
        // 0x800510F4: lw          $t8, 0x0($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X0);
            goto L_800510D8;
    }
    goto skip_3;
    // 0x800510F4: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    skip_3:
L_800510F8:
    // 0x800510F8: jr          $ra
    // 0x800510FC: addiu       $sp, $sp, 0x2C0
    ctx->r29 = ADD32(ctx->r29, 0X2C0);
    return;
    // 0x800510FC: addiu       $sp, $sp, 0x2C0
    ctx->r29 = ADD32(ctx->r29, 0X2C0);
;}
RECOMP_FUNC void func_8070CAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070CAE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8070CAE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8070CAEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8070CAF0: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8070CAF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8070CAF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070CAFC: blez        $v0, L_8070CB10
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8070CB00: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8070CB10;
    }
    // 0x8070CB00: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8070CB04: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8070CB08: b           L_8070CB34
    // 0x8070CB0C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8070CB34;
    // 0x8070CB0C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8070CB10:
    // 0x8070CB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070CB14: jal         0x8070D208
    // 0x8070CB18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8070D208(rdram, ctx);
        goto after_0;
    // 0x8070CB18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8070CB1C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8070CB20: jal         0x80067BBC
    // 0x8070CB24: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8070CB24: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8070CB28: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8070CB2C: jal         0x80067818
    // 0x8070CB30: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8070CB30: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_8070CB34:
    // 0x8070CB34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8070CB38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8070CB3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8070CB40: jr          $ra
    // 0x8070CB44: nop

    return;
    // 0x8070CB44: nop

;}
RECOMP_FUNC void func_8073FD38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073FD38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073FD3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8073FD40: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8073FD44: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8073FD48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073FD4C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8073FD50: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8073FD54: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8073FD58: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8073FD5C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8073FD60: lui         $t2, 0x8074
    ctx->r10 = S32(RELOC_HI16(748, 0X2404) << 16);
    // 0x8073FD64: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8073FD68: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8073FD6C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8073FD70: lw          $t2, 0xBF4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(748, 0X2404));
    // 0x8073FD74: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8073FD78: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8073FD7C: jal         0x8073F6D8
    // 0x8073FD80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8073F6D8(rdram, ctx);
        goto after_0;
    // 0x8073FD80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8073FD84: jal         0x8073F3A4
    // 0x8073FD88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8073F3A4(rdram, ctx);
        goto after_1;
    // 0x8073FD88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8073FD8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073FD90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073FD94: jr          $ra
    // 0x8073FD98: nop

    return;
    // 0x8073FD98: nop

;}
RECOMP_FUNC void func_8055808C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8055808C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80558090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80558094: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80558098: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8055809C: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805580A0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805580A4: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x805580A8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x805580AC: nop

    // 0x805580B0: bc1fl       L_805580DC
    if (!c1cs) {
        // 0x805580B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805580DC;
    }
    goto skip_0;
    // 0x805580B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805580B8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x805580BC: jal         0x8004D1F0
    // 0x805580C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x805580C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805580C4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805580C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805580CC: addiu       $a2, $a2, -0x2B90
    ctx->r6 = ADD32(ctx->r6, -0X2B90);
    // 0x805580D0: jal         0x8004D698
    // 0x805580D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x805580D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x805580D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805580DC:
    // 0x805580DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805580E0: jr          $ra
    // 0x805580E4: nop

    return;
    // 0x805580E4: nop

;}
RECOMP_FUNC void func_80059EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059EBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059EC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80059EC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80059EC8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80059ECC: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80059ED0: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80059ED4: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // 0x80059ED8: bne         $t0, $at, L_80059EE8
    if (ctx->r8 != ctx->r1) {
        // 0x80059EDC: addiu       $v1, $zero, 0xF0
        ctx->r3 = ADD32(0, 0XF0);
            goto L_80059EE8;
    }
    // 0x80059EDC: addiu       $v1, $zero, 0xF0
    ctx->r3 = ADD32(0, 0XF0);
    // 0x80059EE0: b           L_80059F54
    // 0x80059EE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80059F54;
    // 0x80059EE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059EE8:
    // 0x80059EE8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80059EEC: lw          $t7, -0x7D6C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D6C);
    // 0x80059EF0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80059EF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80059EF8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059EFC: lwc1        $f8, 0xBE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XBE0);
    // 0x80059F00: lwc1        $f6, 0x5C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X5C);
    // 0x80059F04: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80059F08: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80059F0C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80059F10: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x80059F14: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x80059F18: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x80059F1C: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80059F20: nop

    // 0x80059F24: bc1fl       L_80059F38
    if (!c1cs) {
        // 0x80059F28: lw          $a0, 0x0($t8)
        ctx->r4 = MEM_W(ctx->r24, 0X0);
            goto L_80059F38;
    }
    goto skip_0;
    // 0x80059F28: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    skip_0:
    // 0x80059F2C: addiu       $v1, $zero, 0x154
    ctx->r3 = ADD32(0, 0X154);
    // 0x80059F30: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    // 0x80059F34: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
L_80059F38:
    // 0x80059F38: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x80059F3C: lh          $a2, 0x2($t9)
    ctx->r6 = MEM_H(ctx->r25, 0X2);
    // 0x80059F40: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80059F44: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80059F48: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80059F4C: jal         0x80065BC8
    // 0x80059F50: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_80065BC8(rdram, ctx);
        goto after_0;
    // 0x80059F50: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
L_80059F54:
    // 0x80059F54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80059F58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80059F5C: jr          $ra
    // 0x80059F60: nop

    return;
    // 0x80059F60: nop

;}
RECOMP_FUNC void func_807AD654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD654: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x807AD658: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AD65C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x807AD660: lw          $a2, 0x80($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X80);
    // 0x807AD664: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x807AD668: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x807AD66C: lui         $t9, 0x807B
    ctx->r25 = S32(RELOC_HI16(859, 0X25F0) << 16);
    // 0x807AD670: addiu       $t9, $t9, -0x13B0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(859, 0X25F0));
    // 0x807AD674: ori         $t8, $t8, 0x103F
    ctx->r24 = ctx->r24 | 0X103F;
    // 0x807AD678: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x807AD67C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x807AD680: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AD684: lui         $t3, 0xFD90
    ctx->r11 = S32(0XFD90 << 16);
    // 0x807AD688: lui         $t6, 0x705
    ctx->r14 = S32(0X705 << 16);
    // 0x807AD68C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x807AD690: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x807AD694: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x807AD698: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x807AD69C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AD6A0: ori         $t6, $t6, 0x4150
    ctx->r14 = ctx->r14 | 0X4150;
    // 0x807AD6A4: lui         $t5, 0xF590
    ctx->r13 = S32(0XF590 << 16);
    // 0x807AD6A8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x807AD6AC: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x807AD6B0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x807AD6B4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x807AD6B8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AD6BC: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x807AD6C0: lui         $t3, 0x70F
    ctx->r11 = S32(0X70F << 16);
    // 0x807AD6C4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x807AD6C8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x807AD6CC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807AD6D0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x807AD6D4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AD6D8: ori         $t3, $t3, 0xF400
    ctx->r11 = ctx->r11 | 0XF400;
    // 0x807AD6DC: lui         $t2, 0xF300
    ctx->r10 = S32(0XF300 << 16);
    // 0x807AD6E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x807AD6E4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x807AD6E8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x807AD6EC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x807AD6F0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AD6F4: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x807AD6F8: lui         $t8, 0x5
    ctx->r24 = S32(0X5 << 16);
    // 0x807AD6FC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x807AD700: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x807AD704: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807AD708: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x807AD70C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AD710: lui         $t7, 0xF580
    ctx->r15 = S32(0XF580 << 16);
    // 0x807AD714: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x807AD718: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x807AD71C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x807AD720: ori         $t8, $t8, 0x4150
    ctx->r24 = ctx->r24 | 0X4150;
    // 0x807AD724: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x807AD728: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x807AD72C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AD730: lui         $t3, 0x7
    ctx->r11 = S32(0X7 << 16);
    // 0x807AD734: ori         $t3, $t3, 0xC07C
    ctx->r11 = ctx->r11 | 0XC07C;
    // 0x807AD738: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x807AD73C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x807AD740: lui         $t2, 0xF200
    ctx->r10 = S32(0XF200 << 16);
    // 0x807AD744: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x807AD748: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x807AD74C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AD750: lui         $t6, 0x4
    ctx->r14 = S32(0X4 << 16);
    // 0x807AD754: lui         $t5, 0xB100
    ctx->r13 = S32(0XB100 << 16);
    // 0x807AD758: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x807AD75C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x807AD760: ori         $t5, $t5, 0x204
    ctx->r13 = ctx->r13 | 0X204;
    // 0x807AD764: ori         $t6, $t6, 0x206
    ctx->r14 = ctx->r14 | 0X206;
    // 0x807AD768: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x807AD76C: jr          $ra
    // 0x807AD770: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    return;
    // 0x807AD770: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_8069EAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069EAE4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8069EAE8: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(577, 0X9B4) << 16);
    // 0x8069EAEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8069EAF0: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8069EAF4: lw          $t6, -0x127C($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(577, 0X9B4));
    // 0x8069EAF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069EAFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8069EB00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069EB04: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8069EB08: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8069EB0C: jal         0x80045A34
    // 0x8069EB10: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8069EB10: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x8069EB14: bne         $v0, $zero, L_8069EB2C
    if (ctx->r2 != 0) {
        // 0x8069EB18: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8069EB2C;
    }
    // 0x8069EB18: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8069EB1C: jal         0x800445A4
    // 0x8069EB20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8069EB20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8069EB24: b           L_8069EB9C
    // 0x8069EB28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8069EB9C;
    // 0x8069EB28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8069EB2C:
    // 0x8069EB2C: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x8069EB30: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8069EB34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8069EB38: jal         0x80065728
    // 0x8069EB3C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8069EB3C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8069EB40: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8069EB44: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(577, 0X99C) << 16);
    // 0x8069EB48: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8069EB4C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8069EB50: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8069EB54: lw          $t8, -0x1294($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(577, 0X99C));
    // 0x8069EB58: lui         $t0, 0x806A
    ctx->r8 = S32(RELOC_HI16(577, 0X8F8) << 16);
    // 0x8069EB5C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8069EB60: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8069EB64: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x8069EB68: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8069EB6C: lw          $t0, -0x1338($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(577, 0X8F8));
    // 0x8069EB70: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    // 0x8069EB74: addiu       $a0, $a3, 0x14
    ctx->r4 = ADD32(ctx->r7, 0X14);
    // 0x8069EB78: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8069EB7C: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x8069EB80: lwc1        $f4, 0x3C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X3C);
    // 0x8069EB84: jal         0x80065490
    // 0x8069EB88: swc1        $f4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f4.u32l;
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x8069EB88: swc1        $f4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f4.u32l;
    after_3:
    // 0x8069EB8C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8069EB90: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8069EB94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8069EB98: swc1        $f6, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f6.u32l;
L_8069EB9C:
    // 0x8069EB9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8069EBA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069EBA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8069EBA8: jr          $ra
    // 0x8069EBAC: nop

    return;
    // 0x8069EBAC: nop

;}
RECOMP_FUNC void func_8045287C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045287C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452884: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80452888: jal         0x804527B0
    // 0x8045288C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804527B0(rdram, ctx);
        goto after_0;
    // 0x8045288C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80452890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452898: jr          $ra
    // 0x8045289C: nop

    return;
    // 0x8045289C: nop

;}
RECOMP_FUNC void func_804A3F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A3F8C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804A3F90: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x804A3F94: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x804A3F98: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x804A3F9C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x804A3FA0: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x804A3FA4: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x804A3FA8: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804A3FAC: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804A3FB0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804A3FB4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804A3FB8: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804A3FBC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804A3FC0: lwc1        $f26, 0x3C($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A3FC4: addiu       $s0, $v0, 0x188
    ctx->r16 = ADD32(ctx->r2, 0X188);
    // 0x804A3FC8: lwc1        $f28, 0x40($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A3FCC: bne         $s0, $zero, L_804A3FDC
    if (ctx->r16 != 0) {
        // 0x804A3FD0: lh          $s1, 0x184($v0)
        ctx->r17 = MEM_H(ctx->r2, 0X184);
            goto L_804A3FDC;
    }
    // 0x804A3FD0: lh          $s1, 0x184($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X184);
    // 0x804A3FD4: b           L_804A4088
    // 0x804A3FD8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_804A4088;
    // 0x804A3FD8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_804A3FDC:
    // 0x804A3FDC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A3FE0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x804A3FE4: beq         $s1, $zero, L_804A4064
    if (ctx->r17 == 0) {
        // 0x804A3FE8: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_804A4064;
    }
    // 0x804A3FE8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_804A3FEC:
    // 0x804A3FEC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804A3FF0: beq         $v0, $zero, L_804A405C
    if (ctx->r2 == 0) {
        // 0x804A3FF4: nop
    
            goto L_804A405C;
    }
    // 0x804A3FF4: nop

    // 0x804A3FF8: lwc1        $f14, 0x3C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A3FFC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x804A4000: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x804A4004: c.lt.s      $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f14.fl < ctx->f26.fl;
    // 0x804A4008: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804A400C: lwc1        $f20, 0x40($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A4010: bc1t        L_804A4028
    if (c1cs) {
        // 0x804A4014: nop
    
            goto L_804A4028;
    }
    // 0x804A4014: nop

    // 0x804A4018: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    // 0x804A401C: nop

    // 0x804A4020: bc1f        L_804A405C
    if (!c1cs) {
        // 0x804A4024: nop
    
            goto L_804A405C;
    }
    // 0x804A4024: nop

L_804A4028:
    // 0x804A4028: jal         0x804A3C08
    // 0x804A402C: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_804A3C08(rdram, ctx);
        goto after_0;
    // 0x804A402C: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_0:
    // 0x804A4030: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x804A4034: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x804A4038: jal         0x804A3C08
    // 0x804A403C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_804A3C08(rdram, ctx);
        goto after_1;
    // 0x804A403C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x804A4040: add.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x804A4044: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x804A4048: nop

    // 0x804A404C: bc1f        L_804A405C
    if (!c1cs) {
        // 0x804A4050: nop
    
            goto L_804A405C;
    }
    // 0x804A4050: nop

    // 0x804A4054: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x804A4058: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_804A405C:
    // 0x804A405C: bne         $s1, $zero, L_804A3FEC
    if (ctx->r17 != 0) {
        // 0x804A4060: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_804A3FEC;
    }
    // 0x804A4060: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_804A4064:
    // 0x804A4064: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A4068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A406C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x804A4070: c.le.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl <= ctx->f24.fl;
    // 0x804A4074: nop

    // 0x804A4078: bc1f        L_804A4088
    if (!c1cs) {
        // 0x804A407C: nop
    
            goto L_804A4088;
    }
    // 0x804A407C: nop

    // 0x804A4080: b           L_804A4088
    // 0x804A4084: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_804A4088;
    // 0x804A4084: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_804A4088:
    // 0x804A4088: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x804A408C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804A4090: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804A4094: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804A4098: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804A409C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x804A40A0: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x804A40A4: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x804A40A8: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x804A40AC: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x804A40B0: jr          $ra
    // 0x804A40B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x804A40B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80465E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80465E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80465E98: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80465E9C: sw          $zero, 0x2858($v0)
    MEM_W(0X2858, ctx->r2) = 0;
    // 0x80465EA0: jal         0x80465D08
    // 0x80465EA4: sw          $zero, 0x285C($v0)
    MEM_W(0X285C, ctx->r2) = 0;
    func_80465D08(rdram, ctx);
        goto after_0;
    // 0x80465EA4: sw          $zero, 0x285C($v0)
    MEM_W(0X285C, ctx->r2) = 0;
    after_0:
    // 0x80465EA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80465EAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80465EB0: jr          $ra
    // 0x80465EB4: nop

    return;
    // 0x80465EB4: nop

;}
RECOMP_FUNC void func_805DCA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DCA58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DCA5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DCA60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DCA64: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805DCA68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805DCA6C: addiu       $at, $zero, 0x4194
    ctx->r1 = ADD32(0, 0X4194);
    // 0x805DCA70: beq         $v0, $at, L_805DCA8C
    if (ctx->r2 == ctx->r1) {
        // 0x805DCA74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805DCA8C;
    }
    // 0x805DCA74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCA78: addiu       $at, $zero, 0x4195
    ctx->r1 = ADD32(0, 0X4195);
    // 0x805DCA7C: beq         $v0, $at, L_805DCAB8
    if (ctx->r2 == ctx->r1) {
        // 0x805DCA80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805DCAB8;
    }
    // 0x805DCA80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCA84: b           L_805DCAE4
    // 0x805DCA88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805DCAE4;
    // 0x805DCA88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DCA8C:
    // 0x805DCA8C: jal         0x805DAF64
    // 0x805DCA90: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    func_805DAF64(rdram, ctx);
        goto after_0;
    // 0x805DCA90: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_0:
    // 0x805DCA94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCA98: jal         0x805DAF64
    // 0x805DCA9C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_805DAF64(rdram, ctx);
        goto after_1;
    // 0x805DCA9C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_1:
    // 0x805DCAA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCAA4: jal         0x805DAF64
    // 0x805DCAA8: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    func_805DAF64(rdram, ctx);
        goto after_2;
    // 0x805DCAA8: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    after_2:
    // 0x805DCAAC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x805DCAB0: b           L_805DCAE0
    // 0x805DCAB4: sh          $t6, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r14;
        goto L_805DCAE0;
    // 0x805DCAB4: sh          $t6, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r14;
L_805DCAB8:
    // 0x805DCAB8: jal         0x805DAF64
    // 0x805DCABC: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    func_805DAF64(rdram, ctx);
        goto after_3;
    // 0x805DCABC: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    after_3:
    // 0x805DCAC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCAC4: jal         0x805DAF64
    // 0x805DCAC8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    func_805DAF64(rdram, ctx);
        goto after_4;
    // 0x805DCAC8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_4:
    // 0x805DCACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCAD0: jal         0x805DAF64
    // 0x805DCAD4: addiu       $a1, $zero, 0x27E
    ctx->r5 = ADD32(0, 0X27E);
    func_805DAF64(rdram, ctx);
        goto after_5;
    // 0x805DCAD4: addiu       $a1, $zero, 0x27E
    ctx->r5 = ADD32(0, 0X27E);
    after_5:
    // 0x805DCAD8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x805DCADC: sh          $t7, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r15;
L_805DCAE0:
    // 0x805DCAE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DCAE4:
    // 0x805DCAE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DCAE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DCAEC: jr          $ra
    // 0x805DCAF0: nop

    return;
    // 0x805DCAF0: nop

;}
RECOMP_FUNC void eepmgr_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D380: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007D384: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007D388: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007D38C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8007D390: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8007D394: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8007D398: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8007D39C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8007D3A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8007D3A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007D3A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007D3AC: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8007D3B0: jal         0x8007CDFC
    // 0x8007D3B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    eepmgr_Probe(rdram, ctx);
        goto after_0;
    // 0x8007D3B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8007D3B8: addiu       $s7, $s1, 0x14
    ctx->r23 = ADD32(ctx->r17, 0X14);
    // 0x8007D3BC: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8007D3C0: addiu       $s5, $zero, 0x9
    ctx->r21 = ADD32(0, 0X9);
    // 0x8007D3C4: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x8007D3C8: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
    // 0x8007D3CC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_8007D3D0:
    // 0x8007D3D0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8007D3D4: jal         0x800824B0
    // 0x8007D3D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8007D3D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8007D3DC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D3E0: addiu       $s0, $s1, 0x2C
    ctx->r16 = ADD32(ctx->r17, 0X2C);
    // 0x8007D3E4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D3E8: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
    // 0x8007D3EC: beql        $v1, $s4, L_8007D408
    if (ctx->r3 == ctx->r20) {
        // 0x8007D3F0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8007D408;
    }
    goto skip_0;
    // 0x8007D3F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8007D3F4: beq         $v1, $s5, L_8007D42C
    if (ctx->r3 == ctx->r21) {
        // 0x8007D3F8: addiu       $s0, $s1, 0x2C
        ctx->r16 = ADD32(ctx->r17, 0X2C);
            goto L_8007D42C;
    }
    // 0x8007D3F8: addiu       $s0, $s1, 0x2C
    ctx->r16 = ADD32(ctx->r17, 0X2C);
    // 0x8007D3FC: b           L_8007D454
    // 0x8007D400: nop

        goto L_8007D454;
    // 0x8007D400: nop

    // 0x8007D404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8007D408:
    // 0x8007D408: jal         0x8007D2C4
    // 0x8007D40C: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    eepmgr_HandleRead(rdram, ctx);
        goto after_2;
    // 0x8007D40C: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    after_2:
    // 0x8007D410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007D414: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007D418: jal         0x80082210
    // 0x8007D41C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8007D41C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8007D420: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D424: b           L_8007D454
    // 0x8007D428: lh          $v1, 0x0($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X0);
        goto L_8007D454;
    // 0x8007D428: lh          $v1, 0x0($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X0);
L_8007D42C:
    // 0x8007D42C: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007D434: jal         0x8007D1EC
    // 0x8007D438: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    eepmgr_HandleWrite(rdram, ctx);
        goto after_4;
    // 0x8007D438: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    after_4:
    // 0x8007D43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007D440: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007D444: jal         0x80082210
    // 0x8007D448: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8007D448: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8007D44C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D450: lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X0);
L_8007D454:
    // 0x8007D454: bnel        $s6, $v1, L_8007D3D0
    if (ctx->r22 != ctx->r3) {
        // 0x8007D458: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8007D3D0;
    }
    goto skip_1;
    // 0x8007D458: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_1:
    // 0x8007D45C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8007D460: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007D464: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007D468: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D46C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007D470: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8007D474: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8007D478: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D47C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8007D480: jr          $ra
    // 0x8007D484: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007D484: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80444408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444408: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8044440C: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x80444410: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80444414: addiu       $v1, $a0, 0x188
    ctx->r3 = ADD32(ctx->r4, 0X188);
    // 0x80444418: addiu       $a2, $sp, 0x4
    ctx->r6 = ADD32(ctx->r29, 0X4);
    // 0x8044441C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80444420:
    // 0x80444420: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80444424: beql        $a0, $zero, L_8044444C
    if (ctx->r4 == 0) {
        // 0x80444428: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_8044444C;
    }
    goto skip_0;
    // 0x80444428: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x8044442C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x80444430: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80444434: lhu         $t8, 0x4($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4);
    // 0x80444438: bnel        $a1, $t8, L_8044444C
    if (ctx->r5 != ctx->r24) {
        // 0x8044443C: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_8044444C;
    }
    goto skip_1;
    // 0x8044443C: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x80444440: b           L_80444484
    // 0x80444444: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
        goto L_80444484;
    // 0x80444444: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80444448: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
L_8044444C:
    // 0x8044444C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80444450: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80444454: beq         $a0, $zero, L_80444478
    if (ctx->r4 == 0) {
        // 0x80444458: nop
    
            goto L_80444478;
    }
    // 0x80444458: nop

    // 0x8044445C: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x80444460: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80444464: lhu         $t1, 0x4($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X4);
    // 0x80444468: bne         $a1, $t1, L_80444478
    if (ctx->r5 != ctx->r9) {
        // 0x8044446C: nop
    
            goto L_80444478;
    }
    // 0x8044446C: nop

    // 0x80444470: b           L_80444484
    // 0x80444474: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
        goto L_80444484;
    // 0x80444474: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80444478:
    // 0x80444478: bne         $v0, $zero, L_80444420
    if (ctx->r2 != 0) {
        // 0x8044447C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80444420;
    }
    // 0x8044447C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80444480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80444484:
    // 0x80444484: jr          $ra
    // 0x80444488: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80444488: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_804479D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804479D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804479D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804479DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x804479E0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x804479E4: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804479E8: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804479EC: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X1331C) << 16);
    // 0x804479F0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804479F4: lw          $v1, 0x6CA4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CA4);
    // 0x804479F8: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x804479FC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80447A00: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80447A04: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80447A08: lw          $t0, 0x76FC($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X1331C));
    // 0x80447A0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80447A10: beql        $t0, $zero, L_80447A24
    if (ctx->r8 == 0) {
        // 0x80447A14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80447A24;
    }
    goto skip_0;
    // 0x80447A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80447A18: jalr        $t0
    // 0x80447A1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x80447A1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80447A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80447A24:
    // 0x80447A24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447A28: jr          $ra
    // 0x80447A2C: nop

    return;
    // 0x80447A2C: nop

;}
RECOMP_FUNC void func_80536830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80536834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80536838: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8053683C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80536840: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80536844: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80536848: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8053684C: lw          $v1, 0x6D98($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D98);
    // 0x80536850: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80536854: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80536858: bne         $v1, $zero, L_80536888
    if (ctx->r3 != 0) {
        // 0x8053685C: nop
    
            goto L_80536888;
    }
    // 0x8053685C: nop

    // 0x80536860: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x80536864: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80536868: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8053686C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80536870: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80536874: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80536878: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8053687C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80536880: b           L_805368AC
    // 0x80536884: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
        goto L_805368AC;
    // 0x80536884: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_80536888:
    // 0x80536888: bne         $v1, $at, L_805368A4
    if (ctx->r3 != ctx->r1) {
        // 0x8053688C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805368A4;
    }
    // 0x8053688C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80536890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80536894: jal         0x805362C4
    // 0x80536898: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    func_805362C4(rdram, ctx);
        goto after_0;
    // 0x80536898: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_0:
    // 0x8053689C: b           L_805368B0
    // 0x805368A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805368B0;
    // 0x805368A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805368A4:
    // 0x805368A4: jal         0x805362F4
    // 0x805368A8: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    func_805362F4(rdram, ctx);
        goto after_1;
    // 0x805368A8: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    after_1:
L_805368AC:
    // 0x805368AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805368B0:
    // 0x805368B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805368B4: jr          $ra
    // 0x805368B8: nop

    return;
    // 0x805368B8: nop

;}
RECOMP_FUNC void func_80057DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80057DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057DC8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80057DCC: lh          $a1, 0x8($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X8);
    // 0x80057DD0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80057DD4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80057DD8: jal         0x800651B0
    // 0x80057DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800651B0(rdram, ctx);
        goto after_0;
    // 0x80057DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80057DE0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80057DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057DE8: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x80057DEC: lw          $t6, 0x10($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X10);
    // 0x80057DF0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80057DF4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80057DF8: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80057DFC: jr          $ra
    // 0x80057E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80057E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006A084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A084: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006A088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A08C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A090: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006A094: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8006A098: lw          $a0, 0x48($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48);
    // 0x8006A09C: jal         0x80069FE4
    // 0x8006A0A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80069FE4(rdram, ctx);
        goto after_0;
    // 0x8006A0A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8006A0A4: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x8006A0A8: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006A0AC: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x8006A0B0: jal         0x80069FE4
    // 0x8006A0B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80069FE4(rdram, ctx);
        goto after_1;
    // 0x8006A0B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8006A0B8: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x8006A0BC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8006A0C0: lw          $a1, 0x4C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4C);
    // 0x8006A0C4: jal         0x80069FE4
    // 0x8006A0C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80069FE4(rdram, ctx);
        goto after_2;
    // 0x8006A0C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8006A0CC: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x8006A0D0: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    // 0x8006A0D4: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x8006A0D8: jal         0x80069FE4
    // 0x8006A0DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80069FE4(rdram, ctx);
        goto after_3;
    // 0x8006A0DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8006A0E0: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x8006A0E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A0E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A0EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006A0F0: jr          $ra
    // 0x8006A0F4: nop

    return;
    // 0x8006A0F4: nop

;}
RECOMP_FUNC void func_806F67C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F67C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F67C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F67CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F67D0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F67D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F67D8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(688, 0X640) << 16);
    // 0x806F67DC: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    // 0x806F67E0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x806F67E4: lwc1        $f6, 0x6CE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(688, 0X640));
    // 0x806F67E8: jal         0x806F678C
    // 0x806F67EC: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    func_806F678C(rdram, ctx);
        goto after_0;
    // 0x806F67EC: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    after_0:
    // 0x806F67F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F67F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F67F8: jr          $ra
    // 0x806F67FC: nop

    return;
    // 0x806F67FC: nop

;}
RECOMP_FUNC void func_807881AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807881AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807881B0: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x807881B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807881B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x807881BC: beq         $at, $zero, L_807881CC
    if (ctx->r1 == 0) {
        // 0x807881C0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_807881CC;
    }
    // 0x807881C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807881C4: bgez        $a0, L_807881D8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x807881C8: lui         $v0, 0x8010
        ctx->r2 = S32(0X8010 << 16);
            goto L_807881D8;
    }
    // 0x807881C8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
L_807881CC:
    // 0x807881CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807881D0: b           L_8078822C
    // 0x807881D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078822C;
    // 0x807881D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807881D8:
    // 0x807881D8: lw          $v0, -0x7290($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7290);
    // 0x807881DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x807881E0: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x807881E4: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x807881E8: subu        $t8, $t8, $a3
    ctx->r24 = SUB32(ctx->r24, ctx->r7);
    // 0x807881EC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x807881F0: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x807881F4: lw          $v1, 0x38($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X38);
    // 0x807881F8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807881FC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80788200: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80788204: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80788208: lw          $a0, 0x1F4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1F4);
    // 0x8078820C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80788210: jal         0x8078743C
    // 0x80788214: addu        $a1, $t3, $a2
    ctx->r5 = ADD32(ctx->r11, ctx->r6);
    func_8078743C(rdram, ctx);
        goto after_0;
    // 0x80788214: addu        $a1, $t3, $a2
    ctx->r5 = ADD32(ctx->r11, ctx->r6);
    after_0:
    // 0x80788218: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8078821C: lwc1        $f4, 0x88($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80788220: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80788224: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80788228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078822C:
    // 0x8078822C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80788230: jr          $ra
    // 0x80788234: nop

    return;
    // 0x80788234: nop

;}
RECOMP_FUNC void func_8053421C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053421C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80534220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80534224: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80534228: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8053422C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80534230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80534234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80534238: jal         0x805341DC
    // 0x8053423C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_805341DC(rdram, ctx);
        goto after_0;
    // 0x8053423C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80534240: jal         0x80534144
    // 0x80534244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80534144(rdram, ctx);
        goto after_1;
    // 0x80534244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80534248: bne         $v0, $zero, L_80534260
    if (ctx->r2 != 0) {
        // 0x8053424C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80534260;
    }
    // 0x8053424C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80534250: jal         0x800445A4
    // 0x80534254: nop

    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80534254: nop

    after_2:
    // 0x80534258: b           L_80534274
    // 0x8053425C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80534274;
    // 0x8053425C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80534260:
    // 0x80534260: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80534264: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80534268: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8053426C: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    // 0x80534270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80534274:
    // 0x80534274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80534278: jr          $ra
    // 0x8053427C: nop

    return;
    // 0x8053427C: nop

;}
RECOMP_FUNC void func_807149D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807149D8: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(730, 0X1870) << 16);
    // 0x807149DC: lwc1        $f0, 0x6090($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(730, 0X1870));
    // 0x807149E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x807149E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807149E8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x807149EC: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x807149F0: bne         $a1, $zero, L_80714A18
    if (ctx->r5 != 0) {
        // 0x807149F4: swc1        $f4, 0xE0($a0)
        MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
            goto L_80714A18;
    }
    // 0x807149F4: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x807149F8: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x807149FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80714A00: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80714A04: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(730, 0X1874) << 16);
    // 0x80714A08: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x80714A0C: lwc1        $f8, 0x6094($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(730, 0X1874));
    // 0x80714A10: b           L_80714A2C
    // 0x80714A14: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
        goto L_80714A2C;
    // 0x80714A14: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
L_80714A18:
    // 0x80714A18: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80714A1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80714A20: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80714A24: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x80714A28: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
L_80714A2C:
    // 0x80714A2C: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x80714A30: jr          $ra
    // 0x80714A34: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
    return;
    // 0x80714A34: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_804D0150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D0150: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(243, 0X10C8) << 16);
    // 0x804D0154: jr          $ra
    // 0x804D0158: addiu       $v0, $v0, 0x1218
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(243, 0X10C8));
    return;
    // 0x804D0158: addiu       $v0, $v0, 0x1218
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(243, 0X10C8));
;}
RECOMP_FUNC void func_8049EDC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049EDC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8049EDCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8049EDD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8049EDD4: jal         0x8004700C
    // 0x8049EDD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8049EDD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8049EDDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8049EDE0: beq         $v0, $zero, L_8049EE90
    if (ctx->r2 == 0) {
        // 0x8049EDE4: lw          $v1, 0x1F4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1F4);
            goto L_8049EE90;
    }
    // 0x8049EDE4: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8049EDE8: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8049EDEC: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8049EDF0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8049EDF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049EDF8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8049EDFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8049EE00: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8049EE04: nop

    // 0x8049EE08: bc1f        L_8049EE28
    if (!c1cs) {
        // 0x8049EE0C: nop
    
            goto L_8049EE28;
    }
    // 0x8049EE0C: nop

    // 0x8049EE10: lbu         $a2, 0x30($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X30);
    // 0x8049EE14: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8049EE18: jal         0x8049FBAC
    // 0x8049EE1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8049FBAC(rdram, ctx);
        goto after_1;
    // 0x8049EE1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8049EE20: b           L_8049EE54
    // 0x8049EE24: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
        goto L_8049EE54;
    // 0x8049EE24: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_8049EE28:
    // 0x8049EE28: jal         0x80049018
    // 0x8049EE2C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x8049EE2C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x8049EE30: beq         $v0, $zero, L_8049EE48
    if (ctx->r2 == 0) {
        // 0x8049EE34: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_8049EE48;
    }
    // 0x8049EE34: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8049EE38: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X12C0) << 16);
    // 0x8049EE3C: lwc1        $f10, -0x1C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X12C0));
    // 0x8049EE40: b           L_8049EE54
    // 0x8049EE44: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
        goto L_8049EE54;
    // 0x8049EE44: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
L_8049EE48:
    // 0x8049EE48: lhu         $t6, 0x8($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X8);
    // 0x8049EE4C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8049EE50: sh          $t7, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r15;
L_8049EE54:
    // 0x8049EE54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049EE58: jal         0x8049EBD8
    // 0x8049EE5C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8049EBD8(rdram, ctx);
        goto after_3;
    // 0x8049EE5C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x8049EE60: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x8049EE64: beq         $t8, $zero, L_8049EE84
    if (ctx->r24 == 0) {
        // 0x8049EE68: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_8049EE84;
    }
    // 0x8049EE68: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8049EE6C: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x8049EE70: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x8049EE74: sh          $t1, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r9;
    // 0x8049EE78: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x8049EE7C: b           L_8049EE90
    // 0x8049EE80: sh          $t2, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r10;
        goto L_8049EE90;
    // 0x8049EE80: sh          $t2, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r10;
L_8049EE84:
    // 0x8049EE84: lhu         $t3, 0x8($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X8);
    // 0x8049EE88: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x8049EE8C: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
L_8049EE90:
    // 0x8049EE90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8049EE94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8049EE98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8049EE9C: jr          $ra
    // 0x8049EEA0: nop

    return;
    // 0x8049EEA0: nop

;}
RECOMP_FUNC void func_806AAC08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AAC08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AAC0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AAC10: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806AAC14: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806AAC18: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806AAC1C: lui         $t8, 0x806B
    ctx->r24 = S32(RELOC_HI16(592, 0XC28) << 16);
    // 0x806AAC20: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806AAC24: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806AAC28: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806AAC2C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806AAC30: lw          $t8, -0x47F8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(592, 0XC28));
    // 0x806AAC34: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806AAC38: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806AAC3C: jal         0x80048490
    // 0x806AAC40: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806AAC40: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806AAC44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AAC48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AAC4C: jr          $ra
    // 0x806AAC50: nop

    return;
    // 0x806AAC50: nop

;}
RECOMP_FUNC void func_804CE4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE4D4: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x804CE4D8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CE4DC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1AF4) << 16);
    // 0x804CE4E0: bnel        $t6, $zero, L_804CE544
    if (ctx->r14 != 0) {
        // 0x804CE4E4: lwc1        $f16, 0x8($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
            goto L_804CE544;
    }
    goto skip_0;
    // 0x804CE4E4: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x804CE4E8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804CE4EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804CE4F0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1AF0) << 16);
    // 0x804CE4F4: lwc1        $f6, -0x260($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1AF0));
    // 0x804CE4F8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x804CE4FC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x804CE500: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804CE504: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x804CE508: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x804CE50C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804CE510: nop

    // 0x804CE514: bc1f        L_804CE538
    if (!c1cs) {
        // 0x804CE518: nop
    
            goto L_804CE538;
    }
    // 0x804CE518: nop

    // 0x804CE51C: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
L_804CE520:
    // 0x804CE520: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x804CE524: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x804CE528: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804CE52C: nop

    // 0x804CE530: bc1tl       L_804CE520
    if (c1cs) {
        // 0x804CE534: sub.s       $f10, $f0, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_804CE520;
    }
    goto skip_1;
    // 0x804CE534: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    skip_1:
L_804CE538:
    // 0x804CE538: b           L_804CE594
    // 0x804CE53C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
        goto L_804CE594;
    // 0x804CE53C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804CE540: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
L_804CE544:
    // 0x804CE544: lwc1        $f18, -0x25C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1AF4));
    // 0x804CE548: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x804CE54C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804CE550: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x804CE554: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x804CE558: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x804CE55C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x804CE560: nop

    // 0x804CE564: bc1fl       L_804CE594
    if (!c1cs) {
        // 0x804CE568: lwc1        $f8, 0x4($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
            goto L_804CE594;
    }
    goto skip_2;
    // 0x804CE568: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    skip_2:
    // 0x804CE56C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804CE570: nop

    // 0x804CE574: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
L_804CE578:
    // 0x804CE578: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x804CE57C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x804CE580: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x804CE584: nop

    // 0x804CE588: bc1tl       L_804CE578
    if (c1cs) {
        // 0x804CE58C: add.s       $f6, $f0, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_804CE578;
    }
    goto skip_3;
    // 0x804CE58C: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    skip_3:
    // 0x804CE590: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
L_804CE594:
    // 0x804CE594: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804CE598: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804CE59C: add.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x804CE5A0: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x804CE5A4: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
    // 0x804CE5A8: bc1fl       L_804CE5D4
    if (!c1cs) {
        // 0x804CE5AC: lwc1        $f0, 0xC($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
            goto L_804CE5D4;
    }
    goto skip_4;
    // 0x804CE5AC: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    skip_4:
    // 0x804CE5B0: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x804CE5B4: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
L_804CE5B8:
    // 0x804CE5B8: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x804CE5BC: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x804CE5C0: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804CE5C4: nop

    // 0x804CE5C8: bc1tl       L_804CE5B8
    if (c1cs) {
        // 0x804CE5CC: sub.s       $f10, $f0, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_804CE5B8;
    }
    goto skip_5;
    // 0x804CE5CC: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    skip_5:
    // 0x804CE5D0: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
L_804CE5D4:
    // 0x804CE5D4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x804CE5D8: nop

    // 0x804CE5DC: bc1f        L_804CE600
    if (!c1cs) {
        // 0x804CE5E0: nop
    
            goto L_804CE600;
    }
    // 0x804CE5E0: nop

    // 0x804CE5E4: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
L_804CE5E8:
    // 0x804CE5E8: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x804CE5EC: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x804CE5F0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x804CE5F4: nop

    // 0x804CE5F8: bc1tl       L_804CE5E8
    if (c1cs) {
        // 0x804CE5FC: add.s       $f16, $f0, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_804CE5E8;
    }
    goto skip_6;
    // 0x804CE5FC: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
    skip_6:
L_804CE600:
    // 0x804CE600: jr          $ra
    // 0x804CE604: nop

    return;
    // 0x804CE604: nop

;}
RECOMP_FUNC void func_804624B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804624B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804624B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804624B8: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804624BC: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X382C) << 16);
    // 0x804624C0: addiu       $t8, $t8, 0x3DBC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(122, 0X382C));
    // 0x804624C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804624C8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804624CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804624D0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804624D4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804624D8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804624DC: beql        $v1, $zero, L_80462514
    if (ctx->r3 == 0) {
        // 0x804624E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80462514;
    }
    goto skip_0;
    // 0x804624E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804624E4: jalr        $v1
    // 0x804624E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804624E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804624EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804624F0: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x804624F4: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x804624F8: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x804624FC: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80462500: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x80462504: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80462508: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8046250C: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x80462510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80462514:
    // 0x80462514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80462518: jr          $ra
    // 0x8046251C: nop

    return;
    // 0x8046251C: nop

;}
RECOMP_FUNC void func_804C1E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1E84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C1E88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C1E8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C1E90: jal         0x804C1D90
    // 0x804C1E94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804C1D90(rdram, ctx);
        goto after_0;
    // 0x804C1E94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804C1E98: bne         $v0, $zero, L_804C1EB0
    if (ctx->r2 != 0) {
        // 0x804C1E9C: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_804C1EB0;
    }
    // 0x804C1E9C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804C1EA0: jal         0x800445A4
    // 0x804C1EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804C1EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804C1EA8: b           L_804C1F1C
    // 0x804C1EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804C1F1C;
    // 0x804C1EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C1EB0:
    // 0x804C1EB0: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x804C1EB4: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804C1EB8: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(203, 0XFE4) << 16);
    // 0x804C1EBC: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x804C1EC0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804C1EC4: addiu       $t7, $t7, 0x2754
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(203, 0XFE4));
    // 0x804C1EC8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804C1ECC: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804C1ED0: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804C1ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C1ED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C1EDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804C1EE0: jal         0x804C1F2C
    // 0x804C1EE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804C1F2C(rdram, ctx);
        goto after_2;
    // 0x804C1EE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804C1EE8: jal         0x804C1E6C
    // 0x804C1EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C1E6C(rdram, ctx);
        goto after_3;
    // 0x804C1EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804C1EF0: jal         0x804C1DD4
    // 0x804C1EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C1DD4(rdram, ctx);
        goto after_4;
    // 0x804C1EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804C1EF8: bne         $v0, $zero, L_804C1F10
    if (ctx->r2 != 0) {
        // 0x804C1EFC: nop
    
            goto L_804C1F10;
    }
    // 0x804C1EFC: nop

    // 0x804C1F00: jal         0x800445A4
    // 0x804C1F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x804C1F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804C1F08: b           L_804C1F1C
    // 0x804C1F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804C1F1C;
    // 0x804C1F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C1F10:
    // 0x804C1F10: jal         0x804C1D0C
    // 0x804C1F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C1D0C(rdram, ctx);
        goto after_6;
    // 0x804C1F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804C1F18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C1F1C:
    // 0x804C1F1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C1F20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C1F24: jr          $ra
    // 0x804C1F28: nop

    return;
    // 0x804C1F28: nop

;}
RECOMP_FUNC void func_806B1000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B1004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B1008: jal         0x806B0F68
    // 0x806B100C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806B0F68(rdram, ctx);
        goto after_0;
    // 0x806B100C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806B1010: jal         0x8004700C
    // 0x806B1014: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x806B1014: nop

    after_1:
    // 0x806B1018: beql        $v0, $zero, L_806B1044
    if (ctx->r2 == 0) {
        // 0x806B101C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806B1044;
    }
    goto skip_0;
    // 0x806B101C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806B1020: lw          $t6, 0x138($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X138);
    // 0x806B1024: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X16F0) << 16);
    // 0x806B1028: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x806B102C: sltu        $t7, $zero, $t6
    ctx->r15 = 0 < ctx->r14 ? 1 : 0;
    // 0x806B1030: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806B1034: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x806B1038: lwc1        $f4, 0x1680($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X16F0));
    // 0x806B103C: swc1        $f4, 0x50($t9)
    MEM_W(0X50, ctx->r25) = ctx->f4.u32l;
    // 0x806B1040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B1044:
    // 0x806B1044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B1048: jr          $ra
    // 0x806B104C: nop

    return;
    // 0x806B104C: nop

;}
RECOMP_FUNC void func_80041214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041214: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80041218: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8004121C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80041220: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80041224: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80041228: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8004122C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80041230: jal         0x800659EC
    // 0x80041234: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800659EC(rdram, ctx);
        goto after_0;
    // 0x80041234: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80041238: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8004123C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80041240: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80041244: lwc1        $f4, 0x68($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80041248: lwc1        $f2, 0x120($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X120);
    // 0x8004124C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80041250: lwc1        $f14, 0x54($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X54);
    // 0x80041254: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80041258: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x8004125C: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80041260: bc1f        L_8004126C
    if (!c1cs) {
        // 0x80041264: add.s       $f14, $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
            goto L_8004126C;
    }
    // 0x80041264: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80041268: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_8004126C:
    // 0x8004126C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80041270: jal         0x800659EC
    // 0x80041274: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x80041274: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80041278: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004127C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80041280: lwc1        $f8, 0x2E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2E8);
    // 0x80041284: sub.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80041288: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8004128C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80041290: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80041294: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80041298: bc1tl       L_800412B8
    if (c1cs) {
        // 0x8004129C: swc1        $f12, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
            goto L_800412B8;
    }
    goto skip_0;
    // 0x8004129C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x800412A0: lwc1        $f10, 0x2EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2EC);
    // 0x800412A4: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800412A8: nop

    // 0x800412AC: bc1fl       L_80041328
    if (!c1cs) {
        // 0x800412B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80041328;
    }
    goto skip_1;
    // 0x800412B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800412B4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
L_800412B8:
    // 0x800412B8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x800412BC: jal         0x80065954
    // 0x800412C0: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x800412C0: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x800412C4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800412C8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800412CC: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800412D0: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800412D4: bc1f        L_800412E4
    if (!c1cs) {
        // 0x800412D8: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_800412E4;
    }
    // 0x800412D8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800412DC: b           L_80041320
    // 0x800412E0: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
        goto L_80041320;
    // 0x800412E0: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
L_800412E4:
    // 0x800412E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800412E8: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x800412EC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x800412F0: nop

    // 0x800412F4: bc1t        L_80041314
    if (c1cs) {
        // 0x800412F8: nop
    
            goto L_80041314;
    }
    // 0x800412F8: nop

    // 0x800412FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80041300: nop

    // 0x80041304: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80041308: nop

    // 0x8004130C: bc1fl       L_80041320
    if (!c1cs) {
        // 0x80041310: sub.s       $f16, $f16, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f20.fl;
            goto L_80041320;
    }
    goto skip_2;
    // 0x80041310: sub.s       $f16, $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f20.fl;
    skip_2:
L_80041314:
    // 0x80041314: b           L_80041320
    // 0x80041318: add.s       $f16, $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f20.fl;
        goto L_80041320;
    // 0x80041318: add.s       $f16, $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8004131C: sub.s       $f16, $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f20.fl;
L_80041320:
    // 0x80041320: swc1        $f16, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f16.u32l;
    // 0x80041324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80041328:
    // 0x80041328: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8004132C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80041330: jr          $ra
    // 0x80041334: nop

    return;
    // 0x80041334: nop

;}
RECOMP_FUNC void func_804A19D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A19D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A19DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A19E0: jal         0x804A1820
    // 0x804A19E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A1820(rdram, ctx);
        goto after_0;
    // 0x804A19E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A19E8: bnel        $v0, $zero, L_804A1A10
    if (ctx->r2 != 0) {
        // 0x804A19EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A1A10;
    }
    goto skip_0;
    // 0x804A19EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804A19F0: jal         0x804A2910
    // 0x804A19F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804A2910(rdram, ctx);
        goto after_1;
    // 0x804A19F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804A19F8: beq         $v0, $zero, L_804A1A0C
    if (ctx->r2 == 0) {
        // 0x804A19FC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804A1A0C;
    }
    // 0x804A19FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A1A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A1A04: jal         0x804A27A0
    // 0x804A1A08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804A27A0(rdram, ctx);
        goto after_2;
    // 0x804A1A08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_804A1A0C:
    // 0x804A1A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A1A10:
    // 0x804A1A10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A1A14: jr          $ra
    // 0x804A1A18: nop

    return;
    // 0x804A1A18: nop

;}
RECOMP_FUNC void func_807B1048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B1048: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x807B104C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x807B1050: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3938) << 16);
    // 0x807B1054: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x807B1058: lwc1        $f16, 0x3488($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3938));
    // 0x807B105C: lh          $t7, 0x2($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X2);
    // 0x807B1060: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807B1064: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x807B1068: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x807B106C: nop

    // 0x807B1070: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807B1074: sub.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x807B1078: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x807B107C: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x807B1080: add.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x807B1084: mul.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x807B1088: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
    // 0x807B108C: trunc.w.s   $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x807B1090: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x807B1094: nop

    // 0x807B1098: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x807B109C: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x807B10A0: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807B10A4: trunc.w.s   $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x807B10A8: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x807B10AC: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x807B10B0: jr          $ra
    // 0x807B10B4: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    return;
    // 0x807B10B4: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void func_806B2134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2134: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B2138: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B213C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B2140: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B2144: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B2148: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B214C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B2150: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B2154: addiu       $t6, $zero, 0x1D10
    ctx->r14 = ADD32(0, 0X1D10);
    // 0x806B2158: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B215C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x806B2160: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x806B2164: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x806B2168: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x806B216C: jal         0x806B195C
    // 0x806B2170: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_806B195C(rdram, ctx);
        goto after_0;
    // 0x806B2170: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x806B2174: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B2178: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B217C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806B2180: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B2184: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x806B2188: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x806B218C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B2190: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B2194: jr          $ra
    // 0x806B2198: nop

    return;
    // 0x806B2198: nop

;}
RECOMP_FUNC void func_805AA738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AA73C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA740: jal         0x8005FE48
    // 0x805AA744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x805AA744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AA748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AA74C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AA750: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805AA754: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x805AA758: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x805AA75C: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x805AA760: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x805AA764: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805AA768: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x805AA76C: jal         0x805AABAC
    // 0x805AA770: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_805AABAC(rdram, ctx);
        goto after_1;
    // 0x805AA770: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x805AA774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AA778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AA77C: jr          $ra
    // 0x805AA780: nop

    return;
    // 0x805AA780: nop

;}
RECOMP_FUNC void func_8057BB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057BB10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057BB14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8057BB18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057BB1C: lui         $a0, 0x8058
    ctx->r4 = S32(RELOC_HI16(387, 0X1220) << 16);
    // 0x8057BB20: lui         $a1, 0x8058
    ctx->r5 = S32(RELOC_HI16(387, 0X1230) << 16);
    // 0x8057BB24: addiu       $a1, $a1, -0x32C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(387, 0X1230));
    // 0x8057BB28: addiu       $a0, $a0, -0x32D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(387, 0X1220));
    // 0x8057BB2C: jal         0x8004667C
    // 0x8057BB30: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x8057BB30: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8057BB34: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8057BB38: lui         $a2, 0x8058
    ctx->r6 = S32(RELOC_HI16(387, 0XDC0) << 16);
    // 0x8057BB3C: addiu       $a2, $a2, -0x3730
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(387, 0XDC0));
    // 0x8057BB40: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x8057BB44: jal         0x80057B28
    // 0x8057BB48: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x8057BB48: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x8057BB4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057BB50: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8057BB54: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(387, 0XB48) << 16);
    // 0x8057BB58: sw          $zero, -0x7280($at)
    MEM_W(-0X7280, ctx->r1) = 0;
    // 0x8057BB5C: addiu       $v0, $v0, -0x39A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(387, 0XB48));
    // 0x8057BB60: jr          $ra
    // 0x8057BB64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8057BB64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805DA3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA3B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DA3B4: lui         $t0, 0x805E
    ctx->r8 = S32(RELOC_HI16(477, 0XA40) << 16);
    // 0x805DA3B8: addiu       $t0, $t0, -0x5580
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(477, 0XA40));
    // 0x805DA3BC: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x805DA3C0: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x805DA3C4: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x805DA3C8: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x805DA3CC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x805DA3D0: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x805DA3D4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x805DA3D8: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x805DA3DC: bne         $at, $zero, L_805DA458
    if (ctx->r1 != 0) {
        // 0x805DA3E0: slti        $at, $t9, 0xE
        ctx->r1 = SIGNED(ctx->r25) < 0XE ? 1 : 0;
            goto L_805DA458;
    }
    // 0x805DA3E0: slti        $at, $t9, 0xE
    ctx->r1 = SIGNED(ctx->r25) < 0XE ? 1 : 0;
    // 0x805DA3E4: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x805DA3E8: bne         $at, $zero, L_805DA404
    if (ctx->r1 != 0) {
        // 0x805DA3EC: sw          $t9, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r25;
            goto L_805DA404;
    }
    // 0x805DA3EC: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x805DA3F0: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x805DA3F4: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x805DA3F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805DA3FC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x805DA400: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
L_805DA404:
    // 0x805DA404: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x805DA408: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x805DA40C: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x805DA410: lui         $t6, 0x805E
    ctx->r14 = S32(RELOC_HI16(477, 0XAB0) << 16);
    // 0x805DA414: addiu       $t6, $t6, -0x5510
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(477, 0XAB0));
    // 0x805DA418: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x805DA41C: subu        $t5, $t5, $a2
    ctx->r13 = SUB32(ctx->r13, ctx->r6);
    // 0x805DA420: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x805DA424: addu        $a3, $t5, $t6
    ctx->r7 = ADD32(ctx->r13, ctx->r14);
    // 0x805DA428: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x805DA42C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x805DA430: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x805DA434: nop

    // 0x805DA438: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805DA43C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x805DA440: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x805DA444: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x805DA448: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x805DA44C: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x805DA450: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
    // 0x805DA454: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
L_805DA458:
    // 0x805DA458: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x805DA45C: jr          $ra
    // 0x805DA460: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
    return;
    // 0x805DA460: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_8004FB08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FB08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004FB0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004FB10: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004FB14: lw          $a0, 0x1B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1B8);
    // 0x8004FB18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004FB1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004FB20: jal         0x8004F9B0
    // 0x8004FB24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004F9B0(rdram, ctx);
        goto after_0;
    // 0x8004FB24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004FB28: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8004FB2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004FB30: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    // 0x8004FB34: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x8004FB38: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8004FB3C: jal         0x8004F42C
    // 0x8004FB40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8004F42C(rdram, ctx);
        goto after_1;
    // 0x8004FB40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8004FB44: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004FB48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004FB4C: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // 0x8004FB50: sh          $t7, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r15;
    // 0x8004FB54: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8004FB58: lw          $t9, 0x1B0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1B0);
    // 0x8004FB5C: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x8004FB60: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x8004FB64: sh          $t1, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r9;
    // 0x8004FB68: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8004FB6C: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x8004FB70: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8004FB74: beql        $t4, $zero, L_8004FB8C
    if (ctx->r12 == 0) {
        // 0x8004FB78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004FB8C;
    }
    goto skip_0;
    // 0x8004FB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004FB7C: lh          $t5, 0xC($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XC);
    // 0x8004FB80: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8004FB84: sh          $t6, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r14;
    // 0x8004FB88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004FB8C:
    // 0x8004FB8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004FB90: jr          $ra
    // 0x8004FB94: nop

    return;
    // 0x8004FB94: nop

;}
RECOMP_FUNC void func_80709588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070958C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80709590: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80709594: lw          $t6, 0x174($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X174);
    // 0x80709598: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070959C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x807095A0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x807095A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807095A8: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x807095AC: jal         0x80065728
    // 0x807095B0: sh          $zero, 0x18($t8)
    MEM_H(0X18, ctx->r24) = 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x807095B0: sh          $zero, 0x18($t8)
    MEM_H(0X18, ctx->r24) = 0;
    after_0:
    // 0x807095B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807095B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807095BC: jr          $ra
    // 0x807095C0: nop

    return;
    // 0x807095C0: nop

;}
RECOMP_FUNC void func_8044FE64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044FE64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044FE68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044FE6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8044FE70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8044FE74: jal         0x80444408
    // 0x8044FE78: addiu       $a1, $zero, 0x40F5
    ctx->r5 = ADD32(0, 0X40F5);
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x8044FE78: addiu       $a1, $zero, 0x40F5
    ctx->r5 = ADD32(0, 0X40F5);
    after_0:
    // 0x8044FE7C: beq         $v0, $zero, L_8044FEB4
    if (ctx->r2 == 0) {
        // 0x8044FE80: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_8044FEB4;
    }
    // 0x8044FE80: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8044FE84: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8044FE88: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8044FE8C: addiu       $t0, $v1, 0x6
    ctx->r8 = ADD32(ctx->r3, 0X6);
    // 0x8044FE90: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
    // 0x8044FE94: lw          $t7, -0x71A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71A8);
    // 0x8044FE98: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8044FE9C: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x8044FEA0: bnel        $t9, $zero, L_8044FEB4
    if (ctx->r25 != 0) {
        // 0x8044FEA4: sh          $v1, 0x144($v0)
        MEM_H(0X144, ctx->r2) = ctx->r3;
            goto L_8044FEB4;
    }
    goto skip_0;
    // 0x8044FEA4: sh          $v1, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r3;
    skip_0:
    // 0x8044FEA8: b           L_8044FEB4
    // 0x8044FEAC: sh          $t0, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r8;
        goto L_8044FEB4;
    // 0x8044FEAC: sh          $t0, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r8;
    // 0x8044FEB0: sh          $v1, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r3;
L_8044FEB4:
    // 0x8044FEB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044FEB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044FEBC: jr          $ra
    // 0x8044FEC0: nop

    return;
    // 0x8044FEC0: nop

;}
RECOMP_FUNC void func_80042F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042F10: lbu         $t6, 0x12C9($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X12C9);
    // 0x80042F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80042F18: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80042F1C: sb          $t7, 0x12C9($a1)
    MEM_B(0X12C9, ctx->r5) = ctx->r15;
    // 0x80042F20: lbu         $t8, 0x18($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X18);
    // 0x80042F24: bnel        $v0, $t8, L_80042F48
    if (ctx->r2 != ctx->r24) {
        // 0x80042F28: sh          $zero, 0x150($a1)
        MEM_H(0X150, ctx->r5) = 0;
            goto L_80042F48;
    }
    goto skip_0;
    // 0x80042F28: sh          $zero, 0x150($a1)
    MEM_H(0X150, ctx->r5) = 0;
    skip_0:
    // 0x80042F2C: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x80042F30: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80042F34: bnel        $t9, $at, L_80042F48
    if (ctx->r25 != ctx->r1) {
        // 0x80042F38: sh          $zero, 0x150($a1)
        MEM_H(0X150, ctx->r5) = 0;
            goto L_80042F48;
    }
    goto skip_1;
    // 0x80042F38: sh          $zero, 0x150($a1)
    MEM_H(0X150, ctx->r5) = 0;
    skip_1:
    // 0x80042F3C: jr          $ra
    // 0x80042F40: sh          $v0, 0x150($a1)
    MEM_H(0X150, ctx->r5) = ctx->r2;
    return;
    // 0x80042F40: sh          $v0, 0x150($a1)
    MEM_H(0X150, ctx->r5) = ctx->r2;
    // 0x80042F44: sh          $zero, 0x150($a1)
    MEM_H(0X150, ctx->r5) = 0;
L_80042F48:
    // 0x80042F48: jr          $ra
    // 0x80042F4C: nop

    return;
    // 0x80042F4C: nop

;}
RECOMP_FUNC void func_80067B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B74: slti        $at, $a0, -0x140
    ctx->r1 = SIGNED(ctx->r4) < -0X140 ? 1 : 0;
    // 0x80067B78: beql        $at, $zero, L_80067B8C
    if (ctx->r1 == 0) {
        // 0x80067B7C: slti        $at, $a0, 0x281
        ctx->r1 = SIGNED(ctx->r4) < 0X281 ? 1 : 0;
            goto L_80067B8C;
    }
    goto skip_0;
    // 0x80067B7C: slti        $at, $a0, 0x281
    ctx->r1 = SIGNED(ctx->r4) < 0X281 ? 1 : 0;
    skip_0:
    // 0x80067B80: b           L_80067B98
    // 0x80067B84: addiu       $a0, $zero, -0x141
    ctx->r4 = ADD32(0, -0X141);
        goto L_80067B98;
    // 0x80067B84: addiu       $a0, $zero, -0x141
    ctx->r4 = ADD32(0, -0X141);
    // 0x80067B88: slti        $at, $a0, 0x281
    ctx->r1 = SIGNED(ctx->r4) < 0X281 ? 1 : 0;
L_80067B8C:
    // 0x80067B8C: bnel        $at, $zero, L_80067B9C
    if (ctx->r1 != 0) {
        // 0x80067B90: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_80067B9C;
    }
    goto skip_1;
    // 0x80067B90: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    skip_1:
    // 0x80067B94: addiu       $a0, $zero, 0x27F
    ctx->r4 = ADD32(0, 0X27F);
L_80067B98:
    // 0x80067B98: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
L_80067B9C:
    // 0x80067B9C: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80067BA0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80067BA4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80067BA8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80067BAC: mflo        $v0
    ctx->r2 = lo;
    // 0x80067BB0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80067BB4: jr          $ra
    // 0x80067BB8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x80067BB8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_8055940C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8055940C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80559410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80559414: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80559418: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8055941C: jal         0x80048F84
    // 0x80559420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80559420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80559424: jal         0x805580E8
    // 0x80559428: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805580E8(rdram, ctx);
        goto after_1;
    // 0x80559428: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8055942C: jal         0x805582E0
    // 0x80559430: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805582E0(rdram, ctx);
        goto after_2;
    // 0x80559430: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80559434: beq         $v0, $zero, L_80559448
    if (ctx->r2 == 0) {
        // 0x80559438: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80559448;
    }
    // 0x80559438: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8055943C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80559440: jal         0x80559928
    // 0x80559444: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80559928(rdram, ctx);
        goto after_3;
    // 0x80559444: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_80559448:
    // 0x80559448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8055944C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80559450: jr          $ra
    // 0x80559454: nop

    return;
    // 0x80559454: nop

;}
RECOMP_FUNC void func_806D8A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D8A64: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806D8A68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D8A6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806D8A70: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806D8A74: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D8A78: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806D8A7C: jal         0x8004700C
    // 0x806D8A80: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D8A80: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    after_0:
    // 0x806D8A84: beq         $v0, $zero, L_806D8C20
    if (ctx->r2 == 0) {
        // 0x806D8A88: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_806D8C20;
    }
    // 0x806D8A88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806D8A8C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x806D8A90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D8A94: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x806D8A98: beq         $v0, $zero, L_806D8AB8
    if (ctx->r2 == 0) {
        // 0x806D8A9C: nop
    
            goto L_806D8AB8;
    }
    // 0x806D8A9C: nop

    // 0x806D8AA0: beq         $v0, $at, L_806D8AC0
    if (ctx->r2 == ctx->r1) {
        // 0x806D8AA4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_806D8AC0;
    }
    // 0x806D8AA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806D8AA8: beq         $v0, $at, L_806D8BD4
    if (ctx->r2 == ctx->r1) {
        // 0x806D8AAC: addiu       $s0, $s1, 0xC4
        ctx->r16 = ADD32(ctx->r17, 0XC4);
            goto L_806D8BD4;
    }
    // 0x806D8AAC: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x806D8AB0: b           L_806D8C08
    // 0x806D8AB4: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
        goto L_806D8C08;
    // 0x806D8AB4: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
L_806D8AB8:
    // 0x806D8AB8: b           L_806D8C08
    // 0x806D8ABC: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
        goto L_806D8C08;
    // 0x806D8ABC: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
L_806D8AC0:
    // 0x806D8AC0: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x806D8AC4: lwc1        $f6, 0x84($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X84);
    // 0x806D8AC8: lwc1        $f8, 0x88($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X88);
    // 0x806D8ACC: lwc1        $f10, 0x88($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X88);
    // 0x806D8AD0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806D8AD4: jal         0x80067114
    // 0x806D8AD8: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    func_80067114(rdram, ctx);
        goto after_1;
    // 0x806D8AD8: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_1:
    // 0x806D8ADC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x806D8AE0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x806D8AE4: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x806D8AE8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x806D8AEC: jal         0x80066E88
    // 0x806D8AF0: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x806D8AF0: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x806D8AF4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806D8AF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806D8AFC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(625, 0X570) << 16);
    // 0x806D8B00: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x806D8B04: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x806D8B08: lwc1        $f6, -0x71D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(625, 0X570));
    // 0x806D8B0C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806D8B10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806D8B14: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x806D8B18: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x806D8B1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806D8B20: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806D8B24: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x806D8B28: bne         $t9, $at, L_806D8B34
    if (ctx->r25 != ctx->r1) {
        // 0x806D8B2C: nop
    
            goto L_806D8B34;
    }
    // 0x806D8B2C: nop

    // 0x806D8B30: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_806D8B34:
    // 0x806D8B34: jal         0x80066DE4
    // 0x806D8B38: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x806D8B38: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x806D8B3C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806D8B40: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806D8B44: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806D8B48: mul.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x806D8B4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806D8B50: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806D8B54: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x806D8B58: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x806D8B5C: bc1fl       L_806D8B7C
    if (!c1cs) {
        // 0x806D8B60: lui         $at, 0xC040
        ctx->r1 = S32(0XC040 << 16);
            goto L_806D8B7C;
    }
    goto skip_0;
    // 0x806D8B60: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    skip_0:
    // 0x806D8B64: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806D8B68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806D8B6C: nop

    // 0x806D8B70: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x806D8B74: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x806D8B78: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
L_806D8B7C:
    // 0x806D8B7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D8B80: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806D8B84: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806D8B88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806D8B8C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x806D8B90: nop

    // 0x806D8B94: bc1f        L_806D8BA8
    if (!c1cs) {
        // 0x806D8B98: nop
    
            goto L_806D8BA8;
    }
    // 0x806D8B98: nop

    // 0x806D8B9C: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x806D8BA0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x806D8BA4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_806D8BA8:
    // 0x806D8BA8: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806D8BAC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(625, 0X574) << 16);
    // 0x806D8BB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D8BB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D8BB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806D8BBC: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x806D8BC0: lwc1        $f4, -0x71CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(625, 0X574));
    // 0x806D8BC4: jal         0x806D8DC4
    // 0x806D8BC8: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    func_806D8DC4(rdram, ctx);
        goto after_4;
    // 0x806D8BC8: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x806D8BCC: b           L_806D8C0C
    // 0x806D8BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_806D8C0C;
    // 0x806D8BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_806D8BD4:
    // 0x806D8BD4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806D8BD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D8BDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806D8BE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806D8BE4: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(625, 0X578) << 16);
    // 0x806D8BE8: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x806D8BEC: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x806D8BF0: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(625, 0X578));
    // 0x806D8BF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D8BF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D8BFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806D8C00: jal         0x806D8DC4
    // 0x806D8C04: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    func_806D8DC4(rdram, ctx);
        goto after_5;
    // 0x806D8C04: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    after_5:
L_806D8C08:
    // 0x806D8C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_806D8C0C:
    // 0x806D8C0C: jal         0x80048F84
    // 0x806D8C10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_6;
    // 0x806D8C10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x806D8C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D8C18: jal         0x80048F84
    // 0x806D8C1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x806D8C1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_806D8C20:
    // 0x806D8C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D8C24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806D8C28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806D8C2C: jr          $ra
    // 0x806D8C30: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x806D8C30: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_804217B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804217B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804217B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804217BC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804217C0: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804217C4: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(32, 0X160C) << 16);
    // 0x804217C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804217CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804217D0: lw          $t8, 0x26CC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(32, 0X160C));
    // 0x804217D4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804217D8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804217DC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804217E0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804217E4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804217E8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804217EC: beql        $v1, $zero, L_80421820
    if (ctx->r3 == 0) {
        // 0x804217F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80421820;
    }
    goto skip_0;
    // 0x804217F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804217F4: jalr        $v1
    // 0x804217F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804217F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804217FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80421800: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80421804: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80421808: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8042180C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80421810: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80421814: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80421818: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8042181C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80421820:
    // 0x80421820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80421824: jr          $ra
    // 0x80421828: nop

    return;
    // 0x80421828: nop

;}
RECOMP_FUNC void func_806FC1EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FC1EC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806FC1F0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806FC1F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806FC1F8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806FC1FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806FC200: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806FC204: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x806FC208: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806FC20C: lui         $t1, 0x8070
    ctx->r9 = S32(RELOC_HI16(700, 0X2AA0) << 16);
    // 0x806FC210: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806FC214: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806FC218: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806FC21C: lw          $t1, -0x3930($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(700, 0X2AA0));
    // 0x806FC220: jr          $ra
    // 0x806FC224: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806FC224: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x806FC228: nop

    // 0x806FC22C: nop

;}
RECOMP_FUNC void func_8076D1EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D1EC: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8076D1F0: beq         $v0, $zero, L_8076D200
    if (ctx->r2 == 0) {
        // 0x8076D1F4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8076D200;
    }
    // 0x8076D1F4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8076D1F8: b           L_8076D244
    // 0x8076D1FC: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
        goto L_8076D244;
    // 0x8076D1FC: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
L_8076D200:
    // 0x8076D200: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8076D204: lui         $t1, 0x8077
    ctx->r9 = S32(RELOC_HI16(766, 0X38C0) << 16);
    // 0x8076D208: addiu       $t1, $t1, 0xB0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(766, 0X38C0));
    // 0x8076D20C: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x8076D210: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    // 0x8076D214: bne         $at, $zero, L_8076D22C
    if (ctx->r1 != 0) {
        // 0x8076D218: sw          $v0, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r2;
            goto L_8076D22C;
    }
    // 0x8076D218: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x8076D21C: addiu       $t9, $zero, 0x15
    ctx->r25 = ADD32(0, 0X15);
    // 0x8076D220: sw          $t9, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r25;
    // 0x8076D224: jr          $ra
    // 0x8076D228: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8076D228: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8076D22C:
    // 0x8076D22C: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x8076D230: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x8076D234: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8076D238: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    // 0x8076D23C: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x8076D240: sw          $t3, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r11;
L_8076D244:
    // 0x8076D244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8076D248: jr          $ra
    // 0x8076D24C: nop

    return;
    // 0x8076D24C: nop

;}
RECOMP_FUNC void func_804C2514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C2514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C2518: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C251C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804C2520: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804C2524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C2528: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804C252C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804C2530: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804C2534: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804C2538: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804C253C: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(203, 0X1130) << 16);
    // 0x804C2540: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C2544: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804C2548: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804C254C: lw          $t2, 0x28A0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(203, 0X1130));
    // 0x804C2550: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804C2554: jal         0x804C227C
    // 0x804C2558: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_804C227C(rdram, ctx);
        goto after_0;
    // 0x804C2558: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804C255C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C2560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C2564: jr          $ra
    // 0x804C2568: nop

    return;
    // 0x804C2568: nop

    // 0x804C256C: nop

;}
RECOMP_FUNC void func_8079093C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079093C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80790940: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80790944: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80790948: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8079094C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80790950: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80790954: jal         0x80790714
    // 0x80790958: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    func_80790714(rdram, ctx);
        goto after_0;
    // 0x80790958: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    after_0:
    // 0x8079095C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x80790960: addiu       $at, $zero, 0x118
    ctx->r1 = ADD32(0, 0X118);
    // 0x80790964: bnel        $v0, $at, L_80790998
    if (ctx->r2 != ctx->r1) {
        // 0x80790968: slti        $at, $v0, 0x11D
        ctx->r1 = SIGNED(ctx->r2) < 0X11D ? 1 : 0;
            goto L_80790998;
    }
    goto skip_0;
    // 0x80790968: slti        $at, $v0, 0x11D
    ctx->r1 = SIGNED(ctx->r2) < 0X11D ? 1 : 0;
    skip_0:
    // 0x8079096C: jal         0x80011C3C
    // 0x80790970: nop

    func_80011C3C(rdram, ctx);
        goto after_1;
    // 0x80790970: nop

    after_1:
    // 0x80790974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790978: jal         0x80790878
    // 0x8079097C: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    func_80790878(rdram, ctx);
        goto after_2;
    // 0x8079097C: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    after_2:
    // 0x80790980: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80790984: sb          $zero, 0x7EA5($at)
    MEM_B(0X7EA5, ctx->r1) = 0;
    // 0x80790988: jal         0x800492C0
    // 0x8079098C: addiu       $a0, $zero, -0x69
    ctx->r4 = ADD32(0, -0X69);
    func_800492C0(rdram, ctx);
        goto after_3;
    // 0x8079098C: addiu       $a0, $zero, -0x69
    ctx->r4 = ADD32(0, -0X69);
    after_3:
    // 0x80790990: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x80790994: slti        $at, $v0, 0x11D
    ctx->r1 = SIGNED(ctx->r2) < 0X11D ? 1 : 0;
L_80790998:
    // 0x80790998: bne         $at, $zero, L_80790A08
    if (ctx->r1 != 0) {
        // 0x8079099C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80790A08;
    }
    // 0x8079099C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807909A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x807909A4: sb          $t8, 0x7EA5($at)
    MEM_B(0X7EA5, ctx->r1) = ctx->r24;
    // 0x807909A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807909AC: jal         0x80790818
    // 0x807909B0: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    func_80790818(rdram, ctx);
        goto after_4;
    // 0x807909B0: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    after_4:
    // 0x807909B4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x807909B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807909BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807909C0: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x807909C4: jal         0x8079393C
    // 0x807909C8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_5;
    // 0x807909C8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x807909CC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x807909D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807909D4: jal         0x8006CB1C
    // 0x807909D8: nop

    func_8006CB1C(rdram, ctx);
        goto after_6;
    // 0x807909D8: nop

    after_6:
    // 0x807909DC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x807909E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807909E4: jal         0x8006CB2C
    // 0x807909E8: nop

    func_8006CB2C(rdram, ctx);
        goto after_7;
    // 0x807909E8: nop

    after_7:
    // 0x807909EC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x807909F0: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x807909F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807909F8: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x807909FC: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x80790A00: jalr        $t9
    // 0x80790A04: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x80790A04: nop

    after_8:
L_80790A08:
    // 0x80790A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80790A0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80790A10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80790A14: jr          $ra
    // 0x80790A18: nop

    return;
    // 0x80790A18: nop

;}
RECOMP_FUNC void func_805670F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805670F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805670F8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805670FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80567100: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80567104: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80567108: lui         $t8, 0x8056
    ctx->r24 = S32(RELOC_HI16(375, 0XCE4) << 16);
    // 0x8056710C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80567110: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80567114: lw          $t8, 0x7234($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(375, 0XCE4));
    // 0x80567118: jal         0x80567088
    // 0x8056711C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    func_80567088(rdram, ctx);
        goto after_0;
    // 0x8056711C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    after_0:
    // 0x80567120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80567124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80567128: jr          $ra
    // 0x8056712C: nop

    return;
    // 0x8056712C: nop

;}
RECOMP_FUNC void func_8046C92C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C92C: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8046C930: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8046C934: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8046C938: beql        $t6, $zero, L_8046C9AC
    if (ctx->r14 == 0) {
        // 0x8046C93C: c.le.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
            goto L_8046C9AC;
    }
    goto skip_0;
    // 0x8046C93C: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
    skip_0:
    // 0x8046C940: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x8046C944: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8046C948: bc1fl       L_8046CA14
    if (!c1cs) {
        // 0x8046C94C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8046CA14;
    }
    goto skip_1;
    // 0x8046C94C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8046C950: sub.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8046C954: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046C958: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8046C95C: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8046C960: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8046C964: nop

    // 0x8046C968: bc1fl       L_8046CA14
    if (!c1cs) {
        // 0x8046C96C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8046CA14;
    }
    goto skip_2;
    // 0x8046C96C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8046C970: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8046C974: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8046C978: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8046C97C: c.le.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl <= ctx->f8.fl;
    // 0x8046C980: nop

    // 0x8046C984: bc1fl       L_8046CA14
    if (!c1cs) {
        // 0x8046C988: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8046CA14;
    }
    goto skip_3;
    // 0x8046C988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8046C98C: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8046C990: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x8046C994: nop

    // 0x8046C998: bc1fl       L_8046CA14
    if (!c1cs) {
        // 0x8046C99C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8046CA14;
    }
    goto skip_4;
    // 0x8046C99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x8046C9A0: jr          $ra
    // 0x8046C9A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8046C9A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8046C9A8: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
L_8046C9AC:
    // 0x8046C9AC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8046C9B0: bc1fl       L_8046CA14
    if (!c1cs) {
        // 0x8046C9B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8046CA14;
    }
    goto skip_5;
    // 0x8046C9B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x8046C9B8: sub.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x8046C9BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046C9C0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8046C9C4: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8046C9C8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8046C9CC: nop

    // 0x8046C9D0: bc1fl       L_8046CA14
    if (!c1cs) {
        // 0x8046C9D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8046CA14;
    }
    goto skip_6;
    // 0x8046C9D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x8046C9D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8046C9DC: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8046C9E0: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8046C9E4: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x8046C9E8: nop

    // 0x8046C9EC: bc1fl       L_8046CA14
    if (!c1cs) {
        // 0x8046C9F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8046CA14;
    }
    goto skip_7;
    // 0x8046C9F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x8046C9F4: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8046C9F8: c.le.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl <= ctx->f8.fl;
    // 0x8046C9FC: nop

    // 0x8046CA00: bc1fl       L_8046CA14
    if (!c1cs) {
        // 0x8046CA04: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8046CA14;
    }
    goto skip_8;
    // 0x8046CA04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_8:
    // 0x8046CA08: jr          $ra
    // 0x8046CA0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8046CA0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8046CA10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8046CA14:
    // 0x8046CA14: jr          $ra
    // 0x8046CA18: nop

    return;
    // 0x8046CA18: nop

;}
RECOMP_FUNC void func_804545D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804545D8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804545DC: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x804545E0: addiu       $a1, $zero, 0x1B6C
    ctx->r5 = ADD32(0, 0X1B6C);
    // 0x804545E4: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x804545E8: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x804545EC: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x804545F0: sw          $a1, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r5;
    // 0x804545F4: sw          $v1, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r3;
    // 0x804545F8: sw          $a1, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r5;
    // 0x804545FC: jr          $ra
    // 0x80454600: sw          $t6, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->r14;
    return;
    // 0x80454600: sw          $t6, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_804A5324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A5324: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A5328: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A532C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A5330: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A5334: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A5338: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A533C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A5340: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A5344: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A5348: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A534C: jr          $ra
    // 0x804A5350: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A5350: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800576CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800576CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800576D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800576D4: jal         0x800575B4
    // 0x800576D8: addiu       $a1, $zero, 0x404C
    ctx->r5 = ADD32(0, 0X404C);
    func_800575B4(rdram, ctx);
        goto after_0;
    // 0x800576D8: addiu       $a1, $zero, 0x404C
    ctx->r5 = ADD32(0, 0X404C);
    after_0:
    // 0x800576DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800576E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800576E4: jr          $ra
    // 0x800576E8: nop

    return;
    // 0x800576E8: nop

;}
RECOMP_FUNC void func_80469D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469D08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80469D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80469D10: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80469D14: lw          $t0, 0x1F4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X1F4);
    // 0x80469D18: bne         $a3, $at, L_80469D24
    if (ctx->r7 != ctx->r1) {
        // 0x80469D1C: addiu       $t1, $a3, 0x1
        ctx->r9 = ADD32(ctx->r7, 0X1);
            goto L_80469D24;
    }
    // 0x80469D1C: addiu       $t1, $a3, 0x1
    ctx->r9 = ADD32(ctx->r7, 0X1);
    // 0x80469D20: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80469D24:
    // 0x80469D24: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80469D28: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80469D2C: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X292C) << 16);
    // 0x80469D30: lwc1        $f14, -0x3F94($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X292C));
    // 0x80469D34: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80469D38: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80469D3C: add.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80469D40: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80469D44: nop

    // 0x80469D48: bc1tl       L_80469D68
    if (c1cs) {
        // 0x80469D4C: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80469D68;
    }
    goto skip_0;
    // 0x80469D4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x80469D50: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80469D54: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80469D58: nop

    // 0x80469D5C: bc1fl       L_80469D90
    if (!c1cs) {
        // 0x80469D60: sll         $t6, $t1, 2
        ctx->r14 = S32(ctx->r9 << 2);
            goto L_80469D90;
    }
    goto skip_1;
    // 0x80469D60: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    skip_1:
    // 0x80469D64: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80469D68:
    // 0x80469D68: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2934) << 16);
    // 0x80469D6C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80469D70: nop

    // 0x80469D74: bc1t        L_80469E0C
    if (c1cs) {
        // 0x80469D78: nop
    
            goto L_80469E0C;
    }
    // 0x80469D78: nop

    // 0x80469D7C: sub.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80469D80: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80469D84: nop

    // 0x80469D88: bc1t        L_80469E0C
    if (c1cs) {
        // 0x80469D8C: sll         $t6, $t1, 2
        ctx->r14 = S32(ctx->r9 << 2);
            goto L_80469E0C;
    }
    // 0x80469D8C: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
L_80469D90:
    // 0x80469D90: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x80469D94: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x80469D98: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x80469D9C: lwc1        $f8, 0x4C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x80469DA0: lwc1        $f10, 0x4C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x80469DA4: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2930) << 16);
    // 0x80469DA8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80469DAC: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80469DB0: nop

    // 0x80469DB4: bc1tl       L_80469DEC
    if (c1cs) {
        // 0x80469DB8: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80469DEC;
    }
    goto skip_2;
    // 0x80469DB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_2:
    // 0x80469DBC: lwc1        $f16, -0x3F90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2930));
    // 0x80469DC0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80469DC4: nop

    // 0x80469DC8: bc1tl       L_80469DEC
    if (c1cs) {
        // 0x80469DCC: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80469DEC;
    }
    goto skip_3;
    // 0x80469DCC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_3:
    // 0x80469DD0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80469DD4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80469DD8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80469DDC: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80469DE0: b           L_80469EF0
    // 0x80469DE4: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
        goto L_80469EF0;
    // 0x80469DE4: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    // 0x80469DE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80469DEC:
    // 0x80469DEC: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x80469DF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80469DF4: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80469DF8: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80469DFC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80469E00: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80469E04: b           L_80469EF0
    // 0x80469E08: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
        goto L_80469EF0;
    // 0x80469E08: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
L_80469E0C:
    // 0x80469E0C: lwc1        $f18, -0x3F8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2934));
    // 0x80469E10: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80469E14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80469E18: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80469E1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80469E20: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80469E24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80469E28: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80469E2C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80469E30: jal         0x80081C30
    // 0x80469E34: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    Math_FTanF(rdram, ctx);
        goto after_0;
    // 0x80469E34: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    after_0:
    // 0x80469E38: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80469E3C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80469E40: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80469E44: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x80469E48: addu        $v1, $t0, $t3
    ctx->r3 = ADD32(ctx->r8, ctx->r11);
    // 0x80469E4C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80469E50: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x80469E54: lwc1        $f18, 0x4C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80469E58: lwc1        $f4, 0x4C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x80469E5C: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80469E60: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80469E64: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80469E68: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2938) << 16);
    // 0x80469E6C: lwc1        $f14, -0x3F88($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2938));
    // 0x80469E70: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80469E74: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80469E78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80469E7C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80469E80: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X293C) << 16);
    // 0x80469E84: sub.s       $f2, $f16, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80469E88: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80469E8C: nop

    // 0x80469E90: bc1tl       L_80469EC4
    if (c1cs) {
        // 0x80469E94: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_80469EC4;
    }
    goto skip_4;
    // 0x80469E94: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_4:
    // 0x80469E98: lwc1        $f10, -0x3F84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X293C));
    // 0x80469E9C: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80469EA0: nop

    // 0x80469EA4: bc1tl       L_80469EC4
    if (c1cs) {
        // 0x80469EA8: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_80469EC4;
    }
    goto skip_5;
    // 0x80469EA8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_5:
    // 0x80469EAC: lwc1        $f18, 0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80469EB0: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80469EB4: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80469EB8: b           L_80469EF0
    // 0x80469EBC: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_80469EF0;
    // 0x80469EBC: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80469EC0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
L_80469EC4:
    // 0x80469EC4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80469EC8: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80469ECC: mul.s       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80469ED0: div.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80469ED4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80469ED8: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80469EDC: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80469EE0: nop

    // 0x80469EE4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80469EE8: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80469EEC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_80469EF0:
    // 0x80469EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80469EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80469EF8: jr          $ra
    // 0x80469EFC: nop

    return;
    // 0x80469EFC: nop

;}
RECOMP_FUNC void func_8069C7A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069C7A0: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(568, 0X334) << 16);
    // 0x8069C7A4: addiu       $v0, $v0, -0x352C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(568, 0X334));
    // 0x8069C7A8: jr          $ra
    // 0x8069C7AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8069C7AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80042148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004214C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042150: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80042154: lw          $v0, 0xC0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC0);
    // 0x80042158: beql        $v0, $zero, L_800421A4
    if (ctx->r2 == 0) {
        // 0x8004215C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800421A4;
    }
    goto skip_0;
    // 0x8004215C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80042160: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80042164: jal         0x80021A44
    // 0x80042168: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80021A44(rdram, ctx);
        goto after_0;
    // 0x80042168: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004216C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80042170: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80042174: jalr        $v0
    // 0x80042178: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80042178: nop

    after_1:
    // 0x8004217C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80042180: lw          $t6, 0xD8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XD8);
    // 0x80042184: sw          $zero, 0xC0($a1)
    MEM_W(0XC0, ctx->r5) = 0;
    // 0x80042188: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8004218C: beq         $at, $zero, L_80042198
    if (ctx->r1 == 0) {
        // 0x80042190: nop
    
            goto L_80042198;
    }
    // 0x80042190: nop

    // 0x80042194: sw          $zero, 0xD8($a1)
    MEM_W(0XD8, ctx->r5) = 0;
L_80042198:
    // 0x80042198: b           L_800421A4
    // 0x8004219C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800421A4;
    // 0x8004219C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800421A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800421A4:
    // 0x800421A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800421A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800421AC: jr          $ra
    // 0x800421B0: nop

    return;
    // 0x800421B0: nop

;}
RECOMP_FUNC void func_8001168C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001168C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011694: jal         0x8001137C
    // 0x80011698: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8001137C(rdram, ctx);
        goto after_0;
    // 0x80011698: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8001169C: jal         0x80011400
    // 0x800116A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80011400(rdram, ctx);
        goto after_1;
    // 0x800116A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800116A4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800116A8: lw          $a0, -0x6D68($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D68);
    // 0x800116AC: jal         0x8001A900
    // 0x800116B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001A900(rdram, ctx);
        goto after_2;
    // 0x800116B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800116B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800116B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800116BC: jr          $ra
    // 0x800116C0: nop

    return;
    // 0x800116C0: nop

;}
RECOMP_FUNC void func_8040EF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EF40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EF44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EF48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040EF4C: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x8040EF50: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(23, 0XD28) << 16);
    // 0x8040EF54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040EF58: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8040EF5C: lw          $t9, -0xB38($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(23, 0XD28));
    // 0x8040EF60: jalr        $t9
    // 0x8040EF64: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8040EF64: nop

    after_0:
    // 0x8040EF68: jal         0x8040EB60
    // 0x8040EF6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8040EB60(rdram, ctx);
        goto after_1;
    // 0x8040EF6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8040EF70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040EF74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EF78: jr          $ra
    // 0x8040EF7C: nop

    return;
    // 0x8040EF7C: nop

;}
RECOMP_FUNC void func_80475390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475390: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475394: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475398: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047539C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804753A0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804753A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804753A8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804753AC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804753B0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804753B4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804753B8: jr          $ra
    // 0x804753BC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804753BC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805ADEA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADEA4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADEA8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADEAC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADEB0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADEB4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADEB8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADEBC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADEC0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADEC4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADEC8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADECC: jr          $ra
    // 0x805ADED0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADED0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807AD364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD364: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807AD368: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807AD36C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AD370: lw          $t7, 0x968($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X968);
    // 0x807AD374: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AD378: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AD37C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x807AD380: lh          $t6, 0x962($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X962);
    // 0x807AD384: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x807AD388: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807AD38C: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x807AD390: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x807AD394: beq         $at, $zero, L_807AD3A4
    if (ctx->r1 == 0) {
        // 0x807AD398: nop
    
            goto L_807AD3A4;
    }
    // 0x807AD398: nop

    // 0x807AD39C: b           L_807AD40C
    // 0x807AD3A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807AD40C;
    // 0x807AD3A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AD3A4:
    // 0x807AD3A4: jal         0x80047090
    // 0x807AD3A8: addiu       $a0, $zero, 0x46F0
    ctx->r4 = ADD32(0, 0X46F0);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807AD3A8: addiu       $a0, $zero, 0x46F0
    ctx->r4 = ADD32(0, 0X46F0);
    after_0:
    // 0x807AD3AC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807AD3B0: bne         $v0, $at, L_807AD3C0
    if (ctx->r2 != ctx->r1) {
        // 0x807AD3B4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807AD3C0;
    }
    // 0x807AD3B4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807AD3B8: b           L_807AD40C
    // 0x807AD3BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807AD40C;
    // 0x807AD3BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AD3C0:
    // 0x807AD3C0: lui         $at, 0x46F0
    ctx->r1 = S32(0X46F0 << 16);
    // 0x807AD3C4: ori         $at, $at, 0x1C00
    ctx->r1 = ctx->r1 | 0X1C00;
    // 0x807AD3C8: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x807AD3CC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x807AD3D0: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x807AD3D4: jal         0x8004613C
    // 0x807AD3D8: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807AD3D8: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x807AD3DC: bne         $v0, $zero, L_807AD3EC
    if (ctx->r2 != 0) {
        // 0x807AD3E0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_807AD3EC;
    }
    // 0x807AD3E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x807AD3E4: b           L_807AD40C
    // 0x807AD3E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807AD40C;
    // 0x807AD3E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AD3EC:
    // 0x807AD3EC: jal         0x80044194
    // 0x807AD3F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x807AD3F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807AD3F4: jal         0x807AD2EC
    // 0x807AD3F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807AD2EC(rdram, ctx);
        goto after_3;
    // 0x807AD3F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807AD3FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AD400: jal         0x807AD348
    // 0x807AD404: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_807AD348(rdram, ctx);
        goto after_4;
    // 0x807AD404: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x807AD408: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_807AD40C:
    // 0x807AD40C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807AD410: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AD414: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AD418: jr          $ra
    // 0x807AD41C: nop

    return;
    // 0x807AD41C: nop

;}
RECOMP_FUNC void func_804494C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804494C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804494C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804494CC: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x804494D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804494D4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x804494D8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14074) << 16);
    // 0x804494DC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x804494E0: nop

    // 0x804494E4: bc1f        L_80449514
    if (!c1cs) {
        // 0x804494E8: nop
    
            goto L_80449514;
    }
    // 0x804494E8: nop

    // 0x804494EC: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x804494F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804494F4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x804494F8: beql        $v0, $t6, L_80449664
    if (ctx->r2 == ctx->r14) {
        // 0x804494FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449664;
    }
    goto skip_0;
    // 0x804494FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80449500: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80449504: jal         0x80445904
    // 0x80449508: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    func_80445904(rdram, ctx);
        goto after_0;
    // 0x80449508: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    after_0:
    // 0x8044950C: b           L_80449664
    // 0x80449510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449664;
    // 0x80449510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449514:
    // 0x80449514: lwc1        $f6, -0x7BAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14074));
    // 0x80449518: lui         $at, 0x43C3
    ctx->r1 = S32(0X43C3 << 16);
    // 0x8044951C: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80449520: nop

    // 0x80449524: bc1fl       L_80449554
    if (!c1cs) {
        // 0x80449528: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80449554;
    }
    goto skip_1;
    // 0x80449528: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x8044952C: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    // 0x80449530: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449534: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80449538: beql        $v0, $t7, L_80449664
    if (ctx->r2 == ctx->r15) {
        // 0x8044953C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449664;
    }
    goto skip_2;
    // 0x8044953C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80449540: jal         0x80445904
    // 0x80449544: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    func_80445904(rdram, ctx);
        goto after_1;
    // 0x80449544: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    after_1:
    // 0x80449548: b           L_80449664
    // 0x8044954C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449664;
    // 0x8044954C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80449550: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80449554:
    // 0x80449554: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80449558: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8044955C: nop

    // 0x80449560: bc1fl       L_80449590
    if (!c1cs) {
        // 0x80449564: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80449590;
    }
    goto skip_3;
    // 0x80449564: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_3:
    // 0x80449568: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8044956C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449570: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80449574: beql        $v0, $t8, L_80449664
    if (ctx->r2 == ctx->r24) {
        // 0x80449578: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449664;
    }
    goto skip_4;
    // 0x80449578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8044957C: jal         0x80445904
    // 0x80449580: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    func_80445904(rdram, ctx);
        goto after_2;
    // 0x80449580: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    after_2:
    // 0x80449584: b           L_80449664
    // 0x80449588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449664;
    // 0x80449588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044958C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80449590:
    // 0x80449590: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x80449594: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80449598: nop

    // 0x8044959C: bc1fl       L_804495CC
    if (!c1cs) {
        // 0x804495A0: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_804495CC;
    }
    goto skip_5;
    // 0x804495A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_5:
    // 0x804495A4: lw          $t9, 0x14($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X14);
    // 0x804495A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804495AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x804495B0: beql        $v0, $t9, L_80449664
    if (ctx->r2 == ctx->r25) {
        // 0x804495B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449664;
    }
    goto skip_6;
    // 0x804495B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x804495B8: jal         0x80445904
    // 0x804495BC: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    func_80445904(rdram, ctx);
        goto after_3;
    // 0x804495BC: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    after_3:
    // 0x804495C0: b           L_80449664
    // 0x804495C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449664;
    // 0x804495C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804495C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_804495CC:
    // 0x804495CC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x804495D0: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x804495D4: nop

    // 0x804495D8: bc1fl       L_80449608
    if (!c1cs) {
        // 0x804495DC: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80449608;
    }
    goto skip_7;
    // 0x804495DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_7:
    // 0x804495E0: lw          $t0, 0xC($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XC);
    // 0x804495E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804495E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x804495EC: beql        $v0, $t0, L_80449664
    if (ctx->r2 == ctx->r8) {
        // 0x804495F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449664;
    }
    goto skip_8;
    // 0x804495F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x804495F4: jal         0x80445904
    // 0x804495F8: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    func_80445904(rdram, ctx);
        goto after_4;
    // 0x804495F8: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    after_4:
    // 0x804495FC: b           L_80449664
    // 0x80449600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449664;
    // 0x80449600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80449604: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80449608:
    // 0x80449608: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8044960C: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x80449610: nop

    // 0x80449614: bc1fl       L_80449644
    if (!c1cs) {
        // 0x80449618: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80449644;
    }
    goto skip_9;
    // 0x80449618: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_9:
    // 0x8044961C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80449620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449624: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80449628: beql        $v0, $t1, L_80449664
    if (ctx->r2 == ctx->r9) {
        // 0x8044962C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449664;
    }
    goto skip_10;
    // 0x8044962C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x80449630: jal         0x80445904
    // 0x80449634: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_80445904(rdram, ctx);
        goto after_5;
    // 0x80449634: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_5:
    // 0x80449638: b           L_80449664
    // 0x8044963C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449664;
    // 0x8044963C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80449640: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80449644:
    // 0x80449644: nop

    // 0x80449648: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8044964C: nop

    // 0x80449650: bc1fl       L_80449664
    if (!c1cs) {
        // 0x80449654: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449664;
    }
    goto skip_11;
    // 0x80449654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x80449658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8044965C: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x80449660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449664:
    // 0x80449664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80449668: jr          $ra
    // 0x8044966C: nop

    return;
    // 0x8044966C: nop

;}
RECOMP_FUNC void func_806756C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806756C0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806756C4: addiu       $at, $zero, 0x4560
    ctx->r1 = ADD32(0, 0X4560);
    // 0x806756C8: beq         $v0, $at, L_806756E0
    if (ctx->r2 == ctx->r1) {
        // 0x806756CC: addiu       $at, $zero, 0x4561
        ctx->r1 = ADD32(0, 0X4561);
            goto L_806756E0;
    }
    // 0x806756CC: addiu       $at, $zero, 0x4561
    ctx->r1 = ADD32(0, 0X4561);
    // 0x806756D0: beq         $v0, $at, L_806756EC
    if (ctx->r2 == ctx->r1) {
        // 0x806756D4: nop
    
            goto L_806756EC;
    }
    // 0x806756D4: nop

    // 0x806756D8: b           L_806756F8
    // 0x806756DC: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(535, 0X1F80) << 16);
        goto L_806756F8;
    // 0x806756DC: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(535, 0X1F80) << 16);
L_806756E0:
    // 0x806756E0: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(535, 0X1F80) << 16);
    // 0x806756E4: jr          $ra
    // 0x806756E8: addiu       $v0, $v0, 0x7640
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(535, 0X1F80));
    return;
    // 0x806756E8: addiu       $v0, $v0, 0x7640
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(535, 0X1F80));
L_806756EC:
    // 0x806756EC: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(535, 0X2298) << 16);
    // 0x806756F0: jr          $ra
    // 0x806756F4: addiu       $v0, $v0, 0x7958
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(535, 0X2298));
    return;
    // 0x806756F4: addiu       $v0, $v0, 0x7958
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(535, 0X2298));
L_806756F8:
    // 0x806756F8: addiu       $v0, $v0, 0x7640
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(535, 0X1F80));
    // 0x806756FC: jr          $ra
    // 0x80675700: nop

    return;
    // 0x80675700: nop

;}
RECOMP_FUNC void func_80036EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036EDC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80036EE0: lbu         $t6, -0x766A($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X766A);
    // 0x80036EE4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80036EE8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80036EEC: beq         $t6, $zero, L_80036EF8
    if (ctx->r14 == 0) {
        // 0x80036EF0: nop
    
            goto L_80036EF8;
    }
    // 0x80036EF0: nop

    // 0x80036EF4: sw          $t7, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r15;
L_80036EF8:
    // 0x80036EF8: jr          $ra
    // 0x80036EFC: nop

    return;
    // 0x80036EFC: nop

;}
RECOMP_FUNC void func_8001D0FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D0FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D100: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D104: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D108: jal         0x8001CD44
    // 0x8001D10C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8001CD44(rdram, ctx);
        goto after_0;
    // 0x8001D10C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8001D110: jal         0x8001CF70
    // 0x8001D114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001CF70(rdram, ctx);
        goto after_1;
    // 0x8001D114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001D118: jal         0x8001CF94
    // 0x8001D11C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001CF94(rdram, ctx);
        goto after_2;
    // 0x8001D11C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8001D120: jal         0x8001D094
    // 0x8001D124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001D094(rdram, ctx);
        goto after_3;
    // 0x8001D124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8001D128: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8001D12C: lw          $t6, -0x7258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7258);
    // 0x8001D130: sb          $t6, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r14;
    // 0x8001D134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D138: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001D13C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D140: jr          $ra
    // 0x8001D144: nop

    return;
    // 0x8001D144: nop

;}
RECOMP_FUNC void func_80005640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005640: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80005644: lw          $v1, 0x6F84($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6F84);
    // 0x80005648: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000564C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80005650: blez        $v1, L_8000568C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80005654: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000568C;
    }
    // 0x80005654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005658: addiu       $a1, $a1, 0x4D10
    ctx->r5 = ADD32(ctx->r5, 0X4D10);
L_8000565C:
    // 0x8000565C: lh          $t6, 0x2280($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2280);
    // 0x80005660: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80005664: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80005668: bne         $a0, $t6, L_80005684
    if (ctx->r4 != ctx->r14) {
        // 0x8000566C: nop
    
            goto L_80005684;
    }
    // 0x8000566C: nop

    // 0x80005670: lh          $t7, 0x2282($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2282);
    // 0x80005674: bne         $a2, $t7, L_80005684
    if (ctx->r6 != ctx->r15) {
        // 0x80005678: nop
    
            goto L_80005684;
    }
    // 0x80005678: nop

    // 0x8000567C: jr          $ra
    // 0x80005680: lw          $v0, 0x2278($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2278);
    return;
    // 0x80005680: lw          $v0, 0x2278($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2278);
L_80005684:
    // 0x80005684: bne         $at, $zero, L_8000565C
    if (ctx->r1 != 0) {
        // 0x80005688: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8000565C;
    }
    // 0x80005688: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_8000568C:
    // 0x8000568C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005690: jr          $ra
    // 0x80005694: nop

    return;
    // 0x80005694: nop

;}
RECOMP_FUNC void func_804748D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804748D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804748D4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x804748D8: bne         $at, $zero, L_80474900
    if (ctx->r1 != 0) {
        // 0x804748DC: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80474900;
    }
    // 0x804748DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804748E0: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x804748E4: beq         $at, $zero, L_80474900
    if (ctx->r1 == 0) {
        // 0x804748E8: lwc1        $f12, 0x4C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_80474900;
    }
    // 0x804748E8: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x804748EC: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x804748F0: jal         0x80474878
    // 0x804748F4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    func_80474878(rdram, ctx);
        goto after_0;
    // 0x804748F4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x804748F8: b           L_80474928
    // 0x804748FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80474928;
    // 0x804748FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80474900:
    // 0x80474900: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80474904: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80474908: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8047490C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80474910: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80474914: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80474918: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8047491C: jal         0x804747CC
    // 0x80474920: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    func_804747CC(rdram, ctx);
        goto after_1;
    // 0x80474920: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80474924: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80474928:
    // 0x80474928: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8047492C: jr          $ra
    // 0x80474930: nop

    return;
    // 0x80474930: nop

;}
RECOMP_FUNC void func_8003BA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BA24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BA28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BA2C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8003BA30: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8003BA34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003BA38: jal         0x8003B7D4
    // 0x8003BA3C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_8003B7D4(rdram, ctx);
        goto after_0;
    // 0x8003BA3C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8003BA40: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8003BA44: bne         $at, $zero, L_8003BA54
    if (ctx->r1 != 0) {
        // 0x8003BA48: nop
    
            goto L_8003BA54;
    }
    // 0x8003BA48: nop

    // 0x8003BA4C: b           L_8003BA80
    // 0x8003BA50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003BA80;
    // 0x8003BA50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003BA54:
    // 0x8003BA54: jal         0x8004700C
    // 0x8003BA58: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x8003BA58: nop

    after_1:
    // 0x8003BA5C: beq         $v0, $zero, L_8003BA70
    if (ctx->r2 == 0) {
        // 0x8003BA60: lwc1        $f12, 0x18($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
            goto L_8003BA70;
    }
    // 0x8003BA60: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8003BA64: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x8003BA68: b           L_8003BA74
    // 0x8003BA6C: lw          $a3, -0x7250($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7250);
        goto L_8003BA74;
    // 0x8003BA6C: lw          $a3, -0x7250($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7250);
L_8003BA70:
    // 0x8003BA70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8003BA74:
    // 0x8003BA74: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003BA78: jal         0x8003B8F0
    // 0x8003BA7C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_8003B8F0(rdram, ctx);
        goto after_2;
    // 0x8003BA7C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
L_8003BA80:
    // 0x8003BA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BA84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003BA88: jr          $ra
    // 0x8003BA8C: nop

    return;
    // 0x8003BA8C: nop

;}
RECOMP_FUNC void func_805A52E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A52E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A52E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805A52E8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x805A52EC: addiu       $at, $zero, 0x4507
    ctx->r1 = ADD32(0, 0X4507);
    // 0x805A52F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A52F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A52F8: beq         $a1, $at, L_805A5320
    if (ctx->r5 == ctx->r1) {
        // 0x805A52FC: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_805A5320;
    }
    // 0x805A52FC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x805A5300: addiu       $at, $zero, 0x4508
    ctx->r1 = ADD32(0, 0X4508);
    // 0x805A5304: beq         $a1, $at, L_805A5320
    if (ctx->r5 == ctx->r1) {
        // 0x805A5308: addiu       $at, $zero, 0x4509
        ctx->r1 = ADD32(0, 0X4509);
            goto L_805A5320;
    }
    // 0x805A5308: addiu       $at, $zero, 0x4509
    ctx->r1 = ADD32(0, 0X4509);
    // 0x805A530C: beq         $a1, $at, L_805A5320
    if (ctx->r5 == ctx->r1) {
        // 0x805A5310: addiu       $at, $zero, 0x450A
        ctx->r1 = ADD32(0, 0X450A);
            goto L_805A5320;
    }
    // 0x805A5310: addiu       $at, $zero, 0x450A
    ctx->r1 = ADD32(0, 0X450A);
    // 0x805A5314: beql        $a1, $at, L_805A5324
    if (ctx->r5 == ctx->r1) {
        // 0x805A5318: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_805A5324;
    }
    goto skip_0;
    // 0x805A5318: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x805A531C: addiu       $v0, $zero, 0x4507
    ctx->r2 = ADD32(0, 0X4507);
L_805A5320:
    // 0x805A5320: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_805A5324:
    // 0x805A5324: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x805A5328: ori         $a0, $a0, 0x4400
    ctx->r4 = ctx->r4 | 0X4400;
    // 0x805A532C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x805A5330: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x805A5334: jal         0x8004613C
    // 0x805A5338: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x805A5338: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    after_0:
    // 0x805A533C: bne         $v0, $zero, L_805A534C
    if (ctx->r2 != 0) {
        // 0x805A5340: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805A534C;
    }
    // 0x805A5340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805A5344: b           L_805A5358
    // 0x805A5348: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A5358;
    // 0x805A5348: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A534C:
    // 0x805A534C: jal         0x80044194
    // 0x805A5350: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_1;
    // 0x805A5350: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x805A5354: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_805A5358:
    // 0x805A5358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A535C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A5360: jr          $ra
    // 0x805A5364: nop

    return;
    // 0x805A5364: nop

;}
RECOMP_FUNC void func_80698D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80698D20: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(556, 0X60) << 16);
    // 0x80698D24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80698D28: jr          $ra
    // 0x80698D2C: addiu       $v0, $v0, -0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(556, 0X60));
    return;
    // 0x80698D2C: addiu       $v0, $v0, -0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(556, 0X60));
;}
RECOMP_FUNC void func_80536A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536A38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80536A3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80536A40: jal         0x805367A4
    // 0x80536A44: nop

    func_805367A4(rdram, ctx);
        goto after_0;
    // 0x80536A44: nop

    after_0:
    // 0x80536A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80536A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80536A50: jr          $ra
    // 0x80536A54: nop

    return;
    // 0x80536A54: nop

;}
RECOMP_FUNC void func_80449098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449098: jr          $ra
    // 0x8044909C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8044909C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80471168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8047116C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80471174: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80471178: jalr        $t9
    // 0x8047117C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8047117C: nop

    after_0:
    // 0x80471180: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80471184: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80471188: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x8047118C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80471190: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80471194: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80471198: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8047119C: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x804711A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804711A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804711A8: jr          $ra
    // 0x804711AC: nop

    return;
    // 0x804711AC: nop

;}
RECOMP_FUNC void func_804B9F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B9F30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B9F34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B9F38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B9F3C: jal         0x8004700C
    // 0x804B9F40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804B9F40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804B9F44: beq         $v0, $zero, L_804B9F90
    if (ctx->r2 == 0) {
        // 0x804B9F48: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_804B9F90;
    }
    // 0x804B9F48: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804B9F4C: jal         0x804B7E74
    // 0x804B9F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B7E74(rdram, ctx);
        goto after_1;
    // 0x804B9F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804B9F54: jal         0x804B98E8
    // 0x804B9F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B98E8(rdram, ctx);
        goto after_2;
    // 0x804B9F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804B9F5C: jal         0x804B9E74
    // 0x804B9F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B9E74(rdram, ctx);
        goto after_3;
    // 0x804B9F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804B9F64: jal         0x804B9944
    // 0x804B9F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B9944(rdram, ctx);
        goto after_4;
    // 0x804B9F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804B9F6C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x804B9F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B9F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B9F78: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x804B9F7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804B9F80: bnel        $s0, $t7, L_804B9F94
    if (ctx->r16 != ctx->r15) {
        // 0x804B9F84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804B9F94;
    }
    goto skip_0;
    // 0x804B9F84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804B9F88: jal         0x804BA728
    // 0x804B9F8C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804BA728(rdram, ctx);
        goto after_5;
    // 0x804B9F8C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_5:
L_804B9F90:
    // 0x804B9F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B9F94:
    // 0x804B9F94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B9F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804B9F9C: jr          $ra
    // 0x804B9FA0: nop

    return;
    // 0x804B9FA0: nop

;}
RECOMP_FUNC void func_80028E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028E80: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80028E84: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80028E88: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x80028E8C: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80028E90: lw          $t1, 0xD0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XD0);
    // 0x80028E94: lw          $t8, 0xFC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XFC);
    // 0x80028E98: lw          $t5, 0x1F4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X1F4);
    // 0x80028E9C: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80028EA0: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x80028EA4: lwc1        $f10, 0x10($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X10);
    // 0x80028EA8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028EAC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80028EB0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80028EB4: lwc1        $f12, -0x20C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X20C);
    // 0x80028EB8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80028EBC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80028EC0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80028EC4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80028EC8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80028ECC: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80028ED0: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80028ED4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80028ED8: lw          $t4, -0x218C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X218C);
    // 0x80028EDC: lw          $t6, 0x38($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X38);
    // 0x80028EE0: lwc1        $f4, 0x88($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X88);
    // 0x80028EE4: lwc1        $f6, 0xAC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XAC);
    // 0x80028EE8: subu        $a3, $t6, $t4
    ctx->r7 = SUB32(ctx->r14, ctx->r12);
    // 0x80028EEC: bc1t        L_80028F0C
    if (c1cs) {
        // 0x80028EF0: sub.s       $f0, $f4, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_80028F0C;
    }
    // 0x80028EF0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80028EF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028EF8: lwc1        $f16, -0x208($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X208);
    // 0x80028EFC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80028F00: nop

    // 0x80028F04: bc1f        L_80028F50
    if (!c1cs) {
        // 0x80028F08: nop
    
            goto L_80028F50;
    }
    // 0x80028F08: nop

L_80028F0C:
    // 0x80028F0C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80028F10: nop

    // 0x80028F14: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80028F18: nop

    // 0x80028F1C: bc1fl       L_80028F40
    if (!c1cs) {
        // 0x80028F20: lw          $t8, 0x38($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X38);
            goto L_80028F40;
    }
    goto skip_0;
    // 0x80028F20: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
    skip_0:
    // 0x80028F24: lw          $t7, 0x38($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X38);
    // 0x80028F28: slti        $at, $t7, 0xD0
    ctx->r1 = SIGNED(ctx->r15) < 0XD0 ? 1 : 0;
    // 0x80028F2C: beq         $at, $zero, L_80028F50
    if (ctx->r1 == 0) {
        // 0x80028F30: nop
    
            goto L_80028F50;
    }
    // 0x80028F30: nop

    // 0x80028F34: b           L_80028F50
    // 0x80028F38: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_80028F50;
    // 0x80028F38: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80028F3C: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
L_80028F40:
    // 0x80028F40: slti        $at, $t8, 0x21
    ctx->r1 = SIGNED(ctx->r24) < 0X21 ? 1 : 0;
    // 0x80028F44: bne         $at, $zero, L_80028F50
    if (ctx->r1 != 0) {
        // 0x80028F48: nop
    
            goto L_80028F50;
    }
    // 0x80028F48: nop

    // 0x80028F4C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80028F50:
    // 0x80028F50: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80028F54: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80028F58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028F5C: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x80028F60: nop

    // 0x80028F64: bc1fl       L_80028F78
    if (!c1cs) {
        // 0x80028F68: add.s       $f4, $f0, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_80028F78;
    }
    goto skip_1;
    // 0x80028F68: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    skip_1:
    // 0x80028F6C: b           L_80028F7C
    // 0x80028F70: swc1        $f0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f0.u32l;
        goto L_80028F7C;
    // 0x80028F70: swc1        $f0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f0.u32l;
    // 0x80028F74: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
L_80028F78:
    // 0x80028F78: swc1        $f4, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f4.u32l;
L_80028F7C:
    // 0x80028F7C: lwc1        $f0, 0xB0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XB0);
    // 0x80028F80: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80028F84: nop

    // 0x80028F88: bc1tl       L_80028FA8
    if (c1cs) {
        // 0x80028F8C: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80028FA8;
    }
    goto skip_2;
    // 0x80028F8C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_2:
    // 0x80028F90: lwc1        $f6, -0x204($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X204);
    // 0x80028F94: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80028F98: nop

    // 0x80028F9C: bc1fl       L_80028FF0
    if (!c1cs) {
        // 0x80028FA0: swc1        $f14, 0xB0($a0)
        MEM_W(0XB0, ctx->r4) = ctx->f14.u32l;
            goto L_80028FF0;
    }
    goto skip_3;
    // 0x80028FA0: swc1        $f14, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f14.u32l;
    skip_3:
    // 0x80028FA4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80028FA8:
    // 0x80028FA8: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80028FAC: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80028FB0: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80028FB4: bc1f        L_80028FDC
    if (!c1cs) {
        // 0x80028FB8: addu        $t2, $t2, $t0
        ctx->r10 = ADD32(ctx->r10, ctx->r8);
            goto L_80028FDC;
    }
    // 0x80028FB8: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80028FBC: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80028FC0: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80028FC4: lw          $t1, -0x21EC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X21EC);
    // 0x80028FC8: slt         $at, $t1, $a3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80028FCC: beql        $at, $zero, L_80028FF0
    if (ctx->r1 == 0) {
        // 0x80028FD0: swc1        $f14, 0xB0($a0)
        MEM_W(0XB0, ctx->r4) = ctx->f14.u32l;
            goto L_80028FF0;
    }
    goto skip_4;
    // 0x80028FD0: swc1        $f14, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f14.u32l;
    skip_4:
    // 0x80028FD4: jr          $ra
    // 0x80028FD8: nop

    return;
    // 0x80028FD8: nop

L_80028FDC:
    // 0x80028FDC: lw          $t2, -0x21BC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X21BC);
    // 0x80028FE0: slt         $at, $a3, $t2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80028FE4: bne         $at, $zero, L_80028FF0
    if (ctx->r1 != 0) {
        // 0x80028FE8: nop
    
            goto L_80028FF0;
    }
    // 0x80028FE8: nop

    // 0x80028FEC: swc1        $f14, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f14.u32l;
L_80028FF0:
    // 0x80028FF0: jr          $ra
    // 0x80028FF4: nop

    return;
    // 0x80028FF4: nop

;}
RECOMP_FUNC void func_800516A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800516A8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800516AC: lw          $v1, -0x57C4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X57C4);
    // 0x800516B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800516B4: blez        $v1, L_800516C8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800516B8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800516C8;
    }
    // 0x800516B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800516BC:
    // 0x800516BC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800516C0: bnel        $at, $zero, L_800516BC
    if (ctx->r1 != 0) {
        // 0x800516C4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800516BC;
    }
    goto skip_0;
    // 0x800516C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
L_800516C8:
    // 0x800516C8: jr          $ra
    // 0x800516CC: nop

    return;
    // 0x800516CC: nop

;}
