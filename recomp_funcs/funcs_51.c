#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80064354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064354: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80064358: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8006435C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80064360: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80064364: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80064368: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006436C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80064370: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80064374: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80064378: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006437C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064380: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    // 0x80064384: sw          $a1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r5;
    // 0x80064388: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8006438C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80064390: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x80064394: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x80064398: lw          $fp, 0x4($v0)
    ctx->r30 = MEM_W(ctx->r2, 0X4);
    // 0x8006439C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800643A0: sw          $t7, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r15;
    // 0x800643A4: lw          $v1, 0xC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XC);
    // 0x800643A8: lw          $s3, 0x18($a3)
    ctx->r19 = MEM_W(ctx->r7, 0X18);
    // 0x800643AC: lw          $s4, 0x1C($a3)
    ctx->r20 = MEM_W(ctx->r7, 0X1C);
    // 0x800643B0: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800643B4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800643B8: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x800643BC: mflo        $s2
    ctx->r18 = lo;
    // 0x800643C0: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800643C4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800643C8: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x800643CC: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800643D0: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800643D4: addiu       $v0, $t2, 0x8
    ctx->r2 = ADD32(ctx->r10, 0X8);
    // 0x800643D8: ori         $t9, $t9, 0x18
    ctx->r25 = ctx->r25 | 0X18;
    // 0x800643DC: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800643E0: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800643E4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800643E8: ori         $t6, $t6, 0x2C80
    ctx->r14 = ctx->r14 | 0X2C80;
    // 0x800643EC: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800643F0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800643F4: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x800643F8: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x800643FC: ori         $a1, $a1, 0x4340
    ctx->r5 = ctx->r5 | 0X4340;
    // 0x80064400: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x80064404: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80064408: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006440C: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x80064410: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80064414: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x80064418: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8006441C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80064420: addiu       $t0, $a0, 0x8
    ctx->r8 = ADD32(ctx->r4, 0X8);
    // 0x80064424: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80064428: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8006442C: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x80064430: lbu         $t7, 0x3($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X3);
    // 0x80064434: addiu       $v1, $t0, 0x8
    ctx->r3 = ADD32(ctx->r8, 0X8);
    // 0x80064438: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x8006443C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80064440: lbu         $t7, 0x1($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X1);
    // 0x80064444: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80064448: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8006444C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80064450: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80064454: lbu         $t8, 0x2($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X2);
    // 0x80064458: addiu       $ra, $fp, 0x2
    ctx->r31 = ADD32(ctx->r30, 0X2);
    // 0x8006445C: mfhi        $t1
    ctx->r9 = hi;
    // 0x80064460: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x80064464: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80064468: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8006446C: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80064470: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80064474: lbu         $t8, 0x4($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X4);
    // 0x80064478: lbu         $t6, 0x7($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X7);
    // 0x8006447C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80064480: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80064484: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80064488: lbu         $t6, 0x5($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X5);
    // 0x8006448C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80064490: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80064494: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80064498: lbu         $t7, 0x6($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X6);
    // 0x8006449C: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x800644A0: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800644A4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800644A8: lui         $t8, 0x55FE
    ctx->r24 = S32(0X55FE << 16);
    // 0x800644AC: lui         $t7, 0xFC30
    ctx->r15 = S32(0XFC30 << 16);
    // 0x800644B0: ori         $t7, $t7, 0xFE61
    ctx->r15 = ctx->r15 | 0XFE61;
    // 0x800644B4: ori         $t8, $t8, 0xF379
    ctx->r24 = ctx->r24 | 0XF379;
    // 0x800644B8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800644BC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800644C0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800644C4: lui         $t9, 0xBB00
    ctx->r25 = S32(0XBB00 << 16);
    // 0x800644C8: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x800644CC: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x800644D0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800644D4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800644D8: sw          $ra, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r31;
    // 0x800644DC: sw          $t1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r9;
    // 0x800644E0: sw          $t0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r8;
    // 0x800644E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800644E8: jal         0x80063414
    // 0x800644EC: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
    func_80063414(rdram, ctx);
        goto after_0;
    // 0x800644EC: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
    after_0:
    // 0x800644F0: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x800644F4: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x800644F8: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800644FC: lw          $ra, 0xC8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XC8);
    // 0x80064500: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064504: beq         $s2, $zero, L_8006452C
    if (ctx->r18 == 0) {
        // 0x80064508: sw          $s0, 0xFC($sp)
        MEM_W(0XFC, ctx->r29) = ctx->r16;
            goto L_8006452C;
    }
    // 0x80064508: sw          $s0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r16;
    // 0x8006450C: lui         $s0, 0x400
    ctx->r16 = S32(0X400 << 16);
    // 0x80064510: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064514: ori         $s0, $s0, 0x79DF
    ctx->r16 = ctx->r16 | 0X79DF;
    // 0x80064518: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8006451C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80064520: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80064524: b           L_80064560
    // 0x80064528: lui         $s1, 0x400
    ctx->r17 = S32(0X400 << 16);
        goto L_80064560;
    // 0x80064528: lui         $s1, 0x400
    ctx->r17 = S32(0X400 << 16);
L_8006452C:
    // 0x8006452C: sll         $t8, $t1, 4
    ctx->r24 = S32(ctx->r9 << 4);
    // 0x80064530: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80064534: sll         $t7, $t1, 10
    ctx->r15 = S32(ctx->r9 << 10);
    // 0x80064538: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8006453C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064540: lui         $s1, 0x400
    ctx->r17 = S32(0X400 << 16);
    // 0x80064544: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80064548: or          $t7, $t8, $s1
    ctx->r15 = ctx->r24 | ctx->r17;
    // 0x8006454C: lui         $s0, 0x400
    ctx->r16 = S32(0X400 << 16);
    // 0x80064550: ori         $s0, $s0, 0x79DF
    ctx->r16 = ctx->r16 | 0X79DF;
    // 0x80064554: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80064558: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8006455C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_80064560:
    // 0x80064560: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x80064564: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80064568: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8006456C: blez        $t9, L_800647F4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80064570: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_800647F4;
    }
    // 0x80064570: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80064574: multu       $s3, $s4
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064578: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8006457C: lui         $t5, 0xBF00
    ctx->r13 = S32(0XBF00 << 16);
    // 0x80064580: mflo        $t6
    ctx->r14 = lo;
    // 0x80064584: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80064588: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8006458C: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80064590: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x80064594: sra         $t8, $t6, 3
    ctx->r24 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80064598: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x8006459C: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x800645A0: bgez        $v0, L_800645B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800645A4: sra         $s6, $v0, 3
        ctx->r22 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800645B0;
    }
    // 0x800645A4: sra         $s6, $v0, 3
    ctx->r22 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800645A8: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x800645AC: sra         $s6, $at, 3
    ctx->r22 = S32(SIGNED(ctx->r1) >> 3);
L_800645B0:
    // 0x800645B0: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x800645B4: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x800645B8: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x800645BC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800645C0: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800645C4: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800645C8: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800645CC: addiu       $t8, $s4, -0x1
    ctx->r24 = ADD32(ctx->r20, -0X1);
    // 0x800645D0: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800645D4: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800645D8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800645DC: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800645E0: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
L_800645E4:
    // 0x800645E4: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x800645E8: lh          $t9, 0x0($fp)
    ctx->r25 = MEM_H(ctx->r30, 0X0);
    // 0x800645EC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800645F0: lw          $t6, 0x24($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X24);
    // 0x800645F4: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800645F8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800645FC: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80064600: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x80064604: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x80064608: lui         $t8, 0xFD90
    ctx->r24 = S32(0XFD90 << 16);
    // 0x8006460C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80064610: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80064614: addu        $t4, $t9, $t6
    ctx->r12 = ADD32(ctx->r25, ctx->r14);
    // 0x80064618: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8006461C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80064620: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80064624: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80064628: lui         $t7, 0xF590
    ctx->r15 = S32(0XF590 << 16);
    // 0x8006462C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80064630: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80064634: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80064638: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8006463C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80064640: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
    // 0x80064644: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80064648: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8006464C: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x80064650: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80064654: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80064658: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006465C: slti        $at, $t7, 0x7FF
    ctx->r1 = SIGNED(ctx->r15) < 0X7FF ? 1 : 0;
    // 0x80064660: beq         $at, $zero, L_80064670
    if (ctx->r1 == 0) {
        // 0x80064664: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80064670;
    }
    // 0x80064664: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80064668: b           L_80064674
    // 0x8006466C: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
        goto L_80064674;
    // 0x8006466C: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_80064670:
    // 0x80064670: addiu       $s3, $zero, 0x7FF
    ctx->r19 = ADD32(0, 0X7FF);
L_80064674:
    // 0x80064674: bgtz        $s6, L_80064684
    if (SIGNED(ctx->r22) > 0) {
        // 0x80064678: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80064684;
    }
    // 0x80064678: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8006467C: b           L_80064688
    // 0x80064680: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
        goto L_80064688;
    // 0x80064680: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80064684:
    // 0x80064684: or          $s4, $s6, $zero
    ctx->r20 = ctx->r22 | 0;
L_80064688:
    // 0x80064688: bgtz        $s6, L_80064698
    if (SIGNED(ctx->r22) > 0) {
        // 0x8006468C: addiu       $t9, $s4, 0x7FF
        ctx->r25 = ADD32(ctx->r20, 0X7FF);
            goto L_80064698;
    }
    // 0x8006468C: addiu       $t9, $s4, 0x7FF
    ctx->r25 = ADD32(ctx->r20, 0X7FF);
    // 0x80064690: b           L_8006469C
    // 0x80064694: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8006469C;
    // 0x80064694: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80064698:
    // 0x80064698: or          $t4, $s6, $zero
    ctx->r12 = ctx->r22 | 0;
L_8006469C:
    // 0x8006469C: div         $zero, $t9, $t4
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r12)));
    // 0x800646A0: bne         $t4, $zero, L_800646AC
    if (ctx->r12 != 0) {
        // 0x800646A4: nop
    
            goto L_800646AC;
    }
    // 0x800646A4: nop

    // 0x800646A8: break       7
    do_break(2147894952);
L_800646AC:
    // 0x800646AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800646B0: bne         $t4, $at, L_800646C4
    if (ctx->r12 != ctx->r1) {
        // 0x800646B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800646C4;
    }
    // 0x800646B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800646B8: bne         $t9, $at, L_800646C4
    if (ctx->r25 != ctx->r1) {
        // 0x800646BC: nop
    
            goto L_800646C4;
    }
    // 0x800646BC: nop

    // 0x800646C0: break       6
    do_break(2147894976);
L_800646C4:
    // 0x800646C4: mflo        $t6
    ctx->r14 = lo;
    // 0x800646C8: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800646CC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800646D0: andi        $t9, $s3, 0xFFF
    ctx->r25 = ctx->r19 & 0XFFF;
    // 0x800646D4: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800646D8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800646DC: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800646E0: sw          $t8, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r24;
    // 0x800646E4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800646E8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800646EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800646F0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800646F4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800646F8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800646FC: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80064700: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80064704: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80064708: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006470C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80064710: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80064714: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80064718: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8006471C: lh          $t9, 0x0($ra)
    ctx->r25 = MEM_H(ctx->r31, 0X0);
    // 0x80064720: blez        $t9, L_800647E0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80064724: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_800647E0;
    }
    // 0x80064724: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
L_80064728:
    // 0x80064728: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x8006472C: addiu       $t8, $v0, 0x2
    ctx->r24 = ADD32(ctx->r2, 0X2);
    // 0x80064730: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80064734: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80064738: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x8006473C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80064740: addiu       $t9, $v0, 0x4
    ctx->r25 = ADD32(ctx->r2, 0X4);
    // 0x80064744: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80064748: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8006474C: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x80064750: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80064754: slti        $at, $a0, 0x1E
    ctx->r1 = SIGNED(ctx->r4) < 0X1E ? 1 : 0;
    // 0x80064758: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006475C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80064760: bne         $at, $zero, L_800647CC
    if (ctx->r1 != 0) {
        // 0x80064764: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_800647CC;
    }
    // 0x80064764: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80064768: slt         $at, $a3, $s2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8006476C: beq         $at, $zero, L_80064790
    if (ctx->r1 == 0) {
        // 0x80064770: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80064790;
    }
    // 0x80064770: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064774: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064778: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8006477C: addu        $t8, $t9, $t3
    ctx->r24 = ADD32(ctx->r25, ctx->r11);
    // 0x80064780: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80064784: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80064788: b           L_800647C4
    // 0x8006478C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
        goto L_800647C4;
    // 0x8006478C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_80064790:
    // 0x80064790: blez        $t1, L_800647C4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80064794: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_800647C4;
    }
    // 0x80064794: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064798: sll         $t7, $t1, 4
    ctx->r15 = S32(ctx->r9 << 4);
    // 0x8006479C: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x800647A0: sll         $t6, $t1, 10
    ctx->r14 = S32(ctx->r9 << 10);
    // 0x800647A4: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800647A8: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x800647AC: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x800647B0: addu        $t8, $t9, $t3
    ctx->r24 = ADD32(ctx->r25, ctx->r11);
    // 0x800647B4: or          $t6, $t7, $s1
    ctx->r14 = ctx->r15 | ctx->r17;
    // 0x800647B8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800647BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800647C0: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_800647C4:
    // 0x800647C4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800647C8: addiu       $a1, $a1, 0x1E
    ctx->r5 = ADD32(ctx->r5, 0X1E);
L_800647CC:
    // 0x800647CC: lh          $t7, 0x0($ra)
    ctx->r15 = MEM_H(ctx->r31, 0X0);
    // 0x800647D0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800647D4: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800647D8: bnel        $at, $zero, L_80064728
    if (ctx->r1 != 0) {
        // 0x800647DC: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_80064728;
    }
    goto skip_0;
    // 0x800647DC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    skip_0:
L_800647E0:
    // 0x800647E0: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800647E4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800647E8: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800647EC: bne         $s7, $t6, L_800645E4
    if (ctx->r23 != ctx->r14) {
        // 0x800647F0: addiu       $ra, $ra, 0x4
        ctx->r31 = ADD32(ctx->r31, 0X4);
            goto L_800645E4;
    }
    // 0x800647F0: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
L_800647F4:
    // 0x800647F4: lw          $t9, 0xF0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF0);
    // 0x800647F8: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800647FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80064800: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80064804: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80064808: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006480C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80064810: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80064814: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80064818: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006481C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80064820: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064824: jr          $ra
    // 0x80064828: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x80064828: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    // 0x8006482C: nop

;}
RECOMP_FUNC void func_8045D304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045D304: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8045D308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045D30C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8045D310: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8045D314: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8045D318: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8045D31C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8045D320: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8045D324: bnel        $t6, $at, L_8045D418
    if (ctx->r14 != ctx->r1) {
        // 0x8045D328: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045D418;
    }
    goto skip_0;
    // 0x8045D328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8045D32C: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x8045D330: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8045D334: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8045D338: beql        $t7, $at, L_8045D418
    if (ctx->r15 == ctx->r1) {
        // 0x8045D33C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045D418;
    }
    goto skip_1;
    // 0x8045D33C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8045D340: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8045D344: jal         0x80047AB8
    // 0x8045D348: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8045D348: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x8045D34C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8045D350: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8045D354: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8045D358: lw          $v1, 0x174($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X174);
    // 0x8045D35C: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8045D360: andi        $t9, $t8, 0xF00
    ctx->r25 = ctx->r24 & 0XF00;
    // 0x8045D364: beql        $t9, $zero, L_8045D38C
    if (ctx->r25 == 0) {
        // 0x8045D368: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_8045D38C;
    }
    goto skip_2;
    // 0x8045D368: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x8045D36C: lw          $t0, 0x180($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X180);
    // 0x8045D370: bnel        $a3, $t0, L_8045D418
    if (ctx->r7 != ctx->r8) {
        // 0x8045D374: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045D418;
    }
    goto skip_3;
    // 0x8045D374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8045D378: jal         0x8045C6A0
    // 0x8045D37C: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    func_8045C6A0(rdram, ctx);
        goto after_1;
    // 0x8045D37C: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    after_1:
    // 0x8045D380: b           L_8045D418
    // 0x8045D384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8045D418;
    // 0x8045D384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045D388: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_8045D38C:
    // 0x8045D38C: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8045D390: lh          $t1, 0x6($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X6);
    // 0x8045D394: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x8045D398: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8045D39C: lwc1        $f8, 0x4($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8045D3A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8045D3A4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8045D3A8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8045D3AC: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8045D3B0: lw          $a0, 0x180($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X180);
    // 0x8045D3B4: bne         $a0, $zero, L_8045D3E4
    if (ctx->r4 != 0) {
        // 0x8045D3B8: nop
    
            goto L_8045D3E4;
    }
    // 0x8045D3B8: nop

    // 0x8045D3BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8045D3C0: lwc1        $f6, 0xC8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC8);
    // 0x8045D3C4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8045D3C8: nop

    // 0x8045D3CC: bc1fl       L_8045D418
    if (!c1cs) {
        // 0x8045D3D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045D418;
    }
    goto skip_4;
    // 0x8045D3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8045D3D4: jal         0x8045C928
    // 0x8045D3D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8045C928(rdram, ctx);
        goto after_2;
    // 0x8045D3D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x8045D3DC: b           L_8045D418
    // 0x8045D3E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8045D418;
    // 0x8045D3E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045D3E4:
    // 0x8045D3E4: bnel        $a3, $a0, L_8045D418
    if (ctx->r7 != ctx->r4) {
        // 0x8045D3E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045D418;
    }
    goto skip_5;
    // 0x8045D3E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8045D3EC: lw          $t3, 0x1F4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X1F4);
    // 0x8045D3F0: lbu         $t4, 0xF4($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XF4);
    // 0x8045D3F4: beq         $t4, $zero, L_8045D40C
    if (ctx->r12 == 0) {
        // 0x8045D3F8: nop
    
            goto L_8045D40C;
    }
    // 0x8045D3F8: nop

    // 0x8045D3FC: jal         0x8045C6A0
    // 0x8045D400: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    func_8045C6A0(rdram, ctx);
        goto after_3;
    // 0x8045D400: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    after_3:
    // 0x8045D404: b           L_8045D418
    // 0x8045D408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8045D418;
    // 0x8045D408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045D40C:
    // 0x8045D40C: jal         0x8045CCEC
    // 0x8045D410: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8045CCEC(rdram, ctx);
        goto after_4;
    // 0x8045D410: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x8045D414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045D418:
    // 0x8045D418: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8045D41C: jr          $ra
    // 0x8045D420: nop

    return;
    // 0x8045D420: nop

;}
RECOMP_FUNC void func_8075FC44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075FC44: jr          $ra
    // 0x8075FC48: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8075FC48: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805A4504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A4504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A4508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A450C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805A4510: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(414, 0X1D40) << 16);
    // 0x805A4514: addiu       $t6, $t6, 0x50D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(414, 0X1D40));
    // 0x805A4518: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805A451C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805A4520: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805A4524: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A4528: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A452C: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x805A4530: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A4534: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A4538: jal         0x805A4678
    // 0x805A453C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_805A4678(rdram, ctx);
        goto after_0;
    // 0x805A453C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x805A4540: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A4544: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(414, 0X4A0) << 16);
    // 0x805A4548: addiu       $t9, $t9, 0x3830
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(414, 0X4A0));
    // 0x805A454C: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x805A4550: lui         $t1, 0x805A
    ctx->r9 = S32(RELOC_HI16(414, 0XC98) << 16);
    // 0x805A4554: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805A4558: addiu       $t1, $t1, 0x4028
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(414, 0XC98));
    // 0x805A455C: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x805A4560: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x805A4564: jal         0x80045A34
    // 0x805A4568: sw          $t1, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = ctx->r9;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x805A4568: sw          $t1, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = ctx->r9;
    after_1:
    // 0x805A456C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A4570: jal         0x805A4298
    // 0x805A4574: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    func_805A4298(rdram, ctx);
        goto after_2;
    // 0x805A4574: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    after_2:
    // 0x805A4578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A457C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A4580: jr          $ra
    // 0x805A4584: nop

    return;
    // 0x805A4584: nop

;}
RECOMP_FUNC void func_806E8F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E8F44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E8F48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E8F4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E8F50: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x806E8F54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E8F58: blez        $v0, L_806E8F64
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806E8F5C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806E8F64;
    }
    // 0x806E8F5C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806E8F60: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_806E8F64:
    // 0x806E8F64: jal         0x806E8818
    // 0x806E8F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E8818(rdram, ctx);
        goto after_0;
    // 0x806E8F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x806E8F6C: jal         0x806E8840
    // 0x806E8F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E8840(rdram, ctx);
        goto after_1;
    // 0x806E8F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806E8F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E8F78: jal         0x806E8990
    // 0x806E8F7C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_806E8990(rdram, ctx);
        goto after_2;
    // 0x806E8F7C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x806E8F80: jal         0x806E8E68
    // 0x806E8F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E8E68(rdram, ctx);
        goto after_3;
    // 0x806E8F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806E8F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806E8F8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E8F90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E8F94: jr          $ra
    // 0x806E8F98: nop

    return;
    // 0x806E8F98: nop

;}
RECOMP_FUNC void func_8067C0E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067C0E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067C0E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067C0EC: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8067C0F0: lui         $a3, 0x8067
    ctx->r7 = S32(0X8067 << 16);
    // 0x8067C0F4: lui         $a1, 0x8068
    ctx->r5 = S32(RELOC_HI16(541, 0X1F80) << 16);
    // 0x8067C0F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8067C0FC: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x8067C100: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x8067C104: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8067C108: lw          $a3, -0x40F0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X40F0);
    // 0x8067C10C: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(541, 0X1F80));
    // 0x8067C110: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8067C114: jal         0x8067BF84
    // 0x8067C118: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8067BF84(rdram, ctx);
        goto after_0;
    // 0x8067C118: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8067C11C: beq         $v0, $zero, L_8067C164
    if (ctx->r2 == 0) {
        // 0x8067C120: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8067C164;
    }
    // 0x8067C120: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8067C124: jal         0x8067BEF4
    // 0x8067C128: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8067BEF4(rdram, ctx);
        goto after_1;
    // 0x8067C128: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8067C12C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8067C130: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X3D00) << 16);
    // 0x8067C134: lui         $t2, 0x8068
    ctx->r10 = S32(RELOC_HI16(541, 0X22AC) << 16);
    // 0x8067C138: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067C13C: addiu       $t2, $t2, -0x40A4
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(541, 0X22AC));
    // 0x8067C140: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8067C144: lw          $t9, 0x28($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X28);
    // 0x8067C148: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8067C14C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8067C150: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8067C154: lwc1        $f4, -0x2650($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X3D00));
    // 0x8067C158: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x8067C15C: sw          $t2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r10;
    // 0x8067C160: sh          $t3, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r11;
L_8067C164:
    // 0x8067C164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067C168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067C16C: jr          $ra
    // 0x8067C170: nop

    return;
    // 0x8067C170: nop

;}
RECOMP_FUNC void func_804CB994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CB994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CB998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CB99C: jal         0x804CB6D4
    // 0x804CB9A0: nop

    func_804CB6D4(rdram, ctx);
        goto after_0;
    // 0x804CB9A0: nop

    after_0:
    // 0x804CB9A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CB9A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CB9AC: jr          $ra
    // 0x804CB9B0: nop

    return;
    // 0x804CB9B0: nop

;}
RECOMP_FUNC void func_8045C6A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045C6A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8045C6A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045C6A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045C6AC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8045C6B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8045C6B4: jal         0x8004700C
    // 0x8045C6B8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8045C6B8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8045C6BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8045C6C0: jal         0x8004816C
    // 0x8045C6C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x8045C6C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8045C6C8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8045C6CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045C6D0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8045C6D4: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8045C6D8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8045C6DC: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8045C6E0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8045C6E4: jal         0x8005FE48
    // 0x8045C6E8: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x8045C6E8: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x8045C6EC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8045C6F0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8045C6F4: beql        $v0, $zero, L_8045C710
    if (ctx->r2 == 0) {
        // 0x8045C6F8: lw          $a0, 0x38($t7)
        ctx->r4 = MEM_W(ctx->r15, 0X38);
            goto L_8045C710;
    }
    goto skip_0;
    // 0x8045C6F8: lw          $a0, 0x38($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X38);
    skip_0:
    // 0x8045C6FC: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x8045C700: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8045C704: bnel        $t6, $at, L_8045C750
    if (ctx->r14 != ctx->r1) {
        // 0x8045C708: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8045C750;
    }
    goto skip_1;
    // 0x8045C708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8045C70C: lw          $a0, 0x38($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X38);
L_8045C710:
    // 0x8045C710: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8045C714: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8045C718: bne         $at, $zero, L_8045C728
    if (ctx->r1 != 0) {
        // 0x8045C71C: nop
    
            goto L_8045C728;
    }
    // 0x8045C71C: nop

    // 0x8045C720: b           L_8045C734
    // 0x8045C724: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
        goto L_8045C734;
    // 0x8045C724: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
L_8045C728:
    // 0x8045C728: bgezl       $a0, L_8045C738
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8045C72C: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_8045C738;
    }
    goto skip_2;
    // 0x8045C72C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_2:
    // 0x8045C730: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8045C734:
    // 0x8045C734: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_8045C738:
    // 0x8045C738: jal         0x80067D5C
    // 0x8045C73C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x8045C73C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8045C740: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x8045C744: jal         0x80067818
    // 0x8045C748: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8045C748: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8045C74C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045C750:
    // 0x8045C750: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045C754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8045C758: jr          $ra
    // 0x8045C75C: nop

    return;
    // 0x8045C75C: nop

;}
RECOMP_FUNC void func_8066622C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066622C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80666230: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80666234: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80666238: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8066623C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80666240: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80666244: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80666248: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8066624C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80666250: lui         $t1, 0x8066
    ctx->r9 = S32(RELOC_HI16(504, 0X2CD8) << 16);
    // 0x80666254: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80666258: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8066625C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80666260: lw          $t1, 0x79A8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(504, 0X2CD8));
    // 0x80666264: jr          $ra
    // 0x80666268: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80666268: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8006DFC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DFC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006DFC8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8006DFCC: addiu       $t6, $a0, -0x6
    ctx->r14 = ADD32(ctx->r4, -0X6);
    // 0x8006DFD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006DFD4: sltiu       $at, $t6, 0x11
    ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
    // 0x8006DFD8: beq         $at, $zero, L_8006E048
    if (ctx->r1 == 0) {
        // 0x8006DFDC: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_8006E048;
    }
    // 0x8006DFDC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8006DFE0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006DFE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006DFE8: addu        $at, $at, $t6
    gpr jr_addend_8006DFF0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8006DFEC: lw          $t6, 0x1114($at)
    ctx->r14 = ADD32(ctx->r1, 0X1114);
    // 0x8006DFF0: jr          $t6
    // 0x8006DFF4: nop

    switch (jr_addend_8006DFF0 >> 2) {
        case 0: goto L_8006E038; break;
        case 1: goto L_8006E048; break;
        case 2: goto L_8006E048; break;
        case 3: goto L_8006E048; break;
        case 4: goto L_8006E048; break;
        case 5: goto L_8006E048; break;
        case 6: goto L_8006E048; break;
        case 7: goto L_8006E048; break;
        case 8: goto L_8006E048; break;
        case 9: goto L_8006E048; break;
        case 10: goto L_8006E048; break;
        case 11: goto L_8006E048; break;
        case 12: goto L_8006E048; break;
        case 13: goto L_8006DFF8; break;
        case 14: goto L_8006E008; break;
        case 15: goto L_8006E018; break;
        case 16: goto L_8006E028; break;
        default: switch_error(__func__, 0x8006DFF0, 0x800B1114);
    }
    // 0x8006DFF4: nop

L_8006DFF8:
    // 0x8006DFF8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006DFFC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8006E000: b           L_8006E058
    // 0x8006E004: sb          $a1, 0x58F($v0)
    MEM_B(0X58F, ctx->r2) = ctx->r5;
        goto L_8006E058;
    // 0x8006E004: sb          $a1, 0x58F($v0)
    MEM_B(0X58F, ctx->r2) = ctx->r5;
L_8006E008:
    // 0x8006E008: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006E00C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8006E010: b           L_8006E058
    // 0x8006E014: sb          $a1, 0x590($v0)
    MEM_B(0X590, ctx->r2) = ctx->r5;
        goto L_8006E058;
    // 0x8006E014: sb          $a1, 0x590($v0)
    MEM_B(0X590, ctx->r2) = ctx->r5;
L_8006E018:
    // 0x8006E018: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006E01C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8006E020: b           L_8006E058
    // 0x8006E024: sb          $a1, 0x592($v0)
    MEM_B(0X592, ctx->r2) = ctx->r5;
        goto L_8006E058;
    // 0x8006E024: sb          $a1, 0x592($v0)
    MEM_B(0X592, ctx->r2) = ctx->r5;
L_8006E028:
    // 0x8006E028: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006E02C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8006E030: b           L_8006E058
    // 0x8006E034: sb          $a1, 0x591($v0)
    MEM_B(0X591, ctx->r2) = ctx->r5;
        goto L_8006E058;
    // 0x8006E034: sb          $a1, 0x591($v0)
    MEM_B(0X591, ctx->r2) = ctx->r5;
L_8006E038:
    // 0x8006E038: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006E03C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8006E040: b           L_8006E058
    // 0x8006E044: sb          $a1, 0x593($v0)
    MEM_B(0X593, ctx->r2) = ctx->r5;
        goto L_8006E058;
    // 0x8006E044: sb          $a1, 0x593($v0)
    MEM_B(0X593, ctx->r2) = ctx->r5;
L_8006E048:
    // 0x8006E048: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006E04C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8006E050: addu        $t7, $v0, $a0
    ctx->r15 = ADD32(ctx->r2, ctx->r4);
    // 0x8006E054: sb          $a1, 0x57D($t7)
    MEM_B(0X57D, ctx->r15) = ctx->r5;
L_8006E058:
    // 0x8006E058: lw          $t8, 0x3F0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3F0);
    // 0x8006E05C: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x8006E060: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8006E064: jr          $ra
    // 0x8006E068: sb          $a1, 0x598($t9)
    MEM_B(0X598, ctx->r25) = ctx->r5;
    return;
    // 0x8006E068: sb          $a1, 0x598($t9)
    MEM_B(0X598, ctx->r25) = ctx->r5;
;}
RECOMP_FUNC void func_8066B2CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B2CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066B2D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8066B2D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066B2D8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8066B2DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8066B2E0: jal         0x8066AD18
    // 0x8066B2E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8066AD18(rdram, ctx);
        goto after_0;
    // 0x8066B2E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8066B2E8: jal         0x8066B1C4
    // 0x8066B2EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8066B1C4(rdram, ctx);
        goto after_1;
    // 0x8066B2EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8066B2F0: jal         0x8066B050
    // 0x8066B2F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8066B050(rdram, ctx);
        goto after_2;
    // 0x8066B2F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8066B2F8: beq         $v0, $zero, L_8066B314
    if (ctx->r2 == 0) {
        // 0x8066B2FC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8066B314;
    }
    // 0x8066B2FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8066B300: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8066B304: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B308: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8066B30C: jal         0x8066B970
    // 0x8066B310: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    func_8066B970(rdram, ctx);
        goto after_3;
    // 0x8066B310: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    after_3:
L_8066B314:
    // 0x8066B314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066B318: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066B31C: jr          $ra
    // 0x8066B320: nop

    return;
    // 0x8066B320: nop

;}
RECOMP_FUNC void func_805CF180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CF180: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805CF184: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805CF188: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805CF18C: lui         $t8, 0x805D
    ctx->r24 = S32(RELOC_HI16(459, 0X32C) << 16);
    // 0x805CF190: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805CF194: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805CF198: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805CF19C: lw          $t8, -0xDC4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(459, 0X32C));
    // 0x805CF1A0: jr          $ra
    // 0x805CF1A4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x805CF1A4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8075F2A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075F2A8: jr          $ra
    // 0x8075F2AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8075F2AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8040E944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E944: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040E948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040E94C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8040E950: lh          $t6, 0x144($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X144);
    // 0x8040E954: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8040E958: bnel        $t6, $at, L_8040E978
    if (ctx->r14 != ctx->r1) {
        // 0x8040E95C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040E978;
    }
    goto skip_0;
    // 0x8040E95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040E960: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
    // 0x8040E964: bnel        $t7, $zero, L_8040E978
    if (ctx->r15 != 0) {
        // 0x8040E968: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040E978;
    }
    goto skip_1;
    // 0x8040E968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8040E96C: jal         0x8040E89C
    // 0x8040E970: nop

    func_8040E89C(rdram, ctx);
        goto after_0;
    // 0x8040E970: nop

    after_0:
    // 0x8040E974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E978:
    // 0x8040E978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040E97C: jr          $ra
    // 0x8040E980: nop

    return;
    // 0x8040E980: nop

;}
RECOMP_FUNC void func_8007691C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007691C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80076920: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80076924: jal         0x80084820
    // 0x80076928: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x80076928: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_0:
    // 0x8007692C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076930: lwc1        $f4, 0x26C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X26C4);
    // 0x80076934: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076938: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007693C: lwc1        $f6, 0x26C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X26C8);
    // 0x80076940: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80076944: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80076948: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007694C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80076950: lui         $a2, 0x43A0
    ctx->r6 = S32(0X43A0 << 16);
    // 0x80076954: lui         $a3, 0x4370
    ctx->r7 = S32(0X4370 << 16);
    // 0x80076958: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8007695C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80076960: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80076964: jal         0x8008CCD4
    // 0x80076968: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    guOrtho(rdram, ctx);
        goto after_1;
    // 0x80076968: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8007696C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80076970: addiu       $v0, $v0, -0x7AF0
    ctx->r2 = ADD32(ctx->r2, -0X7AF0);
    // 0x80076974: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x80076978: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007697C: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    // 0x80076980: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x80076984: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x80076988: addiu       $a3, $zero, 0x1E0
    ctx->r7 = ADD32(0, 0X1E0);
    // 0x8007698C: addiu       $t0, $zero, 0x1FF
    ctx->r8 = ADD32(0, 0X1FF);
    // 0x80076990: addiu       $t1, $t7, 0x3C
    ctx->r9 = ADD32(ctx->r15, 0X3C);
    // 0x80076994: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_80076998:
    // 0x80076998: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8007699C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800769A0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800769A4: sw          $t9, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r25;
    // 0x800769A8: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x800769AC: sw          $t8, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r24;
    // 0x800769B0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800769B4: bne         $t7, $t1, L_80076998
    if (ctx->r15 != ctx->r9) {
        // 0x800769B8: sw          $t9, 0x1C($t6)
        MEM_W(0X1C, ctx->r14) = ctx->r25;
            goto L_80076998;
    }
    // 0x800769B8: sw          $t9, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r25;
    // 0x800769BC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800769C0: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800769C4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800769C8: sw          $t9, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r25;
    // 0x800769CC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800769D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800769D4: sh          $t2, 0x60($t3)
    MEM_H(0X60, ctx->r11) = ctx->r10;
    // 0x800769D8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800769DC: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x800769E0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800769E4: sb          $zero, 0x1($t5)
    MEM_B(0X1, ctx->r13) = 0;
    // 0x800769E8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800769EC: sb          $zero, 0x2($t1)
    MEM_B(0X2, ctx->r9) = 0;
    // 0x800769F0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800769F4: sb          $v1, 0x3($t7)
    MEM_B(0X3, ctx->r15) = ctx->r3;
    // 0x800769F8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800769FC: sb          $zero, 0x4($t6)
    MEM_B(0X4, ctx->r14) = 0;
    // 0x80076A00: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80076A04: sb          $t8, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r24;
    // 0x80076A08: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80076A0C: sh          $a0, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r4;
    // 0x80076A10: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80076A14: sh          $a1, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r5;
    // 0x80076A18: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80076A1C: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
    // 0x80076A20: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80076A24: sw          $zero, 0x10($t5)
    MEM_W(0X10, ctx->r13) = 0;
    // 0x80076A28: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80076A2C: sh          $zero, 0x18($t1)
    MEM_H(0X18, ctx->r9) = 0;
    // 0x80076A30: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80076A34: sh          $zero, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = 0;
    // 0x80076A38: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80076A3C: sh          $a0, 0x1C($t6)
    MEM_H(0X1C, ctx->r14) = ctx->r4;
    // 0x80076A40: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80076A44: sh          $a1, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = ctx->r5;
    // 0x80076A48: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80076A4C: sh          $a2, 0x68($t9)
    MEM_H(0X68, ctx->r25) = ctx->r6;
    // 0x80076A50: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80076A54: sh          $a3, 0x6A($t2)
    MEM_H(0X6A, ctx->r10) = ctx->r7;
    // 0x80076A58: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80076A5C: sh          $t0, 0x6C($t3)
    MEM_H(0X6C, ctx->r11) = ctx->r8;
    // 0x80076A60: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80076A64: sh          $zero, 0x6E($t4)
    MEM_H(0X6E, ctx->r12) = 0;
    // 0x80076A68: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80076A6C: sh          $a2, 0x70($t5)
    MEM_H(0X70, ctx->r13) = ctx->r6;
    // 0x80076A70: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80076A74: sh          $a3, 0x72($t1)
    MEM_H(0X72, ctx->r9) = ctx->r7;
    // 0x80076A78: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80076A7C: sh          $t0, 0x74($t7)
    MEM_H(0X74, ctx->r15) = ctx->r8;
    // 0x80076A80: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80076A84: sh          $zero, 0x76($t6)
    MEM_H(0X76, ctx->r14) = 0;
    // 0x80076A88: sw          $zero, -0x7AE4($at)
    MEM_W(-0X7AE4, ctx->r1) = 0;
    // 0x80076A8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076A90: sb          $v1, -0x7AE0($at)
    MEM_B(-0X7AE0, ctx->r1) = ctx->r3;
    // 0x80076A94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80076A98: jr          $ra
    // 0x80076A9C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80076A9C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8000ED6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ED6C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8000ED70: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000ED74: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000ED78: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000ED7C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000ED80: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000ED84: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000ED88: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000ED8C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000ED90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000ED94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000ED98: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000ED9C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8000EDA0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8000EDA4: bgezl       $t8, L_8000EDB8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8000EDA8: lw          $s6, 0x4C($s4)
        ctx->r22 = MEM_W(ctx->r20, 0X4C);
            goto L_8000EDB8;
    }
    goto skip_0;
    // 0x8000EDA8: lw          $s6, 0x4C($s4)
    ctx->r22 = MEM_W(ctx->r20, 0X4C);
    skip_0:
    // 0x8000EDAC: b           L_8000F92C
    // 0x8000EDB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8000F92C;
    // 0x8000EDB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000EDB4: lw          $s6, 0x4C($s4)
    ctx->r22 = MEM_W(ctx->r20, 0X4C);
L_8000EDB8:
    // 0x8000EDB8: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x8000EDBC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8000EDC0: bgezl       $t1, L_8000EDDC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8000EDC4: lhu         $v1, 0x1E($s4)
        ctx->r3 = MEM_HU(ctx->r20, 0X1E);
            goto L_8000EDDC;
    }
    goto skip_1;
    // 0x8000EDC4: lhu         $v1, 0x1E($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X1E);
    skip_1:
    // 0x8000EDC8: lbu         $t2, 0x3($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X3);
    // 0x8000EDCC: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x8000EDD0: bnel        $t3, $zero, L_8000F958
    if (ctx->r11 != 0) {
        // 0x8000EDD4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8000F958;
    }
    goto skip_2;
    // 0x8000EDD4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x8000EDD8: lhu         $v1, 0x1E($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X1E);
L_8000EDDC:
    // 0x8000EDDC: addiu       $s5, $s4, 0x68
    ctx->r21 = ADD32(ctx->r20, 0X68);
    // 0x8000EDE0: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x8000EDE4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000EDE8: bne         $at, $zero, L_8000EDF8
    if (ctx->r1 != 0) {
        // 0x8000EDEC: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8000EDF8;
    }
    // 0x8000EDEC: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8000EDF0: b           L_8000F928
    // 0x8000EDF4: sh          $t4, 0x1E($s4)
    MEM_H(0X1E, ctx->r20) = ctx->r12;
        goto L_8000F928;
    // 0x8000EDF4: sh          $t4, 0x1E($s4)
    MEM_H(0X1E, ctx->r20) = ctx->r12;
L_8000EDF8:
    // 0x8000EDF8: lui         $fp, 0x800B
    ctx->r30 = S32(0X800B << 16);
    // 0x8000EDFC: addiu       $fp, $fp, 0x4D10
    ctx->r30 = ADD32(ctx->r30, 0X4D10);
L_8000EE00:
    // 0x8000EE00: jal         0x8000DCB4
    // 0x8000EE04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_0;
    // 0x8000EE04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x8000EE08: slti        $at, $v0, 0xB0
    ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
    // 0x8000EE0C: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x8000EE10: bne         $at, $zero, L_8000F688
    if (ctx->r1 != 0) {
        // 0x8000EE14: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000F688;
    }
    // 0x8000EE14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000EE18: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8000EE1C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8000EE20: lbu         $v1, -0x72F0($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X72F0);
    // 0x8000EE24: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x8000EE28: andi        $a1, $v1, 0x3
    ctx->r5 = ctx->r3 & 0X3;
    // 0x8000EE2C: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x8000EE30: blez        $t5, L_8000EE80
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8000EE34: andi        $a3, $a1, 0xFF
        ctx->r7 = ctx->r5 & 0XFF;
            goto L_8000EE80;
    }
    // 0x8000EE34: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x8000EE38: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8000EE3C: addu        $s3, $t7, $s0
    ctx->r19 = ADD32(ctx->r15, ctx->r16);
L_8000EE40:
    // 0x8000EE40: andi        $t8, $v1, 0x80
    ctx->r24 = ctx->r3 & 0X80;
    // 0x8000EE44: bne         $t8, $zero, L_8000EE5C
    if (ctx->r24 != 0) {
        // 0x8000EE48: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8000EE5C;
    }
    // 0x8000EE48: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8000EE4C: jal         0x8000DCB4
    // 0x8000EE50: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_1;
    // 0x8000EE50: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8000EE54: b           L_8000EE68
    // 0x8000EE58: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
        goto L_8000EE68;
    // 0x8000EE58: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8000EE5C:
    // 0x8000EE5C: jal         0x8000DCC8
    // 0x8000EE60: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_2;
    // 0x8000EE60: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x8000EE64: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8000EE68:
    // 0x8000EE68: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000EE6C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8000EE70: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x8000EE74: bne         $at, $zero, L_8000EE40
    if (ctx->r1 != 0) {
        // 0x8000EE78: andi        $v1, $v1, 0xFF
        ctx->r3 = ctx->r3 & 0XFF;
            goto L_8000EE40;
    }
    // 0x8000EE78: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8000EE7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000EE80:
    // 0x8000EE80: slti        $at, $s2, 0xF2
    ctx->r1 = SIGNED(ctx->r18) < 0XF2 ? 1 : 0;
    // 0x8000EE84: bne         $at, $zero, L_8000EEC8
    if (ctx->r1 != 0) {
        // 0x8000EE88: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_8000EEC8;
    }
    // 0x8000EE88: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8000EE8C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000EE90: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000EE94: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8000EE98: jal         0x8000D398
    // 0x8000EE9C: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    func_8000D398(rdram, ctx);
        goto after_3;
    // 0x8000EE9C: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    after_3:
    // 0x8000EEA0: beq         $v0, $zero, L_8000EE00
    if (ctx->r2 == 0) {
        // 0x8000EEA4: nop
    
            goto L_8000EE00;
    }
    // 0x8000EEA4: nop

    // 0x8000EEA8: bne         $v0, $s7, L_8000EEC0
    if (ctx->r2 != ctx->r23) {
        // 0x8000EEAC: nop
    
            goto L_8000EEC0;
    }
    // 0x8000EEAC: nop

    // 0x8000EEB0: jal         0x8000D86C
    // 0x8000EEB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8000D86C(rdram, ctx);
        goto after_4;
    // 0x8000EEB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x8000EEB8: b           L_8000F92C
    // 0x8000EEBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8000F92C;
    // 0x8000EEBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000EEC0:
    // 0x8000EEC0: b           L_8000F928
    // 0x8000EEC4: sh          $v0, 0x1E($s4)
    MEM_H(0X1E, ctx->r20) = ctx->r2;
        goto L_8000F928;
    // 0x8000EEC4: sh          $v0, 0x1E($s4)
    MEM_H(0X1E, ctx->r20) = ctx->r2;
L_8000EEC8:
    // 0x8000EEC8: addiu       $t9, $s0, -0xB0
    ctx->r25 = ADD32(ctx->r16, -0XB0);
    // 0x8000EECC: sltiu       $at, $t9, 0x42
    ctx->r1 = ctx->r25 < 0X42 ? 1 : 0;
    // 0x8000EED0: beq         $at, $zero, L_8000EE00
    if (ctx->r1 == 0) {
        // 0x8000EED4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8000EE00;
    }
    // 0x8000EED4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000EED8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000EEDC: addu        $at, $at, $t9
    gpr jr_addend_8000EEE4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8000EEE0: lw          $t9, -0x4200($at)
    ctx->r25 = ADD32(ctx->r1, -0X4200);
    // 0x8000EEE4: jr          $t9
    // 0x8000EEE8: nop

    switch (jr_addend_8000EEE4 >> 2) {
        case 0: goto L_8000F510; break;
        case 1: goto L_8000F524; break;
        case 2: goto L_8000F55C; break;
        case 3: goto L_8000F52C; break;
        case 4: goto L_8000F580; break;
        case 5: goto L_8000F594; break;
        case 6: goto L_8000F5B0; break;
        case 7: goto L_8000F5C8; break;
        case 8: goto L_8000F608; break;
        case 9: goto L_8000F648; break;
        case 10: goto L_8000F654; break;
        case 11: goto L_8000F660; break;
        case 12: goto L_8000F674; break;
        case 13: goto L_8000EE00; break;
        case 14: goto L_8000EE00; break;
        case 15: goto L_8000EE00; break;
        case 16: goto L_8000EE00; break;
        case 17: goto L_8000EFE0; break;
        case 18: goto L_8000EF2C; break;
        case 19: goto L_8000EFF4; break;
        case 20: goto L_8000F004; break;
        case 21: goto L_8000EF40; break;
        case 22: goto L_8000F1E0; break;
        case 23: goto L_8000F240; break;
        case 24: goto L_8000F260; break;
        case 25: goto L_8000F260; break;
        case 26: goto L_8000F2BC; break;
        case 27: goto L_8000F2D4; break;
        case 28: goto L_8000F260; break;
        case 29: goto L_8000F2A0; break;
        case 30: goto L_8000F2F4; break;
        case 31: goto L_8000F300; break;
        case 32: goto L_8000F324; break;
        case 33: goto L_8000F344; break;
        case 34: goto L_8000F350; break;
        case 35: goto L_8000F088; break;
        case 36: goto L_8000F1D4; break;
        case 37: goto L_8000EE00; break;
        case 38: goto L_8000EE00; break;
        case 39: goto L_8000F15C; break;
        case 40: goto L_8000F144; break;
        case 41: goto L_8000F138; break;
        case 42: goto L_8000F124; break;
        case 43: goto L_8000F118; break;
        case 44: goto L_8000F100; break;
        case 45: goto L_8000F0E8; break;
        case 46: goto L_8000F05C; break;
        case 47: goto L_8000F014; break;
        case 48: goto L_8000F030; break;
        case 49: goto L_8000F19C; break;
        case 50: goto L_8000F174; break;
        case 51: goto L_8000F1C4; break;
        case 52: goto L_8000F368; break;
        case 53: goto L_8000F35C; break;
        case 54: goto L_8000F3C4; break;
        case 55: goto L_8000F3D0; break;
        case 56: goto L_8000F438; break;
        case 57: goto L_8000F4F0; break;
        case 58: goto L_8000EEEC; break;
        case 59: goto L_8000EF7C; break;
        case 60: goto L_8000F4A8; break;
        case 61: goto L_8000F504; break;
        case 62: goto L_8000F0B8; break;
        case 63: goto L_8000EE00; break;
        case 64: goto L_8000EF1C; break;
        case 65: goto L_8000EEFC; break;
        default: switch_error(__func__, 0x8000EEE4, 0x800ABE00);
    }
    // 0x8000EEE8: nop

L_8000EEEC:
    // 0x8000EEEC: lbu         $t1, 0x0($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X0);
    // 0x8000EEF0: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x8000EEF4: b           L_8000F928
    // 0x8000EEF8: sb          $t2, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r10;
        goto L_8000F928;
    // 0x8000EEF8: sb          $t2, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r10;
L_8000EEFC:
    // 0x8000EEFC: addiu       $s0, $s4, 0x8C
    ctx->r16 = ADD32(ctx->r20, 0X8C);
    // 0x8000EF00: jal         0x8000BE94
    // 0x8000EF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000BE94(rdram, ctx);
        goto after_5;
    // 0x8000EF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8000EF08: lbu         $a1, 0x63($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X63);
    // 0x8000EF0C: jal         0x8000BFF4
    // 0x8000EF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000BFF4(rdram, ctx);
        goto after_6;
    // 0x8000EF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8000EF14: b           L_8000EE00
    // 0x8000EF18: nop

        goto L_8000EE00;
    // 0x8000EF18: nop

L_8000EF1C:
    // 0x8000EF1C: jal         0x8000BE94
    // 0x8000EF20: addiu       $a0, $s4, 0x8C
    ctx->r4 = ADD32(ctx->r20, 0X8C);
    func_8000BE94(rdram, ctx);
        goto after_7;
    // 0x8000EF20: addiu       $a0, $s4, 0x8C
    ctx->r4 = ADD32(ctx->r20, 0X8C);
    after_7:
    // 0x8000EF24: b           L_8000EE00
    // 0x8000EF28: nop

        goto L_8000EE00;
    // 0x8000EF28: nop

L_8000EF2C:
    // 0x8000EF2C: lhu         $s1, 0x62($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X62);
    // 0x8000EF30: lw          $t3, 0x18($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X18);
    // 0x8000EF34: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8000EF38: b           L_8000EE00
    // 0x8000EF3C: sw          $t4, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->r12;
        goto L_8000EE00;
    // 0x8000EF3C: sw          $t4, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->r12;
L_8000EF40:
    // 0x8000EF40: lb          $v0, 0x19($s5)
    ctx->r2 = MEM_B(ctx->r21, 0X19);
    // 0x8000EF44: beq         $s7, $v0, L_8000EE00
    if (ctx->r23 == ctx->r2) {
        // 0x8000EF48: nop
    
            goto L_8000EE00;
    }
    // 0x8000EF48: nop

    // 0x8000EF4C: lw          $t5, 0x3C($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X3C);
    // 0x8000EF50: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8000EF54: lw          $t0, 0x18($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X18);
    // 0x8000EF58: addu        $s0, $t5, $t7
    ctx->r16 = ADD32(ctx->r13, ctx->r15);
    // 0x8000EF5C: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x8000EF60: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x8000EF64: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8000EF68: addu        $s1, $t6, $t9
    ctx->r17 = ADD32(ctx->r14, ctx->r25);
    // 0x8000EF6C: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8000EF70: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x8000EF74: b           L_8000EE00
    // 0x8000EF78: sw          $t1, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->r9;
        goto L_8000EE00;
    // 0x8000EF78: sw          $t1, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->r9;
L_8000EF7C:
    // 0x8000EF7C: lbu         $t3, 0x5($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X5);
    // 0x8000EF80: lbu         $t2, 0x63($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X63);
    // 0x8000EF84: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000EF88: beq         $t3, $at, L_8000EFBC
    if (ctx->r11 == ctx->r1) {
        // 0x8000EF8C: or          $s2, $t2, $zero
        ctx->r18 = ctx->r10 | 0;
            goto L_8000EFBC;
    }
    // 0x8000EF8C: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x8000EF90: lbu         $t4, 0x4($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X4);
    // 0x8000EF94: lw          $v0, 0x1D70($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1D70);
    // 0x8000EF98: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8000EF9C: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x8000EFA0: lhu         $s1, 0x0($t7)
    ctx->r17 = MEM_HU(ctx->r15, 0X0);
    // 0x8000EFA4: addu        $t8, $s1, $v0
    ctx->r24 = ADD32(ctx->r17, ctx->r2);
    // 0x8000EFA8: lbu         $a3, 0x0($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X0);
    // 0x8000EFAC: addu        $t6, $s1, $a3
    ctx->r14 = ADD32(ctx->r17, ctx->r7);
    // 0x8000EFB0: subu        $t9, $t6, $t2
    ctx->r25 = SUB32(ctx->r14, ctx->r10);
    // 0x8000EFB4: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8000EFB8: lbu         $s2, 0x0($t0)
    ctx->r18 = MEM_BU(ctx->r8, 0X0);
L_8000EFBC:
    // 0x8000EFBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000EFC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8000EFC4: jal         0x80004160
    // 0x8000EFC8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80004160(rdram, ctx);
        goto after_8;
    // 0x8000EFC8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x8000EFCC: beql        $v0, $zero, L_8000EFDC
    if (ctx->r2 == 0) {
        // 0x8000EFD0: lw          $t1, 0x64($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X64);
            goto L_8000EFDC;
    }
    goto skip_3;
    // 0x8000EFD0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    skip_3:
    // 0x8000EFD4: sb          $s2, 0x7($s4)
    MEM_B(0X7, ctx->r20) = ctx->r18;
    // 0x8000EFD8: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
L_8000EFDC:
    // 0x8000EFDC: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
L_8000EFE0:
    // 0x8000EFE0: lbu         $a1, 0x63($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X63);
    // 0x8000EFE4: jal         0x8000ECB8
    // 0x8000EFE8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8000ECB8(rdram, ctx);
        goto after_9;
    // 0x8000EFE8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_9:
    // 0x8000EFEC: b           L_8000EE00
    // 0x8000EFF0: nop

        goto L_8000EE00;
    // 0x8000EFF0: nop

L_8000EFF4:
    // 0x8000EFF4: lbu         $t3, 0x0($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X0);
    // 0x8000EFF8: andi        $t4, $t3, 0xFFFD
    ctx->r12 = ctx->r11 & 0XFFFD;
    // 0x8000EFFC: b           L_8000EE00
    // 0x8000F000: sb          $t4, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r12;
        goto L_8000EE00;
    // 0x8000F000: sb          $t4, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r12;
L_8000F004:
    // 0x8000F004: lbu         $t7, 0x0($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X0);
    // 0x8000F008: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x8000F00C: b           L_8000EE00
    // 0x8000F010: sb          $t8, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r24;
        goto L_8000EE00;
    // 0x8000F010: sb          $t8, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r24;
L_8000F014:
    // 0x8000F014: lbu         $a1, 0x63($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F018: jal         0x8000ED48
    // 0x8000F01C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8000ED48(rdram, ctx);
        goto after_10;
    // 0x8000F01C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_10:
    // 0x8000F020: lbu         $t2, 0x1($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X1);
    // 0x8000F024: ori         $t9, $t2, 0x40
    ctx->r25 = ctx->r10 | 0X40;
    // 0x8000F028: b           L_8000EE00
    // 0x8000F02C: sb          $t9, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r25;
        goto L_8000EE00;
    // 0x8000F02C: sb          $t9, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r25;
L_8000F030:
    // 0x8000F030: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F034: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
    // 0x8000F038: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000F03C: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x8000F040: lbu         $t1, 0x1($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X1);
    // 0x8000F044: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000F048: ori         $t3, $t1, 0x40
    ctx->r11 = ctx->r9 | 0X40;
    // 0x8000F04C: sb          $t3, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r11;
    // 0x8000F050: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000F054: b           L_8000EE00
    // 0x8000F058: swc1        $f10, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->f10.u32l;
        goto L_8000EE00;
    // 0x8000F058: swc1        $f10, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->f10.u32l;
L_8000F05C:
    // 0x8000F05C: lhu         $s1, 0x62($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X62);
    // 0x8000F060: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8000F064: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000F068: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x8000F06C: lbu         $t5, 0x1($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X1);
    // 0x8000F070: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000F074: ori         $t7, $t5, 0x80
    ctx->r15 = ctx->r13 | 0X80;
    // 0x8000F078: sb          $t7, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r15;
    // 0x8000F07C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000F080: b           L_8000EE00
    // 0x8000F084: swc1        $f6, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->f6.u32l;
        goto L_8000EE00;
    // 0x8000F084: swc1        $f6, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->f6.u32l;
L_8000F088:
    // 0x8000F088: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F08C: lbu         $t2, 0x1($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X1);
    // 0x8000F090: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000F094: addiu       $s2, $s2, 0x80
    ctx->r18 = ADD32(ctx->r18, 0X80);
    // 0x8000F098: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8000F09C: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x8000F0A0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8000F0A4: lwc1        $f8, 0x61D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61D4);
    // 0x8000F0A8: ori         $t9, $t2, 0x80
    ctx->r25 = ctx->r10 | 0X80;
    // 0x8000F0AC: sb          $t9, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r25;
    // 0x8000F0B0: b           L_8000EE00
    // 0x8000F0B4: swc1        $f8, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->f8.u32l;
        goto L_8000EE00;
    // 0x8000F0B4: swc1        $f8, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->f8.u32l;
L_8000F0B8:
    // 0x8000F0B8: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F0BC: lbu         $t3, 0x1($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X1);
    // 0x8000F0C0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000F0C4: addiu       $s2, $s2, 0x80
    ctx->r18 = ADD32(ctx->r18, 0X80);
    // 0x8000F0C8: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8000F0CC: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x8000F0D0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8000F0D4: lwc1        $f10, 0x65D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65D4);
    // 0x8000F0D8: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x8000F0DC: sb          $t4, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r12;
    // 0x8000F0E0: b           L_8000EE00
    // 0x8000F0E4: swc1        $f10, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->f10.u32l;
        goto L_8000EE00;
    // 0x8000F0E4: swc1        $f10, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->f10.u32l;
L_8000F0E8:
    // 0x8000F0E8: lbu         $t7, 0x1($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X1);
    // 0x8000F0EC: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F0F0: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x8000F0F4: sb          $t8, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r24;
    // 0x8000F0F8: b           L_8000EE00
    // 0x8000F0FC: sb          $s2, 0xA($s4)
    MEM_B(0XA, ctx->r20) = ctx->r18;
        goto L_8000EE00;
    // 0x8000F0FC: sb          $s2, 0xA($s4)
    MEM_B(0XA, ctx->r20) = ctx->r18;
L_8000F100:
    // 0x8000F100: lbu         $t2, 0x1($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X1);
    // 0x8000F104: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F108: ori         $t9, $t2, 0x20
    ctx->r25 = ctx->r10 | 0X20;
    // 0x8000F10C: sb          $t9, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r25;
    // 0x8000F110: b           L_8000EE00
    // 0x8000F114: sb          $s2, 0xB($s4)
    MEM_B(0XB, ctx->r20) = ctx->r18;
        goto L_8000EE00;
    // 0x8000F114: sb          $s2, 0xB($s4)
    MEM_B(0XB, ctx->r20) = ctx->r18;
L_8000F118:
    // 0x8000F118: lb          $v0, 0x63($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X63);
    // 0x8000F11C: b           L_8000EE00
    // 0x8000F120: sh          $v0, 0x26($s4)
    MEM_H(0X26, ctx->r20) = ctx->r2;
        goto L_8000EE00;
    // 0x8000F120: sh          $v0, 0x26($s4)
    MEM_H(0X26, ctx->r20) = ctx->r2;
L_8000F124:
    // 0x8000F124: lhu         $s1, 0x62($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X62);
    // 0x8000F128: lw          $t0, 0x18($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X18);
    // 0x8000F12C: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x8000F130: b           L_8000EE00
    // 0x8000F134: sw          $t1, 0x88($s4)
    MEM_W(0X88, ctx->r20) = ctx->r9;
        goto L_8000EE00;
    // 0x8000F134: sw          $t1, 0x88($s4)
    MEM_W(0X88, ctx->r20) = ctx->r9;
L_8000F138:
    // 0x8000F138: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F13C: b           L_8000EE00
    // 0x8000F140: sb          $s2, 0x84($s4)
    MEM_B(0X84, ctx->r20) = ctx->r18;
        goto L_8000EE00;
    // 0x8000F140: sb          $s2, 0x84($s4)
    MEM_B(0X84, ctx->r20) = ctx->r18;
L_8000F144:
    // 0x8000F144: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F148: sh          $zero, 0x12($s4)
    MEM_H(0X12, ctx->r20) = 0;
    // 0x8000F14C: sh          $zero, 0x1A($s4)
    MEM_H(0X1A, ctx->r20) = 0;
    // 0x8000F150: sll         $t3, $s2, 3
    ctx->r11 = S32(ctx->r18 << 3);
    // 0x8000F154: b           L_8000EE00
    // 0x8000F158: sh          $t3, 0x16($s4)
    MEM_H(0X16, ctx->r20) = ctx->r11;
        goto L_8000EE00;
    // 0x8000F158: sh          $t3, 0x16($s4)
    MEM_H(0X16, ctx->r20) = ctx->r11;
L_8000F15C:
    // 0x8000F15C: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F160: sh          $zero, 0x18($s4)
    MEM_H(0X18, ctx->r20) = 0;
    // 0x8000F164: sll         $v0, $s2, 5
    ctx->r2 = S32(ctx->r18 << 5);
    // 0x8000F168: sh          $v0, 0x14($s4)
    MEM_H(0X14, ctx->r20) = ctx->r2;
    // 0x8000F16C: b           L_8000EE00
    // 0x8000F170: sh          $v0, 0x10($s4)
    MEM_H(0X10, ctx->r20) = ctx->r2;
        goto L_8000EE00;
    // 0x8000F170: sh          $v0, 0x10($s4)
    MEM_H(0X10, ctx->r20) = ctx->r2;
L_8000F174:
    // 0x8000F174: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F178: sll         $t4, $s2, 3
    ctx->r12 = S32(ctx->r18 << 3);
    // 0x8000F17C: sh          $t4, 0x12($s4)
    MEM_H(0X12, ctx->r20) = ctx->r12;
    // 0x8000F180: lbu         $s2, 0x67($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X67);
    // 0x8000F184: sll         $t5, $s2, 3
    ctx->r13 = S32(ctx->r18 << 3);
    // 0x8000F188: sh          $t5, 0x16($s4)
    MEM_H(0X16, ctx->r20) = ctx->r13;
    // 0x8000F18C: lbu         $s2, 0x6B($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X6B);
    // 0x8000F190: sll         $t7, $s2, 4
    ctx->r15 = S32(ctx->r18 << 4);
    // 0x8000F194: b           L_8000EE00
    // 0x8000F198: sh          $t7, 0x1A($s4)
    MEM_H(0X1A, ctx->r20) = ctx->r15;
        goto L_8000EE00;
    // 0x8000F198: sh          $t7, 0x1A($s4)
    MEM_H(0X1A, ctx->r20) = ctx->r15;
L_8000F19C:
    // 0x8000F19C: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F1A0: sll         $t8, $s2, 5
    ctx->r24 = S32(ctx->r18 << 5);
    // 0x8000F1A4: sh          $t8, 0x10($s4)
    MEM_H(0X10, ctx->r20) = ctx->r24;
    // 0x8000F1A8: lbu         $s2, 0x67($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X67);
    // 0x8000F1AC: sll         $t6, $s2, 5
    ctx->r14 = S32(ctx->r18 << 5);
    // 0x8000F1B0: sh          $t6, 0x14($s4)
    MEM_H(0X14, ctx->r20) = ctx->r14;
    // 0x8000F1B4: lbu         $s2, 0x6B($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X6B);
    // 0x8000F1B8: sll         $t2, $s2, 4
    ctx->r10 = S32(ctx->r18 << 4);
    // 0x8000F1BC: b           L_8000EE00
    // 0x8000F1C0: sh          $t2, 0x18($s4)
    MEM_H(0X18, ctx->r20) = ctx->r10;
        goto L_8000EE00;
    // 0x8000F1C0: sh          $t2, 0x18($s4)
    MEM_H(0X18, ctx->r20) = ctx->r10;
L_8000F1C4:
    // 0x8000F1C4: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F1C8: sll         $t9, $s2, 4
    ctx->r25 = S32(ctx->r18 << 4);
    // 0x8000F1CC: b           L_8000EE00
    // 0x8000F1D0: sh          $t9, 0x1C($s4)
    MEM_H(0X1C, ctx->r20) = ctx->r25;
        goto L_8000EE00;
    // 0x8000F1D0: sh          $t9, 0x1C($s4)
    MEM_H(0X1C, ctx->r20) = ctx->r25;
L_8000F1D4:
    // 0x8000F1D4: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F1D8: b           L_8000EE00
    // 0x8000F1DC: sb          $s2, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r18;
        goto L_8000EE00;
    // 0x8000F1DC: sb          $s2, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r18;
L_8000F1E0:
    // 0x8000F1E0: lbu         $t1, 0x5($s6)
    ctx->r9 = MEM_BU(ctx->r22, 0X5);
    // 0x8000F1E4: lbu         $t0, 0x63($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F1E8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000F1EC: beq         $t1, $at, L_8000F220
    if (ctx->r9 == ctx->r1) {
        // 0x8000F1F0: or          $s2, $t0, $zero
        ctx->r18 = ctx->r8 | 0;
            goto L_8000F220;
    }
    // 0x8000F1F0: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
    // 0x8000F1F4: lbu         $t3, 0x4($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X4);
    // 0x8000F1F8: lw          $v0, 0x1D70($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X1D70);
    // 0x8000F1FC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8000F200: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8000F204: lhu         $s1, 0x0($t5)
    ctx->r17 = MEM_HU(ctx->r13, 0X0);
    // 0x8000F208: addu        $t7, $s1, $v0
    ctx->r15 = ADD32(ctx->r17, ctx->r2);
    // 0x8000F20C: lbu         $a3, 0x0($t7)
    ctx->r7 = MEM_BU(ctx->r15, 0X0);
    // 0x8000F210: addu        $t8, $s1, $a3
    ctx->r24 = ADD32(ctx->r17, ctx->r7);
    // 0x8000F214: subu        $t6, $t8, $t0
    ctx->r14 = SUB32(ctx->r24, ctx->r8);
    // 0x8000F218: addu        $t2, $t6, $v0
    ctx->r10 = ADD32(ctx->r14, ctx->r2);
    // 0x8000F21C: lbu         $s2, 0x0($t2)
    ctx->r18 = MEM_BU(ctx->r10, 0X0);
L_8000F220:
    // 0x8000F220: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000F224: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8000F228: jal         0x80004160
    // 0x8000F22C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80004160(rdram, ctx);
        goto after_11;
    // 0x8000F22C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_11:
    // 0x8000F230: beq         $v0, $zero, L_8000EE00
    if (ctx->r2 == 0) {
        // 0x8000F234: nop
    
            goto L_8000EE00;
    }
    // 0x8000F234: nop

    // 0x8000F238: b           L_8000EE00
    // 0x8000F23C: sb          $s2, 0x7($s4)
    MEM_B(0X7, ctx->r20) = ctx->r18;
        goto L_8000EE00;
    // 0x8000F23C: sb          $s2, 0x7($s4)
    MEM_B(0X7, ctx->r20) = ctx->r18;
L_8000F240:
    // 0x8000F240: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F244: lhu         $s1, 0x66($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X66);
    // 0x8000F248: lw          $t9, 0x18($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X18);
    // 0x8000F24C: lbu         $t1, 0x19($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X19);
    // 0x8000F250: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x8000F254: addu        $t3, $t1, $s2
    ctx->r11 = ADD32(ctx->r9, ctx->r18);
    // 0x8000F258: b           L_8000EE00
    // 0x8000F25C: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
        goto L_8000EE00;
    // 0x8000F25C: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_8000F260:
    // 0x8000F260: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8000F264: bne         $s0, $at, L_8000F27C
    if (ctx->r16 != ctx->r1) {
        // 0x8000F268: lb          $v0, 0x63($sp)
        ctx->r2 = MEM_B(ctx->r29, 0X63);
            goto L_8000F27C;
    }
    // 0x8000F268: lb          $v0, 0x63($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X63);
    // 0x8000F26C: lb          $t4, 0x19($s5)
    ctx->r12 = MEM_B(ctx->r21, 0X19);
    // 0x8000F270: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x8000F274: b           L_8000EE00
    // 0x8000F278: sb          $t5, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r13;
        goto L_8000EE00;
    // 0x8000F278: sb          $t5, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r13;
L_8000F27C:
    // 0x8000F27C: addiu       $at, $zero, 0xCC
    ctx->r1 = ADD32(0, 0XCC);
    // 0x8000F280: bnel        $s0, $at, L_8000F294
    if (ctx->r16 != ctx->r1) {
        // 0x8000F284: lb          $t7, 0x19($s5)
        ctx->r15 = MEM_B(ctx->r21, 0X19);
            goto L_8000F294;
    }
    goto skip_4;
    // 0x8000F284: lb          $t7, 0x19($s5)
    ctx->r15 = MEM_B(ctx->r21, 0X19);
    skip_4:
    // 0x8000F288: b           L_8000EE00
    // 0x8000F28C: sb          $v0, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r2;
        goto L_8000EE00;
    // 0x8000F28C: sb          $v0, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r2;
    // 0x8000F290: lb          $t7, 0x19($s5)
    ctx->r15 = MEM_B(ctx->r21, 0X19);
L_8000F294:
    // 0x8000F294: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x8000F298: b           L_8000EE00
    // 0x8000F29C: sb          $t8, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r24;
        goto L_8000EE00;
    // 0x8000F29C: sb          $t8, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r24;
L_8000F2A0:
    // 0x8000F2A0: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F2A4: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x8000F2A8: addu        $t6, $s6, $t0
    ctx->r14 = ADD32(ctx->r22, ctx->r8);
    // 0x8000F2AC: jal         0x8000D86C
    // 0x8000F2B0: lw          $a0, 0x34($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X34);
    func_8000D86C(rdram, ctx);
        goto after_12;
    // 0x8000F2B0: lw          $a0, 0x34($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X34);
    after_12:
    // 0x8000F2B4: b           L_8000EE00
    // 0x8000F2B8: nop

        goto L_8000EE00;
    // 0x8000F2B8: nop

L_8000F2BC:
    // 0x8000F2BC: lbu         $t9, 0x1($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X1);
    // 0x8000F2C0: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F2C4: ori         $t1, $t9, 0x40
    ctx->r9 = ctx->r25 | 0X40;
    // 0x8000F2C8: sb          $t1, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r9;
    // 0x8000F2CC: b           L_8000EE00
    // 0x8000F2D0: sb          $s2, 0x3($s4)
    MEM_B(0X3, ctx->r20) = ctx->r18;
        goto L_8000EE00;
    // 0x8000F2D0: sb          $s2, 0x3($s4)
    MEM_B(0X3, ctx->r20) = ctx->r18;
L_8000F2D4:
    // 0x8000F2D4: lhu         $s1, 0x62($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X62);
    // 0x8000F2D8: lb          $t4, 0x19($s5)
    ctx->r12 = MEM_B(ctx->r21, 0X19);
    // 0x8000F2DC: lw          $t3, 0x18($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X18);
    // 0x8000F2E0: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x8000F2E4: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8000F2E8: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8000F2EC: b           L_8000EE00
    // 0x8000F2F0: sb          $t8, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r24;
        goto L_8000EE00;
    // 0x8000F2F0: sb          $t8, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r24;
L_8000F2F4:
    // 0x8000F2F4: lhu         $s1, 0x62($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X62);
    // 0x8000F2F8: b           L_8000EE00
    // 0x8000F2FC: sh          $s1, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r17;
        goto L_8000EE00;
    // 0x8000F2FC: sh          $s1, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r17;
L_8000F300:
    // 0x8000F300: lhu         $s1, 0x62($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X62);
    // 0x8000F304: lw          $t0, 0x18($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X18);
    // 0x8000F308: lhu         $t6, 0x22($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X22);
    // 0x8000F30C: addu        $v0, $t0, $s1
    ctx->r2 = ADD32(ctx->r8, ctx->r17);
    // 0x8000F310: sra         $t9, $t6, 8
    ctx->r25 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8000F314: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8000F318: lhu         $t4, 0x22($s4)
    ctx->r12 = MEM_HU(ctx->r20, 0X22);
    // 0x8000F31C: b           L_8000EE00
    // 0x8000F320: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
        goto L_8000EE00;
    // 0x8000F320: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
L_8000F324:
    // 0x8000F324: lbu         $t3, 0x63($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F328: lbu         $t8, 0x0($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X0);
    // 0x8000F32C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8000F330: andi        $t7, $t5, 0x4
    ctx->r15 = ctx->r13 & 0X4;
    // 0x8000F334: andi        $t0, $t8, 0xFFFB
    ctx->r8 = ctx->r24 & 0XFFFB;
    // 0x8000F338: or          $t6, $t7, $t0
    ctx->r14 = ctx->r15 | ctx->r8;
    // 0x8000F33C: b           L_8000EE00
    // 0x8000F340: sb          $t6, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r14;
        goto L_8000EE00;
    // 0x8000F340: sb          $t6, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r14;
L_8000F344:
    // 0x8000F344: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F348: b           L_8000EE00
    // 0x8000F34C: sb          $s2, 0x2($s4)
    MEM_B(0X2, ctx->r20) = ctx->r18;
        goto L_8000EE00;
    // 0x8000F34C: sb          $s2, 0x2($s4)
    MEM_B(0X2, ctx->r20) = ctx->r18;
L_8000F350:
    // 0x8000F350: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F354: b           L_8000EE00
    // 0x8000F358: sb          $s2, 0x85($s4)
    MEM_B(0X85, ctx->r20) = ctx->r18;
        goto L_8000EE00;
    // 0x8000F358: sb          $s2, 0x85($s4)
    MEM_B(0X85, ctx->r20) = ctx->r18;
L_8000F35C:
    // 0x8000F35C: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F360: b           L_8000EE00
    // 0x8000F364: sb          $s2, 0x8($s4)
    MEM_B(0X8, ctx->r20) = ctx->r18;
        goto L_8000EE00;
    // 0x8000F364: sb          $s2, 0x8($s4)
    MEM_B(0X8, ctx->r20) = ctx->r18;
L_8000F368:
    // 0x8000F368: lb          $v0, 0x19($s5)
    ctx->r2 = MEM_B(ctx->r21, 0X19);
    // 0x8000F36C: beq         $s7, $v0, L_8000EE00
    if (ctx->r23 == ctx->r2) {
        // 0x8000F370: nop
    
            goto L_8000EE00;
    }
    // 0x8000F370: nop

    // 0x8000F374: lbu         $v1, 0x18($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X18);
    // 0x8000F378: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x8000F37C: lw          $t2, 0x3C($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X3C);
    // 0x8000F380: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x8000F384: addu        $t3, $s5, $t4
    ctx->r11 = ADD32(ctx->r21, ctx->r12);
    // 0x8000F388: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x8000F38C: lbu         $t5, 0x18($s5)
    ctx->r13 = MEM_BU(ctx->r21, 0X18);
    // 0x8000F390: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8000F394: addu        $s0, $t2, $t9
    ctx->r16 = ADD32(ctx->r10, ctx->r25);
    // 0x8000F398: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x8000F39C: sb          $t8, 0x18($s5)
    MEM_B(0X18, ctx->r21) = ctx->r24;
    // 0x8000F3A0: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    // 0x8000F3A4: lbu         $t7, 0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1);
    // 0x8000F3A8: lw          $t2, 0x18($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X18);
    // 0x8000F3AC: sll         $t6, $t0, 8
    ctx->r14 = S32(ctx->r8 << 8);
    // 0x8000F3B0: addu        $s1, $t7, $t6
    ctx->r17 = ADD32(ctx->r15, ctx->r14);
    // 0x8000F3B4: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8000F3B8: addu        $t9, $t2, $s1
    ctx->r25 = ADD32(ctx->r10, ctx->r17);
    // 0x8000F3BC: b           L_8000EE00
    // 0x8000F3C0: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
        goto L_8000EE00;
    // 0x8000F3C0: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
L_8000F3C4:
    // 0x8000F3C4: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F3C8: b           L_8000EE00
    // 0x8000F3CC: sb          $s2, 0x9($s4)
    MEM_B(0X9, ctx->r20) = ctx->r18;
        goto L_8000EE00;
    // 0x8000F3CC: sb          $s2, 0x9($s4)
    MEM_B(0X9, ctx->r20) = ctx->r18;
L_8000F3D0:
    // 0x8000F3D0: lhu         $s1, 0x62($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X62);
    // 0x8000F3D4: lw          $t4, 0x18($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X18);
    // 0x8000F3D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000F3DC: addu        $s0, $t4, $s1
    ctx->r16 = ADD32(ctx->r12, ctx->r17);
    // 0x8000F3E0: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x8000F3E4: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // 0x8000F3E8: sb          $t1, 0x3($s4)
    MEM_B(0X3, ctx->r20) = ctx->r9;
    // 0x8000F3EC: lbu         $t3, -0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, -0X2);
    // 0x8000F3F0: sb          $t3, 0x2($s4)
    MEM_B(0X2, ctx->r20) = ctx->r11;
    // 0x8000F3F4: jal         0x8000EC18
    // 0x8000F3F8: lbu         $a1, -0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, -0X1);
    func_8000EC18(rdram, ctx);
        goto after_13;
    // 0x8000F3F8: lbu         $a1, -0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, -0X1);
    after_13:
    // 0x8000F3FC: lb          $t5, 0x0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X0);
    // 0x8000F400: lbu         $t9, 0x1($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X1);
    // 0x8000F404: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F408: sh          $t5, 0x26($s4)
    MEM_H(0X26, ctx->r20) = ctx->r13;
    // 0x8000F40C: lbu         $t8, -0x3($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X3);
    // 0x8000F410: ori         $t4, $t9, 0x20
    ctx->r12 = ctx->r25 | 0X20;
    // 0x8000F414: sb          $t8, 0xA($s4)
    MEM_B(0XA, ctx->r20) = ctx->r24;
    // 0x8000F418: lbu         $t0, -0x2($s0)
    ctx->r8 = MEM_BU(ctx->r16, -0X2);
    // 0x8000F41C: sb          $t0, 0xB($s4)
    MEM_B(0XB, ctx->r20) = ctx->r8;
    // 0x8000F420: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x8000F424: sb          $t7, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r15;
    // 0x8000F428: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8000F42C: sb          $t4, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r12;
    // 0x8000F430: b           L_8000EE00
    // 0x8000F434: sb          $t6, 0x8($s4)
    MEM_B(0X8, ctx->r20) = ctx->r14;
        goto L_8000EE00;
    // 0x8000F434: sb          $t6, 0x8($s4)
    MEM_B(0X8, ctx->r20) = ctx->r14;
L_8000F438:
    // 0x8000F438: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8000F43C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000F440: sb          $t1, 0x3($s4)
    MEM_B(0X3, ctx->r20) = ctx->r9;
    // 0x8000F444: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8000F448: sb          $t3, 0x2($s4)
    MEM_B(0X2, ctx->r20) = ctx->r11;
    // 0x8000F44C: jal         0x8000EC18
    // 0x8000F450: lbu         $a1, 0x6B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6B);
    func_8000EC18(rdram, ctx);
        goto after_14;
    // 0x8000F450: lbu         $a1, 0x6B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6B);
    after_14:
    // 0x8000F454: jal         0x8000DCB4
    // 0x8000F458: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_15;
    // 0x8000F458: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_15:
    // 0x8000F45C: sll         $t5, $v0, 24
    ctx->r13 = S32(ctx->r2 << 24);
    // 0x8000F460: sra         $t8, $t5, 24
    ctx->r24 = S32(SIGNED(ctx->r13) >> 24);
    // 0x8000F464: sh          $t8, 0x26($s4)
    MEM_H(0X26, ctx->r20) = ctx->r24;
    // 0x8000F468: jal         0x8000DCB4
    // 0x8000F46C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_16;
    // 0x8000F46C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_16:
    // 0x8000F470: sb          $v0, 0xA($s4)
    MEM_B(0XA, ctx->r20) = ctx->r2;
    // 0x8000F474: jal         0x8000DCB4
    // 0x8000F478: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_17;
    // 0x8000F478: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_17:
    // 0x8000F47C: sb          $v0, 0xB($s4)
    MEM_B(0XB, ctx->r20) = ctx->r2;
    // 0x8000F480: jal         0x8000DCB4
    // 0x8000F484: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_18;
    // 0x8000F484: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_18:
    // 0x8000F488: sb          $v0, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r2;
    // 0x8000F48C: jal         0x8000DCB4
    // 0x8000F490: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_19;
    // 0x8000F490: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_19:
    // 0x8000F494: lbu         $t7, 0x1($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X1);
    // 0x8000F498: sb          $v0, 0x8($s4)
    MEM_B(0X8, ctx->r20) = ctx->r2;
    // 0x8000F49C: ori         $t6, $t7, 0x20
    ctx->r14 = ctx->r15 | 0X20;
    // 0x8000F4A0: b           L_8000EE00
    // 0x8000F4A4: sb          $t6, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r14;
        goto L_8000EE00;
    // 0x8000F4A4: sb          $t6, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r14;
L_8000F4A8:
    // 0x8000F4A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F4AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000F4B0: sh          $zero, 0x16($s4)
    MEM_H(0X16, ctx->r20) = 0;
    // 0x8000F4B4: sh          $zero, 0x12($s4)
    MEM_H(0X12, ctx->r20) = 0;
    // 0x8000F4B8: sh          $zero, 0x1A($s4)
    MEM_H(0X1A, ctx->r20) = 0;
    // 0x8000F4BC: sh          $zero, 0x14($s4)
    MEM_H(0X14, ctx->r20) = 0;
    // 0x8000F4C0: sh          $zero, 0x10($s4)
    MEM_H(0X10, ctx->r20) = 0;
    // 0x8000F4C4: sh          $zero, 0x18($s4)
    MEM_H(0X18, ctx->r20) = 0;
    // 0x8000F4C8: sw          $zero, 0xD4($s4)
    MEM_W(0XD4, ctx->r20) = 0;
    // 0x8000F4CC: sb          $zero, 0xC($s4)
    MEM_B(0XC, ctx->r20) = 0;
    // 0x8000F4D0: sb          $zero, 0x85($s4)
    MEM_B(0X85, ctx->r20) = 0;
    // 0x8000F4D4: sb          $zero, 0xD($s4)
    MEM_B(0XD, ctx->r20) = 0;
    // 0x8000F4D8: sb          $zero, 0xE($s4)
    MEM_B(0XE, ctx->r20) = 0;
    // 0x8000F4DC: sb          $zero, 0xF($s4)
    MEM_B(0XF, ctx->r20) = 0;
    // 0x8000F4E0: sh          $zero, 0x20($s4)
    MEM_H(0X20, ctx->r20) = 0;
    // 0x8000F4E4: sb          $zero, 0x9($s4)
    MEM_B(0X9, ctx->r20) = 0;
    // 0x8000F4E8: b           L_8000EE00
    // 0x8000F4EC: swc1        $f16, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->f16.u32l;
        goto L_8000EE00;
    // 0x8000F4EC: swc1        $f16, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->f16.u32l;
L_8000F4F0:
    // 0x8000F4F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000F4F4: jal         0x8000EC18
    // 0x8000F4F8: lbu         $a1, 0x63($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X63);
    func_8000EC18(rdram, ctx);
        goto after_20;
    // 0x8000F4F8: lbu         $a1, 0x63($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X63);
    after_20:
    // 0x8000F4FC: b           L_8000EE00
    // 0x8000F500: nop

        goto L_8000EE00;
    // 0x8000F500: nop

L_8000F504:
    // 0x8000F504: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F508: b           L_8000EE00
    // 0x8000F50C: sb          $s2, 0xC($s4)
    MEM_B(0XC, ctx->r20) = ctx->r18;
        goto L_8000EE00;
    // 0x8000F50C: sb          $s2, 0xC($s4)
    MEM_B(0XC, ctx->r20) = ctx->r18;
L_8000F510:
    // 0x8000F510: lhu         $s1, 0x62($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X62);
    // 0x8000F514: lw          $t2, 0x18($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X18);
    // 0x8000F518: addu        $s0, $t2, $s1
    ctx->r16 = ADD32(ctx->r10, ctx->r17);
    // 0x8000F51C: b           L_8000EE00
    // 0x8000F520: sw          $s0, 0xD4($s4)
    MEM_W(0XD4, ctx->r20) = ctx->r16;
        goto L_8000EE00;
    // 0x8000F520: sw          $s0, 0xD4($s4)
    MEM_W(0XD4, ctx->r20) = ctx->r16;
L_8000F524:
    // 0x8000F524: b           L_8000EE00
    // 0x8000F528: sw          $zero, 0xD4($s4)
    MEM_W(0XD4, ctx->r20) = 0;
        goto L_8000EE00;
    // 0x8000F528: sw          $zero, 0xD4($s4)
    MEM_W(0XD4, ctx->r20) = 0;
L_8000F52C:
    // 0x8000F52C: lw          $a0, 0xD4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XD4);
    // 0x8000F530: lbu         $s2, 0x63($sp)
    ctx->r18 = MEM_BU(ctx->r29, 0X63);
    // 0x8000F534: beq         $a0, $zero, L_8000EE00
    if (ctx->r4 == 0) {
        // 0x8000F538: sra         $a3, $s2, 4
        ctx->r7 = S32(SIGNED(ctx->r18) >> 4);
            goto L_8000EE00;
    }
    // 0x8000F538: sra         $a3, $s2, 4
    ctx->r7 = S32(SIGNED(ctx->r18) >> 4);
    // 0x8000F53C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8000F540: andi        $a3, $a3, 0xF
    ctx->r7 = ctx->r7 & 0XF;
    // 0x8000F544: andi        $s2, $s2, 0xF
    ctx->r18 = ctx->r18 & 0XF;
    // 0x8000F548: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x8000F54C: jal         0x80004774
    // 0x8000F550: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    func_80004774(rdram, ctx);
        goto after_21;
    // 0x8000F550: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    after_21:
    // 0x8000F554: b           L_8000EE00
    // 0x8000F558: nop

        goto L_8000EE00;
    // 0x8000F558: nop

L_8000F55C:
    // 0x8000F55C: lb          $t4, 0x19($s5)
    ctx->r12 = MEM_B(ctx->r21, 0X19);
    // 0x8000F560: lhu         $s1, 0x62($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X62);
    // 0x8000F564: lw          $t9, 0x18($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X18);
    // 0x8000F568: sll         $t1, $t4, 1
    ctx->r9 = S32(ctx->r12 << 1);
    // 0x8000F56C: addu        $t3, $s1, $t1
    ctx->r11 = ADD32(ctx->r17, ctx->r9);
    // 0x8000F570: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x8000F574: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x8000F578: b           L_8000EE00
    // 0x8000F57C: sh          $t8, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r24;
        goto L_8000EE00;
    // 0x8000F57C: sh          $t8, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r24;
L_8000F580:
    // 0x8000F580: lw          $t0, 0x18($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X18);
    // 0x8000F584: lhu         $t7, 0x22($s4)
    ctx->r15 = MEM_HU(ctx->r20, 0X22);
    // 0x8000F588: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x8000F58C: b           L_8000EE00
    // 0x8000F590: sw          $t6, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->r14;
        goto L_8000EE00;
    // 0x8000F590: sw          $t6, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->r14;
L_8000F594:
    // 0x8000F594: lb          $t4, 0x19($s5)
    ctx->r12 = MEM_B(ctx->r21, 0X19);
    // 0x8000F598: lw          $t2, 0x3C($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X3C);
    // 0x8000F59C: sll         $t1, $t4, 1
    ctx->r9 = S32(ctx->r12 << 1);
    // 0x8000F5A0: addu        $t9, $t2, $t1
    ctx->r25 = ADD32(ctx->r10, ctx->r9);
    // 0x8000F5A4: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
    // 0x8000F5A8: b           L_8000EE00
    // 0x8000F5AC: sh          $t3, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r11;
        goto L_8000EE00;
    // 0x8000F5AC: sh          $t3, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r11;
L_8000F5B0:
    // 0x8000F5B0: lw          $t5, 0x3C($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X3C);
    // 0x8000F5B4: lb          $t8, 0x19($s5)
    ctx->r24 = MEM_B(ctx->r21, 0X19);
    // 0x8000F5B8: addu        $t0, $t5, $t8
    ctx->r8 = ADD32(ctx->r13, ctx->r24);
    // 0x8000F5BC: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x8000F5C0: b           L_8000EE00
    // 0x8000F5C4: sb          $t7, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r15;
        goto L_8000EE00;
    // 0x8000F5C4: sb          $t7, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r15;
L_8000F5C8:
    // 0x8000F5C8: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8000F5CC: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8000F5D0: bnel        $t6, $zero, L_8000F5E8
    if (ctx->r14 != 0) {
        // 0x8000F5D4: lw          $t1, 0x1E94($fp)
        ctx->r9 = MEM_W(ctx->r30, 0X1E94);
            goto L_8000F5E8;
    }
    goto skip_5;
    // 0x8000F5D4: lw          $t1, 0x1E94($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X1E94);
    skip_5:
    // 0x8000F5D8: lw          $t2, 0x1E94($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X1E94);
    // 0x8000F5DC: b           L_8000EE00
    // 0x8000F5E0: sh          $t2, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r10;
        goto L_8000EE00;
    // 0x8000F5E0: sh          $t2, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r10;
    // 0x8000F5E4: lw          $t1, 0x1E94($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X1E94);
L_8000F5E8:
    // 0x8000F5E8: divu        $zero, $t1, $t9
    lo = S32(U32(ctx->r9) / U32(ctx->r25)); hi = S32(U32(ctx->r9) % U32(ctx->r25));
    // 0x8000F5EC: mfhi        $t3
    ctx->r11 = hi;
    // 0x8000F5F0: sh          $t3, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r11;
    // 0x8000F5F4: bne         $t9, $zero, L_8000F600
    if (ctx->r25 != 0) {
        // 0x8000F5F8: nop
    
            goto L_8000F600;
    }
    // 0x8000F5F8: nop

    // 0x8000F5FC: break       7
    do_break(2147546620);
L_8000F600:
    // 0x8000F600: b           L_8000EE00
    // 0x8000F604: nop

        goto L_8000EE00;
    // 0x8000F604: nop

L_8000F608:
    // 0x8000F608: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8000F60C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8000F610: bnel        $t5, $zero, L_8000F628
    if (ctx->r13 != 0) {
        // 0x8000F614: lw          $t7, 0x1E94($fp)
        ctx->r15 = MEM_W(ctx->r30, 0X1E94);
            goto L_8000F628;
    }
    goto skip_6;
    // 0x8000F614: lw          $t7, 0x1E94($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X1E94);
    skip_6:
    // 0x8000F618: lw          $t0, 0x1E94($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X1E94);
    // 0x8000F61C: b           L_8000EE00
    // 0x8000F620: sb          $t0, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r8;
        goto L_8000EE00;
    // 0x8000F620: sb          $t0, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r8;
    // 0x8000F624: lw          $t7, 0x1E94($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X1E94);
L_8000F628:
    // 0x8000F628: divu        $zero, $t7, $t6
    lo = S32(U32(ctx->r15) / U32(ctx->r14)); hi = S32(U32(ctx->r15) % U32(ctx->r14));
    // 0x8000F62C: mfhi        $t4
    ctx->r12 = hi;
    // 0x8000F630: sb          $t4, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r12;
    // 0x8000F634: bne         $t6, $zero, L_8000F640
    if (ctx->r14 != 0) {
        // 0x8000F638: nop
    
            goto L_8000F640;
    }
    // 0x8000F638: nop

    // 0x8000F63C: break       7
    do_break(2147546684);
L_8000F640:
    // 0x8000F640: b           L_8000EE00
    // 0x8000F644: nop

        goto L_8000EE00;
    // 0x8000F644: nop

L_8000F648:
    // 0x8000F648: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8000F64C: b           L_8000EE00
    // 0x8000F650: sb          $t2, 0xD($s4)
    MEM_B(0XD, ctx->r20) = ctx->r10;
        goto L_8000EE00;
    // 0x8000F650: sb          $t2, 0xD($s4)
    MEM_B(0XD, ctx->r20) = ctx->r10;
L_8000F654:
    // 0x8000F654: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8000F658: b           L_8000EE00
    // 0x8000F65C: sb          $t1, 0xE($s4)
    MEM_B(0XE, ctx->r20) = ctx->r9;
        goto L_8000EE00;
    // 0x8000F65C: sb          $t1, 0xE($s4)
    MEM_B(0XE, ctx->r20) = ctx->r9;
L_8000F660:
    // 0x8000F660: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8000F664: sb          $t9, 0xF($s4)
    MEM_B(0XF, ctx->r20) = ctx->r25;
    // 0x8000F668: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8000F66C: b           L_8000EE00
    // 0x8000F670: sh          $t3, 0x20($s4)
    MEM_H(0X20, ctx->r20) = ctx->r11;
        goto L_8000EE00;
    // 0x8000F670: sh          $t3, 0x20($s4)
    MEM_H(0X20, ctx->r20) = ctx->r11;
L_8000F674:
    // 0x8000F674: lhu         $t5, 0x22($s4)
    ctx->r13 = MEM_HU(ctx->r20, 0X22);
    // 0x8000F678: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8000F67C: addu        $t0, $t5, $t8
    ctx->r8 = ADD32(ctx->r13, ctx->r24);
    // 0x8000F680: b           L_8000EE00
    // 0x8000F684: sh          $t0, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r8;
        goto L_8000EE00;
    // 0x8000F684: sh          $t0, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r8;
L_8000F688:
    // 0x8000F688: slti        $at, $a0, 0x70
    ctx->r1 = SIGNED(ctx->r4) < 0X70 ? 1 : 0;
    // 0x8000F68C: bnel        $at, $zero, L_8000F808
    if (ctx->r1 != 0) {
        // 0x8000F690: andi        $t3, $a0, 0xF0
        ctx->r11 = ctx->r4 & 0XF0;
            goto L_8000F808;
    }
    goto skip_7;
    // 0x8000F690: andi        $t3, $a0, 0xF0
    ctx->r11 = ctx->r4 & 0XF0;
    skip_7:
    // 0x8000F694: andi        $t7, $a0, 0xF8
    ctx->r15 = ctx->r4 & 0XF8;
    // 0x8000F698: addiu       $t6, $t7, -0x70
    ctx->r14 = ADD32(ctx->r15, -0X70);
    // 0x8000F69C: sltiu       $at, $t6, 0x29
    ctx->r1 = ctx->r14 < 0X29 ? 1 : 0;
    // 0x8000F6A0: beq         $at, $zero, L_8000EE00
    if (ctx->r1 == 0) {
        // 0x8000F6A4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8000EE00;
    }
    // 0x8000F6A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000F6A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000F6AC: addu        $at, $at, $t6
    gpr jr_addend_8000F6B4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000F6B0: lw          $t6, -0x40F8($at)
    ctx->r14 = ADD32(ctx->r1, -0X40F8);
    // 0x8000F6B4: jr          $t6
    // 0x8000F6B8: nop

    switch (jr_addend_8000F6B4 >> 2) {
        case 0: goto L_8000F7AC; break;
        case 1: goto L_8000EE00; break;
        case 2: goto L_8000EE00; break;
        case 3: goto L_8000EE00; break;
        case 4: goto L_8000EE00; break;
        case 5: goto L_8000EE00; break;
        case 6: goto L_8000EE00; break;
        case 7: goto L_8000EE00; break;
        case 8: goto L_8000F7C0; break;
        case 9: goto L_8000EE00; break;
        case 10: goto L_8000EE00; break;
        case 11: goto L_8000EE00; break;
        case 12: goto L_8000EE00; break;
        case 13: goto L_8000EE00; break;
        case 14: goto L_8000EE00; break;
        case 15: goto L_8000EE00; break;
        case 16: goto L_8000F6BC; break;
        case 17: goto L_8000EE00; break;
        case 18: goto L_8000EE00; break;
        case 19: goto L_8000EE00; break;
        case 20: goto L_8000EE00; break;
        case 21: goto L_8000EE00; break;
        case 22: goto L_8000EE00; break;
        case 23: goto L_8000EE00; break;
        case 24: goto L_8000F6F0; break;
        case 25: goto L_8000EE00; break;
        case 26: goto L_8000EE00; break;
        case 27: goto L_8000EE00; break;
        case 28: goto L_8000EE00; break;
        case 29: goto L_8000EE00; break;
        case 30: goto L_8000EE00; break;
        case 31: goto L_8000EE00; break;
        case 32: goto L_8000F730; break;
        case 33: goto L_8000EE00; break;
        case 34: goto L_8000EE00; break;
        case 35: goto L_8000EE00; break;
        case 36: goto L_8000EE00; break;
        case 37: goto L_8000EE00; break;
        case 38: goto L_8000EE00; break;
        case 39: goto L_8000EE00; break;
        case 40: goto L_8000F748; break;
        default: switch_error(__func__, 0x8000F6B4, 0x800ABF08);
    }
    // 0x8000F6B8: nop

L_8000F6BC:
    // 0x8000F6BC: andi        $t2, $a0, 0x7
    ctx->r10 = ctx->r4 & 0X7;
    // 0x8000F6C0: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x8000F6C4: addu        $t9, $s4, $t1
    ctx->r25 = ADD32(ctx->r20, ctx->r9);
    // 0x8000F6C8: lw          $v1, 0x50($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X50);
    // 0x8000F6CC: beq         $v1, $zero, L_8000F6E8
    if (ctx->r3 == 0) {
        // 0x8000F6D0: nop
    
            goto L_8000F6E8;
    }
    // 0x8000F6D0: nop

    // 0x8000F6D4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8000F6D8: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x8000F6DC: srl         $t8, $t5, 31
    ctx->r24 = S32(U32(ctx->r13) >> 31);
    // 0x8000F6E0: b           L_8000EE00
    // 0x8000F6E4: sb          $t8, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r24;
        goto L_8000EE00;
    // 0x8000F6E4: sb          $t8, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r24;
L_8000F6E8:
    // 0x8000F6E8: b           L_8000EE00
    // 0x8000F6EC: sb          $s7, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r23;
        goto L_8000EE00;
    // 0x8000F6EC: sb          $s7, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r23;
L_8000F6F0:
    // 0x8000F6F0: jal         0x8000DCC8
    // 0x8000F6F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_22;
    // 0x8000F6F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_22:
    // 0x8000F6F8: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x8000F6FC: andi        $s3, $s3, 0x7
    ctx->r19 = ctx->r19 & 0X7;
    // 0x8000F700: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x8000F704: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000F708: jal         0x8000D6BC
    // 0x8000F70C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8000D6BC(rdram, ctx);
        goto after_23;
    // 0x8000F70C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_23:
    // 0x8000F710: bne         $v0, $zero, L_8000EE00
    if (ctx->r2 != 0) {
        // 0x8000F714: sll         $t6, $s3, 2
        ctx->r14 = S32(ctx->r19 << 2);
            goto L_8000EE00;
    }
    // 0x8000F714: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x8000F718: lw          $t0, 0x18($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X18);
    // 0x8000F71C: addu        $t4, $s4, $t6
    ctx->r12 = ADD32(ctx->r20, ctx->r14);
    // 0x8000F720: lw          $t2, 0x50($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X50);
    // 0x8000F724: addu        $t7, $t0, $s1
    ctx->r15 = ADD32(ctx->r8, ctx->r17);
    // 0x8000F728: b           L_8000EE00
    // 0x8000F72C: sw          $t7, 0x54($t2)
    MEM_W(0X54, ctx->r10) = ctx->r15;
        goto L_8000EE00;
    // 0x8000F72C: sw          $t7, 0x54($t2)
    MEM_W(0X54, ctx->r10) = ctx->r15;
L_8000F730:
    // 0x8000F730: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000F734: andi        $a1, $a1, 0x7
    ctx->r5 = ctx->r5 & 0X7;
    // 0x8000F738: jal         0x8000D81C
    // 0x8000F73C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8000D81C(rdram, ctx);
        goto after_24;
    // 0x8000F73C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_24:
    // 0x8000F740: b           L_8000EE00
    // 0x8000F744: nop

        goto L_8000EE00;
    // 0x8000F744: nop

L_8000F748:
    // 0x8000F748: lb          $t1, 0x19($s5)
    ctx->r9 = MEM_B(ctx->r21, 0X19);
    // 0x8000F74C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000F750: beq         $s7, $t1, L_8000EE00
    if (ctx->r23 == ctx->r9) {
        // 0x8000F754: nop
    
            goto L_8000EE00;
    }
    // 0x8000F754: nop

    // 0x8000F758: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x8000F75C: andi        $s3, $s3, 0x7
    ctx->r19 = ctx->r19 & 0X7;
    // 0x8000F760: jal         0x8000D6BC
    // 0x8000F764: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_8000D6BC(rdram, ctx);
        goto after_25;
    // 0x8000F764: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_25:
    // 0x8000F768: beq         $v0, $s7, L_8000EE00
    if (ctx->r2 == ctx->r23) {
        // 0x8000F76C: sll         $t2, $s3, 2
        ctx->r10 = S32(ctx->r19 << 2);
            goto L_8000EE00;
    }
    // 0x8000F76C: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x8000F770: lb          $t3, 0x19($s5)
    ctx->r11 = MEM_B(ctx->r21, 0X19);
    // 0x8000F774: lw          $t9, 0x3C($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X3C);
    // 0x8000F778: lw          $t4, 0x18($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X18);
    // 0x8000F77C: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x8000F780: addu        $s0, $t9, $t5
    ctx->r16 = ADD32(ctx->r25, ctx->r13);
    // 0x8000F784: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    // 0x8000F788: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x8000F78C: addu        $t1, $s4, $t2
    ctx->r9 = ADD32(ctx->r20, ctx->r10);
    // 0x8000F790: sll         $t6, $t0, 8
    ctx->r14 = S32(ctx->r8 << 8);
    // 0x8000F794: addu        $s1, $t8, $t6
    ctx->r17 = ADD32(ctx->r24, ctx->r14);
    // 0x8000F798: lw          $t3, 0x50($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X50);
    // 0x8000F79C: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8000F7A0: addu        $t7, $t4, $s1
    ctx->r15 = ADD32(ctx->r12, ctx->r17);
    // 0x8000F7A4: b           L_8000EE00
    // 0x8000F7A8: sw          $t7, 0x54($t3)
    MEM_W(0X54, ctx->r11) = ctx->r15;
        goto L_8000EE00;
    // 0x8000F7A8: sw          $t7, 0x54($t3)
    MEM_W(0X54, ctx->r11) = ctx->r15;
L_8000F7AC:
    // 0x8000F7AC: lb          $t9, 0x19($s5)
    ctx->r25 = MEM_B(ctx->r21, 0X19);
    // 0x8000F7B0: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x8000F7B4: addu        $t8, $s4, $t0
    ctx->r24 = ADD32(ctx->r20, ctx->r8);
    // 0x8000F7B8: b           L_8000EE00
    // 0x8000F7BC: sb          $t9, 0xCC($t8)
    MEM_B(0XCC, ctx->r24) = ctx->r25;
        goto L_8000EE00;
    // 0x8000F7BC: sb          $t9, 0xCC($t8)
    MEM_B(0XCC, ctx->r24) = ctx->r25;
L_8000F7C0:
    // 0x8000F7C0: jal         0x8000DCC8
    // 0x8000F7C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_26;
    // 0x8000F7C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_26:
    // 0x8000F7C8: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x8000F7CC: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8000F7D0: andi        $s3, $s3, 0x7
    ctx->r19 = ctx->r19 & 0X7;
    // 0x8000F7D4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8000F7D8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000F7DC: jal         0x8000D6BC
    // 0x8000F7E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8000D6BC(rdram, ctx);
        goto after_27;
    // 0x8000F7E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_27:
    // 0x8000F7E4: bne         $v0, $zero, L_8000EE00
    if (ctx->r2 != 0) {
        // 0x8000F7E8: sll         $t2, $s3, 2
        ctx->r10 = S32(ctx->r19 << 2);
            goto L_8000EE00;
    }
    // 0x8000F7E8: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x8000F7EC: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x8000F7F0: addu        $t1, $s4, $t2
    ctx->r9 = ADD32(ctx->r20, ctx->r10);
    // 0x8000F7F4: lw          $t7, 0x50($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X50);
    // 0x8000F7F8: addu        $t4, $t6, $s0
    ctx->r12 = ADD32(ctx->r14, ctx->r16);
    // 0x8000F7FC: b           L_8000EE00
    // 0x8000F800: sw          $t4, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->r12;
        goto L_8000EE00;
    // 0x8000F800: sw          $t4, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->r12;
    // 0x8000F804: andi        $t3, $a0, 0xF0
    ctx->r11 = ctx->r4 & 0XF0;
L_8000F808:
    // 0x8000F808: andi        $a1, $a0, 0xF
    ctx->r5 = ctx->r4 & 0XF;
    // 0x8000F80C: sltiu       $at, $t3, 0x61
    ctx->r1 = ctx->r11 < 0X61 ? 1 : 0;
    // 0x8000F810: beq         $at, $zero, L_8000EE00
    if (ctx->r1 == 0) {
        // 0x8000F814: andi        $a3, $a1, 0xFF
        ctx->r7 = ctx->r5 & 0XFF;
            goto L_8000EE00;
    }
    // 0x8000F814: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x8000F818: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000F81C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000F820: addu        $at, $at, $t3
    gpr jr_addend_8000F828 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8000F824: lw          $t3, -0x4054($at)
    ctx->r11 = ADD32(ctx->r1, -0X4054);
    // 0x8000F828: jr          $t3
    // 0x8000F82C: nop

    switch (jr_addend_8000F828 >> 2) {
        case 0: goto L_8000F830; break;
        case 1: goto L_8000EE00; break;
        case 2: goto L_8000EE00; break;
        case 3: goto L_8000EE00; break;
        case 4: goto L_8000EE00; break;
        case 5: goto L_8000EE00; break;
        case 6: goto L_8000EE00; break;
        case 7: goto L_8000EE00; break;
        case 8: goto L_8000EE00; break;
        case 9: goto L_8000EE00; break;
        case 10: goto L_8000EE00; break;
        case 11: goto L_8000EE00; break;
        case 12: goto L_8000EE00; break;
        case 13: goto L_8000EE00; break;
        case 14: goto L_8000EE00; break;
        case 15: goto L_8000EE00; break;
        case 16: goto L_8000F83C; break;
        case 17: goto L_8000EE00; break;
        case 18: goto L_8000EE00; break;
        case 19: goto L_8000EE00; break;
        case 20: goto L_8000EE00; break;
        case 21: goto L_8000EE00; break;
        case 22: goto L_8000EE00; break;
        case 23: goto L_8000EE00; break;
        case 24: goto L_8000EE00; break;
        case 25: goto L_8000EE00; break;
        case 26: goto L_8000EE00; break;
        case 27: goto L_8000EE00; break;
        case 28: goto L_8000EE00; break;
        case 29: goto L_8000EE00; break;
        case 30: goto L_8000EE00; break;
        case 31: goto L_8000EE00; break;
        case 32: goto L_8000F8A4; break;
        case 33: goto L_8000EE00; break;
        case 34: goto L_8000EE00; break;
        case 35: goto L_8000EE00; break;
        case 36: goto L_8000EE00; break;
        case 37: goto L_8000EE00; break;
        case 38: goto L_8000EE00; break;
        case 39: goto L_8000EE00; break;
        case 40: goto L_8000EE00; break;
        case 41: goto L_8000EE00; break;
        case 42: goto L_8000EE00; break;
        case 43: goto L_8000EE00; break;
        case 44: goto L_8000EE00; break;
        case 45: goto L_8000EE00; break;
        case 46: goto L_8000EE00; break;
        case 47: goto L_8000EE00; break;
        case 48: goto L_8000F8D0; break;
        case 49: goto L_8000EE00; break;
        case 50: goto L_8000EE00; break;
        case 51: goto L_8000EE00; break;
        case 52: goto L_8000EE00; break;
        case 53: goto L_8000EE00; break;
        case 54: goto L_8000EE00; break;
        case 55: goto L_8000EE00; break;
        case 56: goto L_8000EE00; break;
        case 57: goto L_8000EE00; break;
        case 58: goto L_8000EE00; break;
        case 59: goto L_8000EE00; break;
        case 60: goto L_8000EE00; break;
        case 61: goto L_8000EE00; break;
        case 62: goto L_8000EE00; break;
        case 63: goto L_8000EE00; break;
        case 64: goto L_8000F8FC; break;
        case 65: goto L_8000EE00; break;
        case 66: goto L_8000EE00; break;
        case 67: goto L_8000EE00; break;
        case 68: goto L_8000EE00; break;
        case 69: goto L_8000EE00; break;
        case 70: goto L_8000EE00; break;
        case 71: goto L_8000EE00; break;
        case 72: goto L_8000EE00; break;
        case 73: goto L_8000EE00; break;
        case 74: goto L_8000EE00; break;
        case 75: goto L_8000EE00; break;
        case 76: goto L_8000EE00; break;
        case 77: goto L_8000EE00; break;
        case 78: goto L_8000EE00; break;
        case 79: goto L_8000EE00; break;
        case 80: goto L_8000F888; break;
        case 81: goto L_8000EE00; break;
        case 82: goto L_8000EE00; break;
        case 83: goto L_8000EE00; break;
        case 84: goto L_8000EE00; break;
        case 85: goto L_8000EE00; break;
        case 86: goto L_8000EE00; break;
        case 87: goto L_8000EE00; break;
        case 88: goto L_8000EE00; break;
        case 89: goto L_8000EE00; break;
        case 90: goto L_8000EE00; break;
        case 91: goto L_8000EE00; break;
        case 92: goto L_8000EE00; break;
        case 93: goto L_8000EE00; break;
        case 94: goto L_8000EE00; break;
        case 95: goto L_8000EE00; break;
        case 96: goto L_8000F868; break;
        default: switch_error(__func__, 0x8000F828, 0x800ABFAC);
    }
    // 0x8000F82C: nop

L_8000F830:
    // 0x8000F830: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x8000F834: b           L_8000F928
    // 0x8000F838: sh          $t5, 0x1E($s4)
    MEM_H(0X1E, ctx->r20) = ctx->r13;
        goto L_8000F928;
    // 0x8000F838: sh          $t5, 0x1E($s4)
    MEM_H(0X1E, ctx->r20) = ctx->r13;
L_8000F83C:
    // 0x8000F83C: andi        $t9, $s2, 0xF
    ctx->r25 = ctx->r18 & 0XF;
    // 0x8000F840: addu        $v0, $s4, $t9
    ctx->r2 = ADD32(ctx->r20, ctx->r25);
    // 0x8000F844: sb          $s7, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = ctx->r23;
    // 0x8000F848: lbu         $a1, 0x19($s5)
    ctx->r5 = MEM_BU(ctx->r21, 0X19);
    // 0x8000F84C: lbu         $a0, 0x7($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X7);
    // 0x8000F850: jal         0x800080E8
    // 0x8000F854: addiu       $a2, $v0, 0xCC
    ctx->r6 = ADD32(ctx->r2, 0XCC);
    func_800080E8(rdram, ctx);
        goto after_28;
    // 0x8000F854: addiu       $a2, $v0, 0xCC
    ctx->r6 = ADD32(ctx->r2, 0XCC);
    after_28:
    // 0x8000F858: bne         $v0, $s7, L_8000EE00
    if (ctx->r2 != ctx->r23) {
        // 0x8000F85C: nop
    
            goto L_8000EE00;
    }
    // 0x8000F85C: nop

    // 0x8000F860: b           L_8000EE00
    // 0x8000F864: nop

        goto L_8000EE00;
    // 0x8000F864: nop

L_8000F868:
    // 0x8000F868: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x8000F86C: addu        $a0, $s4, $v1
    ctx->r4 = ADD32(ctx->r20, ctx->r3);
    // 0x8000F870: lb          $t8, 0xCC($a0)
    ctx->r24 = MEM_B(ctx->r4, 0XCC);
    // 0x8000F874: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000F878: beq         $at, $zero, L_8000EE00
    if (ctx->r1 == 0) {
        // 0x8000F87C: sb          $t8, 0x19($s5)
        MEM_B(0X19, ctx->r21) = ctx->r24;
            goto L_8000EE00;
    }
    // 0x8000F87C: sb          $t8, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r24;
    // 0x8000F880: b           L_8000EE00
    // 0x8000F884: sb          $s7, 0xCC($a0)
    MEM_B(0XCC, ctx->r4) = ctx->r23;
        goto L_8000EE00;
    // 0x8000F884: sb          $s7, 0xCC($a0)
    MEM_B(0XCC, ctx->r4) = ctx->r23;
L_8000F888:
    // 0x8000F888: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x8000F88C: addu        $t1, $s4, $t2
    ctx->r9 = ADD32(ctx->r20, ctx->r10);
    // 0x8000F890: lb          $t4, 0xCC($t1)
    ctx->r12 = MEM_B(ctx->r9, 0XCC);
    // 0x8000F894: lb          $t6, 0x19($s5)
    ctx->r14 = MEM_B(ctx->r21, 0X19);
    // 0x8000F898: subu        $t7, $t6, $t4
    ctx->r15 = SUB32(ctx->r14, ctx->r12);
    // 0x8000F89C: b           L_8000EE00
    // 0x8000F8A0: sb          $t7, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r15;
        goto L_8000EE00;
    // 0x8000F8A0: sb          $t7, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r15;
L_8000F8A4:
    // 0x8000F8A4: jal         0x8000DCC8
    // 0x8000F8A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_29;
    // 0x8000F8A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_29:
    // 0x8000F8AC: lw          $t3, 0x18($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X18);
    // 0x8000F8B0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000F8B4: andi        $t5, $v0, 0xFFFF
    ctx->r13 = ctx->r2 & 0XFFFF;
    // 0x8000F8B8: andi        $a1, $a1, 0xF
    ctx->r5 = ctx->r5 & 0XF;
    // 0x8000F8BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000F8C0: jal         0x8000DA50
    // 0x8000F8C4: addu        $a2, $t3, $t5
    ctx->r6 = ADD32(ctx->r11, ctx->r13);
    func_8000DA50(rdram, ctx);
        goto after_30;
    // 0x8000F8C4: addu        $a2, $t3, $t5
    ctx->r6 = ADD32(ctx->r11, ctx->r13);
    after_30:
    // 0x8000F8C8: b           L_8000EE00
    // 0x8000F8CC: nop

        goto L_8000EE00;
    // 0x8000F8CC: nop

L_8000F8D0:
    // 0x8000F8D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8000F8D4: jal         0x8000DCB4
    // 0x8000F8D8: sb          $a3, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r7;
    func_8000DCB4(rdram, ctx);
        goto after_31;
    // 0x8000F8D8: sb          $a3, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r7;
    after_31:
    // 0x8000F8DC: lbu         $a3, 0x7C($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X7C);
    // 0x8000F8E0: lb          $t0, 0x19($s5)
    ctx->r8 = MEM_B(ctx->r21, 0X19);
    // 0x8000F8E4: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8000F8E8: addu        $t8, $s6, $t9
    ctx->r24 = ADD32(ctx->r22, ctx->r25);
    // 0x8000F8EC: lw          $t2, 0x34($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X34);
    // 0x8000F8F0: addu        $t1, $t2, $v0
    ctx->r9 = ADD32(ctx->r10, ctx->r2);
    // 0x8000F8F4: b           L_8000EE00
    // 0x8000F8F8: sb          $t0, 0xCC($t1)
    MEM_B(0XCC, ctx->r9) = ctx->r8;
        goto L_8000EE00;
    // 0x8000F8F8: sb          $t0, 0xCC($t1)
    MEM_B(0XCC, ctx->r9) = ctx->r8;
L_8000F8FC:
    // 0x8000F8FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8000F900: jal         0x8000DCB4
    // 0x8000F904: sb          $a3, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r7;
    func_8000DCB4(rdram, ctx);
        goto after_32;
    // 0x8000F904: sb          $a3, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r7;
    after_32:
    // 0x8000F908: lbu         $a3, 0x7C($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X7C);
    // 0x8000F90C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8000F910: addu        $t4, $s6, $t6
    ctx->r12 = ADD32(ctx->r22, ctx->r14);
    // 0x8000F914: lw          $t7, 0x34($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X34);
    // 0x8000F918: addu        $t3, $t7, $v0
    ctx->r11 = ADD32(ctx->r15, ctx->r2);
    // 0x8000F91C: lb          $t5, 0xCC($t3)
    ctx->r13 = MEM_B(ctx->r11, 0XCC);
    // 0x8000F920: b           L_8000EE00
    // 0x8000F924: sb          $t5, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r13;
        goto L_8000EE00;
    // 0x8000F924: sb          $t5, 0x19($s5)
    MEM_B(0X19, ctx->r21) = ctx->r13;
L_8000F928:
    // 0x8000F928: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000F92C:
    // 0x8000F92C: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x8000F930: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
L_8000F934:
    // 0x8000F934: lw          $a0, 0x50($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X50);
    // 0x8000F938: beql        $a0, $zero, L_8000F94C
    if (ctx->r4 == 0) {
        // 0x8000F93C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F94C;
    }
    goto skip_8;
    // 0x8000F93C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_8:
    // 0x8000F940: jal         0x8000DD40
    // 0x8000F944: nop

    func_8000DD40(rdram, ctx);
        goto after_33;
    // 0x8000F944: nop

    after_33:
    // 0x8000F948: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000F94C:
    // 0x8000F94C: bne         $s0, $s2, L_8000F934
    if (ctx->r16 != ctx->r18) {
        // 0x8000F950: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000F934;
    }
    // 0x8000F950: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000F954: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000F958:
    // 0x8000F958: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000F95C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F960: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000F964: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000F968: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000F96C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F970: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000F974: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000F978: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000F97C: jr          $ra
    // 0x8000F980: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8000F980: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8004C834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C834: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8004C838: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8004C83C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004C840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004C844: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8004C848: lw          $a0, 0x174($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X174);
    // 0x8004C84C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8004C850: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004C854: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004C858: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004C85C: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8004C860: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004C864: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004C868: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8004C86C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8004C870: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8004C874: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8004C878: jal         0x80049864
    // 0x8004C87C: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    func_80049864(rdram, ctx);
        goto after_0;
    // 0x8004C87C: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004C880: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8004C884: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8004C888: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8004C88C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004C890: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8004C894: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8004C898: lw          $t3, 0x34($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34);
    // 0x8004C89C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004C8A0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8004C8A4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004C8A8: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8004C8AC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8004C8B0: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x8004C8B4: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004C8B8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8004C8BC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004C8C0: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x8004C8C4: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8004C8C8: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x8004C8CC: subu        $t6, $t5, $v1
    ctx->r14 = SUB32(ctx->r13, ctx->r3);
    // 0x8004C8D0: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8004C8D4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8004C8D8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8004C8DC: sh          $t6, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r14;
    // 0x8004C8E0: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8004C8E4: sh          $t4, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r12;
    // 0x8004C8E8: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
    // 0x8004C8EC: sh          $t8, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r24;
    // 0x8004C8F0: lbu         $a0, 0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X1);
    // 0x8004C8F4: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8004C8F8: sll         $t7, $t4, 16
    ctx->r15 = S32(ctx->r12 << 16);
    // 0x8004C8FC: srl         $t8, $a0, 6
    ctx->r24 = S32(U32(ctx->r4) >> 6);
    // 0x8004C900: andi        $t1, $a0, 0x3F
    ctx->r9 = ctx->r4 & 0X3F;
    // 0x8004C904: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8004C908: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8004C90C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8004C910: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8004C914: lw          $t5, 0xA24($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XA24);
    // 0x8004C918: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8004C91C: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004C920: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x8004C924: addu        $t9, $t5, $t1
    ctx->r25 = ADD32(ctx->r13, ctx->r9);
    // 0x8004C928: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004C92C: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x8004C930: sll         $t4, $t6, 16
    ctx->r12 = S32(ctx->r14 << 16);
    // 0x8004C934: sra         $t7, $t4, 16
    ctx->r15 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8004C938: srav        $t8, $t2, $t7
    ctx->r24 = S32(SIGNED(ctx->r10) >> (ctx->r15 & 31));
    // 0x8004C93C: andi        $t5, $t8, 0x1
    ctx->r13 = ctx->r24 & 0X1;
    // 0x8004C940: addiu       $t3, $t0, 0xC
    ctx->r11 = ADD32(ctx->r8, 0XC);
    // 0x8004C944: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8004C948: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8004C94C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8004C950: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8004C954: beq         $t5, $zero, L_8004C9DC
    if (ctx->r13 == 0) {
        // 0x8004C958: sh          $t2, 0x3A($sp)
        MEM_H(0X3A, ctx->r29) = ctx->r10;
            goto L_8004C9DC;
    }
    // 0x8004C958: sh          $t2, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r10;
    // 0x8004C95C: lhu         $t1, 0x38($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X38);
    // 0x8004C960: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8004C964: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004C968: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8004C96C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x8004C970: jal         0x8004C67C
    // 0x8004C974: sh          $t1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r9;
    func_8004C67C(rdram, ctx);
        goto after_1;
    // 0x8004C974: sh          $t1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r9;
    after_1:
    // 0x8004C978: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8004C97C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004C980: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8004C984: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004C988: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004C98C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004C990: slti        $at, $v1, -0x8
    ctx->r1 = SIGNED(ctx->r3) < -0X8 ? 1 : 0;
    // 0x8004C994: beq         $at, $zero, L_8004C9C8
    if (ctx->r1 == 0) {
        // 0x8004C998: sb          $t9, 0x14($t0)
        MEM_B(0X14, ctx->r8) = ctx->r25;
            goto L_8004C9C8;
    }
    // 0x8004C998: sb          $t9, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r25;
    // 0x8004C99C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8004C9A0: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8004C9A4: lhu         $t4, 0x22($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X22);
    // 0x8004C9A8: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8004C9AC: lwc1        $f6, 0x84($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X84);
    // 0x8004C9B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004C9B4: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    // 0x8004C9B8: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004C9BC: lwc1        $f8, 0x8CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X8CC);
    // 0x8004C9C0: b           L_8004C9E4
    // 0x8004C9C4: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
        goto L_8004C9E4;
    // 0x8004C9C4: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
L_8004C9C8:
    // 0x8004C9C8: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8004C9CC: nop

    // 0x8004C9D0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004C9D4: b           L_8004C9E4
    // 0x8004C9D8: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
        goto L_8004C9E4;
    // 0x8004C9D8: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
L_8004C9DC:
    // 0x8004C9DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004C9E0: nop

L_8004C9E4:
    // 0x8004C9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004C9E8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8004C9EC: jr          $ra
    // 0x8004C9F0: nop

    return;
    // 0x8004C9F0: nop

;}
RECOMP_FUNC void func_807AFE94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AFE94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807AFE98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807AFE9C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x807AFEA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807AFEA4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807AFEA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AFEAC: jal         0x80064E84
    // 0x807AFEB0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x807AFEB0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x807AFEB4: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x807AFEB8: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x807AFEBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_807AFEC0:
    // 0x807AFEC0: jal         0x80064E84
    // 0x807AFEC4: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x807AFEC4: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    after_1:
    // 0x807AFEC8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x807AFECC: bne         $s0, $s2, L_807AFEC0
    if (ctx->r16 != ctx->r18) {
        // 0x807AFED0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_807AFEC0;
    }
    // 0x807AFED0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807AFED4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807AFED8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AFEDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807AFEE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807AFEE4: jr          $ra
    // 0x807AFEE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807AFEE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8045BBB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045BBB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045BBBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045BBC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8045BBC4: jal         0x80064E84
    // 0x8045BBC8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8045BBC8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8045BBCC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8045BBD0: jal         0x80064E84
    // 0x8045BBD4: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x8045BBD4: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_1:
    // 0x8045BBD8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8045BBDC: jal         0x80064E84
    // 0x8045BBE0: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x8045BBE0: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    after_2:
    // 0x8045BBE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045BBE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045BBEC: jr          $ra
    // 0x8045BBF0: nop

    return;
    // 0x8045BBF0: nop

;}
RECOMP_FUNC void func_800443EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800443EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800443F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800443F4: jal         0x80043830
    // 0x800443F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80043830(rdram, ctx);
        goto after_0;
    // 0x800443F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800443FC: bne         $v0, $zero, L_8004441C
    if (ctx->r2 != 0) {
        // 0x80044400: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_8004441C;
    }
    // 0x80044400: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80044404: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044408: addiu       $a0, $a0, 0x450
    ctx->r4 = ADD32(ctx->r4, 0X450);
    // 0x8004440C: jal         0x80071380
    // 0x80044410: addiu       $a1, $zero, 0x450
    ctx->r5 = ADD32(0, 0X450);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80044410: addiu       $a1, $zero, 0x450
    ctx->r5 = ADD32(0, 0X450);
    after_1:
    // 0x80044414: b           L_8004444C
    // 0x80044418: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004444C;
    // 0x80044418: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004441C:
    // 0x8004441C: addiu       $a0, $a0, -0x77C0
    ctx->r4 = ADD32(ctx->r4, -0X77C0);
    // 0x80044420: jal         0x80043D34
    // 0x80044424: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_80043D34(rdram, ctx);
        goto after_2;
    // 0x80044424: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80044428: bne         $v0, $zero, L_8004443C
    if (ctx->r2 != 0) {
        // 0x8004442C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8004443C;
    }
    // 0x8004442C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044430: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    // 0x80044434: jal         0x80071380
    // 0x80044438: addiu       $a1, $zero, 0x45B
    ctx->r5 = ADD32(0, 0X45B);
    Fault_HungUp(rdram, ctx);
        goto after_3;
    // 0x80044438: addiu       $a1, $zero, 0x45B
    ctx->r5 = ADD32(0, 0X45B);
    after_3:
L_8004443C:
    // 0x8004443C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80044440: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80044444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80044448: sb          $t6, 0x17D($t7)
    MEM_B(0X17D, ctx->r15) = ctx->r14;
L_8004444C:
    // 0x8004444C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044454: jr          $ra
    // 0x80044458: nop

    return;
    // 0x80044458: nop

;}
RECOMP_FUNC void func_80467834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80467834: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80467838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046783C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80467840: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80467844: jal         0x80467610
    // 0x80467848: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80467610(rdram, ctx);
        goto after_0;
    // 0x80467848: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8046784C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80467850: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80467854: lh          $t9, 0x14($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X14);
    // 0x80467858: addiu       $a3, $v1, 0x238E
    ctx->r7 = ADD32(ctx->r3, 0X238E);
    // 0x8046785C: lh          $t6, 0x13E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X13E);
    // 0x80467860: lh          $t7, 0x13C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X13C);
    // 0x80467864: lw          $t0, 0x168($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X168);
    // 0x80467868: addiu       $a2, $v0, 0x13C
    ctx->r6 = ADD32(ctx->r2, 0X13C);
    // 0x8046786C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467870: lw          $t2, 0x80($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X80);
    // 0x80467874: lw          $a0, 0x88($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X88);
    // 0x80467878: mflo        $t8
    ctx->r24 = lo;
    // 0x8046787C: nop

    // 0x80467880: nop

    // 0x80467884: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467888: mflo        $t1
    ctx->r9 = lo;
    // 0x8046788C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x80467890: jal         0x80055D6C
    // 0x80467894: nop

    func_80055D6C(rdram, ctx);
        goto after_1;
    // 0x80467894: nop

    after_1:
    // 0x80467898: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8046789C: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x804678A0: lh          $t6, 0x16($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X16);
    // 0x804678A4: addiu       $a3, $v1, 0x27FE
    ctx->r7 = ADD32(ctx->r3, 0X27FE);
    // 0x804678A8: lh          $t3, 0x13E($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X13E);
    // 0x804678AC: lh          $t4, 0x13C($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X13C);
    // 0x804678B0: lw          $t0, 0x168($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X168);
    // 0x804678B4: addiu       $a2, $v0, 0x13C
    ctx->r6 = ADD32(ctx->r2, 0X13C);
    // 0x804678B8: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804678BC: lw          $t8, 0x80($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X80);
    // 0x804678C0: lw          $a0, 0x88($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X88);
    // 0x804678C4: mflo        $t5
    ctx->r13 = lo;
    // 0x804678C8: nop

    // 0x804678CC: nop

    // 0x804678D0: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804678D4: mflo        $t7
    ctx->r15 = lo;
    // 0x804678D8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x804678DC: jal         0x80055D6C
    // 0x804678E0: nop

    func_80055D6C(rdram, ctx);
        goto after_2;
    // 0x804678E0: nop

    after_2:
    // 0x804678E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804678E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804678EC: jal         0x804686B4
    // 0x804678F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804686B4(rdram, ctx);
        goto after_3;
    // 0x804678F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x804678F4: jal         0x80466950
    // 0x804678F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80466950(rdram, ctx);
        goto after_4;
    // 0x804678F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x804678FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80467900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80467904: jr          $ra
    // 0x80467908: nop

    return;
    // 0x80467908: nop

;}
RECOMP_FUNC void func_8003AF20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AF20: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8003AF24: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8003AF28: addiu       $t6, $t6, 0x5284
    ctx->r14 = ADD32(ctx->r14, 0X5284);
    // 0x8003AF2C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003AF30: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8003AF34: addiu       $t9, $t9, -0x60B8
    ctx->r25 = ADD32(ctx->r25, -0X60B8);
    // 0x8003AF38: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x8003AF3C: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x8003AF40: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8003AF44: jr          $ra
    // 0x8003AF48: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    return;
    // 0x8003AF48: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
;}
RECOMP_FUNC void func_8003B2FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B2FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B304: jal         0x8003B26C
    // 0x8003B308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003B26C(rdram, ctx);
        goto after_0;
    // 0x8003B308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B30C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B310: jal         0x8003B694
    // 0x8003B314: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8003B694(rdram, ctx);
        goto after_1;
    // 0x8003B314: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8003B318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B31C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B320: jr          $ra
    // 0x8003B324: nop

    return;
    // 0x8003B324: nop

;}
RECOMP_FUNC void func_8042FB6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FB6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042FB70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042FB74: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8042FB78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042FB7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042FB80: jal         0x804303F0
    // 0x8042FB84: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804303F0(rdram, ctx);
        goto after_0;
    // 0x8042FB84: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8042FB88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042FB8C: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X18C8) << 16);
    // 0x8042FB90: addiu       $t6, $t6, -0x658
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X18C8));
    // 0x8042FB94: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FB98: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8042FB9C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8042FBA0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8042FBA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042FBA8: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FBAC: swc1        $f4, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f4.u32l;
    // 0x8042FBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042FBB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042FBB8: jr          $ra
    // 0x8042FBBC: nop

    return;
    // 0x8042FBBC: nop

;}
RECOMP_FUNC void func_80409188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409188: addiu       $v0, $a0, 0xA00
    ctx->r2 = ADD32(ctx->r4, 0XA00);
    // 0x8040918C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80409190: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x80409194: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80409198:
    // 0x80409198: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8040919C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x804091A0: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x804091A4: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x804091A8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x804091AC: bne         $v1, $a0, L_80409198
    if (ctx->r3 != ctx->r4) {
        // 0x804091B0: swc1        $f0, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->f0.u32l;
            goto L_80409198;
    }
    // 0x804091B0: swc1        $f0, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f0.u32l;
    // 0x804091B4: jr          $ra
    // 0x804091B8: nop

    return;
    // 0x804091B8: nop

;}
RECOMP_FUNC void func_800405C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800405C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800405CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800405D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800405D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800405D8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800405DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800405E0: lwc1        $f6, 0x2E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2E0);
    // 0x800405E4: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x800405E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800405EC: lw          $a3, 0x1EC($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X1EC);
    // 0x800405F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800405F4: lwc1        $f14, 0x88($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X88);
    // 0x800405F8: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800405FC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80040600: jal         0x8003B8F0
    // 0x80040604: nop

    func_8003B8F0(rdram, ctx);
        goto after_0;
    // 0x80040604: nop

    after_0:
    // 0x80040608: bne         $v0, $zero, L_80040618
    if (ctx->r2 != 0) {
        // 0x8004060C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80040618;
    }
    // 0x8004060C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80040610: b           L_800406CC
    // 0x80040614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800406CC;
    // 0x80040614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040618:
    // 0x80040618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004061C: jal         0x8003AE4C
    // 0x80040620: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8003AE4C(rdram, ctx);
        goto after_1;
    // 0x80040620: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80040624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80040628: jal         0x800404C8
    // 0x8004062C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800404C8(rdram, ctx);
        goto after_2;
    // 0x8004062C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80040630: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80040634: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x80040638: addiu       $a1, $a1, 0x78
    ctx->r5 = ADD32(ctx->r5, 0X78);
    // 0x8004063C: jal         0x80065490
    // 0x80040640: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x80040640: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x80040644: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80040648: jal         0x80065490
    // 0x8004064C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    func_80065490(rdram, ctx);
        goto after_4;
    // 0x8004064C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    after_4:
    // 0x80040650: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80040654: addiu       $t7, $t7, -0x4E10
    ctx->r15 = ADD32(ctx->r15, -0X4E10);
    // 0x80040658: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x8004065C: lw          $t8, 0x174($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X174);
    // 0x80040660: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    // 0x80040664: addiu       $t4, $zero, 0x153
    ctx->r12 = ADD32(0, 0X153);
    // 0x80040668: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x8004066C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80040670: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80040674: sb          $t9, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r25;
    // 0x80040678: lw          $t0, 0x20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X20);
    // 0x8004067C: addiu       $t6, $t6, -0x6004
    ctx->r14 = ADD32(ctx->r14, -0X6004);
    // 0x80040680: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80040684: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x80040688: addiu       $t8, $t8, -0x7644
    ctx->r24 = ADD32(ctx->r24, -0X7644);
    // 0x8004068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80040690: sh          $t1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r9;
    // 0x80040694: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80040698: lw          $t2, 0x20($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X20);
    // 0x8004069C: lh          $t3, 0xE($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XE);
    // 0x800406A0: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    // 0x800406A4: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800406A8: sh          $t4, 0x4C($t5)
    MEM_H(0X4C, ctx->r13) = ctx->r12;
    // 0x800406AC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800406B0: sw          $t6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r14;
    // 0x800406B4: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x800406B8: jal         0x80044194
    // 0x800406BC: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    func_80044194(rdram, ctx);
        goto after_5;
    // 0x800406BC: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    after_5:
    // 0x800406C0: jal         0x800447C8
    // 0x800406C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800447C8(rdram, ctx);
        goto after_6;
    // 0x800406C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x800406C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800406CC:
    // 0x800406CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800406D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800406D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800406D8: jr          $ra
    // 0x800406DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800406DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005BDF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BDF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005BDFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BE00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005BE04: jal         0x8005BA30
    // 0x8005BE08: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8005BA30(rdram, ctx);
        goto after_0;
    // 0x8005BE08: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8005BE0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BE10: bne         $v0, $at, L_8005BE20
    if (ctx->r2 != ctx->r1) {
        // 0x8005BE14: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005BE20;
    }
    // 0x8005BE14: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005BE18: b           L_8005BE38
    // 0x8005BE1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005BE38;
    // 0x8005BE1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005BE20:
    // 0x8005BE20: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8005BE24: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8005BE28: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8005BE2C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005BE30: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8005BE34: lw          $v0, -0x4B9C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B9C);
L_8005BE38:
    // 0x8005BE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BE3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005BE40: jr          $ra
    // 0x8005BE44: nop

    return;
    // 0x8005BE44: nop

    // 0x8005BE48: nop

    // 0x8005BE4C: nop

;}
RECOMP_FUNC void func_80444AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444AB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80444AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80444ABC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80444AC0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80444AC4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80444AC8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80444ACC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80444AD0: jal         0x80047090
    // 0x80444AD4: addiu       $a0, $zero, 0x40EF
    ctx->r4 = ADD32(0, 0X40EF);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80444AD4: addiu       $a0, $zero, 0x40EF
    ctx->r4 = ADD32(0, 0X40EF);
    after_0:
    // 0x80444AD8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80444ADC: beq         $v0, $at, L_80444B14
    if (ctx->r2 == ctx->r1) {
        // 0x80444AE0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80444B14;
    }
    // 0x80444AE0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80444AE4: lui         $at, 0x40EF
    ctx->r1 = S32(0X40EF << 16);
    // 0x80444AE8: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80444AEC: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80444AF0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80444AF4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80444AF8: jal         0x8004613C
    // 0x80444AFC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80444AFC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80444B00: beq         $v0, $zero, L_80444B14
    if (ctx->r2 == 0) {
        // 0x80444B04: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80444B14;
    }
    // 0x80444B04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80444B08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80444B0C: jal         0x80047F9C
    // 0x80444B10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80444B10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_80444B14:
    // 0x80444B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80444B18: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80444B1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80444B20: jr          $ra
    // 0x80444B24: nop

    return;
    // 0x80444B24: nop

;}
RECOMP_FUNC void func_80411328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80411328: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8041132C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80411330: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x80411334: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80411338: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8041133C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80411340: addu        $s4, $a0, $at
    ctx->r20 = ADD32(ctx->r4, ctx->r1);
    // 0x80411344: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80411348: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8041134C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80411350: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80411354: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80411358: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8041135C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80411360: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80411364: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80411368: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8041136C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80411370: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80411374: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80411378: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8041137C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80411380: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80411384: lw          $s5, 0x1E0($a1)
    ctx->r21 = MEM_W(ctx->r5, 0X1E0);
    // 0x80411388: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x8041138C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_80411390:
    // 0x80411390: lui         $at, 0xC320
    ctx->r1 = S32(0XC320 << 16);
    // 0x80411394: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80411398: mul.s       $f30, $f28, $f28
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f30.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8041139C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_804113A0:
    // 0x804113A0: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x804113A4: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(26, 0X2484) << 16);
    // 0x804113A8: lwc1        $f6, 0x1B04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(26, 0X2484));
    // 0x804113AC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x804113B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804113B4: lw          $t7, 0x39E8($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X39E8);
    // 0x804113B8: add.s       $f0, $f4, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x804113BC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x804113C0: multu       $t8, $s2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804113C4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x804113C8: mflo        $t9
    ctx->r25 = lo;
    // 0x804113CC: addu        $s0, $t9, $s6
    ctx->r16 = ADD32(ctx->r25, ctx->r22);
    // 0x804113D0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x804113D4: nop

    // 0x804113D8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804113DC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804113E0: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x804113E4: nop

    // 0x804113E8: slt         $at, $v1, $s5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x804113EC: beq         $at, $zero, L_8041149C
    if (ctx->r1 == 0) {
        // 0x804113F0: subu        $v0, $s5, $v1
        ctx->r2 = SUB32(ctx->r21, ctx->r3);
            goto L_8041149C;
    }
    // 0x804113F0: subu        $v0, $s5, $v1
    ctx->r2 = SUB32(ctx->r21, ctx->r3);
    // 0x804113F4: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x804113F8: beq         $at, $zero, L_80411484
    if (ctx->r1 == 0) {
        // 0x804113FC: nop
    
            goto L_80411484;
    }
    // 0x804113FC: nop

    // 0x80411400: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80411404: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80411408: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8041140C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80411410: mul.s       $f22, $f6, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80411414: jal         0x80066DE4
    // 0x80411418: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80411418: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x8041141C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80411420: jal         0x80066E88
    // 0x80411424: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80411424: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_1:
    // 0x80411428: mul.s       $f10, $f20, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8041142C: nop

    // 0x80411430: mul.s       $f16, $f28, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f28.fl, ctx->f24.fl);
    // 0x80411434: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80411438: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8041143C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80411440: nop

    // 0x80411444: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80411448: mflo        $t1
    ctx->r9 = lo;
    // 0x8041144C: addu        $v0, $s1, $t1
    ctx->r2 = ADD32(ctx->r17, ctx->r9);
    // 0x80411450: mul.s       $f10, $f28, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x80411454: nop

    // 0x80411458: mul.s       $f16, $f20, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8041145C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80411460: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80411464: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80411468: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8041146C: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80411470: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80411474: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80411478: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8041147C: b           L_804114CC
    // 0x80411480: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
        goto L_804114CC;
    // 0x80411480: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
L_80411484:
    // 0x80411484: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80411488: mflo        $t6
    ctx->r14 = lo;
    // 0x8041148C: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x80411490: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80411494: b           L_804114CC
    // 0x80411498: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
        goto L_804114CC;
    // 0x80411498: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
L_8041149C:
    // 0x8041149C: mul.s       $f10, $f20, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x804114A0: nop

    // 0x804114A4: mul.s       $f18, $f28, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f28.fl, ctx->f26.fl);
    // 0x804114A8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804114AC: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804114B0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804114B4: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x804114B8: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x804114BC: mflo        $t7
    ctx->r15 = lo;
    // 0x804114C0: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x804114C4: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x804114C8: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
L_804114CC:
    // 0x804114CC: lw          $t2, 0x39DC($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X39DC);
    // 0x804114D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x804114D4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x804114D8: bgez        $t2, L_804114EC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x804114DC: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_804114EC;
    }
    // 0x804114DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804114E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804114E4: nop

    // 0x804114E8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_804114EC:
    // 0x804114EC: lw          $v0, 0x39E4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X39E4);
    // 0x804114F0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x804114F4: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x804114F8: sltu        $at, $v0, $s2
    ctx->r1 = ctx->r2 < ctx->r18 ? 1 : 0;
    // 0x804114FC: beq         $at, $zero, L_804113A0
    if (ctx->r1 == 0) {
        // 0x80411500: nop
    
            goto L_804113A0;
    }
    // 0x80411500: nop

    // 0x80411504: lw          $t3, 0x39E0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X39E0);
    // 0x80411508: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8041150C: lw          $v1, 0x39E8($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X39E8);
    // 0x80411510: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80411514: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80411518: bgez        $t3, L_8041152C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8041151C: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8041152C;
    }
    // 0x8041151C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80411520: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80411524: nop

    // 0x80411528: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8041152C:
    // 0x8041152C: sltu        $at, $v1, $s6
    ctx->r1 = ctx->r3 < ctx->r22 ? 1 : 0;
    // 0x80411530: beq         $at, $zero, L_80411390
    if (ctx->r1 == 0) {
        // 0x80411534: add.s       $f28, $f28, $f18
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f18.fl;
            goto L_80411390;
    }
    // 0x80411534: add.s       $f28, $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f18.fl;
    // 0x80411538: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8041153C: lw          $v0, 0x1E0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X1E0);
    // 0x80411540: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80411544: sw          $t5, 0x1E0($t4)
    MEM_W(0X1E0, ctx->r12) = ctx->r13;
    // 0x80411548: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8041154C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80411550: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80411554: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80411558: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8041155C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80411560: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80411564: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80411568: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8041156C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80411570: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80411574: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80411578: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8041157C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80411580: jr          $ra
    // 0x80411584: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80411584: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80448FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80448FB8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80448FBC: lw          $t7, -0x71A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71A8);
    // 0x80448FC0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80448FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80448FC8: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80448FCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80448FD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80448FD4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80448FD8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80448FDC: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x80448FE0: bne         $t9, $zero, L_8044900C
    if (ctx->r25 != 0) {
        // 0x80448FE4: lw          $v0, 0x1F4($t6)
        ctx->r2 = MEM_W(ctx->r14, 0X1F4);
            goto L_8044900C;
    }
    // 0x80448FE4: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x80448FE8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448FEC: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80448FF0: addu        $a0, $v0, $at
    ctx->r4 = ADD32(ctx->r2, ctx->r1);
    // 0x80448FF4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448FF8: ori         $at, $at, 0x6E2C
    ctx->r1 = ctx->r1 | 0X6E2C;
    // 0x80448FFC: jal         0x80448C78
    // 0x80449000: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    func_80448C78(rdram, ctx);
        goto after_0;
    // 0x80449000: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    after_0:
    // 0x80449004: b           L_8044902C
    // 0x80449008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044902C;
    // 0x80449008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044900C:
    // 0x8044900C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449010: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80449014: addu        $a0, $v0, $at
    ctx->r4 = ADD32(ctx->r2, ctx->r1);
    // 0x80449018: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044901C: ori         $at, $at, 0x6E2C
    ctx->r1 = ctx->r1 | 0X6E2C;
    // 0x80449020: jal         0x80448E18
    // 0x80449024: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    func_80448E18(rdram, ctx);
        goto after_1;
    // 0x80449024: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    after_1:
    // 0x80449028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044902C:
    // 0x8044902C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80449030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449034: jr          $ra
    // 0x80449038: nop

    return;
    // 0x80449038: nop

;}
RECOMP_FUNC void func_80708D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80708D70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80708D74: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80708D78: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80708D7C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80708D80: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80708D84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80708D88: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x80708D8C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80708D90: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80708D94: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x80708D98: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80708D9C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80708DA0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80708DA4: lw          $t6, 0xA68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XA68);
L_80708DA8:
    // 0x80708DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80708DAC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80708DB0: lw          $t9, 0xA8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XA8);
    // 0x80708DB4: jalr        $t9
    // 0x80708DB8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80708DB8: nop

    after_0:
    // 0x80708DBC: beq         $v0, $zero, L_80708DC8
    if (ctx->r2 == 0) {
        // 0x80708DC0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80708DC8;
    }
    // 0x80708DC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80708DC4: sb          $s2, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r18;
L_80708DC8:
    // 0x80708DC8: jal         0x80047F9C
    // 0x80708DCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x80708DCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x80708DD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80708DD4: bnel        $s0, $s3, L_80708DA8
    if (ctx->r16 != ctx->r19) {
        // 0x80708DD8: lw          $t6, 0xA68($s1)
        ctx->r14 = MEM_W(ctx->r17, 0XA68);
            goto L_80708DA8;
    }
    goto skip_0;
    // 0x80708DD8: lw          $t6, 0xA68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XA68);
    skip_0:
    // 0x80708DDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80708DE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80708DE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80708DE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80708DEC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80708DF0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80708DF4: jr          $ra
    // 0x80708DF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80708DF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8057AA54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057AA54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8057AA58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057AA5C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057AA60: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8057AA64: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8057AA68: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8057AA6C: jal         0x8057A2B8
    // 0x8057AA70: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_8057A2B8(rdram, ctx);
        goto after_0;
    // 0x8057AA70: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x8057AA74: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8057AA78: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8057AA7C: lw          $t7, 0x1E0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1E0);
    // 0x8057AA80: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8057AA84: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8057AA88: bne         $at, $zero, L_8057AB2C
    if (ctx->r1 != 0) {
        // 0x8057AA8C: sw          $t8, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r24;
            goto L_8057AB2C;
    }
    // 0x8057AA8C: sw          $t8, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r24;
    // 0x8057AA90: sw          $zero, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = 0;
    // 0x8057AA94: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8057AA98: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8057AA9C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8057AAA0: addu        $v0, $v1, $t2
    ctx->r2 = ADD32(ctx->r3, ctx->r10);
    // 0x8057AAA4: lh          $t3, 0xC($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XC);
    // 0x8057AAA8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8057AAAC: sh          $t4, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r12;
    // 0x8057AAB0: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x8057AAB4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8057AAB8: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x8057AABC: bne         $at, $zero, L_8057AAF4
    if (ctx->r1 != 0) {
        // 0x8057AAC0: sll         $t6, $t5, 2
        ctx->r14 = S32(ctx->r13 << 2);
            goto L_8057AAF4;
    }
    // 0x8057AAC0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8057AAC4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8057AAC8: lw          $t7, -0x762C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X762C);
    // 0x8057AACC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8057AAD0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8057AAD4: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8057AAD8: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
    // 0x8057AADC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8057AAE0: jal         0x8057B444
    // 0x8057AAE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8057B444(rdram, ctx);
        goto after_1;
    // 0x8057AAE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8057AAE8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8057AAEC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8057AAF0: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
L_8057AAF4:
    // 0x8057AAF4: lw          $v1, 0x168($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X168);
    // 0x8057AAF8: lw          $v0, 0x16C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X16C);
    // 0x8057AAFC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8057AB00: lh          $t3, 0x7C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X7C);
    // 0x8057AB04: lbu         $t9, 0x34($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X34);
    // 0x8057AB08: lw          $t5, 0x80($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X80);
    // 0x8057AB0C: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8057AB10: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8057AB14: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8057AB18: lw          $a0, 0x38($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X38);
    // 0x8057AB1C: mflo        $t4
    ctx->r12 = lo;
    // 0x8057AB20: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x8057AB24: jal         0x8005B350
    // 0x8057AB28: nop

    func_8005B350(rdram, ctx);
        goto after_2;
    // 0x8057AB28: nop

    after_2:
L_8057AB2C:
    // 0x8057AB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057AB30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8057AB34: jr          $ra
    // 0x8057AB38: nop

    return;
    // 0x8057AB38: nop

;}
RECOMP_FUNC void func_80791E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791E90: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80791E94: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80791E98: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x80791E9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80791EA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80791EA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80791EA8: jal         0x80790714
    // 0x80791EAC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    func_80790714(rdram, ctx);
        goto after_0;
    // 0x80791EAC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    after_0:
    // 0x80791EB0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80791EB4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80791EB8: jal         0x807903C4
    // 0x80791EBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_1;
    // 0x80791EBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80791EC0: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    // 0x80791EC4: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80791EC8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80791ECC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80791ED0: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x80791ED4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80791ED8: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80791EDC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80791EE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80791EE4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80791EE8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80791EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80791EF0: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80791EF4: bne         $t8, $at, L_80791F84
    if (ctx->r24 != ctx->r1) {
        // 0x80791EF8: nop
    
            goto L_80791F84;
    }
    // 0x80791EF8: nop

    // 0x80791EFC: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80791F00: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80791F04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80791F08: sub.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x80791F0C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80791F10: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80791F14: nop

    // 0x80791F18: bc1fl       L_80791F4C
    if (!c1cs) {
        // 0x80791F1C: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80791F4C;
    }
    goto skip_0;
    // 0x80791F1C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_0:
    // 0x80791F20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80791F24: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AD0) << 16);
    // 0x80791F28: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80791F2C: lwc1        $f6, 0x7E20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AD0));
    // 0x80791F30: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AD4) << 16);
    // 0x80791F34: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x80791F38: lwc1        $f8, 0x7E24($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AD4));
    // 0x80791F3C: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80791F40: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80791F44: sub.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80791F48: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80791F4C:
    // 0x80791F4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80791F50: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80791F54: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80791F58: nop

    // 0x80791F5C: bc1f        L_80791F84
    if (!c1cs) {
        // 0x80791F60: nop
    
            goto L_80791F84;
    }
    // 0x80791F60: nop

    // 0x80791F64: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80791F68: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AD8) << 16);
    // 0x80791F6C: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80791F70: lwc1        $f4, 0x7E28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AD8));
    // 0x80791F74: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7ADC) << 16);
    // 0x80791F78: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x80791F7C: lwc1        $f6, 0x7E2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7ADC));
    // 0x80791F80: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
L_80791F84:
    // 0x80791F84: jal         0x807903C4
    // 0x80791F88: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_807903C4(rdram, ctx);
        goto after_2;
    // 0x80791F88: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x80791F8C: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x80791F90: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80791F94: slti        $at, $t0, -0x1E
    ctx->r1 = SIGNED(ctx->r8) < -0X1E ? 1 : 0;
    // 0x80791F98: beql        $at, $zero, L_8079208C
    if (ctx->r1 == 0) {
        // 0x80791F9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8079208C;
    }
    goto skip_1;
    // 0x80791F9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80791FA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80791FA4: nop

    // 0x80791FA8: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80791FAC: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80791FB0: lw          $t1, 0x1E4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E4);
    // 0x80791FB4: bnel        $t1, $zero, L_80792008
    if (ctx->r9 != 0) {
        // 0x80791FB8: lw          $t2, 0x1E4($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1E4);
            goto L_80792008;
    }
    goto skip_2;
    // 0x80791FB8: lw          $t2, 0x1E4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E4);
    skip_2:
    // 0x80791FBC: jal         0x80047090
    // 0x80791FC0: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    func_80047090(rdram, ctx);
        goto after_3;
    // 0x80791FC0: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    after_3:
    // 0x80791FC4: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80791FC8: beq         $v0, $at, L_80792004
    if (ctx->r2 == ctx->r1) {
        // 0x80791FCC: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80792004;
    }
    // 0x80791FCC: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80791FD0: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80791FD4: ori         $at, $at, 0x1C00
    ctx->r1 = ctx->r1 | 0X1C00;
    // 0x80791FD8: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80791FDC: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x80791FE0: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x80791FE4: jal         0x8004613C
    // 0x80791FE8: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    func_8004613C(rdram, ctx);
        goto after_4;
    // 0x80791FE8: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_4:
    // 0x80791FEC: beq         $v0, $zero, L_80792004
    if (ctx->r2 == 0) {
        // 0x80791FF0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80792004;
    }
    // 0x80791FF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80791FF4: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80791FF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80791FFC: jal         0x80044194
    // 0x80792000: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    func_80044194(rdram, ctx);
        goto after_5;
    // 0x80792000: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    after_5:
L_80792004:
    // 0x80792004: lw          $t2, 0x1E4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E4);
L_80792008:
    // 0x80792008: blezl       $t2, L_80792058
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8079200C: lw          $v1, 0x1E4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1E4);
            goto L_80792058;
    }
    goto skip_3;
    // 0x8079200C: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
    skip_3:
    // 0x80792010: jal         0x80046E88
    // 0x80792014: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    func_80046E88(rdram, ctx);
        goto after_6;
    // 0x80792014: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    after_6:
    // 0x80792018: beql        $v0, $zero, L_80792058
    if (ctx->r2 == 0) {
        // 0x8079201C: lw          $v1, 0x1E4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1E4);
            goto L_80792058;
    }
    goto skip_4;
    // 0x8079201C: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
    skip_4:
    // 0x80792020: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
    // 0x80792024: lw          $a0, 0x16C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X16C);
    // 0x80792028: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x8079202C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80792030: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80792034: bgez        $v1, L_80792040
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80792038: addiu       $a0, $a0, 0xD
        ctx->r4 = ADD32(ctx->r4, 0XD);
            goto L_80792040;
    }
    // 0x80792038: addiu       $a0, $a0, 0xD
    ctx->r4 = ADD32(ctx->r4, 0XD);
    // 0x8079203C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80792040:
    // 0x80792040: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80792044: bnel        $at, $zero, L_80792054
    if (ctx->r1 != 0) {
        // 0x80792048: sb          $v1, 0x3($a0)
        MEM_B(0X3, ctx->r4) = ctx->r3;
            goto L_80792054;
    }
    goto skip_5;
    // 0x80792048: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
    skip_5:
    // 0x8079204C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80792050: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_80792054:
    // 0x80792054: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
L_80792058:
    // 0x80792058: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x8079205C: bnel        $v1, $at, L_80792084
    if (ctx->r3 != ctx->r1) {
        // 0x80792060: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_80792084;
    }
    goto skip_6;
    // 0x80792060: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    skip_6:
    // 0x80792064: jal         0x800409F0
    // 0x80792068: nop

    func_800409F0(rdram, ctx);
        goto after_7;
    // 0x80792068: nop

    after_7:
    // 0x8079206C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80792070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80792074: jal         0x8006E0FC
    // 0x80792078: addiu       $a2, $zero, 0x4C
    ctx->r6 = ADD32(0, 0X4C);
    func_8006E0FC(rdram, ctx);
        goto after_8;
    // 0x80792078: addiu       $a2, $zero, 0x4C
    ctx->r6 = ADD32(0, 0X4C);
    after_8:
    // 0x8079207C: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
    // 0x80792080: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
L_80792084:
    // 0x80792084: sw          $t3, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r11;
    // 0x80792088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079208C:
    // 0x8079208C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80792090: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80792094: jr          $ra
    // 0x80792098: nop

    return;
    // 0x80792098: nop

;}
RECOMP_FUNC void func_80742B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742B54: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742B58: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742B5C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742B60: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742B64: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742B68: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742B6C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742B70: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742B74: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742B78: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742B7C: jr          $ra
    // 0x80742B80: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742B80: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8078FD84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078FD84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078FD88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078FD8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8078FD90: jal         0x8004700C
    // 0x8078FD94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8078FD94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078FD98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8078FD9C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8078FDA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8078FDA4: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8078FDA8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8078FDAC: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x8078FDB0: jal         0x8078FD04
    // 0x8078FDB4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8078FD04(rdram, ctx);
        goto after_1;
    // 0x8078FDB4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8078FDB8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8078FDBC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8078FDC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8078FDC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8078FDC8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XD9C) << 16);
    // 0x8078FDCC: beq         $v1, $zero, L_8078FE08
    if (ctx->r3 == 0) {
        // 0x8078FDD0: swc1        $f4, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
            goto L_8078FE08;
    }
    // 0x8078FDD0: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8078FDD4: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8078FDD8: lwc1        $f8, 0x84($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8078FDDC: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8078FDE0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8078FDE4: nop

    // 0x8078FDE8: bc1fl       L_8078FDF8
    if (!c1cs) {
        // 0x8078FDEC: sll         $t9, $t8, 2
        ctx->r25 = S32(ctx->r24 << 2);
            goto L_8078FDF8;
    }
    goto skip_0;
    // 0x8078FDEC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    skip_0:
    // 0x8078FDF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8078FDF4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
L_8078FDF8:
    // 0x8078FDF8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8078FDFC: lwc1        $f10, -0xD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XD9C));
    // 0x8078FE00: b           L_8078FE14
    // 0x8078FE04: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
        goto L_8078FE14;
    // 0x8078FE04: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
L_8078FE08:
    // 0x8078FE08: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8078FE0C: nop

    // 0x8078FE10: swc1        $f16, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f16.u32l;
L_8078FE14:
    // 0x8078FE14: jal         0x8005FE48
    // 0x8078FE18: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x8078FE18: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8078FE1C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8078FE20: addiu       $t0, $zero, 0xC12
    ctx->r8 = ADD32(0, 0XC12);
    // 0x8078FE24: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x8078FE28: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8078FE2C: addiu       $t2, $t2, -0x6030
    ctx->r10 = ADD32(ctx->r10, -0X6030);
    // 0x8078FE30: sh          $t0, 0x4C($t1)
    MEM_H(0X4C, ctx->r9) = ctx->r8;
    // 0x8078FE34: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8078FE38: sw          $t2, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->r10;
    // 0x8078FE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078FE40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078FE44: jr          $ra
    // 0x8078FE48: nop

    return;
    // 0x8078FE48: nop

;}
RECOMP_FUNC void func_8073E124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073E124: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8073E128: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8073E12C: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8073E130: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8073E134: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x8073E138: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x8073E13C: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8073E140: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8073E144: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8073E148: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8073E14C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8073E150: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8073E154: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8073E158: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8073E15C: jal         0x8004700C
    // 0x8073E160: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8073E160: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x8073E164: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X148C) << 16);
    // 0x8073E168: lwc1        $f26, -0x19A4($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X148C));
    // 0x8073E16C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1490) << 16);
    // 0x8073E170: lwc1        $f24, -0x19A0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1490));
    // 0x8073E174: lw          $s7, 0x1F4($s5)
    ctx->r23 = MEM_W(ctx->r21, 0X1F4);
    // 0x8073E178: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1494) << 16);
    // 0x8073E17C: lwc1        $f22, -0x199C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1494));
    // 0x8073E180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8073E184: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8073E188: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8073E18C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8073E190: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x8073E194: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8073E198: or          $s0, $s7, $zero
    ctx->r16 = ctx->r23 | 0;
    // 0x8073E19C: addiu       $s2, $s7, 0x14
    ctx->r18 = ADD32(ctx->r23, 0X14);
L_8073E1A0:
    // 0x8073E1A0: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8073E1A4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8073E1A8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8073E1AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8073E1B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8073E1B4: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8073E1B8: jal         0x8073DCE8
    // 0x8073E1BC: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    func_8073DCE8(rdram, ctx);
        goto after_1;
    // 0x8073E1BC: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8073E1C0: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    // 0x8073E1C4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8073E1C8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8073E1CC: bnel        $t6, $zero, L_8073E1F8
    if (ctx->r14 != 0) {
        // 0x8073E1D0: lwc1        $f16, 0x4($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
            goto L_8073E1F8;
    }
    goto skip_0;
    // 0x8073E1D0: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x8073E1D4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8073E1D8: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x8073E1DC: nop

    // 0x8073E1E0: bc1f        L_8073E210
    if (!c1cs) {
        // 0x8073E1E4: nop
    
            goto L_8073E210;
    }
    // 0x8073E1E4: nop

    // 0x8073E1E8: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x8073E1EC: b           L_8073E210
    // 0x8073E1F0: swc1        $f24, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f24.u32l;
        goto L_8073E210;
    // 0x8073E1F0: swc1        $f24, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f24.u32l;
    // 0x8073E1F4: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
L_8073E1F8:
    // 0x8073E1F8: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x8073E1FC: nop

    // 0x8073E200: bc1f        L_8073E210
    if (!c1cs) {
        // 0x8073E204: nop
    
            goto L_8073E210;
    }
    // 0x8073E204: nop

    // 0x8073E208: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8073E20C: swc1        $f26, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f26.u32l;
L_8073E210:
    // 0x8073E210: bne         $s1, $s4, L_8073E1A0
    if (ctx->r17 != ctx->r20) {
        // 0x8073E214: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8073E1A0;
    }
    // 0x8073E214: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8073E218: beq         $s6, $zero, L_8073E244
    if (ctx->r22 == 0) {
        // 0x8073E21C: nop
    
            goto L_8073E244;
    }
    // 0x8073E21C: nop

    // 0x8073E220: lwc1        $f18, 0x3C($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X3C);
    // 0x8073E224: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1498) << 16);
    // 0x8073E228: swc1        $f18, 0x3C($s6)
    MEM_W(0X3C, ctx->r22) = ctx->f18.u32l;
    // 0x8073E22C: lwc1        $f4, 0x40($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X40);
    // 0x8073E230: swc1        $f4, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->f4.u32l;
    // 0x8073E234: lwc1        $f8, -0x1998($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1498));
    // 0x8073E238: lwc1        $f6, 0x44($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X44);
    // 0x8073E23C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8073E240: swc1        $f10, 0x44($s6)
    MEM_W(0X44, ctx->r22) = ctx->f10.u32l;
L_8073E244:
    // 0x8073E244: jal         0x8073DC90
    // 0x8073E248: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_8073DC90(rdram, ctx);
        goto after_2;
    // 0x8073E248: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_2:
    // 0x8073E24C: lw          $t7, 0x28($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X28);
    // 0x8073E250: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8073E254: bnel        $t7, $at, L_8073E30C
    if (ctx->r15 != ctx->r1) {
        // 0x8073E258: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8073E30C;
    }
    goto skip_1;
    // 0x8073E258: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x8073E25C: lwc1        $f20, 0x0($s7)
    ctx->f20.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8073E260: jal         0x80066E88
    // 0x8073E264: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8073E264: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8073E268: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8073E26C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8073E270: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x8073E274: lwc1        $f4, 0x6C($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X6C);
    // 0x8073E278: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8073E27C: lwc1        $f8, 0x3C($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X3C);
    // 0x8073E280: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8073E284: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8073E288: jal         0x80066DE4
    // 0x8073E28C: add.s       $f22, $f8, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f6.fl;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8073E28C: add.s       $f22, $f8, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f6.fl;
    after_4:
    // 0x8073E290: mul.s       $f10, $f0, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8073E294: lwc1        $f16, 0x70($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X70);
    // 0x8073E298: lwc1        $f4, 0x40($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X40);
    // 0x8073E29C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8073E2A0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8073E2A4: jal         0x80066E88
    // 0x8073E2A8: add.s       $f24, $f4, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f18.fl;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x8073E2A8: add.s       $f24, $f4, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f18.fl;
    after_5:
    // 0x8073E2AC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8073E2B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8073E2B4: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8073E2B8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8073E2BC: mul.s       $f26, $f8, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8073E2C0: jal         0x80066DE4
    // 0x8073E2C4: nop

    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x8073E2C4: nop

    after_6:
    // 0x8073E2C8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8073E2CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8073E2D0: swc1        $f22, 0x3C($s6)
    MEM_W(0X3C, ctx->r22) = ctx->f22.u32l;
    // 0x8073E2D4: swc1        $f24, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->f24.u32l;
    // 0x8073E2D8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8073E2DC: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8073E2E0: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x8073E2E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8073E2E8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8073E2EC: jal         0x8002FCFC
    // 0x8073E2F0: nop

    func_8002FCFC(rdram, ctx);
        goto after_7;
    // 0x8073E2F0: nop

    after_7:
    // 0x8073E2F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8073E2F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073E2FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8073E300: jal         0x8073E498
    // 0x8073E304: lw          $a3, 0x138($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X138);
    func_8073E498(rdram, ctx);
        goto after_8;
    // 0x8073E304: lw          $a3, 0x138($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X138);
    after_8:
    // 0x8073E308: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8073E30C:
    // 0x8073E30C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8073E310: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8073E314: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8073E318: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8073E31C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8073E320: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8073E324: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8073E328: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8073E32C: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8073E330: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8073E334: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x8073E338: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8073E33C: jr          $ra
    // 0x8073E340: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8073E340: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800430AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800430AC: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x800430B0: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x800430B4: lw          $t6, 0x1300($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1300);
    // 0x800430B8: lw          $t8, 0x12F0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X12F0);
    // 0x800430BC: addiu       $a1, $v1, 0x12F0
    ctx->r5 = ADD32(ctx->r3, 0X12F0);
    // 0x800430C0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800430C4: beq         $a0, $t8, L_800430DC
    if (ctx->r4 == ctx->r24) {
        // 0x800430C8: sw          $t7, 0x1300($v1)
        MEM_W(0X1300, ctx->r3) = ctx->r15;
            goto L_800430DC;
    }
    // 0x800430C8: sw          $t7, 0x1300($v1)
    MEM_W(0X1300, ctx->r3) = ctx->r15;
    // 0x800430CC: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
L_800430D0:
    // 0x800430D0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800430D4: bnel        $a0, $t9, L_800430D0
    if (ctx->r4 != ctx->r25) {
        // 0x800430D8: lw          $t9, 0x4($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X4);
            goto L_800430D0;
    }
    goto skip_0;
    // 0x800430D8: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    skip_0:
L_800430DC:
    // 0x800430DC: jr          $ra
    // 0x800430E0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    return;
    // 0x800430E0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
;}
RECOMP_FUNC void func_80736EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736EA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80736EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736EA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80736EAC: jal         0x80047090
    // 0x80736EB0: addiu       $a0, $zero, 0x462B
    ctx->r4 = ADD32(0, 0X462B);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80736EB0: addiu       $a0, $zero, 0x462B
    ctx->r4 = ADD32(0, 0X462B);
    after_0:
    // 0x80736EB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80736EB8: lui         $at, 0x462B
    ctx->r1 = S32(0X462B << 16);
    // 0x80736EBC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80736EC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80736EC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80736EC8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80736ECC: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x80736ED0: jal         0x8004613C
    // 0x80736ED4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80736ED4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x80736ED8: bne         $v0, $zero, L_80736EE8
    if (ctx->r2 != 0) {
        // 0x80736EDC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80736EE8;
    }
    // 0x80736EDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80736EE0: b           L_80736F10
    // 0x80736EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80736F10;
    // 0x80736EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80736EE8:
    // 0x80736EE8: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x80736EEC: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x80736EF0: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80736EF4: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80736EF8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80736EFC: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x80736F00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80736F04: jal         0x80047F9C
    // 0x80736F08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80736F08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80736F0C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80736F10:
    // 0x80736F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736F14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80736F18: jr          $ra
    // 0x80736F1C: nop

    return;
    // 0x80736F1C: nop

;}
RECOMP_FUNC void func_80075DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075DAC: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80075DB0: addiu       $t0, $t0, -0x260C
    ctx->r8 = ADD32(ctx->r8, -0X260C);
    // 0x80075DB4: lui         $v1, 0x600
    ctx->r3 = S32(0X600 << 16);
    // 0x80075DB8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80075DBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80075DC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80075DC4: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80075DC8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80075DCC: sw          $t7, -0x4FF4($at)
    MEM_W(-0X4FF4, ctx->r1) = ctx->r15;
    // 0x80075DD0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80075DD4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80075DD8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80075DDC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80075DE0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075DE4: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x80075DE8: ori         $t9, $t9, 0x3406
    ctx->r25 = ctx->r25 | 0X3406;
    // 0x80075DEC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80075DF0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80075DF4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80075DF8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075DFC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80075E00: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x80075E04: lui         $t4, 0xD00
    ctx->r12 = S32(0XD00 << 16);
    // 0x80075E08: addiu       $t4, $t4, 0xC0
    ctx->r12 = ADD32(ctx->r12, 0XC0);
    // 0x80075E0C: sw          $t4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r12;
    // 0x80075E10: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075E14: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x80075E18: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x80075E1C: lw          $t5, -0x7AD8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7AD8);
    // 0x80075E20: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80075E24: lui         $t8, 0x380
    ctx->r24 = S32(0X380 << 16);
    // 0x80075E28: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80075E2C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80075E30: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80075E34: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80075E38: lbu         $t7, -0x65CF($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X65CF);
    // 0x80075E3C: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x80075E40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80075E44: beq         $t7, $zero, L_80075F64
    if (ctx->r15 == 0) {
        // 0x80075E48: lui         $t9, 0xD00
        ctx->r25 = S32(0XD00 << 16);
            goto L_80075F64;
    }
    // 0x80075E48: lui         $t9, 0xD00
    ctx->r25 = S32(0XD00 << 16);
    // 0x80075E4C: addiu       $t9, $t9, 0xB0
    ctx->r25 = ADD32(ctx->r25, 0XB0);
    // 0x80075E50: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80075E54: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075E58: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80075E5C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80075E60: lui         $t3, 0x103
    ctx->r11 = S32(0X103 << 16);
    // 0x80075E64: lui         $t4, 0xD00
    ctx->r12 = S32(0XD00 << 16);
    // 0x80075E68: addiu       $t4, $t4, 0x70
    ctx->r12 = ADD32(ctx->r12, 0X70);
    // 0x80075E6C: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x80075E70: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80075E74: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x80075E78: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075E7C: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x80075E80: ori         $t5, $t5, 0xE
    ctx->r13 = ctx->r13 | 0XE;
    // 0x80075E84: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80075E88: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80075E8C: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80075E90: lw          $t6, -0x7AF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7AF0);
    // 0x80075E94: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075E98: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80075E9C: lhu         $t7, 0x60($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X60);
    // 0x80075EA0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075EA4: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x80075EA8: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80075EAC: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x80075EB0: addiu       $t9, $t9, -0x5CF0
    ctx->r25 = ADD32(ctx->r25, -0X5CF0);
    // 0x80075EB4: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x80075EB8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80075EBC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80075EC0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80075EC4: lui         $t3, 0xBB00
    ctx->r11 = S32(0XBB00 << 16);
    // 0x80075EC8: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80075ECC: ori         $t4, $t4, 0x8000
    ctx->r12 = ctx->r12 | 0X8000;
    // 0x80075ED0: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x80075ED4: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x80075ED8: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x80075EDC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075EE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80075EE4: lui         $t6, 0x1F
    ctx->r14 = S32(0X1F << 16);
    // 0x80075EE8: ori         $t6, $t6, 0x3205
    ctx->r14 = ctx->r14 | 0X3205;
    // 0x80075EEC: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x80075EF0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80075EF4: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80075EF8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075EFC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80075F00: ori         $t2, $zero, 0xFFFE
    ctx->r10 = 0 | 0XFFFE;
    // 0x80075F04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80075F08: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x80075F0C: ori         $t7, $t7, 0x404
    ctx->r15 = ctx->r15 | 0X404;
    // 0x80075F10: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80075F14: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x80075F18: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075F1C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80075F20: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80075F24: ori         $t8, $t8, 0xC04
    ctx->r24 = ctx->r24 | 0XC04;
    // 0x80075F28: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80075F2C: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x80075F30: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075F34: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80075F38: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x80075F3C: ori         $t9, $t9, 0x1404
    ctx->r25 = ctx->r25 | 0X1404;
    // 0x80075F40: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80075F44: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x80075F48: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075F4C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80075F50: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x80075F54: ori         $t3, $t3, 0x1C04
    ctx->r11 = ctx->r11 | 0X1C04;
    // 0x80075F58: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80075F5C: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80075F60: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80075F64:
    // 0x80075F64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80075F68: lui         $t4, 0xD00
    ctx->r12 = S32(0XD00 << 16);
    // 0x80075F6C: addiu       $t4, $t4, 0x180
    ctx->r12 = ADD32(ctx->r12, 0X180);
    // 0x80075F70: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x80075F74: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80075F78: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075F7C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80075F80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80075F84: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x80075F88: lui         $t6, 0x35
    ctx->r14 = S32(0X35 << 16);
    // 0x80075F8C: ori         $t6, $t6, 0xC1A0
    ctx->r14 = ctx->r14 | 0XC1A0;
    // 0x80075F90: ori         $t5, $t5, 0x18
    ctx->r13 = ctx->r13 | 0X18;
    // 0x80075F94: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80075F98: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80075F9C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075FA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80075FA4: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80075FA8: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x80075FAC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80075FB0: sw          $a3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r7;
    // 0x80075FB4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075FB8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80075FBC: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80075FC0: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x80075FC4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80075FC8: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
    // 0x80075FCC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075FD0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80075FD4: jr          $ra
    // 0x80075FD8: nop

    return;
    // 0x80075FD8: nop

;}
RECOMP_FUNC void func_807C3A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3A3C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x807C3A40: lui         $t0, 0x807C
    ctx->r8 = S32(RELOC_HI16(907, 0X1300) << 16);
    // 0x807C3A44: addiu       $t0, $t0, 0x4660
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(907, 0X1300));
    // 0x807C3A48: beq         $v0, $zero, L_807C3A58
    if (ctx->r2 == 0) {
        // 0x807C3A4C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807C3A58;
    }
    // 0x807C3A4C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807C3A50: jr          $ra
    // 0x807C3A54: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    return;
    // 0x807C3A54: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
L_807C3A58:
    // 0x807C3A58: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x807C3A5C: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x807C3A60: slti        $at, $v0, 0x17
    ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
    // 0x807C3A64: bne         $at, $zero, L_807C3A74
    if (ctx->r1 != 0) {
        // 0x807C3A68: sw          $v0, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r2;
            goto L_807C3A74;
    }
    // 0x807C3A68: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x807C3A6C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x807C3A70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807C3A74:
    // 0x807C3A74: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x807C3A78: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x807C3A7C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x807C3A80: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // 0x807C3A84: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x807C3A88: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    // 0x807C3A8C: jr          $ra
    // 0x807C3A90: nop

    return;
    // 0x807C3A90: nop

;}
RECOMP_FUNC void func_807119DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807119DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807119E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807119E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x807119E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807119EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807119F0: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x807119F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x807119F8: jal         0x80048378
    // 0x807119FC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x807119FC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x80711A00: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80711A04: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80711A08: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
    // 0x80711A0C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80711A10: bne         $v1, $zero, L_80711A2C
    if (ctx->r3 != 0) {
        // 0x80711A14: nop
    
            goto L_80711A2C;
    }
    // 0x80711A14: nop

    // 0x80711A18: jal         0x80045A34
    // 0x80711A1C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80711A1C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80711A20: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80711A24: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80711A28: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
L_80711A2C:
    // 0x80711A2C: bne         $v1, $zero, L_80711A44
    if (ctx->r3 != 0) {
        // 0x80711A30: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80711A44;
    }
    // 0x80711A30: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80711A34: jal         0x800447C8
    // 0x80711A38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x80711A38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80711A3C: b           L_80711A50
    // 0x80711A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80711A50;
    // 0x80711A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80711A44:
    // 0x80711A44: jal         0x8071177C
    // 0x80711A48: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    func_8071177C(rdram, ctx);
        goto after_3;
    // 0x80711A48: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    after_3:
    // 0x80711A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80711A50:
    // 0x80711A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80711A54: jr          $ra
    // 0x80711A58: nop

    return;
    // 0x80711A58: nop

;}
RECOMP_FUNC void func_806F193C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F193C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F1940: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F1944: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F1948: jal         0x8004700C
    // 0x806F194C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806F194C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806F1950: beq         $v0, $zero, L_806F1A18
    if (ctx->r2 == 0) {
        // 0x806F1954: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_806F1A18;
    }
    // 0x806F1954: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806F1958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F195C: jal         0x80062684
    // 0x806F1960: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062684(rdram, ctx);
        goto after_1;
    // 0x806F1960: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_1:
    // 0x806F1964: jal         0x806F16CC
    // 0x806F1968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F16CC(rdram, ctx);
        goto after_2;
    // 0x806F1968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F196C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x806F1970: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x806F1974: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x806F1978: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x806F197C: bne         $s0, $t7, L_806F19D8
    if (ctx->r16 != ctx->r15) {
        // 0x806F1980: nop
    
            goto L_806F19D8;
    }
    // 0x806F1980: nop

    // 0x806F1984: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806F1988: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806F198C: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x806F1990: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806F1994: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F1998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F199C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F19A0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806F19A4: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x806F19A8: jal         0x806F1F14
    // 0x806F19AC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F1F14(rdram, ctx);
        goto after_3;
    // 0x806F19AC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
    // 0x806F19B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806F19B4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806F19B8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806F19BC: jal         0x80067BBC
    // 0x806F19C0: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x806F19C0: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    after_4:
    // 0x806F19C4: addiu       $a0, $zero, 0x216
    ctx->r4 = ADD32(0, 0X216);
    // 0x806F19C8: jal         0x80067818
    // 0x806F19CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806F19CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x806F19D0: b           L_806F1A1C
    // 0x806F19D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F1A1C;
    // 0x806F19D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F19D8:
    // 0x806F19D8: lw          $t9, -0x6C78($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6C78);
    // 0x806F19DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F19E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F19E4: bne         $t9, $zero, L_806F1A18
    if (ctx->r25 != 0) {
        // 0x806F19E8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_806F1A18;
    }
    // 0x806F19E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F19EC: jal         0x806F1F14
    // 0x806F19F0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F1F14(rdram, ctx);
        goto after_6;
    // 0x806F19F0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806F19F4: jal         0x8005FE48
    // 0x806F19F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_7;
    // 0x806F19F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806F19FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806F1A00: sb          $t0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r8;
    // 0x806F1A04: jal         0x806F1644
    // 0x806F1A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F1644(rdram, ctx);
        goto after_8;
    // 0x806F1A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x806F1A0C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806F1A10: nop

    // 0x806F1A14: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
L_806F1A18:
    // 0x806F1A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F1A1C:
    // 0x806F1A1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F1A20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F1A24: jr          $ra
    // 0x806F1A28: nop

    return;
    // 0x806F1A28: nop

;}
RECOMP_FUNC void func_807A6C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6C40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807A6C44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807A6C48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x807A6C4C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x807A6C50: lh          $t6, 0x184($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X184);
    // 0x807A6C54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A6C58: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x807A6C5C: beql        $at, $zero, L_807A6CE4
    if (ctx->r1 == 0) {
        // 0x807A6C60: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_807A6CE4;
    }
    goto skip_0;
    // 0x807A6C60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x807A6C64: jal         0x80047090
    // 0x807A6C68: addiu       $a0, $zero, 0x46E7
    ctx->r4 = ADD32(0, 0X46E7);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807A6C68: addiu       $a0, $zero, 0x46E7
    ctx->r4 = ADD32(0, 0X46E7);
    after_0:
    // 0x807A6C6C: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x807A6C70: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x807A6C74: lui         $at, 0x46E7
    ctx->r1 = S32(0X46E7 << 16);
    // 0x807A6C78: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807A6C7C: lw          $a3, 0x88($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X88);
    // 0x807A6C80: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    // 0x807A6C84: lui         $a0, 0x807A
    ctx->r4 = S32(RELOC_HI16(847, 0X18B0) << 16);
    // 0x807A6C88: addiu       $a0, $a0, 0x75B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(847, 0X18B0));
    // 0x807A6C8C: or          $a1, $v0, $at
    ctx->r5 = ctx->r2 | ctx->r1;
    // 0x807A6C90: jal         0x80046804
    // 0x807A6C94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x807A6C94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x807A6C98: beq         $v0, $zero, L_807A6CE0
    if (ctx->r2 == 0) {
        // 0x807A6C9C: lhu         $t8, 0x2A($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X2A);
            goto L_807A6CE0;
    }
    // 0x807A6C9C: lhu         $t8, 0x2A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2A);
    // 0x807A6CA0: lhu         $t0, 0xE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XE);
    // 0x807A6CA4: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x807A6CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A6CAC: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x807A6CB0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x807A6CB4: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x807A6CB8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x807A6CBC: jal         0x80047F9C
    // 0x807A6CC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807A6CC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x807A6CC4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x807A6CC8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x807A6CCC: jal         0x807A6A64
    // 0x807A6CD0: sb          $t3, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r11;
    func_807A6A64(rdram, ctx);
        goto after_3;
    // 0x807A6CD0: sb          $t3, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r11;
    after_3:
    // 0x807A6CD4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x807A6CD8: jal         0x807A6B0C
    // 0x807A6CDC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_807A6B0C(rdram, ctx);
        goto after_4;
    // 0x807A6CDC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
L_807A6CE0:
    // 0x807A6CE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_807A6CE4:
    // 0x807A6CE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x807A6CE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807A6CEC: jr          $ra
    // 0x807A6CF0: nop

    return;
    // 0x807A6CF0: nop

;}
RECOMP_FUNC void func_805AE624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE624: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE628: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE62C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE630: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE634: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE638: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE63C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE640: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE644: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE648: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE64C: jr          $ra
    // 0x805AE650: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE650: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807C32C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C32C0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807C32C4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807C32C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807C32CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807C32D0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807C32D4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x807C32D8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807C32DC: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(904, 0X400) << 16);
    // 0x807C32E0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807C32E4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807C32E8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807C32EC: lw          $t1, 0x3300($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(904, 0X400));
    // 0x807C32F0: jr          $ra
    // 0x807C32F4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807C32F4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x807C32F8: nop

    // 0x807C32FC: nop

;}
RECOMP_FUNC void func_800458EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800458EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800458F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800458F4: jal         0x800454EC
    // 0x800458F8: nop

    func_800454EC(rdram, ctx);
        goto after_0;
    // 0x800458F8: nop

    after_0:
    // 0x800458FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80045900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80045904: jr          $ra
    // 0x80045908: nop

    return;
    // 0x80045908: nop

;}
RECOMP_FUNC void func_80703840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80703840: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80703844: jr          $ra
    // 0x80703848: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80703848: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_8046DCAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046DCAC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8046DCB0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8046DCB4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8046DCB8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8046DCBC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8046DCC0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8046DCC4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8046DCC8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8046DCCC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8046DCD0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8046DCD4: jr          $ra
    // 0x8046DCD8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8046DCD8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806FDD0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FDD0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806FDD10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FDD14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806FDD18: jal         0x80057754
    // 0x806FDD1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80057754(rdram, ctx);
        goto after_0;
    // 0x806FDD1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806FDD20: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806FDD24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806FDD28: jal         0x806FD60C
    // 0x806FDD2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806FD60C(rdram, ctx);
        goto after_1;
    // 0x806FDD2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x806FDD30: jal         0x806FD854
    // 0x806FDD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD854(rdram, ctx);
        goto after_2;
    // 0x806FDD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806FDD38: jal         0x806FD7F8
    // 0x806FDD3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD7F8(rdram, ctx);
        goto after_3;
    // 0x806FDD3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806FDD40: jal         0x806FD720
    // 0x806FDD44: nop

    func_806FD720(rdram, ctx);
        goto after_4;
    // 0x806FDD44: nop

    after_4:
    // 0x806FDD48: bne         $v0, $zero, L_806FDD6C
    if (ctx->r2 != 0) {
        // 0x806FDD4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806FDD6C;
    }
    // 0x806FDD4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDD50: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x806FDD54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDD58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806FDD5C: jal         0x806FE468
    // 0x806FDD60: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    func_806FE468(rdram, ctx);
        goto after_5;
    // 0x806FDD60: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    after_5:
    // 0x806FDD64: b           L_806FDDCC
    // 0x806FDD68: nop

        goto L_806FDDCC;
    // 0x806FDD68: nop

L_806FDD6C:
    // 0x806FDD6C: jal         0x806FD8DC
    // 0x806FDD70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD8DC(rdram, ctx);
        goto after_6;
    // 0x806FDD70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x806FDD74: beq         $v0, $zero, L_806FDDCC
    if (ctx->r2 == 0) {
        // 0x806FDD78: nop
    
            goto L_806FDDCC;
    }
    // 0x806FDD78: nop

    // 0x806FDD7C: jal         0x806FD95C
    // 0x806FDD80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD95C(rdram, ctx);
        goto after_7;
    // 0x806FDD80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806FDD84: beq         $v0, $zero, L_806FDDCC
    if (ctx->r2 == 0) {
        // 0x806FDD88: nop
    
            goto L_806FDDCC;
    }
    // 0x806FDD88: nop

    // 0x806FDD8C: jal         0x800653D8
    // 0x806FDD90: nop

    func_800653D8(rdram, ctx);
        goto after_8;
    // 0x806FDD90: nop

    after_8:
    // 0x806FDD94: andi        $t7, $v0, 0x7F
    ctx->r15 = ctx->r2 & 0X7F;
    // 0x806FDD98: bne         $t7, $zero, L_806FDDCC
    if (ctx->r15 != 0) {
        // 0x806FDD9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806FDDCC;
    }
    // 0x806FDD9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDDA0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x806FDDA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDDA8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806FDDAC: jal         0x806FE468
    // 0x806FDDB0: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    func_806FE468(rdram, ctx);
        goto after_9;
    // 0x806FDDB0: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    after_9:
    // 0x806FDDB4: jal         0x806FD9C4
    // 0x806FDDB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD9C4(rdram, ctx);
        goto after_10;
    // 0x806FDDB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x806FDDBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDDC0: jal         0x806FD4FC
    // 0x806FDDC4: addiu       $a1, $zero, 0x93
    ctx->r5 = ADD32(0, 0X93);
    func_806FD4FC(rdram, ctx);
        goto after_11;
    // 0x806FDDC4: addiu       $a1, $zero, 0x93
    ctx->r5 = ADD32(0, 0X93);
    after_11:
    // 0x806FDDC8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_806FDDCC:
    // 0x806FDDCC: jal         0x806FDA5C
    // 0x806FDDD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FDA5C(rdram, ctx);
        goto after_12;
    // 0x806FDDD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x806FDDD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806FDDD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806FDDDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806FDDE0: jr          $ra
    // 0x806FDDE4: nop

    return;
    // 0x806FDDE4: nop

;}
RECOMP_FUNC void func_8078CF5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078CF5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078CF60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078CF64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8078CF68: jal         0x80045A34
    // 0x8078CF6C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8078CF6C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8078CF70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078CF74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8078CF78: bne         $v0, $zero, L_8078CF90
    if (ctx->r2 != 0) {
        // 0x8078CF7C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8078CF90;
    }
    // 0x8078CF7C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8078CF80: jal         0x800445A4
    // 0x8078CF84: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8078CF84: nop

    after_1:
    // 0x8078CF88: b           L_8078CFDC
    // 0x8078CF8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078CFDC;
    // 0x8078CF8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078CF90:
    // 0x8078CF90: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8078CF94: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(799, 0X180) << 16);
    // 0x8078CF98: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8078CF9C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8078CFA0: addiu       $t7, $t7, -0x2FE0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(799, 0X180));
    // 0x8078CFA4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8078CFA8: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8078CFAC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8078CFB0: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8078CFB4: sw          $t9, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r25;
    // 0x8078CFB8: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x8078CFBC: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(799, 0X188) << 16);
    // 0x8078CFC0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078CFC4: lw          $t1, -0x2FD8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(799, 0X188));
    // 0x8078CFC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078CFCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8078CFD0: jal         0x8078CFE8
    // 0x8078CFD4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    func_8078CFE8(rdram, ctx);
        goto after_2;
    // 0x8078CFD4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    after_2:
    // 0x8078CFD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078CFDC:
    // 0x8078CFDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078CFE0: jr          $ra
    // 0x8078CFE4: nop

    return;
    // 0x8078CFE4: nop

;}
RECOMP_FUNC void func_805A7594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A7598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A759C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A75A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805A75A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805A75A8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805A75AC: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x805A75B0: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x805A75B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805A75B8: bnel        $t6, $at, L_805A75D4
    if (ctx->r14 != ctx->r1) {
        // 0x805A75BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A75D4;
    }
    goto skip_0;
    // 0x805A75BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A75C0: jal         0x8003C358
    // 0x805A75C4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_8003C358(rdram, ctx);
        goto after_0;
    // 0x805A75C4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x805A75C8: jal         0x805A7504
    // 0x805A75CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805A7504(rdram, ctx);
        goto after_1;
    // 0x805A75CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805A75D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A75D4:
    // 0x805A75D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A75D8: jr          $ra
    // 0x805A75DC: nop

    return;
    // 0x805A75DC: nop

;}
RECOMP_FUNC void func_8073EC50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EC50: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8073EC54: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8073EC58: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8073EC5C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8073EC60: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8073EC64: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8073EC68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8073EC6C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8073EC70: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(748, 0X2384) << 16);
    // 0x8073EC74: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8073EC78: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8073EC7C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8073EC80: lw          $t1, 0xB74($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(748, 0X2384));
    // 0x8073EC84: jr          $ra
    // 0x8073EC88: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8073EC88: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_805812C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805812C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805812CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805812D0: jal         0x8058129C
    // 0x805812D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8058129C(rdram, ctx);
        goto after_0;
    // 0x805812D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805812D8: bne         $v0, $zero, L_805812F8
    if (ctx->r2 != 0) {
        // 0x805812DC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805812F8;
    }
    // 0x805812DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805812E0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805812E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805812E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805812EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805812F0: jal         0x805814C4
    // 0x805812F4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    func_805814C4(rdram, ctx);
        goto after_1;
    // 0x805812F4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    after_1:
L_805812F8:
    // 0x805812F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805812FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581300: jr          $ra
    // 0x80581304: nop

    return;
    // 0x80581304: nop

;}
RECOMP_FUNC void func_80039BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039BB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039BB4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039BB8: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    // 0x80039BBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039BC0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80039BC4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80039BC8: sw          $a0, 0x4270($at)
    MEM_W(0X4270, ctx->r1) = ctx->r4;
    // 0x80039BCC: addiu       $a1, $a1, 0x6AB0
    ctx->r5 = ADD32(ctx->r5, 0X6AB0);
    // 0x80039BD0: jal         0x8004667C
    // 0x80039BD4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80039BD4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80039BD8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039BDC: addiu       $a0, $a0, 0x6AB0
    ctx->r4 = ADD32(ctx->r4, 0X6AB0);
    // 0x80039BE0: jal         0x80039ABC
    // 0x80039BE4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80039ABC(rdram, ctx);
        goto after_1;
    // 0x80039BE4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80039BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039BEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039BF0: jr          $ra
    // 0x80039BF4: nop

    return;
    // 0x80039BF4: nop

;}
RECOMP_FUNC void func_8058129C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058129C: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x805812A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805812A4: beq         $v1, $zero, L_805812C0
    if (ctx->r3 == 0) {
        // 0x805812A8: nop
    
            goto L_805812C0;
    }
    // 0x805812A8: nop

    // 0x805812AC: lw          $a0, 0x1F4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1F4);
    // 0x805812B0: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x805812B4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x805812B8: jr          $ra
    // 0x805812BC: lw          $v0, 0x6EF4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6EF4);
    return;
    // 0x805812BC: lw          $v0, 0x6EF4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6EF4);
L_805812C0:
    // 0x805812C0: jr          $ra
    // 0x805812C4: nop

    return;
    // 0x805812C4: nop

;}
RECOMP_FUNC void func_8002CE5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CE5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CE60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CE64: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002CE68: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002CE6C: addiu       $t6, $t6, 0x1F6C
    ctx->r14 = ADD32(ctx->r14, 0X1F6C);
    // 0x8002CE70: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8002CE74: sw          $zero, 0x14($t7)
    MEM_W(0X14, ctx->r15) = 0;
    // 0x8002CE78: jal         0x8002AE54
    // 0x8002CE7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002AE54(rdram, ctx);
        goto after_0;
    // 0x8002CE7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002CE80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002CE84: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8002CE88: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x8002CE8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CE90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002CE94: jr          $ra
    // 0x8002CE98: nop

    return;
    // 0x8002CE98: nop

;}
RECOMP_FUNC void func_804CD0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CD0A0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x804CD0A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CD0A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CD0AC: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x804CD0B0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804CD0B4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x804CD0B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804CD0BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804CD0C0: jal         0x8004921C
    // 0x804CD0C4: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804CD0C4: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    after_0:
    // 0x804CD0C8: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x804CD0CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CD0D0: jal         0x8004921C
    // 0x804CD0D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804CD0D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804CD0D8: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x804CD0DC: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x804CD0E0: lbu         $t4, 0x145($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X145);
    // 0x804CD0E4: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804CD0E8: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x804CD0EC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x804CD0F0: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x804CD0F4: lw          $t6, 0x80($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X80);
    // 0x804CD0F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804CD0FC: mflo        $t3
    ctx->r11 = lo;
    // 0x804CD100: nop

    // 0x804CD104: nop

    // 0x804CD108: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804CD10C: mflo        $t5
    ctx->r13 = lo;
    // 0x804CD110: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x804CD114: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x804CD118: lw          $t8, 0x88($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X88);
    // 0x804CD11C: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x804CD120: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x804CD124: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804CD128: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x804CD12C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x804CD130: srl         $t2, $t2, 2
    ctx->r10 = S32(U32(ctx->r10) >> 2);
    // 0x804CD134: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x804CD138: jal         0x80077338
    // 0x804CD13C: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x804CD13C: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    after_2:
    // 0x804CD140: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x804CD144: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804CD148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804CD14C: jal         0x8007711C
    // 0x804CD150: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x804CD150: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    after_3:
    // 0x804CD154: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x804CD158: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x804CD15C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x804CD160: addiu       $t3, $t9, 0x8
    ctx->r11 = ADD32(ctx->r25, 0X8);
    // 0x804CD164: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x804CD168: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x804CD16C: lui         $t4, 0xFD50
    ctx->r12 = S32(0XFD50 << 16);
    // 0x804CD170: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x804CD174: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x804CD178: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x804CD17C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CD180: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x804CD184: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x804CD188: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x804CD18C: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x804CD190: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804CD194: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x804CD198: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x804CD19C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x804CD1A0: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x804CD1A4: lui         $t9, 0x711
    ctx->r25 = S32(0X711 << 16);
    // 0x804CD1A8: ori         $t9, $t9, 0xF2AB
    ctx->r25 = ctx->r25 | 0XF2AB;
    // 0x804CD1AC: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x804CD1B0: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x804CD1B4: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x804CD1B8: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x804CD1BC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x804CD1C0: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804CD1C4: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x804CD1C8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804CD1CC: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x804CD1D0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x804CD1D4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x804CD1D8: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x804CD1DC: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x804CD1E0: ori         $t8, $t8, 0x600
    ctx->r24 = ctx->r24 | 0X600;
    // 0x804CD1E4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x804CD1E8: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x804CD1EC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x804CD1F0: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x804CD1F4: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x804CD1F8: lui         $t5, 0x5
    ctx->r13 = S32(0X5 << 16);
    // 0x804CD1FC: ori         $t5, $t5, 0xC05C
    ctx->r13 = ctx->r13 | 0XC05C;
    // 0x804CD200: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804CD204: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x804CD208: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x804CD20C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x804CD210: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x804CD214: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x804CD218: addiu       $t3, $t9, 0x8
    ctx->r11 = ADD32(ctx->r25, 0X8);
    // 0x804CD21C: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x804CD220: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x804CD224: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x804CD228: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x804CD22C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x804CD230: lw          $t9, 0x14($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X14);
    // 0x804CD234: jalr        $t9
    // 0x804CD238: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x804CD238: nop

    after_4:
    // 0x804CD23C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x804CD240: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x804CD244: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804CD248: beq         $t2, $zero, L_804CD370
    if (ctx->r10 == 0) {
        // 0x804CD24C: andi        $v0, $t2, 0x3
        ctx->r2 = ctx->r10 & 0X3;
            goto L_804CD370;
    }
    // 0x804CD24C: andi        $v0, $t2, 0x3
    ctx->r2 = ctx->r10 & 0X3;
    // 0x804CD250: beq         $v0, $zero, L_804CD2A4
    if (ctx->r2 == 0) {
        // 0x804CD254: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_804CD2A4;
    }
    // 0x804CD254: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x804CD258: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(237, 0X1B40) << 16);
    // 0x804CD25C: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    // 0x804CD260: ori         $a1, $a1, 0x40FF
    ctx->r5 = ctx->r5 | 0X40FF;
    // 0x804CD264: addiu       $a0, $a0, -0x2050
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(237, 0X1B40));
    // 0x804CD268: lui         $a2, 0x600
    ctx->r6 = S32(0X600 << 16);
L_804CD26C:
    // 0x804CD26C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x804CD270: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x804CD274: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804CD278: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x804CD27C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x804CD280: sw          $a1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r5;
    // 0x804CD284: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x804CD288: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x804CD28C: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x804CD290: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x804CD294: sw          $a0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r4;
    // 0x804CD298: bne         $t1, $a3, L_804CD26C
    if (ctx->r9 != ctx->r7) {
        // 0x804CD29C: sw          $a2, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r6;
            goto L_804CD26C;
    }
    // 0x804CD29C: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x804CD2A0: beq         $a3, $t2, L_804CD370
    if (ctx->r7 == ctx->r10) {
        // 0x804CD2A4: lui         $a1, 0x400
        ctx->r5 = S32(0X400 << 16);
            goto L_804CD370;
    }
L_804CD2A4:
    // 0x804CD2A4: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    // 0x804CD2A8: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(237, 0X1B40) << 16);
    // 0x804CD2AC: addiu       $a0, $a0, -0x2050
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(237, 0X1B40));
    // 0x804CD2B0: ori         $a1, $a1, 0x40FF
    ctx->r5 = ctx->r5 | 0X40FF;
    // 0x804CD2B4: lui         $a2, 0x600
    ctx->r6 = S32(0X600 << 16);
L_804CD2B8:
    // 0x804CD2B8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x804CD2BC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x804CD2C0: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x804CD2C4: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x804CD2C8: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x804CD2CC: sw          $a1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r5;
    // 0x804CD2D0: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x804CD2D4: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x804CD2D8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x804CD2DC: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x804CD2E0: sw          $a0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r4;
    // 0x804CD2E4: sw          $a2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r6;
    // 0x804CD2E8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x804CD2EC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x804CD2F0: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x804CD2F4: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x804CD2F8: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x804CD2FC: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x804CD300: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x804CD304: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x804CD308: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x804CD30C: sw          $a0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r4;
    // 0x804CD310: sw          $a2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r6;
    // 0x804CD314: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x804CD318: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x804CD31C: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x804CD320: sw          $t0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r8;
    // 0x804CD324: sw          $a1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r5;
    // 0x804CD328: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x804CD32C: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x804CD330: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804CD334: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x804CD338: sw          $a0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r4;
    // 0x804CD33C: sw          $a2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r6;
    // 0x804CD340: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x804CD344: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x804CD348: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x804CD34C: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x804CD350: sw          $a1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r5;
    // 0x804CD354: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x804CD358: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x804CD35C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x804CD360: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x804CD364: sw          $a0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r4;
    // 0x804CD368: bne         $a3, $t2, L_804CD2B8
    if (ctx->r7 != ctx->r10) {
        // 0x804CD36C: sw          $a2, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->r6;
            goto L_804CD2B8;
    }
    // 0x804CD36C: sw          $a2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r6;
L_804CD370:
    // 0x804CD370: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x804CD374: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x804CD378: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x804CD37C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804CD380: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CD384: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x804CD388: jr          $ra
    // 0x804CD38C: nop

    return;
    // 0x804CD38C: nop

;}
RECOMP_FUNC void func_80433B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80433B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80433B84: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80433B88: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80433B8C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80433B90: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(71, 0X2920) << 16);
    // 0x80433B94: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80433B98: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80433B9C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80433BA0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80433BA4: lw          $t8, 0x63D0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(71, 0X2920));
    // 0x80433BA8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80433BAC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80433BB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80433BB4: jal         0x80048490
    // 0x80433BB8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80433BB8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80433BBC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80433BC0: jal         0x80048378
    // 0x80433BC4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80433BC4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80433BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80433BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80433BD0: jr          $ra
    // 0x80433BD4: nop

    return;
    // 0x80433BD4: nop

;}
RECOMP_FUNC void func_804A3A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A3A10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804A3A14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A3A18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804A3A1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A3A20: jal         0x80046E88
    // 0x804A3A24: addiu       $a0, $zero, 0x41FC
    ctx->r4 = ADD32(0, 0X41FC);
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x804A3A24: addiu       $a0, $zero, 0x41FC
    ctx->r4 = ADD32(0, 0X41FC);
    after_0:
    // 0x804A3A28: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x804A3A2C: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x804A3A30: lui         $t6, 0x804A
    ctx->r14 = S32(RELOC_HI16(176, 0X1020) << 16);
    // 0x804A3A34: addiu       $t6, $t6, 0x4A20
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(176, 0X1020));
    // 0x804A3A38: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x804A3A3C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804A3A40: sw          $zero, 0x60($v1)
    MEM_W(0X60, ctx->r3) = 0;
    // 0x804A3A44: sw          $zero, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = 0;
    // 0x804A3A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A3A4C: jal         0x80045A34
    // 0x804A3A50: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x804A3A50: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x804A3A54: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804A3A58: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x804A3A5C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x804A3A60: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A3A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A3A68: lw          $t9, 0x188($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X188);
    // 0x804A3A6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804A3A70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804A3A74: jal         0x804A491C
    // 0x804A3A78: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    func_804A491C(rdram, ctx);
        goto after_2;
    // 0x804A3A78: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    after_2:
    // 0x804A3A7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804A3A80: sb          $v0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r2;
    // 0x804A3A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804A3A88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804A3A8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A3A90: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x804A3A94: jr          $ra
    // 0x804A3A98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x804A3A98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80029044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002904C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80029050: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80029054: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80029058: jal         0x80028A78
    // 0x8002905C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80028A78(rdram, ctx);
        goto after_0;
    // 0x8002905C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80029060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80029064: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80029068: jal         0x80028FF8
    // 0x8002906C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_80028FF8(rdram, ctx);
        goto after_1;
    // 0x8002906C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80029070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029078: jr          $ra
    // 0x8002907C: nop

    return;
    // 0x8002907C: nop

;}
RECOMP_FUNC void func_8042D090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042D090: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8042D094: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042D098: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042D09C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042D0A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8042D0A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042D0A8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8042D0AC: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x8042D0B0: beq         $v0, $at, L_8042D1B4
    if (ctx->r2 == ctx->r1) {
        // 0x8042D0B4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8042D1B4;
    }
    // 0x8042D0B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8042D0B8: beql        $v0, $at, L_8042D1B8
    if (ctx->r2 == ctx->r1) {
        // 0x8042D0BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8042D1B8;
    }
    goto skip_0;
    // 0x8042D0BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8042D0C0: lw          $t7, 0x1E4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E4);
    // 0x8042D0C4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8042D0C8: blez        $t8, L_8042D118
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8042D0CC: sw          $t8, 0x1E4($a0)
        MEM_W(0X1E4, ctx->r4) = ctx->r24;
            goto L_8042D118;
    }
    // 0x8042D0CC: sw          $t8, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r24;
    // 0x8042D0D0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8042D0D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042D0D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042D0DC: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8042D0E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8042D0E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8042D0E8: bne         $t1, $at, L_8042D108
    if (ctx->r9 != ctx->r1) {
        // 0x8042D0EC: nop
    
            goto L_8042D108;
    }
    // 0x8042D0EC: nop

    // 0x8042D0F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042D0F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8042D0F8: jal         0x8042D50C
    // 0x8042D0FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8042D50C(rdram, ctx);
        goto after_0;
    // 0x8042D0FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8042D100: b           L_8042D17C
    // 0x8042D104: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
        goto L_8042D17C;
    // 0x8042D104: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_8042D108:
    // 0x8042D108: jal         0x8042D50C
    // 0x8042D10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042D50C(rdram, ctx);
        goto after_1;
    // 0x8042D10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8042D110: b           L_8042D17C
    // 0x8042D114: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
        goto L_8042D17C;
    // 0x8042D114: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_8042D118:
    // 0x8042D118: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8042D11C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042D120: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8042D124: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8042D128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042D12C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042D130: bne         $t3, $at, L_8042D150
    if (ctx->r11 != ctx->r1) {
        // 0x8042D134: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_8042D150;
    }
    // 0x8042D134: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8042D138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042D13C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042D140: jal         0x8042D50C
    // 0x8042D144: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8042D50C(rdram, ctx);
        goto after_2;
    // 0x8042D144: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_2:
    // 0x8042D148: b           L_8042D15C
    // 0x8042D14C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
        goto L_8042D15C;
    // 0x8042D14C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
L_8042D150:
    // 0x8042D150: jal         0x8042D50C
    // 0x8042D154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042D50C(rdram, ctx);
        goto after_3;
    // 0x8042D154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8042D158: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
L_8042D15C:
    // 0x8042D15C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042D160: jal         0x8006CB1C
    // 0x8042D164: nop

    func_8006CB1C(rdram, ctx);
        goto after_4;
    // 0x8042D164: nop

    after_4:
    // 0x8042D168: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8042D16C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042D170: jal         0x8006CB2C
    // 0x8042D174: nop

    func_8006CB2C(rdram, ctx);
        goto after_5;
    // 0x8042D174: nop

    after_5:
    // 0x8042D178: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_8042D17C:
    // 0x8042D17C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8042D180: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042D184: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8042D188: swc1        $f4, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f4.u32l;
    // 0x8042D18C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8042D190: jal         0x80067BBC
    // 0x8042D194: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x8042D194: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_6:
    // 0x8042D198: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8042D19C: addiu       $a0, $zero, 0x211
    ctx->r4 = ADD32(0, 0X211);
    // 0x8042D1A0: jal         0x80067818
    // 0x8042D1A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8042D1A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8042D1A8: addiu       $a0, $zero, 0x279
    ctx->r4 = ADD32(0, 0X279);
    // 0x8042D1AC: jal         0x80067818
    // 0x8042D1B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x8042D1B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
L_8042D1B4:
    // 0x8042D1B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042D1B8:
    // 0x8042D1B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042D1BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8042D1C0: jr          $ra
    // 0x8042D1C4: nop

    return;
    // 0x8042D1C4: nop

;}
RECOMP_FUNC void func_80449CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449CB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80449CBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80449CC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80449CC4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80449CC8: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80449CCC: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80449CD0: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X133A8) << 16);
    // 0x80449CD4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80449CD8: lw          $v1, 0x6CC0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CC0);
    // 0x80449CDC: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x80449CE0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80449CE4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80449CE8: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80449CEC: lw          $t0, 0x7788($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X133A8));
    // 0x80449CF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80449CF4: beql        $t0, $zero, L_80449D08
    if (ctx->r8 == 0) {
        // 0x80449CF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80449D08;
    }
    goto skip_0;
    // 0x80449CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80449CFC: jalr        $t0
    // 0x80449D00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x80449D00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80449D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80449D08:
    // 0x80449D08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80449D0C: jr          $ra
    // 0x80449D10: nop

    return;
    // 0x80449D10: nop

;}
RECOMP_FUNC void func_806D07F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D07F8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D07FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806D0800: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x806D0804: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806D0808: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x806D080C: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x806D0810: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x806D0814: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x806D0818: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x806D081C: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x806D0820: jr          $ra
    // 0x806D0824: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x806D0824: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_8076DE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076DE4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8076DE50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076DE54: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8076DE58: lui         $t6, 0x8077
    ctx->r14 = S32(RELOC_HI16(766, 0X1C68) << 16);
    // 0x8076DE5C: addiu       $t6, $t6, -0x1BA8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(766, 0X1C68));
    // 0x8076DE60: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8076DE64: jal         0x8005FDC4
    // 0x8076DE68: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x8076DE68: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    after_0:
    // 0x8076DE6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8076DE70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8076DE74: jr          $ra
    // 0x8076DE78: nop

    return;
    // 0x8076DE78: nop

;}
RECOMP_FUNC void func_80058E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058E70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058E78: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80058E7C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80058E80: jal         0x80058D94
    // 0x80058E84: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_80058D94(rdram, ctx);
        goto after_0;
    // 0x80058E84: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x80058E88: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80058E8C: jal         0x80081C64
    // 0x80058E90: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x80058E90: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80058E94: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80058E98: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80058E9C: lw          $v0, 0x3F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X3F4);
    // 0x80058EA0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80058EA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80058EA8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80058EAC: lw          $t6, 0x478($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X478);
    // 0x80058EB0: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80058EB4: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80058EB8: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80058EBC: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80058EC0: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80058EC4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80058EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058ECC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80058ED0: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80058ED4: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80058ED8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80058EDC: div.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80058EE0: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80058EE4: jr          $ra
    // 0x80058EE8: nop

    return;
    // 0x80058EE8: nop

;}
RECOMP_FUNC void func_8000AA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AA20: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8000AA24: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8000AA28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000AA2C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8000AA30: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8000AA34: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8000AA38: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000AA3C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8000AA40: jr          $ra
    // 0x8000AA44: lb          $v0, 0x7894($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7894);
    return;
    // 0x8000AA44: lb          $v0, 0x7894($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7894);
;}
RECOMP_FUNC void func_8004D470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D470: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004D474: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8004D478: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8004D47C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004D480: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004D484: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004D488: addu        $a2, $t7, $v1
    ctx->r6 = ADD32(ctx->r15, ctx->r3);
    // 0x8004D48C: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8004D490: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8004D494: bne         $t9, $zero, L_8004D4B8
    if (ctx->r25 != 0) {
        // 0x8004D498: nop
    
            goto L_8004D4B8;
    }
    // 0x8004D498: nop

    // 0x8004D49C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004D4A0: nop

    // 0x8004D4A4: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x8004D4A8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004D4AC: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x8004D4B0: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8004D4B4: sb          $zero, 0x14($t2)
    MEM_B(0X14, ctx->r10) = 0;
L_8004D4B8:
    // 0x8004D4B8: jr          $ra
    // 0x8004D4BC: nop

    return;
    // 0x8004D4BC: nop

;}
RECOMP_FUNC void func_807AD348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD348: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x807AD34C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x807AD350: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x807AD354: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x807AD358: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
    // 0x807AD35C: jr          $ra
    // 0x807AD360: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x807AD360: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8004A9C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A9C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004A9C8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8004A9CC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8004A9D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A9D4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8004A9D8: beq         $a2, $zero, L_8004AB50
    if (ctx->r6 == 0) {
        // 0x8004A9DC: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_8004AB50;
    }
    // 0x8004A9DC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8004A9E0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004A9E4: beq         $a2, $at, L_8004AB50
    if (ctx->r6 == ctx->r1) {
        // 0x8004A9E8: sh          $a2, 0x42($sp)
        MEM_H(0X42, ctx->r29) = ctx->r6;
            goto L_8004AB50;
    }
    // 0x8004A9E8: sh          $a2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r6;
    // 0x8004A9EC: lbu         $v1, 0x42($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X42);
    // 0x8004A9F0: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004A9F4: andi        $v0, $v1, 0xF8
    ctx->r2 = ctx->r3 & 0XF8;
    // 0x8004A9F8: beq         $v0, $at, L_8004AB50
    if (ctx->r2 == ctx->r1) {
        // 0x8004A9FC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004AB50;
    }
    // 0x8004A9FC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004AA00: beq         $v0, $at, L_8004AB50
    if (ctx->r2 == ctx->r1) {
        // 0x8004AA04: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_8004AB50;
    }
    // 0x8004AA04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004AA08: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    // 0x8004AA0C: lwc1        $f4, 0x8B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X8B0);
    // 0x8004AA10: lbu         $a2, 0x12($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X12);
    // 0x8004AA14: srl         $a3, $v1, 3
    ctx->r7 = S32(U32(ctx->r3) >> 3);
    // 0x8004AA18: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8004AA1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004AA20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004AA24: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    // 0x8004AA28: bc1fl       L_8004AA38
    if (!c1cs) {
        // 0x8004AA2C: sltiu       $a1, $v0, 0x1
        ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
            goto L_8004AA38;
    }
    goto skip_0;
    // 0x8004AA2C: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    skip_0:
    // 0x8004AA30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004AA34: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
L_8004AA38:
    // 0x8004AA38: beq         $a1, $zero, L_8004AA60
    if (ctx->r5 == 0) {
        // 0x8004AA3C: nop
    
            goto L_8004AA60;
    }
    // 0x8004AA3C: nop

    // 0x8004AA40: lwc1        $f6, 0x8B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X8B4);
    // 0x8004AA44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004AA48: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x8004AA4C: nop

    // 0x8004AA50: bc1fl       L_8004AA60
    if (!c1cs) {
        // 0x8004AA54: sltiu       $a1, $a1, 0x1
        ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
            goto L_8004AA60;
    }
    goto skip_1;
    // 0x8004AA54: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    skip_1:
    // 0x8004AA58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004AA5C: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
L_8004AA60:
    // 0x8004AA60: beq         $a1, $zero, L_8004AA74
    if (ctx->r5 == 0) {
        // 0x8004AA64: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004AA74;
    }
    // 0x8004AA64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004AA68: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004AA6C: b           L_8004AAA0
    // 0x8004AA70: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
        goto L_8004AAA0;
    // 0x8004AA70: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_8004AA74:
    // 0x8004AA74: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8004AA78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8004AA7C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8004AA80: jal         0x80066DE4
    // 0x8004AA84: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8004AA84: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8004AA88: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8004AA8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8004AA90: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8004AA94: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8004AA98: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8004AA9C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_8004AAA0:
    // 0x8004AAA0: sll         $t9, $a2, 4
    ctx->r25 = S32(ctx->r6 << 4);
    // 0x8004AAA4: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x8004AAA8: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8004AAAC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8004AAB0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004AAB4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8004AAB8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8004AABC: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x8004AAC0: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8004AAC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8004AAC8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8004AACC: lwc1        $f10, 0xD64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XD64);
    // 0x8004AAD0: lwc1        $f8, 0x100($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X100);
    // 0x8004AAD4: sll         $t4, $a2, 4
    ctx->r12 = S32(ctx->r6 << 4);
    // 0x8004AAD8: addu        $t4, $t4, $a2
    ctx->r12 = ADD32(ctx->r12, ctx->r6);
    // 0x8004AADC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004AAE0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8004AAE4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8004AAE8: lwc1        $f18, 0x104($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X104);
    // 0x8004AAEC: lwc1        $f6, 0x108($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X108);
    // 0x8004AAF0: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x8004AAF4: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8004AAF8: swc1        $f16, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f16.u32l;
    // 0x8004AAFC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8004AB00: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004AB04: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8004AB08: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8004AB0C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8004AB10: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8004AB14: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004AB18: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8004AB1C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8004AB20: lwc1        $f0, 0xE74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XE74);
    // 0x8004AB24: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8004AB28: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8004AB2C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004AB30: lwc1        $f10, 0x10C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x8004AB34: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004AB38: swc1        $f4, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->f4.u32l;
    // 0x8004AB3C: swc1        $f8, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->f8.u32l;
    // 0x8004AB40: lwc1        $f16, 0xF84($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XF84);
    // 0x8004AB44: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004AB48: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8004AB4C: swc1        $f4, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f4.u32l;
L_8004AB50:
    // 0x8004AB50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004AB54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8004AB58: jr          $ra
    // 0x8004AB5C: nop

    return;
    // 0x8004AB5C: nop

;}
RECOMP_FUNC void func_800353E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800353E8: lw          $t6, 0x38($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X38);
    // 0x800353EC: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x800353F0: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x800353F4: slti        $at, $v0, -0x78
    ctx->r1 = SIGNED(ctx->r2) < -0X78 ? 1 : 0;
    // 0x800353F8: bne         $at, $zero, L_80035448
    if (ctx->r1 != 0) {
        // 0x800353FC: slti        $at, $v0, 0x30
        ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
            goto L_80035448;
    }
    // 0x800353FC: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x80035400: beq         $at, $zero, L_80035448
    if (ctx->r1 == 0) {
        // 0x80035404: nop
    
            goto L_80035448;
    }
    // 0x80035404: nop

    // 0x80035408: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003540C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80035410: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80035414: nop

    // 0x80035418: bc1f        L_80035448
    if (!c1cs) {
        // 0x8003541C: nop
    
            goto L_80035448;
    }
    // 0x8003541C: nop

    // 0x80035420: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x80035424: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80035428: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8003542C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80035430: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x80035434: bne         $t0, $at, L_80035448
    if (ctx->r8 != ctx->r1) {
        // 0x80035438: nop
    
            goto L_80035448;
    }
    // 0x80035438: nop

    // 0x8003543C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80035440: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x80035444: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
L_80035448:
    // 0x80035448: jr          $ra
    // 0x8003544C: nop

    return;
    // 0x8003544C: nop

;}
RECOMP_FUNC void func_80535B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80535B08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80535B0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80535B10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80535B14: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80535B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80535B1C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80535B20: lui         $a2, 0x8053
    ctx->r6 = S32(RELOC_HI16(351, 0X1270) << 16);
    // 0x80535B24: lui         $a1, 0x8053
    ctx->r5 = S32(RELOC_HI16(351, 0X128C) << 16);
    // 0x80535B28: addiu       $a1, $a1, 0x6B1C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(351, 0X128C));
    // 0x80535B2C: addiu       $a2, $a2, 0x6B00
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(351, 0X1270));
    // 0x80535B30: jal         0x80535958
    // 0x80535B34: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_80535958(rdram, ctx);
        goto after_0;
    // 0x80535B34: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x80535B38: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80535B3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535B40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80535B44: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80535B48: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80535B4C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80535B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80535B54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80535B58: jr          $ra
    // 0x80535B5C: nop

    return;
    // 0x80535B5C: nop

;}
RECOMP_FUNC void func_804625D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804625D4: lui         $at, 0xC294
    ctx->r1 = S32(0XC294 << 16);
    // 0x804625D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804625DC: lwc1        $f6, 0x7C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x804625E0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804625E4: jr          $ra
    // 0x804625E8: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x804625E8: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_807C6C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6C00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807C6C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C6C08: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C6C0C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x807C6C10: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x807C6C14: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x807C6C18: lw          $t7, 0x478($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X478);
    // 0x807C6C1C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x807C6C20: lw          $a3, 0x16C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X16C);
    // 0x807C6C24: lwc1        $f4, 0x30($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X30);
    // 0x807C6C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807C6C2C: lbu         $v0, 0x10($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X10);
    // 0x807C6C30: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x807C6C34: lw          $t8, 0x478($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X478);
    // 0x807C6C38: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x807C6C3C: sltiu       $at, $v0, 0xFF
    ctx->r1 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x807C6C40: lwc1        $f6, 0x34($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X34);
    // 0x807C6C44: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807C6C48: bne         $at, $zero, L_807C6C70
    if (ctx->r1 != 0) {
        // 0x807C6C4C: swc1        $f6, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
            goto L_807C6C70;
    }
    // 0x807C6C4C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x807C6C50: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x807C6C54: sw          $t9, 0xF60($t0)
    MEM_W(0XF60, ctx->r8) = ctx->r25;
    // 0x807C6C58: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x807C6C5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807C6C60: jal         0x8006E0FC
    // 0x807C6C64: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x807C6C64: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x807C6C68: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807C6C6C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_807C6C70:
    // 0x807C6C70: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
    // 0x807C6C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C6C78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807C6C7C: jr          $ra
    // 0x807C6C80: nop

    return;
    // 0x807C6C80: nop

;}
RECOMP_FUNC void func_8073FD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073FD9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073FDA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073FDA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073FDA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8073FDAC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8073FDB0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8073FDB4: jal         0x80047090
    // 0x8073FDB8: addiu       $a0, $zero, 0x4707
    ctx->r4 = ADD32(0, 0X4707);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8073FDB8: addiu       $a0, $zero, 0x4707
    ctx->r4 = ADD32(0, 0X4707);
    after_0:
    // 0x8073FDBC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8073FDC0: bne         $v0, $at, L_8073FDD0
    if (ctx->r2 != ctx->r1) {
        // 0x8073FDC4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8073FDD0;
    }
    // 0x8073FDC4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8073FDC8: b           L_8073FE20
    // 0x8073FDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8073FE20;
    // 0x8073FDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073FDD0:
    // 0x8073FDD0: lui         $at, 0x4707
    ctx->r1 = S32(0X4707 << 16);
    // 0x8073FDD4: ori         $at, $at, 0x400
    ctx->r1 = ctx->r1 | 0X400;
    // 0x8073FDD8: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x8073FDDC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8073FDE0: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8073FDE4: jal         0x8004613C
    // 0x8073FDE8: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8073FDE8: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x8073FDEC: bne         $v0, $zero, L_8073FDFC
    if (ctx->r2 != 0) {
        // 0x8073FDF0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8073FDFC;
    }
    // 0x8073FDF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8073FDF4: b           L_8073FE20
    // 0x8073FDF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8073FE20;
    // 0x8073FDF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073FDFC:
    // 0x8073FDFC: jal         0x80044194
    // 0x8073FE00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x8073FE00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8073FE04: jal         0x8073FC9C
    // 0x8073FE08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073FC9C(rdram, ctx);
        goto after_3;
    // 0x8073FE08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8073FE0C: beq         $s0, $zero, L_8073FE1C
    if (ctx->r16 == 0) {
        // 0x8073FE10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8073FE1C;
    }
    // 0x8073FE10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073FE14: jal         0x8073F6D8
    // 0x8073FE18: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8073F6D8(rdram, ctx);
        goto after_4;
    // 0x8073FE18: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
L_8073FE1C:
    // 0x8073FE1C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8073FE20:
    // 0x8073FE20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073FE24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073FE28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073FE2C: jr          $ra
    // 0x8073FE30: nop

    return;
    // 0x8073FE30: nop

    // 0x8073FE34: nop

    // 0x8073FE38: nop

    // 0x8073FE3C: nop

;}
RECOMP_FUNC void func_8066B8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B8C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066B8CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066B8D0: jal         0x8066B7C0
    // 0x8066B8D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8066B7C0(rdram, ctx);
        goto after_0;
    // 0x8066B8D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066B8D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066B8DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B8E0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8066B8E4: jal         0x8066B970
    // 0x8066B8E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8066B970(rdram, ctx);
        goto after_1;
    // 0x8066B8E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8066B8EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066B8F0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8066B8F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8066B8F8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B8FC: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8066B900: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8066B904: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8066B908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066B90C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066B910: jr          $ra
    // 0x8066B914: nop

    return;
    // 0x8066B914: nop

;}
RECOMP_FUNC void func_8002ECA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ECA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002ECAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002ECB0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002ECB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002ECB8: jal         0x8002DBA8
    // 0x8002ECBC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8002DBA8(rdram, ctx);
        goto after_0;
    // 0x8002ECBC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002ECC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002ECC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002ECC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002ECCC: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x8002ECD0: lwc1        $f6, -0x44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X44);
    // 0x8002ECD4: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    // 0x8002ECD8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002ECDC: sb          $zero, 0x21($t7)
    MEM_B(0X21, ctx->r15) = 0;
    // 0x8002ECE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002ECE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002ECE8: jr          $ra
    // 0x8002ECEC: nop

    return;
    // 0x8002ECEC: nop

;}
RECOMP_FUNC void func_80451B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80451B1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80451B20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80451B24: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80451B28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80451B2C: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80451B30: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140DC) << 16);
    // 0x80451B34: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80451B38: nop

    // 0x80451B3C: bc1f        L_80451B68
    if (!c1cs) {
        // 0x80451B40: nop
    
            goto L_80451B68;
    }
    // 0x80451B40: nop

    // 0x80451B44: jal         0x80451AC8
    // 0x80451B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80451AC8(rdram, ctx);
        goto after_0;
    // 0x80451B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80451B4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80451B50: jal         0x80450B18
    // 0x80451B54: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80450B18(rdram, ctx);
        goto after_1;
    // 0x80451B54: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80451B58: jal         0x80445A34
    // 0x80451B5C: nop

    func_80445A34(rdram, ctx);
        goto after_2;
    // 0x80451B5C: nop

    after_2:
    // 0x80451B60: b           L_80451C70
    // 0x80451B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80451C70;
    // 0x80451B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80451B68:
    // 0x80451B68: lwc1        $f6, -0x7B44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140DC));
    // 0x80451B6C: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80451B70: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80451B74: nop

    // 0x80451B78: bc1fl       L_80451BA8
    if (!c1cs) {
        // 0x80451B7C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80451BA8;
    }
    goto skip_0;
    // 0x80451B7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80451B80: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80451B84: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80451B88: beql        $t6, $zero, L_80451C70
    if (ctx->r14 == 0) {
        // 0x80451B8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451C70;
    }
    goto skip_1;
    // 0x80451B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80451B90: jal         0x80450B18
    // 0x80451B94: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_3;
    // 0x80451B94: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80451B98: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451B9C: b           L_80451C6C
    // 0x80451BA0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_80451C6C;
    // 0x80451BA0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80451BA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80451BA8:
    // 0x80451BA8: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80451BAC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80451BB0: nop

    // 0x80451BB4: bc1fl       L_80451BEC
    if (!c1cs) {
        // 0x80451BB8: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80451BEC;
    }
    goto skip_2;
    // 0x80451BB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_2:
    // 0x80451BBC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80451BC0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80451BC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451BC8: beql        $t7, $at, L_80451C70
    if (ctx->r15 == ctx->r1) {
        // 0x80451BCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451C70;
    }
    goto skip_3;
    // 0x80451BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80451BD0: jal         0x80450B18
    // 0x80451BD4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_4;
    // 0x80451BD4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x80451BD8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451BDC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80451BE0: b           L_80451C6C
    // 0x80451BE4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
        goto L_80451C6C;
    // 0x80451BE4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80451BE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80451BEC:
    // 0x80451BEC: nop

    // 0x80451BF0: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80451BF4: nop

    // 0x80451BF8: bc1fl       L_80451C30
    if (!c1cs) {
        // 0x80451BFC: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80451C30;
    }
    goto skip_4;
    // 0x80451BFC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_4:
    // 0x80451C00: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80451C04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80451C08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451C0C: beql        $t9, $at, L_80451C70
    if (ctx->r25 == ctx->r1) {
        // 0x80451C10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451C70;
    }
    goto skip_5;
    // 0x80451C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80451C14: jal         0x80450B18
    // 0x80451C18: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_5;
    // 0x80451C18: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_5:
    // 0x80451C1C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451C20: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80451C24: b           L_80451C6C
    // 0x80451C28: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_80451C6C;
    // 0x80451C28: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80451C2C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80451C30:
    // 0x80451C30: nop

    // 0x80451C34: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80451C38: nop

    // 0x80451C3C: bc1fl       L_80451C70
    if (!c1cs) {
        // 0x80451C40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451C70;
    }
    goto skip_6;
    // 0x80451C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x80451C44: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80451C48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80451C4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80451C50: beql        $t1, $at, L_80451C70
    if (ctx->r9 == ctx->r1) {
        // 0x80451C54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451C70;
    }
    goto skip_7;
    // 0x80451C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80451C58: jal         0x80450B18
    // 0x80451C5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_6;
    // 0x80451C5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_6:
    // 0x80451C60: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451C64: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80451C68: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_80451C6C:
    // 0x80451C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80451C70:
    // 0x80451C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80451C74: jr          $ra
    // 0x80451C78: nop

    return;
    // 0x80451C78: nop

;}
RECOMP_FUNC void func_8005F690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F690: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005F694: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005F698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F69C: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    // 0x8005F6A0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F6A4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8005F6A8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8005F6AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005F6B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005F6B4: jal         0x8005EFE8
    // 0x8005F6B8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8005EFE8(rdram, ctx);
        goto after_0;
    // 0x8005F6B8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8005F6BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8005F6C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005F6C4: lh          $t8, 0x2C($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2C);
    // 0x8005F6C8: sh          $t8, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r24;
    // 0x8005F6CC: lh          $t9, 0x2E($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2E);
    // 0x8005F6D0: jal         0x8005F0EC
    // 0x8005F6D4: sh          $t9, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r25;
    func_8005F0EC(rdram, ctx);
        goto after_1;
    // 0x8005F6D4: sh          $t9, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r25;
    after_1:
    // 0x8005F6D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005F6DC: jal         0x8007DB34
    // 0x8005F6E0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8007DB34(rdram, ctx);
        goto after_2;
    // 0x8005F6E0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8005F6E4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F6E8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F6EC: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x8005F6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F6F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005F6F8: jr          $ra
    // 0x8005F6FC: nop

    return;
    // 0x8005F6FC: nop

;}
RECOMP_FUNC void func_800591B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800591B4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800591B8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800591BC: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800591C0: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800591C4: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800591C8: jr          $ra
    // 0x800591CC: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800591CC: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_8002FC3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FC3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FC40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FC44: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FC48: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FC4C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002FC50: jal         0x8002F678
    // 0x8002FC54: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FC54: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FC58: beq         $v0, $zero, L_8002FC6C
    if (ctx->r2 == 0) {
        // 0x8002FC5C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FC6C;
    }
    // 0x8002FC5C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FC60: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FC64: addiu       $t6, $t6, -0x2DF8
    ctx->r14 = ADD32(ctx->r14, -0X2DF8);
    // 0x8002FC68: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FC6C:
    // 0x8002FC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FC70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FC74: jr          $ra
    // 0x8002FC78: nop

    return;
    // 0x8002FC78: nop

;}
RECOMP_FUNC void func_8001E788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E788: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001E78C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E790: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E794: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8001E798: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001E79C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8001E7A0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001E7A4: beql        $t7, $zero, L_8001E7C0
    if (ctx->r15 == 0) {
        // 0x8001E7A8: lbu         $t8, 0x1FB($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X1FB);
            goto L_8001E7C0;
    }
    goto skip_0;
    // 0x8001E7A8: lbu         $t8, 0x1FB($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1FB);
    skip_0:
    // 0x8001E7AC: jal         0x8001E324
    // 0x8001E7B0: nop

    func_8001E324(rdram, ctx);
        goto after_0;
    // 0x8001E7B0: nop

    after_0:
    // 0x8001E7B4: b           L_8001E810
    // 0x8001E7B8: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
        goto L_8001E810;
    // 0x8001E7B8: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x8001E7BC: lbu         $t8, 0x1FB($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1FB);
L_8001E7C0:
    // 0x8001E7C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001E7C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001E7C8: beql        $t8, $zero, L_8001E7EC
    if (ctx->r24 == 0) {
        // 0x8001E7CC: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8001E7EC;
    }
    goto skip_1;
    // 0x8001E7CC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    skip_1:
    // 0x8001E7D0: jal         0x8001E324
    // 0x8001E7D4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8001E324(rdram, ctx);
        goto after_1;
    // 0x8001E7D4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8001E7D8: lbu         $t9, 0x1FB($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1FB);
    // 0x8001E7DC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8001E7E0: b           L_8001E80C
    // 0x8001E7E4: sb          $t0, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r8;
        goto L_8001E80C;
    // 0x8001E7E4: sb          $t0, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r8;
    // 0x8001E7E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
L_8001E7EC:
    // 0x8001E7EC: jal         0x8001E674
    // 0x8001E7F0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8001E674(rdram, ctx);
        goto after_2;
    // 0x8001E7F0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x8001E7F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001E7F8: beq         $v0, $zero, L_8001E80C
    if (ctx->r2 == 0) {
        // 0x8001E7FC: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_8001E80C;
    }
    // 0x8001E7FC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8001E800: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001E804: jal         0x8001E324
    // 0x8001E808: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001E324(rdram, ctx);
        goto after_3;
    // 0x8001E808: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
L_8001E80C:
    // 0x8001E80C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
L_8001E810:
    // 0x8001E810: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8001E814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001E818: jal         0x8001E70C
    // 0x8001E81C: lui         $a2, 0xBFC0
    ctx->r6 = S32(0XBFC0 << 16);
    func_8001E70C(rdram, ctx);
        goto after_4;
    // 0x8001E81C: lui         $a2, 0xBFC0
    ctx->r6 = S32(0XBFC0 << 16);
    after_4:
    // 0x8001E820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E824: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E828: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001E82C: jr          $ra
    // 0x8001E830: nop

    return;
    // 0x8001E830: nop

;}
RECOMP_FUNC void func_806E8990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E8990: addiu       $sp, $sp, -0x208
    ctx->r29 = ADD32(ctx->r29, -0X208);
    // 0x806E8994: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x806E8998: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x806E899C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x806E89A0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x806E89A4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x806E89A8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x806E89AC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x806E89B0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x806E89B4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x806E89B8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x806E89BC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806E89C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806E89C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806E89C8: bne         $a1, $at, L_806E89D4
    if (ctx->r5 != ctx->r1) {
        // 0x806E89CC: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_806E89D4;
    }
    // 0x806E89CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E89D0: lw          $a1, 0x454($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X454);
L_806E89D4:
    // 0x806E89D4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x806E89D8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806E89DC: lwc1        $f4, 0x5D4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5D4);
    // 0x806E89E0: lwc1        $f10, 0x5D0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5D0);
    // 0x806E89E4: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x806E89E8: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x806E89EC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x806E89F0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806E89F4: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x806E89F8: lh          $a0, 0x5C8($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X5C8);
    // 0x806E89FC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x806E8A00: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806E8A04: addu        $s6, $v0, $t8
    ctx->r22 = ADD32(ctx->r2, ctx->r24);
    // 0x806E8A08: addiu       $s0, $s6, 0x228
    ctx->r16 = ADD32(ctx->r22, 0X228);
    // 0x806E8A0C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x806E8A10: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16BC) << 16);
    // 0x806E8A14: sll         $s3, $a0, 2
    ctx->r19 = S32(ctx->r4 << 2);
    // 0x806E8A18: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x806E8A1C: mfc1        $s5, $f8
    ctx->r21 = (int32_t)ctx->f8.u32l;
    // 0x806E8A20: addu        $s2, $v0, $s3
    ctx->r18 = ADD32(ctx->r2, ctx->r19);
    // 0x806E8A24: lwc1        $f22, -0x6694($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16BC));
    // 0x806E8A28: mfc1        $fp, $f18
    ctx->r30 = (int32_t)ctx->f18.u32l;
    // 0x806E8A2C: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x806E8A30: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x806E8A34: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x806E8A38: addiu       $s1, $sp, 0x74
    ctx->r17 = ADD32(ctx->r29, 0X74);
L_806E8A3C:
    // 0x806E8A3C: slti        $at, $s3, 0xB8
    ctx->r1 = SIGNED(ctx->r19) < 0XB8 ? 1 : 0;
    // 0x806E8A40: bnel        $at, $zero, L_806E8A54
    if (ctx->r1 != 0) {
        // 0x806E8A44: sh          $s5, 0x2($s6)
        MEM_H(0X2, ctx->r22) = ctx->r21;
            goto L_806E8A54;
    }
    goto skip_0;
    // 0x806E8A44: sh          $s5, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r21;
    skip_0:
    // 0x806E8A48: addiu       $s3, $s3, -0xB8
    ctx->r19 = ADD32(ctx->r19, -0XB8);
    // 0x806E8A4C: addiu       $s2, $s2, -0xB8
    ctx->r18 = ADD32(ctx->r18, -0XB8);
    // 0x806E8A50: sh          $s5, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r21;
L_806E8A54:
    // 0x806E8A54: sh          $s5, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r21;
    // 0x806E8A58: lwc1        $f6, 0x458($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X458);
    // 0x806E8A5C: lwc1        $f4, 0x510($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X510);
    // 0x806E8A60: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x806E8A64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806E8A68: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x806E8A6C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806E8A70: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x806E8A74: nop

    // 0x806E8A78: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x806E8A7C: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x806E8A80: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x806E8A84: nop

    // 0x806E8A88: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806E8A8C: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x806E8A90: jal         0x806E83E0
    // 0x806E8A94: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    func_806E83E0(rdram, ctx);
        goto after_0;
    // 0x806E8A94: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    after_0:
    // 0x806E8A98: lwc1        $f8, 0x458($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X458);
    // 0x806E8A9C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x806E8AA0: slti        $at, $s4, 0x2E
    ctx->r1 = SIGNED(ctx->r20) < 0X2E ? 1 : 0;
    // 0x806E8AA4: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806E8AA8: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x806E8AAC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x806E8AB0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x806E8AB4: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x806E8AB8: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x806E8ABC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x806E8AC0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x806E8AC4: addu        $s5, $s5, $fp
    ctx->r21 = ADD32(ctx->r21, ctx->r30);
    // 0x806E8AC8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x806E8ACC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x806E8AD0: nop

    // 0x806E8AD4: sh          $t4, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r12;
    // 0x806E8AD8: lh          $t5, -0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, -0X2);
    // 0x806E8ADC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x806E8AE0: nop

    // 0x806E8AE4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806E8AE8: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x806E8AEC: bne         $at, $zero, L_806E8A3C
    if (ctx->r1 != 0) {
        // 0x806E8AF0: swc1        $f8, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f8.u32l;
            goto L_806E8A3C;
    }
    // 0x806E8AF0: swc1        $f8, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f8.u32l;
    // 0x806E8AF4: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x806E8AF8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16C0) << 16);
    // 0x806E8AFC: lwc1        $f0, -0x6690($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16C0));
    // 0x806E8B00: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x806E8B04: addiu       $s1, $sp, 0x7C
    ctx->r17 = ADD32(ctx->r29, 0X7C);
    // 0x806E8B08: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    // 0x806E8B0C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x806E8B10: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x806E8B14: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x806E8B18: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x806E8B1C: nop

    // 0x806E8B20: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806E8B24: mul.s       $f22, $f18, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806E8B28: beql        $s4, $v0, L_806E8CBC
    if (ctx->r20 == ctx->r2) {
        // 0x806E8B2C: lwc1        $f20, -0x8($s1)
        ctx->f20.u32l = MEM_W(ctx->r17, -0X8);
            goto L_806E8CBC;
    }
    goto skip_1;
    // 0x806E8B2C: lwc1        $f20, -0x8($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, -0X8);
    skip_1:
L_806E8B30:
    // 0x806E8B30: lwc1        $f20, -0x8($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, -0X8);
    // 0x806E8B34: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x806E8B38: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x806E8B3C: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x806E8B40: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x806E8B44: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x806E8B48: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x806E8B4C: add.s       $f20, $f18, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x806E8B50: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x806E8B54: mtc1        $t5, $f14
    ctx->f14.u32l = ctx->r13;
    // 0x806E8B58: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806E8B5C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x806E8B60: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x806E8B64: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x806E8B68: trunc.w.s   $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x806E8B6C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806E8B70: mfc1        $t8, $f20
    ctx->r24 = (int32_t)ctx->f20.u32l;
    // 0x806E8B74: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806E8B78: sh          $t8, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r24;
    // 0x806E8B7C: lwc1        $f20, -0x24($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, -0X24);
    // 0x806E8B80: lwc1        $f12, -0x14($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0X14);
    // 0x806E8B84: lh          $t8, -0x8($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X8);
    // 0x806E8B88: add.s       $f16, $f20, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x806E8B8C: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806E8B90: mtc1        $t8, $f20
    ctx->f20.u32l = ctx->r24;
    // 0x806E8B94: add.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x806E8B98: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x806E8B9C: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x806E8BA0: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x806E8BA4: nop

    // 0x806E8BA8: sh          $t1, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r9;
    // 0x806E8BAC: lwc1        $f16, -0x20($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, -0X20);
    // 0x806E8BB0: lwc1        $f12, -0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0X10);
    // 0x806E8BB4: lh          $t1, -0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, -0X6);
    // 0x806E8BB8: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806E8BBC: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806E8BC0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x806E8BC4: add.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x806E8BC8: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x806E8BCC: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x806E8BD0: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x806E8BD4: nop

    // 0x806E8BD8: sh          $t4, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r12;
    // 0x806E8BDC: lwc1        $f18, -0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, -0X1C);
    // 0x806E8BE0: lwc1        $f12, -0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0XC);
    // 0x806E8BE4: lh          $t4, -0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, -0X4);
    // 0x806E8BE8: add.s       $f14, $f18, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x806E8BEC: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x806E8BF0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x806E8BF4: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x806E8BF8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806E8BFC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806E8C00: mfc1        $t7, $f14
    ctx->r15 = (int32_t)ctx->f14.u32l;
    // 0x806E8C04: nop

    // 0x806E8C08: sh          $t7, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r15;
    // 0x806E8C0C: lwc1        $f14, -0x18($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, -0X18);
    // 0x806E8C10: lwc1        $f12, -0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0X8);
    // 0x806E8C14: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x806E8C18: add.s       $f20, $f14, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f14.fl + ctx->f20.fl;
    // 0x806E8C1C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806E8C20: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x806E8C24: add.s       $f20, $f12, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x806E8C28: trunc.w.s   $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x806E8C2C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806E8C30: mfc1        $t0, $f20
    ctx->r8 = (int32_t)ctx->f20.u32l;
    // 0x806E8C34: nop

    // 0x806E8C38: sh          $t0, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r8;
    // 0x806E8C3C: lwc1        $f20, -0x14($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, -0X14);
    // 0x806E8C40: lwc1        $f12, -0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0X4);
    // 0x806E8C44: add.s       $f16, $f20, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x806E8C48: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806E8C4C: add.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x806E8C50: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x806E8C54: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x806E8C58: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x806E8C5C: nop

    // 0x806E8C60: sh          $t3, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r11;
    // 0x806E8C64: lwc1        $f16, -0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, -0X10);
    // 0x806E8C68: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x806E8C6C: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806E8C70: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806E8C74: add.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x806E8C78: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x806E8C7C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x806E8C80: nop

    // 0x806E8C84: sh          $t6, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r14;
    // 0x806E8C88: lwc1        $f18, -0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, -0XC);
    // 0x806E8C8C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x806E8C90: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x806E8C94: add.s       $f14, $f18, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x806E8C98: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x806E8C9C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x806E8CA0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806E8CA4: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806E8CA8: mul.s       $f22, $f18, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806E8CAC: mfc1        $t9, $f14
    ctx->r25 = (int32_t)ctx->f14.u32l;
    // 0x806E8CB0: bne         $s4, $v0, L_806E8B30
    if (ctx->r20 != ctx->r2) {
        // 0x806E8CB4: sh          $t9, -0x2($s0)
        MEM_H(-0X2, ctx->r16) = ctx->r25;
            goto L_806E8B30;
    }
    // 0x806E8CB4: sh          $t9, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r25;
    // 0x806E8CB8: lwc1        $f20, -0x8($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, -0X8);
L_806E8CBC:
    // 0x806E8CBC: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x806E8CC0: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x806E8CC4: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x806E8CC8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x806E8CCC: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x806E8CD0: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x806E8CD4: add.s       $f20, $f18, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x806E8CD8: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x806E8CDC: mtc1        $t5, $f14
    ctx->f14.u32l = ctx->r13;
    // 0x806E8CE0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806E8CE4: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x806E8CE8: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x806E8CEC: trunc.w.s   $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x806E8CF0: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806E8CF4: mfc1        $t8, $f20
    ctx->r24 = (int32_t)ctx->f20.u32l;
    // 0x806E8CF8: nop

    // 0x806E8CFC: sh          $t8, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r24;
    // 0x806E8D00: lwc1        $f20, -0x24($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, -0X24);
    // 0x806E8D04: lwc1        $f12, -0x14($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0X14);
    // 0x806E8D08: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806E8D0C: lh          $t8, -0x8($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X8);
    // 0x806E8D10: add.s       $f16, $f20, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x806E8D14: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806E8D18: mtc1        $t8, $f20
    ctx->f20.u32l = ctx->r24;
    // 0x806E8D1C: add.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x806E8D20: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x806E8D24: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x806E8D28: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806E8D2C: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x806E8D30: nop

    // 0x806E8D34: sh          $t1, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r9;
    // 0x806E8D38: lwc1        $f16, -0x20($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, -0X20);
    // 0x806E8D3C: lwc1        $f12, -0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0X10);
    // 0x806E8D40: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x806E8D44: lh          $t1, -0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, -0X6);
    // 0x806E8D48: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806E8D4C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x806E8D50: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x806E8D54: add.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x806E8D58: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806E8D5C: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x806E8D60: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806E8D64: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x806E8D68: nop

    // 0x806E8D6C: sh          $t4, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r12;
    // 0x806E8D70: lwc1        $f18, -0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, -0X1C);
    // 0x806E8D74: lwc1        $f12, -0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0XC);
    // 0x806E8D78: lh          $t4, -0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, -0X4);
    // 0x806E8D7C: add.s       $f14, $f18, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x806E8D80: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x806E8D84: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x806E8D88: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806E8D8C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806E8D90: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806E8D94: mfc1        $t7, $f14
    ctx->r15 = (int32_t)ctx->f14.u32l;
    // 0x806E8D98: nop

    // 0x806E8D9C: sh          $t7, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r15;
    // 0x806E8DA0: lwc1        $f14, -0x18($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, -0X18);
    // 0x806E8DA4: lwc1        $f12, -0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0X8);
    // 0x806E8DA8: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x806E8DAC: add.s       $f20, $f14, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f14.fl + ctx->f20.fl;
    // 0x806E8DB0: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x806E8DB4: add.s       $f20, $f12, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x806E8DB8: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x806E8DBC: trunc.w.s   $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x806E8DC0: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806E8DC4: mfc1        $t0, $f20
    ctx->r8 = (int32_t)ctx->f20.u32l;
    // 0x806E8DC8: nop

    // 0x806E8DCC: sh          $t0, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r8;
    // 0x806E8DD0: lwc1        $f20, -0x14($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, -0X14);
    // 0x806E8DD4: lwc1        $f12, -0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, -0X4);
    // 0x806E8DD8: add.s       $f16, $f20, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x806E8DDC: add.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x806E8DE0: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x806E8DE4: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x806E8DE8: nop

    // 0x806E8DEC: sh          $t3, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r11;
    // 0x806E8DF0: lwc1        $f16, -0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, -0X10);
    // 0x806E8DF4: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x806E8DF8: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806E8DFC: add.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x806E8E00: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x806E8E04: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x806E8E08: nop

    // 0x806E8E0C: sh          $t6, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r14;
    // 0x806E8E10: lwc1        $f18, -0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, -0XC);
    // 0x806E8E14: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x806E8E18: add.s       $f14, $f18, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x806E8E1C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x806E8E20: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806E8E24: mfc1        $t9, $f14
    ctx->r25 = (int32_t)ctx->f14.u32l;
    // 0x806E8E28: nop

    // 0x806E8E2C: sh          $t9, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r25;
    // 0x806E8E30: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x806E8E34: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806E8E38: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806E8E3C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x806E8E40: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x806E8E44: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x806E8E48: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x806E8E4C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x806E8E50: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x806E8E54: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x806E8E58: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x806E8E5C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x806E8E60: jr          $ra
    // 0x806E8E64: addiu       $sp, $sp, 0x208
    ctx->r29 = ADD32(ctx->r29, 0X208);
    return;
    // 0x806E8E64: addiu       $sp, $sp, 0x208
    ctx->r29 = ADD32(ctx->r29, 0X208);
;}
RECOMP_FUNC void func_80039EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039EAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039EB4: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x80039EB8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80039EBC: sw          $v0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r2;
    // 0x80039EC0: sw          $v0, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r2;
    // 0x80039EC4: sb          $zero, 0x158($a0)
    MEM_B(0X158, ctx->r4) = 0;
    // 0x80039EC8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80039ECC: addiu       $a1, $a2, 0x78
    ctx->r5 = ADD32(ctx->r6, 0X78);
    // 0x80039ED0: jal         0x80065490
    // 0x80039ED4: addiu       $a0, $a0, 0x6C
    ctx->r4 = ADD32(ctx->r4, 0X6C);
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x80039ED4: addiu       $a0, $a0, 0x6C
    ctx->r4 = ADD32(ctx->r4, 0X6C);
    after_0:
    // 0x80039ED8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80039EDC: lw          $t6, 0x174($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X174);
    // 0x80039EE0: beql        $t6, $zero, L_80039EF4
    if (ctx->r14 == 0) {
        // 0x80039EE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80039EF4;
    }
    goto skip_0;
    // 0x80039EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80039EE8: jal         0x800498D4
    // 0x80039EEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800498D4(rdram, ctx);
        goto after_1;
    // 0x80039EEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80039EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80039EF4:
    // 0x80039EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039EF8: jr          $ra
    // 0x80039EFC: nop

    return;
    // 0x80039EFC: nop

;}
RECOMP_FUNC void func_805ABB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ABB90: lui         $v0, 0x805B
    ctx->r2 = S32(RELOC_HI16(438, 0X498) << 16);
    // 0x805ABB94: addiu       $v0, $v0, -0x3FD8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(438, 0X498));
    // 0x805ABB98: jr          $ra
    // 0x805ABB9C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805ABB9C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8003A3FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A3FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003A400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A404: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8003A408: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x8003A40C: beql        $v0, $zero, L_8003A4E0
    if (ctx->r2 == 0) {
        // 0x8003A410: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003A4E0;
    }
    goto skip_0;
    // 0x8003A410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003A414: lbu         $t7, 0x18($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X18);
    // 0x8003A418: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8003A41C: bnel        $t7, $at, L_8003A4CC
    if (ctx->r15 != ctx->r1) {
        // 0x8003A420: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8003A4CC;
    }
    goto skip_1;
    // 0x8003A420: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x8003A424: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x8003A428: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003A42C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x8003A430: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x8003A434: bnel        $t0, $at, L_8003A4BC
    if (ctx->r8 != ctx->r1) {
        // 0x8003A438: lwc1        $f10, 0xC8($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_8003A4BC;
    }
    goto skip_2;
    // 0x8003A438: lwc1        $f10, 0xC8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC8);
    skip_2:
    // 0x8003A43C: lwc1        $f12, 0x50($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8003A440: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8003A444: jal         0x80066DE4
    // 0x8003A448: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8003A448: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8003A44C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8003A450: jal         0x80066E88
    // 0x8003A454: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8003A454: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8003A458: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003A45C: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003A460: lwc1        $f2, 0xC4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8003A464: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8003A468: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8003A46C: nop

    // 0x8003A470: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8003A474: nop

    // 0x8003A478: mul.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8003A47C: nop

    // 0x8003A480: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8003A484: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003A488: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8003A48C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003A490: neg.s       $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = -ctx->f14.fl;
    // 0x8003A494: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8003A498: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003A49C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8003A4A0: nop

    // 0x8003A4A4: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003A4A8: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x8003A4AC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003A4B0: b           L_8003A4DC
    // 0x8003A4B4: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
        goto L_8003A4DC;
    // 0x8003A4B4: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    // 0x8003A4B8: lwc1        $f10, 0xC8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC8);
L_8003A4BC:
    // 0x8003A4BC: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8003A4C0: b           L_8003A4DC
    // 0x8003A4C4: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
        goto L_8003A4DC;
    // 0x8003A4C4: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8003A4C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8003A4CC:
    // 0x8003A4CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003A4D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003A4D4: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x8003A4D8: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
L_8003A4DC:
    // 0x8003A4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003A4E0:
    // 0x8003A4E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003A4E4: jr          $ra
    // 0x8003A4E8: nop

    return;
    // 0x8003A4E8: nop

;}
RECOMP_FUNC void func_800328C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800328C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800328C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800328C8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x800328CC: lbu         $t6, 0x156($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X156);
    // 0x800328D0: bnel        $t6, $zero, L_800328EC
    if (ctx->r14 != 0) {
        // 0x800328D4: lbu         $t7, 0x159($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X159);
            goto L_800328EC;
    }
    goto skip_0;
    // 0x800328D4: lbu         $t7, 0x159($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X159);
    skip_0:
    // 0x800328D8: jal         0x800327D0
    // 0x800328DC: nop

    func_800327D0(rdram, ctx);
        goto after_0;
    // 0x800328DC: nop

    after_0:
    // 0x800328E0: b           L_80032938
    // 0x800328E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80032938;
    // 0x800328E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800328E8: lbu         $t7, 0x159($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X159);
L_800328EC:
    // 0x800328EC: bne         $t7, $zero, L_8003290C
    if (ctx->r15 != 0) {
        // 0x800328F0: nop
    
            goto L_8003290C;
    }
    // 0x800328F0: nop

    // 0x800328F4: jal         0x80032878
    // 0x800328F8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80032878(rdram, ctx);
        goto after_1;
    // 0x800328F8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x800328FC: bne         $v0, $zero, L_8003290C
    if (ctx->r2 != 0) {
        // 0x80032900: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8003290C;
    }
    // 0x80032900: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80032904: b           L_80032938
    // 0x80032908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80032938;
    // 0x80032908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003290C:
    // 0x8003290C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80032910: lbu         $t8, -0x7669($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X7669);
    // 0x80032914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80032918: bne         $t8, $zero, L_80032938
    if (ctx->r24 != 0) {
        // 0x8003291C: nop
    
            goto L_80032938;
    }
    // 0x8003291C: nop

    // 0x80032920: lbu         $t9, 0x159($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X159);
    // 0x80032924: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80032928: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8003292C: bne         $at, $zero, L_80032938
    if (ctx->r1 != 0) {
        // 0x80032930: nop
    
            goto L_80032938;
    }
    // 0x80032930: nop

    // 0x80032934: sb          $t0, 0x159($v1)
    MEM_B(0X159, ctx->r3) = ctx->r8;
L_80032938:
    // 0x80032938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003293C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80032940: jr          $ra
    // 0x80032944: nop

    return;
    // 0x80032944: nop

;}
RECOMP_FUNC void func_806D0170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0170: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806D0174: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D0178: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D017C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D0180: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D0184: jal         0x806CFF8C
    // 0x806D0188: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_806CFF8C(rdram, ctx);
        goto after_0;
    // 0x806D0188: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x806D018C: jal         0x806CFFF4
    // 0x806D0190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CFFF4(rdram, ctx);
        goto after_1;
    // 0x806D0190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806D0194: lw          $t7, 0x12C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X12C);
    // 0x806D0198: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806D019C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x806D01A0: bnel        $t7, $zero, L_806D0224
    if (ctx->r15 != 0) {
        // 0x806D01A4: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_806D0224;
    }
    goto skip_0;
    // 0x806D01A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x806D01A8: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x806D01AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806D01B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806D01B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806D01B8: nop

    // 0x806D01BC: bc1fl       L_806D0294
    if (!c1cs) {
        // 0x806D01C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D0294;
    }
    goto skip_1;
    // 0x806D01C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806D01C4: jal         0x806CF7E0
    // 0x806D01C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_806CF7E0(rdram, ctx);
        goto after_2;
    // 0x806D01C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x806D01CC: beq         $v0, $zero, L_806D01FC
    if (ctx->r2 == 0) {
        // 0x806D01D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806D01FC;
    }
    // 0x806D01D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D01D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D01D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D01DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806D01E0: jal         0x806D093C
    // 0x806D01E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806D093C(rdram, ctx);
        goto after_3;
    // 0x806D01E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x806D01E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D01EC: jal         0x806CFE48
    // 0x806D01F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806CFE48(rdram, ctx);
        goto after_4;
    // 0x806D01F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x806D01F4: b           L_806D0294
    // 0x806D01F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D0294;
    // 0x806D01F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D01FC:
    // 0x806D01FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0200: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806D0204: jal         0x806D093C
    // 0x806D0208: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806D093C(rdram, ctx);
        goto after_5;
    // 0x806D0208: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x806D020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0210: jal         0x806D02A4
    // 0x806D0214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806D02A4(rdram, ctx);
        goto after_6;
    // 0x806D0214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x806D0218: b           L_806D0294
    // 0x806D021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D0294;
    // 0x806D021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D0220: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_806D0224:
    // 0x806D0224: lwc1        $f10, 0x1C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x806D0228: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806D022C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806D0230: nop

    // 0x806D0234: bc1fl       L_806D0294
    if (!c1cs) {
        // 0x806D0238: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D0294;
    }
    goto skip_2;
    // 0x806D0238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806D023C: jal         0x806CF7E0
    // 0x806D0240: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_806CF7E0(rdram, ctx);
        goto after_7;
    // 0x806D0240: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x806D0244: beq         $v0, $zero, L_806D0274
    if (ctx->r2 == 0) {
        // 0x806D0248: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806D0274;
    }
    // 0x806D0248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0250: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0254: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806D0258: jal         0x806D093C
    // 0x806D025C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806D093C(rdram, ctx);
        goto after_8;
    // 0x806D025C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x806D0260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0264: jal         0x806CFE48
    // 0x806D0268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806CFE48(rdram, ctx);
        goto after_9;
    // 0x806D0268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x806D026C: b           L_806D0294
    // 0x806D0270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D0294;
    // 0x806D0270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D0274:
    // 0x806D0274: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0278: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806D027C: jal         0x806D093C
    // 0x806D0280: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806D093C(rdram, ctx);
        goto after_10;
    // 0x806D0280: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x806D0284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0288: jal         0x806D02A4
    // 0x806D028C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806D02A4(rdram, ctx);
        goto after_11;
    // 0x806D028C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x806D0290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D0294:
    // 0x806D0294: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D0298: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806D029C: jr          $ra
    // 0x806D02A0: nop

    return;
    // 0x806D02A0: nop

;}
RECOMP_FUNC void func_8078CEA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078CEA0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8078CEA4: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(799, 0X260) << 16);
    // 0x8078CEA8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8078CEAC: addiu       $t6, $t6, -0x2F00
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(799, 0X260));
    // 0x8078CEB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8078CEB4: sw          $t6, 0xEC0($v1)
    MEM_W(0XEC0, ctx->r3) = ctx->r14;
    // 0x8078CEB8: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(799, 0XBC) << 16);
    // 0x8078CEBC: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8078CEC0: jr          $ra
    // 0x8078CEC4: addiu       $v0, $v0, -0x30A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(799, 0XBC));
    return;
    // 0x8078CEC4: addiu       $v0, $v0, -0x30A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(799, 0XBC));
;}
RECOMP_FUNC void func_806F62CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F62CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F62D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F62D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806F62D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806F62DC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806F62E0: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(685, 0X1190) << 16);
    // 0x806F62E4: addiu       $t6, $t6, 0x64F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(685, 0X1190));
    // 0x806F62E8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806F62EC: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x806F62F0: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x806F62F4: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    // 0x806F62F8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F62FC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806F6300: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x806F6304: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x806F6308: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x806F630C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x806F6310: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806F6314: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F6318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F631C: jal         0x800653D8
    // 0x806F6320: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x806F6320: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    after_0:
    // 0x806F6324: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x806F6328: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x806F632C: lui         $at, 0x3CA0
    ctx->r1 = S32(0X3CA0 << 16);
    // 0x806F6330: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806F6334: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806F6338: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x806F633C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806F6340: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x806F6344: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806F6348: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806F634C: jal         0x800653D8
    // 0x806F6350: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x806F6350: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    after_1:
    // 0x806F6354: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x806F6358: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x806F635C: lui         $at, 0xBCA0
    ctx->r1 = S32(0XBCA0 << 16);
    // 0x806F6360: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806F6364: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806F6368: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806F636C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806F6370: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F6374: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(685, 0X11E8) << 16);
    // 0x806F6378: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806F637C: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    // 0x806F6380: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806F6384: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x806F6388: lwc1        $f6, 0x6548($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(685, 0X11E8));
    // 0x806F638C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806F6390: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806F6394: swc1        $f6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f6.u32l;
    // 0x806F6398: jal         0x800653D8
    // 0x806F639C: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x806F639C: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    after_2:
    // 0x806F63A0: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x806F63A4: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x806F63A8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(685, 0X11EC) << 16);
    // 0x806F63AC: lwc1        $f18, 0x654C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(685, 0X11EC));
    // 0x806F63B0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806F63B4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(685, 0X11F0) << 16);
    // 0x806F63B8: lwc1        $f6, 0x6550($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(685, 0X11F0));
    // 0x806F63BC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x806F63C0: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F63C4: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x806F63C8: jal         0x800653D8
    // 0x806F63CC: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x806F63CC: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x806F63D0: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x806F63D4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x806F63D8: lui         $at, 0x3DA0
    ctx->r1 = S32(0X3DA0 << 16);
    // 0x806F63DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806F63E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806F63E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x806F63E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F63EC: lui         $t4, 0x806F
    ctx->r12 = S32(RELOC_HI16(685, 0XBE4) << 16);
    // 0x806F63F0: addiu       $t4, $t4, 0x5F44
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(685, 0XBE4));
    // 0x806F63F4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806F63F8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806F63FC: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
    // 0x806F6400: jal         0x80058958
    // 0x806F6404: sw          $t4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r12;
    func_80058958(rdram, ctx);
        goto after_4;
    // 0x806F6404: sw          $t4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r12;
    after_4:
    // 0x806F6408: beq         $v0, $zero, L_806F6448
    if (ctx->r2 == 0) {
        // 0x806F640C: lui         $a0, 0x800F
        ctx->r4 = S32(0X800F << 16);
            goto L_806F6448;
    }
    // 0x806F640C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x806F6410: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x806F6414: lw          $t5, 0x59C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X59C);
    // 0x806F6418: lw          $t6, 0x10C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10C);
    // 0x806F641C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x806F6420: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x806F6424: beql        $t8, $zero, L_806F644C
    if (ctx->r24 == 0) {
        // 0x806F6428: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F644C;
    }
    goto skip_0;
    // 0x806F6428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F642C: lw          $t9, 0x13B8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X13B8);
    // 0x806F6430: lw          $v0, 0x16C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X16C);
    // 0x806F6434: lbu         $v1, 0x5D($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X5D);
    // 0x806F6438: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x806F643C: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x806F6440: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x806F6444: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_806F6448:
    // 0x806F6448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F644C:
    // 0x806F644C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806F6450: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806F6454: jr          $ra
    // 0x806F6458: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806F6458: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80472820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80472820: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80472824: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80472828: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8047282C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80472830: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80472834: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80472838: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8047283C: jal         0x80048F84
    // 0x80472840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80472840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80472844: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80472848: jal         0x80472440
    // 0x8047284C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80472440(rdram, ctx);
        goto after_1;
    // 0x8047284C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80472850: beql        $v0, $zero, L_80472864
    if (ctx->r2 == 0) {
        // 0x80472854: lw          $t6, 0x28($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X28);
            goto L_80472864;
    }
    goto skip_0;
    // 0x80472854: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x80472858: jal         0x8047265C
    // 0x8047285C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8047265C(rdram, ctx);
        goto after_2;
    // 0x8047285C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80472860: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
L_80472864:
    // 0x80472864: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80472868: beql        $t6, $zero, L_80472A44
    if (ctx->r14 == 0) {
        // 0x8047286C: lw          $v0, 0x1E0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X1E0);
            goto L_80472A44;
    }
    goto skip_1;
    // 0x8047286C: lw          $v0, 0x1E0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1E0);
    skip_1:
    // 0x80472870: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80472874: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80472878: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8047287C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80472880: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80472884: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80472888: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8047288C: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80472890: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80472894: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80472898: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8047289C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x804728A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804728A4: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804728A8: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x804728AC: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x804728B0: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x804728B4: mov.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
    // 0x804728B8: bc1fl       L_804728D0
    if (!c1cs) {
        // 0x804728BC: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_804728D0;
    }
    goto skip_2;
    // 0x804728BC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_2:
    // 0x804728C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804728C4: b           L_804728E0
    // 0x804728C8: nop

        goto L_804728E0;
    // 0x804728C8: nop

    // 0x804728CC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_804728D0:
    // 0x804728D0: nop

    // 0x804728D4: bc1f        L_804728E0
    if (!c1cs) {
        // 0x804728D8: nop
    
            goto L_804728E0;
    }
    // 0x804728D8: nop

    // 0x804728DC: mov.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = ctx->f16.fl;
L_804728E0:
    // 0x804728E0: jal         0x80067114
    // 0x804728E4: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_80067114(rdram, ctx);
        goto after_3;
    // 0x804728E4: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x804728E8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x804728EC: jal         0x80066E88
    // 0x804728F0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x804728F0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x804728F4: jal         0x80065954
    // 0x804728F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x804728F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x804728FC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80472900: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80472904: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80472908: jal         0x80066DE4
    // 0x8047290C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x8047290C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80472910: jal         0x80065954
    // 0x80472914: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_7;
    // 0x80472914: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x80472918: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8047291C: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80472920: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80472924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80472928: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8047292C: mul.s       $f14, $f0, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80472930: bc1fl       L_8047297C
    if (!c1cs) {
        // 0x80472934: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_8047297C;
    }
    goto skip_3;
    // 0x80472934: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_3:
    // 0x80472938: jal         0x804727AC
    // 0x8047293C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    func_804727AC(rdram, ctx);
        goto after_8;
    // 0x8047293C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    after_8:
    // 0x80472940: bne         $v0, $zero, L_804729C4
    if (ctx->r2 != 0) {
        // 0x80472944: lwc1        $f14, 0x28($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
            goto L_804729C4;
    }
    // 0x80472944: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80472948: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8047294C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80472950: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80472954: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80472958: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8047295C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80472960: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80472964: nop

    // 0x80472968: bc1fl       L_804729C8
    if (!c1cs) {
        // 0x8047296C: lwc1        $f2, 0x4($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
            goto L_804729C8;
    }
    goto skip_4;
    // 0x8047296C: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    skip_4:
    // 0x80472970: b           L_804729C4
    // 0x80472974: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
        goto L_804729C4;
    // 0x80472974: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
    // 0x80472978: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_8047297C:
    // 0x8047297C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80472980: bc1fl       L_804729C8
    if (!c1cs) {
        // 0x80472984: lwc1        $f2, 0x4($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
            goto L_804729C8;
    }
    goto skip_5;
    // 0x80472984: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    skip_5:
    // 0x80472988: jal         0x80472738
    // 0x8047298C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    func_80472738(rdram, ctx);
        goto after_9;
    // 0x8047298C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    after_9:
    // 0x80472990: bne         $v0, $zero, L_804729C4
    if (ctx->r2 != 0) {
        // 0x80472994: lwc1        $f14, 0x28($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
            goto L_804729C4;
    }
    // 0x80472994: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80472998: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8047299C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804729A0: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x804729A4: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804729A8: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x804729AC: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x804729B0: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x804729B4: nop

    // 0x804729B8: bc1fl       L_804729C8
    if (!c1cs) {
        // 0x804729BC: lwc1        $f2, 0x4($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
            goto L_804729C8;
    }
    goto skip_6;
    // 0x804729BC: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    skip_6:
    // 0x804729C0: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
L_804729C4:
    // 0x804729C4: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
L_804729C8:
    // 0x804729C8: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x804729CC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804729D0: nop

    // 0x804729D4: bc1fl       L_80472A04
    if (!c1cs) {
        // 0x804729D8: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80472A04;
    }
    goto skip_7;
    // 0x804729D8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_7:
    // 0x804729DC: add.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x804729E0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x804729E4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804729E8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x804729EC: nop

    // 0x804729F0: bc1fl       L_80472A34
    if (!c1cs) {
        // 0x804729F4: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_80472A34;
    }
    goto skip_8;
    // 0x804729F4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    skip_8:
    // 0x804729F8: b           L_80472A30
    // 0x804729FC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
        goto L_80472A30;
    // 0x804729FC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80472A00: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80472A04:
    // 0x80472A04: nop

    // 0x80472A08: bc1fl       L_80472A34
    if (!c1cs) {
        // 0x80472A0C: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_80472A34;
    }
    goto skip_9;
    // 0x80472A0C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    skip_9:
    // 0x80472A10: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80472A14: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80472A18: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80472A1C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80472A20: nop

    // 0x80472A24: bc1fl       L_80472A34
    if (!c1cs) {
        // 0x80472A28: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_80472A34;
    }
    goto skip_10;
    // 0x80472A28: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    skip_10:
    // 0x80472A2C: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
L_80472A30:
    // 0x80472A30: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
L_80472A34:
    // 0x80472A34: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x80472A38: b           L_80472BE0
    // 0x80472A3C: sw          $t7, 0x1E0($t8)
    MEM_W(0X1E0, ctx->r24) = ctx->r15;
        goto L_80472BE0;
    // 0x80472A3C: sw          $t7, 0x1E0($t8)
    MEM_W(0X1E0, ctx->r24) = ctx->r15;
    // 0x80472A40: lw          $v0, 0x1E0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1E0);
L_80472A44:
    // 0x80472A44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80472A48: beq         $v0, $zero, L_80472A58
    if (ctx->r2 == 0) {
        // 0x80472A4C: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80472A58;
    }
    // 0x80472A4C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80472A50: b           L_80472BE0
    // 0x80472A54: sw          $t9, 0x1E0($v1)
    MEM_W(0X1E0, ctx->r3) = ctx->r25;
        goto L_80472BE0;
    // 0x80472A54: sw          $t9, 0x1E0($v1)
    MEM_W(0X1E0, ctx->r3) = ctx->r25;
L_80472A58:
    // 0x80472A58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80472A5C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80472A60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80472A64: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80472A68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80472A6C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80472A70: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80472A74: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80472A78: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80472A7C: nop

    // 0x80472A80: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80472A84: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80472A88: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80472A8C: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80472A90: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80472A94: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80472A98: bc1f        L_80472AA8
    if (!c1cs) {
        // 0x80472A9C: nop
    
            goto L_80472AA8;
    }
    // 0x80472A9C: nop

    // 0x80472AA0: b           L_80472ABC
    // 0x80472AA4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
        goto L_80472ABC;
    // 0x80472AA4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
L_80472AA8:
    // 0x80472AA8: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80472AAC: nop

    // 0x80472AB0: bc1f        L_80472ABC
    if (!c1cs) {
        // 0x80472AB4: nop
    
            goto L_80472ABC;
    }
    // 0x80472AB4: nop

    // 0x80472AB8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
L_80472ABC:
    // 0x80472ABC: jal         0x80067114
    // 0x80472AC0: nop

    func_80067114(rdram, ctx);
        goto after_10;
    // 0x80472AC0: nop

    after_10:
    // 0x80472AC4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80472AC8: jal         0x80066E88
    // 0x80472ACC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066E88(rdram, ctx);
        goto after_11;
    // 0x80472ACC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_11:
    // 0x80472AD0: jal         0x80065954
    // 0x80472AD4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_12;
    // 0x80472AD4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_12:
    // 0x80472AD8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80472ADC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80472AE0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80472AE4: jal         0x80066DE4
    // 0x80472AE8: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_80066DE4(rdram, ctx);
        goto after_13;
    // 0x80472AE8: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x80472AEC: jal         0x80065954
    // 0x80472AF0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_14;
    // 0x80472AF0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_14:
    // 0x80472AF4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80472AF8: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80472AFC: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80472B00: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80472B04: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80472B08: nop

    // 0x80472B0C: bc1fl       L_80472B3C
    if (!c1cs) {
        // 0x80472B10: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_80472B3C;
    }
    goto skip_11;
    // 0x80472B10: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_11:
    // 0x80472B14: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x80472B18: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x80472B1C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80472B20: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80472B24: nop

    // 0x80472B28: bc1fl       L_80472B6C
    if (!c1cs) {
        // 0x80472B2C: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80472B6C;
    }
    goto skip_12;
    // 0x80472B2C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_12:
    // 0x80472B30: b           L_80472B68
    // 0x80472B34: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
        goto L_80472B68;
    // 0x80472B34: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
    // 0x80472B38: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_80472B3C:
    // 0x80472B3C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80472B40: bc1fl       L_80472B6C
    if (!c1cs) {
        // 0x80472B44: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80472B6C;
    }
    goto skip_13;
    // 0x80472B44: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_13:
    // 0x80472B48: sub.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80472B4C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80472B50: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80472B54: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80472B58: nop

    // 0x80472B5C: bc1fl       L_80472B6C
    if (!c1cs) {
        // 0x80472B60: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80472B6C;
    }
    goto skip_14;
    // 0x80472B60: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_14:
    // 0x80472B64: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
L_80472B68:
    // 0x80472B68: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80472B6C:
    // 0x80472B6C: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80472B70: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80472B74: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80472B78: nop

    // 0x80472B7C: bc1fl       L_80472BB0
    if (!c1cs) {
        // 0x80472B80: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_80472BB0;
    }
    goto skip_15;
    // 0x80472B80: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_15:
    // 0x80472B84: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80472B88: add.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80472B8C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80472B90: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80472B94: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80472B98: nop

    // 0x80472B9C: bc1f        L_80472BE0
    if (!c1cs) {
        // 0x80472BA0: nop
    
            goto L_80472BE0;
    }
    // 0x80472BA0: nop

    // 0x80472BA4: b           L_80472BE0
    // 0x80472BA8: swc1        $f12, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f12.u32l;
        goto L_80472BE0;
    // 0x80472BA8: swc1        $f12, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f12.u32l;
    // 0x80472BAC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_80472BB0:
    // 0x80472BB0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80472BB4: bc1f        L_80472BE0
    if (!c1cs) {
        // 0x80472BB8: nop
    
            goto L_80472BE0;
    }
    // 0x80472BB8: nop

    // 0x80472BBC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80472BC0: sub.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80472BC4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80472BC8: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80472BCC: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80472BD0: nop

    // 0x80472BD4: bc1f        L_80472BE0
    if (!c1cs) {
        // 0x80472BD8: nop
    
            goto L_80472BE0;
    }
    // 0x80472BD8: nop

    // 0x80472BDC: swc1        $f12, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f12.u32l;
L_80472BE0:
    // 0x80472BE0: jal         0x804726F4
    // 0x80472BE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_804726F4(rdram, ctx);
        goto after_15;
    // 0x80472BE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_15:
    // 0x80472BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80472BEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80472BF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80472BF4: jr          $ra
    // 0x80472BF8: nop

    return;
    // 0x80472BF8: nop

;}
RECOMP_FUNC void func_80436E3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436E3C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80436E40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80436E44: nop

    // 0x80436E48: div.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80436E4C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80436E50: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80436E54: nop

    // 0x80436E58: blezl       $v0, L_80436EA0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80436E5C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80436EA0;
    }
    goto skip_0;
    // 0x80436E5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80436E60: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80436E64: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(77, 0X1F40) << 16);
    // 0x80436E68: addiu       $t8, $t8, -0x7820
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(77, 0X1F40));
    // 0x80436E6C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80436E70: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80436E74: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80436E78: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80436E7C: lwc1        $f8, -0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80436E80: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80436E84: sub.s       $f2, $f14, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x80436E88: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80436E8C: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80436E90: div.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80436E94: jr          $ra
    // 0x80436E98: add.s       $f0, $f14, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f10.fl;
    return;
    // 0x80436E98: add.s       $f0, $f14, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80436E9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80436EA0:
    // 0x80436EA0: nop

    // 0x80436EA4: jr          $ra
    // 0x80436EA8: nop

    return;
    // 0x80436EA8: nop

;}
RECOMP_FUNC void func_806704E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806704E8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x806704EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806704F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806704F4: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x806704F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806704FC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80670500: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80670504: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80670508: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067050C: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    // 0x80670510: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x80670514: beq         $v1, $zero, L_80670524
    if (ctx->r3 == 0) {
        // 0x80670518: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80670524;
    }
    // 0x80670518: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8067051C: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80670520: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80670524:
    // 0x80670524: bnel        $v1, $zero, L_80670560
    if (ctx->r3 != 0) {
        // 0x80670528: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80670560;
    }
    goto skip_0;
    // 0x80670528: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8067052C: jal         0x80044658
    // 0x80670530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044658(rdram, ctx);
        goto after_0;
    // 0x80670530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80670534: jal         0x80670290
    // 0x80670538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80670290(rdram, ctx);
        goto after_1;
    // 0x80670538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8067053C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80670540: jal         0x80067BBC
    // 0x80670544: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80670544: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80670548: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    // 0x8067054C: jal         0x80067818
    // 0x80670550: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80670550: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80670554: b           L_80670738
    // 0x80670558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80670738;
    // 0x80670558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067055C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80670560:
    // 0x80670560: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80670564: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80670568: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8067056C: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80670570: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80670574: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80670578: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8067057C: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x80670580: nop

    // 0x80670584: bc1fl       L_80670594
    if (!c1cs) {
        // 0x80670588: c.lt.s      $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
            goto L_80670594;
    }
    goto skip_1;
    // 0x80670588: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    skip_1:
    // 0x8067058C: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80670590: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
L_80670594:
    // 0x80670594: nop

    // 0x80670598: bc1fl       L_806705A8
    if (!c1cs) {
        // 0x8067059C: swc1        $f12, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
            goto L_806705A8;
    }
    goto skip_2;
    // 0x8067059C: swc1        $f12, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
    skip_2:
    // 0x806705A0: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x806705A4: swc1        $f12, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
L_806705A8:
    // 0x806705A8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x806705AC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806705B0: lw          $v0, 0x40($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X40);
    // 0x806705B4: lbu         $t9, 0x2C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2C);
    // 0x806705B8: beq         $t9, $zero, L_8067061C
    if (ctx->r25 == 0) {
        // 0x806705BC: nop
    
            goto L_8067061C;
    }
    // 0x806705BC: nop

    // 0x806705C0: lhu         $a0, 0x18($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X18);
    // 0x806705C4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x806705C8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x806705CC: jal         0x8004A97C
    // 0x806705D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004A97C(rdram, ctx);
        goto after_4;
    // 0x806705D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x806705D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x806705D8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x806705DC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x806705E0: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x806705E4: nop

    // 0x806705E8: bc1tl       L_806706C0
    if (c1cs) {
        // 0x806705EC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_806706C0;
    }
    goto skip_3;
    // 0x806705EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_3:
    // 0x806705F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806705F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806705F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806705FC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80670600: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80670604: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    // 0x80670608: bc1fl       L_806706C0
    if (!c1cs) {
        // 0x8067060C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_806706C0;
    }
    goto skip_4;
    // 0x8067060C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_4:
    // 0x80670610: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80670614: b           L_806706BC
    // 0x80670618: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
        goto L_806706BC;
    // 0x80670618: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_8067061C:
    // 0x8067061C: beql        $a1, $zero, L_806706C0
    if (ctx->r5 == 0) {
        // 0x80670620: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_806706C0;
    }
    goto skip_5;
    // 0x80670620: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_5:
    // 0x80670624: lhu         $a0, 0xC($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0XC);
    // 0x80670628: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8067062C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80670630: jal         0x80670310
    // 0x80670634: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_80670310(rdram, ctx);
        goto after_5;
    // 0x80670634: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_5:
    // 0x80670638: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8067063C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80670640: beq         $v0, $zero, L_806706BC
    if (ctx->r2 == 0) {
        // 0x80670644: lw          $a3, 0x38($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X38);
            goto L_806706BC;
    }
    // 0x80670644: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80670648: lwc1        $f12, 0x98($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X98);
    // 0x8067064C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80670650: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80670654: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80670658: jal         0x80066E88
    // 0x8067065C: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x8067065C: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x80670660: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80670664: jal         0x80066DE4
    // 0x80670668: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_7;
    // 0x80670668: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8067066C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80670670: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80670674: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80670678: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8067067C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80670680: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80670684: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80670688: nop

    // 0x8067068C: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80670690: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80670694: nop

    // 0x80670698: bc1f        L_806706B0
    if (!c1cs) {
        // 0x8067069C: nop
    
            goto L_806706B0;
    }
    // 0x8067069C: nop

    // 0x806706A0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806706A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806706A8: b           L_806706BC
    // 0x806706AC: swc1        $f6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f6.u32l;
        goto L_806706BC;
    // 0x806706AC: swc1        $f6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f6.u32l;
L_806706B0:
    // 0x806706B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806706B4: nop

    // 0x806706B8: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_806706BC:
    // 0x806706BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_806706C0:
    // 0x806706C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806706C4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x806706C8: jal         0x80048F84
    // 0x806706CC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_8;
    // 0x806706CC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_8:
    // 0x806706D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x806706D4: jal         0x80048F84
    // 0x806706D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_9;
    // 0x806706D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x806706DC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x806706E0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x806706E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806706E8: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x806706EC: andi        $t2, $t1, 0xF00
    ctx->r10 = ctx->r9 & 0XF00;
    // 0x806706F0: beql        $t2, $zero, L_8067070C
    if (ctx->r10 == 0) {
        // 0x806706F4: lw          $t3, 0x8($a3)
        ctx->r11 = MEM_W(ctx->r7, 0X8);
            goto L_8067070C;
    }
    goto skip_6;
    // 0x806706F4: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    skip_6:
    // 0x806706F8: jal         0x80670344
    // 0x806706FC: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    func_80670344(rdram, ctx);
        goto after_10;
    // 0x806706FC: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    after_10:
    // 0x80670700: b           L_80670738
    // 0x80670704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80670738;
    // 0x80670704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80670708: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
L_8067070C:
    // 0x8067070C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80670710: bnel        $t3, $zero, L_80670738
    if (ctx->r11 != 0) {
        // 0x80670714: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80670738;
    }
    goto skip_7;
    // 0x80670714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80670718: sw          $t4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r12;
    // 0x8067071C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80670720: jal         0x80067BBC
    // 0x80670724: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_11;
    // 0x80670724: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_11:
    // 0x80670728: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    // 0x8067072C: jal         0x80067818
    // 0x80670730: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_12;
    // 0x80670730: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x80670734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80670738:
    // 0x80670738: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067073C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80670740: jr          $ra
    // 0x80670744: nop

    return;
    // 0x80670744: nop

;}
RECOMP_FUNC void func_8001BCD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BCD0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001BCD4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8001BCD8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001BCDC: beq         $a0, $zero, L_8001BCEC
    if (ctx->r4 == 0) {
        // 0x8001BCE0: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8001BCEC;
    }
    // 0x8001BCE0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001BCE4: swc1        $f12, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f12.u32l;
    // 0x8001BCE8: sh          $a2, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r6;
L_8001BCEC:
    // 0x8001BCEC: jr          $ra
    // 0x8001BCF0: nop

    return;
    // 0x8001BCF0: nop

;}
RECOMP_FUNC void func_805ADDB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADDB4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADDB8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADDBC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADDC0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADDC4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADDC8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADDCC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADDD0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADDD4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADDD8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADDDC: jr          $ra
    // 0x805ADDE0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADDE0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806B2A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2A0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2A10: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2A14: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2A18: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2A1C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2A20: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2A24: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2A28: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2A2C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2A30: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2A34: jr          $ra
    // 0x806B2A38: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2A38: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804415C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804415C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804415C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804415CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804415D0: jal         0x8043F33C
    // 0x804415D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8043F33C(rdram, ctx);
        goto after_0;
    // 0x804415D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804415D8: jal         0x8043FBDC
    // 0x804415DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FBDC(rdram, ctx);
        goto after_1;
    // 0x804415DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804415E0: jal         0x8043F150
    // 0x804415E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_2;
    // 0x804415E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804415E8: jal         0x804400F0
    // 0x804415EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804400F0(rdram, ctx);
        goto after_3;
    // 0x804415EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804415F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804415F4: jal         0x8043EF80
    // 0x804415F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8043EF80(rdram, ctx);
        goto after_4;
    // 0x804415F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x804415FC: jal         0x8043F360
    // 0x80441600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F360(rdram, ctx);
        goto after_5;
    // 0x80441600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80441604: beq         $v0, $zero, L_80441634
    if (ctx->r2 == 0) {
        // 0x80441608: nop
    
            goto L_80441634;
    }
    // 0x80441608: nop

    // 0x8044160C: lw          $t6, 0x12C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X12C);
    // 0x80441610: lui         $t9, 0x8044
    ctx->r25 = S32(RELOC_HI16(95, 0X4CA4) << 16);
    // 0x80441614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80441618: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8044161C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80441620: lw          $t9, 0x3BA4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(95, 0X4CA4));
    // 0x80441624: jalr        $t9
    // 0x80441628: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80441628: nop

    after_6:
    // 0x8044162C: b           L_80441640
    // 0x80441630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80441640;
    // 0x80441630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441634:
    // 0x80441634: jal         0x8043F93C
    // 0x80441638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F93C(rdram, ctx);
        goto after_7;
    // 0x80441638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8044163C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441640:
    // 0x80441640: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80441644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80441648: jr          $ra
    // 0x8044164C: nop

    return;
    // 0x8044164C: nop

;}
RECOMP_FUNC void func_8006BF60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF60: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006BF64: jr          $ra
    // 0x8006BF68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006BF68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80027F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027F00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80027F04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80027F08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80027F0C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80027F10: lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X10);
    // 0x80027F14: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80027F18: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80027F1C: beql        $v0, $zero, L_80027FAC
    if (ctx->r2 == 0) {
        // 0x80027F20: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80027FAC;
    }
    goto skip_0;
    // 0x80027F20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80027F24: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80027F28: jalr        $v0
    // 0x80027F2C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80027F2C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027F30: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80027F34: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80027F38: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80027F3C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80027F40: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80027F44: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80027F48: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80027F4C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80027F50: lw          $v0, 0x168($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X168);
    // 0x80027F54: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80027F58: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x80027F5C: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    // 0x80027F60: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80027F64: lw          $t7, -0x7250($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7250);
    // 0x80027F68: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x80027F6C: lw          $t8, 0x28($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X28);
    // 0x80027F70: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80027F74: lw          $a1, 0x16C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X16C);
    // 0x80027F78: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x80027F7C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80027F80: lh          $a3, 0x0($t5)
    ctx->r7 = MEM_H(ctx->r13, 0X0);
    // 0x80027F84: lw          $a2, 0x54($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X54);
    // 0x80027F88: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80027F8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80027F90: jal         0x800245A0
    // 0x80027F94: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_800245A0(rdram, ctx);
        goto after_1;
    // 0x80027F94: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_1:
    // 0x80027F98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80027F9C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80027FA0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80027FA4: sw          $v0, 0x98($t1)
    MEM_W(0X98, ctx->r9) = ctx->r2;
    // 0x80027FA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80027FAC:
    // 0x80027FAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80027FB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80027FB4: jr          $ra
    // 0x80027FB8: nop

    return;
    // 0x80027FB8: nop

;}
RECOMP_FUNC void func_800506B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800506B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800506B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800506BC: bne         $a1, $zero, L_800506E8
    if (ctx->r5 != 0) {
        // 0x800506C0: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800506E8;
    }
    // 0x800506C0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800506C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800506C8: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x800506CC: addiu       $a1, $a1, 0x634
    ctx->r5 = ADD32(ctx->r5, 0X634);
    // 0x800506D0: jal         0x80057A28
    // 0x800506D4: addiu       $a0, $a0, -0x5A48
    ctx->r4 = ADD32(ctx->r4, -0X5A48);
    func_80057A28(rdram, ctx);
        goto after_0;
    // 0x800506D4: addiu       $a0, $a0, -0x5A48
    ctx->r4 = ADD32(ctx->r4, -0X5A48);
    after_0:
    // 0x800506D8: beql        $v0, $zero, L_80050710
    if (ctx->r2 == 0) {
        // 0x800506DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80050710;
    }
    goto skip_0;
    // 0x800506DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800506E0: b           L_80050714
    // 0x800506E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80050714;
    // 0x800506E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800506E8:
    // 0x800506E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800506EC: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x800506F0: addiu       $a1, $a1, 0x674
    ctx->r5 = ADD32(ctx->r5, 0X674);
    // 0x800506F4: jal         0x80057A28
    // 0x800506F8: addiu       $a0, $a0, -0x5A48
    ctx->r4 = ADD32(ctx->r4, -0X5A48);
    func_80057A28(rdram, ctx);
        goto after_1;
    // 0x800506F8: addiu       $a0, $a0, -0x5A48
    ctx->r4 = ADD32(ctx->r4, -0X5A48);
    after_1:
    // 0x800506FC: beql        $v0, $zero, L_80050710
    if (ctx->r2 == 0) {
        // 0x80050700: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80050710;
    }
    goto skip_1;
    // 0x80050700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80050704: b           L_80050714
    // 0x80050708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80050714;
    // 0x80050708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005070C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050710:
    // 0x80050710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80050714:
    // 0x80050714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050718: jr          $ra
    // 0x8005071C: nop

    return;
    // 0x8005071C: nop

;}
RECOMP_FUNC void func_8004A960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A960: andi        $t6, $a0, 0x3F
    ctx->r14 = ctx->r4 & 0X3F;
    // 0x8004A964: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004A968: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8004A96C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8004A970: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8004A974: jr          $ra
    // 0x8004A978: lwc1        $f0, 0xC24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC24);
    return;
    // 0x8004A978: lwc1        $f0, 0xC24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC24);
;}
