#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80438AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80438AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80438AF0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80438AF4: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80438AF8: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(80, 0X19A4) << 16);
    // 0x80438AFC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80438B00: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80438B04: lw          $t8, -0x5B9C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(80, 0X19A4));
    // 0x80438B08: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80438B0C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80438B10: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80438B14: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80438B18: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80438B1C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80438B20: beql        $v1, $zero, L_80438B54
    if (ctx->r3 == 0) {
        // 0x80438B24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80438B54;
    }
    goto skip_0;
    // 0x80438B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80438B28: jalr        $v1
    // 0x80438B2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80438B2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80438B30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80438B34: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80438B38: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80438B3C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80438B40: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80438B44: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80438B48: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80438B4C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80438B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80438B54:
    // 0x80438B54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80438B58: jr          $ra
    // 0x80438B5C: nop

    return;
    // 0x80438B5C: nop

;}
RECOMP_FUNC void func_80445E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445E2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445E34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80445E38: jal         0x8044448C
    // 0x80445E3C: addiu       $a1, $zero, 0x46E5
    ctx->r5 = ADD32(0, 0X46E5);
    func_8044448C(rdram, ctx);
        goto after_0;
    // 0x80445E3C: addiu       $a1, $zero, 0x46E5
    ctx->r5 = ADD32(0, 0X46E5);
    after_0:
    // 0x80445E40: beq         $v0, $zero, L_80445E4C
    if (ctx->r2 == 0) {
        // 0x80445E44: lbu         $t6, 0x1F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1F);
            goto L_80445E4C;
    }
    // 0x80445E44: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80445E48: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
L_80445E4C:
    // 0x80445E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445E50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445E54: jr          $ra
    // 0x80445E58: nop

    return;
    // 0x80445E58: nop

;}
RECOMP_FUNC void func_80475690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475690: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475694: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475698: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047569C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804756A0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804756A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804756A8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804756AC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804756B0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804756B4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804756B8: jr          $ra
    // 0x804756BC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804756BC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8064C2E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C2E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C2E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C2E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C2EC: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064C2F0: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8064C2F4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064C2F8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8064C2FC: nop

    // 0x8064C300: bc1fl       L_8064C33C
    if (!c1cs) {
        // 0x8064C304: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C33C;
    }
    goto skip_0;
    // 0x8064C304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C308: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064C30C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064C310: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064C314: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C318: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8064C31C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064C320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064C324: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x8064C328: jal         0x8064C5D8
    // 0x8064C32C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8064C5D8(rdram, ctx);
        goto after_0;
    // 0x8064C32C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064C330: jal         0x8064A40C
    // 0x8064C334: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8064A40C(rdram, ctx);
        goto after_1;
    // 0x8064C334: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8064C338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C33C:
    // 0x8064C33C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C340: jr          $ra
    // 0x8064C344: nop

    return;
    // 0x8064C344: nop

;}
RECOMP_FUNC void func_80682E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682E04: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682E08: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682E0C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682E10: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682E14: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682E18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682E1C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682E20: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682E24: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682E28: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682E2C: jr          $ra
    // 0x80682E30: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682E30: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80019184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019184: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80019188: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001918C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80019190: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80019194: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80019198: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001919C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800191A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800191A4: jal         0x80019B94
    // 0x800191A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80019B94(rdram, ctx);
        goto after_0;
    // 0x800191A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800191AC: beq         $v0, $zero, L_80019984
    if (ctx->r2 == 0) {
        // 0x800191B0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80019984;
    }
    // 0x800191B0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800191B4: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x800191B8: addiu       $s3, $s3, -0x6D00
    ctx->r19 = ADD32(ctx->r19, -0X6D00);
    // 0x800191BC: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800191C0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800191C4: lui         $s4, 0x500
    ctx->r20 = S32(0X500 << 16);
    // 0x800191C8: lw          $t6, 0x3C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X3C);
L_800191CC:
    // 0x800191CC: beq         $t6, $zero, L_8001997C
    if (ctx->r14 == 0) {
        // 0x800191D0: nop
    
            goto L_8001997C;
    }
    // 0x800191D0: nop

    // 0x800191D4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800191D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800191DC: sltiu       $at, $t7, 0x14
    ctx->r1 = ctx->r15 < 0X14 ? 1 : 0;
    // 0x800191E0: beq         $at, $zero, L_80019968
    if (ctx->r1 == 0) {
        // 0x800191E4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80019968;
    }
    // 0x800191E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800191E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800191EC: addu        $at, $at, $t7
    gpr jr_addend_800191F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800191F0: lw          $t7, -0x78C($at)
    ctx->r15 = ADD32(ctx->r1, -0X78C);
    // 0x800191F4: jr          $t7
    // 0x800191F8: nop

    switch (jr_addend_800191F4 >> 2) {
        case 0: goto L_800191FC; break;
        case 1: goto L_8001923C; break;
        case 2: goto L_80019848; break;
        case 3: goto L_80019868; break;
        case 4: goto L_80019888; break;
        case 5: goto L_800198A8; break;
        case 6: goto L_8001946C; break;
        case 7: goto L_8001971C; break;
        case 8: goto L_80019558; break;
        case 9: goto L_80019544; break;
        case 10: goto L_80019624; break;
        case 11: goto L_8001978C; break;
        case 12: goto L_800192C4; break;
        case 13: goto L_80019394; break;
        case 14: goto L_800193E8; break;
        case 15: goto L_800193FC; break;
        case 16: goto L_80019458; break;
        case 17: goto L_8001926C; break;
        case 18: goto L_80019950; break;
        case 19: goto L_80019928; break;
        default: switch_error(__func__, 0x800191F4, 0x800AF874);
    }
    // 0x800191F8: nop

L_800191FC:
    // 0x800191FC: lbu         $t8, 0x0($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X0);
    // 0x80019200: lui         $at, 0x8200
    ctx->r1 = S32(0X8200 << 16);
    // 0x80019204: bne         $t8, $zero, L_80019968
    if (ctx->r24 != 0) {
        // 0x80019208: nop
    
            goto L_80019968;
    }
    // 0x80019208: nop

    // 0x8001920C: lh          $t9, 0x10($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X10);
    // 0x80019210: lh          $t3, 0x14($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X14);
    // 0x80019214: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80019218: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8001921C: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80019220: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80019224: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x80019228: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8001922C: jal         0x8000A364
    // 0x80019230: or          $a0, $t2, $t5
    ctx->r4 = ctx->r10 | ctx->r13;
    func_8000A364(rdram, ctx);
        goto after_1;
    // 0x80019230: or          $a0, $t2, $t5
    ctx->r4 = ctx->r10 | ctx->r13;
    after_1:
    // 0x80019234: b           L_80019968
    // 0x80019238: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80019968;
    // 0x80019238: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8001923C:
    // 0x8001923C: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x80019240: bne         $t6, $zero, L_80019968
    if (ctx->r14 != 0) {
        // 0x80019244: nop
    
            goto L_80019968;
    }
    // 0x80019244: nop

    // 0x80019248: lh          $a0, 0x10($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X10);
    // 0x8001924C: lui         $at, 0x8300
    ctx->r1 = S32(0X8300 << 16);
    // 0x80019250: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80019254: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80019258: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001925C: jal         0x8000A364
    // 0x80019260: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_8000A364(rdram, ctx);
        goto after_2;
    // 0x80019260: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_2:
    // 0x80019264: b           L_80019968
    // 0x80019268: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80019968;
    // 0x80019268: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8001926C:
    // 0x8001926C: lbu         $t7, 0x0($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X0);
    // 0x80019270: bne         $t7, $zero, L_80019968
    if (ctx->r15 != 0) {
        // 0x80019274: nop
    
            goto L_80019968;
    }
    // 0x80019274: nop

    // 0x80019278: jal         0x800199F0
    // 0x8001927C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800199F0(rdram, ctx);
        goto after_3;
    // 0x8001927C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80019280: lwc1        $f4, 0x2C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80019284: lh          $t8, 0x10($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X10);
    // 0x80019288: lh          $t3, 0x14($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X14);
    // 0x8001928C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80019290: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80019294: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x80019298: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x8001929C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800192A0: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x800192A4: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800192A8: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x800192AC: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x800192B0: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x800192B4: jal         0x8000A388
    // 0x800192B8: or          $a0, $t1, $t4
    ctx->r4 = ctx->r9 | ctx->r12;
    func_8000A388(rdram, ctx);
        goto after_4;
    // 0x800192B8: or          $a0, $t1, $t4
    ctx->r4 = ctx->r9 | ctx->r12;
    after_4:
    // 0x800192BC: b           L_80019968
    // 0x800192C0: nop

        goto L_80019968;
    // 0x800192C0: nop

L_800192C4:
    // 0x800192C4: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x800192C8: bne         $t5, $zero, L_80019968
    if (ctx->r13 != 0) {
        // 0x800192CC: nop
    
            goto L_80019968;
    }
    // 0x800192CC: nop

    // 0x800192D0: lh          $v0, 0x10($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X10);
    // 0x800192D4: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x800192D8: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x800192DC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800192E0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800192E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800192E8: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800192EC: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800192F0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800192F4: lw          $t7, 0x7740($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7740);
    // 0x800192F8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800192FC: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80019300: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80019304: beq         $t8, $zero, L_80019968
    if (ctx->r24 == 0) {
        // 0x80019308: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80019968;
    }
    // 0x80019308: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001930C: lh          $t0, 0x12($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X12);
    // 0x80019310: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80019314: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80019318: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8001931C: addu        $t1, $t9, $t3
    ctx->r9 = ADD32(ctx->r25, ctx->r11);
    // 0x80019320: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x80019324: lw          $t4, 0x7774($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7774);
    // 0x80019328: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8001932C: srl         $t5, $t2, 31
    ctx->r13 = S32(U32(ctx->r10) >> 31);
    // 0x80019330: beq         $t5, $zero, L_80019968
    if (ctx->r13 == 0) {
        // 0x80019334: nop
    
            goto L_80019968;
    }
    // 0x80019334: nop

    // 0x80019338: jal         0x800199F0
    // 0x8001933C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800199F0(rdram, ctx);
        goto after_5;
    // 0x8001933C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80019340: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80019344: lh          $t6, 0x10($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X10);
    // 0x80019348: lh          $t9, 0x12($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X12);
    // 0x8001934C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80019350: lh          $t2, 0x14($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X14);
    // 0x80019354: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80019358: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8001935C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80019360: lui         $at, 0x600
    ctx->r1 = S32(0X600 << 16);
    // 0x80019364: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x80019368: sll         $t1, $t3, 8
    ctx->r9 = S32(ctx->r11 << 8);
    // 0x8001936C: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x80019370: or          $t4, $t0, $t1
    ctx->r12 = ctx->r8 | ctx->r9;
    // 0x80019374: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x80019378: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8001937C: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x80019380: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80019384: jal         0x8000A388
    // 0x80019388: or          $a0, $t4, $t5
    ctx->r4 = ctx->r12 | ctx->r13;
    func_8000A388(rdram, ctx);
        goto after_6;
    // 0x80019388: or          $a0, $t4, $t5
    ctx->r4 = ctx->r12 | ctx->r13;
    after_6:
    // 0x8001938C: b           L_80019968
    // 0x80019390: nop

        goto L_80019968;
    // 0x80019390: nop

L_80019394:
    // 0x80019394: lbu         $t7, 0x0($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X0);
    // 0x80019398: bne         $t7, $zero, L_80019968
    if (ctx->r15 != 0) {
        // 0x8001939C: nop
    
            goto L_80019968;
    }
    // 0x8001939C: nop

    // 0x800193A0: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x800193A4: bne         $s5, $t8, L_80019968
    if (ctx->r21 != ctx->r24) {
        // 0x800193A8: nop
    
            goto L_80019968;
    }
    // 0x800193A8: nop

    // 0x800193AC: jal         0x8001AA08
    // 0x800193B0: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    func_8001AA08(rdram, ctx);
        goto after_7;
    // 0x800193B0: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    after_7:
    // 0x800193B4: beq         $v0, $zero, L_80019968
    if (ctx->r2 == 0) {
        // 0x800193B8: nop
    
            goto L_80019968;
    }
    // 0x800193B8: nop

    // 0x800193BC: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800193C0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800193C4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800193C8: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    // 0x800193CC: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    // 0x800193D0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800193D4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800193D8: jal         0x8000A340
    // 0x800193DC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_8000A340(rdram, ctx);
        goto after_8;
    // 0x800193DC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_8:
    // 0x800193E0: b           L_80019968
    // 0x800193E4: nop

        goto L_80019968;
    // 0x800193E4: nop

L_800193E8:
    // 0x800193E8: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
    // 0x800193EC: beq         $t3, $zero, L_80019968
    if (ctx->r11 == 0) {
        // 0x800193F0: nop
    
            goto L_80019968;
    }
    // 0x800193F0: nop

    // 0x800193F4: b           L_80019968
    // 0x800193F8: nop

        goto L_80019968;
    // 0x800193F8: nop

L_800193FC:
    // 0x800193FC: lbu         $t0, 0x0($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X0);
    // 0x80019400: bne         $t0, $zero, L_80019968
    if (ctx->r8 != 0) {
        // 0x80019404: nop
    
            goto L_80019968;
    }
    // 0x80019404: nop

    // 0x80019408: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x8001940C: bne         $s5, $t1, L_80019968
    if (ctx->r21 != ctx->r9) {
        // 0x80019410: nop
    
            goto L_80019968;
    }
    // 0x80019410: nop

    // 0x80019414: jal         0x8001AA08
    // 0x80019418: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    func_8001AA08(rdram, ctx);
        goto after_9;
    // 0x80019418: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    after_9:
    // 0x8001941C: beq         $v0, $zero, L_80019968
    if (ctx->r2 == 0) {
        // 0x80019420: nop
    
            goto L_80019968;
    }
    // 0x80019420: nop

    // 0x80019424: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x80019428: lwc1        $f16, 0x18($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8001942C: lui         $at, 0x4900
    ctx->r1 = S32(0X4900 << 16);
    // 0x80019430: lh          $a0, 0x0($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X0);
    // 0x80019434: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019438: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8001943C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80019440: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80019444: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80019448: jal         0x8000A364
    // 0x8001944C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_8000A364(rdram, ctx);
        goto after_10;
    // 0x8001944C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_10:
    // 0x80019450: b           L_80019968
    // 0x80019454: nop

        goto L_80019968;
    // 0x80019454: nop

L_80019458:
    // 0x80019458: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x8001945C: beq         $t5, $zero, L_80019968
    if (ctx->r13 == 0) {
        // 0x80019460: nop
    
            goto L_80019968;
    }
    // 0x80019460: nop

    // 0x80019464: b           L_80019968
    // 0x80019468: nop

        goto L_80019968;
    // 0x80019468: nop

L_8001946C:
    // 0x8001946C: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x80019470: bne         $t6, $zero, L_80019968
    if (ctx->r14 != 0) {
        // 0x80019474: nop
    
            goto L_80019968;
    }
    // 0x80019474: nop

    // 0x80019478: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8001947C: beq         $v0, $s5, L_80019494
    if (ctx->r2 == ctx->r21) {
        // 0x80019480: nop
    
            goto L_80019494;
    }
    // 0x80019480: nop

    // 0x80019484: beq         $v0, $s6, L_800194FC
    if (ctx->r2 == ctx->r22) {
        // 0x80019488: nop
    
            goto L_800194FC;
    }
    // 0x80019488: nop

    // 0x8001948C: b           L_80019968
    // 0x80019490: nop

        goto L_80019968;
    // 0x80019490: nop

L_80019494:
    // 0x80019494: jal         0x8001AA08
    // 0x80019498: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    func_8001AA08(rdram, ctx);
        goto after_11;
    // 0x80019498: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    after_11:
    // 0x8001949C: beq         $v0, $zero, L_80019968
    if (ctx->r2 == 0) {
        // 0x800194A0: nop
    
            goto L_80019968;
    }
    // 0x800194A0: nop

    // 0x800194A4: jal         0x800199F0
    // 0x800194A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800199F0(rdram, ctx);
        goto after_12;
    // 0x800194A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800194AC: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x800194B0: lh          $t1, 0x12($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X12);
    // 0x800194B4: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800194B8: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800194BC: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800194C0: sll         $t4, $t2, 8
    ctx->r12 = S32(ctx->r10 << 8);
    // 0x800194C4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800194C8: sll         $t3, $t9, 16
    ctx->r11 = S32(ctx->r25 << 16);
    // 0x800194CC: or          $t0, $t3, $at
    ctx->r8 = ctx->r11 | ctx->r1;
    // 0x800194D0: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x800194D4: or          $a0, $t0, $t4
    ctx->r4 = ctx->r8 | ctx->r12;
    // 0x800194D8: jal         0x8000A340
    // 0x800194DC: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    func_8000A340(rdram, ctx);
        goto after_13;
    // 0x800194DC: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    after_13:
    // 0x800194E0: lh          $t6, 0x12($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X12);
    // 0x800194E4: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x800194E8: lwc1        $f4, 0x2C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800194EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800194F0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800194F4: b           L_80019968
    // 0x800194F8: swc1        $f4, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f4.u32l;
        goto L_80019968;
    // 0x800194F8: swc1        $f4, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f4.u32l;
L_800194FC:
    // 0x800194FC: jal         0x8001BA50
    // 0x80019500: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    func_8001BA50(rdram, ctx);
        goto after_14;
    // 0x80019500: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    after_14:
    // 0x80019504: beq         $v0, $zero, L_80019968
    if (ctx->r2 == 0) {
        // 0x80019508: lui         $at, 0x100
        ctx->r1 = S32(0X100 << 16);
            goto L_80019968;
    }
    // 0x80019508: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8001950C: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x80019510: lh          $t9, 0x10($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X10);
    // 0x80019514: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80019518: lh          $t4, 0x0($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X0);
    // 0x8001951C: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x80019520: sll         $t1, $t3, 16
    ctx->r9 = S32(ctx->r11 << 16);
    // 0x80019524: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x80019528: sll         $t5, $t6, 8
    ctx->r13 = S32(ctx->r14 << 8);
    // 0x8001952C: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80019530: or          $a0, $t2, $t5
    ctx->r4 = ctx->r10 | ctx->r13;
    // 0x80019534: jal         0x8000A340
    // 0x80019538: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    func_8000A340(rdram, ctx);
        goto after_15;
    // 0x80019538: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    after_15:
    // 0x8001953C: b           L_80019968
    // 0x80019540: nop

        goto L_80019968;
    // 0x80019540: nop

L_80019544:
    // 0x80019544: lbu         $t7, 0x0($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X0);
    // 0x80019548: beq         $t7, $zero, L_80019968
    if (ctx->r15 == 0) {
        // 0x8001954C: nop
    
            goto L_80019968;
    }
    // 0x8001954C: nop

    // 0x80019550: b           L_80019968
    // 0x80019554: nop

        goto L_80019968;
    // 0x80019554: nop

L_80019558:
    // 0x80019558: lbu         $t8, 0x0($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X0);
    // 0x8001955C: bne         $t8, $zero, L_80019968
    if (ctx->r24 != 0) {
        // 0x80019560: nop
    
            goto L_80019968;
    }
    // 0x80019560: nop

    // 0x80019564: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80019568: beq         $v0, $s5, L_800195C0
    if (ctx->r2 == ctx->r21) {
        // 0x8001956C: nop
    
            goto L_800195C0;
    }
    // 0x8001956C: nop

    // 0x80019570: bne         $v0, $s6, L_80019968
    if (ctx->r2 != ctx->r22) {
        // 0x80019574: nop
    
            goto L_80019968;
    }
    // 0x80019574: nop

    // 0x80019578: jal         0x8001BA50
    // 0x8001957C: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    func_8001BA50(rdram, ctx);
        goto after_16;
    // 0x8001957C: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    after_16:
    // 0x80019580: beq         $v0, $zero, L_80019968
    if (ctx->r2 == 0) {
        // 0x80019584: lui         $at, 0x400
        ctx->r1 = S32(0X400 << 16);
            goto L_80019968;
    }
    // 0x80019584: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80019588: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x8001958C: lh          $t9, 0x10($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X10);
    // 0x80019590: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80019594: lh          $t6, 0x0($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X0);
    // 0x80019598: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x8001959C: sll         $t1, $t3, 16
    ctx->r9 = S32(ctx->r11 << 16);
    // 0x800195A0: andi        $t2, $t6, 0xFF
    ctx->r10 = ctx->r14 & 0XFF;
    // 0x800195A4: sll         $t5, $t2, 8
    ctx->r13 = S32(ctx->r10 << 8);
    // 0x800195A8: or          $t0, $t1, $at
    ctx->r8 = ctx->r9 | ctx->r1;
    // 0x800195AC: or          $a0, $t0, $t5
    ctx->r4 = ctx->r8 | ctx->r13;
    // 0x800195B0: jal         0x8000A340
    // 0x800195B4: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    func_8000A340(rdram, ctx);
        goto after_17;
    // 0x800195B4: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    after_17:
    // 0x800195B8: b           L_80019968
    // 0x800195BC: nop

        goto L_80019968;
    // 0x800195BC: nop

L_800195C0:
    // 0x800195C0: jal         0x8001AA08
    // 0x800195C4: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    func_8001AA08(rdram, ctx);
        goto after_18;
    // 0x800195C4: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    after_18:
    // 0x800195C8: beq         $v0, $zero, L_80019968
    if (ctx->r2 == 0) {
        // 0x800195CC: nop
    
            goto L_80019968;
    }
    // 0x800195CC: nop

    // 0x800195D0: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x800195D4: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x800195D8: lui         $at, 0x9000
    ctx->r1 = S32(0X9000 << 16);
    // 0x800195DC: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x800195E0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800195E4: lhu         $a1, 0x0($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X0);
    // 0x800195E8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800195EC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800195F0: jal         0x8000A3B8
    // 0x800195F4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_8000A3B8(rdram, ctx);
        goto after_19;
    // 0x800195F4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_19:
    // 0x800195F8: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800195FC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80019600: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    // 0x80019604: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    // 0x80019608: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001960C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80019610: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    // 0x80019614: jal         0x8000A340
    // 0x80019618: ori         $a0, $a0, 0xFF00
    ctx->r4 = ctx->r4 | 0XFF00;
    func_8000A340(rdram, ctx);
        goto after_20;
    // 0x80019618: ori         $a0, $a0, 0xFF00
    ctx->r4 = ctx->r4 | 0XFF00;
    after_20:
    // 0x8001961C: b           L_80019968
    // 0x80019620: nop

        goto L_80019968;
    // 0x80019620: nop

L_80019624:
    // 0x80019624: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
    // 0x80019628: bne         $t3, $zero, L_80019968
    if (ctx->r11 != 0) {
        // 0x8001962C: nop
    
            goto L_80019968;
    }
    // 0x8001962C: nop

    // 0x80019630: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80019634: beq         $v0, $s5, L_8001969C
    if (ctx->r2 == ctx->r21) {
        // 0x80019638: nop
    
            goto L_8001969C;
    }
    // 0x80019638: nop

    // 0x8001963C: bne         $v0, $s6, L_80019968
    if (ctx->r2 != ctx->r22) {
        // 0x80019640: nop
    
            goto L_80019968;
    }
    // 0x80019640: nop

    // 0x80019644: jal         0x8001BA50
    // 0x80019648: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    func_8001BA50(rdram, ctx);
        goto after_21;
    // 0x80019648: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    after_21:
    // 0x8001964C: beq         $v0, $zero, L_80019968
    if (ctx->r2 == 0) {
        // 0x80019650: nop
    
            goto L_80019968;
    }
    // 0x80019650: nop

    // 0x80019654: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80019658: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x8001965C: lh          $t1, 0x10($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X10);
    // 0x80019660: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019664: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x80019668: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x8001966C: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80019670: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80019674: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x80019678: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8001967C: or          $t2, $t6, $s4
    ctx->r10 = ctx->r14 | ctx->r20;
    // 0x80019680: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80019684: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80019688: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8001968C: jal         0x8000A388
    // 0x80019690: or          $a0, $t2, $t8
    ctx->r4 = ctx->r10 | ctx->r24;
    func_8000A388(rdram, ctx);
        goto after_22;
    // 0x80019690: or          $a0, $t2, $t8
    ctx->r4 = ctx->r10 | ctx->r24;
    after_22:
    // 0x80019694: b           L_80019968
    // 0x80019698: nop

        goto L_80019968;
    // 0x80019698: nop

L_8001969C:
    // 0x8001969C: jal         0x8001AA08
    // 0x800196A0: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    func_8001AA08(rdram, ctx);
        goto after_23;
    // 0x800196A0: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    after_23:
    // 0x800196A4: beq         $v0, $zero, L_80019968
    if (ctx->r2 == 0) {
        // 0x800196A8: nop
    
            goto L_80019968;
    }
    // 0x800196A8: nop

    // 0x800196AC: jal         0x800199F0
    // 0x800196B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800199F0(rdram, ctx);
        goto after_24;
    // 0x800196B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_24:
    // 0x800196B4: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x800196B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800196BC: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
L_800196C0:
    // 0x800196C0: lwc1        $f18, 0x2C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800196C4: andi        $t5, $s0, 0xFF
    ctx->r13 = ctx->r16 & 0XFF;
    // 0x800196C8: lh          $t1, 0x0($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X0);
    // 0x800196CC: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800196D0: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x800196D4: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x800196D8: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x800196DC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800196E0: or          $t0, $t6, $s4
    ctx->r8 = ctx->r14 | ctx->r20;
    // 0x800196E4: or          $a0, $t0, $t7
    ctx->r4 = ctx->r8 | ctx->r15;
    // 0x800196E8: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x800196EC: jal         0x8000A388
    // 0x800196F0: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    func_8000A388(rdram, ctx);
        goto after_25;
    // 0x800196F0: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_25:
    // 0x800196F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800196F8: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x800196FC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80019700: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x80019704: bnel        $at, $zero, L_800196C0
    if (ctx->r1 != 0) {
        // 0x80019708: lw          $t3, 0x8($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X8);
            goto L_800196C0;
    }
    goto skip_0;
    // 0x80019708: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    skip_0:
    // 0x8001970C: lwc1        $f18, 0x2C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80019710: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x80019714: b           L_80019968
    // 0x80019718: swc1        $f18, 0x80($t8)
    MEM_W(0X80, ctx->r24) = ctx->f18.u32l;
        goto L_80019968;
    // 0x80019718: swc1        $f18, 0x80($t8)
    MEM_W(0X80, ctx->r24) = ctx->f18.u32l;
L_8001971C:
    // 0x8001971C: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
    // 0x80019720: bne         $t9, $zero, L_80019968
    if (ctx->r25 != 0) {
        // 0x80019724: nop
    
            goto L_80019968;
    }
    // 0x80019724: nop

    // 0x80019728: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x8001972C: bne         $s6, $t3, L_80019968
    if (ctx->r22 != ctx->r11) {
        // 0x80019730: nop
    
            goto L_80019968;
    }
    // 0x80019730: nop

    // 0x80019734: jal         0x8001BA50
    // 0x80019738: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    func_8001BA50(rdram, ctx);
        goto after_26;
    // 0x80019738: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    after_26:
    // 0x8001973C: beq         $v0, $zero, L_80019968
    if (ctx->r2 == 0) {
        // 0x80019740: lui         $at, 0x300
        ctx->r1 = S32(0X300 << 16);
            goto L_80019968;
    }
    // 0x80019740: lui         $at, 0x300
    ctx->r1 = S32(0X300 << 16);
    // 0x80019744: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80019748: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x8001974C: lh          $t1, 0x10($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X10);
    // 0x80019750: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80019754: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x80019758: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x8001975C: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80019760: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80019764: andi        $t2, $t7, 0xFF
    ctx->r10 = ctx->r15 & 0XFF;
    // 0x80019768: sll         $t8, $t2, 8
    ctx->r24 = S32(ctx->r10 << 8);
    // 0x8001976C: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x80019770: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80019774: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80019778: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8001977C: jal         0x8000A388
    // 0x80019780: or          $a0, $t5, $t8
    ctx->r4 = ctx->r13 | ctx->r24;
    func_8000A388(rdram, ctx);
        goto after_27;
    // 0x80019780: or          $a0, $t5, $t8
    ctx->r4 = ctx->r13 | ctx->r24;
    after_27:
    // 0x80019784: b           L_80019968
    // 0x80019788: nop

        goto L_80019968;
    // 0x80019788: nop

L_8001978C:
    // 0x8001978C: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
    // 0x80019790: bne         $t3, $zero, L_80019968
    if (ctx->r11 != 0) {
        // 0x80019794: nop
    
            goto L_80019968;
    }
    // 0x80019794: nop

    // 0x80019798: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x8001979C: bne         $s5, $t1, L_80019968
    if (ctx->r21 != ctx->r9) {
        // 0x800197A0: nop
    
            goto L_80019968;
    }
    // 0x800197A0: nop

    // 0x800197A4: lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X8);
    // 0x800197A8: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x800197AC: lui         $at, 0x9000
    ctx->r1 = S32(0X9000 << 16);
    // 0x800197B0: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    // 0x800197B4: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    // 0x800197B8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800197BC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800197C0: jal         0x8000A3B8
    // 0x800197C4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_8000A3B8(rdram, ctx);
        goto after_28;
    // 0x800197C4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_28:
    // 0x800197C8: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x800197CC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800197D0: sll         $a1, $s5, 24
    ctx->r5 = S32(ctx->r21 << 24);
    // 0x800197D4: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    // 0x800197D8: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x800197DC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800197E0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800197E4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    // 0x800197E8: jal         0x8000A388
    // 0x800197EC: ori         $a0, $a0, 0xFF00
    ctx->r4 = ctx->r4 | 0XFF00;
    func_8000A388(rdram, ctx);
        goto after_29;
    // 0x800197EC: ori         $a0, $a0, 0xFF00
    ctx->r4 = ctx->r4 | 0XFF00;
    after_29:
    // 0x800197F0: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x800197F4: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x800197F8: lui         $at, 0x9000
    ctx->r1 = S32(0X9000 << 16);
    // 0x800197FC: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x80019800: lhu         $a1, 0x0($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X0);
    // 0x80019804: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80019808: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001980C: nor         $a1, $a1, $zero
    ctx->r5 = ~(ctx->r5 | 0);
    // 0x80019810: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80019814: jal         0x8000A3B8
    // 0x80019818: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_8000A3B8(rdram, ctx);
        goto after_30;
    // 0x80019818: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_30:
    // 0x8001981C: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x80019820: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80019824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019828: lh          $a0, 0x0($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X0);
    // 0x8001982C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80019830: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80019834: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    // 0x80019838: jal         0x8000A388
    // 0x8001983C: ori         $a0, $a0, 0xFF00
    ctx->r4 = ctx->r4 | 0XFF00;
    func_8000A388(rdram, ctx);
        goto after_31;
    // 0x8001983C: ori         $a0, $a0, 0xFF00
    ctx->r4 = ctx->r4 | 0XFF00;
    after_31:
    // 0x80019840: b           L_80019968
    // 0x80019844: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80019968;
    // 0x80019844: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80019848:
    // 0x80019848: lbu         $t8, 0x0($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X0);
    // 0x8001984C: lui         $a0, 0xF100
    ctx->r4 = S32(0XF100 << 16);
    // 0x80019850: bne         $t8, $zero, L_80019968
    if (ctx->r24 != 0) {
        // 0x80019854: nop
    
            goto L_80019968;
    }
    // 0x80019854: nop

    // 0x80019858: jal         0x8000A364
    // 0x8001985C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000A364(rdram, ctx);
        goto after_32;
    // 0x8001985C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80019860: b           L_80019968
    // 0x80019864: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80019968;
    // 0x80019864: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80019868:
    // 0x80019868: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
    // 0x8001986C: lui         $a0, 0xF200
    ctx->r4 = S32(0XF200 << 16);
    // 0x80019870: bne         $t9, $zero, L_80019968
    if (ctx->r25 != 0) {
        // 0x80019874: nop
    
            goto L_80019968;
    }
    // 0x80019874: nop

    // 0x80019878: jal         0x8000A364
    // 0x8001987C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000A364(rdram, ctx);
        goto after_33;
    // 0x8001987C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x80019880: b           L_80019968
    // 0x80019884: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80019968;
    // 0x80019884: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80019888:
    // 0x80019888: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
    // 0x8001988C: lui         $a0, 0xF200
    ctx->r4 = S32(0XF200 << 16);
    // 0x80019890: bne         $t3, $zero, L_80019968
    if (ctx->r11 != 0) {
        // 0x80019894: nop
    
            goto L_80019968;
    }
    // 0x80019894: nop

    // 0x80019898: jal         0x8000A364
    // 0x8001989C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_8000A364(rdram, ctx);
        goto after_34;
    // 0x8001989C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_34:
    // 0x800198A0: b           L_80019968
    // 0x800198A4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80019968;
    // 0x800198A4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800198A8:
    // 0x800198A8: lbu         $t1, 0x0($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X0);
    // 0x800198AC: bne         $t1, $zero, L_80019968
    if (ctx->r9 != 0) {
        // 0x800198B0: nop
    
            goto L_80019968;
    }
    // 0x800198B0: nop

    // 0x800198B4: lh          $v0, 0x14($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X14);
    // 0x800198B8: lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // 0x800198BC: beq         $v0, $zero, L_800198E8
    if (ctx->r2 == 0) {
        // 0x800198C0: nop
    
            goto L_800198E8;
    }
    // 0x800198C0: nop

    // 0x800198C4: beq         $v0, $s5, L_80019908
    if (ctx->r2 == ctx->r21) {
        // 0x800198C8: lui         $a0, 0xF000
        ctx->r4 = S32(0XF000 << 16);
            goto L_80019908;
    }
    // 0x800198C8: lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // 0x800198CC: beq         $v0, $s6, L_800198F8
    if (ctx->r2 == ctx->r22) {
        // 0x800198D0: lui         $a0, 0xF000
        ctx->r4 = S32(0XF000 << 16);
            goto L_800198F8;
    }
    // 0x800198D0: lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // 0x800198D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800198D8: beq         $v0, $at, L_80019918
    if (ctx->r2 == ctx->r1) {
        // 0x800198DC: lui         $a0, 0xF000
        ctx->r4 = S32(0XF000 << 16);
            goto L_80019918;
    }
    // 0x800198DC: lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // 0x800198E0: b           L_80019968
    // 0x800198E4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80019968;
    // 0x800198E4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800198E8:
    // 0x800198E8: jal         0x8000A364
    // 0x800198EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000A364(rdram, ctx);
        goto after_35;
    // 0x800198EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_35:
    // 0x800198F0: b           L_80019968
    // 0x800198F4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80019968;
    // 0x800198F4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800198F8:
    // 0x800198F8: jal         0x8000A364
    // 0x800198FC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_8000A364(rdram, ctx);
        goto after_36;
    // 0x800198FC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_36:
    // 0x80019900: b           L_80019968
    // 0x80019904: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80019968;
    // 0x80019904: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80019908:
    // 0x80019908: jal         0x8000A364
    // 0x8001990C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_8000A364(rdram, ctx);
        goto after_37;
    // 0x8001990C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_37:
    // 0x80019910: b           L_80019968
    // 0x80019914: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80019968;
    // 0x80019914: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80019918:
    // 0x80019918: jal         0x8000A364
    // 0x8001991C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8000A364(rdram, ctx);
        goto after_38;
    // 0x8001991C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_38:
    // 0x80019920: b           L_80019968
    // 0x80019924: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80019968;
    // 0x80019924: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80019928:
    // 0x80019928: lbu         $t4, 0x0($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X0);
    // 0x8001992C: bne         $t4, $zero, L_80019968
    if (ctx->r12 != 0) {
        // 0x80019930: nop
    
            goto L_80019968;
    }
    // 0x80019930: nop

    // 0x80019934: jal         0x8000A8F8
    // 0x80019938: lh          $a0, 0x14($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X14);
    func_8000A8F8(rdram, ctx);
        goto after_39;
    // 0x80019938: lh          $a0, 0x14($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X14);
    after_39:
    // 0x8001993C: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x80019940: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80019944: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80019948: b           L_80019968
    // 0x8001994C: sb          $t0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r8;
        goto L_80019968;
    // 0x8001994C: sb          $t0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r8;
L_80019950:
    // 0x80019950: jal         0x8000A84C
    // 0x80019954: nop

    func_8000A84C(rdram, ctx);
        goto after_40;
    // 0x80019954: nop

    after_40:
    // 0x80019958: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x8001995C: beq         $t7, $zero, L_80019968
    if (ctx->r15 == 0) {
        // 0x80019960: andi        $s2, $v0, 0xFF
        ctx->r18 = ctx->r2 & 0XFF;
            goto L_80019968;
    }
    // 0x80019960: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x80019964: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
L_80019968:
    // 0x80019968: beql        $s2, $zero, L_8001997C
    if (ctx->r18 == 0) {
        // 0x8001996C: lw          $s1, 0x44($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X44);
            goto L_8001997C;
    }
    goto skip_1;
    // 0x8001996C: lw          $s1, 0x44($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X44);
    skip_1:
    // 0x80019970: jal         0x80019A78
    // 0x80019974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80019A78(rdram, ctx);
        goto after_41;
    // 0x80019974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_41:
    // 0x80019978: lw          $s1, 0x44($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X44);
L_8001997C:
    // 0x8001997C: bnel        $s1, $zero, L_800191CC
    if (ctx->r17 != 0) {
        // 0x80019980: lw          $t6, 0x3C($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X3C);
            goto L_800191CC;
    }
    goto skip_2;
    // 0x80019980: lw          $t6, 0x3C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X3C);
    skip_2:
L_80019984:
    // 0x80019984: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80019988: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001998C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80019990: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80019994: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80019998: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001999C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800199A0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800199A4: jr          $ra
    // 0x800199A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800199A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800199AC: nop

;}
RECOMP_FUNC void func_80068D8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068D8C: jr          $ra
    // 0x80068D90: nop

    return;
    // 0x80068D90: nop

;}
RECOMP_FUNC void func_8070C7F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070C7F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8070C7F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8070C7FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8070C800: jal         0x80047090
    // 0x8070C804: addiu       $a0, $zero, 0x461C
    ctx->r4 = ADD32(0, 0X461C);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8070C804: addiu       $a0, $zero, 0x461C
    ctx->r4 = ADD32(0, 0X461C);
    after_0:
    // 0x8070C808: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8070C80C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8070C810: beq         $v0, $at, L_8070C860
    if (ctx->r2 == ctx->r1) {
        // 0x8070C814: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8070C860;
    }
    // 0x8070C814: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8070C818: lui         $at, 0x461C
    ctx->r1 = S32(0X461C << 16);
    // 0x8070C81C: or          $a1, $v1, $at
    ctx->r5 = ctx->r3 | ctx->r1;
    // 0x8070C820: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD40) << 16);
    // 0x8070C824: lwc1        $f6, -0x2C30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD40));
    // 0x8070C828: lwc1        $f4, 0x8C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8C);
    // 0x8070C82C: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(721, 0XF50) << 16);
    // 0x8070C830: lw          $a2, 0x84($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X84);
    // 0x8070C834: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8070C838: lw          $a3, 0x88($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X88);
    // 0x8070C83C: addiu       $a0, $a0, -0x2A20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(721, 0XF50));
    // 0x8070C840: jal         0x80046804
    // 0x8070C844: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x8070C844: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8070C848: beq         $v0, $zero, L_8070C860
    if (ctx->r2 == 0) {
        // 0x8070C84C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8070C860;
    }
    // 0x8070C84C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8070C850: jal         0x80044194
    // 0x8070C854: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x8070C854: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x8070C858: jal         0x80052BA4
    // 0x8070C85C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80052BA4(rdram, ctx);
        goto after_3;
    // 0x8070C85C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
L_8070C860:
    // 0x8070C860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8070C864: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8070C868: jr          $ra
    // 0x8070C86C: nop

    return;
    // 0x8070C86C: nop

;}
RECOMP_FUNC void func_80004160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004168: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000416C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80004170: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80004174: jal         0x80005640
    // 0x80004178: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80005640(rdram, ctx);
        goto after_0;
    // 0x80004178: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8000417C: beq         $v0, $zero, L_8000418C
    if (ctx->r2 == 0) {
        // 0x80004180: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8000418C;
    }
    // 0x80004180: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80004184: b           L_800041AC
    // 0x80004188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800041AC;
    // 0x80004188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000418C:
    // 0x8000418C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80004190: bne         $a1, $at, L_800041A0
    if (ctx->r5 != ctx->r1) {
        // 0x80004194: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800041A0;
    }
    // 0x80004194: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80004198: b           L_800041A8
    // 0x8000419C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800041A8;
    // 0x8000419C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800041A0:
    // 0x800041A0: jal         0x800041B8
    // 0x800041A4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800041B8(rdram, ctx);
        goto after_1;
    // 0x800041A4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
L_800041A8:
    // 0x800041A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800041AC:
    // 0x800041AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800041B0: jr          $ra
    // 0x800041B4: nop

    return;
    // 0x800041B4: nop

;}
RECOMP_FUNC void func_80584CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584CCC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584CD0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584CD4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584CD8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584CDC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584CE0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584CE4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584CE8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584CEC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584CF0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584CF4: jr          $ra
    // 0x80584CF8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584CF8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80030A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030A98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80030A9C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80030AA0: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80030AA4: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80030AA8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80030AAC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80030AB0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80030AB4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80030AB8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80030ABC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80030AC0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80030AC4: lh          $s2, 0x184($a0)
    ctx->r18 = MEM_H(ctx->r4, 0X184);
    // 0x80030AC8: andi        $s3, $a1, 0xFF
    ctx->r19 = ctx->r5 & 0XFF;
    // 0x80030ACC: addiu       $s1, $a0, 0x188
    ctx->r17 = ADD32(ctx->r4, 0X188);
    // 0x80030AD0: beq         $s2, $zero, L_80030B50
    if (ctx->r18 == 0) {
        // 0x80030AD4: addiu       $s7, $zero, 0x4011
        ctx->r23 = ADD32(0, 0X4011);
            goto L_80030B50;
    }
    // 0x80030AD4: addiu       $s7, $zero, 0x4011
    ctx->r23 = ADD32(0, 0X4011);
    // 0x80030AD8: addiu       $s6, $zero, 0x4010
    ctx->r22 = ADD32(0, 0X4010);
    // 0x80030ADC: addiu       $s5, $zero, 0x400C
    ctx->r21 = ADD32(0, 0X400C);
    // 0x80030AE0: addiu       $s4, $zero, 0x400B
    ctx->r20 = ADD32(0, 0X400B);
L_80030AE4:
    // 0x80030AE4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80030AE8: beq         $s0, $zero, L_80030B48
    if (ctx->r16 == 0) {
        // 0x80030AEC: nop
    
            goto L_80030B48;
    }
    // 0x80030AEC: nop

    // 0x80030AF0: lh          $t6, 0x184($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X184);
    // 0x80030AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80030AF8: beql        $t6, $zero, L_80030B10
    if (ctx->r14 == 0) {
        // 0x80030AFC: lbu         $t7, 0x18($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X18);
            goto L_80030B10;
    }
    goto skip_0;
    // 0x80030AFC: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    skip_0:
    // 0x80030B00: jal         0x80030A98
    // 0x80030B04: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    func_80030A98(rdram, ctx);
        goto after_0;
    // 0x80030B04: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    after_0:
    // 0x80030B08: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80030B0C: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
L_80030B10:
    // 0x80030B10: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80030B14: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80030B18: beq         $t7, $zero, L_80030B48
    if (ctx->r15 == 0) {
        // 0x80030B1C: sra         $s2, $s2, 16
        ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
            goto L_80030B48;
    }
    // 0x80030B1C: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80030B20: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80030B24: beq         $v0, $s4, L_80030B48
    if (ctx->r2 == ctx->r20) {
        // 0x80030B28: nop
    
            goto L_80030B48;
    }
    // 0x80030B28: nop

    // 0x80030B2C: beq         $v0, $s5, L_80030B48
    if (ctx->r2 == ctx->r21) {
        // 0x80030B30: nop
    
            goto L_80030B48;
    }
    // 0x80030B30: nop

    // 0x80030B34: beq         $v0, $s6, L_80030B48
    if (ctx->r2 == ctx->r22) {
        // 0x80030B38: nop
    
            goto L_80030B48;
    }
    // 0x80030B38: nop

    // 0x80030B3C: beq         $v0, $s7, L_80030B48
    if (ctx->r2 == ctx->r23) {
        // 0x80030B40: nop
    
            goto L_80030B48;
    }
    // 0x80030B40: nop

    // 0x80030B44: sb          $s3, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r19;
L_80030B48:
    // 0x80030B48: bne         $s2, $zero, L_80030AE4
    if (ctx->r18 != 0) {
        // 0x80030B4C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80030AE4;
    }
    // 0x80030B4C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80030B50:
    // 0x80030B50: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80030B54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80030B58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80030B5C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80030B60: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80030B64: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80030B68: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80030B6C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80030B70: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80030B74: jr          $ra
    // 0x80030B78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80030B78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80449E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449E6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80449E70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80449E74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80449E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80449E7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80449E80: bne         $a2, $zero, L_80449EB0
    if (ctx->r6 != 0) {
        // 0x80449E84: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80449EB0;
    }
    // 0x80449E84: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80449E88: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x80449E8C: lw          $v1, 0x118($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X118);
    // 0x80449E90: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80449E94: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80449E98: bne         $at, $zero, L_80449EF0
    if (ctx->r1 != 0) {
        // 0x80449E9C: sw          $t7, 0x28($v0)
        MEM_W(0X28, ctx->r2) = ctx->r15;
            goto L_80449EF0;
    }
    // 0x80449E9C: sw          $t7, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r15;
    // 0x80449EA0: jal         0x80446B8C
    // 0x80449EA4: nop

    func_80446B8C(rdram, ctx);
        goto after_0;
    // 0x80449EA4: nop

    after_0:
    // 0x80449EA8: b           L_80449EF4
    // 0x80449EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449EF4;
    // 0x80449EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449EB0:
    // 0x80449EB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80449EB4: bnel        $a2, $at, L_80449EE0
    if (ctx->r6 != ctx->r1) {
        // 0x80449EB8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80449EE0;
    }
    goto skip_0;
    // 0x80449EB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80449EBC: jal         0x80446B28
    // 0x80449EC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446B28(rdram, ctx);
        goto after_1;
    // 0x80449EC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80449EC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80449EC8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449ECC: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80449ED0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449ED4: b           L_80449EF0
    // 0x80449ED8: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80449EF0;
    // 0x80449ED8: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x80449EDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80449EE0:
    // 0x80449EE0: bnel        $a2, $at, L_80449EF4
    if (ctx->r6 != ctx->r1) {
        // 0x80449EE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449EF4;
    }
    goto skip_1;
    // 0x80449EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80449EE8: jal         0x80446B8C
    // 0x80449EEC: nop

    func_80446B8C(rdram, ctx);
        goto after_2;
    // 0x80449EEC: nop

    after_2:
L_80449EF0:
    // 0x80449EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449EF4:
    // 0x80449EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80449EF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449EFC: jr          $ra
    // 0x80449F00: nop

    return;
    // 0x80449F00: nop

;}
RECOMP_FUNC void func_8000DC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DC14: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000DC18: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000DC1C: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x8000DC20: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000DC24: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x8000DC28: addiu       $s3, $s3, -0x63C4
    ctx->r19 = ADD32(ctx->r19, -0X63C4);
    // 0x8000DC2C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000DC30: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000DC34: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000DC38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000DC3C: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8000DC40: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x8000DC44: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x8000DC48: lui         $s4, 0x800C
    ctx->r20 = S32(0X800C << 16);
    // 0x8000DC4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000DC50: sw          $s3, 0x4F2C($v0)
    MEM_W(0X4F2C, ctx->r2) = ctx->r19;
    // 0x8000DC54: sw          $s3, 0x4F30($v0)
    MEM_W(0X4F30, ctx->r2) = ctx->r19;
    // 0x8000DC58: sw          $zero, 0x4F34($v0)
    MEM_W(0X4F34, ctx->r2) = 0;
    // 0x8000DC5C: sw          $zero, 0x4F38($v0)
    MEM_W(0X4F38, ctx->r2) = 0;
    // 0x8000DC60: addiu       $s4, $s4, -0x6430
    ctx->r20 = ADD32(ctx->r20, -0X6430);
    // 0x8000DC64: addiu       $s2, $s2, 0x7B60
    ctx->r18 = ADD32(ctx->r18, 0X7B60);
    // 0x8000DC68: addiu       $s1, $s1, 0x7BD0
    ctx->r17 = ADD32(ctx->r17, 0X7BD0);
    // 0x8000DC6C: addiu       $s0, $s0, 0x4D10
    ctx->r16 = ADD32(ctx->r16, 0X4D10);
L_8000DC70:
    // 0x8000DC70: sw          $s2, 0x2EC8($s0)
    MEM_W(0X2EC8, ctx->r16) = ctx->r18;
    // 0x8000DC74: sw          $zero, 0x2EC0($s0)
    MEM_W(0X2EC0, ctx->r16) = 0;
    // 0x8000DC78: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000DC7C: jal         0x8000DB94
    // 0x8000DC80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000DB94(rdram, ctx);
        goto after_0;
    // 0x8000DC80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8000DC84: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x8000DC88: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x8000DC8C: bne         $s1, $s4, L_8000DC70
    if (ctx->r17 != ctx->r20) {
        // 0x8000DC90: addiu       $s2, $s2, 0x80
        ctx->r18 = ADD32(ctx->r18, 0X80);
            goto L_8000DC70;
    }
    // 0x8000DC90: addiu       $s2, $s2, 0x80
    ctx->r18 = ADD32(ctx->r18, 0X80);
    // 0x8000DC94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000DC98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000DC9C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DCA0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000DCA4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000DCA8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000DCAC: jr          $ra
    // 0x8000DCB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000DCB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_807B62DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B62DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B62E0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807B62E4: lw          $t6, -0x7250($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7250);
    // 0x807B62E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B62EC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807B62F0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807B62F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B62F8: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x807B62FC: bne         $at, $zero, L_807B630C
    if (ctx->r1 != 0) {
        // 0x807B6300: lw          $s2, 0x10($a0)
        ctx->r18 = MEM_W(ctx->r4, 0X10);
            goto L_807B630C;
    }
    // 0x807B6300: lw          $s2, 0x10($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X10);
    // 0x807B6304: jal         0x807B56F0
    // 0x807B6308: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_807B56F0(rdram, ctx);
        goto after_0;
    // 0x807B6308: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
L_807B630C:
    // 0x807B630C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B6310: addiu       $s1, $zero, 0x80
    ctx->r17 = ADD32(0, 0X80);
    // 0x807B6314: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_807B6318:
    // 0x807B6318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B631C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B6320: jal         0x8005C27C
    // 0x807B6324: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x807B6324: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_1:
    // 0x807B6328: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B632C: bnel        $s0, $s1, L_807B6318
    if (ctx->r16 != ctx->r17) {
        // 0x807B6330: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_807B6318;
    }
    goto skip_0;
    // 0x807B6330: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x807B6334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B6338: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B633C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807B6340: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807B6344: jr          $ra
    // 0x807B6348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B6348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805D2610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D2614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D2618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D261C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805D2620: jal         0x805D1D0C
    // 0x805D2624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_805D1D0C(rdram, ctx);
        goto after_0;
    // 0x805D2624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x805D2628: jal         0x805D2558
    // 0x805D262C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805D2558(rdram, ctx);
        goto after_1;
    // 0x805D262C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805D2630: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D2634: jal         0x805D2170
    // 0x805D2638: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_805D2170(rdram, ctx);
        goto after_2;
    // 0x805D2638: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x805D263C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D2640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D2644: jr          $ra
    // 0x805D2648: nop

    return;
    // 0x805D2648: nop

;}
RECOMP_FUNC void func_80038018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003801C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80038024: jal         0x80065954
    // 0x80038028: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80038028: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    after_0:
    // 0x8003802C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80038030: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038034: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80038038: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003803C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80038040: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80038044: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80038048: lui         $at, 0xC1B4
    ctx->r1 = S32(0XC1B4 << 16);
    // 0x8003804C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80038050: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038054: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80038058: lw          $t8, 0x1F4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1F4);
    // 0x8003805C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80038060: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80038064: swc1        $f6, 0x54($t8)
    MEM_W(0X54, ctx->r24) = ctx->f6.u32l;
    // 0x80038068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003806C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038070: jr          $ra
    // 0x80038074: nop

    return;
    // 0x80038074: nop

;}
RECOMP_FUNC void func_80052CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052CB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80052CBC: jr          $ra
    // 0x80052CC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80052CC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80052CC4: nop

    // 0x80052CC8: nop

    // 0x80052CCC: nop

;}
RECOMP_FUNC void func_80065FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065FD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065FD4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80065FD8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80065FDC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80065FE0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80065FE4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80065FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065FEC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80065FF0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80065FF4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80065FF8: jal         0x8007FFF0
    // 0x80065FFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8007FFF0(rdram, ctx);
        goto after_0;
    // 0x80065FFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80066000: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80066004: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80066008: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006600C: beql        $t6, $zero, L_80066028
    if (ctx->r14 == 0) {
        // 0x80066010: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80066028;
    }
    goto skip_0;
    // 0x80066010: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x80066014: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80066018: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8006601C: b           L_8006602C
    // 0x80066020: nop

        goto L_8006602C;
    // 0x80066020: nop

    // 0x80066024: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80066028:
    // 0x80066028: nop

L_8006602C:
    // 0x8006602C: beq         $t7, $zero, L_80066044
    if (ctx->r15 == 0) {
        // 0x80066030: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80066044;
    }
    // 0x80066030: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80066034: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80066038: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006603C: b           L_80066050
    // 0x80066040: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
        goto L_80066050;
    // 0x80066040: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_80066044:
    // 0x80066044: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066048: nop

    // 0x8006604C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_80066050:
    // 0x80066050: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80066054: jal         0x8007FE74
    // 0x80066058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8007FE74(rdram, ctx);
        goto after_1;
    // 0x80066058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8006605C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80066060: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80066064: jal         0x8007FE74
    // 0x80066068: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_8007FE74(rdram, ctx);
        goto after_2;
    // 0x80066068: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x8006606C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066074: jr          $ra
    // 0x80066078: nop

    return;
    // 0x80066078: nop

;}
RECOMP_FUNC void func_805D2200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D2204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D2208: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805D220C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805D2210: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x805D2214: jal         0x80067BBC
    // 0x805D2218: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805D2218: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x805D221C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x805D2220: jal         0x80067818
    // 0x805D2224: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805D2224: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805D2228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D222C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D2230: jr          $ra
    // 0x805D2234: nop

    return;
    // 0x805D2234: nop

;}
RECOMP_FUNC void func_806FE2E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FE2E0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806FE2E4: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(706, 0XDF0) << 16);
    // 0x806FE2E8: addiu       $t6, $t6, -0x1DB0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(706, 0XDF0));
    // 0x806FE2EC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806FE2F0: jr          $ra
    // 0x806FE2F4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806FE2F4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80428158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428158: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8042815C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80428160: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80428164: jal         0x80427DC8
    // 0x80428168: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80427DC8(rdram, ctx);
        goto after_0;
    // 0x80428168: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8042816C: bne         $v0, $zero, L_80428278
    if (ctx->r2 != 0) {
        // 0x80428170: nop
    
            goto L_80428278;
    }
    // 0x80428170: nop

    // 0x80428174: jal         0x8004700C
    // 0x80428178: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x80428178: nop

    after_1:
    // 0x8042817C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80428180: jal         0x80427AC0
    // 0x80428184: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80427AC0(rdram, ctx);
        goto after_2;
    // 0x80428184: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80428188: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8042818C: bnel        $v1, $zero, L_804281A8
    if (ctx->r3 != 0) {
        // 0x80428190: lw          $t6, 0x180($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X180);
            goto L_804281A8;
    }
    goto skip_0;
    // 0x80428190: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
    skip_0:
    // 0x80428194: jal         0x80427FB8
    // 0x80428198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427FB8(rdram, ctx);
        goto after_3;
    // 0x80428198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8042819C: b           L_80428284
    // 0x804281A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80428284;
    // 0x804281A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804281A4: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
L_804281A8:
    // 0x804281A8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1E94) << 16);
    // 0x804281AC: beq         $s0, $t6, L_804281C4
    if (ctx->r16 == ctx->r14) {
        // 0x804281B0: nop
    
            goto L_804281C4;
    }
    // 0x804281B0: nop

    // 0x804281B4: jal         0x80427FB8
    // 0x804281B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427FB8(rdram, ctx);
        goto after_4;
    // 0x804281B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804281BC: b           L_80428284
    // 0x804281C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80428284;
    // 0x804281C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804281C4:
    // 0x804281C4: lwc1        $f4, -0x682C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1E94));
    // 0x804281C8: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x804281CC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1E98) << 16);
    // 0x804281D0: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x804281D4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804281D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804281DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804281E0: bc1fl       L_80428200
    if (!c1cs) {
        // 0x804281E4: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_80428200;
    }
    goto skip_1;
    // 0x804281E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_1:
    // 0x804281E8: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804281EC: lwc1        $f10, -0x6828($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1E98));
    // 0x804281F0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804281F4: b           L_80428218
    // 0x804281F8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
        goto L_80428218;
    // 0x804281F8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x804281FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80428200:
    // 0x80428200: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80428204: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80428208: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    // 0x8042820C: jal         0x804288A0
    // 0x80428210: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_804288A0(rdram, ctx);
        goto after_5;
    // 0x80428210: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_5:
    // 0x80428214: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80428218:
    // 0x80428218: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1E9C) << 16);
    // 0x8042821C: lwc1        $f6, -0x6824($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1E9C));
    // 0x80428220: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80428224: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80428228: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x8042822C: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80428230: jal         0x80065954
    // 0x80428234: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80065954(rdram, ctx);
        goto after_6;
    // 0x80428234: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_6:
    // 0x80428238: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EA0) << 16);
    // 0x8042823C: lwc1        $f10, -0x6820($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EA0));
    // 0x80428240: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80428244: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80428248: nop

    // 0x8042824C: bc1f        L_80428260
    if (!c1cs) {
        // 0x80428250: nop
    
            goto L_80428260;
    }
    // 0x80428250: nop

    // 0x80428254: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80428258: nop

    // 0x8042825C: swc1        $f16, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f16.u32l;
L_80428260:
    // 0x80428260: jal         0x80427B1C
    // 0x80428264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427B1C(rdram, ctx);
        goto after_7;
    // 0x80428264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80428268: jal         0x80427C6C
    // 0x8042826C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427C6C(rdram, ctx);
        goto after_8;
    // 0x8042826C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80428270: b           L_80428284
    // 0x80428274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80428284;
    // 0x80428274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80428278:
    // 0x80428278: jal         0x80427F5C
    // 0x8042827C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427F5C(rdram, ctx);
        goto after_9;
    // 0x8042827C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80428280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80428284:
    // 0x80428284: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80428288: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8042828C: jr          $ra
    // 0x80428290: nop

    return;
    // 0x80428290: nop

;}
RECOMP_FUNC void func_806E77D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E77D4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x806E77D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E77DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E77E0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x806E77E4: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806E77E8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806E77EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E77F0: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x806E77F4: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806E77F8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(664, 0XEF4) << 16);
    // 0x806E77FC: lwc1        $f10, -0x7ECC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(664, 0XEF4));
    // 0x806E7800: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x806E7804: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x806E7808: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806E780C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806E7810: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806E7814: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806E7818: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x806E781C: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x806E7820: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x806E7824: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x806E7828: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x806E782C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x806E7830: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x806E7834: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806E7838: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E783C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x806E7840: lw          $t9, 0x28($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X28);
    // 0x806E7844: jalr        $t9
    // 0x806E7848: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806E7848: nop

    after_0:
    // 0x806E784C: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x806E7850: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806E7854: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806E7858: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806E785C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E7860: jal         0x8005FCA8
    // 0x806E7864: sh          $t8, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r24;
    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x806E7864: sh          $t8, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r24;
    after_1:
    // 0x806E7868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E786C: jal         0x806E7E4C
    // 0x806E7870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806E7E4C(rdram, ctx);
        goto after_2;
    // 0x806E7870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x806E7874: jal         0x80067E68
    // 0x806E7878: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x806E7878: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x806E787C: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806E7880: jal         0x80067818
    // 0x806E7884: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x806E7884: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x806E7888: jal         0x806E7370
    // 0x806E788C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E7370(rdram, ctx);
        goto after_5;
    // 0x806E788C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806E7890: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806E7894: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806E7898: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x806E789C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806E78A0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x806E78A4: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x806E78A8: addiu       $a0, $zero, 0x4027
    ctx->r4 = ADD32(0, 0X4027);
L_806E78AC:
    // 0x806E78AC: lw          $v0, 0x188($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X188);
    // 0x806E78B0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x806E78B4: beql        $v0, $zero, L_806E78D0
    if (ctx->r2 == 0) {
        // 0x806E78B8: lw          $v0, 0x18C($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X18C);
            goto L_806E78D0;
    }
    goto skip_0;
    // 0x806E78B8: lw          $v0, 0x18C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18C);
    skip_0:
    // 0x806E78BC: lhu         $t3, 0xC($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XC);
    // 0x806E78C0: bnel        $a0, $t3, L_806E78D0
    if (ctx->r4 != ctx->r11) {
        // 0x806E78C4: lw          $v0, 0x18C($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X18C);
            goto L_806E78D0;
    }
    goto skip_1;
    // 0x806E78C4: lw          $v0, 0x18C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18C);
    skip_1:
    // 0x806E78C8: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
    // 0x806E78CC: lw          $v0, 0x18C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18C);
L_806E78D0:
    // 0x806E78D0: beql        $v0, $zero, L_806E78EC
    if (ctx->r2 == 0) {
        // 0x806E78D4: lw          $v0, 0x190($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X190);
            goto L_806E78EC;
    }
    goto skip_2;
    // 0x806E78D4: lw          $v0, 0x190($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X190);
    skip_2:
    // 0x806E78D8: lhu         $t4, 0xC($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0XC);
    // 0x806E78DC: bnel        $a0, $t4, L_806E78EC
    if (ctx->r4 != ctx->r12) {
        // 0x806E78E0: lw          $v0, 0x190($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X190);
            goto L_806E78EC;
    }
    goto skip_3;
    // 0x806E78E0: lw          $v0, 0x190($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X190);
    skip_3:
    // 0x806E78E4: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
    // 0x806E78E8: lw          $v0, 0x190($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X190);
L_806E78EC:
    // 0x806E78EC: beql        $v0, $zero, L_806E7908
    if (ctx->r2 == 0) {
        // 0x806E78F0: lw          $v0, 0x194($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X194);
            goto L_806E7908;
    }
    goto skip_4;
    // 0x806E78F0: lw          $v0, 0x194($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X194);
    skip_4:
    // 0x806E78F4: lhu         $t5, 0xC($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XC);
    // 0x806E78F8: bnel        $a0, $t5, L_806E7908
    if (ctx->r4 != ctx->r13) {
        // 0x806E78FC: lw          $v0, 0x194($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X194);
            goto L_806E7908;
    }
    goto skip_5;
    // 0x806E78FC: lw          $v0, 0x194($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X194);
    skip_5:
    // 0x806E7900: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
    // 0x806E7904: lw          $v0, 0x194($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X194);
L_806E7908:
    // 0x806E7908: beq         $v0, $zero, L_806E7920
    if (ctx->r2 == 0) {
        // 0x806E790C: nop
    
            goto L_806E7920;
    }
    // 0x806E790C: nop

    // 0x806E7910: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7914: bne         $a0, $t6, L_806E7920
    if (ctx->r4 != ctx->r14) {
        // 0x806E7918: nop
    
            goto L_806E7920;
    }
    // 0x806E7918: nop

    // 0x806E791C: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
L_806E7920:
    // 0x806E7920: bne         $a1, $a2, L_806E78AC
    if (ctx->r5 != ctx->r6) {
        // 0x806E7924: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_806E78AC;
    }
    // 0x806E7924: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x806E7928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806E792C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E7930: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x806E7934: jr          $ra
    // 0x806E7938: nop

    return;
    // 0x806E7938: nop

;}
RECOMP_FUNC void func_8066DAF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066DAF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066DAFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066DB00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8066DB04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8066DB08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8066DB0C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8066DB10: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8066DB14: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x8066DB18: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8066DB1C: bnel        $t6, $at, L_8066DB38
    if (ctx->r14 != ctx->r1) {
        // 0x8066DB20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066DB38;
    }
    goto skip_0;
    // 0x8066DB20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066DB24: jal         0x8003C358
    // 0x8066DB28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_8003C358(rdram, ctx);
        goto after_0;
    // 0x8066DB28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x8066DB2C: jal         0x8066DA28
    // 0x8066DB30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8066DA28(rdram, ctx);
        goto after_1;
    // 0x8066DB30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8066DB34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066DB38:
    // 0x8066DB38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066DB3C: jr          $ra
    // 0x8066DB40: nop

    return;
    // 0x8066DB40: nop

;}
RECOMP_FUNC void func_8001ABE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ABE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001ABE4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001ABE8: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8001ABEC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001ABF0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001ABF4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001ABF8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001ABFC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001AC00: beq         $a0, $zero, L_8001ADA0
    if (ctx->r4 == 0) {
        // 0x8001AC04: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8001ADA0;
    }
    // 0x8001AC04: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001AC08: jal         0x8001AA08
    // 0x8001AC0C: nop

    func_8001AA08(rdram, ctx);
        goto after_0;
    // 0x8001AC0C: nop

    after_0:
    // 0x8001AC10: beq         $v0, $zero, L_8001ADA0
    if (ctx->r2 == 0) {
        // 0x8001AC14: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8001ADA0;
    }
    // 0x8001AC14: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001AC18: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x8001AC1C: addiu       $s3, $s3, 0x4D10
    ctx->r19 = ADD32(ctx->r19, 0X4D10);
    // 0x8001AC20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001AC24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001AC28: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
L_8001AC2C:
    // 0x8001AC2C: lh          $t6, 0x0($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X0);
    // 0x8001AC30: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x8001AC34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001AC38: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001AC3C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001AC40: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001AC44: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8001AC48: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x8001AC4C: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x8001AC50: lw          $v0, 0x2A64($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2A64);
    // 0x8001AC54: beql        $v0, $zero, L_8001AC80
    if (ctx->r2 == 0) {
        // 0x8001AC58: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001AC80;
    }
    goto skip_0;
    // 0x8001AC58: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8001AC5C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8001AC60: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8001AC64: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001AC68: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x8001AC6C: srl         $a2, $a2, 31
    ctx->r6 = S32(U32(ctx->r6) >> 31);
    // 0x8001AC70: jal         0x8001AF28
    // 0x8001AC74: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    func_8001AF28(rdram, ctx);
        goto after_1;
    // 0x8001AC74: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_1:
    // 0x8001AC78: andi        $s2, $v0, 0xFFFF
    ctx->r18 = ctx->r2 & 0XFFFF;
    // 0x8001AC7C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001AC80:
    // 0x8001AC80: bne         $s0, $s4, L_8001AC2C
    if (ctx->r16 != ctx->r20) {
        // 0x8001AC84: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8001AC2C;
    }
    // 0x8001AC84: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8001AC88: lhu         $t1, 0x20($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X20);
    // 0x8001AC8C: andi        $t0, $s2, 0xFFFF
    ctx->r8 = ctx->r18 & 0XFFFF;
    // 0x8001AC90: sh          $s2, 0x22($s5)
    MEM_H(0X22, ctx->r21) = ctx->r18;
    // 0x8001AC94: beql        $t0, $t1, L_8001ACBC
    if (ctx->r8 == ctx->r9) {
        // 0x8001AC98: lwc1        $f4, 0xC($s5)
        ctx->f4.u32l = MEM_W(ctx->r21, 0XC);
            goto L_8001ACBC;
    }
    goto skip_1;
    // 0x8001AC98: lwc1        $f4, 0xC($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0XC);
    skip_1:
    // 0x8001AC9C: jal         0x8001AB9C
    // 0x8001ACA0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8001AB9C(rdram, ctx);
        goto after_2;
    // 0x8001ACA0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x8001ACA4: beq         $v0, $zero, L_8001ACB8
    if (ctx->r2 == 0) {
        // 0x8001ACA8: addiu       $t2, $zero, 0xB
        ctx->r10 = ADD32(0, 0XB);
            goto L_8001ACB8;
    }
    // 0x8001ACA8: addiu       $t2, $zero, 0xB
    ctx->r10 = ADD32(0, 0XB);
    // 0x8001ACAC: addiu       $t3, $s5, 0x20
    ctx->r11 = ADD32(ctx->r21, 0X20);
    // 0x8001ACB0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8001ACB4: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
L_8001ACB8:
    // 0x8001ACB8: lwc1        $f4, 0xC($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0XC);
L_8001ACBC:
    // 0x8001ACBC: lwc1        $f6, 0x8($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8001ACC0: jal         0x8001AB70
    // 0x8001ACC4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_8001AB70(rdram, ctx);
        goto after_3;
    // 0x8001ACC4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_3:
    // 0x8001ACC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001ACCC: ldc1        $f8, -0x630($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X630);
    // 0x8001ACD0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8001ACD4: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8001ACD8: nop

    // 0x8001ACDC: bc1fl       L_8001AD0C
    if (!c1cs) {
        // 0x8001ACE0: lwc1        $f16, 0x14($s5)
        ctx->f16.u32l = MEM_W(ctx->r21, 0X14);
            goto L_8001AD0C;
    }
    goto skip_2;
    // 0x8001ACE0: lwc1        $f16, 0x14($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X14);
    skip_2:
    // 0x8001ACE4: jal         0x8001AB9C
    // 0x8001ACE8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8001AB9C(rdram, ctx);
        goto after_4;
    // 0x8001ACE8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x8001ACEC: beq         $v0, $zero, L_8001AD08
    if (ctx->r2 == 0) {
        // 0x8001ACF0: addiu       $t4, $zero, 0xD
        ctx->r12 = ADD32(0, 0XD);
            goto L_8001AD08;
    }
    // 0x8001ACF0: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x8001ACF4: addiu       $t5, $s5, 0x8
    ctx->r13 = ADD32(ctx->r21, 0X8);
    // 0x8001ACF8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8001ACFC: sw          $t5, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r13;
    // 0x8001AD00: jal         0x8001BD40
    // 0x8001AD04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001BD40(rdram, ctx);
        goto after_5;
    // 0x8001AD04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
L_8001AD08:
    // 0x8001AD08: lwc1        $f16, 0x14($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X14);
L_8001AD0C:
    // 0x8001AD0C: lwc1        $f18, 0x18($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X18);
    // 0x8001AD10: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8001AD14: nop

    // 0x8001AD18: bc1tl       L_8001AD48
    if (c1cs) {
        // 0x8001AD1C: lhu         $t8, 0x32($s5)
        ctx->r24 = MEM_HU(ctx->r21, 0X32);
            goto L_8001AD48;
    }
    goto skip_3;
    // 0x8001AD1C: lhu         $t8, 0x32($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X32);
    skip_3:
    // 0x8001AD20: jal         0x8001AB9C
    // 0x8001AD24: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8001AB9C(rdram, ctx);
        goto after_6;
    // 0x8001AD24: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x8001AD28: beq         $v0, $zero, L_8001AD44
    if (ctx->r2 == 0) {
        // 0x8001AD2C: addiu       $t6, $zero, 0xF
        ctx->r14 = ADD32(0, 0XF);
            goto L_8001AD44;
    }
    // 0x8001AD2C: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8001AD30: addiu       $t7, $s5, 0x14
    ctx->r15 = ADD32(ctx->r21, 0X14);
    // 0x8001AD34: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001AD38: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x8001AD3C: jal         0x8001BD40
    // 0x8001AD40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001BD40(rdram, ctx);
        goto after_7;
    // 0x8001AD40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
L_8001AD44:
    // 0x8001AD44: lhu         $t8, 0x32($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X32);
L_8001AD48:
    // 0x8001AD48: lhu         $t9, 0x30($s5)
    ctx->r25 = MEM_HU(ctx->r21, 0X30);
    // 0x8001AD4C: bne         $t8, $t9, L_8001AD6C
    if (ctx->r24 != ctx->r25) {
        // 0x8001AD50: nop
    
            goto L_8001AD6C;
    }
    // 0x8001AD50: nop

    // 0x8001AD54: lwc1        $f4, 0x34($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X34);
    // 0x8001AD58: lwc1        $f6, 0x38($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X38);
    // 0x8001AD5C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8001AD60: nop

    // 0x8001AD64: bc1tl       L_8001ADA4
    if (c1cs) {
        // 0x8001AD68: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001ADA4;
    }
    goto skip_4;
    // 0x8001AD68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
L_8001AD6C:
    // 0x8001AD6C: jal         0x8001AB9C
    // 0x8001AD70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8001AB9C(rdram, ctx);
        goto after_8;
    // 0x8001AD70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x8001AD74: beq         $v0, $zero, L_8001ADA0
    if (ctx->r2 == 0) {
        // 0x8001AD78: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8001ADA0;
    }
    // 0x8001AD78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8001AD7C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8001AD80: addiu       $t1, $s5, 0x30
    ctx->r9 = ADD32(ctx->r21, 0X30);
    // 0x8001AD84: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8001AD88: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x8001AD8C: jal         0x8001BDB4
    // 0x8001AD90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001BDB4(rdram, ctx);
        goto after_9;
    // 0x8001AD90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x8001AD94: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8001AD98: lhu         $t2, 0x0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X0);
    // 0x8001AD9C: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
L_8001ADA0:
    // 0x8001ADA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001ADA4:
    // 0x8001ADA4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001ADA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001ADAC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001ADB0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001ADB4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001ADB8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001ADBC: jr          $ra
    // 0x8001ADC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001ADC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80052CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052CB0: jr          $ra
    // 0x80052CB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80052CB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8078C7A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078C7A4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8078C7A8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8078C7AC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8078C7B0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8078C7B4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8078C7B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8078C7BC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8078C7C0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8078C7C4: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(796, 0X1B24) << 16);
    // 0x8078C7C8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8078C7CC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8078C7D0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8078C7D4: lw          $t1, -0x334C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(796, 0X1B24));
    // 0x8078C7D8: jr          $ra
    // 0x8078C7DC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8078C7DC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80445A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445A18: addiu       $a0, $zero, 0x24E
    ctx->r4 = ADD32(0, 0X24E);
    // 0x80445A1C: jal         0x80067818
    // 0x80445A20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x80445A20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80445A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445A2C: jr          $ra
    // 0x80445A30: nop

    return;
    // 0x80445A30: nop

;}
RECOMP_FUNC void func_8004D618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004D61C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D620: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8004D624: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8004D628: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8004D62C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8004D630: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004D634: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004D638: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004D63C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8004D640: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8004D644: beql        $v1, $zero, L_8004D68C
    if (ctx->r3 == 0) {
        // 0x8004D648: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004D68C;
    }
    goto skip_0;
    // 0x8004D648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004D64C: beql        $v1, $at, L_8004D68C
    if (ctx->r3 == ctx->r1) {
        // 0x8004D650: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004D68C;
    }
    goto skip_1;
    // 0x8004D650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004D654: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8004D658: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004D65C: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x8004D660: beq         $v1, $at, L_8004D688
    if (ctx->r3 == ctx->r1) {
        // 0x8004D664: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004D688;
    }
    // 0x8004D664: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004D668: beql        $v1, $at, L_8004D68C
    if (ctx->r3 == ctx->r1) {
        // 0x8004D66C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004D68C;
    }
    goto skip_2;
    // 0x8004D66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8004D670: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004D674: jalr        $a2
    // 0x8004D678: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r6)(rdram, ctx);
        goto after_0;
    // 0x8004D678: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004D67C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004D680: jal         0x8004D3C4
    // 0x8004D684: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8004D3C4(rdram, ctx);
        goto after_1;
    // 0x8004D684: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_8004D688:
    // 0x8004D688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004D68C:
    // 0x8004D68C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004D690: jr          $ra
    // 0x8004D694: nop

    return;
    // 0x8004D694: nop

;}
RECOMP_FUNC void func_805CC598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CC598: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805CC59C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805CC5A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805CC5A4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805CC5A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805CC5AC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805CC5B0: jal         0x80047090
    // 0x805CC5B4: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805CC5B4: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    after_0:
    // 0x805CC5B8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x805CC5BC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x805CC5C0: beq         $v0, $at, L_805CC62C
    if (ctx->r2 == ctx->r1) {
        // 0x805CC5C4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_805CC62C;
    }
    // 0x805CC5C4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805CC5C8: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x805CC5CC: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x805CC5D0: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(456, 0X4A0) << 16);
    // 0x805CC5D4: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x805CC5D8: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x805CC5DC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x805CC5E0: or          $a1, $t7, $v1
    ctx->r5 = ctx->r15 | ctx->r3;
    // 0x805CC5E4: addiu       $a0, $a0, -0x3900
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(456, 0X4A0));
    // 0x805CC5E8: jal         0x80046804
    // 0x805CC5EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x805CC5EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x805CC5F0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x805CC5F4: beq         $v0, $zero, L_805CC62C
    if (ctx->r2 == 0) {
        // 0x805CC5F8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805CC62C;
    }
    // 0x805CC5F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805CC5FC: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x805CC600: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x805CC604: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x805CC608: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x805CC60C: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x805CC610: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
    // 0x805CC614: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x805CC618: sw          $t8, 0x1E4($v0)
    MEM_W(0X1E4, ctx->r2) = ctx->r24;
    // 0x805CC61C: jal         0x80044194
    // 0x805CC620: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805CC620: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x805CC624: b           L_805CC630
    // 0x805CC628: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_805CC630;
    // 0x805CC628: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_805CC62C:
    // 0x805CC62C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805CC630:
    // 0x805CC630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805CC634: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805CC638: jr          $ra
    // 0x805CC63C: nop

    return;
    // 0x805CC63C: nop

;}
RECOMP_FUNC void func_806FDF20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FDF20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806FDF24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FDF28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806FDF2C: jal         0x8004700C
    // 0x806FDF30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806FDF30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806FDF34: beql        $v0, $zero, L_806FDF84
    if (ctx->r2 == 0) {
        // 0x806FDF38: sw          $zero, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = 0;
            goto L_806FDF84;
    }
    goto skip_0;
    // 0x806FDF38: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    skip_0:
    // 0x806FDF3C: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806FDF40: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806FDF44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806FDF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDF4C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806FDF50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDF54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806FDF58: bc1f        L_806FDF78
    if (!c1cs) {
        // 0x806FDF5C: nop
    
            goto L_806FDF78;
    }
    // 0x806FDF5C: nop

    // 0x806FDF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDF64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDF68: jal         0x806FE468
    // 0x806FDF6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_806FE468(rdram, ctx);
        goto after_1;
    // 0x806FDF6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x806FDF70: b           L_806FDF84
    // 0x806FDF74: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
        goto L_806FDF84;
    // 0x806FDF74: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_806FDF78:
    // 0x806FDF78: jal         0x806FE468
    // 0x806FDF7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806FE468(rdram, ctx);
        goto after_2;
    // 0x806FDF7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x806FDF80: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_806FDF84:
    // 0x806FDF84: jal         0x806FDA5C
    // 0x806FDF88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FDA5C(rdram, ctx);
        goto after_3;
    // 0x806FDF88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806FDF8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806FDF90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806FDF94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806FDF98: jr          $ra
    // 0x806FDF9C: nop

    return;
    // 0x806FDF9C: nop

;}
RECOMP_FUNC void pad_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FAE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007FAE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FAE8: jal         0x80084820
    // 0x8007FAEC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x8007FAEC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x8007FAF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FAF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007FAF8: jr          $ra
    // 0x8007FAFC: nop

    return;
    // 0x8007FAFC: nop

;}
RECOMP_FUNC void func_805563A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805563A0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x805563A4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x805563A8: mtc1        $a2, $f28
    ctx->f28.u32l = ctx->r6;
    // 0x805563AC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x805563B0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x805563B4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x805563B8: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x805563BC: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x805563C0: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x805563C4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x805563C8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x805563CC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x805563D0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x805563D4: jal         0x8004700C
    // 0x805563D8: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805563D8: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    after_0:
    // 0x805563DC: beq         $v0, $zero, L_805564CC
    if (ctx->r2 == 0) {
        // 0x805563E0: sw          $v0, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r2;
            goto L_805564CC;
    }
    // 0x805563E0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x805563E4: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x805563E8: lwc1        $f10, 0x84($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X84);
    // 0x805563EC: addiu       $s0, $s2, 0x2DC
    ctx->r16 = ADD32(ctx->r18, 0X2DC);
    // 0x805563F0: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x805563F4: addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
    // 0x805563F8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x805563FC: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80556400: lw          $a0, 0x70($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X70);
    // 0x80556404: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x80556408: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8055640C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80556410: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x80556414: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80556418: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8055641C: lh          $t0, 0xC($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XC);
    // 0x80556420: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80556424: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80556428: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8055642C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80556430: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80556434: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80556438: add.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8055643C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80556440: nop

    // 0x80556444: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80556448: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8055644C: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80556450: add.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80556454: mul.s       $f26, $f2, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80556458: add.s       $f30, $f12, $f28
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f30.fl = ctx->f12.fl + ctx->f28.fl;
L_8055645C:
    // 0x8055645C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80556460: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80556464: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x80556468: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8055646C: lwc1        $f12, 0x88($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80556470: sub.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80556474: jal         0x80065954
    // 0x80556478: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80556478: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8055647C: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x80556480: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80556484: bc1fl       L_805564C4
    if (!c1cs) {
        // 0x80556488: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_805564C4;
    }
    goto skip_0;
    // 0x80556488: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8055648C: jal         0x80065954
    // 0x80556490: add.s       $f20, $f26, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f26.fl + ctx->f28.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80556490: add.s       $f20, $f26, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f26.fl + ctx->f28.fl;
    after_2:
    // 0x80556494: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80556498: nop

    // 0x8055649C: bc1fl       L_805564C4
    if (!c1cs) {
        // 0x805564A0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_805564C4;
    }
    goto skip_1;
    // 0x805564A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x805564A4: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x805564A8: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x805564AC: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x805564B0: jal         0x8002F6E4
    // 0x805564B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_3;
    // 0x805564B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x805564B8: b           L_805564D0
    // 0x805564BC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_805564D0;
    // 0x805564BC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x805564C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_805564C4:
    // 0x805564C4: bne         $s1, $s2, L_8055645C
    if (ctx->r17 != ctx->r18) {
        // 0x805564C8: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8055645C;
    }
    // 0x805564C8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_805564CC:
    // 0x805564CC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_805564D0:
    // 0x805564D0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805564D4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805564D8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x805564DC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x805564E0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x805564E4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x805564E8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x805564EC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x805564F0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x805564F4: jr          $ra
    // 0x805564F8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x805564F8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_807A9B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A9B40: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(850, 0X10) << 16);
    // 0x807A9B44: addiu       $v0, $v0, -0x64B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(850, 0X10));
    // 0x807A9B48: jr          $ra
    // 0x807A9B4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807A9B4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8003E658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E658: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003E65C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E660: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003E664: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003E668: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8003E66C: lbu         $v1, 0x12C8($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X12C8);
    // 0x8003E670: lhu         $t0, 0x12BE($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X12BE);
    // 0x8003E674: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8003E678: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8003E67C: sb          $t6, 0x12C8($a0)
    MEM_B(0X12C8, ctx->r4) = ctx->r14;
    // 0x8003E680: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8003E684: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003E688: addu        $a1, $t0, $v1
    ctx->r5 = ADD32(ctx->r8, ctx->r3);
    // 0x8003E68C: andi        $a1, $a1, 0x7
    ctx->r5 = ctx->r5 & 0X7;
    // 0x8003E690: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8003E694: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003E698: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    // 0x8003E69C: jalr        $t9
    // 0x8003E6A0: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8003E6A0: sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8003E6A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003E6A8: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x8003E6AC: jal         0x8003E590
    // 0x8003E6B0: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
    func_8003E590(rdram, ctx);
        goto after_1;
    // 0x8003E6B0: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
    after_1:
    // 0x8003E6B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E6B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003E6BC: jr          $ra
    // 0x8003E6C0: nop

    return;
    // 0x8003E6C0: nop

;}
RECOMP_FUNC void func_806D8FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D8FD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D8FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D8FD8: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x806D8FDC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806D8FE0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806D8FE4: beq         $a1, $at, L_806D9000
    if (ctx->r5 == ctx->r1) {
        // 0x806D8FE8: addiu       $a0, $zero, 0x26
        ctx->r4 = ADD32(0, 0X26);
            goto L_806D9000;
    }
    // 0x806D8FE8: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x806D8FEC: jal         0x80067878
    // 0x806D8FF0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x806D8FF0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x806D8FF4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806D8FF8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x806D8FFC: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_806D9000:
    // 0x806D9000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D9004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D9008: jr          $ra
    // 0x806D900C: nop

    return;
    // 0x806D900C: nop

;}
RECOMP_FUNC void func_806F7224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F7228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F722C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F7230: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806F7234: jal         0x806F6E20
    // 0x806F7238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806F6E20(rdram, ctx);
        goto after_0;
    // 0x806F7238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x806F723C: jal         0x806F6F08
    // 0x806F7240: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806F6F08(rdram, ctx);
        goto after_1;
    // 0x806F7240: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806F7244: jal         0x806F6F64
    // 0x806F7248: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806F6F64(rdram, ctx);
        goto after_2;
    // 0x806F7248: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806F724C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F7250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F7254: jr          $ra
    // 0x806F7258: nop

    return;
    // 0x806F7258: nop

;}
RECOMP_FUNC void func_8046B1CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046B1CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046B1D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046B1D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046B1D8: jal         0x80045A34
    // 0x8046B1DC: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8046B1DC: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    after_0:
    // 0x8046B1E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046B1E4: bne         $v0, $zero, L_8046B1F4
    if (ctx->r2 != 0) {
        // 0x8046B1E8: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8046B1F4;
    }
    // 0x8046B1E8: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8046B1EC: b           L_8046B200
    // 0x8046B1F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8046B200;
    // 0x8046B1F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8046B1F4:
    // 0x8046B1F4: jal         0x8046B134
    // 0x8046B1F8: nop

    func_8046B134(rdram, ctx);
        goto after_1;
    // 0x8046B1F8: nop

    after_1:
    // 0x8046B1FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8046B200:
    // 0x8046B200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046B204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046B208: jr          $ra
    // 0x8046B20C: nop

    return;
    // 0x8046B20C: nop

;}
RECOMP_FUNC void func_805A94E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A94E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805A94EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A94F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805A94F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805A94F8: jal         0x8004700C
    // 0x805A94FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805A94FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x805A9500: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x805A9504: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x805A9508: jal         0x805A9468
    // 0x805A950C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A9468(rdram, ctx);
        goto after_1;
    // 0x805A950C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A9510: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A9514: jal         0x805A9314
    // 0x805A9518: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_805A9314(rdram, ctx);
        goto after_2;
    // 0x805A9518: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x805A951C: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x805A9520: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x805A9524: beql        $at, $zero, L_805A96BC
    if (ctx->r1 == 0) {
        // 0x805A9528: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_805A96BC;
    }
    goto skip_0;
    // 0x805A9528: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x805A952C: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x805A9530: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x805A9534: addiu       $a0, $s1, 0x50
    ctx->r4 = ADD32(ctx->r17, 0X50);
    // 0x805A9538: beq         $t7, $zero, L_805A9564
    if (ctx->r15 == 0) {
        // 0x805A953C: lui         $a2, 0x4000
        ctx->r6 = S32(0X4000 << 16);
            goto L_805A9564;
    }
    // 0x805A953C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x805A9540: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x805A9544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A9548: nop

    // 0x805A954C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805A9550: nop

    // 0x805A9554: bc1fl       L_805A96BC
    if (!c1cs) {
        // 0x805A9558: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_805A96BC;
    }
    goto skip_1;
    // 0x805A9558: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x805A955C: b           L_805A96B8
    // 0x805A9560: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
        goto L_805A96B8;
    // 0x805A9560: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_805A9564:
    // 0x805A9564: jal         0x80067170
    // 0x805A9568: lw          $a1, 0x4C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4C);
    func_80067170(rdram, ctx);
        goto after_3;
    // 0x805A9568: lw          $a1, 0x4C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4C);
    after_3:
    // 0x805A956C: jal         0x805A925C
    // 0x805A9570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805A925C(rdram, ctx);
        goto after_4;
    // 0x805A9570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x805A9574: bne         $v0, $zero, L_805A9594
    if (ctx->r2 != 0) {
        // 0x805A9578: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_805A9594;
    }
    // 0x805A9578: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805A957C: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x805A9580: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x805A9584: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
    // 0x805A9588: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x805A958C: b           L_805A96B8
    // 0x805A9590: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
        goto L_805A96B8;
    // 0x805A9590: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
L_805A9594:
    // 0x805A9594: bnel        $v0, $at, L_805A96BC
    if (ctx->r2 != ctx->r1) {
        // 0x805A9598: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_805A96BC;
    }
    goto skip_2;
    // 0x805A9598: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_2:
    // 0x805A959C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x805A95A0: beql        $v0, $zero, L_805A9634
    if (ctx->r2 == 0) {
        // 0x805A95A4: lwc1        $f8, 0x3C($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_805A9634;
    }
    goto skip_3;
    // 0x805A95A4: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    skip_3:
    // 0x805A95A8: lwc1        $f2, 0x84($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X84);
    // 0x805A95AC: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x805A95B0: lwc1        $f16, 0x88($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X88);
    // 0x805A95B4: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x805A95B8: nop

    // 0x805A95BC: bc1fl       L_805A9618
    if (!c1cs) {
        // 0x805A95C0: lwc1        $f10, 0x3C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_805A9618;
    }
    goto skip_4;
    // 0x805A95C0: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    skip_4:
    // 0x805A95C4: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x805A95C8: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x805A95CC: nop

    // 0x805A95D0: bc1fl       L_805A9618
    if (!c1cs) {
        // 0x805A95D4: lwc1        $f10, 0x3C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_805A9618;
    }
    goto skip_5;
    // 0x805A95D4: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    skip_5:
    // 0x805A95D8: lwc1        $f18, 0x5C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x805A95DC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x805A95E0: nop

    // 0x805A95E4: bc1fl       L_805A9618
    if (!c1cs) {
        // 0x805A95E8: lwc1        $f10, 0x3C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_805A9618;
    }
    goto skip_6;
    // 0x805A95E8: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    skip_6:
    // 0x805A95EC: lwc1        $f4, 0x60($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X60);
    // 0x805A95F0: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x805A95F4: nop

    // 0x805A95F8: bc1fl       L_805A9618
    if (!c1cs) {
        // 0x805A95FC: lwc1        $f10, 0x3C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_805A9618;
    }
    goto skip_7;
    // 0x805A95FC: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    skip_7:
    // 0x805A9600: lwc1        $f6, 0x84($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X84);
    // 0x805A9604: lwc1        $f8, 0x88($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X88);
    // 0x805A9608: sub.s       $f12, $f2, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x805A960C: b           L_805A9648
    // 0x805A9610: sub.s       $f14, $f16, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f8.fl;
        goto L_805A9648;
    // 0x805A9610: sub.s       $f14, $f16, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x805A9614: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
L_805A9618:
    // 0x805A9618: lwc1        $f18, 0x84($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X84);
    // 0x805A961C: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805A9620: lwc1        $f6, 0x88($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X88);
    // 0x805A9624: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x805A9628: b           L_805A9648
    // 0x805A962C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
        goto L_805A9648;
    // 0x805A962C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805A9630: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
L_805A9634:
    // 0x805A9634: lwc1        $f10, 0x84($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X84);
    // 0x805A9638: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805A963C: lwc1        $f4, 0x88($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X88);
    // 0x805A9640: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805A9644: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
L_805A9648:
    // 0x805A9648: jal         0x80067114
    // 0x805A964C: nop

    func_80067114(rdram, ctx);
        goto after_5;
    // 0x805A964C: nop

    after_5:
    // 0x805A9650: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x805A9654: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A9658: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x805A965C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805A9660: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x805A9664: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x805A9668: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x805A966C: nop

    // 0x805A9670: bc1fl       L_805A9690
    if (!c1cs) {
        // 0x805A9674: swc1        $f2, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->f2.u32l;
            goto L_805A9690;
    }
    goto skip_8;
    // 0x805A9674: swc1        $f2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f2.u32l;
    skip_8:
    // 0x805A9678: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A967C: nop

    // 0x805A9680: add.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x805A9684: b           L_805A9690
    // 0x805A9688: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
        goto L_805A9690;
    // 0x805A9688: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x805A968C: swc1        $f2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f2.u32l;
L_805A9690:
    // 0x805A9690: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805A9694: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A9698: nop

    // 0x805A969C: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x805A96A0: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x805A96A4: jal         0x80067BBC
    // 0x805A96A8: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x805A96A8: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    after_6:
    // 0x805A96AC: addiu       $a0, $zero, 0x27B
    ctx->r4 = ADD32(0, 0X27B);
    // 0x805A96B0: jal         0x80067818
    // 0x805A96B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x805A96B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
L_805A96B8:
    // 0x805A96B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_805A96BC:
    // 0x805A96BC: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x805A96C0: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x805A96C4: nop

    // 0x805A96C8: bc1tl       L_805A9708
    if (c1cs) {
        // 0x805A96CC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_805A9708;
    }
    goto skip_9;
    // 0x805A96CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_9:
    // 0x805A96D0: jal         0x80066DE4
    // 0x805A96D4: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x805A96D4: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    after_8:
    // 0x805A96D8: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x805A96DC: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x805A96E0: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    // 0x805A96E4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x805A96E8: jal         0x80066E88
    // 0x805A96EC: swc1        $f4, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f4.u32l;
    func_80066E88(rdram, ctx);
        goto after_9;
    // 0x805A96EC: swc1        $f4, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f4.u32l;
    after_9:
    // 0x805A96F0: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x805A96F4: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x805A96F8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805A96FC: b           L_805A9728
    // 0x805A9700: swc1        $f10, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f10.u32l;
        goto L_805A9728;
    // 0x805A9700: swc1        $f10, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f10.u32l;
    // 0x805A9704: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_805A9708:
    // 0x805A9708: nop

    // 0x805A970C: swc1        $f0, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f0.u32l;
    // 0x805A9710: swc1        $f0, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f0.u32l;
    // 0x805A9714: lw          $t1, 0x44($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X44);
    // 0x805A9718: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x805A971C: bnel        $at, $zero, L_805A972C
    if (ctx->r1 != 0) {
        // 0x805A9720: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A972C;
    }
    goto skip_10;
    // 0x805A9720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x805A9724: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
L_805A9728:
    // 0x805A9728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A972C:
    // 0x805A972C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805A9730: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805A9734: jr          $ra
    // 0x805A9738: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x805A9738: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8066B608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B608: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8066B60C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8066B610: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(514, 0X2700) << 16);
    // 0x8066B614: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x8066B618: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x8066B61C: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8066B620: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8066B624: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8066B628: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8066B62C: lwc1        $f24, -0x2CA0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(514, 0X2700));
    // 0x8066B630: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8066B634: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x8066B638: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8066B63C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8066B640: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8066B644: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(514, 0X2704) << 16);
    // 0x8066B648: lui         $s4, 0x4556
    ctx->r20 = S32(0X4556 << 16);
    // 0x8066B64C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8066B650: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8066B654: lw          $s6, 0x1F4($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B658: ori         $s4, $s4, 0x2000
    ctx->r20 = ctx->r20 | 0X2000;
    // 0x8066B65C: lwc1        $f22, -0x2C9C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(514, 0X2704));
    // 0x8066B660: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8066B664: addiu       $s5, $zero, 0x3FF
    ctx->r21 = ADD32(0, 0X3FF);
L_8066B668:
    // 0x8066B668: jal         0x80047090
    // 0x8066B66C: addiu       $a0, $zero, 0x4556
    ctx->r4 = ADD32(0, 0X4556);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8066B66C: addiu       $a0, $zero, 0x4556
    ctx->r4 = ADD32(0, 0X4556);
    after_0:
    // 0x8066B670: beq         $s5, $v0, L_8066B788
    if (ctx->r21 == ctx->r2) {
        // 0x8066B674: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_8066B788;
    }
    // 0x8066B674: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x8066B678: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8066B67C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8066B680: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8066B684: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x8066B688: addu        $s1, $s6, $t6
    ctx->r17 = ADD32(ctx->r22, ctx->r14);
    // 0x8066B68C: jal         0x8004613C
    // 0x8066B690: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8066B690: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x8066B694: beq         $v0, $zero, L_8066B6E0
    if (ctx->r2 == 0) {
        // 0x8066B698: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8066B6E0;
    }
    // 0x8066B698: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8066B69C: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x8066B6A0: andi        $t8, $s3, 0x3FF
    ctx->r24 = ctx->r19 & 0X3FF;
    // 0x8066B6A4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8066B6A8: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x8066B6AC: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8066B6B0: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x8066B6B4: jal         0x80047F9C
    // 0x8066B6B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8066B6B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8066B6BC: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x8066B6C0: jal         0x8066B57C
    // 0x8066B6C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B57C(rdram, ctx);
        goto after_3;
    // 0x8066B6C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8066B6C8: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x8066B6CC: nop

    // 0x8066B6D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8066B6D4: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8066B6D8: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8066B6DC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_8066B6E0:
    // 0x8066B6E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8066B6E4: slti        $at, $s2, 0x6
    ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
    // 0x8066B6E8: bne         $at, $zero, L_8066B668
    if (ctx->r1 != 0) {
        // 0x8066B6EC: sw          $s0, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->r16;
            goto L_8066B668;
    }
    // 0x8066B6EC: sw          $s0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r16;
    // 0x8066B6F0: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x8066B6F4: sw          $zero, 0x30($s6)
    MEM_W(0X30, ctx->r22) = 0;
    // 0x8066B6F8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x8066B6FC: addiu       $s1, $s6, 0x8
    ctx->r17 = ADD32(ctx->r22, 0X8);
    // 0x8066B700: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8066B704:
    // 0x8066B704: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8066B708: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
    // 0x8066B70C: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
    // 0x8066B710: sw          $zero, 0x38($s1)
    MEM_W(0X38, ctx->r17) = 0;
    // 0x8066B714: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8066B718: bne         $s2, $v0, L_8066B704
    if (ctx->r18 != ctx->r2) {
        // 0x8066B71C: sw          $zero, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = 0;
            goto L_8066B704;
    }
    // 0x8066B71C: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x8066B720: jal         0x80047090
    // 0x8066B724: addiu       $a0, $zero, 0x455F
    ctx->r4 = ADD32(0, 0X455F);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x8066B724: addiu       $a0, $zero, 0x455F
    ctx->r4 = ADD32(0, 0X455F);
    after_4:
    // 0x8066B728: beq         $s5, $v0, L_8066B788
    if (ctx->r21 == ctx->r2) {
        // 0x8066B72C: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_8066B788;
    }
    // 0x8066B72C: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x8066B730: lui         $a0, 0x455F
    ctx->r4 = S32(0X455F << 16);
    // 0x8066B734: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8066B738: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8066B73C: lui         $a3, 0xBB83
    ctx->r7 = S32(0XBB83 << 16);
    // 0x8066B740: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8066B744: jal         0x8004613C
    // 0x8066B748: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x8066B748: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    after_5:
    // 0x8066B74C: beq         $v0, $zero, L_8066B788
    if (ctx->r2 == 0) {
        // 0x8066B750: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8066B788;
    }
    // 0x8066B750: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8066B754: lhu         $t4, 0xE($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0XE);
    // 0x8066B758: andi        $t3, $s3, 0x3FF
    ctx->r11 = ctx->r19 & 0X3FF;
    // 0x8066B75C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8066B760: andi        $t5, $t4, 0xFC00
    ctx->r13 = ctx->r12 & 0XFC00;
    // 0x8066B764: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x8066B768: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
    // 0x8066B76C: jal         0x80047F9C
    // 0x8066B770: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x8066B770: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8066B774: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x8066B778: jal         0x8066B5C8
    // 0x8066B77C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B5C8(rdram, ctx);
        goto after_7;
    // 0x8066B77C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8066B780: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x8066B784: sw          $zero, 0xC($s6)
    MEM_W(0XC, ctx->r22) = 0;
L_8066B788:
    // 0x8066B788: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8066B78C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8066B790: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8066B794: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8066B798: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8066B79C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8066B7A0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8066B7A4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8066B7A8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8066B7AC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8066B7B0: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x8066B7B4: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x8066B7B8: jr          $ra
    // 0x8066B7BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8066B7BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80436BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436BBC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80436BC0: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x80436BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80436BC8: beq         $t6, $zero, L_80436BD8
    if (ctx->r14 == 0) {
        // 0x80436BCC: nop
    
            goto L_80436BD8;
    }
    // 0x80436BCC: nop

    // 0x80436BD0: jr          $ra
    // 0x80436BD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80436BD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80436BD8:
    // 0x80436BD8: jr          $ra
    // 0x80436BDC: nop

    return;
    // 0x80436BDC: nop

;}
RECOMP_FUNC void func_8005DF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DF6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005DF70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005DF74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005DF78: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8005DF7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005DF80: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8005DF84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005DF88: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8005DF8C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8005DF90: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x8005DF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005DF98: bc1t        L_8005DFA4
    if (c1cs) {
        // 0x8005DF9C: nop
    
            goto L_8005DFA4;
    }
    // 0x8005DF9C: nop

    // 0x8005DFA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005DFA4:
    // 0x8005DFA4: bnel        $v0, $zero, L_8005DFF0
    if (ctx->r2 != 0) {
        // 0x8005DFA8: lwc1        $f10, 0x0($t0)
        ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
            goto L_8005DFF0;
    }
    goto skip_0;
    // 0x8005DFA8: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x8005DFAC: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8005DFB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005DFB4: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8005DFB8: nop

    // 0x8005DFBC: bc1t        L_8005DFC8
    if (c1cs) {
        // 0x8005DFC0: nop
    
            goto L_8005DFC8;
    }
    // 0x8005DFC0: nop

    // 0x8005DFC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005DFC8:
    // 0x8005DFC8: bnel        $v0, $zero, L_8005DFF0
    if (ctx->r2 != 0) {
        // 0x8005DFCC: lwc1        $f10, 0x0($t0)
        ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
            goto L_8005DFF0;
    }
    goto skip_1;
    // 0x8005DFCC: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    skip_1:
    // 0x8005DFD0: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8005DFD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005DFD8: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8005DFDC: nop

    // 0x8005DFE0: bc1tl       L_8005DFF0
    if (c1cs) {
        // 0x8005DFE4: lwc1        $f10, 0x0($t0)
        ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
            goto L_8005DFF0;
    }
    goto skip_2;
    // 0x8005DFE4: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    skip_2:
    // 0x8005DFE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005DFEC: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
L_8005DFF0:
    // 0x8005DFF0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005DFF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005DFF8: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x8005DFFC: nop

    // 0x8005E000: bc1t        L_8005E00C
    if (c1cs) {
        // 0x8005E004: nop
    
            goto L_8005E00C;
    }
    // 0x8005E004: nop

    // 0x8005E008: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005E00C:
    // 0x8005E00C: bne         $v0, $zero, L_8005E054
    if (ctx->r2 != 0) {
        // 0x8005E010: nop
    
            goto L_8005E054;
    }
    // 0x8005E010: nop

    // 0x8005E014: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8005E018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005E01C: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8005E020: nop

    // 0x8005E024: bc1t        L_8005E030
    if (c1cs) {
        // 0x8005E028: nop
    
            goto L_8005E030;
    }
    // 0x8005E028: nop

    // 0x8005E02C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005E030:
    // 0x8005E030: bne         $v0, $zero, L_8005E054
    if (ctx->r2 != 0) {
        // 0x8005E034: nop
    
            goto L_8005E054;
    }
    // 0x8005E034: nop

    // 0x8005E038: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8005E03C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005E040: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x8005E044: nop

    // 0x8005E048: bc1t        L_8005E054
    if (c1cs) {
        // 0x8005E04C: nop
    
            goto L_8005E054;
    }
    // 0x8005E04C: nop

    // 0x8005E050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005E054:
    // 0x8005E054: bne         $a1, $zero, L_8005E074
    if (ctx->r5 != 0) {
        // 0x8005E058: nop
    
            goto L_8005E074;
    }
    // 0x8005E058: nop

    // 0x8005E05C: bne         $a2, $zero, L_8005E074
    if (ctx->r6 != 0) {
        // 0x8005E060: nop
    
            goto L_8005E074;
    }
    // 0x8005E060: nop

    // 0x8005E064: bne         $v1, $zero, L_8005E074
    if (ctx->r3 != 0) {
        // 0x8005E068: nop
    
            goto L_8005E074;
    }
    // 0x8005E068: nop

    // 0x8005E06C: beql        $v0, $zero, L_8005E268
    if (ctx->r2 == 0) {
        // 0x8005E070: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8005E268;
    }
    goto skip_3;
    // 0x8005E070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_8005E074:
    // 0x8005E074: bne         $a1, $zero, L_8005E084
    if (ctx->r5 != 0) {
        // 0x8005E078: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005E084;
    }
    // 0x8005E078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E07C: beq         $a2, $zero, L_8005E0E0
    if (ctx->r6 == 0) {
        // 0x8005E080: nop
    
            goto L_8005E0E0;
    }
    // 0x8005E080: nop

L_8005E084:
    // 0x8005E084: beq         $a1, $zero, L_8005E09C
    if (ctx->r5 == 0) {
        // 0x8005E088: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005E09C;
    }
    // 0x8005E088: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E08C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8005E090: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005E094: b           L_8005E0A4
    // 0x8005E098: nop

        goto L_8005E0A4;
    // 0x8005E098: nop

L_8005E09C:
    // 0x8005E09C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005E0A0: nop

L_8005E0A4:
    // 0x8005E0A4: beq         $a2, $zero, L_8005E0BC
    if (ctx->r6 == 0) {
        // 0x8005E0A8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005E0BC;
    }
    // 0x8005E0A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E0AC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8005E0B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E0B4: b           L_8005E0C8
    // 0x8005E0B8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
        goto L_8005E0C8;
    // 0x8005E0B8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_8005E0BC:
    // 0x8005E0BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E0C0: nop

    // 0x8005E0C4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_8005E0C8:
    // 0x8005E0C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005E0CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8005E0D0: jal         0x80080440
    // 0x8005E0D4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80080440(rdram, ctx);
        goto after_0;
    // 0x8005E0D4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8005E0D8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8005E0DC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_8005E0E0:
    // 0x8005E0E0: bne         $v1, $zero, L_8005E0F0
    if (ctx->r3 != 0) {
        // 0x8005E0E4: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8005E0F0;
    }
    // 0x8005E0E4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E0E8: beql        $v0, $zero, L_8005E268
    if (ctx->r2 == 0) {
        // 0x8005E0EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8005E268;
    }
    goto skip_4;
    // 0x8005E0EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
L_8005E0F0:
    // 0x8005E0F0: bne         $v0, $zero, L_8005E144
    if (ctx->r2 != 0) {
        // 0x8005E0F4: lwc1        $f0, 0x0($t7)
        ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
            goto L_8005E144;
    }
    // 0x8005E0F4: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8005E0F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005E0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E100: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E104: jal         0x800662B8
    // 0x8005E108: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800662B8(rdram, ctx);
        goto after_1;
    // 0x8005E108: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x8005E10C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E114: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005E118: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005E11C: jal         0x800662B8
    // 0x8005E120: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    func_800662B8(rdram, ctx);
        goto after_2;
    // 0x8005E120: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    after_2:
    // 0x8005E124: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E12C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005E130: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E134: jal         0x800662B8
    // 0x8005E138: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    func_800662B8(rdram, ctx);
        goto after_3;
    // 0x8005E138: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    after_3:
    // 0x8005E13C: b           L_8005E268
    // 0x8005E140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8005E268;
    // 0x8005E140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8005E144:
    // 0x8005E144: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8005E148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E14C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E150: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8005E154: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8005E158: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8005E15C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005E160: jal         0x800662B8
    // 0x8005E164: nop

    func_800662B8(rdram, ctx);
        goto after_4;
    // 0x8005E164: nop

    after_4:
    // 0x8005E168: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E16C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8005E170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E174: lwc1        $f8, 0x4($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8005E178: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8005E17C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005E180: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005E184: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005E188: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8005E18C: jal         0x800662B8
    // 0x8005E190: nop

    func_800662B8(rdram, ctx);
        goto after_5;
    // 0x8005E190: nop

    after_5:
    // 0x8005E194: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E198: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8005E19C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E1A0: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8005E1A4: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8005E1A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005E1AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E1B0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005E1B4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005E1B8: jal         0x800662B8
    // 0x8005E1BC: nop

    func_800662B8(rdram, ctx);
        goto after_6;
    // 0x8005E1BC: nop

    after_6:
    // 0x8005E1C0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8005E1C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E1C8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005E1CC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005E1D0: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8005E1D4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005E1D8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8005E1DC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8005E1E0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8005E1E4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8005E1E8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8005E1EC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005E1F0: jal         0x80080C84
    // 0x8005E1F4: nop

    func_80080C84(rdram, ctx);
        goto after_7;
    // 0x8005E1F4: nop

    after_7:
    // 0x8005E1F8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8005E1FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005E204: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8005E208: jal         0x800662B8
    // 0x8005E20C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_800662B8(rdram, ctx);
        goto after_8;
    // 0x8005E20C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_8:
    // 0x8005E210: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8005E214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E218: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005E21C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005E220: jal         0x800662B8
    // 0x8005E224: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    func_800662B8(rdram, ctx);
        goto after_9;
    // 0x8005E224: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    after_9:
    // 0x8005E228: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8005E22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E230: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005E234: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E238: jal         0x800662B8
    // 0x8005E23C: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    func_800662B8(rdram, ctx);
        goto after_10;
    // 0x8005E23C: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    after_10:
    // 0x8005E240: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8005E244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E248: lwc1        $f10, 0x8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8005E24C: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x8005E250: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x8005E254: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8005E258: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8005E25C: jal         0x80080C84
    // 0x8005E260: nop

    func_80080C84(rdram, ctx);
        goto after_11;
    // 0x8005E260: nop

    after_11:
    // 0x8005E264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8005E268:
    // 0x8005E268: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005E26C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005E270: jr          $ra
    // 0x8005E274: nop

    return;
    // 0x8005E274: nop

;}
RECOMP_FUNC void func_80427A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80427A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80427A2C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80427A30: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80427A34: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(41, 0X1D9C) << 16);
    // 0x80427A38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80427A3C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80427A40: lw          $t8, -0x6924($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(41, 0X1D9C));
    // 0x80427A44: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80427A48: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80427A4C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80427A50: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80427A54: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80427A58: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80427A5C: beql        $v1, $zero, L_80427A90
    if (ctx->r3 == 0) {
        // 0x80427A60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80427A90;
    }
    goto skip_0;
    // 0x80427A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80427A64: jalr        $v1
    // 0x80427A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80427A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80427A6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80427A70: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80427A74: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80427A78: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80427A7C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80427A80: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80427A84: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80427A88: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80427A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80427A90:
    // 0x80427A90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80427A94: jr          $ra
    // 0x80427A98: nop

    return;
    // 0x80427A98: nop

;}
RECOMP_FUNC void func_80519E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519E68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519E70: jal         0x80517D80
    // 0x80519E74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80517D80(rdram, ctx);
        goto after_0;
    // 0x80519E74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80519E78: jal         0x80045BD8
    // 0x80519E7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80519E7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80519E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80519E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519E88: jr          $ra
    // 0x80519E8C: nop

    return;
    // 0x80519E8C: nop

;}
RECOMP_FUNC void func_80052994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005299C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800529A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800529A4: jal         0x8005BDA8
    // 0x800529A8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_8005BDA8(rdram, ctx);
        goto after_0;
    // 0x800529A8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x800529AC: beq         $v0, $zero, L_800529C8
    if (ctx->r2 == 0) {
        // 0x800529B0: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800529C8;
    }
    // 0x800529B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800529B4: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x800529B8: jal         0x8004A780
    // 0x800529BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8004A780(rdram, ctx);
        goto after_1;
    // 0x800529BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800529C0: b           L_800529D8
    // 0x800529C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800529D8;
    // 0x800529C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800529C8:
    // 0x800529C8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800529CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800529D0: sw          $zero, 0x44($t7)
    MEM_W(0X44, ctx->r15) = 0;
    // 0x800529D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800529D8:
    // 0x800529D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800529DC: jr          $ra
    // 0x800529E0: nop

    return;
    // 0x800529E0: nop

;}
RECOMP_FUNC void func_8004A090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004A094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A098: jal         0x80064E84
    // 0x8004A09C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8004A09C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004A0A0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A0A4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8004A0A8: sw          $zero, 0x40($t7)
    MEM_W(0X40, ctx->r15) = 0;
    // 0x8004A0AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004A0B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004A0B4: jr          $ra
    // 0x8004A0B8: nop

    return;
    // 0x8004A0B8: nop

;}
RECOMP_FUNC void func_806F602C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F602C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F6030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F6034: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x806F6038: beql        $a1, $zero, L_806F604C
    if (ctx->r5 == 0) {
        // 0x806F603C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F604C;
    }
    goto skip_0;
    // 0x806F603C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F6040: jal         0x800568E0
    // 0x806F6044: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800568E0(rdram, ctx);
        goto after_0;
    // 0x806F6044: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x806F6048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F604C:
    // 0x806F604C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F6050: jr          $ra
    // 0x806F6054: nop

    return;
    // 0x806F6054: nop

;}
RECOMP_FUNC void func_806F645C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F645C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F6460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F6464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F6468: sb          $v0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r2;
    // 0x806F646C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806F6470: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806F6474: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x806F6478: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x806F647C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x806F6480: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x806F6484: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F6488: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x806F648C: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(685, 0X154) << 16);
    // 0x806F6490: addiu       $t6, $t6, 0x54B4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(685, 0X154));
    // 0x806F6494: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x806F6498: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806F649C: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x806F64A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F64A4: jal         0x80045A34
    // 0x806F64A8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806F64A8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x806F64AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F64B0: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(685, 0XCC4) << 16);
    // 0x806F64B4: bne         $v0, $zero, L_806F64CC
    if (ctx->r2 != 0) {
        // 0x806F64B8: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806F64CC;
    }
    // 0x806F64B8: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806F64BC: jal         0x800447C8
    // 0x806F64C0: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806F64C0: nop

    after_1:
    // 0x806F64C4: b           L_806F64E0
    // 0x806F64C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806F64E0;
    // 0x806F64C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F64CC:
    // 0x806F64CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F64D0: addiu       $t7, $t7, 0x6024
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(685, 0XCC4));
    // 0x806F64D4: sw          $t7, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = ctx->r15;
    // 0x806F64D8: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x806F64DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F64E0:
    // 0x806F64E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F64E4: jr          $ra
    // 0x806F64E8: nop

    return;
    // 0x806F64E8: nop

    // 0x806F64EC: nop

;}
RECOMP_FUNC void func_80400AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80400AC8: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80400ACC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80400AD0: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x80400AD4: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80400AD8: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x80400ADC: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x80400AE0: bne         $at, $zero, L_80400B08
    if (ctx->r1 != 0) {
        // 0x80400AE4: nop
    
            goto L_80400B08;
    }
    // 0x80400AE4: nop

    // 0x80400AE8: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80400AEC: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80400AF0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80400AF4: bne         $v0, $at, L_80400B04
    if (ctx->r2 != ctx->r1) {
        // 0x80400AF8: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_80400B04;
    }
    // 0x80400AF8: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80400AFC: jr          $ra
    // 0x80400B00: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    return;
    // 0x80400B00: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_80400B04:
    // 0x80400B04: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_80400B08:
    // 0x80400B08: jr          $ra
    // 0x80400B0C: nop

    return;
    // 0x80400B0C: nop

;}
RECOMP_FUNC void func_806F295C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F295C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F2960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2964: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F2968: jal         0x80045A34
    // 0x806F296C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806F296C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x806F2970: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F2974: bne         $v0, $zero, L_806F2984
    if (ctx->r2 != 0) {
        // 0x806F2978: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806F2984;
    }
    // 0x806F2978: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806F297C: b           L_806F2990
    // 0x806F2980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F2990;
    // 0x806F2980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F2984:
    // 0x806F2984: jal         0x806F2934
    // 0x806F2988: nop

    func_806F2934(rdram, ctx);
        goto after_1;
    // 0x806F2988: nop

    after_1:
    // 0x806F298C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806F2990:
    // 0x806F2990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F2994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F2998: jr          $ra
    // 0x806F299C: nop

    return;
    // 0x806F299C: nop

;}
RECOMP_FUNC void func_807B4900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4900: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807B4904: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807B4908: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x807B490C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x807B4910: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B4914: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B4918: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B491C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B4920: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B4924: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x807B4928: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x807B492C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B4930: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x807B4934: lw          $s3, 0x18($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X18);
L_807B4938:
    // 0x807B4938: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x807B493C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807B4940: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x807B4944: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x807B4948: beq         $at, $zero, L_807B497C
    if (ctx->r1 == 0) {
        // 0x807B494C: addu        $t7, $a1, $s3
        ctx->r15 = ADD32(ctx->r5, ctx->r19);
            goto L_807B497C;
    }
    // 0x807B494C: addu        $t7, $a1, $s3
    ctx->r15 = ADD32(ctx->r5, ctx->r19);
    // 0x807B4950: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x807B4954: addu        $s0, $v0, $s1
    ctx->r16 = ADD32(ctx->r2, ctx->r17);
    // 0x807B4958: sltiu       $at, $s0, 0x80
    ctx->r1 = ctx->r16 < 0X80 ? 1 : 0;
    // 0x807B495C: beql        $at, $zero, L_807B4980
    if (ctx->r1 == 0) {
        // 0x807B4960: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_807B4980;
    }
    goto skip_0;
    // 0x807B4960: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x807B4964: jal         0x8005C27C
    // 0x807B4968: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x807B4968: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_0:
    // 0x807B496C: sltiu       $at, $s0, 0x80
    ctx->r1 = ctx->r16 < 0X80 ? 1 : 0;
    // 0x807B4970: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x807B4974: bne         $at, $zero, L_807B4938
    if (ctx->r1 != 0) {
        // 0x807B4978: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_807B4938;
    }
    // 0x807B4978: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_807B497C:
    // 0x807B497C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_807B4980:
    // 0x807B4980: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B4984: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B4988: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B498C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B4990: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x807B4994: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x807B4998: jr          $ra
    // 0x807B499C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x807B499C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8055863C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8055863C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80558640: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80558644: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80558648: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x8055864C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80558650: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80558654: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x80558658: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8055865C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80558660: sw          $t6, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r14;
    // 0x80558664: sw          $t7, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r15;
    // 0x80558668: jal         0x80558624
    // 0x8055866C: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    func_80558624(rdram, ctx);
        goto after_0;
    // 0x8055866C: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    after_0:
    // 0x80558670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558674: jal         0x80045A34
    // 0x80558678: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80558678: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_1:
    // 0x8055867C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80558680: jal         0x80558484
    // 0x80558684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80558484(rdram, ctx);
        goto after_2;
    // 0x80558684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80558688: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8055868C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80558690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558698: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8055869C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x805586A0: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x805586A4: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x805586A8: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x805586AC: jal         0x80559928
    // 0x805586B0: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
    func_80559928(rdram, ctx);
        goto after_3;
    // 0x805586B0: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
    after_3:
    // 0x805586B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805586B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805586BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805586C0: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x805586C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x805586C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805586CC: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x805586D0: jr          $ra
    // 0x805586D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805586D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006A198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A19C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A1A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006A1A4: jal         0x80064DD0
    // 0x8006A1A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x8006A1A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8006A1AC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006A1B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A1B4: bne         $v0, $zero, L_8006A1D0
    if (ctx->r2 != 0) {
        // 0x8006A1B8: sw          $v0, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->r2;
            goto L_8006A1D0;
    }
    // 0x8006A1B8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8006A1BC: addiu       $a0, $a0, 0xF40
    ctx->r4 = ADD32(ctx->r4, 0XF40);
    // 0x8006A1C0: jal         0x80071380
    // 0x8006A1C4: addiu       $a1, $zero, 0x12B
    ctx->r5 = ADD32(0, 0X12B);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8006A1C4: addiu       $a1, $zero, 0x12B
    ctx->r5 = ADD32(0, 0X12B);
    after_1:
    // 0x8006A1C8: b           L_8006A1D4
    // 0x8006A1CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A1D4;
    // 0x8006A1CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A1D0:
    // 0x8006A1D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A1D4:
    // 0x8006A1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A1D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A1DC: jr          $ra
    // 0x8006A1E0: nop

    return;
    // 0x8006A1E0: nop

;}
RECOMP_FUNC void func_8000B7CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B7CC: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x8000B7D0: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000B7D4: beql        $at, $zero, L_8000B7E8
    if (ctx->r1 == 0) {
        // 0x8000B7D8: lbu         $t7, 0x2($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X2);
            goto L_8000B7E8;
    }
    goto skip_0;
    // 0x8000B7D8: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
    skip_0:
    // 0x8000B7DC: jr          $ra
    // 0x8000B7E0: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    return;
    // 0x8000B7E0: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8000B7E4: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
L_8000B7E8:
    // 0x8000B7E8: addiu       $v1, $a0, 0x18
    ctx->r3 = ADD32(ctx->r4, 0X18);
    // 0x8000B7EC: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000B7F0: bne         $at, $zero, L_8000B800
    if (ctx->r1 != 0) {
        // 0x8000B7F4: nop
    
            goto L_8000B800;
    }
    // 0x8000B7F4: nop

    // 0x8000B7F8: jr          $ra
    // 0x8000B7FC: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    return;
    // 0x8000B7FC: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
L_8000B800:
    // 0x8000B800: jr          $ra
    // 0x8000B804: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000B804: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_806AE81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AE81C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AE820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AE824: jal         0x8004700C
    // 0x806AE828: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806AE828: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806AE82C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806AE830: lui         $t8, 0x806B
    ctx->r24 = S32(RELOC_HI16(595, 0XA80) << 16);
    // 0x806AE834: addiu       $t8, $t8, -0x1840
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(595, 0XA80));
    // 0x806AE838: lw          $t6, 0x1E0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1E0);
    // 0x806AE83C: lw          $a0, 0x1F4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1F4);
    // 0x806AE840: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x806AE844: slti        $at, $v1, 0x79
    ctx->r1 = SIGNED(ctx->r3) < 0X79 ? 1 : 0;
    // 0x806AE848: bne         $at, $zero, L_806AE85C
    if (ctx->r1 != 0) {
        // 0x806AE84C: sw          $v1, 0x1E0($a2)
        MEM_W(0X1E0, ctx->r6) = ctx->r3;
            goto L_806AE85C;
    }
    // 0x806AE84C: sw          $v1, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r3;
    // 0x806AE850: sw          $zero, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = 0;
    // 0x806AE854: b           L_806AEA14
    // 0x806AE858: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
        goto L_806AEA14;
    // 0x806AE858: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
L_806AE85C:
    // 0x806AE85C: beq         $v0, $zero, L_806AE8FC
    if (ctx->r2 == 0) {
        // 0x806AE860: slti        $at, $v1, 0x3D
        ctx->r1 = SIGNED(ctx->r3) < 0X3D ? 1 : 0;
            goto L_806AE8FC;
    }
    // 0x806AE860: slti        $at, $v1, 0x3D
    ctx->r1 = SIGNED(ctx->r3) < 0X3D ? 1 : 0;
    // 0x806AE864: bne         $at, $zero, L_806AE88C
    if (ctx->r1 != 0) {
        // 0x806AE868: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806AE88C;
    }
    // 0x806AE868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AE86C: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x806AE870: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806AE874: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    // 0x806AE878: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F90) << 16);
    // 0x806AE87C: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x806AE880: lwc1        $f6, -0x330($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F90));
    // 0x806AE884: b           L_806AE8EC
    // 0x806AE888: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
        goto L_806AE8EC;
    // 0x806AE888: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
L_806AE88C:
    // 0x806AE88C: lwc1        $f8, 0x88($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X88);
    // 0x806AE890: lwc1        $f10, 0x88($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X88);
    // 0x806AE894: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x806AE898: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806AE89C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806AE8A0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806AE8A4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x806AE8A8: nop

    // 0x806AE8AC: bc1fl       L_806AE8D8
    if (!c1cs) {
        // 0x806AE8B0: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_806AE8D8;
    }
    goto skip_0;
    // 0x806AE8B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x806AE8B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806AE8B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806AE8BC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    // 0x806AE8C0: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F94) << 16);
    // 0x806AE8C4: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x806AE8C8: lwc1        $f6, -0x32C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F94));
    // 0x806AE8CC: b           L_806AE8EC
    // 0x806AE8D0: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
        goto L_806AE8EC;
    // 0x806AE8D0: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x806AE8D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_806AE8D8:
    // 0x806AE8D8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    // 0x806AE8DC: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F98) << 16);
    // 0x806AE8E0: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x806AE8E4: lwc1        $f10, -0x328($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F98));
    // 0x806AE8E8: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
L_806AE8EC:
    // 0x806AE8EC: jal         0x806AE4CC
    // 0x806AE8F0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_806AE4CC(rdram, ctx);
        goto after_1;
    // 0x806AE8F0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x806AE8F4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806AE8F8: lw          $v1, 0x1E0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1E0);
L_806AE8FC:
    // 0x806AE8FC: slti        $at, $v1, 0x3D
    ctx->r1 = SIGNED(ctx->r3) < 0X3D ? 1 : 0;
    // 0x806AE900: bne         $at, $zero, L_806AE98C
    if (ctx->r1 != 0) {
        // 0x806AE904: addiu       $a0, $a2, 0xC4
        ctx->r4 = ADD32(ctx->r6, 0XC4);
            goto L_806AE98C;
    }
    // 0x806AE904: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    // 0x806AE908: lw          $v0, 0x34($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X34);
    // 0x806AE90C: slti        $at, $v0, -0x28
    ctx->r1 = SIGNED(ctx->r2) < -0X28 ? 1 : 0;
    // 0x806AE910: beql        $at, $zero, L_806AE950
    if (ctx->r1 == 0) {
        // 0x806AE914: slti        $at, $v0, 0x169
        ctx->r1 = SIGNED(ctx->r2) < 0X169 ? 1 : 0;
            goto L_806AE950;
    }
    goto skip_1;
    // 0x806AE914: slti        $at, $v0, 0x169
    ctx->r1 = SIGNED(ctx->r2) < 0X169 ? 1 : 0;
    skip_1:
    // 0x806AE918: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    // 0x806AE91C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806AE920: nop

    // 0x806AE924: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x806AE928: nop

    // 0x806AE92C: bc1fl       L_806AE950
    if (!c1cs) {
        // 0x806AE930: slti        $at, $v0, 0x169
        ctx->r1 = SIGNED(ctx->r2) < 0X169 ? 1 : 0;
            goto L_806AE950;
    }
    goto skip_2;
    // 0x806AE930: slti        $at, $v0, 0x169
    ctx->r1 = SIGNED(ctx->r2) < 0X169 ? 1 : 0;
    skip_2:
    // 0x806AE934: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x806AE938: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x806AE93C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x806AE940: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x806AE944: b           L_806AEA0C
    // 0x806AE948: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
        goto L_806AEA0C;
    // 0x806AE948: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x806AE94C: slti        $at, $v0, 0x169
    ctx->r1 = SIGNED(ctx->r2) < 0X169 ? 1 : 0;
L_806AE950:
    // 0x806AE950: bne         $at, $zero, L_806AEA0C
    if (ctx->r1 != 0) {
        // 0x806AE954: nop
    
            goto L_806AEA0C;
    }
    // 0x806AE954: nop

    // 0x806AE958: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    // 0x806AE95C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806AE960: nop

    // 0x806AE964: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x806AE968: nop

    // 0x806AE96C: bc1f        L_806AEA0C
    if (!c1cs) {
        // 0x806AE970: nop
    
            goto L_806AEA0C;
    }
    // 0x806AE970: nop

    // 0x806AE974: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x806AE978: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x806AE97C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x806AE980: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x806AE984: b           L_806AEA0C
    // 0x806AE988: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
        goto L_806AEA0C;
    // 0x806AE988: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
L_806AE98C:
    // 0x806AE98C: lw          $v0, 0x34($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X34);
    // 0x806AE990: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x806AE994: beql        $at, $zero, L_806AE9D4
    if (ctx->r1 == 0) {
        // 0x806AE998: slti        $at, $v0, 0x119
        ctx->r1 = SIGNED(ctx->r2) < 0X119 ? 1 : 0;
            goto L_806AE9D4;
    }
    goto skip_3;
    // 0x806AE998: slti        $at, $v0, 0x119
    ctx->r1 = SIGNED(ctx->r2) < 0X119 ? 1 : 0;
    skip_3:
    // 0x806AE99C: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    // 0x806AE9A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806AE9A4: nop

    // 0x806AE9A8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806AE9AC: nop

    // 0x806AE9B0: bc1fl       L_806AE9D4
    if (!c1cs) {
        // 0x806AE9B4: slti        $at, $v0, 0x119
        ctx->r1 = SIGNED(ctx->r2) < 0X119 ? 1 : 0;
            goto L_806AE9D4;
    }
    goto skip_4;
    // 0x806AE9B4: slti        $at, $v0, 0x119
    ctx->r1 = SIGNED(ctx->r2) < 0X119 ? 1 : 0;
    skip_4:
    // 0x806AE9B8: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x806AE9BC: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x806AE9C0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x806AE9C4: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x806AE9C8: b           L_806AEA0C
    // 0x806AE9CC: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
        goto L_806AEA0C;
    // 0x806AE9CC: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x806AE9D0: slti        $at, $v0, 0x119
    ctx->r1 = SIGNED(ctx->r2) < 0X119 ? 1 : 0;
L_806AE9D4:
    // 0x806AE9D4: bne         $at, $zero, L_806AEA0C
    if (ctx->r1 != 0) {
        // 0x806AE9D8: nop
    
            goto L_806AEA0C;
    }
    // 0x806AE9D8: nop

    // 0x806AE9DC: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    // 0x806AE9E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806AE9E4: nop

    // 0x806AE9E8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x806AE9EC: nop

    // 0x806AE9F0: bc1f        L_806AEA0C
    if (!c1cs) {
        // 0x806AE9F4: nop
    
            goto L_806AEA0C;
    }
    // 0x806AE9F4: nop

    // 0x806AE9F8: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x806AE9FC: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x806AEA00: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x806AEA04: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x806AEA08: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
L_806AEA0C:
    // 0x806AEA0C: jal         0x806AE4CC
    // 0x806AEA10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806AE4CC(rdram, ctx);
        goto after_2;
    // 0x806AEA10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_806AEA14:
    // 0x806AEA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AEA18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AEA1C: jr          $ra
    // 0x806AEA20: nop

    return;
    // 0x806AEA20: nop

;}
RECOMP_FUNC void func_80534A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534A28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80534A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80534A30: lwc1        $f6, 0xDC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x80534A34: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80534A38: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x80534A3C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80534A40: nop

    // 0x80534A44: bc1fl       L_80534A60
    if (!c1cs) {
        // 0x80534A48: addiu       $v1, $a0, 0xC4
        ctx->r3 = ADD32(ctx->r4, 0XC4);
            goto L_80534A60;
    }
    goto skip_0;
    // 0x80534A48: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    skip_0:
    // 0x80534A4C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80534A50: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80534A54: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80534A58: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x80534A5C: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
L_80534A60:
    // 0x80534A60: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80534A64: jal         0x805347F0
    // 0x80534A68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_805347F0(rdram, ctx);
        goto after_0;
    // 0x80534A68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80534A6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80534A70: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80534A74: bne         $v0, $at, L_80534A94
    if (ctx->r2 != ctx->r1) {
        // 0x80534A78: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80534A94;
    }
    // 0x80534A78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80534A7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80534A80: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80534A84: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80534A88: jal         0x805350A0
    // 0x80534A8C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_805350A0(rdram, ctx);
        goto after_1;
    // 0x80534A8C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x80534A90: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_80534A94:
    // 0x80534A94: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(348, 0X1090) << 16);
    // 0x80534A98: lwc1        $f4, 0x56A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(348, 0X1090));
    // 0x80534A9C: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80534AA0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80534AA4: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80534AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80534AAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80534AB0: jr          $ra
    // 0x80534AB4: nop

    return;
    // 0x80534AB4: nop

;}
RECOMP_FUNC void func_804CB670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CB670: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804CB674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CB678: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804CB67C: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x804CB680: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    // 0x804CB684: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804CB688: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804CB68C: jal         0x80066DE4
    // 0x804CB690: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x804CB690: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x804CB694: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804CB698: jal         0x80066E88
    // 0x804CB69C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x804CB69C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x804CB6A0: lui         $at, 0xC190
    ctx->r1 = S32(0XC190 << 16);
    // 0x804CB6A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804CB6A8: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804CB6AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804CB6B0: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x804CB6B4: nop

    // 0x804CB6B8: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x804CB6BC: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x804CB6C0: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x804CB6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CB6C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804CB6CC: jr          $ra
    // 0x804CB6D0: nop

    return;
    // 0x804CB6D0: nop

;}
RECOMP_FUNC void func_805C9D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C9D10: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805C9D14: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805C9D18: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x805C9D1C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805C9D20: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x805C9D24: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805C9D28: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805C9D2C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805C9D30: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805C9D34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805C9D38: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805C9D3C: lui         $t1, 0x805D
    ctx->r9 = S32(RELOC_HI16(447, 0X3B40) << 16);
    // 0x805C9D40: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805C9D44: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805C9D48: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805C9D4C: lw          $t1, -0x5FD0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(447, 0X3B40));
    // 0x805C9D50: jr          $ra
    // 0x805C9D54: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x805C9D54: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x805C9D58: nop

    // 0x805C9D5C: nop

;}
RECOMP_FUNC void func_8003588C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003588C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035894: jal         0x80035834
    // 0x80035898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80035834(rdram, ctx);
        goto after_0;
    // 0x80035898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003589C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800358A0: sh          $zero, 0x14A($a0)
    MEM_H(0X14A, ctx->r4) = 0;
    // 0x800358A4: sh          $zero, 0x148($a0)
    MEM_H(0X148, ctx->r4) = 0;
    // 0x800358A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800358AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800358B0: jr          $ra
    // 0x800358B4: nop

    return;
    // 0x800358B4: nop

;}
RECOMP_FUNC void func_805A1BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A1BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A1BB0: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x805A1BB4: beql        $v0, $zero, L_805A1BEC
    if (ctx->r2 == 0) {
        // 0x805A1BB8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805A1BEC;
    }
    goto skip_0;
    // 0x805A1BB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x805A1BBC: jalr        $v0
    // 0x805A1BC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x805A1BC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A1BC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A1BC8: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x805A1BCC: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x805A1BD0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x805A1BD4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x805A1BD8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805A1BDC: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x805A1BE0: b           L_805A1BEC
    // 0x805A1BE4: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
        goto L_805A1BEC;
    // 0x805A1BE4: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x805A1BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A1BEC:
    // 0x805A1BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A1BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A1BF4: jr          $ra
    // 0x805A1BF8: nop

    return;
    // 0x805A1BF8: nop

;}
RECOMP_FUNC void func_80036540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036548: jal         0x80021958
    // 0x8003654C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x8003654C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80036550: bne         $v0, $zero, L_80036560
    if (ctx->r2 != 0) {
        // 0x80036554: nop
    
            goto L_80036560;
    }
    // 0x80036554: nop

    // 0x80036558: b           L_80036594
    // 0x8003655C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036594;
    // 0x8003655C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036560:
    // 0x80036560: jal         0x800415FC
    // 0x80036564: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80036564: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80036568: beq         $v0, $zero, L_80036578
    if (ctx->r2 == 0) {
        // 0x8003656C: nop
    
            goto L_80036578;
    }
    // 0x8003656C: nop

    // 0x80036570: b           L_80036594
    // 0x80036574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036594;
    // 0x80036574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036578:
    // 0x80036578: jal         0x80036260
    // 0x8003657C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80036260(rdram, ctx);
        goto after_2;
    // 0x8003657C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80036580: bnel        $v0, $zero, L_80036594
    if (ctx->r2 != 0) {
        // 0x80036584: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80036594;
    }
    goto skip_0;
    // 0x80036584: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80036588: b           L_80036594
    // 0x8003658C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036594;
    // 0x8003658C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036594:
    // 0x80036594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003659C: jr          $ra
    // 0x800365A0: nop

    return;
    // 0x800365A0: nop

;}
RECOMP_FUNC void func_8044D490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044D490: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044D494: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044D498: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8044D49C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8044D4A0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8044D4A4: lw          $v1, 0x1F4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X1F4);
    // 0x8044D4A8: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8044D4AC: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x8044D4B0: lw          $t0, 0xA54($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XA54);
    // 0x8044D4B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8044D4B8: slti        $at, $t0, 0x3C0
    ctx->r1 = SIGNED(ctx->r8) < 0X3C0 ? 1 : 0;
    // 0x8044D4BC: beql        $at, $zero, L_8044D510
    if (ctx->r1 == 0) {
        // 0x8044D4C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8044D510;
    }
    goto skip_0;
    // 0x8044D4C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8044D4C4: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x8044D4C8: lw          $a3, 0x38($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X38);
    // 0x8044D4CC: beql        $a3, $zero, L_8044D510
    if (ctx->r7 == 0) {
        // 0x8044D4D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8044D510;
    }
    goto skip_1;
    // 0x8044D4D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8044D4D4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8044D4D8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8044D4DC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8044D4E0: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x8044D4E4: addu        $a1, $t9, $a1
    ctx->r5 = ADD32(ctx->r25, ctx->r5);
    // 0x8044D4E8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8044D4EC: jal         0x8044D1F4
    // 0x8044D4F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8044D1F4(rdram, ctx);
        goto after_0;
    // 0x8044D4F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8044D4F4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8044D4F8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8044D4FC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8044D500: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x8044D504: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8044D508: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8044D50C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8044D510:
    // 0x8044D510: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8044D514: jr          $ra
    // 0x8044D518: nop

    return;
    // 0x8044D518: nop

;}
RECOMP_FUNC void func_80450000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80450004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80450008: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80450010: addiu       $a1, $zero, 0x40F3
    ctx->r5 = ADD32(0, 0X40F3);
    // 0x80450014: jal         0x8044448C
    // 0x80450018: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8044448C(rdram, ctx);
        goto after_0;
    // 0x80450018: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8045001C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80450020: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80450024: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80450028: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8045002C: jal         0x8044DED0
    // 0x80450030: lw          $a0, 0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A28);
    func_8044DED0(rdram, ctx);
        goto after_1;
    // 0x80450030: lw          $a0, 0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A28);
    after_1:
    // 0x80450034: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80450038: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8045003C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80450040: bnel        $t8, $zero, L_804500AC
    if (ctx->r24 != 0) {
        // 0x80450044: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804500AC;
    }
    goto skip_0;
    // 0x80450044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80450048: lw          $t9, -0x71A8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X71A8);
    // 0x8045004C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140AC) << 16);
    // 0x80450050: lui         $a2, 0xC3AA
    ctx->r6 = S32(0XC3AA << 16);
    // 0x80450054: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80450058: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x8045005C: bne         $t1, $zero, L_80450090
    if (ctx->r9 != 0) {
        // 0x80450060: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80450090;
    }
    // 0x80450060: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80450064: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140A4) << 16);
    // 0x80450068: lwc1        $f0, -0x7B7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140A4));
    // 0x8045006C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140A8) << 16);
    // 0x80450070: lwc1        $f4, -0x7B78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140A8));
    // 0x80450074: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80450078: lui         $a3, 0xC363
    ctx->r7 = S32(0XC363 << 16);
    // 0x8045007C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80450080: jal         0x80444D5C
    // 0x80450084: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80444D5C(rdram, ctx);
        goto after_2;
    // 0x80450084: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80450088: b           L_804500AC
    // 0x8045008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804500AC;
    // 0x8045008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80450090:
    // 0x80450090: lwc1        $f0, -0x7B74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140AC));
    // 0x80450094: lui         $a2, 0xC357
    ctx->r6 = S32(0XC357 << 16);
    // 0x80450098: lui         $a3, 0xC363
    ctx->r7 = S32(0XC363 << 16);
    // 0x8045009C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x804500A0: jal         0x80444D5C
    // 0x804500A4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80444D5C(rdram, ctx);
        goto after_3;
    // 0x804500A4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x804500A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804500AC:
    // 0x804500AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804500B0: jr          $ra
    // 0x804500B4: nop

    return;
    // 0x804500B4: nop

;}
RECOMP_FUNC void func_80065AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065AF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065AF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80065AFC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80065B00: jal         0x8006593C
    // 0x80065B04: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80065B04: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    after_0:
    // 0x80065B08: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80065B0C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80065B10: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80065B14: subu        $v0, $t7, $v0
    ctx->r2 = SUB32(ctx->r15, ctx->r2);
    // 0x80065B18: slti        $v0, $v0, 0x0
    ctx->r2 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x80065B1C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80065B20: beql        $v0, $zero, L_80065B44
    if (ctx->r2 == 0) {
        // 0x80065B24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80065B44;
    }
    goto skip_0;
    // 0x80065B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80065B28: jal         0x8006593C
    // 0x80065B2C: subu        $a0, $t8, $t9
    ctx->r4 = SUB32(ctx->r24, ctx->r25);
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x80065B2C: subu        $a0, $t8, $t9
    ctx->r4 = SUB32(ctx->r24, ctx->r25);
    after_1:
    // 0x80065B30: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80065B34: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x80065B38: slti        $v0, $v0, 0x0
    ctx->r2 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x80065B3C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80065B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80065B44:
    // 0x80065B44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065B48: jr          $ra
    // 0x80065B4C: nop

    return;
    // 0x80065B4C: nop

;}
RECOMP_FUNC void func_8052598C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052598C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80525990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80525994: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80525998: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8052599C: jal         0x80045A34
    // 0x805259A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805259A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805259A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805259A8: bne         $v0, $zero, L_805259C0
    if (ctx->r2 != 0) {
        // 0x805259AC: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_805259C0;
    }
    // 0x805259AC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x805259B0: jal         0x800445A4
    // 0x805259B4: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805259B4: nop

    after_1:
    // 0x805259B8: b           L_805259D4
    // 0x805259BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805259D4;
    // 0x805259BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805259C0:
    // 0x805259C0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805259C4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x805259C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805259CC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x805259D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_805259D4:
    // 0x805259D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805259D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805259DC: jr          $ra
    // 0x805259E0: nop

    return;
    // 0x805259E0: nop

;}
RECOMP_FUNC void func_80034F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034F04: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80034F08: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80034F0C: sb          $v0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r2;
    // 0x80034F10: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80034F14: sb          $v0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r2;
    // 0x80034F18: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80034F1C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80034F20: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80034F24: jr          $ra
    // 0x80034F28: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    return;
    // 0x80034F28: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80049E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049E7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80049E80: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80049E84: lw          $t7, -0x77F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X77F0);
    // 0x80049E88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80049E8C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80049E90: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80049E94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80049E98: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80049E9C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80049EA0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80049EA4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80049EA8: lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4);
    // 0x80049EAC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80049EB0: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x80049EB4: bnel        $v0, $zero, L_80049EE4
    if (ctx->r2 != 0) {
        // 0x80049EB8: lwc1        $f4, 0x8($t9)
        ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
            goto L_80049EE4;
    }
    goto skip_0;
    // 0x80049EB8: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    skip_0:
    // 0x80049EBC: beq         $s0, $zero, L_80049F54
    if (ctx->r16 == 0) {
        // 0x80049EC0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80049F54;
    }
    // 0x80049EC0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80049EC4:
    // 0x80049EC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80049EC8: jal         0x80049D38
    // 0x80049ECC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80049D38(rdram, ctx);
        goto after_0;
    // 0x80049ECC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80049ED0: bnel        $s0, $zero, L_80049EC4
    if (ctx->r16 != 0) {
        // 0x80049ED4: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80049EC4;
    }
    goto skip_1;
    // 0x80049ED4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_1:
    // 0x80049ED8: b           L_80049F58
    // 0x80049EDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80049F58;
    // 0x80049EDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80049EE0: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
L_80049EE4:
    // 0x80049EE4: lwc1        $f6, 0x8C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x80049EE8: jal         0x80065954
    // 0x80049EEC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80049EEC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x80049EF0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80049EF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049EF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80049EFC: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80049F00: nop

    // 0x80049F04: bc1f        L_80049F38
    if (!c1cs) {
        // 0x80049F08: nop
    
            goto L_80049F38;
    }
    // 0x80049F08: nop

    // 0x80049F0C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80049F10: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80049F14: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80049F18: lw          $a0, 0x40($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X40);
    // 0x80049F1C: lw          $a2, 0x30($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X30);
    // 0x80049F20: lw          $a3, 0x34($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X34);
    // 0x80049F24: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80049F28: jal         0x80052D1C
    // 0x80049F2C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_80052D1C(rdram, ctx);
        goto after_2;
    // 0x80049F2C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_2:
    // 0x80049F30: b           L_80049F58
    // 0x80049F34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80049F58;
    // 0x80049F34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80049F38:
    // 0x80049F38: beq         $s0, $zero, L_80049F54
    if (ctx->r16 == 0) {
        // 0x80049F3C: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80049F54;
    }
    // 0x80049F3C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80049F40:
    // 0x80049F40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80049F44: jal         0x80049D38
    // 0x80049F48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80049D38(rdram, ctx);
        goto after_3;
    // 0x80049F48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80049F4C: bnel        $s0, $zero, L_80049F40
    if (ctx->r16 != 0) {
        // 0x80049F50: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80049F40;
    }
    goto skip_2;
    // 0x80049F50: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_2:
L_80049F54:
    // 0x80049F54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80049F58:
    // 0x80049F58: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80049F5C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80049F60: jr          $ra
    // 0x80049F64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80049F64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80699250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699250: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80699254: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80699258: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8069925C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80699260: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80699264: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80699268: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8069926C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80699270: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80699274: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80699278: lui         $t1, 0x806A
    ctx->r9 = S32(RELOC_HI16(556, 0X5A4) << 16);
    // 0x8069927C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80699280: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80699284: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80699288: lw          $t1, -0x6D3C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(556, 0X5A4));
    // 0x8069928C: jr          $ra
    // 0x80699290: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80699290: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80699294: nop

    // 0x80699298: nop

    // 0x8069929C: nop

;}
RECOMP_FUNC void func_8046CF2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046CF2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8046CF30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046CF34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046CF38: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8046CF3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8046CF40: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8046CF44: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8046CF48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CF4C: jal         0x80048F84
    // 0x8046CF50: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8046CF50: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x8046CF54: jal         0x8046C850
    // 0x8046CF58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046C850(rdram, ctx);
        goto after_1;
    // 0x8046CF58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8046CF5C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8046CF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CF64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CF68: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8046CF6C: andi        $t9, $t8, 0xF00
    ctx->r25 = ctx->r24 & 0XF00;
    // 0x8046CF70: beql        $t9, $zero, L_8046CF8C
    if (ctx->r25 == 0) {
        // 0x8046CF74: lbu         $t0, 0x30($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X30);
            goto L_8046CF8C;
    }
    goto skip_0;
    // 0x8046CF74: lbu         $t0, 0x30($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X30);
    skip_0:
    // 0x8046CF78: jal         0x8046D3E8
    // 0x8046CF7C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_8046D3E8(rdram, ctx);
        goto after_2;
    // 0x8046CF7C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_2:
    // 0x8046CF80: b           L_8046CFD0
    // 0x8046CF84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8046CFD0;
    // 0x8046CF84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8046CF88: lbu         $t0, 0x30($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X30);
L_8046CF8C:
    // 0x8046CF8C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8046CF90: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8046CF94: bnel        $t0, $at, L_8046CFD0
    if (ctx->r8 != ctx->r1) {
        // 0x8046CF98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8046CFD0;
    }
    goto skip_1;
    // 0x8046CF98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8046CF9C: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8046CFA0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8046CFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CFA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CFAC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8046CFB0: nop

    // 0x8046CFB4: bc1fl       L_8046CFD0
    if (!c1cs) {
        // 0x8046CFB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8046CFD0;
    }
    goto skip_2;
    // 0x8046CFB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8046CFBC: jal         0x8046D3E8
    // 0x8046CFC0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8046D3E8(rdram, ctx);
        goto after_3;
    // 0x8046CFC0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_3:
    // 0x8046CFC4: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046CFC8: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x8046CFCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046CFD0:
    // 0x8046CFD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046CFD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8046CFD8: jr          $ra
    // 0x8046CFDC: nop

    return;
    // 0x8046CFDC: nop

;}
RECOMP_FUNC void func_8006E5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E5EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006E5F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006E5F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E5F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E5FC: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006E600: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006E604: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006E608: jal         0x8006E154
    // 0x8006E60C: addiu       $a1, $a1, -0x1A84
    ctx->r5 = ADD32(ctx->r5, -0X1A84);
    func_8006E154(rdram, ctx);
        goto after_0;
    // 0x8006E60C: addiu       $a1, $a1, -0x1A84
    ctx->r5 = ADD32(ctx->r5, -0X1A84);
    after_0:
    // 0x8006E610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E618: jr          $ra
    // 0x8006E61C: nop

    return;
    // 0x8006E61C: nop

;}
RECOMP_FUNC void func_80409358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409358: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8040935C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80409360: lwc1        $f0, 0xB48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XB48);
    // 0x80409364: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(11, 0X2E14) << 16);
    // 0x80409368: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8040936C: nop

    // 0x80409370: bc1f        L_804093A0
    if (!c1cs) {
        // 0x80409374: nop
    
            goto L_804093A0;
    }
    // 0x80409374: nop

    // 0x80409378: lwc1        $f4, -0x581C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(11, 0X2E14));
    // 0x8040937C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80409380: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80409384: nop

    // 0x80409388: bc1fl       L_804093A0
    if (!c1cs) {
        // 0x8040938C: swc1        $f0, 0xB48($a0)
        MEM_W(0XB48, ctx->r4) = ctx->f0.u32l;
            goto L_804093A0;
    }
    goto skip_0;
    // 0x8040938C: swc1        $f0, 0xB48($a0)
    MEM_W(0XB48, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x80409390: swc1        $f2, 0xB48($a0)
    MEM_W(0XB48, ctx->r4) = ctx->f2.u32l;
    // 0x80409394: jr          $ra
    // 0x80409398: sw          $zero, 0xB4C($a0)
    MEM_W(0XB4C, ctx->r4) = 0;
    return;
    // 0x80409398: sw          $zero, 0xB4C($a0)
    MEM_W(0XB4C, ctx->r4) = 0;
    // 0x8040939C: swc1        $f0, 0xB48($a0)
    MEM_W(0XB48, ctx->r4) = ctx->f0.u32l;
L_804093A0:
    // 0x804093A0: jr          $ra
    // 0x804093A4: nop

    return;
    // 0x804093A4: nop

;}
RECOMP_FUNC void func_806654D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806654D0: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x806654D4: lui         $t8, 0x8066
    ctx->r24 = S32(RELOC_HI16(504, 0X2CA0) << 16);
    // 0x806654D8: lui         $t1, 0x8066
    ctx->r9 = S32(RELOC_HI16(504, 0X2B90) << 16);
    // 0x806654DC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806654E0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806654E4: lw          $t8, 0x7970($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(504, 0X2CA0));
    // 0x806654E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806654EC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x806654F0: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x806654F4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806654F8: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
    // 0x806654FC: lw          $t1, 0x7860($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(504, 0X2B90));
    // 0x80665500: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80665504: sw          $t2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r10;
    // 0x80665508: sw          $t3, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r11;
    // 0x8066550C: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    // 0x80665510: jr          $ra
    // 0x80665514: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80665514: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80557940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80557940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80557944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80557948: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8055794C: lui         $t6, 0x8055
    ctx->r14 = S32(RELOC_HI16(360, 0X1A0) << 16);
    // 0x80557950: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80557954: addiu       $t6, $t6, 0x7AD0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(360, 0X1A0));
    // 0x80557958: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8055795C: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x80557960: addiu       $at, $zero, 0x40A5
    ctx->r1 = ADD32(0, 0X40A5);
    // 0x80557964: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80557968: beq         $t8, $at, L_80557978
    if (ctx->r24 == ctx->r1) {
        // 0x8055796C: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_80557978;
    }
    // 0x8055796C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80557970: b           L_8055797C
    // 0x80557974: sb          $t9, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r25;
        goto L_8055797C;
    // 0x80557974: sb          $t9, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r25;
L_80557978:
    // 0x80557978: sb          $t0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r8;
L_8055797C:
    // 0x8055797C: jal         0x80557AA0
    // 0x80557980: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    func_80557AA0(rdram, ctx);
        goto after_0;
    // 0x80557980: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    after_0:
    // 0x80557984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80557988: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8055798C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80557990: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x80557994: jr          $ra
    // 0x80557998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80557998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80035008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003500C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80035014: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80035018: lw          $t8, 0x12EC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X12EC);
    // 0x8003501C: bne         $t8, $zero, L_80035034
    if (ctx->r24 != 0) {
        // 0x80035020: nop
    
            goto L_80035034;
    }
    // 0x80035020: nop

    // 0x80035024: jal         0x80040FD4
    // 0x80035028: nop

    func_80040FD4(rdram, ctx);
        goto after_0;
    // 0x80035028: nop

    after_0:
    // 0x8003502C: b           L_80035040
    // 0x80035030: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80035040;
    // 0x80035030: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80035034:
    // 0x80035034: jal         0x80040C9C
    // 0x80035038: nop

    func_80040C9C(rdram, ctx);
        goto after_1;
    // 0x80035038: nop

    after_1:
    // 0x8003503C: addiu       $v1, $v0, 0xB
    ctx->r3 = ADD32(ctx->r2, 0XB);
L_80035040:
    // 0x80035040: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80035044: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80035048: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8003504C: lw          $t9, -0x1028($at)
    ctx->r25 = MEM_W(ctx->r1, -0X1028);
    // 0x80035050: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80035054: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80035058: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8003505C: lbu         $a2, -0x7684($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7684);
    // 0x80035060: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x80035064: jalr        $t9
    // 0x80035068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80035068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8003506C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035074: jr          $ra
    // 0x80035078: nop

    return;
    // 0x80035078: nop

;}
RECOMP_FUNC void func_804D8CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8CE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804D8CE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804D8CE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804D8CEC: jal         0x804D8D98
    // 0x804D8CF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804D8D98(rdram, ctx);
        goto after_0;
    // 0x804D8CF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804D8CF4: beq         $v0, $zero, L_804D8D4C
    if (ctx->r2 == 0) {
        // 0x804D8CF8: nop
    
            goto L_804D8D4C;
    }
    // 0x804D8CF8: nop

    // 0x804D8CFC: jal         0x804D8E34
    // 0x804D8D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804D8E34(rdram, ctx);
        goto after_1;
    // 0x804D8D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804D8D04: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x804D8D08: lui         $t6, 0x804E
    ctx->r14 = S32(RELOC_HI16(258, 0XE62C) << 16);
    // 0x804D8D0C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804D8D10: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804D8D14: addiu       $t6, $t6, 0x72FC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(258, 0XE62C));
    // 0x804D8D18: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804D8D1C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804D8D20: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804D8D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804D8D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804D8D2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804D8D30: jal         0x804D9108
    // 0x804D8D34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804D9108(rdram, ctx);
        goto after_2;
    // 0x804D8D34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804D8D38: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x804D8D3C: lui         $t8, 0x804E
    ctx->r24 = S32(RELOC_HI16(258, 0X250) << 16);
    // 0x804D8D40: addiu       $t8, $t8, -0x70E0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(258, 0X250));
    // 0x804D8D44: b           L_804D8D54
    // 0x804D8D48: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
        goto L_804D8D54;
    // 0x804D8D48: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
L_804D8D4C:
    // 0x804D8D4C: jal         0x800445A4
    // 0x804D8D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x804D8D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_804D8D54:
    // 0x804D8D54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804D8D58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804D8D5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804D8D60: jr          $ra
    // 0x804D8D64: nop

    return;
    // 0x804D8D64: nop

;}
RECOMP_FUNC void func_8044C6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044C6B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044C6B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044C6BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8044C6C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8044C6C4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8044C6C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8044C6CC: jal         0x80066E88
    // 0x8044C6D0: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8044C6D0: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x8044C6D4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8044C6D8: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C6DC: jal         0x80066DE4
    // 0x8044C6E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8044C6E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x8044C6E4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8044C6E8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8044C6EC: jal         0x80066E88
    // 0x8044C6F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8044C6F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x8044C6F4: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C6F8: jal         0x80066DE4
    // 0x8044C6FC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8044C6FC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8044C700: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8044C704: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8044C708: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8044C70C: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x8044C710: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8044C714: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8044C718: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8044C71C: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x8044C720: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8044C724: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8044C728: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8044C72C: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8044C730: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C734: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8044C738: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8044C73C: swc1        $f14, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f14.u32l;
    // 0x8044C740: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8044C744: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C748: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8044C74C: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8044C750: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8044C754: swc1        $f16, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f16.u32l;
    // 0x8044C758: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x8044C75C: swc1        $f12, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f12.u32l;
    // 0x8044C760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8044C764: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8044C768: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8044C76C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8044C770: jr          $ra
    // 0x8044C774: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8044C774: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80475570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475570: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475574: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475578: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047557C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475580: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475584: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475588: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047558C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475590: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475594: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475598: jr          $ra
    // 0x8047559C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047559C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80799364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799364: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80799368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079936C: lwc1        $f6, 0x84($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X84);
    // 0x80799370: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80799374: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80799378: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8079937C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80799380: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80799384: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80799388: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8079938C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80799390: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80799394: nop

    // 0x80799398: bc1fl       L_80799424
    if (!c1cs) {
        // 0x8079939C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80799424;
    }
    goto skip_0;
    // 0x8079939C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807993A0: lw          $t7, 0xE94($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XE94);
    // 0x807993A4: addiu       $t6, $zero, 0x4034
    ctx->r14 = ADD32(0, 0X4034);
    // 0x807993A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807993AC: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x807993B0: lw          $t8, 0xE94($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE94);
    // 0x807993B4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x807993B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807993BC: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x807993C0: lw          $t9, 0xE94($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XE94);
    // 0x807993C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807993C8: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
    // 0x807993CC: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807993D0: lw          $t0, 0x478($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X478);
    // 0x807993D4: lw          $t1, 0xE94($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XE94);
    // 0x807993D8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x807993DC: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x807993E0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x807993E4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x807993E8: lwc1        $f6, 0x8C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x807993EC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x807993F0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x807993F4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x807993F8: lw          $t9, 0xC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC);
    // 0x807993FC: jalr        $t9
    // 0x80799400: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80799400: nop

    after_0:
    // 0x80799404: jal         0x8079A550
    // 0x80799408: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8079A550(rdram, ctx);
        goto after_1;
    // 0x80799408: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8079940C: jal         0x80067E68
    // 0x80799410: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067E68(rdram, ctx);
        goto after_2;
    // 0x80799410: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80799414: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80799418: jal         0x80067818
    // 0x8079941C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8079941C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80799420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80799424:
    // 0x80799424: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80799428: jr          $ra
    // 0x8079942C: nop

    return;
    // 0x8079942C: nop

;}
RECOMP_FUNC void func_8057BCF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057BCF4: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x8057BCF8: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x8057BCFC: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8057BD00: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8057BD04: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(387, 0X178) << 16);
    // 0x8057BD08: addiu       $t8, $t8, -0x4378
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(387, 0X178));
    // 0x8057BD0C: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    // 0x8057BD10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8057BD14: jr          $ra
    // 0x8057BD18: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
    return;
    // 0x8057BD18: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80446758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446758: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044675C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80446760: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446764: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x80446768: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X131F0) << 16);
    // 0x8044676C: sw          $a1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r5;
    // 0x80446770: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x80446774: lw          $v1, 0x75D0($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X131F0));
    // 0x80446778: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8044677C: beql        $v1, $zero, L_80446794
    if (ctx->r3 == 0) {
        // 0x80446780: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80446794;
    }
    goto skip_0;
    // 0x80446780: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    skip_0:
    // 0x80446784: jalr        $v1
    // 0x80446788: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80446788: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8044678C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80446790: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
L_80446794:
    // 0x80446794: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446798: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8044679C: sw          $t6, 0x6CB8($at)
    MEM_W(0X6CB8, ctx->r1) = ctx->r14;
    // 0x804467A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804467A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804467A8: jr          $ra
    // 0x804467AC: nop

    return;
    // 0x804467AC: nop

;}
RECOMP_FUNC void func_80074908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074908: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007490C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80074910: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80074914: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80074918: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007491C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80074920: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80074924: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80074928: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007492C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80074930: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80074934: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074938: jal         0x80074588
    // 0x8007493C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80074588(rdram, ctx);
        goto after_0;
    // 0x8007493C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80074940: lbu         $t6, 0x2A9($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X2A9);
    // 0x80074944: addiu       $s0, $s3, 0x230
    ctx->r16 = ADD32(ctx->r19, 0X230);
    // 0x80074948: addiu       $s1, $s3, 0x290
    ctx->r17 = ADD32(ctx->r19, 0X290);
    // 0x8007494C: blez        $t6, L_80074AB0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80074950: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80074AB0;
    }
    // 0x80074950: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80074954: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x80074958: addiu       $s6, $s6, 0x2300
    ctx->r22 = ADD32(ctx->r22, 0X2300);
    // 0x8007495C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80074960: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x80074964: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x80074968: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_8007496C:
    // 0x8007496C: lwl         $t8, 0x0($s0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r16, 0X0);
    // 0x80074970: lwr         $t8, 0x3($s0)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r16, 0X3);
    // 0x80074974: addiu       $v1, $s0, 0x6
    ctx->r3 = ADD32(ctx->r16, 0X6);
    // 0x80074978: swl         $t8, 0x0($v1)
    do_swl(rdram, 0X0, ctx->r3, ctx->r24);
    // 0x8007497C: swr         $t8, 0x3($v1)
    do_swr(rdram, 0X3, ctx->r3, ctx->r24);
    // 0x80074980: lhu         $t8, 0x4($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X4);
    // 0x80074984: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80074988: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x8007498C: beql        $v0, $zero, L_800749B0
    if (ctx->r2 == 0) {
        // 0x80074990: lwl         $t0, 0x0($s1)
        ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r17, 0X0);
            goto L_800749B0;
    }
    goto skip_0;
    // 0x80074990: lwl         $t0, 0x0($s1)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r17, 0X0);
    skip_0:
    // 0x80074994: beql        $v0, $s4, L_800749E0
    if (ctx->r2 == ctx->r20) {
        // 0x80074998: lwl         $t3, 0x0($v1)
        ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r3, 0X0);
            goto L_800749E0;
    }
    goto skip_1;
    // 0x80074998: lwl         $t3, 0x0($v1)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r3, 0X0);
    skip_1:
    // 0x8007499C: beq         $v0, $s5, L_800749F8
    if (ctx->r2 == ctx->r21) {
        // 0x800749A0: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800749F8;
    }
    // 0x800749A0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800749A4: b           L_80074A2C
    // 0x800749A8: nop

        goto L_80074A2C;
    // 0x800749A8: nop

    // 0x800749AC: lwl         $t0, 0x0($s1)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r17, 0X0);
L_800749B0:
    // 0x800749B0: lwr         $t0, 0x3($s1)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r17, 0X3);
    // 0x800749B4: addu        $v0, $s3, $s2
    ctx->r2 = ADD32(ctx->r19, ctx->r18);
    // 0x800749B8: swl         $t0, 0x0($s0)
    do_swl(rdram, 0X0, ctx->r16, ctx->r8);
    // 0x800749BC: swr         $t0, 0x3($s0)
    do_swr(rdram, 0X3, ctx->r16, ctx->r8);
    // 0x800749C0: lhu         $t0, 0x4($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X4);
    // 0x800749C4: sh          $t0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r8;
    // 0x800749C8: lbu         $t1, 0x2AA($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2AA);
    // 0x800749CC: bnel        $t1, $zero, L_80074A38
    if (ctx->r9 != 0) {
        // 0x800749D0: lhu         $v1, 0x6($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X6);
            goto L_80074A38;
    }
    goto skip_2;
    // 0x800749D0: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    skip_2:
    // 0x800749D4: b           L_80074A34
    // 0x800749D8: sb          $fp, 0x2AA($v0)
    MEM_B(0X2AA, ctx->r2) = ctx->r30;
        goto L_80074A34;
    // 0x800749D8: sb          $fp, 0x2AA($v0)
    MEM_B(0X2AA, ctx->r2) = ctx->r30;
    // 0x800749DC: lwl         $t3, 0x0($v1)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r3, 0X0);
L_800749E0:
    // 0x800749E0: lwr         $t3, 0x3($v1)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r3, 0X3);
    // 0x800749E4: swl         $t3, 0x0($s0)
    do_swl(rdram, 0X0, ctx->r16, ctx->r11);
    // 0x800749E8: swr         $t3, 0x3($s0)
    do_swr(rdram, 0X3, ctx->r16, ctx->r11);
    // 0x800749EC: lhu         $t3, 0x4($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X4);
    // 0x800749F0: b           L_80074A34
    // 0x800749F4: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
        goto L_80074A34;
    // 0x800749F4: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
L_800749F8:
    // 0x800749F8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x800749FC: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x80074A00: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80074A04: lbu         $t4, 0x4($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X4);
    // 0x80074A08: addu        $v0, $s3, $s2
    ctx->r2 = ADD32(ctx->r19, ctx->r18);
    // 0x80074A0C: sb          $t4, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r12;
    // 0x80074A10: lbu         $t5, 0x2AA($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2AA);
    // 0x80074A14: beql        $t5, $zero, L_80074A38
    if (ctx->r13 == 0) {
        // 0x80074A18: lhu         $v1, 0x6($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X6);
            goto L_80074A38;
    }
    goto skip_3;
    // 0x80074A18: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    skip_3:
    // 0x80074A1C: sb          $zero, 0x2AA($v0)
    MEM_B(0X2AA, ctx->r2) = 0;
    // 0x80074A20: sb          $zero, 0x2AE($v0)
    MEM_B(0X2AE, ctx->r2) = 0;
    // 0x80074A24: b           L_80074A34
    // 0x80074A28: sb          $s7, 0x2B6($v0)
    MEM_B(0X2B6, ctx->r2) = ctx->r23;
        goto L_80074A34;
    // 0x80074A28: sb          $s7, 0x2B6($v0)
    MEM_B(0X2B6, ctx->r2) = ctx->r23;
L_80074A2C:
    // 0x80074A2C: jal         0x80071380
    // 0x80074A30: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80074A30: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    after_1:
L_80074A34:
    // 0x80074A34: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
L_80074A38:
    // 0x80074A38: lhu         $a1, 0x0($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X0);
    // 0x80074A3C: lhu         $t6, 0xC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC);
    // 0x80074A40: lhu         $t0, 0x12($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X12);
    // 0x80074A44: xor         $v0, $v1, $a1
    ctx->r2 = ctx->r3 ^ ctx->r5;
    // 0x80074A48: and         $t2, $v0, $v1
    ctx->r10 = ctx->r2 & ctx->r3;
    // 0x80074A4C: and         $t8, $v0, $a1
    ctx->r24 = ctx->r2 & ctx->r5;
    // 0x80074A50: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80074A54: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80074A58: sh          $t9, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r25;
    // 0x80074A5C: sh          $t3, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r11;
    // 0x80074A60: jal         0x8007FC14
    // 0x80074A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    pad_correct_stick(rdram, ctx);
        goto after_2;
    // 0x80074A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80074A68: lb          $t4, 0x2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X2);
    // 0x80074A6C: lb          $t5, 0x8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X8);
    // 0x80074A70: lb          $t0, 0x3($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X3);
    // 0x80074A74: lb          $t2, 0x9($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X9);
    // 0x80074A78: lb          $t9, 0xE($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XE);
    // 0x80074A7C: lb          $t7, 0xF($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XF);
    // 0x80074A80: subu        $t8, $t4, $t5
    ctx->r24 = SUB32(ctx->r12, ctx->r13);
    // 0x80074A84: subu        $t5, $t0, $t2
    ctx->r13 = SUB32(ctx->r8, ctx->r10);
    // 0x80074A88: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x80074A8C: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x80074A90: sb          $t1, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r9;
    // 0x80074A94: sb          $t6, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r14;
    // 0x80074A98: lbu         $t9, 0x2A9($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X2A9);
    // 0x80074A9C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80074AA0: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80074AA4: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80074AA8: bne         $at, $zero, L_8007496C
    if (ctx->r1 != 0) {
        // 0x80074AAC: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_8007496C;
    }
    // 0x80074AAC: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
L_80074AB0:
    // 0x80074AB0: jal         0x800745B4
    // 0x80074AB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800745B4(rdram, ctx);
        goto after_3;
    // 0x80074AB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80074AB8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80074ABC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074AC0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80074AC4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80074AC8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80074ACC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80074AD0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80074AD4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80074AD8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80074ADC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80074AE0: jr          $ra
    // 0x80074AE4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80074AE4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_807AF508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF508: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807AF50C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807AF510: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807AF514: lui         $t8, 0x807B
    ctx->r24 = S32(RELOC_HI16(865, 0X438) << 16);
    // 0x807AF518: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807AF51C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807AF520: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807AF524: lw          $t8, -0xAC8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(865, 0X438));
    // 0x807AF528: jr          $ra
    // 0x807AF52C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x807AF52C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8043D370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D370: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x8043D374: addu        $t6, $a2, $v0
    ctx->r14 = ADD32(ctx->r6, ctx->r2);
    // 0x8043D378: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x8043D37C: lwc1        $f6, 0x84($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X84);
    // 0x8043D380: lwc1        $f4, 0x84($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X84);
    // 0x8043D384: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A18) << 16);
    // 0x8043D388: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8043D38C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8043D390: nop

    // 0x8043D394: bc1fl       L_8043D3E0
    if (!c1cs) {
        // 0x8043D398: lwc1        $f4, 0x0($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
            goto L_8043D3E0;
    }
    goto skip_0;
    // 0x8043D398: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8043D39C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A18) << 16);
    // 0x8043D3A0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8043D3A4: lwc1        $f10, -0x15A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A18));
    // 0x8043D3A8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8043D3AC: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A20) << 16);
    // 0x8043D3B0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8043D3B4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8043D3B8: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x8043D3BC: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8043D3C0: lwc1        $f0, -0x15A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A20));
    // 0x8043D3C4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8043D3C8: nop

    // 0x8043D3CC: bc1f        L_8043D414
    if (!c1cs) {
        // 0x8043D3D0: nop
    
            goto L_8043D414;
    }
    // 0x8043D3D0: nop

    // 0x8043D3D4: jr          $ra
    // 0x8043D3D8: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8043D3D8: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8043D3DC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
L_8043D3E0:
    // 0x8043D3E0: lwc1        $f6, -0x15A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A18));
    // 0x8043D3E4: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A20) << 16);
    // 0x8043D3E8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8043D3EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043D3F0: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8043D3F4: lwc1        $f0, -0x15A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A20));
    // 0x8043D3F8: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8043D3FC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8043D400: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8043D404: nop

    // 0x8043D408: bc1f        L_8043D414
    if (!c1cs) {
        // 0x8043D40C: nop
    
            goto L_8043D414;
    }
    // 0x8043D40C: nop

    // 0x8043D410: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
L_8043D414:
    // 0x8043D414: jr          $ra
    // 0x8043D418: nop

    return;
    // 0x8043D418: nop

;}
RECOMP_FUNC void func_805A3CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3CBC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x805A3CC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805A3CC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805A3CC8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x805A3CCC: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x805A3CD0: addiu       $t8, $zero, 0x13F
    ctx->r24 = ADD32(0, 0X13F);
    // 0x805A3CD4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x805A3CD8: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x805A3CDC: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x805A3CE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A3CE4: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x805A3CE8: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
    // 0x805A3CEC: lw          $t9, 0x38($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X38);
    // 0x805A3CF0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x805A3CF4: sw          $t0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r8;
    // 0x805A3CF8: lwc1        $f6, 0xB4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XB4);
    // 0x805A3CFC: lw          $t3, 0x38($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X38);
    // 0x805A3D00: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805A3D04: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x805A3D08: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x805A3D0C: nop

    // 0x805A3D10: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x805A3D14: bgez        $t0, L_805A3D24
    if (SIGNED(ctx->r8) >= 0) {
        // 0x805A3D18: sw          $t4, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->r12;
            goto L_805A3D24;
    }
    // 0x805A3D18: sw          $t4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r12;
    // 0x805A3D1C: b           L_805A3D3C
    // 0x805A3D20: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
        goto L_805A3D3C;
    // 0x805A3D20: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
L_805A3D24:
    // 0x805A3D24: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x805A3D28: addiu       $t7, $zero, 0xEF
    ctx->r15 = ADD32(0, 0XEF);
    // 0x805A3D2C: slti        $at, $t6, 0xF0
    ctx->r1 = SIGNED(ctx->r14) < 0XF0 ? 1 : 0;
    // 0x805A3D30: bnel        $at, $zero, L_805A3D40
    if (ctx->r1 != 0) {
        // 0x805A3D34: lw          $t8, 0x10($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X10);
            goto L_805A3D40;
    }
    goto skip_0;
    // 0x805A3D34: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x805A3D38: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
L_805A3D3C:
    // 0x805A3D3C: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
L_805A3D40:
    // 0x805A3D40: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x805A3D44: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x805A3D48: beql        $at, $zero, L_805A3DF0
    if (ctx->r1 == 0) {
        // 0x805A3D4C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_805A3DF0;
    }
    goto skip_1;
    // 0x805A3D4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x805A3D50: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x805A3D54: lw          $t1, 0x1C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1C);
    // 0x805A3D58: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x805A3D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A3D60: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x805A3D64: beql        $at, $zero, L_805A3DF0
    if (ctx->r1 == 0) {
        // 0x805A3D68: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_805A3DF0;
    }
    goto skip_2;
    // 0x805A3D68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x805A3D6C: jal         0x8007B4F0
    // 0x805A3D70: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8007B4F0(rdram, ctx);
        goto after_0;
    // 0x805A3D70: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x805A3D74: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x805A3D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A3D7C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x805A3D80: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x805A3D84: jal         0x8007B55C
    // 0x805A3D88: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    func_8007B55C(rdram, ctx);
        goto after_1;
    // 0x805A3D88: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    after_1:
    // 0x805A3D8C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x805A3D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A3D94: lw          $t3, 0x1C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1C);
    // 0x805A3D98: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x805A3D9C: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x805A3DA0: lw          $a3, 0x18($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X18);
    // 0x805A3DA4: jal         0x8007B580
    // 0x805A3DA8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8007B580(rdram, ctx);
        goto after_2;
    // 0x805A3DA8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_2:
    // 0x805A3DAC: jal         0x8007B59C
    // 0x805A3DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007B59C(rdram, ctx);
        goto after_3;
    // 0x805A3DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805A3DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A3DB8: jal         0x805A3874
    // 0x805A3DBC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_805A3874(rdram, ctx);
        goto after_4;
    // 0x805A3DBC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_4:
    // 0x805A3DC0: jal         0x8007B550
    // 0x805A3DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007B550(rdram, ctx);
        goto after_5;
    // 0x805A3DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805A3DC8: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x805A3DCC: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x805A3DD0: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x805A3DD4: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x805A3DD8: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x805A3DDC: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x805A3DE0: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x805A3DE4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x805A3DE8: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x805A3DEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805A3DF0:
    // 0x805A3DF0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805A3DF4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x805A3DF8: jr          $ra
    // 0x805A3DFC: nop

    return;
    // 0x805A3DFC: nop

;}
RECOMP_FUNC void func_80469F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469F00: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80469F04: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2940) << 16);
    // 0x80469F08: lwc1        $f4, -0x3F80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2940));
    // 0x80469F0C: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80469F10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80469F14: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80469F18: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80469F1C: nop

    // 0x80469F20: bc1f        L_80469F2C
    if (!c1cs) {
        // 0x80469F24: nop
    
            goto L_80469F2C;
    }
    // 0x80469F24: nop

    // 0x80469F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80469F2C:
    // 0x80469F2C: jr          $ra
    // 0x80469F30: nop

    return;
    // 0x80469F30: nop

;}
RECOMP_FUNC void func_8001C5D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C5D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C5D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001C5D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C5DC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001C5E0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001C5E4: addiu       $a1, $a1, 0x1550
    ctx->r5 = ADD32(ctx->r5, 0X1550);
    // 0x8001C5E8: addiu       $a0, $a0, 0x1540
    ctx->r4 = ADD32(ctx->r4, 0X1540);
    // 0x8001C5EC: jal         0x8004667C
    // 0x8001C5F0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x8001C5F0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x8001C5F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C5F8: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x8001C5FC: addiu       $v0, $v0, -0x349C
    ctx->r2 = ADD32(ctx->r2, -0X349C);
    // 0x8001C600: jr          $ra
    // 0x8001C604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001C604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80426BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80426BB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80426BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80426BBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80426BC0: jal         0x804269B0
    // 0x80426BC4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_804269B0(rdram, ctx);
        goto after_0;
    // 0x80426BC4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80426BC8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80426BCC: jal         0x80064E84
    // 0x80426BD0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x80426BD0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x80426BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80426BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80426BDC: jr          $ra
    // 0x80426BE0: nop

    return;
    // 0x80426BE0: nop

;}
RECOMP_FUNC void func_805ADB7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADB7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805ADB80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805ADB84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805ADB88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805ADB8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805ADB90: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805ADB94: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805ADB98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805ADB9C: addiu       $t6, $zero, 0x1D88
    ctx->r14 = ADD32(0, 0X1D88);
    // 0x805ADBA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805ADBA4: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805ADBA8: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805ADBAC: addiu       $a1, $zero, 0x1A4
    ctx->r5 = ADD32(0, 0X1A4);
    // 0x805ADBB0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x805ADBB4: jal         0x805AD70C
    // 0x805ADBB8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_805AD70C(rdram, ctx);
        goto after_0;
    // 0x805ADBB8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805ADBBC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805ADBC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ADBC4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805ADBC8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805ADBCC: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x805ADBD0: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x805ADBD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805ADBD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ADBDC: jr          $ra
    // 0x805ADBE0: nop

    return;
    // 0x805ADBE0: nop

;}
RECOMP_FUNC void func_805DBFBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DBFBC: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x805DBFC0: addiu       $at, $zero, 0x4048
    ctx->r1 = ADD32(0, 0X4048);
    // 0x805DBFC4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DBFC8: bne         $t6, $at, L_805DC008
    if (ctx->r14 != ctx->r1) {
        // 0x805DBFCC: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_805DC008;
    }
    // 0x805DBFCC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x805DBFD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805DBFD4: lwc1        $f4, 0x6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x805DBFD8: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805DBFDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805DBFE0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805DBFE4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x805DBFE8: nop

    // 0x805DBFEC: bc1f        L_805DC008
    if (!c1cs) {
        // 0x805DBFF0: nop
    
            goto L_805DC008;
    }
    // 0x805DBFF0: nop

    // 0x805DBFF4: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805DBFF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805DBFFC: nop

    // 0x805DC000: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x805DC004: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
L_805DC008:
    // 0x805DC008: jr          $ra
    // 0x805DC00C: nop

    return;
    // 0x805DC00C: nop

;}
RECOMP_FUNC void func_8005D134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D134: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8005D138: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005D13C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005D140: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8005D144: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005D148: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8005D14C: lw          $t8, 0x62D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X62D8);
    // 0x8005D150: jr          $ra
    // 0x8005D154: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x8005D154: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8005D158: nop

    // 0x8005D15C: nop

;}
RECOMP_FUNC void func_806AB6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB6C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AB6C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AB6C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AB6CC: jal         0x806AB648
    // 0x806AB6D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806AB648(rdram, ctx);
        goto after_0;
    // 0x806AB6D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806AB6D4: jal         0x806AB470
    // 0x806AB6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AB470(rdram, ctx);
        goto after_1;
    // 0x806AB6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806AB6DC: bne         $v0, $zero, L_806AB708
    if (ctx->r2 != 0) {
        // 0x806AB6E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806AB708;
    }
    // 0x806AB6E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AB6E4: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x806AB6E8: beq         $t6, $zero, L_806AB6F8
    if (ctx->r14 == 0) {
        // 0x806AB6EC: nop
    
            goto L_806AB6F8;
    }
    // 0x806AB6EC: nop

    // 0x806AB6F0: jal         0x80048060
    // 0x806AB6F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048060(rdram, ctx);
        goto after_2;
    // 0x806AB6F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_806AB6F8:
    // 0x806AB6F8: jal         0x800447C8
    // 0x806AB6FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x806AB6FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806AB700: b           L_806AB71C
    // 0x806AB704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806AB71C;
    // 0x806AB704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806AB708:
    // 0x806AB708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AB70C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806AB710: jal         0x806AB72C
    // 0x806AB714: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806AB72C(rdram, ctx);
        goto after_4;
    // 0x806AB714: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x806AB718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806AB71C:
    // 0x806AB71C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AB720: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806AB724: jr          $ra
    // 0x806AB728: nop

    return;
    // 0x806AB728: nop

;}
RECOMP_FUNC void func_8043A1D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043A1D8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8043A1DC: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x8043A1E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043A1E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043A1E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043A1EC: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8043A1F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043A1F4: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8043A1F8: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8043A1FC: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8043A200: jal         0x80051194
    // 0x8043A204: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x8043A204: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x8043A208: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x8043A20C: jal         0x8043A198
    // 0x8043A210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043A198(rdram, ctx);
        goto after_1;
    // 0x8043A210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8043A214: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8043A218: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(80, 0X196C) << 16);
    // 0x8043A21C: addiu       $t7, $t7, -0x5BD4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(80, 0X196C));
    // 0x8043A220: bne         $t6, $zero, L_8043A238
    if (ctx->r14 != 0) {
        // 0x8043A224: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8043A238;
    }
    // 0x8043A224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043A228: jal         0x800445A4
    // 0x8043A22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x8043A22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8043A230: b           L_8043A26C
    // 0x8043A234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8043A26C;
    // 0x8043A234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043A238:
    // 0x8043A238: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8043A23C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8043A240: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8043A244: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8043A248: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8043A24C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043A250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8043A254: jal         0x8043A27C
    // 0x8043A258: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8043A27C(rdram, ctx);
        goto after_3;
    // 0x8043A258: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8043A25C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8043A260: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8043A264: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x8043A268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043A26C:
    // 0x8043A26C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043A270: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043A274: jr          $ra
    // 0x8043A278: nop

    return;
    // 0x8043A278: nop

;}
RECOMP_FUNC void pad_stick_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FBE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007FBE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FBEC: jal         0x8007FBBC
    // 0x8007FBF0: nop

    pad_logical_stick_y(rdram, ctx);
        goto after_0;
    // 0x8007FBF0: nop

    after_0:
    // 0x8007FBF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FBF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007FBFC: jr          $ra
    // 0x8007FC00: nop

    return;
    // 0x8007FC00: nop

;}
RECOMP_FUNC void func_800447C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800447C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800447CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800447D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800447D4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800447D8: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800447DC: addiu       $a3, $a3, 0x4658
    ctx->r7 = ADD32(ctx->r7, 0X4658);
    // 0x800447E0: addiu       $a2, $a2, 0x3E88
    ctx->r6 = ADD32(ctx->r6, 0X3E88);
    // 0x800447E4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800447E8: jal         0x80057F74
    // 0x800447EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80057F74(rdram, ctx);
        goto after_0;
    // 0x800447EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800447F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800447F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800447F8: jr          $ra
    // 0x800447FC: nop

    return;
    // 0x800447FC: nop

;}
RECOMP_FUNC void func_804648EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804648EC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x804648F0: sll         $a3, $a2, 4
    ctx->r7 = S32(ctx->r6 << 4);
    // 0x804648F4: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x804648F8: sll         $t7, $a2, 10
    ctx->r15 = S32(ctx->r6 << 10);
    // 0x804648FC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80464900: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80464904: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80464908: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8046490C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80464910: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80464914: subu        $t8, $a1, $a3
    ctx->r24 = SUB32(ctx->r5, ctx->r7);
    // 0x80464918: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8046491C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80464920: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80464924: bgez        $a2, L_80464934
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80464928: sra         $t1, $a2, 2
        ctx->r9 = S32(SIGNED(ctx->r6) >> 2);
            goto L_80464934;
    }
    // 0x80464928: sra         $t1, $a2, 2
    ctx->r9 = S32(SIGNED(ctx->r6) >> 2);
    // 0x8046492C: addiu       $at, $a2, 0x3
    ctx->r1 = ADD32(ctx->r6, 0X3);
    // 0x80464930: sra         $t1, $at, 2
    ctx->r9 = S32(SIGNED(ctx->r1) >> 2);
L_80464934:
    // 0x80464934: addiu       $t0, $t1, -0x1
    ctx->r8 = ADD32(ctx->r9, -0X1);
    // 0x80464938: bltz        $t0, L_804649C0
    if (SIGNED(ctx->r8) < 0) {
        // 0x8046493C: sll         $t4, $a2, 1
        ctx->r12 = S32(ctx->r6 << 1);
            goto L_804649C0;
    }
    // 0x8046493C: sll         $t4, $a2, 1
    ctx->r12 = S32(ctx->r6 << 1);
    // 0x80464940: lui         $t5, 0xB100
    ctx->r13 = S32(0XB100 << 16);
L_80464944:
    // 0x80464944: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80464948: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8046494C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80464950: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80464954: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80464958: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8046495C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80464960: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80464964: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80464968: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8046496C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80464970: andi        $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 & 0XFF;
    // 0x80464974: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80464978: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8046497C: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x80464980: sll         $t3, $a3, 1
    ctx->r11 = S32(ctx->r7 << 1);
    // 0x80464984: andi        $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 & 0XFF;
    // 0x80464988: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8046498C: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x80464990: addiu       $t4, $t4, -0x8
    ctx->r12 = ADD32(ctx->r12, -0X8);
    // 0x80464994: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80464998: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x8046499C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x804649A0: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x804649A4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x804649A8: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x804649AC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x804649B0: or          $t7, $t6, $t2
    ctx->r15 = ctx->r14 | ctx->r10;
    // 0x804649B4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x804649B8: bgez        $t0, L_80464944
    if (SIGNED(ctx->r8) >= 0) {
        // 0x804649BC: sw          $t7, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r15;
            goto L_80464944;
    }
    // 0x804649BC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_804649C0:
    // 0x804649C0: jr          $ra
    // 0x804649C4: nop

    return;
    // 0x804649C4: nop

;}
RECOMP_FUNC void func_80682D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682D14: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682D18: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682D1C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682D20: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682D24: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682D28: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682D2C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682D30: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682D34: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682D38: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682D3C: jr          $ra
    // 0x80682D40: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682D40: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80680AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680AA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80680AAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80680AB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80680AB4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80680AB8: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80680ABC: addiu       $a0, $zero, 0x4595
    ctx->r4 = ADD32(0, 0X4595);
    // 0x80680AC0: jal         0x80047090
    // 0x80680AC4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80680AC4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80680AC8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80680ACC: bne         $v0, $at, L_80680ADC
    if (ctx->r2 != ctx->r1) {
        // 0x80680AD0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80680ADC;
    }
    // 0x80680AD0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80680AD4: b           L_80680B7C
    // 0x80680AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80680B7C;
    // 0x80680AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80680ADC:
    // 0x80680ADC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80680AE0: lui         $at, 0x4595
    ctx->r1 = S32(0X4595 << 16);
    // 0x80680AE4: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80680AE8: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X224C) << 16);
    // 0x80680AEC: lwc1        $f4, 0x265C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X224C));
    // 0x80680AF0: lwc1        $f6, 0x8C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8C);
    // 0x80680AF4: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2250) << 16);
    // 0x80680AF8: lwc1        $f10, 0x2660($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2250));
    // 0x80680AFC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80680B00: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    // 0x80680B04: lui         $a1, 0xC000
    ctx->r5 = S32(0XC000 << 16);
    // 0x80680B08: lui         $a2, 0x41A8
    ctx->r6 = S32(0X41A8 << 16);
    // 0x80680B0C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80680B10: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80680B14: jal         0x8004613C
    // 0x80680B18: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80680B18: nop

    after_1:
    // 0x80680B1C: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x80680B20: bne         $v0, $zero, L_80680B30
    if (ctx->r2 != 0) {
        // 0x80680B24: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80680B30;
    }
    // 0x80680B24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80680B28: b           L_80680B7C
    // 0x80680B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80680B7C;
    // 0x80680B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80680B30:
    // 0x80680B30: lhu         $t1, 0xE($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XE);
    // 0x80680B34: andi        $t0, $v1, 0x3FF
    ctx->r8 = ctx->r3 & 0X3FF;
    // 0x80680B38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80680B3C: andi        $t2, $t1, 0xFC00
    ctx->r10 = ctx->r9 & 0XFC00;
    // 0x80680B40: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80680B44: sh          $t3, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r11;
    // 0x80680B48: jal         0x80047F9C
    // 0x80680B4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80680B4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80680B50: jal         0x8068152C
    // 0x80680B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8068152C(rdram, ctx);
        goto after_3;
    // 0x80680B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80680B58: bne         $v0, $zero, L_80680B68
    if (ctx->r2 != 0) {
        // 0x80680B5C: nop
    
            goto L_80680B68;
    }
    // 0x80680B5C: nop

    // 0x80680B60: b           L_80680B7C
    // 0x80680B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80680B7C;
    // 0x80680B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80680B68:
    // 0x80680B68: jal         0x8005FDC4
    // 0x80680B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x80680B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80680B70: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80680B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80680B78: sw          $s0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r16;
L_80680B7C:
    // 0x80680B7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80680B80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80680B84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80680B88: jr          $ra
    // 0x80680B8C: nop

    return;
    // 0x80680B8C: nop

;}
RECOMP_FUNC void func_807A9C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A9C40: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x807A9C44: addiu       $at, $zero, 0x4107
    ctx->r1 = ADD32(0, 0X4107);
    // 0x807A9C48: beq         $v0, $at, L_807A9C60
    if (ctx->r2 == ctx->r1) {
        // 0x807A9C4C: addiu       $at, $zero, 0x46E4
        ctx->r1 = ADD32(0, 0X46E4);
            goto L_807A9C60;
    }
    // 0x807A9C4C: addiu       $at, $zero, 0x46E4
    ctx->r1 = ADD32(0, 0X46E4);
    // 0x807A9C50: beq         $v0, $at, L_807A9C6C
    if (ctx->r2 == ctx->r1) {
        // 0x807A9C54: nop
    
            goto L_807A9C6C;
    }
    // 0x807A9C54: nop

    // 0x807A9C58: b           L_807A9C78
    // 0x807A9C5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A9C78;
    // 0x807A9C5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A9C60:
    // 0x807A9C60: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(853, 0X58) << 16);
    // 0x807A9C64: jr          $ra
    // 0x807A9C68: addiu       $v0, $v0, -0x6368
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(853, 0X58));
    return;
    // 0x807A9C68: addiu       $v0, $v0, -0x6368
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(853, 0X58));
L_807A9C6C:
    // 0x807A9C6C: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(853, 0X16AC) << 16);
    // 0x807A9C70: jr          $ra
    // 0x807A9C74: addiu       $v0, $v0, -0x4D14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(853, 0X16AC));
    return;
    // 0x807A9C74: addiu       $v0, $v0, -0x4D14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(853, 0X16AC));
L_807A9C78:
    // 0x807A9C78: jr          $ra
    // 0x807A9C7C: nop

    return;
    // 0x807A9C7C: nop

;}
RECOMP_FUNC void func_804B7FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B7FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B7FB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B7FBC: jal         0x804B7F6C
    // 0x804B7FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804B7F6C(rdram, ctx);
        goto after_0;
    // 0x804B7FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B7FC4: jal         0x80045BD8
    // 0x804B7FC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x804B7FC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804B7FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B7FD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B7FD4: jr          $ra
    // 0x804B7FD8: nop

    return;
    // 0x804B7FD8: nop

;}
RECOMP_FUNC void func_804B7F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B7F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B7F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B7F74: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x804B7F78: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804B7F7C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x804B7F80: beq         $a1, $at, L_804B7FA4
    if (ctx->r5 == ctx->r1) {
        // 0x804B7F84: addiu       $a0, $zero, 0xD
        ctx->r4 = ADD32(0, 0XD);
            goto L_804B7FA4;
    }
    // 0x804B7F84: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x804B7F88: jal         0x80067930
    // 0x804B7F8C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x804B7F8C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x804B7F90: beq         $v0, $zero, L_804B7FA4
    if (ctx->r2 == 0) {
        // 0x804B7F94: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_804B7FA4;
    }
    // 0x804B7F94: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804B7F98: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x804B7F9C: jal         0x80067878
    // 0x804B7FA0: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x804B7FA0: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    after_1:
L_804B7FA4:
    // 0x804B7FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B7FA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B7FAC: jr          $ra
    // 0x804B7FB0: nop

    return;
    // 0x804B7FB0: nop

;}
RECOMP_FUNC void func_800257EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800257EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800257F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800257F4: lbu         $t6, 0x158($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X158);
    // 0x800257F8: bne         $t6, $zero, L_80025828
    if (ctx->r14 != 0) {
        // 0x800257FC: nop
    
            goto L_80025828;
    }
    // 0x800257FC: nop

    // 0x80025800: lw          $v0, 0x154($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X154);
    // 0x80025804: sltiu       $at, $v0, 0x20
    ctx->r1 = ctx->r2 < 0X20 ? 1 : 0;
    // 0x80025808: bne         $at, $zero, L_80025820
    if (ctx->r1 != 0) {
        // 0x8002580C: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_80025820;
    }
    // 0x8002580C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80025810: jal         0x80025768
    // 0x80025814: nop

    func_80025768(rdram, ctx);
        goto after_0;
    // 0x80025814: nop

    after_0:
    // 0x80025818: b           L_80025844
    // 0x8002581C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80025844;
    // 0x8002581C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80025820:
    // 0x80025820: b           L_80025840
    // 0x80025824: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
        goto L_80025840;
    // 0x80025824: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
L_80025828:
    // 0x80025828: jal         0x80024748
    // 0x8002582C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024748(rdram, ctx);
        goto after_1;
    // 0x8002582C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80025830: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80025834: bne         $v0, $at, L_80025840
    if (ctx->r2 != ctx->r1) {
        // 0x80025838: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80025840;
    }
    // 0x80025838: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002583C: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
L_80025840:
    // 0x80025840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80025844:
    // 0x80025844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002584C: jr          $ra
    // 0x80025850: nop

    return;
    // 0x80025850: nop

;}
