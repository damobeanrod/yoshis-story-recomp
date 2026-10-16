#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80682C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682C54: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682C58: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682C5C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682C60: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682C64: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682C68: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682C6C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682C70: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682C74: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682C78: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682C7C: jr          $ra
    // 0x80682C80: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682C80: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806B1950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1950: lui         $v0, 0x806B
    ctx->r2 = S32(RELOC_HI16(601, 0X1390) << 16);
    // 0x806B1954: jr          $ra
    // 0x806B1958: addiu       $v0, $v0, 0x2CE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(601, 0X1390));
    return;
    // 0x806B1958: addiu       $v0, $v0, 0x2CE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(601, 0X1390));
;}
RECOMP_FUNC void Fault_WaitInputImpl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070790: lui         $t7, 0xFFFA
    ctx->r15 = S32(0XFFFA << 16);
    // 0x80070794: or          $t8, $sp, $zero
    ctx->r24 = ctx->r29 | 0;
    // 0x80070798: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007079C: ori         $t7, $t7, 0x5A5A
    ctx->r15 = ctx->r15 | 0X5A5A;
L_800707A0:
    // 0x800707A0: addiu       $t8, $t8, -0x8
    ctx->r24 = ADD32(ctx->r24, -0X8);
    // 0x800707A4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800707A8: bne         $t8, $sp, L_800707A0
    if (ctx->r24 != ctx->r29) {
        // 0x800707AC: sw          $t7, 0x4($t8)
        MEM_W(0X4, ctx->r24) = ctx->r15;
            goto L_800707A0;
    }
    // 0x800707AC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800707B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800707B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800707B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800707BC: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800707C0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800707C4: addiu       $s0, $s0, -0x79D0
    ctx->r16 = ADD32(ctx->r16, -0X79D0);
    // 0x800707C8: addiu       $s1, $s1, -0x20C0
    ctx->r17 = ADD32(ctx->r17, -0X20C0);
L_800707CC:
    // 0x800707CC: jal         0x8006F8F0
    // 0x800707D0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    Fault_Sleep(rdram, ctx);
        goto after_0;
    // 0x800707D0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x800707D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800707D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800707DC: jal         0x80074C88
    // 0x800707E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80074C88(rdram, ctx);
        goto after_1;
    // 0x800707E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800707E4: jal         0x8007FB90
    // 0x800707E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    pad_trigger(rdram, ctx);
        goto after_2;
    // 0x800707E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800707EC: andi        $t6, $v0, 0xD00F
    ctx->r14 = ctx->r2 & 0XD00F;
    // 0x800707F0: beq         $t6, $zero, L_800707CC
    if (ctx->r14 == 0) {
        // 0x800707F4: nop
    
            goto L_800707CC;
    }
    // 0x800707F4: nop

    // 0x800707F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800707FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80070800: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80070804: jr          $ra
    // 0x80070808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80070808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8046BB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046BB88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8046BB8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046BB90: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8046BB94: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8046BB98: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8046BB9C: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8046BBA0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8046BBA4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8046BBA8: lw          $t9, 0xC80($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC80);
    // 0x8046BBAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8046BBB0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8046BBB4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8046BBB8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8046BBBC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8046BBC0: sll         $t0, $t0, 6
    ctx->r8 = S32(ctx->r8 << 6);
    // 0x8046BBC4: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8046BBC8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8046BBCC: lw          $t2, 0x168($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X168);
    // 0x8046BBD0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8046BBD4: jal         0x8007711C
    // 0x8046BBD8: lw          $a3, 0x88($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X88);
    func_8007711C(rdram, ctx);
        goto after_0;
    // 0x8046BBD8: lw          $a3, 0x88($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X88);
    after_0:
    // 0x8046BBDC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8046BBE0: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8046BBE4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8046BBE8: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8046BBEC: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8046BBF0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8046BBF4: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8046BBF8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8046BBFC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8046BC00: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8046BC04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046BC08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8046BC0C: jr          $ra
    // 0x8046BC10: nop

    return;
    // 0x8046BC10: nop

;}
RECOMP_FUNC void func_804098E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804098E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804098E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804098E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804098EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804098F0: jal         0x80409810
    // 0x804098F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80409810(rdram, ctx);
        goto after_0;
    // 0x804098F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x804098F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804098FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80409900: jr          $ra
    // 0x80409904: nop

    return;
    // 0x80409904: nop

;}
RECOMP_FUNC void func_806FD5C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD5C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD5C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD5C8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806FD5CC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806FD5D0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806FD5D4: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(706, 0X116C) << 16);
    // 0x806FD5D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806FD5DC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806FD5E0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806FD5E4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806FD5E8: lw          $t8, -0x1A34($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(706, 0X116C));
    // 0x806FD5EC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806FD5F0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806FD5F4: jal         0x80048490
    // 0x806FD5F8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806FD5F8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806FD5FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FD600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FD604: jr          $ra
    // 0x806FD608: nop

    return;
    // 0x806FD608: nop

;}
RECOMP_FUNC void func_80676E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676E20: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80676E24: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80676E28: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80676E2C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80676E30: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80676E34: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80676E38: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80676E3C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80676E40: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80676E44: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80676E48: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80676E4C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80676E50: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80676E54: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80676E58: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80676E5C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80676E60: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80676E64: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x80676E68: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x80676E6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80676E70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80676E74: lwc1        $f6, 0x3EC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X3EC);
    // 0x80676E78: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80676E7C: lwc1        $f10, 0x3F0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X3F0);
    // 0x80676E80: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80676E84: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80676E88: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80676E8C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80676E90: mul.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80676E94: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80676E98: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80676E9C: nop

    // 0x80676EA0: bltz        $v0, L_806771FC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80676EA4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_806771FC;
    }
    // 0x80676EA4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80676EA8: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80676EAC: beq         $at, $zero, L_806771FC
    if (ctx->r1 == 0) {
        // 0x80676EB0: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_806771FC;
    }
    // 0x80676EB0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80676EB4: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x80676EB8: lwc1        $f6, 0x2F0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X2F0);
    // 0x80676EBC: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80676EC0: addiu       $t2, $v0, 0x6
    ctx->r10 = ADD32(ctx->r2, 0X6);
    // 0x80676EC4: addiu       $s1, $v0, -0x4
    ctx->r17 = ADD32(ctx->r2, -0X4);
    // 0x80676EC8: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80676ECC: addiu       $t1, $v0, 0x6
    ctx->r9 = ADD32(ctx->r2, 0X6);
    // 0x80676ED0: bc1fl       L_80677070
    if (!c1cs) {
        // 0x80676ED4: lhu         $t7, 0xC($s7)
        ctx->r15 = MEM_HU(ctx->r23, 0XC);
            goto L_80677070;
    }
    goto skip_0;
    // 0x80676ED4: lhu         $t7, 0xC($s7)
    ctx->r15 = MEM_HU(ctx->r23, 0XC);
    skip_0:
    // 0x80676ED8: lhu         $t9, 0xC($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XC);
    // 0x80676EDC: addiu       $fp, $zero, 0x4001
    ctx->r30 = ADD32(0, 0X4001);
    // 0x80676EE0: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80676EE4: bne         $fp, $t9, L_80676EF8
    if (ctx->r30 != ctx->r25) {
        // 0x80676EE8: addiu       $s1, $v0, -0x4
        ctx->r17 = ADD32(ctx->r2, -0X4);
            goto L_80676EF8;
    }
    // 0x80676EE8: addiu       $s1, $v0, -0x4
    ctx->r17 = ADD32(ctx->r2, -0X4);
    // 0x80676EEC: lhu         $t0, 0x408($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X408);
    // 0x80676EF0: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80676EF4: sh          $t1, 0x408($s2)
    MEM_H(0X408, ctx->r18) = ctx->r9;
L_80676EF8:
    // 0x80676EF8: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80676EFC: beq         $at, $zero, L_80677050
    if (ctx->r1 == 0) {
        // 0x80676F00: mov.s       $f22, $f24
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
            goto L_80677050;
    }
    // 0x80676F00: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x80676F04: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80676F08: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80676F0C: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X260C) << 16);
    // 0x80676F10: lui         $s4, 0x8067
    ctx->r20 = S32(RELOC_HI16(535, 0X2538) << 16);
    // 0x80676F14: addiu       $s4, $s4, 0x7BF8
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(535, 0X2538));
    // 0x80676F18: lwc1        $f28, 0x7CCC($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X260C));
    // 0x80676F1C: addiu       $s6, $s3, 0x6
    ctx->r22 = ADD32(ctx->r19, 0X6);
    // 0x80676F20: lwc1        $f26, 0xC4($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80676F24: addiu       $s5, $sp, 0x88
    ctx->r21 = ADD32(ctx->r29, 0X88);
    // 0x80676F28: slti        $at, $s1, 0x1F
    ctx->r1 = SIGNED(ctx->r17) < 0X1F ? 1 : 0;
L_80676F2C:
    // 0x80676F2C: beql        $at, $zero, L_80677048
    if (ctx->r1 == 0) {
        // 0x80676F30: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80677048;
    }
    goto skip_1;
    // 0x80676F30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80676F34: bltz        $s1, L_80677044
    if (SIGNED(ctx->r17) < 0) {
        // 0x80676F38: sll         $t3, $s1, 2
        ctx->r11 = S32(ctx->r17 << 2);
            goto L_80677044;
    }
    // 0x80676F38: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80676F3C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80676F40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80676F44: slt         $at, $s3, $s1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80676F48: addu        $s0, $s2, $t3
    ctx->r16 = ADD32(ctx->r18, ctx->r11);
    // 0x80676F4C: lwc1        $f14, 0x3E8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X3E8);
    // 0x80676F50: beq         $at, $zero, L_80676F64
    if (ctx->r1 == 0) {
        // 0x80676F54: sub.s       $f12, $f26, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f26.fl - ctx->f16.fl;
            goto L_80676F64;
    }
    // 0x80676F54: sub.s       $f12, $f26, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f26.fl - ctx->f16.fl;
    // 0x80676F58: subu        $v0, $s1, $s3
    ctx->r2 = SUB32(ctx->r17, ctx->r19);
    // 0x80676F5C: b           L_80676F68
    // 0x80676F60: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80676F68;
    // 0x80676F60: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80676F64:
    // 0x80676F64: subu        $v0, $s3, $s1
    ctx->r2 = SUB32(ctx->r19, ctx->r17);
L_80676F68:
    // 0x80676F68: lwc1        $f0, 0x2F0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80676F6C: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80676F70: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80676F74: add.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80676F78: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x80676F7C: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80676F80: add.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80676F84: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80676F88: mul.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80676F8C: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x80676F90: nop

    // 0x80676F94: bc1fl       L_80677048
    if (!c1cs) {
        // 0x80676F98: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80677048;
    }
    goto skip_2;
    // 0x80676F98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80676F9C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80676FA0: jal         0x80676DB0
    // 0x80676FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80676DB0(rdram, ctx);
        goto after_0;
    // 0x80676FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80676FA8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80676FAC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80676FB0: jal         0x80676D8C
    // 0x80676FB4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80676D8C(rdram, ctx);
        goto after_1;
    // 0x80676FB4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x80676FB8: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80676FBC: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x80676FC0: nop

    // 0x80676FC4: bc1fl       L_80676FFC
    if (!c1cs) {
        // 0x80676FC8: mtc1        $s1, $f10
        ctx->f10.u32l = ctx->r17;
            goto L_80676FFC;
    }
    goto skip_3;
    // 0x80676FC8: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    skip_3:
    // 0x80676FCC: lwc1        $f16, 0x2F0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80676FD0: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80676FD4: swc1        $f18, 0x2F0($s0)
    MEM_W(0X2F0, ctx->r16) = ctx->f18.u32l;
    // 0x80676FD8: lhu         $t6, 0xC($s7)
    ctx->r14 = MEM_HU(ctx->r23, 0XC);
    // 0x80676FDC: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80676FE0: beql        $fp, $t6, L_80676FFC
    if (ctx->r30 == ctx->r14) {
        // 0x80676FE4: mtc1        $s1, $f10
        ctx->f10.u32l = ctx->r17;
            goto L_80676FFC;
    }
    goto skip_4;
    // 0x80676FE4: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    skip_4:
    // 0x80676FE8: mul.s       $f4, $f6, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x80676FEC: lwc1        $f8, 0x36C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X36C);
    // 0x80676FF0: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80676FF4: swc1        $f16, 0x36C($s0)
    MEM_W(0X36C, ctx->r16) = ctx->f16.u32l;
    // 0x80676FF8: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
L_80676FFC:
    // 0x80676FFC: lwc1        $f8, 0x3EC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X3EC);
    // 0x80677000: lwc1        $f16, 0x2F0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80677004: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80677008: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x8067700C: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80677010: nop

    // 0x80677014: mul.s       $f0, $f4, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x80677018: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8067701C: nop

    // 0x80677020: bc1f        L_8067702C
    if (!c1cs) {
        // 0x80677024: nop
    
            goto L_8067702C;
    }
    // 0x80677024: nop

    // 0x80677028: swc1        $f0, 0x2F0($s0)
    MEM_W(0X2F0, ctx->r16) = ctx->f0.u32l;
L_8067702C:
    // 0x8067702C: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80677030: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80677034: nop

    // 0x80677038: bc1fl       L_80677048
    if (!c1cs) {
        // 0x8067703C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80677048;
    }
    goto skip_5;
    // 0x8067703C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x80677040: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_80677044:
    // 0x80677044: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80677048:
    // 0x80677048: bnel        $s1, $s6, L_80676F2C
    if (ctx->r17 != ctx->r22) {
        // 0x8067704C: slti        $at, $s1, 0x1F
        ctx->r1 = SIGNED(ctx->r17) < 0X1F ? 1 : 0;
            goto L_80676F2C;
    }
    goto skip_6;
    // 0x8067704C: slti        $at, $s1, 0x1F
    ctx->r1 = SIGNED(ctx->r17) < 0X1F ? 1 : 0;
    skip_6:
L_80677050:
    // 0x80677050: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x80677054: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80677058: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8067705C: jalr        $t9
    // 0x80677060: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80677060: nop

    after_2:
    // 0x80677064: b           L_80677200
    // 0x80677068: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
        goto L_80677200;
    // 0x80677068: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8067706C: lhu         $t7, 0xC($s7)
    ctx->r15 = MEM_HU(ctx->r23, 0XC);
L_80677070:
    // 0x80677070: addiu       $fp, $zero, 0x4001
    ctx->r30 = ADD32(0, 0X4001);
    // 0x80677074: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80677078: bne         $fp, $t7, L_8067708C
    if (ctx->r30 != ctx->r15) {
        // 0x8067707C: slt         $at, $s1, $t1
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8067708C;
    }
    // 0x8067707C: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80677080: lhu         $t8, 0x408($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X408);
    // 0x80677084: andi        $t0, $t8, 0xFFFE
    ctx->r8 = ctx->r24 & 0XFFFE;
    // 0x80677088: sh          $t0, 0x408($s2)
    MEM_H(0X408, ctx->r18) = ctx->r8;
L_8067708C:
    // 0x8067708C: beq         $at, $zero, L_806771E4
    if (ctx->r1 == 0) {
        // 0x80677090: mov.s       $f22, $f24
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
            goto L_806771E4;
    }
    // 0x80677090: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x80677094: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80677098: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8067709C: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X2610) << 16);
    // 0x806770A0: lui         $s4, 0x8067
    ctx->r20 = S32(RELOC_HI16(535, 0X2538) << 16);
    // 0x806770A4: addiu       $s4, $s4, 0x7BF8
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(535, 0X2538));
    // 0x806770A8: lwc1        $f28, 0x7CD0($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X2610));
    // 0x806770AC: addiu       $s6, $s3, 0x6
    ctx->r22 = ADD32(ctx->r19, 0X6);
    // 0x806770B0: lwc1        $f26, 0xC4($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x806770B4: addiu       $s5, $sp, 0x88
    ctx->r21 = ADD32(ctx->r29, 0X88);
    // 0x806770B8: slti        $at, $s1, 0x1F
    ctx->r1 = SIGNED(ctx->r17) < 0X1F ? 1 : 0;
L_806770BC:
    // 0x806770BC: beql        $at, $zero, L_806771DC
    if (ctx->r1 == 0) {
        // 0x806770C0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806771DC;
    }
    goto skip_7;
    // 0x806770C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x806770C4: bltz        $s1, L_806771D8
    if (SIGNED(ctx->r17) < 0) {
        // 0x806770C8: sll         $t2, $s1, 2
        ctx->r10 = S32(ctx->r17 << 2);
            goto L_806771D8;
    }
    // 0x806770C8: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x806770CC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x806770D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806770D4: lwc1        $f14, 0x3E8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X3E8);
    // 0x806770D8: slt         $at, $s3, $s1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x806770DC: addu        $s0, $s2, $t2
    ctx->r16 = ADD32(ctx->r18, ctx->r10);
    // 0x806770E0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x806770E4: beq         $at, $zero, L_806770F8
    if (ctx->r1 == 0) {
        // 0x806770E8: sub.s       $f12, $f26, $f10
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f26.fl - ctx->f10.fl;
            goto L_806770F8;
    }
    // 0x806770E8: sub.s       $f12, $f26, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f26.fl - ctx->f10.fl;
    // 0x806770EC: subu        $v0, $s1, $s3
    ctx->r2 = SUB32(ctx->r17, ctx->r19);
    // 0x806770F0: b           L_806770FC
    // 0x806770F4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_806770FC;
    // 0x806770F4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_806770F8:
    // 0x806770F8: subu        $v0, $s3, $s1
    ctx->r2 = SUB32(ctx->r19, ctx->r17);
L_806770FC:
    // 0x806770FC: lwc1        $f0, 0x2F0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80677100: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80677104: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80677108: add.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8067710C: addu        $t4, $s4, $t3
    ctx->r12 = ADD32(ctx->r20, ctx->r11);
    // 0x80677110: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80677114: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80677118: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8067711C: mul.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80677120: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x80677124: nop

    // 0x80677128: bc1fl       L_806771DC
    if (!c1cs) {
        // 0x8067712C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806771DC;
    }
    goto skip_8;
    // 0x8067712C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x80677130: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80677134: jal         0x80676DB0
    // 0x80677138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80676DB0(rdram, ctx);
        goto after_3;
    // 0x80677138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8067713C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80677140: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80677144: jal         0x80676D8C
    // 0x80677148: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80676D8C(rdram, ctx);
        goto after_4;
    // 0x80677148: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x8067714C: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80677150: c.lt.s      $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f24.fl < ctx->f16.fl;
    // 0x80677154: nop

    // 0x80677158: bc1fl       L_80677194
    if (!c1cs) {
        // 0x8067715C: mtc1        $s1, $f10
        ctx->f10.u32l = ctx->r17;
            goto L_80677194;
    }
    goto skip_9;
    // 0x8067715C: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    skip_9:
    // 0x80677160: lwc1        $f10, 0x2F0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80677164: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80677168: swc1        $f18, 0x2F0($s0)
    MEM_W(0X2F0, ctx->r16) = ctx->f18.u32l;
    // 0x8067716C: lhu         $t5, 0xC($s7)
    ctx->r13 = MEM_HU(ctx->r23, 0XC);
    // 0x80677170: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80677174: beql        $fp, $t5, L_80677194
    if (ctx->r30 == ctx->r13) {
        // 0x80677178: mtc1        $s1, $f10
        ctx->f10.u32l = ctx->r17;
            goto L_80677194;
    }
    goto skip_10;
    // 0x80677178: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    skip_10:
    // 0x8067717C: mul.s       $f0, $f6, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x80677180: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x80677184: lwc1        $f4, 0x36C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X36C);
    // 0x80677188: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8067718C: swc1        $f8, 0x36C($s0)
    MEM_W(0X36C, ctx->r16) = ctx->f8.u32l;
    // 0x80677190: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
L_80677194:
    // 0x80677194: lwc1        $f18, 0x3EC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X3EC);
    // 0x80677198: lwc1        $f4, 0x2F0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x8067719C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806771A0: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x806771A4: nop

    // 0x806771A8: mul.s       $f0, $f6, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f30.fl);
    // 0x806771AC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806771B0: nop

    // 0x806771B4: bc1f        L_806771C0
    if (!c1cs) {
        // 0x806771B8: nop
    
            goto L_806771C0;
    }
    // 0x806771B8: nop

    // 0x806771BC: swc1        $f0, 0x2F0($s0)
    MEM_W(0X2F0, ctx->r16) = ctx->f0.u32l;
L_806771C0:
    // 0x806771C0: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x806771C4: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x806771C8: nop

    // 0x806771CC: bc1fl       L_806771DC
    if (!c1cs) {
        // 0x806771D0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806771DC;
    }
    goto skip_11;
    // 0x806771D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_11:
    // 0x806771D4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_806771D8:
    // 0x806771D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_806771DC:
    // 0x806771DC: bnel        $s1, $s6, L_806770BC
    if (ctx->r17 != ctx->r22) {
        // 0x806771E0: slti        $at, $s1, 0x1F
        ctx->r1 = SIGNED(ctx->r17) < 0X1F ? 1 : 0;
            goto L_806770BC;
    }
    goto skip_12;
    // 0x806771E0: slti        $at, $s1, 0x1F
    ctx->r1 = SIGNED(ctx->r17) < 0X1F ? 1 : 0;
    skip_12:
L_806771E4:
    // 0x806771E4: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x806771E8: neg.s       $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = -ctx->f22.fl;
    // 0x806771EC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x806771F0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x806771F4: jalr        $t9
    // 0x806771F8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x806771F8: nop

    after_5:
L_806771FC:
    // 0x806771FC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80677200:
    // 0x80677200: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80677204: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80677208: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8067720C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80677210: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80677214: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80677218: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8067721C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80677220: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80677224: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80677228: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8067722C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80677230: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80677234: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80677238: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8067723C: jr          $ra
    // 0x80677240: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80677240: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80007894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007894: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80007898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000789C: jal         0x800071C8
    // 0x800078A0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800071C8(rdram, ctx);
        goto after_0;
    // 0x800078A0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800078A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800078A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800078AC: jr          $ra
    // 0x800078B0: nop

    return;
    // 0x800078B0: nop

;}
RECOMP_FUNC void func_807B877C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B877C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B8780: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B8784: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x807B8788: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x807B878C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807B8790: jal         0x807B8298
    // 0x807B8794: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_807B8298(rdram, ctx);
        goto after_0;
    // 0x807B8794: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x807B8798: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x807B879C: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x807B87A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B87A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B87A8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807B87AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807B87B0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x807B87B4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807B87B8: lui         $a0, 0x807C
    ctx->r4 = S32(RELOC_HI16(886, 0X1C10) << 16);
    // 0x807B87BC: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x807B87C0: lui         $a2, 0x4188
    ctx->r6 = S32(0X4188 << 16);
    // 0x807B87C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807B87C8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x807B87CC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x807B87D0: ori         $a2, $a2, 0x51EB
    ctx->r6 = ctx->r6 | 0X51EB;
    // 0x807B87D4: lhu         $a0, -0x6180($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(886, 0X1C10));
    // 0x807B87D8: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    // 0x807B87DC: jal         0x8005CEBC
    // 0x807B87E0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_1;
    // 0x807B87E0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x807B87E4: lw          $t2, 0x3C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X3C);
    // 0x807B87E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B87EC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x807B87F0: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x807B87F4: jal         0x807B8314
    // 0x807B87F8: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_2;
    // 0x807B87F8: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    after_2:
    // 0x807B87FC: lw          $t5, 0x44($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X44);
    // 0x807B8800: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x807B8804: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807B8808: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x807B880C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x807B8810: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x807B8814: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x807B8818: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x807B881C: lui         $a0, 0x807C
    ctx->r4 = S32(RELOC_HI16(886, 0X1C10) << 16);
    // 0x807B8820: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x807B8824: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807B8828: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x807B882C: lhu         $a0, -0x6180($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(886, 0X1C10));
    // 0x807B8830: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x807B8834: lui         $a2, 0x4180
    ctx->r6 = S32(0X4180 << 16);
    // 0x807B8838: lui         $a3, 0xC1C0
    ctx->r7 = S32(0XC1C0 << 16);
    // 0x807B883C: jal         0x8005CEBC
    // 0x807B8840: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_3;
    // 0x807B8840: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x807B8844: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x807B8848: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B884C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x807B8850: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x807B8854: jal         0x807B8314
    // 0x807B8858: sw          $v0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_4;
    // 0x807B8858: sw          $v0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r2;
    after_4:
    // 0x807B885C: jal         0x807B8340
    // 0x807B8860: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807B8340(rdram, ctx);
        goto after_5;
    // 0x807B8860: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x807B8864: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B8868: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807B886C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807B8870: jr          $ra
    // 0x807B8874: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B8874: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_807C5F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C5F18: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807C5F1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807C5F20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x807C5F24: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C5F28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807C5F2C: jal         0x8004700C
    // 0x807C5F30: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807C5F30: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_0:
    // 0x807C5F34: beq         $v0, $zero, L_807C616C
    if (ctx->r2 == 0) {
        // 0x807C5F38: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_807C616C;
    }
    // 0x807C5F38: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x807C5F3C: lbu         $a0, 0x18($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X18);
    // 0x807C5F40: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x807C5F44: bne         $a1, $a0, L_807C5F94
    if (ctx->r5 != ctx->r4) {
        // 0x807C5F48: nop
    
            goto L_807C5F94;
    }
    // 0x807C5F48: nop

    // 0x807C5F4C: lw          $t6, 0x10($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X10);
    // 0x807C5F50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807C5F54: bne         $t6, $zero, L_807C5F8C
    if (ctx->r14 != 0) {
        // 0x807C5F58: nop
    
            goto L_807C5F8C;
    }
    // 0x807C5F58: nop

    // 0x807C5F5C: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x807C5F60: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x807C5F64: beq         $v1, $at, L_807C5F8C
    if (ctx->r3 == ctx->r1) {
        // 0x807C5F68: nop
    
            goto L_807C5F8C;
    }
    // 0x807C5F68: nop

    // 0x807C5F6C: beq         $a1, $v1, L_807C5F8C
    if (ctx->r5 == ctx->r3) {
        // 0x807C5F70: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_807C5F8C;
    }
    // 0x807C5F70: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x807C5F74: beq         $v1, $at, L_807C5F8C
    if (ctx->r3 == ctx->r1) {
        // 0x807C5F78: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_807C5F8C;
    }
    // 0x807C5F78: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x807C5F7C: beq         $v1, $at, L_807C5F8C
    if (ctx->r3 == ctx->r1) {
        // 0x807C5F80: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_807C5F8C;
    }
    // 0x807C5F80: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x807C5F84: bne         $v1, $at, L_807C5F94
    if (ctx->r3 != ctx->r1) {
        // 0x807C5F88: nop
    
            goto L_807C5F94;
    }
    // 0x807C5F88: nop

L_807C5F8C:
    // 0x807C5F8C: b           L_807C616C
    // 0x807C5F90: sw          $t7, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r15;
        goto L_807C616C;
    // 0x807C5F90: sw          $t7, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r15;
L_807C5F94:
    // 0x807C5F94: bne         $a1, $a0, L_807C600C
    if (ctx->r5 != ctx->r4) {
        // 0x807C5F98: nop
    
            goto L_807C600C;
    }
    // 0x807C5F98: nop

    // 0x807C5F9C: lw          $t8, 0x10($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X10);
    // 0x807C5FA0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x807C5FA4: bne         $t8, $zero, L_807C6004
    if (ctx->r24 != 0) {
        // 0x807C5FA8: nop
    
            goto L_807C6004;
    }
    // 0x807C5FA8: nop

    // 0x807C5FAC: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x807C5FB0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x807C5FB4: beq         $v1, $zero, L_807C6004
    if (ctx->r3 == 0) {
        // 0x807C5FB8: nop
    
            goto L_807C6004;
    }
    // 0x807C5FB8: nop

    // 0x807C5FBC: beq         $v1, $at, L_807C6004
    if (ctx->r3 == ctx->r1) {
        // 0x807C5FC0: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_807C6004;
    }
    // 0x807C5FC0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x807C5FC4: beq         $v1, $at, L_807C6004
    if (ctx->r3 == ctx->r1) {
        // 0x807C5FC8: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_807C6004;
    }
    // 0x807C5FC8: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x807C5FCC: beq         $v1, $at, L_807C6004
    if (ctx->r3 == ctx->r1) {
        // 0x807C5FD0: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_807C6004;
    }
    // 0x807C5FD0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x807C5FD4: beq         $v1, $at, L_807C6004
    if (ctx->r3 == ctx->r1) {
        // 0x807C5FD8: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_807C6004;
    }
    // 0x807C5FD8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x807C5FDC: beq         $v1, $at, L_807C6004
    if (ctx->r3 == ctx->r1) {
        // 0x807C5FE0: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_807C6004;
    }
    // 0x807C5FE0: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x807C5FE4: beq         $v1, $at, L_807C6004
    if (ctx->r3 == ctx->r1) {
        // 0x807C5FE8: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_807C6004;
    }
    // 0x807C5FE8: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x807C5FEC: beq         $v1, $at, L_807C6004
    if (ctx->r3 == ctx->r1) {
        // 0x807C5FF0: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_807C6004;
    }
    // 0x807C5FF0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x807C5FF4: beq         $v1, $at, L_807C6004
    if (ctx->r3 == ctx->r1) {
        // 0x807C5FF8: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_807C6004;
    }
    // 0x807C5FF8: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x807C5FFC: bne         $v1, $at, L_807C600C
    if (ctx->r3 != ctx->r1) {
        // 0x807C6000: nop
    
            goto L_807C600C;
    }
    // 0x807C6000: nop

L_807C6004:
    // 0x807C6004: b           L_807C616C
    // 0x807C6008: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
        goto L_807C616C;
    // 0x807C6008: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
L_807C600C:
    // 0x807C600C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807C6010: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807C6014: lw          $t1, 0xE88($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XE88);
    // 0x807C6018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807C601C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807C6020: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x807C6024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C6028: bnel        $t2, $at, L_807C6044
    if (ctx->r10 != ctx->r1) {
        // 0x807C602C: lw          $v0, 0x8($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X8);
            goto L_807C6044;
    }
    goto skip_0;
    // 0x807C602C: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    skip_0:
    // 0x807C6030: jal         0x807C66CC
    // 0x807C6034: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_807C66CC(rdram, ctx);
        goto after_1;
    // 0x807C6034: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x807C6038: b           L_807C6170
    // 0x807C603C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_807C6170;
    // 0x807C603C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807C6040: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
L_807C6044:
    // 0x807C6044: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x807C6048: beq         $v0, $zero, L_807C6054
    if (ctx->r2 == 0) {
        // 0x807C604C: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_807C6054;
    }
    // 0x807C604C: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x807C6050: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
L_807C6054:
    // 0x807C6054: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x807C6058: beq         $v0, $zero, L_807C6068
    if (ctx->r2 == 0) {
        // 0x807C605C: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_807C6068;
    }
    // 0x807C605C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x807C6060: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x807C6064: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_807C6068:
    // 0x807C6068: bnel        $v0, $zero, L_807C60BC
    if (ctx->r2 != 0) {
        // 0x807C606C: lwc1        $f4, 0x14($t0)
        ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
            goto L_807C60BC;
    }
    goto skip_1;
    // 0x807C606C: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    skip_1:
    // 0x807C6070: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x807C6074: lh          $t6, 0x144($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X144);
    // 0x807C6078: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807C607C: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x807C6080: sh          $t8, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r24;
    // 0x807C6084: lh          $t9, 0x144($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X144);
    // 0x807C6088: bnel        $t9, $zero, L_807C60BC
    if (ctx->r25 != 0) {
        // 0x807C608C: lwc1        $f4, 0x14($t0)
        ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
            goto L_807C60BC;
    }
    goto skip_2;
    // 0x807C608C: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    skip_2:
    // 0x807C6090: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x807C6094: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x807C6098: jal         0x80067BBC
    // 0x807C609C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x807C609C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_2:
    // 0x807C60A0: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    // 0x807C60A4: jal         0x80067818
    // 0x807C60A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x807C60A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x807C60AC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807C60B0: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807C60B4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x807C60B8: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
L_807C60BC:
    // 0x807C60BC: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x807C60C0: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x807C60C4: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x807C60C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807C60CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807C60D0: swc1        $f8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f8.u32l;
    // 0x807C60D4: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x807C60D8: lwc1        $f16, 0x14($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X14);
    // 0x807C60DC: lwc1        $f10, 0x30($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X30);
    // 0x807C60E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x807C60E4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x807C60E8: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x807C60EC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x807C60F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807C60F4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x807C60F8: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x807C60FC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807C6100: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x807C6104: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x807C6108: bnel        $t1, $zero, L_807C6170
    if (ctx->r9 != 0) {
        // 0x807C610C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_807C6170;
    }
    goto skip_3;
    // 0x807C610C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x807C6110: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807C6114: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    // 0x807C6118: lw          $t3, 0xA68($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XA68);
    // 0x807C611C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x807C6120: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x807C6124: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x807C6128: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807C612C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807C6130: lw          $t9, 0x40($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X40);
    // 0x807C6134: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x807C6138: lui         $a3, 0xC100
    ctx->r7 = S32(0XC100 << 16);
    // 0x807C613C: jalr        $t9
    // 0x807C6140: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x807C6140: nop

    after_4:
    // 0x807C6144: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x807C6148: jal         0x80067BBC
    // 0x807C614C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x807C614C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x807C6150: addiu       $a0, $zero, 0xC6
    ctx->r4 = ADD32(0, 0XC6);
    // 0x807C6154: jal         0x80067818
    // 0x807C6158: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x807C6158: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x807C615C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807C6160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C6164: jal         0x807C66CC
    // 0x807C6168: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_807C66CC(rdram, ctx);
        goto after_7;
    // 0x807C6168: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
L_807C616C:
    // 0x807C616C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_807C6170:
    // 0x807C6170: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x807C6174: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x807C6178: jr          $ra
    // 0x807C617C: nop

    return;
    // 0x807C617C: nop

;}
RECOMP_FUNC void func_8046292C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046292C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80462930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80462934: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80462938: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8046293C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80462940: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X3920) << 16);
    // 0x80462944: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80462948: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8046294C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80462950: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80462954: lw          $t8, 0x3EB0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(122, 0X3920));
    // 0x80462958: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8046295C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80462960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80462964: jal         0x80048490
    // 0x80462968: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80462968: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8046296C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80462970: jal         0x80048378
    // 0x80462974: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80462974: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80462978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046297C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80462980: jr          $ra
    // 0x80462984: nop

    return;
    // 0x80462984: nop

;}
RECOMP_FUNC void func_8059F360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059F360: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8059F364: addiu       $at, $zero, 0x4059
    ctx->r1 = ADD32(0, 0X4059);
    // 0x8059F368: beq         $v0, $at, L_8059F390
    if (ctx->r2 == ctx->r1) {
        // 0x8059F36C: addiu       $at, $zero, 0x405A
        ctx->r1 = ADD32(0, 0X405A);
            goto L_8059F390;
    }
    // 0x8059F36C: addiu       $at, $zero, 0x405A
    ctx->r1 = ADD32(0, 0X405A);
    // 0x8059F370: beq         $v0, $at, L_8059F3A8
    if (ctx->r2 == ctx->r1) {
        // 0x8059F374: addiu       $at, $zero, 0x44FD
        ctx->r1 = ADD32(0, 0X44FD);
            goto L_8059F3A8;
    }
    // 0x8059F374: addiu       $at, $zero, 0x44FD
    ctx->r1 = ADD32(0, 0X44FD);
    // 0x8059F378: beq         $v0, $at, L_8059F39C
    if (ctx->r2 == ctx->r1) {
        // 0x8059F37C: addiu       $at, $zero, 0x44FF
        ctx->r1 = ADD32(0, 0X44FF);
            goto L_8059F39C;
    }
    // 0x8059F37C: addiu       $at, $zero, 0x44FF
    ctx->r1 = ADD32(0, 0X44FF);
    // 0x8059F380: beq         $v0, $at, L_8059F3B4
    if (ctx->r2 == ctx->r1) {
        // 0x8059F384: nop
    
            goto L_8059F3B4;
    }
    // 0x8059F384: nop

    // 0x8059F388: b           L_8059F3C0
    // 0x8059F38C: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(408, 0X12F8) << 16);
        goto L_8059F3C0;
    // 0x8059F38C: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(408, 0X12F8) << 16);
L_8059F390:
    // 0x8059F390: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(408, 0X118C) << 16);
    // 0x8059F394: jr          $ra
    // 0x8059F398: addiu       $v0, $v0, 0x4EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(408, 0X118C));
    return;
    // 0x8059F398: addiu       $v0, $v0, 0x4EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(408, 0X118C));
L_8059F39C:
    // 0x8059F39C: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(408, 0X12F8) << 16);
    // 0x8059F3A0: jr          $ra
    // 0x8059F3A4: addiu       $v0, $v0, 0x658
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(408, 0X12F8));
    return;
    // 0x8059F3A4: addiu       $v0, $v0, 0x658
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(408, 0X12F8));
L_8059F3A8:
    // 0x8059F3A8: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(408, 0X122C) << 16);
    // 0x8059F3AC: jr          $ra
    // 0x8059F3B0: addiu       $v0, $v0, 0x58C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(408, 0X122C));
    return;
    // 0x8059F3B0: addiu       $v0, $v0, 0x58C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(408, 0X122C));
L_8059F3B4:
    // 0x8059F3B4: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(408, 0X1330) << 16);
    // 0x8059F3B8: jr          $ra
    // 0x8059F3BC: addiu       $v0, $v0, 0x690
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(408, 0X1330));
    return;
    // 0x8059F3BC: addiu       $v0, $v0, 0x690
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(408, 0X1330));
L_8059F3C0:
    // 0x8059F3C0: addiu       $v0, $v0, 0x658
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(408, 0X12F8));
    // 0x8059F3C4: jr          $ra
    // 0x8059F3C8: nop

    return;
    // 0x8059F3C8: nop

;}
RECOMP_FUNC void func_80052290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052290: jr          $ra
    // 0x80052294: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80052294: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807A6710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A6714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A6718: jal         0x807A6514
    // 0x807A671C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807A6514(rdram, ctx);
        goto after_0;
    // 0x807A671C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A6720: beq         $v0, $zero, L_807A6768
    if (ctx->r2 == 0) {
        // 0x807A6724: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807A6768;
    }
    // 0x807A6724: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A6728: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x807A672C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x807A6730: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x807A6734: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(847, 0X14B8) << 16);
    // 0x807A6738: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x807A673C: addiu       $t7, $t7, 0x71B8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(847, 0X14B8));
    // 0x807A6740: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807A6744: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807A6748: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807A674C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807A6750: jal         0x807A6640
    // 0x807A6754: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807A6640(rdram, ctx);
        goto after_1;
    // 0x807A6754: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x807A6758: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A675C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A6760: jal         0x807A6778
    // 0x807A6764: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807A6778(rdram, ctx);
        goto after_2;
    // 0x807A6764: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_807A6768:
    // 0x807A6768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A676C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A6770: jr          $ra
    // 0x807A6774: nop

    return;
    // 0x807A6774: nop

;}
RECOMP_FUNC void func_80052298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052298: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8005229C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800522A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800522A4: sw          $zero, 0xED4($v0)
    MEM_W(0XED4, ctx->r2) = 0;
    // 0x800522A8: sw          $zero, 0xE7C($v0)
    MEM_W(0XE7C, ctx->r2) = 0;
    // 0x800522AC: sw          $zero, 0xE80($v0)
    MEM_W(0XE80, ctx->r2) = 0;
    // 0x800522B0: jr          $ra
    // 0x800522B4: sw          $zero, 0xE84($v0)
    MEM_W(0XE84, ctx->r2) = 0;
    return;
    // 0x800522B4: sw          $zero, 0xE84($v0)
    MEM_W(0XE84, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8079B840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079B840: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8079B844: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8079B848: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8079B84C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8079B850: nop

    // 0x8079B854: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8079B858: nop

    // 0x8079B85C: bc1fl       L_8079B88C
    if (!c1cs) {
        // 0x8079B860: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8079B88C;
    }
    goto skip_0;
    // 0x8079B860: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8079B864: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8079B868: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8079B86C: nop

    // 0x8079B870: bc1f        L_8079B8A8
    if (!c1cs) {
        // 0x8079B874: nop
    
            goto L_8079B8A8;
    }
    // 0x8079B874: nop

    // 0x8079B878: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8079B87C: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8079B880: jr          $ra
    // 0x8079B884: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8079B884: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8079B888: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_8079B88C:
    // 0x8079B88C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8079B890: nop

    // 0x8079B894: bc1f        L_8079B8A8
    if (!c1cs) {
        // 0x8079B898: nop
    
            goto L_8079B8A8;
    }
    // 0x8079B898: nop

    // 0x8079B89C: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8079B8A0: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8079B8A4: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_8079B8A8:
    // 0x8079B8A8: jr          $ra
    // 0x8079B8AC: nop

    return;
    // 0x8079B8AC: nop

;}
RECOMP_FUNC void func_8043AD54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043AD54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043AD58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043AD5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043AD60: jal         0x8043AC18
    // 0x8043AD64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8043AC18(rdram, ctx);
        goto after_0;
    // 0x8043AD64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8043AD68: jal         0x8043AC3C
    // 0x8043AD6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043AC3C(rdram, ctx);
        goto after_1;
    // 0x8043AD6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8043AD70: jal         0x8043AC8C
    // 0x8043AD74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043AC8C(rdram, ctx);
        goto after_2;
    // 0x8043AD74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8043AD78: jal         0x8043ACF0
    // 0x8043AD7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043ACF0(rdram, ctx);
        goto after_3;
    // 0x8043AD7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043AD80: jal         0x8043A6F4
    // 0x8043AD84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043A6F4(rdram, ctx);
        goto after_4;
    // 0x8043AD84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8043AD88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043AD8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043AD90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043AD94: jr          $ra
    // 0x8043AD98: nop

    return;
    // 0x8043AD98: nop

;}
RECOMP_FUNC void func_8042FF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FF34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042FF38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042FF3C: lwc1        $f6, 0xDC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x8042FF40: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042FF44: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8042FF48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042FF4C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8042FF50: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8042FF54: bc1tl       L_8042FF88
    if (c1cs) {
        // 0x8042FF58: lw          $a3, 0x138($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X138);
            goto L_8042FF88;
    }
    goto skip_0;
    // 0x8042FF58: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    skip_0:
    // 0x8042FF5C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042FF60: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8042FF64: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8042FF68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042FF6C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8042FF70: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8042FF74: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042FF78: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8042FF7C: b           L_8042FFB0
    // 0x8042FF80: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
        goto L_8042FFB0;
    // 0x8042FF80: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    // 0x8042FF84: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
L_8042FF88:
    // 0x8042FF88: jal         0x804303F0
    // 0x8042FF8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804303F0(rdram, ctx);
        goto after_0;
    // 0x8042FF8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042FF90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042FF94: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X18C8) << 16);
    // 0x8042FF98: addiu       $t6, $t6, -0x658
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X18C8));
    // 0x8042FF9C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BC0) << 16);
    // 0x8042FFA0: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8042FFA4: lwc1        $f8, 0x1CA0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BC0));
    // 0x8042FFA8: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FFAC: swc1        $f8, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f8.u32l;
L_8042FFB0:
    // 0x8042FFB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042FFB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042FFB8: jr          $ra
    // 0x8042FFBC: nop

    return;
    // 0x8042FFBC: nop

;}
RECOMP_FUNC void func_80533B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533B60: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80533B64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80533B68: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80533B6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80533B70: jal         0x8004700C
    // 0x80533B74: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80533B74: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x80533B78: beq         $v0, $zero, L_80533D00
    if (ctx->r2 == 0) {
        // 0x80533B7C: lwc1        $f20, 0x84($s0)
        ctx->f20.u32l = MEM_W(ctx->r16, 0X84);
            goto L_80533D00;
    }
    // 0x80533B7C: lwc1        $f20, 0x84($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80533B80: lwc1        $f0, 0x84($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80533B84: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80533B88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80533B8C: sub.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80533B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80533B94: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80533B98: nop

    // 0x80533B9C: bc1fl       L_80533D04
    if (!c1cs) {
        // 0x80533BA0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80533D04;
    }
    goto skip_0;
    // 0x80533BA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80533BA4: lwc1        $f0, 0x88($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80533BA8: lwc1        $f2, 0x8C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80533BAC: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80533BB0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80533BB4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80533BB8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80533BBC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80533BC0: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80533BC4: jal         0x80533A80
    // 0x80533BC8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80533A80(rdram, ctx);
        goto after_1;
    // 0x80533BC8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_1:
    // 0x80533BCC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80533BD0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80533BD4: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80533BD8: bne         $v0, $zero, L_80533BF0
    if (ctx->r2 != 0) {
        // 0x80533BDC: addiu       $t0, $v1, 0x14
        ctx->r8 = ADD32(ctx->r3, 0X14);
            goto L_80533BF0;
    }
    // 0x80533BDC: addiu       $t0, $v1, 0x14
    ctx->r8 = ADD32(ctx->r3, 0X14);
    // 0x80533BE0: jal         0x800445A4
    // 0x80533BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80533BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80533BE8: b           L_80533D04
    // 0x80533BEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80533D04;
    // 0x80533BEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80533BF0:
    // 0x80533BF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80533BF4: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80533BF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80533BFC: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80533C00: add.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x80533C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80533C08: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80533C0C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80533C10: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80533C14: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80533C18: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80533C1C: jal         0x80533A80
    // 0x80533C20: nop

    func_80533A80(rdram, ctx);
        goto after_3;
    // 0x80533C20: nop

    after_3:
    // 0x80533C24: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80533C28: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80533C2C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80533C30: bne         $v0, $zero, L_80533C48
    if (ctx->r2 != 0) {
        // 0x80533C34: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80533C48;
    }
    // 0x80533C34: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80533C38: jal         0x800445A4
    // 0x80533C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x80533C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80533C40: b           L_80533D04
    // 0x80533C44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80533D04;
    // 0x80533C44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80533C48:
    // 0x80533C48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80533C4C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80533C50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80533C54: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80533C58: add.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x80533C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80533C60: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80533C64: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80533C68: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80533C6C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80533C70: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80533C74: jal         0x80533A80
    // 0x80533C78: nop

    func_80533A80(rdram, ctx);
        goto after_5;
    // 0x80533C78: nop

    after_5:
    // 0x80533C7C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80533C80: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80533C84: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80533C88: bne         $v0, $zero, L_80533CA0
    if (ctx->r2 != 0) {
        // 0x80533C8C: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80533CA0;
    }
    // 0x80533C8C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80533C90: jal         0x800445A4
    // 0x80533C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x80533C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80533C98: b           L_80533D04
    // 0x80533C9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80533D04;
    // 0x80533C9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80533CA0:
    // 0x80533CA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80533CA4: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x80533CA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80533CAC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80533CB0: add.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x80533CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80533CB8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80533CBC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80533CC0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80533CC4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80533CC8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80533CCC: jal         0x80533A80
    // 0x80533CD0: nop

    func_80533A80(rdram, ctx);
        goto after_7;
    // 0x80533CD0: nop

    after_7:
    // 0x80533CD4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80533CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80533CDC: bne         $v0, $zero, L_80533CF4
    if (ctx->r2 != 0) {
        // 0x80533CE0: sw          $v0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r2;
            goto L_80533CF4;
    }
    // 0x80533CE0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80533CE4: jal         0x800445A4
    // 0x80533CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x80533CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80533CEC: b           L_80533D04
    // 0x80533CF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80533D04;
    // 0x80533CF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80533CF4:
    // 0x80533CF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80533CF8: jal         0x805341DC
    // 0x80533CFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805341DC(rdram, ctx);
        goto after_9;
    // 0x80533CFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
L_80533D00:
    // 0x80533D00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80533D04:
    // 0x80533D04: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80533D08: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80533D0C: jr          $ra
    // 0x80533D10: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80533D10: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8043AA34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043AA34: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8043AA38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043AA3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043AA40: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8043AA44: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8043AA48: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8043AA4C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8043AA50: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8043AA54: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8043AA58: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8043AA5C: lh          $t8, 0x56($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X56);
    // 0x8043AA60: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x8043AA64: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8043AA68: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8043AA6C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8043AA70: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8043AA74: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8043AA78: lwc1        $f16, 0xC4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x8043AA7C: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x8043AA80: jal         0x80047AB8
    // 0x8043AA84: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8043AA84: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8043AA88: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8043AA8C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8043AA90: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8043AA94: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8043AA98: sub.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8043AA9C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8043AAA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8043AAA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8043AAA8: add.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8043AAAC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8043AAB0: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8043AAB4: div.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8043AAB8: c.le.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl <= ctx->f12.fl;
    // 0x8043AABC: nop

    // 0x8043AAC0: bc1fl       L_8043AC08
    if (!c1cs) {
        // 0x8043AAC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8043AC08;
    }
    goto skip_0;
    // 0x8043AAC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8043AAC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8043AACC: nop

    // 0x8043AAD0: c.le.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl <= ctx->f16.fl;
    // 0x8043AAD4: nop

    // 0x8043AAD8: bc1fl       L_8043AC08
    if (!c1cs) {
        // 0x8043AADC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8043AC08;
    }
    goto skip_1;
    // 0x8043AADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8043AAE0: jal         0x80081FB0
    // 0x8043AAE4: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    Math_FAcosF(rdram, ctx);
        goto after_1;
    // 0x8043AAE4: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    after_1:
    // 0x8043AAE8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11B4) << 16);
    // 0x8043AAEC: lwc1        $f18, -0x47EC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11B4));
    // 0x8043AAF0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8043AAF4: addiu       $at, $zero, 0x40BE
    ctx->r1 = ADD32(0, 0X40BE);
    // 0x8043AAF8: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8043AAFC: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8043AB00: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8043AB04: bnel        $v0, $at, L_8043AB40
    if (ctx->r2 != ctx->r1) {
        // 0x8043AB08: addiu       $at, $zero, 0x40BF
        ctx->r1 = ADD32(0, 0X40BF);
            goto L_8043AB40;
    }
    goto skip_2;
    // 0x8043AB08: addiu       $at, $zero, 0x40BF
    ctx->r1 = ADD32(0, 0X40BF);
    skip_2:
    // 0x8043AB0C: lw          $t9, 0x1F4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X1F4);
    // 0x8043AB10: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8043AB14: jal         0x80066E88
    // 0x8043AB18: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8043AB18: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_2:
    // 0x8043AB1C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11B8) << 16);
    // 0x8043AB20: lwc1        $f8, -0x47E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11B8));
    // 0x8043AB24: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8043AB28: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8043AB2C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8043AB30: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8043AB34: b           L_8043AB68
    // 0x8043AB38: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_8043AB68;
    // 0x8043AB38: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8043AB3C: addiu       $at, $zero, 0x40BF
    ctx->r1 = ADD32(0, 0X40BF);
L_8043AB40:
    // 0x8043AB40: bnel        $v0, $at, L_8043AB58
    if (ctx->r2 != ctx->r1) {
        // 0x8043AB44: addiu       $at, $zero, 0x40C0
        ctx->r1 = ADD32(0, 0X40C0);
            goto L_8043AB58;
    }
    goto skip_3;
    // 0x8043AB44: addiu       $at, $zero, 0x40C0
    ctx->r1 = ADD32(0, 0X40C0);
    skip_3:
    // 0x8043AB48: lw          $t0, 0x1F4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1F4);
    // 0x8043AB4C: b           L_8043AB68
    // 0x8043AB50: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
        goto L_8043AB68;
    // 0x8043AB50: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8043AB54: addiu       $at, $zero, 0x40C0
    ctx->r1 = ADD32(0, 0X40C0);
L_8043AB58:
    // 0x8043AB58: bne         $v0, $at, L_8043AB68
    if (ctx->r2 != ctx->r1) {
        // 0x8043AB5C: nop
    
            goto L_8043AB68;
    }
    // 0x8043AB5C: nop

    // 0x8043AB60: lw          $t1, 0x1F4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X1F4);
    // 0x8043AB64: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_8043AB68:
    // 0x8043AB68: jal         0x80066DE4
    // 0x8043AB6C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8043AB6C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8043AB70: jal         0x80065954
    // 0x8043AB74: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x8043AB74: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x8043AB78: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11BC) << 16);
    // 0x8043AB7C: lwc1        $f2, -0x47E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11BC));
    // 0x8043AB80: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11C4) << 16);
    // 0x8043AB84: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8043AB88: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8043AB8C: nop

    // 0x8043AB90: bc1fl       L_8043ABE0
    if (!c1cs) {
        // 0x8043AB94: lwc1        $f8, 0x0($t3)
        ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
            goto L_8043ABE0;
    }
    goto skip_4;
    // 0x8043AB94: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    skip_4:
    // 0x8043AB98: jal         0x80066DE4
    // 0x8043AB9C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x8043AB9C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x8043ABA0: jal         0x80065954
    // 0x8043ABA4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_6;
    // 0x8043ABA4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x8043ABA8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8043ABAC: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11C0) << 16);
    // 0x8043ABB0: lwc1        $f6, -0x47E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11C0));
    // 0x8043ABB4: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8043ABB8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8043ABBC: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8043ABC0: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8043ABC4: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8043ABC8: nop

    // 0x8043ABCC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8043ABD0: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8043ABD4: b           L_8043AC04
    // 0x8043ABD8: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
        goto L_8043AC04;
    // 0x8043ABD8: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x8043ABDC: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
L_8043ABE0:
    // 0x8043ABE0: lwc1        $f4, -0x47DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11C4));
    // 0x8043ABE4: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8043ABE8: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8043ABEC: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8043ABF0: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8043ABF4: nop

    // 0x8043ABF8: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8043ABFC: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8043AC00: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
L_8043AC04:
    // 0x8043AC04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043AC08:
    // 0x8043AC08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043AC0C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8043AC10: jr          $ra
    // 0x8043AC14: nop

    return;
    // 0x8043AC14: nop

;}
RECOMP_FUNC void func_80027DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027DAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027DB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027DB4: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80027DB8: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80027DBC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80027DC0: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x80027DC4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80027DC8: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x80027DCC: bnel        $at, $zero, L_80027E64
    if (ctx->r1 != 0) {
        // 0x80027DD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80027E64;
    }
    goto skip_0;
    // 0x80027DD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80027DD4: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x80027DD8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80027DDC: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80027DE0: xori        $v1, $v1, 0x19
    ctx->r3 = ctx->r3 ^ 0X19;
    // 0x80027DE4: bne         $t0, $zero, L_80027E20
    if (ctx->r8 != 0) {
        // 0x80027DE8: sltiu       $v1, $v1, 0x1
        ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
            goto L_80027E20;
    }
    // 0x80027DE8: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80027DEC: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x80027DF0: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80027DF4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80027DF8: lw          $t2, -0x3A08($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3A08);
    // 0x80027DFC: lw          $v0, 0x14C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C);
    // 0x80027E00: bne         $v0, $t2, L_80027E18
    if (ctx->r2 != ctx->r10) {
        // 0x80027E04: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_80027E18;
    }
    // 0x80027E04: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80027E08: jal         0x80027D5C
    // 0x80027E0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80027D5C(rdram, ctx);
        goto after_0;
    // 0x80027E0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027E10: b           L_80027E5C
    // 0x80027E14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80027E5C;
    // 0x80027E14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80027E18:
    // 0x80027E18: b           L_80027E5C
    // 0x80027E1C: sw          $t3, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r11;
        goto L_80027E5C;
    // 0x80027E1C: sw          $t3, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r11;
L_80027E20:
    // 0x80027E20: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x80027E24: addu        $t4, $t4, $a1
    ctx->r12 = ADD32(ctx->r12, ctx->r5);
    // 0x80027E28: lw          $t4, -0x3A08($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3A08);
    // 0x80027E2C: lw          $v0, 0x14C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C);
    // 0x80027E30: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x80027E34: addu        $t5, $t5, $a1
    ctx->r13 = ADD32(ctx->r13, ctx->r5);
    // 0x80027E38: bne         $v0, $t4, L_80027E58
    if (ctx->r2 != ctx->r12) {
        // 0x80027E3C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80027E58;
    }
    // 0x80027E3C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80027E40: lw          $t5, -0x3A00($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3A00);
    // 0x80027E44: sw          $t5, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r13;
    // 0x80027E48: jal         0x80027D78
    // 0x80027E4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80027D78(rdram, ctx);
        goto after_1;
    // 0x80027E4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80027E50: b           L_80027E5C
    // 0x80027E54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80027E5C;
    // 0x80027E54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80027E58:
    // 0x80027E58: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
L_80027E5C:
    // 0x80027E5C: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80027E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80027E64:
    // 0x80027E64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80027E6C: jr          $ra
    // 0x80027E70: nop

    return;
    // 0x80027E70: nop

;}
RECOMP_FUNC void func_80535890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535890: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(351, 0X1230) << 16);
    // 0x80535894: jr          $ra
    // 0x80535898: addiu       $v0, $v0, 0x6AC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(351, 0X1230));
    return;
    // 0x80535898: addiu       $v0, $v0, 0x6AC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(351, 0X1230));
;}
RECOMP_FUNC void func_804549D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804549D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804549D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804549DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804549E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804549E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804549E8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x804549EC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14114) << 16);
    // 0x804549F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804549F4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x804549F8: lwc1        $f10, -0x7B0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14114));
    // 0x804549FC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80454A00: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14118) << 16);
    // 0x80454A04: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80454A08: nop

    // 0x80454A0C: bc1f        L_80454A1C
    if (!c1cs) {
        // 0x80454A10: nop
    
            goto L_80454A1C;
    }
    // 0x80454A10: nop

    // 0x80454A14: b           L_80454C34
    // 0x80454A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80454C34;
    // 0x80454A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80454A1C:
    // 0x80454A1C: lwc1        $f16, -0x7B08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14118));
    // 0x80454A20: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80454A24: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1411C) << 16);
    // 0x80454A28: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80454A2C: nop

    // 0x80454A30: bc1f        L_80454A7C
    if (!c1cs) {
        // 0x80454A34: nop
    
            goto L_80454A7C;
    }
    // 0x80454A34: nop

    // 0x80454A38: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80454A3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80454A40: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80454A44: beql        $t7, $zero, L_80454C34
    if (ctx->r15 == 0) {
        // 0x80454A48: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80454C34;
    }
    goto skip_0;
    // 0x80454A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80454A4C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80454A50: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80454A54: jal         0x80450B18
    // 0x80454A58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_0;
    // 0x80454A58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80454A5C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80454A60: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80454A64: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80454A68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80454A6C: jal         0x80445E2C
    // 0x80454A70: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    func_80445E2C(rdram, ctx);
        goto after_1;
    // 0x80454A70: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    after_1:
    // 0x80454A74: b           L_80454C34
    // 0x80454A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80454C34;
    // 0x80454A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80454A7C:
    // 0x80454A7C: lwc1        $f18, -0x7B04($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1411C));
    // 0x80454A80: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80454A84: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14120) << 16);
    // 0x80454A88: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80454A8C: nop

    // 0x80454A90: bc1f        L_80454ABC
    if (!c1cs) {
        // 0x80454A94: nop
    
            goto L_80454ABC;
    }
    // 0x80454A94: nop

    // 0x80454A98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80454A9C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80454AA0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80454AA4: beq         $v0, $t9, L_80454C30
    if (ctx->r2 == ctx->r25) {
        // 0x80454AA8: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80454C30;
    }
    // 0x80454AA8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80454AAC: jal         0x80450B18
    // 0x80454AB0: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    func_80450B18(rdram, ctx);
        goto after_2;
    // 0x80454AB0: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    after_2:
    // 0x80454AB4: b           L_80454C34
    // 0x80454AB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80454C34;
    // 0x80454AB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80454ABC:
    // 0x80454ABC: lwc1        $f4, -0x7B00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14120));
    // 0x80454AC0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80454AC4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14124) << 16);
    // 0x80454AC8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80454ACC: nop

    // 0x80454AD0: bc1f        L_80454AFC
    if (!c1cs) {
        // 0x80454AD4: nop
    
            goto L_80454AFC;
    }
    // 0x80454AD4: nop

    // 0x80454AD8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80454ADC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80454AE0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80454AE4: beq         $v0, $t1, L_80454C30
    if (ctx->r2 == ctx->r9) {
        // 0x80454AE8: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80454C30;
    }
    // 0x80454AE8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80454AEC: jal         0x80450B18
    // 0x80454AF0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    func_80450B18(rdram, ctx);
        goto after_3;
    // 0x80454AF0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    after_3:
    // 0x80454AF4: b           L_80454C34
    // 0x80454AF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80454C34;
    // 0x80454AF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80454AFC:
    // 0x80454AFC: lwc1        $f6, -0x7AFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14124));
    // 0x80454B00: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80454B04: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80454B08: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80454B0C: nop

    // 0x80454B10: bc1fl       L_80454B40
    if (!c1cs) {
        // 0x80454B14: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80454B40;
    }
    goto skip_1;
    // 0x80454B14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x80454B18: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80454B1C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80454B20: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80454B24: beq         $v0, $t3, L_80454C30
    if (ctx->r2 == ctx->r11) {
        // 0x80454B28: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80454C30;
    }
    // 0x80454B28: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80454B2C: jal         0x80450B18
    // 0x80454B30: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    func_80450B18(rdram, ctx);
        goto after_4;
    // 0x80454B30: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    after_4:
    // 0x80454B34: b           L_80454C34
    // 0x80454B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80454C34;
    // 0x80454B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80454B3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80454B40:
    // 0x80454B40: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80454B44: lui         $at, 0x42DE
    ctx->r1 = S32(0X42DE << 16);
    // 0x80454B48: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80454B4C: nop

    // 0x80454B50: bc1fl       L_80454B80
    if (!c1cs) {
        // 0x80454B54: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80454B80;
    }
    goto skip_2;
    // 0x80454B54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_2:
    // 0x80454B58: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80454B5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80454B60: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80454B64: beq         $v0, $t5, L_80454C30
    if (ctx->r2 == ctx->r13) {
        // 0x80454B68: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80454C30;
    }
    // 0x80454B68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80454B6C: jal         0x80450B18
    // 0x80454B70: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    func_80450B18(rdram, ctx);
        goto after_5;
    // 0x80454B70: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    after_5:
    // 0x80454B74: b           L_80454C34
    // 0x80454B78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80454C34;
    // 0x80454B78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80454B7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80454B80:
    // 0x80454B80: lui         $at, 0x42BA
    ctx->r1 = S32(0X42BA << 16);
    // 0x80454B84: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80454B88: nop

    // 0x80454B8C: bc1fl       L_80454BBC
    if (!c1cs) {
        // 0x80454B90: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80454BBC;
    }
    goto skip_3;
    // 0x80454B90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_3:
    // 0x80454B94: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80454B98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80454B9C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80454BA0: beq         $v0, $t7, L_80454C30
    if (ctx->r2 == ctx->r15) {
        // 0x80454BA4: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80454C30;
    }
    // 0x80454BA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80454BA8: jal         0x80445E2C
    // 0x80454BAC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    func_80445E2C(rdram, ctx);
        goto after_6;
    // 0x80454BAC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    after_6:
    // 0x80454BB0: b           L_80454C34
    // 0x80454BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80454C34;
    // 0x80454BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80454BB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80454BBC:
    // 0x80454BBC: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80454BC0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80454BC4: nop

    // 0x80454BC8: bc1fl       L_80454C00
    if (!c1cs) {
        // 0x80454BCC: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80454C00;
    }
    goto skip_4;
    // 0x80454BCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_4:
    // 0x80454BD0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80454BD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80454BD8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80454BDC: beq         $v0, $t6, L_80454C30
    if (ctx->r2 == ctx->r14) {
        // 0x80454BE0: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80454C30;
    }
    // 0x80454BE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80454BE4: jal         0x80445E2C
    // 0x80454BE8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    func_80445E2C(rdram, ctx);
        goto after_7;
    // 0x80454BE8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    after_7:
    // 0x80454BEC: jal         0x80445C9C
    // 0x80454BF0: nop

    func_80445C9C(rdram, ctx);
        goto after_8;
    // 0x80454BF0: nop

    after_8:
    // 0x80454BF4: b           L_80454C34
    // 0x80454BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80454C34;
    // 0x80454BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80454BFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80454C00:
    // 0x80454C00: nop

    // 0x80454C04: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80454C08: nop

    // 0x80454C0C: bc1fl       L_80454C34
    if (!c1cs) {
        // 0x80454C10: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80454C34;
    }
    goto skip_5;
    // 0x80454C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80454C14: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80454C18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80454C1C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80454C20: beq         $v0, $t9, L_80454C30
    if (ctx->r2 == ctx->r25) {
        // 0x80454C24: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80454C30;
    }
    // 0x80454C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80454C28: jal         0x80445E2C
    // 0x80454C2C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    func_80445E2C(rdram, ctx);
        goto after_9;
    // 0x80454C2C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    after_9:
L_80454C30:
    // 0x80454C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80454C34:
    // 0x80454C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80454C38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80454C3C: jr          $ra
    // 0x80454C40: nop

    return;
    // 0x80454C40: nop

;}
RECOMP_FUNC void func_807806C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807806C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807806C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807806CC: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x807806D0: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x807806D4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807806D8: addiu       $t9, $t8, -0x463B
    ctx->r25 = ADD32(ctx->r24, -0X463B);
    // 0x807806DC: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x807806E0: sltiu       $at, $t9, 0x23
    ctx->r1 = ctx->r25 < 0X23 ? 1 : 0;
    // 0x807806E4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807806E8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807806EC: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x807806F0: beq         $at, $zero, L_807807CC
    if (ctx->r1 == 0) {
        // 0x807806F4: sw          $t7, 0x130($a0)
        MEM_W(0X130, ctx->r4) = ctx->r15;
            goto L_807807CC;
    }
    // 0x807806F4: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x807806F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x807806FC: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(784, 0X65D0) << 16);
    // 0x80780700: addu        $at, $at, $t9
    gpr jr_addend_80780708 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80780704: lw          $t9, 0x67C0($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(784, 0X65D0));
    // 0x80780708: jr          $t9
    // 0x8078070C: nop

    switch (jr_addend_80780708 >> 2) {
        case 0: goto L_807807B0; break;
        case 1: goto L_8078077C; break;
        case 2: goto L_807807CC; break;
        case 3: goto L_807807B0; break;
        case 4: goto L_807807CC; break;
        case 5: goto L_807807CC; break;
        case 6: goto L_807807CC; break;
        case 7: goto L_807807CC; break;
        case 8: goto L_807807CC; break;
        case 9: goto L_807807CC; break;
        case 10: goto L_807807CC; break;
        case 11: goto L_807807CC; break;
        case 12: goto L_807807CC; break;
        case 13: goto L_807807CC; break;
        case 14: goto L_807807CC; break;
        case 15: goto L_807807CC; break;
        case 16: goto L_80780710; break;
        case 17: goto L_807807CC; break;
        case 18: goto L_807807CC; break;
        case 19: goto L_807807CC; break;
        case 20: goto L_807807CC; break;
        case 21: goto L_807807CC; break;
        case 22: goto L_807807CC; break;
        case 23: goto L_807807A8; break;
        case 24: goto L_807807CC; break;
        case 25: goto L_807807CC; break;
        case 26: goto L_807807CC; break;
        case 27: goto L_807807B0; break;
        case 28: goto L_807807B0; break;
        case 29: goto L_807807B0; break;
        case 30: goto L_807807B0; break;
        case 31: goto L_807807B0; break;
        case 32: goto L_807807B0; break;
        case 33: goto L_807807B0; break;
        case 34: goto L_807807B0; break;
        default: switch_error(__func__, 0x80780708, 0x807867C0);
    }
    // 0x8078070C: nop

L_80780710:
    // 0x80780710: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80780714: jal         0x80045A34
    // 0x80780718: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80780718: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078071C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80780720: jal         0x807803A8
    // 0x80780724: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    func_807803A8(rdram, ctx);
        goto after_1;
    // 0x80780724: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    after_1:
    // 0x80780728: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8078072C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80780730: lw          $t2, 0xF54($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XF54);
    // 0x80780734: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x80780738: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8078073C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80780740: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x80780744: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80780748: sw          $t3, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r11;
    // 0x8078074C: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80780750: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80780754: sw          $t5, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r13;
    // 0x80780758: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8078075C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80780760: sb          $t0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r8;
    // 0x80780764: sb          $t1, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r9;
    // 0x80780768: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8078076C: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x80780770: sw          $zero, 0xCF0($v0)
    MEM_W(0XCF0, ctx->r2) = 0;
    // 0x80780774: b           L_807807CC
    // 0x80780778: sw          $t7, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r15;
        goto L_807807CC;
    // 0x80780778: sw          $t7, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r15;
L_8078077C:
    // 0x8078077C: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x80780780: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80780784: lui         $t9, 0x8078
    ctx->r25 = S32(RELOC_HI16(784, 0X64E0) << 16);
    // 0x80780788: sh          $t8, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r24;
    // 0x8078078C: addiu       $t9, $t9, 0x66D0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(784, 0X64E0));
    // 0x80780790: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80780794: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80780798: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8078079C: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    // 0x807807A0: b           L_807807CC
    // 0x807807A4: sb          $t2, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r10;
        goto L_807807CC;
    // 0x807807A4: sb          $t2, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r10;
L_807807A8:
    // 0x807807A8: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x807807AC: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_807807B0:
    // 0x807807B0: lw          $t5, 0x16C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X16C);
    // 0x807807B4: lui         $t4, 0x8078
    ctx->r12 = S32(RELOC_HI16(784, 0X64E0) << 16);
    // 0x807807B8: addiu       $t4, $t4, 0x66D0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(784, 0X64E0));
    // 0x807807BC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x807807C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807807C4: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x807807C8: sb          $t6, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r14;
L_807807CC:
    // 0x807807CC: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x807807D0: jal         0x807813F0
    // 0x807807D4: lbu         $a2, 0x1E($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1E);
    func_807813F0(rdram, ctx);
        goto after_2;
    // 0x807807D4: lbu         $a2, 0x1E($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1E);
    after_2:
    // 0x807807D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807807DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807807E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807807E4: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    // 0x807807E8: jr          $ra
    // 0x807807EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807807EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_805D7B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7B7C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805D7B80: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(474, 0X310) << 16);
    // 0x805D7B84: addiu       $t6, $t6, 0x7C10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(474, 0X310));
    // 0x805D7B88: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805D7B8C: jr          $ra
    // 0x805D7B90: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x805D7B90: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_807B8270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8270: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x807B8274: addiu       $at, $zero, 0x470A
    ctx->r1 = ADD32(0, 0X470A);
    // 0x807B8278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807B827C: bne         $t6, $at, L_807B8290
    if (ctx->r14 != ctx->r1) {
        // 0x807B8280: nop
    
            goto L_807B8290;
    }
    // 0x807B8280: nop

    // 0x807B8284: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(886, 0X1B4C) << 16);
    // 0x807B8288: jr          $ra
    // 0x807B828C: addiu       $v0, $v0, -0x6244
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(886, 0X1B4C));
    return;
    // 0x807B828C: addiu       $v0, $v0, -0x6244
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(886, 0X1B4C));
L_807B8290:
    // 0x807B8290: jr          $ra
    // 0x807B8294: nop

    return;
    // 0x807B8294: nop

;}
RECOMP_FUNC void func_806ED714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED714: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806ED718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806ED71C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806ED720: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806ED724: jal         0x8004700C
    // 0x806ED728: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806ED728: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x806ED72C: bnel        $v0, $zero, L_806ED740
    if (ctx->r2 != 0) {
        // 0x806ED730: lwc1        $f6, 0x88($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
            goto L_806ED740;
    }
    goto skip_0;
    // 0x806ED730: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    skip_0:
    // 0x806ED734: b           L_806ED830
    // 0x806ED738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806ED830;
    // 0x806ED738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806ED73C: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
L_806ED740:
    // 0x806ED740: lwc1        $f8, 0x88($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X88);
    // 0x806ED744: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x806ED748: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806ED74C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806ED750: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806ED754: nop

    // 0x806ED758: bc1fl       L_806ED830
    if (!c1cs) {
        // 0x806ED75C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806ED830;
    }
    goto skip_1;
    // 0x806ED75C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x806ED760: lwc1        $f16, 0x84($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X84);
    // 0x806ED764: lwc1        $f18, 0x84($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806ED768: lui         $at, 0x423C
    ctx->r1 = S32(0X423C << 16);
    // 0x806ED76C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806ED770: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806ED774: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806ED778: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806ED77C: nop

    // 0x806ED780: bc1fl       L_806ED830
    if (!c1cs) {
        // 0x806ED784: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806ED830;
    }
    goto skip_2;
    // 0x806ED784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x806ED788: lh          $a0, 0x184($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X184);
    // 0x806ED78C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806ED790: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x806ED794: blez        $a0, L_806ED82C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x806ED798: addiu       $a1, $zero, 0x45E4
        ctx->r5 = ADD32(0, 0X45E4);
            goto L_806ED82C;
    }
    // 0x806ED798: addiu       $a1, $zero, 0x45E4
    ctx->r5 = ADD32(0, 0X45E4);
L_806ED79C:
    // 0x806ED79C: lw          $s0, 0x188($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X188);
    // 0x806ED7A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x806ED7A4: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x806ED7A8: beq         $s0, $zero, L_806ED824
    if (ctx->r16 == 0) {
        // 0x806ED7AC: nop
    
            goto L_806ED824;
    }
    // 0x806ED7AC: nop

    // 0x806ED7B0: lhu         $t6, 0xC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC);
    // 0x806ED7B4: bne         $a1, $t6, L_806ED824
    if (ctx->r5 != ctx->r14) {
        // 0x806ED7B8: nop
    
            goto L_806ED824;
    }
    // 0x806ED7B8: nop

    // 0x806ED7BC: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806ED7C0: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806ED7C4: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x806ED7C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806ED7CC: sb          $t7, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r15;
    // 0x806ED7D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ED7D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ED7D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806ED7DC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x806ED7E0: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x806ED7E4: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x806ED7E8: jal         0x806EF4A0
    // 0x806ED7EC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    func_806EF4A0(rdram, ctx);
        goto after_1;
    // 0x806ED7EC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x806ED7F0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CEC) << 16);
    // 0x806ED7F4: lwc1        $f16, 0xC3C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CEC));
    // 0x806ED7F8: addiu       $t8, $zero, 0x5A
    ctx->r24 = ADD32(0, 0X5A);
    // 0x806ED7FC: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x806ED800: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    // 0x806ED804: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x806ED808: jal         0x80067BBC
    // 0x806ED80C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x806ED80C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    after_2:
    // 0x806ED810: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x806ED814: jal         0x80067818
    // 0x806ED818: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x806ED818: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x806ED81C: b           L_806ED830
    // 0x806ED820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806ED830;
    // 0x806ED820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806ED824:
    // 0x806ED824: bne         $at, $zero, L_806ED79C
    if (ctx->r1 != 0) {
        // 0x806ED828: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_806ED79C;
    }
    // 0x806ED828: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_806ED82C:
    // 0x806ED82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806ED830:
    // 0x806ED830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806ED834: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806ED838: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806ED83C: jr          $ra
    // 0x806ED840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806ED840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80453A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453A44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453A48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453A4C: jal         0x804539F0
    // 0x80453A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_804539F0(rdram, ctx);
        goto after_0;
    // 0x80453A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80453A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453A5C: jr          $ra
    // 0x80453A60: nop

    return;
    // 0x80453A60: nop

;}
RECOMP_FUNC void func_8079DAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079DAF0: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(835, 0X778) << 16);
    // 0x8079DAF4: addiu       $v0, $v0, -0x1D98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(835, 0X778));
    // 0x8079DAF8: jr          $ra
    // 0x8079DAFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8079DAFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8007E458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E458: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8007E45C: sw          $zero, -0x65B0($at)
    MEM_W(-0X65B0, ctx->r1) = 0;
    // 0x8007E460: jr          $ra
    // 0x8007E464: nop

    return;
    // 0x8007E464: nop

;}
RECOMP_FUNC void func_80048E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048E0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048E10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048E14: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80048E18: jal         0x80048D74
    // 0x80048E1C: addiu       $a1, $a1, -0x72B4
    ctx->r5 = ADD32(ctx->r5, -0X72B4);
    func_80048D74(rdram, ctx);
        goto after_0;
    // 0x80048E1C: addiu       $a1, $a1, -0x72B4
    ctx->r5 = ADD32(ctx->r5, -0X72B4);
    after_0:
    // 0x80048E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048E28: jr          $ra
    // 0x80048E2C: nop

    return;
    // 0x80048E2C: nop

;}
RECOMP_FUNC void func_8078F3F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F3F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078F3F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078F3FC: lw          $a1, 0x14C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X14C);
    // 0x8078F400: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8078F404: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8078F408: jal         0x80065954
    // 0x8078F40C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8078F40C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8078F410: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8078F414: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8078F418: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8078F41C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8078F420: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8078F424: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8078F428: addiu       $v1, $a0, 0x154
    ctx->r3 = ADD32(ctx->r4, 0X154);
    // 0x8078F42C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8078F430: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8078F434: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8078F438: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8078F43C: nop

    // 0x8078F440: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8078F444: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8078F448: nop

    // 0x8078F44C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8078F450: beql        $t8, $zero, L_8078F4A0
    if (ctx->r24 == 0) {
        // 0x8078F454: mfc1        $t8, $f8
        ctx->r24 = (int32_t)ctx->f8.u32l;
            goto L_8078F4A0;
    }
    goto skip_0;
    // 0x8078F454: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x8078F458: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8078F45C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8078F460: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8078F464: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8078F468: nop

    // 0x8078F46C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8078F470: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8078F474: nop

    // 0x8078F478: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8078F47C: bne         $t8, $zero, L_8078F494
    if (ctx->r24 != 0) {
        // 0x8078F480: nop
    
            goto L_8078F494;
    }
    // 0x8078F480: nop

    // 0x8078F484: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8078F488: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8078F48C: b           L_8078F4AC
    // 0x8078F490: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8078F4AC;
    // 0x8078F490: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8078F494:
    // 0x8078F494: b           L_8078F4AC
    // 0x8078F498: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8078F4AC;
    // 0x8078F498: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8078F49C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
L_8078F4A0:
    // 0x8078F4A0: nop

    // 0x8078F4A4: bltz        $t8, L_8078F494
    if (SIGNED(ctx->r24) < 0) {
        // 0x8078F4A8: nop
    
            goto L_8078F494;
    }
    // 0x8078F4A8: nop

L_8078F4AC:
    // 0x8078F4AC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8078F4B0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8078F4B4: sltu        $at, $t9, $a1
    ctx->r1 = ctx->r25 < ctx->r5 ? 1 : 0;
    // 0x8078F4B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8078F4BC: bne         $at, $zero, L_8078F500
    if (ctx->r1 != 0) {
        // 0x8078F4C0: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8078F500;
    }
    // 0x8078F4C0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8078F4C4: sltu        $at, $t9, $a1
    ctx->r1 = ctx->r25 < ctx->r5 ? 1 : 0;
    // 0x8078F4C8: bne         $at, $zero, L_8078F4E0
    if (ctx->r1 != 0) {
        // 0x8078F4CC: subu        $t0, $v0, $a1
        ctx->r8 = SUB32(ctx->r2, ctx->r5);
            goto L_8078F4E0;
    }
L_8078F4CC:
    // 0x8078F4CC: subu        $t0, $v0, $a1
    ctx->r8 = SUB32(ctx->r2, ctx->r5);
    // 0x8078F4D0: sltu        $at, $t0, $a1
    ctx->r1 = ctx->r8 < ctx->r5 ? 1 : 0;
    // 0x8078F4D4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8078F4D8: beq         $at, $zero, L_8078F4CC
    if (ctx->r1 == 0) {
        // 0x8078F4DC: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8078F4CC;
    }
    // 0x8078F4DC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8078F4E0:
    // 0x8078F4E0: lh          $t1, 0x144($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X144);
    // 0x8078F4E4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8078F4E8: bgez        $t2, L_8078F4FC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8078F4EC: andi        $t3, $t2, 0x7
        ctx->r11 = ctx->r10 & 0X7;
            goto L_8078F4FC;
    }
    // 0x8078F4EC: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x8078F4F0: beq         $t3, $zero, L_8078F4FC
    if (ctx->r11 == 0) {
        // 0x8078F4F4: nop
    
            goto L_8078F4FC;
    }
    // 0x8078F4F4: nop

    // 0x8078F4F8: addiu       $t3, $t3, -0x8
    ctx->r11 = ADD32(ctx->r11, -0X8);
L_8078F4FC:
    // 0x8078F4FC: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8078F500:
    // 0x8078F500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078F504: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078F508: jr          $ra
    // 0x8078F50C: nop

    return;
    // 0x8078F50C: nop

;}
RECOMP_FUNC void func_80437C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437C04: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80437C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80437C0C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437C10: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80437C14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80437C18: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80437C1C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80437C20: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80437C24: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80437C28: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80437C2C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80437C30: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80437C34: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x80437C38: jal         0x8004A97C
    // 0x80437C3C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_8004A97C(rdram, ctx);
        goto after_0;
    // 0x80437C3C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x80437C40: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80437C44: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80437C48: addiu       $v0, $a2, 0xC4
    ctx->r2 = ADD32(ctx->r6, 0XC4);
    // 0x80437C4C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80437C50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80437C54: jal         0x80066E88
    // 0x80437C58: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80437C58: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80437C5C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80437C60: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80437C64: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F74) << 16);
    // 0x80437C68: lwc1        $f18, -0x77EC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F74));
    // 0x80437C6C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80437C70: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F78) << 16);
    // 0x80437C74: lwc1        $f6, -0x77E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F78));
    // 0x80437C78: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80437C7C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F7C) << 16);
    // 0x80437C80: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80437C84: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80437C88: nop

    // 0x80437C8C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80437C90: lwc1        $f4, -0x77E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F7C));
    // 0x80437C94: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80437C98: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80437C9C: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x80437CA0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80437CA4: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80437CA8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80437CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80437CB0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80437CB4: jr          $ra
    // 0x80437CB8: nop

    return;
    // 0x80437CB8: nop

;}
RECOMP_FUNC void func_8046ADC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046ADC8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046ADCC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8046ADD0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8046ADD4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046ADD8: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X298C) << 16);
    // 0x8046ADDC: lwc1        $f6, -0x3F34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X298C));
    // 0x8046ADE0: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8046ADE4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8046ADE8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8046ADEC: nop

    // 0x8046ADF0: bc1f        L_8046ADFC
    if (!c1cs) {
        // 0x8046ADF4: nop
    
            goto L_8046ADFC;
    }
    // 0x8046ADF4: nop

    // 0x8046ADF8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_8046ADFC:
    // 0x8046ADFC: jr          $ra
    // 0x8046AE00: nop

    return;
    // 0x8046AE00: nop

;}
RECOMP_FUNC void func_804BBC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BBC70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BBC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BBC78: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804BBC7C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804BBC80: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804BBC84: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(191, 0X3F44) << 16);
    // 0x804BBC88: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BBC8C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804BBC90: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804BBC94: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804BBC98: lw          $t8, -0x78C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(191, 0X3F44));
    // 0x804BBC9C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804BBCA0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804BBCA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804BBCA8: jal         0x80048490
    // 0x804BBCAC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804BBCAC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804BBCB0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804BBCB4: jal         0x80048378
    // 0x804BBCB8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804BBCB8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804BBCBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BBCC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BBCC4: jr          $ra
    // 0x804BBCC8: nop

    return;
    // 0x804BBCC8: nop

;}
RECOMP_FUNC void func_80023A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023A2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023A34: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80023A38: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80023A3C: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x80023A40: beq         $t6, $zero, L_80023A60
    if (ctx->r14 == 0) {
        // 0x80023A44: nop
    
            goto L_80023A60;
    }
    // 0x80023A44: nop

    // 0x80023A48: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80023A4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023A50: swc1        $f12, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f12.u32l;
    // 0x80023A54: lwc1        $f4, -0x2C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C4);
    // 0x80023A58: b           L_80023B68
    // 0x80023A5C: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
        goto L_80023B68;
    // 0x80023A5C: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
L_80023A60:
    // 0x80023A60: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80023A64: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    // 0x80023A68: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80023A6C: jal         0x8006593C
    // 0x80023A70: sh          $a0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r4;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80023A70: sh          $a0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r4;
    after_0:
    // 0x80023A74: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    // 0x80023A78: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80023A7C: blez        $a0, L_80023AB8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80023A80: nop
    
            goto L_80023AB8;
    }
    // 0x80023A80: nop

    // 0x80023A84: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80023A88: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80023A8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80023A90: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80023A94: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80023A98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023A9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023AA0: lwc1        $f18, -0x2C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2C0);
    // 0x80023AA4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80023AA8: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80023AAC: mul.s       $f2, $f18, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80023AB0: b           L_80023B44
    // 0x80023AB4: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
        goto L_80023B44;
    // 0x80023AB4: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
L_80023AB8:
    // 0x80023AB8: bgez        $a0, L_80023AF4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80023ABC: lui         $at, 0xC080
        ctx->r1 = S32(0XC080 << 16);
            goto L_80023AF4;
    }
    // 0x80023ABC: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80023AC0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80023AC4: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80023AC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80023ACC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80023AD0: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80023AD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023AD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023ADC: lwc1        $f18, -0x2BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2BC);
    // 0x80023AE0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80023AE4: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80023AE8: mul.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80023AEC: b           L_80023B44
    // 0x80023AF0: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
        goto L_80023B44;
    // 0x80023AF0: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
L_80023AF4:
    // 0x80023AF4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80023AF8: lwc1        $f0, 0xDC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XDC);
    // 0x80023AFC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80023B00: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80023B04: nop

    // 0x80023B08: bc1fl       L_80023B1C
    if (!c1cs) {
        // 0x80023B0C: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80023B1C;
    }
    goto skip_0;
    // 0x80023B0C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x80023B10: b           L_80023B34
    // 0x80023B14: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80023B34;
    // 0x80023B14: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80023B18: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80023B1C:
    // 0x80023B1C: nop

    // 0x80023B20: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80023B24: nop

    // 0x80023B28: bc1fl       L_80023B38
    if (!c1cs) {
        // 0x80023B2C: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80023B38;
    }
    goto skip_1;
    // 0x80023B2C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_1:
    // 0x80023B30: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80023B34:
    // 0x80023B34: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80023B38:
    // 0x80023B38: nop

    // 0x80023B3C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80023B40: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
L_80023B44:
    // 0x80023B44: swc1        $f0, 0xDC($a1)
    MEM_W(0XDC, ctx->r5) = ctx->f0.u32l;
    // 0x80023B48: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80023B4C: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x80023B50: bnel        $t9, $zero, L_80023B64
    if (ctx->r25 != 0) {
        // 0x80023B54: swc1        $f12, 0xC4($a1)
        MEM_W(0XC4, ctx->r5) = ctx->f12.u32l;
            goto L_80023B64;
    }
    goto skip_2;
    // 0x80023B54: swc1        $f12, 0xC4($a1)
    MEM_W(0XC4, ctx->r5) = ctx->f12.u32l;
    skip_2:
    // 0x80023B58: b           L_80023B68
    // 0x80023B5C: swc1        $f2, 0xE8($a1)
    MEM_W(0XE8, ctx->r5) = ctx->f2.u32l;
        goto L_80023B68;
    // 0x80023B5C: swc1        $f2, 0xE8($a1)
    MEM_W(0XE8, ctx->r5) = ctx->f2.u32l;
    // 0x80023B60: swc1        $f12, 0xC4($a1)
    MEM_W(0XC4, ctx->r5) = ctx->f12.u32l;
L_80023B64:
    // 0x80023B64: swc1        $f12, 0xE8($a1)
    MEM_W(0XE8, ctx->r5) = ctx->f12.u32l;
L_80023B68:
    // 0x80023B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023B6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80023B70: jr          $ra
    // 0x80023B74: nop

    return;
    // 0x80023B74: nop

;}
RECOMP_FUNC void func_804610D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804610D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804610D8: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x804610DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804610E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804610E4: mul.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x804610E8: swc1        $f14, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f14.u32l;
    // 0x804610EC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39EC) << 16);
    // 0x804610F0: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x804610F4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x804610F8: nop

    // 0x804610FC: bc1f        L_80461110
    if (!c1cs) {
        // 0x80461100: nop
    
            goto L_80461110;
    }
    // 0x80461100: nop

    // 0x80461104: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39E8) << 16);
    // 0x80461108: b           L_8046114C
    // 0x8046110C: lwc1        $f14, 0x3F78($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39E8));
        goto L_8046114C;
    // 0x8046110C: lwc1        $f14, 0x3F78($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39E8));
L_80461110:
    // 0x80461110: lwc1        $f8, 0x3F7C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39EC));
    // 0x80461114: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80461118: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8046111C: nop

    // 0x80461120: bc1fl       L_80461148
    if (!c1cs) {
        // 0x80461124: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80461148;
    }
    goto skip_0;
    // 0x80461124: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x80461128: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8046112C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39F0) << 16);
    // 0x80461130: lwc1        $f18, 0x3F80($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39F0));
    // 0x80461134: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80461138: mul.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8046113C: b           L_8046114C
    // 0x80461140: nop

        goto L_8046114C;
    // 0x80461140: nop

    // 0x80461144: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80461148:
    // 0x80461148: nop

L_8046114C:
    // 0x8046114C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39F4) << 16);
    // 0x80461150: lwc1        $f4, 0x3F84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39F4));
    // 0x80461154: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80461158: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8046115C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80461160: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80461164: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80461168: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8046116C: bc1f        L_80461184
    if (!c1cs) {
        // 0x80461170: add.s       $f14, $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
            goto L_80461184;
    }
    // 0x80461170: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80461174: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80461178: nop

    // 0x8046117C: mul.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80461180: nop

L_80461184:
    // 0x80461184: jr          $ra
    // 0x80461188: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    return;
    // 0x80461188: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
;}
RECOMP_FUNC void func_80584C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584C0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584C10: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584C14: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584C18: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584C1C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584C20: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584C24: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584C28: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584C2C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584C30: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584C34: jr          $ra
    // 0x80584C38: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584C38: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8046C450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C450: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(143, 0X28) << 16);
    // 0x8046C454: addiu       $v0, $v0, -0x3B88
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(143, 0X28));
    // 0x8046C458: jr          $ra
    // 0x8046C45C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8046C45C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80517194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517194: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80517198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051719C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805171A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805171A4: addiu       $a3, $a0, 0xC4
    ctx->r7 = ADD32(ctx->r4, 0XC4);
    // 0x805171A8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805171AC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x805171B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x805171B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805171B8: jal         0x80048F84
    // 0x805171BC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x805171BC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x805171C0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x805171C4: beq         $v0, $zero, L_805171E0
    if (ctx->r2 == 0) {
        // 0x805171C8: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_805171E0;
    }
    // 0x805171C8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x805171CC: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(285, 0X3D0) << 16);
    // 0x805171D0: lwc1        $f4, 0x74E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(285, 0X3D0));
    // 0x805171D4: lwc1        $f6, 0x1C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x805171D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805171DC: swc1        $f8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f8.u32l;
L_805171E0:
    // 0x805171E0: lwc1        $f10, 0x78($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X78);
    // 0x805171E4: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x805171E8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x805171EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805171F0: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x805171F4: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x805171F8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x805171FC: swc1        $f0, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f0.u32l;
    // 0x80517200: jal         0x80517120
    // 0x80517204: swc1        $f4, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f4.u32l;
    func_80517120(rdram, ctx);
        goto after_1;
    // 0x80517204: swc1        $f4, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f4.u32l;
    after_1:
    // 0x80517208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051720C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80517210: jr          $ra
    // 0x80517214: nop

    return;
    // 0x80517214: nop

;}
RECOMP_FUNC void func_80584AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584AEC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584AF0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584AF4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584AF8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584AFC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584B00: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584B04: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584B08: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584B0C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584B10: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584B14: jr          $ra
    // 0x80584B18: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584B18: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8078A8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A8B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8078A8B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078A8B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078A8BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078A8C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8078A8C4: lw          $a0, 0x264($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X264);
    // 0x8078A8C8: jal         0x800443EC
    // 0x8078A8CC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800443EC(rdram, ctx);
        goto after_0;
    // 0x8078A8CC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078A8D0: beq         $v0, $zero, L_8078A984
    if (ctx->r2 == 0) {
        // 0x8078A8D4: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8078A984;
    }
    // 0x8078A8D4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8078A8D8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(793, 0XDE8) << 16);
    // 0x8078A8DC: lwc1        $f6, -0x4FD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XDE8));
    // 0x8078A8E0: lwc1        $f4, 0x7C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X7C);
    // 0x8078A8E4: lw          $t7, 0x174($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X174);
    // 0x8078A8E8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8078A8EC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8078A8F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8078A8F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8078A8F8: addiu       $a0, $a2, 0x84
    ctx->r4 = ADD32(ctx->r6, 0X84);
    // 0x8078A8FC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8078A900: swc1        $f8, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f8.u32l;
    // 0x8078A904: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8078A908: swc1        $f10, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f10.u32l;
    // 0x8078A90C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8078A910: lwc1        $f16, 0x88($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8078A914: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8078A918: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x8078A91C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8078A920: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(793, 0XDEC) << 16);
    // 0x8078A924: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8078A928: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8078A92C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8078A930: swc1        $f16, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f16.u32l;
    // 0x8078A934: lwc1        $f4, -0x4FD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XDEC));
    // 0x8078A938: lwc1        $f18, 0x8C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8078A93C: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
    // 0x8078A940: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8078A944: jal         0x80047AB8
    // 0x8078A948: swc1        $f6, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f6.u32l;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x8078A948: swc1        $f6, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f6.u32l;
    after_1:
    // 0x8078A94C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8078A950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078A954: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8078A958: jal         0x8078ACF0
    // 0x8078A95C: sw          $zero, 0x264($t0)
    MEM_W(0X264, ctx->r8) = 0;
    func_8078ACF0(rdram, ctx);
        goto after_2;
    // 0x8078A95C: sw          $zero, 0x264($t0)
    MEM_W(0X264, ctx->r8) = 0;
    after_2:
    // 0x8078A960: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x8078A964: sw          $t1, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r9;
    // 0x8078A968: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(793, 0XDF0) << 16);
    // 0x8078A96C: lwc1        $f8, -0x4FD0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XDF0));
    // 0x8078A970: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8078A974: addiu       $a0, $zero, 0x22C
    ctx->r4 = ADD32(0, 0X22C);
    // 0x8078A978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8078A97C: jal         0x80067818
    // 0x8078A980: swc1        $f8, 0x268($t2)
    MEM_W(0X268, ctx->r10) = ctx->f8.u32l;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8078A980: swc1        $f8, 0x268($t2)
    MEM_W(0X268, ctx->r10) = ctx->f8.u32l;
    after_3:
L_8078A984:
    // 0x8078A984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078A988: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078A98C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8078A990: jr          $ra
    // 0x8078A994: nop

    return;
    // 0x8078A994: nop

;}
RECOMP_FUNC void func_805514AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805514AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805514B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805514B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805514B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805514BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805514C0: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x805514C4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x805514C8: lw          $a2, 0x88($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X88);
    // 0x805514CC: addiu       $s1, $s0, 0xDFC
    ctx->r17 = ADD32(ctx->r16, 0XDFC);
    // 0x805514D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805514D4: lw          $a3, 0xFFC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XFFC);
    // 0x805514D8: jal         0x80550B74
    // 0x805514DC: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    func_80550B74(rdram, ctx);
        goto after_0;
    // 0x805514DC: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    after_0:
    // 0x805514E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805514E4: jal         0x8004590C
    // 0x805514E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x805514E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x805514EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x805514F0: jal         0x8004590C
    // 0x805514F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8004590C(rdram, ctx);
        goto after_2;
    // 0x805514F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x805514F8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x805514FC: jal         0x8004590C
    // 0x80551500: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8004590C(rdram, ctx);
        goto after_3;
    // 0x80551500: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80551504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80551508: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8055150C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80551510: jr          $ra
    // 0x80551514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80551514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80432478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432478: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043247C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80432480: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80432484: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80432488: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043248C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80432490: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80432494: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80432498: lw          $a2, 0xC($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XC);
    // 0x8043249C: beql        $a2, $zero, L_80432540
    if (ctx->r6 == 0) {
        // 0x804324A0: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_80432540;
    }
    goto skip_0;
    // 0x804324A0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_0:
    // 0x804324A4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x804324A8: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x804324AC: bne         $at, $zero, L_80432534
    if (ctx->r1 != 0) {
        // 0x804324B0: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_80432534;
    }
    // 0x804324B0: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x804324B4: lbu         $t9, 0x30($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X30);
    // 0x804324B8: bnel        $t9, $zero, L_80432544
    if (ctx->r25 != 0) {
        // 0x804324BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80432544;
    }
    goto skip_1;
    // 0x804324BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x804324C0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x804324C4: jal         0x8004700C
    // 0x804324C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804324C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x804324CC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804324D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804324D4: beq         $v0, $zero, L_80432540
    if (ctx->r2 == 0) {
        // 0x804324D8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80432540;
    }
    // 0x804324D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804324DC: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x804324E0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804324E4: sb          $t0, 0x30($a2)
    MEM_B(0X30, ctx->r6) = ctx->r8;
    // 0x804324E8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x804324EC: jal         0x804322F0
    // 0x804324F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_804322F0(rdram, ctx);
        goto after_1;
    // 0x804324F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x804324F4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804324F8: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x804324FC: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x80432500: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80432504: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80432508: bne         $at, $zero, L_80432514
    if (ctx->r1 != 0) {
        // 0x8043250C: sw          $t2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r10;
            goto L_80432514;
    }
    // 0x8043250C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80432510: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80432514:
    // 0x80432514: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80432518: jal         0x80067BBC
    // 0x8043251C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8043251C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80432520: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80432524: jal         0x80067818
    // 0x80432528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80432528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8043252C: b           L_80432544
    // 0x80432530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80432544;
    // 0x80432530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80432534:
    // 0x80432534: b           L_80432540
    // 0x80432538: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
        goto L_80432540;
    // 0x80432538: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x8043253C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80432540:
    // 0x80432540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80432544:
    // 0x80432544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80432548: jal         0x804326C4
    // 0x8043254C: lbu         $a2, 0x30($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X30);
    func_804326C4(rdram, ctx);
        goto after_4;
    // 0x8043254C: lbu         $a2, 0x30($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X30);
    after_4:
    // 0x80432550: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80432554: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80432558: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043255C: jr          $ra
    // 0x80432560: nop

    return;
    // 0x80432560: nop

;}
RECOMP_FUNC void func_800238A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800238A8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800238AC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800238B0: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    // 0x800238B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800238B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800238BC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800238C0: jal         0x8006593C
    // 0x800238C4: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x800238C4: sh          $a0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r4;
    after_0:
    // 0x800238C8: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x800238CC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800238D0: slti        $at, $v1, 0x35
    ctx->r1 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
    // 0x800238D4: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    // 0x800238D8: bne         $at, $zero, L_8002394C
    if (ctx->r1 != 0) {
        // 0x800238DC: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_8002394C;
    }
    // 0x800238DC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800238E0: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x800238E4: lw          $v0, 0xE0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XE0);
    // 0x800238E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800238EC: sltiu       $at, $v0, 0x15
    ctx->r1 = ctx->r2 < 0X15 ? 1 : 0;
    // 0x800238F0: bnel        $at, $zero, L_80023900
    if (ctx->r1 != 0) {
        // 0x800238F4: mtc1        $v0, $f4
        ctx->f4.u32l = ctx->r2;
            goto L_80023900;
    }
    goto skip_0;
    // 0x800238F4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    skip_0:
    // 0x800238F8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800238FC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
L_80023900:
    // 0x80023900: sw          $v0, 0xE0($v1)
    MEM_W(0XE0, ctx->r3) = ctx->r2;
    // 0x80023904: bgez        $v0, L_8002391C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80023908: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8002391C;
    }
    // 0x80023908: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002390C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80023910: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023914: nop

    // 0x80023918: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8002391C:
    // 0x8002391C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80023920: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023924: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80023928: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002392C: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80023930: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80023934: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023938: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002393C: lwc1        $f2, -0x2DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2DC);
    // 0x80023940: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80023944: b           L_800239D8
    // 0x80023948: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
        goto L_800239D8;
    // 0x80023948: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
L_8002394C:
    // 0x8002394C: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80023950: bne         $at, $zero, L_80023990
    if (ctx->r1 != 0) {
        // 0x80023954: addiu       $t6, $v1, -0xA
        ctx->r14 = ADD32(ctx->r3, -0XA);
            goto L_80023990;
    }
    // 0x80023954: addiu       $t6, $v1, -0xA
    ctx->r14 = ADD32(ctx->r3, -0XA);
    // 0x80023958: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8002395C: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x80023960: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80023964: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80023968: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002396C: lwc1        $f4, -0x2D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2D8);
    // 0x80023970: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023974: lwc1        $f6, -0x2D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2D4);
    // 0x80023978: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002397C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80023980: lwc1        $f2, -0x2D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2D0);
    // 0x80023984: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80023988: b           L_800239D8
    // 0x8002398C: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
        goto L_800239D8;
    // 0x8002398C: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
L_80023990:
    // 0x80023990: blez        $v1, L_800239CC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80023994: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800239CC;
    }
    // 0x80023994: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80023998: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8002399C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800239A0: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800239A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800239A8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800239AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800239B0: lwc1        $f8, -0x2CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2CC);
    // 0x800239B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800239B8: lwc1        $f2, -0x2C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2C8);
    // 0x800239BC: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800239C0: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800239C4: b           L_800239D8
    // 0x800239C8: nop

        goto L_800239D8;
    // 0x800239C8: nop

L_800239CC:
    // 0x800239CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800239D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800239D4: nop

L_800239D8:
    // 0x800239D8: bgezl       $a0, L_800239E8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800239DC: swc1        $f0, 0xDC($a1)
        MEM_W(0XDC, ctx->r5) = ctx->f0.u32l;
            goto L_800239E8;
    }
    goto skip_1;
    // 0x800239DC: swc1        $f0, 0xDC($a1)
    MEM_W(0XDC, ctx->r5) = ctx->f0.u32l;
    skip_1:
    // 0x800239E0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800239E4: swc1        $f0, 0xDC($a1)
    MEM_W(0XDC, ctx->r5) = ctx->f0.u32l;
L_800239E8:
    // 0x800239E8: swc1        $f2, 0xE8($a1)
    MEM_W(0XE8, ctx->r5) = ctx->f2.u32l;
    // 0x800239EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800239F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800239F4: jr          $ra
    // 0x800239F8: nop

    return;
    // 0x800239F8: nop

;}
RECOMP_FUNC void func_80568E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80568E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568E20: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80568E24: addiu       $at, $zero, 0x4157
    ctx->r1 = ADD32(0, 0X4157);
    // 0x80568E28: beq         $v0, $at, L_80568E48
    if (ctx->r2 == ctx->r1) {
        // 0x80568E2C: addiu       $at, $zero, 0x4163
        ctx->r1 = ADD32(0, 0X4163);
            goto L_80568E48;
    }
    // 0x80568E2C: addiu       $at, $zero, 0x4163
    ctx->r1 = ADD32(0, 0X4163);
    // 0x80568E30: beq         $v0, $at, L_80568E58
    if (ctx->r2 == ctx->r1) {
        // 0x80568E34: addiu       $at, $zero, 0x416F
        ctx->r1 = ADD32(0, 0X416F);
            goto L_80568E58;
    }
    // 0x80568E34: addiu       $at, $zero, 0x416F
    ctx->r1 = ADD32(0, 0X416F);
    // 0x80568E38: beql        $v0, $at, L_80568E6C
    if (ctx->r2 == ctx->r1) {
        // 0x80568E3C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80568E6C;
    }
    goto skip_0;
    // 0x80568E3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80568E40: b           L_80568E78
    // 0x80568E44: nop

        goto L_80568E78;
    // 0x80568E44: nop

L_80568E48:
    // 0x80568E48: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80568E4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80568E50: b           L_80568E78
    // 0x80568E54: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
        goto L_80568E78;
    // 0x80568E54: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
L_80568E58:
    // 0x80568E58: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21F8) << 16);
    // 0x80568E5C: lwc1        $f6, -0x6858($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21F8));
    // 0x80568E60: b           L_80568E78
    // 0x80568E64: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
        goto L_80568E78;
    // 0x80568E64: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x80568E68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80568E6C:
    // 0x80568E6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80568E70: nop

    // 0x80568E74: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
L_80568E78:
    // 0x80568E78: jal         0x80568710
    // 0x80568E7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80568E7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80568E80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80568E84: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80568E88: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80568E8C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80568E90: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568E94: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80568E98: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80568E9C: jal         0x80569310
    // 0x80568EA0: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    func_80569310(rdram, ctx);
        goto after_1;
    // 0x80568EA0: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x80568EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80568EAC: jr          $ra
    // 0x80568EB0: nop

    return;
    // 0x80568EB0: nop

;}
RECOMP_FUNC void func_80032DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032DAC: jal         0x80032B50
    // 0x80032DB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80032B50(rdram, ctx);
        goto after_0;
    // 0x80032DB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80032DB4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80032DB8: jal         0x80065954
    // 0x80032DBC: lwc1        $f12, 0xC4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC4);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80032DBC: lwc1        $f12, 0xC4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC4);
    after_1:
    // 0x80032DC0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80032DC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80032DC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80032DCC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80032DD0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80032DD4: jal         0x80041214
    // 0x80032DD8: nop

    func_80041214(rdram, ctx);
        goto after_2;
    // 0x80032DD8: nop

    after_2:
    // 0x80032DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032DE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032DE4: jr          $ra
    // 0x80032DE8: nop

    return;
    // 0x80032DE8: nop

;}
RECOMP_FUNC void func_806FE2F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FE2F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FE2FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FE300: jal         0x80056904
    // 0x806FE304: nop

    func_80056904(rdram, ctx);
        goto after_0;
    // 0x806FE304: nop

    after_0:
    // 0x806FE308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FE30C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FE310: jr          $ra
    // 0x806FE314: nop

    return;
    // 0x806FE314: nop

;}
RECOMP_FUNC void func_8064B81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B81C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8064B820: lui         $t6, 0x8065
    ctx->r14 = S32(RELOC_HI16(495, 0X15CC) << 16);
    // 0x8064B824: addiu       $t6, $t6, -0x4964
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(495, 0X15CC));
    // 0x8064B828: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064B82C: jr          $ra
    // 0x8064B830: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8064B830: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80430654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430654: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80430658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043065C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80430660: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80430664: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X38C0) << 16);
    // 0x80430668: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043066C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80430670: lw          $t8, 0x19A0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X38C0));
    // 0x80430674: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80430678: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8043067C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80430680: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80430684: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80430688: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8043068C: beql        $v1, $zero, L_804306C0
    if (ctx->r3 == 0) {
        // 0x80430690: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804306C0;
    }
    goto skip_0;
    // 0x80430690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80430694: jalr        $v1
    // 0x80430698: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80430698: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043069C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804306A0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804306A4: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804306A8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804306AC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804306B0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804306B4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804306B8: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804306BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804306C0:
    // 0x804306C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804306C4: jr          $ra
    // 0x804306C8: nop

    return;
    // 0x804306C8: nop

;}
RECOMP_FUNC void func_807A632C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A632C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807A6330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A6334: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A6338: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X156C) << 16);
    // 0x807A633C: lwc1        $f6, 0x726C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X156C));
    // 0x807A6340: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807A6344: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807A6348: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X157C) << 16);
    // 0x807A634C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807A6350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A6354: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x807A6358: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807A635C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x807A6360: nop

    // 0x807A6364: bc1f        L_807A6408
    if (!c1cs) {
        // 0x807A6368: nop
    
            goto L_807A6408;
    }
    // 0x807A6368: nop

    // 0x807A636C: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x807A6370: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807A6374: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807A6378: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807A637C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x807A6380: jal         0x800659EC
    // 0x807A6384: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    func_800659EC(rdram, ctx);
        goto after_0;
    // 0x807A6384: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x807A6388: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807A638C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x807A6390: jal         0x80066DE4
    // 0x807A6394: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x807A6394: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x807A6398: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1570) << 16);
    // 0x807A639C: lwc1        $f14, 0x7270($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1570));
    // 0x807A63A0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1574) << 16);
    // 0x807A63A4: lwc1        $f4, 0x7274($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1574));
    // 0x807A63A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807A63AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807A63B0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x807A63B4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807A63B8: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1578) << 16);
    // 0x807A63BC: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807A63C0: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x807A63C4: add.s       $f16, $f14, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x807A63C8: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    // 0x807A63CC: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
    // 0x807A63D0: lwc1        $f4, 0x7278($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1578));
    // 0x807A63D4: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x807A63D8: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807A63DC: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x807A63E0: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x807A63E4: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807A63E8: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x807A63EC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807A63F0: add.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x807A63F4: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x807A63F8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x807A63FC: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x807A6400: b           L_807A6440
    // 0x807A6404: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
        goto L_807A6440;
    // 0x807A6404: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
L_807A6408:
    // 0x807A6408: lwc1        $f14, 0x727C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X157C));
    // 0x807A640C: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x807A6410: addiu       $at, $zero, 0x46E6
    ctx->r1 = ADD32(0, 0X46E6);
    // 0x807A6414: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x807A6418: swc1        $f14, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f14.u32l;
    // 0x807A641C: beq         $t6, $at, L_807A6438
    if (ctx->r14 == ctx->r1) {
        // 0x807A6420: swc1        $f14, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f14.u32l;
            goto L_807A6438;
    }
    // 0x807A6420: swc1        $f14, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f14.u32l;
    // 0x807A6424: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1580) << 16);
    // 0x807A6428: lwc1        $f10, 0x7280($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1580));
    // 0x807A642C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807A6430: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x807A6434: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
L_807A6438:
    // 0x807A6438: jal         0x807A6778
    // 0x807A643C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_807A6778(rdram, ctx);
        goto after_2;
    // 0x807A643C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
L_807A6440:
    // 0x807A6440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A6444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807A6448: jr          $ra
    // 0x807A644C: nop

    return;
    // 0x807A644C: nop

;}
RECOMP_FUNC void func_807AF5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF5F0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x807AF5F4: addiu       $at, $zero, 0x44CE
    ctx->r1 = ADD32(0, 0X44CE);
    // 0x807AF5F8: beq         $v0, $at, L_807AF620
    if (ctx->r2 == ctx->r1) {
        // 0x807AF5FC: addiu       $at, $zero, 0x44CF
        ctx->r1 = ADD32(0, 0X44CF);
            goto L_807AF620;
    }
    // 0x807AF5FC: addiu       $at, $zero, 0x44CF
    ctx->r1 = ADD32(0, 0X44CF);
    // 0x807AF600: beq         $v0, $at, L_807AF62C
    if (ctx->r2 == ctx->r1) {
        // 0x807AF604: addiu       $at, $zero, 0x4519
        ctx->r1 = ADD32(0, 0X4519);
            goto L_807AF62C;
    }
    // 0x807AF604: addiu       $at, $zero, 0x4519
    ctx->r1 = ADD32(0, 0X4519);
    // 0x807AF608: beq         $v0, $at, L_807AF638
    if (ctx->r2 == ctx->r1) {
        // 0x807AF60C: addiu       $at, $zero, 0x451A
        ctx->r1 = ADD32(0, 0X451A);
            goto L_807AF638;
    }
    // 0x807AF60C: addiu       $at, $zero, 0x451A
    ctx->r1 = ADD32(0, 0X451A);
    // 0x807AF610: beq         $v0, $at, L_807AF644
    if (ctx->r2 == ctx->r1) {
        // 0x807AF614: nop
    
            goto L_807AF644;
    }
    // 0x807AF614: nop

    // 0x807AF618: b           L_807AF650
    // 0x807AF61C: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(868, 0X314) << 16);
        goto L_807AF650;
    // 0x807AF61C: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(868, 0X314) << 16);
L_807AF620:
    // 0x807AF620: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(868, 0X314) << 16);
    // 0x807AF624: jr          $ra
    // 0x807AF628: addiu       $v0, $v0, -0x6FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(868, 0X314));
    return;
    // 0x807AF628: addiu       $v0, $v0, -0x6FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(868, 0X314));
L_807AF62C:
    // 0x807AF62C: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(868, 0X364) << 16);
    // 0x807AF630: jr          $ra
    // 0x807AF634: addiu       $v0, $v0, -0x6AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(868, 0X364));
    return;
    // 0x807AF634: addiu       $v0, $v0, -0x6AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(868, 0X364));
L_807AF638:
    // 0x807AF638: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(868, 0X3B4) << 16);
    // 0x807AF63C: jr          $ra
    // 0x807AF640: addiu       $v0, $v0, -0x65C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(868, 0X3B4));
    return;
    // 0x807AF640: addiu       $v0, $v0, -0x65C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(868, 0X3B4));
L_807AF644:
    // 0x807AF644: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(868, 0X400) << 16);
    // 0x807AF648: jr          $ra
    // 0x807AF64C: addiu       $v0, $v0, -0x610
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(868, 0X400));
    return;
    // 0x807AF64C: addiu       $v0, $v0, -0x610
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(868, 0X400));
L_807AF650:
    // 0x807AF650: addiu       $v0, $v0, -0x6FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(868, 0X314));
    // 0x807AF654: jr          $ra
    // 0x807AF658: nop

    return;
    // 0x807AF658: nop

;}
RECOMP_FUNC void func_80699FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069A000: jal         0x80699C60
    // 0x8069A004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80699C60(rdram, ctx);
        goto after_0;
    // 0x8069A004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069A008: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069A00C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069A010: jal         0x8069A0F0
    // 0x8069A014: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8069A0F0(rdram, ctx);
        goto after_1;
    // 0x8069A014: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8069A018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069A01C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069A020: jr          $ra
    // 0x8069A024: nop

    return;
    // 0x8069A024: nop

;}
RECOMP_FUNC void func_805270E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805270E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805270EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805270F0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x805270F4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x805270F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805270FC: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80527100: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80527104: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80527108: nop

    // 0x8052710C: bc1fl       L_805271B8
    if (!c1cs) {
        // 0x80527110: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_805271B8;
    }
    goto skip_0;
    // 0x80527110: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80527114: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80527118: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8052711C: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80527120: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80527124: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80527128: bne         $at, $zero, L_80527198
    if (ctx->r1 != 0) {
        // 0x8052712C: swc1        $f6, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
            goto L_80527198;
    }
    // 0x8052712C: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    // 0x80527130: lw          $t8, 0x78($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X78);
    // 0x80527134: blezl       $t8, L_8052715C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80527138: lhu         $v0, 0xC($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0XC);
            goto L_8052715C;
    }
    goto skip_1;
    // 0x80527138: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    skip_1:
    // 0x8052713C: lw          $t0, 0x78($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X78);
    // 0x80527140: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80527144: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x80527148: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8052714C: sw          $t1, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r9;
    // 0x80527150: b           L_805271C4
    // 0x80527154: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_805271C4;
    // 0x80527154: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80527158: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
L_8052715C:
    // 0x8052715C: addiu       $at, $zero, 0x41ED
    ctx->r1 = ADD32(0, 0X41ED);
    // 0x80527160: beq         $v0, $at, L_80527188
    if (ctx->r2 == ctx->r1) {
        // 0x80527164: addiu       $at, $zero, 0x41EF
        ctx->r1 = ADD32(0, 0X41EF);
            goto L_80527188;
    }
    // 0x80527164: addiu       $at, $zero, 0x41EF
    ctx->r1 = ADD32(0, 0X41EF);
    // 0x80527168: beq         $v0, $at, L_80527188
    if (ctx->r2 == ctx->r1) {
        // 0x8052716C: addiu       $at, $zero, 0x41F0
        ctx->r1 = ADD32(0, 0X41F0);
            goto L_80527188;
    }
    // 0x8052716C: addiu       $at, $zero, 0x41F0
    ctx->r1 = ADD32(0, 0X41F0);
    // 0x80527170: bne         $v0, $at, L_80527188
    if (ctx->r2 != ctx->r1) {
        // 0x80527174: nop
    
            goto L_80527188;
    }
    // 0x80527174: nop

    // 0x80527178: jal         0x805270C8
    // 0x8052717C: nop

    func_805270C8(rdram, ctx);
        goto after_0;
    // 0x8052717C: nop

    after_0:
    // 0x80527180: b           L_805271C8
    // 0x80527184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805271C8;
    // 0x80527184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527188:
    // 0x80527188: jal         0x8052707C
    // 0x8052718C: nop

    func_8052707C(rdram, ctx);
        goto after_1;
    // 0x8052718C: nop

    after_1:
    // 0x80527190: b           L_805271C8
    // 0x80527194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805271C8;
    // 0x80527194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527198:
    // 0x80527198: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x8052719C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x805271A0: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x805271A4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x805271A8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x805271AC: b           L_805271C4
    // 0x805271B0: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
        goto L_805271C4;
    // 0x805271B0: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x805271B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_805271B8:
    // 0x805271B8: nop

    // 0x805271BC: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x805271C0: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
L_805271C4:
    // 0x805271C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805271C8:
    // 0x805271C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805271CC: jr          $ra
    // 0x805271D0: nop

    return;
    // 0x805271D0: nop

;}
RECOMP_FUNC void func_80664DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80664DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80664DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80664DF8: jal         0x80664DB0
    // 0x80664DFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80664DB0(rdram, ctx);
        goto after_0;
    // 0x80664DFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80664E00: jal         0x80045BD8
    // 0x80664E04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80664E04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80664E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80664E0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80664E10: jr          $ra
    // 0x80664E14: nop

    return;
    // 0x80664E14: nop

;}
RECOMP_FUNC void func_80475E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475E00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475E04: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475E08: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475E0C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475E10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475E14: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26E08) << 16);
    // 0x80475E18: addiu       $a2, $a2, -0x4A38
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26E08));
    // 0x80475E1C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80475E20: jal         0x80475B40
    // 0x80475E24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475B40(rdram, ctx);
        goto after_0;
    // 0x80475E24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475E28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475E2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475E30: jr          $ra
    // 0x80475E34: nop

    return;
    // 0x80475E34: nop

;}
RECOMP_FUNC void func_806EC098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EC09C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EC0A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806EC0A4: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806EC0A8: jal         0x80067BBC
    // 0x806EC0AC: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806EC0AC: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x806EC0B0: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x806EC0B4: jal         0x80067818
    // 0x806EC0B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806EC0B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806EC0BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EC0C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EC0C4: jr          $ra
    // 0x806EC0C8: nop

    return;
    // 0x806EC0C8: nop

;}
RECOMP_FUNC void func_804C5608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5608: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804C560C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C5610: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C5614: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x804C5618: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C561C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x804C5620: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x804C5624: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x804C5628: beq         $v1, $zero, L_804C5634
    if (ctx->r3 == 0) {
        // 0x804C562C: sw          $t6, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r14;
            goto L_804C5634;
    }
    // 0x804C562C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x804C5630: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
L_804C5634:
    // 0x804C5634: jal         0x804C50B4
    // 0x804C5638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C50B4(rdram, ctx);
        goto after_0;
    // 0x804C5638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x804C563C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x804C5640: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x804C5644: jal         0x80048F84
    // 0x804C5648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x804C5648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x804C564C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x804C5650: jal         0x80048F84
    // 0x804C5654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x804C5654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x804C5658: jal         0x804C53C4
    // 0x804C565C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C53C4(rdram, ctx);
        goto after_3;
    // 0x804C565C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804C5660: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804C5664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C5668: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x804C566C: beql        $t8, $zero, L_804C5684
    if (ctx->r24 == 0) {
        // 0x804C5670: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804C5684;
    }
    goto skip_0;
    // 0x804C5670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804C5674: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x804C5678: jal         0x804C57AC
    // 0x804C567C: lbu         $a1, 0x18($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X18);
    func_804C57AC(rdram, ctx);
        goto after_4;
    // 0x804C567C: lbu         $a1, 0x18($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X18);
    after_4:
    // 0x804C5680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C5684:
    // 0x804C5684: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C5688: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804C568C: jr          $ra
    // 0x804C5690: nop

    return;
    // 0x804C5690: nop

;}
RECOMP_FUNC void func_8006EDF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EDF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EDF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EDFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006EE00: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8006EE04: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8006EE08: addiu       $v1, $zero, 0x4002
    ctx->r3 = ADD32(0, 0X4002);
    // 0x8006EE0C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8006EE10: beq         $v1, $v0, L_8006EE20
    if (ctx->r3 == ctx->r2) {
        // 0x8006EE14: nop
    
            goto L_8006EE20;
    }
    // 0x8006EE14: nop

    // 0x8006EE18: bnel        $v0, $at, L_8006EE68
    if (ctx->r2 != ctx->r1) {
        // 0x8006EE1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006EE68;
    }
    goto skip_0;
    // 0x8006EE1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8006EE20:
    // 0x8006EE20: bne         $v1, $v0, L_8006EE4C
    if (ctx->r3 != ctx->r2) {
        // 0x8006EE24: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_8006EE4C;
    }
    // 0x8006EE24: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8006EE28: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x8006EE2C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8006EE30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006EE34: bne         $t6, $at, L_8006EE64
    if (ctx->r14 != ctx->r1) {
        // 0x8006EE38: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_8006EE64;
    }
    // 0x8006EE38: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8006EE3C: jal         0x8006F070
    // 0x8006EE40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8006F070(rdram, ctx);
        goto after_0;
    // 0x8006EE40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8006EE44: b           L_8006EE68
    // 0x8006EE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006EE68;
    // 0x8006EE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006EE4C:
    // 0x8006EE4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006EE50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006EE54: jal         0x8006F070
    // 0x8006EE58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006F070(rdram, ctx);
        goto after_1;
    // 0x8006EE58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8006EE5C: jal         0x8006E970
    // 0x8006EE60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006E970(rdram, ctx);
        goto after_2;
    // 0x8006EE60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8006EE64:
    // 0x8006EE64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006EE68:
    // 0x8006EE68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EE6C: jr          $ra
    // 0x8006EE70: nop

    return;
    // 0x8006EE70: nop

;}
RECOMP_FUNC void func_806E3CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3CC0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806E3CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E3CC8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x806E3CCC: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x806E3CD0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x806E3CD4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E3CD8: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(649, 0X2190) << 16);
    // 0x806E3CDC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806E3CE0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x806E3CE4: lwc1        $f4, 0x5990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X2190));
    // 0x806E3CE8: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806E3CEC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806E3CF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806E3CF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806E3CF8: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(649, 0X21E0) << 16);
    // 0x806E3CFC: lwc1        $f6, 0x59E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X21E0));
    // 0x806E3D00: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806E3D04: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x806E3D08: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806E3D0C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x806E3D10: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x806E3D14: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806E3D18: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x806E3D1C: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x806E3D20: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x806E3D24: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x806E3D28: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806E3D2C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x806E3D30: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x806E3D34: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x806E3D38: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x806E3D3C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x806E3D40: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x806E3D44: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x806E3D48: lw          $t9, 0x10($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X10);
    // 0x806E3D4C: jalr        $t9
    // 0x806E3D50: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806E3D50: nop

    after_0:
    // 0x806E3D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E3D58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806E3D5C: jr          $ra
    // 0x806E3D60: nop

    return;
    // 0x806E3D60: nop

;}
RECOMP_FUNC void func_805A6E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6E58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805A6E5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A6E60: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x805A6E64: jr          $ra
    // 0x805A6E68: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    return;
    // 0x805A6E68: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80038F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038F38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80038F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038F40: jal         0x8004700C
    // 0x80038F44: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80038F44: nop

    after_0:
    // 0x80038F48: beql        $v0, $zero, L_80038F8C
    if (ctx->r2 == 0) {
        // 0x80038F4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038F8C;
    }
    goto skip_0;
    // 0x80038F4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80038F50: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80038F54: lw          $a0, 0x1F4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1F4);
    // 0x80038F58: beql        $a0, $zero, L_80038F8C
    if (ctx->r4 == 0) {
        // 0x80038F5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038F8C;
    }
    goto skip_1;
    // 0x80038F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80038F60: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80038F64: jal         0x8004816C
    // 0x80038F68: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x80038F68: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80038F6C: jal         0x8005FE48
    // 0x80038F70: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x80038F70: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80038F74: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80038F78: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80038F7C: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80038F80: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x80038F84: sw          $zero, 0x1F4($v1)
    MEM_W(0X1F4, ctx->r3) = 0;
    // 0x80038F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038F8C:
    // 0x80038F8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80038F90: jr          $ra
    // 0x80038F94: nop

    return;
    // 0x80038F94: nop

;}
RECOMP_FUNC void func_806665CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806665CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806665D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806665D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806665D8: jal         0x80045A34
    // 0x806665DC: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806665DC: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    after_0:
    // 0x806665E0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806665E4: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x806665E8: bne         $v0, $zero, L_806665F8
    if (ctx->r2 != 0) {
        // 0x806665EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806665F8;
    }
    // 0x806665EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806665F0: b           L_806665FC
    // 0x806665F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806665FC;
    // 0x806665F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806665F8:
    // 0x806665F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806665FC:
    // 0x806665FC: jr          $ra
    // 0x80666600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80666600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804A1D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1D18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804A1D1C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804A1D20: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x804A1D24: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x804A1D28: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x804A1D2C: lwc1        $f20, 0x3C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A1D30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A1D34: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804A1D38: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A1D3C: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x804A1D40: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x804A1D44: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x804A1D48: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A1D4C: bc1f        L_804A1D74
    if (!c1cs) {
        // 0x804A1D50: mov.s       $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
            goto L_804A1D74;
    }
    // 0x804A1D50: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x804A1D54: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x804A1D58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804A1D5C: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X318C) << 16);
    // 0x804A1D60: lwc1        $f10, 0x35CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X318C));
    // 0x804A1D64: sub.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x804A1D68: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804A1D6C: b           L_804A1DA0
    // 0x804A1D70: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
        goto L_804A1DA0;
    // 0x804A1D70: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
L_804A1D74:
    // 0x804A1D74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804A1D78: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X3190) << 16);
    // 0x804A1D7C: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x804A1D80: nop

    // 0x804A1D84: bc1fl       L_804A1DA0
    if (!c1cs) {
        // 0x804A1D88: lui         $at, 0x42FA
        ctx->r1 = S32(0X42FA << 16);
            goto L_804A1DA0;
    }
    goto skip_0;
    // 0x804A1D88: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    skip_0:
    // 0x804A1D8C: sub.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x804A1D90: lwc1        $f6, 0x35D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X3190));
    // 0x804A1D94: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804A1D98: nop

    // 0x804A1D9C: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
L_804A1DA0:
    // 0x804A1DA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804A1DA4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x804A1DA8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x804A1DAC: nop

    // 0x804A1DB0: bc1fl       L_804A1DD4
    if (!c1cs) {
        // 0x804A1DB4: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_804A1DD4;
    }
    goto skip_1;
    // 0x804A1DB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
    // 0x804A1DB8: sub.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x804A1DBC: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X3194) << 16);
    // 0x804A1DC0: lwc1        $f10, 0x35D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X3194));
    // 0x804A1DC4: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804A1DC8: b           L_804A1DFC
    // 0x804A1DCC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
        goto L_804A1DFC;
    // 0x804A1DCC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x804A1DD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_804A1DD4:
    // 0x804A1DD4: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X3198) << 16);
    // 0x804A1DD8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x804A1DDC: nop

    // 0x804A1DE0: bc1fl       L_804A1DFC
    if (!c1cs) {
        // 0x804A1DE4: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_804A1DFC;
    }
    goto skip_2;
    // 0x804A1DE4: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_2:
    // 0x804A1DE8: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x804A1DEC: lwc1        $f6, 0x35D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X3198));
    // 0x804A1DF0: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804A1DF4: nop

    // 0x804A1DF8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_804A1DFC:
    // 0x804A1DFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804A1E00: bc1fl       L_804A1E10
    if (!c1cs) {
        // 0x804A1E04: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_804A1E10;
    }
    goto skip_3;
    // 0x804A1E04: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_3:
    // 0x804A1E08: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A1E0C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_804A1E10:
    // 0x804A1E10: nop

    // 0x804A1E14: bc1fl       L_804A1E24
    if (!c1cs) {
        // 0x804A1E18: c.lt.s      $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
            goto L_804A1E24;
    }
    goto skip_4;
    // 0x804A1E18: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    skip_4:
    // 0x804A1E1C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x804A1E20: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
L_804A1E24:
    // 0x804A1E24: nop

    // 0x804A1E28: bc1fl       L_804A1E38
    if (!c1cs) {
        // 0x804A1E2C: c.lt.s      $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
            goto L_804A1E38;
    }
    goto skip_5;
    // 0x804A1E2C: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    skip_5:
    // 0x804A1E30: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x804A1E34: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
L_804A1E38:
    // 0x804A1E38: nop

    // 0x804A1E3C: bc1fl       L_804A1E4C
    if (!c1cs) {
        // 0x804A1E40: add.s       $f8, $f2, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
            goto L_804A1E4C;
    }
    goto skip_6;
    // 0x804A1E40: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    skip_6:
    // 0x804A1E44: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x804A1E48: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
L_804A1E4C:
    // 0x804A1E4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804A1E50: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x804A1E54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804A1E58: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804A1E5C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804A1E60: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x804A1E64: sub.s       $f18, $f14, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x804A1E68: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x804A1E6C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x804A1E70: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x804A1E74: nop

    // 0x804A1E78: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x804A1E7C: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x804A1E80: nop

    // 0x804A1E84: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x804A1E88: beql        $v1, $zero, L_804A1ED8
    if (ctx->r3 == 0) {
        // 0x804A1E8C: mfc1        $v1, $f10
        ctx->r3 = (int32_t)ctx->f10.u32l;
            goto L_804A1ED8;
    }
    goto skip_7;
    // 0x804A1E8C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    skip_7:
    // 0x804A1E90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804A1E94: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804A1E98: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804A1E9C: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x804A1EA0: nop

    // 0x804A1EA4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x804A1EA8: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x804A1EAC: nop

    // 0x804A1EB0: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x804A1EB4: bne         $v1, $zero, L_804A1ECC
    if (ctx->r3 != 0) {
        // 0x804A1EB8: nop
    
            goto L_804A1ECC;
    }
    // 0x804A1EB8: nop

    // 0x804A1EBC: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x804A1EC0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804A1EC4: b           L_804A1EE4
    // 0x804A1EC8: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_804A1EE4;
    // 0x804A1EC8: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_804A1ECC:
    // 0x804A1ECC: b           L_804A1EE4
    // 0x804A1ED0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_804A1EE4;
    // 0x804A1ED0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x804A1ED4: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
L_804A1ED8:
    // 0x804A1ED8: nop

    // 0x804A1EDC: bltz        $v1, L_804A1ECC
    if (SIGNED(ctx->r3) < 0) {
        // 0x804A1EE0: nop
    
            goto L_804A1ECC;
    }
    // 0x804A1EE0: nop

L_804A1EE4:
    // 0x804A1EE4: sb          $v1, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r3;
    // 0x804A1EE8: sb          $v1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r3;
    // 0x804A1EEC: sb          $v1, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r3;
    // 0x804A1EF0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x804A1EF4: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x804A1EF8: jr          $ra
    // 0x804A1EFC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x804A1EFC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_806CFBF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFBF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CFBF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CFBFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CFC00: jal         0x806CF9B8
    // 0x806CFC04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CF9B8(rdram, ctx);
        goto after_0;
    // 0x806CFC04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CFC08: jal         0x806CFA34
    // 0x806CFC0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CFA34(rdram, ctx);
        goto after_1;
    // 0x806CFC0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CFC10: jal         0x806CFAB8
    // 0x806CFC14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CFAB8(rdram, ctx);
        goto after_2;
    // 0x806CFC14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806CFC18: bne         $v0, $zero, L_806CFC48
    if (ctx->r2 != 0) {
        // 0x806CFC1C: lui         $at, 0x806D
        ctx->r1 = S32(RELOC_HI16(607, 0X1ADC) << 16);
            goto L_806CFC48;
    }
    // 0x806CFC1C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1ADC) << 16);
    // 0x806CFC20: lwc1        $f4, 0x127C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1ADC));
    // 0x806CFC24: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806CFC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CFC2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CFC30: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806CFC34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806CFC38: bc1fl       L_806CFC4C
    if (!c1cs) {
        // 0x806CFC3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CFC4C;
    }
    goto skip_0;
    // 0x806CFC3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806CFC40: jal         0x806D093C
    // 0x806CFC44: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806D093C(rdram, ctx);
        goto after_3;
    // 0x806CFC44: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
L_806CFC48:
    // 0x806CFC48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CFC4C:
    // 0x806CFC4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CFC50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CFC54: jr          $ra
    // 0x806CFC58: nop

    return;
    // 0x806CFC58: nop

;}
RECOMP_FUNC void func_80674030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80674030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80674034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80674038: lbu         $t7, 0x158($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X158);
    // 0x8067403C: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80674040: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80674044: bne         $t7, $at, L_80674080
    if (ctx->r15 != ctx->r1) {
        // 0x80674048: sw          $t6, 0x150($a0)
        MEM_W(0X150, ctx->r4) = ctx->r14;
            goto L_80674080;
    }
    // 0x80674048: sw          $t6, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->r14;
    // 0x8067404C: jal         0x80673F6C
    // 0x80674050: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80673F6C(rdram, ctx);
        goto after_0;
    // 0x80674050: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80674054: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80674058: bne         $v0, $at, L_806740C4
    if (ctx->r2 != ctx->r1) {
        // 0x8067405C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806740C4;
    }
    // 0x8067405C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80674060: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x80674064: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x80674068: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8067406C: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    // 0x80674070: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80674074: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80674078: b           L_806740C8
    // 0x8067407C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_806740C8;
    // 0x8067407C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80674080:
    // 0x80674080: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x80674084: lbu         $t1, 0xC($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XC);
    // 0x80674088: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8067408C: bnel        $t1, $at, L_806740C8
    if (ctx->r9 != ctx->r1) {
        // 0x80674090: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806740C8;
    }
    goto skip_0;
    // 0x80674090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80674094: jal         0x80673FD0
    // 0x80674098: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80673FD0(rdram, ctx);
        goto after_1;
    // 0x80674098: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x8067409C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806740A0: bne         $v0, $at, L_806740C4
    if (ctx->r2 != ctx->r1) {
        // 0x806740A4: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_806740C4;
    }
    // 0x806740A4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806740A8: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x806740AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806740B0: sb          $t2, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r10;
    // 0x806740B4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x806740B8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x806740BC: b           L_806740C8
    // 0x806740C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806740C8;
    // 0x806740C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806740C4:
    // 0x806740C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806740C8:
    // 0x806740C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806740CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806740D0: jr          $ra
    // 0x806740D4: nop

    return;
    // 0x806740D4: nop

;}
RECOMP_FUNC void func_806EE338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EE33C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EE340: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806EE344: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806EE348: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806EE34C: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(676, 0X486C) << 16);
    // 0x806EE350: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806EE354: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806EE358: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806EE35C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806EE360: lw          $t8, 0x7BC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(676, 0X486C));
    // 0x806EE364: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806EE368: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806EE36C: jal         0x80048490
    // 0x806EE370: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806EE370: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806EE374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EE378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EE37C: jr          $ra
    // 0x806EE380: nop

    return;
    // 0x806EE380: nop

;}
RECOMP_FUNC void func_80531440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80531444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80531448: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X19F8) << 16);
    // 0x8053144C: lwc1        $f6, 0x27E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X19F8));
    // 0x80531450: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80531454: lwc1        $f10, 0x8C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8C);
    // 0x80531458: lwc1        $f18, 0x44($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X44);
    // 0x8053145C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80531460: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80531464: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80531468: swc1        $f4, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f4.u32l;
    // 0x8053146C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80531470: jal         0x8005FE48
    // 0x80531474: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x80531474: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80531478: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8053147C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80531480: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80531484: lw          $t6, 0x174($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X174);
    // 0x80531488: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8053148C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80531490: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80531494: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    // 0x80531498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8053149C: sb          $zero, 0x74($t7)
    MEM_B(0X74, ctx->r15) = 0;
    // 0x805314A0: swc1        $f0, 0x270($a2)
    MEM_W(0X270, ctx->r6) = ctx->f0.u32l;
    // 0x805314A4: swc1        $f0, 0x26C($a2)
    MEM_W(0X26C, ctx->r6) = ctx->f0.u32l;
    // 0x805314A8: jal         0x80067818
    // 0x805314AC: swc1        $f6, 0x274($a2)
    MEM_W(0X274, ctx->r6) = ctx->f6.u32l;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805314AC: swc1        $f6, 0x274($a2)
    MEM_W(0X274, ctx->r6) = ctx->f6.u32l;
    after_1:
    // 0x805314B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805314B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805314B8: jr          $ra
    // 0x805314BC: nop

    return;
    // 0x805314BC: nop

;}
RECOMP_FUNC void func_805ABBE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ABBE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805ABBEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805ABBF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805ABBF4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805ABBF8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x805ABBFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805ABC00: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x805ABC04: jal         0x800443EC
    // 0x805ABC08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800443EC(rdram, ctx);
        goto after_0;
    // 0x805ABC08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x805ABC0C: beq         $v0, $zero, L_805ABC98
    if (ctx->r2 == 0) {
        // 0x805ABC10: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_805ABC98;
    }
    // 0x805ABC10: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805ABC14: lwc1        $f4, 0x84($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X84);
    // 0x805ABC18: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(438, 0X580) << 16);
    // 0x805ABC1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805ABC20: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x805ABC24: lwc1        $f6, 0x88($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X88);
    // 0x805ABC28: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x805ABC2C: lwc1        $f10, -0x3EF0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(438, 0X580));
    // 0x805ABC30: lwc1        $f8, 0x8C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8C);
    // 0x805ABC34: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(438, 0X588) << 16);
    // 0x805ABC38: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x805ABC3C: nop

    // 0x805ABC40: bc1f        L_805ABC54
    if (!c1cs) {
        // 0x805ABC44: nop
    
            goto L_805ABC54;
    }
    // 0x805ABC44: nop

    // 0x805ABC48: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(438, 0X584) << 16);
    // 0x805ABC4C: b           L_805ABC58
    // 0x805ABC50: lwc1        $f0, -0x3EEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(438, 0X584));
        goto L_805ABC58;
    // 0x805ABC50: lwc1        $f0, -0x3EEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(438, 0X584));
L_805ABC54:
    // 0x805ABC54: lwc1        $f0, -0x3EE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(438, 0X588));
L_805ABC58:
    // 0x805ABC58: jal         0x80040C0C
    // 0x805ABC5C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    func_80040C0C(rdram, ctx);
        goto after_1;
    // 0x805ABC5C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x805ABC60: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805ABC64: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x805ABC68: jal         0x80047AB8
    // 0x805ABC6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x805ABC6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x805ABC70: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x805ABC74: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x805ABC78: addiu       $t6, $t6, 0x33B4
    ctx->r14 = ADD32(ctx->r14, 0X33B4);
    // 0x805ABC7C: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x805ABC80: addiu       $t7, $zero, 0xC0
    ctx->r15 = ADD32(0, 0XC0);
    // 0x805ABC84: addiu       $a0, $zero, 0x243
    ctx->r4 = ADD32(0, 0X243);
    // 0x805ABC88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805ABC8C: sw          $zero, 0x264($v0)
    MEM_W(0X264, ctx->r2) = 0;
    // 0x805ABC90: jal         0x80067818
    // 0x805ABC94: sw          $t7, 0x268($v0)
    MEM_W(0X268, ctx->r2) = ctx->r15;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x805ABC94: sw          $t7, 0x268($v0)
    MEM_W(0X268, ctx->r2) = ctx->r15;
    after_3:
L_805ABC98:
    // 0x805ABC98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805ABC9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805ABCA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805ABCA4: jr          $ra
    // 0x805ABCA8: nop

    return;
    // 0x805ABCA8: nop

;}
RECOMP_FUNC void func_804D1560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D1560: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804D1564: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804D1568: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x804D156C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804D1570: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x804D1574: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x804D1578: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x804D157C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x804D1580: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(246, 0X430) << 16);
    // 0x804D1584: slti        $at, $t7, 0x96
    ctx->r1 = SIGNED(ctx->r15) < 0X96 ? 1 : 0;
    // 0x804D1588: bne         $at, $zero, L_804D1598
    if (ctx->r1 != 0) {
        // 0x804D158C: addiu       $a0, $a0, 0x1700
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(246, 0X430));
            goto L_804D1598;
    }
    // 0x804D158C: addiu       $a0, $a0, 0x1700
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(246, 0X430));
    // 0x804D1590: b           L_804D1650
    // 0x804D1594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804D1650;
    // 0x804D1594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804D1598:
    // 0x804D1598: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x804D159C: lui         $a1, 0x400A
    ctx->r5 = S32(0X400A << 16);
    // 0x804D15A0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x804D15A4: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x804D15A8: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x804D15AC: jal         0x80046804
    // 0x804D15B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x804D15B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x804D15B4: bne         $v0, $zero, L_804D15C4
    if (ctx->r2 != 0) {
        // 0x804D15B8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_804D15C4;
    }
    // 0x804D15B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x804D15BC: b           L_804D1650
    // 0x804D15C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804D1650;
    // 0x804D15C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804D15C4:
    // 0x804D15C4: jal         0x80047090
    // 0x804D15C8: addiu       $a0, $zero, 0x400A
    ctx->r4 = ADD32(0, 0X400A);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x804D15C8: addiu       $a0, $zero, 0x400A
    ctx->r4 = ADD32(0, 0X400A);
    after_1:
    // 0x804D15CC: lhu         $t0, 0xE($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XE);
    // 0x804D15D0: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x804D15D4: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x804D15D8: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x804D15DC: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x804D15E0: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    // 0x804D15E4: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x804D15E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804D15EC: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x804D15F0: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x804D15F4: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x804D15F8: jal         0x80048378
    // 0x804D15FC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80048378(rdram, ctx);
        goto after_2;
    // 0x804D15FC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_2:
    // 0x804D1600: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x804D1604: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x804D1608: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804D160C: lui         $t4, 0x804D
    ctx->r12 = S32(RELOC_HI16(246, 0X50) << 16);
    // 0x804D1610: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x804D1614: lwc1        $f16, 0x18($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X18);
    // 0x804D1618: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x804D161C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x804D1620: swc1        $f16, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
    // 0x804D1624: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x804D1628: addiu       $t4, $t4, 0x1320
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(246, 0X50));
    // 0x804D162C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804D1630: swc1        $f18, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f18.u32l;
    // 0x804D1634: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x804D1638: swc1        $f0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f0.u32l;
    // 0x804D163C: swc1        $f4, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f4.u32l;
    // 0x804D1640: sw          $t3, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r11;
    // 0x804D1644: jal         0x80044194
    // 0x804D1648: sw          $t4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r12;
    func_80044194(rdram, ctx);
        goto after_3;
    // 0x804D1648: sw          $t4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r12;
    after_3:
    // 0x804D164C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_804D1650:
    // 0x804D1650: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804D1654: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x804D1658: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x804D165C: jr          $ra
    // 0x804D1660: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x804D1660: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804D1664: nop

    // 0x804D1668: nop

    // 0x804D166C: nop

;}
RECOMP_FUNC void func_804BA67C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BA67C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BA680: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BA684: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BA688: jal         0x804BA638
    // 0x804BA68C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804BA638(rdram, ctx);
        goto after_0;
    // 0x804BA68C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804BA690: bne         $v0, $zero, L_804BA6A8
    if (ctx->r2 != 0) {
        // 0x804BA694: lui         $t6, 0x804C
        ctx->r14 = S32(RELOC_HI16(185, 0X2360) << 16);
            goto L_804BA6A8;
    }
    // 0x804BA694: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(185, 0X2360) << 16);
    // 0x804BA698: jal         0x800445A4
    // 0x804BA69C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804BA69C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804BA6A0: b           L_804BA718
    // 0x804BA6A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804BA718;
    // 0x804BA6A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804BA6A8:
    // 0x804BA6A8: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x804BA6AC: addiu       $t6, $t6, -0x5E80
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(185, 0X2360));
    // 0x804BA6B0: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x804BA6B4: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x804BA6B8: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x804BA6BC: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x804BA6C0: lui         $t9, 0x804C
    ctx->r25 = S32(RELOC_HI16(185, 0X2A9C) << 16);
    // 0x804BA6C4: sw          $t8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r24;
    // 0x804BA6C8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804BA6CC: addiu       $t9, $t9, -0x5744
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(185, 0X2A9C));
    // 0x804BA6D0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x804BA6D4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804BA6D8: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804BA6DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BA6E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BA6E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804BA6E8: jal         0x804BA728
    // 0x804BA6EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804BA728(rdram, ctx);
        goto after_2;
    // 0x804BA6EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804BA6F0: jal         0x804BA2E8
    // 0x804BA6F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BA2E8(rdram, ctx);
        goto after_3;
    // 0x804BA6F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804BA6F8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x804BA6FC: sh          $t1, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r9;
    // 0x804BA700: jal         0x804B7F14
    // 0x804BA704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B7F14(rdram, ctx);
        goto after_4;
    // 0x804BA704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804BA708: lui         $t2, 0x804B
    ctx->r10 = S32(RELOC_HI16(185, 0X194) << 16);
    // 0x804BA70C: addiu       $t2, $t2, 0x7FB4
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(185, 0X194));
    // 0x804BA710: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x804BA714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804BA718:
    // 0x804BA718: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BA71C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BA720: jr          $ra
    // 0x804BA724: nop

    return;
    // 0x804BA724: nop

;}
RECOMP_FUNC void func_8046212C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046212C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80462130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80462134: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80462138: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8046213C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80462140: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80462144: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80462148: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8046214C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80462150: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80462154: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80462158: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8046215C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80462160: jal         0x80081E8C
    // 0x80462164: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    fatan2(rdram, ctx);
        goto after_0;
    // 0x80462164: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80462168: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8046216C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80462170: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A5C) << 16);
    // 0x80462174: lwc1        $f8, 0x3FEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A5C));
    // 0x80462178: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8046217C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80462180: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80462184: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x80462188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046218C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80462190: jr          $ra
    // 0x80462194: nop

    return;
    // 0x80462194: nop

;}
RECOMP_FUNC void func_80445E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445E5C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80445E60: addiu       $a1, $zero, 0x1EF0
    ctx->r5 = ADD32(0, 0X1EF0);
    // 0x80445E64: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80445E68: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80445E6C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80445E70: sw          $zero, 0x6C9C($v1)
    MEM_W(0X6C9C, ctx->r3) = 0;
    // 0x80445E74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80445E78: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80445E7C: addiu       $t7, $zero, 0x1B6C
    ctx->r15 = ADD32(0, 0X1B6C);
    // 0x80445E80: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
    // 0x80445E84: sw          $t7, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r15;
    // 0x80445E88: sw          $a1, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r5;
    // 0x80445E8C: jr          $ra
    // 0x80445E90: swc1        $f4, 0x6AA0($v1)
    MEM_W(0X6AA0, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x80445E90: swc1        $f4, 0x6AA0($v1)
    MEM_W(0X6AA0, ctx->r3) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80025ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025ADC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80025AE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80025AE4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80025AE8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80025AEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80025AF0: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80025AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025AF8: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x80025AFC: beql        $t8, $zero, L_80025B18
    if (ctx->r24 == 0) {
        // 0x80025B00: addiu       $a0, $a1, 0x14C
        ctx->r4 = ADD32(ctx->r5, 0X14C);
            goto L_80025B18;
    }
    goto skip_0;
    // 0x80025B00: addiu       $a0, $a1, 0x14C
    ctx->r4 = ADD32(ctx->r5, 0X14C);
    skip_0:
    // 0x80025B04: jal         0x80025ABC
    // 0x80025B08: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    func_80025ABC(rdram, ctx);
        goto after_0;
    // 0x80025B08: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    after_0:
    // 0x80025B0C: b           L_80025B20
    // 0x80025B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80025B20;
    // 0x80025B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80025B14: addiu       $a0, $a1, 0x14C
    ctx->r4 = ADD32(ctx->r5, 0X14C);
L_80025B18:
    // 0x80025B18: jal         0x80024680
    // 0x80025B1C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    func_80024680(rdram, ctx);
        goto after_1;
    // 0x80025B1C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
L_80025B20:
    // 0x80025B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80025B24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80025B28: jr          $ra
    // 0x80025B2C: nop

    return;
    // 0x80025B2C: nop

;}
RECOMP_FUNC void func_805ADF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADF94: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADF98: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADF9C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADFA0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADFA4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADFA8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADFAC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADFB0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADFB4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADFB8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADFBC: jr          $ra
    // 0x805ADFC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADFC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80022448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022448: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002244C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80022450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022454: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80022458: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002245C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80022460: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x80022464: bnel        $t7, $at, L_80022548
    if (ctx->r15 != ctx->r1) {
        // 0x80022468: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80022548;
    }
    goto skip_0;
    // 0x80022468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8002246C: lhu         $v0, 0xE($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XE);
    // 0x80022470: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80022474: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x80022478: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8002247C: bnel        $v0, $at, L_80022534
    if (ctx->r2 != ctx->r1) {
        // 0x80022480: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80022534;
    }
    goto skip_1;
    // 0x80022480: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_1:
    // 0x80022484: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x80022488: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x8002248C: slti        $at, $v0, -0x2F
    ctx->r1 = SIGNED(ctx->r2) < -0X2F ? 1 : 0;
    // 0x80022490: bne         $at, $zero, L_80022544
    if (ctx->r1 != 0) {
        // 0x80022494: slti        $at, $v0, 0x170
        ctx->r1 = SIGNED(ctx->r2) < 0X170 ? 1 : 0;
            goto L_80022544;
    }
    // 0x80022494: slti        $at, $v0, 0x170
    ctx->r1 = SIGNED(ctx->r2) < 0X170 ? 1 : 0;
    // 0x80022498: beq         $at, $zero, L_80022544
    if (ctx->r1 == 0) {
        // 0x8002249C: slti        $at, $v1, -0x2F
        ctx->r1 = SIGNED(ctx->r3) < -0X2F ? 1 : 0;
            goto L_80022544;
    }
    // 0x8002249C: slti        $at, $v1, -0x2F
    ctx->r1 = SIGNED(ctx->r3) < -0X2F ? 1 : 0;
    // 0x800224A0: bne         $at, $zero, L_80022544
    if (ctx->r1 != 0) {
        // 0x800224A4: slti        $at, $v1, 0x120
        ctx->r1 = SIGNED(ctx->r3) < 0X120 ? 1 : 0;
            goto L_80022544;
    }
    // 0x800224A4: slti        $at, $v1, 0x120
    ctx->r1 = SIGNED(ctx->r3) < 0X120 ? 1 : 0;
    // 0x800224A8: beql        $at, $zero, L_80022548
    if (ctx->r1 == 0) {
        // 0x800224AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80022548;
    }
    goto skip_2;
    // 0x800224AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800224B0: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800224B4: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x800224B8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800224BC: beql        $v0, $zero, L_800224D4
    if (ctx->r2 == 0) {
        // 0x800224C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800224D4;
    }
    goto skip_3;
    // 0x800224C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x800224C4: jalr        $v0
    // 0x800224C8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800224C8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x800224CC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800224D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800224D4:
    // 0x800224D4: jal         0x80022360
    // 0x800224D8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80022360(rdram, ctx);
        goto after_1;
    // 0x800224D8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x800224DC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800224E0: beql        $v1, $zero, L_8002250C
    if (ctx->r3 == 0) {
        // 0x800224E4: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_8002250C;
    }
    goto skip_4;
    // 0x800224E4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_4:
    // 0x800224E8: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x800224EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800224F0: beql        $t8, $zero, L_8002250C
    if (ctx->r24 == 0) {
        // 0x800224F4: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_8002250C;
    }
    goto skip_5;
    // 0x800224F4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_5:
    // 0x800224F8: jal         0x80048060
    // 0x800224FC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80048060(rdram, ctx);
        goto after_2;
    // 0x800224FC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80022500: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80022504: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80022508: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_8002250C:
    // 0x8002250C: jal         0x80067BBC
    // 0x80022510: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x80022510: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x80022514: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    // 0x80022518: jal         0x80067818
    // 0x8002251C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8002251C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80022520: jal         0x800447C8
    // 0x80022524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x80022524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80022528: b           L_80022548
    // 0x8002252C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80022548;
    // 0x8002252C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022530: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_80022534:
    // 0x80022534: bne         $v0, $at, L_80022544
    if (ctx->r2 != ctx->r1) {
        // 0x80022538: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80022544;
    }
    // 0x80022538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002253C: jal         0x8003DBB4
    // 0x80022540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003DBB4(rdram, ctx);
        goto after_6;
    // 0x80022540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_80022544:
    // 0x80022544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80022548:
    // 0x80022548: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002254C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80022550: jr          $ra
    // 0x80022554: nop

    return;
    // 0x80022554: nop

;}
RECOMP_FUNC void func_807C3D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C3D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C3DA0: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807C3DA4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x807C3DA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C3DAC: beq         $v0, $zero, L_807C3DC0
    if (ctx->r2 == 0) {
        // 0x807C3DB0: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_807C3DC0;
    }
    // 0x807C3DB0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x807C3DB4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807C3DB8: b           L_807C3DC8
    // 0x807C3DBC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_807C3DC8;
    // 0x807C3DBC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_807C3DC0:
    // 0x807C3DC0: jal         0x807C3EC0
    // 0x807C3DC4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    func_807C3EC0(rdram, ctx);
        goto after_0;
    // 0x807C3DC4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    after_0:
L_807C3DC8:
    // 0x807C3DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C3DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C3DD0: jr          $ra
    // 0x807C3DD4: nop

    return;
    // 0x807C3DD4: nop

;}
RECOMP_FUNC void func_80435094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435094: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80435098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043509C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804350A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804350A4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x804350A8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x804350AC: addiu       $t7, $v0, 0x2E0
    ctx->r15 = ADD32(ctx->r2, 0X2E0);
    // 0x804350B0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x804350B4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x804350B8: jal         0x80435044
    // 0x804350BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80435044(rdram, ctx);
        goto after_0;
    // 0x804350BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x804350C0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804350C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804350C8: lui         $t9, 0x8043
    ctx->r25 = S32(RELOC_HI16(71, 0X1544) << 16);
    // 0x804350CC: sw          $t8, 0x5C0($v0)
    MEM_W(0X5C0, ctx->r2) = ctx->r24;
    // 0x804350D0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x804350D4: addiu       $t9, $t9, 0x4FF4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(71, 0X1544));
    // 0x804350D8: lw          $t1, 0x16C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X16C);
    // 0x804350DC: sw          $t9, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r25;
    // 0x804350E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804350E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804350E8: jr          $ra
    // 0x804350EC: nop

    return;
    // 0x804350EC: nop

;}
RECOMP_FUNC void func_807370C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807370C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807370C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807370C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807370CC: jal         0x80047090
    // 0x807370D0: addiu       $a0, $zero, 0x462A
    ctx->r4 = ADD32(0, 0X462A);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807370D0: addiu       $a0, $zero, 0x462A
    ctx->r4 = ADD32(0, 0X462A);
    after_0:
    // 0x807370D4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x807370D8: lui         $at, 0x462A
    ctx->r1 = S32(0X462A << 16);
    // 0x807370DC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807370E0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x807370E4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x807370E8: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x807370EC: jal         0x8004613C
    // 0x807370F0: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807370F0: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    after_1:
    // 0x807370F4: bne         $v0, $zero, L_80737104
    if (ctx->r2 != 0) {
        // 0x807370F8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80737104;
    }
    // 0x807370F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807370FC: b           L_80737110
    // 0x80737100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80737110;
    // 0x80737100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80737104:
    // 0x80737104: jal         0x80044194
    // 0x80737108: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x80737108: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8073710C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80737110:
    // 0x80737110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80737114: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80737118: jr          $ra
    // 0x8073711C: nop

    return;
    // 0x8073711C: nop

;}
RECOMP_FUNC void func_80400068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80400068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80400070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80400074: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80400078: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8040007C: jal         0x80047090
    // 0x80400080: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80400080: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x80400084: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80400088: beq         $v0, $at, L_80400104
    if (ctx->r2 == ctx->r1) {
        // 0x8040008C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80400104;
    }
    // 0x8040008C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80400090: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80400094: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x80400098: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x8040009C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x804000A0: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x804000A4: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x804000A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x804000AC: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    // 0x804000B0: jal         0x8004613C
    // 0x804000B4: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804000B4: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    after_1:
    // 0x804000B8: beq         $v0, $zero, L_80400104
    if (ctx->r2 == 0) {
        // 0x804000BC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80400104;
    }
    // 0x804000BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804000C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804000C4: jal         0x80047F9C
    // 0x804000C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804000C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x804000CC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x804000D0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x804000D4: lbu         $v1, 0x2B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X2B);
    // 0x804000D8: lwc1        $f4, 0x6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x804000DC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x804000E0: swc1        $f4, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f4.u32l;
    // 0x804000E4: lwc1        $f6, 0x70($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X70);
    // 0x804000E8: swc1        $f6, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f6.u32l;
    // 0x804000EC: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x804000F0: beq         $v1, $at, L_804000FC
    if (ctx->r3 == ctx->r1) {
        // 0x804000F4: swc1        $f8, 0x74($a1)
        MEM_W(0X74, ctx->r5) = ctx->f8.u32l;
            goto L_804000FC;
    }
    // 0x804000F4: swc1        $f8, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->f8.u32l;
    // 0x804000F8: sb          $v1, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r3;
L_804000FC:
    // 0x804000FC: b           L_80400108
    // 0x80400100: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80400108;
    // 0x80400100: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80400104:
    // 0x80400104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80400108:
    // 0x80400108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040010C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80400110: jr          $ra
    // 0x80400114: nop

    return;
    // 0x80400114: nop

;}
RECOMP_FUNC void func_80437540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437540: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80437544: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80437548: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8043754C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80437550: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437554: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80437558: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8043755C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80437560: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80437564: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80437568: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8043756C: jal         0x80065490
    // 0x80437570: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x80437570: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80437574: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x80437578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043757C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80437580: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80437584: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80437588: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x8043758C: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x80437590: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x80437594: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80437598: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8043759C: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x804375A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804375A4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x804375A8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x804375AC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804375B0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x804375B4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x804375B8: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x804375BC: jal         0x80437440
    // 0x804375C0: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    func_80437440(rdram, ctx);
        goto after_1;
    // 0x804375C0: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x804375C4: beq         $v0, $zero, L_80437600
    if (ctx->r2 == 0) {
        // 0x804375C8: lw          $a3, 0x48($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X48);
            goto L_80437600;
    }
    // 0x804375C8: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x804375CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804375D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804375D4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x804375D8: jal         0x80436F3C
    // 0x804375DC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_80436F3C(rdram, ctx);
        goto after_2;
    // 0x804375DC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x804375E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804375E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804375E8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x804375EC: jal         0x80437048
    // 0x804375F0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_80437048(rdram, ctx);
        goto after_3;
    // 0x804375F0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x804375F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804375F8: b           L_8043763C
    // 0x804375FC: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
        goto L_8043763C;
    // 0x804375FC: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
L_80437600:
    // 0x80437600: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80437604: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80437608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8043760C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80437610: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80437614: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x80437618: lwc1        $f16, 0x40($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8043761C: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80437620: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80437624: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x80437628: lwc1        $f4, 0x44($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8043762C: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80437630: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80437634: jal         0x80437410
    // 0x80437638: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    func_80437410(rdram, ctx);
        goto after_4;
    // 0x80437638: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    after_4:
L_8043763C:
    // 0x8043763C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80437640: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80437644: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80437648: jr          $ra
    // 0x8043764C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8043764C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_806F1D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1D24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F1D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F1D2C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806F1D30: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806F1D34: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F1D38: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(679, 0X1A10) << 16);
    // 0x806F1D3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F1D40: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806F1D44: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806F1D48: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F1D4C: lw          $t8, 0x2F90($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(679, 0X1A10));
    // 0x806F1D50: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F1D54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F1D58: jal         0x80048490
    // 0x806F1D5C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806F1D5C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806F1D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F1D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F1D68: jr          $ra
    // 0x806F1D6C: nop

    return;
    // 0x806F1D6C: nop

;}
RECOMP_FUNC void func_8005AF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AF8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005AF90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005AF94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005AF98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005AF9C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005AFA0: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x8005AFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005AFA8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8005AFAC: lhu         $a1, 0x26($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X26);
    // 0x8005AFB0: jal         0x8006A8AC
    // 0x8005AFB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8006A8AC(rdram, ctx);
        goto after_0;
    // 0x8005AFB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005AFB8: bne         $v0, $zero, L_8005AFC8
    if (ctx->r2 != 0) {
        // 0x8005AFBC: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_8005AFC8;
    }
    // 0x8005AFBC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8005AFC0: b           L_8005B098
    // 0x8005AFC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B098;
    // 0x8005AFC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005AFC8:
    // 0x8005AFC8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8005AFCC: lw          $v1, 0x20($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X20);
    // 0x8005AFD0: bnel        $v1, $zero, L_8005AFE4
    if (ctx->r3 != 0) {
        // 0x8005AFD4: lh          $t7, 0x8($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X8);
            goto L_8005AFE4;
    }
    goto skip_0;
    // 0x8005AFD4: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
    skip_0:
    // 0x8005AFD8: b           L_8005B098
    // 0x8005AFDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005B098;
    // 0x8005AFDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005AFE0: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
L_8005AFE4:
    // 0x8005AFE4: sh          $t7, 0x30($a3)
    MEM_H(0X30, ctx->r7) = ctx->r15;
    // 0x8005AFE8: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x8005AFEC: sh          $t8, 0x32($a3)
    MEM_H(0X32, ctx->r7) = ctx->r24;
    // 0x8005AFF0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x8005AFF4: sh          $t9, 0x2C($a3)
    MEM_H(0X2C, ctx->r7) = ctx->r25;
    // 0x8005AFF8: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x8005AFFC: lh          $t2, 0x2C($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X2C);
    // 0x8005B000: sh          $t0, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r8;
    // 0x8005B004: lh          $t1, 0x2E($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X2E);
    // 0x8005B008: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B00C: mflo        $t3
    ctx->r11 = lo;
    // 0x8005B010: sh          $t3, 0x34($a3)
    MEM_H(0X34, ctx->r7) = ctx->r11;
    // 0x8005B014: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8005B018: beq         $a0, $zero, L_8005B040
    if (ctx->r4 == 0) {
        // 0x8005B01C: sll         $t4, $a0, 4
        ctx->r12 = S32(ctx->r4 << 4);
            goto L_8005B040;
    }
    // 0x8005B01C: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x8005B020: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x8005B024: beql        $t5, $zero, L_8005B044
    if (ctx->r13 == 0) {
        // 0x8005B028: sw          $a0, 0x40($a3)
        MEM_W(0X40, ctx->r7) = ctx->r4;
            goto L_8005B044;
    }
    goto skip_1;
    // 0x8005B028: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    skip_1:
    // 0x8005B02C: jal         0x80050970
    // 0x8005B030: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80050970(rdram, ctx);
        goto after_1;
    // 0x8005B030: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x8005B034: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8005B038: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8005B03C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8005B040:
    // 0x8005B040: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
L_8005B044:
    // 0x8005B044: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x8005B048: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B04C: sra         $t7, $t6, 14
    ctx->r15 = S32(SIGNED(ctx->r14) >> 14);
    // 0x8005B050: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8005B054: bne         $t8, $at, L_8005B06C
    if (ctx->r24 != ctx->r1) {
        // 0x8005B058: nop
    
            goto L_8005B06C;
    }
    // 0x8005B058: nop

    // 0x8005B05C: jal         0x8005AD30
    // 0x8005B060: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8005AD30(rdram, ctx);
        goto after_2;
    // 0x8005B060: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x8005B064: b           L_8005B078
    // 0x8005B068: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8005B078;
    // 0x8005B068: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8005B06C:
    // 0x8005B06C: jal         0x8005AF18
    // 0x8005B070: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8005AF18(rdram, ctx);
        goto after_3;
    // 0x8005B070: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x8005B074: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8005B078:
    // 0x8005B078: bne         $v0, $zero, L_8005B094
    if (ctx->r2 != 0) {
        // 0x8005B07C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8005B094;
    }
    // 0x8005B07C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005B080: addiu       $a0, $a0, 0xC40
    ctx->r4 = ADD32(ctx->r4, 0XC40);
    // 0x8005B084: jal         0x80071380
    // 0x8005B088: addiu       $a1, $zero, 0x1A0
    ctx->r5 = ADD32(0, 0X1A0);
    Fault_HungUp(rdram, ctx);
        goto after_4;
    // 0x8005B088: addiu       $a1, $zero, 0x1A0
    ctx->r5 = ADD32(0, 0X1A0);
    after_4:
    // 0x8005B08C: b           L_8005B098
    // 0x8005B090: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8005B098;
    // 0x8005B090: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8005B094:
    // 0x8005B094: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8005B098:
    // 0x8005B098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B09C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005B0A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005B0A4: jr          $ra
    // 0x8005B0A8: nop

    return;
    // 0x8005B0A8: nop

;}
RECOMP_FUNC void func_80027C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027C6C: jal         0x80024748
    // 0x80027C70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024748(rdram, ctx);
        goto after_0;
    // 0x80027C70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027C74: beq         $v0, $zero, L_80027C9C
    if (ctx->r2 == 0) {
        // 0x80027C78: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80027C9C;
    }
    // 0x80027C78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80027C7C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80027C80: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80027C84: jal         0x80027B90
    // 0x80027C88: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    func_80027B90(rdram, ctx);
        goto after_1;
    // 0x80027C88: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    after_1:
    // 0x80027C8C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80027C90: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80027C94: addiu       $t8, $t8, 0x7BC4
    ctx->r24 = ADD32(ctx->r24, 0X7BC4);
    // 0x80027C98: sw          $t8, 0x160($t9)
    MEM_W(0X160, ctx->r25) = ctx->r24;
L_80027C9C:
    // 0x80027C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027CA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027CA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80027CA8: jr          $ra
    // 0x80027CAC: nop

    return;
    // 0x80027CAC: nop

;}
RECOMP_FUNC void func_80716D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716D38: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716D3C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716D40: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716D44: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716D48: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716D4C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716D50: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716D54: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716D58: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716D5C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716D60: jr          $ra
    // 0x80716D64: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716D64: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80024CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024CBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024CC4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80024CC8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80024CCC: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x80024CD0: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80024CD4: addiu       $t9, $t9, 0x4A74
    ctx->r25 = ADD32(ctx->r25, 0X4A74);
    // 0x80024CD8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80024CDC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80024CE0: lw          $t8, -0x3BD0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3BD0);
    // 0x80024CE4: sw          $t9, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r25;
    // 0x80024CE8: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
    // 0x80024CEC: lbu         $t0, 0x1F8($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1F8);
    // 0x80024CF0: bnel        $t0, $zero, L_80024D24
    if (ctx->r8 != 0) {
        // 0x80024CF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80024D24;
    }
    goto skip_0;
    // 0x80024CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80024CF8: jal         0x8001D770
    // 0x80024CFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x80024CFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80024D00: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80024D04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024D08: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80024D0C: jal         0x80067BF8
    // 0x80024D10: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x80024D10: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_1:
    // 0x80024D14: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80024D18: jal         0x80067818
    // 0x80024D1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80024D1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80024D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80024D24:
    // 0x80024D24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024D28: jr          $ra
    // 0x80024D2C: nop

    return;
    // 0x80024D2C: nop

;}
RECOMP_FUNC void func_80049D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049D38: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80049D3C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80049D40: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80049D44: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80049D48: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80049D4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80049D50: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80049D54: lbu         $t0, 0x14($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X14);
    // 0x80049D58: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x80049D5C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80049D60: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x80049D64: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80049D68: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80049D6C: jr          $ra
    // 0x80049D70: sb          $t0, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r8;
    return;
    // 0x80049D70: sb          $t0, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void func_8006E548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E548: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8006E54C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006E550: jr          $ra
    // 0x8006E554: addiu       $v0, $v0, -0x1AA8
    ctx->r2 = ADD32(ctx->r2, -0X1AA8);
    return;
    // 0x8006E554: addiu       $v0, $v0, -0x1AA8
    ctx->r2 = ADD32(ctx->r2, -0X1AA8);
;}
RECOMP_FUNC void func_8043BD38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043BD38: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8043BD3C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8043BD40: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8043BD44: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8043BD48: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8043BD4C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8043BD50: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8043BD54: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8043BD58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8043BD5C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8043BD60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043BD64: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8043BD68: lw          $v1, 0x168($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X168);
    // 0x8043BD6C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8043BD70: lw          $t6, 0x318($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X318);
    // 0x8043BD74: lw          $s3, 0x34($v1)
    ctx->r19 = MEM_W(ctx->r3, 0X34);
    // 0x8043BD78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8043BD7C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043BD80: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8043BD84: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8043BD88: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8043BD8C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8043BD90: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8043BD94: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8043BD98: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8043BD9C: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    // 0x8043BDA0: lw          $a3, 0x88($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X88);
    // 0x8043BDA4: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    // 0x8043BDA8: jal         0x8007711C
    // 0x8043BDAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8007711C(rdram, ctx);
        goto after_0;
    // 0x8043BDAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8043BDB0: addiu       $t9, $s3, 0x780
    ctx->r25 = ADD32(ctx->r19, 0X780);
    // 0x8043BDB4: sw          $s0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r16;
    // 0x8043BDB8: lw          $a0, 0xF0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF0);
    // 0x8043BDBC: lui         $s0, 0xBF00
    ctx->r16 = S32(0XBF00 << 16);
    // 0x8043BDC0: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8043BDC4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8043BDC8: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x8043BDCC: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8043BDD0: lui         $fp, 0xF300
    ctx->r30 = S32(0XF300 << 16);
    // 0x8043BDD4: lui         $s7, 0x700
    ctx->r23 = S32(0X700 << 16);
    // 0x8043BDD8: lui         $s6, 0xF550
    ctx->r22 = S32(0XF550 << 16);
    // 0x8043BDDC: lui         $s5, 0xFD50
    ctx->r21 = S32(0XFD50 << 16);
    // 0x8043BDE0: addiu       $s4, $zero, 0x7D0
    ctx->r20 = ADD32(0, 0X7D0);
    // 0x8043BDE4: lui         $ra, 0xF200
    ctx->r31 = S32(0XF200 << 16);
    // 0x8043BDE8: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
L_8043BDEC:
    // 0x8043BDEC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BDF0: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x8043BDF4: ori         $t7, $t7, 0x79DF
    ctx->r15 = ctx->r15 | 0X79DF;
    // 0x8043BDF8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8043BDFC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8043BE00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8043BE04: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8043BE08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8043BE0C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8043BE10: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8043BE14: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8043BE18: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8043BE1C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8043BE20: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_8043BE24:
    // 0x8043BE24: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8043BE28: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_8043BE2C:
    // 0x8043BE2C: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x8043BE30: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x8043BE34: addiu       $t4, $t4, 0x2C
    ctx->r12 = ADD32(ctx->r12, 0X2C);
    // 0x8043BE38: bltzl       $a2, L_8043C04C
    if (SIGNED(ctx->r6) < 0) {
        // 0x8043BE3C: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_8043C04C;
    }
    goto skip_0;
    // 0x8043BE3C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    skip_0:
    // 0x8043BE40: lw          $t6, 0x168($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X168);
    // 0x8043BE44: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BE48: multu       $a2, $s4
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8043BE4C: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x8043BE50: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8043BE54: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8043BE58: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8043BE5C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8043BE60: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BE64: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8043BE68: mflo        $t8
    ctx->r24 = lo;
    // 0x8043BE6C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8043BE70: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x8043BE74: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8043BE78: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8043BE7C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BE80: addu        $t7, $s1, $s2
    ctx->r15 = ADD32(ctx->r17, ctx->r18);
    // 0x8043BE84: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8043BE88: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8043BE8C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043BE90: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x8043BE94: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8043BE98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BE9C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8043BEA0: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8043BEA4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8043BEA8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8043BEAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8043BEB0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8043BEB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BEB8: addu        $t6, $t9, $s3
    ctx->r14 = ADD32(ctx->r25, ctx->r19);
    // 0x8043BEBC: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x8043BEC0: addu        $a3, $t6, $t8
    ctx->r7 = ADD32(ctx->r14, ctx->r24);
    // 0x8043BEC4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8043BEC8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8043BECC: lui         $t6, 0x73E
    ctx->r14 = S32(0X73E << 16);
    // 0x8043BED0: ori         $t6, $t6, 0x719A
    ctx->r14 = ctx->r14 | 0X719A;
    // 0x8043BED4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8043BED8: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x8043BEDC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BEE0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8043BEE4: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x8043BEE8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8043BEEC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043BEF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8043BEF4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8043BEF8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BEFC: ori         $t6, $t6, 0xA00
    ctx->r14 = ctx->r14 | 0XA00;
    // 0x8043BF00: lui         $t7, 0x9
    ctx->r15 = S32(0X9 << 16);
    // 0x8043BF04: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8043BF08: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8043BF0C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8043BF10: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8043BF14: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BF18: ori         $t7, $t7, 0xC0C4
    ctx->r15 = ctx->r15 | 0XC0C4;
    // 0x8043BF1C: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8043BF20: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8043BF24: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043BF28: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8043BF2C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x8043BF30: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BF34: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8043BF38: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8043BF3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8043BF40: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8043BF44: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BF48: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8043BF4C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043BF50: lh          $t7, 0xA($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XA);
    // 0x8043BF54: srl         $t9, $t7, 6
    ctx->r25 = S32(U32(ctx->r15) >> 6);
    // 0x8043BF58: addiu       $t6, $t9, -0x32
    ctx->r14 = ADD32(ctx->r25, -0X32);
    // 0x8043BF5C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8043BF60: lh          $t6, 0x8($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X8);
    // 0x8043BF64: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8043BF68: or          $t9, $t7, $ra
    ctx->r25 = ctx->r15 | ctx->r31;
    // 0x8043BF6C: srl         $t8, $t6, 6
    ctx->r24 = S32(U32(ctx->r14) >> 6);
    // 0x8043BF70: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8043BF74: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8043BF78: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8043BF7C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8043BF80: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8043BF84: lh          $t6, 0xA($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XA);
    // 0x8043BF88: srl         $t9, $t6, 6
    ctx->r25 = S32(U32(ctx->r14) >> 6);
    // 0x8043BF8C: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x8043BF90: lh          $t9, 0x8($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X8);
    // 0x8043BF94: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8043BF98: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8043BF9C: srl         $t8, $t9, 6
    ctx->r24 = S32(U32(ctx->r25) >> 6);
    // 0x8043BFA0: addiu       $t7, $t8, 0x27
    ctx->r15 = ADD32(ctx->r24, 0X27);
    // 0x8043BFA4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8043BFA8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8043BFAC: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8043BFB0: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8043BFB4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8043BFB8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043BFBC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8043BFC0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043BFC4: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8043BFC8: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x8043BFCC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8043BFD0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8043BFD4: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8043BFD8: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x8043BFDC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8043BFE0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8043BFE4: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8043BFE8: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8043BFEC: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8043BFF0: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x8043BFF4: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x8043BFF8: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8043BFFC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8043C000: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C004: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8043C008: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043C00C: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8043C010: lw          $t6, 0x14($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X14);
    // 0x8043C014: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
    // 0x8043C018: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8043C01C: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8043C020: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x8043C024: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8043C028: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8043C02C: lw          $t7, 0x10($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X10);
    // 0x8043C030: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8043C034: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8043C038: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x8043C03C: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x8043C040: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8043C044: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8043C048: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
L_8043C04C:
    // 0x8043C04C: slti        $at, $t3, 0x9
    ctx->r1 = SIGNED(ctx->r11) < 0X9 ? 1 : 0;
    // 0x8043C050: bne         $at, $zero, L_8043BE2C
    if (ctx->r1 != 0) {
        // 0x8043C054: addiu       $t0, $t0, 0x18
        ctx->r8 = ADD32(ctx->r8, 0X18);
            goto L_8043BE2C;
    }
    // 0x8043C054: addiu       $t0, $t0, 0x18
    ctx->r8 = ADD32(ctx->r8, 0X18);
    // 0x8043C058: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8043C05C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8043C060: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x8043C064: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x8043C068: bne         $at, $zero, L_8043BE24
    if (ctx->r1 != 0) {
        // 0x8043C06C: sw          $t6, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r14;
            goto L_8043BE24;
    }
    // 0x8043C06C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x8043C070: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8043C074: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8043C078: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8043C07C: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x8043C080: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8043C084: addiu       $t6, $t8, 0x140
    ctx->r14 = ADD32(ctx->r24, 0X140);
    // 0x8043C088: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8043C08C: bne         $at, $zero, L_8043BDEC
    if (ctx->r1 != 0) {
        // 0x8043C090: sw          $t9, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r25;
            goto L_8043BDEC;
    }
    // 0x8043C090: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x8043C094: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C098: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8043C09C: ori         $t9, $t9, 0x513F
    ctx->r25 = ctx->r25 | 0X513F;
    // 0x8043C0A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8043C0A4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8043C0A8: addiu       $t8, $s3, 0x640
    ctx->r24 = ADD32(ctx->r19, 0X640);
    // 0x8043C0AC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8043C0B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8043C0B4: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x8043C0B8: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8043C0BC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8043C0C0: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
    // 0x8043C0C4: addiu       $t4, $t4, 0x28
    ctx->r12 = ADD32(ctx->r12, 0X28);
L_8043C0C8:
    // 0x8043C0C8: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x8043C0CC: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
    // 0x8043C0D0: addiu       $t4, $t4, 0x2C
    ctx->r12 = ADD32(ctx->r12, 0X2C);
    // 0x8043C0D4: bltzl       $a2, L_8043C2D8
    if (SIGNED(ctx->r6) < 0) {
        // 0x8043C0D8: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_8043C2D8;
    }
    goto skip_1;
    // 0x8043C0D8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    skip_1:
    // 0x8043C0DC: lw          $t9, 0x168($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X168);
    // 0x8043C0E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C0E4: multu       $a2, $s4
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8043C0E8: lw          $t8, 0x80($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X80);
    // 0x8043C0EC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8043C0F0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8043C0F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8043C0F8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8043C0FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C100: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8043C104: mflo        $t6
    ctx->r14 = lo;
    // 0x8043C108: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8043C10C: addu        $t2, $t6, $t8
    ctx->r10 = ADD32(ctx->r14, ctx->r24);
    // 0x8043C110: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8043C114: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8043C118: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C11C: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x8043C120: addu        $a3, $s3, $t8
    ctx->r7 = ADD32(ctx->r19, ctx->r24);
    // 0x8043C124: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8043C128: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8043C12C: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x8043C130: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8043C134: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C138: lui         $t6, 0x73E
    ctx->r14 = S32(0X73E << 16);
    // 0x8043C13C: ori         $t6, $t6, 0x719A
    ctx->r14 = ctx->r14 | 0X719A;
    // 0x8043C140: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8043C144: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8043C148: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8043C14C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8043C150: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C154: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8043C158: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    // 0x8043C15C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8043C160: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8043C164: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8043C168: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x8043C16C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C170: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x8043C174: ori         $t6, $t6, 0xA00
    ctx->r14 = ctx->r14 | 0XA00;
    // 0x8043C178: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8043C17C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043C180: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8043C184: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8043C188: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C18C: lui         $t7, 0x9
    ctx->r15 = S32(0X9 << 16);
    // 0x8043C190: ori         $t7, $t7, 0xC0C4
    ctx->r15 = ctx->r15 | 0XC0C4;
    // 0x8043C194: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8043C198: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8043C19C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8043C1A0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8043C1A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C1A8: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8043C1AC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8043C1B0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043C1B4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8043C1B8: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x8043C1BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C1C0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8043C1C4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8043C1C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8043C1CC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8043C1D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C1D4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8043C1D8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043C1DC: lh          $t7, 0xA($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XA);
    // 0x8043C1E0: srl         $t9, $t7, 6
    ctx->r25 = S32(U32(ctx->r15) >> 6);
    // 0x8043C1E4: addiu       $t6, $t9, -0x32
    ctx->r14 = ADD32(ctx->r25, -0X32);
    // 0x8043C1E8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8043C1EC: lh          $t6, 0x8($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X8);
    // 0x8043C1F0: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8043C1F4: or          $t9, $t7, $ra
    ctx->r25 = ctx->r15 | ctx->r31;
    // 0x8043C1F8: srl         $t8, $t6, 6
    ctx->r24 = S32(U32(ctx->r14) >> 6);
    // 0x8043C1FC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8043C200: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8043C204: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8043C208: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8043C20C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8043C210: lh          $t6, 0xA($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XA);
    // 0x8043C214: srl         $t9, $t6, 6
    ctx->r25 = S32(U32(ctx->r14) >> 6);
    // 0x8043C218: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x8043C21C: lh          $t9, 0x8($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X8);
    // 0x8043C220: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8043C224: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8043C228: srl         $t8, $t9, 6
    ctx->r24 = S32(U32(ctx->r25) >> 6);
    // 0x8043C22C: addiu       $t7, $t8, 0x27
    ctx->r15 = ADD32(ctx->r24, 0X27);
    // 0x8043C230: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8043C234: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8043C238: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8043C23C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8043C240: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8043C244: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C248: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8043C24C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043C250: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8043C254: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x8043C258: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8043C25C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8043C260: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8043C264: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x8043C268: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8043C26C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8043C270: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8043C274: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8043C278: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8043C27C: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x8043C280: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x8043C284: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8043C288: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8043C28C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8043C290: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8043C294: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043C298: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8043C29C: lw          $t6, 0x14($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X14);
    // 0x8043C2A0: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
    // 0x8043C2A4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8043C2A8: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8043C2AC: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x8043C2B0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8043C2B4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8043C2B8: lw          $t7, 0x10($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X10);
    // 0x8043C2BC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8043C2C0: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8043C2C4: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x8043C2C8: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x8043C2CC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8043C2D0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8043C2D4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
L_8043C2D8:
    // 0x8043C2D8: bne         $t3, $s1, L_8043C0C8
    if (ctx->r11 != ctx->r17) {
        // 0x8043C2DC: addiu       $t0, $t0, 0x18
        ctx->r8 = ADD32(ctx->r8, 0X18);
            goto L_8043C0C8;
    }
    // 0x8043C2DC: addiu       $t0, $t0, 0x18
    ctx->r8 = ADD32(ctx->r8, 0X18);
    // 0x8043C2E0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8043C2E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043C2E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8043C2EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8043C2F0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8043C2F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8043C2F8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8043C2FC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8043C300: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8043C304: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8043C308: jr          $ra
    // 0x8043C30C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x8043C30C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_8053167C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053167C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80531680: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80531684: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80531688: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8053168C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80531690: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80531694: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80531698: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8053169C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x805316A0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x805316A4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x805316A8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x805316AC: mtc1        $a1, $f24
    ctx->f24.u32l = ctx->r5;
    // 0x805316B0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x805316B4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x805316B8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x805316BC: lwc1        $f22, 0x3C($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805316C0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x805316C4: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_805316C8:
    // 0x805316C8: lwc1        $f20, 0x40($s3)
    ctx->f20.u32l = MEM_W(ctx->r19, 0X40);
    // 0x805316CC: blez        $s1, L_80531704
    if (SIGNED(ctx->r17) <= 0) {
        // 0x805316D0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80531704;
    }
    // 0x805316D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_805316D4:
    // 0x805316D4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x805316D8: jal         0x80053924
    // 0x805316DC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_80053924(rdram, ctx);
        goto after_0;
    // 0x805316DC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_0:
    // 0x805316E0: andi        $a2, $v0, 0xF800
    ctx->r6 = ctx->r2 & 0XF800;
    // 0x805316E4: ori         $a2, $a2, 0x701
    ctx->r6 = ctx->r6 | 0X701;
    // 0x805316E8: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x805316EC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x805316F0: jal         0x800538BC
    // 0x805316F4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800538BC(rdram, ctx);
        goto after_1;
    // 0x805316F4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x805316F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x805316FC: bne         $s0, $s1, L_805316D4
    if (ctx->r16 != ctx->r17) {
        // 0x80531700: add.s       $f20, $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
            goto L_805316D4;
    }
    // 0x80531700: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
L_80531704:
    // 0x80531704: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80531708: bne         $s2, $s4, L_805316C8
    if (ctx->r18 != ctx->r20) {
        // 0x8053170C: add.s       $f22, $f22, $f26
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
            goto L_805316C8;
    }
    // 0x8053170C: add.s       $f22, $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
    // 0x80531710: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80531714: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80531718: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8053171C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80531720: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80531724: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80531728: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8053172C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80531730: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80531734: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80531738: jr          $ra
    // 0x8053173C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8053173C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8073EF60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EF60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073EF64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EF68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8073EF6C: jal         0x80047090
    // 0x8073EF70: addiu       $a0, $zero, 0x4643
    ctx->r4 = ADD32(0, 0X4643);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8073EF70: addiu       $a0, $zero, 0x4643
    ctx->r4 = ADD32(0, 0X4643);
    after_0:
    // 0x8073EF74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073EF78: lui         $at, 0x4643
    ctx->r1 = S32(0X4643 << 16);
    // 0x8073EF7C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8073EF80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8073EF84: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8073EF88: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8073EF8C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x8073EF90: jal         0x8004613C
    // 0x8073EF94: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8073EF94: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x8073EF98: bne         $v0, $zero, L_8073EFA8
    if (ctx->r2 != 0) {
        // 0x8073EF9C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8073EFA8;
    }
    // 0x8073EF9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8073EFA0: b           L_8073EFD8
    // 0x8073EFA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8073EFD8;
    // 0x8073EFA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073EFA8:
    // 0x8073EFA8: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x8073EFAC: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x8073EFB0: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8073EFB4: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x8073EFB8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8073EFBC: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x8073EFC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8073EFC4: jal         0x80047F9C
    // 0x8073EFC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8073EFC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8073EFCC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8073EFD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8073EFD4: sb          $t2, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r10;
L_8073EFD8:
    // 0x8073EFD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073EFDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073EFE0: jr          $ra
    // 0x8073EFE4: nop

    return;
    // 0x8073EFE4: nop

;}
RECOMP_FUNC void func_806EAE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EAE4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EAE50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EAE54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EAE58: jal         0x806EA9C0
    // 0x806EAE5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EA9C0(rdram, ctx);
        goto after_0;
    // 0x806EAE5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EAE60: jal         0x806EA92C
    // 0x806EAE64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EA92C(rdram, ctx);
        goto after_1;
    // 0x806EAE64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EAE68: beq         $v0, $zero, L_806EAEB0
    if (ctx->r2 == 0) {
        // 0x806EAE6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EAEB0;
    }
    // 0x806EAE6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EAE70: jal         0x806EA988
    // 0x806EAE74: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    func_806EA988(rdram, ctx);
        goto after_2;
    // 0x806EAE74: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    after_2:
    // 0x806EAE78: lw          $t6, 0x12C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X12C);
    // 0x806EAE7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EAE80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EAE84: bne         $t6, $zero, L_806EAEA8
    if (ctx->r14 != 0) {
        // 0x806EAE88: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_806EAEA8;
    }
    // 0x806EAE88: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806EAE8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EAE90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EAE94: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806EAE98: jal         0x806EB43C
    // 0x806EAE9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806EB43C(rdram, ctx);
        goto after_3;
    // 0x806EAE9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x806EAEA0: b           L_806EAEB4
    // 0x806EAEA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EAEB4;
    // 0x806EAEA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EAEA8:
    // 0x806EAEA8: jal         0x806EB43C
    // 0x806EAEAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806EB43C(rdram, ctx);
        goto after_4;
    // 0x806EAEAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_806EAEB0:
    // 0x806EAEB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EAEB4:
    // 0x806EAEB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EAEB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EAEBC: jr          $ra
    // 0x806EAEC0: nop

    return;
    // 0x806EAEC0: nop

;}
RECOMP_FUNC void func_806EA9C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EA9C0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EA9C4: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806EA9C8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x806EA9CC: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806EA9D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EA9D4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(670, 0XF60) << 16);
    // 0x806EA9D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806EA9DC: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x806EA9E0: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806EA9E4: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x806EA9E8: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806EA9EC: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x806EA9F0: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x806EA9F4: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x806EA9F8: lwc1        $f6, -0x48D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(670, 0XF60));
    // 0x806EA9FC: sub.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x806EAA00: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806EAA04: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x806EAA08: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806EAA0C: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x806EAA10: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x806EAA14: lwc1        $f2, 0x88($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806EAA18: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x806EAA1C: nop

    // 0x806EAA20: bc1fl       L_806EAA44
    if (!c1cs) {
        // 0x806EAA24: add.s       $f8, $f12, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f14.fl;
            goto L_806EAA44;
    }
    goto skip_0;
    // 0x806EAA24: add.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f14.fl;
    skip_0:
    // 0x806EAA28: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806EAA2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806EAA30: lwc1        $f2, 0x88($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806EAA34: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x806EAA38: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x806EAA3C: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806EAA40: add.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f14.fl;
L_806EAA44:
    // 0x806EAA44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806EAA48: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x806EAA4C: nop

    // 0x806EAA50: bc1f        L_806EAA6C
    if (!c1cs) {
        // 0x806EAA54: nop
    
            goto L_806EAA6C;
    }
    // 0x806EAA54: nop

    // 0x806EAA58: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806EAA5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806EAA60: nop

    // 0x806EAA64: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806EAA68: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
L_806EAA6C:
    // 0x806EAA6C: jr          $ra
    // 0x806EAA70: nop

    return;
    // 0x806EAA70: nop

;}
RECOMP_FUNC void func_8001DC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DC38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001DC3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DC40: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8001DC44: jal         0x8001D908
    // 0x8001DC48: addiu       $a1, $a1, -0x6768
    ctx->r5 = ADD32(ctx->r5, -0X6768);
    func_8001D908(rdram, ctx);
        goto after_0;
    // 0x8001DC48: addiu       $a1, $a1, -0x6768
    ctx->r5 = ADD32(ctx->r5, -0X6768);
    after_0:
    // 0x8001DC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DC50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001DC54: jr          $ra
    // 0x8001DC58: nop

    return;
    // 0x8001DC58: nop

;}
RECOMP_FUNC void func_80674F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80674F98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80674F9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80674FA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80674FA4: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80674FA8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80674FAC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80674FB0: beq         $v0, $at, L_80675084
    if (ctx->r2 == ctx->r1) {
        // 0x80674FB4: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80675084;
    }
    // 0x80674FB4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80674FB8: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80674FBC: bnel        $v0, $at, L_80675088
    if (ctx->r2 != ctx->r1) {
        // 0x80674FC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80675088;
    }
    goto skip_0;
    // 0x80674FC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80674FC4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80674FC8: bnel        $t6, $zero, L_80675088
    if (ctx->r14 != 0) {
        // 0x80674FCC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80675088;
    }
    goto skip_1;
    // 0x80674FCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80674FD0: lbu         $v0, 0x18($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X18);
    // 0x80674FD4: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80674FD8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80674FDC: beq         $v0, $at, L_80674FF0
    if (ctx->r2 == ctx->r1) {
        // 0x80674FE0: lui         $t7, 0x8067
        ctx->r15 = S32(RELOC_HI16(532, 0X338) << 16);
            goto L_80674FF0;
    }
    // 0x80674FE0: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(532, 0X338) << 16);
    // 0x80674FE4: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80674FE8: bnel        $v0, $at, L_80675088
    if (ctx->r2 != ctx->r1) {
        // 0x80674FEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80675088;
    }
    goto skip_2;
    // 0x80674FEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_80674FF0:
    // 0x80674FF0: lw          $a0, 0x180($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X180);
    // 0x80674FF4: addiu       $t7, $t7, 0x5288
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(532, 0X338));
    // 0x80674FF8: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(532, 0X228) << 16);
    // 0x80674FFC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80675000: sb          $v1, 0x30($a2)
    MEM_B(0X30, ctx->r6) = ctx->r3;
    // 0x80675004: sw          $t7, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r15;
    // 0x80675008: addiu       $t8, $t8, 0x5178
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(532, 0X228));
    // 0x8067500C: sb          $v1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r3;
    // 0x80675010: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80675014: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80675018: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8067501C: bgez        $t0, L_80675030
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80675020: andi        $t1, $t0, 0x3
        ctx->r9 = ctx->r8 & 0X3;
            goto L_80675030;
    }
    // 0x80675020: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80675024: beq         $t1, $zero, L_80675030
    if (ctx->r9 == 0) {
        // 0x80675028: nop
    
            goto L_80675030;
    }
    // 0x80675028: nop

    // 0x8067502C: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
L_80675030:
    // 0x80675030: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80675034: jal         0x80675098
    // 0x80675038: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80675098(rdram, ctx);
        goto after_0;
    // 0x80675038: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8067503C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80675040: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x80675044: jal         0x80067BBC
    // 0x80675048: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x80675048: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_1:
    // 0x8067504C: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    // 0x80675050: jal         0x80067818
    // 0x80675054: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80675054: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80675058: lhu         $t2, 0xC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XC);
    // 0x8067505C: addiu       $at, $zero, 0x4018
    ctx->r1 = ADD32(0, 0X4018);
    // 0x80675060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80675064: beql        $t2, $at, L_80675088
    if (ctx->r10 == ctx->r1) {
        // 0x80675068: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80675088;
    }
    goto skip_3;
    // 0x80675068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8067506C: jal         0x8003E478
    // 0x80675070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003E478(rdram, ctx);
        goto after_3;
    // 0x80675070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80675074: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80675078: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067507C: nop

    // 0x80675080: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
L_80675084:
    // 0x80675084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80675088:
    // 0x80675088: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067508C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80675090: jr          $ra
    // 0x80675094: nop

    return;
    // 0x80675094: nop

;}
RECOMP_FUNC void func_80465708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465708: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8046570C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80465710: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80465714: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80465718: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8046571C: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80465720: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80465724: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80465728: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8046572C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80465730: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80465734: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80465738: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8046573C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80465740: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x80465744: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80465748: lw          $v0, 0x1750($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X1750);
    // 0x8046574C: addiu       $s1, $s5, 0x1754
    ctx->r17 = ADD32(ctx->r21, 0X1754);
    // 0x80465750: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80465754: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80465758: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8046575C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80465760: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80465764: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80465768: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8046576C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80465770: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80465774: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80465778: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8046577C: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x80465780: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x80465784: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80465788: sll         $t8, $v0, 11
    ctx->r24 = S32(ctx->r2 << 11);
    // 0x8046578C: lwc1        $f14, 0xC4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80465790: addu        $s0, $s5, $t8
    ctx->r16 = ADD32(ctx->r21, ctx->r24);
    // 0x80465794: addiu       $s0, $s0, 0x1858
    ctx->r16 = ADD32(ctx->r16, 0X1858);
    // 0x80465798: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x8046579C: jal         0x80067114
    // 0x804657A0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x804657A0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x804657A4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x804657A8: jal         0x80066DE4
    // 0x804657AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x804657AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x804657B0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x804657B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804657B8: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x804657BC: mul.s       $f30, $f0, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f30.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804657C0: jal         0x80066E88
    // 0x804657C4: nop

    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x804657C4: nop

    after_2:
    // 0x804657C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804657CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804657D0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x804657D4: mul.s       $f26, $f0, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x804657D8: jal         0x80066E88
    // 0x804657DC: nop

    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x804657DC: nop

    after_3:
    // 0x804657E0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x804657E4: jal         0x80066DE4
    // 0x804657E8: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x804657E8: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_4:
    // 0x804657EC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(125, 0X1E18) << 16);
    // 0x804657F0: lwc1        $f8, 0x63E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(125, 0X1E18));
    // 0x804657F4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804657F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804657FC: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80465800: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80465804: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80465808: jal         0x80066DE4
    // 0x8046580C: sub.s       $f28, $f10, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f10.fl - ctx->f18.fl;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x8046580C: sub.s       $f28, $f10, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f10.fl - ctx->f18.fl;
    after_5:
    // 0x80465810: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80465814: jal         0x80066E88
    // 0x80465818: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x80465818: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_6:
    // 0x8046581C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80465820: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80465824: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(125, 0X1E1C) << 16);
    // 0x80465828: lwc1        $f8, 0x63EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(125, 0X1E1C));
    // 0x8046582C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80465830: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80465834: mul.s       $f16, $f8, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80465838: jal         0x80066E88
    // 0x8046583C: add.s       $f20, $f6, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f16.fl;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x8046583C: add.s       $f20, $f6, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f16.fl;
    after_7:
    // 0x80465840: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(125, 0X1E20) << 16);
    // 0x80465844: lwc1        $f10, 0x63F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(125, 0X1E20));
    // 0x80465848: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x8046584C: mul.s       $f22, $f0, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80465850: jal         0x80066DE4
    // 0x80465854: nop

    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x80465854: nop

    after_8:
    // 0x80465858: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(125, 0X1E24) << 16);
    // 0x8046585C: lwc1        $f18, 0x63F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(125, 0X1E24));
    // 0x80465860: lw          $s2, 0x2858($s5)
    ctx->r18 = MEM_W(ctx->r21, 0X2858);
    // 0x80465864: addiu       $s4, $sp, 0xA0
    ctx->r20 = ADD32(ctx->r29, 0XA0);
    // 0x80465868: mul.s       $f24, $f0, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8046586C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80465870: bltz        $s2, L_8046592C
    if (SIGNED(ctx->r18) < 0) {
        // 0x80465874: nop
    
            goto L_8046592C;
    }
    // 0x80465874: nop

    // 0x80465878: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
L_8046587C:
    // 0x8046587C: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80465880: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80465884: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80465888: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x8046588C: slti        $at, $s3, 0x20
    ctx->r1 = SIGNED(ctx->r19) < 0X20 ? 1 : 0;
    // 0x80465890: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80465894: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80465898: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8046589C: add.s       $f6, $f0, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f30.fl;
    // 0x804658A0: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x804658A4: sh          $t0, -0x40($s0)
    MEM_H(-0X40, ctx->r16) = ctx->r8;
    // 0x804658A8: add.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f28.fl;
    // 0x804658AC: sh          $t2, -0x3E($s0)
    MEM_H(-0X3E, ctx->r16) = ctx->r10;
    // 0x804658B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804658B4: add.s       $f10, $f2, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f26.fl;
    // 0x804658B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x804658BC: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804658C0: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804658C4: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x804658C8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804658CC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x804658D0: sh          $t4, -0x30($s0)
    MEM_H(-0X30, ctx->r16) = ctx->r12;
    // 0x804658D4: add.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x804658D8: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x804658DC: sh          $t6, -0x2E($s0)
    MEM_H(-0X2E, ctx->r16) = ctx->r14;
    // 0x804658E0: add.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x804658E4: sh          $t8, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r24;
    // 0x804658E8: add.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x804658EC: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804658F0: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804658F4: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x804658F8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804658FC: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80465900: sh          $t0, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r8;
    // 0x80465904: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80465908: sh          $t2, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r10;
    // 0x8046590C: bne         $at, $zero, L_80465920
    if (ctx->r1 != 0) {
        // 0x80465910: sh          $t4, -0xE($s0)
        MEM_H(-0XE, ctx->r16) = ctx->r12;
            goto L_80465920;
    }
    // 0x80465910: sh          $t4, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r12;
    // 0x80465914: jal         0x8046562C
    // 0x80465918: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8046562C(rdram, ctx);
        goto after_9;
    // 0x80465918: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_9:
    // 0x8046591C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80465920:
    // 0x80465920: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80465924: bgezl       $s2, L_8046587C
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80465928: lwc1        $f0, 0x0($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
            goto L_8046587C;
    }
    goto skip_0;
    // 0x80465928: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    skip_0:
L_8046592C:
    // 0x8046592C: blez        $s3, L_80465944
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80465930: addiu       $s4, $sp, 0xA0
        ctx->r20 = ADD32(ctx->r29, 0XA0);
            goto L_80465944;
    }
    // 0x80465930: addiu       $s4, $sp, 0xA0
    ctx->r20 = ADD32(ctx->r29, 0XA0);
    // 0x80465934: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80465938: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8046593C: jal         0x8046562C
    // 0x80465940: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8046562C(rdram, ctx);
        goto after_10;
    // 0x80465940: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_10:
L_80465944:
    // 0x80465944: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x80465948: lui         $t7, 0xB800
    ctx->r15 = S32(0XB800 << 16);
    // 0x8046594C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80465950: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x80465954: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80465958: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8046595C: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80465960: sw          $t8, 0x1750($s5)
    MEM_W(0X1750, ctx->r21) = ctx->r24;
    // 0x80465964: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80465968: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8046596C: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80465970: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80465974: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80465978: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8046597C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80465980: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80465984: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80465988: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8046598C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80465990: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80465994: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80465998: jr          $ra
    // 0x8046599C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8046599C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80426600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80426600: lui         $v0, 0x8042
    ctx->r2 = S32(RELOC_HI16(38, 0X10) << 16);
    // 0x80426604: addiu       $v0, $v0, 0x6610
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(38, 0X10));
    // 0x80426608: jr          $ra
    // 0x8042660C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8042660C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800574D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800574D0: lw          $v0, 0x1B4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1B4);
    // 0x800574D4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800574D8: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800574DC: sw          $t6, 0x1B4($a0)
    MEM_W(0X1B4, ctx->r4) = ctx->r14;
    // 0x800574E0: bne         $at, $zero, L_800574EC
    if (ctx->r1 != 0) {
        // 0x800574E4: sw          $v0, 0x1B0($a0)
        MEM_W(0X1B0, ctx->r4) = ctx->r2;
            goto L_800574EC;
    }
    // 0x800574E4: sw          $v0, 0x1B0($a0)
    MEM_W(0X1B0, ctx->r4) = ctx->r2;
    // 0x800574E8: sw          $zero, 0x1B4($a0)
    MEM_W(0X1B4, ctx->r4) = 0;
L_800574EC:
    // 0x800574EC: jr          $ra
    // 0x800574F0: nop

    return;
    // 0x800574F0: nop

;}
RECOMP_FUNC void func_80531D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531D68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80531D6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80531D70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80531D74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80531D78: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x80531D7C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80531D80: addiu       $a1, $zero, 0x338
    ctx->r5 = ADD32(0, 0X338);
    // 0x80531D84: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x80531D88: jal         0x80045A34
    // 0x80531D8C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80531D8C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x80531D90: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x80531D94: bne         $v0, $zero, L_80531DAC
    if (ctx->r2 != 0) {
        // 0x80531D98: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80531DAC;
    }
    // 0x80531D98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80531D9C: jal         0x800445A4
    // 0x80531DA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80531DA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80531DA4: b           L_80531E0C
    // 0x80531DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80531E0C;
    // 0x80531DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80531DAC:
    // 0x80531DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80531DB0: addiu       $a1, $zero, 0x338
    ctx->r5 = ADD32(0, 0X338);
    // 0x80531DB4: jal         0x80065728
    // 0x80531DB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x80531DB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80531DBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80531DC0: jal         0x8005D730
    // 0x80531DC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005D730(rdram, ctx);
        goto after_3;
    // 0x80531DC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80531DC8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80531DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80531DD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80531DD4: sw          $t8, 0x260($s0)
    MEM_W(0X260, ctx->r16) = ctx->r24;
    // 0x80531DD8: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80531DDC: andi        $t0, $t9, 0x3FF
    ctx->r8 = ctx->r25 & 0X3FF;
    // 0x80531DE0: jal         0x805312B0
    // 0x80531DE4: sh          $t0, 0x25C($s0)
    MEM_H(0X25C, ctx->r16) = ctx->r8;
    func_805312B0(rdram, ctx);
        goto after_4;
    // 0x80531DE4: sh          $t0, 0x25C($s0)
    MEM_H(0X25C, ctx->r16) = ctx->r8;
    after_4:
    // 0x80531DE8: lw          $t1, 0x134($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X134);
    // 0x80531DEC: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X19AC) << 16);
    // 0x80531DF0: lwc1        $f4, 0x88($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X88);
    // 0x80531DF4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80531DF8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80531DFC: lwc1        $f6, 0x279C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X19AC));
    // 0x80531E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80531E04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80531E08: swc1        $f8, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->f8.u32l;
L_80531E0C:
    // 0x80531E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80531E10: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80531E14: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80531E18: jr          $ra
    // 0x80531E1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80531E1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000606C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000606C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80006070: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80006074: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80006078: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000607C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80006080: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80006084: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80006088: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8000608C: bne         $a2, $zero, L_800060B0
    if (ctx->r6 != 0) {
        // 0x80006090: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_800060B0;
    }
    // 0x80006090: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80006094: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x80006098: addiu       $t1, $t1, 0x4D10
    ctx->r9 = ADD32(ctx->r9, 0X4D10);
    // 0x8000609C: lw          $a2, 0x1B58($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X1B58);
    // 0x800060A0: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x800060A4: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800060A8: bnel        $at, $zero, L_80006208
    if (ctx->r1 != 0) {
        // 0x800060AC: lw          $a1, 0x1B50($t1)
        ctx->r5 = MEM_W(ctx->r9, 0X1B50);
            goto L_80006208;
    }
    goto skip_0;
    // 0x800060AC: lw          $a1, 0x1B50($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X1B50);
    skip_0:
L_800060B0:
    // 0x800060B0: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800060B4: addiu       $t1, $t1, 0x4D10
    ctx->r9 = ADD32(ctx->r9, 0X4D10);
    // 0x800060B8: lw          $a2, 0x1B58($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X1B58);
    // 0x800060BC: lw          $a1, 0x1B54($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X1B54);
    // 0x800060C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800060C4: sltu        $at, $a2, $a1
    ctx->r1 = ctx->r6 < ctx->r5 ? 1 : 0;
    // 0x800060C8: beql        $at, $zero, L_800061A4
    if (ctx->r1 == 0) {
        // 0x800060CC: lw          $t9, 0x58($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X58);
            goto L_800061A4;
    }
    goto skip_1;
    // 0x800060CC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    skip_1:
    // 0x800060D0: lw          $t9, 0x1B50($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X1B50);
    // 0x800060D4: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800060D8: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
L_800060DC:
    // 0x800060DC: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x800060E0: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x800060E4: subu        $v0, $s1, $t4
    ctx->r2 = SUB32(ctx->r17, ctx->r12);
    // 0x800060E8: bltzl       $v0, L_80006190
    if (SIGNED(ctx->r2) < 0) {
        // 0x800060EC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80006190;
    }
    goto skip_2;
    // 0x800060EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_2:
    // 0x800060F0: lhu         $t5, 0xA($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0XA);
    // 0x800060F4: subu        $t6, $t5, $s0
    ctx->r14 = SUB32(ctx->r13, ctx->r16);
    // 0x800060F8: sltu        $at, $t6, $v0
    ctx->r1 = ctx->r14 < ctx->r2 ? 1 : 0;
    // 0x800060FC: bnel        $at, $zero, L_80006190
    if (ctx->r1 != 0) {
        // 0x80006100: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80006190;
    }
    goto skip_3;
    // 0x80006100: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_3:
    // 0x80006104: lbu         $t7, 0xE($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0XE);
    // 0x80006108: bnel        $t7, $zero, L_8000616C
    if (ctx->r15 != 0) {
        // 0x8000610C: addiu       $t4, $zero, 0x20
        ctx->r12 = ADD32(0, 0X20);
            goto L_8000616C;
    }
    goto skip_4;
    // 0x8000610C: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    skip_4:
    // 0x80006110: lbu         $v0, 0x1D61($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1D61);
    // 0x80006114: lbu         $t8, 0x1D63($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1D63);
    // 0x80006118: beql        $t8, $v0, L_8000616C
    if (ctx->r24 == ctx->r2) {
        // 0x8000611C: addiu       $t4, $zero, 0x20
        ctx->r12 = ADD32(0, 0X20);
            goto L_8000616C;
    }
    goto skip_5;
    // 0x8000611C: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    skip_5:
    // 0x80006120: lbu         $v1, 0xD($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XD);
    // 0x80006124: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x80006128: beql        $v0, $v1, L_80006164
    if (ctx->r2 == ctx->r3) {
        // 0x8000612C: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_80006164;
    }
    goto skip_6;
    // 0x8000612C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    skip_6:
    // 0x80006130: lbu         $t4, 0x1C60($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X1C60);
    // 0x80006134: addu        $t5, $t1, $v1
    ctx->r13 = ADD32(ctx->r9, ctx->r3);
    // 0x80006138: sb          $t4, 0x1C60($t5)
    MEM_B(0X1C60, ctx->r13) = ctx->r12;
    // 0x8000613C: lbu         $t8, 0x1D61($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1D61);
    // 0x80006140: lw          $t7, 0x1B50($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X1B50);
    // 0x80006144: lbu         $t6, 0xD($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XD);
    // 0x80006148: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x8000614C: lbu         $t4, 0x1C60($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X1C60);
    // 0x80006150: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80006154: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x80006158: sb          $t6, 0xD($t8)
    MEM_B(0XD, ctx->r24) = ctx->r14;
    // 0x8000615C: lbu         $v0, 0x1D61($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1D61);
    // 0x80006160: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
L_80006164:
    // 0x80006164: sb          $t9, 0x1D61($t1)
    MEM_B(0X1D61, ctx->r9) = ctx->r25;
    // 0x80006168: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
L_8000616C:
    // 0x8000616C: sb          $t4, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r12;
    // 0x80006170: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80006174: sb          $a0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r4;
    // 0x80006178: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8000617C: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x80006180: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80006184: b           L_80006394
    // 0x80006188: subu        $v0, $t6, $t8
    ctx->r2 = SUB32(ctx->r14, ctx->r24);
        goto L_80006394;
    // 0x80006188: subu        $v0, $t6, $t8
    ctx->r2 = SUB32(ctx->r14, ctx->r24);
    // 0x8000618C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80006190:
    // 0x80006190: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80006194: bne         $at, $zero, L_800060DC
    if (ctx->r1 != 0) {
        // 0x80006198: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800060DC;
    }
    // 0x80006198: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8000619C: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x800061A0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_800061A4:
    // 0x800061A4: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800061A8: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800061AC: bnel        $t9, $zero, L_800061C4
    if (ctx->r25 != 0) {
        // 0x800061B0: lbu         $v0, 0x1D61($t1)
        ctx->r2 = MEM_BU(ctx->r9, 0X1D61);
            goto L_800061C4;
    }
    goto skip_7;
    // 0x800061B0: lbu         $v0, 0x1D61($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1D61);
    skip_7:
    // 0x800061B4: lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X0);
    // 0x800061B8: b           L_80006208
    // 0x800061BC: lw          $a1, 0x1B50($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X1B50);
        goto L_80006208;
    // 0x800061BC: lw          $a1, 0x1B50($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X1B50);
    // 0x800061C0: lbu         $v0, 0x1D61($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1D61);
L_800061C4:
    // 0x800061C4: lbu         $t7, 0x1D63($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X1D63);
    // 0x800061C8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800061CC: beq         $t7, $v0, L_800061FC
    if (ctx->r15 == ctx->r2) {
        // 0x800061D0: nop
    
            goto L_800061FC;
    }
    // 0x800061D0: nop

    // 0x800061D4: beq         $t5, $zero, L_800061FC
    if (ctx->r13 == 0) {
        // 0x800061D8: addu        $t6, $t1, $v0
        ctx->r14 = ADD32(ctx->r9, ctx->r2);
            goto L_800061FC;
    }
    // 0x800061D8: addu        $t6, $t1, $v0
    ctx->r14 = ADD32(ctx->r9, ctx->r2);
    // 0x800061DC: lbu         $t2, 0x1C60($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X1C60);
    // 0x800061E0: lw          $t4, 0x1B50($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X1B50);
    // 0x800061E4: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x800061E8: sll         $t9, $t2, 4
    ctx->r25 = S32(ctx->r10 << 4);
    // 0x800061EC: sb          $t8, 0x1D61($t1)
    MEM_B(0X1D61, ctx->r9) = ctx->r24;
    // 0x800061F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800061F4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800061F8: addu        $t0, $t9, $t4
    ctx->r8 = ADD32(ctx->r25, ctx->r12);
L_800061FC:
    // 0x800061FC: b           L_800062C0
    // 0x80006200: nop

        goto L_800062C0;
    // 0x80006200: nop

    // 0x80006204: lw          $a1, 0x1B50($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X1B50);
L_80006208:
    // 0x80006208: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8000620C: addu        $t0, $t7, $a1
    ctx->r8 = ADD32(ctx->r15, ctx->r5);
    // 0x80006210: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80006214:
    // 0x80006214: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x80006218: subu        $v0, $s1, $v1
    ctx->r2 = SUB32(ctx->r17, ctx->r3);
    // 0x8000621C: bltzl       $v0, L_800062B0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80006220: sll         $t5, $a0, 4
        ctx->r13 = S32(ctx->r4 << 4);
            goto L_800062B0;
    }
    goto skip_8;
    // 0x80006220: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    skip_8:
    // 0x80006224: lhu         $t5, 0xA($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0XA);
    // 0x80006228: subu        $t6, $t5, $s0
    ctx->r14 = SUB32(ctx->r13, ctx->r16);
    // 0x8000622C: sltu        $at, $t6, $v0
    ctx->r1 = ctx->r14 < ctx->r2 ? 1 : 0;
    // 0x80006230: bnel        $at, $zero, L_800062B0
    if (ctx->r1 != 0) {
        // 0x80006234: sll         $t5, $a0, 4
        ctx->r13 = S32(ctx->r4 << 4);
            goto L_800062B0;
    }
    goto skip_9;
    // 0x80006234: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    skip_9:
    // 0x80006238: lbu         $t8, 0xE($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XE);
    // 0x8000623C: bnel        $t8, $zero, L_80006298
    if (ctx->r24 != 0) {
        // 0x80006240: lw          $t6, 0x0($t0)
        ctx->r14 = MEM_W(ctx->r8, 0X0);
            goto L_80006298;
    }
    goto skip_10;
    // 0x80006240: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    skip_10:
    // 0x80006244: lbu         $v0, 0x1D60($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1D60);
    // 0x80006248: lbu         $v1, 0xD($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XD);
    // 0x8000624C: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x80006250: beql        $v0, $v1, L_8000628C
    if (ctx->r2 == ctx->r3) {
        // 0x80006254: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_8000628C;
    }
    goto skip_11;
    // 0x80006254: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    skip_11:
    // 0x80006258: lbu         $t4, 0x1B60($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X1B60);
    // 0x8000625C: addu        $t7, $t1, $v1
    ctx->r15 = ADD32(ctx->r9, ctx->r3);
    // 0x80006260: sb          $t4, 0x1B60($t7)
    MEM_B(0X1B60, ctx->r15) = ctx->r12;
    // 0x80006264: lbu         $t8, 0x1D60($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1D60);
    // 0x80006268: lw          $t6, 0x1B50($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X1B50);
    // 0x8000626C: lbu         $t5, 0xD($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XD);
    // 0x80006270: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x80006274: lbu         $t4, 0x1B60($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X1B60);
    // 0x80006278: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x8000627C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80006280: sb          $t5, 0xD($t8)
    MEM_B(0XD, ctx->r24) = ctx->r13;
    // 0x80006284: lbu         $v0, 0x1D60($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1D60);
    // 0x80006288: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
L_8000628C:
    // 0x8000628C: sb          $t9, 0x1D60($t1)
    MEM_B(0X1D60, ctx->r9) = ctx->r25;
    // 0x80006290: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x80006294: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
L_80006298:
    // 0x80006298: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8000629C: sb          $t4, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r12;
    // 0x800062A0: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800062A4: b           L_80006394
    // 0x800062A8: subu        $v0, $t7, $v1
    ctx->r2 = SUB32(ctx->r15, ctx->r3);
        goto L_80006394;
    // 0x800062A8: subu        $v0, $t7, $v1
    ctx->r2 = SUB32(ctx->r15, ctx->r3);
    // 0x800062AC: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
L_800062B0:
    // 0x800062B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800062B4: sltu        $at, $a2, $a0
    ctx->r1 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x800062B8: beq         $at, $zero, L_80006214
    if (ctx->r1 == 0) {
        // 0x800062BC: addu        $t0, $t5, $a1
        ctx->r8 = ADD32(ctx->r13, ctx->r5);
            goto L_80006214;
    }
    // 0x800062BC: addu        $t0, $t5, $a1
    ctx->r8 = ADD32(ctx->r13, ctx->r5);
L_800062C0:
    // 0x800062C0: bne         $t3, $zero, L_800062F8
    if (ctx->r11 != 0) {
        // 0x800062C4: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_800062F8;
    }
    // 0x800062C4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800062C8: lbu         $v0, 0x1D60($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1D60);
    // 0x800062CC: lbu         $t8, 0x1D62($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1D62);
    // 0x800062D0: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x800062D4: bne         $t8, $v0, L_800062E4
    if (ctx->r24 != ctx->r2) {
        // 0x800062D8: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_800062E4;
    }
    // 0x800062D8: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x800062DC: b           L_80006394
    // 0x800062E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80006394;
    // 0x800062E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800062E4:
    // 0x800062E4: lbu         $t2, 0x1B60($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X1B60);
    // 0x800062E8: lw          $t7, 0x1B50($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X1B50);
    // 0x800062EC: sb          $t4, 0x1D60($t1)
    MEM_B(0X1D60, ctx->r9) = ctx->r12;
    // 0x800062F0: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x800062F4: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
L_800062F8:
    // 0x800062F8: lhu         $v0, 0xA($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0XA);
    // 0x800062FC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80006300: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80006304: sb          $t5, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r13;
    // 0x80006308: and         $s0, $s1, $at
    ctx->r16 = ctx->r17 & ctx->r1;
    // 0x8000630C: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
    // 0x80006310: sh          $v0, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r2;
    // 0x80006314: lw          $v1, 0x1DB8($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X1DB8);
    // 0x80006318: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8000631C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80006320: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80006324: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x80006328: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8000632C: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x80006330: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80006334: addiu       $t7, $t7, 0x7E94
    ctx->r15 = ADD32(ctx->r15, 0X7E94);
    // 0x80006338: addiu       $t4, $t4, 0x6114
    ctx->r12 = ADD32(ctx->r12, 0X6114);
    // 0x8000633C: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    // 0x80006340: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x80006344: sw          $t5, 0x1DB8($t1)
    MEM_W(0X1DB8, ctx->r9) = ctx->r13;
    // 0x80006348: addiu       $a0, $a0, 0x151C
    ctx->r4 = ADD32(ctx->r4, 0X151C);
    // 0x8000634C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80006350: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80006354: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80006358: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x8000635C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80006360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80006364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80006368: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8000636C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80006370: jal         0x800077AC
    // 0x80006374: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_800077AC(rdram, ctx);
        goto after_0;
    // 0x80006374: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80006378: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000637C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80006380: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80006384: subu        $t9, $s1, $s0
    ctx->r25 = SUB32(ctx->r17, ctx->r16);
    // 0x80006388: sb          $t2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r10;
    // 0x8000638C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80006390: addu        $v0, $t9, $t4
    ctx->r2 = ADD32(ctx->r25, ctx->r12);
L_80006394:
    // 0x80006394: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80006398: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8000639C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800063A0: jr          $ra
    // 0x800063A4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800063A4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
