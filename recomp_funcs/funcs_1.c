#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804E7D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7D5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E7D60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804E7D64: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804E7D68: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804E7D6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E7D70: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804E7D74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804E7D78: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x804E7D7C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804E7D80: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804E7D84: lui         $t2, 0x804E
    ctx->r10 = S32(RELOC_HI16(261, 0X6D4) << 16);
    // 0x804E7D88: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804E7D8C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804E7D90: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804E7D94: lw          $t2, 0x7F34($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(261, 0X6D4));
    // 0x804E7D98: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804E7D9C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804E7DA0: jal         0x804E7AF0
    // 0x804E7DA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804E7AF0(rdram, ctx);
        goto after_0;
    // 0x804E7DA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804E7DA8: jal         0x804E7B4C
    // 0x804E7DAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804E7B4C(rdram, ctx);
        goto after_1;
    // 0x804E7DAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804E7DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E7DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E7DB8: jr          $ra
    // 0x804E7DBC: nop

    return;
    // 0x804E7DBC: nop

;}
RECOMP_FUNC void func_800592AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800592AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800592B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800592B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800592B8: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800592BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800592C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800592C4: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x800592C8: bnel        $t7, $at, L_800592DC
    if (ctx->r15 != ctx->r1) {
        // 0x800592CC: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_800592DC;
    }
    goto skip_0;
    // 0x800592CC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x800592D0: b           L_800592EC
    // 0x800592D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800592EC;
    // 0x800592D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800592D8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_800592DC:
    // 0x800592DC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x800592E0: lh          $a2, 0xC0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC0);
    // 0x800592E4: jal         0x800591EC
    // 0x800592E8: lh          $a3, 0xC2($s0)
    ctx->r7 = MEM_H(ctx->r16, 0XC2);
    func_800591EC(rdram, ctx);
        goto after_0;
    // 0x800592E8: lh          $a3, 0xC2($s0)
    ctx->r7 = MEM_H(ctx->r16, 0XC2);
    after_0:
L_800592EC:
    // 0x800592EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800592F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800592F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800592F8: jr          $ra
    // 0x800592FC: nop

    return;
    // 0x800592FC: nop

;}
RECOMP_FUNC void func_8001A68C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A68C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A694: jal         0x8001A600
    // 0x8001A698: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001A600(rdram, ctx);
        goto after_0;
    // 0x8001A698: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001A69C: beq         $v0, $zero, L_8001A6DC
    if (ctx->r2 == 0) {
        // 0x8001A6A0: lui         $a0, 0x800C
        ctx->r4 = S32(0X800C << 16);
            goto L_8001A6DC;
    }
    // 0x8001A6A0: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001A6A4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001A6A8: addiu       $a0, $a0, 0x650
    ctx->r4 = ADD32(ctx->r4, 0X650);
    // 0x8001A6AC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8001A6B0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001A6B4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001A6B8: beql        $v1, $zero, L_8001A6D4
    if (ctx->r3 == 0) {
        // 0x8001A6BC: sw          $zero, 0xC($v0)
        MEM_W(0XC, ctx->r2) = 0;
            goto L_8001A6D4;
    }
    goto skip_0;
    // 0x8001A6BC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    skip_0:
    // 0x8001A6C0: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8001A6C4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8001A6C8: b           L_8001A6D4
    // 0x8001A6CC: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
        goto L_8001A6D4;
    // 0x8001A6CC: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8001A6D0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_8001A6D4:
    // 0x8001A6D4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001A6D8: sw          $v0, 0x650($at)
    MEM_W(0X650, ctx->r1) = ctx->r2;
L_8001A6DC:
    // 0x8001A6DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A6E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A6E4: jr          $ra
    // 0x8001A6E8: nop

    return;
    // 0x8001A6E8: nop

;}
RECOMP_FUNC void func_800782CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800782CC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800782D0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800782D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800782D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800782DC: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800782E0: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800782E4: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x800782E8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800782EC: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x800782F0: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800782F4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800782F8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800782FC: sll         $t9, $v1, 8
    ctx->r25 = S32(ctx->r3 << 8);
    // 0x80078300: srl         $t0, $t9, 24
    ctx->r8 = S32(U32(ctx->r25) >> 24);
    // 0x80078304: srl         $t8, $v1, 24
    ctx->r24 = S32(U32(ctx->r3) >> 24);
    // 0x80078308: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8007830C: jal         0x80077084
    // 0x80078310: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_80077084(rdram, ctx);
        goto after_0;
    // 0x80078310: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_0:
    // 0x80078314: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80078318: lw          $a2, -0x260C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X260C);
    // 0x8007831C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80078320: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x80078324: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80078328: srl         $a1, $a1, 24
    ctx->r5 = S32(U32(ctx->r5) >> 24);
    // 0x8007832C: addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // 0x80078330: srl         $a0, $v1, 24
    ctx->r4 = S32(U32(ctx->r3) >> 24);
    // 0x80078334: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x80078338: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x8007833C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80078340: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x80078344: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x80078348: sra         $t2, $t1, 24
    ctx->r10 = S32(SIGNED(ctx->r9) >> 24);
    // 0x8007834C: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x80078350: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x80078354: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x80078358: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8007835C: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80078360: sra         $t5, $t4, 24
    ctx->r13 = S32(SIGNED(ctx->r12) >> 24);
    // 0x80078364: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x80078368: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8007836C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80078370: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80078374: sra         $t8, $t7, 24
    ctx->r24 = S32(SIGNED(ctx->r15) >> 24);
    // 0x80078378: sh          $t8, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r24;
    // 0x8007837C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80078380: sh          $zero, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = 0;
    // 0x80078384: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
    // 0x80078388: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x8007838C: sra         $t1, $t0, 24
    ctx->r9 = S32(SIGNED(ctx->r8) >> 24);
    // 0x80078390: sh          $t1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r9;
    // 0x80078394: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    // 0x80078398: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8007839C: sra         $t3, $t2, 24
    ctx->r11 = S32(SIGNED(ctx->r10) >> 24);
    // 0x800783A0: sh          $t3, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r11;
    // 0x800783A4: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x800783A8: sh          $a1, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r5;
    // 0x800783AC: sh          $a0, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r4;
    // 0x800783B0: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800783B4: sra         $t6, $t5, 24
    ctx->r14 = S32(SIGNED(ctx->r13) >> 24);
    // 0x800783B8: sh          $t6, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r14;
    // 0x800783BC: sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // 0x800783C0: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800783C4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800783C8: sra         $t9, $t8, 24
    ctx->r25 = S32(SIGNED(ctx->r24) >> 24);
    // 0x800783CC: sh          $t9, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r25;
    // 0x800783D0: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x800783D4: sh          $a1, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r5;
    // 0x800783D8: sh          $zero, 0x38($v0)
    MEM_H(0X38, ctx->r2) = 0;
    // 0x800783DC: sll         $t1, $t0, 24
    ctx->r9 = S32(ctx->r8 << 24);
    // 0x800783E0: sra         $t2, $t1, 24
    ctx->r10 = S32(SIGNED(ctx->r9) >> 24);
    // 0x800783E4: sh          $t2, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r10;
    // 0x800783E8: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x800783EC: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x800783F0: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x800783F4: ori         $t5, $t5, 0x103F
    ctx->r13 = ctx->r13 | 0X103F;
    // 0x800783F8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800783FC: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x80078400: sw          $a3, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r7;
    // 0x80078404: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80078408: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8007840C: lui         $t8, 0xB100
    ctx->r24 = S32(0XB100 << 16);
    // 0x80078410: ori         $t8, $t8, 0x204
    ctx->r24 = ctx->r24 | 0X204;
    // 0x80078414: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80078418: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x8007841C: addiu       $t9, $zero, 0x406
    ctx->r25 = ADD32(0, 0X406);
    // 0x80078420: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80078424: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80078428: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8007842C: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x80078430: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80078434: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80078438: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007843C: jr          $ra
    // 0x80078440: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80078440: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_806F974C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F974C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F9750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9754: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x806F9758: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x806F975C: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x806F9760: beq         $t8, $zero, L_806F9774
    if (ctx->r24 == 0) {
        // 0x806F9764: nop
    
            goto L_806F9774;
    }
    // 0x806F9764: nop

    // 0x806F9768: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F976C: nop

    // 0x806F9770: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
L_806F9774:
    // 0x806F9774: jal         0x806F95A0
    // 0x806F9778: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F95A0(rdram, ctx);
        goto after_0;
    // 0x806F9778: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F977C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F9780: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806F9784: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806F9788: jal         0x80065ABC
    // 0x806F978C: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x806F978C: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    after_1:
    // 0x806F9790: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F9794: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x806F9798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F979C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F97A0: jr          $ra
    // 0x806F97A4: nop

    return;
    // 0x806F97A4: nop

;}
RECOMP_FUNC void func_8001D770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D770: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8001D774: lw          $t6, -0x7250($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7250);
    // 0x8001D778: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001D77C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D780: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D784: jr          $ra
    // 0x8001D788: lw          $v0, -0x6900($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6900);
    return;
    // 0x8001D788: lw          $v0, -0x6900($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6900);
;}
RECOMP_FUNC void func_805D2558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2558: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x805D255C: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(471, 0X23E0) << 16);
    // 0x805D2560: addiu       $a1, $sp, 0x8
    ctx->r5 = ADD32(ctx->r29, 0X8);
    // 0x805D2564: addiu       $t6, $t6, 0x3E10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(471, 0X23E0));
    // 0x805D2568: addiu       $t0, $t6, 0x48
    ctx->r8 = ADD32(ctx->r14, 0X48);
    // 0x805D256C: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
L_805D2570:
    // 0x805D2570: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x805D2574: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x805D2578: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x805D257C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x805D2580: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x805D2584: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x805D2588: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x805D258C: bne         $t6, $t0, L_805D2570
    if (ctx->r14 != ctx->r8) {
        // 0x805D2590: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_805D2570;
    }
    // 0x805D2590: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x805D2594: lw          $t1, 0x1E0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1E0);
    // 0x805D2598: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D259C: lui         $t3, 0x805D
    ctx->r11 = S32(RELOC_HI16(471, 0X244C) << 16);
    // 0x805D25A0: addiu       $v1, $t1, 0x1
    ctx->r3 = ADD32(ctx->r9, 0X1);
    // 0x805D25A4: slti        $at, $v1, 0x12
    ctx->r1 = SIGNED(ctx->r3) < 0X12 ? 1 : 0;
    // 0x805D25A8: bne         $at, $zero, L_805D25B8
    if (ctx->r1 != 0) {
        // 0x805D25AC: sw          $v1, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r3;
            goto L_805D25B8;
    }
    // 0x805D25AC: sw          $v1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r3;
    // 0x805D25B0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805D25B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_805D25B8:
    // 0x805D25B8: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x805D25BC: lbu         $t3, 0x3E7C($t3)
    ctx->r11 = MEM_BU(ctx->r11, (int16_t)RELOC_LO16(471, 0X244C));
    // 0x805D25C0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805D25C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x805D25C8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x805D25CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805D25D0: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x805D25D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805D25D8: lui         $t5, 0x805D
    ctx->r13 = S32(RELOC_HI16(471, 0X2428) << 16);
    // 0x805D25DC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x805D25E0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x805D25E4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805D25E8: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x805D25EC: lh          $t5, 0x3E58($t5)
    ctx->r13 = MEM_H(ctx->r13, (int16_t)RELOC_LO16(471, 0X2428));
    // 0x805D25F0: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x805D25F4: lh          $t0, 0x144($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X144);
    // 0x805D25F8: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x805D25FC: addu        $t9, $a1, $t6
    ctx->r25 = ADD32(ctx->r5, ctx->r14);
    // 0x805D2600: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x805D2604: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x805D2608: jr          $ra
    // 0x805D260C: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x805D260C: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_807C2E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C2E04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C2E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C2E0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807C2E10: jal         0x80047090
    // 0x807C2E14: addiu       $a0, $zero, 0x46F4
    ctx->r4 = ADD32(0, 0X46F4);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807C2E14: addiu       $a0, $zero, 0x46F4
    ctx->r4 = ADD32(0, 0X46F4);
    after_0:
    // 0x807C2E18: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x807C2E1C: lui         $at, 0x46F4
    ctx->r1 = S32(0X46F4 << 16);
    // 0x807C2E20: ori         $at, $at, 0x1C00
    ctx->r1 = ctx->r1 | 0X1C00;
    // 0x807C2E24: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x807C2E28: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x807C2E2C: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x807C2E30: jal         0x8004613C
    // 0x807C2E34: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807C2E34: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    after_1:
    // 0x807C2E38: beq         $v0, $zero, L_807C2E48
    if (ctx->r2 == 0) {
        // 0x807C2E3C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_807C2E48;
    }
    // 0x807C2E3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807C2E40: jal         0x80044194
    // 0x807C2E44: nop

    func_80044194(rdram, ctx);
        goto after_2;
    // 0x807C2E44: nop

    after_2:
L_807C2E48:
    // 0x807C2E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C2E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C2E50: jr          $ra
    // 0x807C2E54: nop

    return;
    // 0x807C2E54: nop

    // 0x807C2E58: nop

    // 0x807C2E5C: nop

;}
RECOMP_FUNC void func_804693F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804693F4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804693F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804693FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80469400: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80469404: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(135, 0XE30) << 16);
    // 0x80469408: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x8046940C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80469410: addiu       $t6, $t6, -0x69B0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(135, 0XE30));
    // 0x80469414: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80469418: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8046941C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80469420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80469424: jal         0x80469580
    // 0x80469428: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80469580(rdram, ctx);
        goto after_0;
    // 0x80469428: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8046942C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80469430: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80469434: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80469438: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8046943C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80469440: jal         0x80045A34
    // 0x80469444: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80469444: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x80469448: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8046944C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80469450: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80469454: jal         0x80047AB8
    // 0x80469458: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x80469458: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8046945C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80469460: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80469464: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80469468: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8046946C: addiu       $t5, $zero, 0x100
    ctx->r13 = ADD32(0, 0X100);
    // 0x80469470: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80469474: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80469478: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046947C: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(135, 0X7A8) << 16);
    // 0x80469480: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80469484: addiu       $t6, $t6, -0x7038
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(135, 0X7A8));
    // 0x80469488: addiu       $at, $zero, 0x4081
    ctx->r1 = ADD32(0, 0X4081);
    // 0x8046948C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80469490: nop

    // 0x80469494: sh          $t0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r8;
    // 0x80469498: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8046949C: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x804694A0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804694A4: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x804694A8: nop

    // 0x804694AC: sh          $t2, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r10;
    // 0x804694B0: lwc1        $f18, 0x70($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
    // 0x804694B4: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
    // 0x804694B8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x804694BC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804694C0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804694C4: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x804694C8: nop

    // 0x804694CC: sh          $t4, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r12;
    // 0x804694D0: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x804694D4: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x804694D8: lhu         $t8, 0xC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XC);
    // 0x804694DC: bnel        $t8, $at, L_80469570
    if (ctx->r24 != ctx->r1) {
        // 0x804694E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80469570;
    }
    goto skip_0;
    // 0x804694E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804694E4: jal         0x80047090
    // 0x804694E8: addiu       $a0, $zero, 0x459C
    ctx->r4 = ADD32(0, 0X459C);
    func_80047090(rdram, ctx);
        goto after_3;
    // 0x804694E8: addiu       $a0, $zero, 0x459C
    ctx->r4 = ADD32(0, 0X459C);
    after_3:
    // 0x804694EC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804694F0: bne         $v0, $at, L_80469500
    if (ctx->r2 != ctx->r1) {
        // 0x804694F4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80469500;
    }
    // 0x804694F4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804694F8: b           L_80469528
    // 0x804694FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80469528;
    // 0x804694FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80469500:
    // 0x80469500: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80469504: lui         $a0, 0x459C
    ctx->r4 = S32(0X459C << 16);
    // 0x80469508: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x8046950C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80469510: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80469514: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80469518: jal         0x8004613C
    // 0x8046951C: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_4;
    // 0x8046951C: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    after_4:
    // 0x80469520: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x80469524: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80469528:
    // 0x80469528: beql        $a1, $zero, L_80469570
    if (ctx->r5 == 0) {
        // 0x8046952C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80469570;
    }
    goto skip_1;
    // 0x8046952C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80469530: lhu         $t1, 0xE($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0XE);
    // 0x80469534: andi        $t0, $v1, 0x3FF
    ctx->r8 = ctx->r3 & 0X3FF;
    // 0x80469538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046953C: andi        $t2, $t1, 0xFC00
    ctx->r10 = ctx->r9 & 0XFC00;
    // 0x80469540: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80469544: sh          $t3, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r11;
    // 0x80469548: jal         0x80047F9C
    // 0x8046954C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8046954C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_5:
    // 0x80469550: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80469554: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80469558: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(135, 0XE74) << 16);
    // 0x8046955C: sb          $t4, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r12;
    // 0x80469560: lwc1        $f10, -0x696C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(135, 0XE74));
    // 0x80469564: jal         0x8005FDC4
    // 0x80469568: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    func_8005FDC4(rdram, ctx);
        goto after_6;
    // 0x80469568: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    after_6:
    // 0x8046956C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80469570:
    // 0x80469570: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80469574: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80469578: jr          $ra
    // 0x8046957C: nop

    return;
    // 0x8046957C: nop

;}
RECOMP_FUNC void func_80067EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067F00: jal         0x80067CAC
    // 0x80067F04: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_80067CAC(rdram, ctx);
        goto after_0;
    // 0x80067F04: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_0:
    // 0x80067F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067F0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067F10: jr          $ra
    // 0x80067F14: nop

    return;
    // 0x80067F14: nop

;}
RECOMP_FUNC void func_80521D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521D30: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80521D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80521D38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80521D3C: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80521D40: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80521D44: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(312, 0X240) << 16);
    // 0x80521D48: sb          $a2, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r6;
    // 0x80521D4C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80521D50: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80521D54: lw          $t8, 0x1DE0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(312, 0X240));
    // 0x80521D58: lui         $a1, 0x8052
    ctx->r5 = S32(RELOC_HI16(312, 0X1E8) << 16);
    // 0x80521D5C: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x80521D60: addiu       $a1, $a1, 0x1D88
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(312, 0X1E8));
    // 0x80521D64: jal         0x80048490
    // 0x80521D68: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80521D68: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    after_0:
    // 0x80521D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80521D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80521D74: jr          $ra
    // 0x80521D78: nop

    return;
    // 0x80521D78: nop

    // 0x80521D7C: nop

;}
RECOMP_FUNC void func_805A6E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6E00: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(423, 0X470) << 16);
    // 0x805A6E04: addiu       $v0, $v0, 0x7270
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(423, 0X470));
    // 0x805A6E08: jr          $ra
    // 0x805A6E0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805A6E0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800283C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800283C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800283C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800283CC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800283D0: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x800283D4: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800283D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800283DC: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x800283E0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800283E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800283E8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800283EC: div.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800283F0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800283F4: nop

    // 0x800283F8: bc1fl       L_8002840C
    if (!c1cs) {
        // 0x800283FC: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8002840C;
    }
    goto skip_0;
    // 0x800283FC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80028400: b           L_80028424
    // 0x80028404: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80028424;
    // 0x80028404: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80028408: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8002840C:
    // 0x8002840C: nop

    // 0x80028410: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80028414: nop

    // 0x80028418: bc1f        L_80028424
    if (!c1cs) {
        // 0x8002841C: nop
    
            goto L_80028424;
    }
    // 0x8002841C: nop

    // 0x80028420: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80028424:
    // 0x80028424: jal         0x80067930
    // 0x80028428: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80028428: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8002842C: beq         $v0, $zero, L_8002845C
    if (ctx->r2 == 0) {
        // 0x80028430: lwc1        $f0, 0x1C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8002845C;
    }
    // 0x80028430: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80028434: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80028438: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8002843C: jal         0x80067D28
    // 0x80028440: nop

    func_80067D28(rdram, ctx);
        goto after_1;
    // 0x80028440: nop

    after_1:
    // 0x80028444: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x80028448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002844C: jal         0x800678F0
    // 0x80028450: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_2;
    // 0x80028450: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80028454: b           L_80028480
    // 0x80028458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80028480;
    // 0x80028458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002845C:
    // 0x8002845C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80028460: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80028464: jal         0x80067D28
    // 0x80028468: nop

    func_80067D28(rdram, ctx);
        goto after_3;
    // 0x80028468: nop

    after_3:
    // 0x8002846C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x80028470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80028474: jal         0x80067838
    // 0x80028478: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_4;
    // 0x80028478: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x8002847C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80028480:
    // 0x80028480: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80028484: jr          $ra
    // 0x80028488: nop

    return;
    // 0x80028488: nop

;}
RECOMP_FUNC void func_80442188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80442188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044218C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80442190: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80442194: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80442198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044219C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804421A0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804421A4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x804421A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x804421AC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804421B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804421B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x804421B8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804421BC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804421C0: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(95, 0X4CB4) << 16);
    // 0x804421C4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804421C8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804421CC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804421D0: lw          $t2, 0x3BB4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(95, 0X4CB4));
    // 0x804421D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804421D8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804421DC: jal         0x8043F0F4
    // 0x804421E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043F0F4(rdram, ctx);
        goto after_0;
    // 0x804421E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804421E4: jal         0x8043F07C
    // 0x804421E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043F07C(rdram, ctx);
        goto after_1;
    // 0x804421E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804421EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804421F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804421F4: jr          $ra
    // 0x804421F8: nop

    return;
    // 0x804421F8: nop

;}
RECOMP_FUNC void func_804BB1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB1BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BB1C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB1C4: jal         0x804BB604
    // 0x804BB1C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804BB604(rdram, ctx);
        goto after_0;
    // 0x804BB1C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BB1CC: beq         $v0, $zero, L_804BB1E0
    if (ctx->r2 == 0) {
        // 0x804BB1D0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804BB1E0;
    }
    // 0x804BB1D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BB1D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB1D8: jal         0x804BB4C4
    // 0x804BB1DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_804BB4C4(rdram, ctx);
        goto after_1;
    // 0x804BB1DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
L_804BB1E0:
    // 0x804BB1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BB1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BB1E8: jr          $ra
    // 0x804BB1EC: nop

    return;
    // 0x804BB1EC: nop

;}
RECOMP_FUNC void func_80709744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709744: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80709748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8070974C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80709750: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80709754: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80709758: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8070975C: jal         0x80066DE4
    // 0x80709760: neg.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = -ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80709760: neg.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = -ctx->f20.fl;
    after_0:
    // 0x80709764: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80709768: jal         0x80066E88
    // 0x8070976C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8070976C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80709770: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80709774: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80709778: lui         $t9, 0x8071
    ctx->r25 = S32(RELOC_HI16(718, 0XC60) << 16);
    // 0x8070977C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80709780: addiu       $t9, $t9, -0x61C0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(718, 0XC60));
    // 0x80709784: lwc1        $f16, 0x6C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x80709788: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8070978C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80709790: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80709794: lwc1        $f18, 0x70($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X70);
    // 0x80709798: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8070979C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x807097A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807097A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_807097A8:
    // 0x807097A8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x807097AC: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x807097B0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x807097B4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x807097B8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x807097BC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x807097C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807097C4: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x807097C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x807097CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807097D0: mul.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x807097D4: nop

    // 0x807097D8: mul.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x807097DC: nop

    // 0x807097E0: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x807097E4: nop

    // 0x807097E8: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x807097EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807097F0: mul.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x807097F4: nop

    // 0x807097F8: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x807097FC: swc1        $f8, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f8.u32l;
    // 0x80709800: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x80709804: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80709808: swc1        $f6, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f6.u32l;
    // 0x8070980C: lwc1        $f8, -0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X10);
    // 0x80709810: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x80709814: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80709818: swc1        $f10, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f10.u32l;
    // 0x8070981C: lwc1        $f4, -0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0XC);
    // 0x80709820: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x80709824: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80709828: swc1        $f6, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->f6.u32l;
    // 0x8070982C: lwc1        $f8, -0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X8);
    // 0x80709830: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80709834: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80709838: swc1        $f10, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f10.u32l;
    // 0x8070983C: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x80709840: lw          $t7, -0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X4);
    // 0x80709844: bne         $a0, $a1, L_807097A8
    if (ctx->r4 != ctx->r5) {
        // 0x80709848: sw          $t7, 0x138($t8)
        MEM_W(0X138, ctx->r24) = ctx->r15;
            goto L_807097A8;
    }
    // 0x80709848: sw          $t7, 0x138($t8)
    MEM_W(0X138, ctx->r24) = ctx->r15;
    // 0x8070984C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80709850: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80709854: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80709858: jr          $ra
    // 0x8070985C: nop

    return;
    // 0x8070985C: nop

;}
RECOMP_FUNC void eepmgr_Create(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D488: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007D48C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007D490: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007D494: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007D498: jal         0x8007CF50
    // 0x8007D49C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    eepmgr_Setup(rdram, ctx);
        goto after_0;
    // 0x8007D49C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007D4A0: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x8007D4A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8007D4A8: jal         0x8008AE20
    // 0x8007D4AC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8007D4AC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8007D4B0: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x8007D4B4: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8007D4B8: jal         0x8008AE20
    // 0x8007D4BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x8007D4BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8007D4C0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8007D4C4: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8007D4C8: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    // 0x8007D4CC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8007D4D0: addiu       $a2, $a2, -0x2C80
    ctx->r6 = ADD32(ctx->r6, -0X2C80);
    // 0x8007D4D4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8007D4D8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8007D4DC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8007D4E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8007D4E4: jal         0x80085B10
    // 0x8007D4E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    osCreateThread_recomp(rdram, ctx);
        goto after_3;
    // 0x8007D4E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_3:
    // 0x8007D4EC: jal         0x80090CC0
    // 0x8007D4F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osStartThread_recomp(rdram, ctx);
        goto after_4;
    // 0x8007D4F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x8007D4F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007D4F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007D4FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007D500: jr          $ra
    // 0x8007D504: nop

    return;
    // 0x8007D504: nop

;}
RECOMP_FUNC void func_80441BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441BE8: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x80441BEC: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x80441BF0: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(95, 0X3A98) << 16);
    // 0x80441BF4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80441BF8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80441BFC: addiu       $t8, $t8, 0x2998
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(95, 0X3A98));
    // 0x80441C00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80441C04: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80441C08: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80441C0C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80441C10: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80441C14: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80441C18: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80441C1C: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x80441C20: addu        $a2, $v1, $t7
    ctx->r6 = ADD32(ctx->r3, ctx->r15);
    // 0x80441C24: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80441C28: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80441C2C: addiu       $a2, $a2, 0x1C98
    ctx->r6 = ADD32(ctx->r6, 0X1C98);
    // 0x80441C30: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x80441C34: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80441C38: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x80441C3C: jr          $ra
    // 0x80441C40: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    return;
    // 0x80441C40: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_805C8140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C8140: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805C8144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C8148: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C814C: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C8150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C8154: lw          $v0, 0x1C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1C);
    // 0x805C8158: beq         $v0, $zero, L_805C8164
    if (ctx->r2 == 0) {
        // 0x805C815C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805C8164;
    }
    // 0x805C815C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805C8160: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
L_805C8164:
    // 0x805C8164: lw          $a0, 0x18($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X18);
    // 0x805C8168: lui         $t8, 0x805D
    ctx->r24 = S32(RELOC_HI16(447, 0X3870) << 16);
    // 0x805C816C: addiu       $t8, $t8, -0x62A0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(447, 0X3870));
    // 0x805C8170: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x805C8174: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x805C8178: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x805C817C: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x805C8180: lw          $t3, 0x1C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X1C);
    // 0x805C8184: sh          $t9, 0x168($a3)
    MEM_H(0X168, ctx->r7) = ctx->r25;
    // 0x805C8188: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x805C818C: sh          $t0, 0x16A($a3)
    MEM_H(0X16A, ctx->r7) = ctx->r8;
    // 0x805C8190: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x805C8194: sh          $t1, 0x16C($a3)
    MEM_H(0X16C, ctx->r7) = ctx->r9;
    // 0x805C8198: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
    // 0x805C819C: bne         $t3, $zero, L_805C8210
    if (ctx->r11 != 0) {
        // 0x805C81A0: sh          $t2, 0x16E($a3)
        MEM_H(0X16E, ctx->r7) = ctx->r10;
            goto L_805C8210;
    }
    // 0x805C81A0: sh          $t2, 0x16E($a3)
    MEM_H(0X16E, ctx->r7) = ctx->r10;
    // 0x805C81A4: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
    // 0x805C81A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805C81AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C81B0: bne         $v0, $at, L_805C81CC
    if (ctx->r2 != ctx->r1) {
        // 0x805C81B4: lui         $a1, 0x3E4C
        ctx->r5 = S32(0X3E4C << 16);
            goto L_805C81CC;
    }
    // 0x805C81B4: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x805C81B8: lw          $t4, 0x138($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X138);
    // 0x805C81BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805C81C0: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x805C81C4: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    // 0x805C81C8: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
L_805C81CC:
    // 0x805C81CC: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x805C81D0: slti        $at, $t7, 0x6
    ctx->r1 = SIGNED(ctx->r15) < 0X6 ? 1 : 0;
    // 0x805C81D4: bne         $at, $zero, L_805C8208
    if (ctx->r1 != 0) {
        // 0x805C81D8: sw          $t7, 0x18($a3)
        MEM_W(0X18, ctx->r7) = ctx->r15;
            goto L_805C8208;
    }
    // 0x805C81D8: sw          $t7, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r15;
    // 0x805C81DC: sw          $zero, 0x28($a3)
    MEM_W(0X28, ctx->r7) = 0;
    // 0x805C81E0: sw          $zero, 0x18($a3)
    MEM_W(0X18, ctx->r7) = 0;
    // 0x805C81E4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805C81E8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x805C81EC: jal         0x805C74C8
    // 0x805C81F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_805C74C8(rdram, ctx);
        goto after_0;
    // 0x805C81F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x805C81F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C81F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C81FC: jal         0x805C9D10
    // 0x805C8200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805C9D10(rdram, ctx);
        goto after_1;
    // 0x805C8200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x805C8204: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
L_805C8208:
    // 0x805C8208: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x805C820C: sw          $t9, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r25;
L_805C8210:
    // 0x805C8210: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805C8214: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805C8218: jal         0x80048F84
    // 0x805C821C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805C821C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x805C8220: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805C8224: jal         0x80048F84
    // 0x805C8228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805C8228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x805C822C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805C8230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C8234: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805C8238: jr          $ra
    // 0x805C823C: nop

    return;
    // 0x805C823C: nop

;}
RECOMP_FUNC void func_8064A1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A1C8: beq         $a2, $zero, L_8064A1FC
    if (ctx->r6 == 0) {
        // 0x8064A1CC: addiu       $sp, $sp, -0x10
        ctx->r29 = ADD32(ctx->r29, -0X10);
            goto L_8064A1FC;
    }
    // 0x8064A1CC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8064A1D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8064A1D4: beq         $a2, $at, L_8064A218
    if (ctx->r6 == ctx->r1) {
        // 0x8064A1D8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8064A218;
    }
    // 0x8064A1D8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8064A1DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8064A1E0: beq         $a2, $at, L_8064A230
    if (ctx->r6 == ctx->r1) {
        // 0x8064A1E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8064A230;
    }
    // 0x8064A1E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8064A1E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8064A1EC: beql        $a2, $at, L_8064A248
    if (ctx->r6 == ctx->r1) {
        // 0x8064A1F0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8064A248;
    }
    goto skip_0;
    // 0x8064A1F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x8064A1F4: b           L_8064A258
    // 0x8064A1F8: lw          $v0, 0x8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8);
        goto L_8064A258;
    // 0x8064A1F8: lw          $v0, 0x8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8);
L_8064A1FC:
    // 0x8064A1FC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8064A200: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064A204: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8064A208: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8064A20C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8064A210: b           L_8064A258
    // 0x8064A214: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
        goto L_8064A258;
    // 0x8064A214: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
L_8064A218:
    // 0x8064A218: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064A21C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8064A220: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x8064A224: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8064A228: b           L_8064A258
    // 0x8064A22C: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
        goto L_8064A258;
    // 0x8064A22C: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
L_8064A230:
    // 0x8064A230: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8064A234: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064A238: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8064A23C: b           L_8064A258
    // 0x8064A240: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
        goto L_8064A258;
    // 0x8064A240: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x8064A244: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8064A248:
    // 0x8064A248: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8064A24C: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8064A250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8064A254: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
L_8064A258:
    // 0x8064A258: lw          $v1, 0xC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC);
    // 0x8064A25C: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8064A260: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8064A264: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8064A268: addu        $t8, $a0, $v1
    ctx->r24 = ADD32(ctx->r4, ctx->r3);
    // 0x8064A26C: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8064A270: addu        $t9, $a1, $v1
    ctx->r25 = ADD32(ctx->r5, ctx->r3);
    // 0x8064A274: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8064A278: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8064A27C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064A280: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8064A284: addu        $t0, $a0, $v1
    ctx->r8 = ADD32(ctx->r4, ctx->r3);
    // 0x8064A288: addu        $t1, $a1, $v1
    ctx->r9 = ADD32(ctx->r5, ctx->r3);
    // 0x8064A28C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8064A290: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8064A294: nop

    // 0x8064A298: bc1fl       L_8064A2E4
    if (!c1cs) {
        // 0x8064A29C: lui         $at, 0x4226
        ctx->r1 = S32(0X4226 << 16);
            goto L_8064A2E4;
    }
    goto skip_1;
    // 0x8064A29C: lui         $at, 0x4226
    ctx->r1 = S32(0X4226 << 16);
    skip_1:
    // 0x8064A2A0: lwc1        $f2, 0x0($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8064A2A4: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8064A2A8: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8064A2AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8064A2B0: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8064A2B4: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8064A2B8: nop

    // 0x8064A2BC: bc1fl       L_8064A2E4
    if (!c1cs) {
        // 0x8064A2C0: lui         $at, 0x4226
        ctx->r1 = S32(0X4226 << 16);
            goto L_8064A2E4;
    }
    goto skip_2;
    // 0x8064A2C0: lui         $at, 0x4226
    ctx->r1 = S32(0X4226 << 16);
    skip_2:
    // 0x8064A2C4: sub.s       $f16, $f12, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8064A2C8: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x8064A2CC: nop

    // 0x8064A2D0: bc1fl       L_8064A2E4
    if (!c1cs) {
        // 0x8064A2D4: lui         $at, 0x4226
        ctx->r1 = S32(0X4226 << 16);
            goto L_8064A2E4;
    }
    goto skip_3;
    // 0x8064A2D4: lui         $at, 0x4226
    ctx->r1 = S32(0X4226 << 16);
    skip_3:
    // 0x8064A2D8: b           L_8064A404
    // 0x8064A2DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8064A404;
    // 0x8064A2DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8064A2E0: lui         $at, 0x4226
    ctx->r1 = S32(0X4226 << 16);
L_8064A2E4:
    // 0x8064A2E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064A2E8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8064A2EC: addu        $t2, $a0, $v1
    ctx->r10 = ADD32(ctx->r4, ctx->r3);
    // 0x8064A2F0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8064A2F4: addu        $t3, $a1, $v1
    ctx->r11 = ADD32(ctx->r5, ctx->r3);
    // 0x8064A2F8: bc1fl       L_8064A344
    if (!c1cs) {
        // 0x8064A2FC: lui         $at, 0x4288
        ctx->r1 = S32(0X4288 << 16);
            goto L_8064A344;
    }
    goto skip_4;
    // 0x8064A2FC: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    skip_4:
    // 0x8064A300: lwc1        $f2, 0x0($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8064A304: lwc1        $f12, 0x0($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8064A308: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8064A30C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8064A310: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8064A314: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x8064A318: nop

    // 0x8064A31C: bc1fl       L_8064A344
    if (!c1cs) {
        // 0x8064A320: lui         $at, 0x4288
        ctx->r1 = S32(0X4288 << 16);
            goto L_8064A344;
    }
    goto skip_5;
    // 0x8064A320: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    skip_5:
    // 0x8064A324: sub.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8064A328: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x8064A32C: nop

    // 0x8064A330: bc1fl       L_8064A344
    if (!c1cs) {
        // 0x8064A334: lui         $at, 0x4288
        ctx->r1 = S32(0X4288 << 16);
            goto L_8064A344;
    }
    goto skip_6;
    // 0x8064A334: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    skip_6:
    // 0x8064A338: b           L_8064A404
    // 0x8064A33C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8064A404;
    // 0x8064A33C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8064A340: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
L_8064A344:
    // 0x8064A344: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064A348: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8064A34C: addu        $t4, $a0, $v1
    ctx->r12 = ADD32(ctx->r4, ctx->r3);
    // 0x8064A350: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8064A354: addu        $t5, $a1, $v1
    ctx->r13 = ADD32(ctx->r5, ctx->r3);
    // 0x8064A358: bc1fl       L_8064A3A4
    if (!c1cs) {
        // 0x8064A35C: lui         $at, 0x42AC
        ctx->r1 = S32(0X42AC << 16);
            goto L_8064A3A4;
    }
    goto skip_7;
    // 0x8064A35C: lui         $at, 0x42AC
    ctx->r1 = S32(0X42AC << 16);
    skip_7:
    // 0x8064A360: lwc1        $f2, 0x0($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8064A364: lwc1        $f12, 0x0($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8064A368: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8064A36C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8064A370: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8064A374: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8064A378: nop

    // 0x8064A37C: bc1fl       L_8064A3A4
    if (!c1cs) {
        // 0x8064A380: lui         $at, 0x42AC
        ctx->r1 = S32(0X42AC << 16);
            goto L_8064A3A4;
    }
    goto skip_8;
    // 0x8064A380: lui         $at, 0x42AC
    ctx->r1 = S32(0X42AC << 16);
    skip_8:
    // 0x8064A384: sub.s       $f16, $f12, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8064A388: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x8064A38C: nop

    // 0x8064A390: bc1fl       L_8064A3A4
    if (!c1cs) {
        // 0x8064A394: lui         $at, 0x42AC
        ctx->r1 = S32(0X42AC << 16);
            goto L_8064A3A4;
    }
    goto skip_9;
    // 0x8064A394: lui         $at, 0x42AC
    ctx->r1 = S32(0X42AC << 16);
    skip_9:
    // 0x8064A398: b           L_8064A404
    // 0x8064A39C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8064A404;
    // 0x8064A39C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8064A3A0: lui         $at, 0x42AC
    ctx->r1 = S32(0X42AC << 16);
L_8064A3A4:
    // 0x8064A3A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064A3A8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8064A3AC: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x8064A3B0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8064A3B4: addu        $t7, $a1, $v1
    ctx->r15 = ADD32(ctx->r5, ctx->r3);
    // 0x8064A3B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8064A3BC: bc1f        L_8064A404
    if (!c1cs) {
        // 0x8064A3C0: nop
    
            goto L_8064A404;
    }
    // 0x8064A3C0: nop

    // 0x8064A3C4: lwc1        $f2, 0x0($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8064A3C8: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8064A3CC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8064A3D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8064A3D4: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8064A3D8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8064A3DC: nop

    // 0x8064A3E0: bc1f        L_8064A404
    if (!c1cs) {
        // 0x8064A3E4: nop
    
            goto L_8064A404;
    }
    // 0x8064A3E4: nop

    // 0x8064A3E8: sub.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8064A3EC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8064A3F0: nop

    // 0x8064A3F4: bc1f        L_8064A404
    if (!c1cs) {
        // 0x8064A3F8: nop
    
            goto L_8064A404;
    }
    // 0x8064A3F8: nop

    // 0x8064A3FC: b           L_8064A404
    // 0x8064A400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8064A404;
    // 0x8064A400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8064A404:
    // 0x8064A404: jr          $ra
    // 0x8064A408: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8064A408: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80534610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534610: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(348, 0XD68) << 16);
    // 0x80534614: addiu       $v0, $v0, 0x5378
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(348, 0XD68));
    // 0x80534618: jr          $ra
    // 0x8053461C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8053461C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800230A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800230A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800230A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800230AC: lwc1        $f4, -0x320($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X320);
    // 0x800230B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800230B4: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x800230B8: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x800230BC: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x800230C0: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x800230C4: lwc1        $f6, -0x31C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X31C);
    // 0x800230C8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800230CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800230D0: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    // 0x800230D4: jr          $ra
    // 0x800230D8: swc1        $f8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800230D8: swc1        $f8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80050AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050AFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050B04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050B08: jal         0x80064E84
    // 0x80050B0C: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x80050B0C: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    after_0:
    // 0x80050B10: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80050B14: jal         0x80064E84
    // 0x80050B18: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x80050B18: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    after_1:
    // 0x80050B1C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80050B20: jal         0x80064E84
    // 0x80050B24: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x80050B24: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    after_2:
    // 0x80050B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050B30: jr          $ra
    // 0x80050B34: nop

    return;
    // 0x80050B34: nop

;}
RECOMP_FUNC void func_80407CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80407CB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80407CB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80407CBC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80407CC0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80407CC4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80407CC8: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(11, 0X2D54) << 16);
    // 0x80407CCC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80407CD0: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80407CD4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80407CD8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80407CDC: lw          $t8, -0x58DC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(11, 0X2D54));
    // 0x80407CE0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80407CE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80407CE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80407CEC: jal         0x80048490
    // 0x80407CF0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80407CF0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80407CF4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80407CF8: jal         0x80048378
    // 0x80407CFC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80407CFC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80407D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80407D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80407D08: jr          $ra
    // 0x80407D0C: nop

    return;
    // 0x80407D0C: nop

;}
RECOMP_FUNC void func_80536264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536264: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536268: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053626C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536270: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536274: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536278: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053627C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536280: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536284: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536288: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053628C: jr          $ra
    // 0x80536290: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536290: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804A5054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A5054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A5058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A505C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804A5060: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804A5064: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804A5068: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804A506C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804A5070: lw          $v1, 0x6EE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6EE4);
    // 0x804A5074: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x804A5078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A507C: bne         $v1, $zero, L_804A50AC
    if (ctx->r3 != 0) {
        // 0x804A5080: nop
    
            goto L_804A50AC;
    }
    // 0x804A5080: nop

    // 0x804A5084: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x804A5088: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x804A508C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x804A5090: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x804A5094: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x804A5098: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804A509C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x804A50A0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x804A50A4: b           L_804A50B4
    // 0x804A50A8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
        goto L_804A50B4;
    // 0x804A50A8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_804A50AC:
    // 0x804A50AC: jal         0x804A4E34
    // 0x804A50B0: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    func_804A4E34(rdram, ctx);
        goto after_0;
    // 0x804A50B0: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_0:
L_804A50B4:
    // 0x804A50B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A50B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A50BC: jr          $ra
    // 0x804A50C0: nop

    return;
    // 0x804A50C0: nop

;}
RECOMP_FUNC void func_8070CCD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070CCD4: lwc1        $f4, 0xEC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8070CCD8: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8070CCDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8070CCE0: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD5C) << 16);
    // 0x8070CCE4: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8070CCE8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8070CCEC: nop

    // 0x8070CCF0: bc1f        L_8070CD24
    if (!c1cs) {
        // 0x8070CCF4: nop
    
            goto L_8070CD24;
    }
    // 0x8070CCF4: nop

    // 0x8070CCF8: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD58) << 16);
    // 0x8070CCFC: lwc1        $f12, -0x2C18($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD58));
    // 0x8070CD00: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8070CD04: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8070CD08: nop

    // 0x8070CD0C: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8070CD10: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8070CD14: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8070CD18: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8070CD1C: b           L_8070CD48
    // 0x8070CD20: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
        goto L_8070CD48;
    // 0x8070CD20: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_8070CD24:
    // 0x8070CD24: lwc1        $f12, -0x2C14($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD5C));
    // 0x8070CD28: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8070CD2C: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8070CD30: nop

    // 0x8070CD34: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8070CD38: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8070CD3C: mul.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8070CD40: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8070CD44: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
L_8070CD48:
    // 0x8070CD48: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8070CD4C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8070CD50: nop

    // 0x8070CD54: bc1fl       L_8070CD7C
    if (!c1cs) {
        // 0x8070CD58: lwc1        $f6, 0x4($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
            goto L_8070CD7C;
    }
    goto skip_0;
    // 0x8070CD58: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x8070CD5C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8070CD60: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8070CD64: nop

    // 0x8070CD68: bc1f        L_8070CD90
    if (!c1cs) {
        // 0x8070CD6C: nop
    
            goto L_8070CD90;
    }
    // 0x8070CD6C: nop

    // 0x8070CD70: jr          $ra
    // 0x8070CD74: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x8070CD74: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8070CD78: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
L_8070CD7C:
    // 0x8070CD7C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8070CD80: nop

    // 0x8070CD84: bc1f        L_8070CD90
    if (!c1cs) {
        // 0x8070CD88: nop
    
            goto L_8070CD90;
    }
    // 0x8070CD88: nop

    // 0x8070CD8C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_8070CD90:
    // 0x8070CD90: jr          $ra
    // 0x8070CD94: nop

    return;
    // 0x8070CD94: nop

;}
RECOMP_FUNC void func_80025768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002576C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025770: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80025774: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80025778: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8002577C: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    // 0x80025780: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80025784: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
    // 0x80025788: lw          $t9, 0xA0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA0);
    // 0x8002578C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80025790: lui         $t3, 0x8002
    ctx->r11 = S32(0X8002 << 16);
    // 0x80025794: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80025798: lw          $t0, 0xA0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XA0);
    // 0x8002579C: lw          $t2, 0x9C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X9C);
    // 0x800257A0: addiu       $t3, $t3, 0x5724
    ctx->r11 = ADD32(ctx->r11, 0X5724);
    // 0x800257A4: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800257A8: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800257AC: sw          $t3, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r11;
    // 0x800257B0: jal         0x8001D770
    // 0x800257B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x800257B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800257B8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800257BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800257C0: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x800257C4: jal         0x80067BF8
    // 0x800257C8: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x800257C8: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_1:
    // 0x800257CC: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x800257D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800257D4: jal         0x80067838
    // 0x800257D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_2;
    // 0x800257D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x800257DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800257E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800257E4: jr          $ra
    // 0x800257E8: nop

    return;
    // 0x800257E8: nop

;}
RECOMP_FUNC void func_8043F86C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F86C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043F870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F874: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F878: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x8043F87C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8043F880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F884: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8043F888: jal         0x80442188
    // 0x8043F88C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80442188(rdram, ctx);
        goto after_0;
    // 0x8043F88C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8043F890: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8043F894: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8043F898: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8043F89C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8043F8A0: swc1        $f0, 0x1C88($v0)
    MEM_W(0X1C88, ctx->r2) = ctx->f0.u32l;
    // 0x8043F8A4: jal         0x8043F310
    // 0x8043F8A8: swc1        $f0, 0x1C8C($v0)
    MEM_W(0X1C8C, ctx->r2) = ctx->f0.u32l;
    func_8043F310(rdram, ctx);
        goto after_1;
    // 0x8043F8A8: swc1        $f0, 0x1C8C($v0)
    MEM_W(0X1C8C, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x8043F8AC: jal         0x8043F1A0
    // 0x8043F8B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8043F1A0(rdram, ctx);
        goto after_2;
    // 0x8043F8B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8043F8B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043F8B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043F8BC: jr          $ra
    // 0x8043F8C0: nop

    return;
    // 0x8043F8C0: nop

;}
RECOMP_FUNC void func_806EB43C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EB43C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EB440: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806EB444: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806EB448: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806EB44C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EB450: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806EB454: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806EB458: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806EB45C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x806EB460: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806EB464: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806EB468: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x806EB46C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806EB470: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806EB474: lui         $t2, 0x806F
    ctx->r10 = S32(RELOC_HI16(670, 0XF00) << 16);
    // 0x806EB478: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806EB47C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806EB480: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806EB484: lw          $t2, -0x4930($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(670, 0XF00));
    // 0x806EB488: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806EB48C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806EB490: jal         0x806EA7F8
    // 0x806EB494: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806EA7F8(rdram, ctx);
        goto after_0;
    // 0x806EB494: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EB498: jal         0x806EA8B4
    // 0x806EB49C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806EA8B4(rdram, ctx);
        goto after_1;
    // 0x806EB49C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806EB4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EB4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EB4A8: jr          $ra
    // 0x806EB4AC: nop

    return;
    // 0x806EB4AC: nop

;}
RECOMP_FUNC void func_80007B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007B8C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80007B90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80007B94: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80007B98: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80007B9C: addiu       $s1, $s1, 0x4D10
    ctx->r17 = ADD32(ctx->r17, 0X4D10);
    // 0x80007BA0: sw          $zero, -0x5AF8($at)
    MEM_W(-0X5AF8, ctx->r1) = 0;
    // 0x80007BA4: sw          $zero, 0x1E9C($s1)
    MEM_W(0X1E9C, ctx->r17) = 0;
    // 0x80007BA8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80007BAC: lw          $a0, -0x3C4C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3C4C);
    // 0x80007BB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80007BB4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80007BB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80007BBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80007BC0: bgez        $a0, L_80007BCC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80007BC4: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_80007BCC;
    }
    // 0x80007BC4: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80007BC8: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
L_80007BCC:
    // 0x80007BCC: sra         $a0, $at, 3
    ctx->r4 = S32(SIGNED(ctx->r1) >> 3);
    // 0x80007BD0: blez        $a0, L_80007C04
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80007BD4: lui         $t0, 0x800C
        ctx->r8 = S32(0X800C << 16);
            goto L_80007C04;
    }
    // 0x80007BD4: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80007BD8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80007BDC: addiu       $v0, $t6, 0x77B0
    ctx->r2 = ADD32(ctx->r14, 0X77B0);
    // 0x80007BE0: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80007BE4: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
L_80007BE8:
    // 0x80007BE8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80007BEC: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80007BF0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80007BF4: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80007BF8: sw          $t9, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r25;
    // 0x80007BFC: bne         $at, $zero, L_80007BE8
    if (ctx->r1 != 0) {
        // 0x80007C00: sw          $t8, -0x8($v0)
        MEM_W(-0X8, ctx->r2) = ctx->r24;
            goto L_80007BE8;
    }
    // 0x80007C00: sw          $t8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r24;
L_80007C04:
    // 0x80007C04: addiu       $t0, $t0, -0x5AF9
    ctx->r8 = ADD32(ctx->r8, -0X5AF9);
    // 0x80007C08: subu        $a0, $t0, $s1
    ctx->r4 = SUB32(ctx->r8, ctx->r17);
    // 0x80007C0C: srl         $v1, $a0, 3
    ctx->r3 = S32(U32(ctx->r4) >> 3);
    // 0x80007C10: bltz        $v1, L_80007C34
    if (SIGNED(ctx->r3) < 0) {
        // 0x80007C14: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_80007C34;
    }
    // 0x80007C14: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80007C18:
    // 0x80007C18: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80007C1C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x80007C20: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x80007C24: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80007C28: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80007C2C: bgez        $v1, L_80007C18
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80007C30: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80007C18;
    }
    // 0x80007C30: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80007C34:
    // 0x80007C34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80007C38: lwc1        $f4, -0x43C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X43C8);
    // 0x80007C3C: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x80007C40: sw          $t1, 0x1E7C($s1)
    MEM_W(0X1E7C, ctx->r17) = ctx->r9;
    // 0x80007C44: jal         0x8000AC70
    // 0x80007C48: swc1        $f4, 0x1E78($s1)
    MEM_W(0X1E78, ctx->r17) = ctx->f4.u32l;
    func_8000AC70(rdram, ctx);
        goto after_0;
    // 0x80007C48: swc1        $f4, 0x1E78($s1)
    MEM_W(0X1E78, ctx->r17) = ctx->f4.u32l;
    after_0:
    // 0x80007C4C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80007C50: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80007C54: addiu       $a0, $a0, 0x4D16
    ctx->r4 = ADD32(ctx->r4, 0X4D16);
    // 0x80007C58: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x80007C5C: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
L_80007C60:
    // 0x80007C60: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80007C64: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80007C68: bne         $at, $zero, L_80007C60
    if (ctx->r1 != 0) {
        // 0x80007C6C: sh          $v1, 0x1E8A($v0)
        MEM_H(0X1E8A, ctx->r2) = ctx->r3;
            goto L_80007C60;
    }
    // 0x80007C6C: sh          $v1, 0x1E8A($v0)
    MEM_H(0X1E8A, ctx->r2) = ctx->r3;
    // 0x80007C70: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80007C74: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80007C78: sw          $zero, 0x1DB4($s1)
    MEM_W(0X1DB4, ctx->r17) = 0;
    // 0x80007C7C: sw          $zero, 0x1DBC($s1)
    MEM_W(0X1DBC, ctx->r17) = 0;
    // 0x80007C80: sw          $zero, 0x1DC0($s1)
    MEM_W(0X1DC0, ctx->r17) = 0;
    // 0x80007C84: sb          $zero, 0x1DB2($s1)
    MEM_B(0X1DB2, ctx->r17) = 0;
    // 0x80007C88: sw          $zero, 0x1DD0($s1)
    MEM_W(0X1DD0, ctx->r17) = 0;
    // 0x80007C8C: sw          $zero, 0x1E0C($s1)
    MEM_W(0X1E0C, ctx->r17) = 0;
    // 0x80007C90: sw          $zero, 0x1E5C($s1)
    MEM_W(0X1E5C, ctx->r17) = 0;
    // 0x80007C94: addiu       $a1, $a1, 0x6844
    ctx->r5 = ADD32(ctx->r5, 0X6844);
    // 0x80007C98: addiu       $a0, $a0, 0x682C
    ctx->r4 = ADD32(ctx->r4, 0X682C);
    // 0x80007C9C: jal         0x8008AE20
    // 0x80007CA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80007CA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80007CA4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80007CA8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80007CAC: addiu       $a1, $a1, 0x612C
    ctx->r5 = ADD32(ctx->r5, 0X612C);
    // 0x80007CB0: addiu       $a0, $a0, 0x6114
    ctx->r4 = ADD32(ctx->r4, 0X6114);
    // 0x80007CB4: jal         0x8008AE20
    // 0x80007CB8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80007CB8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_2:
    // 0x80007CBC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80007CC0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80007CC4: addiu       $a1, $a1, 0x60BC
    ctx->r5 = ADD32(ctx->r5, 0X60BC);
    // 0x80007CC8: addiu       $a0, $a0, 0x60A4
    ctx->r4 = ADD32(ctx->r4, 0X60A4);
    // 0x80007CCC: jal         0x8008AE20
    // 0x80007CD0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x80007CD0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x80007CD4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80007CD8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80007CDC: addiu       $a1, $a1, 0x60F4
    ctx->r5 = ADD32(ctx->r5, 0X60F4);
    // 0x80007CE0: addiu       $a0, $a0, 0x60DC
    ctx->r4 = ADD32(ctx->r4, 0X60DC);
    // 0x80007CE4: jal         0x8008AE20
    // 0x80007CE8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x80007CE8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x80007CEC: sw          $zero, 0x1DB8($s1)
    MEM_W(0X1DB8, ctx->r17) = 0;
    // 0x80007CF0: jal         0x80089630
    // 0x80007CF4: sw          $zero, 0x1B54($s1)
    MEM_W(0X1B54, ctx->r17) = 0;
    osCartRomInit_recomp(rdram, ctx);
        goto after_5;
    // 0x80007CF4: sw          $zero, 0x1B54($s1)
    MEM_W(0X1B54, ctx->r17) = 0;
    after_5:
    // 0x80007CF8: jal         0x80085E80
    // 0x80007CFC: sw          $v0, 0x138C($s1)
    MEM_W(0X138C, ctx->r17) = ctx->r2;
    osDriveRomInit(rdram, ctx);
        goto after_6;
    // 0x80007CFC: sw          $v0, 0x138C($s1)
    MEM_W(0X138C, ctx->r17) = ctx->r2;
    after_6:
    // 0x80007D00: sw          $v0, 0x1390($s1)
    MEM_W(0X1390, ctx->r17) = ctx->r2;
    // 0x80007D04: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80007D08: jal         0x8000376C
    // 0x80007D0C: lw          $a0, -0x3C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3C48);
    func_8000376C(rdram, ctx);
        goto after_7;
    // 0x80007D0C: lw          $a0, -0x3C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3C48);
    after_7:
    // 0x80007D10: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80007D14: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x80007D18: addiu       $s2, $s2, 0x6BD8
    ctx->r18 = ADD32(ctx->r18, 0X6BD8);
    // 0x80007D1C: addiu       $a2, $a2, 0x4D10
    ctx->r6 = ADD32(ctx->r6, 0X4D10);
    // 0x80007D20: addiu       $s0, $zero, 0x580
    ctx->r16 = ADD32(0, 0X580);
    // 0x80007D24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80007D28:
    // 0x80007D28: addiu       $a1, $zero, 0xB00
    ctx->r5 = ADD32(0, 0XB00);
    // 0x80007D2C: jal         0x80003698
    // 0x80007D30: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80003698(rdram, ctx);
        goto after_8;
    // 0x80007D30: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_8:
    // 0x80007D34: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80007D38: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80007D3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80007D40: sw          $v0, 0x1E80($a2)
    MEM_W(0X1E80, ctx->r6) = ctx->r2;
L_80007D44:
    // 0x80007D44: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80007D48: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x80007D4C: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x80007D50: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x80007D54: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80007D58: bne         $a0, $s0, L_80007D44
    if (ctx->r4 != ctx->r16) {
        // 0x80007D5C: sh          $zero, -0x8($v1)
        MEM_H(-0X8, ctx->r3) = 0;
            goto L_80007D44;
    }
    // 0x80007D5C: sh          $zero, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = 0;
    // 0x80007D60: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x80007D64: addiu       $t4, $t4, 0x4D1C
    ctx->r12 = ADD32(ctx->r12, 0X4D1C);
    // 0x80007D68: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80007D6C: sltu        $at, $a2, $t4
    ctx->r1 = ctx->r6 < ctx->r12 ? 1 : 0;
    // 0x80007D70: bnel        $at, $zero, L_80007D28
    if (ctx->r1 != 0) {
        // 0x80007D74: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80007D28;
    }
    goto skip_0;
    // 0x80007D74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80007D78: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80007D7C: sb          $zero, 0x2A23($s1)
    MEM_B(0X2A23, ctx->r17) = 0;
    // 0x80007D80: jal         0x80004AD8
    // 0x80007D84: sb          $t5, 0x2A22($s1)
    MEM_B(0X2A22, ctx->r17) = ctx->r13;
    func_80004AD8(rdram, ctx);
        goto after_9;
    // 0x80007D84: sb          $t5, 0x2A22($s1)
    MEM_B(0X2A22, ctx->r17) = ctx->r13;
    after_9:
    // 0x80007D88: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80007D8C: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80007D90: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80007D94: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x80007D98: addiu       $a0, $t7, 0x4860
    ctx->r4 = ADD32(ctx->r15, 0X4860);
    // 0x80007D9C: addiu       $t6, $t6, 0x4360
    ctx->r14 = ADD32(ctx->r14, 0X4360);
    // 0x80007DA0: addiu       $t8, $t8, 0x4C80
    ctx->r24 = ADD32(ctx->r24, 0X4C80);
    // 0x80007DA4: addiu       $t9, $t9, 0x4750
    ctx->r25 = ADD32(ctx->r25, 0X4750);
    // 0x80007DA8: sw          $a0, 0x1D64($s1)
    MEM_W(0X1D64, ctx->r17) = ctx->r4;
    // 0x80007DAC: sw          $t6, 0x1D68($s1)
    MEM_W(0X1D68, ctx->r17) = ctx->r14;
    // 0x80007DB0: sw          $t8, 0x1D6C($s1)
    MEM_W(0X1D6C, ctx->r17) = ctx->r24;
    // 0x80007DB4: sw          $t9, 0x1D70($s1)
    MEM_W(0X1D70, ctx->r17) = ctx->r25;
    // 0x80007DB8: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x80007DBC: lui         $a1, 0x4F
    ctx->r5 = S32(0X4F << 16);
    // 0x80007DC0: addiu       $a1, $a1, 0x3930
    ctx->r5 = ADD32(ctx->r5, 0X3930);
    // 0x80007DC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80007DC8: jal         0x800067EC
    // 0x80007DCC: sh          $t0, 0x1D74($s1)
    MEM_H(0X1D74, ctx->r17) = ctx->r8;
    func_800067EC(rdram, ctx);
        goto after_10;
    // 0x80007DCC: sh          $t0, 0x1D74($s1)
    MEM_H(0X1D74, ctx->r17) = ctx->r8;
    after_10:
    // 0x80007DD0: lui         $a1, 0xB
    ctx->r5 = S32(0XB << 16);
    // 0x80007DD4: addiu       $a1, $a1, 0x58B0
    ctx->r5 = ADD32(ctx->r5, 0X58B0);
    // 0x80007DD8: lw          $a0, 0x1D68($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007DDC: jal         0x800067EC
    // 0x80007DE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800067EC(rdram, ctx);
        goto after_11;
    // 0x80007DE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80007DE4: lui         $a1, 0xE
    ctx->r5 = S32(0XE << 16);
    // 0x80007DE8: addiu       $a1, $a1, 0x1AD0
    ctx->r5 = ADD32(ctx->r5, 0X1AD0);
    // 0x80007DEC: lw          $a0, 0x1D6C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1D6C);
    // 0x80007DF0: jal         0x800067EC
    // 0x80007DF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800067EC(rdram, ctx);
        goto after_12;
    // 0x80007DF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80007DF8: lw          $t2, 0x1D68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007DFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80007E00: lh          $s0, 0x0($t2)
    ctx->r16 = MEM_H(ctx->r10, 0X0);
    // 0x80007E04: sll         $a1, $s0, 2
    ctx->r5 = S32(ctx->r16 << 2);
    // 0x80007E08: subu        $a1, $a1, $s0
    ctx->r5 = SUB32(ctx->r5, ctx->r16);
    // 0x80007E0C: jal         0x80003698
    // 0x80007E10: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    func_80003698(rdram, ctx);
        goto after_13;
    // 0x80007E10: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    after_13:
    // 0x80007E14: sw          $v0, 0x1D78($s1)
    MEM_W(0X1D78, ctx->r17) = ctx->r2;
    // 0x80007E18: blez        $s0, L_80008078
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80007E1C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80008078;
    }
    // 0x80007E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80007E20: andi        $a2, $s0, 0x3
    ctx->r6 = ctx->r16 & 0X3;
    // 0x80007E24: beq         $a2, $zero, L_80007EB8
    if (ctx->r6 == 0) {
        // 0x80007E28: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80007EB8;
    }
    // 0x80007E28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80007E2C: sll         $v1, $zero, 2
    ctx->r3 = S32(0 << 2);
    // 0x80007E30: subu        $v1, $v1, $zero
    ctx->r3 = SUB32(ctx->r3, 0);
    // 0x80007E34: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80007E38: sll         $v0, $zero, 4
    ctx->r2 = S32(0 << 4);
L_80007E3C:
    // 0x80007E3C: lw          $t3, 0x1D68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007E40: lw          $t6, 0x1D78($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007E44: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80007E48: addu        $t1, $t3, $v0
    ctx->r9 = ADD32(ctx->r11, ctx->r2);
    // 0x80007E4C: lh          $t4, 0x1A($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X1A);
    // 0x80007E50: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x80007E54: sra         $t7, $t4, 8
    ctx->r15 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80007E58: sb          $t7, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r15;
    // 0x80007E5C: lw          $t9, 0x1D68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007E60: lw          $t1, 0x1D78($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007E64: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80007E68: lh          $t3, 0x1A($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X1A);
    // 0x80007E6C: addu        $t4, $t1, $v1
    ctx->r12 = ADD32(ctx->r9, ctx->r3);
    // 0x80007E70: sb          $t3, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r11;
    // 0x80007E74: lw          $t5, 0x1D68($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007E78: lw          $t0, 0x1D78($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007E7C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80007E80: lh          $t7, 0x1C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X1C);
    // 0x80007E84: addu        $t2, $t0, $v1
    ctx->r10 = ADD32(ctx->r8, ctx->r3);
    // 0x80007E88: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80007E8C: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    // 0x80007E90: lw          $t1, 0x1D68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007E94: lw          $t6, 0x1D78($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007E98: addu        $t3, $t1, $v0
    ctx->r11 = ADD32(ctx->r9, ctx->r2);
    // 0x80007E9C: lh          $t5, 0x1C($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X1C);
    // 0x80007EA0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80007EA4: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80007EA8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80007EAC: bne         $a0, $a1, L_80007E3C
    if (ctx->r4 != ctx->r5) {
        // 0x80007EB0: sb          $t5, 0x1($t7)
        MEM_B(0X1, ctx->r15) = ctx->r13;
            goto L_80007E3C;
    }
    // 0x80007EB0: sb          $t5, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r13;
    // 0x80007EB4: beq         $a1, $s0, L_80008078
    if (ctx->r5 == ctx->r16) {
        // 0x80007EB8: sll         $v1, $a1, 2
        ctx->r3 = S32(ctx->r5 << 2);
            goto L_80008078;
    }
L_80007EB8:
    // 0x80007EB8: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80007EBC: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80007EC0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80007EC4: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x80007EC8: sll         $a0, $s0, 4
    ctx->r4 = S32(ctx->r16 << 4);
L_80007ECC:
    // 0x80007ECC: lw          $t8, 0x1D68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007ED0: lw          $t3, 0x1D78($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007ED4: addu        $t0, $t8, $v0
    ctx->r8 = ADD32(ctx->r24, ctx->r2);
    // 0x80007ED8: lh          $t9, 0x1A($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X1A);
    // 0x80007EDC: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x80007EE0: sra         $t1, $t9, 8
    ctx->r9 = S32(SIGNED(ctx->r25) >> 8);
    // 0x80007EE4: sb          $t1, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r9;
    // 0x80007EE8: lw          $t6, 0x1D68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007EEC: lw          $t0, 0x1D78($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007EF0: addu        $t5, $t6, $v0
    ctx->r13 = ADD32(ctx->r14, ctx->r2);
    // 0x80007EF4: lh          $t8, 0x1A($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X1A);
    // 0x80007EF8: addu        $t9, $t0, $v1
    ctx->r25 = ADD32(ctx->r8, ctx->r3);
    // 0x80007EFC: sb          $t8, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r24;
    // 0x80007F00: lw          $t2, 0x1D68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007F04: lw          $t5, 0x1D78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007F08: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80007F0C: lh          $t1, 0x1C($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X1C);
    // 0x80007F10: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x80007F14: sra         $t6, $t1, 8
    ctx->r14 = S32(SIGNED(ctx->r9) >> 8);
    // 0x80007F18: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80007F1C: lw          $t0, 0x1D68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007F20: lw          $t3, 0x1D78($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007F24: addu        $t8, $t0, $v0
    ctx->r24 = ADD32(ctx->r8, ctx->r2);
    // 0x80007F28: lh          $t2, 0x1C($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X1C);
    // 0x80007F2C: addu        $t1, $t3, $v1
    ctx->r9 = ADD32(ctx->r11, ctx->r3);
    // 0x80007F30: sb          $t2, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r10;
    // 0x80007F34: lw          $t4, 0x1D68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007F38: lw          $t8, 0x1D78($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007F3C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80007F40: lh          $t6, 0x2A($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2A);
    // 0x80007F44: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80007F48: sra         $t0, $t6, 8
    ctx->r8 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80007F4C: sb          $t0, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r8;
    // 0x80007F50: lw          $t3, 0x1D68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007F54: lw          $t5, 0x1D78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007F58: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x80007F5C: lh          $t4, 0x2A($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X2A);
    // 0x80007F60: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80007F64: sb          $t4, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r12;
    // 0x80007F68: lw          $t7, 0x1D68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007F6C: lw          $t2, 0x1D78($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007F70: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80007F74: lh          $t0, 0x2C($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X2C);
    // 0x80007F78: addu        $t1, $t2, $v1
    ctx->r9 = ADD32(ctx->r10, ctx->r3);
    // 0x80007F7C: sra         $t3, $t0, 8
    ctx->r11 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80007F80: sb          $t3, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r11;
    // 0x80007F84: lw          $t5, 0x1D68($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007F88: lw          $t8, 0x1D78($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007F8C: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x80007F90: lh          $t7, 0x2C($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2C);
    // 0x80007F94: addu        $t0, $t8, $v1
    ctx->r8 = ADD32(ctx->r24, ctx->r3);
    // 0x80007F98: sb          $t7, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r15;
    // 0x80007F9C: lw          $t9, 0x1D68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007FA0: lw          $t4, 0x1D78($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007FA4: addu        $t2, $t9, $v0
    ctx->r10 = ADD32(ctx->r25, ctx->r2);
    // 0x80007FA8: lh          $t3, 0x3A($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X3A);
    // 0x80007FAC: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x80007FB0: sra         $t5, $t3, 8
    ctx->r13 = S32(SIGNED(ctx->r11) >> 8);
    // 0x80007FB4: sb          $t5, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r13;
    // 0x80007FB8: lw          $t8, 0x1D68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007FBC: lw          $t2, 0x1D78($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007FC0: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x80007FC4: lh          $t9, 0x3A($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X3A);
    // 0x80007FC8: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80007FCC: sb          $t9, 0x1B($t3)
    MEM_B(0X1B, ctx->r11) = ctx->r25;
    // 0x80007FD0: lw          $t1, 0x1D68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007FD4: lw          $t7, 0x1D78($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007FD8: addu        $t4, $t1, $v0
    ctx->r12 = ADD32(ctx->r9, ctx->r2);
    // 0x80007FDC: lh          $t5, 0x3C($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X3C);
    // 0x80007FE0: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x80007FE4: sra         $t8, $t5, 8
    ctx->r24 = S32(SIGNED(ctx->r13) >> 8);
    // 0x80007FE8: sb          $t8, 0x18($t0)
    MEM_B(0X18, ctx->r8) = ctx->r24;
    // 0x80007FEC: lw          $t2, 0x1D68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1D68);
    // 0x80007FF0: lw          $t4, 0x1D78($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1D78);
    // 0x80007FF4: addu        $t9, $t2, $v0
    ctx->r25 = ADD32(ctx->r10, ctx->r2);
    // 0x80007FF8: lh          $t1, 0x3C($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X3C);
    // 0x80007FFC: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80008000: sb          $t1, 0x19($t5)
    MEM_B(0X19, ctx->r13) = ctx->r9;
    // 0x80008004: lw          $t6, 0x1D68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1D68);
    // 0x80008008: lw          $t9, 0x1D78($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1D78);
    // 0x8000800C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80008010: lh          $t8, 0x4A($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4A);
    // 0x80008014: addu        $t3, $t9, $v1
    ctx->r11 = ADD32(ctx->r25, ctx->r3);
    // 0x80008018: sra         $t2, $t8, 8
    ctx->r10 = S32(SIGNED(ctx->r24) >> 8);
    // 0x8000801C: sb          $t2, 0x26($t3)
    MEM_B(0X26, ctx->r11) = ctx->r10;
    // 0x80008020: lw          $t4, 0x1D68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1D68);
    // 0x80008024: lw          $t7, 0x1D78($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1D78);
    // 0x80008028: addu        $t1, $t4, $v0
    ctx->r9 = ADD32(ctx->r12, ctx->r2);
    // 0x8000802C: lh          $t6, 0x4A($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X4A);
    // 0x80008030: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80008034: sb          $t6, 0x27($t8)
    MEM_B(0X27, ctx->r24) = ctx->r14;
    // 0x80008038: lw          $t0, 0x1D68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1D68);
    // 0x8000803C: lw          $t1, 0x1D78($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1D78);
    // 0x80008040: addu        $t9, $t0, $v0
    ctx->r25 = ADD32(ctx->r8, ctx->r2);
    // 0x80008044: lh          $t2, 0x4C($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X4C);
    // 0x80008048: addu        $t5, $t1, $v1
    ctx->r13 = ADD32(ctx->r9, ctx->r3);
    // 0x8000804C: sra         $t4, $t2, 8
    ctx->r12 = S32(SIGNED(ctx->r10) >> 8);
    // 0x80008050: sb          $t4, 0x24($t5)
    MEM_B(0X24, ctx->r13) = ctx->r12;
    // 0x80008054: lw          $t7, 0x1D68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1D68);
    // 0x80008058: lw          $t9, 0x1D78($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1D78);
    // 0x8000805C: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x80008060: lh          $t0, 0x4C($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X4C);
    // 0x80008064: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x80008068: addu        $t2, $t9, $v1
    ctx->r10 = ADD32(ctx->r25, ctx->r3);
    // 0x8000806C: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x80008070: bne         $v0, $a0, L_80007ECC
    if (ctx->r2 != ctx->r4) {
        // 0x80008074: sb          $t0, 0x25($t2)
        MEM_B(0X25, ctx->r10) = ctx->r8;
            goto L_80007ECC;
    }
    // 0x80008074: sb          $t0, 0x25($t2)
    MEM_B(0X25, ctx->r10) = ctx->r8;
L_80008078:
    // 0x80008078: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000807C: lw          $a1, -0x3C44($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3C44);
    // 0x80008080: jal         0x80003698
    // 0x80008084: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80003698(rdram, ctx);
        goto after_14;
    // 0x80008084: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80008088: bne         $v0, $zero, L_80008098
    if (ctx->r2 != 0) {
        // 0x8000808C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80008098;
    }
    // 0x8000808C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80008090: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80008094: sw          $zero, -0x3C44($at)
    MEM_W(-0X3C44, ctx->r1) = 0;
L_80008098:
    // 0x80008098: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000809C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800080A0: lw          $a2, -0x3C44($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X3C44);
    // 0x800080A4: jal         0x800036F0
    // 0x800080A8: addiu       $a0, $a0, 0x6F78
    ctx->r4 = ADD32(ctx->r4, 0X6F78);
    func_800036F0(rdram, ctx);
        goto after_15;
    // 0x800080A8: addiu       $a0, $a0, 0x6F78
    ctx->r4 = ADD32(ctx->r4, 0X6F78);
    after_15:
    // 0x800080AC: lw          $a0, 0x4F8C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4F8C);
    // 0x800080B0: lw          $a1, 0x1DB4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1DB4);
    // 0x800080B4: jal         0x80082210
    // 0x800080B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_16;
    // 0x800080B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x800080BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800080C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800080C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800080C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800080CC: jr          $ra
    // 0x800080D0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800080D0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80038998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003899C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800389A0: jal         0x800389BC
    // 0x800389A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800389BC(rdram, ctx);
        goto after_0;
    // 0x800389A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800389A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800389AC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800389B0: addiu       $v0, $v0, -0x6690
    ctx->r2 = ADD32(ctx->r2, -0X6690);
    // 0x800389B4: jr          $ra
    // 0x800389B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800389B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8069B5E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069B5E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069B5E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069B5EC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069B5F0: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(565, 0X1840) << 16);
    // 0x8069B5F4: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8069B5F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8069B5FC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8069B600: lw          $t8, -0x3AF0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(565, 0X1840));
    // 0x8069B604: jal         0x8069B588
    // 0x8069B608: sh          $t8, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r24;
    func_8069B588(rdram, ctx);
        goto after_0;
    // 0x8069B608: sh          $t8, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r24;
    after_0:
    // 0x8069B60C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069B610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069B614: jr          $ra
    // 0x8069B618: nop

    return;
    // 0x8069B618: nop

;}
RECOMP_FUNC void func_8070F3F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070F3F0: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(724, 0X204) << 16);
    // 0x8070F3F4: addiu       $v0, $v0, -0xA0C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(724, 0X204));
    // 0x8070F3F8: jr          $ra
    // 0x8070F3FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8070F3FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8053242C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053242C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80532430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80532434: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80532438: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(342, 0X1840) << 16);
    // 0x8053243C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80532440: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80532444: addiu       $at, $zero, 0x440C
    ctx->r1 = ADD32(0, 0X440C);
    // 0x80532448: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8053244C: nop

    // 0x80532450: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x80532454: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x80532458: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8053245C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80532460: lh          $t1, 0x2630($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(342, 0X1840));
    // 0x80532464: beq         $v0, $at, L_80532490
    if (ctx->r2 == ctx->r1) {
        // 0x80532468: sh          $t1, 0x144($a0)
        MEM_H(0X144, ctx->r4) = ctx->r9;
            goto L_80532490;
    }
    // 0x80532468: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x8053246C: addiu       $at, $zero, 0x440D
    ctx->r1 = ADD32(0, 0X440D);
    // 0x80532470: beq         $v0, $at, L_80532498
    if (ctx->r2 == ctx->r1) {
        // 0x80532474: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80532498;
    }
    // 0x80532474: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80532478: addiu       $at, $zero, 0x440E
    ctx->r1 = ADD32(0, 0X440E);
    // 0x8053247C: beq         $v0, $at, L_805324A0
    if (ctx->r2 == ctx->r1) {
        // 0x80532480: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_805324A0;
    }
    // 0x80532480: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80532484: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80532488: b           L_805324A4
    // 0x8053248C: sw          $t2, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r10;
        goto L_805324A4;
    // 0x8053248C: sw          $t2, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r10;
L_80532490:
    // 0x80532490: b           L_805324A4
    // 0x80532494: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
        goto L_805324A4;
    // 0x80532494: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
L_80532498:
    // 0x80532498: b           L_805324A4
    // 0x8053249C: sw          $t3, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r11;
        goto L_805324A4;
    // 0x8053249C: sw          $t3, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r11;
L_805324A0:
    // 0x805324A0: sw          $t4, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r12;
L_805324A4:
    // 0x805324A4: jal         0x80531D68
    // 0x805324A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80531D68(rdram, ctx);
        goto after_0;
    // 0x805324A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805324AC: beq         $v0, $zero, L_80532544
    if (ctx->r2 == 0) {
        // 0x805324B0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80532544;
    }
    // 0x805324B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805324B4: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x805324B8: lui         $t5, 0x8053
    ctx->r13 = S32(RELOC_HI16(342, 0X1830) << 16);
    // 0x805324BC: addiu       $t5, $t5, 0x2620
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(342, 0X1830));
    // 0x805324C0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x805324C4: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x805324C8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x805324CC: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(342, 0X384) << 16);
    // 0x805324D0: sw          $t7, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r15;
    // 0x805324D4: addiu       $t8, $t8, 0x1174
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(342, 0X384));
    // 0x805324D8: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x805324DC: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(342, 0X161C) << 16);
    // 0x805324E0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805324E4: addiu       $t1, $t1, 0x240C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(342, 0X161C));
    // 0x805324E8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805324EC: sb          $t0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r8;
    // 0x805324F0: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x805324F4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x805324F8: jal         0x80531740
    // 0x805324FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80531740(rdram, ctx);
        goto after_1;
    // 0x805324FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80532500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80532504: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80532508: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8053250C: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80532510: lw          $t2, 0x134($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X134);
    // 0x80532514: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1850) << 16);
    // 0x80532518: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8053251C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80532520: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80532524: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80532528: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
    // 0x8053252C: lwc1        $f18, 0x2640($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1850));
    // 0x80532530: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80532534: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80532538: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8053253C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80532540: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
L_80532544:
    // 0x80532544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80532548: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8053254C: jr          $ra
    // 0x80532550: nop

    return;
    // 0x80532550: nop

;}
RECOMP_FUNC void func_80037380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037380: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80037384: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80037388: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003738C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80037390: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x80037394: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003739C: lw          $t6, 0x14($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X14);
    // 0x800373A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800373A4: bne         $t6, $zero, L_80037440
    if (ctx->r14 != 0) {
        // 0x800373A8: nop
    
            goto L_80037440;
    }
    // 0x800373A8: nop

    // 0x800373AC: lbu         $t7, 0x22($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X22);
    // 0x800373B0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800373B4: beql        $t7, $zero, L_800373D0
    if (ctx->r15 == 0) {
        // 0x800373B8: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_800373D0;
    }
    goto skip_0;
    // 0x800373B8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    skip_0:
    // 0x800373BC: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x800373C0: andi        $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 & 0X3000;
    // 0x800373C4: bne         $t9, $zero, L_80037440
    if (ctx->r25 != 0) {
        // 0x800373C8: nop
    
            goto L_80037440;
    }
    // 0x800373C8: nop

    // 0x800373CC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_800373D0:
    // 0x800373D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800373D4: jal         0x800356E8
    // 0x800373D8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_800356E8(rdram, ctx);
        goto after_0;
    // 0x800373D8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800373DC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800373E0: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800373E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800373E8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800373EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800373F0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800373F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800373F8: bc1f        L_80037418
    if (!c1cs) {
        // 0x800373FC: nop
    
            goto L_80037418;
    }
    // 0x800373FC: nop

    // 0x80037400: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80037404: addiu       $a0, $sp, 0x2F
    ctx->r4 = ADD32(ctx->r29, 0X2F);
    // 0x80037408: jal         0x80035900
    // 0x8003740C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80035900(rdram, ctx);
        goto after_1;
    // 0x8003740C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80037410: b           L_8003742C
    // 0x80037414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8003742C;
    // 0x80037414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80037418:
    // 0x80037418: jal         0x8003588C
    // 0x8003741C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8003588C(rdram, ctx);
        goto after_2;
    // 0x8003741C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x80037420: addiu       $t0, $zero, 0x27
    ctx->r8 = ADD32(0, 0X27);
    // 0x80037424: sb          $t0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r8;
    // 0x80037428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003742C:
    // 0x8003742C: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x80037430: jal         0x8002DBE4
    // 0x80037434: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_3;
    // 0x80037434: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x80037438: b           L_80037484
    // 0x8003743C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037484;
    // 0x8003743C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037440:
    // 0x80037440: jal         0x80040E24
    // 0x80037444: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_80040E24(rdram, ctx);
        goto after_4;
    // 0x80037444: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80037448: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8003744C: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80037450: lbu         $t1, 0xADC($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XADC);
    // 0x80037454: lw          $v1, 0x138($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X138);
    // 0x80037458: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8003745C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80037460: beql        $t1, $v1, L_8003747C
    if (ctx->r9 == ctx->r3) {
        // 0x80037464: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003747C;
    }
    goto skip_1;
    // 0x80037464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80037468: lw          $t2, 0x12EC($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X12EC);
    // 0x8003746C: beql        $t2, $zero, L_8003747C
    if (ctx->r10 == 0) {
        // 0x80037470: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003747C;
    }
    goto skip_2;
    // 0x80037470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80037474: sb          $v1, 0xADC($a0)
    MEM_B(0XADC, ctx->r4) = ctx->r3;
    // 0x80037478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003747C:
    // 0x8003747C: jal         0x8004115C
    // 0x80037480: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    func_8004115C(rdram, ctx);
        goto after_5;
    // 0x80037480: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    after_5:
L_80037484:
    // 0x80037484: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80037488: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003748C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80037490: jr          $ra
    // 0x80037494: nop

    return;
    // 0x80037494: nop

;}
RECOMP_FUNC void func_806DF430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF430: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x806DF434: addiu       $at, $zero, 0x45BE
    ctx->r1 = ADD32(0, 0X45BE);
    // 0x806DF438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806DF43C: bne         $t6, $at, L_806DF450
    if (ctx->r14 != ctx->r1) {
        // 0x806DF440: nop
    
            goto L_806DF450;
    }
    // 0x806DF440: nop

    // 0x806DF444: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(643, 0XEA4) << 16);
    // 0x806DF448: jr          $ra
    // 0x806DF44C: addiu       $v0, $v0, 0x2D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(643, 0XEA4));
    return;
    // 0x806DF44C: addiu       $v0, $v0, 0x2D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(643, 0XEA4));
L_806DF450:
    // 0x806DF450: jr          $ra
    // 0x806DF454: nop

    return;
    // 0x806DF454: nop

;}
RECOMP_FUNC void func_80473DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80473DFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80473E00: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80473E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80473E08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80473E0C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80473E10: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80473E14: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80473E18: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80473E1C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80473E20: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80473E24: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80473E28: lui         $t2, 0x8047
    ctx->r10 = S32(RELOC_HI16(161, 0X1428) << 16);
    // 0x80473E2C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80473E30: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80473E34: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80473E38: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80473E3C: lw          $t2, 0x45B8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(161, 0X1428));
    // 0x80473E40: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80473E44: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80473E48: jal         0x80473D6C
    // 0x80473E4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80473D6C(rdram, ctx);
        goto after_0;
    // 0x80473E4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80473E50: jal         0x8047387C
    // 0x80473E54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8047387C(rdram, ctx);
        goto after_1;
    // 0x80473E54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80473E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80473E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80473E60: jr          $ra
    // 0x80473E64: nop

    return;
    // 0x80473E64: nop

    // 0x80473E68: nop

    // 0x80473E6C: nop

;}
RECOMP_FUNC void func_8001B3AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3AC: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8001B3B0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001B3B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B3B8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001B3BC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001B3C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001B3C4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8001B3C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001B3CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001B3D0: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8001B3D4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8001B3D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001B3DC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8001B3E0:
    // 0x8001B3E0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8001B3E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001B3E8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001B3EC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001B3F0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8001B3F4: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8001B3F8: bne         $at, $zero, L_8001B3E0
    if (ctx->r1 != 0) {
        // 0x8001B3FC: swc1        $f0, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
            goto L_8001B3E0;
    }
    // 0x8001B3FC: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x8001B400: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001B404: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
L_8001B408:
    // 0x8001B408: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8001B40C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8001B410: addiu       $t9, $t9, 0x660
    ctx->r25 = ADD32(ctx->r25, 0X660);
    // 0x8001B414: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8001B418: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8001B41C: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x8001B420: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x8001B424: beq         $at, $zero, L_8001B494
    if (ctx->r1 == 0) {
        // 0x8001B428: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8001B494;
    }
    // 0x8001B428: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8001B42C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B430: addu        $at, $at, $t0
    gpr jr_addend_8001B438 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8001B434: lw          $t0, -0x5E0($at)
    ctx->r8 = ADD32(ctx->r1, -0X5E0);
    // 0x8001B438: jr          $t0
    // 0x8001B43C: nop

    switch (jr_addend_8001B438 >> 2) {
        case 0: goto L_8001B494; break;
        case 1: goto L_8001B494; break;
        case 2: goto L_8001B440; break;
        case 3: goto L_8001B440; break;
        case 4: goto L_8001B440; break;
        default: switch_error(__func__, 0x8001B438, 0x800AFA20);
    }
    // 0x8001B43C: nop

L_8001B440:
    // 0x8001B440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001B444: jal         0x8001B6F4
    // 0x8001B448: sh          $v1, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r3;
    func_8001B6F4(rdram, ctx);
        goto after_0;
    // 0x8001B448: sh          $v1, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001B44C: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8001B450: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8001B454: lh          $v1, 0x88($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X88);
    // 0x8001B458: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001B45C: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8001B460: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
    // 0x8001B464: lh          $v0, 0x4($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4);
    // 0x8001B468: bltzl       $v0, L_8001B498
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001B46C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001B498;
    }
    goto skip_0;
    // 0x8001B46C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8001B470: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x8001B474: bnel        $t4, $v0, L_8001B498
    if (ctx->r12 != ctx->r2) {
        // 0x8001B478: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001B498;
    }
    goto skip_1;
    // 0x8001B478: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x8001B47C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8001B480: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8001B484: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x8001B488: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8001B48C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8001B490: lwc1        $f20, 0x0($t6)
    ctx->f20.u32l = MEM_W(ctx->r14, 0X0);
L_8001B494:
    // 0x8001B494: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001B498:
    // 0x8001B498: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001B49C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001B4A0: slti        $at, $v1, 0x32
    ctx->r1 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // 0x8001B4A4: bnel        $at, $zero, L_8001B408
    if (ctx->r1 != 0) {
        // 0x8001B4A8: sll         $t8, $v1, 3
        ctx->r24 = S32(ctx->r3 << 3);
            goto L_8001B408;
    }
    goto skip_2;
    // 0x8001B4A8: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    skip_2:
    // 0x8001B4AC: bgez        $s1, L_8001B530
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8001B4B0: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_8001B530;
    }
    // 0x8001B4B0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001B4B4: lh          $v0, -0x6CF0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6CF0);
    // 0x8001B4B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001B4BC: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8001B4C0: blezl       $v0, L_8001B534
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001B4C4: lw          $v0, 0x40($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X40);
            goto L_8001B534;
    }
    goto skip_3;
    // 0x8001B4C4: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
    skip_3:
    // 0x8001B4C8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8001B4CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001B4D0: nop

    // 0x8001B4D4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
L_8001B4D8:
    // 0x8001B4D8: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8001B4DC: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8001B4E0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8001B4E4: c.eq.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d == ctx->f4.d;
    // 0x8001B4E8: nop

    // 0x8001B4EC: bc1fl       L_8001B500
    if (!c1cs) {
        // 0x8001B4F0: c.lt.s      $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
            goto L_8001B500;
    }
    goto skip_4;
    // 0x8001B4F0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    skip_4:
    // 0x8001B4F4: b           L_8001B5C0
    // 0x8001B4F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8001B5C0;
    // 0x8001B4F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001B4FC: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
L_8001B500:
    // 0x8001B500: nop

    // 0x8001B504: bc1fl       L_8001B51C
    if (!c1cs) {
        // 0x8001B508: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001B51C;
    }
    goto skip_5;
    // 0x8001B508: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_5:
    // 0x8001B50C: sll         $s1, $v1, 16
    ctx->r17 = S32(ctx->r3 << 16);
    // 0x8001B510: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8001B514: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001B518: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001B51C:
    // 0x8001B51C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001B520: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001B524: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001B528: bnel        $at, $zero, L_8001B4D8
    if (ctx->r1 != 0) {
        // 0x8001B52C: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8001B4D8;
    }
    goto skip_6;
    // 0x8001B52C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    skip_6:
L_8001B530:
    // 0x8001B530: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
L_8001B534:
    // 0x8001B534: bnel        $v0, $zero, L_8001B55C
    if (ctx->r2 != 0) {
        // 0x8001B538: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8001B55C;
    }
    goto skip_7;
    // 0x8001B538: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_7:
    // 0x8001B53C: jal         0x8001B6F4
    // 0x8001B540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8001B6F4(rdram, ctx);
        goto after_1;
    // 0x8001B540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8001B544: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x8001B548: nop

    // 0x8001B54C: bc1tl       L_8001B57C
    if (c1cs) {
        // 0x8001B550: sll         $a0, $s1, 16
        ctx->r4 = S32(ctx->r17 << 16);
            goto L_8001B57C;
    }
    goto skip_8;
    // 0x8001B550: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    skip_8:
    // 0x8001B554: lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X40);
    // 0x8001B558: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8001B55C:
    // 0x8001B55C: bnel        $s0, $v0, L_8001B5C0
    if (ctx->r16 != ctx->r2) {
        // 0x8001B560: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8001B5C0;
    }
    goto skip_9;
    // 0x8001B560: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_9:
    // 0x8001B564: jal         0x8001B6F4
    // 0x8001B568: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8001B6F4(rdram, ctx);
        goto after_2;
    // 0x8001B568: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8001B56C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8001B570: nop

    // 0x8001B574: bc1f        L_8001B5BC
    if (!c1cs) {
        // 0x8001B578: sll         $a0, $s1, 16
        ctx->r4 = S32(ctx->r17 << 16);
            goto L_8001B5BC;
    }
    // 0x8001B578: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
L_8001B57C:
    // 0x8001B57C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8001B580: jal         0x8001B66C
    // 0x8001B584: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8001B66C(rdram, ctx);
        goto after_3;
    // 0x8001B584: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x8001B588: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x8001B58C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001B590: beq         $v1, $zero, L_8001B5AC
    if (ctx->r3 == 0) {
        // 0x8001B594: nop
    
            goto L_8001B5AC;
    }
    // 0x8001B594: nop

    // 0x8001B598: bne         $v1, $s0, L_8001B5B4
    if (ctx->r3 != ctx->r16) {
        // 0x8001B59C: nop
    
            goto L_8001B5B4;
    }
    // 0x8001B59C: nop

    // 0x8001B5A0: sw          $s0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r16;
    // 0x8001B5A4: b           L_8001B5C0
    // 0x8001B5A8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8001B5C0;
    // 0x8001B5A8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8001B5AC:
    // 0x8001B5AC: jal         0x80019C4C
    // 0x8001B5B0: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    func_80019C4C(rdram, ctx);
        goto after_4;
    // 0x8001B5B0: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    after_4:
L_8001B5B4:
    // 0x8001B5B4: b           L_8001B5C0
    // 0x8001B5B8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8001B5C0;
    // 0x8001B5B8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8001B5BC:
    // 0x8001B5BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001B5C0:
    // 0x8001B5C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001B5C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001B5C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001B5CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001B5D0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001B5D4: jr          $ra
    // 0x8001B5D8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8001B5D8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_805A0690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A0690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A0694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A0698: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805A069C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805A06A0: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x805A06A4: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805A06A8: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x805A06AC: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x805A06B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A06B4: jal         0x80045A34
    // 0x805A06B8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805A06B8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x805A06BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A06C0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805A06C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805A06C8: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805A06CC: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805A06D0: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x805A06D4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x805A06D8: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(408, 0XC80) << 16);
    // 0x805A06DC: addiu       $t9, $t9, -0x20
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(408, 0XC80));
    // 0x805A06E0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x805A06E4: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x805A06E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A06EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805A06F0: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x805A06F4: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x805A06F8: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A06FC: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x805A0700: sh          $zero, 0x8($t0)
    MEM_H(0X8, ctx->r8) = 0;
    // 0x805A0704: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805A0708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A070C: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x805A0710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A0714: jr          $ra
    // 0x805A0718: nop

    return;
    // 0x805A0718: nop

;}
RECOMP_FUNC void func_80474D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474D90: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474D94: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474D98: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474D9C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474DA0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474DA4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474DA8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474DAC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474DB0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474DB4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474DB8: jr          $ra
    // 0x80474DBC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474DBC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8049F438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F438: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8049F43C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8049F440: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8049F444: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8049F448: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8049F44C: jal         0x8049EF18
    // 0x8049F450: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_8049EF18(rdram, ctx);
        goto after_0;
    // 0x8049F450: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x8049F454: lh          $t7, 0x144($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X144);
    // 0x8049F458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F45C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F460: bne         $t7, $zero, L_8049F494
    if (ctx->r15 != 0) {
        // 0x8049F464: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_8049F494;
    }
    // 0x8049F464: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8049F468: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x8049F46C: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x8049F470: jal         0x8049FBAC
    // 0x8049F474: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8049FBAC(rdram, ctx);
        goto after_1;
    // 0x8049F474: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8049F478: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8049F47C: jal         0x80048378
    // 0x8049F480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048378(rdram, ctx);
        goto after_2;
    // 0x8049F480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8049F484: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8049F488: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8049F48C: b           L_8049F4AC
    // 0x8049F490: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
        goto L_8049F4AC;
    // 0x8049F490: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
L_8049F494:
    // 0x8049F494: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8049F498: jal         0x80067BBC
    // 0x8049F49C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8049F49C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8049F4A0: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
    // 0x8049F4A4: jal         0x80067818
    // 0x8049F4A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8049F4A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
L_8049F4AC:
    // 0x8049F4AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8049F4B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8049F4B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8049F4B8: jr          $ra
    // 0x8049F4BC: nop

    return;
    // 0x8049F4BC: nop

;}
RECOMP_FUNC void func_8040D09C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D09C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040D0A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040D0A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D0A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8040D0AC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8040D0B0: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8040D0B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8040D0B8: sw          $t6, -0x72DC($at)
    MEM_W(-0X72DC, ctx->r1) = ctx->r14;
    // 0x8040D0BC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8040D0C0: jal         0x80067BBC
    // 0x8040D0C4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8040D0C4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8040D0C8: jal         0x80067E68
    // 0x8040D0CC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80067E68(rdram, ctx);
        goto after_1;
    // 0x8040D0CC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_1:
    // 0x8040D0D0: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8040D0D4: jal         0x80067818
    // 0x8040D0D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8040D0D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8040D0DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040D0E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040D0E4: jr          $ra
    // 0x8040D0E8: nop

    return;
    // 0x8040D0E8: nop

;}
RECOMP_FUNC void func_807099D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807099D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x807099DC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x807099E0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x807099E4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x807099E8: nop

    // 0x807099EC: bc1fl       L_80709A1C
    if (!c1cs) {
        // 0x807099F0: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_80709A1C;
    }
    goto skip_0;
    // 0x807099F0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x807099F4: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x807099F8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x807099FC: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80709A00: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80709A04: nop

    // 0x80709A08: bc1f        L_80709A48
    if (!c1cs) {
        // 0x80709A0C: nop
    
            goto L_80709A48;
    }
    // 0x80709A0C: nop

    // 0x80709A10: jr          $ra
    // 0x80709A14: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80709A14: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80709A18: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_80709A1C:
    // 0x80709A1C: nop

    // 0x80709A20: bc1f        L_80709A48
    if (!c1cs) {
        // 0x80709A24: nop
    
            goto L_80709A48;
    }
    // 0x80709A24: nop

    // 0x80709A28: sub.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80709A2C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80709A30: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80709A34: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80709A38: nop

    // 0x80709A3C: bc1f        L_80709A48
    if (!c1cs) {
        // 0x80709A40: nop
    
            goto L_80709A48;
    }
    // 0x80709A40: nop

    // 0x80709A44: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
L_80709A48:
    // 0x80709A48: jr          $ra
    // 0x80709A4C: nop

    return;
    // 0x80709A4C: nop

;}
RECOMP_FUNC void func_800475EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800475EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800475F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800475F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800475F8: lh          $t6, 0x13E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X13E);
    // 0x800475FC: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80047600: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80047604: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80047608: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8004760C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80047610: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80047614: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80047618: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004761C: jal         0x800471D8
    // 0x80047620: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    func_800471D8(rdram, ctx);
        goto after_0;
    // 0x80047620: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    after_0:
    // 0x80047624: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80047628: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8004762C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80047630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80047634: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80047638: nop

    // 0x8004763C: slt         $v0, $t9, $t0
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80047640: jr          $ra
    // 0x80047644: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    return;
    // 0x80047644: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
;}
RECOMP_FUNC void func_805E4674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E4678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E467C: jal         0x805E420C
    // 0x805E4680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805E420C(rdram, ctx);
        goto after_0;
    // 0x805E4680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805E4684: jal         0x805E4548
    // 0x805E4688: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805E4548(rdram, ctx);
        goto after_1;
    // 0x805E4688: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805E468C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E4690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4694: jr          $ra
    // 0x805E4698: nop

    return;
    // 0x805E4698: nop

;}
RECOMP_FUNC void func_80566B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566B08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80566B0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80566B10: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80566B14: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80566B18: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80566B1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80566B20: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80566B24: beq         $v0, $zero, L_80566B34
    if (ctx->r2 == 0) {
        // 0x80566B28: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80566B34;
    }
    // 0x80566B28: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80566B2C: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x80566B30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80566B34:
    // 0x80566B34: bne         $v0, $zero, L_80566BC8
    if (ctx->r2 != 0) {
        // 0x80566B38: nop
    
            goto L_80566BC8;
    }
    // 0x80566B38: nop

    // 0x80566B3C: jal         0x805667A8
    // 0x80566B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805667A8(rdram, ctx);
        goto after_0;
    // 0x80566B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80566B44: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80566B48: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80566B4C: bne         $t7, $at, L_80566BC8
    if (ctx->r15 != ctx->r1) {
        // 0x80566B50: nop
    
            goto L_80566BC8;
    }
    // 0x80566B50: nop

    // 0x80566B54: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x80566B58: bne         $t8, $zero, L_80566BC8
    if (ctx->r24 != 0) {
        // 0x80566B5C: nop
    
            goto L_80566BC8;
    }
    // 0x80566B5C: nop

    // 0x80566B60: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80566B64: addiu       $at, $zero, 0x4174
    ctx->r1 = ADD32(0, 0X4174);
    // 0x80566B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80566B6C: bne         $v0, $at, L_80566B80
    if (ctx->r2 != ctx->r1) {
        // 0x80566B70: lui         $a1, 0x4100
        ctx->r5 = S32(0X4100 << 16);
            goto L_80566B80;
    }
    // 0x80566B70: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x80566B74: jal         0x8056698C
    // 0x80566B78: addiu       $a2, $zero, 0x4159
    ctx->r6 = ADD32(0, 0X4159);
    func_8056698C(rdram, ctx);
        goto after_1;
    // 0x80566B78: addiu       $a2, $zero, 0x4159
    ctx->r6 = ADD32(0, 0X4159);
    after_1:
    // 0x80566B7C: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_80566B80:
    // 0x80566B80: addiu       $at, $zero, 0x4175
    ctx->r1 = ADD32(0, 0X4175);
    // 0x80566B84: bne         $v0, $at, L_80566B9C
    if (ctx->r2 != ctx->r1) {
        // 0x80566B88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80566B9C;
    }
    // 0x80566B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80566B8C: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x80566B90: jal         0x8056698C
    // 0x80566B94: addiu       $a2, $zero, 0x4165
    ctx->r6 = ADD32(0, 0X4165);
    func_8056698C(rdram, ctx);
        goto after_2;
    // 0x80566B94: addiu       $a2, $zero, 0x4165
    ctx->r6 = ADD32(0, 0X4165);
    after_2:
    // 0x80566B98: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_80566B9C:
    // 0x80566B9C: addiu       $at, $zero, 0x4176
    ctx->r1 = ADD32(0, 0X4176);
    // 0x80566BA0: bne         $v0, $at, L_80566BB4
    if (ctx->r2 != ctx->r1) {
        // 0x80566BA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80566BB4;
    }
    // 0x80566BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80566BA8: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x80566BAC: jal         0x8056698C
    // 0x80566BB0: addiu       $a2, $zero, 0x4171
    ctx->r6 = ADD32(0, 0X4171);
    func_8056698C(rdram, ctx);
        goto after_3;
    // 0x80566BB0: addiu       $a2, $zero, 0x4171
    ctx->r6 = ADD32(0, 0X4171);
    after_3:
L_80566BB4:
    // 0x80566BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80566BB8: jal         0x80566900
    // 0x80566BBC: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_80566900(rdram, ctx);
        goto after_4;
    // 0x80566BBC: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_4:
    // 0x80566BC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80566BC4: sw          $t9, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r25;
L_80566BC8:
    // 0x80566BC8: jal         0x80566674
    // 0x80566BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80566674(rdram, ctx);
        goto after_5;
    // 0x80566BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80566BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80566BD4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80566BD8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80566BDC: jr          $ra
    // 0x80566BE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80566BE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800471D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800471D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800471DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800471E0: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x800471E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800471E8: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x800471EC: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x800471F0: lwc1        $f14, 0x8C($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X8C);
    // 0x800471F4: beql        $t6, $at, L_80047250
    if (ctx->r14 == ctx->r1) {
        // 0x800471F8: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_80047250;
    }
    goto skip_0;
    // 0x800471F8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_0:
    // 0x800471FC: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x80047200: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80047204: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80047208: beql        $t8, $at, L_80047250
    if (ctx->r24 == ctx->r1) {
        // 0x8004720C: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_80047250;
    }
    goto skip_1;
    // 0x8004720C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_1:
    // 0x80047210: lwc1        $f4, 0xB0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XB0);
    // 0x80047214: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80047218: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8004721C: c.eq.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl == ctx->f4.fl;
    // 0x80047220: nop

    // 0x80047224: bc1fl       L_80047250
    if (!c1cs) {
        // 0x80047228: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_80047250;
    }
    goto skip_2;
    // 0x80047228: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_2:
    // 0x8004722C: lw          $t9, 0x3F4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3F4);
    // 0x80047230: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x80047234: bnel        $t0, $zero, L_80047250
    if (ctx->r8 != 0) {
        // 0x80047238: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_80047250;
    }
    goto skip_3;
    // 0x80047238: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_3:
    // 0x8004723C: lbu         $t1, 0x3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X3);
    // 0x80047240: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80047244: bnel        $t1, $at, L_800472DC
    if (ctx->r9 != ctx->r1) {
        // 0x80047248: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_800472DC;
    }
    goto skip_4;
    // 0x80047248: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    skip_4:
    // 0x8004724C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_80047250:
    // 0x80047250: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80047254: jal         0x80081C64
    // 0x80047258: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80047258: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8004725C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80047260: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x80047264: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80047268: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004726C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80047270: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80047274: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80047278: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004727C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80047280: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80047284: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80047288: div.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8004728C: swc1        $f4, 0xB4($a1)
    MEM_W(0XB4, ctx->r5) = ctx->f4.u32l;
    // 0x80047290: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80047294: bnel        $t2, $zero, L_800472C0
    if (ctx->r10 != 0) {
        // 0x80047298: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_800472C0;
    }
    goto skip_5;
    // 0x80047298: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_5:
    // 0x8004729C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800472A0: jal         0x80058D94
    // 0x800472A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80058D94(rdram, ctx);
        goto after_1;
    // 0x800472A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x800472A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800472AC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800472B0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800472B4: b           L_800472D8
    // 0x800472B8: swc1        $f0, 0xB8($a1)
    MEM_W(0XB8, ctx->r5) = ctx->f0.u32l;
        goto L_800472D8;
    // 0x800472B8: swc1        $f0, 0xB8($a1)
    MEM_W(0XB8, ctx->r5) = ctx->f0.u32l;
    // 0x800472BC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_800472C0:
    // 0x800472C0: jal         0x80058E08
    // 0x800472C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80058E08(rdram, ctx);
        goto after_2;
    // 0x800472C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x800472C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800472CC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800472D0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800472D4: swc1        $f0, 0xBC($a1)
    MEM_W(0XBC, ctx->r5) = ctx->f0.u32l;
L_800472D8:
    // 0x800472D8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800472DC:
    // 0x800472DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800472E0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800472E4: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x800472E8: bne         $t3, $zero, L_80047314
    if (ctx->r11 != 0) {
        // 0x800472EC: lwc1        $f2, 0xB8($t5)
        ctx->f2.u32l = MEM_W(ctx->r13, 0XB8);
            goto L_80047314;
    }
    // 0x800472EC: lwc1        $f2, 0xB8($t5)
    ctx->f2.u32l = MEM_W(ctx->r13, 0XB8);
    // 0x800472F0: lw          $t6, 0x478($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X478);
    // 0x800472F4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800472F8: lwc1        $f18, 0xB4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XB4);
    // 0x800472FC: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80047300: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80047304: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80047308: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8004730C: b           L_80047334
    // 0x80047310: nop

        goto L_80047334;
    // 0x80047310: nop

L_80047314:
    // 0x80047314: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x80047318: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004731C: lwc1        $f16, 0xB4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XB4);
    // 0x80047320: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80047324: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80047328: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8004732C: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80047330: nop

L_80047334:
    // 0x80047334: jr          $ra
    // 0x80047338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80047338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8042E9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E9B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042E9B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E9B8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8042E9BC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8042E9C0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8042E9C4: jal         0x80048F84
    // 0x8042E9C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8042E9C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8042E9CC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8042E9D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8042E9D4: lw          $t6, 0x1F4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1F4);
    // 0x8042E9D8: lwc1        $f0, 0x40($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X40);
    // 0x8042E9DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8042E9E0: lwc1        $f2, 0x14($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8042E9E4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8042E9E8: nop

    // 0x8042E9EC: bc1fl       L_8042EA04
    if (!c1cs) {
        // 0x8042E9F0: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8042EA04;
    }
    goto skip_0;
    // 0x8042E9F0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x8042E9F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042E9F8: b           L_8042EA1C
    // 0x8042E9FC: swc1        $f4, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f4.u32l;
        goto L_8042EA1C;
    // 0x8042E9FC: swc1        $f4, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f4.u32l;
    // 0x8042EA00: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8042EA04:
    // 0x8042EA04: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8042EA08: bc1f        L_8042EA1C
    if (!c1cs) {
        // 0x8042EA0C: nop
    
            goto L_8042EA1C;
    }
    // 0x8042EA0C: nop

    // 0x8042EA10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042EA14: nop

    // 0x8042EA18: swc1        $f6, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f6.u32l;
L_8042EA1C:
    // 0x8042EA1C: jal         0x8042E880
    // 0x8042EA20: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8042E880(rdram, ctx);
        goto after_1;
    // 0x8042EA20: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8042EA24: jal         0x8042E824
    // 0x8042EA28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8042E824(rdram, ctx);
        goto after_2;
    // 0x8042EA28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8042EA2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042EA30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042EA34: jr          $ra
    // 0x8042EA38: nop

    return;
    // 0x8042EA38: nop

;}
RECOMP_FUNC void func_8003DE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DE00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DE04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DE08: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8003DE0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003DE10: jal         0x8004700C
    // 0x8003DE14: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003DE14: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8003DE18: beq         $v0, $zero, L_8003DF08
    if (ctx->r2 == 0) {
        // 0x8003DE1C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8003DF08;
    }
    // 0x8003DE1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003DE20: lw          $t7, 0x1F4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003DE24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DE28: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DE2C: lbu         $t8, 0x159($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X159);
    // 0x8003DE30: bnel        $t8, $at, L_8003DEE4
    if (ctx->r24 != ctx->r1) {
        // 0x8003DE34: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8003DEE4;
    }
    goto skip_0;
    // 0x8003DE34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x8003DE38: lw          $v0, 0x1F4($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X1F4);
    // 0x8003DE3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003DE40: lwc1        $f2, 0x224($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X224);
    // 0x8003DE44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003DE48: lwc1        $f6, 0x228($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X228);
    // 0x8003DE4C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003DE50: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003DE54: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003DE58: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003DE5C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8003DE60: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8003DE64: lwc1        $f16, 0x22C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X22C);
    // 0x8003DE68: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003DE6C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003DE70: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003DE74: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003DE78: nop

    // 0x8003DE7C: bc1f        L_8003DE8C
    if (!c1cs) {
        // 0x8003DE80: swc1        $f18, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
            goto L_8003DE8C;
    }
    // 0x8003DE80: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8003DE84: b           L_8003DEA8
    // 0x8003DE88: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
        goto L_8003DEA8;
    // 0x8003DE88: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_8003DE8C:
    // 0x8003DE8C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003DE90: nop

    // 0x8003DE94: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8003DE98: nop

    // 0x8003DE9C: bc1fl       L_8003DEAC
    if (!c1cs) {
        // 0x8003DEA0: lwc1        $f4, 0x4($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
            goto L_8003DEAC;
    }
    goto skip_1;
    // 0x8003DEA0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x8003DEA4: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
L_8003DEA8:
    // 0x8003DEA8: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
L_8003DEAC:
    // 0x8003DEAC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8003DEB0: nop

    // 0x8003DEB4: bc1fl       L_8003DEC4
    if (!c1cs) {
        // 0x8003DEB8: lwc1        $f6, 0x0($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8003DEC4;
    }
    goto skip_2;
    // 0x8003DEB8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x8003DEBC: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x8003DEC0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
L_8003DEC4:
    // 0x8003DEC4: lwc1        $f8, 0x78($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003DEC8: lwc1        $f18, 0x7C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003DECC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003DED0: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    // 0x8003DED4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8003DED8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8003DEDC: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    // 0x8003DEE0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_8003DEE4:
    // 0x8003DEE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003DEE8: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8003DEEC: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8003DEF0: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x8003DEF4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003DEF8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8003DEFC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003DF00: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8003DF04: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
L_8003DF08:
    // 0x8003DF08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DF0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DF10: jr          $ra
    // 0x8003DF14: nop

    return;
    // 0x8003DF14: nop

;}
RECOMP_FUNC void func_805D22B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D22B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805D22B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D22BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D22C0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D22C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805D22C8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805D22CC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805D22D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805D22D4: jal         0x805D1D0C
    // 0x805D22D8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_805D1D0C(rdram, ctx);
        goto after_0;
    // 0x805D22D8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x805D22DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805D22E0: jal         0x805D1D0C
    // 0x805D22E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805D1D0C(rdram, ctx);
        goto after_1;
    // 0x805D22E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805D22E8: lh          $t7, 0x144($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X144);
    // 0x805D22EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805D22F0: beql        $t7, $at, L_805D2304
    if (ctx->r15 == ctx->r1) {
        // 0x805D22F4: lhu         $t8, 0xC($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0XC);
            goto L_805D2304;
    }
    goto skip_0;
    // 0x805D22F4: lhu         $t8, 0xC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XC);
    skip_0:
    // 0x805D22F8: jal         0x805D2238
    // 0x805D22FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D2238(rdram, ctx);
        goto after_2;
    // 0x805D22FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805D2300: lhu         $t8, 0xC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XC);
L_805D2304:
    // 0x805D2304: addiu       $at, $zero, 0x4526
    ctx->r1 = ADD32(0, 0X4526);
    // 0x805D2308: bnel        $t8, $at, L_805D2338
    if (ctx->r24 != ctx->r1) {
        // 0x805D230C: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_805D2338;
    }
    goto skip_1;
    // 0x805D230C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x805D2310: lw          $t9, 0x1E4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E4);
    // 0x805D2314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D2318: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x805D231C: slti        $at, $t0, 0xB4
    ctx->r1 = SIGNED(ctx->r8) < 0XB4 ? 1 : 0;
    // 0x805D2320: bne         $at, $zero, L_805D2334
    if (ctx->r1 != 0) {
        // 0x805D2324: sw          $t0, 0x1E4($s0)
        MEM_W(0X1E4, ctx->r16) = ctx->r8;
            goto L_805D2334;
    }
    // 0x805D2324: sw          $t0, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r8;
    // 0x805D2328: jal         0x805D2200
    // 0x805D232C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    func_805D2200(rdram, ctx);
        goto after_3;
    // 0x805D232C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_3:
    // 0x805D2330: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
L_805D2334:
    // 0x805D2334: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_805D2338:
    // 0x805D2338: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805D233C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D2340: lw          $t2, 0x68($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X68);
    // 0x805D2344: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D2348: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805D234C: bne         $t2, $at, L_805D2380
    if (ctx->r10 != ctx->r1) {
        // 0x805D2350: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_805D2380;
    }
    // 0x805D2350: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x805D2354: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805D2358: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805D235C: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X253C) << 16);
    // 0x805D2360: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x805D2364: nop

    // 0x805D2368: bc1fl       L_805D23B0
    if (!c1cs) {
        // 0x805D236C: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_805D23B0;
    }
    goto skip_2;
    // 0x805D236C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x805D2370: lwc1        $f6, 0x3F6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(471, 0X253C));
    // 0x805D2374: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x805D2378: b           L_805D23AC
    // 0x805D237C: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
        goto L_805D23AC;
    // 0x805D237C: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
L_805D2380:
    // 0x805D2380: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x805D2384: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805D2388: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805D238C: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2540) << 16);
    // 0x805D2390: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x805D2394: nop

    // 0x805D2398: bc1fl       L_805D23B0
    if (!c1cs) {
        // 0x805D239C: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_805D23B0;
    }
    goto skip_3;
    // 0x805D239C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    skip_3:
    // 0x805D23A0: lwc1        $f16, 0x3F70($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(471, 0X2540));
    // 0x805D23A4: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x805D23A8: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
L_805D23AC:
    // 0x805D23AC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_805D23B0:
    // 0x805D23B0: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805D23B4: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x805D23B8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805D23BC: nop

    // 0x805D23C0: bc1fl       L_805D23DC
    if (!c1cs) {
        // 0x805D23C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D23DC;
    }
    goto skip_4;
    // 0x805D23C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x805D23C8: jal         0x805D3B18
    // 0x805D23CC: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    func_805D3B18(rdram, ctx);
        goto after_4;
    // 0x805D23CC: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    after_4:
    // 0x805D23D0: jal         0x805D2238
    // 0x805D23D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D2238(rdram, ctx);
        goto after_5;
    // 0x805D23D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805D23D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D23DC:
    // 0x805D23DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D23E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805D23E4: jr          $ra
    // 0x805D23E8: nop

    return;
    // 0x805D23E8: nop

;}
RECOMP_FUNC void func_806F2818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2818: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F281C: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806F2820: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806F2824: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806F2828: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806F282C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F2830: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x806F2834: lwc1        $f16, 0x50($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806F2838: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806F283C: nop

    // 0x806F2840: bc1fl       L_806F2884
    if (!c1cs) {
        // 0x806F2844: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_806F2884;
    }
    goto skip_0;
    // 0x806F2844: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x806F2848: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x806F284C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806F2850: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(679, 0X1BE8) << 16);
    // 0x806F2854: lwc1        $f4, 0x3168($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(679, 0X1BE8));
    // 0x806F2858: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806F285C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806F2860: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x806F2864: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806F2868: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x806F286C: nop

    // 0x806F2870: bc1f        L_806F28B0
    if (!c1cs) {
        // 0x806F2874: nop
    
            goto L_806F28B0;
    }
    // 0x806F2874: nop

    // 0x806F2878: jr          $ra
    // 0x806F287C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x806F287C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x806F2880: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_806F2884:
    // 0x806F2884: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(679, 0X1BEC) << 16);
    // 0x806F2888: lwc1        $f16, 0x316C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(679, 0X1BEC));
    // 0x806F288C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806F2890: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806F2894: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x806F2898: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806F289C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806F28A0: nop

    // 0x806F28A4: bc1f        L_806F28B0
    if (!c1cs) {
        // 0x806F28A8: nop
    
            goto L_806F28B0;
    }
    // 0x806F28A8: nop

    // 0x806F28AC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
L_806F28B0:
    // 0x806F28B0: jr          $ra
    // 0x806F28B4: nop

    return;
    // 0x806F28B4: nop

;}
RECOMP_FUNC void func_8041E2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E2A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8041E2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041E2A8: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8041E2AC: lwc1        $f2, 0x3C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8041E2B0: lwc1        $f14, 0x40($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8041E2B4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8041E2B8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8041E2BC: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041E2C0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8041E2C4: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x8041E2C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8041E2CC: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x8041E2D0: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8041E2D4: jal         0x80065728
    // 0x8041E2D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8041E2D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8041E2DC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8041E2E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8041E2E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8041E2E8: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8041E2EC: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8041E2F0: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8041E2F4: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8041E2F8: sh          $t6, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r14;
    // 0x8041E2FC: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x8041E300: add.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8041E304: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x8041E308: swc1        $f14, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f14.u32l;
    // 0x8041E30C: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8041E310: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x8041E314: add.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8041E318: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x8041E31C: swc1        $f16, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f16.u32l;
    // 0x8041E320: jal         0x80081C64
    // 0x8041E324: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x8041E324: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8041E328: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8041E32C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8041E330: lw          $v0, 0x3F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X3F4);
    // 0x8041E334: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8041E338: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041E33C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8041E340: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8041E344: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34F8) << 16);
    // 0x8041E348: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8041E34C: lw          $t7, 0x478($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X478);
    // 0x8041E350: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8041E354: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8041E358: lwc1        $f18, 0xB58($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34F8));
    // 0x8041E35C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8041E360: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8041E364: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041E368: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8041E36C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8041E370: lwc1        $f10, 0x30($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8041E374: mul.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8041E378: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8041E37C: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8041E380: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8041E384: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8041E388: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8041E38C: jal         0x80081C64
    // 0x8041E390: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_2;
    // 0x8041E390: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8041E394: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8041E398: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8041E39C: lw          $v0, 0x3F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X3F4);
    // 0x8041E3A0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8041E3A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041E3A8: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8041E3AC: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8041E3B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8041E3B4: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8041E3B8: lw          $t8, 0x478($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X478);
    // 0x8041E3BC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8041E3C0: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8041E3C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041E3C8: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8041E3CC: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8041E3D0: lwc1        $f8, 0x34($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X34);
    // 0x8041E3D4: mul.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8041E3D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8041E3DC: add.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x8041E3E0: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8041E3E4: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8041E3E8: swc1        $f6, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f6.u32l;
    // 0x8041E3EC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8041E3F0: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8041E3F4: swc1        $f14, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f14.u32l;
    // 0x8041E3F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041E3FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8041E400: jr          $ra
    // 0x8041E404: nop

    return;
    // 0x8041E404: nop

;}
RECOMP_FUNC void func_8042A090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042A090: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8042A094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042A098: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8042A09C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8042A0A0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8042A0A4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8042A0A8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8042A0AC: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8042A0B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8042A0B4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8042A0B8: lw          $t9, 0x20($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X20);
    // 0x8042A0BC: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8042A0C0: jal         0x80077338
    // 0x8042A0C4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x8042A0C4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    after_0:
    // 0x8042A0C8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8042A0CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8042A0D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042A0D4: jal         0x8007711C
    // 0x8042A0D8: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x8042A0D8: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_1:
    // 0x8042A0DC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8042A0E0: lui         $t2, 0xFD50
    ctx->r10 = S32(0XFD50 << 16);
    // 0x8042A0E4: lui         $t7, 0x701
    ctx->r15 = S32(0X701 << 16);
    // 0x8042A0E8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8042A0EC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8042A0F0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8042A0F4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8042A0F8: ori         $t7, $t7, 0x4050
    ctx->r15 = ctx->r15 | 0X4050;
    // 0x8042A0FC: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x8042A100: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x8042A104: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8042A108: lui         $t0, 0xE600
    ctx->r8 = S32(0XE600 << 16);
    // 0x8042A10C: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8042A110: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8042A114: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8042A118: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8042A11C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8042A120: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8042A124: lui         $t4, 0x71F
    ctx->r12 = S32(0X71F << 16);
    // 0x8042A128: ori         $t4, $t4, 0xF200
    ctx->r12 = ctx->r12 | 0XF200;
    // 0x8042A12C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8042A130: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8042A134: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8042A138: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8042A13C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8042A140: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8042A144: lui         $t0, 0xF548
    ctx->r8 = S32(0XF548 << 16);
    // 0x8042A148: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8042A14C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8042A150: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x8042A154: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8042A158: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8042A15C: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8042A160: ori         $t1, $t1, 0x4050
    ctx->r9 = ctx->r9 | 0X4050;
    // 0x8042A164: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8042A168: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8042A16C: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8042A170: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8042A174: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8042A178: ori         $t0, $t0, 0x800
    ctx->r8 = ctx->r8 | 0X800;
    // 0x8042A17C: lui         $t5, 0x7
    ctx->r13 = S32(0X7 << 16);
    // 0x8042A180: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8042A184: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8042A188: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8042A18C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8042A190: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8042A194: ori         $t5, $t5, 0xC07C
    ctx->r13 = ctx->r13 | 0XC07C;
    // 0x8042A198: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x8042A19C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8042A1A0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8042A1A4: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8042A1A8: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8042A1AC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8042A1B0: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x8042A1B4: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x8042A1B8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8042A1BC: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8042A1C0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8042A1C4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8042A1C8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8042A1CC: lui         $t2, 0x400
    ctx->r10 = S32(0X400 << 16);
    // 0x8042A1D0: ori         $t2, $t2, 0x38DF
    ctx->r10 = ctx->r10 | 0X38DF;
    // 0x8042A1D4: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8042A1D8: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8042A1DC: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8042A1E0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8042A1E4: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(47, 0X908) << 16);
    // 0x8042A1E8: addiu       $t7, $t7, -0x5928
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(47, 0X908));
    // 0x8042A1EC: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x8042A1F0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8042A1F4: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8042A1F8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8042A1FC: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8042A200: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8042A204: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8042A208: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8042A20C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8042A210: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8042A214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042A218: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8042A21C: jr          $ra
    // 0x8042A220: nop

    return;
    // 0x8042A220: nop

;}
RECOMP_FUNC void func_804EF0EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF0EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804EF0F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF0F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x804EF0F8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x804EF0FC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804EF100: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x804EF104: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x804EF108: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x804EF10C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804EF110: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x804EF114: bnel        $t6, $zero, L_804EF1D8
    if (ctx->r14 != 0) {
        // 0x804EF118: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804EF1D8;
    }
    goto skip_0;
    // 0x804EF118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804EF11C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x804EF120: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804EF124: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804EF128: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804EF12C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x804EF130: nop

    // 0x804EF134: bc1fl       L_804EF1D8
    if (!c1cs) {
        // 0x804EF138: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804EF1D8;
    }
    goto skip_1;
    // 0x804EF138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804EF13C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804EF140: lwc1        $f18, 0xC8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804EF144: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x804EF148: nop

    // 0x804EF14C: bc1fl       L_804EF1D8
    if (!c1cs) {
        // 0x804EF150: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804EF1D8;
    }
    goto skip_2;
    // 0x804EF150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804EF154: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804EF158: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x804EF15C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x804EF160: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x804EF164: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x804EF168: lui         $a2, 0x804F
    ctx->r6 = S32(RELOC_HI16(267, 0XF90) << 16);
    // 0x804EF16C: addiu       $a2, $a2, -0x2E0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(267, 0XF90));
    // 0x804EF170: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x804EF174: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804EF178: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x804EF17C: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x804EF180: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x804EF184: lwc1        $f16, 0x44($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X44);
    // 0x804EF188: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x804EF18C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x804EF190: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804EF194: addiu       $a0, $zero, 0x4008
    ctx->r4 = ADD32(0, 0X4008);
    // 0x804EF198: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x804EF19C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x804EF1A0: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x804EF1A4: jalr        $t9
    // 0x804EF1A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804EF1A8: nop

    after_0:
    // 0x804EF1AC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x804EF1B0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x804EF1B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804EF1B8: sw          $t0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r8;
    // 0x804EF1BC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x804EF1C0: jal         0x80067EB8
    // 0x804EF1C4: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    func_80067EB8(rdram, ctx);
        goto after_1;
    // 0x804EF1C4: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    after_1:
    // 0x804EF1C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x804EF1CC: jal         0x80067818
    // 0x804EF1D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x804EF1D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x804EF1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EF1D8:
    // 0x804EF1D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804EF1DC: jr          $ra
    // 0x804EF1E0: nop

    return;
    // 0x804EF1E0: nop

;}
RECOMP_FUNC void func_8069EBDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069EBDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069EBE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069EBE4: jal         0x8069E4E8
    // 0x8069EBE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8069E4E8(rdram, ctx);
        goto after_0;
    // 0x8069EBE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069EBEC: jal         0x80045BD8
    // 0x8069EBF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8069EBF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8069EBF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069EBF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069EBFC: jr          $ra
    // 0x8069EC00: nop

    return;
    // 0x8069EC00: nop

;}
RECOMP_FUNC void func_8007C1A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C1A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007C1A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C1A8: jal         0x8007CBC0
    // 0x8007C1AC: nop

    func_8007CBC0(rdram, ctx);
        goto after_0;
    // 0x8007C1AC: nop

    after_0:
    // 0x8007C1B0: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8007C1B4: lw          $t6, -0x6600($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6600);
    // 0x8007C1B8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8007C1BC: sw          $zero, -0x2598($at)
    MEM_W(-0X2598, ctx->r1) = 0;
    // 0x8007C1C0: bne         $t6, $zero, L_8007C200
    if (ctx->r14 != 0) {
        // 0x8007C1C4: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_8007C200;
    }
    // 0x8007C1C4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C1C8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C1CC: addiu       $a0, $a0, -0x2108
    ctx->r4 = ADD32(ctx->r4, -0X2108);
    // 0x8007C1D0: jal         0x8007FB34
    // 0x8007C1D4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    pad_push_also(rdram, ctx);
        goto after_1;
    // 0x8007C1D4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x8007C1D8: beq         $v0, $zero, L_8007C2D4
    if (ctx->r2 == 0) {
        // 0x8007C1DC: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_8007C2D4;
    }
    // 0x8007C1DC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C1E0: addiu       $a0, $a0, -0x2108
    ctx->r4 = ADD32(ctx->r4, -0X2108);
    // 0x8007C1E4: jal         0x8007FB50
    // 0x8007C1E8: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    pad_on_trigger(rdram, ctx);
        goto after_2;
    // 0x8007C1E8: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_2:
    // 0x8007C1EC: beq         $v0, $zero, L_8007C2D4
    if (ctx->r2 == 0) {
        // 0x8007C1F0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8007C2D4;
    }
    // 0x8007C1F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007C1F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8007C1F8: b           L_8007C2D4
    // 0x8007C1FC: sw          $t7, -0x6600($at)
    MEM_W(-0X6600, ctx->r1) = ctx->r15;
        goto L_8007C2D4;
    // 0x8007C1FC: sw          $t7, -0x6600($at)
    MEM_W(-0X6600, ctx->r1) = ctx->r15;
L_8007C200:
    // 0x8007C200: addiu       $a0, $a0, -0x2108
    ctx->r4 = ADD32(ctx->r4, -0X2108);
    // 0x8007C204: jal         0x8007FB34
    // 0x8007C208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    pad_push_also(rdram, ctx);
        goto after_3;
    // 0x8007C208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8007C20C: beq         $v0, $zero, L_8007C22C
    if (ctx->r2 == 0) {
        // 0x8007C210: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_8007C22C;
    }
    // 0x8007C210: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C214: addiu       $a0, $a0, -0x2108
    ctx->r4 = ADD32(ctx->r4, -0X2108);
    // 0x8007C218: jal         0x8007FB50
    // 0x8007C21C: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    pad_on_trigger(rdram, ctx);
        goto after_4;
    // 0x8007C21C: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_4:
    // 0x8007C220: beq         $v0, $zero, L_8007C22C
    if (ctx->r2 == 0) {
        // 0x8007C224: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_8007C22C;
    }
    // 0x8007C224: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8007C228: sw          $zero, -0x6600($at)
    MEM_W(-0X6600, ctx->r1) = 0;
L_8007C22C:
    // 0x8007C22C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C230: addiu       $a0, $a0, -0x2108
    ctx->r4 = ADD32(ctx->r4, -0X2108);
    // 0x8007C234: jal         0x8007FB34
    // 0x8007C238: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    pad_push_also(rdram, ctx);
        goto after_5;
    // 0x8007C238: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_5:
    // 0x8007C23C: beq         $v0, $zero, L_8007C278
    if (ctx->r2 == 0) {
        // 0x8007C240: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_8007C278;
    }
    // 0x8007C240: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C244: addiu       $a0, $a0, -0x2108
    ctx->r4 = ADD32(ctx->r4, -0X2108);
    // 0x8007C248: jal         0x8007FB50
    // 0x8007C24C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    pad_on_trigger(rdram, ctx);
        goto after_6;
    // 0x8007C24C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8007C250: beq         $v0, $zero, L_8007C278
    if (ctx->r2 == 0) {
        // 0x8007C254: lui         $t8, 0x8011
        ctx->r24 = S32(0X8011 << 16);
            goto L_8007C278;
    }
    // 0x8007C254: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8007C258: addiu       $t8, $t8, -0x25F0
    ctx->r24 = ADD32(ctx->r24, -0X25F0);
    // 0x8007C25C: lw          $t9, 0x58($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X58);
    // 0x8007C260: blez        $t9, L_8007C278
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8007C264: nop
    
            goto L_8007C278;
    }
    // 0x8007C264: nop

    // 0x8007C268: lw          $t0, 0x58($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X58);
    // 0x8007C26C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8007C270: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007C274: sw          $t1, -0x2598($at)
    MEM_W(-0X2598, ctx->r1) = ctx->r9;
L_8007C278:
    // 0x8007C278: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C27C: addiu       $a0, $a0, -0x2108
    ctx->r4 = ADD32(ctx->r4, -0X2108);
    // 0x8007C280: jal         0x8007FB34
    // 0x8007C284: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    pad_push_also(rdram, ctx);
        goto after_7;
    // 0x8007C284: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_7:
    // 0x8007C288: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8007C28C: beq         $v0, $zero, L_8007C2D0
    if (ctx->r2 == 0) {
        // 0x8007C290: addiu       $v1, $v1, -0x25F0
        ctx->r3 = ADD32(ctx->r3, -0X25F0);
            goto L_8007C2D0;
    }
    // 0x8007C290: addiu       $v1, $v1, -0x25F0
    ctx->r3 = ADD32(ctx->r3, -0X25F0);
    // 0x8007C294: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C298: addiu       $a0, $a0, -0x2108
    ctx->r4 = ADD32(ctx->r4, -0X2108);
    // 0x8007C29C: jal         0x8007FB50
    // 0x8007C2A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    pad_on_trigger(rdram, ctx);
        goto after_8;
    // 0x8007C2A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8007C2A4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8007C2A8: beq         $v0, $zero, L_8007C2D0
    if (ctx->r2 == 0) {
        // 0x8007C2AC: addiu       $v1, $v1, -0x25F0
        ctx->r3 = ADD32(ctx->r3, -0X25F0);
            goto L_8007C2D0;
    }
    // 0x8007C2AC: addiu       $v1, $v1, -0x25F0
    ctx->r3 = ADD32(ctx->r3, -0X25F0);
    // 0x8007C2B0: lw          $t2, 0x58($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X58);
    // 0x8007C2B4: slti        $at, $t2, 0x64
    ctx->r1 = SIGNED(ctx->r10) < 0X64 ? 1 : 0;
    // 0x8007C2B8: beql        $at, $zero, L_8007C2D4
    if (ctx->r1 == 0) {
        // 0x8007C2BC: lw          $zero, 0x58($v1)
        (void)(MEM_W(ctx->r3, 0X58));
            goto L_8007C2D4;
    }
    goto skip_0;
    // 0x8007C2BC: lw          $zero, 0x58($v1)
    (void)(MEM_W(ctx->r3, 0X58));
    skip_0:
    // 0x8007C2C0: lw          $t3, 0x58($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X58);
    // 0x8007C2C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8007C2C8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007C2CC: sw          $t4, -0x2598($at)
    MEM_W(-0X2598, ctx->r1) = ctx->r12;
L_8007C2D0:
    // 0x8007C2D0: lw          $zero, 0x58($v1)
    (void)(MEM_W(ctx->r3, 0X58));
L_8007C2D4:
    // 0x8007C2D4: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x8007C2D8: addiu       $t5, $t5, -0x25F0
    ctx->r13 = ADD32(ctx->r13, -0X25F0);
    // 0x8007C2DC: lw          $zero, 0x58($t5)
    (void)(MEM_W(ctx->r13, 0X58));
    // 0x8007C2E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C2E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007C2E8: jr          $ra
    // 0x8007C2EC: nop

    return;
    // 0x8007C2EC: nop

;}
RECOMP_FUNC void func_80674F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80674F50: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80674F54: addiu       $at, $zero, 0x4082
    ctx->r1 = ADD32(0, 0X4082);
    // 0x80674F58: beq         $v0, $at, L_80674F78
    if (ctx->r2 == ctx->r1) {
        // 0x80674F5C: addiu       $at, $zero, 0x4083
        ctx->r1 = ADD32(0, 0X4083);
            goto L_80674F78;
    }
    // 0x80674F5C: addiu       $at, $zero, 0x4083
    ctx->r1 = ADD32(0, 0X4083);
    // 0x80674F60: beq         $v0, $at, L_80674F78
    if (ctx->r2 == ctx->r1) {
        // 0x80674F64: addiu       $at, $zero, 0x4084
        ctx->r1 = ADD32(0, 0X4084);
            goto L_80674F78;
    }
    // 0x80674F64: addiu       $at, $zero, 0x4084
    ctx->r1 = ADD32(0, 0X4084);
    // 0x80674F68: beq         $v0, $at, L_80674F84
    if (ctx->r2 == ctx->r1) {
        // 0x80674F6C: nop
    
            goto L_80674F84;
    }
    // 0x80674F6C: nop

    // 0x80674F70: b           L_80674F90
    // 0x80674F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80674F90;
    // 0x80674F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80674F78:
    // 0x80674F78: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(532, 0X47C) << 16);
    // 0x80674F7C: jr          $ra
    // 0x80674F80: addiu       $v0, $v0, 0x53CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(532, 0X47C));
    return;
    // 0x80674F80: addiu       $v0, $v0, 0x53CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(532, 0X47C));
L_80674F84:
    // 0x80674F84: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(532, 0X538) << 16);
    // 0x80674F88: jr          $ra
    // 0x80674F8C: addiu       $v0, $v0, 0x5488
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(532, 0X538));
    return;
    // 0x80674F8C: addiu       $v0, $v0, 0x5488
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(532, 0X538));
L_80674F90:
    // 0x80674F90: jr          $ra
    // 0x80674F94: nop

    return;
    // 0x80674F94: nop

;}
RECOMP_FUNC void func_807ABA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ABA50: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x807ABA54: addiu       $at, $zero, 0x4515
    ctx->r1 = ADD32(0, 0X4515);
    // 0x807ABA58: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(856, 0XA38) << 16);
    // 0x807ABA5C: bne         $t6, $at, L_807ABA70
    if (ctx->r14 != ctx->r1) {
        // 0x807ABA60: addiu       $v0, $v0, -0x3B78
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(856, 0XA38));
            goto L_807ABA70;
    }
    // 0x807ABA60: addiu       $v0, $v0, -0x3B78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(856, 0XA38));
    // 0x807ABA64: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(856, 0XA38) << 16);
    // 0x807ABA68: jr          $ra
    // 0x807ABA6C: addiu       $v0, $v0, -0x3B78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(856, 0XA38));
    return;
    // 0x807ABA6C: addiu       $v0, $v0, -0x3B78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(856, 0XA38));
L_807ABA70:
    // 0x807ABA70: jr          $ra
    // 0x807ABA74: nop

    return;
    // 0x807ABA74: nop

;}
RECOMP_FUNC void func_805AE264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE264: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE268: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE26C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE270: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE274: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE278: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE27C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE280: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE284: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE288: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE28C: jr          $ra
    // 0x805AE290: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE290: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8007CDCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CDCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007CDD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CDD4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007CDD8: lw          $a0, 0x218($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X218);
    // 0x8007CDDC: lw          $a1, 0x44($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X44);
    // 0x8007CDE0: jal         0x8007451C
    // 0x8007CDE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8007451C(rdram, ctx);
        goto after_0;
    // 0x8007CDE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007CDE8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8007CDEC: sw          $zero, 0x44($a2)
    MEM_W(0X44, ctx->r6) = 0;
    // 0x8007CDF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CDF4: jr          $ra
    // 0x8007CDF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007CDF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806D0DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0DE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D0DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D0DEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806D0DF0: jal         0x80045A34
    // 0x806D0DF4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806D0DF4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x806D0DF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D0DFC: bne         $v0, $zero, L_806D0E0C
    if (ctx->r2 != 0) {
        // 0x806D0E00: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806D0E0C;
    }
    // 0x806D0E00: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806D0E04: b           L_806D0E18
    // 0x806D0E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D0E18;
    // 0x806D0E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D0E0C:
    // 0x806D0E0C: jal         0x806D0DBC
    // 0x806D0E10: nop

    func_806D0DBC(rdram, ctx);
        goto after_1;
    // 0x806D0E10: nop

    after_1:
    // 0x806D0E14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806D0E18:
    // 0x806D0E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D0E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D0E20: jr          $ra
    // 0x806D0E24: nop

    return;
    // 0x806D0E24: nop

;}
RECOMP_FUNC void func_805AB0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB0A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AB0A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AB0A8: jal         0x805AAF8C
    // 0x805AB0AC: nop

    func_805AAF8C(rdram, ctx);
        goto after_0;
    // 0x805AB0AC: nop

    after_0:
    // 0x805AB0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AB0B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AB0B8: jr          $ra
    // 0x805AB0BC: nop

    return;
    // 0x805AB0BC: nop

;}
RECOMP_FUNC void func_80049470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049470: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80049474: addiu       $v1, $v1, 0x5A4
    ctx->r3 = ADD32(ctx->r3, 0X5A4);
    // 0x80049478: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x8004947C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049480: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80049484: bne         $t6, $at, L_800494B4
    if (ctx->r14 != ctx->r1) {
        // 0x80049488: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800494B4;
    }
    // 0x80049488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004948C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    // 0x80049490: jal         0x80067F78
    // 0x80049494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067F78(rdram, ctx);
        goto after_0;
    // 0x80049494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80049498: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8004949C: addiu       $v1, $v1, 0x5A4
    ctx->r3 = ADD32(ctx->r3, 0X5A4);
    // 0x800494A0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800494A4: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x800494A8: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    // 0x800494AC: jal         0x800678F0
    // 0x800494B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800678F0(rdram, ctx);
        goto after_1;
    // 0x800494B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_800494B4:
    // 0x800494B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800494B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800494BC: jr          $ra
    // 0x800494C0: nop

    return;
    // 0x800494C0: nop

;}
RECOMP_FUNC void func_80060FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060FE0: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80060FE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80060FE8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80060FEC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80060FF0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80060FF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80060FF8: lh          $s0, 0x184($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X184);
    // 0x80060FFC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80061000: addiu       $s1, $a0, 0x188
    ctx->r17 = ADD32(ctx->r4, 0X188);
    // 0x80061004: beq         $s0, $zero, L_80061050
    if (ctx->r16 == 0) {
        // 0x80061008: addiu       $s3, $sp, 0x30
        ctx->r19 = ADD32(ctx->r29, 0X30);
            goto L_80061050;
    }
    // 0x80061008: addiu       $s3, $sp, 0x30
    ctx->r19 = ADD32(ctx->r29, 0X30);
L_8006100C:
    // 0x8006100C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80061010: beq         $v0, $zero, L_80061048
    if (ctx->r2 == 0) {
        // 0x80061014: nop
    
            goto L_80061048;
    }
    // 0x80061014: nop

    // 0x80061018: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x8006101C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80061020: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80061024: beq         $v1, $zero, L_80061048
    if (ctx->r3 == 0) {
        // 0x80061028: sra         $s0, $s0, 16
        ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
            goto L_80061048;
    }
    // 0x80061028: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006102C: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80061030: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80061034: bne         $s2, $t6, L_80061048
    if (ctx->r18 != ctx->r14) {
        // 0x80061038: nop
    
            goto L_80061048;
    }
    // 0x80061038: nop

    // 0x8006103C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80061040: jal         0x80060F6C
    // 0x80061044: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    func_80060F6C(rdram, ctx);
        goto after_0;
    // 0x80061044: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    after_0:
L_80061048:
    // 0x80061048: bne         $s0, $zero, L_8006100C
    if (ctx->r16 != 0) {
        // 0x8006104C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8006100C;
    }
    // 0x8006104C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80061050:
    // 0x80061050: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80061054: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80061058: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006105C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80061060: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80061064: jr          $ra
    // 0x80061068: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80061068: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_80022B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022B20: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80022B24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022B28: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x80022B2C: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
    // 0x80022B30: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80022B34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80022B38: lb          $a0, 0x2($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X2);
    // 0x80022B3C: jal         0x80022A58
    // 0x80022B40: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80022A58(rdram, ctx);
        goto after_0;
    // 0x80022B40: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_0:
    // 0x80022B44: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80022B48: lb          $a0, 0x3($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X3);
    // 0x80022B4C: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
    // 0x80022B50: jal         0x80022A58
    // 0x80022B54: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80022A58(rdram, ctx);
        goto after_1;
    // 0x80022B54: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_1:
    // 0x80022B58: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x80022B5C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80022B60: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80022B64: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80022B68: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80022B6C: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80022B70: mflo        $t8
    ctx->r24 = lo;
    // 0x80022B74: nop

    // 0x80022B78: nop

    // 0x80022B7C: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80022B80: mflo        $t9
    ctx->r25 = lo;
    // 0x80022B84: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80022B88: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80022B8C: nop

    // 0x80022B90: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80022B94: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80022B98: jal         0x80081E8C
    // 0x80022B9C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    fatan2(rdram, ctx);
        goto after_2;
    // 0x80022B9C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80022BA0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80022BA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80022BA8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022BAC: lwc1        $f18, -0x368($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X368);
    // 0x80022BB0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80022BB4: jal         0x80065954
    // 0x80022BB8: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x80022BB8: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_3:
    // 0x80022BBC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80022BC0: jal         0x80066E88
    // 0x80022BC4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x80022BC4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x80022BC8: jal         0x80065954
    // 0x80022BCC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x80022BCC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x80022BD0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80022BD4: jal         0x80066DE4
    // 0x80022BD8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x80022BD8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80022BDC: jal         0x80065954
    // 0x80022BE0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_7;
    // 0x80022BE0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x80022BE4: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x80022BE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022BEC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80022BF0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80022BF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80022BF8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80022BFC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80022C00: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80022C04: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80022C08: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80022C0C: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80022C10: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80022C14: nop

    // 0x80022C18: bc1fl       L_80022C74
    if (!c1cs) {
        // 0x80022C1C: lw          $t1, 0x8($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X8);
            goto L_80022C74;
    }
    goto skip_0;
    // 0x80022C1C: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x80022C20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80022C24: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80022C28: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80022C2C: nop

    // 0x80022C30: bc1tl       L_80022C54
    if (c1cs) {
        // 0x80022C34: c.le.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
            goto L_80022C54;
    }
    goto skip_1;
    // 0x80022C34: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    skip_1:
    // 0x80022C38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022C3C: nop

    // 0x80022C40: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x80022C44: nop

    // 0x80022C48: bc1fl       L_80022C74
    if (!c1cs) {
        // 0x80022C4C: lw          $t1, 0x8($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X8);
            goto L_80022C74;
    }
    goto skip_2;
    // 0x80022C4C: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x80022C50: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
L_80022C54:
    // 0x80022C54: addiu       $v0, $zero, -0x36
    ctx->r2 = ADD32(0, -0X36);
    // 0x80022C58: bc1f        L_80022C68
    if (!c1cs) {
        // 0x80022C5C: nop
    
            goto L_80022C68;
    }
    // 0x80022C5C: nop

    // 0x80022C60: b           L_80022C68
    // 0x80022C64: addiu       $v0, $zero, 0x36
    ctx->r2 = ADD32(0, 0X36);
        goto L_80022C68;
    // 0x80022C64: addiu       $v0, $zero, 0x36
    ctx->r2 = ADD32(0, 0X36);
L_80022C68:
    // 0x80022C68: b           L_80022C84
    // 0x80022C6C: sh          $v0, 0xADE($s0)
    MEM_H(0XADE, ctx->r16) = ctx->r2;
        goto L_80022C84;
    // 0x80022C6C: sh          $v0, 0xADE($s0)
    MEM_H(0XADE, ctx->r16) = ctx->r2;
    // 0x80022C70: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
L_80022C74:
    // 0x80022C74: lh          $a1, 0xADE($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XADE);
    // 0x80022C78: jal         0x80022A58
    // 0x80022C7C: lb          $a0, 0x2($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X2);
    func_80022A58(rdram, ctx);
        goto after_8;
    // 0x80022C7C: lb          $a0, 0x2($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X2);
    after_8:
    // 0x80022C80: sh          $v0, 0xADE($s0)
    MEM_H(0XADE, ctx->r16) = ctx->r2;
L_80022C84:
    // 0x80022C84: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80022C88: lh          $a1, 0xAE0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XAE0);
    // 0x80022C8C: jal         0x80022A58
    // 0x80022C90: lb          $a0, 0x3($t2)
    ctx->r4 = MEM_B(ctx->r10, 0X3);
    func_80022A58(rdram, ctx);
        goto after_9;
    // 0x80022C90: lb          $a0, 0x3($t2)
    ctx->r4 = MEM_B(ctx->r10, 0X3);
    after_9:
    // 0x80022C94: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x80022C98: sh          $v0, 0xAE0($s0)
    MEM_H(0XAE0, ctx->r16) = ctx->r2;
    // 0x80022C9C: lh          $a1, 0xAE2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XAE2);
    // 0x80022CA0: jal         0x80022A58
    // 0x80022CA4: lb          $a0, 0x2($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X2);
    func_80022A58(rdram, ctx);
        goto after_10;
    // 0x80022CA4: lb          $a0, 0x2($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X2);
    after_10:
    // 0x80022CA8: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x80022CAC: sh          $v0, 0xAE2($s0)
    MEM_H(0XAE2, ctx->r16) = ctx->r2;
    // 0x80022CB0: lh          $a1, 0xAE4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XAE4);
    // 0x80022CB4: jal         0x80022A58
    // 0x80022CB8: lb          $a0, 0x3($t4)
    ctx->r4 = MEM_B(ctx->r12, 0X3);
    func_80022A58(rdram, ctx);
        goto after_11;
    // 0x80022CB8: lb          $a0, 0x3($t4)
    ctx->r4 = MEM_B(ctx->r12, 0X3);
    after_11:
    // 0x80022CBC: lh          $v1, 0xADE($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XADE);
    // 0x80022CC0: lh          $a0, 0xAE0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XAE0);
    // 0x80022CC4: lh          $a1, 0xAE2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XAE2);
    // 0x80022CC8: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80022CCC: sh          $v0, 0xAE4($s0)
    MEM_H(0XAE4, ctx->r16) = ctx->r2;
    // 0x80022CD0: lh          $a2, 0xAE4($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XAE4);
    // 0x80022CD4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80022CD8: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80022CDC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80022CE0: mflo        $t5
    ctx->r13 = lo;
    // 0x80022CE4: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80022CE8: nop

    // 0x80022CEC: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80022CF0: mflo        $t6
    ctx->r14 = lo;
    // 0x80022CF4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80022CF8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80022CFC: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80022D00: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80022D04: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80022D08: mflo        $t8
    ctx->r24 = lo;
    // 0x80022D0C: nop

    // 0x80022D10: nop

    // 0x80022D14: multu       $a2, $a2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80022D18: mflo        $t9
    ctx->r25 = lo;
    // 0x80022D1C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80022D20: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80022D24: swc1        $f0, 0xAE8($s0)
    MEM_W(0XAE8, ctx->r16) = ctx->f0.u32l;
    // 0x80022D28: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80022D2C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80022D30: jal         0x80081E8C
    // 0x80022D34: swc1        $f0, 0xAEC($s0)
    MEM_W(0XAEC, ctx->r16) = ctx->f0.u32l;
    fatan2(rdram, ctx);
        goto after_12;
    // 0x80022D34: swc1        $f0, 0xAEC($s0)
    MEM_W(0XAEC, ctx->r16) = ctx->f0.u32l;
    after_12:
    // 0x80022D38: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80022D3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022D40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022D44: lwc1        $f16, -0x364($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X364);
    // 0x80022D48: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80022D4C: div.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80022D50: jal         0x80022AC0
    // 0x80022D54: swc1        $f10, 0xAF0($s0)
    MEM_W(0XAF0, ctx->r16) = ctx->f10.u32l;
    func_80022AC0(rdram, ctx);
        goto after_13;
    // 0x80022D54: swc1        $f10, 0xAF0($s0)
    MEM_W(0XAF0, ctx->r16) = ctx->f10.u32l;
    after_13:
    // 0x80022D58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022D5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022D60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80022D64: jr          $ra
    // 0x80022D68: nop

    return;
    // 0x80022D68: nop

;}
RECOMP_FUNC void func_800232E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800232E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800232E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800232E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800232EC: swc1        $f0, 0x114($a0)
    MEM_W(0X114, ctx->r4) = ctx->f0.u32l;
    // 0x800232F0: swc1        $f0, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f0.u32l;
    // 0x800232F4: swc1        $f0, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f0.u32l;
    // 0x800232F8: swc1        $f0, 0xE4($a1)
    MEM_W(0XE4, ctx->r5) = ctx->f0.u32l;
    // 0x800232FC: swc1        $f0, 0xE8($a1)
    MEM_W(0XE8, ctx->r5) = ctx->f0.u32l;
    // 0x80023300: swc1        $f2, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f2.u32l;
    // 0x80023304: swc1        $f2, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->f2.u32l;
    // 0x80023308: jr          $ra
    // 0x8002330C: swc1        $f2, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8002330C: swc1        $f2, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_807AFA3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AFA3C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807AFA40: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807AFA44: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807AFA48: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807AFA4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807AFA50: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x807AFA54: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807AFA58: lui         $t1, 0x807B
    ctx->r9 = S32(RELOC_HI16(868, 0X490) << 16);
    // 0x807AFA5C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807AFA60: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807AFA64: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807AFA68: lw          $t1, -0x580($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(868, 0X490));
    // 0x807AFA6C: jr          $ra
    // 0x807AFA70: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807AFA70: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x807AFA74: nop

    // 0x807AFA78: nop

    // 0x807AFA7C: nop

;}
RECOMP_FUNC void func_805A34F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A34F8: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x805A34FC: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x805A3500: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x805A3504: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x805A3508: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805A350C: ori         $t7, $t7, 0x103F
    ctx->r15 = ctx->r15 | 0X103F;
    // 0x805A3510: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805A3514: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x805A3518: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x805A351C: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x805A3520: lui         $t1, 0xBF00
    ctx->r9 = S32(0XBF00 << 16);
    // 0x805A3524: addiu       $t2, $zero, 0x204
    ctx->r10 = ADD32(0, 0X204);
    // 0x805A3528: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x805A352C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805A3530: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x805A3534: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x805A3538: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x805A353C: lui         $t4, 0x2
    ctx->r12 = S32(0X2 << 16);
    // 0x805A3540: ori         $t4, $t4, 0x604
    ctx->r12 = ctx->r12 | 0X604;
    // 0x805A3544: addiu       $t3, $a2, 0x8
    ctx->r11 = ADD32(ctx->r6, 0X8);
    // 0x805A3548: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x805A354C: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x805A3550: jr          $ra
    // 0x805A3554: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    return;
    // 0x805A3554: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
;}
RECOMP_FUNC void func_80453764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045376C: jal         0x80453644
    // 0x80453770: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80453644(rdram, ctx);
        goto after_0;
    // 0x80453770: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80453774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045377C: jr          $ra
    // 0x80453780: nop

    return;
    // 0x80453780: nop

;}
RECOMP_FUNC void func_8044C360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044C360: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8044C364: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8044C368: addiu       $v1, $sp, 0x1C
    ctx->r3 = ADD32(ctx->r29, 0X1C);
    // 0x8044C36C: addiu       $t3, $sp, 0x5C
    ctx->r11 = ADD32(ctx->r29, 0X5C);
    // 0x8044C370: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8044C374: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8044C378: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
L_8044C37C:
    // 0x8044C37C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8044C380: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8044C384: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x8044C388: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8044C38C: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8044C390: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8044C394: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8044C398: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8044C39C: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8044C3A0: beql        $a0, $t2, L_8044C424
    if (ctx->r4 == ctx->r10) {
        // 0x8044C3A4: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_8044C424;
    }
    goto skip_0;
    // 0x8044C3A4: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x8044C3A8: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_8044C3AC:
    // 0x8044C3AC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8044C3B0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8044C3B4: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8044C3B8: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8044C3BC: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8044C3C0: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8044C3C4: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8044C3C8: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8044C3CC: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8044C3D0: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x8044C3D4: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8044C3D8: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8044C3DC: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8044C3E0: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8044C3E4: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8044C3E8: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8044C3EC: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8044C3F0: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x8044C3F4: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8044C3F8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8044C3FC: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8044C400: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8044C404: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8044C408: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8044C40C: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8044C410: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8044C414: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8044C418: bnel        $a0, $t2, L_8044C3AC
    if (ctx->r4 != ctx->r10) {
        // 0x8044C41C: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_8044C3AC;
    }
    goto skip_1;
    // 0x8044C41C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x8044C420: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_8044C424:
    // 0x8044C424: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8044C428: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8044C42C: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8044C430: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8044C434: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8044C438: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8044C43C: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8044C440: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8044C444: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x8044C448: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8044C44C: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8044C450: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8044C454: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8044C458: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8044C45C: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8044C460: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x8044C464: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8044C468: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8044C46C: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8044C470: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8044C474: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8044C478: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8044C47C: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x8044C480: bne         $at, $zero, L_8044C37C
    if (ctx->r1 != 0) {
        // 0x8044C484: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8044C37C;
    }
    // 0x8044C484: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8044C488: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8044C48C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8044C490: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
L_8044C494:
    // 0x8044C494: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8044C498: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8044C49C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8044C4A0: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x8044C4A4: lwc1        $f8, -0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, -0XC);
    // 0x8044C4A8: swc1        $f8, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f8.u32l;
    // 0x8044C4AC: lwc1        $f16, -0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8044C4B0: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x8044C4B4: lwc1        $f10, -0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X4);
    // 0x8044C4B8: bne         $a0, $v0, L_8044C494
    if (ctx->r4 != ctx->r2) {
        // 0x8044C4BC: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_8044C494;
    }
    // 0x8044C4BC: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8044C4C0: jr          $ra
    // 0x8044C4C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8044C4C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_805DCD14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DCD14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DCD18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DCD1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DCD20: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805DCD24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805DCD28: addiu       $at, $zero, 0x4194
    ctx->r1 = ADD32(0, 0X4194);
    // 0x805DCD2C: beq         $v0, $at, L_805DCD48
    if (ctx->r2 == ctx->r1) {
        // 0x805DCD30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805DCD48;
    }
    // 0x805DCD30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCD34: addiu       $at, $zero, 0x4195
    ctx->r1 = ADD32(0, 0X4195);
    // 0x805DCD38: beq         $v0, $at, L_805DCD74
    if (ctx->r2 == ctx->r1) {
        // 0x805DCD3C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805DCD74;
    }
    // 0x805DCD3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCD40: b           L_805DCD9C
    // 0x805DCD44: nop

        goto L_805DCD9C;
    // 0x805DCD44: nop

L_805DCD48:
    // 0x805DCD48: jal         0x805DAF64
    // 0x805DCD4C: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    func_805DAF64(rdram, ctx);
        goto after_0;
    // 0x805DCD4C: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_0:
    // 0x805DCD50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCD54: jal         0x805DAF64
    // 0x805DCD58: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_805DAF64(rdram, ctx);
        goto after_1;
    // 0x805DCD58: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_1:
    // 0x805DCD5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCD60: jal         0x805DAF64
    // 0x805DCD64: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    func_805DAF64(rdram, ctx);
        goto after_2;
    // 0x805DCD64: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    after_2:
    // 0x805DCD68: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x805DCD6C: b           L_805DCD9C
    // 0x805DCD70: sh          $t6, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r14;
        goto L_805DCD9C;
    // 0x805DCD70: sh          $t6, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r14;
L_805DCD74:
    // 0x805DCD74: jal         0x805DAF64
    // 0x805DCD78: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    func_805DAF64(rdram, ctx);
        goto after_3;
    // 0x805DCD78: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    after_3:
    // 0x805DCD7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCD80: jal         0x805DAF64
    // 0x805DCD84: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    func_805DAF64(rdram, ctx);
        goto after_4;
    // 0x805DCD84: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_4:
    // 0x805DCD88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCD8C: jal         0x805DAF64
    // 0x805DCD90: addiu       $a1, $zero, 0x27E
    ctx->r5 = ADD32(0, 0X27E);
    func_805DAF64(rdram, ctx);
        goto after_5;
    // 0x805DCD90: addiu       $a1, $zero, 0x27E
    ctx->r5 = ADD32(0, 0X27E);
    after_5:
    // 0x805DCD94: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x805DCD98: sh          $t7, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r15;
L_805DCD9C:
    // 0x805DCD9C: jal         0x80045BD8
    // 0x805DCDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80045BD8(rdram, ctx);
        goto after_6;
    // 0x805DCDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805DCDA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805DCDA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DCDAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DCDB0: jr          $ra
    // 0x805DCDB4: nop

    return;
    // 0x805DCDB4: nop

;}
RECOMP_FUNC void func_80069FBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069FC4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80069FC8: addiu       $a1, $a2, 0x3C
    ctx->r5 = ADD32(ctx->r6, 0X3C);
    // 0x80069FCC: jal         0x80050B38
    // 0x80069FD0: lhu         $a0, 0x18($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X18);
    func_80050B38(rdram, ctx);
        goto after_0;
    // 0x80069FD0: lhu         $a0, 0x18($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X18);
    after_0:
    // 0x80069FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069FDC: jr          $ra
    // 0x80069FE0: nop

    return;
    // 0x80069FE0: nop

;}
RECOMP_FUNC void func_8002A630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A630: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002A634: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002A638: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002A63C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8002A640: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002A644: jal         0x80081C64
    // 0x8002A648: lwc1        $f12, 0x38($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X38);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8002A648: lwc1        $f12, 0x38($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X38);
    after_0:
    // 0x8002A64C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8002A650: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8002A654: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8002A658: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002A65C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002A660: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8002A664: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A668: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002A66C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002A670: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8002A674: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8002A678: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8002A67C: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8002A680: div.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8002A684: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002A688: jal         0x8002A0D0
    // 0x8002A68C: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    func_8002A0D0(rdram, ctx);
        goto after_1;
    // 0x8002A68C: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8002A690: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8002A694: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002A698: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002A69C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8002A6A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002A6A4: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002A6A8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002A6AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002A6B0: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8002A6B4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8002A6B8: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8002A6BC: lwc1        $f20, 0x30($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8002A6C0: sub.s       $f10, $f20, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8002A6C4: jal         0x80081FE0
    // 0x8002A6C8: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    floorf_recomp(rdram, ctx);
        goto after_2;
    // 0x8002A6C8: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_2:
    // 0x8002A6CC: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8002A6D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002A6D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002A6D8: add.s       $f4, $f20, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x8002A6DC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8002A6E0: jal         0x80081FE0
    // 0x8002A6E4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    floorf_recomp(rdram, ctx);
        goto after_3;
    // 0x8002A6E4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_3:
    // 0x8002A6E8: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8002A6EC: lwc1        $f2, 0xB0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x8002A6F0: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8002A6F4: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002A6F8: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002A6FC: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8002A700: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8002A704: add.s       $f20, $f2, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8002A708: bgez        $a0, L_8002A714
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002A70C: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_8002A714;
    }
    // 0x8002A70C: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x8002A710: addiu       $at, $a0, 0xF
    ctx->r1 = ADD32(ctx->r4, 0XF);
L_8002A714:
    // 0x8002A714: sra         $a0, $at, 4
    ctx->r4 = S32(SIGNED(ctx->r1) >> 4);
    // 0x8002A718: jal         0x8006593C
    // 0x8002A71C: nop

    func_8006593C(rdram, ctx);
        goto after_4;
    // 0x8002A71C: nop

    after_4:
    // 0x8002A720: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8002A724: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8002A728: jal         0x80053924
    // 0x8002A72C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_80053924(rdram, ctx);
        goto after_5;
    // 0x8002A72C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_5:
    // 0x8002A730: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8002A734: bne         $v0, $at, L_8002A7A8
    if (ctx->r2 != ctx->r1) {
        // 0x8002A738: lwc1        $f12, 0x64($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
            goto L_8002A7A8;
    }
    // 0x8002A738: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8002A73C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002A740: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002A744: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002A748: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8002A74C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8002A750: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002A754: add.s       $f14, $f20, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f20.fl + ctx->f2.fl;
    // 0x8002A758: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8002A75C: jal         0x8002A034
    // 0x8002A760: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8002A034(rdram, ctx);
        goto after_6;
    // 0x8002A760: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8002A764: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8002A768: jal         0x80082050
    // 0x8002A76C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    truncf_recomp(rdram, ctx);
        goto after_7;
    // 0x8002A76C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x8002A770: trunc.w.s   $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8002A774: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8002A778: sub.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8002A77C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8002A780: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8002A784: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x8002A788: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8002A78C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8002A790: nop

    // 0x8002A794: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002A798: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8002A79C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002A7A0: b           L_8002A7B4
    // 0x8002A7A4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
        goto L_8002A7B4;
    // 0x8002A7A4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
L_8002A7A8:
    // 0x8002A7A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002A7AC: nop

    // 0x8002A7B0: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
L_8002A7B4:
    // 0x8002A7B4: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8002A7B8: jal         0x80053924
    // 0x8002A7BC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_80053924(rdram, ctx);
        goto after_8;
    // 0x8002A7BC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_8:
    // 0x8002A7C0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8002A7C4: bnel        $v0, $at, L_8002A844
    if (ctx->r2 != ctx->r1) {
        // 0x8002A7C8: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8002A844;
    }
    goto skip_0;
    // 0x8002A7C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x8002A7CC: trunc.w.s   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8002A7D0: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8002A7D4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002A7D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002A7DC: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8002A7E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002A7E4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8002A7E8: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x8002A7EC: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8002A7F0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8002A7F4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8002A7F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002A7FC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002A800: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8002A804: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8002A808: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002A80C: add.s       $f14, $f20, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f20.fl + ctx->f2.fl;
    // 0x8002A810: jal         0x8002A034
    // 0x8002A814: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    func_8002A034(rdram, ctx);
        goto after_9;
    // 0x8002A814: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x8002A818: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8002A81C: jal         0x80082050
    // 0x8002A820: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    truncf_recomp(rdram, ctx);
        goto after_10;
    // 0x8002A820: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_10:
    // 0x8002A824: sub.s       $f18, $f20, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8002A828: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002A82C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002A830: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8002A834: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002A838: b           L_8002A84C
    // 0x8002A83C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
        goto L_8002A84C;
    // 0x8002A83C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x8002A840: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8002A844:
    // 0x8002A844: nop

    // 0x8002A848: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
L_8002A84C:
    // 0x8002A84C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002A850: lwc1        $f0, -0x1A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1A4);
    // 0x8002A854: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8002A858: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002A85C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002A860: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002A864: nop

    // 0x8002A868: bc1tl       L_8002A8B0
    if (c1cs) {
        // 0x8002A86C: sw          $t0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r8;
            goto L_8002A8B0;
    }
    goto skip_1;
    // 0x8002A86C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    skip_1:
    // 0x8002A870: lwc1        $f18, -0x1A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1A0);
    // 0x8002A874: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002A878: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8002A87C: nop

    // 0x8002A880: bc1tl       L_8002A8B0
    if (c1cs) {
        // 0x8002A884: sw          $t0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r8;
            goto L_8002A8B0;
    }
    goto skip_2;
    // 0x8002A884: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    skip_2:
    // 0x8002A888: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8002A88C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002A890: bc1tl       L_8002A8B0
    if (c1cs) {
        // 0x8002A894: sw          $t0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r8;
            goto L_8002A8B0;
    }
    goto skip_3;
    // 0x8002A894: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    skip_3:
    // 0x8002A898: lwc1        $f8, -0x19C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X19C);
    // 0x8002A89C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8002A8A0: nop

    // 0x8002A8A4: bc1fl       L_8002A8B4
    if (!c1cs) {
        // 0x8002A8A8: lwc1        $f4, 0x34($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
            goto L_8002A8B4;
    }
    goto skip_4;
    // 0x8002A8A8: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    skip_4:
    // 0x8002A8AC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
L_8002A8B0:
    // 0x8002A8B0: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
L_8002A8B4:
    // 0x8002A8B4: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002A8B8: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002A8BC: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8002A8C0: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002A8C4: lwc1        $f4, 0xB0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x8002A8C8: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8002A8CC: add.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A8D0: jal         0x80053924
    // 0x8002A8D4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_80053924(rdram, ctx);
        goto after_11;
    // 0x8002A8D4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_11:
    // 0x8002A8D8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8002A8DC: bne         $v0, $at, L_8002A950
    if (ctx->r2 != ctx->r1) {
        // 0x8002A8E0: lwc1        $f12, 0x64($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
            goto L_8002A950;
    }
    // 0x8002A8E0: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8002A8E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002A8E8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002A8EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002A8F0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8002A8F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002A8F8: lui         $a3, 0xC180
    ctx->r7 = S32(0XC180 << 16);
    // 0x8002A8FC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002A900: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8002A904: jal         0x8002A034
    // 0x8002A908: sub.s       $f14, $f20, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f10.fl;
    func_8002A034(rdram, ctx);
        goto after_12;
    // 0x8002A908: sub.s       $f14, $f20, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f10.fl;
    after_12:
    // 0x8002A90C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8002A910: jal         0x80082050
    // 0x8002A914: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    truncf_recomp(rdram, ctx);
        goto after_13;
    // 0x8002A914: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x8002A918: trunc.w.s   $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    ctx->f18.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8002A91C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A920: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002A924: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8002A928: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8002A92C: sub.s       $f18, $f20, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8002A930: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x8002A934: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8002A938: nop

    // 0x8002A93C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002A940: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A944: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8002A948: b           L_8002A958
    // 0x8002A94C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
        goto L_8002A958;
    // 0x8002A94C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_8002A950:
    // 0x8002A950: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002A954: nop

L_8002A958:
    // 0x8002A958: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8002A95C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x8002A960: jal         0x80053924
    // 0x8002A964: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    func_80053924(rdram, ctx);
        goto after_14;
    // 0x8002A964: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    after_14:
    // 0x8002A968: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8002A96C: bne         $v0, $at, L_8002A9F0
    if (ctx->r2 != ctx->r1) {
        // 0x8002A970: lwc1        $f16, 0x48($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
            goto L_8002A9F0;
    }
    // 0x8002A970: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8002A974: trunc.w.s   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8002A978: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002A97C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002A980: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A984: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8002A988: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002A98C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002A990: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x8002A994: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8002A998: sub.s       $f14, $f20, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x8002A99C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8002A9A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002A9A4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002A9A8: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8002A9AC: lui         $a3, 0xC180
    ctx->r7 = S32(0XC180 << 16);
    // 0x8002A9B0: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x8002A9B4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002A9B8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8002A9BC: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8002A9C0: jal         0x8002A034
    // 0x8002A9C4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    func_8002A034(rdram, ctx);
        goto after_15;
    // 0x8002A9C4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x8002A9C8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8002A9CC: jal         0x80082050
    // 0x8002A9D0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    truncf_recomp(rdram, ctx);
        goto after_16;
    // 0x8002A9D0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x8002A9D4: sub.s       $f10, $f20, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8002A9D8: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002A9DC: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002A9E0: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8002A9E4: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002A9E8: b           L_8002A9F8
    // 0x8002A9EC: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
        goto L_8002A9F8;
    // 0x8002A9EC: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_8002A9F0:
    // 0x8002A9F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002A9F4: nop

L_8002A9F8:
    // 0x8002A9F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002A9FC: lwc1        $f0, -0x198($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X198);
    // 0x8002AA00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002AA04: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8002AA08: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8002AA0C: nop

    // 0x8002AA10: bc1tl       L_8002AA54
    if (c1cs) {
        // 0x8002AA14: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8002AA54;
    }
    goto skip_5;
    // 0x8002AA14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_5:
    // 0x8002AA18: lwc1        $f12, -0x194($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X194);
    // 0x8002AA1C: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x8002AA20: nop

    // 0x8002AA24: bc1tl       L_8002AA54
    if (c1cs) {
        // 0x8002AA28: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8002AA54;
    }
    goto skip_6;
    // 0x8002AA28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_6:
    // 0x8002AA2C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002AA30: nop

    // 0x8002AA34: bc1tl       L_8002AA54
    if (c1cs) {
        // 0x8002AA38: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8002AA54;
    }
    goto skip_7;
    // 0x8002AA38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_7:
    // 0x8002AA3C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8002AA40: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8002AA44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AA48: bc1f        L_8002AA94
    if (!c1cs) {
        // 0x8002AA4C: nop
    
            goto L_8002AA94;
    }
    // 0x8002AA4C: nop

    // 0x8002AA50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8002AA54:
    // 0x8002AA54: beql        $t8, $at, L_8002AADC
    if (ctx->r24 == ctx->r1) {
        // 0x8002AA58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002AADC;
    }
    goto skip_8;
    // 0x8002AA58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_8:
    // 0x8002AA5C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002AA60: nop

    // 0x8002AA64: bc1fl       L_8002AA84
    if (!c1cs) {
        // 0x8002AA68: lwc1        $f8, 0xB0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XB0);
            goto L_8002AA84;
    }
    goto skip_9;
    // 0x8002AA68: lwc1        $f8, 0xB0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB0);
    skip_9:
    // 0x8002AA6C: lwc1        $f6, 0xB0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x8002AA70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002AA74: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8002AA78: b           L_8002AADC
    // 0x8002AA7C: swc1        $f4, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f4.u32l;
        goto L_8002AADC;
    // 0x8002AA7C: swc1        $f4, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f4.u32l;
    // 0x8002AA80: lwc1        $f8, 0xB0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB0);
L_8002AA84:
    // 0x8002AA84: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8002AA88: swc1        $f10, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f10.u32l;
    // 0x8002AA8C: b           L_8002AADC
    // 0x8002AA90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002AADC;
    // 0x8002AA90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002AA94:
    // 0x8002AA94: bne         $t0, $at, L_8002AAD8
    if (ctx->r8 != ctx->r1) {
        // 0x8002AA98: lwc1        $f0, 0x4C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_8002AAD8;
    }
    // 0x8002AA98: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002AA9C: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8002AAA0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8002AAA4: nop

    // 0x8002AAA8: bc1fl       L_8002AAC8
    if (!c1cs) {
        // 0x8002AAAC: lwc1        $f8, 0xB0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XB0);
            goto L_8002AAC8;
    }
    goto skip_10;
    // 0x8002AAAC: lwc1        $f8, 0xB0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB0);
    skip_10:
    // 0x8002AAB0: lwc1        $f6, 0xB0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x8002AAB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002AAB8: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8002AABC: b           L_8002AADC
    // 0x8002AAC0: swc1        $f4, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f4.u32l;
        goto L_8002AADC;
    // 0x8002AAC0: swc1        $f4, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f4.u32l;
    // 0x8002AAC4: lwc1        $f8, 0xB0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB0);
L_8002AAC8:
    // 0x8002AAC8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8002AACC: swc1        $f10, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f10.u32l;
    // 0x8002AAD0: b           L_8002AADC
    // 0x8002AAD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002AADC;
    // 0x8002AAD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002AAD8:
    // 0x8002AAD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002AADC:
    // 0x8002AADC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AAE0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8002AAE4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002AAE8: jr          $ra
    // 0x8002AAEC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8002AAEC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8057C418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057C41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C420: jal         0x8057BB68
    // 0x8057C424: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8057BB68(rdram, ctx);
        goto after_0;
    // 0x8057C424: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057C428: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8057C42C: lw          $t6, -0x7280($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7280);
    // 0x8057C430: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8057C434: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x8057C438: bne         $at, $zero, L_8057C448
    if (ctx->r1 != 0) {
        // 0x8057C43C: nop
    
            goto L_8057C448;
    }
    // 0x8057C43C: nop

    // 0x8057C440: jal         0x8057C6B0
    // 0x8057C444: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8057C6B0(rdram, ctx);
        goto after_1;
    // 0x8057C444: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
L_8057C448:
    // 0x8057C448: jal         0x8057BD84
    // 0x8057C44C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8057BD84(rdram, ctx);
        goto after_2;
    // 0x8057C44C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8057C450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057C454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057C458: jr          $ra
    // 0x8057C45C: nop

    return;
    // 0x8057C45C: nop

;}
RECOMP_FUNC void func_8064B440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B448: jal         0x8004700C
    // 0x8064B44C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8064B44C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064B450: beq         $v0, $zero, L_8064B4B0
    if (ctx->r2 == 0) {
        // 0x8064B454: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8064B4B0;
    }
    // 0x8064B454: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064B458: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064B45C: blez        $v1, L_8064B46C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8064B460: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8064B46C;
    }
    // 0x8064B460: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8064B464: b           L_8064B4B0
    // 0x8064B468: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064B4B0;
    // 0x8064B468: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064B46C:
    // 0x8064B46C: lwc1        $f4, 0x88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8064B470: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064B474: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8064B478: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064B47C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8064B480: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8064B484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B488: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8064B48C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8064B490: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8064B494: nop

    // 0x8064B498: bc1fl       L_8064B4B4
    if (!c1cs) {
        // 0x8064B49C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064B4B4;
    }
    goto skip_0;
    // 0x8064B49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064B4A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8064B4A4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064B4A8: jal         0x8064B918
    // 0x8064B4AC: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
    func_8064B918(rdram, ctx);
        goto after_1;
    // 0x8064B4AC: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
    after_1:
L_8064B4B0:
    // 0x8064B4B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064B4B4:
    // 0x8064B4B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B4B8: jr          $ra
    // 0x8064B4BC: nop

    return;
    // 0x8064B4BC: nop

;}
RECOMP_FUNC void func_804C4F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C4F80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804C4F84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C4F88: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(212, 0X990) << 16);
    // 0x804C4F8C: lwc1        $f0, 0x58D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(212, 0X990));
    // 0x804C4F90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C4F94: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804C4F98: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x804C4F9C: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(212, 0X8B0) << 16);
    // 0x804C4FA0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804C4FA4: addiu       $t6, $t6, 0x57F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(212, 0X8B0));
    // 0x804C4FA8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804C4FAC: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x804C4FB0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x804C4FB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C4FB8: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x804C4FBC: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x804C4FC0: bne         $at, $zero, L_804C4FD0
    if (ctx->r1 != 0) {
        // 0x804C4FC4: swc1        $f0, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
            goto L_804C4FD0;
    }
    // 0x804C4FC4: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x804C4FC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804C4FCC: sw          $t9, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r25;
L_804C4FD0:
    // 0x804C4FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C4FD4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x804C4FD8: jal         0x80045A34
    // 0x804C4FDC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804C4FDC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804C4FE0: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804C4FE4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x804C4FE8: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x804C4FEC: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x804C4FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C4FF4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x804C4FF8: lw          $t2, 0x180($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X180);
    // 0x804C4FFC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x804C5000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C5004: jal         0x804C57AC
    // 0x804C5008: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    func_804C57AC(rdram, ctx);
        goto after_1;
    // 0x804C5008: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    after_1:
    // 0x804C500C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x804C5010: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x804C5014: sw          $t3, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r11;
    // 0x804C5018: addiu       $t4, $t4, -0x7C48
    ctx->r12 = ADD32(ctx->r12, -0X7C48);
    // 0x804C501C: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x804C5020: sw          $t4, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r12;
    // 0x804C5024: lw          $a1, 0x138($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X138);
    // 0x804C5028: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x804C502C: jal         0x804C52D0
    // 0x804C5030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C52D0(rdram, ctx);
        goto after_2;
    // 0x804C5030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804C5034: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x804C5038: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x804C503C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(212, 0X8B8) << 16);
    // 0x804C5040: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x804C5044: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804C5048: lwc1        $f6, 0x57F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(212, 0X8B8));
    // 0x804C504C: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x804C5050: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(212, 0X8CC) << 16);
    // 0x804C5054: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804C5058: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804C505C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C5060: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    // 0x804C5064: lwc1        $f10, 0x580C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(212, 0X8CC));
    // 0x804C5068: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x804C506C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804C5070: nop

    // 0x804C5074: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804C5078: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x804C507C: jal         0x804C4F68
    // 0x804C5080: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    func_804C4F68(rdram, ctx);
        goto after_3;
    // 0x804C5080: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    after_3:
    // 0x804C5084: lui         $t5, 0x804C
    ctx->r13 = S32(RELOC_HI16(212, 0X360) << 16);
    // 0x804C5088: addiu       $t5, $t5, 0x52A0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(212, 0X360));
    // 0x804C508C: sw          $t5, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r13;
    // 0x804C5090: jal         0x8005FCA8
    // 0x804C5094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FCA8(rdram, ctx);
        goto after_4;
    // 0x804C5094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804C5098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C509C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804C50A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804C50A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C50A8: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x804C50AC: jr          $ra
    // 0x804C50B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804C50B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_807808D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807808D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807808D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807808DC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807808E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807808E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807808E8: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x807808EC: lw          $a3, 0x16C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X16C);
    // 0x807808F0: lbu         $v0, 0x10($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X10);
    // 0x807808F4: addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // 0x807808F8: bgtzl       $v0, L_80780930
    if (SIGNED(ctx->r2) > 0) {
        // 0x807808FC: sb          $v0, 0x10($a3)
        MEM_B(0X10, ctx->r7) = ctx->r2;
            goto L_80780930;
    }
    goto skip_0;
    // 0x807808FC: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
    skip_0:
    // 0x80780900: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80780904: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80780908: jal         0x807813F0
    // 0x8078090C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_807813F0(rdram, ctx);
        goto after_0;
    // 0x8078090C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80780910: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80780914: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80780918: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8078091C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80780920: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80780924: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x80780928: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x8078092C: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
L_80780930:
    // 0x80780930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80780934: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80780938: jr          $ra
    // 0x8078093C: nop

    return;
    // 0x8078093C: nop

;}
RECOMP_FUNC void func_8046D1AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046D1AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046D1B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046D1B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046D1B8: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x8046D1BC: lui         $t9, 0x8047
    ctx->r25 = S32(RELOC_HI16(143, 0X139C) << 16);
    // 0x8046D1C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8046D1C4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8046D1C8: lw          $t9, -0x2814($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(143, 0X139C));
    // 0x8046D1CC: jalr        $t9
    // 0x8046D1D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8046D1D0: nop

    after_0:
    // 0x8046D1D4: jal         0x8046C850
    // 0x8046D1D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8046C850(rdram, ctx);
        goto after_1;
    // 0x8046D1D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8046D1DC: beq         $v0, $zero, L_8046D208
    if (ctx->r2 == 0) {
        // 0x8046D1E0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8046D208;
    }
    // 0x8046D1E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046D1E4: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046D1E8: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8046D1EC: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8046D1F0: sb          $t8, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r24;
    // 0x8046D1F4: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046D1F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046D1FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8046D200: jal         0x8046D3E8
    // 0x8046D204: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    func_8046D3E8(rdram, ctx);
        goto after_2;
    // 0x8046D204: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    after_2:
L_8046D208:
    // 0x8046D208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046D20C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046D210: jr          $ra
    // 0x8046D214: nop

    return;
    // 0x8046D214: nop

;}
RECOMP_FUNC void func_804B85C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B85C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B85C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B85CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B85D0: jal         0x8004700C
    // 0x804B85D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804B85D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804B85D8: beq         $v0, $zero, L_804B8660
    if (ctx->r2 == 0) {
        // 0x804B85DC: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_804B8660;
    }
    // 0x804B85DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804B85E0: jal         0x804B7E74
    // 0x804B85E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B7E74(rdram, ctx);
        goto after_1;
    // 0x804B85E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804B85E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B85EC: jal         0x80062684
    // 0x804B85F0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062684(rdram, ctx);
        goto after_2;
    // 0x804B85F0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_2:
    // 0x804B85F4: jal         0x804B7FDC
    // 0x804B85F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B7FDC(rdram, ctx);
        goto after_3;
    // 0x804B85F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804B85FC: jal         0x804B8038
    // 0x804B8600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B8038(rdram, ctx);
        goto after_4;
    // 0x804B8600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804B8604: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804B8608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B860C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B8610: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x804B8614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804B8618: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x804B861C: beq         $s0, $t6, L_804B8634
    if (ctx->r16 == ctx->r14) {
        // 0x804B8620: lui         $t7, 0x8010
        ctx->r15 = S32(0X8010 << 16);
            goto L_804B8634;
    }
    // 0x804B8620: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x804B8624: jal         0x804B8C00
    // 0x804B8628: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804B8C00(rdram, ctx);
        goto after_5;
    // 0x804B8628: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_5:
    // 0x804B862C: b           L_804B8664
    // 0x804B8630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804B8664;
    // 0x804B8630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B8634:
    // 0x804B8634: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804B8638: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x804B863C: lw          $t7, -0x7BC4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7BC4);
    // 0x804B8640: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x804B8644: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804B8648: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804B864C: lwc1        $f10, 0x3C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x804B8650: lw          $t8, 0x1F4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1F4);
    // 0x804B8654: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804B8658: div.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x804B865C: swc1        $f4, 0xE4($t8)
    MEM_W(0XE4, ctx->r24) = ctx->f4.u32l;
L_804B8660:
    // 0x804B8660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B8664:
    // 0x804B8664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B8668: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804B866C: jr          $ra
    // 0x804B8670: nop

    return;
    // 0x804B8670: nop

;}
RECOMP_FUNC void func_806EAB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EAB48: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806EAB4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EAB50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806EAB54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EAB58: jal         0x8004700C
    // 0x806EAB5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806EAB5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x806EAB60: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x806EAB64: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EAB68: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x806EAB6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806EAB70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806EAB74: jal         0x806EA844
    // 0x806EAB78: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_806EA844(rdram, ctx);
        goto after_1;
    // 0x806EAB78: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_1:
    // 0x806EAB7C: jal         0x806EA9C0
    // 0x806EAB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EA9C0(rdram, ctx);
        goto after_2;
    // 0x806EAB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EAB84: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    // 0x806EAB88: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806EAB8C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806EAB90: bne         $a3, $zero, L_806EABD4
    if (ctx->r7 != 0) {
        // 0x806EAB94: lui         $at, 0x4300
        ctx->r1 = S32(0X4300 << 16);
            goto L_806EABD4;
    }
    // 0x806EAB94: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x806EAB98: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x806EAB9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806EABA0: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x806EABA4: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806EABA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EABAC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806EABB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EABB4: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806EABB8: nop

    // 0x806EABBC: bc1fl       L_806EAC10
    if (!c1cs) {
        // 0x806EABC0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_806EAC10;
    }
    goto skip_0;
    // 0x806EABC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x806EABC4: jal         0x806EB43C
    // 0x806EABC8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_806EB43C(rdram, ctx);
        goto after_3;
    // 0x806EABC8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x806EABCC: b           L_806EAC50
    // 0x806EABD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EAC50;
    // 0x806EABD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EABD4:
    // 0x806EABD4: lwc1        $f16, 0x10($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X10);
    // 0x806EABD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806EABDC: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806EABE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EABE4: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806EABE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EABEC: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806EABF0: nop

    // 0x806EABF4: bc1fl       L_806EAC10
    if (!c1cs) {
        // 0x806EABF8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_806EAC10;
    }
    goto skip_1;
    // 0x806EABF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x806EABFC: jal         0x806EB43C
    // 0x806EAC00: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_806EB43C(rdram, ctx);
        goto after_4;
    // 0x806EAC00: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x806EAC04: b           L_806EAC50
    // 0x806EAC08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EAC50;
    // 0x806EAC08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EAC0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_806EAC10:
    // 0x806EAC10: beql        $a0, $zero, L_806EAC50
    if (ctx->r4 == 0) {
        // 0x806EAC14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EAC50;
    }
    goto skip_2;
    // 0x806EAC14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806EAC18: jal         0x806EAA74
    // 0x806EAC1C: nop

    func_806EAA74(rdram, ctx);
        goto after_5;
    // 0x806EAC1C: nop

    after_5:
    // 0x806EAC20: beq         $v0, $zero, L_806EAC4C
    if (ctx->r2 == 0) {
        // 0x806EAC24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EAC4C;
    }
    // 0x806EAC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EAC28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EAC2C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806EAC30: jal         0x806EB43C
    // 0x806EAC34: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_806EB43C(rdram, ctx);
        goto after_6;
    // 0x806EAC34: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_6:
    // 0x806EAC38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806EAC3C: nop

    // 0x806EAC40: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x806EAC44: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x806EAC48: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_806EAC4C:
    // 0x806EAC4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EAC50:
    // 0x806EAC50: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806EAC54: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806EAC58: jr          $ra
    // 0x806EAC5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x806EAC5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8078B87C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B87C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8078B880: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(796, 0X1150) << 16);
    // 0x8078B884: addiu       $t6, $t6, -0x3D20
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(796, 0X1150));
    // 0x8078B888: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8078B88C: jr          $ra
    // 0x8078B890: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8078B890: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804B70C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B70C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B70C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B70C8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804B70CC: lui         $v0, 0x804B
    ctx->r2 = S32(RELOC_HI16(182, 0X1178) << 16);
    // 0x804B70D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804B70D4: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x804B70D8: lw          $v0, 0x7418($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(182, 0X1178));
    // 0x804B70DC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804B70E0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804B70E4: beql        $v1, $zero, L_804B7118
    if (ctx->r3 == 0) {
        // 0x804B70E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804B7118;
    }
    goto skip_0;
    // 0x804B70E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804B70EC: jalr        $v1
    // 0x804B70F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804B70F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B70F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B70F8: lw          $t8, 0x15C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X15C);
    // 0x804B70FC: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804B7100: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x804B7104: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804B7108: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x804B710C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804B7110: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x804B7114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804B7118:
    // 0x804B7118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B711C: jr          $ra
    // 0x804B7120: nop

    return;
    // 0x804B7120: nop

;}
RECOMP_FUNC void func_80468288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80468288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046828C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80468290: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80468294: beql        $a1, $zero, L_804682A8
    if (ctx->r5 == 0) {
        // 0x80468298: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804682A8;
    }
    goto skip_0;
    // 0x80468298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8046829C: jal         0x800568E0
    // 0x804682A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800568E0(rdram, ctx);
        goto after_0;
    // 0x804682A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x804682A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804682A8:
    // 0x804682A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804682AC: jr          $ra
    // 0x804682B0: nop

    return;
    // 0x804682B0: nop

;}
RECOMP_FUNC void func_80557F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80557F88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80557F8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80557F90: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80557F94: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80557F98: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x80557F9C: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x80557FA0: bne         $t6, $zero, L_80558020
    if (ctx->r14 != 0) {
        // 0x80557FA4: ori         $t7, $v1, 0x2
        ctx->r15 = ctx->r3 | 0X2;
            goto L_80558020;
    }
    // 0x80557FA4: ori         $t7, $v1, 0x2
    ctx->r15 = ctx->r3 | 0X2;
    // 0x80557FA8: sw          $t7, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r15;
    // 0x80557FAC: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x80557FB0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80557FB4: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x80557FB8: beq         $t8, $zero, L_80558000
    if (ctx->r24 == 0) {
        // 0x80557FBC: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80558000;
    }
    // 0x80557FBC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80557FC0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80557FC4: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x80557FC8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80557FCC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80557FD0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80557FD4: jal         0x8004D1F0
    // 0x80557FD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x80557FD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80557FDC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80557FE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80557FE4: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x80557FE8: jal         0x8004D698
    // 0x80557FEC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x80557FEC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80557FF0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80557FF4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80557FF8: b           L_80558020
    // 0x80557FFC: sw          $t9, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r25;
        goto L_80558020;
    // 0x80557FFC: sw          $t9, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r25;
L_80558000:
    // 0x80558000: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80558004: jal         0x8004D1F0
    // 0x80558008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x80558008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x8055800C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80558010: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80558014: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x80558018: jal         0x8004D698
    // 0x8055801C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x8055801C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
L_80558020:
    // 0x80558020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80558024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80558028: jr          $ra
    // 0x8055802C: nop

    return;
    // 0x8055802C: nop

;}
RECOMP_FUNC void func_80462220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462220: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80462224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80462228: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8046222C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80462230: jal         0x8004700C
    // 0x80462234: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80462234: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80462238: beq         $v0, $zero, L_804622B0
    if (ctx->r2 == 0) {
        // 0x8046223C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_804622B0;
    }
    // 0x8046223C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80462240: jal         0x80461C60
    // 0x80462244: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80461C60(rdram, ctx);
        goto after_1;
    // 0x80462244: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80462248: jal         0x80461F3C
    // 0x8046224C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80461F3C(rdram, ctx);
        goto after_2;
    // 0x8046224C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80462250: jal         0x80462014
    // 0x80462254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80462014(rdram, ctx);
        goto after_3;
    // 0x80462254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80462258: jal         0x8046212C
    // 0x8046225C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8046212C(rdram, ctx);
        goto after_4;
    // 0x8046225C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80462260: jal         0x80461C04
    // 0x80462264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80461C04(rdram, ctx);
        goto after_5;
    // 0x80462264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80462268: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x8046226C: beql        $s1, $t6, L_804622B4
    if (ctx->r17 == ctx->r14) {
        // 0x80462270: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804622B4;
    }
    goto skip_0;
    // 0x80462270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80462274: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80462278: lwc1        $f6, 0xC4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8046227C: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80462280: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80462284: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80462288: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x8046228C: lwc1        $f16, 0xC8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x80462290: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80462294: jal         0x80461FB4
    // 0x80462298: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    func_80461FB4(rdram, ctx);
        goto after_6;
    // 0x80462298: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    after_6:
    // 0x8046229C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804622A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804622A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804622A8: jal         0x804623F0
    // 0x804622AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804623F0(rdram, ctx);
        goto after_7;
    // 0x804622AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_804622B0:
    // 0x804622B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804622B4:
    // 0x804622B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804622B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804622BC: jr          $ra
    // 0x804622C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x804622C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8070CA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070CA90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070CA94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070CA98: jal         0x8070C934
    // 0x8070CA9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8070C934(rdram, ctx);
        goto after_0;
    // 0x8070CA9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8070CAA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8070CAA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8070CAA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8070CAAC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8070CAB0: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x8070CAB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070CAB8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8070CABC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8070CAC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8070CAC4: bc1fl       L_8070CAD8
    if (!c1cs) {
        // 0x8070CAC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8070CAD8;
    }
    goto skip_0;
    // 0x8070CAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8070CACC: jal         0x8070D208
    // 0x8070CAD0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    func_8070D208(rdram, ctx);
        goto after_1;
    // 0x8070CAD0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    after_1:
    // 0x8070CAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8070CAD8:
    // 0x8070CAD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070CADC: jr          $ra
    // 0x8070CAE0: nop

    return;
    // 0x8070CAE0: nop

;}
RECOMP_FUNC void func_804371BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804371BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804371C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804371C4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x804371C8: lwc1        $f2, 0xC4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x804371CC: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x804371D0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x804371D4: nop

    // 0x804371D8: bc1fl       L_80437234
    if (!c1cs) {
        // 0x804371DC: c.le.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
            goto L_80437234;
    }
    goto skip_0;
    // 0x804371DC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    skip_0:
    // 0x804371E0: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804371E4: nop

    // 0x804371E8: bc1fl       L_8043720C
    if (!c1cs) {
        // 0x804371EC: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8043720C;
    }
    goto skip_1;
    // 0x804371EC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x804371F0: jal         0x80437148
    // 0x804371F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80437148(rdram, ctx);
        goto after_0;
    // 0x804371F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x804371F8: jal         0x80437178
    // 0x804371FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80437178(rdram, ctx);
        goto after_1;
    // 0x804371FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80437200: b           L_8043725C
    // 0x80437204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043725C;
    // 0x80437204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80437208: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8043720C:
    // 0x8043720C: nop

    // 0x80437210: bc1fl       L_8043725C
    if (!c1cs) {
        // 0x80437214: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043725C;
    }
    goto skip_2;
    // 0x80437214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80437218: jal         0x80437148
    // 0x8043721C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80437148(rdram, ctx);
        goto after_2;
    // 0x8043721C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80437220: jal         0x80437178
    // 0x80437224: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80437178(rdram, ctx);
        goto after_3;
    // 0x80437224: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80437228: b           L_8043725C
    // 0x8043722C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043725C;
    // 0x8043722C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80437230: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
L_80437234:
    // 0x80437234: nop

    // 0x80437238: bc1fl       L_8043725C
    if (!c1cs) {
        // 0x8043723C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043725C;
    }
    goto skip_3;
    // 0x8043723C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80437240: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80437244: nop

    // 0x80437248: bc1fl       L_8043725C
    if (!c1cs) {
        // 0x8043724C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043725C;
    }
    goto skip_4;
    // 0x8043724C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80437250: jal         0x80437118
    // 0x80437254: nop

    func_80437118(rdram, ctx);
        goto after_4;
    // 0x80437254: nop

    after_4:
    // 0x80437258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043725C:
    // 0x8043725C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80437260: jr          $ra
    // 0x80437264: nop

    return;
    // 0x80437264: nop

;}
RECOMP_FUNC void func_806ED6C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED6C4: lh          $v1, 0x184($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X184);
    // 0x806ED6C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806ED6CC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x806ED6D0: blez        $v1, L_806ED708
    if (SIGNED(ctx->r3) <= 0) {
        // 0x806ED6D4: addiu       $a2, $zero, 0x45E4
        ctx->r6 = ADD32(0, 0X45E4);
            goto L_806ED708;
    }
    // 0x806ED6D4: addiu       $a2, $zero, 0x45E4
    ctx->r6 = ADD32(0, 0X45E4);
L_806ED6D8:
    // 0x806ED6D8: lw          $a0, 0x188($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X188);
    // 0x806ED6DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x806ED6E0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x806ED6E4: beq         $a0, $zero, L_806ED700
    if (ctx->r4 == 0) {
        // 0x806ED6E8: nop
    
            goto L_806ED700;
    }
    // 0x806ED6E8: nop

    // 0x806ED6EC: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x806ED6F0: bne         $a2, $t6, L_806ED700
    if (ctx->r6 != ctx->r14) {
        // 0x806ED6F4: nop
    
            goto L_806ED700;
    }
    // 0x806ED6F4: nop

    // 0x806ED6F8: jr          $ra
    // 0x806ED6FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x806ED6FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806ED700:
    // 0x806ED700: bne         $at, $zero, L_806ED6D8
    if (ctx->r1 != 0) {
        // 0x806ED704: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_806ED6D8;
    }
    // 0x806ED704: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_806ED708:
    // 0x806ED708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806ED70C: jr          $ra
    // 0x806ED710: nop

    return;
    // 0x806ED710: nop

;}
RECOMP_FUNC void func_804C9624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C9624: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C9628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C962C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x804C9630: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C9634: jal         0x80048F84
    // 0x804C9638: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x804C9638: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804C963C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C9640: jal         0x80048F84
    // 0x804C9644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x804C9644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804C9648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C964C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C9650: jr          $ra
    // 0x804C9654: nop

    return;
    // 0x804C9654: nop

;}
RECOMP_FUNC void func_8045F290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F290: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8045F294: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8045F298: jr          $ra
    // 0x8045F29C: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    return;
    // 0x8045F29C: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8044899C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044899C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804489A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804489A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x804489A8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x804489AC: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804489B0: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804489B4: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X1336C) << 16);
    // 0x804489B8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804489BC: lw          $v1, 0x6CB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CB4);
    // 0x804489C0: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x804489C4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x804489C8: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x804489CC: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x804489D0: lw          $t0, 0x774C($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X1336C));
    // 0x804489D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804489D8: beql        $t0, $zero, L_804489EC
    if (ctx->r8 == 0) {
        // 0x804489DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804489EC;
    }
    goto skip_0;
    // 0x804489DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804489E0: jalr        $t0
    // 0x804489E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x804489E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x804489E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804489EC:
    // 0x804489EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804489F0: jr          $ra
    // 0x804489F4: nop

    return;
    // 0x804489F4: nop

;}
RECOMP_FUNC void func_805323E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805323E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805323EC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x805323F0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x805323F4: lui         $t7, 0x8053
    ctx->r15 = S32(RELOC_HI16(342, 0X19CC) << 16);
    // 0x805323F8: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x805323FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80532400: lw          $t7, 0x27BC($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(342, 0X19CC));
    // 0x80532404: jr          $ra
    // 0x80532408: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x80532408: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8005FC0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FC0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005FC10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FC14: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8005FC18: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005FC1C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005FC20: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005FC24: lbu         $t7, 0x78($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X78);
    // 0x8005FC28: bnel        $t7, $zero, L_8005FC50
    if (ctx->r15 != 0) {
        // 0x8005FC2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FC50;
    }
    goto skip_0;
    // 0x8005FC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005FC30: jal         0x8005F9A8
    // 0x8005FC34: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8005F9A8(rdram, ctx);
        goto after_0;
    // 0x8005FC34: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005FC38: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005FC3C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005FC40: lw          $t9, 0x174($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X174);
    // 0x8005FC44: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8005FC48: sb          $t8, 0x78($t0)
    MEM_B(0X78, ctx->r8) = ctx->r24;
    // 0x8005FC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FC50:
    // 0x8005FC50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005FC54: jr          $ra
    // 0x8005FC58: nop

    return;
    // 0x8005FC58: nop

;}
RECOMP_FUNC void func_80536594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536594: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536598: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053659C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805365A0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805365A4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805365A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805365AC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805365B0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805365B4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805365B8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805365BC: jr          $ra
    // 0x805365C0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805365C0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8044BA04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BA04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044BA08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044BA0C: jal         0x8044B740
    // 0x8044BA10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8044B740(rdram, ctx);
        goto after_0;
    // 0x8044BA10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8044BA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044BA18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044BA1C: jr          $ra
    // 0x8044BA20: nop

    return;
    // 0x8044BA20: nop

;}
RECOMP_FUNC void func_8073FAD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073FAD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073FAD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073FADC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073FAE0: jal         0x8073F3B4
    // 0x8073FAE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8073F3B4(rdram, ctx);
        goto after_0;
    // 0x8073FAE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8073FAE8: jal         0x8073F638
    // 0x8073FAEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F638(rdram, ctx);
        goto after_1;
    // 0x8073FAEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8073FAF0: jal         0x8073F98C
    // 0x8073FAF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F98C(rdram, ctx);
        goto after_2;
    // 0x8073FAF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8073FAF8: jal         0x8073F760
    // 0x8073FAFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F760(rdram, ctx);
        goto after_3;
    // 0x8073FAFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8073FB00: jal         0x8073FAC4
    // 0x8073FB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073FAC4(rdram, ctx);
        goto after_4;
    // 0x8073FB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8073FB08: beq         $v0, $zero, L_8073FB44
    if (ctx->r2 == 0) {
        // 0x8073FB0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8073FB44;
    }
    // 0x8073FB0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073FB10: jal         0x8073F848
    // 0x8073FB14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F848(rdram, ctx);
        goto after_5;
    // 0x8073FB14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8073FB18: beq         $v0, $zero, L_8073FB54
    if (ctx->r2 == 0) {
        // 0x8073FB1C: nop
    
            goto L_8073FB54;
    }
    // 0x8073FB1C: nop

    // 0x8073FB20: jal         0x8073F8C8
    // 0x8073FB24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F8C8(rdram, ctx);
        goto after_6;
    // 0x8073FB24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8073FB28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073FB2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073FB30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8073FB34: jal         0x8073FD38
    // 0x8073FB38: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8073FD38(rdram, ctx);
        goto after_7;
    // 0x8073FB38: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x8073FB3C: b           L_8073FB54
    // 0x8073FB40: nop

        goto L_8073FB54;
    // 0x8073FB40: nop

L_8073FB44:
    // 0x8073FB44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073FB48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8073FB4C: jal         0x8073FD38
    // 0x8073FB50: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8073FD38(rdram, ctx);
        goto after_8;
    // 0x8073FB50: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_8:
L_8073FB54:
    // 0x8073FB54: jal         0x8073F2FC
    // 0x8073FB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F2FC(rdram, ctx);
        goto after_9;
    // 0x8073FB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8073FB5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073FB60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073FB64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073FB68: jr          $ra
    // 0x8073FB6C: nop

    return;
    // 0x8073FB6C: nop

;}
RECOMP_FUNC void func_8004E8DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E8DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004E8E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004E8E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004E8E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004E8EC: lw          $s0, 0x174($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X174);
    // 0x8004E8F0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004E8F4: jal         0x8004E79C
    // 0x8004E8F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004E79C(rdram, ctx);
        goto after_0;
    // 0x8004E8F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8004E8FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E900: jal         0x8004E57C
    // 0x8004E904: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004E57C(rdram, ctx);
        goto after_1;
    // 0x8004E904: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8004E908: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8004E90C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004E910: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004E914: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004E918: jal         0x8004AB60
    // 0x8004E91C: lhu         $a2, 0x60($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X60);
    func_8004AB60(rdram, ctx);
        goto after_2;
    // 0x8004E91C: lhu         $a2, 0x60($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X60);
    after_2:
    // 0x8004E920: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E924: jal         0x8004E658
    // 0x8004E928: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004E658(rdram, ctx);
        goto after_3;
    // 0x8004E928: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8004E92C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8004E930: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E934: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E938: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8004E93C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8004E940: jal         0x8004A9C4
    // 0x8004E944: lhu         $a2, 0x18($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X18);
    func_8004A9C4(rdram, ctx);
        goto after_4;
    // 0x8004E944: lhu         $a2, 0x18($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X18);
    after_4:
    // 0x8004E948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004E94C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004E950: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004E954: jr          $ra
    // 0x8004E958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8004E958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80554928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80554928: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8055492C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80554930: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80554934: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80554938: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8055493C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80554940: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80554944: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x80554948: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8055494C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80554950: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80554954: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80554958: bne         $t7, $at, L_80554A38
    if (ctx->r15 != ctx->r1) {
        // 0x8055495C: lw          $s1, 0x1F4($t6)
        ctx->r17 = MEM_W(ctx->r14, 0X1F4);
            goto L_80554A38;
    }
    // 0x8055495C: lw          $s1, 0x1F4($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X1F4);
    // 0x80554960: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80554964: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80554968: beq         $v0, $at, L_80554980
    if (ctx->r2 == ctx->r1) {
        // 0x8055496C: addiu       $at, $zero, 0x4018
        ctx->r1 = ADD32(0, 0X4018);
            goto L_80554980;
    }
    // 0x8055496C: addiu       $at, $zero, 0x4018
    ctx->r1 = ADD32(0, 0X4018);
    // 0x80554970: beql        $v0, $at, L_805549D8
    if (ctx->r2 == ctx->r1) {
        // 0x80554974: lw          $t0, 0xDE4($s1)
        ctx->r8 = MEM_W(ctx->r17, 0XDE4);
            goto L_805549D8;
    }
    goto skip_0;
    // 0x80554974: lw          $t0, 0xDE4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XDE4);
    skip_0:
    // 0x80554978: b           L_80554A3C
    // 0x8055497C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80554A3C;
    // 0x8055497C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80554980:
    // 0x80554980: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80554984: jal         0x80067BBC
    // 0x80554988: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80554988: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x8055498C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80554990: jal         0x80067818
    // 0x80554994: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80554994: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80554998: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8055499C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805549A0: sb          $t8, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r24;
    // 0x805549A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805549A8: jalr        $t9
    // 0x805549AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x805549AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x805549B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805549B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x805549B8: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x805549BC: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x805549C0: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x805549C4: jal         0x8055394C
    // 0x805549C8: lw          $a0, 0x180($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X180);
    func_8055394C(rdram, ctx);
        goto after_3;
    // 0x805549C8: lw          $a0, 0x180($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X180);
    after_3:
    // 0x805549CC: b           L_80554A3C
    // 0x805549D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80554A3C;
    // 0x805549D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805549D4: lw          $t0, 0xDE4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XDE4);
L_805549D8:
    // 0x805549D8: bnel        $t0, $zero, L_80554A3C
    if (ctx->r8 != 0) {
        // 0x805549DC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80554A3C;
    }
    goto skip_1;
    // 0x805549DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x805549E0: lw          $t1, 0xDF8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XDF8);
    // 0x805549E4: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x805549E8: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x805549EC: bnel        $t1, $zero, L_80554A3C
    if (ctx->r9 != 0) {
        // 0x805549F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80554A3C;
    }
    goto skip_2;
    // 0x805549F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x805549F4: lw          $v0, 0xDE8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XDE8);
    // 0x805549F8: beq         $v0, $zero, L_80554A04
    if (ctx->r2 == 0) {
        // 0x805549FC: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_80554A04;
    }
    // 0x805549FC: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80554A00: sw          $t2, 0xDE8($s1)
    MEM_W(0XDE8, ctx->r17) = ctx->r10;
L_80554A04:
    // 0x80554A04: sw          $zero, 0xDCC($s1)
    MEM_W(0XDCC, ctx->r17) = 0;
    // 0x80554A08: sw          $t3, 0xDE4($s1)
    MEM_W(0XDE4, ctx->r17) = ctx->r11;
    // 0x80554A0C: sw          $t4, 0xDF8($s1)
    MEM_W(0XDF8, ctx->r17) = ctx->r12;
    // 0x80554A10: lw          $a1, 0x38($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X38);
    // 0x80554A14: jal         0x80067BBC
    // 0x80554A18: lw          $a0, 0x34($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x80554A18: lw          $a0, 0x34($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X34);
    after_4:
    // 0x80554A1C: addiu       $a0, $zero, 0x279
    ctx->r4 = ADD32(0, 0X279);
    // 0x80554A20: jal         0x80067818
    // 0x80554A24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x80554A24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80554A28: lw          $a0, 0x180($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X180);
    // 0x80554A2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80554A30: jal         0x8055394C
    // 0x80554A34: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    func_8055394C(rdram, ctx);
        goto after_6;
    // 0x80554A34: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    after_6:
L_80554A38:
    // 0x80554A38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80554A3C:
    // 0x80554A3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80554A40: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80554A44: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80554A48: jr          $ra
    // 0x80554A4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80554A4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80021C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021C88: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80021C8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021C90: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80021C94: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80021C98: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80021C9C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80021CA0: sw          $a1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r5;
    // 0x80021CA4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80021CA8: jal         0x80047AB8
    // 0x80021CAC: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80021CAC: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    after_0:
    // 0x80021CB0: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80021CB4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80021CB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80021CBC: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x80021CC0: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
    // 0x80021CC4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80021CC8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80021CCC: lwc1        $f10, 0x64($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X64);
    // 0x80021CD0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80021CD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80021CD8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80021CDC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80021CE0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80021CE4: lwc1        $f18, -0x3B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3B4);
    // 0x80021CE8: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80021CEC: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x80021CF0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80021CF4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80021CF8: lw          $t0, 0x34($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X34);
    // 0x80021CFC: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80021D00: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80021D04: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80021D08: jal         0x800653D8
    // 0x80021D0C: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x80021D0C: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80021D10: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80021D14: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80021D18: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80021D1C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80021D20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80021D24: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021D28: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80021D2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80021D30: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80021D34: lwc1        $f18, 0x6C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x80021D38: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80021D3C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80021D40: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80021D44: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80021D48: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80021D4C: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x80021D50: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x80021D54: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80021D58: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80021D5C: lwc1        $f16, -0x3B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3B0);
    // 0x80021D60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80021D64: lwc1        $f18, -0x3AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3AC);
    // 0x80021D68: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80021D6C: lwc1        $f4, -0x3A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A8);
    // 0x80021D70: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80021D74: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80021D78: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80021D7C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80021D80: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80021D84: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80021D88: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x80021D8C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80021D90: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80021D94: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80021D98: lw          $t9, 0x10($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X10);
    // 0x80021D9C: jalr        $t9
    // 0x80021DA0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80021DA0: nop

    after_2:
    // 0x80021DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021DA8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80021DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021DB0: jr          $ra
    // 0x80021DB4: nop

    return;
    // 0x80021DB4: nop

;}
