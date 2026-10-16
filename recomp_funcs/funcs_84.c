#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_806DB4C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB4C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DB4C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806DB4C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DB4CC: lui         $a0, 0x806E
    ctx->r4 = S32(RELOC_HI16(634, 0X760) << 16);
    // 0x806DB4D0: lui         $a1, 0x806E
    ctx->r5 = S32(RELOC_HI16(634, 0X770) << 16);
    // 0x806DB4D4: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(634, 0X770));
    // 0x806DB4D8: addiu       $a0, $a0, -0x43E0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(634, 0X760));
    // 0x806DB4DC: jal         0x8004667C
    // 0x806DB4E0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x806DB4E0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x806DB4E4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x806DB4E8: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x806DB4EC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x806DB4F0: lui         $a2, 0x806E
    ctx->r6 = S32(RELOC_HI16(634, 0X4D4) << 16);
    // 0x806DB4F4: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x806DB4F8: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x806DB4FC: bnel        $t7, $zero, L_806DB510
    if (ctx->r15 != 0) {
        // 0x806DB500: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806DB510;
    }
    goto skip_0;
    // 0x806DB500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806DB504: jal         0x80057B28
    // 0x806DB508: addiu       $a2, $a2, -0x466C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(634, 0X4D4));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x806DB508: addiu       $a2, $a2, -0x466C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(634, 0X4D4));
    after_1:
    // 0x806DB50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806DB510:
    // 0x806DB510: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(634, 0X78) << 16);
    // 0x806DB514: addiu       $v0, $v0, -0x4AC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(634, 0X78));
    // 0x806DB518: jr          $ra
    // 0x806DB51C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806DB51C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80072940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072940: sw          $a1, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r5;
    // 0x80072944: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80072948: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    // 0x8007294C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80072950: addiu       $t7, $t7, -0x7B70
    ctx->r15 = ADD32(ctx->r15, -0X7B70);
    // 0x80072954: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
    // 0x80072958: addiu       $t1, $t7, 0x3C
    ctx->r9 = ADD32(ctx->r15, 0X3C);
    // 0x8007295C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_80072960:
    // 0x80072960: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80072964: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80072968: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8007296C: sw          $t9, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r25;
    // 0x80072970: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80072974: sw          $t8, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r24;
    // 0x80072978: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8007297C: bne         $t7, $t1, L_80072960
    if (ctx->r15 != ctx->r9) {
        // 0x80072980: sw          $t9, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r25;
            goto L_80072960;
    }
    // 0x80072980: sw          $t9, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r25;
    // 0x80072984: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80072988: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x8007298C: subu        $t2, $t2, $a1
    ctx->r10 = SUB32(ctx->r10, ctx->r5);
    // 0x80072990: lui         $t3, 0x800B
    ctx->r11 = S32(0X800B << 16);
    // 0x80072994: addiu       $t3, $t3, -0x65D0
    ctx->r11 = ADD32(ctx->r11, -0X65D0);
    // 0x80072998: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8007299C: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x800729A0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800729A4: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x800729A8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800729AC: addiu       $a2, $a2, 0x34C0
    ctx->r6 = ADD32(ctx->r6, 0X34C0);
    // 0x800729B0: sw          $t4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r12;
    // 0x800729B4: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800729B8: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x800729BC: addu        $t6, $a2, $v1
    ctx->r14 = ADD32(ctx->r6, ctx->r3);
    // 0x800729C0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800729C4: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x800729C8: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
    // 0x800729CC: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x800729D0: sw          $t5, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r13;
    // 0x800729D4: jr          $ra
    // 0x800729D8: nop

    return;
    // 0x800729D8: nop

;}
RECOMP_FUNC void func_804540C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804540C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804540CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804540D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804540D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804540D8: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804540DC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804540E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x804540E4: addu        $v0, $s0, $at
    ctx->r2 = ADD32(ctx->r16, ctx->r1);
    // 0x804540E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804540EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804540F0: lwc1        $f4, 0x6C84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C84);
    // 0x804540F4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804540F8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804540FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80454100: swc1        $f8, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f8.u32l;
    // 0x80454104: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80454108: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8045410C: lwc1        $f10, 0x6C84($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C84);
    // 0x80454110: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80454114: nop

    // 0x80454118: bc1f        L_804541D4
    if (!c1cs) {
        // 0x8045411C: nop
    
            goto L_804541D4;
    }
    // 0x8045411C: nop

    // 0x80454120: lw          $v1, 0xA5C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA5C);
    // 0x80454124: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80454128: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8045412C: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80454130: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80454134: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80454138: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8045413C: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80454140: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80454144: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80454148: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8045414C: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80454150: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80454154: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80454158: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x8045415C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80454160: jal         0x80446D70
    // 0x80454164: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80446D70(rdram, ctx);
        goto after_0;
    // 0x80454164: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x80454168: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x8045416C: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80454170: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80454174: jal         0x8044EEF8
    // 0x80454178: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8044EEF8(rdram, ctx);
        goto after_1;
    // 0x80454178: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x8045417C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80454180: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80454184: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80454188: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8045418C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80454190: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80454194: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80454198: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8045419C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x804541A0: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x804541A4: addu        $a1, $s0, $t0
    ctx->r5 = ADD32(ctx->r16, ctx->r8);
    // 0x804541A8: jal         0x8044ED68
    // 0x804541AC: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_2;
    // 0x804541AC: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_2:
    // 0x804541B0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x804541B4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804541B8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804541BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804541C0: sw          $t1, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r9;
    // 0x804541C4: jal         0x80450490
    // 0x804541C8: lwc1        $f12, 0x6C84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X6C84);
    func_80450490(rdram, ctx);
        goto after_3;
    // 0x804541C8: lwc1        $f12, 0x6C84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X6C84);
    after_3:
    // 0x804541CC: b           L_804541E8
    // 0x804541D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804541E8;
    // 0x804541D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804541D4:
    // 0x804541D4: jal         0x804448BC
    // 0x804541D8: nop

    func_804448BC(rdram, ctx);
        goto after_4;
    // 0x804541D8: nop

    after_4:
    // 0x804541DC: jal         0x80453B80
    // 0x804541E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80453B80(rdram, ctx);
        goto after_5;
    // 0x804541E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x804541E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804541E8:
    // 0x804541E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804541EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804541F0: jr          $ra
    // 0x804541F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x804541F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807B8D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8D30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B8D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B8D38: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B8D3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807B8D40: jal         0x807B8C78
    // 0x807B8D44: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_807B8C78(rdram, ctx);
        goto after_0;
    // 0x807B8D44: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x807B8D48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807B8D4C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807B8D50: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x807B8D54: addiu       $t7, $t6, -0x5
    ctx->r15 = ADD32(ctx->r14, -0X5);
    // 0x807B8D58: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x807B8D5C: beq         $at, $zero, L_807B8ECC
    if (ctx->r1 == 0) {
        // 0x807B8D60: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_807B8ECC;
    }
    // 0x807B8D60: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807B8D64: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(886, 0X1DB8) << 16);
    // 0x807B8D68: addu        $at, $at, $t7
    gpr jr_addend_807B8D70 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x807B8D6C: lw          $t7, -0x5FD8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(886, 0X1DB8));
    // 0x807B8D70: jr          $t7
    // 0x807B8D74: nop

    switch (jr_addend_807B8D70 >> 2) {
        case 0: goto L_807B8D78; break;
        case 1: goto L_807B8DBC; break;
        case 2: goto L_807B8E00; break;
        case 3: goto L_807B8E44; break;
        case 4: goto L_807B8E88; break;
        default: switch_error(__func__, 0x807B8D70, 0x807BA028);
    }
    // 0x807B8D74: nop

L_807B8D78:
    // 0x807B8D78: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x807B8D7C: lui         $v1, 0x807C
    ctx->r3 = S32(RELOC_HI16(886, 0X1C94) << 16);
    // 0x807B8D80: addiu       $v1, $v1, -0x60FC
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(886, 0X1C94));
    // 0x807B8D84: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x807B8D88: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x807B8D8C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x807B8D90: lw          $t1, 0x1C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8D94: swc1        $f4, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f4.u32l;
    // 0x807B8D98: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x807B8D9C: lw          $t5, 0x1C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8DA0: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x807B8DA4: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x807B8DA8: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x807B8DAC: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x807B8DB0: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8DB4: b           L_807B8ED8
    // 0x807B8DB8: sb          $zero, 0x165($t6)
    MEM_B(0X165, ctx->r14) = 0;
        goto L_807B8ED8;
    // 0x807B8DB8: sb          $zero, 0x165($t6)
    MEM_B(0X165, ctx->r14) = 0;
L_807B8DBC:
    // 0x807B8DBC: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x807B8DC0: lui         $v1, 0x807C
    ctx->r3 = S32(RELOC_HI16(886, 0X1CAC) << 16);
    // 0x807B8DC4: addiu       $v1, $v1, -0x60E4
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(886, 0X1CAC));
    // 0x807B8DC8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x807B8DCC: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x807B8DD0: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x807B8DD4: lw          $t0, 0x1C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8DD8: swc1        $f8, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f8.u32l;
    // 0x807B8DDC: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x807B8DE0: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8DE4: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x807B8DE8: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x807B8DEC: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x807B8DF0: swc1        $f10, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f10.u32l;
    // 0x807B8DF4: lw          $t5, 0x1C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8DF8: b           L_807B8ED8
    // 0x807B8DFC: sb          $zero, 0x165($t5)
    MEM_B(0X165, ctx->r13) = 0;
        goto L_807B8ED8;
    // 0x807B8DFC: sb          $zero, 0x165($t5)
    MEM_B(0X165, ctx->r13) = 0;
L_807B8E00:
    // 0x807B8E00: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x807B8E04: lui         $v1, 0x807C
    ctx->r3 = S32(RELOC_HI16(886, 0X1CC4) << 16);
    // 0x807B8E08: addiu       $v1, $v1, -0x60CC
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(886, 0X1CC4));
    // 0x807B8E0C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x807B8E10: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x807B8E14: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x807B8E18: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8E1C: swc1        $f16, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f16.u32l;
    // 0x807B8E20: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x807B8E24: lw          $t3, 0x1C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8E28: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x807B8E2C: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x807B8E30: lwc1        $f18, 0x4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X4);
    // 0x807B8E34: swc1        $f18, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
    // 0x807B8E38: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8E3C: b           L_807B8ED8
    // 0x807B8E40: sb          $zero, 0x165($t4)
    MEM_B(0X165, ctx->r12) = 0;
        goto L_807B8ED8;
    // 0x807B8E40: sb          $zero, 0x165($t4)
    MEM_B(0X165, ctx->r12) = 0;
L_807B8E44:
    // 0x807B8E44: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x807B8E48: lui         $v1, 0x807C
    ctx->r3 = S32(RELOC_HI16(886, 0X1CDC) << 16);
    // 0x807B8E4C: addiu       $v1, $v1, -0x60B4
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(886, 0X1CDC));
    // 0x807B8E50: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x807B8E54: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x807B8E58: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x807B8E5C: lw          $t8, 0x1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8E60: swc1        $f4, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f4.u32l;
    // 0x807B8E64: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x807B8E68: lw          $t2, 0x1C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8E6C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x807B8E70: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x807B8E74: lwc1        $f6, 0x4($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X4);
    // 0x807B8E78: swc1        $f6, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f6.u32l;
    // 0x807B8E7C: lw          $t3, 0x1C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8E80: b           L_807B8ED8
    // 0x807B8E84: sb          $zero, 0x165($t3)
    MEM_B(0X165, ctx->r11) = 0;
        goto L_807B8ED8;
    // 0x807B8E84: sb          $zero, 0x165($t3)
    MEM_B(0X165, ctx->r11) = 0;
L_807B8E88:
    // 0x807B8E88: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    // 0x807B8E8C: lui         $v1, 0x807C
    ctx->r3 = S32(RELOC_HI16(886, 0X1CFC) << 16);
    // 0x807B8E90: addiu       $v1, $v1, -0x6094
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(886, 0X1CFC));
    // 0x807B8E94: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x807B8E98: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x807B8E9C: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x807B8EA0: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8EA4: swc1        $f8, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f8.u32l;
    // 0x807B8EA8: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x807B8EAC: lw          $t1, 0x1C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8EB0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x807B8EB4: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x807B8EB8: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x807B8EBC: swc1        $f10, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f10.u32l;
    // 0x807B8EC0: lw          $t2, 0x1C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8EC4: b           L_807B8ED8
    // 0x807B8EC8: sb          $zero, 0x165($t2)
    MEM_B(0X165, ctx->r10) = 0;
        goto L_807B8ED8;
    // 0x807B8EC8: sb          $zero, 0x165($t2)
    MEM_B(0X165, ctx->r10) = 0;
L_807B8ECC:
    // 0x807B8ECC: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x807B8ED0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x807B8ED4: sb          $t3, 0x165($t4)
    MEM_B(0X165, ctx->r12) = ctx->r11;
L_807B8ED8:
    // 0x807B8ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B8EDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B8EE0: jr          $ra
    // 0x807B8EE4: nop

    return;
    // 0x807B8EE4: nop

;}
RECOMP_FUNC void func_80407EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80407EDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80407EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80407EE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80407EE8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80407EEC: addiu       $a0, $zero, 0x4103
    ctx->r4 = ADD32(0, 0X4103);
    // 0x80407EF0: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x80407EF4: beql        $t7, $zero, L_80407F68
    if (ctx->r15 == 0) {
        // 0x80407EF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80407F68;
    }
    goto skip_0;
    // 0x80407EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80407EFC: jal         0x80046E88
    // 0x80407F00: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x80407F00: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80407F04: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80407F08: beq         $v0, $zero, L_80407F64
    if (ctx->r2 == 0) {
        // 0x80407F0C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80407F64;
    }
    // 0x80407F0C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80407F10: lw          $v0, 0x1F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1F4);
    // 0x80407F14: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80407F18: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80407F1C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80407F20: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80407F24: addiu       $a0, $v0, 0xB50
    ctx->r4 = ADD32(ctx->r2, 0XB50);
    // 0x80407F28: swc1        $f4, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f4.u32l;
    // 0x80407F2C: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x80407F30: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x80407F34: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80407F38: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x80407F3C: jalr        $t9
    // 0x80407F40: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80407F40: nop

    after_1:
    // 0x80407F44: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80407F48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80407F4C: beq         $v0, $zero, L_80407F64
    if (ctx->r2 == 0) {
        // 0x80407F50: sw          $v0, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r2;
            goto L_80407F64;
    }
    // 0x80407F50: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80407F54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80407F58: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80407F5C: jal         0x8040818C
    // 0x80407F60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8040818C(rdram, ctx);
        goto after_2;
    // 0x80407F60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
L_80407F64:
    // 0x80407F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80407F68:
    // 0x80407F68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80407F6C: jr          $ra
    // 0x80407F70: nop

    return;
    // 0x80407F70: nop

;}
RECOMP_FUNC void func_80699424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699424: jr          $ra
    // 0x80699428: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80699428: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80453A84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453A84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453A88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453A8C: jal         0x804539F0
    // 0x80453A90: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_804539F0(rdram, ctx);
        goto after_0;
    // 0x80453A90: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80453A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453A98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453A9C: jr          $ra
    // 0x80453AA0: nop

    return;
    // 0x80453AA0: nop

;}
RECOMP_FUNC void func_8002C8E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C8E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002C8EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002C8F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002C8F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002C8F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002C8FC: lh          $s0, 0x184($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X184);
    // 0x8002C900: addiu       $s1, $a0, 0x188
    ctx->r17 = ADD32(ctx->r4, 0X188);
    // 0x8002C904: addiu       $s2, $zero, 0x4016
    ctx->r18 = ADD32(0, 0X4016);
    // 0x8002C908: beql        $s0, $zero, L_8002C948
    if (ctx->r16 == 0) {
        // 0x8002C90C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8002C948;
    }
    goto skip_0;
    // 0x8002C90C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_8002C910:
    // 0x8002C910: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002C914: beq         $a0, $zero, L_8002C93C
    if (ctx->r4 == 0) {
        // 0x8002C918: nop
    
            goto L_8002C93C;
    }
    // 0x8002C918: nop

    // 0x8002C91C: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8002C920: bnel        $s2, $t6, L_8002C934
    if (ctx->r18 != ctx->r14) {
        // 0x8002C924: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8002C934;
    }
    goto skip_1;
    // 0x8002C924: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_1:
    // 0x8002C928: jal         0x800447C8
    // 0x8002C92C: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x8002C92C: nop

    after_0:
    // 0x8002C930: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8002C934:
    // 0x8002C934: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8002C938: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8002C93C:
    // 0x8002C93C: bne         $s0, $zero, L_8002C910
    if (ctx->r16 != 0) {
        // 0x8002C940: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8002C910;
    }
    // 0x8002C940: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002C944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8002C948:
    // 0x8002C948: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002C94C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C950: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002C954: jr          $ra
    // 0x8002C958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002C958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80742EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742EC4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742EC8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742ECC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742ED0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742ED4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742ED8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742EDC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742EE0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742EE4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742EE8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742EEC: jr          $ra
    // 0x80742EF0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742EF0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8006F250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F258: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8006F25C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8006F260: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8006F264: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8006F268: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006F26C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8006F270: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006F274: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006F278: lw          $t8, 0x7F4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7F4C);
    // 0x8006F27C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8006F280: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006F284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006F288: jal         0x80048490
    // 0x8006F28C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8006F28C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8006F290: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8006F294: jal         0x80048378
    // 0x8006F298: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8006F298: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8006F29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F2A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F2A4: jr          $ra
    // 0x8006F2A8: nop

    return;
    // 0x8006F2A8: nop

;}
RECOMP_FUNC void func_8043BC40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043BC40: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(89, 0X10B0) << 16);
    // 0x8043BC44: addiu       $v0, $v0, -0x3310
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(89, 0X10B0));
    // 0x8043BC48: jr          $ra
    // 0x8043BC4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8043BC4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806FD460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD468: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806FD46C: addiu       $at, $zero, 0x4600
    ctx->r1 = ADD32(0, 0X4600);
    // 0x806FD470: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(706, 0X1060) << 16);
    // 0x806FD474: beq         $v0, $at, L_806FD48C
    if (ctx->r2 == ctx->r1) {
        // 0x806FD478: addiu       $at, $zero, 0x4602
        ctx->r1 = ADD32(0, 0X4602);
            goto L_806FD48C;
    }
    // 0x806FD478: addiu       $at, $zero, 0x4602
    ctx->r1 = ADD32(0, 0X4602);
    // 0x806FD47C: beq         $v0, $at, L_806FD4DC
    if (ctx->r2 == ctx->r1) {
        // 0x806FD480: nop
    
            goto L_806FD4DC;
    }
    // 0x806FD480: nop

    // 0x806FD484: b           L_806FD4E8
    // 0x806FD488: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(706, 0XF58) << 16);
        goto L_806FD4E8;
    // 0x806FD488: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(706, 0XF58) << 16);
L_806FD48C:
    // 0x806FD48C: lw          $t6, -0x1B40($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(706, 0X1060));
    // 0x806FD490: lui         $a0, 0x8070
    ctx->r4 = S32(RELOC_HI16(706, 0X1500) << 16);
    // 0x806FD494: addiu       $a0, $a0, -0x16A0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(706, 0X1500));
    // 0x806FD498: bne         $t6, $zero, L_806FD4D0
    if (ctx->r14 != 0) {
        // 0x806FD49C: lui         $a1, 0x8070
        ctx->r5 = S32(RELOC_HI16(706, 0X1510) << 16);
            goto L_806FD4D0;
    }
    // 0x806FD49C: lui         $a1, 0x8070
    ctx->r5 = S32(RELOC_HI16(706, 0X1510) << 16);
    // 0x806FD4A0: addiu       $a1, $a1, -0x1690
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(706, 0X1510));
    // 0x806FD4A4: jal         0x8004667C
    // 0x806FD4A8: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x806FD4A8: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_0:
    // 0x806FD4AC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x806FD4B0: lui         $a2, 0x8070
    ctx->r6 = S32(RELOC_HI16(706, 0XD4) << 16);
    // 0x806FD4B4: addiu       $a2, $a2, -0x2ACC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(706, 0XD4));
    // 0x806FD4B8: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x806FD4BC: jal         0x80057B28
    // 0x806FD4C0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x806FD4C0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_1:
    // 0x806FD4C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806FD4C8: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(706, 0X1060) << 16);
    // 0x806FD4CC: sw          $t7, -0x1B40($at)
    MEM_W((int16_t)RELOC_LO16(706, 0X1060), ctx->r1) = ctx->r15;
L_806FD4D0:
    // 0x806FD4D0: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(706, 0XF58) << 16);
    // 0x806FD4D4: b           L_806FD4EC
    // 0x806FD4D8: addiu       $v0, $v0, -0x1C48
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(706, 0XF58));
        goto L_806FD4EC;
    // 0x806FD4D8: addiu       $v0, $v0, -0x1C48
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(706, 0XF58));
L_806FD4DC:
    // 0x806FD4DC: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(706, 0XFA4) << 16);
    // 0x806FD4E0: b           L_806FD4EC
    // 0x806FD4E4: addiu       $v0, $v0, -0x1BFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(706, 0XFA4));
        goto L_806FD4EC;
    // 0x806FD4E4: addiu       $v0, $v0, -0x1BFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(706, 0XFA4));
L_806FD4E8:
    // 0x806FD4E8: addiu       $v0, $v0, -0x1C48
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(706, 0XF58));
L_806FD4EC:
    // 0x806FD4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FD4F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FD4F4: jr          $ra
    // 0x806FD4F8: nop

    return;
    // 0x806FD4F8: nop

;}
RECOMP_FUNC void func_80438C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438C18: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80438C1C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80438C20: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80438C24: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80438C28: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80438C2C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80438C30: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80438C34: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80438C38: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80438C3C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80438C40: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80438C44: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x80438C48: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80438C4C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80438C50: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80438C54: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80438C58: lbu         $t1, 0x13($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X13);
    // 0x80438C5C: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80438C60: sll         $t2, $a1, 24
    ctx->r10 = S32(ctx->r5 << 24);
    // 0x80438C64: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80438C68: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80438C6C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80438C70: or          $t3, $t8, $t1
    ctx->r11 = ctx->r24 | ctx->r9;
    // 0x80438C74: jr          $ra
    // 0x80438C78: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    return;
    // 0x80438C78: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
;}
RECOMP_FUNC void func_8073E8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073E8B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073E8B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073E8B8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8073E8BC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8073E8C0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8073E8C4: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(748, 0X234C) << 16);
    // 0x8073E8C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8073E8CC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8073E8D0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8073E8D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8073E8D8: lw          $t8, 0xB3C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(748, 0X234C));
    // 0x8073E8DC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8073E8E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8073E8E4: jal         0x80048490
    // 0x8073E8E8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8073E8E8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8073E8EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073E8F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073E8F4: jr          $ra
    // 0x8073E8F8: nop

    return;
    // 0x8073E8F8: nop

;}
RECOMP_FUNC void func_8057C8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C8D0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8057C8D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8057C8D8: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8057C8DC: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8057C8E0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8057C8E4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8057C8E8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8057C8EC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8057C8F0: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8057C8F4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8057C8F8: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x8057C8FC: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8057C900: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8057C904: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8057C908: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x8057C90C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8057C910: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8057C914: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(387, 0XE98) << 16);
    // 0x8057C918: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8057C91C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8057C920: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8057C924: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8057C928: lwc1        $f20, -0x3658($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(387, 0XE98));
    // 0x8057C92C: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x8057C930: lwc1        $f16, 0x8C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8057C934: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8057C938: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x8057C93C: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8057C940: add.s       $f22, $f4, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8057C944: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x8057C948: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
L_8057C94C:
    // 0x8057C94C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8057C950: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8057C954: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8057C958: jal         0x8057C728
    // 0x8057C95C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_8057C728(rdram, ctx);
        goto after_0;
    // 0x8057C95C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_0:
    // 0x8057C960: beq         $v0, $zero, L_8057C970
    if (ctx->r2 == 0) {
        // 0x8057C964: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8057C970;
    }
    // 0x8057C964: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8057C968: bnel        $s0, $s3, L_8057C94C
    if (ctx->r16 != ctx->r19) {
        // 0x8057C96C: mfc1        $a3, $f20
        ctx->r7 = (int32_t)ctx->f20.u32l;
            goto L_8057C94C;
    }
    goto skip_0;
    // 0x8057C96C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    skip_0:
L_8057C970:
    // 0x8057C970: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8057C974: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8057C978: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8057C97C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8057C980: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8057C984: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8057C988: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8057C98C: jr          $ra
    // 0x8057C990: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8057C990: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8057C994: nop

    // 0x8057C998: nop

    // 0x8057C99C: nop

;}
RECOMP_FUNC void func_8043F6F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F6F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043F6F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043F6FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043F700: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F704: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043F708: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x8043F70C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F710: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8043F714: jal         0x80442188
    // 0x8043F718: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80442188(rdram, ctx);
        goto after_0;
    // 0x8043F718: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8043F71C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4E9C) << 16);
    // 0x8043F720: lwc1        $f0, 0x3D9C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4E9C));
    // 0x8043F724: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8043F728: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8043F72C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8043F730: sw          $zero, 0x2628($v0)
    MEM_W(0X2628, ctx->r2) = 0;
    // 0x8043F734: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8043F738: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EA0) << 16);
    // 0x8043F73C: swc1        $f0, 0x1C24($v0)
    MEM_W(0X1C24, ctx->r2) = ctx->f0.u32l;
    // 0x8043F740: swc1        $f0, 0x1C28($v0)
    MEM_W(0X1C28, ctx->r2) = ctx->f0.u32l;
    // 0x8043F744: lwc1        $f4, 0x3DA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EA0));
    // 0x8043F748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043F74C: swc1        $f2, 0x1C88($v0)
    MEM_W(0X1C88, ctx->r2) = ctx->f2.u32l;
    // 0x8043F750: swc1        $f2, 0x1C8C($v0)
    MEM_W(0X1C8C, ctx->r2) = ctx->f2.u32l;
    // 0x8043F754: jal         0x8043F310
    // 0x8043F758: swc1        $f4, 0x1C74($v0)
    MEM_W(0X1C74, ctx->r2) = ctx->f4.u32l;
    func_8043F310(rdram, ctx);
        goto after_1;
    // 0x8043F758: swc1        $f4, 0x1C74($v0)
    MEM_W(0X1C74, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x8043F75C: jal         0x8043F42C
    // 0x8043F760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F42C(rdram, ctx);
        goto after_2;
    // 0x8043F760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8043F764: jal         0x8043F1A0
    // 0x8043F768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F1A0(rdram, ctx);
        goto after_3;
    // 0x8043F768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043F76C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043F770: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043F774: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043F778: jr          $ra
    // 0x8043F77C: nop

    return;
    // 0x8043F77C: nop

;}
RECOMP_FUNC void func_80522F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80522F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80522F30: jal         0x80522AD4
    // 0x80522F34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80522AD4(rdram, ctx);
        goto after_0;
    // 0x80522F34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80522F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80522F3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80522F40: jr          $ra
    // 0x80522F44: nop

    return;
    // 0x80522F44: nop

;}
RECOMP_FUNC void func_80058000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80058004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80058008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005800C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80058010: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80058014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80058018: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8005801C: beq         $t6, $zero, L_80058084
    if (ctx->r14 == 0) {
        // 0x80058020: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_80058084;
    }
    // 0x80058020: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80058024: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x80058028: lh          $t0, 0x4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4);
    // 0x8005802C: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x80058030: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80058034: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80058038: beq         $at, $zero, L_80058054
    if (ctx->r1 == 0) {
        // 0x8005803C: addu        $a0, $t8, $t9
        ctx->r4 = ADD32(ctx->r24, ctx->r25);
            goto L_80058054;
    }
    // 0x8005803C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80058040: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    // 0x80058044: jal         0x80057F74
    // 0x80058048: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80057F74(rdram, ctx);
        goto after_0;
    // 0x80058048: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x8005804C: b           L_80058088
    // 0x80058050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80058088;
    // 0x80058050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80058054:
    // 0x80058054: lh          $t1, 0x8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8);
    // 0x80058058: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8005805C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80058060: subu        $a1, $t1, $v0
    ctx->r5 = SUB32(ctx->r9, ctx->r2);
    // 0x80058064: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80058068: jal         0x80057F74
    // 0x8005806C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80057F74(rdram, ctx);
        goto after_1;
    // 0x8005806C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_1:
    // 0x80058070: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80058074: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80058078: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x8005807C: jal         0x80057F74
    // 0x80058080: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80057F74(rdram, ctx);
        goto after_2;
    // 0x80058080: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
L_80058084:
    // 0x80058084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80058088:
    // 0x80058088: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005808C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80058090: jr          $ra
    // 0x80058094: nop

    return;
    // 0x80058094: nop

;}
RECOMP_FUNC void func_8040EA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EA88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EA8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8040EA90: bne         $a1, $at, L_8040EAA8
    if (ctx->r5 != ctx->r1) {
        // 0x8040EA94: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8040EAA8;
    }
    // 0x8040EA94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EA98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040EA9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8040EAA0: jal         0x8040F0B8
    // 0x8040EAA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8040F0B8(rdram, ctx);
        goto after_0;
    // 0x8040EAA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
L_8040EAA8:
    // 0x8040EAA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040EAAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EAB0: jr          $ra
    // 0x8040EAB4: nop

    return;
    // 0x8040EAB4: nop

;}
RECOMP_FUNC void func_8000C7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C7E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000C7E4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000C7E8: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x8000C7EC: addiu       $s4, $s4, 0x4D10
    ctx->r20 = ADD32(ctx->r20, 0X4D10);
    // 0x8000C7F0: lw          $t6, 0x1DAC($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X1DAC);
    // 0x8000C7F4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000C7F8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000C7FC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000C800: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000C804: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000C808: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000C80C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000C810: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000C814: blez        $t6, L_8000C8D8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000C818: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000C8D8;
    }
    // 0x8000C818: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000C81C: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x8000C820: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x8000C824: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8000C828: addiu       $s5, $s5, 0x6C04
    ctx->r21 = ADD32(ctx->r21, 0X6C04);
    // 0x8000C82C: addiu       $s6, $s6, 0x6BE8
    ctx->r22 = ADD32(ctx->r22, 0X6BE8);
    // 0x8000C830: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000C834: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x8000C838: lw          $t7, 0x2A2C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X2A2C);
L_8000C83C:
    // 0x8000C83C: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x8000C840: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000C844: addu        $s0, $s2, $t7
    ctx->r16 = ADD32(ctx->r18, ctx->r15);
    // 0x8000C848: sw          $t9, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r25;
    // 0x8000C84C: lw          $t8, 0x4($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X4);
    // 0x8000C850: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x8000C854: sw          $t8, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->r24;
    // 0x8000C858: lw          $t9, 0x8($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X8);
    // 0x8000C85C: sw          $t9, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r25;
    // 0x8000C860: lw          $t8, 0xC($s5)
    ctx->r24 = MEM_W(ctx->r21, 0XC);
    // 0x8000C864: sw          $t8, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r24;
    // 0x8000C868: lw          $t9, 0x10($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X10);
    // 0x8000C86C: sw          $t9, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->r25;
    // 0x8000C870: lw          $t8, 0x14($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X14);
    // 0x8000C874: sw          $t8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->r24;
    // 0x8000C878: lw          $t9, 0x18($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X18);
    // 0x8000C87C: sw          $t9, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->r25;
    // 0x8000C880: lw          $t8, 0x1C($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X1C);
    // 0x8000C884: sb          $zero, 0x30($s0)
    MEM_B(0X30, ctx->r16) = 0;
    // 0x8000C888: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x8000C88C: sw          $s3, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r19;
    // 0x8000C890: sw          $s3, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r19;
    // 0x8000C894: sw          $s3, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r19;
    // 0x8000C898: sb          $zero, 0x31($s0)
    MEM_B(0X31, ctx->r16) = 0;
    // 0x8000C89C: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x8000C8A0: sh          $zero, 0x36($s0)
    MEM_H(0X36, ctx->r16) = 0;
    // 0x8000C8A4: sb          $zero, 0x60($s0)
    MEM_B(0X60, ctx->r16) = 0;
    // 0x8000C8A8: sb          $zero, 0xA0($s0)
    MEM_B(0XA0, ctx->r16) = 0;
    // 0x8000C8AC: sh          $zero, 0x82($s0)
    MEM_H(0X82, ctx->r16) = 0;
    // 0x8000C8B0: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x8000C8B4: jal         0x800035F8
    // 0x8000C8B8: sw          $t8, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->r24;
    func_800035F8(rdram, ctx);
        goto after_0;
    // 0x8000C8B8: sw          $t8, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->r24;
    after_0:
    // 0x8000C8BC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x8000C8C0: lw          $t0, 0x1DAC($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X1DAC);
    // 0x8000C8C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000C8C8: addiu       $s2, $s2, 0xD0
    ctx->r18 = ADD32(ctx->r18, 0XD0);
    // 0x8000C8CC: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000C8D0: bnel        $at, $zero, L_8000C83C
    if (ctx->r1 != 0) {
        // 0x8000C8D4: lw          $t7, 0x2A2C($s4)
        ctx->r15 = MEM_W(ctx->r20, 0X2A2C);
            goto L_8000C83C;
    }
    goto skip_0;
    // 0x8000C8D4: lw          $t7, 0x2A2C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X2A2C);
    skip_0:
L_8000C8D8:
    // 0x8000C8D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C8DC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000C8E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000C8E4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000C8E8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000C8EC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C8F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000C8F4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000C8F8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000C8FC: jr          $ra
    // 0x8000C900: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000C900: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000C904: nop

    // 0x8000C908: nop

    // 0x8000C90C: nop

;}
RECOMP_FUNC void func_804C31FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C31FC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x804C3200: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x804C3204: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x804C3208: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804C320C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804C3210: lwc1        $f0, 0x84($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X84);
    // 0x804C3214: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x804C3218: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804C321C: nop

    // 0x804C3220: bc1fl       L_804C3234
    if (!c1cs) {
        // 0x804C3224: lwc1        $f8, 0x18($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
            goto L_804C3234;
    }
    goto skip_0;
    // 0x804C3224: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    skip_0:
    // 0x804C3228: jr          $ra
    // 0x804C322C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x804C322C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804C3230: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
L_804C3234:
    // 0x804C3234: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x804C3238: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804C323C: nop

    // 0x804C3240: bc1fl       L_804C3254
    if (!c1cs) {
        // 0x804C3244: lwc1        $f16, 0x4($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
            goto L_804C3254;
    }
    goto skip_1;
    // 0x804C3244: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x804C3248: jr          $ra
    // 0x804C324C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x804C324C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804C3250: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
L_804C3254:
    // 0x804C3254: lwc1        $f0, 0x88($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X88);
    // 0x804C3258: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804C325C: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x804C3260: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x804C3264: nop

    // 0x804C3268: bc1fl       L_804C327C
    if (!c1cs) {
        // 0x804C326C: lwc1        $f4, 0x10($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
            goto L_804C327C;
    }
    goto skip_2;
    // 0x804C326C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    skip_2:
    // 0x804C3270: jr          $ra
    // 0x804C3274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x804C3274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804C3278: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
L_804C327C:
    // 0x804C327C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C3280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804C3284: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804C3288: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x804C328C: nop

    // 0x804C3290: bc1f        L_804C32A0
    if (!c1cs) {
        // 0x804C3294: nop
    
            goto L_804C32A0;
    }
    // 0x804C3294: nop

    // 0x804C3298: jr          $ra
    // 0x804C329C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x804C329C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C32A0:
    // 0x804C32A0: jr          $ra
    // 0x804C32A4: nop

    return;
    // 0x804C32A4: nop

;}
RECOMP_FUNC void func_80063F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F08: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80063F0C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80063F10: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80063F14: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80063F18: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80063F1C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80063F20: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80063F24: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80063F28: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80063F2C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80063F30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80063F34: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x80063F38: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x80063F3C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80063F40: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80063F44: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80063F48: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x80063F4C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80063F50: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x80063F54: addiu       $s5, $sp, 0xB4
    ctx->r21 = ADD32(ctx->r29, 0XB4);
    // 0x80063F58: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x80063F5C: lw          $s7, 0x4($v0)
    ctx->r23 = MEM_W(ctx->r2, 0X4);
    // 0x80063F60: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80063F64: sw          $t8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r24;
    // 0x80063F68: lw          $v1, 0xC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XC);
    // 0x80063F6C: lw          $s3, 0x18($a3)
    ctx->r19 = MEM_W(ctx->r7, 0X18);
    // 0x80063F70: lw          $s4, 0x1C($a3)
    ctx->r20 = MEM_W(ctx->r7, 0X1C);
    // 0x80063F74: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80063F78: mflo        $s1
    ctx->r17 = lo;
    // 0x80063F7C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80063F80: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80063F84: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80063F88: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80063F8C: mfhi        $t0
    ctx->r8 = hi;
    // 0x80063F90: addiu       $t5, $s7, 0x2
    ctx->r13 = ADD32(ctx->r23, 0X2);
    // 0x80063F94: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    // 0x80063F98: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    // 0x80063F9C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80063FA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80063FA4: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80063FA8: jal         0x80077338
    // 0x80063FAC: sw          $t2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r10;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x80063FAC: sw          $t2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r10;
    after_0:
    // 0x80063FB0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80063FB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80063FB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80063FBC: jal         0x8007711C
    // 0x80063FC0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x80063FC0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80063FC4: jal         0x80063414
    // 0x80063FC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80063414(rdram, ctx);
        goto after_2;
    // 0x80063FC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80063FCC: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80063FD0: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x80063FD4: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x80063FD8: beq         $s1, $zero, L_80064008
    if (ctx->r17 == 0) {
        // 0x80063FDC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80064008;
    }
    // 0x80063FDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80063FE0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x80063FE4: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x80063FE8: ori         $ra, $ra, 0x79DF
    ctx->r31 = ctx->r31 | 0X79DF;
    // 0x80063FEC: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80063FF0: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x80063FF4: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x80063FF8: sw          $ra, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r31;
    // 0x80063FFC: sw          $s2, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r18;
    // 0x80064000: b           L_80064044
    // 0x80064004: lui         $s0, 0x400
    ctx->r16 = S32(0X400 << 16);
        goto L_80064044;
    // 0x80064004: lui         $s0, 0x400
    ctx->r16 = S32(0X400 << 16);
L_80064008:
    // 0x80064008: lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB4);
    // 0x8006400C: sll         $t6, $t0, 4
    ctx->r14 = S32(ctx->r8 << 4);
    // 0x80064010: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80064014: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80064018: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8006401C: sll         $t9, $t0, 10
    ctx->r25 = S32(ctx->r8 << 10);
    // 0x80064020: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80064024: lui         $s0, 0x400
    ctx->r16 = S32(0X400 << 16);
    // 0x80064028: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8006402C: or          $t9, $t6, $s0
    ctx->r25 = ctx->r14 | ctx->r16;
    // 0x80064030: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x80064034: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80064038: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8006403C: sw          $s2, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r18;
    // 0x80064040: ori         $ra, $ra, 0x79DF
    ctx->r31 = ctx->r31 | 0X79DF;
L_80064044:
    // 0x80064044: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80064048: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8006404C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80064050: blez        $t7, L_80064318
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80064054: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_80064318;
    }
    // 0x80064054: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80064058: multu       $s3, $s4
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006405C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80064060: addiu       $t8, $v0, 0x7
    ctx->r24 = ADD32(ctx->r2, 0X7);
    // 0x80064064: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80064068: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8006406C: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x80064070: addiu       $t6, $s3, -0x1
    ctx->r14 = ADD32(ctx->r19, -0X1);
    // 0x80064074: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80064078: addiu       $t6, $s4, -0x1
    ctx->r14 = ADD32(ctx->r20, -0X1);
    // 0x8006407C: lui         $t4, 0xBF00
    ctx->r12 = S32(0XBF00 << 16);
    // 0x80064080: mflo        $fp
    ctx->r30 = lo;
    // 0x80064084: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80064088: sra         $fp, $fp, 1
    ctx->r30 = S32(SIGNED(ctx->r30) >> 1);
    // 0x8006408C: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // 0x80064090: bgez        $v0, L_800640A0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80064094: sra         $s5, $v0, 3
        ctx->r21 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800640A0;
    }
    // 0x80064094: sra         $s5, $v0, 3
    ctx->r21 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80064098: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8006409C: sra         $s5, $at, 3
    ctx->r21 = S32(SIGNED(ctx->r1) >> 3);
L_800640A0:
    // 0x800640A0: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x800640A4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800640A8: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800640AC: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800640B0: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800640B4: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800640B8: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800640BC: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800640C0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
L_800640C4:
    // 0x800640C4: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x800640C8: lh          $t7, 0x0($s7)
    ctx->r15 = MEM_H(ctx->r23, 0X0);
    // 0x800640CC: slti        $at, $fp, 0x7FF
    ctx->r1 = SIGNED(ctx->r30) < 0X7FF ? 1 : 0;
    // 0x800640D0: lw          $t8, 0x24($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X24);
    // 0x800640D4: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800640D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800640DC: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800640E0: lhu         $t7, 0x0($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X0);
    // 0x800640E4: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x800640E8: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    // 0x800640EC: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
    // 0x800640F0: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800640F4: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    // 0x800640F8: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x800640FC: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x80064100: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80064104: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x80064108: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8006410C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064110: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80064114: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80064118: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8006411C: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x80064120: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80064124: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80064128: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8006412C: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x80064130: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80064134: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x80064138: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8006413C: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x80064140: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80064144: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80064148: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8006414C: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x80064150: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80064154: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80064158: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8006415C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80064160: beq         $at, $zero, L_80064170
    if (ctx->r1 == 0) {
        // 0x80064164: or          $s4, $t7, $zero
        ctx->r20 = ctx->r15 | 0;
            goto L_80064170;
    }
    // 0x80064164: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x80064168: b           L_80064170
    // 0x8006416C: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
        goto L_80064170;
    // 0x8006416C: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
L_80064170:
    // 0x80064170: bgtz        $s5, L_80064180
    if (SIGNED(ctx->r21) > 0) {
        // 0x80064174: or          $t3, $s5, $zero
        ctx->r11 = ctx->r21 | 0;
            goto L_80064180;
    }
    // 0x80064174: or          $t3, $s5, $zero
    ctx->r11 = ctx->r21 | 0;
    // 0x80064178: b           L_80064180
    // 0x8006417C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80064180;
    // 0x8006417C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80064180:
    // 0x80064180: bgtz        $s5, L_80064190
    if (SIGNED(ctx->r21) > 0) {
        // 0x80064184: addiu       $t9, $s3, 0x7FF
        ctx->r25 = ADD32(ctx->r19, 0X7FF);
            goto L_80064190;
    }
    // 0x80064184: addiu       $t9, $s3, 0x7FF
    ctx->r25 = ADD32(ctx->r19, 0X7FF);
    // 0x80064188: b           L_80064190
    // 0x8006418C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_80064190;
    // 0x8006418C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80064190:
    // 0x80064190: div         $zero, $t9, $t3
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r11)));
    // 0x80064194: bne         $t3, $zero, L_800641A0
    if (ctx->r11 != 0) {
        // 0x80064198: nop
    
            goto L_800641A0;
    }
    // 0x80064198: nop

    // 0x8006419C: break       7
    do_break(2147893660);
L_800641A0:
    // 0x800641A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800641A4: bne         $t3, $at, L_800641B8
    if (ctx->r11 != ctx->r1) {
        // 0x800641A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800641B8;
    }
    // 0x800641A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800641AC: bne         $t9, $at, L_800641B8
    if (ctx->r25 != ctx->r1) {
        // 0x800641B0: nop
    
            goto L_800641B8;
    }
    // 0x800641B0: nop

    // 0x800641B4: break       6
    do_break(2147893684);
L_800641B8:
    // 0x800641B8: mflo        $t7
    ctx->r15 = lo;
    // 0x800641BC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800641C0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800641C4: andi        $t9, $s2, 0xFFF
    ctx->r25 = ctx->r18 & 0XFFF;
    // 0x800641C8: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x800641CC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800641D0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800641D4: sw          $t8, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r24;
    // 0x800641D8: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800641DC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800641E0: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800641E4: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x800641E8: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800641EC: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800641F0: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x800641F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800641F8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800641FC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80064200: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    // 0x80064204: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80064208: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8006420C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80064210: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80064214: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80064218: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8006421C: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x80064220: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80064224: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80064228: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x8006422C: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80064230: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x80064234: blezl       $t7, L_80064308
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80064238: lw          $t7, 0xA0($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA0);
            goto L_80064308;
    }
    goto skip_0;
    // 0x80064238: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    skip_0:
    // 0x8006423C: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
L_80064240:
    // 0x80064240: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80064244: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x80064248: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006424C: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    // 0x80064250: addiu       $t8, $v0, 0x2
    ctx->r24 = ADD32(ctx->r2, 0X2);
    // 0x80064254: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80064258: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8006425C: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x80064260: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80064264: addiu       $t9, $v0, 0x4
    ctx->r25 = ADD32(ctx->r2, 0X4);
    // 0x80064268: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x8006426C: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x80064270: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80064274: slti        $at, $a0, 0x1E
    ctx->r1 = SIGNED(ctx->r4) < 0X1E ? 1 : 0;
    // 0x80064278: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006427C: bne         $at, $zero, L_800642F0
    if (ctx->r1 != 0) {
        // 0x80064280: sw          $t4, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r12;
            goto L_800642F0;
    }
    // 0x80064280: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80064284: slt         $at, $a3, $s1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80064288: beq         $at, $zero, L_800642B0
    if (ctx->r1 == 0) {
        // 0x8006428C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800642B0;
    }
    // 0x8006428C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064290: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x80064294: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x80064298: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x8006429C: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800642A0: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x800642A4: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x800642A8: b           L_800642E8
    // 0x800642AC: sw          $ra, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r31;
        goto L_800642E8;
    // 0x800642AC: sw          $ra, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r31;
L_800642B0:
    // 0x800642B0: blez        $t0, L_800642E8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800642B4: lw          $v0, 0xB4($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XB4);
            goto L_800642E8;
    }
    // 0x800642B4: lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB4);
    // 0x800642B8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800642BC: sll         $t6, $t0, 4
    ctx->r14 = S32(ctx->r8 << 4);
    // 0x800642C0: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x800642C4: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x800642C8: sll         $t7, $t0, 10
    ctx->r15 = S32(ctx->r8 << 10);
    // 0x800642CC: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800642D0: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x800642D4: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x800642D8: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x800642DC: or          $t7, $t6, $s0
    ctx->r15 = ctx->r14 | ctx->r16;
    // 0x800642E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800642E4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_800642E8:
    // 0x800642E8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800642EC: addiu       $a1, $a1, 0x1E
    ctx->r5 = ADD32(ctx->r5, 0X1E);
L_800642F0:
    // 0x800642F0: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x800642F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800642F8: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800642FC: bnel        $at, $zero, L_80064240
    if (ctx->r1 != 0) {
        // 0x80064300: lw          $v1, 0xB4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XB4);
            goto L_80064240;
    }
    goto skip_1;
    // 0x80064300: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    skip_1:
    // 0x80064304: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
L_80064308:
    // 0x80064308: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8006430C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80064310: bne         $s6, $t7, L_800640C4
    if (ctx->r22 != ctx->r15) {
        // 0x80064314: addiu       $t5, $t5, 0x4
        ctx->r13 = ADD32(ctx->r13, 0X4);
            goto L_800640C4;
    }
    // 0x80064314: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
L_80064318:
    // 0x80064318: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8006431C: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x80064320: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80064324: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80064328: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8006432C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80064330: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80064334: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80064338: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006433C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80064340: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80064344: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80064348: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006434C: jr          $ra
    // 0x80064350: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80064350: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void Fault_WaitButtonCombo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800703C4: lui         $t7, 0xFFFA
    ctx->r15 = S32(0XFFFA << 16);
    // 0x800703C8: or          $t0, $sp, $zero
    ctx->r8 = ctx->r29 | 0;
    // 0x800703CC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800703D0: ori         $t7, $t7, 0x5A5A
    ctx->r15 = ctx->r15 | 0X5A5A;
L_800703D4:
    // 0x800703D4: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x800703D8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800703DC: bne         $t0, $sp, L_800703D4
    if (ctx->r8 != ctx->r29) {
        // 0x800703E0: sw          $t7, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->r15;
            goto L_800703D4;
    }
    // 0x800703E0: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800703E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800703E8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800703EC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800703F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800703F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800703F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800703FC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070400: jal         0x8008AD5C
    // 0x80070404: addiu       $a0, $a0, 0x1720
    ctx->r4 = ADD32(ctx->r4, 0X1720);
    osSyncPrintf(rdram, ctx);
        goto after_0;
    // 0x80070404: addiu       $a0, $a0, 0x1720
    ctx->r4 = ADD32(ctx->r4, 0X1720);
    after_0:
    // 0x80070408: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x8007040C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80070410: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80070414: addiu       $s3, $s3, -0x79D0
    ctx->r19 = ADD32(ctx->r19, -0X79D0);
    // 0x80070418: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_8007041C:
    // 0x8007041C: jal         0x8006F8F0
    // 0x80070420: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    Fault_Sleep(rdram, ctx);
        goto after_1;
    // 0x80070420: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x80070424: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80070428: addiu       $a0, $a0, -0x20C0
    ctx->r4 = ADD32(ctx->r4, -0X20C0);
    // 0x8007042C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80070430: jal         0x80074C88
    // 0x80070434: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80074C88(rdram, ctx);
        goto after_2;
    // 0x80070434: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80070438: jal         0x8007FB90
    // 0x8007043C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    pad_trigger(rdram, ctx);
        goto after_3;
    // 0x8007043C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80070440: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80070444: jal         0x8007FB88
    // 0x80070448: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    pad_button(rdram, ctx);
        goto after_4;
    // 0x80070448: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x8007044C: bne         $v0, $zero, L_80070478
    if (ctx->r2 != 0) {
        // 0x80070450: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80070478;
    }
    // 0x80070450: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80070454: bne         $s2, $s4, L_80070478
    if (ctx->r18 != ctx->r20) {
        // 0x80070458: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80070478;
    }
    // 0x80070458: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8007045C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80070460: addiu       $a0, $a0, 0x1798
    ctx->r4 = ADD32(ctx->r4, 0X1798);
    // 0x80070464: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80070468: jal         0x8008AD5C
    // 0x8007046C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSyncPrintf(rdram, ctx);
        goto after_5;
    // 0x8007046C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80070470: b           L_80070768
    // 0x80070474: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
        goto L_80070768;
    // 0x80070474: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_80070478:
    // 0x80070478: beql        $s0, $zero, L_80070768
    if (ctx->r16 == 0) {
        // 0x8007047C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80070768;
    }
    goto skip_0;
    // 0x8007047C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_0:
    // 0x80070480: bne         $s2, $s4, L_800704A4
    if (ctx->r18 != ctx->r20) {
        // 0x80070484: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800704A4;
    }
    // 0x80070484: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070488: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007048C: addiu       $a0, $a0, 0x17A4
    ctx->r4 = ADD32(ctx->r4, 0X17A4);
    // 0x80070490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80070494: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80070498: jal         0x8008AD5C
    // 0x8007049C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    osSyncPrintf(rdram, ctx);
        goto after_6;
    // 0x8007049C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_6:
    // 0x800704A0: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
L_800704A4:
    // 0x800704A4: slti        $at, $s1, 0x5C
    ctx->r1 = SIGNED(ctx->r17) < 0X5C ? 1 : 0;
    // 0x800704A8: bne         $at, $zero, L_800704C0
    if (ctx->r1 != 0) {
        // 0x800704AC: addiu       $at, $zero, 0x5C
        ctx->r1 = ADD32(0, 0X5C);
            goto L_800704C0;
    }
    // 0x800704AC: addiu       $at, $zero, 0x5C
    ctx->r1 = ADD32(0, 0X5C);
    // 0x800704B0: beql        $s1, $at, L_80070668
    if (ctx->r17 == ctx->r1) {
        // 0x800704B4: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_80070668;
    }
    goto skip_1;
    // 0x800704B4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    skip_1:
    // 0x800704B8: b           L_80070768
    // 0x800704BC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
        goto L_80070768;
    // 0x800704BC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_800704C0:
    // 0x800704C0: slti        $at, $s1, 0xB
    ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
    // 0x800704C4: bne         $at, $zero, L_800704DC
    if (ctx->r1 != 0) {
        // 0x800704C8: addiu       $at, $zero, 0x5B
        ctx->r1 = ADD32(0, 0X5B);
            goto L_800704DC;
    }
    // 0x800704C8: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x800704CC: beql        $s1, $at, L_8007064C
    if (ctx->r17 == ctx->r1) {
        // 0x800704D0: addiu       $at, $zero, 0x4000
        ctx->r1 = ADD32(0, 0X4000);
            goto L_8007064C;
    }
    goto skip_2;
    // 0x800704D0: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    skip_2:
    // 0x800704D4: b           L_80070768
    // 0x800704D8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
        goto L_80070768;
    // 0x800704D8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_800704DC:
    // 0x800704DC: sltiu       $at, $s1, 0xB
    ctx->r1 = ctx->r17 < 0XB ? 1 : 0;
    // 0x800704E0: beq         $at, $zero, L_80070764
    if (ctx->r1 == 0) {
        // 0x800704E4: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_80070764;
    }
    // 0x800704E4: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800704E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800704EC: addu        $at, $at, $t6
    gpr jr_addend_800704F4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800704F0: lw          $t6, 0x1A94($at)
    ctx->r14 = ADD32(ctx->r1, 0X1A94);
    // 0x800704F4: jr          $t6
    // 0x800704F8: nop

    switch (jr_addend_800704F4 >> 2) {
        case 0: goto L_800704FC; break;
        case 1: goto L_80070528; break;
        case 2: goto L_80070544; break;
        case 3: goto L_80070560; break;
        case 4: goto L_8007057C; break;
        case 5: goto L_80070598; break;
        case 6: goto L_800705B4; break;
        case 7: goto L_800705D0; break;
        case 8: goto L_800705E8; break;
        case 9: goto L_80070604; break;
        case 10: goto L_80070680; break;
        default: switch_error(__func__, 0x800704F4, 0x800B1A94);
    }
    // 0x800704F8: nop

L_800704FC:
    // 0x800704FC: addiu       $at, $zero, 0x2030
    ctx->r1 = ADD32(0, 0X2030);
    // 0x80070500: bne         $a3, $at, L_80070764
    if (ctx->r7 != ctx->r1) {
        // 0x80070504: addiu       $at, $zero, 0x2000
        ctx->r1 = ADD32(0, 0X2000);
            goto L_80070764;
    }
    // 0x80070504: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x80070508: bnel        $s0, $at, L_80070768
    if (ctx->r16 != ctx->r1) {
        // 0x8007050C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80070768;
    }
    goto skip_3;
    // 0x8007050C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_3:
    // 0x80070510: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x80070514: jal         0x8008B920
    // 0x80070518: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    osGetTime_recomp(rdram, ctx);
        goto after_7;
    // 0x80070518: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    after_7:
    // 0x8007051C: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80070520: b           L_80070764
    // 0x80070524: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
        goto L_80070764;
    // 0x80070524: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
L_80070528:
    // 0x80070528: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x8007052C: bne         $s0, $at, L_8007053C
    if (ctx->r16 != ctx->r1) {
        // 0x80070530: nop
    
            goto L_8007053C;
    }
    // 0x80070530: nop

    // 0x80070534: b           L_80070764
    // 0x80070538: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_80070764;
    // 0x80070538: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8007053C:
    // 0x8007053C: b           L_80070764
    // 0x80070540: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80070764;
    // 0x80070540: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80070544:
    // 0x80070544: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80070548: bne         $s0, $at, L_80070558
    if (ctx->r16 != ctx->r1) {
        // 0x8007054C: addiu       $s1, $zero, 0x3
        ctx->r17 = ADD32(0, 0X3);
            goto L_80070558;
    }
    // 0x8007054C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80070550: b           L_80070764
    // 0x80070554: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
        goto L_80070764;
    // 0x80070554: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
L_80070558:
    // 0x80070558: b           L_80070764
    // 0x8007055C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80070764;
    // 0x8007055C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80070560:
    // 0x80070560: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80070564: bne         $s0, $at, L_80070574
    if (ctx->r16 != ctx->r1) {
        // 0x80070568: nop
    
            goto L_80070574;
    }
    // 0x80070568: nop

    // 0x8007056C: b           L_80070764
    // 0x80070570: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
        goto L_80070764;
    // 0x80070570: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80070574:
    // 0x80070574: b           L_80070764
    // 0x80070578: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80070764;
    // 0x80070578: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007057C:
    // 0x8007057C: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80070580: bne         $s0, $at, L_80070590
    if (ctx->r16 != ctx->r1) {
        // 0x80070584: addiu       $s1, $zero, 0x5
        ctx->r17 = ADD32(0, 0X5);
            goto L_80070590;
    }
    // 0x80070584: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x80070588: b           L_80070764
    // 0x8007058C: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
        goto L_80070764;
    // 0x8007058C: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
L_80070590:
    // 0x80070590: b           L_80070764
    // 0x80070594: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80070764;
    // 0x80070594: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80070598:
    // 0x80070598: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8007059C: bne         $s0, $at, L_800705AC
    if (ctx->r16 != ctx->r1) {
        // 0x800705A0: nop
    
            goto L_800705AC;
    }
    // 0x800705A0: nop

    // 0x800705A4: b           L_80070764
    // 0x800705A8: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
        goto L_80070764;
    // 0x800705A8: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_800705AC:
    // 0x800705AC: b           L_80070764
    // 0x800705B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80070764;
    // 0x800705B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800705B4:
    // 0x800705B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800705B8: bne         $s0, $at, L_800705C8
    if (ctx->r16 != ctx->r1) {
        // 0x800705BC: addiu       $s1, $zero, 0x7
        ctx->r17 = ADD32(0, 0X7);
            goto L_800705C8;
    }
    // 0x800705BC: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // 0x800705C0: b           L_80070764
    // 0x800705C4: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
        goto L_80070764;
    // 0x800705C4: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
L_800705C8:
    // 0x800705C8: b           L_80070764
    // 0x800705CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80070764;
    // 0x800705CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800705D0:
    // 0x800705D0: bne         $s0, $s4, L_800705E0
    if (ctx->r16 != ctx->r20) {
        // 0x800705D4: nop
    
            goto L_800705E0;
    }
    // 0x800705D4: nop

    // 0x800705D8: b           L_80070764
    // 0x800705DC: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
        goto L_80070764;
    // 0x800705DC: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_800705E0:
    // 0x800705E0: b           L_80070764
    // 0x800705E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80070764;
    // 0x800705E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800705E8:
    // 0x800705E8: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x800705EC: bne         $s0, $at, L_800705FC
    if (ctx->r16 != ctx->r1) {
        // 0x800705F0: addiu       $s1, $zero, 0x9
        ctx->r17 = ADD32(0, 0X9);
            goto L_800705FC;
    }
    // 0x800705F0: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
    // 0x800705F4: b           L_80070764
    // 0x800705F8: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
        goto L_80070764;
    // 0x800705F8: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
L_800705FC:
    // 0x800705FC: b           L_80070764
    // 0x80070600: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80070764;
    // 0x80070600: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80070604:
    // 0x80070604: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x80070608: bnel        $s0, $at, L_8007061C
    if (ctx->r16 != ctx->r1) {
        // 0x8007060C: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_8007061C;
    }
    goto skip_4;
    // 0x8007060C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    skip_4:
    // 0x80070610: b           L_80070764
    // 0x80070614: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
        goto L_80070764;
    // 0x80070614: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80070618: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
L_8007061C:
    // 0x8007061C: bnel        $s0, $at, L_80070630
    if (ctx->r16 != ctx->r1) {
        // 0x80070620: addiu       $at, $zero, 0x4000
        ctx->r1 = ADD32(0, 0X4000);
            goto L_80070630;
    }
    goto skip_5;
    // 0x80070620: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    skip_5:
    // 0x80070624: b           L_80070764
    // 0x80070628: addiu       $s1, $zero, 0x5B
    ctx->r17 = ADD32(0, 0X5B);
        goto L_80070764;
    // 0x80070628: addiu       $s1, $zero, 0x5B
    ctx->r17 = ADD32(0, 0X5B);
    // 0x8007062C: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
L_80070630:
    // 0x80070630: bne         $s0, $at, L_80070640
    if (ctx->r16 != ctx->r1) {
        // 0x80070634: nop
    
            goto L_80070640;
    }
    // 0x80070634: nop

    // 0x80070638: b           L_80070764
    // 0x8007063C: addiu       $s1, $zero, 0x5C
    ctx->r17 = ADD32(0, 0X5C);
        goto L_80070764;
    // 0x8007063C: addiu       $s1, $zero, 0x5C
    ctx->r17 = ADD32(0, 0X5C);
L_80070640:
    // 0x80070640: b           L_80070764
    // 0x80070644: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80070764;
    // 0x80070644: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80070648: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
L_8007064C:
    // 0x8007064C: bne         $s0, $at, L_8007065C
    if (ctx->r16 != ctx->r1) {
        // 0x80070650: nop
    
            goto L_8007065C;
    }
    // 0x80070650: nop

    // 0x80070654: b           L_80070764
    // 0x80070658: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
        goto L_80070764;
    // 0x80070658: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
L_8007065C:
    // 0x8007065C: b           L_80070764
    // 0x80070660: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80070764;
    // 0x80070660: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80070664: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
L_80070668:
    // 0x80070668: bne         $s0, $at, L_80070678
    if (ctx->r16 != ctx->r1) {
        // 0x8007066C: nop
    
            goto L_80070678;
    }
    // 0x8007066C: nop

    // 0x80070670: b           L_80070764
    // 0x80070674: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
        goto L_80070764;
    // 0x80070674: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
L_80070678:
    // 0x80070678: b           L_80070764
    // 0x8007067C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80070764;
    // 0x8007067C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80070680:
    // 0x80070680: ori         $at, $zero, 0xD000
    ctx->r1 = 0 | 0XD000;
    // 0x80070684: bne         $a3, $at, L_80070764
    if (ctx->r7 != ctx->r1) {
        // 0x80070688: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80070764;
    }
    // 0x80070688: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007068C: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80070690: bne         $s0, $at, L_80070764
    if (ctx->r16 != ctx->r1) {
        // 0x80070694: nop
    
            goto L_80070764;
    }
    // 0x80070694: nop

    // 0x80070698: jal         0x8008B920
    // 0x8007069C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_8;
    // 0x8007069C: nop

    after_8:
    // 0x800706A0: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800706A4: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800706A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800706AC: subu        $a0, $v0, $t8
    ctx->r4 = SUB32(ctx->r2, ctx->r24);
    // 0x800706B0: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x800706B4: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x800706B8: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800706BC: jal         0x80082D88
    // 0x800706C0: subu        $a1, $v1, $t9
    ctx->r5 = SUB32(ctx->r3, ctx->r25);
    __ll_mul_recomp(rdram, ctx);
        goto after_9;
    // 0x800706C0: subu        $a1, $v1, $t9
    ctx->r5 = SUB32(ctx->r3, ctx->r25);
    after_9:
    // 0x800706C4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800706C8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800706CC: lw          $a1, -0x53BC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X53BC);
    // 0x800706D0: lw          $a0, -0x53C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53C0);
    // 0x800706D4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800706D8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800706DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800706E0: jal         0x80082C88
    // 0x800706E4: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_10;
    // 0x800706E4: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_10:
    // 0x800706E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800706EC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800706F0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800706F4: jal         0x80082C88
    // 0x800706F8: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_11;
    // 0x800706F8: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_11:
    // 0x800706FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80070700: jal         0x80090C88
    // 0x80070704: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    __ull_to_f_recomp(rdram, ctx);
        goto after_12;
    // 0x80070704: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_12:
    // 0x80070708: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8007070C: lwc1        $f4, 0x1AC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1AC0);
    // 0x80070710: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070714: addiu       $a0, $a0, 0x17B0
    ctx->r4 = ADD32(ctx->r4, 0X17B0);
    // 0x80070718: div.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007071C: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80070720: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x80070724: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80070728: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x8007072C: jal         0x8008AD5C
    // 0x80070730: nop

    osSyncPrintf(rdram, ctx);
        goto after_13;
    // 0x80070730: nop

    after_13:
    // 0x80070734: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80070738: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007073C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80070740: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80070744: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80070748: nop

    // 0x8007074C: bc1f        L_8007075C
    if (!c1cs) {
        // 0x80070750: nop
    
            goto L_8007075C;
    }
    // 0x80070750: nop

    // 0x80070754: b           L_80070764
    // 0x80070758: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
        goto L_80070764;
    // 0x80070758: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
L_8007075C:
    // 0x8007075C: b           L_80070768
    // 0x80070760: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
        goto L_80070768;
    // 0x80070760: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_80070764:
    // 0x80070764: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_80070768:
    // 0x80070768: bne         $s1, $at, L_8007041C
    if (ctx->r17 != ctx->r1) {
        // 0x8007076C: nop
    
            goto L_8007041C;
    }
    // 0x8007076C: nop

    // 0x80070770: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80070774: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80070778: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007077C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80070780: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80070784: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80070788: jr          $ra
    // 0x8007078C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8007078C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80698D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80698D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80698D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80698D50: jal         0x8005FCA8
    // 0x80698D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x80698D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80698D58: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80698D5C: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(556, 0X260) << 16);
    // 0x80698D60: addiu       $t6, $t6, -0x7080
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(556, 0X260));
    // 0x80698D64: lw          $t8, 0x174($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X174);
    // 0x80698D68: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80698D6C: sw          $t6, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r14;
    // 0x80698D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80698D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80698D78: jr          $ra
    // 0x80698D7C: nop

    return;
    // 0x80698D7C: nop

;}
RECOMP_FUNC void func_8073DA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073DA24: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8073DA28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073DA2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8073DA30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8073DA34: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8073DA38: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8073DA3C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8073DA40: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073DA44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8073DA48: jal         0x8004700C
    // 0x8073DA4C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8073DA4C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x8073DA50: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8073DA54: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8073DA58: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8073DA5C: lbu         $v1, 0x18($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X18);
    // 0x8073DA60: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8073DA64: beql        $v1, $at, L_8073DBB0
    if (ctx->r3 == ctx->r1) {
        // 0x8073DA68: lwc1        $f8, 0x3C($a3)
        ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
            goto L_8073DBB0;
    }
    goto skip_0;
    // 0x8073DA68: lwc1        $f8, 0x3C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
    skip_0:
    // 0x8073DA6C: lhu         $v0, 0xC($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0XC);
    // 0x8073DA70: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8073DA74: bne         $v0, $at, L_8073DB30
    if (ctx->r2 != ctx->r1) {
        // 0x8073DA78: slti        $at, $v1, 0x5
        ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
            goto L_8073DB30;
    }
    // 0x8073DA78: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8073DA7C: beql        $at, $zero, L_8073DC80
    if (ctx->r1 == 0) {
        // 0x8073DA80: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073DC80;
    }
    goto skip_1;
    // 0x8073DA80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8073DA84: lbu         $t6, 0x30($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X30);
    // 0x8073DA88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8073DA8C: bnel        $v0, $t6, L_8073DC80
    if (ctx->r2 != ctx->r14) {
        // 0x8073DA90: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073DC80;
    }
    goto skip_2;
    // 0x8073DA90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8073DA94: lw          $t7, 0x34($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X34);
    // 0x8073DA98: bnel        $t7, $zero, L_8073DC80
    if (ctx->r15 != 0) {
        // 0x8073DA9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073DC80;
    }
    goto skip_3;
    // 0x8073DA9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8073DAA0: jal         0x8002FD38
    // 0x8073DAA4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8002FD38(rdram, ctx);
        goto after_1;
    // 0x8073DAA4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8073DAA8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1464) << 16);
    // 0x8073DAAC: lwc1        $f0, -0x19CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1464));
    // 0x8073DAB0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1468) << 16);
    // 0x8073DAB4: lwc1        $f2, -0x19C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1468));
    // 0x8073DAB8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8073DABC: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x8073DAC0: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x8073DAC4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8073DAC8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8073DACC: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x8073DAD0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8073DAD4: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x8073DAD8: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
    // 0x8073DADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8073DAE0: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8073DAE4: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x8073DAE8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8073DAEC: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x8073DAF0: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
    // 0x8073DAF4: sw          $t1, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r9;
    // 0x8073DAF8: sw          $t2, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r10;
    // 0x8073DAFC: sw          $t3, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r11;
    // 0x8073DB00: sw          $v0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r2;
    // 0x8073DB04: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8073DB08: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x8073DB0C: swc1        $f2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f2.u32l;
    // 0x8073DB10: swc1        $f2, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f2.u32l;
    // 0x8073DB14: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8073DB18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073DB1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073DB20: jal         0x8073E498
    // 0x8073DB24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8073E498(rdram, ctx);
        goto after_2;
    // 0x8073DB24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x8073DB28: b           L_8073DC80
    // 0x8073DB2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8073DC80;
    // 0x8073DB2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073DB30:
    // 0x8073DB30: addiu       $at, $zero, 0x407B
    ctx->r1 = ADD32(0, 0X407B);
    // 0x8073DB34: bnel        $v0, $at, L_8073DC80
    if (ctx->r2 != ctx->r1) {
        // 0x8073DB38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073DC80;
    }
    goto skip_4;
    // 0x8073DB38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8073DB3C: jal         0x8005FD1C
    // 0x8073DB40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_3;
    // 0x8073DB40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8073DB44: lw          $t4, 0x174($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X174);
    // 0x8073DB48: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8073DB4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8073DB50: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8073DB54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8073DB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073DB5C: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    // 0x8073DB60: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8073DB64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073DB68: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8073DB6C: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x8073DB70: jal         0x8073E498
    // 0x8073DB74: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    func_8073E498(rdram, ctx);
        goto after_4;
    // 0x8073DB74: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x8073DB78: lw          $t6, 0x3C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X3C);
    // 0x8073DB7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073DB80: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8073DB84: beql        $t6, $zero, L_8073DC80
    if (ctx->r14 == 0) {
        // 0x8073DB88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073DC80;
    }
    goto skip_5;
    // 0x8073DB88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8073DB8C: beql        $a0, $zero, L_8073DC80
    if (ctx->r4 == 0) {
        // 0x8073DB90: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073DC80;
    }
    goto skip_6;
    // 0x8073DB90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8073DB94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8073DB98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8073DB9C: jal         0x8002FCFC
    // 0x8073DBA0: sw          $zero, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = 0;
    func_8002FCFC(rdram, ctx);
        goto after_5;
    // 0x8073DBA0: sw          $zero, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = 0;
    after_5:
    // 0x8073DBA4: b           L_8073DC80
    // 0x8073DBA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8073DC80;
    // 0x8073DBA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073DBAC: lwc1        $f8, 0x3C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
L_8073DBB0:
    // 0x8073DBB0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X146C) << 16);
    // 0x8073DBB4: lwc1        $f16, -0x19C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X146C));
    // 0x8073DBB8: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x8073DBBC: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8073DBC0: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8073DBC4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8073DBC8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x8073DBCC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8073DBD0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8073DBD4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8073DBD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073DBDC: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8073DBE0: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8073DBE4: jalr        $t9
    // 0x8073DBE8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8073DBE8: nop

    after_6:
    // 0x8073DBEC: jal         0x800447C8
    // 0x8073DBF0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800447C8(rdram, ctx);
        goto after_7;
    // 0x8073DBF0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_7:
    // 0x8073DBF4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8073DBF8: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x8073DBFC: jal         0x80067BBC
    // 0x8073DC00: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_8;
    // 0x8073DC00: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_8:
    // 0x8073DC04: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8073DC08: jal         0x80067818
    // 0x8073DC0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x8073DC0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x8073DC10: jal         0x8005FD1C
    // 0x8073DC14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_10;
    // 0x8073DC14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8073DC18: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x8073DC1C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8073DC20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073DC24: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8073DC28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8073DC2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073DC30: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x8073DC34: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8073DC38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073DC3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8073DC40: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8073DC44: jal         0x8073E498
    // 0x8073DC48: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    func_8073E498(rdram, ctx);
        goto after_11;
    // 0x8073DC48: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    after_11:
    // 0x8073DC4C: lw          $t2, 0x3C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X3C);
    // 0x8073DC50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073DC54: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8073DC58: beql        $t2, $zero, L_8073DC80
    if (ctx->r10 == 0) {
        // 0x8073DC5C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073DC80;
    }
    goto skip_7;
    // 0x8073DC5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8073DC60: beql        $t3, $zero, L_8073DC80
    if (ctx->r11 == 0) {
        // 0x8073DC64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073DC80;
    }
    goto skip_8;
    // 0x8073DC64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8073DC68: sw          $zero, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = 0;
    // 0x8073DC6C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8073DC70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8073DC74: jal         0x8002FCFC
    // 0x8073DC78: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8002FCFC(rdram, ctx);
        goto after_12;
    // 0x8073DC78: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x8073DC7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073DC80:
    // 0x8073DC80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8073DC84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8073DC88: jr          $ra
    // 0x8073DC8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8073DC8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80071DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071DEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071DF4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071DF8: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    // 0x80071DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071E00: jal         0x800824B0
    // 0x80071E04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80071E04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80071E08: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071E0C: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    // 0x80071E10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071E14: jal         0x80082210
    // 0x80071E18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80071E18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80071E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071E24: jr          $ra
    // 0x80071E28: nop

    return;
    // 0x80071E28: nop

;}
RECOMP_FUNC void func_80048A84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048A84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048A88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048A8C: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x80048A90: addiu       $a1, $zero, 0xC18
    ctx->r5 = ADD32(0, 0XC18);
    // 0x80048A94: bnel        $t6, $zero, L_80048AB4
    if (ctx->r14 != 0) {
        // 0x80048A98: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80048AB4;
    }
    goto skip_0;
    // 0x80048A98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x80048A9C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80048AA0: jal         0x80071380
    // 0x80048AA4: addiu       $a0, $a0, 0x840
    ctx->r4 = ADD32(ctx->r4, 0X840);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80048AA4: addiu       $a0, $a0, 0x840
    ctx->r4 = ADD32(ctx->r4, 0X840);
    after_0:
    // 0x80048AA8: b           L_80048AD4
    // 0x80048AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048AD4;
    // 0x80048AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048AB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80048AB4:
    // 0x80048AB4: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x80048AB8: jalr        $t9
    // 0x80048ABC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80048ABC: nop

    after_1:
    // 0x80048AC0: bne         $v0, $zero, L_80048AD0
    if (ctx->r2 != 0) {
        // 0x80048AC4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80048AD0;
    }
    // 0x80048AC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80048AC8: jal         0x80048A30
    // 0x80048ACC: nop

    func_80048A30(rdram, ctx);
        goto after_2;
    // 0x80048ACC: nop

    after_2:
L_80048AD0:
    // 0x80048AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048AD4:
    // 0x80048AD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048AD8: jr          $ra
    // 0x80048ADC: nop

    return;
    // 0x80048ADC: nop

;}
RECOMP_FUNC void func_8049EF3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049EF3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8049EF40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8049EF44: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8049EF48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8049EF4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8049EF50: lw          $s2, 0x16C($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X16C);
    // 0x8049EF54: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8049EF58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8049EF5C: jal         0x8049EF18
    // 0x8049EF60: addiu       $s2, $s2, 0xD
    ctx->r18 = ADD32(ctx->r18, 0XD);
    func_8049EF18(rdram, ctx);
        goto after_0;
    // 0x8049EF60: addiu       $s2, $s2, 0xD
    ctx->r18 = ADD32(ctx->r18, 0XD);
    after_0:
    // 0x8049EF64: lhu         $t6, 0x8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X8);
    // 0x8049EF68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8049EF6C: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X1168) << 16);
    // 0x8049EF70: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x8049EF74: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x8049EF78: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x8049EF7C: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x8049EF80: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8049EF84: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8049EF88: lw          $t9, -0x318($at)
    ctx->r25 = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X1168));
    // 0x8049EF8C: jalr        $t9
    // 0x8049EF90: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8049EF90: nop

    after_1:
    // 0x8049EF94: jal         0x8049EC3C
    // 0x8049EF98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8049EC3C(rdram, ctx);
        goto after_2;
    // 0x8049EF98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8049EF9C: lhu         $t1, 0x8($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X8);
    // 0x8049EFA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8049EFA4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8049EFA8: beq         $t2, $zero, L_8049F008
    if (ctx->r10 == 0) {
        // 0x8049EFAC: nop
    
            goto L_8049F008;
    }
    // 0x8049EFAC: nop

    // 0x8049EFB0: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8049EFB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8049EFB8: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x8049EFBC: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8049EFC0: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8049EFC4: lhu         $t3, 0x8($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X8);
    // 0x8049EFC8: ori         $t6, $t3, 0x4
    ctx->r14 = ctx->r11 | 0X4;
    // 0x8049EFCC: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x8049EFD0: beq         $t7, $zero, L_8049EFF0
    if (ctx->r15 == 0) {
        // 0x8049EFD4: sh          $t6, 0x8($s0)
        MEM_H(0X8, ctx->r16) = ctx->r14;
            goto L_8049EFF0;
    }
    // 0x8049EFD4: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x8049EFD8: lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X3);
    // 0x8049EFDC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8049EFE0: bne         $at, $zero, L_8049F048
    if (ctx->r1 != 0) {
        // 0x8049EFE4: addiu       $t8, $v0, -0x2
        ctx->r24 = ADD32(ctx->r2, -0X2);
            goto L_8049F048;
    }
    // 0x8049EFE4: addiu       $t8, $v0, -0x2
    ctx->r24 = ADD32(ctx->r2, -0X2);
    // 0x8049EFE8: b           L_8049F048
    // 0x8049EFEC: sb          $t8, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r24;
        goto L_8049F048;
    // 0x8049EFEC: sb          $t8, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r24;
L_8049EFF0:
    // 0x8049EFF0: lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X3);
    // 0x8049EFF4: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x8049EFF8: bne         $at, $zero, L_8049F048
    if (ctx->r1 != 0) {
        // 0x8049EFFC: addiu       $t9, $v0, -0x2
        ctx->r25 = ADD32(ctx->r2, -0X2);
            goto L_8049F048;
    }
    // 0x8049EFFC: addiu       $t9, $v0, -0x2
    ctx->r25 = ADD32(ctx->r2, -0X2);
    // 0x8049F000: b           L_8049F048
    // 0x8049F004: sb          $t9, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r25;
        goto L_8049F048;
    // 0x8049F004: sb          $t9, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r25;
L_8049F008:
    // 0x8049F008: jal         0x8049EEA4
    // 0x8049F00C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8049EEA4(rdram, ctx);
        goto after_3;
    // 0x8049F00C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8049F010: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8049F014: jal         0x8049EEA4
    // 0x8049F018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8049EEA4(rdram, ctx);
        goto after_4;
    // 0x8049F018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8049F01C: lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X3);
    // 0x8049F020: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8049F024: slti        $at, $v0, 0xFA
    ctx->r1 = SIGNED(ctx->r2) < 0XFA ? 1 : 0;
    // 0x8049F028: beq         $at, $zero, L_8049F038
    if (ctx->r1 == 0) {
        // 0x8049F02C: addiu       $t0, $v0, 0x5
        ctx->r8 = ADD32(ctx->r2, 0X5);
            goto L_8049F038;
    }
    // 0x8049F02C: addiu       $t0, $v0, 0x5
    ctx->r8 = ADD32(ctx->r2, 0X5);
    // 0x8049F030: b           L_8049F048
    // 0x8049F034: sb          $t0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r8;
        goto L_8049F048;
    // 0x8049F034: sb          $t0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r8;
L_8049F038:
    // 0x8049F038: sb          $t1, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r9;
    // 0x8049F03C: lhu         $t2, 0x8($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X8);
    // 0x8049F040: andi        $t3, $t2, 0xFFFB
    ctx->r11 = ctx->r10 & 0XFFFB;
    // 0x8049F044: sh          $t3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r11;
L_8049F048:
    // 0x8049F048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8049F04C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8049F050: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8049F054: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8049F058: jr          $ra
    // 0x8049F05C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8049F05C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80469C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469C44: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80469C48: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80469C4C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80469C50: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80469C54: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80469C58: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80469C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80469C60: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80469C64: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x80469C68: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80469C6C: bc1fl       L_80469C7C
    if (!c1cs) {
        // 0x80469C70: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_80469C7C;
    }
    goto skip_0;
    // 0x80469C70: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    skip_0:
    // 0x80469C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80469C78: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
L_80469C7C:
    // 0x80469C7C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80469C80: lwc1        $f0, 0x34($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X34);
    // 0x80469C84: lwc1        $f8, 0x34($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80469C88: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80469C8C: nop

    // 0x80469C90: bc1fl       L_80469CA4
    if (!c1cs) {
        // 0x80469C94: lwc1        $f10, 0x38($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
            goto L_80469CA4;
    }
    goto skip_1;
    // 0x80469C94: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    skip_1:
    // 0x80469C98: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80469C9C: lwc1        $f0, 0x34($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X34);
    // 0x80469CA0: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
L_80469CA4:
    // 0x80469CA4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80469CA8: nop

    // 0x80469CAC: bc1fl       L_80469CC8
    if (!c1cs) {
        // 0x80469CB0: lwc1        $f16, 0x3C($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_80469CC8;
    }
    goto skip_2;
    // 0x80469CB0: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    skip_2:
    // 0x80469CB4: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x80469CB8: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80469CBC: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80469CC0: lwc1        $f0, 0x34($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X34);
    // 0x80469CC4: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
L_80469CC8:
    // 0x80469CC8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80469CCC: nop

    // 0x80469CD0: bc1fl       L_80469CEC
    if (!c1cs) {
        // 0x80469CD4: lwc1        $f18, 0x40($a0)
        ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
            goto L_80469CEC;
    }
    goto skip_3;
    // 0x80469CD4: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    skip_3:
    // 0x80469CD8: addiu       $a1, $v1, 0x2
    ctx->r5 = ADD32(ctx->r3, 0X2);
    // 0x80469CDC: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80469CE0: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80469CE4: lwc1        $f0, 0x34($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X34);
    // 0x80469CE8: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
L_80469CEC:
    // 0x80469CEC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80469CF0: nop

    // 0x80469CF4: bc1f        L_80469D00
    if (!c1cs) {
        // 0x80469CF8: nop
    
            goto L_80469D00;
    }
    // 0x80469CF8: nop

    // 0x80469CFC: addiu       $a1, $v1, 0x3
    ctx->r5 = ADD32(ctx->r3, 0X3);
L_80469D00:
    // 0x80469D00: jr          $ra
    // 0x80469D04: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80469D04: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_804D2C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D2C64: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804D2C68: lw          $t6, -0x7BC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7BC4);
    // 0x804D2C6C: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(249, 0X4C0) << 16);
    // 0x804D2C70: addiu       $t8, $t8, 0x2FD0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(249, 0X4C0));
    // 0x804D2C74: lw          $v0, 0x10C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X10C);
    // 0x804D2C78: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x804D2C7C: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x804D2C80: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x804D2C84: beq         $v0, $zero, L_804D2CAC
    if (ctx->r2 == 0) {
        // 0x804D2C88: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_804D2CAC;
    }
    // 0x804D2C88: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x804D2C8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804D2C90: beq         $v0, $at, L_804D2CEC
    if (ctx->r2 == ctx->r1) {
        // 0x804D2C94: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_804D2CEC;
    }
    // 0x804D2C94: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x804D2C98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804D2C9C: beq         $v0, $at, L_804D2D3C
    if (ctx->r2 == ctx->r1) {
        // 0x804D2CA0: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_804D2D3C;
    }
    // 0x804D2CA0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x804D2CA4: b           L_804D2D3C
    // 0x804D2CA8: nop

        goto L_804D2D3C;
    // 0x804D2CA8: nop

L_804D2CAC:
    // 0x804D2CAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804D2CB0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_804D2CB4:
    // 0x804D2CB4: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x804D2CB8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804D2CBC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804D2CC0: sb          $t9, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r25;
    // 0x804D2CC4: lbu         $t0, 0x1($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X1);
    // 0x804D2CC8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x804D2CCC: sb          $t0, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r8;
    // 0x804D2CD0: lbu         $t1, -0x2($a2)
    ctx->r9 = MEM_BU(ctx->r6, -0X2);
    // 0x804D2CD4: sb          $t1, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r9;
    // 0x804D2CD8: lbu         $t2, -0x1($a2)
    ctx->r10 = MEM_BU(ctx->r6, -0X1);
    // 0x804D2CDC: bne         $v0, $a0, L_804D2CB4
    if (ctx->r2 != ctx->r4) {
        // 0x804D2CE0: sb          $t2, 0xC($v1)
        MEM_B(0XC, ctx->r3) = ctx->r10;
            goto L_804D2CB4;
    }
    // 0x804D2CE0: sb          $t2, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r10;
    // 0x804D2CE4: jr          $ra
    // 0x804D2CE8: nop

    return;
    // 0x804D2CE8: nop

L_804D2CEC:
    // 0x804D2CEC: lui         $t4, 0x804D
    ctx->r12 = S32(RELOC_HI16(249, 0X4E8) << 16);
    // 0x804D2CF0: addiu       $t4, $t4, 0x2FF8
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(249, 0X4E8));
    // 0x804D2CF4: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x804D2CF8: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x804D2CFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804D2D00: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_804D2D04:
    // 0x804D2D04: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x804D2D08: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804D2D0C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804D2D10: sb          $t5, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r13;
    // 0x804D2D14: lbu         $t6, 0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1);
    // 0x804D2D18: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x804D2D1C: sb          $t6, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r14;
    // 0x804D2D20: lbu         $t7, -0x2($a2)
    ctx->r15 = MEM_BU(ctx->r6, -0X2);
    // 0x804D2D24: sb          $t7, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r15;
    // 0x804D2D28: lbu         $t8, -0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0X1);
    // 0x804D2D2C: bne         $v0, $a0, L_804D2D04
    if (ctx->r2 != ctx->r4) {
        // 0x804D2D30: sb          $t8, 0xC($v1)
        MEM_B(0XC, ctx->r3) = ctx->r24;
            goto L_804D2D04;
    }
    // 0x804D2D30: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    // 0x804D2D34: jr          $ra
    // 0x804D2D38: nop

    return;
    // 0x804D2D38: nop

L_804D2D3C:
    // 0x804D2D3C: lui         $t0, 0x804D
    ctx->r8 = S32(RELOC_HI16(249, 0X510) << 16);
    // 0x804D2D40: addiu       $t0, $t0, 0x3020
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(249, 0X510));
    // 0x804D2D44: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x804D2D48: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x804D2D4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804D2D50: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_804D2D54:
    // 0x804D2D54: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    // 0x804D2D58: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804D2D5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804D2D60: sb          $t1, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r9;
    // 0x804D2D64: lbu         $t2, 0x1($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X1);
    // 0x804D2D68: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x804D2D6C: sb          $t2, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r10;
    // 0x804D2D70: lbu         $t3, -0x2($a2)
    ctx->r11 = MEM_BU(ctx->r6, -0X2);
    // 0x804D2D74: sb          $t3, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r11;
    // 0x804D2D78: lbu         $t4, -0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, -0X1);
    // 0x804D2D7C: bne         $v0, $a0, L_804D2D54
    if (ctx->r2 != ctx->r4) {
        // 0x804D2D80: sb          $t4, 0xC($v1)
        MEM_B(0XC, ctx->r3) = ctx->r12;
            goto L_804D2D54;
    }
    // 0x804D2D80: sb          $t4, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r12;
    // 0x804D2D84: jr          $ra
    // 0x804D2D88: nop

    return;
    // 0x804D2D88: nop

;}
RECOMP_FUNC void func_80673C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673C4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80673C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80673C54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80673C58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80673C5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80673C60: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80673C64: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80673C68: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80673C6C: beq         $v0, $at, L_80673C88
    if (ctx->r2 == ctx->r1) {
        // 0x80673C70: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80673C88;
    }
    // 0x80673C70: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80673C74: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80673C78: beq         $v0, $at, L_80673C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80673C7C: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80673C9C;
    }
    // 0x80673C7C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80673C80: b           L_80673CBC
    // 0x80673C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80673CBC;
    // 0x80673C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80673C88:
    // 0x80673C88: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80673C8C: jal         0x8002F6E4
    // 0x80673C90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x80673C90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80673C94: b           L_80673CBC
    // 0x80673C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80673CBC;
    // 0x80673C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80673C9C:
    // 0x80673C9C: lw          $t9, 0x1F4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1F4);
    // 0x80673CA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80673CA4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80673CA8: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80673CAC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80673CB0: jal         0x806730B0
    // 0x80673CB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_806730B0(rdram, ctx);
        goto after_1;
    // 0x80673CB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80673CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80673CBC:
    // 0x80673CBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80673CC0: jr          $ra
    // 0x80673CC4: nop

    return;
    // 0x80673CC4: nop

;}
RECOMP_FUNC void func_805ABBA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ABBA0: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x805ABBA4: addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
    // 0x805ABBA8: beql        $v0, $zero, L_805ABBE0
    if (ctx->r2 == 0) {
        // 0x805ABBAC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805ABBE0;
    }
    goto skip_0;
    // 0x805ABBAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_805ABBB0:
    // 0x805ABBB0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x805ABBB4: beq         $a1, $zero, L_805ABBD4
    if (ctx->r5 == 0) {
        // 0x805ABBB8: nop
    
            goto L_805ABBD4;
    }
    // 0x805ABBB8: nop

    // 0x805ABBBC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x805ABBC0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x805ABBC4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x805ABBC8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x805ABBCC: jr          $ra
    // 0x805ABBD0: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x805ABBD0: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
L_805ABBD4:
    // 0x805ABBD4: bne         $v0, $zero, L_805ABBB0
    if (ctx->r2 != 0) {
        // 0x805ABBD8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_805ABBB0;
    }
    // 0x805ABBD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x805ABBDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805ABBE0:
    // 0x805ABBE0: jr          $ra
    // 0x805ABBE4: nop

    return;
    // 0x805ABBE4: nop

;}
RECOMP_FUNC void func_8045BAD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045BAD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045BADC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045BAE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8045BAE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045BAE8: jal         0x80051194
    // 0x8045BAEC: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x8045BAEC: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x8045BAF0: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x8045BAF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BAF8: jal         0x8045BBF4
    // 0x8045BAFC: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_8045BBF4(rdram, ctx);
        goto after_1;
    // 0x8045BAFC: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_1:
    // 0x8045BB00: beq         $v0, $zero, L_8045BB2C
    if (ctx->r2 == 0) {
        // 0x8045BB04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8045BB2C;
    }
    // 0x8045BB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BB08: jal         0x8045BE24
    // 0x8045BB0C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_8045BE24(rdram, ctx);
        goto after_2;
    // 0x8045BB0C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_2:
    // 0x8045BB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045BB18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8045BB1C: jal         0x8045D680
    // 0x8045BB20: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8045D680(rdram, ctx);
        goto after_3;
    // 0x8045BB20: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x8045BB24: b           L_8045BB38
    // 0x8045BB28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8045BB38;
    // 0x8045BB28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045BB2C:
    // 0x8045BB2C: jal         0x800445A4
    // 0x8045BB30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8045BB30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8045BB34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045BB38:
    // 0x8045BB38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045BB3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045BB40: jr          $ra
    // 0x8045BB44: nop

    return;
    // 0x8045BB44: nop

;}
RECOMP_FUNC void func_8041F634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041F634: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8041F638: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x8041F63C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8041F640: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8041F644: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8041F648: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8041F64C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8041F650: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041F654: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8041F658: lwc1        $f2, 0x88($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8041F65C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8041F660: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8041F664: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8041F668: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8041F66C: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8041F670: nop

    // 0x8041F674: bc1fl       L_8041F694
    if (!c1cs) {
        // 0x8041F678: c.lt.s      $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
            goto L_8041F694;
    }
    goto skip_0;
    // 0x8041F678: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    skip_0:
    // 0x8041F67C: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8041F680: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041F684: lwc1        $f2, 0x88($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8041F688: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8041F68C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8041F690: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
L_8041F694:
    // 0x8041F694: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8041F698: bc1f        L_8041F6B4
    if (!c1cs) {
        // 0x8041F69C: nop
    
            goto L_8041F6B4;
    }
    // 0x8041F69C: nop

    // 0x8041F6A0: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8041F6A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8041F6A8: nop

    // 0x8041F6AC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8041F6B0: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
L_8041F6B4:
    // 0x8041F6B4: jr          $ra
    // 0x8041F6B8: nop

    return;
    // 0x8041F6B8: nop

;}
RECOMP_FUNC void func_8073F1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F1B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073F1B4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8073F1B8: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x8073F1BC: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8073F1C0: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x8073F1C4: beq         $v1, $zero, L_8073F204
    if (ctx->r3 == 0) {
        // 0x8073F1C8: lw          $t0, 0x10($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X10);
            goto L_8073F204;
    }
    // 0x8073F1C8: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x8073F1CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8073F1D0: sb          $v0, 0x17C($v1)
    MEM_B(0X17C, ctx->r3) = ctx->r2;
    // 0x8073F1D4: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8073F1D8: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8073F1DC: lwc1        $f10, 0x88($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X88);
    // 0x8073F1E0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073F1E4: lwc1        $f4, 0x8C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x8073F1E8: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x8073F1EC: lwc1        $f16, 0x88($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8073F1F0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8073F1F4: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x8073F1F8: lwc1        $f6, 0x8C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8073F1FC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073F200: swc1        $f8, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f8.u32l;
L_8073F204:
    // 0x8073F204: beq         $a1, $zero, L_8073F240
    if (ctx->r5 == 0) {
        // 0x8073F208: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8073F240;
    }
    // 0x8073F208: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8073F20C: sb          $v0, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r2;
    // 0x8073F210: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8073F214: lwc1        $f10, 0x84($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X84);
    // 0x8073F218: lwc1        $f4, 0x88($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X88);
    // 0x8073F21C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8073F220: lwc1        $f10, 0x8C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8C);
    // 0x8073F224: swc1        $f18, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f18.u32l;
    // 0x8073F228: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8073F22C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073F230: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
    // 0x8073F234: lwc1        $f16, 0x8C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8073F238: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8073F23C: swc1        $f18, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f18.u32l;
L_8073F240:
    // 0x8073F240: beq         $a2, $zero, L_8073F27C
    if (ctx->r6 == 0) {
        // 0x8073F244: nop
    
            goto L_8073F27C;
    }
    // 0x8073F244: nop

    // 0x8073F248: sb          $v0, 0x17C($a2)
    MEM_B(0X17C, ctx->r6) = ctx->r2;
    // 0x8073F24C: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8073F250: lwc1        $f4, 0x84($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X84);
    // 0x8073F254: lwc1        $f10, 0x88($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X88);
    // 0x8073F258: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073F25C: lwc1        $f4, 0x8C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8C);
    // 0x8073F260: swc1        $f8, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f8.u32l;
    // 0x8073F264: lwc1        $f16, 0x88($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8073F268: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8073F26C: swc1        $f18, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f18.u32l;
    // 0x8073F270: lwc1        $f6, 0x8C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8073F274: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073F278: swc1        $f8, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f8.u32l;
L_8073F27C:
    // 0x8073F27C: beq         $a3, $zero, L_8073F2B8
    if (ctx->r7 == 0) {
        // 0x8073F280: nop
    
            goto L_8073F2B8;
    }
    // 0x8073F280: nop

    // 0x8073F284: sb          $v0, 0x17C($a3)
    MEM_B(0X17C, ctx->r7) = ctx->r2;
    // 0x8073F288: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8073F28C: lwc1        $f10, 0x84($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X84);
    // 0x8073F290: lwc1        $f4, 0x88($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X88);
    // 0x8073F294: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8073F298: lwc1        $f10, 0x8C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8C);
    // 0x8073F29C: swc1        $f18, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f18.u32l;
    // 0x8073F2A0: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8073F2A4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073F2A8: swc1        $f8, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f8.u32l;
    // 0x8073F2AC: lwc1        $f16, 0x8C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8073F2B0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8073F2B4: swc1        $f18, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->f18.u32l;
L_8073F2B8:
    // 0x8073F2B8: beq         $t0, $zero, L_8073F2F4
    if (ctx->r8 == 0) {
        // 0x8073F2BC: nop
    
            goto L_8073F2F4;
    }
    // 0x8073F2BC: nop

    // 0x8073F2C0: sb          $v0, 0x17C($t0)
    MEM_B(0X17C, ctx->r8) = ctx->r2;
    // 0x8073F2C4: lwc1        $f6, 0x84($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X84);
    // 0x8073F2C8: lwc1        $f4, 0x84($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X84);
    // 0x8073F2CC: lwc1        $f10, 0x88($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X88);
    // 0x8073F2D0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073F2D4: lwc1        $f4, 0x8C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8C);
    // 0x8073F2D8: swc1        $f8, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f8.u32l;
    // 0x8073F2DC: lwc1        $f16, 0x88($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X88);
    // 0x8073F2E0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8073F2E4: swc1        $f18, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f18.u32l;
    // 0x8073F2E8: lwc1        $f6, 0x8C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8C);
    // 0x8073F2EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073F2F0: swc1        $f8, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f8.u32l;
L_8073F2F4:
    // 0x8073F2F4: jr          $ra
    // 0x8073F2F8: nop

    return;
    // 0x8073F2F8: nop

;}
RECOMP_FUNC void func_80699BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80699BCC: jal         0x80699A94
    // 0x80699BD0: nop

    func_80699A94(rdram, ctx);
        goto after_0;
    // 0x80699BD0: nop

    after_0:
    // 0x80699BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699BDC: jr          $ra
    // 0x80699BE0: nop

    return;
    // 0x80699BE0: nop

;}
RECOMP_FUNC void func_806A2A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A2A3C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806A2A40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806A2A44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806A2A48: jal         0x806A2984
    // 0x806A2A4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806A2984(rdram, ctx);
        goto after_0;
    // 0x806A2A4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806A2A50: beql        $v0, $zero, L_806A2B40
    if (ctx->r2 == 0) {
        // 0x806A2A54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806A2B40;
    }
    goto skip_0;
    // 0x806A2A54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806A2A58: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x806A2A5C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x806A2A60: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x806A2A64: bne         $t7, $zero, L_806A2A7C
    if (ctx->r15 != 0) {
        // 0x806A2A68: sw          $t7, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r15;
            goto L_806A2A7C;
    }
    // 0x806A2A68: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x806A2A6C: jal         0x800447C8
    // 0x806A2A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806A2A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806A2A74: b           L_806A2B40
    // 0x806A2A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806A2B40;
    // 0x806A2A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806A2A7C:
    // 0x806A2A7C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x806A2A80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806A2A84: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806A2A88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806A2A8C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806A2A90: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x806A2A94: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x806A2A98: nop

    // 0x806A2A9C: bc1f        L_806A2AA8
    if (!c1cs) {
        // 0x806A2AA0: nop
    
            goto L_806A2AA8;
    }
    // 0x806A2AA0: nop

    // 0x806A2AA4: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
L_806A2AA8:
    // 0x806A2AA8: jal         0x80066DE4
    // 0x806A2AAC: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x806A2AAC: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    after_2:
    // 0x806A2AB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806A2AB4: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806A2AB8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x806A2ABC: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x806A2AC0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806A2AC4: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(583, 0X584) << 16);
    // 0x806A2AC8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806A2ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A2AD0: bc1f        L_806A2AE8
    if (!c1cs) {
        // 0x806A2AD4: nop
    
            goto L_806A2AE8;
    }
    // 0x806A2AD4: nop

    // 0x806A2AD8: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(583, 0X580) << 16);
    // 0x806A2ADC: lwc1        $f10, 0x2DE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(583, 0X580));
    // 0x806A2AE0: b           L_806A2AF0
    // 0x806A2AE4: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
        goto L_806A2AF0;
    // 0x806A2AE4: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
L_806A2AE8:
    // 0x806A2AE8: lwc1        $f16, 0x2DE4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(583, 0X584));
    // 0x806A2AEC: swc1        $f16, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f16.u32l;
L_806A2AF0:
    // 0x806A2AF0: jal         0x80048F84
    // 0x806A2AF4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x806A2AF4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x806A2AF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806A2AFC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806A2B00: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(583, 0X588) << 16);
    // 0x806A2B04: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806A2B08: lwc1        $f4, 0x2DE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(583, 0X588));
    // 0x806A2B0C: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x806A2B10: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(583, 0X58C) << 16);
    // 0x806A2B14: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806A2B18: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x806A2B1C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x806A2B20: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x806A2B24: swc1        $f10, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f10.u32l;
    // 0x806A2B28: lwc1        $f4, 0x2DEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(583, 0X58C));
    // 0x806A2B2C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806A2B30: sub.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x806A2B34: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x806A2B38: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x806A2B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806A2B40:
    // 0x806A2B40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806A2B44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806A2B48: jr          $ra
    // 0x806A2B4C: nop

    return;
    // 0x806A2B4C: nop

;}
RECOMP_FUNC void func_806724D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806724D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806724DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806724E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806724E4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806724E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806724EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806724F0: lw          $a3, 0x20($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X20);
    // 0x806724F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806724F8: lw          $t6, 0x1E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1E0);
    // 0x806724FC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80672500: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x80672504: lw          $a3, 0x20($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X20);
    // 0x80672508: lw          $t8, 0x1E0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X1E0);
    // 0x8067250C: slti        $at, $t8, 0x14
    ctx->r1 = SIGNED(ctx->r24) < 0X14 ? 1 : 0;
    // 0x80672510: bnel        $at, $zero, L_80672524
    if (ctx->r1 != 0) {
        // 0x80672514: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80672524;
    }
    goto skip_0;
    // 0x80672514: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x80672518: sw          $zero, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = 0;
    // 0x8067251C: lw          $a3, 0x20($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X20);
    // 0x80672520: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80672524:
    // 0x80672524: jal         0x80671BE4
    // 0x80672528: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80671BE4(rdram, ctx);
        goto after_0;
    // 0x80672528: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8067252C: lw          $t9, 0x1E0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E0);
    // 0x80672530: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80672534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80672538: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8067253C: slti        $at, $t0, 0x14
    ctx->r1 = SIGNED(ctx->r8) < 0X14 ? 1 : 0;
    // 0x80672540: bne         $at, $zero, L_80672560
    if (ctx->r1 != 0) {
        // 0x80672544: sw          $t0, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r8;
            goto L_80672560;
    }
    // 0x80672544: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    // 0x80672548: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8067254C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80672550: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80672554: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80672558: jal         0x80672C80
    // 0x8067255C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    func_80672C80(rdram, ctx);
        goto after_1;
    // 0x8067255C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    after_1:
L_80672560:
    // 0x80672560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80672564: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80672568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8067256C: jr          $ra
    // 0x80672570: nop

    return;
    // 0x80672570: nop

;}
RECOMP_FUNC void func_804751E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804751E0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804751E4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804751E8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804751EC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804751F0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804751F4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804751F8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804751FC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475200: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475204: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475208: jr          $ra
    // 0x8047520C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047520C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8000C910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C910: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000C914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000C918: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000C91C: sll         $t7, $v0, 9
    ctx->r15 = S32(ctx->r2 << 9);
    // 0x8000C920: bltz        $t7, L_8000C930
    if (SIGNED(ctx->r15) < 0) {
        // 0x8000C924: addiu       $t1, $zero, 0x18
        ctx->r9 = ADD32(0, 0X18);
            goto L_8000C930;
    }
    // 0x8000C924: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x8000C928: beql        $a1, $zero, L_8000C984
    if (ctx->r5 == 0) {
        // 0x8000C92C: sll         $t6, $v0, 10
        ctx->r14 = S32(ctx->r2 << 10);
            goto L_8000C984;
    }
    goto skip_0;
    // 0x8000C92C: sll         $t6, $v0, 10
    ctx->r14 = S32(ctx->r2 << 10);
    skip_0:
L_8000C930:
    // 0x8000C930: lwc1        $f4, 0x2C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8000C934: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8000C938: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x8000C93C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000C940: lwc1        $f10, 0x30($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8000C944: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000C948: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x8000C94C: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000C950: bgez        $t2, L_8000C974
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8000C954: nop
    
            goto L_8000C974;
    }
    // 0x8000C954: nop

    // 0x8000C958: lbu         $t3, 0x3($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X3);
    // 0x8000C95C: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x8000C960: beq         $t4, $zero, L_8000C974
    if (ctx->r12 == 0) {
        // 0x8000C964: nop
    
            goto L_8000C974;
    }
    // 0x8000C964: nop

    // 0x8000C968: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8000C96C: mul.s       $f0, $f16, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8000C970: nop

L_8000C974:
    // 0x8000C974: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000C978: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000C97C: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x8000C980: sll         $t6, $v0, 10
    ctx->r14 = S32(ctx->r2 << 10);
L_8000C984:
    // 0x8000C984: bgez        $t6, L_8000C9A4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000C988: addiu       $t0, $zero, 0x80
        ctx->r8 = ADD32(0, 0X80);
            goto L_8000C9A4;
    }
    // 0x8000C988: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8000C98C: lbu         $t7, 0xA($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XA);
    // 0x8000C990: lbu         $t8, 0xB($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XB);
    // 0x8000C994: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C998: mflo        $t9
    ctx->r25 = lo;
    // 0x8000C99C: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
    // 0x8000C9A0: nop

L_8000C9A4:
    // 0x8000C9A4: lw          $v1, 0x50($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X50);
    // 0x8000C9A8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8000C9AC: beq         $v1, $zero, L_8000CAA8
    if (ctx->r3 == 0) {
        // 0x8000C9B0: nop
    
            goto L_8000CAA8;
    }
    // 0x8000C9B0: nop

    // 0x8000C9B4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8000C9B8: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x8000C9BC: beq         $t3, $zero, L_8000CAA8
    if (ctx->r11 == 0) {
        // 0x8000C9C0: nop
    
            goto L_8000CAA8;
    }
    // 0x8000C9C0: nop

    // 0x8000C9C4: lw          $t4, 0x2C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2C);
    // 0x8000C9C8: beq         $t4, $zero, L_8000CAA8
    if (ctx->r12 == 0) {
        // 0x8000C9CC: nop
    
            goto L_8000CAA8;
    }
    // 0x8000C9CC: nop

    // 0x8000C9D0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000C9D4: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8000C9D8: beql        $t5, $zero, L_8000CA34
    if (ctx->r13 == 0) {
        // 0x8000C9DC: lb          $t6, 0x1($a0)
        ctx->r14 = MEM_B(ctx->r4, 0X1);
            goto L_8000CA34;
    }
    goto skip_1;
    // 0x8000C9DC: lb          $t6, 0x1($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1);
    skip_1:
    // 0x8000C9E0: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8000C9E4: lwc1        $f6, 0x38($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8000C9E8: lwc1        $f10, 0x38($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8000C9EC: lbu         $t6, 0x5($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X5);
    // 0x8000C9F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000C9F4: andi        $t5, $v0, 0xFFFE
    ctx->r13 = ctx->r2 & 0XFFFE;
    // 0x8000C9F8: swc1        $f8, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f8.u32l;
    // 0x8000C9FC: lwc1        $f16, 0x34($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8000CA00: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000CA04: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x8000CA08: lbu         $t7, 0xB($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XB);
    // 0x8000CA0C: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x8000CA10: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8000CA14: subu        $t8, $t0, $t7
    ctx->r24 = SUB32(ctx->r8, ctx->r15);
    // 0x8000CA18: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000CA1C: mflo        $t9
    ctx->r25 = lo;
    // 0x8000CA20: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x8000CA24: sra         $t4, $t3, 7
    ctx->r12 = S32(SIGNED(ctx->r11) >> 7);
    // 0x8000CA28: b           L_8000CAA8
    // 0x8000CA2C: sb          $t4, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r12;
        goto L_8000CAA8;
    // 0x8000CA2C: sb          $t4, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r12;
    // 0x8000CA30: lb          $t6, 0x1($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1);
L_8000CA34:
    // 0x8000CA34: bgezl       $t6, L_8000CA50
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000CA38: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8000CA50;
    }
    goto skip_2;
    // 0x8000CA38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x8000CA3C: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8000CA40: lwc1        $f6, 0x38($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8000CA44: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000CA48: swc1        $f8, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f8.u32l;
    // 0x8000CA4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_8000CA50:
    // 0x8000CA50: sll         $t2, $v0, 9
    ctx->r10 = S32(ctx->r2 << 9);
    // 0x8000CA54: bltzl       $t2, L_8000CA68
    if (SIGNED(ctx->r10) < 0) {
        // 0x8000CA58: lwc1        $f10, 0x38($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X38);
            goto L_8000CA68;
    }
    goto skip_3;
    // 0x8000CA58: lwc1        $f10, 0x38($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X38);
    skip_3:
    // 0x8000CA5C: beql        $a1, $zero, L_8000CA7C
    if (ctx->r5 == 0) {
        // 0x8000CA60: sll         $t3, $v0, 10
        ctx->r11 = S32(ctx->r2 << 10);
            goto L_8000CA7C;
    }
    goto skip_4;
    // 0x8000CA60: sll         $t3, $v0, 10
    ctx->r11 = S32(ctx->r2 << 10);
    skip_4:
    // 0x8000CA64: lwc1        $f10, 0x38($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X38);
L_8000CA68:
    // 0x8000CA68: lwc1        $f16, 0x34($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8000CA6C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000CA70: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x8000CA74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000CA78: sll         $t3, $v0, 10
    ctx->r11 = S32(ctx->r2 << 10);
L_8000CA7C:
    // 0x8000CA7C: bgez        $t3, L_8000CAA8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000CA80: nop
    
            goto L_8000CAA8;
    }
    // 0x8000CA80: nop

    // 0x8000CA84: lbu         $t5, 0xB($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XB);
    // 0x8000CA88: lbu         $t4, 0x5($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X5);
    // 0x8000CA8C: lw          $t8, 0x30($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X30);
    // 0x8000CA90: subu        $t7, $t0, $t5
    ctx->r15 = SUB32(ctx->r8, ctx->r13);
    // 0x8000CA94: multu       $t4, $t7
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000CA98: mflo        $t6
    ctx->r14 = lo;
    // 0x8000CA9C: addu        $t2, $t8, $t6
    ctx->r10 = ADD32(ctx->r24, ctx->r14);
    // 0x8000CAA0: sra         $t9, $t2, 7
    ctx->r25 = S32(SIGNED(ctx->r10) >> 7);
    // 0x8000CAA4: sb          $t9, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r25;
L_8000CAA8:
    // 0x8000CAA8: bne         $a2, $t1, L_8000C9A4
    if (ctx->r6 != ctx->r9) {
        // 0x8000CAAC: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8000C9A4;
    }
    // 0x8000CAAC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8000CAB0: jr          $ra
    // 0x8000CAB4: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    return;
    // 0x8000CAB4: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80000FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000FF8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80000FFC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80001000: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80001004: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80001008: andi        $t9, $a2, 0xFFFF
    ctx->r25 = ctx->r6 & 0XFFFF;
    // 0x8000100C: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80001010: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80001014: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x80001018: sll         $t2, $a3, 16
    ctx->r10 = S32(ctx->r7 << 16);
    // 0x8000101C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x80001020: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80001024: jr          $ra
    // 0x80001028: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    return;
    // 0x80001028: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void func_8000744C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000744C: beq         $a0, $zero, L_80007474
    if (ctx->r4 == 0) {
        // 0x80007450: lui         $v1, 0x800B
        ctx->r3 = S32(0X800B << 16);
            goto L_80007474;
    }
    // 0x80007450: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80007454: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007458: beq         $a0, $at, L_8000747C
    if (ctx->r4 == ctx->r1) {
        // 0x8000745C: lui         $v1, 0x800B
        ctx->r3 = S32(0X800B << 16);
            goto L_8000747C;
    }
    // 0x8000745C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80007460: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80007464: beq         $a0, $at, L_80007484
    if (ctx->r4 == ctx->r1) {
        // 0x80007468: lui         $v1, 0x800B
        ctx->r3 = S32(0X800B << 16);
            goto L_80007484;
    }
    // 0x80007468: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8000746C: jr          $ra
    // 0x80007470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80007470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80007474:
    // 0x80007474: jr          $ra
    // 0x80007478: lw          $v0, 0x6A74($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6A74);
    return;
    // 0x80007478: lw          $v0, 0x6A74($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6A74);
L_8000747C:
    // 0x8000747C: jr          $ra
    // 0x80007480: lw          $v0, 0x6A78($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6A78);
    return;
    // 0x80007480: lw          $v0, 0x6A78($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6A78);
L_80007484:
    // 0x80007484: lw          $v1, 0x6A7C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6A7C);
    // 0x80007488: jr          $ra
    // 0x8000748C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000748C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8007B2DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B2DC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007B2E0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8007B2E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007B2E8: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8007B2EC: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8007B2F0: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8007B2F4: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8007B2F8: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8007B2FC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8007B300: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8007B304: bc1f        L_8007B318
    if (!c1cs) {
        // 0x8007B308: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8007B318;
    }
    // 0x8007B308: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007B30C: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x8007B310: b           L_8007B320
    // 0x8007B314: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_8007B320;
    // 0x8007B314: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8007B318:
    // 0x8007B318: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8007B31C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8007B320:
    // 0x8007B320: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8007B324: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007B328: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007B32C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8007B330: bc1f        L_8007B340
    if (!c1cs) {
        // 0x8007B334: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_8007B340;
    }
    // 0x8007B334: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8007B338: b           L_8007B348
    // 0x8007B33C: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
        goto L_8007B348;
    // 0x8007B33C: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_8007B340:
    // 0x8007B340: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
    // 0x8007B344: ori         $t0, $t0, 0x2
    ctx->r8 = ctx->r8 | 0X2;
L_8007B348:
    // 0x8007B348: lw          $v0, -0x7AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7AF0);
    // 0x8007B34C: mul.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8007B350: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8007B354: lhu         $t7, 0x18($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X18);
    // 0x8007B358: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007B35C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8007B360: add.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8007B364: bgez        $t7, L_8007B378
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8007B368: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8007B378;
    }
    // 0x8007B368: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007B36C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007B370: nop

    // 0x8007B374: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8007B378:
    // 0x8007B378: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8007B37C: nop

    // 0x8007B380: bc1tl       L_8007B4E4
    if (c1cs) {
        // 0x8007B384: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8007B4E4;
    }
    goto skip_0;
    // 0x8007B384: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8007B388: lhu         $t8, 0x1C($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1C);
    // 0x8007B38C: sub.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8007B390: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007B394: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8007B398: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8007B39C: bgez        $t8, L_8007B3B0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007B3A0: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8007B3B0;
    }
    // 0x8007B3A0: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007B3A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007B3A8: nop

    // 0x8007B3AC: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_8007B3B0:
    // 0x8007B3B0: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8007B3B4: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x8007B3B8: bc1tl       L_8007B4E4
    if (c1cs) {
        // 0x8007B3BC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8007B4E4;
    }
    goto skip_1;
    // 0x8007B3BC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x8007B3C0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8007B3C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007B3C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007B3CC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007B3D0: lhu         $t4, 0x1A($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X1A);
    // 0x8007B3D4: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007B3D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007B3DC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8007B3E0: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8007B3E4: mul.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8007B3E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007B3EC: bgez        $t4, L_8007B400
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007B3F0: add.s       $f16, $f6, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f2.fl;
            goto L_8007B400;
    }
    // 0x8007B3F0: add.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8007B3F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007B3F8: nop

    // 0x8007B3FC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8007B400:
    // 0x8007B400: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8007B404: nop

    // 0x8007B408: bc1tl       L_8007B4E4
    if (c1cs) {
        // 0x8007B40C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8007B4E4;
    }
    goto skip_2;
    // 0x8007B40C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x8007B410: lhu         $t5, 0x1E($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X1E);
    // 0x8007B414: sub.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8007B418: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007B41C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8007B420: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8007B424: bgez        $t5, L_8007B438
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007B428: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8007B438;
    }
    // 0x8007B428: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007B42C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007B430: nop

    // 0x8007B434: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_8007B438:
    // 0x8007B438: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8007B43C: sllv        $v1, $t3, $a3
    ctx->r3 = S32(ctx->r11 << (ctx->r7 & 31));
    // 0x8007B440: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007B444: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007B448: bc1t        L_8007B4E0
    if (c1cs) {
        // 0x8007B44C: sra         $v1, $v1, 1
        ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8007B4E0;
    }
    // 0x8007B44C: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8007B450: bne         $a2, $at, L_8007B460
    if (ctx->r6 != ctx->r1) {
        // 0x8007B454: addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
            goto L_8007B460;
    }
    // 0x8007B454: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x8007B458: b           L_8007B460
    // 0x8007B45C: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
        goto L_8007B460;
    // 0x8007B45C: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
L_8007B460:
    // 0x8007B460: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B464: mflo        $t6
    ctx->r14 = lo;
    // 0x8007B468: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007B46C: bnel        $at, $zero, L_8007B4A0
    if (ctx->r1 != 0) {
        // 0x8007B470: lw          $t7, 0x5C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5C);
            goto L_8007B4A0;
    }
    goto skip_3;
    // 0x8007B470: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    skip_3:
    // 0x8007B474: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8007B478: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8007B47C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8007B480: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8007B484: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8007B488: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8007B48C: jal         0x80079A20
    // 0x8007B490: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_80079A20(rdram, ctx);
        goto after_0;
    // 0x8007B490: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x8007B494: b           L_8007B4E4
    // 0x8007B498: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8007B4E4;
    // 0x8007B498: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8007B49C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
L_8007B4A0:
    // 0x8007B4A0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8007B4A4: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8007B4A8: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007B4AC: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8007B4B0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8007B4B4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8007B4B8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8007B4BC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8007B4C0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8007B4C4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007B4C8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8007B4CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8007B4D0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8007B4D4: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8007B4D8: jal         0x8007A900
    // 0x8007B4DC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_8007A900(rdram, ctx);
        goto after_1;
    // 0x8007B4DC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_1:
L_8007B4E0:
    // 0x8007B4E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8007B4E4:
    // 0x8007B4E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8007B4E8: jr          $ra
    // 0x8007B4EC: nop

    return;
    // 0x8007B4EC: nop

;}
RECOMP_FUNC void func_8064DFC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064DFC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064DFCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064DFD0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8064DFD4: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064DFD8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8064DFDC: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8064DFE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064DFE4: jal         0x80065728
    // 0x8064DFE8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8064DFE8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064DFEC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8064DFF0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8064DFF4: lwc1        $f4, 0x3C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8064DFF8: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x8064DFFC: lwc1        $f6, 0x40($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8064E000: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x8064E004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064E008: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064E00C: jr          $ra
    // 0x8064E010: nop

    return;
    // 0x8064E010: nop

;}
RECOMP_FUNC void func_804C9518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C9518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C951C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C9520: jal         0x8004700C
    // 0x804C9524: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804C9524: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C9528: beq         $v0, $zero, L_804C9558
    if (ctx->r2 == 0) {
        // 0x804C952C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804C9558;
    }
    // 0x804C952C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C9530: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x804C9534: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x804C9538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C953C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804C9540: nop

    // 0x804C9544: bc1f        L_804C955C
    if (!c1cs) {
        // 0x804C9548: nop
    
            goto L_804C955C;
    }
    // 0x804C9548: nop

    // 0x804C954C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C9550: b           L_804C955C
    // 0x804C9554: nop

        goto L_804C955C;
    // 0x804C9554: nop

L_804C9558:
    // 0x804C9558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_804C955C:
    // 0x804C955C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(228, 0X7E0) << 16);
    // 0x804C9560: lwc1        $f2, -0x64E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X7E0));
    // 0x804C9564: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(228, 0X7E4) << 16);
    // 0x804C9568: lwc1        $f12, -0x64DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X7E4));
    // 0x804C956C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804C9570: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(228, 0X780) << 16);
    // 0x804C9574: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x804C9578: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804C957C: swc1        $f2, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f2.u32l;
    // 0x804C9580: swc1        $f2, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f2.u32l;
    // 0x804C9584: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x804C9588: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x804C958C: lwc1        $f8, -0x6540($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X780));
    // 0x804C9590: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(228, 0X788) << 16);
    // 0x804C9594: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x804C9598: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x804C959C: swc1        $f12, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f12.u32l;
    // 0x804C95A0: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(228, 0X1B0) << 16);
    // 0x804C95A4: addiu       $t6, $t6, -0x6B10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(228, 0X1B0));
    // 0x804C95A8: swc1        $f10, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f10.u32l;
    // 0x804C95AC: lw          $v0, -0x6538($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(228, 0X788));
    // 0x804C95B0: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x804C95B4: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
    // 0x804C95B8: sw          $v0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r2;
    // 0x804C95BC: sw          $v0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r2;
    // 0x804C95C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C95C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C95C8: jr          $ra
    // 0x804C95CC: nop

    return;
    // 0x804C95CC: nop

;}
RECOMP_FUNC void func_800268BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800268BC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x800268C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800268C4: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x800268C8: lbu         $v0, 0x17C($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X17C);
    // 0x800268CC: addiu       $t7, $t7, 0x674C
    ctx->r15 = ADD32(ctx->r15, 0X674C);
    // 0x800268D0: beq         $v0, $at, L_800268E8
    if (ctx->r2 == ctx->r1) {
        // 0x800268D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800268E8;
    }
    // 0x800268D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800268D8: beq         $v0, $at, L_80026900
    if (ctx->r2 == ctx->r1) {
        // 0x800268DC: lui         $t8, 0x8002
        ctx->r24 = S32(0X8002 << 16);
            goto L_80026900;
    }
    // 0x800268DC: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x800268E0: jr          $ra
    // 0x800268E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800268E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800268E8:
    // 0x800268E8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800268EC: sb          $v0, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r2;
    // 0x800268F0: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x800268F4: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    // 0x800268F8: jr          $ra
    // 0x800268FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800268FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80026900:
    // 0x80026900: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x80026904: addiu       $t8, $t8, 0x680C
    ctx->r24 = ADD32(ctx->r24, 0X680C);
    // 0x80026908: sw          $v0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r2;
    // 0x8002690C: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    // 0x80026910: sb          $v0, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r2;
    // 0x80026914: jr          $ra
    // 0x80026918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80026918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80043E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043E8C: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80043E90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043E94: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80043E98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80043E9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80043EA0: beq         $t7, $zero, L_80043EC0
    if (ctx->r15 == 0) {
        // 0x80043EA4: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80043EC0;
    }
    // 0x80043EA4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80043EA8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043EAC: addiu       $a0, $a0, 0x3D0
    ctx->r4 = ADD32(ctx->r4, 0X3D0);
    // 0x80043EB0: jal         0x80071380
    // 0x80043EB4: addiu       $a1, $zero, 0x2F6
    ctx->r5 = ADD32(0, 0X2F6);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80043EB4: addiu       $a1, $zero, 0x2F6
    ctx->r5 = ADD32(0, 0X2F6);
    after_0:
    // 0x80043EB8: b           L_80043EF0
    // 0x80043EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80043EF0;
    // 0x80043EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80043EC0:
    // 0x80043EC0: lh          $a1, 0x184($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X184);
    // 0x80043EC4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80043EC8: addiu       $a2, $a2, 0x3E88
    ctx->r6 = ADD32(ctx->r6, 0X3E88);
    // 0x80043ECC: beq         $a1, $zero, L_80043EDC
    if (ctx->r5 == 0) {
        // 0x80043ED0: addiu       $a0, $s0, 0x188
        ctx->r4 = ADD32(ctx->r16, 0X188);
            goto L_80043EDC;
    }
    // 0x80043ED0: addiu       $a0, $s0, 0x188
    ctx->r4 = ADD32(ctx->r16, 0X188);
    // 0x80043ED4: jal         0x80057F74
    // 0x80043ED8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_80057F74(rdram, ctx);
        goto after_1;
    // 0x80043ED8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
L_80043EDC:
    // 0x80043EDC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80043EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80043EE4: jalr        $t9
    // 0x80043EE8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80043EE8: nop

    after_2:
    // 0x80043EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80043EF0:
    // 0x80043EF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80043EF8: jr          $ra
    // 0x80043EFC: nop

    return;
    // 0x80043EFC: nop

;}
RECOMP_FUNC void func_8002B9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B9E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002B9E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002B9EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002B9F0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8002B9F4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8002B9F8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8002B9FC: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8002BA00: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8002BA04: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002BA08: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8002BA0C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8002BA10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002BA14: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x8002BA18: beql        $v0, $zero, L_8002BA7C
    if (ctx->r2 == 0) {
        // 0x8002BA1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002BA7C;
    }
    goto skip_0;
    // 0x8002BA1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8002BA20: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x8002BA24: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002BA28: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x8002BA2C: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x8002BA30: bne         $t0, $at, L_8002BA78
    if (ctx->r8 != ctx->r1) {
        // 0x8002BA34: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8002BA78;
    }
    // 0x8002BA34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002BA38: bnel        $a1, $at, L_8002BA7C
    if (ctx->r5 != ctx->r1) {
        // 0x8002BA3C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002BA7C;
    }
    goto skip_1;
    // 0x8002BA3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8002BA40: lbu         $t1, 0x30($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X30);
    // 0x8002BA44: addiu       $t2, $t1, -0x16
    ctx->r10 = ADD32(ctx->r9, -0X16);
    // 0x8002BA48: sltiu       $at, $t2, 0xE
    ctx->r1 = ctx->r10 < 0XE ? 1 : 0;
    // 0x8002BA4C: beq         $at, $zero, L_8002BA68
    if (ctx->r1 == 0) {
        // 0x8002BA50: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8002BA68;
    }
    // 0x8002BA50: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002BA54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002BA58: addu        $at, $at, $t2
    gpr jr_addend_8002BA60 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8002BA5C: lw          $t2, -0x178($at)
    ctx->r10 = ADD32(ctx->r1, -0X178);
    // 0x8002BA60: jr          $t2
    // 0x8002BA64: nop

    switch (jr_addend_8002BA60 >> 2) {
        case 0: goto L_8002BA78; break;
        case 1: goto L_8002BA78; break;
        case 2: goto L_8002BA78; break;
        case 3: goto L_8002BA78; break;
        case 4: goto L_8002BA78; break;
        case 5: goto L_8002BA78; break;
        case 6: goto L_8002BA78; break;
        case 7: goto L_8002BA78; break;
        case 8: goto L_8002BA78; break;
        case 9: goto L_8002BA78; break;
        case 10: goto L_8002BA78; break;
        case 11: goto L_8002BA78; break;
        case 12: goto L_8002BA78; break;
        case 13: goto L_8002BA78; break;
        default: switch_error(__func__, 0x8002BA60, 0x800AFE88);
    }
    // 0x8002BA64: nop

L_8002BA68:
    // 0x8002BA68: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8002BA6C: beql        $a2, $at, L_8002BA7C
    if (ctx->r6 == ctx->r1) {
        // 0x8002BA70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002BA7C;
    }
    goto skip_2;
    // 0x8002BA70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8002BA74: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
L_8002BA78:
    // 0x8002BA78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8002BA7C:
    // 0x8002BA7C: jal         0x8002B82C
    // 0x8002BA80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8002B82C(rdram, ctx);
        goto after_0;
    // 0x8002BA80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8002BA84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002BA88: jal         0x80023144
    // 0x8002BA8C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80023144(rdram, ctx);
        goto after_1;
    // 0x8002BA8C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x8002BA90: lbu         $t3, 0x18($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X18);
    // 0x8002BA94: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8002BA98: beq         $at, $zero, L_8002BAB0
    if (ctx->r1 == 0) {
        // 0x8002BA9C: nop
    
            goto L_8002BAB0;
    }
    // 0x8002BA9C: nop

    // 0x8002BAA0: jal         0x80027FBC
    // 0x8002BAA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80027FBC(rdram, ctx);
        goto after_2;
    // 0x8002BAA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002BAA8: b           L_8002BABC
    // 0x8002BAAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8002BABC;
    // 0x8002BAAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8002BAB0:
    // 0x8002BAB0: jal         0x80028038
    // 0x8002BAB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028038(rdram, ctx);
        goto after_3;
    // 0x8002BAB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8002BAB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8002BABC:
    // 0x8002BABC: jal         0x8001D808
    // 0x8002BAC0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8001D808(rdram, ctx);
        goto after_4;
    // 0x8002BAC0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x8002BAC4: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8002BAC8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8002BACC: addiu       $t5, $t4, -0x1A
    ctx->r13 = ADD32(ctx->r12, -0X1A);
    // 0x8002BAD0: sltiu       $at, $t5, 0x31
    ctx->r1 = ctx->r13 < 0X31 ? 1 : 0;
    // 0x8002BAD4: beq         $at, $zero, L_8002BB7C
    if (ctx->r1 == 0) {
        // 0x8002BAD8: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8002BB7C;
    }
    // 0x8002BAD8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8002BADC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002BAE0: addu        $at, $at, $t5
    gpr jr_addend_8002BAE8 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8002BAE4: lw          $t5, -0x140($at)
    ctx->r13 = ADD32(ctx->r1, -0X140);
    // 0x8002BAE8: jr          $t5
    // 0x8002BAEC: nop

    switch (jr_addend_8002BAE8 >> 2) {
        case 0: goto L_8002BB48; break;
        case 1: goto L_8002BB7C; break;
        case 2: goto L_8002BB7C; break;
        case 3: goto L_8002BB7C; break;
        case 4: goto L_8002BB7C; break;
        case 5: goto L_8002BB7C; break;
        case 6: goto L_8002BB7C; break;
        case 7: goto L_8002BB7C; break;
        case 8: goto L_8002BB7C; break;
        case 9: goto L_8002BB7C; break;
        case 10: goto L_8002BB7C; break;
        case 11: goto L_8002BAF0; break;
        case 12: goto L_8002BAF0; break;
        case 13: goto L_8002BB7C; break;
        case 14: goto L_8002BB7C; break;
        case 15: goto L_8002BB1C; break;
        case 16: goto L_8002BB7C; break;
        case 17: goto L_8002BB7C; break;
        case 18: goto L_8002BB7C; break;
        case 19: goto L_8002BB7C; break;
        case 20: goto L_8002BB7C; break;
        case 21: goto L_8002BB7C; break;
        case 22: goto L_8002BB7C; break;
        case 23: goto L_8002BB7C; break;
        case 24: goto L_8002BB7C; break;
        case 25: goto L_8002BB7C; break;
        case 26: goto L_8002BB7C; break;
        case 27: goto L_8002BB7C; break;
        case 28: goto L_8002BB7C; break;
        case 29: goto L_8002BAF0; break;
        case 30: goto L_8002BAF0; break;
        case 31: goto L_8002BB7C; break;
        case 32: goto L_8002BB1C; break;
        case 33: goto L_8002BB7C; break;
        case 34: goto L_8002BB7C; break;
        case 35: goto L_8002BB7C; break;
        case 36: goto L_8002BB7C; break;
        case 37: goto L_8002BAF0; break;
        case 38: goto L_8002BAF0; break;
        case 39: goto L_8002BB1C; break;
        case 40: goto L_8002BB7C; break;
        case 41: goto L_8002BB7C; break;
        case 42: goto L_8002BB7C; break;
        case 43: goto L_8002BB7C; break;
        case 44: goto L_8002BB7C; break;
        case 45: goto L_8002BB7C; break;
        case 46: goto L_8002BAF0; break;
        case 47: goto L_8002BAF0; break;
        case 48: goto L_8002BB1C; break;
        default: switch_error(__func__, 0x8002BAE8, 0x800AFEC0);
    }
    // 0x8002BAEC: nop

L_8002BAF0:
    // 0x8002BAF0: jal         0x8001D770
    // 0x8002BAF4: nop

    func_8001D770(rdram, ctx);
        goto after_5;
    // 0x8002BAF4: nop

    after_5:
    // 0x8002BAF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002BAFC: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002BB00: jal         0x80067BF8
    // 0x8002BB04: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_6;
    // 0x8002BB04: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x8002BB08: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8002BB0C: jal         0x80067818
    // 0x8002BB10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8002BB10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8002BB14: b           L_8002BB80
    // 0x8002BB18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8002BB80;
    // 0x8002BB18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002BB1C:
    // 0x8002BB1C: jal         0x8001D770
    // 0x8002BB20: nop

    func_8001D770(rdram, ctx);
        goto after_8;
    // 0x8002BB20: nop

    after_8:
    // 0x8002BB24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002BB28: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002BB2C: jal         0x80067BF8
    // 0x8002BB30: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_9;
    // 0x8002BB30: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_9:
    // 0x8002BB34: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    // 0x8002BB38: jal         0x80067818
    // 0x8002BB3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x8002BB3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x8002BB40: b           L_8002BB80
    // 0x8002BB44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8002BB80;
    // 0x8002BB44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002BB48:
    // 0x8002BB48: jal         0x8001D770
    // 0x8002BB4C: nop

    func_8001D770(rdram, ctx);
        goto after_11;
    // 0x8002BB4C: nop

    after_11:
    // 0x8002BB50: jal         0x8001D840
    // 0x8002BB54: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8001D840(rdram, ctx);
        goto after_12;
    // 0x8002BB54: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_12:
    // 0x8002BB58: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002BB5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002BB60: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8002BB64: jal         0x80067D94
    // 0x8002BB68: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067D94(rdram, ctx);
        goto after_13;
    // 0x8002BB68: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_13:
    // 0x8002BB6C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002BB70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002BB74: jal         0x80067838
    // 0x8002BB78: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_14;
    // 0x8002BB78: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_14:
L_8002BB7C:
    // 0x8002BB7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002BB80:
    // 0x8002BB80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002BB84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8002BB88: jr          $ra
    // 0x8002BB8C: nop

    return;
    // 0x8002BB8C: nop

;}
RECOMP_FUNC void func_8043E2D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E2D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043E2D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043E2D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043E2DC: jal         0x8043DCF4
    // 0x8043E2E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8043DCF4(rdram, ctx);
        goto after_0;
    // 0x8043E2E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8043E2E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8043E2E8: bne         $v0, $at, L_8043E2FC
    if (ctx->r2 != ctx->r1) {
        // 0x8043E2EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8043E2FC;
    }
    // 0x8043E2EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043E2F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8043E2F4: jal         0x8043E490
    // 0x8043E2F8: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    func_8043E490(rdram, ctx);
        goto after_1;
    // 0x8043E2F8: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_1:
L_8043E2FC:
    // 0x8043E2FC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8043E300: jal         0x80048F84
    // 0x8043E304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8043E304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8043E308: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8043E30C: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8043E310: jal         0x80065ABC
    // 0x8043E314: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_3;
    // 0x8043E314: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_3:
    // 0x8043E318: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8043E31C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043E320: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043E324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043E328: jr          $ra
    // 0x8043E32C: nop

    return;
    // 0x8043E32C: nop

;}
RECOMP_FUNC void func_80532DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532DFC: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80532E00: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80532E04: beq         $v0, $zero, L_80532F10
    if (ctx->r2 == 0) {
        // 0x80532E08: nop
    
            goto L_80532F10;
    }
    // 0x80532E08: nop

    // 0x80532E0C: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80532E10: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80532E14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80532E18: addiu       $t0, $v1, 0x10
    ctx->r8 = ADD32(ctx->r3, 0X10);
L_80532E1C:
    // 0x80532E1C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80532E20: bnel        $a0, $t6, L_80532E94
    if (ctx->r4 != ctx->r14) {
        // 0x80532E24: lw          $t1, 0x4($t0)
        ctx->r9 = MEM_W(ctx->r8, 0X4);
            goto L_80532E94;
    }
    goto skip_0;
    // 0x80532E24: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    skip_0:
    // 0x80532E28: beq         $a3, $zero, L_80532F10
    if (ctx->r7 == 0) {
        // 0x80532E2C: sw          $zero, 0x0($t0)
        MEM_W(0X0, ctx->r8) = 0;
            goto L_80532F10;
    }
    // 0x80532E2C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80532E30: lhu         $t7, 0xC($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0XC);
    // 0x80532E34: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80532E38: bnel        $t7, $at, L_80532E6C
    if (ctx->r15 != ctx->r1) {
        // 0x80532E3C: lw          $v0, 0x1F4($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X1F4);
            goto L_80532E6C;
    }
    goto skip_1;
    // 0x80532E3C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    skip_1:
    // 0x80532E40: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80532E44: addu        $a1, $v1, $a2
    ctx->r5 = ADD32(ctx->r3, ctx->r6);
    // 0x80532E48: sw          $a3, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r7;
    // 0x80532E4C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80532E50: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80532E54: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80532E58: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x80532E5C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80532E60: jr          $ra
    // 0x80532E64: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    return;
    // 0x80532E64: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    // 0x80532E68: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
L_80532E6C:
    // 0x80532E6C: addu        $a1, $v1, $a2
    ctx->r5 = ADD32(ctx->r3, ctx->r6);
    // 0x80532E70: sw          $a3, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r7;
    // 0x80532E74: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x80532E78: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80532E7C: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80532E80: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x80532E84: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80532E88: jr          $ra
    // 0x80532E8C: swc1        $f10, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f10.u32l;
    return;
    // 0x80532E8C: swc1        $f10, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f10.u32l;
    // 0x80532E90: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
L_80532E94:
    // 0x80532E94: bnel        $a0, $t1, L_80532F08
    if (ctx->r4 != ctx->r9) {
        // 0x80532E98: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80532F08;
    }
    goto skip_2;
    // 0x80532E98: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_2:
    // 0x80532E9C: beq         $a3, $zero, L_80532F10
    if (ctx->r7 == 0) {
        // 0x80532EA0: sw          $zero, 0x4($t0)
        MEM_W(0X4, ctx->r8) = 0;
            goto L_80532F10;
    }
    // 0x80532EA0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80532EA4: lhu         $t2, 0xC($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0XC);
    // 0x80532EA8: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80532EAC: bnel        $t2, $at, L_80532EE0
    if (ctx->r10 != ctx->r1) {
        // 0x80532EB0: lw          $v0, 0x1F4($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X1F4);
            goto L_80532EE0;
    }
    goto skip_3;
    // 0x80532EB0: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    skip_3:
    // 0x80532EB4: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80532EB8: addu        $a1, $v1, $a2
    ctx->r5 = ADD32(ctx->r3, ctx->r6);
    // 0x80532EBC: sw          $a3, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r7;
    // 0x80532EC0: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x80532EC4: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x80532EC8: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80532ECC: swc1        $f16, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
    // 0x80532ED0: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80532ED4: jr          $ra
    // 0x80532ED8: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    return;
    // 0x80532ED8: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x80532EDC: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
L_80532EE0:
    // 0x80532EE0: addu        $a1, $v1, $a2
    ctx->r5 = ADD32(ctx->r3, ctx->r6);
    // 0x80532EE4: sw          $a3, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r7;
    // 0x80532EE8: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x80532EEC: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x80532EF0: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80532EF4: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x80532EF8: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80532EFC: jr          $ra
    // 0x80532F00: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    return;
    // 0x80532F00: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    // 0x80532F04: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80532F08:
    // 0x80532F08: bne         $a2, $v0, L_80532E1C
    if (ctx->r6 != ctx->r2) {
        // 0x80532F0C: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80532E1C;
    }
    // 0x80532F0C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_80532F10:
    // 0x80532F10: jr          $ra
    // 0x80532F14: nop

    return;
    // 0x80532F14: nop

;}
RECOMP_FUNC void func_8064DCE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064DCE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064DCE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064DCE8: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8064DCEC: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x8064DCF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8064DCF4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8064DCF8: lw          $v1, 0x88($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X88);
    // 0x8064DCFC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8064DD00: nop

    // 0x8064DD04: sra         $v0, $v0, 4
    ctx->r2 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8064DD08: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8064DD0C: beql        $v0, $zero, L_8064DDE4
    if (ctx->r2 == 0) {
        // 0x8064DD10: lw          $t9, 0x174($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X174);
            goto L_8064DDE4;
    }
    goto skip_0;
    // 0x8064DD10: lw          $t9, 0x174($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X174);
    skip_0:
    // 0x8064DD14: beq         $v0, $at, L_8064DD3C
    if (ctx->r2 == ctx->r1) {
        // 0x8064DD18: addiu       $a1, $v1, 0x200
        ctx->r5 = ADD32(ctx->r3, 0X200);
            goto L_8064DD3C;
    }
    // 0x8064DD18: addiu       $a1, $v1, 0x200
    ctx->r5 = ADD32(ctx->r3, 0X200);
    // 0x8064DD1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8064DD20: beq         $v0, $at, L_8064DD74
    if (ctx->r2 == ctx->r1) {
        // 0x8064DD24: addiu       $a1, $v1, 0x400
        ctx->r5 = ADD32(ctx->r3, 0X400);
            goto L_8064DD74;
    }
    // 0x8064DD24: addiu       $a1, $v1, 0x400
    ctx->r5 = ADD32(ctx->r3, 0X400);
    // 0x8064DD28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8064DD2C: beq         $v0, $at, L_8064DDA8
    if (ctx->r2 == ctx->r1) {
        // 0x8064DD30: addiu       $a1, $v1, 0x600
        ctx->r5 = ADD32(ctx->r3, 0X600);
            goto L_8064DDA8;
    }
    // 0x8064DD30: addiu       $a1, $v1, 0x600
    ctx->r5 = ADD32(ctx->r3, 0X600);
    // 0x8064DD34: b           L_8064DE0C
    // 0x8064DD38: lhu         $t4, 0xC($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0XC);
        goto L_8064DE0C;
    // 0x8064DD38: lhu         $t4, 0xC($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0XC);
L_8064DD3C:
    // 0x8064DD3C: jal         0x8004590C
    // 0x8064DD40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x8064DD40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064DD44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064DD48: addiu       $t8, $zero, 0x2242
    ctx->r24 = ADD32(0, 0X2242);
    // 0x8064DD4C: addiu       $t1, $zero, 0x2244
    ctx->r9 = ADD32(0, 0X2244);
    // 0x8064DD50: lw          $t9, 0x174($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X174);
    // 0x8064DD54: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8064DD58: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064DD5C: sh          $t8, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r24;
    // 0x8064DD60: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x8064DD64: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8064DD68: sh          $t1, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r9;
    // 0x8064DD6C: b           L_8064DE08
    // 0x8064DD70: sw          $t4, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->r12;
        goto L_8064DE08;
    // 0x8064DD70: sw          $t4, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->r12;
L_8064DD74:
    // 0x8064DD74: jal         0x8004590C
    // 0x8064DD78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x8064DD78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8064DD7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064DD80: addiu       $t5, $zero, 0x4222
    ctx->r13 = ADD32(0, 0X4222);
    // 0x8064DD84: addiu       $t9, $zero, 0x2244
    ctx->r25 = ADD32(0, 0X2244);
    // 0x8064DD88: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8064DD8C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8064DD90: sh          $t5, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r13;
    // 0x8064DD94: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x8064DD98: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8064DD9C: sh          $t9, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r25;
    // 0x8064DDA0: b           L_8064DE08
    // 0x8064DDA4: sw          $zero, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = 0;
        goto L_8064DE08;
    // 0x8064DDA4: sw          $zero, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = 0;
L_8064DDA8:
    // 0x8064DDA8: jal         0x8004590C
    // 0x8064DDAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004590C(rdram, ctx);
        goto after_2;
    // 0x8064DDAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8064DDB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064DDB4: addiu       $t2, $zero, 0x2224
    ctx->r10 = ADD32(0, 0X2224);
    // 0x8064DDB8: addiu       $t4, $zero, 0x4244
    ctx->r12 = ADD32(0, 0X4244);
    // 0x8064DDBC: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x8064DDC0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8064DDC4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8064DDC8: sh          $t2, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r10;
    // 0x8064DDCC: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8064DDD0: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x8064DDD4: sh          $t4, 0x1A($t5)
    MEM_H(0X1A, ctx->r13) = ctx->r12;
    // 0x8064DDD8: b           L_8064DE08
    // 0x8064DDDC: sw          $t7, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->r15;
        goto L_8064DE08;
    // 0x8064DDDC: sw          $t7, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->r15;
    // 0x8064DDE0: lw          $t9, 0x174($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X174);
L_8064DDE4:
    // 0x8064DDE4: addiu       $t8, $zero, 0x2422
    ctx->r24 = ADD32(0, 0X2422);
    // 0x8064DDE8: addiu       $t1, $zero, 0x2444
    ctx->r9 = ADD32(0, 0X2444);
    // 0x8064DDEC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064DDF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8064DDF4: sh          $t8, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r24;
    // 0x8064DDF8: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x8064DDFC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8064DE00: sh          $t1, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r9;
    // 0x8064DE04: sw          $t6, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->r14;
L_8064DE08:
    // 0x8064DE08: lhu         $t4, 0xC($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0XC);
L_8064DE0C:
    // 0x8064DE0C: addiu       $t5, $t4, -0x4547
    ctx->r13 = ADD32(ctx->r12, -0X4547);
    // 0x8064DE10: sltiu       $at, $t5, 0x8
    ctx->r1 = ctx->r13 < 0X8 ? 1 : 0;
    // 0x8064DE14: beq         $at, $zero, L_8064DEAC
    if (ctx->r1 == 0) {
        // 0x8064DE18: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8064DEAC;
    }
    // 0x8064DE18: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8064DE1C: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(498, 0XBC0) << 16);
    // 0x8064DE20: addu        $at, $at, $t5
    gpr jr_addend_8064DE28 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8064DE24: lw          $t5, -0x1770($at)
    ctx->r13 = ADD32(ctx->r1, (int16_t)RELOC_LO16(498, 0XBC0));
    // 0x8064DE28: jr          $t5
    // 0x8064DE2C: nop

    switch (jr_addend_8064DE28 >> 2) {
        case 0: goto L_8064DE30; break;
        case 1: goto L_8064DE40; break;
        case 2: goto L_8064DE50; break;
        case 3: goto L_8064DE60; break;
        case 4: goto L_8064DE70; break;
        case 5: goto L_8064DE80; break;
        case 6: goto L_8064DE90; break;
        case 7: goto L_8064DEA0; break;
        default: switch_error(__func__, 0x8064DE28, 0x8064E890);
    }
    // 0x8064DE2C: nop

L_8064DE30:
    // 0x8064DE30: jal         0x8064DEFC
    // 0x8064DE34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8064DEFC(rdram, ctx);
        goto after_3;
    // 0x8064DE34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8064DE38: b           L_8064DEB0
    // 0x8064DE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8064DEB0;
    // 0x8064DE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064DE40:
    // 0x8064DE40: jal         0x8064DEFC
    // 0x8064DE44: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    func_8064DEFC(rdram, ctx);
        goto after_4;
    // 0x8064DE44: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    after_4:
    // 0x8064DE48: b           L_8064DEB0
    // 0x8064DE4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8064DEB0;
    // 0x8064DE4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064DE50:
    // 0x8064DE50: jal         0x8064DEFC
    // 0x8064DE54: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    func_8064DEFC(rdram, ctx);
        goto after_5;
    // 0x8064DE54: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    after_5:
    // 0x8064DE58: b           L_8064DEB0
    // 0x8064DE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8064DEB0;
    // 0x8064DE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064DE60:
    // 0x8064DE60: jal         0x8064DEFC
    // 0x8064DE64: lui         $a1, 0x4307
    ctx->r5 = S32(0X4307 << 16);
    func_8064DEFC(rdram, ctx);
        goto after_6;
    // 0x8064DE64: lui         $a1, 0x4307
    ctx->r5 = S32(0X4307 << 16);
    after_6:
    // 0x8064DE68: b           L_8064DEB0
    // 0x8064DE6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8064DEB0;
    // 0x8064DE6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064DE70:
    // 0x8064DE70: jal         0x8064DEFC
    // 0x8064DE74: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    func_8064DEFC(rdram, ctx);
        goto after_7;
    // 0x8064DE74: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    after_7:
    // 0x8064DE78: b           L_8064DEB0
    // 0x8064DE7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8064DEB0;
    // 0x8064DE7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064DE80:
    // 0x8064DE80: jal         0x8064DEFC
    // 0x8064DE84: lui         $a1, 0x4361
    ctx->r5 = S32(0X4361 << 16);
    func_8064DEFC(rdram, ctx);
        goto after_8;
    // 0x8064DE84: lui         $a1, 0x4361
    ctx->r5 = S32(0X4361 << 16);
    after_8:
    // 0x8064DE88: b           L_8064DEB0
    // 0x8064DE8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8064DEB0;
    // 0x8064DE8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064DE90:
    // 0x8064DE90: jal         0x8064DEFC
    // 0x8064DE94: lui         $a1, 0x4387
    ctx->r5 = S32(0X4387 << 16);
    func_8064DEFC(rdram, ctx);
        goto after_9;
    // 0x8064DE94: lui         $a1, 0x4387
    ctx->r5 = S32(0X4387 << 16);
    after_9:
    // 0x8064DE98: b           L_8064DEB0
    // 0x8064DE9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8064DEB0;
    // 0x8064DE9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064DEA0:
    // 0x8064DEA0: lui         $a1, 0x439D
    ctx->r5 = S32(0X439D << 16);
    // 0x8064DEA4: jal         0x8064DEFC
    // 0x8064DEA8: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    func_8064DEFC(rdram, ctx);
        goto after_10;
    // 0x8064DEA8: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    after_10:
L_8064DEAC:
    // 0x8064DEAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064DEB0:
    // 0x8064DEB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064DEB4: jr          $ra
    // 0x8064DEB8: nop

    return;
    // 0x8064DEB8: nop

;}
RECOMP_FUNC void func_80474FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474FD0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474FD4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474FD8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474FDC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474FE0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474FE4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474FE8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474FEC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474FF0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474FF4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474FF8: jr          $ra
    // 0x80474FFC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474FFC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804210C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804210C0: lui         $v0, 0x8042
    ctx->r2 = S32(RELOC_HI16(32, 0X10) << 16);
    // 0x804210C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804210C8: jr          $ra
    // 0x804210CC: addiu       $v0, $v0, 0x10D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(32, 0X10));
    return;
    // 0x804210CC: addiu       $v0, $v0, 0x10D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(32, 0X10));
;}
RECOMP_FUNC void func_806AB410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB410: jr          $ra
    // 0x806AB414: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806AB414: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8069D820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D820: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8069D824: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069D828: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8069D82C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8069D830: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8069D834: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(574, 0XD78) << 16);
    // 0x8069D838: lwc1        $f2, -0x1D08($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(574, 0XD78));
    // 0x8069D83C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8069D840: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8069D844: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(574, 0XD7C) << 16);
    // 0x8069D848: lwc1        $f10, -0x1D04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(574, 0XD7C));
    // 0x8069D84C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8069D850: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8069D854: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8069D858: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8069D85C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8069D860: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8069D864: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8069D868: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8069D86C: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x8069D870: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8069D874: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8069D878: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8069D87C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8069D880: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8069D884: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069D888: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8069D88C: lw          $t9, 0x28($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X28);
    // 0x8069D890: jalr        $t9
    // 0x8069D894: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8069D894: nop

    after_0:
    // 0x8069D898: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8069D89C: jal         0x80067BBC
    // 0x8069D8A0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8069D8A0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8069D8A4: addiu       $a0, $zero, 0x277
    ctx->r4 = ADD32(0, 0X277);
    // 0x8069D8A8: jal         0x80067818
    // 0x8069D8AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8069D8AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8069D8B0: jal         0x800447C8
    // 0x8069D8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x8069D8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8069D8B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8069D8BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069D8C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8069D8C4: jr          $ra
    // 0x8069D8C8: nop

    return;
    // 0x8069D8C8: nop

;}
RECOMP_FUNC void Fault_PrintThreadContext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FC04: lui         $t9, 0xFFFA
    ctx->r25 = S32(0XFFFA << 16);
    // 0x8006FC08: or          $t0, $sp, $zero
    ctx->r8 = ctx->r29 | 0;
    // 0x8006FC0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006FC10: ori         $t9, $t9, 0x5A5A
    ctx->r25 = ctx->r25 | 0X5A5A;
L_8006FC14:
    // 0x8006FC14: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x8006FC18: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8006FC1C: bne         $t0, $sp, L_8006FC14
    if (ctx->r8 != ctx->r29) {
        // 0x8006FC20: sw          $t9, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->r25;
            goto L_8006FC14;
    }
    // 0x8006FC20: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8006FC24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006FC28: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8006FC2C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8006FC30: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006FC34: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006FC38: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8006FC3C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8006FC40: lw          $s1, 0x120($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X120);
    // 0x8006FC44: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8006FC48: addiu       $a2, $zero, 0x114
    ctx->r6 = ADD32(0, 0X114);
    // 0x8006FC4C: srl         $s1, $s1, 2
    ctx->r17 = S32(U32(ctx->r17) >> 2);
    // 0x8006FC50: andi        $s1, $s1, 0x1F
    ctx->r17 = ctx->r17 & 0X1F;
    // 0x8006FC54: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x8006FC58: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8006FC5C: bnel        $s1, $at, L_8006FC6C
    if (ctx->r17 != ctx->r1) {
        // 0x8006FC60: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_8006FC6C;
    }
    goto skip_0;
    // 0x8006FC60: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    skip_0:
    // 0x8006FC64: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // 0x8006FC68: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
L_8006FC6C:
    // 0x8006FC6C: bne         $s1, $at, L_8006FC78
    if (ctx->r17 != ctx->r1) {
        // 0x8006FC70: nop
    
            goto L_8006FC78;
    }
    // 0x8006FC70: nop

    // 0x8006FC74: addiu       $s1, $zero, 0x11
    ctx->r17 = ADD32(0, 0X11);
L_8006FC78:
    // 0x8006FC78: jal         0x8006F600
    // 0x8006FC7C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    Fault_DrawRec(rdram, ctx);
        goto after_0;
    // 0x8006FC7C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    after_0:
    // 0x8006FC80: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8006FC84: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8006FC88: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x8006FC8C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006FC90: lw          $t9, -0x7BF4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7BF4);
    // 0x8006FC94: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FC98: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    // 0x8006FC9C: addiu       $a2, $a2, 0x140C
    ctx->r6 = ADD32(ctx->r6, 0X140C);
    // 0x8006FCA0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FCA4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8006FCA8: jal         0x8006F884
    // 0x8006FCAC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Fault_Printf(rdram, ctx);
        goto after_1;
    // 0x8006FCAC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x8006FCB0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8006FCB4: addiu       $s0, $zero, 0x1D
    ctx->r16 = ADD32(0, 0X1D);
    // 0x8006FCB8: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FCBC: lw          $t0, 0x118($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X118);
    // 0x8006FCC0: lw          $a3, 0x11C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X11C);
    // 0x8006FCC4: addiu       $a2, $a2, 0x141C
    ctx->r6 = ADD32(ctx->r6, 0X141C);
    // 0x8006FCC8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8006FCCC: lw          $t1, 0x124($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X124);
    // 0x8006FCD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FCD4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FCD8: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8006FCDC: jal         0x8006F884
    // 0x8006FCE0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    Fault_Printf(rdram, ctx);
        goto after_2;
    // 0x8006FCE0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_2:
    // 0x8006FCE4: addiu       $s0, $s0, 0xD
    ctx->r16 = ADD32(ctx->r16, 0XD);
    // 0x8006FCE8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8006FCEC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8006FCF0: addiu       $a2, $zero, 0x114
    ctx->r6 = ADD32(0, 0X114);
    // 0x8006FCF4: jal         0x8006F600
    // 0x8006FCF8: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    Fault_DrawRec(rdram, ctx);
        goto after_3;
    // 0x8006FCF8: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_3:
    // 0x8006FCFC: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    // 0x8006FD00: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x8006FD04: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FD08: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8006FD0C: lw          $t9, 0x14($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X14);
    // 0x8006FD10: addiu       $a2, $a2, 0x143C
    ctx->r6 = ADD32(ctx->r6, 0X143C);
    // 0x8006FD14: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FD18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FD1C: jal         0x8006F884
    // 0x8006FD20: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    Fault_Printf(rdram, ctx);
        goto after_4;
    // 0x8006FD20: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_4:
    // 0x8006FD24: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x8006FD28: lw          $a3, 0x1C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1C);
    // 0x8006FD2C: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FD30: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8006FD34: lw          $t7, 0x2C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X2C);
    // 0x8006FD38: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FD3C: addiu       $a2, $a2, 0x145C
    ctx->r6 = ADD32(ctx->r6, 0X145C);
    // 0x8006FD40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FD44: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FD48: jal         0x8006F884
    // 0x8006FD4C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Fault_Printf(rdram, ctx);
        goto after_5;
    // 0x8006FD4C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_5:
    // 0x8006FD50: lw          $t1, 0x3C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X3C);
    // 0x8006FD54: lw          $a3, 0x34($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X34);
    // 0x8006FD58: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FD5C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8006FD60: lw          $t5, 0x44($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X44);
    // 0x8006FD64: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FD68: addiu       $a2, $a2, 0x147C
    ctx->r6 = ADD32(ctx->r6, 0X147C);
    // 0x8006FD6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FD70: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FD74: jal         0x8006F884
    // 0x8006FD78: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    Fault_Printf(rdram, ctx);
        goto after_6;
    // 0x8006FD78: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_6:
    // 0x8006FD7C: lw          $t9, 0x54($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X54);
    // 0x8006FD80: lw          $a3, 0x4C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4C);
    // 0x8006FD84: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FD88: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8006FD8C: lw          $t3, 0x5C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X5C);
    // 0x8006FD90: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FD94: addiu       $a2, $a2, 0x149C
    ctx->r6 = ADD32(ctx->r6, 0X149C);
    // 0x8006FD98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FD9C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FDA0: jal         0x8006F884
    // 0x8006FDA4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    Fault_Printf(rdram, ctx);
        goto after_7;
    // 0x8006FDA4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_7:
    // 0x8006FDA8: lw          $t7, 0x6C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X6C);
    // 0x8006FDAC: lw          $a3, 0x64($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X64);
    // 0x8006FDB0: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FDB4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006FDB8: lw          $t1, 0x74($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X74);
    // 0x8006FDBC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FDC0: addiu       $a2, $a2, 0x14BC
    ctx->r6 = ADD32(ctx->r6, 0X14BC);
    // 0x8006FDC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FDC8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FDCC: jal         0x8006F884
    // 0x8006FDD0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    Fault_Printf(rdram, ctx);
        goto after_8;
    // 0x8006FDD0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_8:
    // 0x8006FDD4: lw          $t5, 0x84($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X84);
    // 0x8006FDD8: lw          $a3, 0x7C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X7C);
    // 0x8006FDDC: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FDE0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8006FDE4: lw          $t9, 0x8C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8C);
    // 0x8006FDE8: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FDEC: addiu       $a2, $a2, 0x14DC
    ctx->r6 = ADD32(ctx->r6, 0X14DC);
    // 0x8006FDF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FDF4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FDF8: jal         0x8006F884
    // 0x8006FDFC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    Fault_Printf(rdram, ctx);
        goto after_9;
    // 0x8006FDFC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_9:
    // 0x8006FE00: lw          $t3, 0x9C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X9C);
    // 0x8006FE04: lw          $a3, 0x94($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X94);
    // 0x8006FE08: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FE0C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8006FE10: lw          $t7, 0xA4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XA4);
    // 0x8006FE14: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FE18: addiu       $a2, $a2, 0x14FC
    ctx->r6 = ADD32(ctx->r6, 0X14FC);
    // 0x8006FE1C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FE20: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FE24: jal         0x8006F884
    // 0x8006FE28: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Fault_Printf(rdram, ctx);
        goto after_10;
    // 0x8006FE28: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_10:
    // 0x8006FE2C: lw          $t1, 0xB4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XB4);
    // 0x8006FE30: lw          $a3, 0xAC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XAC);
    // 0x8006FE34: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FE38: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8006FE3C: lw          $t5, 0xBC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XBC);
    // 0x8006FE40: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FE44: addiu       $a2, $a2, 0x151C
    ctx->r6 = ADD32(ctx->r6, 0X151C);
    // 0x8006FE48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FE4C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FE50: jal         0x8006F884
    // 0x8006FE54: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    Fault_Printf(rdram, ctx);
        goto after_11;
    // 0x8006FE54: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_11:
    // 0x8006FE58: lw          $t9, 0xCC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XCC);
    // 0x8006FE5C: lw          $a3, 0xC4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC4);
    // 0x8006FE60: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FE64: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8006FE68: lw          $t3, 0xD4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XD4);
    // 0x8006FE6C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FE70: addiu       $a2, $a2, 0x153C
    ctx->r6 = ADD32(ctx->r6, 0X153C);
    // 0x8006FE74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FE78: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FE7C: jal         0x8006F884
    // 0x8006FE80: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    Fault_Printf(rdram, ctx);
        goto after_12;
    // 0x8006FE80: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_12:
    // 0x8006FE84: lw          $t7, 0xE4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XE4);
    // 0x8006FE88: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FE8C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FE90: lw          $a3, 0xDC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XDC);
    // 0x8006FE94: addiu       $a2, $a2, 0x155C
    ctx->r6 = ADD32(ctx->r6, 0X155C);
    // 0x8006FE98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FE9C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FEA0: jal         0x8006F884
    // 0x8006FEA4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Fault_Printf(rdram, ctx);
        goto after_13;
    // 0x8006FEA4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_13:
    // 0x8006FEA8: addiu       $s0, $s0, 0xD
    ctx->r16 = ADD32(ctx->r16, 0XD);
    // 0x8006FEAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FEB0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FEB4: jal         0x8006FAB4
    // 0x8006FEB8: lw          $a2, 0x10C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10C);
    Fault_PrintFPCSR(rdram, ctx);
        goto after_14;
    // 0x8006FEB8: lw          $a2, 0x10C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10C);
    after_14:
    // 0x8006FEBC: addiu       $s0, $s0, 0xD
    ctx->r16 = ADD32(ctx->r16, 0XD);
    // 0x8006FEC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FEC4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FEC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006FECC: jal         0x8006F964
    // 0x8006FED0: addiu       $a3, $s1, 0x114
    ctx->r7 = ADD32(ctx->r17, 0X114);
    Fault_PrintFReg(rdram, ctx);
        goto after_15;
    // 0x8006FED0: addiu       $a3, $s1, 0x114
    ctx->r7 = ADD32(ctx->r17, 0X114);
    after_15:
    // 0x8006FED4: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x8006FED8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FEDC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8006FEE0: jal         0x8006F964
    // 0x8006FEE4: addiu       $a3, $s1, 0x11C
    ctx->r7 = ADD32(ctx->r17, 0X11C);
    Fault_PrintFReg(rdram, ctx);
        goto after_16;
    // 0x8006FEE4: addiu       $a3, $s1, 0x11C
    ctx->r7 = ADD32(ctx->r17, 0X11C);
    after_16:
    // 0x8006FEE8: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FEEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FEF0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FEF4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8006FEF8: jal         0x8006F964
    // 0x8006FEFC: addiu       $a3, $s1, 0x124
    ctx->r7 = ADD32(ctx->r17, 0X124);
    Fault_PrintFReg(rdram, ctx);
        goto after_17;
    // 0x8006FEFC: addiu       $a3, $s1, 0x124
    ctx->r7 = ADD32(ctx->r17, 0X124);
    after_17:
    // 0x8006FF00: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x8006FF04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FF08: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8006FF0C: jal         0x8006F964
    // 0x8006FF10: addiu       $a3, $s1, 0x12C
    ctx->r7 = ADD32(ctx->r17, 0X12C);
    Fault_PrintFReg(rdram, ctx);
        goto after_18;
    // 0x8006FF10: addiu       $a3, $s1, 0x12C
    ctx->r7 = ADD32(ctx->r17, 0X12C);
    after_18:
    // 0x8006FF14: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FF18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FF1C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FF20: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8006FF24: jal         0x8006F964
    // 0x8006FF28: addiu       $a3, $s1, 0x134
    ctx->r7 = ADD32(ctx->r17, 0X134);
    Fault_PrintFReg(rdram, ctx);
        goto after_19;
    // 0x8006FF28: addiu       $a3, $s1, 0x134
    ctx->r7 = ADD32(ctx->r17, 0X134);
    after_19:
    // 0x8006FF2C: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x8006FF30: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FF34: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8006FF38: jal         0x8006F964
    // 0x8006FF3C: addiu       $a3, $s1, 0x13C
    ctx->r7 = ADD32(ctx->r17, 0X13C);
    Fault_PrintFReg(rdram, ctx);
        goto after_20;
    // 0x8006FF3C: addiu       $a3, $s1, 0x13C
    ctx->r7 = ADD32(ctx->r17, 0X13C);
    after_20:
    // 0x8006FF40: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FF44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FF48: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FF4C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8006FF50: jal         0x8006F964
    // 0x8006FF54: addiu       $a3, $s1, 0x144
    ctx->r7 = ADD32(ctx->r17, 0X144);
    Fault_PrintFReg(rdram, ctx);
        goto after_21;
    // 0x8006FF54: addiu       $a3, $s1, 0x144
    ctx->r7 = ADD32(ctx->r17, 0X144);
    after_21:
    // 0x8006FF58: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x8006FF5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FF60: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8006FF64: jal         0x8006F964
    // 0x8006FF68: addiu       $a3, $s1, 0x14C
    ctx->r7 = ADD32(ctx->r17, 0X14C);
    Fault_PrintFReg(rdram, ctx);
        goto after_22;
    // 0x8006FF68: addiu       $a3, $s1, 0x14C
    ctx->r7 = ADD32(ctx->r17, 0X14C);
    after_22:
    // 0x8006FF6C: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FF70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FF74: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FF78: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8006FF7C: jal         0x8006F964
    // 0x8006FF80: addiu       $a3, $s1, 0x154
    ctx->r7 = ADD32(ctx->r17, 0X154);
    Fault_PrintFReg(rdram, ctx);
        goto after_23;
    // 0x8006FF80: addiu       $a3, $s1, 0x154
    ctx->r7 = ADD32(ctx->r17, 0X154);
    after_23:
    // 0x8006FF84: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x8006FF88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FF8C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x8006FF90: jal         0x8006F964
    // 0x8006FF94: addiu       $a3, $s1, 0x15C
    ctx->r7 = ADD32(ctx->r17, 0X15C);
    Fault_PrintFReg(rdram, ctx);
        goto after_24;
    // 0x8006FF94: addiu       $a3, $s1, 0x15C
    ctx->r7 = ADD32(ctx->r17, 0X15C);
    after_24:
    // 0x8006FF98: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FF9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FFA0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FFA4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8006FFA8: jal         0x8006F964
    // 0x8006FFAC: addiu       $a3, $s1, 0x164
    ctx->r7 = ADD32(ctx->r17, 0X164);
    Fault_PrintFReg(rdram, ctx);
        goto after_25;
    // 0x8006FFAC: addiu       $a3, $s1, 0x164
    ctx->r7 = ADD32(ctx->r17, 0X164);
    after_25:
    // 0x8006FFB0: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x8006FFB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FFB8: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x8006FFBC: jal         0x8006F964
    // 0x8006FFC0: addiu       $a3, $s1, 0x16C
    ctx->r7 = ADD32(ctx->r17, 0X16C);
    Fault_PrintFReg(rdram, ctx);
        goto after_26;
    // 0x8006FFC0: addiu       $a3, $s1, 0x16C
    ctx->r7 = ADD32(ctx->r17, 0X16C);
    after_26:
    // 0x8006FFC4: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FFC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FFCC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FFD0: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8006FFD4: jal         0x8006F964
    // 0x8006FFD8: addiu       $a3, $s1, 0x174
    ctx->r7 = ADD32(ctx->r17, 0X174);
    Fault_PrintFReg(rdram, ctx);
        goto after_27;
    // 0x8006FFD8: addiu       $a3, $s1, 0x174
    ctx->r7 = ADD32(ctx->r17, 0X174);
    after_27:
    // 0x8006FFDC: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x8006FFE0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FFE4: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x8006FFE8: jal         0x8006F964
    // 0x8006FFEC: addiu       $a3, $s1, 0x17C
    ctx->r7 = ADD32(ctx->r17, 0X17C);
    Fault_PrintFReg(rdram, ctx);
        goto after_28;
    // 0x8006FFEC: addiu       $a3, $s1, 0x17C
    ctx->r7 = ADD32(ctx->r17, 0X17C);
    after_28:
    // 0x8006FFF0: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x8006FFF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006FFF8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8006FFFC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80070000: jal         0x8006F964
    // 0x80070004: addiu       $a3, $s1, 0x184
    ctx->r7 = ADD32(ctx->r17, 0X184);
    Fault_PrintFReg(rdram, ctx);
        goto after_29;
    // 0x80070004: addiu       $a3, $s1, 0x184
    ctx->r7 = ADD32(ctx->r17, 0X184);
    after_29:
    // 0x80070008: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x8007000C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80070010: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80070014: jal         0x8006F964
    // 0x80070018: addiu       $a3, $s1, 0x18C
    ctx->r7 = ADD32(ctx->r17, 0X18C);
    Fault_PrintFReg(rdram, ctx);
        goto after_30;
    // 0x80070018: addiu       $a3, $s1, 0x18C
    ctx->r7 = ADD32(ctx->r17, 0X18C);
    after_30:
    // 0x8007001C: jal         0x80090710
    // 0x80070020: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_31;
    // 0x80070020: nop

    after_31:
    // 0x80070024: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80070028: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8007002C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80070030: jr          $ra
    // 0x80070034: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80070034: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80041450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041450: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80041454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041458: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8004145C: lw          $t6, 0x12D0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X12D0);
    // 0x80041460: beql        $t6, $zero, L_800415C4
    if (ctx->r14 == 0) {
        // 0x80041464: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800415C4;
    }
    goto skip_0;
    // 0x80041464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80041468: lwc1        $f2, 0x12D8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X12D8);
    // 0x8004146C: lwc1        $f0, 0x12DC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X12DC);
    // 0x80041470: lwc1        $f12, 0x12D4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X12D4);
    // 0x80041474: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80041478: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8004147C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80041480: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80041484: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80041488: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8004148C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80041490: nop

    // 0x80041494: bc1fl       L_800414A8
    if (!c1cs) {
        // 0x80041498: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_800414A8;
    }
    goto skip_1;
    // 0x80041498: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_1:
    // 0x8004149C: b           L_800414C0
    // 0x800414A0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_800414C0;
    // 0x800414A0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800414A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_800414A8:
    // 0x800414A8: nop

    // 0x800414AC: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x800414B0: nop

    // 0x800414B4: bc1fl       L_800414C4
    if (!c1cs) {
        // 0x800414B8: c.lt.s      $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
            goto L_800414C4;
    }
    goto skip_2;
    // 0x800414B8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    skip_2:
    // 0x800414BC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_800414C0:
    // 0x800414C0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
L_800414C4:
    // 0x800414C4: nop

    // 0x800414C8: bc1fl       L_80041508
    if (!c1cs) {
        // 0x800414CC: c.lt.s      $f18, $f12
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
            goto L_80041508;
    }
    goto skip_3;
    // 0x800414CC: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    skip_3:
    // 0x800414D0: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x800414D4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800414D8: bc1fl       L_80041530
    if (!c1cs) {
        // 0x800414DC: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_80041530;
    }
    goto skip_4;
    // 0x800414DC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_4:
    // 0x800414E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800414E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800414E8: swc1        $f4, 0x12DC($v1)
    MEM_W(0X12DC, ctx->r3) = ctx->f4.u32l;
    // 0x800414EC: lwc1        $f6, 0x2F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2F8);
    // 0x800414F0: sw          $zero, 0x12E0($v1)
    MEM_W(0X12E0, ctx->r3) = 0;
    // 0x800414F4: sw          $zero, 0x12D0($v1)
    MEM_W(0X12D0, ctx->r3) = 0;
    // 0x800414F8: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800414FC: b           L_80041530
    // 0x80041500: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
        goto L_80041530;
    // 0x80041500: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80041504: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
L_80041508:
    // 0x80041508: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8004150C: bc1fl       L_80041530
    if (!c1cs) {
        // 0x80041510: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_80041530;
    }
    goto skip_5;
    // 0x80041510: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_5:
    // 0x80041514: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80041518: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004151C: swc1        $f8, 0x12DC($v1)
    MEM_W(0X12DC, ctx->r3) = ctx->f8.u32l;
    // 0x80041520: lwc1        $f10, 0x2FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2FC);
    // 0x80041524: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80041528: nop

    // 0x8004152C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_80041530:
    // 0x80041530: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80041534: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80041538: jal         0x80066DE4
    // 0x8004153C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8004153C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80041540: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80041544: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80041548: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004154C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80041550: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x80041554: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80041558: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004155C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80041560: bc1f        L_8004156C
    if (!c1cs) {
        // 0x80041564: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004156C;
    }
    // 0x80041564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80041568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004156C:
    // 0x8004156C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80041570: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80041574: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80041578: lwc1        $f6, -0xAB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XAB4);
    // 0x8004157C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80041580: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80041584: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80041588: lwc1        $f10, -0xAAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XAAC);
    // 0x8004158C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041590: swc1        $f2, 0x12D8($v1)
    MEM_W(0X12D8, ctx->r3) = ctx->f2.u32l;
    // 0x80041594: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80041598: swc1        $f12, 0x12D4($v1)
    MEM_W(0X12D4, ctx->r3) = ctx->f12.u32l;
    // 0x8004159C: lw          $a1, 0x12D0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X12D0);
    // 0x800415A0: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800415A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800415A8: nop

    // 0x800415AC: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800415B0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800415B4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800415B8: jal         0x800491B8
    // 0x800415BC: nop

    func_800491B8(rdram, ctx);
        goto after_1;
    // 0x800415BC: nop

    after_1:
    // 0x800415C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800415C4:
    // 0x800415C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800415C8: jr          $ra
    // 0x800415CC: nop

    return;
    // 0x800415CC: nop

;}
RECOMP_FUNC void func_80046F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046F1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80046F20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046F24: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80046F28: addiu       $a0, $a0, 0x6EF0
    ctx->r4 = ADD32(ctx->r4, 0X6EF0);
    // 0x80046F2C: jal         0x80046D2C
    // 0x80046F30: addiu       $a1, $sp, 0x1A
    ctx->r5 = ADD32(ctx->r29, 0X1A);
    func_80046D2C(rdram, ctx);
        goto after_0;
    // 0x80046F30: addiu       $a1, $sp, 0x1A
    ctx->r5 = ADD32(ctx->r29, 0X1A);
    after_0:
    // 0x80046F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046F38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046F3C: jr          $ra
    // 0x80046F40: nop

    return;
    // 0x80046F40: nop

;}
RECOMP_FUNC void func_80669DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80669DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80669DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80669DDC: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80669DE0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80669DE4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80669DE8: beq         $a1, $at, L_80669E28
    if (ctx->r5 == ctx->r1) {
        // 0x80669DEC: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_80669E28;
    }
    // 0x80669DEC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80669DF0: jal         0x80067930
    // 0x80669DF4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80669DF4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80669DF8: bne         $v0, $zero, L_80669E28
    if (ctx->r2 != 0) {
        // 0x80669DFC: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80669E28;
    }
    // 0x80669DFC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80669E00: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80669E04: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x80669E08: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80669E0C: jal         0x80067D5C
    // 0x80669E10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x80669E10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80669E14: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80669E18: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80669E1C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80669E20: jal         0x80067838
    // 0x80669E24: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    func_80067838(rdram, ctx);
        goto after_2;
    // 0x80669E24: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    after_2:
L_80669E28:
    // 0x80669E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80669E2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80669E30: jr          $ra
    // 0x80669E34: nop

    return;
    // 0x80669E34: nop

;}
RECOMP_FUNC void func_80453DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453DC4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80453DC8: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x80453DCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453DD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453DD4: lb          $v0, 0x3($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X3);
    // 0x80453DD8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80453DDC: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80453DE0: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80453DE4: bne         $at, $zero, L_80453E3C
    if (ctx->r1 != 0) {
        // 0x80453DE8: addu        $t7, $t7, $v1
        ctx->r15 = ADD32(ctx->r15, ctx->r3);
            goto L_80453E3C;
    }
    // 0x80453DE8: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80453DEC: lbu         $t7, 0x6C80($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X6C80);
    // 0x80453DF0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453DF4: ori         $at, $at, 0x6D10
    ctx->r1 = ctx->r1 | 0X6D10;
    // 0x80453DF8: beql        $t7, $zero, L_80453E40
    if (ctx->r15 == 0) {
        // 0x80453DFC: slti        $at, $v0, -0x5
        ctx->r1 = SIGNED(ctx->r2) < -0X5 ? 1 : 0;
            goto L_80453E40;
    }
    goto skip_0;
    // 0x80453DFC: slti        $at, $v0, -0x5
    ctx->r1 = SIGNED(ctx->r2) < -0X5 ? 1 : 0;
    skip_0:
    // 0x80453E00: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80453E04: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80453E08: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453E0C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80453E10: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80453E14: bgez        $t9, L_80453E24
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80453E18: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_80453E24;
    }
    // 0x80453E18: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80453E1C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80453E20: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_80453E24:
    // 0x80453E24: jal         0x80445C54
    // 0x80453E28: sb          $zero, 0x6C80($at)
    MEM_B(0X6C80, ctx->r1) = 0;
    func_80445C54(rdram, ctx);
        goto after_0;
    // 0x80453E28: sb          $zero, 0x6C80($at)
    MEM_B(0X6C80, ctx->r1) = 0;
    after_0:
    // 0x80453E2C: jal         0x804459C8
    // 0x80453E30: nop

    func_804459C8(rdram, ctx);
        goto after_1;
    // 0x80453E30: nop

    after_1:
    // 0x80453E34: b           L_80453EA4
    // 0x80453E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80453EA4;
    // 0x80453E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80453E3C:
    // 0x80453E3C: slti        $at, $v0, -0x5
    ctx->r1 = SIGNED(ctx->r2) < -0X5 ? 1 : 0;
L_80453E40:
    // 0x80453E40: beq         $at, $zero, L_80453E98
    if (ctx->r1 == 0) {
        // 0x80453E44: lui         $t2, 0x1
        ctx->r10 = S32(0X1 << 16);
            goto L_80453E98;
    }
    // 0x80453E44: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x80453E48: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80453E4C: lbu         $t2, 0x6C80($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X6C80);
    // 0x80453E50: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453E54: ori         $at, $at, 0x6D10
    ctx->r1 = ctx->r1 | 0X6D10;
    // 0x80453E58: beq         $t2, $zero, L_80453E98
    if (ctx->r10 == 0) {
        // 0x80453E5C: addu        $v0, $v1, $at
        ctx->r2 = ADD32(ctx->r3, ctx->r1);
            goto L_80453E98;
    }
    // 0x80453E5C: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80453E60: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80453E64: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80453E68: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x80453E6C: bne         $at, $zero, L_80453E78
    if (ctx->r1 != 0) {
        // 0x80453E70: sw          $t4, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r12;
            goto L_80453E78;
    }
    // 0x80453E70: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80453E74: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80453E78:
    // 0x80453E78: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453E7C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80453E80: jal         0x80445C54
    // 0x80453E84: sb          $zero, 0x6C80($at)
    MEM_B(0X6C80, ctx->r1) = 0;
    func_80445C54(rdram, ctx);
        goto after_2;
    // 0x80453E84: sb          $zero, 0x6C80($at)
    MEM_B(0X6C80, ctx->r1) = 0;
    after_2:
    // 0x80453E88: jal         0x804459C8
    // 0x80453E8C: nop

    func_804459C8(rdram, ctx);
        goto after_3;
    // 0x80453E8C: nop

    after_3:
    // 0x80453E90: b           L_80453EA4
    // 0x80453E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80453EA4;
    // 0x80453E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80453E98:
    // 0x80453E98: jal         0x8045043C
    // 0x80453E9C: nop

    func_8045043C(rdram, ctx);
        goto after_4;
    // 0x80453E9C: nop

    after_4:
    // 0x80453EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80453EA4:
    // 0x80453EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453EA8: jr          $ra
    // 0x80453EAC: nop

    return;
    // 0x80453EAC: nop

;}
RECOMP_FUNC void func_8044BAC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BAC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BAC8: jr          $ra
    // 0x8044BACC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BACC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_806B26AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B26AC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B26B0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B26B4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B26B8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B26BC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B26C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B26C4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B26C8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B26CC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B26D0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B26D4: jr          $ra
    // 0x806B26D8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B26D8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8064F018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F018: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F01C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F020: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F024: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F028: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F02C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F030: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F034: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F038: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F03C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F040: jr          $ra
    // 0x8064F044: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F044: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8001BD40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BD40: beq         $a0, $zero, L_8001BDAC
    if (ctx->r4 == 0) {
        // 0x8001BD44: nop
    
            goto L_8001BDAC;
    }
    // 0x8001BD44: nop

    // 0x8001BD48: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x8001BD4C: beq         $v0, $zero, L_8001BDAC
    if (ctx->r2 == 0) {
        // 0x8001BD50: nop
    
            goto L_8001BDAC;
    }
    // 0x8001BD50: nop

    // 0x8001BD54: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x8001BD58: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001BD5C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001BD60: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001BD64: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001BD68: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001BD6C: c.eq.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl == ctx->f6.fl;
    // 0x8001BD70: nop

    // 0x8001BD74: bc1fl       L_8001BD88
    if (!c1cs) {
        // 0x8001BD78: sub.s       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8001BD88;
    }
    goto skip_0;
    // 0x8001BD78: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x8001BD7C: b           L_8001BDA0
    // 0x8001BD80: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
        goto L_8001BDA0;
    // 0x8001BD80: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x8001BD84: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
L_8001BD88:
    // 0x8001BD88: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8001BD8C: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8001BD90: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
    // 0x8001BD94: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x8001BD98: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001BD9C: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
L_8001BDA0:
    // 0x8001BDA0: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8001BDA4: lw          $t9, 0x20($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X20);
    // 0x8001BDA8: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
L_8001BDAC:
    // 0x8001BDAC: jr          $ra
    // 0x8001BDB0: nop

    return;
    // 0x8001BDB0: nop

;}
RECOMP_FUNC void func_800411E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800411E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800411EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800411F0: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800411F4: beql        $a1, $t6, L_80041208
    if (ctx->r5 == ctx->r14) {
        // 0x800411F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80041208;
    }
    goto skip_0;
    // 0x800411F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800411FC: jal         0x8001D7CC
    // 0x80041200: nop

    func_8001D7CC(rdram, ctx);
        goto after_0;
    // 0x80041200: nop

    after_0:
    // 0x80041204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80041208:
    // 0x80041208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004120C: jr          $ra
    // 0x80041210: nop

    return;
    // 0x80041210: nop

;}
RECOMP_FUNC void func_806CC888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CC888: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806CC88C: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x806CC890: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x806CC894: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x806CC898: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806CC89C: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x806CC8A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x806CC8A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x806CC8A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806CC8AC: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x806CC8B0: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x806CC8B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x806CC8B8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806CC8BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806CC8C0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x806CC8C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806CC8C8: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x806CC8CC: addiu       $t3, $zero, 0x2C80
    ctx->r11 = ADD32(0, 0X2C80);
    // 0x806CC8D0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x806CC8D4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x806CC8D8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x806CC8DC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x806CC8E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806CC8E4: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x806CC8E8: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x806CC8EC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x806CC8F0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x806CC8F4: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x806CC8F8: ori         $a3, $a3, 0x41C8
    ctx->r7 = ctx->r7 | 0X41C8;
    // 0x806CC8FC: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x806CC900: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x806CC904: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806CC908: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x806CC90C: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x806CC910: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x806CC914: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806CC918: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x806CC91C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x806CC920: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806CC924: lui         $t0, 0xFFFE
    ctx->r8 = S32(0XFFFE << 16);
    // 0x806CC928: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x806CC92C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x806CC930: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806CC934: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x806CC938: ori         $t0, $t0, 0x793C
    ctx->r8 = ctx->r8 | 0X793C;
    // 0x806CC93C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x806CC940: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x806CC944: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806CC948: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x806CC94C: addiu       $t3, $zero, 0x204
    ctx->r11 = ADD32(0, 0X204);
    // 0x806CC950: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x806CC954: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x806CC958: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x806CC95C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x806CC960: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806CC964: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x806CC968: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x806CC96C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x806CC970: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x806CC974: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x806CC978: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x806CC97C: jr          $ra
    // 0x806CC980: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x806CC980: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_804C6254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C6254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C6258: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804C625C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804C6260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C6264: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C6268: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804C626C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804C6270: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C6274: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x804C6278: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804C627C: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(218, 0X484) << 16);
    // 0x804C6280: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804C6284: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C6288: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804C628C: lw          $t1, 0x6404($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(218, 0X484));
    // 0x804C6290: jal         0x804C60B4
    // 0x804C6294: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_804C60B4(rdram, ctx);
        goto after_0;
    // 0x804C6294: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x804C6298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C629C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C62A0: jr          $ra
    // 0x804C62A4: nop

    return;
    // 0x804C62A4: nop

;}
RECOMP_FUNC void func_80027CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027CB0: lw          $t8, 0x15C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X15C);
    // 0x80027CB4: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80027CB8: addiu       $t6, $t6, 0x7C64
    ctx->r14 = ADD32(ctx->r14, 0X7C64);
    // 0x80027CBC: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80027CC0: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80027CC4: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x80027CC8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80027CCC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80027CD0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80027CD4: jr          $ra
    // 0x80027CD8: sb          $t9, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r25;
    return;
    // 0x80027CD8: sb          $t9, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_8066D7CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066D7CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066D7D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066D7D4: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8066D7D8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066D7DC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8066D7E0: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x8066D7E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8066D7E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8066D7EC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8066D7F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8066D7F4: jal         0x8004D150
    // 0x8066D7F8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8004D150(rdram, ctx);
        goto after_0;
    // 0x8066D7F8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x8066D7FC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8066D800: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8066D804: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8066D808: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8066D80C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8066D810: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8066D814: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8066D818: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8066D81C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8066D820: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8066D824: lbu         $t1, 0x14($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X14);
    // 0x8066D828: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x8066D82C: beql        $t1, $zero, L_8066D85C
    if (ctx->r9 == 0) {
        // 0x8066D830: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066D85C;
    }
    goto skip_0;
    // 0x8066D830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066D834: jal         0x8004D618
    // 0x8066D838: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8004D618(rdram, ctx);
        goto after_1;
    // 0x8066D838: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8066D83C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8066D840: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8066D844: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8066D848: sw          $t2, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r10;
    // 0x8066D84C: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x8066D850: ori         $t5, $t4, 0xF00
    ctx->r13 = ctx->r12 | 0XF00;
    // 0x8066D854: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x8066D858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066D85C:
    // 0x8066D85C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066D860: jr          $ra
    // 0x8066D864: nop

    return;
    // 0x8066D864: nop

;}
RECOMP_FUNC void func_80475030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475030: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475034: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475038: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047503C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475040: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475044: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475048: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047504C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475050: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475054: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475058: jr          $ra
    // 0x8047505C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047505C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8045B8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B8A0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8045B8A4: lui         $t6, 0x8046
    ctx->r14 = S32(RELOC_HI16(107, 0X1A74) << 16);
    // 0x8045B8A8: addiu       $t6, $t6, -0x2CFC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(107, 0X1A74));
    // 0x8045B8AC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8045B8B0: jr          $ra
    // 0x8045B8B4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8045B8B4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806AB418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB418: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806AB41C: jr          $ra
    // 0x806AB420: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    return;
    // 0x806AB420: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800316BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800316BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800316C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800316C4: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800316C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800316CC: jal         0x800310A0
    // 0x800316D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x800316D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800316D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800316D8: jal         0x80030EE8
    // 0x800316DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80030EE8(rdram, ctx);
        goto after_1;
    // 0x800316DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800316E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800316E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800316E8: jr          $ra
    // 0x800316EC: nop

    return;
    // 0x800316EC: nop

;}
RECOMP_FUNC void func_804618C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804618C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804618CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804618D0: jal         0x80461778
    // 0x804618D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80461778(rdram, ctx);
        goto after_0;
    // 0x804618D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804618D8: bne         $v0, $zero, L_804618E8
    if (ctx->r2 != 0) {
        // 0x804618DC: nop
    
            goto L_804618E8;
    }
    // 0x804618DC: nop

    // 0x804618E0: b           L_80461904
    // 0x804618E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80461904;
    // 0x804618E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804618E8:
    // 0x804618E8: jal         0x80461820
    // 0x804618EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80461820(rdram, ctx);
        goto after_1;
    // 0x804618EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804618F0: bnel        $v0, $zero, L_80461904
    if (ctx->r2 != 0) {
        // 0x804618F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80461904;
    }
    goto skip_0;
    // 0x804618F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x804618F8: b           L_80461904
    // 0x804618FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80461904;
    // 0x804618FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80461900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80461904:
    // 0x80461904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80461908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046190C: jr          $ra
    // 0x80461910: nop

    return;
    // 0x80461910: nop

;}
RECOMP_FUNC void func_8078A748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A748: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8078A74C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8078A750: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8078A754: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8078A758: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8078A75C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8078A760: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8078A764: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8078A768: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8078A76C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8078A770: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8078A774: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8078A778: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8078A77C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8078A780: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8078A784: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8078A788: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8078A78C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8078A790: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8078A794: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8078A798: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8078A79C: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x8078A7A0: sub.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl - ctx->f6.fl;
L_8078A7A4:
    // 0x8078A7A4: lwc1        $f8, 0x3C($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x8078A7A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8078A7AC: sub.s       $f20, $f8, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f26.fl;
L_8078A7B0:
    // 0x8078A7B0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8078A7B4: jal         0x80053924
    // 0x8078A7B8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_80053924(rdram, ctx);
        goto after_0;
    // 0x8078A7B8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_0:
    // 0x8078A7BC: andi        $a2, $v0, 0xF800
    ctx->r6 = ctx->r2 & 0XF800;
    // 0x8078A7C0: ori         $a2, $a2, 0x701
    ctx->r6 = ctx->r6 | 0X701;
    // 0x8078A7C4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8078A7C8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8078A7CC: jal         0x800538BC
    // 0x8078A7D0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800538BC(rdram, ctx);
        goto after_1;
    // 0x8078A7D0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_1:
    // 0x8078A7D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8078A7D8: bne         $s0, $s1, L_8078A7B0
    if (ctx->r16 != ctx->r17) {
        // 0x8078A7DC: add.s       $f20, $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
            goto L_8078A7B0;
    }
    // 0x8078A7DC: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x8078A7E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8078A7E4: bne         $s2, $s4, L_8078A7A4
    if (ctx->r18 != ctx->r20) {
        // 0x8078A7E8: add.s       $f22, $f22, $f24
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f24.fl;
            goto L_8078A7A4;
    }
    // 0x8078A7E8: add.s       $f22, $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f24.fl;
    // 0x8078A7EC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8078A7F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8078A7F4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8078A7F8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8078A7FC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8078A800: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8078A804: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8078A808: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8078A80C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8078A810: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8078A814: jr          $ra
    // 0x8078A818: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8078A818: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8040B9B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B9B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040B9BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040B9C0: jal         0x8004700C
    // 0x8040B9C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8040B9C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040B9C8: beq         $v0, $zero, L_8040BA30
    if (ctx->r2 == 0) {
        // 0x8040B9CC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8040BA30;
    }
    // 0x8040B9CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040B9D0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8040B9D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040B9D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8040B9DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8040B9E0: jal         0x8040BA40
    // 0x8040B9E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8040BA40(rdram, ctx);
        goto after_1;
    // 0x8040B9E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x8040B9E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040B9EC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8040B9F0: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8040B9F4: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8040B9F8: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8040B9FC: lwc1        $f6, 0x3C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8040BA00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8040BA04: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8040BA08: nop

    // 0x8040BA0C: bc1fl       L_8040BA28
    if (!c1cs) {
        // 0x8040BA10: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8040BA28;
    }
    goto skip_0;
    // 0x8040BA10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x8040BA14: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8040BA18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8040BA1C: b           L_8040BA30
    // 0x8040BA20: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
        goto L_8040BA30;
    // 0x8040BA20: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x8040BA24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8040BA28:
    // 0x8040BA28: nop

    // 0x8040BA2C: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
L_8040BA30:
    // 0x8040BA30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040BA34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040BA38: jr          $ra
    // 0x8040BA3C: nop

    return;
    // 0x8040BA3C: nop

;}
RECOMP_FUNC void func_806DF010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF010: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x806DF014: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806DF018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806DF01C: bne         $t6, $at, L_806DF048
    if (ctx->r14 != ctx->r1) {
        // 0x806DF020: nop
    
            goto L_806DF048;
    }
    // 0x806DF020: nop

    // 0x806DF024: lbu         $t7, 0x18($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X18);
    // 0x806DF028: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806DF02C: bne         $t7, $at, L_806DF048
    if (ctx->r15 != ctx->r1) {
        // 0x806DF030: nop
    
            goto L_806DF048;
    }
    // 0x806DF030: nop

    // 0x806DF034: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x806DF038: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806DF03C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x806DF040: jr          $ra
    // 0x806DF044: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    return;
    // 0x806DF044: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_806DF048:
    // 0x806DF048: jr          $ra
    // 0x806DF04C: nop

    return;
    // 0x806DF04C: nop

;}
RECOMP_FUNC void func_80455190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80455194: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80455198: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045519C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804551A0: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x804551A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804551A8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x804551AC: lw          $t6, 0x6A28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A28);
    // 0x804551B0: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x804551B4: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x804551B8: bne         $t6, $at, L_804551E4
    if (ctx->r14 != ctx->r1) {
        // 0x804551BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804551E4;
    }
    // 0x804551BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804551C0: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x804551C4: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x804551C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x804551CC: jal         0x8044EDC4
    // 0x804551D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8044EDC4(rdram, ctx);
        goto after_0;
    // 0x804551D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x804551D4: jal         0x80446D70
    // 0x804551D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80446D70(rdram, ctx);
        goto after_1;
    // 0x804551D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804551DC: b           L_804551F4
    // 0x804551E0: nop

        goto L_804551F4;
    // 0x804551E0: nop

L_804551E4:
    // 0x804551E4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804551E8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804551EC: jal         0x80453764
    // 0x804551F0: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    func_80453764(rdram, ctx);
        goto after_2;
    // 0x804551F0: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    after_2:
L_804551F4:
    // 0x804551F4: jal         0x80454664
    // 0x804551F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80454664(rdram, ctx);
        goto after_3;
    // 0x804551F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804551FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80455200: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80455204: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80455208: jr          $ra
    // 0x8045520C: nop

    return;
    // 0x8045520C: nop

;}
RECOMP_FUNC void func_804D8D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8D98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804D8D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D8DA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804D8DA4: jal         0x80045A34
    // 0x804D8DA8: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804D8DA8: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_0:
    // 0x804D8DAC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804D8DB0: lui         $t6, 0x804E
    ctx->r14 = S32(RELOC_HI16(258, 0X98) << 16);
    // 0x804D8DB4: bne         $v0, $zero, L_804D8DC4
    if (ctx->r2 != 0) {
        // 0x804D8DB8: sw          $v0, 0x1F4($a2)
        MEM_W(0X1F4, ctx->r6) = ctx->r2;
            goto L_804D8DC4;
    }
    // 0x804D8DB8: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
    // 0x804D8DBC: b           L_804D8E24
    // 0x804D8DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804D8E24;
    // 0x804D8DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804D8DC4:
    // 0x804D8DC4: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
    // 0x804D8DC8: addiu       $t6, $t6, -0x7298
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(258, 0X98));
    // 0x804D8DCC: sw          $t6, 0x1F8($a2)
    MEM_W(0X1F8, ctx->r6) = ctx->r14;
    // 0x804D8DD0: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x804D8DD4: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x804D8DD8: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x804D8DDC: jal         0x80064D1C
    // 0x804D8DE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x804D8DE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x804D8DE4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804D8DE8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x804D8DEC: bne         $v0, $zero, L_804D8DFC
    if (ctx->r2 != 0) {
        // 0x804D8DF0: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_804D8DFC;
    }
    // 0x804D8DF0: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x804D8DF4: b           L_804D8E24
    // 0x804D8DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804D8E24;
    // 0x804D8DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804D8DFC:
    // 0x804D8DFC: sw          $t8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r24;
    // 0x804D8E00: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x804D8E04: jal         0x80064D1C
    // 0x804D8E08: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x804D8E08: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_2:
    // 0x804D8E0C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804D8E10: bne         $v0, $zero, L_804D8E20
    if (ctx->r2 != 0) {
        // 0x804D8E14: sw          $v0, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r2;
            goto L_804D8E20;
    }
    // 0x804D8E14: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    // 0x804D8E18: b           L_804D8E24
    // 0x804D8E1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804D8E24;
    // 0x804D8E1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804D8E20:
    // 0x804D8E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804D8E24:
    // 0x804D8E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D8E28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804D8E2C: jr          $ra
    // 0x804D8E30: nop

    return;
    // 0x804D8E30: nop

;}
RECOMP_FUNC void func_806D9064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9064: lw          $v0, 0x14C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C);
    // 0x806D9068: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(628, 0X738) << 16);
    // 0x806D906C: addiu       $t7, $t7, -0x6A08
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(628, 0X738));
    // 0x806D9070: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x806D9074: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x806D9078: bnel        $at, $zero, L_806D9088
    if (ctx->r1 != 0) {
        // 0x806D907C: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_806D9088;
    }
    goto skip_0;
    // 0x806D907C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    skip_0:
    // 0x806D9080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806D9084: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
L_806D9088:
    // 0x806D9088: sw          $v0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r2;
    // 0x806D908C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x806D9090: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806D9094: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x806D9098: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806D909C: jr          $ra
    // 0x806D90A0: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x806D90A0: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_804292FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804292FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80429300: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80429304: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80429308: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8042930C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429310: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80429314: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80429318: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8042931C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80429320: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80429324: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(41, 0X1E88) << 16);
    // 0x80429328: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8042932C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80429330: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80429334: lw          $t2, -0x6838($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(41, 0X1E88));
    // 0x80429338: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8042933C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80429340: jal         0x8042910C
    // 0x80429344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042910C(rdram, ctx);
        goto after_0;
    // 0x80429344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80429348: jal         0x80429168
    // 0x8042934C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80429168(rdram, ctx);
        goto after_1;
    // 0x8042934C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80429350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80429354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80429358: jr          $ra
    // 0x8042935C: nop

    return;
    // 0x8042935C: nop

;}
RECOMP_FUNC void func_8064C4A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C4A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C4A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C4A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064C4AC: jal         0x80045A34
    // 0x8064C4B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8064C4B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8064C4B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064C4B8: bne         $v0, $zero, L_8064C4C8
    if (ctx->r2 != 0) {
        // 0x8064C4BC: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8064C4C8;
    }
    // 0x8064C4BC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8064C4C0: b           L_8064C4D4
    // 0x8064C4C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8064C4D4;
    // 0x8064C4C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064C4C8:
    // 0x8064C4C8: jal         0x8064C488
    // 0x8064C4CC: nop

    func_8064C488(rdram, ctx);
        goto after_1;
    // 0x8064C4CC: nop

    after_1:
    // 0x8064C4D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8064C4D4:
    // 0x8064C4D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064C4D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C4DC: jr          $ra
    // 0x8064C4E0: nop

    return;
    // 0x8064C4E0: nop

;}
RECOMP_FUNC void func_80777514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80777514: jr          $ra
    // 0x80777518: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    return;
    // 0x80777518: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
;}
RECOMP_FUNC void func_806B29DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B29DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B29E0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B29E4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B29E8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B29EC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B29F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B29F4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B29F8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B29FC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2A00: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2A04: jr          $ra
    // 0x806B2A08: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2A08: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805AB778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB778: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805AB77C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805AB780: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x805AB784: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x805AB788: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x805AB78C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805AB790: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x805AB794: jal         0x805AB6D0
    // 0x805AB798: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_805AB6D0(rdram, ctx);
        goto after_0;
    // 0x805AB798: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_0:
    // 0x805AB79C: bne         $v0, $zero, L_805AB7B4
    if (ctx->r2 != 0) {
        // 0x805AB7A0: sw          $v0, 0x1F4($s1)
        MEM_W(0X1F4, ctx->r17) = ctx->r2;
            goto L_805AB7B4;
    }
    // 0x805AB7A0: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x805AB7A4: jal         0x800445A4
    // 0x805AB7A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805AB7A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x805AB7AC: b           L_805AB88C
    // 0x805AB7B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805AB88C;
    // 0x805AB7B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805AB7B4:
    // 0x805AB7B4: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x805AB7B8: lui         $t8, 0x805B
    ctx->r24 = S32(RELOC_HI16(435, 0X7B0) << 16);
    // 0x805AB7BC: addiu       $t8, $t8, -0x4910
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(435, 0X7B0));
    // 0x805AB7C0: sw          $t8, 0x1F8($s1)
    MEM_W(0X1F8, ctx->r17) = ctx->r24;
    // 0x805AB7C4: addiu       $a1, $zero, 0x27C
    ctx->r5 = ADD32(0, 0X27C);
    // 0x805AB7C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805AB7CC: jal         0x80065728
    // 0x805AB7D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x805AB7D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805AB7D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805AB7D8: jal         0x8005D730
    // 0x805AB7DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005D730(rdram, ctx);
        goto after_3;
    // 0x805AB7DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x805AB7E0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x805AB7E4: sw          $t9, 0x260($s0)
    MEM_W(0X260, ctx->r16) = ctx->r25;
    // 0x805AB7E8: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x805AB7EC: sw          $zero, 0x268($s0)
    MEM_W(0X268, ctx->r16) = 0;
    // 0x805AB7F0: andi        $t1, $t0, 0x3FF
    ctx->r9 = ctx->r8 & 0X3FF;
    // 0x805AB7F4: jal         0x80058958
    // 0x805AB7F8: sh          $t1, 0x25C($s0)
    MEM_H(0X25C, ctx->r16) = ctx->r9;
    func_80058958(rdram, ctx);
        goto after_4;
    // 0x805AB7F8: sh          $t1, 0x25C($s0)
    MEM_H(0X25C, ctx->r16) = ctx->r9;
    after_4:
    // 0x805AB7FC: beq         $v0, $zero, L_805AB888
    if (ctx->r2 == 0) {
        // 0x805AB800: lui         $t2, 0x8010
        ctx->r10 = S32(0X8010 << 16);
            goto L_805AB888;
    }
    // 0x805AB800: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x805AB804: lw          $t2, -0x7BC4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7BC4);
    // 0x805AB808: lw          $t3, 0x10C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10C);
    // 0x805AB80C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x805AB810: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x805AB814: beql        $t5, $zero, L_805AB88C
    if (ctx->r13 == 0) {
        // 0x805AB818: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_805AB88C;
    }
    goto skip_0;
    // 0x805AB818: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x805AB81C: jal         0x80056564
    // 0x805AB820: nop

    func_80056564(rdram, ctx);
        goto after_5;
    // 0x805AB820: nop

    after_5:
    // 0x805AB824: beq         $v0, $zero, L_805AB888
    if (ctx->r2 == 0) {
        // 0x805AB828: sw          $v0, 0x268($s0)
        MEM_W(0X268, ctx->r16) = ctx->r2;
            goto L_805AB888;
    }
    // 0x805AB828: sw          $v0, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r2;
    // 0x805AB82C: lw          $v0, 0x16C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X16C);
    // 0x805AB830: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x805AB834: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805AB838: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805AB83C: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x805AB840: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
    // 0x805AB844: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x805AB848: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x805AB84C: jal         0x800457A0
    // 0x805AB850: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    func_800457A0(rdram, ctx);
        goto after_6;
    // 0x805AB850: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    after_6:
    // 0x805AB854: lw          $a0, 0x268($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X268);
    // 0x805AB858: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x805AB85C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805AB860: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x805AB864: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x805AB868: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805AB86C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805AB870: jal         0x80056584
    // 0x805AB874: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80056584(rdram, ctx);
        goto after_7;
    // 0x805AB874: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_7:
    // 0x805AB878: lw          $t0, 0x16C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X16C);
    // 0x805AB87C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805AB880: addiu       $t9, $t9, 0x7890
    ctx->r25 = ADD32(ctx->r25, 0X7890);
    // 0x805AB884: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
L_805AB888:
    // 0x805AB888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805AB88C:
    // 0x805AB88C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805AB890: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x805AB894: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x805AB898: jr          $ra
    // 0x805AB89C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x805AB89C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_805CC554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CC554: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805CC558: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805CC55C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x805CC560: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805CC564: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805CC568: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805CC56C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805CC570: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805CC574: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805CC578: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805CC57C: lui         $t1, 0x805D
    ctx->r9 = S32(RELOC_HI16(456, 0X3E4) << 16);
    // 0x805CC580: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805CC584: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805CC588: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805CC58C: lw          $t1, -0x39BC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(456, 0X3E4));
    // 0x805CC590: jr          $ra
    // 0x805CC594: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x805CC594: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8042668C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042668C: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80426690: lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X10);
    // 0x80426694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80426698: beq         $a3, $zero, L_804269A8
    if (ctx->r7 == 0) {
        // 0x8042669C: andi        $v1, $a3, 0x1
        ctx->r3 = ctx->r7 & 0X1;
            goto L_804269A8;
    }
    // 0x8042669C: andi        $v1, $a3, 0x1
    ctx->r3 = ctx->r7 & 0X1;
    // 0x804266A0: beql        $v1, $zero, L_8042674C
    if (ctx->r3 == 0) {
        // 0x804266A4: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_8042674C;
    }
    goto skip_0;
    // 0x804266A4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    skip_0:
    // 0x804266A8: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x804266AC: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x804266B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804266B4: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x804266B8: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x804266BC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x804266C0: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // 0x804266C4: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x804266C8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804266CC: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x804266D0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804266D4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x804266D8: nop

    // 0x804266DC: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x804266E0: sh          $t4, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r12;
    // 0x804266E4: lh          $t5, -0x4($a2)
    ctx->r13 = MEM_H(ctx->r6, -0X4);
    // 0x804266E8: lh          $t0, -0x4($a1)
    ctx->r8 = MEM_H(ctx->r5, -0X4);
    // 0x804266EC: subu        $t6, $t5, $t0
    ctx->r14 = SUB32(ctx->r13, ctx->r8);
    // 0x804266F0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x804266F4: nop

    // 0x804266F8: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804266FC: mul.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80426700: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80426704: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80426708: nop

    // 0x8042670C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80426710: sh          $t3, -0x4($a0)
    MEM_H(-0X4, ctx->r4) = ctx->r11;
    // 0x80426714: lh          $t4, -0x2($a2)
    ctx->r12 = MEM_H(ctx->r6, -0X2);
    // 0x80426718: lh          $t1, -0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, -0X2);
    // 0x8042671C: subu        $t5, $t4, $t1
    ctx->r13 = SUB32(ctx->r12, ctx->r9);
    // 0x80426720: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80426724: nop

    // 0x80426728: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8042672C: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80426730: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80426734: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80426738: nop

    // 0x8042673C: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x80426740: beq         $v0, $a3, L_804269A8
    if (ctx->r2 == ctx->r7) {
        // 0x80426744: sh          $t2, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r10;
            goto L_804269A8;
    }
    // 0x80426744: sh          $t2, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r10;
    // 0x80426748: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_8042674C:
    // 0x8042674C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x80426750: beq         $v0, $a3, L_80426888
    if (ctx->r2 == ctx->r7) {
        // 0x80426754: lh          $t3, 0x0($a2)
        ctx->r11 = MEM_H(ctx->r6, 0X0);
            goto L_80426888;
    }
    // 0x80426754: lh          $t3, 0x0($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X0);
L_80426758:
    // 0x80426758: subu        $t4, $t3, $v1
    ctx->r12 = SUB32(ctx->r11, ctx->r3);
    // 0x8042675C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80426760: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80426764: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80426768: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8042676C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80426770: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x80426774: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80426778: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8042677C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80426780: nop

    // 0x80426784: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80426788: sh          $t9, -0xC($a0)
    MEM_H(-0XC, ctx->r4) = ctx->r25;
    // 0x8042678C: lh          $t0, -0xA($a1)
    ctx->r8 = MEM_H(ctx->r5, -0XA);
    // 0x80426790: lh          $t2, -0xA($a2)
    ctx->r10 = MEM_H(ctx->r6, -0XA);
    // 0x80426794: subu        $t3, $t2, $t0
    ctx->r11 = SUB32(ctx->r10, ctx->r8);
    // 0x80426798: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8042679C: nop

    // 0x804267A0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804267A4: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x804267A8: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804267AC: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x804267B0: nop

    // 0x804267B4: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x804267B8: sh          $t8, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r24;
    // 0x804267BC: lh          $t1, -0x8($a1)
    ctx->r9 = MEM_H(ctx->r5, -0X8);
    // 0x804267C0: lh          $t9, -0x8($a2)
    ctx->r25 = MEM_H(ctx->r6, -0X8);
    // 0x804267C4: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x804267C8: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x804267CC: nop

    // 0x804267D0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804267D4: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x804267D8: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804267DC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x804267E0: nop

    // 0x804267E4: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x804267E8: sh          $t7, -0x8($a0)
    MEM_H(-0X8, ctx->r4) = ctx->r15;
    // 0x804267EC: lh          $v1, -0x6($a1)
    ctx->r3 = MEM_H(ctx->r5, -0X6);
    // 0x804267F0: lh          $t8, -0x6($a2)
    ctx->r24 = MEM_H(ctx->r6, -0X6);
    // 0x804267F4: subu        $t9, $t8, $v1
    ctx->r25 = SUB32(ctx->r24, ctx->r3);
    // 0x804267F8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x804267FC: nop

    // 0x80426800: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80426804: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80426808: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8042680C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80426810: nop

    // 0x80426814: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80426818: sh          $t6, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r14;
    // 0x8042681C: lh          $t0, -0x4($a1)
    ctx->r8 = MEM_H(ctx->r5, -0X4);
    // 0x80426820: lh          $t7, -0x4($a2)
    ctx->r15 = MEM_H(ctx->r6, -0X4);
    // 0x80426824: subu        $t8, $t7, $t0
    ctx->r24 = SUB32(ctx->r15, ctx->r8);
    // 0x80426828: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8042682C: nop

    // 0x80426830: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80426834: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80426838: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8042683C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80426840: nop

    // 0x80426844: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80426848: sh          $t5, -0x4($a0)
    MEM_H(-0X4, ctx->r4) = ctx->r13;
    // 0x8042684C: lh          $t1, -0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, -0X2);
    // 0x80426850: lh          $t6, -0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X2);
    // 0x80426854: subu        $t7, $t6, $t1
    ctx->r15 = SUB32(ctx->r14, ctx->r9);
    // 0x80426858: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8042685C: nop

    // 0x80426860: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80426864: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80426868: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8042686C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80426870: nop

    // 0x80426874: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80426878: sh          $t4, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r12;
    // 0x8042687C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x80426880: bne         $v0, $a3, L_80426758
    if (ctx->r2 != ctx->r7) {
        // 0x80426884: lh          $t3, 0x0($a2)
        ctx->r11 = MEM_H(ctx->r6, 0X0);
            goto L_80426758;
    }
    // 0x80426884: lh          $t3, 0x0($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X0);
L_80426888:
    // 0x80426888: subu        $t4, $t3, $v1
    ctx->r12 = SUB32(ctx->r11, ctx->r3);
    // 0x8042688C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80426890: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80426894: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80426898: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8042689C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x804268A0: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x804268A4: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804268A8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x804268AC: nop

    // 0x804268B0: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x804268B4: sh          $t9, -0xC($a0)
    MEM_H(-0XC, ctx->r4) = ctx->r25;
    // 0x804268B8: lh          $t2, -0xA($a2)
    ctx->r10 = MEM_H(ctx->r6, -0XA);
    // 0x804268BC: lh          $t0, -0xA($a1)
    ctx->r8 = MEM_H(ctx->r5, -0XA);
    // 0x804268C0: subu        $t3, $t2, $t0
    ctx->r11 = SUB32(ctx->r10, ctx->r8);
    // 0x804268C4: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x804268C8: nop

    // 0x804268CC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804268D0: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x804268D4: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804268D8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x804268DC: nop

    // 0x804268E0: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x804268E4: sh          $t8, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r24;
    // 0x804268E8: lh          $t9, -0x8($a2)
    ctx->r25 = MEM_H(ctx->r6, -0X8);
    // 0x804268EC: lh          $t1, -0x8($a1)
    ctx->r9 = MEM_H(ctx->r5, -0X8);
    // 0x804268F0: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x804268F4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x804268F8: nop

    // 0x804268FC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80426900: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80426904: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80426908: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8042690C: nop

    // 0x80426910: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x80426914: sh          $t7, -0x8($a0)
    MEM_H(-0X8, ctx->r4) = ctx->r15;
    // 0x80426918: lh          $t8, -0x6($a2)
    ctx->r24 = MEM_H(ctx->r6, -0X6);
    // 0x8042691C: lh          $v1, -0x6($a1)
    ctx->r3 = MEM_H(ctx->r5, -0X6);
    // 0x80426920: subu        $t9, $t8, $v1
    ctx->r25 = SUB32(ctx->r24, ctx->r3);
    // 0x80426924: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80426928: nop

    // 0x8042692C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80426930: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80426934: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80426938: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8042693C: nop

    // 0x80426940: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80426944: sh          $t6, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r14;
    // 0x80426948: lh          $t7, -0x4($a2)
    ctx->r15 = MEM_H(ctx->r6, -0X4);
    // 0x8042694C: lh          $t0, -0x4($a1)
    ctx->r8 = MEM_H(ctx->r5, -0X4);
    // 0x80426950: subu        $t8, $t7, $t0
    ctx->r24 = SUB32(ctx->r15, ctx->r8);
    // 0x80426954: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80426958: nop

    // 0x8042695C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80426960: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80426964: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80426968: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8042696C: nop

    // 0x80426970: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80426974: sh          $t5, -0x4($a0)
    MEM_H(-0X4, ctx->r4) = ctx->r13;
    // 0x80426978: lh          $t6, -0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X2);
    // 0x8042697C: lh          $t1, -0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, -0X2);
    // 0x80426980: subu        $t7, $t6, $t1
    ctx->r15 = SUB32(ctx->r14, ctx->r9);
    // 0x80426984: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80426988: nop

    // 0x8042698C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80426990: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80426994: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80426998: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8042699C: nop

    // 0x804269A0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804269A4: sh          $t4, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r12;
L_804269A8:
    // 0x804269A8: jr          $ra
    // 0x804269AC: nop

    return;
    // 0x804269AC: nop

;}
RECOMP_FUNC void func_807B9B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B9B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B9B8C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B9B90: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x807B9B94: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x807B9B98: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x807B9B9C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x807B9BA0: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x807B9BA4: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x807B9BA8: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x807B9BAC: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x807B9BB0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x807B9BB4: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x807B9BB8: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x807B9BBC: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x807B9BC0: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x807B9BC4: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x807B9BC8: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x807B9BCC: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x807B9BD0: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x807B9BD4: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x807B9BD8: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x807B9BDC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x807B9BE0: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x807B9BE4: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
    // 0x807B9BE8: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x807B9BEC: jal         0x807B90E8
    // 0x807B9BF0: sw          $zero, 0x48($v1)
    MEM_W(0X48, ctx->r3) = 0;
    func_807B90E8(rdram, ctx);
        goto after_0;
    // 0x807B9BF0: sw          $zero, 0x48($v1)
    MEM_W(0X48, ctx->r3) = 0;
    after_0:
    // 0x807B9BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B9BF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B9BFC: jr          $ra
    // 0x807B9C00: nop

    return;
    // 0x807B9C00: nop

;}
RECOMP_FUNC void func_80582940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582940: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80582944: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80582948: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8058294C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80582950: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80582954: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80582958: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8058295C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80582960: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80582964: blez        $a2, L_805829B8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80582968: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_805829B8;
    }
    // 0x80582968: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8058296C: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x80582970: addu        $s6, $t6, $a1
    ctx->r22 = ADD32(ctx->r14, ctx->r5);
    // 0x80582974: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80582978: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8058297C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
L_80582980:
    // 0x80582980: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80582984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80582988: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x8058298C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80582990: jal         0x8005C27C
    // 0x80582994: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x80582994: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_0:
    // 0x80582998: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8058299C: lhu         $a1, 0x0($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X0);
    // 0x805829A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x805829A4: jal         0x8005C27C
    // 0x805829A8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x805829A8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_1:
    // 0x805829AC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x805829B0: bne         $s0, $s6, L_80582980
    if (ctx->r16 != ctx->r22) {
        // 0x805829B4: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80582980;
    }
    // 0x805829B4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_805829B8:
    // 0x805829B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x805829BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805829C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x805829C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x805829C8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x805829CC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x805829D0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x805829D4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x805829D8: jr          $ra
    // 0x805829DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x805829DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8064C7D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C7D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C7D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C7D8: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064C7DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8064C7E0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C7E4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064C7E8: nop

    // 0x8064C7EC: bc1fl       L_8064C844
    if (!c1cs) {
        // 0x8064C7F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C844;
    }
    goto skip_0;
    // 0x8064C7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C7F4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064C7F8: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064C7FC: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x8064C800: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064C804: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8064C808: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8064C80C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C810: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8064C814: nop

    // 0x8064C818: bc1fl       L_8064C844
    if (!c1cs) {
        // 0x8064C81C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C844;
    }
    goto skip_1;
    // 0x8064C81C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8064C820: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064C824: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(495, 0X3658) << 16);
    // 0x8064C828: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8064C82C: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8064C830: lwc1        $f6, -0x28D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(495, 0X3658));
    // 0x8064C834: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064C838: jal         0x8064CD50
    // 0x8064C83C: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    func_8064CD50(rdram, ctx);
        goto after_0;
    // 0x8064C83C: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x8064C840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C844:
    // 0x8064C844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C848: jr          $ra
    // 0x8064C84C: nop

    return;
    // 0x8064C84C: nop

;}
RECOMP_FUNC void func_8044A9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A9BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044A9C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A9C4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044A9C8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A9CC: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044A9D0: lw          $a1, 0x6A58($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A58);
    // 0x8044A9D4: beq         $a1, $zero, L_8044A9EC
    if (ctx->r5 == 0) {
        // 0x8044A9D8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044A9EC;
    }
    // 0x8044A9D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A9DC: jal         0x80050A2C
    // 0x8044A9E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044A9E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044A9E4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A9E8: sw          $zero, 0x6A58($v1)
    MEM_W(0X6A58, ctx->r3) = 0;
L_8044A9EC:
    // 0x8044A9EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044A9F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044A9F4: jr          $ra
    // 0x8044A9F8: nop

    return;
    // 0x8044A9F8: nop

;}
RECOMP_FUNC void func_8006A99C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A99C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A9A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006A9A4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006A9A8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006A9AC: bgez        $a0, L_8006A9FC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006A9B0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006A9FC;
    }
    // 0x8006A9B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A9B4: jal         0x8006593C
    // 0x8006A9B8: nop

    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x8006A9B8: nop

    after_0:
    // 0x8006A9BC: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8006A9C0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8006A9C4: sra         $a1, $v1, 4
    ctx->r5 = S32(SIGNED(ctx->r3) >> 4);
    // 0x8006A9C8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8006A9CC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006A9D0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x8006A9D4: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x8006A9D8: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x8006A9DC: beq         $t6, $zero, L_8006A9F4
    if (ctx->r14 == 0) {
        // 0x8006A9E0: sra         $a0, $a0, 16
        ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
            goto L_8006A9F4;
    }
    // 0x8006A9E0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006A9E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8006A9E8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006A9EC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006A9F0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_8006A9F4:
    // 0x8006A9F4: b           L_8006AA08
    // 0x8006A9F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006AA08;
    // 0x8006A9F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006A9FC:
    // 0x8006A9FC: sra         $v0, $a0, 4
    ctx->r2 = S32(SIGNED(ctx->r4) >> 4);
    // 0x8006AA00: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8006AA04: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8006AA08:
    // 0x8006AA08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006AA0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006AA10: jr          $ra
    // 0x8006AA14: nop

    return;
    // 0x8006AA14: nop

;}
RECOMP_FUNC void func_806F6FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6FEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F6FF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F6FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F6FF8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806F6FFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F7000: jal         0x806F6E20
    // 0x806F7004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806F6E20(rdram, ctx);
        goto after_0;
    // 0x806F7004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x806F7008: jal         0x806F6F64
    // 0x806F700C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806F6F64(rdram, ctx);
        goto after_1;
    // 0x806F700C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x806F7010: jal         0x806F6F08
    // 0x806F7014: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806F6F08(rdram, ctx);
        goto after_2;
    // 0x806F7014: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x806F7018: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806F701C: bne         $v0, $at, L_806F7038
    if (ctx->r2 != ctx->r1) {
        // 0x806F7020: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806F7038;
    }
    // 0x806F7020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806F7024: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806F7028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F702C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806F7030: jal         0x806F73DC
    // 0x806F7034: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    func_806F73DC(rdram, ctx);
        goto after_3;
    // 0x806F7034: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    after_3:
L_806F7038:
    // 0x806F7038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F703C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F7040: jr          $ra
    // 0x806F7044: nop

    return;
    // 0x806F7044: nop

;}
RECOMP_FUNC void func_8043F360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043F364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F368: jal         0x8004700C
    // 0x8043F36C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8043F36C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043F370: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8043F374: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8043F378: bne         $v0, $zero, L_8043F388
    if (ctx->r2 != 0) {
        // 0x8043F37C: lw          $a0, 0x1F4($t6)
        ctx->r4 = MEM_W(ctx->r14, 0X1F4);
            goto L_8043F388;
    }
    // 0x8043F37C: lw          $a0, 0x1F4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X1F4);
    // 0x8043F380: b           L_8043F41C
    // 0x8043F384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043F41C;
    // 0x8043F384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043F388:
    // 0x8043F388: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8043F38C: lwc1        $f6, 0x1C78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C78);
    // 0x8043F390: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x8043F394: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8043F398: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043F39C: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8043F3A0: lwc1        $f10, 0x1C7C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C7C);
    // 0x8043F3A4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8043F3A8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8043F3AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8043F3B0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8043F3B4: bc1f        L_8043F3C0
    if (!c1cs) {
        // 0x8043F3B8: nop
    
            goto L_8043F3C0;
    }
    // 0x8043F3B8: nop

    // 0x8043F3BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8043F3C0:
    // 0x8043F3C0: beql        $v0, $zero, L_8043F420
    if (ctx->r2 == 0) {
        // 0x8043F3C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043F420;
    }
    goto skip_0;
    // 0x8043F3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8043F3C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8043F3CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8043F3D0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8043F3D4: nop

    // 0x8043F3D8: bc1f        L_8043F3E4
    if (!c1cs) {
        // 0x8043F3DC: nop
    
            goto L_8043F3E4;
    }
    // 0x8043F3DC: nop

    // 0x8043F3E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8043F3E4:
    // 0x8043F3E4: beql        $v0, $zero, L_8043F420
    if (ctx->r2 == 0) {
        // 0x8043F3E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043F420;
    }
    goto skip_1;
    // 0x8043F3E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8043F3EC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8043F3F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8043F3F4: bc1f        L_8043F400
    if (!c1cs) {
        // 0x8043F3F8: nop
    
            goto L_8043F400;
    }
    // 0x8043F3F8: nop

    // 0x8043F3FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8043F400:
    // 0x8043F400: beql        $v0, $zero, L_8043F420
    if (ctx->r2 == 0) {
        // 0x8043F404: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043F420;
    }
    goto skip_2;
    // 0x8043F404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8043F408: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8043F40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8043F410: bc1fl       L_8043F420
    if (!c1cs) {
        // 0x8043F414: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043F420;
    }
    goto skip_3;
    // 0x8043F414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8043F418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8043F41C:
    // 0x8043F41C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043F420:
    // 0x8043F420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043F424: jr          $ra
    // 0x8043F428: nop

    return;
    // 0x8043F428: nop

;}
RECOMP_FUNC void func_80472DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80472DA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80472DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80472DA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80472DAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80472DB0: jal         0x80047090
    // 0x80472DB4: addiu       $a0, $zero, 0x4127
    ctx->r4 = ADD32(0, 0X4127);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80472DB4: addiu       $a0, $zero, 0x4127
    ctx->r4 = ADD32(0, 0X4127);
    after_0:
    // 0x80472DB8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80472DBC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80472DC0: beq         $v0, $at, L_80472E18
    if (ctx->r2 == ctx->r1) {
        // 0x80472DC4: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_80472E18;
    }
    // 0x80472DC4: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x80472DC8: lui         $at, 0x4127
    ctx->r1 = S32(0X4127 << 16);
    // 0x80472DCC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80472DD0: or          $a0, $t0, $at
    ctx->r4 = ctx->r8 | ctx->r1;
    // 0x80472DD4: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80472DD8: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x80472DDC: jal         0x8004613C
    // 0x80472DE0: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80472DE0: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    after_1:
    // 0x80472DE4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80472DE8: beq         $v0, $zero, L_80472E18
    if (ctx->r2 == 0) {
        // 0x80472DEC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80472E18;
    }
    // 0x80472DEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80472DF0: beq         $v1, $zero, L_80472E10
    if (ctx->r3 == 0) {
        // 0x80472DF4: nop
    
            goto L_80472E10;
    }
    // 0x80472DF4: nop

    // 0x80472DF8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80472DFC: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    // 0x80472E00: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80472E04: swc1        $f6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
    // 0x80472E08: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80472E0C: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
L_80472E10:
    // 0x80472E10: b           L_80472E1C
    // 0x80472E14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80472E1C;
    // 0x80472E14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80472E18:
    // 0x80472E18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80472E1C:
    // 0x80472E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80472E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80472E24: jr          $ra
    // 0x80472E28: nop

    return;
    // 0x80472E28: nop

    // 0x80472E2C: nop

;}
RECOMP_FUNC void func_8003C974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003C978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003C97C: beq         $a0, $zero, L_8003C9A0
    if (ctx->r4 == 0) {
        // 0x8003C980: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8003C9A0;
    }
    // 0x8003C980: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003C984: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8003C988: beql        $a0, $zero, L_8003C9A4
    if (ctx->r4 == 0) {
        // 0x8003C98C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003C9A4;
    }
    goto skip_0;
    // 0x8003C98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003C990: jal         0x800568E0
    // 0x8003C994: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800568E0(rdram, ctx);
        goto after_0;
    // 0x8003C994: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003C998: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8003C99C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8003C9A0:
    // 0x8003C9A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003C9A4:
    // 0x8003C9A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003C9A8: jr          $ra
    // 0x8003C9AC: nop

    return;
    // 0x8003C9AC: nop

;}
RECOMP_FUNC void func_8042EE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EE08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042EE0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042EE10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042EE14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042EE18: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8042EE1C: jal         0x80048F84
    // 0x8042EE20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8042EE20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8042EE24: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042EE28: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8042EE2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8042EE30: lwc1        $f2, 0x14($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8042EE34: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8042EE38: nop

    // 0x8042EE3C: bc1fl       L_8042EE54
    if (!c1cs) {
        // 0x8042EE40: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8042EE54;
    }
    goto skip_0;
    // 0x8042EE40: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x8042EE44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042EE48: b           L_8042EE6C
    // 0x8042EE4C: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
        goto L_8042EE6C;
    // 0x8042EE4C: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    // 0x8042EE50: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8042EE54:
    // 0x8042EE54: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8042EE58: bc1f        L_8042EE6C
    if (!c1cs) {
        // 0x8042EE5C: nop
    
            goto L_8042EE6C;
    }
    // 0x8042EE5C: nop

    // 0x8042EE60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042EE64: nop

    // 0x8042EE68: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
L_8042EE6C:
    // 0x8042EE6C: jal         0x8042ECD8
    // 0x8042EE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042ECD8(rdram, ctx);
        goto after_1;
    // 0x8042EE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8042EE74: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042EE78: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8042EE7C: lwc1        $f10, 0x10($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8042EE80: jal         0x80065954
    // 0x8042EE84: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8042EE84: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x8042EE88: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8042EE8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8042EE90: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8042EE94: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8042EE98: nop

    // 0x8042EE9C: bc1f        L_8042EEB8
    if (!c1cs) {
        // 0x8042EEA0: nop
    
            goto L_8042EEB8;
    }
    // 0x8042EEA0: nop

    // 0x8042EEA4: lwc1        $f18, 0xC4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8042EEA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042EEAC: nop

    // 0x8042EEB0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8042EEB4: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
L_8042EEB8:
    // 0x8042EEB8: jal         0x8042EC7C
    // 0x8042EEBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042EC7C(rdram, ctx);
        goto after_3;
    // 0x8042EEBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8042EEC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042EEC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042EEC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042EECC: jr          $ra
    // 0x8042EED0: nop

    return;
    // 0x8042EED0: nop

;}
RECOMP_FUNC void func_8073FBB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073FBB8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073FBBC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8073FBC0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8073FBC4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8073FBC8: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x8073FBCC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8073FBD0: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8073FBD4: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8073FBD8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8073FBDC: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x8073FBE0: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8073FBE4: jr          $ra
    // 0x8073FBE8: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    return;
    // 0x8073FBE8: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
;}
RECOMP_FUNC void func_804C0D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C0D74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C0D78: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804C0D7C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804C0D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C0D84: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804C0D88: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804C0D8C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804C0D90: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804C0D94: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804C0D98: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(200, 0X4C8) << 16);
    // 0x804C0D9C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C0DA0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804C0DA4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804C0DA8: lw          $t2, 0xF28($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(200, 0X4C8));
    // 0x804C0DAC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804C0DB0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804C0DB4: jal         0x804C0C74
    // 0x804C0DB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C0C74(rdram, ctx);
        goto after_0;
    // 0x804C0DB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C0DBC: jal         0x804C0BC0
    // 0x804C0DC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804C0BC0(rdram, ctx);
        goto after_1;
    // 0x804C0DC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804C0DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C0DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C0DCC: jr          $ra
    // 0x804C0DD0: nop

    return;
    // 0x804C0DD0: nop

;}
RECOMP_FUNC void func_80027260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027268: jal         0x80024748
    // 0x8002726C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024748(rdram, ctx);
        goto after_0;
    // 0x8002726C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027270: beq         $v0, $zero, L_800272BC
    if (ctx->r2 == 0) {
        // 0x80027274: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_800272BC;
    }
    // 0x80027274: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80027278: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x8002727C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80027280: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x80027284: addiu       $t8, $t8, 0x71C4
    ctx->r24 = ADD32(ctx->r24, 0X71C4);
    // 0x80027288: sw          $t6, 0x14C($a3)
    MEM_W(0X14C, ctx->r7) = ctx->r14;
    // 0x8002728C: sb          $t7, 0x158($a3)
    MEM_B(0X158, ctx->r7) = ctx->r15;
    // 0x80027290: sw          $t8, 0x160($a3)
    MEM_W(0X160, ctx->r7) = ctx->r24;
    // 0x80027294: jal         0x8001D770
    // 0x80027298: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x80027298: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x8002729C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800272A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800272A4: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x800272A8: jal         0x80067BF8
    // 0x800272AC: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x800272AC: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x800272B0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800272B4: jal         0x80067818
    // 0x800272B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x800272B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_800272BC:
    // 0x800272BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800272C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800272C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800272C8: jr          $ra
    // 0x800272CC: nop

    return;
    // 0x800272CC: nop

;}
