#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8003644C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003644C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80036450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036454: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80036458: jal         0x80028288
    // 0x8003645C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80028288(rdram, ctx);
        goto after_0;
    // 0x8003645C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80036460: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80036464: sw          $v0, 0x78($t7)
    MEM_W(0X78, ctx->r15) = ctx->r2;
    // 0x80036468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003646C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80036470: jr          $ra
    // 0x80036474: nop

    return;
    // 0x80036474: nop

;}
RECOMP_FUNC void func_8041DBB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041DBB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041DBB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041DBBC: jal         0x8041DB8C
    // 0x8041DBC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8041DB8C(rdram, ctx);
        goto after_0;
    // 0x8041DBC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8041DBC4: jal         0x80045BD8
    // 0x8041DBC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8041DBC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8041DBCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041DBD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041DBD4: jr          $ra
    // 0x8041DBD8: nop

    return;
    // 0x8041DBD8: nop

;}
RECOMP_FUNC void func_806DF114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DF118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF11C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806DF120: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x806DF124: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x806DF128: sw          $t7, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r15;
    // 0x806DF12C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806DF130: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806DF134: jal         0x80045A34
    // 0x806DF138: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806DF138: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x806DF13C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806DF140: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806DF144: jal         0x806DF0FC
    // 0x806DF148: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_806DF0FC(rdram, ctx);
        goto after_1;
    // 0x806DF148: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_1:
    // 0x806DF14C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806DF150: addiu       $at, $zero, 0x45BB
    ctx->r1 = ADD32(0, 0X45BB);
    // 0x806DF154: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806DF158: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x806DF15C: beq         $v0, $at, L_806DF174
    if (ctx->r2 == ctx->r1) {
        // 0x806DF160: addiu       $at, $zero, 0x45BD
        ctx->r1 = ADD32(0, 0X45BD);
            goto L_806DF174;
    }
    // 0x806DF160: addiu       $at, $zero, 0x45BD
    ctx->r1 = ADD32(0, 0X45BD);
    // 0x806DF164: beq         $v0, $at, L_806DF17C
    if (ctx->r2 == ctx->r1) {
        // 0x806DF168: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_806DF17C;
    }
    // 0x806DF168: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x806DF16C: b           L_806DF198
    // 0x806DF170: nop

        goto L_806DF198;
    // 0x806DF170: nop

L_806DF174:
    // 0x806DF174: b           L_806DF198
    // 0x806DF178: sb          $t8, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r24;
        goto L_806DF198;
    // 0x806DF178: sb          $t8, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r24;
L_806DF17C:
    // 0x806DF17C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x806DF180: sb          $t9, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r25;
    // 0x806DF184: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x806DF188: lw          $t0, -0x7530($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7530);
    // 0x806DF18C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806DF190: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x806DF194: sw          $t1, -0x7530($at)
    MEM_W(-0X7530, ctx->r1) = ctx->r9;
L_806DF198:
    // 0x806DF198: jal         0x806DF37C
    // 0x806DF19C: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    func_806DF37C(rdram, ctx);
        goto after_2;
    // 0x806DF19C: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    after_2:
    // 0x806DF1A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DF1A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806DF1A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806DF1AC: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x806DF1B0: jr          $ra
    // 0x806DF1B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806DF1B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806F1D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1D70: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F1D74: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806F1D78: jr          $ra
    // 0x806F1D7C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x806F1D7C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80704E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80704E94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80704E98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80704E9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80704EA0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80704EA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80704EA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80704EAC: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80704EB0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80704EB4: beql        $t6, $zero, L_80704ECC
    if (ctx->r14 == 0) {
        // 0x80704EB8: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_80704ECC;
    }
    goto skip_0;
    // 0x80704EB8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x80704EBC: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80704EC0: jal         0x80705A5C
    // 0x80704EC4: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    func_80705A5C(rdram, ctx);
        goto after_0;
    // 0x80704EC4: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    after_0:
    // 0x80704EC8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_80704ECC:
    // 0x80704ECC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80704ED0: jal         0x80048F84
    // 0x80704ED4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80704ED4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80704ED8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80704EDC: jal         0x80048F84
    // 0x80704EE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x80704EE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80704EE4: jal         0x8070384C
    // 0x80704EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8070384C(rdram, ctx);
        goto after_3;
    // 0x80704EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80704EEC: jal         0x80703F10
    // 0x80704EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80703F10(rdram, ctx);
        goto after_4;
    // 0x80704EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80704EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80704EF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80704EFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80704F00: jr          $ra
    // 0x80704F04: nop

    return;
    // 0x80704F04: nop

;}
RECOMP_FUNC void func_8003E4C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E4C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003E4CC: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8003E4D0: addiu       $at, $zero, 0x401F
    ctx->r1 = ADD32(0, 0X401F);
    // 0x8003E4D4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8003E4D8: beq         $v0, $at, L_8003E504
    if (ctx->r2 == ctx->r1) {
        // 0x8003E4DC: addiu       $at, $zero, 0x406C
        ctx->r1 = ADD32(0, 0X406C);
            goto L_8003E504;
    }
    // 0x8003E4DC: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8003E4E0: beq         $v0, $at, L_8003E4F8
    if (ctx->r2 == ctx->r1) {
        // 0x8003E4E4: addiu       $at, $zero, 0x4144
        ctx->r1 = ADD32(0, 0X4144);
            goto L_8003E4F8;
    }
    // 0x8003E4E4: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x8003E4E8: beql        $v0, $at, L_8003E514
    if (ctx->r2 == ctx->r1) {
        // 0x8003E4EC: lw          $t8, 0x1F4($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X1F4);
            goto L_8003E514;
    }
    goto skip_0;
    // 0x8003E4EC: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    skip_0:
    // 0x8003E4F0: jr          $ra
    // 0x8003E4F4: nop

    return;
    // 0x8003E4F4: nop

L_8003E4F8:
    // 0x8003E4F8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003E4FC: jr          $ra
    // 0x8003E500: sh          $a1, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r5;
    return;
    // 0x8003E500: sh          $a1, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r5;
L_8003E504:
    // 0x8003E504: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003E508: jr          $ra
    // 0x8003E50C: sh          $a1, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r5;
    return;
    // 0x8003E50C: sh          $a1, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r5;
    // 0x8003E510: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
L_8003E514:
    // 0x8003E514: sh          $a1, 0x208($t8)
    MEM_H(0X208, ctx->r24) = ctx->r5;
    // 0x8003E518: jr          $ra
    // 0x8003E51C: nop

    return;
    // 0x8003E51C: nop

;}
RECOMP_FUNC void func_8007C61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C61C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007C620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C624: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C628: jal         0x800744B0
    // 0x8007C62C: addiu       $a0, $a0, -0x20C0
    ctx->r4 = ADD32(ctx->r4, -0X20C0);
    func_800744B0(rdram, ctx);
        goto after_0;
    // 0x8007C62C: addiu       $a0, $a0, -0x20C0
    ctx->r4 = ADD32(ctx->r4, -0X20C0);
    after_0:
    // 0x8007C630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007C638: jr          $ra
    // 0x8007C63C: nop

    return;
    // 0x8007C63C: nop

;}
RECOMP_FUNC void func_80550B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80550B20: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80550B24: addiu       $at, $zero, 0x41C6
    ctx->r1 = ADD32(0, 0X41C6);
    // 0x80550B28: beq         $v0, $at, L_80550B40
    if (ctx->r2 == ctx->r1) {
        // 0x80550B2C: addiu       $at, $zero, 0x46F9
        ctx->r1 = ADD32(0, 0X46F9);
            goto L_80550B40;
    }
    // 0x80550B2C: addiu       $at, $zero, 0x46F9
    ctx->r1 = ADD32(0, 0X46F9);
    // 0x80550B30: beq         $v0, $at, L_80550B4C
    if (ctx->r2 == ctx->r1) {
        // 0x80550B34: addiu       $at, $zero, 0x470F
        ctx->r1 = ADD32(0, 0X470F);
            goto L_80550B4C;
    }
    // 0x80550B34: addiu       $at, $zero, 0x470F
    ctx->r1 = ADD32(0, 0X470F);
    // 0x80550B38: bne         $v0, $at, L_80550B54
    if (ctx->r2 != ctx->r1) {
        // 0x80550B3C: nop
    
            goto L_80550B54;
    }
    // 0x80550B3C: nop

L_80550B40:
    // 0x80550B40: lui         $v0, 0x8055
    ctx->r2 = S32(RELOC_HI16(354, 0X9F8) << 16);
    // 0x80550B44: jr          $ra
    // 0x80550B48: addiu       $v0, $v0, 0x1518
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(354, 0X9F8));
    return;
    // 0x80550B48: addiu       $v0, $v0, 0x1518
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(354, 0X9F8));
L_80550B4C:
    // 0x80550B4C: lui         $v0, 0x8055
    ctx->r2 = S32(RELOC_HI16(354, 0X3DB8) << 16);
    // 0x80550B50: addiu       $v0, $v0, 0x48D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(354, 0X3DB8));
L_80550B54:
    // 0x80550B54: jr          $ra
    // 0x80550B58: nop

    return;
    // 0x80550B58: nop

;}
RECOMP_FUNC void func_80436AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80436AD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80436ADC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80436AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436AE4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80436AE8: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80436AEC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80436AF0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80436AF4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80436AF8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80436AFC: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(77, 0X1EE4) << 16);
    // 0x80436B00: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80436B04: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80436B08: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80436B0C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80436B10: lw          $t2, -0x787C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(77, 0X1EE4));
    // 0x80436B14: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80436B18: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80436B1C: jal         0x804368F4
    // 0x80436B20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804368F4(rdram, ctx);
        goto after_0;
    // 0x80436B20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80436B24: jal         0x80436950
    // 0x80436B28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80436950(rdram, ctx);
        goto after_1;
    // 0x80436B28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80436B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80436B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80436B34: jr          $ra
    // 0x80436B38: nop

    return;
    // 0x80436B38: nop

;}
RECOMP_FUNC void func_800595A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800595A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800595AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800595B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800595B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800595B8: jal         0x80081C64
    // 0x800595BC: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x800595BC: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x800595C0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800595C4: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x800595C8: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x800595CC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800595D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800595D4: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800595D8: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800595DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800595E0: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800595E4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800595E8: lw          $t7, 0x478($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X478);
    // 0x800595EC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800595F0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800595F4: lwc1        $f4, 0xBA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XBA4);
    // 0x800595F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800595FC: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80059600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059608: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8005960C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80059610: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80059614: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80059618: lwc1        $f16, 0x30($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8005961C: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80059620: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80059624: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80059628: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8005962C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80059630: nop

    // 0x80059634: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80059638: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8005963C: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80059640: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80059644: nop

    // 0x80059648: bc1f        L_80059654
    if (!c1cs) {
        // 0x8005964C: nop
    
            goto L_80059654;
    }
    // 0x8005964C: nop

    // 0x80059650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059654:
    // 0x80059654: jr          $ra
    // 0x80059658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8003F2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F2AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003F2B0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003F2B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8003F2B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003F2BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003F2C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8003F2C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003F2C8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8003F2CC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8003F2D0: lw          $a3, 0x1EC($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1EC);
    // 0x8003F2D4: jal         0x8003BB20
    // 0x8003F2D8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_8003BB20(rdram, ctx);
        goto after_0;
    // 0x8003F2D8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_0:
    // 0x8003F2DC: bne         $v0, $zero, L_8003F2EC
    if (ctx->r2 != 0) {
        // 0x8003F2E0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003F2EC;
    }
    // 0x8003F2E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003F2E4: b           L_8003F368
    // 0x8003F2E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003F368;
    // 0x8003F2E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003F2EC:
    // 0x8003F2EC: jal         0x800447C8
    // 0x8003F2F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8003F2F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8003F2F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003F2F8: jal         0x8003EBD4
    // 0x8003F2FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8003EBD4(rdram, ctx);
        goto after_2;
    // 0x8003F2FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8003F300: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003F304: addiu       $t7, $t7, -0x4D50
    ctx->r15 = ADD32(ctx->r15, -0X4D50);
    // 0x8003F308: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x8003F30C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8003F310: jal         0x80065490
    // 0x8003F314: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x8003F314: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    after_3:
    // 0x8003F318: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8003F31C: jal         0x80065490
    // 0x8003F320: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80065490(rdram, ctx);
        goto after_4;
    // 0x8003F320: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x8003F324: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8003F328: jal         0x80065490
    // 0x8003F32C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80065490(rdram, ctx);
        goto after_5;
    // 0x8003F32C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x8003F330: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8003F334: jal         0x80047F9C
    // 0x8003F338: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x8003F338: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8003F33C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003F340: sb          $t8, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r24;
    // 0x8003F344: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8003F348: addiu       $t9, $t9, -0x19E8
    ctx->r25 = ADD32(ctx->r25, -0X19E8);
    // 0x8003F34C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003F350: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003F354: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x8003F358: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003F35C: jal         0x8003E6C4
    // 0x8003F360: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8003E6C4(rdram, ctx);
        goto after_7;
    // 0x8003F360: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x8003F364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003F368:
    // 0x8003F368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003F36C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003F370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003F374: jr          $ra
    // 0x8003F378: nop

    return;
    // 0x8003F378: nop

;}
RECOMP_FUNC void func_80475A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475A20: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475A24: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475A28: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80475A2C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475A30: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475A34: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475A38: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80475A3C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475A40: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475A44: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475A48: jr          $ra
    // 0x80475A4C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80475A4C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806F2180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2180: jr          $ra
    // 0x806F2184: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806F2184: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8043DD6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DD6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043DD70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8043DD74: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8043DD78: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8043DD7C: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(92, 0X1AF8) << 16);
    // 0x8043DD80: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8043DD84: lw          $v0, -0x14C8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(92, 0X1AF8));
    // 0x8043DD88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043DD8C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8043DD90: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8043DD94: beql        $v1, $zero, L_8043DDA8
    if (ctx->r3 == 0) {
        // 0x8043DD98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043DDA8;
    }
    goto skip_0;
    // 0x8043DD98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8043DD9C: jalr        $v1
    // 0x8043DDA0: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8043DDA0: nop

    after_0:
    // 0x8043DDA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043DDA8:
    // 0x8043DDA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043DDAC: jr          $ra
    // 0x8043DDB0: nop

    return;
    // 0x8043DDB0: nop

;}
RECOMP_FUNC void func_80026238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026238: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002623C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026240: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026244: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80026248: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8002624C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80026250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80026254: jal         0x80024680
    // 0x80026258: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x80026258: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    after_0:
    // 0x8002625C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026260: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026264: jr          $ra
    // 0x80026268: nop

    return;
    // 0x80026268: nop

;}
RECOMP_FUNC void func_80046014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046014: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80046018: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004601C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80046020: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x80046024: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80046028: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8004602C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80046030: bne         $t6, $at, L_80046040
    if (ctx->r14 != ctx->r1) {
        // 0x80046034: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80046040;
    }
    // 0x80046034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80046038: b           L_80046104
    // 0x8004603C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80046104;
    // 0x8004603C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80046040:
    // 0x80046040: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80046044: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80046048: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8004604C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80046050: jal         0x80045CAC
    // 0x80046054: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80045CAC(rdram, ctx);
        goto after_0;
    // 0x80046054: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80046058: bnel        $v0, $zero, L_8004606C
    if (ctx->r2 != 0) {
        // 0x8004605C: lw          $t7, 0xC($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XC);
            goto L_8004606C;
    }
    goto skip_0;
    // 0x8004605C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x80046060: b           L_80046104
    // 0x80046064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046104;
    // 0x80046064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80046068: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
L_8004606C:
    // 0x8004606C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80046070: lw          $v0, 0x168($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X168);
    // 0x80046074: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80046078: bnel        $t8, $at, L_800460A4
    if (ctx->r24 != ctx->r1) {
        // 0x8004607C: lbu         $t0, 0x170($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X170);
            goto L_800460A4;
    }
    goto skip_1;
    // 0x8004607C: lbu         $t0, 0x170($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X170);
    skip_1:
    // 0x80046080: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x80046084: beql        $v1, $zero, L_800460A4
    if (ctx->r3 == 0) {
        // 0x80046088: lbu         $t0, 0x170($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X170);
            goto L_800460A4;
    }
    goto skip_2;
    // 0x80046088: lbu         $t0, 0x170($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X170);
    skip_2:
    // 0x8004608C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80046090: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    // 0x80046094: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x80046098: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8004609C: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x800460A0: lbu         $t0, 0x170($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X170);
L_800460A4:
    // 0x800460A4: beql        $t0, $zero, L_800460C8
    if (ctx->r8 == 0) {
        // 0x800460A8: lbu         $t1, 0x164($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X164);
            goto L_800460C8;
    }
    goto skip_3;
    // 0x800460A8: lbu         $t1, 0x164($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X164);
    skip_3:
    // 0x800460AC: jal         0x80052B04
    // 0x800460B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052B04(rdram, ctx);
        goto after_1;
    // 0x800460B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800460B4: bnel        $v0, $zero, L_800460C8
    if (ctx->r2 != 0) {
        // 0x800460B8: lbu         $t1, 0x164($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X164);
            goto L_800460C8;
    }
    goto skip_4;
    // 0x800460B8: lbu         $t1, 0x164($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X164);
    skip_4:
    // 0x800460BC: b           L_80046104
    // 0x800460C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046104;
    // 0x800460C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800460C4: lbu         $t1, 0x164($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X164);
L_800460C8:
    // 0x800460C8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800460CC: beql        $t1, $at, L_800460F0
    if (ctx->r9 == ctx->r1) {
        // 0x800460D0: lhu         $t2, 0xC($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0XC);
            goto L_800460F0;
    }
    goto skip_5;
    // 0x800460D0: lhu         $t2, 0xC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XC);
    skip_5:
    // 0x800460D4: jal         0x80045730
    // 0x800460D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80045730(rdram, ctx);
        goto after_2;
    // 0x800460D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800460DC: bnel        $v0, $zero, L_800460F0
    if (ctx->r2 != 0) {
        // 0x800460E0: lhu         $t2, 0xC($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0XC);
            goto L_800460F0;
    }
    goto skip_6;
    // 0x800460E0: lhu         $t2, 0xC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XC);
    skip_6:
    // 0x800460E4: b           L_80046104
    // 0x800460E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046104;
    // 0x800460E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800460EC: lhu         $t2, 0xC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XC);
L_800460F0:
    // 0x800460F0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x800460F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800460F8: bne         $t2, $at, L_80046104
    if (ctx->r10 != ctx->r1) {
        // 0x800460FC: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_80046104;
    }
    // 0x800460FC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80046100: sw          $s0, -0x77D8($at)
    MEM_W(-0X77D8, ctx->r1) = ctx->r16;
L_80046104:
    // 0x80046104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80046108: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004610C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80046110: jr          $ra
    // 0x80046114: nop

    return;
    // 0x80046114: nop

;}
RECOMP_FUNC void func_80058D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058D60: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80058D64: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80058D68: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80058D6C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80058D70: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80058D74: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80058D78: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80058D7C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80058D80: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80058D84: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80058D88: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80058D8C: jr          $ra
    // 0x80058D90: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80058D90: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80428960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80428964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80428968: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042896C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80428970: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(41, 0X1E28) << 16);
    // 0x80428974: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80428978: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042897C: lw          $t8, -0x6898($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(41, 0X1E28));
    // 0x80428980: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80428984: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80428988: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8042898C: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80428990: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80428994: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80428998: beql        $v1, $zero, L_804289CC
    if (ctx->r3 == 0) {
        // 0x8042899C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804289CC;
    }
    goto skip_0;
    // 0x8042899C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804289A0: jalr        $v1
    // 0x804289A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804289A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804289A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804289AC: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804289B0: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804289B4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804289B8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804289BC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804289C0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804289C4: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804289C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804289CC:
    // 0x804289CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804289D0: jr          $ra
    // 0x804289D4: nop

    return;
    // 0x804289D4: nop

;}
RECOMP_FUNC void func_805A5E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5E68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A5E6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A5E70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A5E74: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x805A5E78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A5E7C: jal         0x805A5DF0
    // 0x805A5E80: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_805A5DF0(rdram, ctx);
        goto after_0;
    // 0x805A5E80: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x805A5E84: jal         0x805A54AC
    // 0x805A5E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A54AC(rdram, ctx);
        goto after_1;
    // 0x805A5E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A5E8C: jal         0x805A5D58
    // 0x805A5E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A5D58(rdram, ctx);
        goto after_2;
    // 0x805A5E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805A5E94: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805A5E98: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x805A5E9C: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x805A5EA0: beql        $t8, $zero, L_805A5ECC
    if (ctx->r24 == 0) {
        // 0x805A5EA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A5ECC;
    }
    goto skip_0;
    // 0x805A5EA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805A5EA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x805A5EAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805A5EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A5EB4: lbu         $t9, 0x74($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X74);
    // 0x805A5EB8: bnel        $t9, $zero, L_805A5ECC
    if (ctx->r25 != 0) {
        // 0x805A5EBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A5ECC;
    }
    goto skip_1;
    // 0x805A5EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805A5EC0: jal         0x8005FCA8
    // 0x805A5EC4: sb          $t0, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r8;
    func_8005FCA8(rdram, ctx);
        goto after_3;
    // 0x805A5EC4: sb          $t0, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r8;
    after_3:
    // 0x805A5EC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A5ECC:
    // 0x805A5ECC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A5ED0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805A5ED4: jr          $ra
    // 0x805A5ED8: nop

    return;
    // 0x805A5ED8: nop

;}
RECOMP_FUNC void func_8003BCDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BCDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BCE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BCE4: jal         0x80040804
    // 0x8003BCE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80040804(rdram, ctx);
        goto after_0;
    // 0x8003BCE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003BCEC: bne         $v0, $zero, L_8003BCFC
    if (ctx->r2 != 0) {
        // 0x8003BCF0: nop
    
            goto L_8003BCFC;
    }
    // 0x8003BCF0: nop

    // 0x8003BCF4: b           L_8003BD08
    // 0x8003BCF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003BD08;
    // 0x8003BCF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003BCFC:
    // 0x8003BCFC: jal         0x8002EFF8
    // 0x8003BD00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002EFF8(rdram, ctx);
        goto after_1;
    // 0x8003BD00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003BD04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003BD08:
    // 0x8003BD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BD0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003BD10: jr          $ra
    // 0x8003BD14: nop

    return;
    // 0x8003BD14: nop

;}
RECOMP_FUNC void func_80005CAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CAC: beq         $a1, $zero, L_80005CE8
    if (ctx->r5 == 0) {
        // 0x80005CB0: nop
    
            goto L_80005CE8;
    }
    // 0x80005CB0: nop

    // 0x80005CB4: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80005CB8: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80005CBC: bne         $t6, $t7, L_80005CE8
    if (ctx->r14 != ctx->r15) {
        // 0x80005CC0: nop
    
            goto L_80005CE8;
    }
    // 0x80005CC0: nop

    // 0x80005CC4: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80005CC8: lbu         $t3, 0x0($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X0);
    // 0x80005CCC: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80005CD0: lb          $t0, 0x1($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X1);
    // 0x80005CD4: andi        $t4, $t3, 0xFFF3
    ctx->r12 = ctx->r11 & 0XFFF3;
    // 0x80005CD8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80005CDC: andi        $t2, $t1, 0xC
    ctx->r10 = ctx->r9 & 0XC;
    // 0x80005CE0: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80005CE4: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
L_80005CE8:
    // 0x80005CE8: jr          $ra
    // 0x80005CEC: nop

    return;
    // 0x80005CEC: nop

;}
RECOMP_FUNC void func_804CE608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE608: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804CE60C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CE610: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CE614: jal         0x804CE318
    // 0x804CE618: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804CE318(rdram, ctx);
        goto after_0;
    // 0x804CE618: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804CE61C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804CE620: jal         0x804CE4D4
    // 0x804CE624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CE4D4(rdram, ctx);
        goto after_1;
    // 0x804CE624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804CE628: jal         0x804CE418
    // 0x804CE62C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CE418(rdram, ctx);
        goto after_2;
    // 0x804CE62C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804CE630: jal         0x804CE468
    // 0x804CE634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CE468(rdram, ctx);
        goto after_3;
    // 0x804CE634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804CE638: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804CE63C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x804CE640: bne         $v1, $v0, L_804CE698
    if (ctx->r3 != ctx->r2) {
        // 0x804CE644: nop
    
            goto L_804CE698;
    }
    // 0x804CE644: nop

    // 0x804CE648: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x804CE64C: bne         $t6, $zero, L_804CE698
    if (ctx->r14 != 0) {
        // 0x804CE650: nop
    
            goto L_804CE698;
    }
    // 0x804CE650: nop

    // 0x804CE654: jal         0x800653D8
    // 0x804CE658: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x804CE658: nop

    after_4:
    // 0x804CE65C: slti        $at, $v0, 0xBB8
    ctx->r1 = SIGNED(ctx->r2) < 0XBB8 ? 1 : 0;
    // 0x804CE660: beq         $at, $zero, L_804CE6EC
    if (ctx->r1 == 0) {
        // 0x804CE664: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804CE6EC;
    }
    // 0x804CE664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CE668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CE66C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804CE670: jal         0x804CE99C
    // 0x804CE674: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804CE99C(rdram, ctx);
        goto after_5;
    // 0x804CE674: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_5:
    // 0x804CE678: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x804CE67C: jal         0x80067BBC
    // 0x804CE680: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x804CE680: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x804CE684: addiu       $a0, $zero, 0x234
    ctx->r4 = ADD32(0, 0X234);
    // 0x804CE688: jal         0x80067818
    // 0x804CE68C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x804CE68C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x804CE690: b           L_804CE6F0
    // 0x804CE694: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804CE6F0;
    // 0x804CE694: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CE698:
    // 0x804CE698: bnel        $v1, $v0, L_804CE6F0
    if (ctx->r3 != ctx->r2) {
        // 0x804CE69C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CE6F0;
    }
    goto skip_0;
    // 0x804CE69C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804CE6A0: lw          $t7, 0x138($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X138);
    // 0x804CE6A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804CE6A8: bnel        $t7, $at, L_804CE6F0
    if (ctx->r15 != ctx->r1) {
        // 0x804CE6AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CE6F0;
    }
    goto skip_1;
    // 0x804CE6AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x804CE6B0: jal         0x800653D8
    // 0x804CE6B4: nop

    func_800653D8(rdram, ctx);
        goto after_8;
    // 0x804CE6B4: nop

    after_8:
    // 0x804CE6B8: slti        $at, $v0, 0x1770
    ctx->r1 = SIGNED(ctx->r2) < 0X1770 ? 1 : 0;
    // 0x804CE6BC: beq         $at, $zero, L_804CE6EC
    if (ctx->r1 == 0) {
        // 0x804CE6C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804CE6EC;
    }
    // 0x804CE6C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CE6C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CE6C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804CE6CC: jal         0x804CE99C
    // 0x804CE6D0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804CE99C(rdram, ctx);
        goto after_9;
    // 0x804CE6D0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_9:
    // 0x804CE6D4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x804CE6D8: jal         0x80067BBC
    // 0x804CE6DC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_10;
    // 0x804CE6DC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_10:
    // 0x804CE6E0: addiu       $a0, $zero, 0x234
    ctx->r4 = ADD32(0, 0X234);
    // 0x804CE6E4: jal         0x80067818
    // 0x804CE6E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_11;
    // 0x804CE6E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
L_804CE6EC:
    // 0x804CE6EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CE6F0:
    // 0x804CE6F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CE6F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804CE6F8: jr          $ra
    // 0x804CE6FC: nop

    return;
    // 0x804CE6FC: nop

;}
RECOMP_FUNC void func_800603E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800603E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800603EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800603F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800603F4: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800603F8: lw          $a2, 0x3C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X3C);
    // 0x800603FC: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80060400: lwc1        $f6, 0x84($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X84);
    // 0x80060404: lwc1        $f4, 0x84($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X84);
    // 0x80060408: lwc1        $f10, 0x88($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X88);
    // 0x8006040C: lwc1        $f8, 0x88($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X88);
    // 0x80060410: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80060414: lwc1        $f14, 0x1C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80060418: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x8006041C: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80060420: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80060424: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060428: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006042C: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80060430: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x80060434: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x80060438: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8006043C: nop

    // 0x80060440: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80060444: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80060448: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8006044C: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80060450: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80060454: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80060458: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006045C: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    // 0x80060460: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060464: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x80060468: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x8006046C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80060470: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80060474: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060478: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006047C: swc1        $f10, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f10.u32l;
    // 0x80060480: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060484: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x80060488: lw          $t0, 0x70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X70);
    // 0x8006048C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80060490: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80060494: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80060498: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006049C: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    // 0x800604A0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x800604A4: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800604A8: jal         0x80049018
    // 0x800604AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x800604AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800604B0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800604B4: beq         $v0, $zero, L_800604CC
    if (ctx->r2 == 0) {
        // 0x800604B8: lwc1        $f18, 0x20($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
            goto L_800604CC;
    }
    // 0x800604B8: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800604BC: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800604C0: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800604C4: b           L_800604D8
    // 0x800604C8: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
        goto L_800604D8;
    // 0x800604C8: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
L_800604CC:
    // 0x800604CC: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800604D0: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800604D4: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_800604D8:
    // 0x800604D8: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
    // 0x800604DC: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x800604E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800604E4: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x800604E8: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x800604EC: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800604F0: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800604F4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800604F8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800604FC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80060500: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80060504: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060508: lh          $t5, 0x8($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X8);
    // 0x8006050C: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x80060510: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80060514: lwc1        $f6, 0x8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80060518: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006051C: lwc1        $f8, 0x8C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x80060520: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80060524: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80060528: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8006052C: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80060530: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x80060534: jal         0x80065954
    // 0x80060538: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80060538: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    after_1:
    // 0x8006053C: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80060540: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80060544: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80060548: sub.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8006054C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80060550: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    // 0x80060554: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80060558: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8006055C: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80060560: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80060564: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80060568: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8006056C: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
    // 0x80060570: jal         0x80065954
    // 0x80060574: sub.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f8.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80060574: sub.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f8.fl;
    after_2:
    // 0x80060578: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8006057C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80060580: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80060584: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80060588: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006058C: lwc1        $f4, 0x64($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X64);
    // 0x80060590: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x80060594: sub.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80060598: bc1f        L_800605A4
    if (!c1cs) {
        // 0x8006059C: swc1        $f8, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
            goto L_800605A4;
    }
    // 0x8006059C: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x800605A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800605A4:
    // 0x800605A4: beq         $v1, $zero, L_80060614
    if (ctx->r3 == 0) {
        // 0x800605A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80060614;
    }
    // 0x800605A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800605AC: lwc1        $f0, 0x68($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800605B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800605B4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800605B8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800605BC: nop

    // 0x800605C0: bc1f        L_800605CC
    if (!c1cs) {
        // 0x800605C4: nop
    
            goto L_800605CC;
    }
    // 0x800605C4: nop

    // 0x800605C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800605CC:
    // 0x800605CC: beql        $v1, $zero, L_80060618
    if (ctx->r3 == 0) {
        // 0x800605D0: lw          $s0, 0x18($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X18);
            goto L_80060618;
    }
    goto skip_0;
    // 0x800605D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x800605D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800605D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800605DC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800605E0: nop

    // 0x800605E4: bc1f        L_800605F0
    if (!c1cs) {
        // 0x800605E8: nop
    
            goto L_800605F0;
    }
    // 0x800605E8: nop

    // 0x800605EC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800605F0:
    // 0x800605F0: beql        $v1, $zero, L_80060618
    if (ctx->r3 == 0) {
        // 0x800605F4: lw          $s0, 0x18($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X18);
            goto L_80060618;
    }
    goto skip_1;
    // 0x800605F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x800605F8: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800605FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80060600: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x80060604: nop

    // 0x80060608: bc1fl       L_80060618
    if (!c1cs) {
        // 0x8006060C: lw          $s0, 0x18($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X18);
            goto L_80060618;
    }
    goto skip_2;
    // 0x8006060C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    skip_2:
    // 0x80060610: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80060614:
    // 0x80060614: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
L_80060618:
    // 0x80060618: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006061C: jr          $ra
    // 0x80060620: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80060620: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_807AC0B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC0B8: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x807AC0BC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x807AC0C0: lui         $t4, 0x807B
    ctx->r12 = S32(RELOC_HI16(856, 0XAF8) << 16);
    // 0x807AC0C4: addiu       $t4, $t4, -0x3AB8
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(856, 0XAF8));
    // 0x807AC0C8: lui         $t3, 0x807B
    ctx->r11 = S32(RELOC_HI16(856, 0XB08) << 16);
    // 0x807AC0CC: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x807AC0D0: addiu       $t3, $t3, -0x3AA8
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(856, 0XB08));
    // 0x807AC0D4: lui         $t2, 0x807B
    ctx->r10 = S32(RELOC_HI16(856, 0XB28) << 16);
    // 0x807AC0D8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x807AC0DC: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x807AC0E0: addiu       $t2, $t2, -0x3A88
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(856, 0XB28));
    // 0x807AC0E4: sh          $v0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r2;
    // 0x807AC0E8: sh          $v0, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r2;
    // 0x807AC0EC: sh          $v1, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r3;
    // 0x807AC0F0: sh          $v1, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r3;
    // 0x807AC0F4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x807AC0F8: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x807AC0FC: lui         $t5, 0x807B
    ctx->r13 = S32(RELOC_HI16(856, 0XB18) << 16);
    // 0x807AC100: addiu       $t5, $t5, -0x3A98
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(856, 0XB18));
    // 0x807AC104: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x807AC108: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x807AC10C: addu        $t0, $a1, $a3
    ctx->r8 = ADD32(ctx->r5, ctx->r7);
    // 0x807AC110: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x807AC114: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x807AC118: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x807AC11C: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x807AC120: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x807AC124: lw          $t8, 0x4($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X4);
    // 0x807AC128: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
    // 0x807AC12C: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x807AC130: sw          $t9, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r25;
    // 0x807AC134: lw          $t8, 0xC($t3)
    ctx->r24 = MEM_W(ctx->r11, 0XC);
    // 0x807AC138: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x807AC13C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x807AC140: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x807AC144: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x807AC148: sw          $t6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r14;
    // 0x807AC14C: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x807AC150: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    // 0x807AC154: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x807AC158: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
    // 0x807AC15C: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x807AC160: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
    // 0x807AC164: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
    // 0x807AC168: sw          $t8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r24;
    // 0x807AC16C: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x807AC170: sw          $t9, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r25;
    // 0x807AC174: lw          $t8, 0xC($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XC);
    // 0x807AC178: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x807AC17C: sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
    // 0x807AC180: sh          $t0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r8;
    // 0x807AC184: sh          $a2, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r6;
    // 0x807AC188: sh          $a1, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r5;
    // 0x807AC18C: sw          $t8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r24;
    // 0x807AC190: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x807AC194: sh          $t0, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r8;
    // 0x807AC198: addu        $t1, $a2, $t5
    ctx->r9 = ADD32(ctx->r6, ctx->r13);
    // 0x807AC19C: sh          $t1, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r9;
    // 0x807AC1A0: jr          $ra
    // 0x807AC1A4: sh          $t1, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r9;
    return;
    // 0x807AC1A4: sh          $t1, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8044D9A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044D9A0: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8044D9A4: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x8044D9A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8044D9AC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8044D9B0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8044D9B4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8044D9B8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8044D9BC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8044D9C0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8044D9C4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8044D9C8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8044D9CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8044D9D0: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x8044D9D4: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x8044D9D8: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x8044D9DC: sw          $a3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r7;
    // 0x8044D9E0: lw          $s2, 0x1F4($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X1F4);
    // 0x8044D9E4: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8044D9E8: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8044D9EC: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8044D9F0: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x8044D9F4: lw          $fp, 0xA60($s2)
    ctx->r30 = MEM_W(ctx->r18, 0XA60);
    // 0x8044D9F8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8044D9FC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8044DA00: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x8044DA04: addiu       $s7, $sp, 0x80
    ctx->r23 = ADD32(ctx->r29, 0X80);
    // 0x8044DA08: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8044DA0C: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
L_8044DA10:
    // 0x8044DA10: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8044DA14: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x8044DA18: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8044DA1C: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x8044DA20: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8044DA24: lw          $t5, 0xF0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF0);
    // 0x8044DA28: beq         $s0, $zero, L_8044DB00
    if (ctx->r16 == 0) {
        // 0x8044DA2C: addiu       $v0, $s2, 0xA64
        ctx->r2 = ADD32(ctx->r18, 0XA64);
            goto L_8044DB00;
    }
    // 0x8044DA2C: addiu       $v0, $s2, 0xA64
    ctx->r2 = ADD32(ctx->r18, 0XA64);
    // 0x8044DA30: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8044DA34: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8044DA38: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x8044DA3C: beq         $a2, $zero, L_8044DA8C
    if (ctx->r6 == 0) {
        // 0x8044DA40: addu        $s4, $t4, $s3
        ctx->r20 = ADD32(ctx->r12, ctx->r19);
            goto L_8044DA8C;
    }
    // 0x8044DA40: addu        $s4, $t4, $s3
    ctx->r20 = ADD32(ctx->r12, ctx->r19);
    // 0x8044DA44: addiu       $s1, $fp, 0x1
    ctx->r17 = ADD32(ctx->r30, 0X1);
    // 0x8044DA48: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8044DA4C: lw          $a3, 0x420($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X420);
    // 0x8044DA50: sll         $t7, $fp, 2
    ctx->r15 = S32(ctx->r30 << 2);
    // 0x8044DA54: addu        $s6, $v0, $t7
    ctx->r22 = ADD32(ctx->r2, ctx->r15);
    // 0x8044DA58: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8044DA5C: jal         0x8044D140
    // 0x8044DA60: addu        $s5, $v0, $t6
    ctx->r21 = ADD32(ctx->r2, ctx->r14);
    func_8044D140(rdram, ctx);
        goto after_0;
    // 0x8044DA60: addu        $s5, $v0, $t6
    ctx->r21 = ADD32(ctx->r2, ctx->r14);
    after_0:
    // 0x8044DA64: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8044DA68: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8044DA6C: jal         0x8044CCE4
    // 0x8044DA70: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    func_8044CCE4(rdram, ctx);
        goto after_1;
    // 0x8044DA70: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_1:
    // 0x8044DA74: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8044DA78: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8044DA7C: jal         0x8044C360
    // 0x8044DA80: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_8044C360(rdram, ctx);
        goto after_2;
    // 0x8044DA80: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_2:
    // 0x8044DA84: sw          $s7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r23;
    // 0x8044DA88: sw          $s1, 0xA60($s2)
    MEM_W(0XA60, ctx->r18) = ctx->r17;
L_8044DA8C:
    // 0x8044DA8C: lw          $t8, 0xE8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE8);
    // 0x8044DA90: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x8044DA94: lw          $t3, 0x360($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X360);
    // 0x8044DA98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8044DA9C: lw          $t4, 0xF0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF0);
    // 0x8044DAA0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8044DAA4: sll         $t1, $t9, 6
    ctx->r9 = S32(ctx->r25 << 6);
    // 0x8044DAA8: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x8044DAAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044DAB0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x8044DAB4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8044DAB8: jal         0x8044D1F4
    // 0x8044DABC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_8044D1F4(rdram, ctx);
        goto after_3;
    // 0x8044DABC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_3:
    // 0x8044DAC0: lw          $t5, 0xE8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE8);
    // 0x8044DAC4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8044DAC8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8044DACC: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x8044DAD0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8044DAD4: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8044DAD8: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8044DADC: beql        $t1, $zero, L_8044DAEC
    if (ctx->r9 == 0) {
        // 0x8044DAE0: lw          $t2, 0x58($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X58);
            goto L_8044DAEC;
    }
    goto skip_0;
    // 0x8044DAE0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    skip_0:
    // 0x8044DAE4: sw          $fp, 0xA60($s2)
    MEM_W(0XA60, ctx->r18) = ctx->r30;
    // 0x8044DAE8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
L_8044DAEC:
    // 0x8044DAEC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8044DAF0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8044DAF4: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8044DAF8: bne         $s3, $at, L_8044DA10
    if (ctx->r19 != ctx->r1) {
        // 0x8044DAFC: sw          $t3, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r11;
            goto L_8044DA10;
    }
    // 0x8044DAFC: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_8044DB00:
    // 0x8044DB00: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8044DB04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8044DB08: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8044DB0C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8044DB10: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8044DB14: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8044DB18: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8044DB1C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8044DB20: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8044DB24: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8044DB28: jr          $ra
    // 0x8044DB2C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8044DB2C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_8007C5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C5EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007C5F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C5F4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C5F8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8007C5FC: addiu       $a1, $a1, -0x2120
    ctx->r5 = ADD32(ctx->r5, -0X2120);
    // 0x8007C600: addiu       $a0, $a0, -0x20C0
    ctx->r4 = ADD32(ctx->r4, -0X20C0);
    // 0x8007C604: jal         0x80074C88
    // 0x8007C608: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80074C88(rdram, ctx);
        goto after_0;
    // 0x8007C608: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007C60C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007C614: jr          $ra
    // 0x8007C618: nop

    return;
    // 0x8007C618: nop

;}
RECOMP_FUNC void func_806F1580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1580: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806F1584: slti        $at, $v0, 0x4616
    ctx->r1 = SIGNED(ctx->r2) < 0X4616 ? 1 : 0;
    // 0x806F1588: bne         $at, $zero, L_806F15B8
    if (ctx->r1 != 0) {
        // 0x806F158C: addiu       $at, $zero, 0x4616
        ctx->r1 = ADD32(0, 0X4616);
            goto L_806F15B8;
    }
    // 0x806F158C: addiu       $at, $zero, 0x4616
    ctx->r1 = ADD32(0, 0X4616);
    // 0x806F1590: beq         $v0, $at, L_806F1608
    if (ctx->r2 == ctx->r1) {
        // 0x806F1594: addiu       $at, $zero, 0x4653
        ctx->r1 = ADD32(0, 0X4653);
            goto L_806F1608;
    }
    // 0x806F1594: addiu       $at, $zero, 0x4653
    ctx->r1 = ADD32(0, 0X4653);
    // 0x806F1598: beq         $v0, $at, L_806F1614
    if (ctx->r2 == ctx->r1) {
        // 0x806F159C: addiu       $at, $zero, 0x4654
        ctx->r1 = ADD32(0, 0X4654);
            goto L_806F1614;
    }
    // 0x806F159C: addiu       $at, $zero, 0x4654
    ctx->r1 = ADD32(0, 0X4654);
    // 0x806F15A0: beq         $v0, $at, L_806F1620
    if (ctx->r2 == ctx->r1) {
        // 0x806F15A4: addiu       $at, $zero, 0x4655
        ctx->r1 = ADD32(0, 0X4655);
            goto L_806F1620;
    }
    // 0x806F15A4: addiu       $at, $zero, 0x4655
    ctx->r1 = ADD32(0, 0X4655);
    // 0x806F15A8: beq         $v0, $at, L_806F162C
    if (ctx->r2 == ctx->r1) {
        // 0x806F15AC: nop
    
            goto L_806F162C;
    }
    // 0x806F15AC: nop

    // 0x806F15B0: b           L_806F163C
    // 0x806F15B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F163C;
    // 0x806F15B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F15B8:
    // 0x806F15B8: addiu       $at, $zero, 0x45E6
    ctx->r1 = ADD32(0, 0X45E6);
    // 0x806F15BC: beq         $v0, $at, L_806F15F0
    if (ctx->r2 == ctx->r1) {
        // 0x806F15C0: lui         $t6, 0x806F
        ctx->r14 = S32(RELOC_HI16(679, 0X18F4) << 16);
            goto L_806F15F0;
    }
    // 0x806F15C0: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(679, 0X18F4) << 16);
    // 0x806F15C4: addiu       $at, $zero, 0x45E7
    ctx->r1 = ADD32(0, 0X45E7);
    // 0x806F15C8: beq         $v0, $at, L_806F1608
    if (ctx->r2 == ctx->r1) {
        // 0x806F15CC: addiu       $at, $zero, 0x460E
        ctx->r1 = ADD32(0, 0X460E);
            goto L_806F1608;
    }
    // 0x806F15CC: addiu       $at, $zero, 0x460E
    ctx->r1 = ADD32(0, 0X460E);
    // 0x806F15D0: beq         $v0, $at, L_806F15FC
    if (ctx->r2 == ctx->r1) {
        // 0x806F15D4: addiu       $at, $zero, 0x460F
        ctx->r1 = ADD32(0, 0X460F);
            goto L_806F15FC;
    }
    // 0x806F15D4: addiu       $at, $zero, 0x460F
    ctx->r1 = ADD32(0, 0X460F);
    // 0x806F15D8: beq         $v0, $at, L_806F15FC
    if (ctx->r2 == ctx->r1) {
        // 0x806F15DC: addiu       $at, $zero, 0x4615
        ctx->r1 = ADD32(0, 0X4615);
            goto L_806F15FC;
    }
    // 0x806F15DC: addiu       $at, $zero, 0x4615
    ctx->r1 = ADD32(0, 0X4615);
    // 0x806F15E0: beq         $v0, $at, L_806F1608
    if (ctx->r2 == ctx->r1) {
        // 0x806F15E4: nop
    
            goto L_806F1608;
    }
    // 0x806F15E4: nop

    // 0x806F15E8: b           L_806F163C
    // 0x806F15EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F163C;
    // 0x806F15EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F15F0:
    // 0x806F15F0: addiu       $t6, $t6, 0x2E74
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(679, 0X18F4));
    // 0x806F15F4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F15F8: sw          $t6, -0x72A8($at)
    MEM_W(-0X72A8, ctx->r1) = ctx->r14;
L_806F15FC:
    // 0x806F15FC: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(679, 0X85C) << 16);
    // 0x806F1600: jr          $ra
    // 0x806F1604: addiu       $v0, $v0, 0x1DDC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(679, 0X85C));
    return;
    // 0x806F1604: addiu       $v0, $v0, 0x1DDC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(679, 0X85C));
L_806F1608:
    // 0x806F1608: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(679, 0XEC0) << 16);
    // 0x806F160C: jr          $ra
    // 0x806F1610: addiu       $v0, $v0, 0x2440
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(679, 0XEC0));
    return;
    // 0x806F1610: addiu       $v0, $v0, 0x2440
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(679, 0XEC0));
L_806F1614:
    // 0x806F1614: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(679, 0X1420) << 16);
    // 0x806F1618: jr          $ra
    // 0x806F161C: addiu       $v0, $v0, 0x29A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(679, 0X1420));
    return;
    // 0x806F161C: addiu       $v0, $v0, 0x29A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(679, 0X1420));
L_806F1620:
    // 0x806F1620: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(679, 0X1528) << 16);
    // 0x806F1624: jr          $ra
    // 0x806F1628: addiu       $v0, $v0, 0x2AA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(679, 0X1528));
    return;
    // 0x806F1628: addiu       $v0, $v0, 0x2AA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(679, 0X1528));
L_806F162C:
    // 0x806F162C: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(679, 0X185C) << 16);
    // 0x806F1630: jr          $ra
    // 0x806F1634: addiu       $v0, $v0, 0x2DDC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(679, 0X185C));
    return;
    // 0x806F1634: addiu       $v0, $v0, 0x2DDC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(679, 0X185C));
    // 0x806F1638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F163C:
    // 0x806F163C: jr          $ra
    // 0x806F1640: nop

    return;
    // 0x806F1640: nop

;}
RECOMP_FUNC void func_8003A4EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A4EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003A4F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A4F4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003A4F8: jal         0x8003A3FC
    // 0x8003A4FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8003A3FC(rdram, ctx);
        goto after_0;
    // 0x8003A4FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003A500: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8003A504: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8003A508: beq         $v1, $zero, L_8003A514
    if (ctx->r3 == 0) {
        // 0x8003A50C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8003A514;
    }
    // 0x8003A50C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8003A510: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_8003A514:
    // 0x8003A514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003A51C: jr          $ra
    // 0x8003A520: nop

    return;
    // 0x8003A520: nop

;}
RECOMP_FUNC void func_80073728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073728: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007372C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073730: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80073734: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80073738: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007373C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073740: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80073744: lwc1        $f14, 0x1FC8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X1FC8);
    // 0x80073748: lhu         $v1, 0xA($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XA);
    // 0x8007374C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80073750: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80073754: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80073758: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8007375C: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80073760: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80073764: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80073768: nop

    // 0x8007376C: bc1fl       L_80073780
    if (!c1cs) {
        // 0x80073770: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_80073780;
    }
    goto skip_0;
    // 0x80073770: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_0:
    // 0x80073774: b           L_80073780
    // 0x80073778: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80073780;
    // 0x80073778: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8007377C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80073780:
    // 0x80073780: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x80073784: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80073788: bgez        $t8, L_8007379C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007378C: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8007379C;
    }
    // 0x8007378C: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80073790: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80073794: nop

    // 0x80073798: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_8007379C:
    // 0x8007379C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800737A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800737A4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800737A8: bc1fl       L_800737BC
    if (!c1cs) {
        // 0x800737AC: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_800737BC;
    }
    goto skip_1;
    // 0x800737AC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_1:
    // 0x800737B0: b           L_800737BC
    // 0x800737B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_800737BC;
    // 0x800737B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800737B8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_800737BC:
    // 0x800737BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800737C0: nop

    // 0x800737C4: lbu         $t9, 0x8($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X8);
    // 0x800737C8: lbu         $t3, 0x9($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X9);
    // 0x800737CC: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800737D0: andi        $t0, $t9, 0x7
    ctx->r8 = ctx->r25 & 0X7;
    // 0x800737D4: sll         $t1, $t0, 21
    ctx->r9 = S32(ctx->r8 << 21);
    // 0x800737D8: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x800737DC: sll         $t5, $t4, 19
    ctx->r13 = S32(ctx->r12 << 19);
    // 0x800737E0: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x800737E4: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x800737E8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800737EC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800737F0: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800737F4: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800737F8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800737FC: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x80073800: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80073804: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80073808: lui         $t1, 0xED00
    ctx->r9 = S32(0XED00 << 16);
    // 0x8007380C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80073810: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073814: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80073818: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8007381C: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80073820: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80073824: andi        $t2, $t4, 0xFFF
    ctx->r10 = ctx->r12 & 0XFFF;
    // 0x80073828: sll         $t5, $t2, 12
    ctx->r13 = S32(ctx->r10 << 12);
    // 0x8007382C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80073830: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80073834: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x80073838: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8007383C: jr          $ra
    // 0x80073840: nop

    return;
    // 0x80073840: nop

;}
RECOMP_FUNC void func_8002AE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AE54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AE58: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002AE5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AE60: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8002AE64: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x8002AE68: addiu       $a2, $a2, -0x52EC
    ctx->r6 = ADD32(ctx->r6, -0X52EC);
    // 0x8002AE6C: jal         0x8005A994
    // 0x8002AE70: lw          $a0, -0x7CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE8);
    func_8005A994(rdram, ctx);
        goto after_0;
    // 0x8002AE70: lw          $a0, -0x7CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE8);
    after_0:
    // 0x8002AE74: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8002AE78: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x8002AE7C: sw          $zero, 0xF4($t6)
    MEM_W(0XF4, ctx->r14) = 0;
    // 0x8002AE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AE84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002AE88: jr          $ra
    // 0x8002AE8C: nop

    return;
    // 0x8002AE8C: nop

;}
RECOMP_FUNC void func_80735E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735E58: lui         $a3, 0x8074
    ctx->r7 = S32(RELOC_HI16(736, 0X3918) << 16);
    // 0x80735E5C: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(736, 0X3920) << 16);
    // 0x80735E60: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80735E64: addiu       $t1, $t1, -0x6C80
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(736, 0X3920));
    // 0x80735E68: addiu       $a3, $a3, -0x6C88
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(736, 0X3918));
    // 0x80735E6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80735E70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80735E74:
    // 0x80735E74: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80735E78: addu        $a2, $t6, $a1
    ctx->r6 = ADD32(ctx->r14, ctx->r5);
    // 0x80735E7C: lw          $t7, 0x18($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X18);
    // 0x80735E80: lw          $t2, 0x1C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X1C);
    // 0x80735E84: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80735E88: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80735E8C: bgez        $t2, L_80735EA0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80735E90: lw          $v1, 0x0($t9)
        ctx->r3 = MEM_W(ctx->r25, 0X0);
            goto L_80735EA0;
    }
    // 0x80735E90: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x80735E94: sb          $t0, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r8;
    // 0x80735E98: b           L_80735EB4
    // 0x80735E9C: sh          $zero, 0x144($v1)
    MEM_H(0X144, ctx->r3) = 0;
        goto L_80735EB4;
    // 0x80735E9C: sh          $zero, 0x144($v1)
    MEM_H(0X144, ctx->r3) = 0;
L_80735EA0:
    // 0x80735EA0: sb          $zero, 0x165($v1)
    MEM_B(0X165, ctx->r3) = 0;
    // 0x80735EA4: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80735EA8: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x80735EAC: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
    // 0x80735EB0: sh          $t5, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r13;
L_80735EB4:
    // 0x80735EB4: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80735EB8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80735EBC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80735EC0: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80735EC4: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80735EC8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80735ECC: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x80735ED0: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80735ED4: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80735ED8: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80735EDC: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80735EE0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80735EE4: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x80735EE8: lwc1        $f4, -0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, -0X4);
    // 0x80735EEC: swc1        $f4, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f4.u32l;
    // 0x80735EF0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80735EF4: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80735EF8: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x80735EFC: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80735F00: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80735F04: swc1        $f10, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f10.u32l;
    // 0x80735F08: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x80735F0C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80735F10: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x80735F14: lwc1        $f16, 0xC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80735F18: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80735F1C: swc1        $f4, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f4.u32l;
    // 0x80735F20: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80735F24: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80735F28: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80735F2C: swc1        $f6, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f6.u32l;
    // 0x80735F30: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80735F34: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80735F38: lw          $t2, 0x14($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X14);
    // 0x80735F3C: bnel        $t2, $zero, L_80735F54
    if (ctx->r10 != 0) {
        // 0x80735F40: lw          $t4, 0x138($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X138);
            goto L_80735F54;
    }
    goto skip_0;
    // 0x80735F40: lw          $t4, 0x138($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X138);
    skip_0:
    // 0x80735F44: lw          $t3, 0x138($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X138);
    // 0x80735F48: b           L_80735F5C
    // 0x80735F4C: sw          $t3, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r11;
        goto L_80735F5C;
    // 0x80735F4C: sw          $t3, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r11;
    // 0x80735F50: lw          $t4, 0x138($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X138);
L_80735F54:
    // 0x80735F54: xori        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 ^ 0X1;
    // 0x80735F58: sw          $t5, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r13;
L_80735F5C:
    // 0x80735F5C: bne         $a3, $t1, L_80735E74
    if (ctx->r7 != ctx->r9) {
        // 0x80735F60: addiu       $a1, $a1, 0x20
        ctx->r5 = ADD32(ctx->r5, 0X20);
            goto L_80735E74;
    }
    // 0x80735F60: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80735F64: jr          $ra
    // 0x80735F68: nop

    return;
    // 0x80735F68: nop

;}
RECOMP_FUNC void func_8078E534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078E534: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8078E538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078E53C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078E540: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8078E544: jal         0x8004700C
    // 0x8078E548: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8078E548: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8078E54C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8078E550: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8078E554: beq         $v0, $zero, L_8078E770
    if (ctx->r2 == 0) {
        // 0x8078E558: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8078E770;
    }
    // 0x8078E558: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8078E55C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8078E560: beq         $v0, $zero, L_8078E56C
    if (ctx->r2 == 0) {
        // 0x8078E564: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8078E56C;
    }
    // 0x8078E564: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8078E568: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
L_8078E56C:
    // 0x8078E56C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8078E570: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8078E574: beq         $v0, $zero, L_8078E580
    if (ctx->r2 == 0) {
        // 0x8078E578: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8078E580;
    }
    // 0x8078E578: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8078E57C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_8078E580:
    // 0x8078E580: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8078E584: bnel        $t8, $zero, L_8078E5AC
    if (ctx->r24 != 0) {
        // 0x8078E588: lw          $t4, 0x4($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X4);
            goto L_8078E5AC;
    }
    goto skip_0;
    // 0x8078E588: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x8078E58C: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x8078E590: lh          $t0, 0x144($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X144);
    // 0x8078E594: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8078E598: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x8078E59C: lh          $t2, 0x144($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X144);
    // 0x8078E5A0: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x8078E5A4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x8078E5A8: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
L_8078E5AC:
    // 0x8078E5AC: bnel        $t4, $zero, L_8078E61C
    if (ctx->r12 != 0) {
        // 0x8078E5B0: lwc1        $f14, 0x6C($a0)
        ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
            goto L_8078E61C;
    }
    goto skip_1;
    // 0x8078E5B0: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    skip_1:
    // 0x8078E5B4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8078E5B8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA48) << 16);
    // 0x8078E5BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8078E5C0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8078E5C4: lwc1        $f4, -0x1698($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA48));
    // 0x8078E5C8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA50) << 16);
    // 0x8078E5CC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8078E5D0: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
    // 0x8078E5D4: lwc1        $f6, -0x1690($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA50));
    // 0x8078E5D8: swc1        $f6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f6.u32l;
    // 0x8078E5DC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8078E5E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8078E5E4: jal         0x800653D8
    // 0x8078E5E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x8078E5E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8078E5EC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8078E5F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8078E5F4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8078E5F8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8078E5FC: andi        $t5, $v0, 0x46
    ctx->r13 = ctx->r2 & 0X46;
    // 0x8078E600: addiu       $t6, $t5, 0x64
    ctx->r14 = ADD32(ctx->r13, 0X64);
    // 0x8078E604: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8078E608: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x8078E60C: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x8078E610: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8078E614: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x8078E618: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
L_8078E61C:
    // 0x8078E61C: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8078E620: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8078E624: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XAA4) << 16);
    // 0x8078E628: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x8078E62C: nop

    // 0x8078E630: bc1f        L_8078E648
    if (!c1cs) {
        // 0x8078E634: nop
    
            goto L_8078E648;
    }
    // 0x8078E634: nop

    // 0x8078E638: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XAA0) << 16);
    // 0x8078E63C: lwc1        $f10, -0x1640($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XAA0));
    // 0x8078E640: b           L_8078E650
    // 0x8078E644: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
        goto L_8078E650;
    // 0x8078E644: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
L_8078E648:
    // 0x8078E648: lwc1        $f18, -0x163C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XAA4));
    // 0x8078E64C: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
L_8078E650:
    // 0x8078E650: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8078E654: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XAAC) << 16);
    // 0x8078E658: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8078E65C: nop

    // 0x8078E660: bc1f        L_8078E678
    if (!c1cs) {
        // 0x8078E664: nop
    
            goto L_8078E678;
    }
    // 0x8078E664: nop

    // 0x8078E668: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XAA8) << 16);
    // 0x8078E66C: lwc1        $f6, -0x1638($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XAA8));
    // 0x8078E670: b           L_8078E680
    // 0x8078E674: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
        goto L_8078E680;
    // 0x8078E674: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_8078E678:
    // 0x8078E678: lwc1        $f8, -0x1634($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XAAC));
    // 0x8078E67C: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
L_8078E680:
    // 0x8078E680: lui         $at, 0xC2F6
    ctx->r1 = S32(0XC2F6 << 16);
    // 0x8078E684: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8078E688: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078E68C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8078E690: lui         $at, 0xC1B4
    ctx->r1 = S32(0XC1B4 << 16);
    // 0x8078E694: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8078E698: sub.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8078E69C: lui         $at, 0xC204
    ctx->r1 = S32(0XC204 << 16);
    // 0x8078E6A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8078E6A4: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8078E6A8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8078E6AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8078E6B0: swc1        $f14, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f14.u32l;
    // 0x8078E6B4: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x8078E6B8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8078E6BC: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8078E6C0: nop

    // 0x8078E6C4: bc1fl       L_8078E6D4
    if (!c1cs) {
        // 0x8078E6C8: lwc1        $f10, 0x70($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
            goto L_8078E6D4;
    }
    goto skip_2;
    // 0x8078E6C8: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    skip_2:
    // 0x8078E6CC: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x8078E6D0: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
L_8078E6D4:
    // 0x8078E6D4: swc1        $f12, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f12.u32l;
    // 0x8078E6D8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8078E6DC: mul.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8078E6E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8078E6E4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8078E6E8: jal         0x8078E35C
    // 0x8078E6EC: nop

    func_8078E35C(rdram, ctx);
        goto after_2;
    // 0x8078E6EC: nop

    after_2:
    // 0x8078E6F0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8078E6F4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8078E6F8: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8078E6FC: lw          $t1, 0x1F4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X1F4);
    // 0x8078E700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078E704: lw          $t2, 0x1A4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A4);
    // 0x8078E708: beq         $t2, $zero, L_8078E744
    if (ctx->r10 == 0) {
        // 0x8078E70C: nop
    
            goto L_8078E744;
    }
    // 0x8078E70C: nop

    // 0x8078E710: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8078E714: lwc1        $f6, 0x84($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X84);
    // 0x8078E718: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8078E71C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8078E720: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8078E724: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8078E728: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8078E72C: nop

    // 0x8078E730: bc1f        L_8078E744
    if (!c1cs) {
        // 0x8078E734: nop
    
            goto L_8078E744;
    }
    // 0x8078E734: nop

    // 0x8078E738: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8078E73C: nop

    // 0x8078E740: swc1        $f10, 0xC4($a2)
    MEM_W(0XC4, ctx->r6) = ctx->f10.u32l;
L_8078E744:
    // 0x8078E744: lw          $t3, -0x72B0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X72B0);
    // 0x8078E748: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8078E74C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8078E750: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8078E754: bne         $t4, $at, L_8078E768
    if (ctx->r12 != ctx->r1) {
        // 0x8078E758: nop
    
            goto L_8078E768;
    }
    // 0x8078E758: nop

    // 0x8078E75C: jal         0x8078E918
    // 0x8078E760: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8078E918(rdram, ctx);
        goto after_3;
    // 0x8078E760: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_3:
    // 0x8078E764: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_8078E768:
    // 0x8078E768: jal         0x8078DF30
    // 0x8078E76C: nop

    func_8078DF30(rdram, ctx);
        goto after_4;
    // 0x8078E76C: nop

    after_4:
L_8078E770:
    // 0x8078E770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078E774: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8078E778: jr          $ra
    // 0x8078E77C: nop

    return;
    // 0x8078E77C: nop

;}
RECOMP_FUNC void func_8073AC44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073AC44: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8073AC48: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8073AC4C: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8073AC50: lbu         $t6, 0xF5C($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XF5C);
    // 0x8073AC54: lbu         $t7, 0xF5D($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0XF5D);
    // 0x8073AC58: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8073AC5C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8073AC60: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8073AC64: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8073AC68: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8073AC6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8073AC70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8073AC74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073AC78: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8073AC7C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8073AC80: sb          $t6, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r14;
    // 0x8073AC84: beq         $a1, $zero, L_8073AD48
    if (ctx->r5 == 0) {
        // 0x8073AC88: sb          $t7, 0x66($sp)
        MEM_B(0X66, ctx->r29) = ctx->r15;
            goto L_8073AD48;
    }
    // 0x8073AC88: sb          $t7, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r15;
    // 0x8073AC8C: addiu       $s6, $a1, -0x1
    ctx->r22 = ADD32(ctx->r5, -0X1);
    // 0x8073AC90: slti        $at, $s6, 0x4
    ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
    // 0x8073AC94: beq         $at, $zero, L_8073AD08
    if (ctx->r1 == 0) {
        // 0x8073AC98: addiu       $s0, $zero, 0x3
        ctx->r16 = ADD32(0, 0X3);
            goto L_8073AD08;
    }
    // 0x8073AC98: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8073AC9C: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8073ACA0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8073ACA4: andi        $t0, $t7, 0xFF
    ctx->r8 = ctx->r15 & 0XFF;
    // 0x8073ACA8: addu        $s2, $t9, $t0
    ctx->r18 = ADD32(ctx->r25, ctx->r8);
    // 0x8073ACAC: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x8073ACB0: addu        $t1, $t1, $s2
    ctx->r9 = ADD32(ctx->r9, ctx->r18);
    // 0x8073ACB4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8073ACB8: addu        $s5, $a3, $t1
    ctx->r21 = ADD32(ctx->r7, ctx->r9);
    // 0x8073ACBC: addiu       $s4, $s6, -0x1
    ctx->r20 = ADD32(ctx->r22, -0X1);
    // 0x8073ACC0: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x8073ACC4: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
L_8073ACC8:
    // 0x8073ACC8: addu        $v0, $s5, $s1
    ctx->r2 = ADD32(ctx->r21, ctx->r17);
    // 0x8073ACCC: lhu         $v1, 0xFE8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XFE8);
    // 0x8073ACD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8073ACD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8073ACD8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8073ACDC: jal         0x800696D4
    // 0x8073ACE0: sh          $v1, 0xFF0($v0)
    MEM_H(0XFF0, ctx->r2) = ctx->r3;
    func_800696D4(rdram, ctx);
        goto after_0;
    // 0x8073ACE0: sh          $v1, 0xFF0($v0)
    MEM_H(0XFF0, ctx->r2) = ctx->r3;
    after_0:
    // 0x8073ACE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8073ACE8: addiu       $a1, $s0, 0x1
    ctx->r5 = ADD32(ctx->r16, 0X1);
    // 0x8073ACEC: jal         0x80069684
    // 0x8073ACF0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80069684(rdram, ctx);
        goto after_1;
    // 0x8073ACF0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x8073ACF4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8073ACF8: bne         $s0, $s4, L_8073ACC8
    if (ctx->r16 != ctx->r20) {
        // 0x8073ACFC: addiu       $s1, $s1, -0x8
        ctx->r17 = ADD32(ctx->r17, -0X8);
            goto L_8073ACC8;
    }
    // 0x8073ACFC: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
    // 0x8073AD00: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8073AD04: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
L_8073AD08:
    // 0x8073AD08: lbu         $t2, 0x67($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X67);
    // 0x8073AD0C: lbu         $t4, 0x66($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X66);
    // 0x8073AD10: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
    // 0x8073AD14: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8073AD18: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x8073AD1C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8073AD20: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8073AD24: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8073AD28: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8073AD2C: sll         $t8, $s6, 3
    ctx->r24 = S32(ctx->r22 << 3);
    // 0x8073AD30: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8073AD34: sh          $t5, 0xFE8($t9)
    MEM_H(0XFE8, ctx->r25) = ctx->r13;
    // 0x8073AD38: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8073AD3C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8073AD40: jal         0x80069684
    // 0x8073AD44: addiu       $a2, $a2, 0x1A
    ctx->r6 = ADD32(ctx->r6, 0X1A);
    func_80069684(rdram, ctx);
        goto after_2;
    // 0x8073AD44: addiu       $a2, $a2, 0x1A
    ctx->r6 = ADD32(ctx->r6, 0X1A);
    after_2:
L_8073AD48:
    // 0x8073AD48: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8073AD4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073AD50: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8073AD54: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8073AD58: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8073AD5C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8073AD60: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8073AD64: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8073AD68: jr          $ra
    // 0x8073AD6C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8073AD6C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80776F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776F44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80776F48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80776F4C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80776F50: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80776F54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80776F58: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80776F5C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80776F60: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80776F64: nop

    // 0x80776F68: bc1fl       L_80776F88
    if (!c1cs) {
        // 0x80776F6C: lwc1        $f2, 0x8($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
            goto L_80776F88;
    }
    goto skip_0;
    // 0x80776F6C: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x80776F70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80776F74: nop

    // 0x80776F78: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80776F7C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80776F80: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80776F84: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
L_80776F88:
    // 0x80776F88: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80776F8C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80776F90: nop

    // 0x80776F94: bc1f        L_80776FAC
    if (!c1cs) {
        // 0x80776F98: nop
    
            goto L_80776FAC;
    }
    // 0x80776F98: nop

    // 0x80776F9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80776FA0: nop

    // 0x80776FA4: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80776FA8: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
L_80776FAC:
    // 0x80776FAC: jal         0x80776B7C
    // 0x80776FB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80776B7C(rdram, ctx);
        goto after_0;
    // 0x80776FB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80776FB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80776FB8: bne         $v0, $at, L_80776FE4
    if (ctx->r2 != ctx->r1) {
        // 0x80776FBC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80776FE4;
    }
    // 0x80776FBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80776FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80776FC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80776FC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80776FCC: jal         0x8077725C
    // 0x80776FD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8077725C(rdram, ctx);
        goto after_1;
    // 0x80776FD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80776FD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80776FD8: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x80776FDC: jal         0x80776CA4
    // 0x80776FE0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_80776CA4(rdram, ctx);
        goto after_2;
    // 0x80776FE0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_2:
L_80776FE4:
    // 0x80776FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80776FE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80776FEC: jr          $ra
    // 0x80776FF0: nop

    return;
    // 0x80776FF0: nop

;}
RECOMP_FUNC void func_80069684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069684: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80069688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006968C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80069690: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80069694: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x80069698: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006969C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800696A0: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800696A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800696A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800696AC: addiu       $t1, $t1, 0x7EA0
    ctx->r9 = ADD32(ctx->r9, 0X7EA0);
    // 0x800696B0: addiu       $t0, $t9, 0xFEA
    ctx->r8 = ADD32(ctx->r25, 0XFEA);
    // 0x800696B4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800696B8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800696BC: jal         0x80069508
    // 0x800696C0: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    func_80069508(rdram, ctx);
        goto after_0;
    // 0x800696C0: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_0:
    // 0x800696C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800696C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800696CC: jr          $ra
    // 0x800696D0: nop

    return;
    // 0x800696D0: nop

;}
RECOMP_FUNC void func_8002B3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B3A0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8002B3A4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8002B3A8: lw          $t6, 0xF10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XF10);
    // 0x8002B3AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002B3B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002B3B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002B3B8: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8002B3BC: lw          $v0, 0xF14($t8)
    ctx->r2 = MEM_W(ctx->r24, 0XF14);
    // 0x8002B3C0: sltiu       $at, $v0, 0x9
    ctx->r1 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x8002B3C4: bnel        $at, $zero, L_8002B3E0
    if (ctx->r1 != 0) {
        // 0x8002B3C8: sltiu       $at, $v0, 0x8
        ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
            goto L_8002B3E0;
    }
    goto skip_0;
    // 0x8002B3C8: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    skip_0:
    // 0x8002B3CC: jal         0x800679F0
    // 0x8002B3D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800679F0(rdram, ctx);
        goto after_0;
    // 0x8002B3D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8002B3D4: b           L_8002B41C
    // 0x8002B3D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002B41C;
    // 0x8002B3D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002B3DC: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
L_8002B3E0:
    // 0x8002B3E0: bne         $at, $zero, L_8002B3F8
    if (ctx->r1 != 0) {
        // 0x8002B3E4: nop
    
            goto L_8002B3F8;
    }
    // 0x8002B3E4: nop

    // 0x8002B3E8: jal         0x800679F0
    // 0x8002B3EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800679F0(rdram, ctx);
        goto after_1;
    // 0x8002B3EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8002B3F0: b           L_8002B41C
    // 0x8002B3F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002B41C;
    // 0x8002B3F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002B3F8:
    // 0x8002B3F8: beq         $v0, $zero, L_8002B410
    if (ctx->r2 == 0) {
        // 0x8002B3FC: nop
    
            goto L_8002B410;
    }
    // 0x8002B3FC: nop

    // 0x8002B400: jal         0x800679F0
    // 0x8002B404: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800679F0(rdram, ctx);
        goto after_2;
    // 0x8002B404: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8002B408: b           L_8002B41C
    // 0x8002B40C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002B41C;
    // 0x8002B40C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002B410:
    // 0x8002B410: jal         0x800679F0
    // 0x8002B414: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800679F0(rdram, ctx);
        goto after_3;
    // 0x8002B414: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x8002B418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002B41C:
    // 0x8002B41C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002B420: jr          $ra
    // 0x8002B424: nop

    return;
    // 0x8002B424: nop

;}
RECOMP_FUNC void func_807ABB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ABB78: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x807ABB7C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x807ABB80: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x807ABB84: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x807ABB88: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x807ABB8C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x807ABB90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x807ABB94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x807ABB98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807ABB9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807ABBA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807ABBA4: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x807ABBA8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x807ABBAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807ABBB0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x807ABBB4: lw          $t6, 0x168($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X168);
    // 0x807ABBB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807ABBBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807ABBC0: lw          $a3, 0x88($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X88);
    // 0x807ABBC4: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x807ABBC8: jal         0x8007711C
    // 0x807ABBCC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    func_8007711C(rdram, ctx);
        goto after_0;
    // 0x807ABBCC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_0:
    // 0x807ABBD0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x807ABBD4: jal         0x8004921C
    // 0x807ABBD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x807ABBD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x807ABBDC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x807ABBE0: jal         0x8004921C
    // 0x807ABBE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x807ABBE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x807ABBE8: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x807ABBEC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABBF0: lui         $t0, 0xE600
    ctx->r8 = S32(0XE600 << 16);
    // 0x807ABBF4: lw          $t8, 0x168($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X168);
    // 0x807ABBF8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x807ABBFC: lui         $t3, 0xFD50
    ctx->r11 = S32(0XFD50 << 16);
    // 0x807ABC00: lw          $a3, 0x80($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X80);
    // 0x807ABC04: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x807ABC08: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x807ABC0C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x807ABC10: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABC14: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x807ABC18: ori         $t6, $t6, 0x786E
    ctx->r14 = ctx->r14 | 0X786E;
    // 0x807ABC1C: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x807ABC20: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x807ABC24: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x807ABC28: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x807ABC2C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABC30: lui         $t5, 0xF550
    ctx->r13 = S32(0XF550 << 16);
    // 0x807ABC34: lui         $t2, 0x73F
    ctx->r10 = S32(0X73F << 16);
    // 0x807ABC38: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x807ABC3C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x807ABC40: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x807ABC44: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x807ABC48: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABC4C: ori         $t2, $t2, 0xF100
    ctx->r10 = ctx->r10 | 0XF100;
    // 0x807ABC50: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x807ABC54: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x807ABC58: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x807ABC5C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x807ABC60: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x807ABC64: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABC68: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x807ABC6C: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x807ABC70: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x807ABC74: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x807ABC78: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x807ABC7C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x807ABC80: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABC84: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x807ABC88: ori         $t6, $t6, 0x1000
    ctx->r14 = ctx->r14 | 0X1000;
    // 0x807ABC8C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x807ABC90: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x807ABC94: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x807ABC98: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x807ABC9C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABCA0: ori         $t7, $t7, 0x786E
    ctx->r15 = ctx->r15 | 0X786E;
    // 0x807ABCA4: lui         $t2, 0xF
    ctx->r10 = S32(0XF << 16);
    // 0x807ABCA8: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x807ABCAC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x807ABCB0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x807ABCB4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x807ABCB8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABCBC: ori         $t2, $t2, 0xC07C
    ctx->r10 = ctx->r10 | 0XC07C;
    // 0x807ABCC0: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x807ABCC4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x807ABCC8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x807ABCCC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x807ABCD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807ABCD4: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x807ABCD8: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x807ABCDC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_807ABCE0:
    // 0x807ABCE0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x807ABCE4: slti        $at, $a2, 0x1E
    ctx->r1 = SIGNED(ctx->r6) < 0X1E ? 1 : 0;
    // 0x807ABCE8: beq         $at, $zero, L_807ABD14
    if (ctx->r1 == 0) {
        // 0x807ABCEC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_807ABD14;
    }
    // 0x807ABCEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807ABCF0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABCF4: lui         $t4, 0x400
    ctx->r12 = S32(0X400 << 16);
    // 0x807ABCF8: ori         $t4, $t4, 0x81FF
    ctx->r12 = ctx->r12 | 0X81FF;
    // 0x807ABCFC: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x807ABD00: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x807ABD04: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x807ABD08: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x807ABD0C: b           L_807ABD54
    // 0x807ABD10: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
        goto L_807ABD54;
    // 0x807ABD10: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
L_807ABD14:
    // 0x807ABD14: negu        $a0, $a2
    ctx->r4 = SUB32(0, ctx->r6);
    // 0x807ABD18: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x807ABD1C: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    // 0x807ABD20: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABD24: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x807ABD28: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x807ABD2C: sll         $t7, $a0, 10
    ctx->r15 = S32(ctx->r4 << 10);
    // 0x807ABD30: or          $t2, $t7, $t9
    ctx->r10 = ctx->r15 | ctx->r25;
    // 0x807ABD34: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x807ABD38: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x807ABD3C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x807ABD40: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x807ABD44: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x807ABD48: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x807ABD4C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x807ABD50: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
L_807ABD54:
    // 0x807ABD54: slti        $at, $s7, 0x1E
    ctx->r1 = SIGNED(ctx->r23) < 0X1E ? 1 : 0;
    // 0x807ABD58: beq         $at, $zero, L_807ABF38
    if (ctx->r1 == 0) {
        // 0x807ABD5C: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_807ABF38;
    }
    // 0x807ABD5C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x807ABD60: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x807ABD64: sll         $s2, $a1, 1
    ctx->r18 = S32(ctx->r5 << 1);
    // 0x807ABD68: sll         $t8, $fp, 2
    ctx->r24 = S32(ctx->r30 << 2);
    // 0x807ABD6C: addiu       $s4, $s2, 0x2
    ctx->r20 = ADD32(ctx->r18, 0X2);
    // 0x807ABD70: addiu       $s5, $s2, 0x6
    ctx->r21 = ADD32(ctx->r18, 0X6);
    // 0x807ABD74: addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // 0x807ABD78: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x807ABD7C: addu        $s3, $t6, $t8
    ctx->r19 = ADD32(ctx->r14, ctx->r24);
    // 0x807ABD80: lw          $t7, 0x780($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X780);
L_807ABD84:
    // 0x807ABD84: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x807ABD88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807ABD8C: slt         $at, $s7, $t7
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x807ABD90: bnel        $at, $zero, L_807ABEBC
    if (ctx->r1 != 0) {
        // 0x807ABD94: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_807ABEBC;
    }
    goto skip_0;
    // 0x807ABD94: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x807ABD98: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x807ABD9C: jal         0x8004921C
    // 0x807ABDA0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x807ABDA0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    after_3:
    // 0x807ABDA4: sll         $s6, $v0, 16
    ctx->r22 = S32(ctx->r2 << 16);
    // 0x807ABDA8: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x807ABDAC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x807ABDB0: jal         0x8004921C
    // 0x807ABDB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x807ABDB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x807ABDB8: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807ABDBC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x807ABDC0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABDC4: lui         $t0, 0xE600
    ctx->r8 = S32(0XE600 << 16);
    // 0x807ABDC8: lw          $t4, 0x168($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X168);
    // 0x807ABDCC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x807ABDD0: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x807ABDD4: lw          $t5, 0x80($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X80);
    // 0x807ABDD8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x807ABDDC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x807ABDE0: mflo        $t9
    ctx->r25 = lo;
    // 0x807ABDE4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x807ABDE8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABDEC: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807ABDF0: lui         $t4, 0x705
    ctx->r12 = S32(0X705 << 16);
    // 0x807ABDF4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x807ABDF8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x807ABDFC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x807ABE00: ori         $t4, $t4, 0x796E
    ctx->r12 = ctx->r12 | 0X796E;
    // 0x807ABE04: lui         $t3, 0xF550
    ctx->r11 = S32(0XF550 << 16);
    // 0x807ABE08: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x807ABE0C: ori         $t8, $t8, 0xF100
    ctx->r24 = ctx->r24 | 0XF100;
    // 0x807ABE10: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x807ABE14: mflo        $t2
    ctx->r10 = lo;
    // 0x807ABE18: addu        $a3, $t2, $t5
    ctx->r7 = ADD32(ctx->r10, ctx->r13);
    // 0x807ABE1C: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x807ABE20: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABE24: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x807ABE28: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x807ABE2C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x807ABE30: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x807ABE34: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABE38: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x807ABE3C: lui         $t4, 0xF548
    ctx->r12 = S32(0XF548 << 16);
    // 0x807ABE40: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x807ABE44: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x807ABE48: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x807ABE4C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x807ABE50: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABE54: lui         $t2, 0x5
    ctx->r10 = S32(0X5 << 16);
    // 0x807ABE58: ori         $t2, $t2, 0x796E
    ctx->r10 = ctx->r10 | 0X796E;
    // 0x807ABE5C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x807ABE60: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x807ABE64: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x807ABE68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x807ABE6C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABE70: ori         $t4, $t4, 0x1000
    ctx->r12 = ctx->r12 | 0X1000;
    // 0x807ABE74: lui         $t8, 0xF
    ctx->r24 = S32(0XF << 16);
    // 0x807ABE78: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x807ABE7C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x807ABE80: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x807ABE84: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x807ABE88: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABE8C: ori         $t8, $t8, 0xC07C
    ctx->r24 = ctx->r24 | 0XC07C;
    // 0x807ABE90: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x807ABE94: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x807ABE98: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x807ABE9C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x807ABEA0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x807ABEA4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABEA8: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x807ABEAC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x807ABEB0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x807ABEB4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x807ABEB8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_807ABEBC:
    // 0x807ABEBC: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x807ABEC0: andi        $t9, $s4, 0xFF
    ctx->r25 = ctx->r20 & 0XFF;
    // 0x807ABEC4: sll         $t3, $t9, 8
    ctx->r11 = S32(ctx->r25 << 8);
    // 0x807ABEC8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x807ABECC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x807ABED0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x807ABED4: or          $t4, $a0, $t3
    ctx->r12 = ctx->r4 | ctx->r11;
    // 0x807ABED8: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    // 0x807ABEDC: lui         $a3, 0xBF00
    ctx->r7 = S32(0XBF00 << 16);
    // 0x807ABEE0: or          $t2, $t4, $a1
    ctx->r10 = ctx->r12 | ctx->r5;
    // 0x807ABEE4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x807ABEE8: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x807ABEEC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807ABEF0: sll         $t6, $a1, 8
    ctx->r14 = S32(ctx->r5 << 8);
    // 0x807ABEF4: andi        $t7, $s1, 0xFF
    ctx->r15 = ctx->r17 & 0XFF;
    // 0x807ABEF8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807ABEFC: or          $t8, $a0, $t6
    ctx->r24 = ctx->r4 | ctx->r14;
    // 0x807ABF00: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x807ABF04: slti        $at, $s1, 0x44
    ctx->r1 = SIGNED(ctx->r17) < 0X44 ? 1 : 0;
    // 0x807ABF08: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x807ABF0C: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x807ABF10: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x807ABF14: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x807ABF18: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x807ABF1C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x807ABF20: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x807ABF24: beq         $at, $zero, L_807ABF38
    if (ctx->r1 == 0) {
        // 0x807ABF28: sw          $a3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r7;
            goto L_807ABF38;
    }
    // 0x807ABF28: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x807ABF2C: slti        $at, $s7, 0x1E
    ctx->r1 = SIGNED(ctx->r23) < 0X1E ? 1 : 0;
    // 0x807ABF30: bnel        $at, $zero, L_807ABD84
    if (ctx->r1 != 0) {
        // 0x807ABF34: lw          $t7, 0x780($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X780);
            goto L_807ABD84;
    }
    goto skip_1;
    // 0x807ABF34: lw          $t7, 0x780($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X780);
    skip_1:
L_807ABF38:
    // 0x807ABF38: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x807ABF3C: slti        $at, $s7, 0x1E
    ctx->r1 = SIGNED(ctx->r23) < 0X1E ? 1 : 0;
    // 0x807ABF40: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x807ABF44: addiu       $t4, $t3, 0x200
    ctx->r12 = ADD32(ctx->r11, 0X200);
    // 0x807ABF48: bne         $at, $zero, L_807ABCE0
    if (ctx->r1 != 0) {
        // 0x807ABF4C: sw          $t4, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r12;
            goto L_807ABCE0;
    }
    // 0x807ABF4C: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x807ABF50: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x807ABF54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807ABF58: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807ABF5C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807ABF60: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x807ABF64: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x807ABF68: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x807ABF6C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x807ABF70: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x807ABF74: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x807ABF78: jr          $ra
    // 0x807ABF7C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x807ABF7C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_805C79B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C79B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805C79B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805C79BC: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C79C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805C79C4: lw          $t6, 0x24($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X24);
    // 0x805C79C8: bnel        $t6, $zero, L_805C79DC
    if (ctx->r14 != 0) {
        // 0x805C79CC: lw          $v0, 0x1C($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X1C);
            goto L_805C79DC;
    }
    goto skip_0;
    // 0x805C79CC: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
    skip_0:
    // 0x805C79D0: sw          $zero, 0x18($a2)
    MEM_W(0X18, ctx->r6) = 0;
    // 0x805C79D4: sw          $zero, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = 0;
    // 0x805C79D8: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
L_805C79DC:
    // 0x805C79DC: beq         $v0, $zero, L_805C79E8
    if (ctx->r2 == 0) {
        // 0x805C79E0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_805C79E8;
    }
    // 0x805C79E0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x805C79E4: sw          $t7, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r15;
L_805C79E8:
    // 0x805C79E8: lw          $a0, 0x18($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X18);
    // 0x805C79EC: lui         $t9, 0x805D
    ctx->r25 = S32(RELOC_HI16(447, 0X38A0) << 16);
    // 0x805C79F0: addiu       $t9, $t9, -0x6270
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(447, 0X38A0));
    // 0x805C79F4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x805C79F8: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x805C79FC: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x805C7A00: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x805C7A04: lw          $t4, 0x1C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X1C);
    // 0x805C7A08: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x805C7A0C: sh          $t0, 0x168($a2)
    MEM_H(0X168, ctx->r6) = ctx->r8;
    // 0x805C7A10: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x805C7A14: sh          $t1, 0x16A($a2)
    MEM_H(0X16A, ctx->r6) = ctx->r9;
    // 0x805C7A18: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x805C7A1C: sh          $t2, 0x16C($a2)
    MEM_H(0X16C, ctx->r6) = ctx->r10;
    // 0x805C7A20: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x805C7A24: bne         $t4, $zero, L_805C7AAC
    if (ctx->r12 != 0) {
        // 0x805C7A28: sh          $t3, 0x16E($a2)
        MEM_H(0X16E, ctx->r6) = ctx->r11;
            goto L_805C7AAC;
    }
    // 0x805C7A28: sh          $t3, 0x16E($a2)
    MEM_H(0X16E, ctx->r6) = ctx->r11;
    // 0x805C7A2C: lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18);
    // 0x805C7A30: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x805C7A34: bne         $at, $zero, L_805C7A58
    if (ctx->r1 != 0) {
        // 0x805C7A38: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_805C7A58;
    }
    // 0x805C7A38: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x805C7A3C: beql        $at, $zero, L_805C7A5C
    if (ctx->r1 == 0) {
        // 0x805C7A40: lw          $t0, 0x24($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X24);
            goto L_805C7A5C;
    }
    goto skip_1;
    // 0x805C7A40: lw          $t0, 0x24($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X24);
    skip_1:
    // 0x805C7A44: lw          $t5, 0x138($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X138);
    // 0x805C7A48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805C7A4C: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x805C7A50: sw          $t7, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->r15;
    // 0x805C7A54: lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18);
L_805C7A58:
    // 0x805C7A58: lw          $t0, 0x24($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X24);
L_805C7A5C:
    // 0x805C7A5C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x805C7A60: sw          $t8, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r24;
    // 0x805C7A64: bne         $t0, $zero, L_805C7A8C
    if (ctx->r8 != 0) {
        // 0x805C7A68: sw          $t9, 0x18($a2)
        MEM_W(0X18, ctx->r6) = ctx->r25;
            goto L_805C7A8C;
    }
    // 0x805C7A68: sw          $t9, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r25;
    // 0x805C7A6C: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x805C7A70: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x805C7A74: jal         0x80067BBC
    // 0x805C7A78: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805C7A78: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x805C7A7C: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x805C7A80: jal         0x80067818
    // 0x805C7A84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805C7A84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805C7A88: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_805C7A8C:
    // 0x805C7A8C: lw          $t2, 0x18($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X18);
    // 0x805C7A90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805C7A94: sw          $t1, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r9;
    // 0x805C7A98: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x805C7A9C: bnel        $at, $zero, L_805C7AB0
    if (ctx->r1 != 0) {
        // 0x805C7AA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805C7AB0;
    }
    goto skip_2;
    // 0x805C7AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x805C7AA4: sw          $zero, 0x18($a2)
    MEM_W(0X18, ctx->r6) = 0;
    // 0x805C7AA8: sw          $zero, 0x24($a2)
    MEM_W(0X24, ctx->r6) = 0;
L_805C7AAC:
    // 0x805C7AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805C7AB0:
    // 0x805C7AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805C7AB4: jr          $ra
    // 0x805C7AB8: nop

    return;
    // 0x805C7AB8: nop

;}
RECOMP_FUNC void func_8067E420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067E424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067E428: jal         0x8067E32C
    // 0x8067E42C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8067E32C(rdram, ctx);
        goto after_0;
    // 0x8067E42C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8067E430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8067E434: beq         $v0, $at, L_8067E450
    if (ctx->r2 == ctx->r1) {
        // 0x8067E438: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8067E450;
    }
    // 0x8067E438: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067E43C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8067E440: beq         $v0, $at, L_8067E460
    if (ctx->r2 == ctx->r1) {
        // 0x8067E444: nop
    
            goto L_8067E460;
    }
    // 0x8067E444: nop

    // 0x8067E448: b           L_8067E470
    // 0x8067E44C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8067E470;
    // 0x8067E44C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8067E450:
    // 0x8067E450: jal         0x8067E004
    // 0x8067E454: nop

    func_8067E004(rdram, ctx);
        goto after_1;
    // 0x8067E454: nop

    after_1:
    // 0x8067E458: b           L_8067E470
    // 0x8067E45C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8067E470;
    // 0x8067E45C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8067E460:
    // 0x8067E460: jal         0x8067E004
    // 0x8067E464: nop

    func_8067E004(rdram, ctx);
        goto after_2;
    // 0x8067E464: nop

    after_2:
    // 0x8067E468: b           L_8067E470
    // 0x8067E46C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8067E470;
    // 0x8067E46C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8067E470:
    // 0x8067E470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067E474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067E478: jr          $ra
    // 0x8067E47C: nop

    return;
    // 0x8067E47C: nop

;}
RECOMP_FUNC void func_8006E300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E300: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8006E304: addiu       $v0, $v0, -0x1CF0
    ctx->r2 = ADD32(ctx->r2, -0X1CF0);
    // 0x8006E308: jr          $ra
    // 0x8006E30C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006E30C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80518C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80518C44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80518C48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80518C4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80518C50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80518C54: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80518C58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80518C5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80518C60: lwc1        $f0, 0x200($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X200);
    // 0x80518C64: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x80518C68: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X25F4) << 16);
    // 0x80518C6C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80518C70: lw          $a2, 0x88($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X88);
    // 0x80518C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80518C78: bc1t        L_80518CB4
    if (c1cs) {
        // 0x80518C7C: addiu       $a1, $a2, 0x200
        ctx->r5 = ADD32(ctx->r6, 0X200);
            goto L_80518CB4;
    }
    // 0x80518C7C: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    // 0x80518C80: lwc1        $f4, -0x5D9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X25F4));
    // 0x80518C84: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80518C88: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80518C8C: nop

    // 0x80518C90: bc1fl       L_80518CA0
    if (!c1cs) {
        // 0x80518C94: mfc1        $a3, $f0
        ctx->r7 = (int32_t)ctx->f0.u32l;
            goto L_80518CA0;
    }
    goto skip_0;
    // 0x80518C94: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x80518C98: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80518C9C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
L_80518CA0:
    // 0x80518CA0: jal         0x8051830C
    // 0x80518CA4: swc1        $f0, 0x200($s0)
    MEM_W(0X200, ctx->r16) = ctx->f0.u32l;
    func_8051830C(rdram, ctx);
        goto after_0;
    // 0x80518CA4: swc1        $f0, 0x200($s0)
    MEM_W(0X200, ctx->r16) = ctx->f0.u32l;
    after_0:
    // 0x80518CA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80518CAC: jal         0x8004590C
    // 0x80518CB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x80518CB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
L_80518CB4:
    // 0x80518CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80518CB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80518CBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80518CC0: jr          $ra
    // 0x80518CC4: nop

    return;
    // 0x80518CC4: nop

;}
RECOMP_FUNC void func_804718BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804718BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804718C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804718C4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804718C8: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804718CC: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(158, 0X1A84) << 16);
    // 0x804718D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804718D4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804718D8: lw          $t8, 0x2F44($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(158, 0X1A84));
    // 0x804718DC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804718E0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804718E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804718E8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804718EC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804718F0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804718F4: beql        $v1, $zero, L_80471928
    if (ctx->r3 == 0) {
        // 0x804718F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80471928;
    }
    goto skip_0;
    // 0x804718F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804718FC: jalr        $v1
    // 0x80471900: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80471900: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80471904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80471908: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8047190C: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80471910: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80471914: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80471918: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8047191C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80471920: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80471924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80471928:
    // 0x80471928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8047192C: jr          $ra
    // 0x80471930: nop

    return;
    // 0x80471930: nop

;}
RECOMP_FUNC void func_8045CCEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045CCEC: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8045CCF0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8045CCF4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8045CCF8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8045CCFC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8045CD00: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8045CD04: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8045CD08: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8045CD0C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8045CD10: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8045CD14: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x8045CD18: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x8045CD1C: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045CD20: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8045CD24: lbu         $t1, -0x766A($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X766A);
    // 0x8045CD28: lw          $v0, 0x30($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X30);
    // 0x8045CD2C: lw          $s0, 0x4($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X4);
    // 0x8045CD30: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X2198) << 16);
    // 0x8045CD34: addiu       $t7, $v0, -0x2
    ctx->r15 = ADD32(ctx->r2, -0X2);
    // 0x8045CD38: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x8045CD3C: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x8045CD40: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8045CD44: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8045CD48: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8045CD4C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8045CD50: lwc1        $f0, -0x25D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X2198));
    // 0x8045CD54: beq         $t1, $zero, L_8045CE1C
    if (ctx->r9 == 0) {
        // 0x8045CD58: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_8045CE1C;
    }
    // 0x8045CD58: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8045CD5C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8045CD60: lwc1        $f4, 0x18($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X18);
    // 0x8045CD64: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8045CD68: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8045CD6C: nop

    // 0x8045CD70: bc1f        L_8045CDC4
    if (!c1cs) {
        // 0x8045CD74: nop
    
            goto L_8045CDC4;
    }
    // 0x8045CD74: nop

    // 0x8045CD78: lw          $t2, 0x38($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X38);
    // 0x8045CD7C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X2110) << 16);
    // 0x8045CD80: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045CD84: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8045CD88: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8045CD8C: lwc1        $f0, -0x2660($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X2110));
    // 0x8045CD90: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22C8) << 16);
    // 0x8045CD94: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8045CD98: nop

    // 0x8045CD9C: bc1t        L_8045CDC4
    if (c1cs) {
        // 0x8045CDA0: nop
    
            goto L_8045CDC4;
    }
    // 0x8045CDA0: nop

    // 0x8045CDA4: lwc1        $f6, -0x24A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22C8));
    // 0x8045CDA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8045CDAC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8045CDB0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8045CDB4: jal         0x8002FABC
    // 0x8045CDB8: nop

    func_8002FABC(rdram, ctx);
        goto after_0;
    // 0x8045CDB8: nop

    after_0:
    // 0x8045CDBC: b           L_8045CDD0
    // 0x8045CDC0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_8045CDD0;
    // 0x8045CDC0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8045CDC4:
    // 0x8045CDC4: jal         0x8002FABC
    // 0x8045CDC8: lui         $a1, 0xC0E0
    ctx->r5 = S32(0XC0E0 << 16);
    func_8002FABC(rdram, ctx);
        goto after_1;
    // 0x8045CDC8: lui         $a1, 0xC0E0
    ctx->r5 = S32(0XC0E0 << 16);
    after_1:
    // 0x8045CDCC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8045CDD0:
    // 0x8045CDD0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8045CDD4: jal         0x8045C6A0
    // 0x8045CDD8: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    func_8045C6A0(rdram, ctx);
        goto after_2;
    // 0x8045CDD8: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    after_2:
    // 0x8045CDDC: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x8045CDE0: jal         0x80067BBC
    // 0x8045CDE4: lw          $a1, 0x38($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8045CDE4: lw          $a1, 0x38($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X38);
    after_3:
    // 0x8045CDE8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8045CDEC: jal         0x80067818
    // 0x8045CDF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8045CDF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8045CDF4: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x8045CDF8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8045CDFC: sb          $t4, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r12;
    // 0x8045CE00: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8045CE04: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8045CE08: sb          $t5, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r13;
    // 0x8045CE0C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8045CE10: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8045CE14: b           L_8045D2D8
    // 0x8045CE18: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
        goto L_8045D2D8;
    // 0x8045CE18: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
L_8045CE1C:
    // 0x8045CE1C: lw          $v0, 0x4C($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4C);
    // 0x8045CE20: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8045CE24: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8045CE28: blez        $v0, L_8045CE34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8045CE2C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8045CE34;
    }
    // 0x8045CE2C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8045CE30: sw          $t6, 0x4C($s5)
    MEM_W(0X4C, ctx->r21) = ctx->r14;
L_8045CE34:
    // 0x8045CE34: lwc1        $f10, 0x6C($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X6C);
    // 0x8045CE38: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22CC) << 16);
    // 0x8045CE3C: lwc1        $f20, -0x24A4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22CC));
    // 0x8045CE40: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8045CE44: sltiu       $at, $t0, 0x2
    ctx->r1 = ctx->r8 < 0X2 ? 1 : 0;
    // 0x8045CE48: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8045CE4C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8045CE50: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8045CE54: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8045CE58: nop

    // 0x8045CE5C: sw          $t9, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r25;
    // 0x8045CE60: lw          $t1, 0x174($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X174);
    // 0x8045CE64: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8045CE68: lh          $t3, 0xC($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XC);
    // 0x8045CE6C: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x8045CE70: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8045CE74: lwc1        $f4, 0x4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8045CE78: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x8045CE7C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8045CE80: addiu       $s3, $t2, 0x6C
    ctx->r19 = ADD32(ctx->r10, 0X6C);
    // 0x8045CE84: addiu       $s2, $t2, 0x3C
    ctx->r18 = ADD32(ctx->r10, 0X3C);
    // 0x8045CE88: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8045CE8C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8045CE90: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8045CE94: nop

    // 0x8045CE98: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    // 0x8045CE9C: lw          $t7, 0x174($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X174);
    // 0x8045CEA0: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8045CEA4: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x8045CEA8: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x8045CEAC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8045CEB0: lwc1        $f18, 0x8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8045CEB4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8045CEB8: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8045CEBC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8045CEC0: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8045CEC4: nop

    // 0x8045CEC8: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x8045CECC: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8045CED0: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8045CED4: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8045CED8: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8045CEDC: nop

    // 0x8045CEE0: sw          $t4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r12;
    // 0x8045CEE4: lwc1        $f8, 0x28($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X28);
    // 0x8045CEE8: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8045CEEC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8045CEF0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8045CEF4: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8045CEF8: nop

    // 0x8045CEFC: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x8045CF00: lw          $t6, 0x174($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X174);
    // 0x8045CF04: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8045CF08: lh          $t9, 0xE($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XE);
    // 0x8045CF0C: lw          $t8, 0x70($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X70);
    // 0x8045CF10: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8045CF14: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8045CF18: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x8045CF1C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8045CF20: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8045CF24: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8045CF28: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8045CF2C: bne         $at, $zero, L_8045D048
    if (ctx->r1 != 0) {
        // 0x8045CF30: sw          $t3, 0x9C($sp)
        MEM_W(0X9C, ctx->r29) = ctx->r11;
            goto L_8045D048;
    }
    // 0x8045CF30: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    // 0x8045CF34: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x8045CF38: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8045CF3C: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
L_8045CF40:
    // 0x8045CF40: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8045CF44: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8045CF48: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8045CF4C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8045CF50: addiu       $t4, $s0, 0xC
    ctx->r12 = ADD32(ctx->r16, 0XC);
    // 0x8045CF54: addiu       $t5, $s0, 0x14
    ctx->r13 = ADD32(ctx->r16, 0X14);
    // 0x8045CF58: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x8045CF5C: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x8045CF60: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    // 0x8045CF64: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    // 0x8045CF68: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8045CF6C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8045CF70: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x8045CF74: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8045CF78: lwc1        $f18, 0x4($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8045CF7C: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8045CF80: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8045CF84: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8045CF88: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x8045CF8C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8045CF90: lwc1        $f10, 0x8($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8045CF94: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8045CF98: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8045CF9C: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8045CFA0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8045CFA4: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8045CFA8: jal         0x8045C760
    // 0x8045CFAC: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    func_8045C760(rdram, ctx);
        goto after_5;
    // 0x8045CFAC: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8045CFB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8045CFB4: bne         $s1, $at, L_8045CFDC
    if (ctx->r17 != ctx->r1) {
        // 0x8045CFB8: andi        $v1, $v0, 0x8
        ctx->r3 = ctx->r2 & 0X8;
            goto L_8045CFDC;
    }
    // 0x8045CFB8: andi        $v1, $v0, 0x8
    ctx->r3 = ctx->r2 & 0X8;
    // 0x8045CFBC: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8045CFC0: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8045CFC4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8045CFC8: nop

    // 0x8045CFCC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8045CFD0: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8045CFD4: b           L_8045D004
    // 0x8045CFD8: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
        goto L_8045D004;
    // 0x8045CFD8: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
L_8045CFDC:
    // 0x8045CFDC: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8045CFE0: bne         $s1, $t6, L_8045D004
    if (ctx->r17 != ctx->r14) {
        // 0x8045CFE4: nop
    
            goto L_8045D004;
    }
    // 0x8045CFE4: nop

    // 0x8045CFE8: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8045CFEC: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8045CFF0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8045CFF4: nop

    // 0x8045CFF8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8045CFFC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8045D000: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
L_8045D004:
    // 0x8045D004: beql        $v1, $zero, L_8045D034
    if (ctx->r3 == 0) {
        // 0x8045D008: lw          $t9, 0x60($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X60);
            goto L_8045D034;
    }
    goto skip_0;
    // 0x8045D008: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    skip_0:
    // 0x8045D00C: jal         0x80065954
    // 0x8045D010: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    func_80065954(rdram, ctx);
        goto after_6;
    // 0x8045D010: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    after_6:
    // 0x8045D014: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x8045D018: nop

    // 0x8045D01C: bc1fl       L_8045D034
    if (!c1cs) {
        // 0x8045D020: lw          $t9, 0x60($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X60);
            goto L_8045D034;
    }
    goto skip_1;
    // 0x8045D020: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x8045D024: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8045D028: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8045D02C: sw          $s1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r17;
    // 0x8045D030: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
L_8045D034:
    // 0x8045D034: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8045D038: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8045D03C: bnel        $s1, $t9, L_8045CF40
    if (ctx->r17 != ctx->r25) {
        // 0x8045D040: lwc1        $f0, 0x58($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
            goto L_8045CF40;
    }
    goto skip_2;
    // 0x8045D040: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    skip_2:
    // 0x8045D044: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
L_8045D048:
    // 0x8045D048: beq         $s4, $zero, L_8045D1EC
    if (ctx->r20 == 0) {
        // 0x8045D04C: lw          $t6, 0xC0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XC0);
            goto L_8045D1EC;
    }
    // 0x8045D04C: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x8045D050: sw          $s4, 0x34($s5)
    MEM_W(0X34, ctx->r21) = ctx->r20;
    // 0x8045D054: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8045D058: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8045D05C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8045D060: sw          $t1, 0x38($s5)
    MEM_W(0X38, ctx->r21) = ctx->r9;
    // 0x8045D064: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8045D068: lwc1        $f6, 0x0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8045D06C: lwc1        $f10, 0xC($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8045D070: mul.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8045D074: nop

    // 0x8045D078: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8045D07C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8045D080: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x8045D084: lw          $t3, 0x174($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X174);
    // 0x8045D088: lw          $t2, 0x18($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X18);
    // 0x8045D08C: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8045D090: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8045D094: lwc1        $f18, 0x4($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8045D098: addiu       $t4, $t2, -0x2
    ctx->r12 = ADD32(ctx->r10, -0X2);
    // 0x8045D09C: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8045D0A0: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8045D0A4: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8045D0A8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8045D0AC: lw          $t5, 0x70($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X70);
    // 0x8045D0B0: lwc1        $f18, 0x4($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8045D0B4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8045D0B8: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8045D0BC: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8045D0C0: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8045D0C4: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8045D0C8: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8045D0CC: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x8045D0D0: swc1        $f16, 0x3C($s6)
    MEM_W(0X3C, ctx->r22) = ctx->f16.u32l;
    // 0x8045D0D4: lw          $t6, 0x44($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X44);
    // 0x8045D0D8: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x8045D0DC: bne         $t6, $zero, L_8045D0F8
    if (ctx->r14 != 0) {
        // 0x8045D0E0: nop
    
            goto L_8045D0F8;
    }
    // 0x8045D0E0: nop

    // 0x8045D0E4: jal         0x8045C8E4
    // 0x8045D0E8: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    func_8045C8E4(rdram, ctx);
        goto after_7;
    // 0x8045D0E8: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    after_7:
    // 0x8045D0EC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8045D0F0: b           L_8045D128
    // 0x8045D0F4: lwc1        $f8, 0x18($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X18);
        goto L_8045D128;
    // 0x8045D0F4: lwc1        $f8, 0x18($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X18);
L_8045D0F8:
    // 0x8045D0F8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8045D0FC: lwc1        $f18, 0xC8($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0XC8);
    // 0x8045D100: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8045D104: nop

    // 0x8045D108: bc1fl       L_8045D128
    if (!c1cs) {
        // 0x8045D10C: lwc1        $f8, 0x18($s5)
        ctx->f8.u32l = MEM_W(ctx->r21, 0X18);
            goto L_8045D128;
    }
    goto skip_3;
    // 0x8045D10C: lwc1        $f8, 0x18($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X18);
    skip_3:
    // 0x8045D110: lw          $t8, 0x4C($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X4C);
    // 0x8045D114: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8045D118: bnel        $t8, $zero, L_8045D128
    if (ctx->r24 != 0) {
        // 0x8045D11C: lwc1        $f8, 0x18($s5)
        ctx->f8.u32l = MEM_W(ctx->r21, 0X18);
            goto L_8045D128;
    }
    goto skip_4;
    // 0x8045D11C: lwc1        $f8, 0x18($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X18);
    skip_4:
    // 0x8045D120: swc1        $f10, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->f10.u32l;
    // 0x8045D124: lwc1        $f8, 0x18($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X18);
L_8045D128:
    // 0x8045D128: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8045D12C: nop

    // 0x8045D130: bc1fl       L_8045D1D4
    if (!c1cs) {
        // 0x8045D134: lw          $v0, 0x1F4($s6)
        ctx->r2 = MEM_W(ctx->r22, 0X1F4);
            goto L_8045D1D4;
    }
    goto skip_5;
    // 0x8045D134: lw          $v0, 0x1F4($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1F4);
    skip_5:
    // 0x8045D138: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045D13C: lwc1        $f6, 0x14($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8045D140: lui         $t3, 0x8046
    ctx->r11 = S32(RELOC_HI16(107, 0X2110) << 16);
    // 0x8045D144: addiu       $t3, $t3, -0x2660
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(107, 0X2110));
    // 0x8045D148: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x8045D14C: nop

    // 0x8045D150: bc1fl       L_8045D1D4
    if (!c1cs) {
        // 0x8045D154: lw          $v0, 0x1F4($s6)
        ctx->r2 = MEM_W(ctx->r22, 0X1F4);
            goto L_8045D1D4;
    }
    goto skip_6;
    // 0x8045D154: lw          $v0, 0x1F4($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1F4);
    skip_6:
    // 0x8045D158: lw          $t9, 0x38($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X38);
    // 0x8045D15C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8045D160: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8045D164: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8045D168: addu        $v0, $t1, $t3
    ctx->r2 = ADD32(ctx->r9, ctx->r11);
    // 0x8045D16C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8045D170: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8045D174: nop

    // 0x8045D178: bc1fl       L_8045D1D4
    if (!c1cs) {
        // 0x8045D17C: lw          $v0, 0x1F4($s6)
        ctx->r2 = MEM_W(ctx->r22, 0X1F4);
            goto L_8045D1D4;
    }
    goto skip_7;
    // 0x8045D17C: lw          $v0, 0x1F4($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1F4);
    skip_7:
    // 0x8045D180: lwc1        $f18, 0x48($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X48);
    // 0x8045D184: c.eq.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl == ctx->f18.fl;
    // 0x8045D188: nop

    // 0x8045D18C: bc1tl       L_8045D1AC
    if (c1cs) {
        // 0x8045D190: lwc1        $f8, 0xC8($s6)
        ctx->f8.u32l = MEM_W(ctx->r22, 0XC8);
            goto L_8045D1AC;
    }
    goto skip_8;
    // 0x8045D190: lwc1        $f8, 0xC8($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0XC8);
    skip_8:
    // 0x8045D194: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    // 0x8045D198: sw          $t2, 0x4C($s5)
    MEM_W(0X4C, ctx->r21) = ctx->r10;
    // 0x8045D19C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8045D1A0: b           L_8045D1D0
    // 0x8045D1A4: swc1        $f10, 0xC8($s6)
    MEM_W(0XC8, ctx->r22) = ctx->f10.u32l;
        goto L_8045D1D0;
    // 0x8045D1A4: swc1        $f10, 0xC8($s6)
    MEM_W(0XC8, ctx->r22) = ctx->f10.u32l;
    // 0x8045D1A8: lwc1        $f8, 0xC8($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0XC8);
L_8045D1AC:
    // 0x8045D1AC: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x8045D1B0: nop

    // 0x8045D1B4: bc1fl       L_8045D1D4
    if (!c1cs) {
        // 0x8045D1B8: lw          $v0, 0x1F4($s6)
        ctx->r2 = MEM_W(ctx->r22, 0X1F4);
            goto L_8045D1D4;
    }
    goto skip_9;
    // 0x8045D1B8: lw          $v0, 0x1F4($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1F4);
    skip_9:
    // 0x8045D1BC: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x8045D1C0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8045D1C4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8045D1C8: jal         0x8045C8E4
    // 0x8045D1CC: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    func_8045C8E4(rdram, ctx);
        goto after_8;
    // 0x8045D1CC: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    after_8:
L_8045D1D0:
    // 0x8045D1D0: lw          $v0, 0x1F4($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1F4);
L_8045D1D4:
    // 0x8045D1D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8045D1D8: lw          $t4, 0x34($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X34);
    // 0x8045D1DC: ori         $t5, $t4, 0x700
    ctx->r13 = ctx->r12 | 0X700;
    // 0x8045D1E0: sw          $t5, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r13;
    // 0x8045D1E4: b           L_8045D2D8
    // 0x8045D1E8: sw          $t7, 0x44($s5)
    MEM_W(0X44, ctx->r21) = ctx->r15;
        goto L_8045D2D8;
    // 0x8045D1E8: sw          $t7, 0x44($s5)
    MEM_W(0X44, ctx->r21) = ctx->r15;
L_8045D1EC:
    // 0x8045D1EC: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8045D1F0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8045D1F4: lwc1        $f14, 0x7C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8045D1F8: jal         0x8045C8A4
    // 0x8045D1FC: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    func_8045C8A4(rdram, ctx);
        goto after_9;
    // 0x8045D1FC: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    after_9:
    // 0x8045D200: beql        $v0, $zero, L_8045D2A4
    if (ctx->r2 == 0) {
        // 0x8045D204: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_8045D2A4;
    }
    goto skip_10;
    // 0x8045D204: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_10:
    // 0x8045D208: lw          $s4, 0x34($s5)
    ctx->r20 = MEM_W(ctx->r21, 0X34);
    // 0x8045D20C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8045D210: lwc1        $f18, 0x0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8045D214: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8045D218: lwc1        $f8, 0xC($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8045D21C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8045D220: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8045D224: nop

    // 0x8045D228: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8045D22C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8045D230: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x8045D234: lw          $t8, 0x18($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X18);
    // 0x8045D238: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8045D23C: lwc1        $f4, 0x4($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8045D240: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x8045D244: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8045D248: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8045D24C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8045D250: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8045D254: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8045D258: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x8045D25C: swc1        $f4, 0x3C($s6)
    MEM_W(0X3C, ctx->r22) = ctx->f4.u32l;
    // 0x8045D260: lw          $t1, 0x4C($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X4C);
    // 0x8045D264: beq         $t1, $zero, L_8045D280
    if (ctx->r9 == 0) {
        // 0x8045D268: nop
    
            goto L_8045D280;
    }
    // 0x8045D268: nop

    // 0x8045D26C: lw          $v0, 0x1F4($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1F4);
    // 0x8045D270: lw          $t3, 0x34($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X34);
    // 0x8045D274: ori         $t2, $t3, 0x700
    ctx->r10 = ctx->r11 | 0X700;
    // 0x8045D278: b           L_8045D2D4
    // 0x8045D27C: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
        goto L_8045D2D4;
    // 0x8045D27C: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
L_8045D280:
    // 0x8045D280: jal         0x8002FABC
    // 0x8045D284: lw          $a1, 0xC8($s6)
    ctx->r5 = MEM_W(ctx->r22, 0XC8);
    func_8002FABC(rdram, ctx);
        goto after_10;
    // 0x8045D284: lw          $a1, 0xC8($s6)
    ctx->r5 = MEM_W(ctx->r22, 0XC8);
    after_10:
    // 0x8045D288: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8045D28C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8045D290: jal         0x8045C6A0
    // 0x8045D294: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    func_8045C6A0(rdram, ctx);
        goto after_11;
    // 0x8045D294: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    after_11:
    // 0x8045D298: b           L_8045D2D8
    // 0x8045D29C: sw          $zero, 0x44($s5)
    MEM_W(0X44, ctx->r21) = 0;
        goto L_8045D2D8;
    // 0x8045D29C: sw          $zero, 0x44($s5)
    MEM_W(0X44, ctx->r21) = 0;
    // 0x8045D2A0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_8045D2A4:
    // 0x8045D2A4: lwc1        $f0, 0xC8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0XC8);
    // 0x8045D2A8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8045D2AC: nop

    // 0x8045D2B0: bc1fl       L_8045D2C8
    if (!c1cs) {
        // 0x8045D2B4: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8045D2C8;
    }
    goto skip_11;
    // 0x8045D2B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_11:
    // 0x8045D2B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8045D2BC: jal         0x8002FABC
    // 0x8045D2C0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_8002FABC(rdram, ctx);
        goto after_12;
    // 0x8045D2C0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_12:
    // 0x8045D2C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8045D2C8:
    // 0x8045D2C8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8045D2CC: jal         0x8045C6A0
    // 0x8045D2D0: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    func_8045C6A0(rdram, ctx);
        goto after_13;
    // 0x8045D2D0: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    after_13:
L_8045D2D4:
    // 0x8045D2D4: sw          $zero, 0x44($s5)
    MEM_W(0X44, ctx->r21) = 0;
L_8045D2D8:
    // 0x8045D2D8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8045D2DC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8045D2E0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8045D2E4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8045D2E8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8045D2EC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8045D2F0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8045D2F4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8045D2F8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8045D2FC: jr          $ra
    // 0x8045D300: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8045D300: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_804756C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804756C0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804756C4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804756C8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804756CC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804756D0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804756D4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804756D8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804756DC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804756E0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804756E4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804756E8: jr          $ra
    // 0x804756EC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804756EC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8001A9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A9B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A9B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001A9B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001A9BC: beq         $a0, $zero, L_8001A9F4
    if (ctx->r4 == 0) {
        // 0x8001A9C0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8001A9F4;
    }
    // 0x8001A9C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A9C4: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8001A9C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001A9CC: bne         $t6, $at, L_8001A9DC
    if (ctx->r14 != ctx->r1) {
        // 0x8001A9D0: nop
    
            goto L_8001A9DC;
    }
    // 0x8001A9D0: nop

    // 0x8001A9D4: jal         0x8001A6EC
    // 0x8001A9D8: nop

    func_8001A6EC(rdram, ctx);
        goto after_0;
    // 0x8001A9D8: nop

    after_0:
L_8001A9DC:
    // 0x8001A9DC: jal         0x8001A4F4
    // 0x8001A9E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001A4F4(rdram, ctx);
        goto after_1;
    // 0x8001A9E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001A9E4: jal         0x80019BE0
    // 0x8001A9E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80019BE0(rdram, ctx);
        goto after_2;
    // 0x8001A9E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8001A9EC: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x8001A9F0: sw          $t7, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r15;
L_8001A9F4:
    // 0x8001A9F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A9F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A9FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001AA00: jr          $ra
    // 0x8001AA04: nop

    return;
    // 0x8001AA04: nop

;}
RECOMP_FUNC void func_80424B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424B60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80424B64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80424B68: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80424B6C: jal         0x804249A0
    // 0x80424B70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804249A0(rdram, ctx);
        goto after_0;
    // 0x80424B70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80424B74: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424B78: lui         $a1, 0x8042
    ctx->r5 = S32(RELOC_HI16(35, 0X3380) << 16);
    // 0x80424B7C: lui         $a2, 0x8042
    ctx->r6 = S32(RELOC_HI16(35, 0X33C4) << 16);
    // 0x80424B80: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80424B84: lw          $a3, 0xE4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE4);
    // 0x80424B88: addiu       $a2, $a2, 0x5DC4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(35, 0X33C4));
    // 0x80424B8C: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80424B90: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80424B94: addiu       $a1, $a1, 0x5D80
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(35, 0X3380));
    // 0x80424B98: jal         0x80424824
    // 0x80424B9C: addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    func_80424824(rdram, ctx);
        goto after_1;
    // 0x80424B9C: addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    after_1:
    // 0x80424BA0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424BA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80424BA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80424BAC: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(35, 0X36DC) << 16);
    // 0x80424BB0: lwc1        $f6, 0x60DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(35, 0X36DC));
    // 0x80424BB4: lwc1        $f4, 0xE4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x80424BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80424BBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80424BC0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80424BC4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80424BC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80424BCC: swc1        $f8, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f8.u32l;
    // 0x80424BD0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424BD4: lwc1        $f10, 0xE4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x80424BD8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80424BDC: nop

    // 0x80424BE0: bc1fl       L_80424BF4
    if (!c1cs) {
        // 0x80424BE4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80424BF4;
    }
    goto skip_0;
    // 0x80424BE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80424BE8: jal         0x80424E54
    // 0x80424BEC: swc1        $f0, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f0.u32l;
    func_80424E54(rdram, ctx);
        goto after_2;
    // 0x80424BEC: swc1        $f0, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f0.u32l;
    after_2:
    // 0x80424BF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80424BF4:
    // 0x80424BF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80424BF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80424BFC: jr          $ra
    // 0x80424C00: nop

    return;
    // 0x80424C00: nop

;}
RECOMP_FUNC void func_8003BF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BF88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003BF8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003BF90: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003BF94: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003BF98: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003BF9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003BFA0: jal         0x80042148
    // 0x8003BFA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042148(rdram, ctx);
        goto after_0;
    // 0x8003BFA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8003BFA8: beql        $v0, $zero, L_8003C034
    if (ctx->r2 == 0) {
        // 0x8003BFAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003C034;
    }
    goto skip_0;
    // 0x8003BFAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8003BFB0: jal         0x800433D0
    // 0x8003BFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800433D0(rdram, ctx);
        goto after_1;
    // 0x8003BFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003BFB8: jal         0x8003BF28
    // 0x8003BFBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003BF28(rdram, ctx);
        goto after_2;
    // 0x8003BFBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003BFC0: beql        $v0, $zero, L_8003C034
    if (ctx->r2 == 0) {
        // 0x8003BFC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003C034;
    }
    goto skip_1;
    // 0x8003BFC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8003BFC8: jal         0x80032D78
    // 0x8003BFCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80032D78(rdram, ctx);
        goto after_3;
    // 0x8003BFCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8003BFD0: jal         0x8003635C
    // 0x8003BFD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003635C(rdram, ctx);
        goto after_4;
    // 0x8003BFD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8003BFD8: lw          $t9, 0xA8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XA8);
    // 0x8003BFDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003BFE0: jalr        $t9
    // 0x8003BFE4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8003BFE4: nop

    after_5:
    // 0x8003BFE8: lw          $t9, 0xAC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XAC);
    // 0x8003BFEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003BFF0: jalr        $t9
    // 0x8003BFF4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8003BFF4: nop

    after_6:
    // 0x8003BFF8: beql        $v0, $zero, L_8003C034
    if (ctx->r2 == 0) {
        // 0x8003BFFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003C034;
    }
    goto skip_2;
    // 0x8003BFFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8003C000: lw          $t9, 0xB4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XB4);
    // 0x8003C004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C008: jalr        $t9
    // 0x8003C00C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8003C00C: nop

    after_7:
    // 0x8003C010: lw          $t9, 0xB8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XB8);
    // 0x8003C014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C018: jalr        $t9
    // 0x8003C01C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8003C01C: nop

    after_8:
    // 0x8003C020: lw          $t9, 0xBC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XBC);
    // 0x8003C024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C028: jalr        $t9
    // 0x8003C02C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x8003C02C: nop

    after_9:
    // 0x8003C030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003C034:
    // 0x8003C034: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003C038: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003C03C: jr          $ra
    // 0x8003C040: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003C040: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80699F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80699F38: jal         0x80699C60
    // 0x80699F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80699C60(rdram, ctx);
        goto after_0;
    // 0x80699F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80699F40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80699F44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80699F48: jal         0x8069A0F0
    // 0x80699F4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8069A0F0(rdram, ctx);
        goto after_1;
    // 0x80699F4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80699F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699F58: jr          $ra
    // 0x80699F5C: nop

    return;
    // 0x80699F5C: nop

;}
RECOMP_FUNC void func_8079FC84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079FC84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8079FC88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079FC8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079FC90: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079FC94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8079FC98: jal         0x8079FBE4
    // 0x8079FC9C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_8079FBE4(rdram, ctx);
        goto after_0;
    // 0x8079FC9C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x8079FCA0: bne         $v0, $zero, L_8079FD74
    if (ctx->r2 != 0) {
        // 0x8079FCA4: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_8079FD74;
    }
    // 0x8079FCA4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8079FCA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079FCAC: jal         0x8079FB84
    // 0x8079FCB0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_8079FB84(rdram, ctx);
        goto after_1;
    // 0x8079FCB0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_1:
    // 0x8079FCB4: beq         $v0, $zero, L_8079FD74
    if (ctx->r2 == 0) {
        // 0x8079FCB8: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_8079FD74;
    }
    // 0x8079FCB8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8079FCBC: lbu         $a2, 0x30($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X30);
    // 0x8079FCC0: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x8079FCC4: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x8079FCC8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8079FCCC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8079FCD0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8079FCD4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8079FCD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079FCDC: jal         0x807A0380
    // 0x8079FCE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807A0380(rdram, ctx);
        goto after_2;
    // 0x8079FCE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8079FCE4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8079FCE8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8079FCEC: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(838, 0X16E0) << 16);
    // 0x8079FCF0: lw          $t6, 0x18($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X18);
    // 0x8079FCF4: lbu         $t7, 0x1C($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1C);
    // 0x8079FCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079FCFC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8079FD00: lbu         $v1, 0x0($t8)
    ctx->r3 = MEM_BU(ctx->r24, 0X0);
    // 0x8079FD04: beq         $v1, $zero, L_8079FD20
    if (ctx->r3 == 0) {
        // 0x8079FD08: nop
    
            goto L_8079FD20;
    }
    // 0x8079FD08: nop

    // 0x8079FD0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8079FD10: beq         $v1, $at, L_8079FD2C
    if (ctx->r3 == ctx->r1) {
        // 0x8079FD14: nop
    
            goto L_8079FD2C;
    }
    // 0x8079FD14: nop

    // 0x8079FD18: b           L_8079FD3C
    // 0x8079FD1C: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
        goto L_8079FD3C;
    // 0x8079FD1C: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
L_8079FD20:
    // 0x8079FD20: lwc1        $f4, 0xD40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(838, 0X16E0));
    // 0x8079FD24: b           L_8079FD38
    // 0x8079FD28: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
        goto L_8079FD38;
    // 0x8079FD28: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_8079FD2C:
    // 0x8079FD2C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(838, 0X16E4) << 16);
    // 0x8079FD30: lwc1        $f6, 0xD44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(838, 0X16E4));
    // 0x8079FD34: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_8079FD38:
    // 0x8079FD38: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
L_8079FD3C:
    // 0x8079FD3C: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8079FD40: bnel        $at, $zero, L_8079FD54
    if (ctx->r1 != 0) {
        // 0x8079FD44: lbu         $t1, 0x1C($t0)
        ctx->r9 = MEM_BU(ctx->r8, 0X1C);
            goto L_8079FD54;
    }
    goto skip_0;
    // 0x8079FD44: lbu         $t1, 0x1C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1C);
    skip_0:
    // 0x8079FD48: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8079FD4C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8079FD50: lbu         $t1, 0x1C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1C);
L_8079FD54:
    // 0x8079FD54: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8079FD58: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8079FD5C: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x8079FD60: bne         $at, $zero, L_8079FD6C
    if (ctx->r1 != 0) {
        // 0x8079FD64: sb          $t2, 0x1C($t0)
        MEM_B(0X1C, ctx->r8) = ctx->r10;
            goto L_8079FD6C;
    }
    // 0x8079FD64: sb          $t2, 0x1C($t0)
    MEM_B(0X1C, ctx->r8) = ctx->r10;
    // 0x8079FD68: sb          $zero, 0x1C($t0)
    MEM_B(0X1C, ctx->r8) = 0;
L_8079FD6C:
    // 0x8079FD6C: jal         0x8079F7A0
    // 0x8079FD70: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    func_8079F7A0(rdram, ctx);
        goto after_3;
    // 0x8079FD70: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    after_3:
L_8079FD74:
    // 0x8079FD74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8079FD78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079FD7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8079FD80: jr          $ra
    // 0x8079FD84: nop

    return;
    // 0x8079FD84: nop

;}
RECOMP_FUNC void func_8064EEB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EEB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8064EEBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8064EEC0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8064EEC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8064EEC8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8064EECC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8064EED0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8064EED4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064EED8: addiu       $t6, $zero, 0x1C5C
    ctx->r14 = ADD32(0, 0X1C5C);
    // 0x8064EEDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8064EEE0: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8064EEE4: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8064EEE8: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x8064EEEC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8064EEF0: jal         0x8064EA0C
    // 0x8064EEF4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8064EA0C(rdram, ctx);
        goto after_0;
    // 0x8064EEF4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8064EEF8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8064EEFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064EF00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064EF04: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8064EF08: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8064EF0C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8064EF10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8064EF14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8064EF18: jr          $ra
    // 0x8064EF1C: nop

    return;
    // 0x8064EF1C: nop

;}
RECOMP_FUNC void func_80791A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791A8C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80791A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80791A94: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80791A98: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80791A9C: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x80791AA0: lui         $t9, 0x8079
    ctx->r25 = S32(RELOC_HI16(817, 0X766C) << 16);
    // 0x80791AA4: addiu       $t9, $t9, 0x79BC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(817, 0X766C));
    // 0x80791AA8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80791AAC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80791AB0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80791AB4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80791AB8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80791ABC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80791AC0: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80791AC4: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x80791AC8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80791ACC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80791AD0: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80791AD4: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80791AD8: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x80791ADC: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80791AE0: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x80791AE4: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x80791AE8: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x80791AEC: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x80791AF0: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x80791AF4: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80791AF8: bne         $t3, $zero, L_80791B28
    if (ctx->r11 != 0) {
        // 0x80791AFC: nop
    
            goto L_80791B28;
    }
    // 0x80791AFC: nop

    // 0x80791B00: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80791B04: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80791B08: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80791B0C: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x80791B10: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x80791B14: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80791B18: bne         $t9, $at, L_80791B28
    if (ctx->r25 != ctx->r1) {
        // 0x80791B1C: nop
    
            goto L_80791B28;
    }
    // 0x80791B1C: nop

    // 0x80791B20: jal         0x807907AC
    // 0x80791B24: addiu       $a1, $zero, 0xB5
    ctx->r5 = ADD32(0, 0XB5);
    func_807907AC(rdram, ctx);
        goto after_0;
    // 0x80791B24: addiu       $a1, $zero, 0xB5
    ctx->r5 = ADD32(0, 0XB5);
    after_0:
L_80791B28:
    // 0x80791B28: jal         0x80790A1C
    // 0x80791B2C: nop

    func_80790A1C(rdram, ctx);
        goto after_1;
    // 0x80791B2C: nop

    after_1:
    // 0x80791B30: beq         $v0, $zero, L_80791B8C
    if (ctx->r2 == 0) {
        // 0x80791B34: addiu       $s0, $s1, 0xC4
        ctx->r16 = ADD32(ctx->r17, 0XC4);
            goto L_80791B8C;
    }
    // 0x80791B34: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x80791B38: lw          $v0, 0x1E4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1E4);
    // 0x80791B3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80791B40: beql        $v0, $at, L_80791B90
    if (ctx->r2 == ctx->r1) {
        // 0x80791B44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80791B90;
    }
    goto skip_0;
    // 0x80791B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80791B48: beq         $v0, $zero, L_80791B8C
    if (ctx->r2 == 0) {
        // 0x80791B4C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80791B8C;
    }
    // 0x80791B4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80791B50: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x80791B54: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    // 0x80791B58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791B5C: jal         0x8079393C
    // 0x80791B60: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80791B60: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_2:
    // 0x80791B64: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80791B68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80791B6C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80791B70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80791B74: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80791B78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80791B7C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80791B80: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80791B84: b           L_80791BDC
    // 0x80791B88: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
        goto L_80791BDC;
    // 0x80791B88: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
L_80791B8C:
    // 0x80791B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80791B90:
    // 0x80791B90: jal         0x807903C4
    // 0x80791B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_3;
    // 0x80791B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80791B98: jal         0x80790714
    // 0x80791B9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80790714(rdram, ctx);
        goto after_4;
    // 0x80791B9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80791BA0: beq         $v0, $zero, L_80791BDC
    if (ctx->r2 == 0) {
        // 0x80791BA4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80791BDC;
    }
    // 0x80791BA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80791BA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791BAC: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80791BB0: jal         0x8079393C
    // 0x80791BB4: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_8079393C(rdram, ctx);
        goto after_5;
    // 0x80791BB4: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_5:
    // 0x80791BB8: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80791BBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80791BC0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80791BC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80791BC8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80791BCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80791BD0: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80791BD4: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
    // 0x80791BD8: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
L_80791BDC:
    // 0x80791BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80791BE0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80791BE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80791BE8: jr          $ra
    // 0x80791BEC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80791BEC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80523060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80523060: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80523064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80523068: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052306C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80523070: jal         0x8004700C
    // 0x80523074: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80523074: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80523078: beq         $v0, $zero, L_805230E0
    if (ctx->r2 == 0) {
        // 0x8052307C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_805230E0;
    }
    // 0x8052307C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80523080: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80523084: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80523088: beq         $t8, $zero, L_805230AC
    if (ctx->r24 == 0) {
        // 0x8052308C: nop
    
            goto L_805230AC;
    }
    // 0x8052308C: nop

    // 0x80523090: lbu         $t9, 0x165($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X165);
    // 0x80523094: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80523098: bne         $t9, $zero, L_805230AC
    if (ctx->r25 != 0) {
        // 0x8052309C: nop
    
            goto L_805230AC;
    }
    // 0x8052309C: nop

    // 0x805230A0: jal         0x80523830
    // 0x805230A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80523830(rdram, ctx);
        goto after_1;
    // 0x805230A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x805230A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_805230AC:
    // 0x805230AC: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x805230B0: lw          $t0, -0x72E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X72E0);
    // 0x805230B4: lbu         $v0, 0x165($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X165);
    // 0x805230B8: beq         $t0, $zero, L_805230D0
    if (ctx->r8 == 0) {
        // 0x805230BC: nop
    
            goto L_805230D0;
    }
    // 0x805230BC: nop

    // 0x805230C0: beq         $v0, $zero, L_805230D0
    if (ctx->r2 == 0) {
        // 0x805230C4: nop
    
            goto L_805230D0;
    }
    // 0x805230C4: nop

    // 0x805230C8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805230CC: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
L_805230D0:
    // 0x805230D0: bnel        $v0, $zero, L_805230E4
    if (ctx->r2 != 0) {
        // 0x805230D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805230E4;
    }
    goto skip_0;
    // 0x805230D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805230D8: jal         0x80522AD4
    // 0x805230DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80522AD4(rdram, ctx);
        goto after_2;
    // 0x805230DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_805230E0:
    // 0x805230E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805230E4:
    // 0x805230E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805230E8: jr          $ra
    // 0x805230EC: nop

    return;
    // 0x805230EC: nop

;}
RECOMP_FUNC void func_80038620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038628: jal         0x80021958
    // 0x8003862C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x8003862C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038630: bne         $v0, $zero, L_80038640
    if (ctx->r2 != 0) {
        // 0x80038634: nop
    
            goto L_80038640;
    }
    // 0x80038634: nop

    // 0x80038638: b           L_80038674
    // 0x8003863C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038674;
    // 0x8003863C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038640:
    // 0x80038640: jal         0x800415FC
    // 0x80038644: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80038644: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80038648: beq         $v0, $zero, L_80038658
    if (ctx->r2 == 0) {
        // 0x8003864C: nop
    
            goto L_80038658;
    }
    // 0x8003864C: nop

    // 0x80038650: b           L_80038674
    // 0x80038654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038674;
    // 0x80038654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038658:
    // 0x80038658: jal         0x80037C2C
    // 0x8003865C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80037C2C(rdram, ctx);
        goto after_2;
    // 0x8003865C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80038660: bnel        $v0, $zero, L_80038674
    if (ctx->r2 != 0) {
        // 0x80038664: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80038674;
    }
    goto skip_0;
    // 0x80038664: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80038668: b           L_80038674
    // 0x8003866C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038674;
    // 0x8003866C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038670: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80038674:
    // 0x80038674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003867C: jr          $ra
    // 0x80038680: nop

    return;
    // 0x80038680: nop

;}
RECOMP_FUNC void func_8079BF84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079BF84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079BF88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079BF8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8079BF90: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8079BF94: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x8079BF98: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8079BF9C: bnel        $t6, $at, L_8079BFE8
    if (ctx->r14 != ctx->r1) {
        // 0x8079BFA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079BFE8;
    }
    goto skip_0;
    // 0x8079BFA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8079BFA4: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x8079BFA8: beql        $t7, $zero, L_8079BFE8
    if (ctx->r15 == 0) {
        // 0x8079BFAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079BFE8;
    }
    goto skip_1;
    // 0x8079BFAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8079BFB0: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x8079BFB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8079BFB8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8079BFBC: beq         $t8, $at, L_8079BFE4
    if (ctx->r24 == ctx->r1) {
        // 0x8079BFC0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8079BFE4;
    }
    // 0x8079BFC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079BFC4: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
    // 0x8079BFC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8079BFCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8079BFD0: jal         0x8079C140
    // 0x8079BFD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8079C140(rdram, ctx);
        goto after_0;
    // 0x8079BFD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8079BFD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079BFDC: jal         0x8079B95C
    // 0x8079BFE0: addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    func_8079B95C(rdram, ctx);
        goto after_1;
    // 0x8079BFE0: addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    after_1:
L_8079BFE4:
    // 0x8079BFE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079BFE8:
    // 0x8079BFE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079BFEC: jr          $ra
    // 0x8079BFF0: nop

    return;
    // 0x8079BFF0: nop

;}
RECOMP_FUNC void func_8042EB3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EB3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042EB40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8042EB44: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8042EB48: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8042EB4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042EB50: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8042EB54: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8042EB58: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8042EB5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8042EB60: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8042EB64: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042EB68: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8042EB6C: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(56, 0X32C4) << 16);
    // 0x8042EB70: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8042EB74: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8042EB78: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8042EB7C: lw          $t2, 0x13A4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(56, 0X32C4));
    // 0x8042EB80: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8042EB84: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8042EB88: jal         0x8042E750
    // 0x8042EB8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042E750(rdram, ctx);
        goto after_0;
    // 0x8042EB8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042EB90: jal         0x8042E7AC
    // 0x8042EB94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8042E7AC(rdram, ctx);
        goto after_1;
    // 0x8042EB94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8042EB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042EB9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042EBA0: jr          $ra
    // 0x8042EBA4: nop

    return;
    // 0x8042EBA4: nop

;}
RECOMP_FUNC void func_806EE384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE384: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EE388: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806EE38C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x806EE390: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806EE394: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x806EE398: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806EE39C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806EE3A0: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x806EE3A4: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806EE3A8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806EE3AC: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x806EE3B0: swc1        $f16, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f16.u32l;
    // 0x806EE3B4: jr          $ra
    // 0x806EE3B8: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x806EE3B8: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_805D7910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D7914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D7918: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805D791C: addiu       $at, $zero, 0x4536
    ctx->r1 = ADD32(0, 0X4536);
    // 0x805D7920: beq         $v0, $at, L_805D7950
    if (ctx->r2 == ctx->r1) {
        // 0x805D7924: addiu       $at, $zero, 0x4537
        ctx->r1 = ADD32(0, 0X4537);
            goto L_805D7950;
    }
    // 0x805D7924: addiu       $at, $zero, 0x4537
    ctx->r1 = ADD32(0, 0X4537);
    // 0x805D7928: beq         $v0, $at, L_805D7960
    if (ctx->r2 == ctx->r1) {
        // 0x805D792C: addiu       $at, $zero, 0x453B
        ctx->r1 = ADD32(0, 0X453B);
            goto L_805D7960;
    }
    // 0x805D792C: addiu       $at, $zero, 0x453B
    ctx->r1 = ADD32(0, 0X453B);
    // 0x805D7930: beq         $v0, $at, L_805D7970
    if (ctx->r2 == ctx->r1) {
        // 0x805D7934: addiu       $at, $zero, 0x4565
        ctx->r1 = ADD32(0, 0X4565);
            goto L_805D7970;
    }
    // 0x805D7934: addiu       $at, $zero, 0x4565
    ctx->r1 = ADD32(0, 0X4565);
    // 0x805D7938: beq         $v0, $at, L_805D7980
    if (ctx->r2 == ctx->r1) {
        // 0x805D793C: addiu       $at, $zero, 0x4590
        ctx->r1 = ADD32(0, 0X4590);
            goto L_805D7980;
    }
    // 0x805D793C: addiu       $at, $zero, 0x4590
    ctx->r1 = ADD32(0, 0X4590);
    // 0x805D7940: beq         $v0, $at, L_805D7990
    if (ctx->r2 == ctx->r1) {
        // 0x805D7944: nop
    
            goto L_805D7990;
    }
    // 0x805D7944: nop

    // 0x805D7948: b           L_805D799C
    // 0x805D794C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805D799C;
    // 0x805D794C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D7950:
    // 0x805D7950: jal         0x805D79EC
    // 0x805D7954: nop

    func_805D79EC(rdram, ctx);
        goto after_0;
    // 0x805D7954: nop

    after_0:
    // 0x805D7958: b           L_805D799C
    // 0x805D795C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805D799C;
    // 0x805D795C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D7960:
    // 0x805D7960: jal         0x805D7DE0
    // 0x805D7964: nop

    func_805D7DE0(rdram, ctx);
        goto after_1;
    // 0x805D7964: nop

    after_1:
    // 0x805D7968: b           L_805D799C
    // 0x805D796C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805D799C;
    // 0x805D796C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D7970:
    // 0x805D7970: jal         0x805D7B94
    // 0x805D7974: nop

    func_805D7B94(rdram, ctx);
        goto after_2;
    // 0x805D7974: nop

    after_2:
    // 0x805D7978: b           L_805D799C
    // 0x805D797C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805D799C;
    // 0x805D797C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D7980:
    // 0x805D7980: jal         0x805D7E6C
    // 0x805D7984: nop

    func_805D7E6C(rdram, ctx);
        goto after_3;
    // 0x805D7984: nop

    after_3:
    // 0x805D7988: b           L_805D799C
    // 0x805D798C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805D799C;
    // 0x805D798C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D7990:
    // 0x805D7990: jal         0x805D7EF8
    // 0x805D7994: nop

    func_805D7EF8(rdram, ctx);
        goto after_4;
    // 0x805D7994: nop

    after_4:
    // 0x805D7998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D799C:
    // 0x805D799C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D79A0: jr          $ra
    // 0x805D79A4: nop

    return;
    // 0x805D79A4: nop

;}
RECOMP_FUNC void func_80053790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053790: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80053794: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80053798: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005379C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800537A0: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x800537A4: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x800537A8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800537AC: blez        $a3, L_8005380C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800537B0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005380C;
    }
    // 0x800537B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800537B4: andi        $a1, $a3, 0x3
    ctx->r5 = ctx->r7 & 0X3;
    // 0x800537B8: beq         $a1, $zero, L_800537E0
    if (ctx->r5 == 0) {
        // 0x800537BC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800537E0;
    }
    // 0x800537BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800537C0: sll         $t7, $zero, 1
    ctx->r15 = S32(0 << 1);
    // 0x800537C4: addu        $v0, $a2, $t7
    ctx->r2 = ADD32(ctx->r6, ctx->r15);
L_800537C8:
    // 0x800537C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800537CC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800537D0: bne         $a0, $v1, L_800537C8
    if (ctx->r4 != ctx->r3) {
        // 0x800537D4: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_800537C8;
    }
    // 0x800537D4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800537D8: beq         $v1, $s0, L_8005380C
    if (ctx->r3 == ctx->r16) {
        // 0x800537DC: nop
    
            goto L_8005380C;
    }
    // 0x800537DC: nop

L_800537E0:
    // 0x800537E0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800537E4: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800537E8: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x800537EC: addu        $a0, $t0, $t8
    ctx->r4 = ADD32(ctx->r8, ctx->r24);
    // 0x800537F0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
L_800537F4:
    // 0x800537F4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800537F8: sh          $zero, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = 0;
    // 0x800537FC: sh          $zero, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = 0;
    // 0x80053800: sh          $zero, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = 0;
    // 0x80053804: bne         $v0, $a0, L_800537F4
    if (ctx->r2 != ctx->r4) {
        // 0x80053808: sh          $zero, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = 0;
            goto L_800537F4;
    }
    // 0x80053808: sh          $zero, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = 0;
L_8005380C:
    // 0x8005380C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80053810: lw          $t1, 0x60D0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X60D0);
    // 0x80053814: bne         $t1, $zero, L_80053828
    if (ctx->r9 != 0) {
        // 0x80053818: nop
    
            goto L_80053828;
    }
    // 0x80053818: nop

    // 0x8005381C: jal         0x80052CDC
    // 0x80053820: nop

    func_80052CDC(rdram, ctx);
        goto after_0;
    // 0x80053820: nop

    after_0:
    // 0x80053824: beq         $v0, $zero, L_800538A8
    if (ctx->r2 == 0) {
        // 0x80053828: lui         $t2, 0x800A
        ctx->r10 = S32(0X800A << 16);
            goto L_800538A8;
    }
L_80053828:
    // 0x80053828: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8005382C: lw          $t2, 0x60D0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X60D0);
    // 0x80053830: lw          $t3, 0x16C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X16C);
    // 0x80053834: lw          $v0, 0x1B0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X1B0);
    // 0x80053838: beql        $v0, $zero, L_800538AC
    if (ctx->r2 == 0) {
        // 0x8005383C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800538AC;
    }
    goto skip_0;
    // 0x8005383C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80053840: lw          $t4, 0x20($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X20);
    // 0x80053844: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80053848: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x8005384C: beql        $t5, $zero, L_800538AC
    if (ctx->r13 == 0) {
        // 0x80053850: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800538AC;
    }
    goto skip_1;
    // 0x80053850: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80053854: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80053858: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8005385C: nop

    // 0x80053860: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80053864: jal         0x8006A99C
    // 0x80053868: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x80053868: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8005386C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80053870: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x80053874: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80053878: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8005387C: nop

    // 0x80053880: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80053884: jal         0x8006A99C
    // 0x80053888: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_2;
    // 0x80053888: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x8005388C: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80053890: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80053894: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80053898: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x8005389C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800538A0: jal         0x8006AFA0
    // 0x800538A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8006AFA0(rdram, ctx);
        goto after_3;
    // 0x800538A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
L_800538A8:
    // 0x800538A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800538AC:
    // 0x800538AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800538B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800538B4: jr          $ra
    // 0x800538B8: nop

    return;
    // 0x800538B8: nop

;}
RECOMP_FUNC void func_805369F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805369F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805369FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80536A00: jal         0x805367A4
    // 0x80536A04: nop

    func_805367A4(rdram, ctx);
        goto after_0;
    // 0x80536A04: nop

    after_0:
    // 0x80536A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80536A0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80536A10: jr          $ra
    // 0x80536A14: nop

    return;
    // 0x80536A14: nop

;}
RECOMP_FUNC void func_80028038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002803C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028040: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80028044: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80028048: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002804C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80028050: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80028054: lw          $t8, -0x24FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X24FC);
    // 0x80028058: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8002805C: lbu         $t2, 0x1F8($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1F8);
    // 0x80028060: sw          $t8, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->r24;
    // 0x80028064: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x80028068: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8002806C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80028070: lw          $t1, -0x23BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X23BC);
    // 0x80028074: bne         $t2, $zero, L_80028088
    if (ctx->r10 != 0) {
        // 0x80028078: sw          $t1, 0xA0($v1)
        MEM_W(0XA0, ctx->r3) = ctx->r9;
            goto L_80028088;
    }
    // 0x80028078: sw          $t1, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->r9;
    // 0x8002807C: lw          $t3, 0x12EC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X12EC);
    // 0x80028080: beql        $t3, $zero, L_80028098
    if (ctx->r11 == 0) {
        // 0x80028084: lw          $t5, 0x9C($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X9C);
            goto L_80028098;
    }
    goto skip_0;
    // 0x80028084: lw          $t5, 0x9C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X9C);
    skip_0:
L_80028088:
    // 0x80028088: lw          $t4, 0xA0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA0);
    // 0x8002808C: b           L_8002809C
    // 0x80028090: sw          $t4, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r12;
        goto L_8002809C;
    // 0x80028090: sw          $t4, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r12;
    // 0x80028094: lw          $t5, 0x9C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X9C);
L_80028098:
    // 0x80028098: sw          $t5, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r13;
L_8002809C:
    // 0x8002809C: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x800280A0: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x800280A4: beql        $a1, $zero, L_800280E8
    if (ctx->r5 == 0) {
        // 0x800280A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800280E8;
    }
    goto skip_1;
    // 0x800280A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800280AC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800280B0: jalr        $a1
    // 0x800280B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_0;
    // 0x800280B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800280B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800280BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800280C0: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x800280C4: lw          $v0, 0x14C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C);
    // 0x800280C8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800280CC: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800280D0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800280D4: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800280D8: sw          $v0, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->r2;
    // 0x800280DC: sh          $t0, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r8;
    // 0x800280E0: sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // 0x800280E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800280E8:
    // 0x800280E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800280EC: jr          $ra
    // 0x800280F0: nop

    return;
    // 0x800280F0: nop

;}
RECOMP_FUNC void func_8005CEBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CEBC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005CEC0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005CEC4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005CEC8: addiu       $at, $zero, 0x4024
    ctx->r1 = ADD32(0, 0X4024);
    // 0x8005CECC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005CED0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005CED4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8005CED8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8005CEDC: bne         $a0, $at, L_8005CEFC
    if (ctx->r4 != ctx->r1) {
        // 0x8005CEE0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8005CEFC;
    }
    // 0x8005CEE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8005CEE4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8005CEE8: lbu         $t6, 0x62C0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X62C0);
    // 0x8005CEEC: beq         $t6, $zero, L_8005CEFC
    if (ctx->r14 == 0) {
        // 0x8005CEF0: nop
    
            goto L_8005CEFC;
    }
    // 0x8005CEF0: nop

    // 0x8005CEF4: b           L_8005D064
    // 0x8005CEF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005D064;
    // 0x8005CEF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005CEFC:
    // 0x8005CEFC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8005CF00: lw          $t7, -0x71A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71A8);
    // 0x8005CF04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CF08: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8005CF0C: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x8005CF10: bnel        $t9, $at, L_8005CF20
    if (ctx->r25 != ctx->r1) {
        // 0x8005CF14: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_8005CF20;
    }
    goto skip_0;
    // 0x8005CF14: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    skip_0:
    // 0x8005CF18: addiu       $a1, $a1, 0xB1
    ctx->r5 = ADD32(ctx->r5, 0XB1);
    // 0x8005CF1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_8005CF20:
    // 0x8005CF20: sh          $a0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r4;
    // 0x8005CF24: jal         0x80047090
    // 0x8005CF28: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8005CF28: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005CF2C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8005CF30: bne         $v0, $at, L_8005CF40
    if (ctx->r2 != ctx->r1) {
        // 0x8005CF34: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8005CF40;
    }
    // 0x8005CF34: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8005CF38: b           L_8005D064
    // 0x8005CF3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005D064;
    // 0x8005CF3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005CF40:
    // 0x8005CF40: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8005CF44: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005CF48: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8005CF4C: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8005CF50: ori         $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 | 0X2000;
    // 0x8005CF54: or          $a0, $t2, $v1
    ctx->r4 = ctx->r10 | ctx->r3;
    // 0x8005CF58: jal         0x8004613C
    // 0x8005CF5C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8005CF5C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x8005CF60: lui         $t3, 0x8006
    ctx->r11 = S32(0X8006 << 16);
    // 0x8005CF64: addiu       $t3, $t3, -0x3420
    ctx->r11 = ADD32(ctx->r11, -0X3420);
    // 0x8005CF68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005CF6C: sw          $t3, 0x1F8($v0)
    MEM_W(0X1F8, ctx->r2) = ctx->r11;
    // 0x8005CF70: jal         0x80064DD0
    // 0x8005CF74: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_80064DD0(rdram, ctx);
        goto after_2;
    // 0x8005CF74: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_2:
    // 0x8005CF78: bne         $v0, $zero, L_8005CF90
    if (ctx->r2 != 0) {
        // 0x8005CF7C: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8005CF90;
    }
    // 0x8005CF7C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8005CF80: jal         0x800445A4
    // 0x8005CF84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x8005CF84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8005CF88: b           L_8005D064
    // 0x8005CF8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005D064;
    // 0x8005CF8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005CF90:
    // 0x8005CF90: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005CF94: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8005CF98: jal         0x800657CC
    // 0x8005CF9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_4;
    // 0x8005CF9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8005CFA0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8005CFA4: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005CFA8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8005CFAC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8005CFB0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8005CFB4: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005CFB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CFBC: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
    // 0x8005CFC0: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005CFC4: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x8005CFC8: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005CFCC: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
    // 0x8005CFD0: jal         0x8005CC90
    // 0x8005CFD4: sb          $zero, 0x164($s0)
    MEM_B(0X164, ctx->r16) = 0;
    func_8005CC90(rdram, ctx);
        goto after_5;
    // 0x8005CFD4: sb          $zero, 0x164($s0)
    MEM_B(0X164, ctx->r16) = 0;
    after_5:
    // 0x8005CFD8: bne         $v0, $zero, L_8005CFF0
    if (ctx->r2 != 0) {
        // 0x8005CFDC: nop
    
            goto L_8005CFF0;
    }
    // 0x8005CFDC: nop

    // 0x8005CFE0: jal         0x800445A4
    // 0x8005CFE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x8005CFE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8005CFE8: b           L_8005D064
    // 0x8005CFEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005D064;
    // 0x8005CFEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005CFF0:
    // 0x8005CFF0: jal         0x80045730
    // 0x8005CFF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80045730(rdram, ctx);
        goto after_7;
    // 0x8005CFF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8005CFF8: bne         $v0, $zero, L_8005D010
    if (ctx->r2 != 0) {
        // 0x8005CFFC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8005D010;
    }
    // 0x8005CFFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005D000: jal         0x800445A4
    // 0x8005D004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x8005D004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8005D008: b           L_8005D064
    // 0x8005D00C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005D064;
    // 0x8005D00C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005D010:
    // 0x8005D010: lw          $t2, 0x16C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X16C);
    // 0x8005D014: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8005D018: sb          $t0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r8;
    // 0x8005D01C: addiu       $t1, $t1, 0x62C4
    ctx->r9 = ADD32(ctx->r9, 0X62C4);
    // 0x8005D020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005D028: jal         0x8005D110
    // 0x8005D02C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    func_8005D110(rdram, ctx);
        goto after_9;
    // 0x8005D02C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    after_9:
    // 0x8005D030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005D034: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x8005D038: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D03C: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x8005D040: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
    // 0x8005D044: lhu         $t3, 0x32($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X32);
    // 0x8005D048: addiu       $at, $zero, 0x4024
    ctx->r1 = ADD32(0, 0X4024);
    // 0x8005D04C: sh          $t3, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = ctx->r11;
    // 0x8005D050: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8005D054: bne         $t5, $at, L_8005D060
    if (ctx->r13 != ctx->r1) {
        // 0x8005D058: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_8005D060;
    }
    // 0x8005D058: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005D05C: sb          $v0, 0x62C0($at)
    MEM_B(0X62C0, ctx->r1) = ctx->r2;
L_8005D060:
    // 0x8005D060: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8005D064:
    // 0x8005D064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D068: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D06C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005D070: jr          $ra
    // 0x8005D074: nop

    return;
    // 0x8005D074: nop

;}
RECOMP_FUNC void func_8044EEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044EEF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044EEFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044EF00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8044EF04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8044EF08: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8044EF0C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x8044EF10: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8044EF14: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8044EF18: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8044EF1C: lw          $t7, 0x6A28($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A28);
    // 0x8044EF20: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8044EF24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8044EF28: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8044EF2C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8044EF30: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x8044EF34: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8044EF38: jalr        $t9
    // 0x8044EF3C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8044EF3C: nop

    after_0:
    // 0x8044EF40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044EF44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044EF48: jr          $ra
    // 0x8044EF4C: nop

    return;
    // 0x8044EF4C: nop

;}
RECOMP_FUNC void func_80073694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073694: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80073698: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007369C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800736A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800736A4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800736A8: jal         0x800735A4
    // 0x800736AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800735A4(rdram, ctx);
        goto after_0;
    // 0x800736AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800736B0: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800736B4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800736B8: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800736BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800736C0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800736C4: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800736C8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800736CC: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800736D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800736D4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800736D8: bne         $at, $zero, L_800736F4
    if (ctx->r1 != 0) {
        // 0x800736DC: sw          $t1, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r9;
            goto L_800736F4;
    }
    // 0x800736DC: sw          $t1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r9;
    // 0x800736E0: jal         0x800735A4
    // 0x800736E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800735A4(rdram, ctx);
        goto after_1;
    // 0x800736E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800736E8: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x800736EC: addiu       $v0, $t2, -0x20
    ctx->r2 = ADD32(ctx->r10, -0X20);
    // 0x800736F0: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_800736F4:
    // 0x800736F4: bgez        $v0, L_80073714
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800736F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80073714;
    }
    // 0x800736F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800736FC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80073700: jal         0x800735A4
    // 0x80073704: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800735A4(rdram, ctx);
        goto after_2;
    // 0x80073704: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80073708: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x8007370C: addiu       $t5, $t4, 0x20
    ctx->r13 = ADD32(ctx->r12, 0X20);
    // 0x80073710: sw          $t5, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r13;
L_80073714:
    // 0x80073714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80073718: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007371C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80073720: jr          $ra
    // 0x80073724: nop

    return;
    // 0x80073724: nop

;}
RECOMP_FUNC void func_804A4CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4CD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804A4CDC: lui         $at, 0x804B
    ctx->r1 = S32(RELOC_HI16(179, 0X11230) << 16);
    // 0x804A4CE0: lwc1        $f0, 0x5E40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(179, 0X11230));
    // 0x804A4CE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804A4CE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804A4CEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x804A4CF0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x804A4CF4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x804A4CF8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x804A4CFC: addiu       $t6, $zero, 0x8E8
    ctx->r14 = ADD32(0, 0X8E8);
    // 0x804A4D00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x804A4D04: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x804A4D08: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x804A4D0C: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x804A4D10: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x804A4D14: jal         0x804A4C1C
    // 0x804A4D18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_804A4C1C(rdram, ctx);
        goto after_0;
    // 0x804A4D18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x804A4D1C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x804A4D20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804A4D24: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804A4D28: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x804A4D2C: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x804A4D30: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x804A4D34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804A4D38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804A4D3C: jr          $ra
    // 0x804A4D40: nop

    return;
    // 0x804A4D40: nop

;}
RECOMP_FUNC void func_806ED160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED160: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806ED164: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806ED168: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x806ED16C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806ED170: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x806ED174: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806ED178: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806ED17C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x806ED180: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806ED184: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806ED188: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x806ED18C: swc1        $f16, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f16.u32l;
    // 0x806ED190: jr          $ra
    // 0x806ED194: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x806ED194: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_806D9258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9258: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806D925C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D9260: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D9264: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x806D9268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D926C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806D9270: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x806D9274: bne         $t7, $zero, L_806D92B4
    if (ctx->r15 != 0) {
        // 0x806D9278: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_806D92B4;
    }
    // 0x806D9278: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x806D927C: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x806D9280: lui         $t0, 0x806E
    ctx->r8 = S32(RELOC_HI16(628, 0X430) << 16);
    // 0x806D9284: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x806D9288: addiu       $t0, $t0, -0x6D10
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(628, 0X430));
    // 0x806D928C: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
    // 0x806D9290: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x806D9294: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x806D9298: lh          $t1, 0xA($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XA);
    // 0x806D929C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x806D92A0: sh          $t2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r10;
    // 0x806D92A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x806D92A8: lh          $t3, 0xC($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XC);
    // 0x806D92AC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x806D92B0: sh          $t4, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r12;
L_806D92B4:
    // 0x806D92B4: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806D92B8: jal         0x80048F84
    // 0x806D92BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x806D92BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D92C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D92C4: jal         0x80048F84
    // 0x806D92C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x806D92C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806D92CC: jal         0x806D90A4
    // 0x806D92D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D90A4(rdram, ctx);
        goto after_2;
    // 0x806D92D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806D92D4: jal         0x806D9064
    // 0x806D92D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D9064(rdram, ctx);
        goto after_3;
    // 0x806D92D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806D92DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D92E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D92E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806D92E8: jr          $ra
    // 0x806D92EC: nop

    return;
    // 0x806D92EC: nop

;}
RECOMP_FUNC void func_80038124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003812C: jal         0x80021958
    // 0x80038130: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80038130: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038134: bne         $v0, $zero, L_80038144
    if (ctx->r2 != 0) {
        // 0x80038138: nop
    
            goto L_80038144;
    }
    // 0x80038138: nop

    // 0x8003813C: b           L_80038178
    // 0x80038140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038178;
    // 0x80038140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038144:
    // 0x80038144: jal         0x800415FC
    // 0x80038148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80038148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003814C: beq         $v0, $zero, L_8003815C
    if (ctx->r2 == 0) {
        // 0x80038150: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8003815C;
    }
    // 0x80038150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038154: b           L_80038178
    // 0x80038158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038178;
    // 0x80038158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003815C:
    // 0x8003815C: jal         0x800376A4
    // 0x80038160: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800376A4(rdram, ctx);
        goto after_2;
    // 0x80038160: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x80038164: bnel        $v0, $zero, L_80038178
    if (ctx->r2 != 0) {
        // 0x80038168: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80038178;
    }
    goto skip_0;
    // 0x80038168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8003816C: b           L_80038178
    // 0x80038170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038178;
    // 0x80038170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80038178:
    // 0x80038178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003817C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038180: jr          $ra
    // 0x80038184: nop

    return;
    // 0x80038184: nop

;}
RECOMP_FUNC void func_8046B8B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046B8B4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8046B8B8: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8046B8BC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8046B8C0: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8046B8C4: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8046B8C8: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X299C) << 16);
    // 0x8046B8CC: lwc1        $f28, -0x3F24($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X299C));
    // 0x8046B8D0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8046B8D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8046B8D8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8046B8DC: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8046B8E0: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X29A0) << 16);
    // 0x8046B8E4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8046B8E8: lwc1        $f24, -0x3F20($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X29A0));
    // 0x8046B8EC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8046B8F0: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x8046B8F4: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8046B8F8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8046B8FC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8046B900: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8046B904: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8046B908: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8046B90C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8046B910: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046B914: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8046B918: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x8046B91C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8046B920: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8046B924: addiu       $s1, $zero, 0xFC0
    ctx->r17 = ADD32(0, 0XFC0);
    // 0x8046B928: addiu       $s2, $zero, 0x7C0
    ctx->r18 = ADD32(0, 0X7C0);
    // 0x8046B92C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8046B930: addiu       $s4, $s5, 0xC88
    ctx->r20 = ADD32(ctx->r21, 0XC88);
L_8046B934:
    // 0x8046B934: mtc1        $s3, $f4
    ctx->f4.u32l = ctx->r19;
    // 0x8046B938: lwc1        $f16, 0xE08($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0XE08);
    // 0x8046B93C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8046B940: mul.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x8046B944: nop

    // 0x8046B948: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x8046B94C: div.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f30.fl);
    // 0x8046B950: div.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f26.fl);
    // 0x8046B954: jal         0x80082730
    // 0x8046B958: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    fsin(rdram, ctx);
        goto after_0;
    // 0x8046B958: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_0:
    // 0x8046B95C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8046B960: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8046B964: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x8046B968: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8046B96C: sll         $t6, $t0, 4
    ctx->r14 = S32(ctx->r8 << 4);
    // 0x8046B970: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8046B974: addu        $v0, $t6, $s4
    ctx->r2 = ADD32(ctx->r14, ctx->r20);
    // 0x8046B978: bne         $at, $zero, L_8046B988
    if (ctx->r1 != 0) {
        // 0x8046B97C: abs.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
            goto L_8046B988;
    }
    // 0x8046B97C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8046B980: b           L_8046B98C
    // 0x8046B984: addiu       $a3, $s0, -0x2
    ctx->r7 = ADD32(ctx->r16, -0X2);
        goto L_8046B98C;
    // 0x8046B984: addiu       $a3, $s0, -0x2
    ctx->r7 = ADD32(ctx->r16, -0X2);
L_8046B988:
    // 0x8046B988: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
L_8046B98C:
    // 0x8046B98C: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8046B990: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8046B994: sub.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8046B998: sll         $t1, $a3, 4
    ctx->r9 = S32(ctx->r7 << 4);
    // 0x8046B99C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8046B9A0: sub.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8046B9A4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8046B9A8: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8046B9AC: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8046B9B0: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x8046B9B4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8046B9B8: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    // 0x8046B9BC: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x8046B9C0: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8046B9C4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8046B9C8: sh          $s1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r17;
    // 0x8046B9CC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8046B9D0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8046B9D4: sh          $zero, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = 0;
    // 0x8046B9D8: addu        $v1, $t1, $s4
    ctx->r3 = ADD32(ctx->r9, ctx->r20);
    // 0x8046B9DC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8046B9E0: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x8046B9E4: sh          $a0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r4;
    // 0x8046B9E8: sh          $a0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r4;
    // 0x8046B9EC: sh          $a2, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r6;
    // 0x8046B9F0: slti        $at, $s3, 0x6
    ctx->r1 = SIGNED(ctx->r19) < 0X6 ? 1 : 0;
    // 0x8046B9F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8046B9F8: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x8046B9FC: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8046BA00: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x8046BA04: sh          $s2, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r18;
    // 0x8046BA08: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x8046BA0C: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x8046BA10: sh          $s1, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r17;
    // 0x8046BA14: sh          $s2, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r18;
    // 0x8046BA18: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    // 0x8046BA1C: sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
    // 0x8046BA20: sh          $a0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r4;
    // 0x8046BA24: bne         $at, $zero, L_8046B934
    if (ctx->r1 != 0) {
        // 0x8046BA28: sh          $a2, 0x10($v1)
        MEM_H(0X10, ctx->r3) = ctx->r6;
            goto L_8046B934;
    }
    // 0x8046BA28: sh          $a2, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r6;
    // 0x8046BA2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8046BA30: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8046BA34: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
    // 0x8046BA38: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8046BA3C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8046BA40: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8046BA44: mfc1        $s1, $f16
    ctx->r17 = (int32_t)ctx->f16.u32l;
    // 0x8046BA48: nop

L_8046BA4C:
    // 0x8046BA4C: mtc1        $s3, $f18
    ctx->f18.u32l = ctx->r19;
    // 0x8046BA50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8046BA54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046BA58: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8046BA5C: lwc1        $f16, 0xE08($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0XE08);
    // 0x8046BA60: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8046BA64: mul.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x8046BA68: nop

    // 0x8046BA6C: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x8046BA70: div.s       $f20, $f8, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f30.fl);
    // 0x8046BA74: div.s       $f10, $f18, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f26.fl);
    // 0x8046BA78: jal         0x80082730
    // 0x8046BA7C: add.s       $f12, $f20, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f10.fl;
    fsin(rdram, ctx);
        goto after_1;
    // 0x8046BA7C: add.s       $f12, $f20, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f10.fl;
    after_1:
    // 0x8046BA80: lwc1        $f4, 0xE08($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0XE08);
    // 0x8046BA84: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8046BA88: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8046BA8C: div.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f26.fl);
    // 0x8046BA90: jal         0x8008D250
    // 0x8046BA94: add.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f8.fl;
    fcos(rdram, ctx);
        goto after_2;
    // 0x8046BA94: add.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f8.fl;
    after_2:
    // 0x8046BA98: neg.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = -ctx->f22.fl;
    // 0x8046BA9C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8046BAA0: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8046BAA4: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8046BAA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8046BAAC: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8046BAB0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8046BAB4: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x8046BAB8: sb          $s1, -0x24($s0)
    MEM_B(-0X24, ctx->r16) = ctx->r17;
    // 0x8046BABC: sb          $s2, -0x21($s0)
    MEM_B(-0X21, ctx->r16) = ctx->r18;
    // 0x8046BAC0: sb          $s1, -0x14($s0)
    MEM_B(-0X14, ctx->r16) = ctx->r17;
    // 0x8046BAC4: sb          $s2, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r18;
    // 0x8046BAC8: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8046BACC: sb          $s1, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r17;
    // 0x8046BAD0: sb          $s2, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r18;
    // 0x8046BAD4: sb          $s1, -0x34($s0)
    MEM_B(-0X34, ctx->r16) = ctx->r17;
    // 0x8046BAD8: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8046BADC: sb          $s2, -0x31($s0)
    MEM_B(-0X31, ctx->r16) = ctx->r18;
    // 0x8046BAE0: div.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8046BAE4: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8046BAE8: nop

    // 0x8046BAEC: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8046BAF0: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8046BAF4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8046BAF8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8046BAFC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8046BB00: sb          $v0, -0x22($s0)
    MEM_B(-0X22, ctx->r16) = ctx->r2;
    // 0x8046BB04: sb          $v0, -0x12($s0)
    MEM_B(-0X12, ctx->r16) = ctx->r2;
    // 0x8046BB08: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x8046BB0C: sb          $v0, -0x32($s0)
    MEM_B(-0X32, ctx->r16) = ctx->r2;
    // 0x8046BB10: sb          $v1, -0x23($s0)
    MEM_B(-0X23, ctx->r16) = ctx->r3;
    // 0x8046BB14: sb          $v1, -0x13($s0)
    MEM_B(-0X13, ctx->r16) = ctx->r3;
    // 0x8046BB18: sb          $v1, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r3;
    // 0x8046BB1C: bne         $s3, $s4, L_8046BA4C
    if (ctx->r19 != ctx->r20) {
        // 0x8046BB20: sb          $v1, -0x33($s0)
        MEM_B(-0X33, ctx->r16) = ctx->r3;
            goto L_8046BA4C;
    }
    // 0x8046BB20: sb          $v1, -0x33($s0)
    MEM_B(-0X33, ctx->r16) = ctx->r3;
    // 0x8046BB24: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8046BB28: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8046BB2C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8046BB30: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8046BB34: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8046BB38: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8046BB3C: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8046BB40: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8046BB44: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8046BB48: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8046BB4C: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8046BB50: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8046BB54: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8046BB58: jr          $ra
    // 0x8046BB5C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8046BB5C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80566F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566F88: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80566F8C: lui         $t6, 0x8056
    ctx->r14 = S32(RELOC_HI16(375, 0X178) << 16);
    // 0x80566F90: addiu       $t6, $t6, 0x66C8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(375, 0X178));
    // 0x80566F94: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80566F98: jr          $ra
    // 0x80566F9C: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x80566F9C: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8006BB04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BB04: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x8006BB08: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x8006BB0C: lh          $t1, 0x2($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X2);
    // 0x8006BB10: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006BB14: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8006BB18: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8006BB1C: bgez        $t2, L_8006BB28
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8006BB20: addu        $at, $t2, $zero
        ctx->r1 = ADD32(ctx->r10, 0);
            goto L_8006BB28;
    }
    // 0x8006BB20: addu        $at, $t2, $zero
    ctx->r1 = ADD32(ctx->r10, 0);
    // 0x8006BB24: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
L_8006BB28:
    // 0x8006BB28: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
    // 0x8006BB2C: bgez        $t3, L_8006BB38
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8006BB30: addu        $at, $t3, $zero
        ctx->r1 = ADD32(ctx->r11, 0);
            goto L_8006BB38;
    }
    // 0x8006BB30: addu        $at, $t3, $zero
    ctx->r1 = ADD32(ctx->r11, 0);
    // 0x8006BB34: addiu       $at, $t3, 0x3
    ctx->r1 = ADD32(ctx->r11, 0X3);
L_8006BB38:
    // 0x8006BB38: sra         $t3, $at, 2
    ctx->r11 = S32(SIGNED(ctx->r1) >> 2);
    // 0x8006BB3C: blez        $t1, L_8006BBE4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8006BB40: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_8006BBE4;
    }
    // 0x8006BB40: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8006BB44: sll         $a1, $t3, 2
    ctx->r5 = S32(ctx->r11 << 2);
L_8006BB48:
    // 0x8006BB48: blez        $t2, L_8006BBD4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8006BB4C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8006BBD4;
    }
    // 0x8006BB4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006BB50: andi        $a3, $t2, 0x3
    ctx->r7 = ctx->r10 & 0X3;
    // 0x8006BB54: beq         $a3, $zero, L_8006BB84
    if (ctx->r7 == 0) {
        // 0x8006BB58: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_8006BB84;
    }
    // 0x8006BB58: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
L_8006BB5C:
    // 0x8006BB5C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8006BB60: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006BB64: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8006BB68: sw          $t6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r14;
    // 0x8006BB6C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8006BB70: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8006BB74: bne         $a2, $a0, L_8006BB5C
    if (ctx->r6 != ctx->r4) {
        // 0x8006BB78: sw          $t7, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r15;
            goto L_8006BB5C;
    }
    // 0x8006BB78: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x8006BB7C: beql        $a0, $t2, L_8006BBD8
    if (ctx->r4 == ctx->r10) {
        // 0x8006BB80: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_8006BBD8;
    }
    goto skip_0;
    // 0x8006BB80: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    skip_0:
L_8006BB84:
    // 0x8006BB84: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8006BB88: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006BB8C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8006BB90: sw          $t8, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->r24;
    // 0x8006BB94: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x8006BB98: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8006BB9C: sw          $t9, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->r25;
    // 0x8006BBA0: lw          $t5, -0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X18);
    // 0x8006BBA4: sw          $t5, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->r13;
    // 0x8006BBA8: lw          $t6, -0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X14);
    // 0x8006BBAC: sw          $t6, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->r14;
    // 0x8006BBB0: lw          $t7, -0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X10);
    // 0x8006BBB4: sw          $t7, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r15;
    // 0x8006BBB8: lw          $t8, -0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XC);
    // 0x8006BBBC: sw          $t8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r24;
    // 0x8006BBC0: lw          $t9, -0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X8);
    // 0x8006BBC4: sw          $t9, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r25;
    // 0x8006BBC8: lw          $t5, -0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X4);
    // 0x8006BBCC: bne         $a0, $t2, L_8006BB84
    if (ctx->r4 != ctx->r10) {
        // 0x8006BBD0: sw          $t5, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r13;
            goto L_8006BB84;
    }
    // 0x8006BBD0: sw          $t5, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r13;
L_8006BBD4:
    // 0x8006BBD4: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_8006BBD8:
    // 0x8006BBD8: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x8006BBDC: bne         $t4, $t1, L_8006BB48
    if (ctx->r12 != ctx->r9) {
        // 0x8006BBE0: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8006BB48;
    }
    // 0x8006BBE0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8006BBE4:
    // 0x8006BBE4: jr          $ra
    // 0x8006BBE8: nop

    return;
    // 0x8006BBE8: nop

;}
RECOMP_FUNC void func_80421A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421A4C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80421A50: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80421A54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80421A58: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80421A5C: lw          $a1, 0x880($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X880);
    // 0x80421A60: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80421A64: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80421A68: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80421A6C: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80421A70: swc1        $f8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f8.u32l;
    // 0x80421A74: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80421A78: addu        $a2, $v0, $a1
    ctx->r6 = ADD32(ctx->r2, ctx->r5);
    // 0x80421A7C: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80421A80: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80421A84: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80421A88: addiu       $a2, $a2, 0x790
    ctx->r6 = ADD32(ctx->r6, 0X790);
    // 0x80421A8C: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80421A90: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x80421A94: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x80421A98: lw          $t8, 0x880($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X880);
    // 0x80421A9C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80421AA0: divu        $zero, $t9, $at
    lo = S32(U32(ctx->r25) / U32(ctx->r1)); hi = S32(U32(ctx->r25) % U32(ctx->r1));
    // 0x80421AA4: mfhi        $t0
    ctx->r8 = hi;
    // 0x80421AA8: sw          $t0, 0x880($v0)
    MEM_W(0X880, ctx->r2) = ctx->r8;
    // 0x80421AAC: jr          $ra
    // 0x80421AB0: nop

    return;
    // 0x80421AB0: nop

;}
RECOMP_FUNC void func_807C3DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C3DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C3DE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807C3DE4: jal         0x80046E88
    // 0x807C3DE8: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x807C3DE8: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    after_0:
    // 0x807C3DEC: beq         $v0, $zero, L_807C3E40
    if (ctx->r2 == 0) {
        // 0x807C3DF0: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_807C3E40;
    }
    // 0x807C3DF0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x807C3DF4: lw          $a0, 0x16C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X16C);
    // 0x807C3DF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C3DFC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x807C3E00: lbu         $v1, 0x10($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X10);
    // 0x807C3E04: addiu       $a0, $a0, 0xD
    ctx->r4 = ADD32(ctx->r4, 0XD);
    // 0x807C3E08: slti        $at, $v1, 0xFF
    ctx->r1 = SIGNED(ctx->r3) < 0XFF ? 1 : 0;
    // 0x807C3E0C: beq         $at, $zero, L_807C3E30
    if (ctx->r1 == 0) {
        // 0x807C3E10: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_807C3E30;
    }
    // 0x807C3E10: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x807C3E14: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x807C3E18: bne         $at, $zero, L_807C3E28
    if (ctx->r1 != 0) {
        // 0x807C3E1C: addiu       $t6, $zero, 0xFF
        ctx->r14 = ADD32(0, 0XFF);
            goto L_807C3E28;
    }
    // 0x807C3E1C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807C3E20: b           L_807C3E50
    // 0x807C3E24: sb          $t6, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r14;
        goto L_807C3E50;
    // 0x807C3E24: sb          $t6, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r14;
L_807C3E28:
    // 0x807C3E28: b           L_807C3E50
    // 0x807C3E2C: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
        goto L_807C3E50;
    // 0x807C3E2C: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_807C3E30:
    // 0x807C3E30: jal         0x807C3EC0
    // 0x807C3E34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_807C3EC0(rdram, ctx);
        goto after_1;
    // 0x807C3E34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x807C3E38: b           L_807C3E54
    // 0x807C3E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C3E54;
    // 0x807C3E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C3E40:
    // 0x807C3E40: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807C3E44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C3E48: jal         0x807C3EC0
    // 0x807C3E4C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_807C3EC0(rdram, ctx);
        goto after_2;
    // 0x807C3E4C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
L_807C3E50:
    // 0x807C3E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C3E54:
    // 0x807C3E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C3E58: jr          $ra
    // 0x807C3E5C: nop

    return;
    // 0x807C3E5C: nop

;}
RECOMP_FUNC void func_806E8F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E8F9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806E8FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E8FA4: lw          $a2, 0x180($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X180);
    // 0x806E8FA8: beql        $a2, $zero, L_806E9138
    if (ctx->r6 == 0) {
        // 0x806E8FAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E9138;
    }
    goto skip_0;
    // 0x806E8FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E8FB0: lw          $t6, 0x138($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X138);
    // 0x806E8FB4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806E8FB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806E8FBC: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x806E8FC0: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
    // 0x806E8FC4: lw          $t7, 0x450($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X450);
    // 0x806E8FC8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806E8FCC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806E8FD0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806E8FD4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806E8FD8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806E8FDC: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x806E8FE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806E8FE4: addiu       $a1, $v0, 0x228
    ctx->r5 = ADD32(ctx->r2, 0X228);
    // 0x806E8FE8: lh          $t2, 0x10($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X10);
    // 0x806E8FEC: lh          $t3, 0x12($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X12);
    // 0x806E8FF0: lh          $t5, 0x16($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X16);
    // 0x806E8FF4: lh          $t7, 0x14($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X14);
    // 0x806E8FF8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x806E8FFC: lh          $t0, 0x18($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X18);
    // 0x806E9000: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x806E9004: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x806E9008: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x806E900C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x806E9010: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x806E9014: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x806E9018: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806E901C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x806E9020: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x806E9024: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806E9028: mul.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806E902C: jal         0x80067114
    // 0x806E9030: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x806E9030: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x806E9034: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806E9038: jal         0x80049018
    // 0x806E903C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80049018(rdram, ctx);
        goto after_1;
    // 0x806E903C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x806E9040: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806E9044: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x806E9048: beq         $v0, $zero, L_806E90A4
    if (ctx->r2 == 0) {
        // 0x806E904C: lwc1        $f2, 0x1C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_806E90A4;
    }
    // 0x806E904C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x806E9050: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x806E9054: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16C8) << 16);
    // 0x806E9058: lwc1        $f0, -0x6688($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16C8));
    // 0x806E905C: lh          $t0, 0x18($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X18);
    // 0x806E9060: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16CC) << 16);
    // 0x806E9064: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806E9068: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x806E906C: nop

    // 0x806E9070: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806E9074: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x806E9078: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806E907C: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x806E9080: lwc1        $f10, -0x6684($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16CC));
    // 0x806E9084: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16D0) << 16);
    // 0x806E9088: lwc1        $f18, -0x6680($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16D0));
    // 0x806E908C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806E9090: nop

    // 0x806E9094: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x806E9098: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x806E909C: b           L_806E90F0
    // 0x806E90A0: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
        goto L_806E90F0;
    // 0x806E90A0: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
L_806E90A4:
    // 0x806E90A4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x806E90A8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16D4) << 16);
    // 0x806E90AC: lwc1        $f0, -0x667C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16D4));
    // 0x806E90B0: lh          $t2, 0x18($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X18);
    // 0x806E90B4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16D8) << 16);
    // 0x806E90B8: lwc1        $f16, 0x50($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806E90BC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x806E90C0: nop

    // 0x806E90C4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806E90C8: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806E90CC: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x806E90D0: lwc1        $f4, -0x6678($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16D8));
    // 0x806E90D4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16DC) << 16);
    // 0x806E90D8: lwc1        $f8, -0x6674($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16DC));
    // 0x806E90DC: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x806E90E0: nop

    // 0x806E90E4: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x806E90E8: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x806E90EC: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
L_806E90F0:
    // 0x806E90F0: lh          $t3, 0x16($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X16);
    // 0x806E90F4: lh          $t4, 0x14($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X14);
    // 0x806E90F8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16E0) << 16);
    // 0x806E90FC: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x806E9100: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x806E9104: lwc1        $f8, -0x6670($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16E0));
    // 0x806E9108: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806E910C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16E4) << 16);
    // 0x806E9110: lwc1        $f16, -0x666C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16E4));
    // 0x806E9114: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806E9118: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x806E911C: nop

    // 0x806E9120: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x806E9124: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x806E9128: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x806E912C: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806E9130: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x806E9134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E9138:
    // 0x806E9138: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806E913C: jr          $ra
    // 0x806E9140: nop

    return;
    // 0x806E9140: nop

;}
RECOMP_FUNC void func_80450B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450B48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80450B4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80450B50: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450B54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80450B58: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450B5C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80450B60: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    // 0x80450B64: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450B68: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80450B6C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80450B70: sw          $t6, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r14;
    // 0x80450B74: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80450B78: lw          $t7, -0x71A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71A8);
    // 0x80450B7C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140B8) << 16);
    // 0x80450B80: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80450B84: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80450B88: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x80450B8C: bne         $t9, $zero, L_80450BD4
    if (ctx->r25 != 0) {
        // 0x80450B90: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80450BD4;
    }
    // 0x80450B90: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80450B94: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140B0) << 16);
    // 0x80450B98: lwc1        $f0, -0x7B70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140B0));
    // 0x80450B9C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80450BA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80450BA4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140B4) << 16);
    // 0x80450BA8: lwc1        $f8, -0x7B6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140B4));
    // 0x80450BAC: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80450BB0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80450BB4: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80450BB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80450BBC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80450BC0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80450BC4: jal         0x80444B28
    // 0x80450BC8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_80444B28(rdram, ctx);
        goto after_0;
    // 0x80450BC8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80450BCC: b           L_80450BFC
    // 0x80450BD0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_80450BFC;
    // 0x80450BD0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80450BD4:
    // 0x80450BD4: lwc1        $f0, -0x7B68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140B8));
    // 0x80450BD8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80450BDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80450BE0: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80450BE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80450BE8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80450BEC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80450BF0: jal         0x80444B28
    // 0x80450BF4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80444B28(rdram, ctx);
        goto after_1;
    // 0x80450BF4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80450BF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80450BFC:
    // 0x80450BFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80450C00: jal         0x80457164
    // 0x80450C04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80457164(rdram, ctx);
        goto after_2;
    // 0x80450C04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x80450C08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80450C0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80450C10: jr          $ra
    // 0x80450C14: nop

    return;
    // 0x80450C14: nop

;}
RECOMP_FUNC void func_806AA1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA1BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AA1C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AA1C4: jal         0x806A98AC
    // 0x806AA1C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806A98AC(rdram, ctx);
        goto after_0;
    // 0x806AA1C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806AA1CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806AA1D0: bne         $v0, $at, L_806AA1E8
    if (ctx->r2 != ctx->r1) {
        // 0x806AA1D4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806AA1E8;
    }
    // 0x806AA1D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AA1D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AA1DC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x806AA1E0: jal         0x806AA784
    // 0x806AA1E4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806AA1E4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_1:
L_806AA1E8:
    // 0x806AA1E8: jal         0x806AA06C
    // 0x806AA1EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806AA06C(rdram, ctx);
        goto after_2;
    // 0x806AA1EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806AA1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AA1F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AA1F8: jr          $ra
    // 0x806AA1FC: nop

    return;
    // 0x806AA1FC: nop

;}
RECOMP_FUNC void func_804D89CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D89CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D89D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D89D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804D89D8: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x804D89DC: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x804D89E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D89E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804D89E8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804D89EC: jal         0x804D8878
    // 0x804D89F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_804D8878(rdram, ctx);
        goto after_0;
    // 0x804D89F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x804D89F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D89F8: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x804D89FC: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x804D8A00: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x804D8A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D8A08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D8A0C: jr          $ra
    // 0x804D8A10: nop

    return;
    // 0x804D8A10: nop

    // 0x804D8A14: nop

    // 0x804D8A18: nop

    // 0x804D8A1C: nop

;}
RECOMP_FUNC void func_80434FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434FA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80434FA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80434FAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80434FB0: jal         0x804347A8
    // 0x80434FB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804347A8(rdram, ctx);
        goto after_0;
    // 0x80434FB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80434FB8: jal         0x80434774
    // 0x80434FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434774(rdram, ctx);
        goto after_1;
    // 0x80434FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80434FC0: jal         0x804348BC
    // 0x80434FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804348BC(rdram, ctx);
        goto after_2;
    // 0x80434FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80434FC8: jal         0x80434A28
    // 0x80434FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434A28(rdram, ctx);
        goto after_3;
    // 0x80434FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80434FD0: jal         0x80434B9C
    // 0x80434FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434B9C(rdram, ctx);
        goto after_4;
    // 0x80434FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80434FD8: jal         0x80434D00
    // 0x80434FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434D00(rdram, ctx);
        goto after_5;
    // 0x80434FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80434FE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80434FE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80434FE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80434FEC: jr          $ra
    // 0x80434FF0: nop

    return;
    // 0x80434FF0: nop

;}
RECOMP_FUNC void func_806B288C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B288C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2890: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2894: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2898: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B289C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B28A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B28A4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B28A8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B28AC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B28B0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B28B4: jr          $ra
    // 0x806B28B8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B28B8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80716AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716AE8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716AEC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716AF0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716AF4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716AF8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716AFC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716B00: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716B04: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716B08: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716B0C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716B10: jr          $ra
    // 0x80716B14: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716B14: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8006D360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D360: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8006D364: lw          $a1, -0x7BB0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7BB0);
    // 0x8006D368: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8006D36C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8006D370: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8006D374: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8006D378: addiu       $a2, $a1, 0xC
    ctx->r6 = ADD32(ctx->r5, 0XC);
    // 0x8006D37C: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x8006D380: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8006D384: beql        $a3, $t6, L_8006D394
    if (ctx->r7 == ctx->r14) {
        // 0x8006D388: lw          $a0, 0x4($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X4);
            goto L_8006D394;
    }
    goto skip_0;
    // 0x8006D388: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x8006D38C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006D390: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
L_8006D394:
    // 0x8006D394: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x8006D398: beql        $a3, $t7, L_8006D3A8
    if (ctx->r7 == ctx->r15) {
        // 0x8006D39C: lw          $a0, 0x8($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X8);
            goto L_8006D3A8;
    }
    goto skip_1;
    // 0x8006D39C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    skip_1:
    // 0x8006D3A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006D3A4: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
L_8006D3A8:
    // 0x8006D3A8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006D3AC: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x8006D3B0: beq         $a3, $t8, L_8006D3BC
    if (ctx->r7 == ctx->r24) {
        // 0x8006D3B4: nop
    
            goto L_8006D3BC;
    }
    // 0x8006D3B4: nop

    // 0x8006D3B8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8006D3BC:
    // 0x8006D3BC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8006D3C0: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8006D3C4: beql        $a3, $t9, L_8006D3D4
    if (ctx->r7 == ctx->r25) {
        // 0x8006D3C8: lw          $a0, 0x4($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X4);
            goto L_8006D3D4;
    }
    goto skip_2;
    // 0x8006D3C8: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    skip_2:
    // 0x8006D3CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8006D3D0: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
L_8006D3D4:
    // 0x8006D3D4: lbu         $t0, 0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1);
    // 0x8006D3D8: beql        $a3, $t0, L_8006D3E8
    if (ctx->r7 == ctx->r8) {
        // 0x8006D3DC: lw          $a0, 0x8($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X8);
            goto L_8006D3E8;
    }
    goto skip_3;
    // 0x8006D3DC: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    skip_3:
    // 0x8006D3E0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8006D3E4: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
L_8006D3E8:
    // 0x8006D3E8: lbu         $t1, 0x1($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X1);
    // 0x8006D3EC: beql        $a3, $t1, L_8006D3FC
    if (ctx->r7 == ctx->r9) {
        // 0x8006D3F0: lw          $a0, 0xC($a2)
        ctx->r4 = MEM_W(ctx->r6, 0XC);
            goto L_8006D3FC;
    }
    goto skip_4;
    // 0x8006D3F0: lw          $a0, 0xC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC);
    skip_4:
    // 0x8006D3F4: addiu       $v1, $v0, 0x2
    ctx->r3 = ADD32(ctx->r2, 0X2);
    // 0x8006D3F8: lw          $a0, 0xC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC);
L_8006D3FC:
    // 0x8006D3FC: lbu         $t2, 0x1($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X1);
    // 0x8006D400: beql        $a3, $t2, L_8006D410
    if (ctx->r7 == ctx->r10) {
        // 0x8006D404: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006D410;
    }
    goto skip_5;
    // 0x8006D404: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_5:
    // 0x8006D408: addiu       $v1, $v0, 0x3
    ctx->r3 = ADD32(ctx->r2, 0X3);
    // 0x8006D40C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8006D410:
    // 0x8006D410: bne         $v0, $a1, L_8006D3BC
    if (ctx->r2 != ctx->r5) {
        // 0x8006D414: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_8006D3BC;
    }
    // 0x8006D414: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8006D418: jr          $ra
    // 0x8006D41C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8006D41C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8046BC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046BC34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8046BC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046BC3C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8046BC40: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046BC44: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8046BC48: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8046BC4C: addiu       $t7, $v0, 0x640
    ctx->r15 = ADD32(ctx->r2, 0X640);
    // 0x8046BC50: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8046BC54: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8046BC58: jal         0x8046BC14
    // 0x8046BC5C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8046BC14(rdram, ctx);
        goto after_0;
    // 0x8046BC5C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8046BC60: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8046BC64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8046BC68: lui         $t9, 0x8047
    ctx->r25 = S32(RELOC_HI16(138, 0X2448) << 16);
    // 0x8046BC6C: sw          $t8, 0xC80($v0)
    MEM_W(0XC80, ctx->r2) = ctx->r24;
    // 0x8046BC70: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8046BC74: addiu       $t9, $t9, -0x4478
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(138, 0X2448));
    // 0x8046BC78: lw          $t1, 0x16C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X16C);
    // 0x8046BC7C: sw          $t9, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r25;
    // 0x8046BC80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046BC84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8046BC88: jr          $ra
    // 0x8046BC8C: nop

    return;
    // 0x8046BC8C: nop

;}
RECOMP_FUNC void func_80409F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409F1C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80409F20: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80409F24: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80409F28: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80409F2C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80409F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80409F34: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_80409F38:
    // 0x80409F38: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80409F3C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80409F40: bne         $t6, $zero, L_80409FA0
    if (ctx->r14 != 0) {
        // 0x80409F44: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80409FA0;
    }
    // 0x80409F44: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80409F48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80409F4C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80409F50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80409F54: lui         $t0, 0x8041
    ctx->r8 = S32(RELOC_HI16(11, 0X1F48) << 16);
    // 0x80409F58: lui         $t1, 0x8041
    ctx->r9 = S32(RELOC_HI16(11, 0X12EC) << 16);
    // 0x80409F5C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80409F60: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80409F64: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80409F68: addiu       $t0, $t0, -0x66E8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(11, 0X1F48));
    // 0x80409F6C: addiu       $t1, $t1, -0x7344
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(11, 0X12EC));
    // 0x80409F70: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409F74: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409F78: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409F7C: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x80409F80: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80409F84: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x80409F88: sw          $t0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r8;
    // 0x80409F8C: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x80409F90: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80409F94: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80409F98: b           L_8040A0E4
    // 0x80409F9C: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
        goto L_8040A0E4;
    // 0x80409F9C: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_80409FA0:
    // 0x80409FA0: lw          $t2, 0x58($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X58);
    // 0x80409FA4: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409FA8: bne         $t2, $zero, L_8040A008
    if (ctx->r10 != 0) {
        // 0x80409FAC: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_8040A008;
    }
    // 0x80409FAC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80409FB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80409FB4: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80409FB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80409FBC: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(11, 0X1F48) << 16);
    // 0x80409FC0: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(11, 0X12EC) << 16);
    // 0x80409FC4: addiu       $t7, $t7, -0x7344
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(11, 0X12EC));
    // 0x80409FC8: addiu       $t6, $t6, -0x66E8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(11, 0X1F48));
    // 0x80409FCC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80409FD0: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80409FD4: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80409FD8: sw          $t5, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r13;
    // 0x80409FDC: sw          $t4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r12;
    // 0x80409FE0: sw          $t3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r11;
    // 0x80409FE4: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    // 0x80409FE8: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x80409FEC: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409FF0: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409FF4: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409FF8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80409FFC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x8040A000: b           L_8040A0E4
    // 0x8040A004: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
        goto L_8040A0E4;
    // 0x8040A004: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
L_8040A008:
    // 0x8040A008: lw          $t8, 0x58($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X58);
    // 0x8040A00C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x8040A010: bne         $t8, $zero, L_8040A070
    if (ctx->r24 != 0) {
        // 0x8040A014: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_8040A070;
    }
    // 0x8040A014: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8040A018: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8040A01C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8040A020: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8040A024: lui         $t2, 0x8041
    ctx->r10 = S32(RELOC_HI16(11, 0X1F48) << 16);
    // 0x8040A028: lui         $t3, 0x8041
    ctx->r11 = S32(RELOC_HI16(11, 0X12EC) << 16);
    // 0x8040A02C: addiu       $t3, $t3, -0x7344
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(11, 0X12EC));
    // 0x8040A030: addiu       $t2, $t2, -0x66E8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(11, 0X1F48));
    // 0x8040A034: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8040A038: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x8040A03C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8040A040: sw          $t1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r9;
    // 0x8040A044: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x8040A048: sw          $t9, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r25;
    // 0x8040A04C: sw          $t2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r10;
    // 0x8040A050: sw          $t3, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r11;
    // 0x8040A054: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8040A058: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8040A05C: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x8040A060: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8040A064: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x8040A068: b           L_8040A0E4
    // 0x8040A06C: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
        goto L_8040A0E4;
    // 0x8040A06C: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
L_8040A070:
    // 0x8040A070: lw          $t4, 0x58($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X58);
    // 0x8040A074: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x8040A078: bne         $t4, $zero, L_8040A0D8
    if (ctx->r12 != 0) {
        // 0x8040A07C: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_8040A0D8;
    }
    // 0x8040A07C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8040A080: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8040A084: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8040A088: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040A08C: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(11, 0X1F48) << 16);
    // 0x8040A090: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(11, 0X12EC) << 16);
    // 0x8040A094: addiu       $t9, $t9, -0x7344
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(11, 0X12EC));
    // 0x8040A098: addiu       $t8, $t8, -0x66E8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(11, 0X1F48));
    // 0x8040A09C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8040A0A0: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8040A0A4: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8040A0A8: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x8040A0AC: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8040A0B0: sw          $t5, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r13;
    // 0x8040A0B4: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    // 0x8040A0B8: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x8040A0BC: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8040A0C0: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8040A0C4: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x8040A0C8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8040A0CC: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x8040A0D0: b           L_8040A0E4
    // 0x8040A0D4: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
        goto L_8040A0E4;
    // 0x8040A0D4: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_8040A0D8:
    // 0x8040A0D8: bne         $v0, $v1, L_80409F38
    if (ctx->r2 != ctx->r3) {
        // 0x8040A0DC: addiu       $a0, $a0, 0x30
        ctx->r4 = ADD32(ctx->r4, 0X30);
            goto L_80409F38;
    }
    // 0x8040A0DC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x8040A0E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8040A0E4:
    // 0x8040A0E4: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8040A0E8: jr          $ra
    // 0x8040A0EC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8040A0EC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8001A64C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A64C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8001A650: beql        $v0, $zero, L_8001A668
    if (ctx->r2 == 0) {
        // 0x8001A654: lw          $t7, 0xC($a0)
        ctx->r15 = MEM_W(ctx->r4, 0XC);
            goto L_8001A668;
    }
    goto skip_0;
    // 0x8001A654: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    skip_0:
    // 0x8001A658: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8001A65C: b           L_8001A670
    // 0x8001A660: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
        goto L_8001A670;
    // 0x8001A660: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x8001A664: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
L_8001A668:
    // 0x8001A668: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001A66C: sw          $t7, 0x650($at)
    MEM_W(0X650, ctx->r1) = ctx->r15;
L_8001A670:
    // 0x8001A670: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8001A674: beq         $v0, $zero, L_8001A684
    if (ctx->r2 == 0) {
        // 0x8001A678: nop
    
            goto L_8001A684;
    }
    // 0x8001A678: nop

    // 0x8001A67C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8001A680: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
L_8001A684:
    // 0x8001A684: jr          $ra
    // 0x8001A688: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x8001A688: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8005D110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D110: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8005D114: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005D118: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005D11C: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8005D120: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005D124: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8005D128: lw          $t8, 0x62C8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X62C8);
    // 0x8005D12C: jr          $ra
    // 0x8005D130: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x8005D130: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8003B1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B1BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B1C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B1C4: jal         0x8003B004
    // 0x8003B1C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003B004(rdram, ctx);
        goto after_0;
    // 0x8003B1C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B1CC: jal         0x8003AE00
    // 0x8003B1D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003AE00(rdram, ctx);
        goto after_1;
    // 0x8003B1D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003B1D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B1D8: jal         0x8003B540
    // 0x8003B1DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8003B540(rdram, ctx);
        goto after_2;
    // 0x8003B1DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8003B1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B1E8: jr          $ra
    // 0x8003B1EC: nop

    return;
    // 0x8003B1EC: nop

;}
RECOMP_FUNC void func_80442584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80442584: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80442588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044258C: jal         0x804424DC
    // 0x80442590: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804424DC(rdram, ctx);
        goto after_0;
    // 0x80442590: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80442594: beq         $v0, $zero, L_804425AC
    if (ctx->r2 == 0) {
        // 0x80442598: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804425AC;
    }
    // 0x80442598: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8044259C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804425A0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x804425A4: jal         0x8044284C
    // 0x804425A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8044284C(rdram, ctx);
        goto after_1;
    // 0x804425A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_804425AC:
    // 0x804425AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804425B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804425B4: jr          $ra
    // 0x804425B8: nop

    return;
    // 0x804425B8: nop

;}
RECOMP_FUNC void func_80078584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078584: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80078588: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007858C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80078590: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80078594: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80078598: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007859C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800785A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800785A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800785A8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800785AC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800785B0: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
    // 0x800785B4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800785B8: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800785BC: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800785C0: lw          $s1, 0x4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X4);
    // 0x800785C4: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x800785C8: srl         $s0, $s0, 24
    ctx->r16 = S32(U32(ctx->r16) >> 24);
    // 0x800785CC: blez        $s0, L_800785F0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800785D0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800785F0;
    }
L_800785D0:
    // 0x800785D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800785D4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800785D8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800785DC: jal         0x80078244
    // 0x800785E0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80078244(rdram, ctx);
        goto after_0;
    // 0x800785E0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_0:
    // 0x800785E4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800785E8: bgtz        $s0, L_800785D0
    if (SIGNED(ctx->r16) > 0) {
        // 0x800785EC: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_800785D0;
    }
    // 0x800785EC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_800785F0:
    // 0x800785F0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800785F4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800785F8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800785FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80078600: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80078604: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80078608: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007860C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80078610: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80078614: jr          $ra
    // 0x80078618: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80078618: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80561694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80561694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80561698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8056169C: jal         0x805614C0
    // 0x805616A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805614C0(rdram, ctx);
        goto after_0;
    // 0x805616A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805616A4: jal         0x80045BD8
    // 0x805616A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x805616A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805616AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805616B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805616B4: jr          $ra
    // 0x805616B8: nop

    return;
    // 0x805616B8: nop

;}
RECOMP_FUNC void func_804CDF54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CDF54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CDF58: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804CDF5C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804CDF60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CDF64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804CDF68: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804CDF6C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804CDF70: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804CDF74: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x804CDF78: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804CDF7C: lui         $t1, 0x804D
    ctx->r9 = S32(RELOC_HI16(237, 0X1C80) << 16);
    // 0x804CDF80: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804CDF84: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804CDF88: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804CDF8C: lw          $t1, -0x1F10($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(237, 0X1C80));
    // 0x804CDF90: jal         0x804CCAB4
    // 0x804CDF94: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_804CCAB4(rdram, ctx);
        goto after_0;
    // 0x804CDF94: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x804CDF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CDF9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CDFA0: jr          $ra
    // 0x804CDFA4: nop

    return;
    // 0x804CDFA4: nop

    // 0x804CDFA8: nop

    // 0x804CDFAC: nop

;}
RECOMP_FUNC void func_80001064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001064: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x80001068: lui         $at, 0x1100
    ctx->r1 = S32(0X1100 << 16);
    // 0x8000106C: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80001070: andi        $t0, $a2, 0xFFFF
    ctx->r8 = ctx->r6 & 0XFFFF;
    // 0x80001074: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80001078: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x8000107C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80001080: jr          $ra
    // 0x80001084: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    return;
    // 0x80001084: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8002ADE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ADE4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8002ADE8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8002ADEC: lw          $v1, 0x478($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X478);
    // 0x8002ADF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002ADF4: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8002ADF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002ADFC: addiu       $t6, $t6, 0x2E4C
    ctx->r14 = ADD32(ctx->r14, 0X2E4C);
    // 0x8002AE00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002AE04: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x8002AE08: jal         0x8004700C
    // 0x8002AE0C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8002AE0C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002AE10: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002AE14: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x8002AE18: addiu       $a2, $a2, -0x5430
    ctx->r6 = ADD32(ctx->r6, -0X5430);
    // 0x8002AE1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002AE20: jal         0x8005A994
    // 0x8002AE24: lw          $a0, 0x478($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X478);
    func_8005A994(rdram, ctx);
        goto after_1;
    // 0x8002AE24: lw          $a0, 0x478($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X478);
    after_1:
    // 0x8002AE28: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AE2C: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8002AE30: addiu       $t8, $t8, -0x6DF4
    ctx->r24 = ADD32(ctx->r24, -0X6DF4);
    // 0x8002AE34: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8002AE38: sw          $t8, 0xF4($v1)
    MEM_W(0XF4, ctx->r3) = ctx->r24;
    // 0x8002AE3C: sw          $zero, 0xD0($v1)
    MEM_W(0XD0, ctx->r3) = 0;
    // 0x8002AE40: sw          $t9, 0xCC($v1)
    MEM_W(0XCC, ctx->r3) = ctx->r25;
    // 0x8002AE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AE48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002AE4C: jr          $ra
    // 0x8002AE50: nop

    return;
    // 0x8002AE50: nop

;}
RECOMP_FUNC void func_80735C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735C2C: jr          $ra
    // 0x80735C30: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80735C30: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8078D800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078D800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078D804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078D808: jal         0x8078D2D4
    // 0x8078D80C: nop

    func_8078D2D4(rdram, ctx);
        goto after_0;
    // 0x8078D80C: nop

    after_0:
    // 0x8078D810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078D814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078D818: jr          $ra
    // 0x8078D81C: nop

    return;
    // 0x8078D81C: nop

;}
RECOMP_FUNC void func_80789F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80789F04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80789F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80789F0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80789F10: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80789F14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80789F18: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80789F1C: jal         0x8005FD1C
    // 0x80789F20: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x80789F20: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80789F24: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80789F28: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80789F2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80789F30: lw          $t8, 0x174($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X174);
    // 0x80789F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80789F38: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80789F3C: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x80789F40: lw          $t0, 0x174($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X174);
    // 0x80789F44: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80789F48: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
    // 0x80789F4C: sb          $t2, 0x165($a3)
    MEM_B(0X165, ctx->r7) = ctx->r10;
    // 0x80789F50: jal         0x8078A148
    // 0x80789F54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8078A148(rdram, ctx);
        goto after_1;
    // 0x80789F54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80789F58: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80789F5C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80789F60: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80789F64: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80789F68: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80789F6C: jal         0x80789DA0
    // 0x80789F70: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    func_80789DA0(rdram, ctx);
        goto after_2;
    // 0x80789F70: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    after_2:
    // 0x80789F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80789F78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80789F7C: jr          $ra
    // 0x80789F80: nop

    return;
    // 0x80789F80: nop

;}
RECOMP_FUNC void func_80673F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673F6C: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80673F70: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80673F74: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x80673F78: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80673F7C: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x80673F80: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80673F84: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x80673F88: bnel        $at, $zero, L_80673FC8
    if (ctx->r1 != 0) {
        // 0x80673F8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80673FC8;
    }
    goto skip_0;
    // 0x80673F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80673F90: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x80673F94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80673F98: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80673F9C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80673FA0: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80673FA4: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80673FA8: beql        $t1, $t2, L_80673FBC
    if (ctx->r9 == ctx->r10) {
        // 0x80673FAC: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_80673FBC;
    }
    goto skip_1;
    // 0x80673FAC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_1:
    // 0x80673FB0: b           L_80673FC4
    // 0x80673FB4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_80673FC4;
    // 0x80673FB4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80673FB8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80673FBC:
    // 0x80673FBC: jr          $ra
    // 0x80673FC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80673FC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80673FC4:
    // 0x80673FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80673FC8:
    // 0x80673FC8: jr          $ra
    // 0x80673FCC: nop

    return;
    // 0x80673FCC: nop

;}
RECOMP_FUNC void func_806ED29C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED29C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806ED2A0: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(676, 0X1138) << 16);
    // 0x806ED2A4: addiu       $t6, $t6, -0x2F78
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(676, 0X1138));
    // 0x806ED2A8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806ED2AC: jr          $ra
    // 0x806ED2B0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806ED2B0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8049EB80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049EB80: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8049EB84: addiu       $at, $zero, 0x4054
    ctx->r1 = ADD32(0, 0X4054);
    // 0x8049EB88: beq         $v0, $at, L_8049EBA8
    if (ctx->r2 == ctx->r1) {
        // 0x8049EB8C: addiu       $at, $zero, 0x4056
        ctx->r1 = ADD32(0, 0X4056);
            goto L_8049EBA8;
    }
    // 0x8049EB8C: addiu       $at, $zero, 0x4056
    ctx->r1 = ADD32(0, 0X4056);
    // 0x8049EB90: beq         $v0, $at, L_8049EBC0
    if (ctx->r2 == ctx->r1) {
        // 0x8049EB94: addiu       $at, $zero, 0x4057
        ctx->r1 = ADD32(0, 0X4057);
            goto L_8049EBC0;
    }
    // 0x8049EB94: addiu       $at, $zero, 0x4057
    ctx->r1 = ADD32(0, 0X4057);
    // 0x8049EB98: beq         $v0, $at, L_8049EBB4
    if (ctx->r2 == ctx->r1) {
        // 0x8049EB9C: nop
    
            goto L_8049EBB4;
    }
    // 0x8049EB9C: nop

    // 0x8049EBA0: b           L_8049EBCC
    // 0x8049EBA4: lui         $v0, 0x804A
    ctx->r2 = S32(RELOC_HI16(167, 0XE5C) << 16);
        goto L_8049EBCC;
    // 0x8049EBA4: lui         $v0, 0x804A
    ctx->r2 = S32(RELOC_HI16(167, 0XE5C) << 16);
L_8049EBA8:
    // 0x8049EBA8: lui         $v0, 0x804A
    ctx->r2 = S32(RELOC_HI16(167, 0XE5C) << 16);
    // 0x8049EBAC: jr          $ra
    // 0x8049EBB0: addiu       $v0, $v0, -0x624
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(167, 0XE5C));
    return;
    // 0x8049EBB0: addiu       $v0, $v0, -0x624
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(167, 0XE5C));
L_8049EBB4:
    // 0x8049EBB4: lui         $v0, 0x804A
    ctx->r2 = S32(RELOC_HI16(167, 0XCF4) << 16);
    // 0x8049EBB8: jr          $ra
    // 0x8049EBBC: addiu       $v0, $v0, -0x78C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(167, 0XCF4));
    return;
    // 0x8049EBBC: addiu       $v0, $v0, -0x78C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(167, 0XCF4));
L_8049EBC0:
    // 0x8049EBC0: lui         $v0, 0x804A
    ctx->r2 = S32(RELOC_HI16(167, 0XE5C) << 16);
    // 0x8049EBC4: jr          $ra
    // 0x8049EBC8: addiu       $v0, $v0, -0x624
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(167, 0XE5C));
    return;
    // 0x8049EBC8: addiu       $v0, $v0, -0x624
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(167, 0XE5C));
L_8049EBCC:
    // 0x8049EBCC: addiu       $v0, $v0, -0x624
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(167, 0XE5C));
    // 0x8049EBD0: jr          $ra
    // 0x8049EBD4: nop

    return;
    // 0x8049EBD4: nop

;}
RECOMP_FUNC void func_805E537C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E537C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805E5380: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805E5384: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805E5388: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805E538C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805E5390: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805E5394: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805E5398: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805E539C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805E53A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805E53A4: jr          $ra
    // 0x805E53A8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805E53A8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x805E53AC: nop

;}
RECOMP_FUNC void func_806AA64C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA64C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806AA650: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806AA654: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(589, 0X11F8) << 16);
    // 0x806AA658: lwc1        $f4, -0x5648($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(589, 0X11F8));
    // 0x806AA65C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x806AA660: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x806AA664: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x806AA668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AA66C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x806AA670: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x806AA674: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806AA678: sh          $a1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r5;
    // 0x806AA67C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x806AA680: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x806AA684: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x806AA688: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x806AA68C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x806AA690: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x806AA694: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x806AA698: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x806AA69C: lw          $t9, 0x54($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X54);
    // 0x806AA6A0: jalr        $t9
    // 0x806AA6A4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806AA6A4: nop

    after_0:
    // 0x806AA6A8: beq         $v0, $zero, L_806AA6CC
    if (ctx->r2 == 0) {
        // 0x806AA6AC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_806AA6CC;
    }
    // 0x806AA6AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806AA6B0: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
    // 0x806AA6B4: jal         0x8005FDC4
    // 0x806AA6B8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x806AA6B8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x806AA6BC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x806AA6C0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x806AA6C4: lw          $v0, 0x1F4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X1F4);
    // 0x806AA6C8: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
L_806AA6CC:
    // 0x806AA6CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AA6D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806AA6D4: jr          $ra
    // 0x806AA6D8: nop

    return;
    // 0x806AA6D8: nop

;}
RECOMP_FUNC void func_80027AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027AEC: jal         0x80024668
    // 0x80027AF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024668(rdram, ctx);
        goto after_0;
    // 0x80027AF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027AF4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80027AF8: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80027AFC: addiu       $t6, $t6, 0x7A4C
    ctx->r14 = ADD32(ctx->r14, 0X7A4C);
    // 0x80027B00: sw          $t6, 0x160($t7)
    MEM_W(0X160, ctx->r15) = ctx->r14;
    // 0x80027B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027B08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027B0C: jr          $ra
    // 0x80027B10: nop

    return;
    // 0x80027B10: nop

;}
